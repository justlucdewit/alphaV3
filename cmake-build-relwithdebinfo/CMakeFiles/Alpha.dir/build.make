# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\programming\cpp\alphav3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\programming\cpp\alphav3\cmake-build-relwithdebinfo

# Include any dependencies generated for this target.
include CMakeFiles\Alpha.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Alpha.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Alpha.dir\flags.make

CMakeFiles\Alpha.dir\main.cpp.obj: CMakeFiles\Alpha.dir\flags.make
CMakeFiles\Alpha.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Alpha.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Alpha.dir\main.cpp.obj /FdCMakeFiles\Alpha.dir\ /FS -c D:\programming\cpp\alphav3\main.cpp
<<

CMakeFiles\Alpha.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alpha.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Alpha.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\programming\cpp\alphav3\main.cpp
<<

CMakeFiles\Alpha.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alpha.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Alpha.dir\main.cpp.s /c D:\programming\cpp\alphav3\main.cpp
<<

CMakeFiles\Alpha.dir\components\fileReader\fileReader.cpp.obj: CMakeFiles\Alpha.dir\flags.make
CMakeFiles\Alpha.dir\components\fileReader\fileReader.cpp.obj: ..\components\fileReader\fileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Alpha.dir/components/fileReader/fileReader.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Alpha.dir\components\fileReader\fileReader.cpp.obj /FdCMakeFiles\Alpha.dir\ /FS -c D:\programming\cpp\alphav3\components\fileReader\fileReader.cpp
<<

CMakeFiles\Alpha.dir\components\fileReader\fileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alpha.dir/components/fileReader/fileReader.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Alpha.dir\components\fileReader\fileReader.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\programming\cpp\alphav3\components\fileReader\fileReader.cpp
<<

CMakeFiles\Alpha.dir\components\fileReader\fileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alpha.dir/components/fileReader/fileReader.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Alpha.dir\components\fileReader\fileReader.cpp.s /c D:\programming\cpp\alphav3\components\fileReader\fileReader.cpp
<<

CMakeFiles\Alpha.dir\components\errorSys\errorSys.cpp.obj: CMakeFiles\Alpha.dir\flags.make
CMakeFiles\Alpha.dir\components\errorSys\errorSys.cpp.obj: ..\components\errorSys\errorSys.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Alpha.dir/components/errorSys/errorSys.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Alpha.dir\components\errorSys\errorSys.cpp.obj /FdCMakeFiles\Alpha.dir\ /FS -c D:\programming\cpp\alphav3\components\errorSys\errorSys.cpp
<<

CMakeFiles\Alpha.dir\components\errorSys\errorSys.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alpha.dir/components/errorSys/errorSys.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Alpha.dir\components\errorSys\errorSys.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\programming\cpp\alphav3\components\errorSys\errorSys.cpp
<<

CMakeFiles\Alpha.dir\components\errorSys\errorSys.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alpha.dir/components/errorSys/errorSys.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Alpha.dir\components\errorSys\errorSys.cpp.s /c D:\programming\cpp\alphav3\components\errorSys\errorSys.cpp
<<

CMakeFiles\Alpha.dir\components\tokenSplitter\tokenSplitter.cpp.obj: CMakeFiles\Alpha.dir\flags.make
CMakeFiles\Alpha.dir\components\tokenSplitter\tokenSplitter.cpp.obj: ..\components\tokenSplitter\tokenSplitter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Alpha.dir/components/tokenSplitter/tokenSplitter.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Alpha.dir\components\tokenSplitter\tokenSplitter.cpp.obj /FdCMakeFiles\Alpha.dir\ /FS -c D:\programming\cpp\alphav3\components\tokenSplitter\tokenSplitter.cpp
<<

CMakeFiles\Alpha.dir\components\tokenSplitter\tokenSplitter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alpha.dir/components/tokenSplitter/tokenSplitter.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Alpha.dir\components\tokenSplitter\tokenSplitter.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\programming\cpp\alphav3\components\tokenSplitter\tokenSplitter.cpp
<<

CMakeFiles\Alpha.dir\components\tokenSplitter\tokenSplitter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alpha.dir/components/tokenSplitter/tokenSplitter.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Alpha.dir\components\tokenSplitter\tokenSplitter.cpp.s /c D:\programming\cpp\alphav3\components\tokenSplitter\tokenSplitter.cpp
<<

CMakeFiles\Alpha.dir\components\tokenSys\tokenSys.cpp.obj: CMakeFiles\Alpha.dir\flags.make
CMakeFiles\Alpha.dir\components\tokenSys\tokenSys.cpp.obj: ..\components\tokenSys\tokenSys.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Alpha.dir/components/tokenSys/tokenSys.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Alpha.dir\components\tokenSys\tokenSys.cpp.obj /FdCMakeFiles\Alpha.dir\ /FS -c D:\programming\cpp\alphav3\components\tokenSys\tokenSys.cpp
<<

CMakeFiles\Alpha.dir\components\tokenSys\tokenSys.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alpha.dir/components/tokenSys/tokenSys.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Alpha.dir\components\tokenSys\tokenSys.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\programming\cpp\alphav3\components\tokenSys\tokenSys.cpp
<<

CMakeFiles\Alpha.dir\components\tokenSys\tokenSys.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alpha.dir/components/tokenSys/tokenSys.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Alpha.dir\components\tokenSys\tokenSys.cpp.s /c D:\programming\cpp\alphav3\components\tokenSys\tokenSys.cpp
<<

CMakeFiles\Alpha.dir\components\configLoader\configLoader.cpp.obj: CMakeFiles\Alpha.dir\flags.make
CMakeFiles\Alpha.dir\components\configLoader\configLoader.cpp.obj: ..\components\configLoader\configLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Alpha.dir/components/configLoader/configLoader.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Alpha.dir\components\configLoader\configLoader.cpp.obj /FdCMakeFiles\Alpha.dir\ /FS -c D:\programming\cpp\alphav3\components\configLoader\configLoader.cpp
<<

CMakeFiles\Alpha.dir\components\configLoader\configLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alpha.dir/components/configLoader/configLoader.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Alpha.dir\components\configLoader\configLoader.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\programming\cpp\alphav3\components\configLoader\configLoader.cpp
<<

CMakeFiles\Alpha.dir\components\configLoader\configLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alpha.dir/components/configLoader/configLoader.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Alpha.dir\components\configLoader\configLoader.cpp.s /c D:\programming\cpp\alphav3\components\configLoader\configLoader.cpp
<<

CMakeFiles\Alpha.dir\components\typeIdentifier\typeIdentifier.cpp.obj: CMakeFiles\Alpha.dir\flags.make
CMakeFiles\Alpha.dir\components\typeIdentifier\typeIdentifier.cpp.obj: ..\components\typeIdentifier\typeIdentifier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Alpha.dir/components/typeIdentifier/typeIdentifier.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Alpha.dir\components\typeIdentifier\typeIdentifier.cpp.obj /FdCMakeFiles\Alpha.dir\ /FS -c D:\programming\cpp\alphav3\components\typeIdentifier\typeIdentifier.cpp
<<

CMakeFiles\Alpha.dir\components\typeIdentifier\typeIdentifier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alpha.dir/components/typeIdentifier/typeIdentifier.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Alpha.dir\components\typeIdentifier\typeIdentifier.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\programming\cpp\alphav3\components\typeIdentifier\typeIdentifier.cpp
<<

CMakeFiles\Alpha.dir\components\typeIdentifier\typeIdentifier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alpha.dir/components/typeIdentifier/typeIdentifier.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Alpha.dir\components\typeIdentifier\typeIdentifier.cpp.s /c D:\programming\cpp\alphav3\components\typeIdentifier\typeIdentifier.cpp
<<

CMakeFiles\Alpha.dir\components\markerExtracter\markerExtracter.cpp.obj: CMakeFiles\Alpha.dir\flags.make
CMakeFiles\Alpha.dir\components\markerExtracter\markerExtracter.cpp.obj: ..\components\markerExtracter\markerExtracter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Alpha.dir/components/markerExtracter/markerExtracter.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Alpha.dir\components\markerExtracter\markerExtracter.cpp.obj /FdCMakeFiles\Alpha.dir\ /FS -c D:\programming\cpp\alphav3\components\markerExtracter\markerExtracter.cpp
<<

CMakeFiles\Alpha.dir\components\markerExtracter\markerExtracter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alpha.dir/components/markerExtracter/markerExtracter.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Alpha.dir\components\markerExtracter\markerExtracter.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\programming\cpp\alphav3\components\markerExtracter\markerExtracter.cpp
<<

CMakeFiles\Alpha.dir\components\markerExtracter\markerExtracter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alpha.dir/components/markerExtracter/markerExtracter.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Alpha.dir\components\markerExtracter\markerExtracter.cpp.s /c D:\programming\cpp\alphav3\components\markerExtracter\markerExtracter.cpp
<<

# Object files for target Alpha
Alpha_OBJECTS = \
"CMakeFiles\Alpha.dir\main.cpp.obj" \
"CMakeFiles\Alpha.dir\components\fileReader\fileReader.cpp.obj" \
"CMakeFiles\Alpha.dir\components\errorSys\errorSys.cpp.obj" \
"CMakeFiles\Alpha.dir\components\tokenSplitter\tokenSplitter.cpp.obj" \
"CMakeFiles\Alpha.dir\components\tokenSys\tokenSys.cpp.obj" \
"CMakeFiles\Alpha.dir\components\configLoader\configLoader.cpp.obj" \
"CMakeFiles\Alpha.dir\components\typeIdentifier\typeIdentifier.cpp.obj" \
"CMakeFiles\Alpha.dir\components\markerExtracter\markerExtracter.cpp.obj"

# External object files for target Alpha
Alpha_EXTERNAL_OBJECTS =

Alpha.exe: CMakeFiles\Alpha.dir\main.cpp.obj
Alpha.exe: CMakeFiles\Alpha.dir\components\fileReader\fileReader.cpp.obj
Alpha.exe: CMakeFiles\Alpha.dir\components\errorSys\errorSys.cpp.obj
Alpha.exe: CMakeFiles\Alpha.dir\components\tokenSplitter\tokenSplitter.cpp.obj
Alpha.exe: CMakeFiles\Alpha.dir\components\tokenSys\tokenSys.cpp.obj
Alpha.exe: CMakeFiles\Alpha.dir\components\configLoader\configLoader.cpp.obj
Alpha.exe: CMakeFiles\Alpha.dir\components\typeIdentifier\typeIdentifier.cpp.obj
Alpha.exe: CMakeFiles\Alpha.dir\components\markerExtracter\markerExtracter.cpp.obj
Alpha.exe: CMakeFiles\Alpha.dir\build.make
Alpha.exe: CMakeFiles\Alpha.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Alpha.exe"
	"C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Alpha.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Alpha.dir\objects1.rsp @<<
 /out:Alpha.exe /implib:Alpha.lib /pdb:D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\Alpha.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Alpha.dir\build: Alpha.exe

.PHONY : CMakeFiles\Alpha.dir\build

CMakeFiles\Alpha.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Alpha.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Alpha.dir\clean

CMakeFiles\Alpha.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\programming\cpp\alphav3 D:\programming\cpp\alphav3 D:\programming\cpp\alphav3\cmake-build-relwithdebinfo D:\programming\cpp\alphav3\cmake-build-relwithdebinfo D:\programming\cpp\alphav3\cmake-build-relwithdebinfo\CMakeFiles\Alpha.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Alpha.dir\depend

