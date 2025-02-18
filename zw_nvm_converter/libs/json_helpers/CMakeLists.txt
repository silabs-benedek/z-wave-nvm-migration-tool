find_package(PkgConfig)
pkg_check_modules(JSON_C json-c)

add_library(json_helpers "json_helpers.c")
target_link_libraries(json_helpers app_utils)

target_include_directories(json_helpers PUBLIC
                            ${JSON_C_INCLUDE_DIRS}/json-c
                            ${CMAKE_CURRENT_SOURCE_DIR}
                          )

target_compile_options(json_helpers PUBLIC ${JSON_C_CFLAGS})
