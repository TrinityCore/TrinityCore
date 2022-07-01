add_definitions(-D_WIN32_WINNT=0x0601)
add_definitions(-DWIN32_LEAN_AND_MEAN)
add_definitions(-DNOMINMAX)

<<<<<<< HEAD
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
=======
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
>>>>>>> 5221f56d8cb5f43c91e0f5d4ecb5bc5b98e3227d
  include(${CMAKE_SOURCE_DIR}/cmake/compiler/msvc/settings.cmake)
elseif(CMAKE_CXX_PLATFORM_ID MATCHES "MinGW")
  include(${CMAKE_SOURCE_DIR}/cmake/compiler/mingw/settings.cmake)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  include(${CMAKE_SOURCE_DIR}/cmake/compiler/clang/settings.cmake)
endif()
