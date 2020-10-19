# https://www.jetbrains.com/help/clion/cmakelists-txt-file.html 
# https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b
cmake_minimum_required(VERSION 3.13)  # CMake version check
project(ostep_code)               # Create project "ostep_code"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.c file of project root directory as source file
set(SOURCE_FILES main.c intro/cpu.c intro/mem.c intro/threads.c intro/common_threads.h intro/io.c cpu-api/p1.c cpu-api/p2.c cpu-api/p3.c cpu-api/p4.c cpu-sched-lottery/lottery.c 13-vm/virtual-addresses.c 17/mmap.c)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(simple_example ${SOURCE_FILES})
