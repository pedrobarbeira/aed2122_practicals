# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\aed2122_p01.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\aed2122_p01.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\aed2122_p01.dir\flags.make

CMakeFiles\aed2122_p01.dir\main.cpp.obj: CMakeFiles\aed2122_p01.dir\flags.make
CMakeFiles\aed2122_p01.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aed2122_p01.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\aed2122_p01.dir\main.cpp.obj /FdCMakeFiles\aed2122_p01.dir\ /FS -c "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\main.cpp"
<<

CMakeFiles\aed2122_p01.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aed2122_p01.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\aed2122_p01.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\main.cpp"
<<

CMakeFiles\aed2122_p01.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aed2122_p01.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\aed2122_p01.dir\main.cpp.s /c "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\main.cpp"
<<

CMakeFiles\aed2122_p01.dir\Tests\tests.cpp.obj: CMakeFiles\aed2122_p01.dir\flags.make
CMakeFiles\aed2122_p01.dir\Tests\tests.cpp.obj: ..\Tests\tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aed2122_p01.dir/Tests/tests.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\aed2122_p01.dir\Tests\tests.cpp.obj /FdCMakeFiles\aed2122_p01.dir\ /FS -c "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\Tests\tests.cpp"
<<

CMakeFiles\aed2122_p01.dir\Tests\tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aed2122_p01.dir/Tests/tests.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\aed2122_p01.dir\Tests\tests.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\Tests\tests.cpp"
<<

CMakeFiles\aed2122_p01.dir\Tests\tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aed2122_p01.dir/Tests/tests.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\aed2122_p01.dir\Tests\tests.cpp.s /c "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\Tests\tests.cpp"
<<

CMakeFiles\aed2122_p01.dir\Tests\parque.cpp.obj: CMakeFiles\aed2122_p01.dir\flags.make
CMakeFiles\aed2122_p01.dir\Tests\parque.cpp.obj: ..\Tests\parque.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/aed2122_p01.dir/Tests/parque.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\aed2122_p01.dir\Tests\parque.cpp.obj /FdCMakeFiles\aed2122_p01.dir\ /FS -c "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\Tests\parque.cpp"
<<

CMakeFiles\aed2122_p01.dir\Tests\parque.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aed2122_p01.dir/Tests/parque.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\aed2122_p01.dir\Tests\parque.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\Tests\parque.cpp"
<<

CMakeFiles\aed2122_p01.dir\Tests\parque.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aed2122_p01.dir/Tests/parque.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\aed2122_p01.dir\Tests\parque.cpp.s /c "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\Tests\parque.cpp"
<<

# Object files for target aed2122_p01
aed2122_p01_OBJECTS = \
"CMakeFiles\aed2122_p01.dir\main.cpp.obj" \
"CMakeFiles\aed2122_p01.dir\Tests\tests.cpp.obj" \
"CMakeFiles\aed2122_p01.dir\Tests\parque.cpp.obj"

# External object files for target aed2122_p01
aed2122_p01_EXTERNAL_OBJECTS =

aed2122_p01.exe: CMakeFiles\aed2122_p01.dir\main.cpp.obj
aed2122_p01.exe: CMakeFiles\aed2122_p01.dir\Tests\tests.cpp.obj
aed2122_p01.exe: CMakeFiles\aed2122_p01.dir\Tests\parque.cpp.obj
aed2122_p01.exe: CMakeFiles\aed2122_p01.dir\build.make
aed2122_p01.exe: lib\gtestd.lib
aed2122_p01.exe: lib\gtest_maind.lib
aed2122_p01.exe: lib\gtestd.lib
aed2122_p01.exe: CMakeFiles\aed2122_p01.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable aed2122_p01.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\aed2122_p01.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\aed2122_p01.dir\objects1.rsp @<<
 /out:aed2122_p01.exe /implib:aed2122_p01.lib /pdb:"C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\cmake-build-debug\aed2122_p01.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  lib\gtestd.lib lib\gtest_maind.lib lib\gtestd.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\aed2122_p01.dir\build: aed2122_p01.exe

.PHONY : CMakeFiles\aed2122_p01.dir\build

CMakeFiles\aed2122_p01.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\aed2122_p01.dir\cmake_clean.cmake
.PHONY : CMakeFiles\aed2122_p01.dir\clean

CMakeFiles\aed2122_p01.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01" "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01" "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\cmake-build-debug" "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\cmake-build-debug" "C:\Users\35191\Desktop\MIEIC\2ano\1o Semestre\AEDA\Praticas\aed2122_p01\cmake-build-debug\CMakeFiles\aed2122_p01.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\aed2122_p01.dir\depend

