cmake_minimum_required(VERSION 3.20.0)
project(lecture8 VERSION 0.1.0)


# Compilation flags
add_compile_options(-Wall -pedantic-errors)

include_directories(department/include)
# Add executable
add_executable(
department 
department/src/main.cpp 
department/src/department.cpp
department/src/employee.cpp
department/src/date.cpp
department/src/idbadge.cpp
)

# add_custom_command(TARGET lecture8 POST_BUILD
#     COMMAND valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./lecture8
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#     COMMENT "Running Valgrind after building lecture8"
#     VERBATIM
# )


# add_custom_target(run_valgrind ALL
#     COMMAND valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./lecture8
#     DEPENDS lecture8
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# )


# Set C++ standard to C++17
set_property(TARGET department PROPERTY CXX_STANDARD 17)

