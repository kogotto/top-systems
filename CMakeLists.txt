cmake_minimum_required(VERSION 3.16.3)

project(figures)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_CXX_STANDARD 20)

add_executable(
    ${PROJECT_NAME}

    main.cpp
    generate.cpp
    Figure.cpp
    FiguresCollection.cpp
    Square.cpp
)

add_subdirectory(external EXCLUDE_FROM_ALL)

include_directories(".")

target_link_libraries(
    ${PROJECT_NAME}

    PRIVATE SDL3::SDL3
)
