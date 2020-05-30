cmake_minimum_required(VERSION 3.5) 
project(testprograms)

include_directories(${CMAKE_SOURCE_DIR}/src/headers)

file(GLOB TEST_FILES
    "test*.cpp"
)

file(GLOB EXAMPLE_FILES
    "example*.cpp"
)

MESSAGE(STATUS "++")
FOREACH(FILEPATH ${TEST_FILES})
    get_filename_component(MYFILENAME ${FILEPATH} NAME)
    get_filename_component(MYBASENAME ${FILEPATH} NAME_WE)
    MESSAGE(STATUS "++  Adding test program           : ${MYFILENAME}")

    add_executable(${MYBASENAME} ${MYFILENAME})
    target_link_libraries(${MYBASENAME} lib${PROJECT_LIB_ABBREVIATION}_static ${TARGET_EXTRA_LINK})
ENDFOREACH()

MESSAGE(STATUS "++")
FOREACH(FILEPATH ${EXAMPLE_FILES})
    get_filename_component(MYFILENAME ${FILEPATH} NAME)
    get_filename_component(MYBASENAME ${FILEPATH} NAME_WE)
    MESSAGE(STATUS "++  Adding example program           : ${MYFILENAME}")

    add_executable(${MYBASENAME} ${MYFILENAME})
    target_link_libraries(${MYBASENAME} lib${PROJECT_LIB_ABBREVIATION}_static ${TARGET_EXTRA_LINK})
ENDFOREACH()


