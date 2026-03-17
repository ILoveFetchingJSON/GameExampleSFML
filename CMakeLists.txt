cmake_minimum_required(VERSION 3.16)
project(ShooterTycoon)

set(CMAKE_CXX_STANDARD 17)

# Path to your SFML folder inside the repo
set(SFML_DIR "${CMAKE_SOURCE_DIR}/vendor/SFML")

# Include directories
include_directories(
    ${SFML_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

# Source files
file(GLOB SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(ShooterTycoon ${SRC_FILES})

# Link SFML libraries
target_link_libraries(ShooterTycoon
    ${SFML_DIR}/lib/sfml-graphics.lib
    ${SFML_DIR}/lib/sfml-window.lib
    ${SFML_DIR}/lib/sfml-system.lib
)

# Copy DLLs next to the executable after build
add_custom_command(TARGET ShooterTycoon POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${SFML_DIR}/bin"
    $<TARGET_FILE_DIR:ShooterTycoon>
)
