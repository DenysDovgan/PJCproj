cmake_minimum_required(VERSION 3.25)
project(PJCproj)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)

FetchContent_MakeAvailable(SFML fmt)

add_executable(
        PJCproj
        src/main.cpp
        src/GameEngine.cpp
        headers/GameEngine.h
        src/Scene.cpp
        headers/Scene.h
        src/TitleScene.cpp
        headers/TitleScene.h
        src/GameScene.cpp
        headers/GameScene.h
        src/GameOverScene.cpp
        headers/GameOverScene.h
        src/GameEvent.cpp
        headers/GameEvent.h
        src/Settings.cpp
        headers/Settings.h
        src/Button.cpp
        headers/Button.h
)

target_link_libraries(PJCproj sfml-graphics fmt)
