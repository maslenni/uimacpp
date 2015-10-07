set(TARGET_NAME libapr-1)
set(apr_headers ${CMAKE_CURRENT_LIST_DIR})

if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")
endif()

add_library(${TARGET_NAME} ${LIBRARY_TYPE}
    ${apr_headers}/apr_allocator.h
    ${apr_headers}/apr_atomic.h
    ${apr_headers}/apr_dso.h
    ${apr_headers}/apr_env.h
    ${apr_headers}/apr_errno.h
    ${apr_headers}/apr_file_info.h
    ${apr_headers}/apr_file_io.h
    ${apr_headers}/apr_fnmatch.h
    ${apr_headers}/apr_general.h
    ${apr_headers}/apr_getopt.h
    ${apr_headers}/apr_global_mutex.h
    ${apr_headers}/apr.h
    ${apr_headers}/apr_hash.h
    ${apr_headers}/apr_inherit.h
    ${apr_headers}/apr_lib.h
    ${apr_headers}/apr_mmap.h
    ${apr_headers}/apr_network_io.h
    ${apr_headers}/apr_poll.h
    ${apr_headers}/apr_pools.h
    ${apr_headers}/apr_portable.h
    ${apr_headers}/apr_proc_mutex.h
    ${apr_headers}/apr_random.h
    ${apr_headers}/apr_ring.h
    ${apr_headers}/apr_shm.h
    ${apr_headers}/apr_signal.h
    ${apr_headers}/apr_strings.h
    ${apr_headers}/apr_support.h
    ${apr_headers}/apr_tables.h
    ${apr_headers}/apr_thread_cond.h
    ${apr_headers}/apr_thread_mutex.h
    ${apr_headers}/apr_thread_proc.h
    ${apr_headers}/apr_thread_rwlock.h
    ${apr_headers}/apr_time.h
    ${apr_headers}/apr_user.h
    ${apr_headers}/apr_version.h
    ${apr_headers}/apr_want.h
)
