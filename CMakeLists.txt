# mkdir build
# cd build
# cmake -DCMAKE_INSTALL_PREFIX=/home/fernando/testing ..
# make
# make install

cmake_minimum_required(VERSION 3.5) 
include(GNUInstallDirs)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


################################################################################
## Describing the project
################################################################################
project(libpdsramm 
        LANGUAGES CXX
        VERSION 0.1.0 
)

set(PROJECT_DESCRIPTION       "C++ Library to work with real arrays")
set(PROJECT_LIB_ABBREVIATION  "pdsramm")
set(PROJECT_HEADER_ABBREVIATION  "Ra")
set(PROJECT_COMMENT           "PDS Real Arrays in C++")
set(PROJECT_URL               "http://www.nongnu.org/pdsplibrary/")
# Requires
set(DEBPACK_REQUIRES          "")# "libpdsramm-dev, libpdsba-dev") # Acording deb names
set(PKGCONFIG_REQUIRES        "")# "libpdsramm, libpdsba")         # Acording pkgconfig names
# Pkg-config private
set(PKGCONFIG_LIB_PRIVATE     "") # "libpdsramm, libpdsba")         # Acording pkgconfig names
# Compiling library and examples
set(TARGET_EXTRA_LINK         "")
# Compiling manually
set(DEVELOP_EXTRA_STATIC_LINK "")
set(DEVELOP_EXTRA_SHARED_LINK "")

################################################################################
## Architecture
################################################################################
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
    # set(LIBSUFFIX "64") 
    set(DEBFILE_ARCH "amd64")
else() 
    # set(LIBSUFFIX "") 
    set(DEBFILE_ARCH "i386")
endif()

################################################################################
## Sources files
################################################################################
file(GLOB SOURCE_FILES
    src/biblioteca/*.cpp
)

file(GLOB HEADER_FILES 
    src/headers/pds/*.hpp
)
include_directories(src/headers ${ADD_INCLUDE_DIRECTORY})

add_library(${PROJECT_NAME}_shared SHARED ${SOURCE_FILES})

add_library(${PROJECT_NAME}_static STATIC ${SOURCE_FILES})

set_target_properties(  ${PROJECT_NAME}_shared  PROPERTIES 
                        OUTPUT_NAME             ${PROJECT_LIB_ABBREVIATION}
                        VERSION                 ${PROJECT_VERSION}
                    )
set_target_properties(  ${PROJECT_NAME}_static  PROPERTIES
                        OUTPUT_NAME             ${PROJECT_LIB_ABBREVIATION} 
                        VERSION                 ${PROJECT_VERSION}
                    )
target_link_libraries(${PROJECT_NAME}_shared ${TARGET_EXTRA_LINK} ${ADD_LIB_DIRECTORY})
target_link_libraries(${PROJECT_NAME}_static ${TARGET_EXTRA_LINK} ${ADD_LIB_DIRECTORY})

set(DOC_FILES 
    ${CMAKE_BINARY_DIR}/doc/README.md
)

################################################################################
## Archivos de configuracion
################################################################################
configure_file(pkgconfigdat.pc.in ${PROJECT_NAME}.pc @ONLY)
configure_file(doc/README.md.in   doc/README.md @ONLY)

################################################################################
## Install
################################################################################


install(TARGETS     ${PROJECT_NAME}_shared 
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(TARGETS     ${PROJECT_NAME}_static 
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES       ${HEADER_FILES}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/pds
)

# pkgconfig
install(FILES       ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc 
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

# doc
install(FILES       ${DOC_FILES} 
        DESTINATION ${CMAKE_INSTALL_DOCDIR}/${PROJECT_NAME}
)

################################################################################
## Make dist
################################################################################
add_subdirectory(package)

################################################################################
## DOXYGEN
################################################################################
add_subdirectory(manual)

################################################################################
## Test programs
################################################################################
add_subdirectory(test)

################################################################################
## Final messages
################################################################################

MESSAGE(STATUS "++  ")
MESSAGE(STATUS "++  Detecting architecture        : ${DEBFILE_ARCH}") 
MESSAGE(STATUS "++  La biblioteca se instalará en : ${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "++  Para cambiar esta opción      : cmake /path/of/source/code -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "++  ")

################################################################################
## Macro defines
################################################################################

add_definitions(-DPDS_LIBRARY_VERSION=\"${PROJECT_VERSION}\")
add_definitions(-DPDS_LIBRARY_PACKAGE=\"${PROJECT_NAME}\")

