# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Github\DataStructure\Sorting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Github\DataStructure\Sorting\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Sorting.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Sorting.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Sorting.dir\flags.make

CMakeFiles\Sorting.dir\BubbleSort.cpp.obj: CMakeFiles\Sorting.dir\flags.make
CMakeFiles\Sorting.dir\BubbleSort.cpp.obj: ..\BubbleSort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Github\DataStructure\Sorting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sorting.dir/BubbleSort.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Sorting.dir\BubbleSort.cpp.obj /FdCMakeFiles\Sorting.dir\ /FS -c D:\Github\DataStructure\Sorting\BubbleSort.cpp
<<

CMakeFiles\Sorting.dir\BubbleSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sorting.dir/BubbleSort.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\Sorting.dir\BubbleSort.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Github\DataStructure\Sorting\BubbleSort.cpp
<<

CMakeFiles\Sorting.dir\BubbleSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sorting.dir/BubbleSort.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Sorting.dir\BubbleSort.cpp.s /c D:\Github\DataStructure\Sorting\BubbleSort.cpp
<<

CMakeFiles\Sorting.dir\SelectionSort.cpp.obj: CMakeFiles\Sorting.dir\flags.make
CMakeFiles\Sorting.dir\SelectionSort.cpp.obj: ..\SelectionSort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Github\DataStructure\Sorting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Sorting.dir/SelectionSort.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Sorting.dir\SelectionSort.cpp.obj /FdCMakeFiles\Sorting.dir\ /FS -c D:\Github\DataStructure\Sorting\SelectionSort.cpp
<<

CMakeFiles\Sorting.dir\SelectionSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sorting.dir/SelectionSort.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\Sorting.dir\SelectionSort.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Github\DataStructure\Sorting\SelectionSort.cpp
<<

CMakeFiles\Sorting.dir\SelectionSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sorting.dir/SelectionSort.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Sorting.dir\SelectionSort.cpp.s /c D:\Github\DataStructure\Sorting\SelectionSort.cpp
<<

CMakeFiles\Sorting.dir\InsertionSort.cpp.obj: CMakeFiles\Sorting.dir\flags.make
CMakeFiles\Sorting.dir\InsertionSort.cpp.obj: ..\InsertionSort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Github\DataStructure\Sorting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Sorting.dir/InsertionSort.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Sorting.dir\InsertionSort.cpp.obj /FdCMakeFiles\Sorting.dir\ /FS -c D:\Github\DataStructure\Sorting\InsertionSort.cpp
<<

CMakeFiles\Sorting.dir\InsertionSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sorting.dir/InsertionSort.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\Sorting.dir\InsertionSort.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Github\DataStructure\Sorting\InsertionSort.cpp
<<

CMakeFiles\Sorting.dir\InsertionSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sorting.dir/InsertionSort.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Sorting.dir\InsertionSort.cpp.s /c D:\Github\DataStructure\Sorting\InsertionSort.cpp
<<

# Object files for target Sorting
Sorting_OBJECTS = \
"CMakeFiles\Sorting.dir\BubbleSort.cpp.obj" \
"CMakeFiles\Sorting.dir\SelectionSort.cpp.obj" \
"CMakeFiles\Sorting.dir\InsertionSort.cpp.obj"

# External object files for target Sorting
Sorting_EXTERNAL_OBJECTS =

Sorting.exe: CMakeFiles\Sorting.dir\BubbleSort.cpp.obj
Sorting.exe: CMakeFiles\Sorting.dir\SelectionSort.cpp.obj
Sorting.exe: CMakeFiles\Sorting.dir\InsertionSort.cpp.obj
Sorting.exe: CMakeFiles\Sorting.dir\build.make
Sorting.exe: CMakeFiles\Sorting.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Github\DataStructure\Sorting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Sorting.exe"
	"C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Sorting.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Sorting.dir\objects1.rsp @<<
 /out:Sorting.exe /implib:Sorting.lib /pdb:D:\Github\DataStructure\Sorting\cmake-build-debug\Sorting.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Sorting.dir\build: Sorting.exe

.PHONY : CMakeFiles\Sorting.dir\build

CMakeFiles\Sorting.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sorting.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Sorting.dir\clean

CMakeFiles\Sorting.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Github\DataStructure\Sorting D:\Github\DataStructure\Sorting D:\Github\DataStructure\Sorting\cmake-build-debug D:\Github\DataStructure\Sorting\cmake-build-debug D:\Github\DataStructure\Sorting\cmake-build-debug\CMakeFiles\Sorting.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Sorting.dir\depend

