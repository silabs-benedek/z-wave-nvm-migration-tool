add_library(bin2hex bin2hex.c)

target_include_directories(bin2hex PUBLIC
                              "${CMAKE_CURRENT_SOURCE_DIR}"
                          )
