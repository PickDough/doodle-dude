cmake_minimum_required(VERSION 3.27)
project(doodle_jump)

set(CMAKE_CXX_STANDARD 17)

add_executable(doodle_jump main.cpp
        src/FrameworkObjects/FObject.h
        src/FrameworkScene/FScene.cpp
        src/FrameworkScene/FScene.h
        src/FrameworkObjects/DoodleGuy/ODoodleGuy.cpp
        src/FrameworkObjects/DoodleGuy/ODoodleGuy.h
        src/FrameworkCamera/FCamera.cpp
        src/FrameworkCamera/FCamera.h
        src/FrameworkObjects/PlatformSpawner/OPlatformSpawner.cpp
        src/FrameworkObjects/PlatformSpawner/OPlatformSpawner.h
        src/FGameState/FGameState.cpp
        src/FGameState/FGameState.h
)
add_executable(framework_example Framework-win64/game.cpp)

set(TARGETS
        doodle_jump
        framework_example
)

foreach (target IN LISTS TARGETS)
    target_include_directories(${target} PRIVATE ${CMAKE_SOURCE_DIR}/Framework-win64)

    target_link_libraries(${target} PRIVATE ${CMAKE_SOURCE_DIR}/Framework-win64/FrameworkRelease_x64.lib)

    add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Framework-win64
        $<TARGET_FILE_DIR:${target}>
    )
endforeach ()

find_package(glm CONFIG REQUIRED)
target_link_libraries(doodle_jump PRIVATE glm::glm)



