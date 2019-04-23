message(STATUS "Using CURL_INCLUDE_DIRS: ${CURL_INCLUDE_DIRS}.")

add_library(${CPR_LIBRARIES} STATIC

    # Source files
    auth.cpp
    cookies.cpp
    cprtypes.cpp
    digest.cpp
    error.cpp
    multipart.cpp
    parameters.cpp
    payload.cpp
    proxies.cpp
    session.cpp
    timeout.cpp
    util.cpp
    ssl_options.cpp

    # Header files (useful in IDEs)
    "${CPR_INCLUDE_DIRS}/cpr/api.h"
    "${CPR_INCLUDE_DIRS}/cpr/auth.h"
    "${CPR_INCLUDE_DIRS}/cpr/body.h"
    "${CPR_INCLUDE_DIRS}/cpr/cookies.h"
    "${CPR_INCLUDE_DIRS}/cpr/cpr.h"
    "${CPR_INCLUDE_DIRS}/cpr/cprtypes.h"
    "${CPR_INCLUDE_DIRS}/cpr/curlholder.h"
    "${CPR_INCLUDE_DIRS}/cpr/defines.h"
    "${CPR_INCLUDE_DIRS}/cpr/digest.h"
    "${CPR_INCLUDE_DIRS}/cpr/error.h"
    "${CPR_INCLUDE_DIRS}/cpr/max_redirects.h"
    "${CPR_INCLUDE_DIRS}/cpr/multipart.h"
    "${CPR_INCLUDE_DIRS}/cpr/parameters.h"
    "${CPR_INCLUDE_DIRS}/cpr/payload.h"
    "${CPR_INCLUDE_DIRS}/cpr/proxies.h"
    "${CPR_INCLUDE_DIRS}/cpr/response.h"
    "${CPR_INCLUDE_DIRS}/cpr/session.h"
    "${CPR_INCLUDE_DIRS}/cpr/timeout.h"
    "${CPR_INCLUDE_DIRS}/cpr/util.h"
    "${CPR_INCLUDE_DIRS}/cpr/ssl_options.h")

message(STATUS "Using CURL_LIBRARIES: ${CURL_LIBRARIES}.")
set_property(TARGET ${CPR_LIBRARIES} PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(${CPR_LIBRARIES}
    ${CURL_LIBRARIES})

if(NOT (CMAKE_VERSION VERSION_LESS 3.0))
    target_include_directories(${CPR_LIBRARIES}
        PUBLIC
        ${CPR_INCLUDE_DIRS}
        ${CURL_INCLUDE_DIRS})
else()
    include_directories(
        ${CPR_INCLUDE_DIRS}
        ${CURL_INCLUDE_DIRS})
endif()
