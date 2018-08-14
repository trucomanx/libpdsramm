cmake_minimum_required(VERSION 3.5) 
project(testprograms)

include_directories(${CMAKE_SOURCE_DIR}/src/headers)

add_executable(exampleprog exampleprog.cpp)
target_link_libraries(exampleprog lib${PROJECT_LIB_ABBREVIATION}_static ${TARGET_EXTRA_LINK})

file(GLOB TEST_FILES
    "test*.cpp"
)


MESSAGE(STATUS "++")
FOREACH(FILEPATH ${TEST_FILES})
    get_filename_component(MYFILENAME ${FILEPATH} NAME)
    get_filename_component(MYBASENAME ${FILEPATH} NAME_WE)
    MESSAGE(STATUS "++  Adding test program           : ${MYFILENAME}")

    add_executable(${MYBASENAME} ${MYFILENAME})
    target_link_libraries(${MYBASENAME} lib${PROJECT_LIB_ABBREVIATION}_static ${TARGET_EXTRA_LINK})
ENDFOREACH()

