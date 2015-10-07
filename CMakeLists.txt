project(uimacpp)

cmake_minimum_required(VERSION 2.6)

#set(LIBRARY_TYPE SHARED)
set(LIBRARY_TYPE STATIC)
#set(CMAKE_DISABLE_SOURCE_CHANGES ON)
#set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(ENV{UIMA_VERSION} "2.4.0")

if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -c ")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11") #TODO:  -Wconversion -Weffc++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb3")

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps -dD")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLINUX=2 -D_REENTRANT -D_GNU_SOURCE -D_LARGEFILE64_SOURCE")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DU_COMBINED_IMPLEMENTATION -DUNISTR_FROM_STRING_EXPLICIT=explicit")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DU_COMBINED_IMPLEMENTATION")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
endif()

add_definitions(-D__STDC_LIMIT_MACROS)

set(CMAKE_C_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(CAS src/cas)
set(FRAMEWORK src/framework)
set(JNI src/jni)
set(UTILS src/utils)

include_directories(
    include
    include/apr-1
    #include/uima
    include/unicode
    #include/xercesc
    lib
    src
    src/cas
    src/framework
    src/jni
#    src/utils
    /usr/lib/jvm/java-7-oracle/include
    /usr/lib/jvm/java-7-oracle/include/linux
    # for xerces
    /usr/lib
    # for icu
    /usr/lib/x86_64-linux-gnu
)

add_subdirectory(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/examples/src)

set(SOURCES
      ${FRAMEWORK}/annotator_context.cpp
      ${FRAMEWORK}/annotator.cpp
      ${FRAMEWORK}/annotator_mgr.cpp
      ${FRAMEWORK}/casdefinition.cpp
      ${FRAMEWORK}/casiterator.cpp
      ${FRAMEWORK}/caspool.cpp
      ${FRAMEWORK}/config_param.cpp
      ${FRAMEWORK}/consoleui.cpp
      ${FRAMEWORK}/cp2ucnvrt.cpp
      ${FRAMEWORK}/dottypesystemwriter.cpp
      ${FRAMEWORK}/engine.cpp
      ${FRAMEWORK}/exceptions.cpp
      ${FRAMEWORK}/ftools.cpp
      ${FRAMEWORK}/internal_aggregate_engine.cpp
      ${FRAMEWORK}/internal_capability_container.cpp
      ${FRAMEWORK}/internal_engine_base.cpp
      ${FRAMEWORK}/internal_jedii_engine.cpp
      ${FRAMEWORK}/internal_primitive_engine.cpp
      ${FRAMEWORK}/language.cpp
      ${FRAMEWORK}/log.cpp
      ${FRAMEWORK}/res_abase.cpp
      ${FRAMEWORK}/res_annotator.cpp
      ${FRAMEWORK}/resmgr.cpp
      ${FRAMEWORK}/strtools.cpp
      ${FRAMEWORK}/taemetadata.cpp
      ${FRAMEWORK}/taespecifierbuilder.cpp
      ${FRAMEWORK}/taespecifier.cpp
      ${FRAMEWORK}/timedatetools.cpp
      ${FRAMEWORK}/token_properties.cpp
      ${FRAMEWORK}/typesystemdescription.cpp
      ${FRAMEWORK}/u2cpcnvrt.cpp
      ${FRAMEWORK}/unistrref.cpp


      ${CAS}/arrayfs.cpp
      ${CAS}/cas.cpp
      ${CAS}/casexception.cpp
      ${CAS}/caswriter_abase.cpp
      ${CAS}/featurestructure.cpp
      ${CAS}/fsfilterbuilder.cpp
      ${CAS}/fsindex.cpp
      ${CAS}/fsindexrepository.cpp
      ${CAS}/fsiterator.cpp
      ${CAS}/internal_casdeserializer.cpp
      ${CAS}/internal_casimpl.cpp
      ${CAS}/internal_casserializer.cpp
      ${CAS}/internal_fspromoter.cpp
      ${CAS}/internal_serializedcas.cpp
      ${CAS}/internal_typeshortcuts.cpp
      ${CAS}/internal_xmlconstants.cpp
      ${CAS}/listfs.cpp
      ${CAS}/lowlevel_fsheap.cpp
      ${CAS}/lowlevel_indexcomparator.cpp
      ${CAS}/lowlevel_index.cpp
      ${CAS}/lowlevel_indexdefinition.cpp
      ${CAS}/lowlevel_indexrepository.cpp
      ${CAS}/lowlevel_internal_indexes.cpp
      ${CAS}/lowlevel_typesystem.cpp
      ${CAS}/sofastream.cpp
      ${CAS}/typenamespace.cpp
      ${CAS}/typesystem.cpp


      ${CAS}/xcasdeserializer.cpp
      ${CAS}/xcasdeserializer_handler.cpp
      ${CAS}/xmlerror_handler.cpp
      ${CAS}/xmltypesystemreader.cpp
      ${CAS}/xmltypesystemwriter.cpp
      ${CAS}/xmlwriter.cpp

      ${JNI}/jni.cpp
      ${JNI}/jni_string.cpp
      ${JNI}/jni_utils.cpp

      ${CAS}/xmideserializer.cpp
      ${CAS}/xmideserializer_handler.cpp
      ${CAS}/xmiwriter.cpp



      # my addition
#      ${UTILS}/deployCppService.cpp
#      ${UTILS}/ActiveMQAnalysisEngineService.cpp
      ${UTILS}/runAECpp.cpp




    )

    set(HEADERS
      ${FRAMEWORK}/uima/annotator.hpp
      ${FRAMEWORK}/uima/annotator_abase.hpp
      ${FRAMEWORK}/uima/annotator_aux.hpp
      ${FRAMEWORK}/uima/annotator_context.hpp
      ${FRAMEWORK}/uima/annotator_mgr.hpp
      ${FRAMEWORK}/uima/annotator_timing.hpp
      ${FRAMEWORK}/uima/assertmsg.h
      ${FRAMEWORK}/uima/capability.hpp
      ${FRAMEWORK}/uima/casdefinition.hpp
      ${FRAMEWORK}/uima/casiterator.hpp
      ${FRAMEWORK}/uima/caspool.hpp
      ${FRAMEWORK}/uima/caswriter_abase.hpp
      ${FRAMEWORK}/uima/ccsid.hpp
      ${FRAMEWORK}/uima/comp_ids.h
      ${FRAMEWORK}/uima/config_param.hpp
      ${FRAMEWORK}/uima/configure.h
      ${FRAMEWORK}/uima/consoleui.hpp
      ${FRAMEWORK}/uima/cp2ucnvrt.hpp
      ${FRAMEWORK}/uima/dirwalk.hpp
      ${FRAMEWORK}/uima/dllfile.hpp
      ${FRAMEWORK}/uima/dottypesystemwriter.hpp
      ${FRAMEWORK}/uima/endian1.h
      ${FRAMEWORK}/uima/engine.hpp
      ${FRAMEWORK}/uima/engine_state.hpp
      ${FRAMEWORK}/uima/envvar.hpp
      ${FRAMEWORK}/uima/envvars.h
      ${FRAMEWORK}/uima/err_ids.h
      ${FRAMEWORK}/uima/exceptions.hpp
      ${FRAMEWORK}/uima/filename.hpp
#      ${FRAMEWORK}/uima/filter_abase.hpp
      ${FRAMEWORK}/uima/ftools.hpp
      ${FRAMEWORK}/uima/importdescription.hpp
      ${FRAMEWORK}/uima/internal_aggregate_engine.hpp
      ${FRAMEWORK}/uima/internal_capability_container.hpp
      ${FRAMEWORK}/uima/internal_engine_base.hpp
      ${FRAMEWORK}/uima/internal_jedii_engine.hpp
      ${FRAMEWORK}/uima/internal_primitive_engine.hpp
      ${FRAMEWORK}/uima/language.hpp
      ${FRAMEWORK}/uima/location.hpp
      ${FRAMEWORK}/uima/log.hpp
      ${FRAMEWORK}/uima/macros.h
      ${FRAMEWORK}/uima/msg.h
      ${FRAMEWORK}/uima/msgstrtab.h
      ${FRAMEWORK}/uima/pragmas.hpp
      ${FRAMEWORK}/uima/res_abase.hpp
      ${FRAMEWORK}/uima/res_annotator.hpp
      ${FRAMEWORK}/uima/resmgr.hpp
      ${FRAMEWORK}/uima/result_specification.hpp
      ${FRAMEWORK}/uima/sofamapping.hpp
      ${FRAMEWORK}/uima/stltools.hpp
      ${FRAMEWORK}/uima/strconvert.hpp
      ${FRAMEWORK}/uima/strtools.hpp
      ${FRAMEWORK}/uima/taemetadata.hpp
      ${FRAMEWORK}/uima/taespecifier.hpp
      ${FRAMEWORK}/uima/taespecifierbuilder.hpp
      ${FRAMEWORK}/uima/text.h
      ${FRAMEWORK}/uima/timedatetools.hpp
      ${FRAMEWORK}/uima/token_properties.hpp
      ${FRAMEWORK}/uima/trace.hpp
      ${FRAMEWORK}/uima/types.h
      ${FRAMEWORK}/uima/typesystemdescription.hpp
      ${FRAMEWORK}/uima/u2cpcnvrt.hpp
      ${FRAMEWORK}/uima/unistrref.hpp



      ${CAS}/uima/annotator_generic.inl
      ${CAS}/uima/arrayfs.hpp
      ${CAS}/uima/cas.hpp
      ${CAS}/uima/casconsumer_generic.inl
      ${CAS}/uima/casexception.hpp
      ${CAS}/uima/featurestructure.hpp
      ${CAS}/uima/fsfilterbuilder.hpp
      ${CAS}/uima/fsindex.hpp
      ${CAS}/uima/fsindexrepository.hpp
      ${CAS}/uima/fsiterator.hpp
      ${CAS}/uima/internal_casdeserializer.hpp
      ${CAS}/uima/internal_casimpl.hpp
      ${CAS}/uima/internal_casserializer.hpp
      ${CAS}/uima/internal_fspromoter.hpp
      ${CAS}/uima/internal_fsvalue_accessors.hpp
      ${CAS}/uima/internal_serializedcas.hpp
#      ${CAS}/uima/internal_tcasimpl.hpp
      ${CAS}/uima/internal_typeshortcuts.hpp
      ${CAS}/uima/internal_xmlconstants.hpp
      ${CAS}/uima/listfs.hpp
      ${CAS}/uima/lowlevel_defaultfsiterator.hpp
      ${CAS}/uima/lowlevel_fsfilter.hpp
      ${CAS}/uima/lowlevel_fsheap.hpp
      ${CAS}/uima/lowlevel_index.hpp
      ${CAS}/uima/lowlevel_indexcomparator.hpp
      ${CAS}/uima/lowlevel_indexdefinition.hpp
      ${CAS}/uima/lowlevel_indexiterator.hpp
      ${CAS}/uima/lowlevel_indexrepository.hpp
      ${CAS}/uima/lowlevel_internal_heap.hpp
      ${CAS}/uima/lowlevel_internal_indexes.hpp
      ${CAS}/uima/lowlevel_internal_indexfactory.hpp
      ${CAS}/uima/lowlevel_typedefs.hpp
      ${CAS}/uima/lowlevel_typesystem.hpp
      ${CAS}/uima/sofaid.hpp
      ${CAS}/uima/sofastream.hpp
      ${CAS}/uima/sofastreamhandler.hpp
#      ${CAS}/uima/tcas.hpp

      ${CAS}/uima/xcasdeserializer.hpp
      ${CAS}/uima/xcasdeserializer_handler.hpp
      ${CAS}/uima/xmideserializer.hpp
      ${CAS}/uima/xmideserializer_handler.hpp
      ${CAS}/uima/xmishareddata.hpp
      ${CAS}/uima/xmiwriter.hpp
      ${CAS}/uima/xmlerror_handler.hpp
      ${CAS}/uima/xmltypesystemreader.hpp
      ${CAS}/uima/xmltypesystemwriter.hpp
      ${CAS}/uima/xmlwriter.hpp
      ${CAS}/uima/typesystem.hpp


      ${CAS}/uima/type_or_feature.hpp
      ${CAS}/uima/typenamespace.hpp
      ${JNI}/uima/jni.hpp
      ${JNI}/uima/jni_string.hpp
      ${JNI}/uima/jni_utils.hpp
#      ${FRAMEWORK}/uima/annotator_generic.inl
#      ${JNI}/uima/com_ibm_itu_JTafEngine.h

      # my addition
#      ${UTILS}/deployCppService.hpp
#      ${UTILS}/ActiveMQAnalysisEngineService.hpp
)
add_library(uima STATIC ${SOURCES} ${HEADERS})
#add_library(icu STATIC IMPORTED)
#set_target_properties(icu PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
#set_property(TARGET icu PROPERTY IMPORTED_LOCATION /home/steve/projects/uimaAnalyzer/uimacpp-2.4.0-rc7/lib/libicuio.so)
#set_property(TARGET icu PROPERTY IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libicuio.so.52)

add_executable(uimacpp ${UTILS}/runAECpp.cpp)
#target_link_libraries(uimacpp lib/libapr-1 lib/libxerces-c lib/libuima lib/libicuuc)

find_library(APR-1 apr-1 HINTS lib)
find_library(XERCES xerces-c HINTS lib)
#find_library(ICUDATA icudata PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32" HINTS /home/steve/projects/uimaAnalyzer/uimacpp-2.4.0-rc7/lib)
#find_library(ICUDATA icudata HINTS /home/steve/projects/uimaAnalyzer/uimacpp-2.4.0-rc7/lib)
#find_library(ICUIO icuio HINTS /home/steve/projects/uimaAnalyzer/uimacpp-2.4.0-rc7/lib)
#find_library(ICUUC icuuc HINTS /home/steve/projects/uimaAnalyzer/uimacpp-2.4.0-rc7/lib PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
#find_library(ICU LIBRARY   NAMES icuio HINTS lib)
#find_library(ICU LIBRARY NAMES libicuio.so HINTS /usr/lib/x86_64-linux-gnu/)
#target_link_libraries(uimacpp ${APR-1} UIMA /usr/lib/x86_64-linux-gnu/libicuio.so.52)
#target_link_libraries(uimacpp ${APR-1} UIMA /home/steve/projects/uimaAnalyzer/uimacpp-2.4.0-rc7/lib/libicuio.so)
target_link_libraries(uimacpp ${APR-1} ${XERCES} uima unicode)
#target_link_libraries(uimacpp ${APR-1} ${XERCES} ${ICUDATA} ${ICUIO} ${ICUUC} UIMA )
#target_link_libraries(uimacpp ${APR-1} ${XERCES} ${ICUDATA} ${ICUIO} UIMA )

