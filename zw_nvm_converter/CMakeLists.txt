add_library(zw_nvm_converter nvmconv_main.c)
add_library (controllerlib_api INTERFACE)

# Try to find json-c package
find_package(json-c QUIET)
# if(NOT json-c_FOUND)
#   message(STATUS "json-c not found. Fetching via ExternalProject_Add()")
#   set(JSON_C_INSTALL_DIRS "/usr/local")
#   set(JSON_C_INCLUDE_DIRS ${JSON_C_INSTALL_DIRS}/include)
#   set(JSON_C_LIBRARY_DIRS ${JSON_C_INSTALL_DIRS}/lib)
#   # This lib will be linked
#   set(JSON_C_LIBRARIES "${JSON_C_LIBRARY_DIRS}/libjson-c.so")

#   # Manage json-c lib by ExternalProject_Add()
#   include(ExternalProject)
#   ExternalProject_Add(
#     json-c
#     GIT_REPOSITORY  https://github.com/json-c/json-c.git
#     GIT_TAG master
#     PREFIX ${CMAKE_BINARY_DIR}/json-c # Base directory where json-c will be downloaded
#     CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${JSON_C_INSTALL_DIRS}
#   )

#   # specify include directories & link libraries after building
#   include_directories(${JSON_C_INCLUDE_DIRS})
#   link_directories(${JSON_C_LIBRARY_DIRS})
  
  
#   message(STATUS "JSON_C_INSTALL_DIRS: ${JSON_C_INSTALL_DIRS}; JSON_C_INCLUDE_DIRS=${JSON_C_INCLUDE_DIRS}; JSON_C_LIBRARY_DIRS=${JSON_C_LIBRARY_DIRS}; JSON_C_LIBRARIES=${JSON_C_LIBRARIES}")
  
#   # Make sure the json-c is built before the zw_nvm_converter
#   add_dependencies(zw_nvm_converter json-c)

#   # Set RPATH to include the library directory
#   set_target_properties(zw_nvm_converter PROPERTIES
#     INSTALL_RPATH "${JSON_C_LIBRARY_DIRS}"
#     BUILD_WITH_INSTALL_RPATH TRUE
#   )
# else()
#   message(STATUS "json-c found: ${json-c_INCLUDE_DIRS}")
#   include_directories(${json-c_INCLUDE_DIRS})
#   set(JSON_C_LIBRARIES json-c::json-c)
# endif()

target_include_directories(zw_nvm_converter PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(controllerlib_api INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include" ${JSON_C_INCLUDE_DIRS})

add_subdirectory( nvm3lib )
add_subdirectory( controllerlib_7.xx )
add_subdirectory( libs)

target_link_libraries( zw_nvm_converter PRIVATE
                       controllerlib_api
                       controllerlib_7xx
                       json-c::json-c
                     )

install(TARGETS zw_nvm_converter DESTINATION bin)