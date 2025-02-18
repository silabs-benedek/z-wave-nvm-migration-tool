find_package(PkgConfig)
pkg_check_modules(JSON_C json-c)
add_library(json_upgrade "json_upgrade.c")
target_link_libraries(json_upgrade)

target_include_directories(json_upgrade PUBLIC
                            ${JSON_C_INCLUDE_DIRS}/json-c
                            ${CMAKE_CURRENT_SOURCE_DIR}
                          )

target_compile_options(json_upgrade PUBLIC ${JSON_C_CFLAGS})


