set(TARGET_NAME unicode)
set(source_dir ${CMAKE_CURRENT_LIST_DIR}/sources)
set(header_dir ${CMAKE_CURRENT_LIST_DIR})

if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")
endif()

add_definitions(-DU_HAVE_NAMESPACE=0)

#link_directories(${source_dir})

set(unicode_sources
    ${source_dir}/cmemory.c
    ${source_dir}/cmemory.h
    ${source_dir}/cstring.c
    ${source_dir}/cstring.h
    ${source_dir}/cwchar.c
    ${source_dir}/cwchar.h
    ${source_dir}/locmap.c
    ${source_dir}/locmap.h
    ${source_dir}/putil.c
    ${source_dir}/putilimp.h
    ${source_dir}/uarrsort.c
    ${source_dir}/uarrsort.h
    ${source_dir}/uassert.h
    ${source_dir}/ubidi_props_data.c
    ${source_dir}/ubidi_props.c
    ${source_dir}/ubidi_props.h
    ${source_dir}/ucase_props_data.c
    ${source_dir}/ucase.c
    ${source_dir}/ucase.h
    ${source_dir}/uchar.c
    ${source_dir}/ucmndata.c
    ${source_dir}/ucmndata.h
    ${source_dir}/ucln.h
    ${source_dir}/ucln_cmn.c
    ${source_dir}/ucln_cmn.h
    ${source_dir}/ucnv.c
    ${source_dir}/ucnv_bld.c
    ${source_dir}/ucnv_bld.h
    ${source_dir}/ucnv_cb.c
    ${source_dir}/ucnv_cnv.c
    ${source_dir}/ucnv_cnv.h
    ${source_dir}/ucnv_err.c
    ${source_dir}/ucnv_ext.c
    ${source_dir}/ucnv_ext.h
    ${source_dir}/ucnv_imp.h
    ${source_dir}/ucnv_io.c
    ${source_dir}/ucnv_io.h
    ${source_dir}/ucnv_lmb.c
    ${source_dir}/ucnv_u7.c
    ${source_dir}/ucnv_u8.c
    ${source_dir}/ucnv_u16.c
    ${source_dir}/ucnv_u32.c
    ${source_dir}/ucnv2022.c
    ${source_dir}/ucnvhz.c
    ${source_dir}/ucnvbocu.c
    ${source_dir}/ucnvisci.c
    ${source_dir}/ucnvmbcs.c
    ${source_dir}/ucnvlat1.c
    ${source_dir}/ucnvmbcs.h
    ${source_dir}/ucnvscsu.c
#    ${source_dir}/ucudt_dat
    ${source_dir}/udata.c
    ${source_dir}/udataswp.c
    ${source_dir}/udataswp.h
    ${source_dir}/udatamem.c
    ${source_dir}/udatamem.h
    ${source_dir}/uenumimp.h
    ${source_dir}/uenum.c
    ${source_dir}/uhash.c
    ${source_dir}/uhash.h
    ${source_dir}/uinit.c
    ${source_dir}/uinvchar.c
    ${source_dir}/uinvchar.h
    ${source_dir}/umath.c
    ${source_dir}/umapfile.c
    ${source_dir}/umapfile.h
    ${source_dir}/umutex.c
    ${source_dir}/umutex.h
    ${source_dir}/unistr.cpp
    ${source_dir}/unistr_cnv.cpp
    ${source_dir}/unistr_props.cpp
    ${source_dir}/uchar_props_data.c
    ${source_dir}/uprops.c
    ${source_dir}/uprops.h
    ${source_dir}/unormimp.h
    ${source_dir}/uobject.cpp
    ${source_dir}/ustr_cnv.c
    ${source_dir}/ustr_cnv.h
    ${source_dir}/uset_imp.h
    ${source_dir}/ustr_imp.h
    ${source_dir}/ustrfmt.c
    ${source_dir}/ustrfmt.h
    ${source_dir}/ustring.c
    ${source_dir}/ustrtrns.c
    ${source_dir}/utf_impl.c
    ${source_dir}/utrace.c
    ${source_dir}/utrie.c
    ${source_dir}/utrie.h
    ${source_dir}/utracimp.h
    ${source_dir}/uiter.cpp
)

set(unicode_headers
    ${header_dir}/chariter.h
#    ${header_dir}/help.h
    ${header_dir}/ucnv.h
    ${header_dir}/ucnv_cb.h
    ${header_dir}/ucnv_err.h
    ${header_dir}/udata.h
    ${header_dir}/uenum.h
    ${header_dir}/uiter.h
    ${header_dir}/umachine.h
    ${header_dir}/unistr1.h
    ${header_dir}/uobject.h
    ${header_dir}/urename.h
    ${header_dir}/ustring.h
    ${header_dir}/utypes.h
    ${header_dir}/utrace.h
    ${header_dir}/putil.h

)

add_library(${TARGET_NAME} ${LIBRARY_TYPE} ${unicode_sources} ${unicode_headers})

