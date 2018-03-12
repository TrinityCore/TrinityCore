# C++ Requests: Curl for People <img align="right" height="40" src="http://i.imgur.com/d9Xtyts.png">

[![Build Status](https://travis-ci.org/whoshuu/cpr.svg?branch=master)](https://travis-ci.org/whoshuu/cpr) [![Build status](https://ci.appveyor.com/api/projects/status/imalkp3a6hblpj5y/branch/master?svg=true)](https://ci.appveyor.com/project/whoshuu/cpr/branch/master) [![Coverage Status](https://coveralls.io/repos/whoshuu/cpr/badge.svg?branch=master&service=github)](https://coveralls.io/github/whoshuu/cpr) [![Documentation](https://img.shields.io/badge/documentation-master-brightgreen.svg)](https://whoshuu.github.io/cpr/)

C++ Requests is a simple wrapper around [libcurl](http://curl.haxx.se/libcurl) inspired by the excellent [Python Requests](https://github.com/kennethreitz/requests) project.

Despite its name, libcurl's easy interface is anything but, and making mistakes misusing it is a common source of error and frustration. Using the more expressive language facilities of C++11, this library captures the essence of making network calls into a few concise idioms.

Here's a quick GET request:

```c++
#include <cpr/cpr.h>

int main(int argc, char** argv) {
    auto r = cpr::Get(cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
                      cpr::Authentication{"user", "pass"},
                      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text;                         // JSON text string
}
```

And here's [less functional, more complicated code, without cpr](https://gist.github.com/whoshuu/2dc858b8730079602044).

## Documentation

You can find the latest documentation [here](https://whoshuu.github.io/cpr). It's a work in progress, but it should give you a better idea of how to use the library than the [tests](https://github.com/whoshuu/cpr/tree/master/test) currently do.

## Features

C++ Requests currently supports:

* Custom headers
* Url encoded parameters
* Url encoded POST values
* Multipart form POST upload
* File POST upload
* Basic authentication
* Digest authentication
* Timeout specification
* Timeout for low speed connection
* Asynchronous requests
* :cookie: support!
* Proxy support
* Callback interface
* PUT methods
* DELETE methods
* HEAD methods
* OPTIONS methods
* PATCH methods

## Planned

Support for the following will be forthcoming (in rough order of implementation priority):

* [Streamed requests](https://github.com/whoshuu/cpr/issues/25)
* [OpenSSL support](https://github.com/whoshuu/cpr/issues/31)

and much more!

## Usage

For just getting this library up and running, I highly recommend forking the [example project](https://github.com/whoshuu/cpr-example). It's configured with the minimum CMake magic and boilerplate needed to start playing around with networked applications.

If you already have a project you need to integrate C++ Requests with, the primary way is to use git submodules. Add this repository as a submodule of your root repository:

```shell
git submodule add git@github.com:whoshuu/cpr.git
OR 
git submodule add https://github.com/whoshuu/cpr.git

git submodule update --init --recursive
```

Next, add this subdirectory to your CMakeLists.txt before declaring any targets that might use it:

```cmake
add_subdirectory(cpr)
```

This will produce two important CMake variables, `CPR_INCLUDE_DIRS` and `CPR_LIBRARIES`, which you'll use in the typical way:

```cmake
include_directories(${CPR_INCLUDE_DIRS})
target_link_libraries(your_target_name ${CPR_LIBRARIES})
```

and that should do it! Using the submodule method of integrating C++ Requests, there's no need to handle libcurl yourself, all of those dependencies are taken care of for you.

## Requirements

The only explicit requirements are:

* a C++11 compatible compiler such as Clang or GCC. The minimum required version of GCC is unknown, so if anyone has trouble building this library with a specific version of GCC, do let me know
* curl and its development libraries
