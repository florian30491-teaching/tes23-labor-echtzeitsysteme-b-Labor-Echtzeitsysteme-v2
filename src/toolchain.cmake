set(CMAKE_SYSTEM_NAME Generic)

# Set the local path to the GNU ARM Embedded Toolchain
set(GCC_PATH ${CMAKE_SOURCE_DIR}/../assets/software/gnu-tools-for-stm32)

# Set GNU ARM Embedded Toolchain compiler / linker / objcopy
set(CMAKE_C_COMPILER ${GCC_PATH}/bin/arm-none-eabi-gcc.exe)
set(CMAKE_CXX_COMPILER ${GCC_PATH}/bin/arm-none-eabi-g++.exe)
set(CMAKE_ASM_COMPILER ${GCC_PATH}/bin/arm-none-eabi-gcc.exe)
set(CMAKE_OBJCOPY ${GCC_PATH}/bin/arm-none-eabi-objcopy.exe)
set(CMAKE_SIZE ${GCC_PATH}/bin/arm-none-eabi-size.exe)
set(CMAKE_AR ${GCC_PATH}/bin/arm-none-eabi-ar.exe)
set(CMAKE_OBJDUMP ${GCC_PATH}/bin/arm-none-eabi-objdump.exe)
set(CMAKE_LINKER ${GCC_PATH}/bin/arm-none-eabi-ld.exe)

# Without that flag CMake is not able to pass test compilation check
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)