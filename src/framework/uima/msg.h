/* The following was once generated from msg ... now maintained by hand! */
/*   >>>>>                                                        <<<<<  */
/*   >>>>>   MUST MUST be kept in sync with msgstrtab.h           <<<<<  */
/*   >>>>>                                                        <<<<<  */

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

#ifndef UIMA_MSG_H
#define UIMA_MSG_H

#include <limits.h>

#if !(defined( _MSC_VER) || defined(__BORLANDC__))

#include <nl_types.h>

#endif

/* The following was once generated automatically ... now maintained by hand! */
/*   >>>>>                                                             <<<<<  */
/*   >>>>>   MUST MUST be kept in sync with uima/msgstrtab.h           <<<<<  */
/*   >>>>>                                                             <<<<<  */

#define UIMA_MSG_ID_SIGNATURE_BEGIN 1
#define UIMA_MSG_ID_LITERAL_STRING 2
#define UIMA_MSG_ID_NO_MESSAGE_AVAILABLE 3
#define UIMA_MSG_ID_EXC_UNEXPECTED_ERROR 4
#define UIMA_MSG_ID_EXC_OUT_OF_MEMORY 5
#define UIMA_MSG_ID_EXC_RESOURCE_KEY 6
#define UIMA_MSG_ID_EXC_INVALID_ITERATOR 7
#define UIMA_MSG_ID_EXC_DOCUMENT_INVALID_IDX 8
#define UIMA_MSG_ID_EXC_DOCUMENT_EMPTY_REF 9
#define UIMA_MSG_ID_EXC_DOCUMENT_INVAL_COPY_OP 10
#define UIMA_MSG_ID_EXC_CPCONVERSION_ILLEGAL_CALL 11
#define UIMA_MSG_ID_EXC_CPCONVERSION_OVERFLOW 12
#define UIMA_MSG_ID_EXC_CPCONVERSION_INVALID_SRCSEQ 13
#define UIMA_MSG_ID_EXC_CPCONVERSION_INVALID_DBCS_SRC 14
#define UIMA_MSG_ID_EXC_CPCONVERSION_NOT_SUPPORTED 15
#define UIMA_MSG_ID_EXC_ANNOTATORMGR_INVAL_ANNOTATOR_REQ 16
#define UIMA_MSG_ID_EXC_ENUMERATION_OVERFLOW 17
#define UIMA_MSG_ID_EXC_WINDOWS_EXCEPTION 18
#define UIMA_MSG_ID_EXC_XML_SAXPARSE_WARNING 19
#define UIMA_MSG_ID_EXC_XML_SAXPARSE_ERROR 20
#define UIMA_MSG_ID_EXC_XML_SAXPARSE_FATALERROR 21
#define UIMA_MSG_ID_EXC_XML_XMLEXCEPTION 22
#define UIMA_MSG_ID_EXC_INVALID_LANGUAGE 23
#define UIMA_MSG_ID_ANNOTATOR_COULD_NOT_FIND 24
#define UIMA_MSG_ID_ANNOTATOR_COULD_NOT_FIND_MAKEAE 25
#define UIMA_MSG_ID_ANNOTATOR_COULD_NOT_LOAD 26
#define UIMA_MSG_ID_ANNOTATOR_COULD_NOT_INITIALIZE 27
#define UIMA_MSG_ID_EXC_UNKNOWN_JAVA_EXCEPTION 28
#define UIMA_MSG_ID_EXC_JAVA_EXCEPTION 29
#define UIMA_MSG_ID_EXC_JNI_CALL_FAILED 30
#define UIMA_MSG_ID_EXC_JAVA_VM_COULD_NOT_BE_CREATED 31
#define UIMA_MSG_ID_EXC_COULD_NOT_LOAD_JAVA_DLL 32
#define UIMA_MSG_ID_EXC_INCOMPATIBLE_CAS 33
#define UIMA_MSG_ID_EXC_NO_CAS 34
#define UIMA_MSG_ID_RESMGR_DATADIR_DOES_NOT_EXIST 35
#define UIMA_MSG_ID_RESMGR_WORKDIR_DOES_NOT_EXIST 36
#define UIMA_MSG_ID_EXC_INVALID_FS_OBJECT 37
#define UIMA_MSG_ID_EXC_INVALID_FSTYPE_OBJECT 38
#define UIMA_MSG_ID_EXC_INVALID_FSFEATURE_OBJECT 39
#define UIMA_MSG_ID_EXC_FEATURE_NOT_APPROPRIATE 40
#define UIMA_MSG_ID_EXC_INCOMPATIBLE_RANGE_TYPE 41
#define UIMA_MSG_ID_EXC_INVALID_INDEX_OBJECT 42
#define UIMA_MSG_ID_EXC_FS_IS_NOT_STRING 43
#define UIMA_MSG_ID_EXC_TYPESYSTEM_ALREADY_COMMITTED 44
#define UIMA_MSG_ID_EXC_WRONG_FSTYPE 45
#define UIMA_MSG_ID_EXC_LIST_IS_EMPTY 46
#define UIMA_MSG_ID_EXC_LIST_IS_CIRCULAR 47
#define UIMA_MSG_ID_EXC_FS_IS_NOT_LIST 48
#define UIMA_MSG_ID_EXC_TYPESYSTEM_NOT_YET_COMMITTED 49
#define UIMA_MSG_ID_EXC_INDEX_ALREADY_EXISTS 50
#define UIMA_MSG_ID_EXC_WRONG_FSTYPE_FOR_INDEX 51
#define UIMA_MSG_ID_EXC_INVALID_INDEX_ID 52
#define UIMA_MSG_ID_EXC_XMLTYPESYSTEMREADER 53
#define UIMA_MSG_ID_EXC_WRONG_XML_TYPESYSTEM_FORMAT 54
#define UIMA_MSG_ID_EXC_INVALID_INTRO_TYPE 55
#define UIMA_MSG_ID_EXC_INVALID_RANGE_TYPE 56
#define UIMA_MSG_ID_EXC_WRONG_PARENT_TYPE 57
#define UIMA_MSG_ID_EXC_FS_IS_NOT_ARRAY 58
#define UIMA_MSG_ID_EXC_ARRAY_OUT_OF_BOUNDS 59
#define UIMA_MSG_ID_EXC_NOT_YET_IMPLEMENTED 60
#define UIMA_MSG_ID_EXC_TYPE_CREATION_FAILED_FINAL_TYPE 61
#define UIMA_MSG_ID_EXC_FEATURE_INTRO_FAILED_FINAL_TYPE 62
#define UIMA_MSG_ID_EXC_TYPE_ALREADY_EXISTS 63
#define UIMA_MSG_ID_EXC_FEATURE_ALREADY_EXISTS 64
#define UIMA_MSG_ID_EXC_COULD_NOT_CREATE_FS_FINAL_TYPE 65
#define UIMA_MSG_ID_EXC_UNKNOWN_TYPE_NAME 66
#define UIMA_MSG_ID_EXC_UNKNOWN_FEATURE_NAME 67
#define UIMA_MSG_ID_EXC_WRONG_STRING_VALUE 68
#define UIMA_MSG_ID_EXC_ALLOWED_STRING_VALUES_INCOMPATIBLE 69
#define UIMA_MSG_ID_EXC_TYPE_PRIORITY_CONFLICT 70
#define UIMA_MSG_ID_EXC_INCOMPATIBLE_INDEX_DEFINITIONS 71
#define UIMA_MSG_ID_EXC_WRONG_DESERIALIZED_DATA 72
#define UIMA_MSG_ID_EXC_SOFA_NAME_ALREADY_EXISTS 73
#define UIMA_MSG_ID_EXC_DUPLICATE_INDEX_LABEL 74
#define UIMA_MSG_ID_EXC_DUPLICATE_TYPE_NAME 75
#define UIMA_MSG_ID_EXC_DUPLICATE_FEATURE_NAME 76
#define UIMA_MSG_ID_EXC_UNKNOWN_CONFIG_XML_TAG 77
#define UIMA_MSG_ID_EXC_CONFIG_XML_ATTRIBUTE_VALUE_NOT_ALLOWED 78
#define UIMA_MSG_ID_UNKNOWN_TYPE_IN_CAPBILITY_SPEC 79
#define UIMA_MSG_ID_UNKNOWN_FEATURE_IN_CAPBILITY_SPEC 80
#define UIMA_MSG_ID_EXC_NO_VALUE_FOR_MANDATORY_PARAM 81
#define UIMA_MSG_ID_EXC_NO_VALUE_FOR_MANDATORY_PARAM_IN_GROUP 82
#define UIMA_MSG_ID_EXC_CONFIG_DUPLICATE_CONFIG_PARAM 83
#define UIMA_MSG_ID_EXC_CONFIG_DUPLICATE_NAME_VALUE_PAIR 84
#define UIMA_MSG_ID_EXC_CONFIG_DUPLICATE_GROUP 85
#define UIMA_MSG_ID_EXC_ALLOWEDVAL_DEF_FOR_NONSTRINGTYPE 86
#define UIMA_MSG_ID_EXC_XINCLUSION_IS_CYCLIC 87
#define UIMA_MSG_ID_EXC_INVALID_XINCLUDE_TAG 88
#define UIMA_MSG_ID_EXC_DUPLICATE_ALLOWED_VALUE 89
#define UIMA_MSG_ID_EXC_CONFIG_VALUE_TYPE_MISMATCH 90
#define UIMA_MSG_ID_EXC_CONFIG_VALUE_MUST_BE_SINGLE 91
#define UIMA_MSG_ID_EXC_CONFIG_VALUE_MUST_BE_MULTI 92
#define UIMA_MSG_ID_EXCON_CONFIG_VALUE_EXTRACT 93
#define UIMA_MSG_ID_EXC_CONFIG_PARAM_NOT_DEFINED 94
#define UIMA_MSG_ID_EXC_CONFIG_PARAM_NOT_DEFINED_IN_GROUP 95
#define UIMA_MSG_ID_EXC_CONFIG_NO_DEFAULT_GROUP_DEFINED 96
#define UIMA_MSG_ID_EXC_CONFIG_NO_GROUPS_DEFINED 97
#define UIMA_MSG_ID_EXCON_BUILD_TAE_SPEC_FROM_FILE 98
#define UIMA_MSG_ID_EXCON_BUILD_TAE_SPEC 99
#define UIMA_MSG_ID_EXCON_VALIDATE_TAE_SPEC_FROM_FILE 100
#define UIMA_MSG_ID_EXCON_VALIDATE_TAE_SPEC 101
#define UIMA_MSG_ID_EXCON_CONFIG_PARAM_SEARCH 102
#define UIMA_MSG_ID_EXCON_CONFIG_PARAM_IN_GROUP_SEARCH 103
#define UIMA_MSG_ID_EXCON_RESOLVING_XINCLUDES 104
#define UIMA_MSG_ID_EXCON_UNKNOWN_CONTEXT 105
#define UIMA_MSG_ID_EXCON_ITERATOR_ACCESS 106
#define UIMA_MSG_ID_EXCON_DOCUMENT_INVALID_IDX 107
#define UIMA_MSG_ID_EXCON_CPCONVERSION 108
#define UIMA_MSG_ID_EXCON_ANNOTATORMGR_INVAL_ANNOTATOR_REQ 109
#define UIMA_MSG_ID_EXCON_ENUMERATION_OVERFLOW 110
#define UIMA_MSG_ID_EXCON_ALLOCATE_MEMPOOL_INST 111
#define UIMA_MSG_ID_EXCON_ALLOCATE_MEMPOOL_DOC_BUF 112
#define UIMA_MSG_ID_EXCON_ALLOCATE_MEMPOOL_DOC_MISC 113
#define UIMA_MSG_ID_EXCON_EXECUTING_ANNOTATOR 114
#define UIMA_MSG_ID_EXCON_CALLING_ANNOTATOR_FUNCTION 115
#define UIMA_MSG_ID_EXCON_GENERIC_PARAM 116
#define UIMA_MSG_ID_EXCON_NO_RES_FOR_LANGUAGE 117
#define UIMA_MSG_ID_EXCON_PARSING_TAGGED_DOCUMENT 118
#define UIMA_MSG_ID_EXCON_CHECKING_CAPABILITY_SPEC 119
#define UIMA_MSG_ID_EXCON_CHECKING_INDEX_DEFINITION 120
#define UIMA_MSG_ID_EXCON_PROCESSING_JAVA_TAE 121
#define UIMA_MSG_ID_EXCON_PROCESSING_CAS 122
#define UIMA_MSG_ID_EXCON_PROMOTING_CAS 123
#define UIMA_MSG_ID_EXCON_CREATING_FS 124
#define UIMA_MSG_ID_EXCON_GETTING_INDEX 125
#define UIMA_MSG_ID_EXCON_CREATING_SET_INDEX 126
#define UIMA_MSG_ID_EXCON_CREATING_ORDERED_INDEX 127
#define UIMA_MSG_ID_EXCON_CHECKING_INDEX_ID 128
#define UIMA_MSG_ID_EXCON_ADDING_FS_TO_INDEX 129
#define UIMA_MSG_ID_EXCON_FINDING_FS_IN_INDEX 130
#define UIMA_MSG_ID_EXCON_REMOVING_FS_FROM_INDEX 131
#define UIMA_MSG_ID_EXCON_INTRODUCING_FEATURE 132
#define UIMA_MSG_ID_EXCON_ADDING_TYPE 133
#define UIMA_MSG_ID_EXCON_SETTING_STRINGVALUE_IN_FS 134
#define UIMA_MSG_ID_EXCON_GETTING_STRINGVALUE_FROM_FS 135
#define UIMA_MSG_ID_EXCON_GETTING_ARRAYDATA_FROM_FS 136
#define UIMA_MSG_ID_EXCON_GETTING_ARRAYSIZE_FROM_FS 137
#define UIMA_MSG_ID_EXCON_GETTING_FEATURE_VALUE 138
#define UIMA_MSG_ID_EXCON_SETTING_FEATURE_VALUE 139
#define UIMA_MSG_ID_EXCON_INITIALIZING_KEYFEATURECOMPARATOR 140
#define UIMA_MSG_ID_EXCON_COMPARING_FSS 141
#define UIMA_MSG_ID_EXCON_GETTING_FSTYPE 142
#define UIMA_MSG_ID_EXCON_CREATING_LISTFS 143
#define UIMA_MSG_ID_EXCON_APPENDING_TO_LIST 144
#define UIMA_MSG_ID_EXCON_PREPENDING_TO_LIST 145
#define UIMA_MSG_ID_EXCON_GETTING_LIST_LENGTH 146
#define UIMA_MSG_ID_EXCON_GETTING_FIRST_LIST_ELEMENT 147
#define UIMA_MSG_ID_EXCON_GETTING_LAST_LIST_ELEMENT 148
#define UIMA_MSG_ID_EXCON_SETTING_FIRST_LIST_ELEMENT 149
#define UIMA_MSG_ID_EXCON_SETTING_LAST_LIST_ELEMENT 150
#define UIMA_MSG_ID_EXCON_GETTING_LIST_ISEMPTY 151
#define UIMA_MSG_ID_EXCON_GETTING_LIST_HEAD 152
#define UIMA_MSG_ID_EXCON_SETTING_LIST_HEAD 153
#define UIMA_MSG_ID_EXCON_GETTING_LIST_TAIL 154
#define UIMA_MSG_ID_EXCON_SETTING_LIST_TAIL 155
#define UIMA_MSG_ID_EXCON_ADDING_LIST_VALUE 156
#define UIMA_MSG_ID_EXCON_MOVING_LIST_TO_NEXT 157
#define UIMA_MSG_ID_EXCON_CREATING_ARRAYFS 158
#define UIMA_MSG_ID_EXCON_GETTING_FS_FROM_ARRAY 159
#define UIMA_MSG_ID_EXCON_SETTING_FS_IN_ARRAY 160
#define UIMA_MSG_ID_EXCON_CREATING_STRINGFS 161
#define UIMA_MSG_ID_EXCON_READING_TYPESYSTEM_FROM_XML 162
#define UIMA_MSG_ID_EXCON_CREATING_TYPE 163
#define UIMA_MSG_ID_EXCON_CREATING_FEATURE 164
#define UIMA_MSG_ID_EXCON_CREATING_ITERATOR 165
#define UIMA_MSG_ID_EXCON_CREATING_TYPESYSTEM_FROM_CONFIG 166
#define UIMA_MSG_ID_EXCON_CREATING_TYPEPRIORITIES_FROM_CONFIG 167
#define UIMA_MSG_ID_EXCON_CREATING_INDEXES_FROM_CONFIG 168
#define UIMA_MSG_ID_EXCON_DESERIALIZING_CAS 169
#define UIMA_MSG_ID_ERR_PARSER_CONFIG_INVALID_RULE_CONTENT_ERROR 170
#define UIMA_MSG_ID_ERRCON_PARSER_CONFIG_FUNCTION 171
#define UIMA_MSG_ID_ERRCON_PARSER_CONFIG_FILE 172
#define UIMA_MSG_ID_ERRCON_PARSER_CONFIG_TAG 173
#define UIMA_MSG_ID_ERRCON_PARSER_CONFIG_LINE 174
#define UIMA_MSG_ID_EXC_FILE_ACCESS 175
#define UIMA_MSG_ID_EXC_FILE_OPEN 176
#define UIMA_MSG_ID_EXC_FILE_WRITE 177
#define UIMA_MSG_ID_EXC_FILE_READ 178
#define UIMA_MSG_ID_LOG_TO_ERROR_INFO 179
#define UIMA_MSG_ID_LOG_MESSAGE 180
#define UIMA_MSG_ID_LOG_WARNING 181
#define UIMA_MSG_ID_LOG_ERROR 182
#define UIMA_MSG_ID_LOG_FATAL_ERROR 183
#define UIMA_MSG_ID_LOG_USER_CODE 184
#define UIMA_MSG_ID_EXC_CONV_BUFFER_PROBLEM 185
#define UIMA_MSG_ID_EXC_U2CP_CONVERSION_PROBLEM 186
#define UIMA_MSG_ID_EXC_CP2U_CONVERSION_PROBLEM 187
#define UIMA_MSG_ID_EXC_POE_DICTIONARY_UNLOAD 188
#define UIMA_MSG_ID_EXC_POE_DICTIONARY_NOT_FOUND 189
#define UIMA_MSG_ID_EXC_POE_DICTIONARY_NOT_LOADABLE 190
#define UIMA_MSG_ID_EXC_POE_LEXICAL_ANALYSIS_FAILED 191
#define UIMA_MSG_ID_EXC_POE_UNEXPECTED_RC 192
#define UIMA_MSG_ID_EXC_POE_LEXICAL_ANALYSIS_ABORTED 193
#define UIMA_MSG_ID_EXCON_POE_ABBREV_DICT_OPEN 194
#define UIMA_MSG_ID_EXCON_POE_STOPWORD_DICT_OPEN 195
#define UIMA_MSG_ID_EXCON_POE_ADDENDA_DICT_OPEN 196
#define UIMA_MSG_ID_EXCON_POE_MAIN_DICT_OPEN 197
#define UIMA_MSG_ID_EXCON_POE_USING_DICT_PATH 198
#define UIMA_MSG_ID_EXCON_POE_CALLING_LEXICAL_ANALYSIS 199
#define UIMA_MSG_ID_EXCON_POE_CALLING_MORPHID 200
#define UIMA_MSG_ID_EXCON_TOK_ALLOCATING_CHARTABLE 201
#define UIMA_MSG_ID_EXC_THES_PATH_NOT_FOUND 202
#define UIMA_MSG_ID_EXC_THES_FILE_NOT_FOUND 203
#define UIMA_MSG_ID_EXC_THES_NO_PATH_CREATED 204
#define UIMA_MSG_ID_EXC_THES_NO_FILE_NAME 205
#define UIMA_MSG_ID_EXC_THES_NO_PATH_NAME 206
#define UIMA_MSG_ID_EXC_THES_NO_PATH_PARAM 207
#define UIMA_MSG_ID_EXC_THES_NO_FILE_PARAM 208
#define UIMA_MSG_ID_EXC_THES_RELATION_NOT_FOUND 209
#define UIMA_MSG_ID_EXC_THES_DEPTH_OVERFLOW 210
#define UIMA_MSG_ID_EXC_THES_MAXCOUNT_OVERFLOW 211
#define UIMA_MSG_ID_EXC_THES_NO_ERRCODE_MSG 212
#define UIMA_MSG_ID_EXC_THES_FAIL_MSG 213
#define UIMA_MSG_ID_EXC_THES_INVALID_PATH 214
#define UIMA_MSG_ID_EXC_THES_INVALID_FILE 215
#define UIMA_MSG_ID_EXC_THES_INVALID_RELATION 216
#define UIMA_MSG_ID_EXC_THES_INVALID_DEPTH 217
#define UIMA_MSG_ID_EXC_THES_INVALID_MAXCOUNT 218
#define UIMA_MSG_ID_EXC_CATRULE_PARSING_RULE_FILE_FAILED 219
#define UIMA_MSG_ID_EXCON_CATRULE_INITIALIZING 220
#define UIMA_MSG_ID_EXCON_SUM_WFTABLE_LOAD 221
#define UIMA_MSG_ID_EXCON_SUM_WFTABLE_SAVE 222
#define UIMA_MSG_ID_EXCON_DOX_DOXTRACT_ERROR 223
#define UIMA_MSG_ID_LOGACCESS 224
#define UIMA_MSG_ID_FILENLEN 225
#define UIMA_MSG_ID_AUTHFNLEN 226
#define UIMA_MSG_ID_STOPFNLEN 227
#define UIMA_MSG_ID_NO_POEDICT 228
#define UIMA_MSG_ID_NO_TSTOP_FILE 229
#define UIMA_MSG_ID_NO_AUTH_FILE 230
#define UIMA_MSG_ID_CREA_LOGFILE 231
#define UIMA_MSG_ID_IMZ_ERROR_1STRING 232
#define UIMA_MSG_ID_IMZ_ERROR_2STRING 233
#define UIMA_MSG_ID_EXCON_LIN_RESFILE_LOAD 234
#define UIMA_MSG_ID_EXC_LIN_MAXCAT 235
#define UIMA_MSG_ID_EXC_LIN_WORKDICT_CR_FAILED 236
#define UIMA_MSG_ID_EXC_LIN_WORKDICT_INSERT_FAILED 237
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_CR_FAILED 238
#define UIMA_MSG_ID_EXC_LIN_NEWMASTDICT_CR_FAILED 239
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_NR_COMPONENTS 240
#define UIMA_MSG_ID_EXC_LIN_PREFIXES_NOT_FOUND 241
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_STR_NOT_FOUND 242
#define UIMA_MSG_ID_EXCON_LIN_MASTDICT_SAVE 243
#define UIMA_MSG_ID_EXCON_LIN_MASTDICT_OPEN 244
#define UIMA_MSG_ID_EXCON_LIN_MASTDICT_TRYOPEN 245
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_NO_MINWLENGTH 246
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_NO_MAXWLENGTH 247
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_NO_GRAMLENGTH 248
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_WRONG_MINWLENGTH 249
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_WRONG_MAXWLENGTH 250
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_WRONG_GRAMLENGTH 251
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_PREFX_USED 252
#define UIMA_MSG_ID_EXC_LIN_DICT_FEATTOTAL 253
#define UIMA_MSG_ID_EXC_LIN_DICT_FEATSS 254
#define UIMA_MSG_ID_EXC_LIN_DICT_BALANCED 255
#define UIMA_MSG_ID_EXC_LIN_MASTDICT_MISSING_ENTRY 256
#define UIMA_MSG_ID_EXC_LIN_TEMPDICT_MISSING_ENTRY 257
#define UIMA_MSG_ID_EXC_LIN_PREFIX_LENGTH 258
#define UIMA_MSG_ID_EXC_LIN_BALANCE_NOT_SUPPORTED 259
#define UIMA_MSG_ID_EXC_LIN_BALANCE_AND_TRAIN 260
#define UIMA_MSG_ID_EXC_LIN_MISSING_NEWDICTNAME 261
#define UIMA_MSG_ID_EXC_LIN_DICTNAME_EQ_NEWDICTNAME 262
#define UIMA_MSG_ID_ERR_LIN_PARAM_OUT_OF_RANGE 263
#define UIMA_MSG_ID_ERRCON_LIN_SET_MAXCHARS 264
#define UIMA_MSG_ID_ERRCON_LIN_SET_MAXLANGS 265
#define UIMA_MSG_ID_EXC_DOX_GENERIC_ERROR 266
#define UIMA_MSG_ID_EXCON_DOX_FUNCTION_CONTEXT 267
#define UIMA_MSG_ID_EXC_REGEX_GENERIC_ERROR 268
#define UIMA_MSG_ID_ERR_REGEX_PARSE_ERROR 269
#define UIMA_MSG_ID_ERR_REGEX_NO_RULES_ERROR 270
#define UIMA_MSG_ID_ERR_REGEX_INVALID_RULE_CONTENT_ERROR 271
#define UIMA_MSG_ID_ERR_REGEX_UNKNOWN_TYPE_ERROR 272
#define UIMA_MSG_ID_ERR_REGEX_UNKNOWN_FEAT_ERROR 273
#define UIMA_MSG_ID_ERR_REGEX_INVALID_FEAT_ERROR 274
#define UIMA_MSG_ID_EXC_REGEX_TYPESYSTEM_FILE 275
#define UIMA_MSG_ID_ERRCON_REGEX_FUNCTION 276
#define UIMA_MSG_ID_ERRCON_REGEX_RULE_FILE 277
#define UIMA_MSG_ID_ERRCON_REGEX_RULE 278
#define UIMA_MSG_ID_ERRCON_REGEX_RULE_LINE 279
#define UIMA_MSG_ID_EXCCON_REGEX_SET_FEATURE 280
#define UIMA_MSG_ID_EXCON_PARSING_TOTEM_XMLFILE 281
#define UIMA_MSG_ID_EXC_UNKOWN_XMLTAG 282
#define UIMA_MSG_ID_EXC_UNKNOWN_SYMBOLTABLE 283
#define UIMA_MSG_ID_EXC_SYMBOLTABLE_ALREADY_FILLED 284
#define UIMA_MSG_ID_EXC_INSTRUCTIONS_ALREADY_FILLED 285
#define UIMA_MSG_ID_EXC_WRONG_ARGUMENT_TYPE 286
#define UIMA_MSG_ID_EXC_INVALID_INPUT_ANNOTATION_TYPE 287
#define UIMA_MSG_ID_EXC_WRONG_ARGUMENT_NUMBER 288
#define UIMA_MSG_ID_EXC_UNKNOWN_INSTRUCTION 289
#define UIMA_MSG_ID_EXC_UNSUPPORTED_XML_ATTRIBUTE 290
#define UIMA_MSG_ID_EXCON_CREATING_POOL_FOR_CLASS 291
#define UIMA_MSG_ID_EXC_APR_ERROR 292
#define UIMA_MSG_ID_EXCON_APR_FUNCTION 293
#define UIMA_MSG_ID_EXCON_CONSTRUCTING_CLASS 294
#define UIMA_MSG_ID_RESERVED_05 295
#define UIMA_MSG_ID_RESERVED_06 296
#define UIMA_MSG_ID_RESERVED_07 297
#define UIMA_MSG_ID_RESERVED_08 298
#define UIMA_MSG_ID_RESERVED_09 299
#define UIMA_MSG_ID_RESERVED_10 300
#define UIMA_MSG_ID_RESERVED_11 301
#define UIMA_MSG_ID_RESERVED_12 302
#define UIMA_MSG_ID_RESERVED_13 303
#define UIMA_MSG_ID_RESERVED_14 304
#define UIMA_MSG_ID_RESERVED_15 305
#define UIMA_MSG_ID_RESERVED_16 306
#define UIMA_MSG_ID_RESERVED_17 307
#define UIMA_MSG_ID_RESERVED_18 308
#define UIMA_MSG_ID_RESERVED_19 309
#define UIMA_MSG_ID_RESERVED_20 310
#define UIMA_MSG_ID_RESERVED_21 311
#define UIMA_MSG_ID_INCOMPATIBLE_UIMA_JAVA_VERSION 312
#define UIMA_MSG_ID_EXC_CREATE_CASPOOL      313
#define UIMA_MSG_ID_EXCON_SOFADATASTREAM      314
#define UIMA_MSG_ID_EXC_INVALID_SOFAURI       315
#define UIMA_MSG_ID_EXC_SCHEMEHANDLER_NOT_REGISTERED 316
#define UIMA_MSG_ID_EXC_SCHEMEHANDLER_LOAD 317
#define UIMA_MSG_ID_EXC_SCHEMEHANDLER_GETPROC 318
#define UIMA_MSG_ID_EXC_SCHEMEHANDLER_OPEN 319
#define UIMA_MSG_ID_EXC_SOFADATASTREAM_NOTOPEN 320
#define UIMA_MSG_ID_EXC_LOCAL_SOFADATA_UNSUPPORTED_TYPE 321
#define UIMA_MSG_ID_EXC_LOCAL_SOFADATA_NOTSET 322
#define UIMA_MSG_ID_EXC_LOCAL_SOFADATA_ELEMENTSIZE 323
#define UIMA_MSG_ID_EXC_SOFADATASTREAM_INVALID_SEEK_ORIGIN 324
#define UIMA_MSG_ID_EXC_SCHEMEHANDLER_DUPLICATE 325
#define UIMA_MSG_ID_CODEPAGE_CONV_ERROR 326
#define UIMA_MSG_ID_EXC_SOFA_NAME_NOT_FOUND 327
#define UIMA_MSG_ID_EXC_INVALID_BASE_CAS_METHOD 328
#define UIMA_MSG_ID_EXC_NO_FREE_CAS 329
#define UIMA_MSG_ID_EXC_INVALID_CALL_TO_NEXT 330
#define UIMA_MSG_ID_SIGNATURE_END 331
#endif
