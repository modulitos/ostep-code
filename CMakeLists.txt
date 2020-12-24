# https://www.jetbrains.com/help/clion/cmakelists-txt-file.html 
# https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b
cmake_minimum_required(VERSION 3.13)  # CMake version check
project(ostep_code)               # Create project "ostep_code"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# ASAN support
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(ostep_main main.c)
add_executable(intro_cpu intro/cpu.c)
add_executable(intro_mem intro/mem.c)
add_executable(intro_threads intro/threads.c)
add_executable(intro_io intro/io.c)
add_executable(cpu_api_p1 cpu-api/p1.c)
add_executable(cpu_api_p2 cpu-api/p2.c)
add_executable(cpu_api_p3 cpu-api/p3.c)
add_executable(cpu_api_p4 cpu-api/p4.c)
add_executable(cpu_sched_lottery cpu-sched-lottery/lottery.c)
add_executable(13-vm 13-vm/virtual-addresses.c)
add_executable(17_mmap 17/mmap.c)
add_executable(26_threads_into_t0 26-threads-intro/t0.c)
add_executable(26_threads_into_t1 26-threads-intro/t1.c)
add_executable(27_threads_api_thread_create 27-threads-api/thread_create.c)
add_executable(27_threads_api_thread_create_simple_args 27-threads-api/thread_create_simple_args.c)
add_executable(27_threads_api_thread_create_with_return_args 27-threads-api/thread_create_with_return_args.c)
add_executable(29-lock-based-concurrent-data-structures_counter 29-lock-based-concurrent-data-structures/test_counters.c)
add_executable(29-lock-based-concurrent-data-structures_linked_list 29-lock-based-concurrent-data-structures/test_linked_lists.c)
add_executable(29-lock-based-concurrent-data-structures_queues 29-lock-based-concurrent-data-structures/test_queues.c)
add_executable(29-lock-based-concurrent-data-structures_hash_tables 29-lock-based-concurrent-data-structures/test_hash_tables.c)

# Another example of setting multiple files into a single executable:
set(SOURCE_FILES main.c intro/cpu.c intro/mem.c intro/threads.c intro/common_threads.h intro/io.c)
add_executable(simple_example ${SOURCE_FILES})

