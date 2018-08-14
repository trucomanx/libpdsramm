#-------------------------------------------------
#
# Project created by QtCreator 2018-07-31T21:01:42
#
#-------------------------------------------------

QT       -= gui

TARGET = pdsramm
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = lib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_CFLAGS   += -Wall
QMAKE_CXXFLAGS += -Wall
################################################################################
## CODE SCRIPT
################################################################################
SOURCES += $$files(../../src/biblioteca/*.cpp)

HEADERS += $$files(../../src/headers/pds/*.hpp)


INCLUDEPATH += ../../src/headers

INCLUDEPATH += "$${PREFIX}/include"
#LIBS        += -L"$${PREFIX}/lib"


################################################################################
## PREFIX SCRIPT
################################################################################

win32:DEFINES += __OS_WINDOWS__
unix:DEFINES += __OS_UNIX__

isEmpty(PREFIX) {
    win32:PREFIX = c:\\usr\\local
    unix:PREFIX = /usr/local
    message("")
    message("To change the current 'make install' path, write: qmake PREFIX=$${PREFIX}")
}

message("The current 'make install' path is $$PREFIX")

################################################################################
## INSTALL SCRIPT
################################################################################

## MYLIB
mylib.path   = "$$PREFIX/lib"
mylib.files += "$${OUT_PWD}/lib/lib$${TARGET}.a"


# MYHEADERS
headers.path   = "$$PREFIX/include/pds"
headers.files += $${HEADERS}


# Install: MYLIB MYHEADERS
INSTALLS    += mylib headers


################################################################################
## INFO
################################################################################
APPARCHITECTURE = $${QMAKE_HOST.arch}
equals(APPARCHITECTURE , "x86_64") {
    APPARCHITECTURE = "amd64"
}
equals(APPARCHITECTURE , "x86") {
    APPARCHITECTURE = "i386"
}
equals(APPARCHITECTURE , "i686") {
    APPARCHITECTURE = "i386"
}


message("")
message(" Program filename: $$TARGET")
message(" Host architecture $${QMAKE_HOST.arch}: $$APPARCHITECTURE")
message("")
message(" Header to install:")
message(" $${headers.path}")
message(" $${headers.files}")
message("")
message(" Static lib to install:")
message(" $${mylib.path}")
message(" $${mylib.files}")
message("")

