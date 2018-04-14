cmake_minimum_required (VERSION 3.4)
project(num ASM C)
string(APPEND CMAKE_C_FLAGS "-std=gnu11 -g0 -O3 -Wall -Wno-unused-parameter -flto  -fno-fat-lto-objects")
foreach(i 1 2)
	add_executable(num${i} src/main.c)
	target_compile_definitions(num${i} PRIVATE USE_NUM=${i})
	add_custom_target(num${i}.asm ALL 
		COMMAND 
		gcc -std=gnu11 -g0 -O3 -Wall -Wno-unused-parameter -flto -fno-fat-lto-objects -S 
		-o num${i}.asm ${CMAKE_SOURCE_DIR}/src/main.c)
endforeach()
	 
