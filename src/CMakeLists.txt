cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME Labor-Echtzeitsysteme)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Include fetch content
include(FetchContent)

# Initialize variables for extracted targets
set(WinIDEAExtractionTarget "")
set(GNUExtractionTarget "")

## Check if directory for debugger exists under toolchain directory
#if(NOT EXISTS ${CMAKE_SOURCE_DIR}/toolchain/winIDEA)
#    message(STATUS "Directory for winIDEA Debugger does not exist. Downloading and extracting...")
#
#    # Download and extract winIDEA Debugger
#    FetchContent_Declare(
#            winIDEA
#            URL https://github.com/florian30491-teaching/Labor-Echtzeitsysteme-Public/releases/download/v1.0.0/winIDEA_x64_9_21_268_184034.7z
#            SOURCE_DIR ${CMAKE_SOURCE_DIR}/toolchain/winIDEA
#            DOWNLOAD_EXTRACT_TIMESTAMP TRUE
#    )
#
#    # Ensure the content is downloaded and extracted
#    FetchContent_MakeAvailable(winIDEA)
#
#    # Custom command to extract the 7z archive
#    add_custom_command(
#            OUTPUT ${CMAKE_BINARY_DIR}/toolchain/winIDEA_extracted
#            COMMAND 7z x ${CMAKE_SOURCE_DIR}/toolchain/winIDEA/winIDEA_x64_9_21_268_184034.7z -o${CMAKE_BINARY_DIR}/toolchain
#            COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_BINARY_DIR}/toolchain/winIDEA_extracted
#            DEPENDS ${CMAKE_SOURCE_DIR}/toolchain/winIDEA/winIDEA_x64_9_21_268_184034.7z
#            COMMENT "Entpacke winIDEA Toolchain nach ${CMAKE_BINARY_DIR}/toolchain..."
#    )
#
#    # Create a target to track the extraction process
#    add_custom_target(ExtractedWinIDEA ALL DEPENDS ${CMAKE_BINARY_DIR}/toolchain/winIDEA_extracted)
#    set(WinIDEAExtractionTarget ExtractedWinIDEA)
#else()
#    message(STATUS "Directory for winIDEA Debugger exists.")
#endif()

# Check if directory for gnu tools for stm32 exists under toolchain directory
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/toolchain/gnu-tools-for-stm32)
    message(STATUS "Directory for GNU Tools for STM32 does not exist. Downloading and extracting...")

    # Download and extract GNU Tools for STM32
    FetchContent_Declare(
            gnu-tools-for-stm32
            URL https://github.com/florian30491-teaching/Labor-Echtzeitsysteme-Public/releases/download/v1.0.0/gnu-tools-for-stm32.11.3.rel1.win32_1.1.1.202309131626.7z
            SOURCE_DIR ${CMAKE_SOURCE_DIR}/toolchain/gnu-tools-for-stm32
            DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )

    # Ensure the content is downloaded and extracted
    FetchContent_MakeAvailable(gnu-tools-for-stm32)

    # Custom command to extract the 7z archive
    add_custom_command(
            OUTPUT ${CMAKE_BINARY_DIR}/toolchain/gnu-tools-for-stm32_extracted
            COMMAND 7z x ${CMAKE_SOURCE_DIR}/toolchain/gnu-tools-for-stm32/gnu-tools-for-stm32.11.3.rel1.win32_1.1.1.202309131626.7z -o${CMAKE_BINARY_DIR}/toolchain
            COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_BINARY_DIR}/toolchain/gnu-tools-for-stm32_extracted
            DEPENDS ${CMAKE_SOURCE_DIR}/toolchain/gnu-tools-for-stm32/gnu-tools-for-stm32.11.3.rel1.win32_1.1.1.202309131626.7z
            COMMENT "Entpacke GNU Tools for STM32 nach ${CMAKE_BINARY_DIR}/toolchain..."
    )

    # Create a target to track the extraction process
    add_custom_target(ExtractedGNU ALL DEPENDS ${CMAKE_BINARY_DIR}/toolchain/gnu-tools-for-stm32_extracted)
    set(GNUExtractionTarget ExtractedGNU)
else()
    message(STATUS "Directory for GNU Tools for STM32 exists.")
endif()

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add dependencies for the project to ensure toolchains are extracted before build
if(WinIDEAExtractionTarget)
    add_dependencies(${CMAKE_PROJECT_NAME} ${WinIDEAExtractionTarget})
endif()

if(GNUExtractionTarget)
    add_dependencies(${CMAKE_PROJECT_NAME} ${GNUExtractionTarget})
endif()

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Define the task selection option
option(TASK_SELECTION "Specify the task selection (e.g., TASK1, TASK2)" "TASK1")

# Pass the TASK_SELECTION to the compiler
add_compile_definitions(TASK_SELECTION=${TASK_SELECTION})

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
        # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
        # Add user sources here
        Tasks/Task1/task1.c
        Tasks/Task2/task2.c
        Tasks/Task3/task3.c
        Tasks/Task4/task4.c
        Tasks/Task5/task5.c
        Tasks/Task6/task6.c
        Tasks/Task7/task7.c
        Tasks/Task8/task8.c
        Tasks/tasks.c
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        # Add user defined include paths
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

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
        # Add user defined symbols
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
        stm32cubemx
        # Add user defined libraries
)
