# README

## I) INSTALL STEPS

### Step 1: Create a working directory

	mkdir build
	cd build
### Step 2: Configure de project
Configure defining the install path in '/install/test/path'

	cmake -DCMAKE_INSTALL_PREFIX=/install/test/path  ..

Or without define the install path, by default the install path is  '/usr/local'

	cmake ..

To add a specific path to the headers and libraries
	cmake .. -DADD_INCLUDE_DIRECTORY="/some/directory/include" -DADD_LIB_DIRECTORY="-L/some/directory/lib"
		
### Step 3: Compile the library and install
	
#### In GNU/Linux

	make
	make install

#### In WINDOWS

	cmake --build . --config Release
	cmake --build . --config Release --target INSTALL


## II) PACKAGE BUILDING
After made the steps 1 and 2, 

### Step X: Creating a source package
Generate a PACKAGE-VERSION.tar.gz file

	make package_source

If necessary you can generate a detached GPG binary signature for the file PACKAGE-VERSION.tar.gz
	
	gpg -b --use-agent PACKAGE-VERSION.tar.gz
	
To verify it:

	gpg --verify PACKAGE-VERSION.tar.gz.sig
### Step Y: Creating a *.deb package
Generate a *.deb file, but require that -DCMAKE_INSTALL_PREFIX=/usr (Step 2)

	make package
	
	
### Step Z: Creating a windows package

Build release version from the command line

	cmake --build . --config Release


Build setup package from the command line

	
	cmake --build . --config Release --target INSTALL


## III) ADDITIONAL NOTES

In Windows the CPack generators normally include 

    NSIS - (Nullsoft Scriptable Install System) - Generates an installer EXE - see nsis.sourceforge - needs to be installed.

 