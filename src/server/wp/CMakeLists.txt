# WP stub — минимальная библиотека, без зависимостей

add_library(wp_stub STATIC
    wp_stub.cpp
)

target_include_directories(wp_stub
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
