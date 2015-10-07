#ifndef UIMA_XMLTYPESYSTEMREADER_HPP
#define UIMA_XMLTYPESYSTEMREADER_HPP
/** \file xmltypesystemreader.hpp .
-----------------------------------------------------------------------------




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

-----------------------------------------------------------------------------

   Description:

-----------------------------------------------------------------------------


-------------------------------------------------------------------------- */


/* ----------------------------------------------------------------------- */
/*       Include dependencies                                              */
/* ----------------------------------------------------------------------- */

#include "uima/pragmas.hpp"
#include "uima/lowlevel_typedefs.hpp"
#include "uima/exceptions.hpp"
#include "xercesc/dom/DOMElement.hpp"
#include "xercesc/sax/ErrorHandler.hpp"
#include "xercesc/sax/InputSource.hpp"

/* ----------------------------------------------------------------------- */
/*       Constants                                                         */
/* ----------------------------------------------------------------------- */

/* ----------------------------------------------------------------------- */
/*       Forward declarations                                              */
/* ----------------------------------------------------------------------- */

//class DOMElement;
//class InputSource;
//class ErrorHandler;
XERCES_CPP_NAMESPACE_USE

namespace uima {
  class TypeSystem;
  namespace internal {
    class CASDefinition;
  }
  namespace lowlevel {
    class TypeSystem;
  }
}

/* ----------------------------------------------------------------------- */
/*       Types / Classes                                                   */
/* ----------------------------------------------------------------------- */

namespace uima {

  UIMA_EXC_CLASSDECLARE(XMLTypeSystemReaderException, uima::Exception);

  /**
   * Reads a typesystem in XML format and creates the types described in it.
   * @see XMLTypeSystemWriter
   * @see DotTypeSystemWriter
   */
  class UIMA_LINK_IMPORTSPEC XMLTypeSystemReader {
  public:
    XMLTypeSystemReader(uima::internal::CASDefinition &);
    XMLTypeSystemReader(uima::TypeSystem &);
    ~XMLTypeSystemReader();

    void setErrorHandler(ErrorHandler*);

    void readFile(UnicodeString const & fileName, UnicodeString const & creatorID);
    void readFile(char const * fileName, UnicodeString const & creatorID);
    void readMemory(UnicodeString const & xmlString, UnicodeString const & creatorID);
    void readMemory(char const * cpszXMLString, UnicodeString const & creatorID);
  protected:

    void read(InputSource const &, UnicodeString const & creatorID );

    void checkValidityCondition( bool ) const;
    void checkValidityCondition(bool bCondition, TyMessageId tyMessage, UnicodeString const & crString) const;
    void checkValidityCondition(bool bCondition, TyMessageId tyMessage, UnicodeString const & crString1, UnicodeString const & crString2) const;

    void createType(lowlevel::TyFSType, DOMElement* );
    void createFeatures(DOMElement* );

    UnicodeString iv_ustrCreatorID;
    lowlevel::TypeSystem & iv_rTypeSystem;
    ErrorHandler * iv_pXMLErrorHandler;
  };

}

/* ----------------------------------------------------------------------- */
/*       Implementation                                                    */
/* ----------------------------------------------------------------------- */


/* ----------------------------------------------------------------------- */


#endif

