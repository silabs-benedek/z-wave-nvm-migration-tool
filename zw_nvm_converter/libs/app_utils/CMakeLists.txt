add_library(app_utils user_message.c base64.c)

target_include_directories(app_utils PUBLIC
                              "${CMAKE_CURRENT_SOURCE_DIR}"
                          )

