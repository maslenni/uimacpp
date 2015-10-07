set(TARGET_NAME myuimacomponent)
set(source_dir ${CMAKE_CURRENT_LIST_DIR})

set(CMAKE_BUILD_TYPE Release)

if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")
endif()

set(component_sources
    ${source_dir}/DaveDetector.cpp
#    ${source_dir}/ExampleApplication.cpp
#    ${source_dir}/SofaDataAnnotator.cpp
#    ${source_dir}/SofaExampleAnnotator.cpp
#    ${source_dir}/SofaExampleApplication.cpp
#    ${source_dir}/XCasWriterCasConsumer.cpp
)

add_library(${TARGET_NAME} SHARED ${component_sources})
add_executable(componentexe ExampleApplication.cpp)
target_link_libraries(componentexe uima ${APR-1} ${XERCES} unicode)