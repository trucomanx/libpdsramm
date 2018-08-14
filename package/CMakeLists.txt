
if (WIN32)

    if (USE_NSIS_TOOLSET)
        # this needs NSIS installed, and available
        set(CPACK_GENERATOR "NSIS") 
        # If this is set to “ON”, then an extra page will appear in the installer 
        # that will allow the user to choose whether the program directory should 
        # be added to the system PATH variable.
        set(CPACK_NSIS_MODIFY_PATH ON)
        set(CPACK_NSIS_URL_INFO_ABOUT "http://www.nongnu.org/pdsplibrary/${PROJECT_NAME}/refman/html/index.html")
        set(CPACK_NSIS_HELP_LINK "http://www.nongnu.org/pdsplibrary/${PROJECT_NAME}/refman/html/index.html")
        set(CPACK_NSIS_INSTALL_ROOT   "C:\\")

        set(CPACK_PACKAGE_INSTALL_DIRECTORY   "user")
        set(CPACK_PACKAGE_NAME                "${PROJECT_NAME}-dev")
        set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_DESCRIPTION}")
        set(CPACK_PACKAGE_VERSION             "${PROJECT_VERSION}")

    endif ()
    set(CPACK_SOURCE_GENERATOR "ZIP")

else ()

    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_NAME           "${PROJECT_NAME}-dev")
    set(CPACK_DEBIAN_PACKAGE_SOURCE         "${PROJECT_NAME}")
    set(CPACK_DEBIAN_PACKAGE_VERSION        "${PROJECT_VERSION}")
    set(CPACK_DEBIAN_PACKAGE_SECTION        "libdevel")
    set(CPACK_DEBIAN_PACKAGE_HOMEPAGE       "${PROJECT_URL}")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS        "${DEBPACK_REQUIRES}")
    set(CPACK_DEBIAN_PACKAGE_DESCRIPTION    "${PROJECT_COMMENT}\n ${PROJECT_DESCRIPTION}")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER     "Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>") #required

    set(CPACK_SOURCE_GENERATOR "TGZ")

endif ()
set(CPACK_PACKAGE_VENDOR           "http://www.nongnu.org/pdsplibrary/")
set(CPACK_PACKAGE_FILE_NAME        "${PROJECT_NAME}-${PROJECT_VERSION}_${DEBFILE_ARCH}")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}")
set(CPACK_SOURCE_IGNORE_FILES      "/build/;/.bzr/;/.bzrignore;/.git/;/.gitignore;~$;${CPACK_SOURCE_IGNORE_FILES}")

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README  "${CMAKE_SOURCE_DIR}/README.md")

include(CPack)

