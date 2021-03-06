
# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/../test/example.cpp" PROJECT_EXAMPLE)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_MAINPAGE_IN  "${CMAKE_CURRENT_SOURCE_DIR}/Doxymainpage.h.in")
    set(DOXYGEN_MAINPAGE_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxymainpage.h")
    configure_file(${DOXYGEN_MAINPAGE_IN} ${DOXYGEN_MAINPAGE_OUT} @ONLY)

    set(DOXYGEN_IN  ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    message(STATUS "++")
    message(STATUS "++  Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

