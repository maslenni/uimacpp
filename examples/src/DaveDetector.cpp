/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "uima/api.hpp"

using namespace uima;

class DaveDetector : public uima::Annotator {
private:
    Type david;
    CAS* tcas;
    UnicodeString us_DaveString;

public:

    DaveDetector(void) {
        std::cout << "DaveDetector: Constructor" << std::endl;
    }

    ~DaveDetector(void) {
        std::cout << "DaveDetector: Destructor" << std::endl;
    }

    /** */
    TyErrorId initialize(uima::AnnotatorContext& rclAnnotatorContext) {
        std::cout << "DaveDetector: initialize()" << std::endl;


        if (!rclAnnotatorContext.isParameterDefined("DaveString") ||
            rclAnnotatorContext.extractValue("DaveString", us_DaveString) != UIMA_ERR_NONE) {
            /* log the error condition */
            rclAnnotatorContext.getLogger().logError(
            "Required configuration parameter \"DaveString\" not found in component descriptor");
            std::cout << "DaveDetector::initialize() - Error. See logfile." << std::endl;
            return UIMA_ERR_USER_ANNOTATOR_COULD_NOT_INIT;
        }

        /* log the configuration parameter setting */
        rclAnnotatorContext.getLogger().logMessage("DaveString = '" + us_DaveString + "'");

        std::cout << "DaveDetector::initialize() .. us_DaveString.getBuffer: " << us_DaveString << std::endl;

        return (TyErrorId) UIMA_ERR_NONE;
    }

    /** */
    TyErrorId typeSystemInit(TypeSystem const& crTypeSystem) {
        std::cout << "DaveDetector:: typeSystemInit()" << std::endl;
        david = crTypeSystem.getType("org.apache.uima.examples.David");
        if (!david.isValid()) {
            getAnnotatorContext().getLogger().logError("Error getting Type object for org.apache.uima.examples.David");
            std::cout << "DaveDetector::typeSystemInit - Error. See logfile" << std::endl;
            return (TyErrorId) UIMA_ERR_RESMGR_INVALID_RESOURCE;
        }
        return (TyErrorId) UIMA_ERR_NONE;
    }

    /** */
    TyErrorId destroy() {
        std::cout << "DaveDetector: destroy()" << std::endl;
        return (TyErrorId) UIMA_ERR_NONE;
    }

    /** */
    TyErrorId process(CAS& tcas, ResultSpecification const& crResultSpecification) {
        std::cout << "DaveDetector::process() begins" << std::endl;
        FSIndexRepository& indexRep = tcas.getIndexRepository();

        /* This is a shallow pointer object containing a reference to document text*/
        uima::UnicodeStringRef ulstrDoc = tcas.getDocumentText();
        std::string a = ulstrDoc.asUTF8();

        /* Conventional pointer to mark beginning of the buffer*/
        const UChar* cpszDocTextBegin = ulstrDoc.getBuffer();
        /* Pointer to the document text remaining to be scanned */
        const UChar* remainingTextP = cpszDocTextBegin;
        /* Pointer to the match string */
        const UChar* DaveStringP = us_DaveString.getBuffer();
        /* Get number of Unicode chars (UTF-16 code units) of a couple strings */
        size_t uiDocLen = ulstrDoc.length();
        size_t uiMatchLen = us_DaveString.length();
        size_t remainingLen = uiDocLen;

        std::cout << "DaveDetector::process() .. uiDocLen: " << uiDocLen << std::endl;
        getAnnotatorContext().getLogger().logMessage("process called");

        UChar* gotDaveP;
        while (NULL != (gotDaveP = u_strFindFirst(remainingTextP, remainingLen, DaveStringP, uiMatchLen))) {
            size_t uiExprBeginPos = gotDaveP - cpszDocTextBegin;
            size_t uiExprEndPos = uiExprBeginPos + uiMatchLen;
            remainingLen = uiDocLen - uiExprBeginPos;
            remainingTextP = gotDaveP + uiMatchLen;

            std::cout << "DaveDetector::process() .. Gotta Dave begin: " << uiExprBeginPos << "  end: "
            << uiExprEndPos << "  remaining: " << remainingLen << std::endl;

            AnnotationFS fsNewExp = tcas.createAnnotation(david, uiExprBeginPos, uiExprEndPos);
            indexRep.addFS(fsNewExp);
        }

        std::cout << "DaveDetector::process() ends" << std::endl;
        return (TyErrorId) UIMA_ERR_NONE;
    }
};

// This macro exports an entry point that is used to create the annotator.

MAKE_AE(DaveDetector);
