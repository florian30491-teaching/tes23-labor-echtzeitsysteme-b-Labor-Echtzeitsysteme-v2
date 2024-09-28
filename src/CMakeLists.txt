cmake_minimum_required(VERSION 3.29)

# Set the project name
project(LaborEchtzeitsysteme)

# Include the toolchain file if specified
if(CMAKE_TOOLCHAIN_FILE)
    include(${CMAKE_TOOLCHAIN_FILE})
endif()

# Enable verbose makefile
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Set the C standard version
set(CMAKE_C_STANDARD 99)
enable_language(C ASM)

# Debug build?
set(DEBUG 1)
if(DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

# Define the task selection option
option(TASK_SELECTION "Specify the task selection (e.g., TASK1, TASK2)" "TASK1")

# Pass the TASK_SELECTION to the compiler
add_compile_definitions(TASK_SELECTION=${TASK_SELECTION})

# Optimization
set(CMAKE_C_FLAGS_DEBUG "-Og -g")
set(CMAKE_C_FLAGS_RELEASE "-O3")

# Paths
set(BUILD_DIR ${CMAKE_BINARY_DIR}/build)

# Source files
set(C_SOURCES
        Core/Src/main.c
        Core/Src/gpio.c
        Core/Src/adc.c
        Core/Src/mdf.c
        Core/Src/dcmi.c
        Core/Src/fmc.c
        Core/Src/i2c.c
        Core/Src/icache.c
        Core/Src/memorymap.c
        Core/Src/octospi.c
        Core/Src/rtc.c
        Core/Src/sai.c
        Core/Src/sdmmc.c
        Core/Src/tamp.c
        Core/Src/tsc.c
        Core/Src/ucpd.c
        Core/Src/usart.c
        Core/Src/usb_otg.c
        Core/Src/stm32u5xx_it.c
        Core/Src/stm32u5xx_hal_msp.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_utils.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_exti.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_adc.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_adc_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dma_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_i2c_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rcc_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_cortex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_flash_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gpio.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_exti.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pwr_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_gtzc.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_icache.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_mdf.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_dcmi.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_fmc.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sram.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_ospi.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_dlyb.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rtc.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_rtc_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sai.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sai_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_sdmmc.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_sd_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tim_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_tsc.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_ucpd.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_gpio.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_lpgpio.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_dma.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_uart_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_smartcard.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_smartcard_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pcd.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_hal_pcd_ex.c
        Drivers/STM32U5xx_HAL_Driver/Src/stm32u5xx_ll_usb.c
        Core/Src/system_stm32u5xx.c
        Core/Src/app_freertos.c
        Core/Src/stm32u5xx_hal_timebase_tim.c
        Middlewares/Third_Party/FreeRTOS/Source/croutine.c
        Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
        Middlewares/Third_Party/FreeRTOS/Source/list.c
        Middlewares/Third_Party/FreeRTOS/Source/queue.c
        Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c
        Middlewares/Third_Party/FreeRTOS/Source/tasks.c
        Middlewares/Third_Party/FreeRTOS/Source/timers.c
        Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/port.c
        Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/portasm.c
        Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c
        Tasks/Task1/task1.c
        Tasks/Task1/task1.h
        Tasks/Task3/task3.c
        Tasks/Task3/task3.h
        Tasks/Task4/task4.c
        Tasks/Task4/task4.h
        Tasks/Task5/task5.c
        Tasks/Task5/task5.h
        Tasks/Task6/task6.c
        Tasks/Task6/task6.h
        Tasks/Task7/task7.c
        Tasks/Task7/task7.h
        Tasks/Task8/task8.c
        Tasks/Task8/task8.h
        #Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_1.c
)

# Assembler sources
set(ASM_SOURCES
        startup_stm32u575xx.s
        Tasks/Task2/task2.c
        Tasks/Task2/task2.h
        Tasks/tasks.c
        Tasks/tasks.h
)

# Include directories
set(INCLUDE_DIRS
        Core/Inc
        Drivers/STM32U5xx_HAL_Driver/Inc
        Drivers/STM32U5xx_HAL_Driver/Inc/Legacy
        Drivers/CMSIS/Device/ST/STM32U5xx/Include
        Drivers/CMSIS/Include
        Middlewares/Third_Party/FreeRTOS/Source/include/
        Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/
        Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/
        Middlewares/Third_Party/CMSIS/RTOS2/Include/
        Tasks/Task1
        Tasks/Task2
        Tasks/Task3
        Tasks/Task4
        Tasks/Task5
        Tasks/Task6
        Tasks/Task7
        Tasks/Task8
        Tasks
)

include_directories(${INCLUDE_DIRS})

# Create the executable target
add_executable(${PROJECT_NAME} ${C_SOURCES} ${ASM_SOURCES})

# Set compile options
target_compile_options(${PROJECT_NAME} PRIVATE
        -mcpu=cortex-m33
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
        -mthumb
        -DUSE_FULL_LL_DRIVER
        -DUSE_HAL_DRIVER
        -DSTM32U575xx
        -Wall
        -fdata-sections
        -ffunction-sections
        -Wno-unused-function
        -Wno-missing-prototypes
        -Wno-implicit-function-declaration
)

# Set linker options
target_link_options(${PROJECT_NAME} PRIVATE
        --specs=rdimon.specs
        -mcpu=cortex-m33
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
        -specs=nano.specs
        -T${CMAKE_SOURCE_DIR}/STM32U575xx_FLASH.ld
        -lgcc
        -lc
        -lm
        -lrdimon
        -Wl,-Map=${BUILD_DIR}/${PROJECT_NAME}.map,--cref
        -Wl,--gc-sections
        -Wl,--undefined=Reset_Handler
        -Wl,--print-memory-usage
)

# Create binary, hex, and ELF files
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${PROJECT_NAME}> ${BUILD_DIR}/${PROJECT_NAME}.hex
        COMMAND ${CMAKE_OBJCOPY} -O binary -S $<TARGET_FILE:${PROJECT_NAME}> ${BUILD_DIR}/${PROJECT_NAME}.bin
        COMMAND ${CMAKE_OBJCOPY} -O elf32-littlearm $<TARGET_FILE:${PROJECT_NAME}> ${BUILD_DIR}/${PROJECT_NAME}.elf
)

# Create the build directory
file(MAKE_DIRECTORY ${BUILD_DIR})

# Custom target to start the debugger
add_custom_target(start_debugger
        COMMAND ${CMAKE_COMMAND} -E echo "Starting winIDEA Debugger..."
        COMMAND ${CMAKE_COMMAND} -E env "start ./../assets/software/winIDEA/winIDEA.exe"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)