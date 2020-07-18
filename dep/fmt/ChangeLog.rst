4.0.1 - TBD
-----------

4.0.0 - 2017-06-27
------------------

* Removed old compatibility headers ``cppformat/*.h`` and CMake options (`#527 <https://github.com/pull/527>`_). Thanks `@maddinat0r (Alex Martin) <https://github.com/maddinat0r>`_.

* Added ``string.h`` containing ``fmt::to_string()`` as alternative to ``std::to_string()`` as well as other string writer functionality (`#326 <https://github.com/fmtlib/fmt/issues/326>`_ and `#441 <https://github.com/fmtlib/fmt/pull/441>`_):

  .. code:: c++

    #include "fmt/string.h"
  
    std::string answer = fmt::to_string(42);

  Thanks to `@glebov-andrey (Andrey Glebov) <https://github.com/glebov-andrey>`_.

* Moved ``fmt::printf()`` to new ``printf.h`` header and allowed ``%s`` as generic specifier (`#453 <https://github.com/fmtlib/fmt/pull/453>`_), made ``%.f`` more conformant to regular ``printf()`` (`#490 <https://github.com/fmtlib/fmt/pull/490>`_), added custom writer support (`#476 <https://github.com/fmtlib/fmt/issues/476>`_) and implemented missing custom argument formatting (`#339 <https://github.com/fmtlib/fmt/pull/339>`_ and `#340 <https://github.com/fmtlib/fmt/pull/340>`_):

  .. code:: c++

    #include "fmt/printf.h"
 
    // %s format specifier can be used with any argument type.
    fmt::printf("%s", 42);

  Thanks `@mojoBrendan <https://github.com/mojoBrendan>`_, `@manylegged (Arthur Danskin) <https://github.com/manylegged>`_ and `@spacemoose (Glen Stark) <https://github.com/spacemoose>`_. See also `#360 <https://github.com/fmtlib/fmt/issues/360>`_, `#335 <https://github.com/fmtlib/fmt/issues/335>`_ and `#331 <https://github.com/fmtlib/fmt/issues/331>`_.

* Added ``container.h`` containing a ``BasicContainerWriter`` to write to containers like ``std::vector`` (`#450 <https://github.com/fmtlib/fmt/pull/450>`_). Thanks `@polyvertex (Jean-Charles Lefebvre) <https://github.com/polyvertex>`_.

* Added ``fmt::join()`` function that takes a range and formats its elements separated by a given string (`#466 <https://github.com/fmtlib/fmt/pull/466>`_):

  .. code:: c++

    #include "fmt/format.h"
 
    std::vector<double> v = {1.2, 3.4, 5.6};
    // Prints "(+01.20, +03.40, +05.60)".
    fmt::print("({:+06.2f})", fmt::join(v.begin(), v.end(), ", "));

  Thanks `@olivier80 <https://github.com/olivier80>`_.

* Added support for custom formatting specifications to simplify customization of built-in formatting (`#444 <https://github.com/fmtlib/fmt/pull/444>`_). Thanks `@polyvertex (Jean-Charles Lefebvre) <https://github.com/polyvertex>`_. See also `#439 <https://github.com/fmtlib/fmt/issues/439>`_.

* Added ``fmt::format_system_error()`` for error code formatting (`#323 <https://github.com/fmtlib/fmt/issues/323>`_ and `#526 <https://github.com/fmtlib/fmt/pull/526>`_). Thanks `@maddinat0r (Alex Martin) <https://github.com/maddinat0r>`_.

* Added thread-safe ``fmt::localtime()`` and ``fmt::gmtime()`` as replacement for the standard version to ``time.h`` (`#396 <https://github.com/fmtlib/fmt/pull/396>`_). Thanks `@codicodi <https://github.com/codicodi>`_.

* Internal improvements to ``NamedArg`` and ``ArgLists`` (`#389 <https://github.com/fmtlib/fmt/pull/389>`_ and `#390 <https://github.com/fmtlib/fmt/pull/390>`_). Thanks `@chronoxor <https://github.com/chronoxor>`_.

* Fixed crash due to bug in ``FormatBuf`` (`#493 <https://github.com/fmtlib/fmt/pull/493>`_). Thanks `@effzeh <https://github.com/effzeh>`_. See also `#480 <https://github.com/fmtlib/fmt/issues/480>`_ and `#491 <https://github.com/fmtlib/fmt/issues/491>`_.

* Fixed handling of wide strings in ``fmt::StringWriter``.

* Improved compiler error messages (`#357 <https://github.com/fmtlib/fmt/issues/357>`_).

* Fixed various warnings and issues with various compilers (`#494 <https://github.com/fmtlib/fmt/pull/494>`_, `#499 <https://github.com/fmtlib/fmt/pull/499>`_, `#483 <https://github.com/fmtlib/fmt/pull/483>`_, `#519 <https://github.com/fmtlib/fmt/pull/519>`_, `#485 <https://github.com/fmtlib/fmt/pull/485>`_, `#482 <https://github.com/fmtlib/fmt/pull/482>`_, `#475 <https://github.com/fmtlib/fmt/pull/475>`_, `#473 <https://github.com/fmtlib/fmt/pull/473>`_ and `#414 <https://github.com/fmtlib/fmt/pull/414>`_). Thanks `@chronoxor <https://github.com/chronoxor>`_, `@zhaohuaxishi <https://github.com/zhaohuaxishi>`_, `@pkestene (Pierre Kestener) <https://github.com/pkestene>`_, `@dschmidt (Dominik Schmidt) <https://github.com/dschmidt>`_ and `@0x414c (Alexey Gorishny) <https://github.com/0x414c>`_ .

* Improved CMake: targets are now namespaced (`#511 <https://github.com/fmtlib/fmt/pull/511>`_ and `#513 <https://github.com/fmtlib/fmt/pull/513>`_), supported header-only ``printf.h`` (`#354 <https://github.com/fmtlib/fmt/pull/354>`_), fixed issue with minimal supported library subset (`#418 <https://github.com/fmtlib/fmt/issues/418>`_, `#419 <https://github.com/fmtlib/fmt/pull/419>`_ and `#420 <https://github.com/fmtlib/fmt/pull/420>`_). Thanks `@bjoernthiel (Bjoern Thiel) <https://github.com/bjoernthiel>`_,
  `@niosHD (Mario Werner) <https://github.com/niosHD>`_, `@LogicalKnight (Sean LK) <https://github.com/LogicalKnight>`_ and `@alabuzhev (Alex Alabuzhev) <https://github.com/alabuzhev>`_.

* Improved documentation. Thanks to `@pwm1234 (Phil) <https://github.com/pwm1234>`_ for `#393 <https://github.com/fmtlib/fmt/pull/393>`_.

3.0.2 - 2017-06-14
------------------

* Added ``FMT_VERSION`` macro (`#411 <https://github.com/fmtlib/fmt/issues/411>`_).

* Used ``FMT_NULL`` instead of literal ``0`` (`#409 <https://github.com/fmtlib/fmt/pull/409>`_). Thanks `@alabuzhev (Alex Alabuzhev) <https://github.com/alabuzhev>`_.

* Added extern templates for ``format_float`` (`#413 <https://github.com/fmtlib/fmt/issues/413>`_).

* Fixed implicit conversion issue (`#507 <https://github.com/fmtlib/fmt/issues/507>`_).

* Fixed signbit detection (`#423 <https://github.com/fmtlib/fmt/issues/423>`_).

* Fixed naming collision (`#425 <https://github.com/fmtlib/fmt/issues/425>`_).

* Fixed missing intrinsic for C++/CLI (`#457 <https://github.com/fmtlib/fmt/pull/457>`_). Thanks `@calumr (Calum Robinson) <https://github.com/calumr>`_

* Fixed Android detection (`#458 <https://github.com/fmtlib/fmt/pull/458>`_). Thanks `@Gachapen (Magnus Bjerke Vik) <https://github.com/Gachapen>`_.

* Use lean ``windows.h`` if not in header-only mode (`#503 <https://github.com/fmtlib/fmt/pull/503>`_). Thanks `@Quentin01 (Quentin Buathier) <https://github.com/Quentin01>`_.

* Fixed issue with CMake exporting C++11 flag (`#445 <https://github.com/fmtlib/fmt/pull/455>`_). Thanks `@EricWF (Eric) <https://github.com/EricWF>`_.

* Fixed issue with nvcc and MSVC compiler bug and MinGW (`#505 <https://github.com/fmtlib/fmt/issues/505>`_).

* Fixed DLL issues (`#469 <https://github.com/fmtlib/fmt/pull/469>`_ and `#502 <https://github.com/fmtlib/fmt/pull/502>`_). Thanks `@richardeakin (Richard Eakin) <https://github.com/richardeakin>`_ and `@AndreasSchoenle (Andreas Schönle) <https://github.com/AndreasSchoenle>`_.

* Fixed test compilation under FreeBSD (`#433 <https://github.com/fmtlib/fmt/issues/433>`_).

* Fixed various warnings (`#403 <https://github.com/fmtlib/fmt/pull/403>`_, `#410 <https://github.com/fmtlib/fmt/pull/410>`_ and `#510 <https://github.com/fmtlib/fmt/pull/510>`_). Thanks `@Lecetem <https://github.com/Lectem>`_, `@chenhayat (Chen Hayat) <https://github.com/chenhayat>`_ and `@trozen <https://github.com/trozen>`_.

* Removed redundant include (`#479 <https://github.com/fmtlib/fmt/issues/479>`_).

* Fixed documentation issues.

3.0.1 - 2016-11-01
------------------
* Fixed handling of thousands seperator (`#353 <https://github.com/fmtlib/fmt/issues/353>`_)

* Fixed handling of ``unsigned char`` strings (`#373 <https://github.com/fmtlib/fmt/issues/373>`_)

* Corrected buffer growth when formatting time (`#367 <https://github.com/fmtlib/fmt/issues/367>`_)

* Removed warnings under MSVC and clang (`#318 <https://github.com/fmtlib/fmt/issues/318>`_, `#250 <https://github.com/fmtlib/fmt/issues/250>`_, also merged `#385 <https://github.com/fmtlib/fmt/pull/385>`_ and `#361 <https://github.com/fmtlib/fmt/pull/361>`_). Thanks `@jcelerier (Jean-Michaël Celerier) <https://github.com/jcelerier>`_ and `@nmoehrle (Nils Moehrle) <https://github.com/nmoehrle>`_.

* Fixed compilation issues under Android (`#327 <https://github.com/fmtlib/fmt/pull/327>`_, `#345 <https://github.com/fmtlib/fmt/issues/345>`_ and `#381 <https://github.com/fmtlib/fmt/pull/381>`_), FreeBSD (`#358 <https://github.com/fmtlib/fmt/pull/358>`_), Cygwin (`#388 <https://github.com/fmtlib/fmt/issues/388>`_), MinGW (`#355 <https://github.com/fmtlib/fmt/issues/355>`_) as well as other issues (`#350 <https://github.com/fmtlib/fmt/issues/350>`_, `#366 <https://github.com/fmtlib/fmt/issues/355>`_, `#348 <https://github.com/fmtlib/fmt/pull/348>`_, `#402 <https://github.com/fmtlib/fmt/pull/402>`_, `#405 <https://github.com/fmtlib/fmt/pull/405>`_). Thanks to `@dpantele (Dmitry) <https://github.com/dpantele>`_, `@hghwng (Hugh Wang) <https://github.com/hghwng>`_, `@arvedarved (Tilman Keskinöz) <https://github.com/arvedarved>`_, `@LogicalKnight (Sean) <https://github.com/LogicalKnight>`_ and `@JanHellwig (Jan Hellwig) <https://github.com/janhellwig>`_.
 
* Fixed some documentation issues and extended specification (`#320 <https://github.com/fmtlib/fmt/issues/320>`_, `#333 <https://github.com/fmtlib/fmt/pull/333>`_, `#347 <https://github.com/fmtlib/fmt/issues/347>`_, `#362 <https://github.com/fmtlib/fmt/pull/362>`_). Thanks to `@smellman (Taro Matsuzawa aka. btm) <https://github.com/smellman>`_.

3.0.0 - 2016-05-07
------------------

* The project has been renamed from C++ Format (cppformat) to fmt for
  consistency with the used namespace and macro prefix
  (`#307 <https://github.com/fmtlib/fmt/issues/307>`_).
  Library headers are now located in the ``fmt`` directory:

  .. code:: c++

    #include "fmt/format.h"

  Including ``format.h`` from the ``cppformat`` directory is deprecated
  but works via a proxy header which will be removed in the next major version.
  
  The documentation is now available at http://fmtlib.net.

* Added support for `strftime <http://en.cppreference.com/w/cpp/chrono/c/strftime>`_-like
  `date and time formatting <http://fmtlib.net/3.0.0/api.html#date-and-time-formatting>`_
  (`#283 <https://github.com/fmtlib/fmt/issues/283>`_):

  .. code:: c++

    #include "fmt/time.h"

    std::time_t t = std::time(nullptr);
    // Prints "The date is 2016-04-29." (with the current date)
    fmt::print("The date is {:%Y-%m-%d}.", *std::localtime(&t));

* ``std::ostream`` support including formatting of user-defined types that provide
  overloaded ``operator<<`` has been moved to ``fmt/ostream.h``:

  .. code:: c++

    #include "fmt/ostream.h"

    class Date {
      int year_, month_, day_;
    public:
      Date(int year, int month, int day) : year_(year), month_(month), day_(day) {}

      friend std::ostream &operator<<(std::ostream &os, const Date &d) {
        return os << d.year_ << '-' << d.month_ << '-' << d.day_;
      }
    };

    std::string s = fmt::format("The date is {}", Date(2012, 12, 9));
    // s == "The date is 2012-12-9"

* Added support for `custom argument formatters
  <http://fmtlib.net/3.0.0/api.html#argument-formatters>`_
  (`#235 <https://github.com/fmtlib/fmt/issues/235>`_).

* Added support for locale-specific integer formatting with the ``n`` specifier
  (`#305 <https://github.com/fmtlib/fmt/issues/305>`_):

  .. code:: c++

    std::setlocale(LC_ALL, "en_US.utf8");
    fmt::print("cppformat: {:n}\n", 1234567); // prints 1,234,567

* Sign is now preserved when formatting an integer with an incorrect ``printf``
  format specifier (`#265 <https://github.com/fmtlib/fmt/issues/265>`_):

  .. code:: c++

    fmt::printf("%lld", -42); // prints -42

  Note that it would be an undefined behavior in ``std::printf``.

* Length modifiers such as ``ll`` are now optional in printf formatting
  functions and the correct type is determined automatically
  (`#255 <https://github.com/fmtlib/fmt/issues/255>`_):

  .. code:: c++

    fmt::printf("%d", std::numeric_limits<long long>::max());

  Note that it would be an undefined behavior in ``std::printf``.

* Added initial support for custom formatters
  (`#231 <https://github.com/fmtlib/fmt/issues/231>`_).

* Fixed detection of user-defined literal support on Intel C++ compiler
  (`#311 <https://github.com/fmtlib/fmt/issues/311>`_,
  `#312 <https://github.com/fmtlib/fmt/pull/312>`_).
  Thanks to `@dean0x7d (Dean Moldovan) <https://github.com/dean0x7d>`_ and
  `@speth (Ray Speth) <https://github.com/speth>`_.

* Reduced compile time
  (`#243 <https://github.com/fmtlib/fmt/pull/243>`_,
  `#249 <https://github.com/fmtlib/fmt/pull/249>`_,
  `#317 <https://github.com/fmtlib/fmt/issues/317>`_):

  .. image:: https://cloud.githubusercontent.com/assets/4831417/11614060/
             b9e826d2-9c36-11e5-8666-d4131bf503ef.png

  .. image:: https://cloud.githubusercontent.com/assets/4831417/11614080/
             6ac903cc-9c37-11e5-8165-26df6efae364.png

  Thanks to `@dean0x7d (Dean Moldovan) <https://github.com/dean0x7d>`_.

* Compile test fixes (`#313 <https://github.com/fmtlib/fmt/pull/313>`_).
  Thanks to `@dean0x7d (Dean Moldovan) <https://github.com/dean0x7d>`_.

* Documentation fixes (`#239 <https://github.com/fmtlib/fmt/pull/239>`_,
  `#248 <https://github.com/fmtlib/fmt/issues/248>`_,
  `#252 <https://github.com/fmtlib/fmt/issues/252>`_,
  `#258 <https://github.com/fmtlib/fmt/pull/258>`_,
  `#260 <https://github.com/fmtlib/fmt/issues/260>`_,
  `#301 <https://github.com/fmtlib/fmt/issues/301>`_,
  `#309 <https://github.com/fmtlib/fmt/pull/309>`_).
  Thanks to `@ReadmeCritic <https://github.com/ReadmeCritic>`_
  `@Gachapen (Magnus Bjerke Vik) <https://github.com/Gachapen>`_ and
  `@jwilk (Jakub Wilk) <https://github.com/jwilk>`_.

* Fixed compiler and sanitizer warnings (
  `#244 <https://github.com/fmtlib/fmt/issues/244>`_,
  `#256 <https://github.com/fmtlib/fmt/pull/256>`_,
  `#259 <https://github.com/fmtlib/fmt/pull/259>`_,
  `#263 <https://github.com/fmtlib/fmt/issues/263>`_,
  `#274 <https://github.com/fmtlib/fmt/issues/274>`_,
  `#277 <https://github.com/fmtlib/fmt/pull/277>`_,
  `#286 <https://github.com/fmtlib/fmt/pull/286>`_,
  `#291 <https://github.com/fmtlib/fmt/issues/291>`_,
  `#296 <https://github.com/fmtlib/fmt/issues/296>`_,
  `#308 <https://github.com/fmtlib/fmt/issues/308>`_)
  Thanks to `@mwinterb <https://github.com/mwinterb>`_,
  `@pweiskircher (Patrik Weiskircher) <https://github.com/pweiskircher>`_,
  `@Naios <https://github.com/Naios>`_.

* Improved compatibility with Windows Store apps
  (`#280 <https://github.com/fmtlib/fmt/issues/280>`_,
  `#285 <https://github.com/fmtlib/fmt/pull/285>`_)
  Thanks to `@mwinterb <https://github.com/mwinterb>`_.

* Added tests of compatibility with older C++ standards
  (`#273 <https://github.com/fmtlib/fmt/pull/273>`_).
  Thanks to `@niosHD <https://github.com/niosHD>`_.

* Fixed Android build (`#271 <https://github.com/fmtlib/fmt/pull/271>`_).
  Thanks to `@newnon <https://github.com/newnon>`_.

* Changed ``ArgMap`` to be backed by a vector instead of a map.
  (`#261 <https://github.com/fmtlib/fmt/issues/261>`_,
  `#262 <https://github.com/fmtlib/fmt/pull/262>`_).
  Thanks to `@mwinterb <https://github.com/mwinterb>`_.

* Added ``fprintf`` overload that writes to a ``std::ostream``
  (`#251 <https://github.com/fmtlib/fmt/pull/251>`_).
  Thanks to `nickhutchinson (Nicholas Hutchinson) <https://github.com/nickhutchinson>`_.

* Export symbols when building a Windows DLL
  (`#245 <https://github.com/fmtlib/fmt/pull/245>`_).
  Thanks to `macdems (Maciek Dems) <https://github.com/macdems>`_.

* Fixed compilation on Cygwin (`#304 <https://github.com/fmtlib/fmt/issues/304>`_).

* Implemented a workaround for a bug in Apple LLVM version 4.2 of clang
  (`#276 <https://github.com/fmtlib/fmt/issues/276>`_).

* Implemented a workaround for Google Test bug
  `#705 <https://github.com/google/googletest/issues/705>`_ on gcc 6
  (`#268 <https://github.com/fmtlib/fmt/issues/268>`_).
  Thanks to `octoploid <https://github.com/octoploid>`_.

* Removed Biicode support because the latter has been discontinued.

2.1.1 - 2016-04-11
------------------

* The install location for generated CMake files is now configurable via
  the ``FMT_CMAKE_DIR`` CMake variable
  (`#299 <https://github.com/fmtlib/fmt/pull/299>`_).
  Thanks to `@niosHD <https://github.com/niosHD>`_.

* Documentation fixes (`#252 <https://github.com/fmtlib/fmt/issues/252>`_).

2.1.0 - 2016-03-21
------------------

* Project layout and build system improvements
  (`#267 <https://github.com/fmtlib/fmt/pull/267>`_):

  * The code have been moved to the ``cppformat`` directory.
    Including ``format.h`` from the top-level directory is deprecated
    but works via a proxy header which will be removed in the next
    major version.

  * C++ Format CMake targets now have proper interface definitions.

  * Installed version of the library now supports the header-only
    configuration.

  * Targets ``doc``, ``install``, and ``test`` are now disabled if C++ Format
    is included as a CMake subproject. They can be enabled by setting
    ``FMT_DOC``, ``FMT_INSTALL``, and ``FMT_TEST`` in the parent project.

  Thanks to `@niosHD <https://github.com/niosHD>`_.

2.0.1 - 2016-03-13
------------------

* Improved CMake find and package support
  (`#264 <https://github.com/fmtlib/fmt/issues/264>`_).
  Thanks to `@niosHD <https://github.com/niosHD>`_.

* Fix compile error with Android NDK and mingw32
  (`#241 <https://github.com/fmtlib/fmt/issues/241>`_).
  Thanks to `@Gachapen (Magnus Bjerke Vik) <https://github.com/Gachapen>`_.

* Documentation fixes
  (`#248 <https://github.com/fmtlib/fmt/issues/248>`_,
  `#260 <https://github.com/fmtlib/fmt/issues/260>`_).

2.0.0 - 2015-12-01
------------------

General
~~~~~~~

* [Breaking] Named arguments
  (`#169 <https://github.com/fmtlib/fmt/pull/169>`_,
  `#173 <https://github.com/fmtlib/fmt/pull/173>`_,
  `#174 <https://github.com/fmtlib/fmt/pull/174>`_):

  .. code:: c++

    fmt::print("The answer is {answer}.", fmt::arg("answer", 42));

  Thanks to `@jamboree <https://github.com/jamboree>`_.

* [Experimental] User-defined literals for format and named arguments
  (`#204 <https://github.com/fmtlib/fmt/pull/204>`_,
  `#206 <https://github.com/fmtlib/fmt/pull/206>`_,
  `#207 <https://github.com/fmtlib/fmt/pull/207>`_):

  .. code:: c++

    using namespace fmt::literals;
    fmt::print("The answer is {answer}.", "answer"_a=42);

  Thanks to `@dean0x7d (Dean Moldovan) <https://github.com/dean0x7d>`_.

* [Breaking] Formatting of more than 16 arguments is now supported when using
  variadic templates
  (`#141 <https://github.com/fmtlib/fmt/issues/141>`_).
  Thanks to `@Shauren <https://github.com/Shauren>`_.

* Runtime width specification
  (`#168 <https://github.com/fmtlib/fmt/pull/168>`_):

  .. code:: c++

    fmt::format("{0:{1}}", 42, 5); // gives "   42"

  Thanks to `@jamboree <https://github.com/jamboree>`_.

* [Breaking] Enums are now formatted with an overloaded ``std::ostream`` insertion
  operator (``operator<<``) if available
  (`#232 <https://github.com/fmtlib/fmt/issues/232>`_).

* [Breaking] Changed default ``bool`` format to textual, "true" or "false"
  (`#170 <https://github.com/fmtlib/fmt/issues/170>`_):

  .. code:: c++
  
    fmt::print("{}", true); // prints "true"

  To print ``bool`` as a number use numeric format specifier such as ``d``:

  .. code:: c++

    fmt::print("{:d}", true); // prints "1"

* ``fmt::printf`` and ``fmt::sprintf`` now support formatting of ``bool`` with the
  ``%s`` specifier giving textual output, "true" or "false"
  (`#223 <https://github.com/fmtlib/fmt/pull/223>`_):

  .. code:: c++

    fmt::printf("%s", true); // prints "true"

  Thanks to `@LarsGullik <https://github.com/LarsGullik>`_.

* [Breaking] ``signed char`` and ``unsigned char`` are now formatted as integers by default
  (`#217 <https://github.com/fmtlib/fmt/pull/217>`_).

* [Breaking] Pointers to C strings can now be formatted with the ``p`` specifier
  (`#223 <https://github.com/fmtlib/fmt/pull/223>`_):

  .. code:: c++

    fmt::print("{:p}", "test"); // prints pointer value

  Thanks to `@LarsGullik <https://github.com/LarsGullik>`_.

* [Breaking] ``fmt::printf`` and ``fmt::sprintf`` now print null pointers as ``(nil)``
  and null strings as ``(null)`` for consistency with glibc
  (`#226 <https://github.com/fmtlib/fmt/pull/226>`_).
  Thanks to `@LarsGullik <https://github.com/LarsGullik>`_.

* [Breaking] ``fmt::(s)printf`` now supports formatting of objects of user-defined types
  that provide an overloaded ``std::ostream`` insertion operator (``operator<<``)
  (`#201 <https://github.com/fmtlib/fmt/issues/201>`_):

  .. code:: c++

    fmt::printf("The date is %s", Date(2012, 12, 9));

* [Breaking] The ``Buffer`` template is now part of the public API and can be used
  to implement custom memory buffers
  (`#140 <https://github.com/fmtlib/fmt/issues/140>`_).
  Thanks to `@polyvertex (Jean-Charles Lefebvre) <https://github.com/polyvertex>`_.

* [Breaking] Improved compatibility between ``BasicStringRef`` and
  `std::experimental::basic_string_view
  <http://en.cppreference.com/w/cpp/experimental/basic_string_view>`_
  (`#100 <https://github.com/fmtlib/fmt/issues/100>`_,
  `#159 <https://github.com/fmtlib/fmt/issues/159>`_,
  `#183 <https://github.com/fmtlib/fmt/issues/183>`_):

  - Comparison operators now compare string content, not pointers
  - ``BasicStringRef::c_str`` replaced by ``BasicStringRef::data``
  - ``BasicStringRef`` is no longer assumed to be null-terminated

  References to null-terminated strings are now represented by a new class,
  ``BasicCStringRef``.

* Dependency on pthreads introduced by Google Test is now optional
  (`#185 <https://github.com/fmtlib/fmt/issues/185>`_).

* New CMake options ``FMT_DOC``, ``FMT_INSTALL`` and ``FMT_TEST`` to control
  generation of ``doc``, ``install`` and ``test`` targets respectively, on by default
  (`#197 <https://github.com/fmtlib/fmt/issues/197>`_,
  `#198 <https://github.com/fmtlib/fmt/issues/198>`_,
  `#200 <https://github.com/fmtlib/fmt/issues/200>`_).
  Thanks to `@maddinat0r (Alex Martin) <https://github.com/maddinat0r>`_.

* ``noexcept`` is now used when compiling with MSVC2015
  (`#215 <https://github.com/fmtlib/fmt/pull/215>`_).
  Thanks to `@dmkrepo (Dmitriy) <https://github.com/dmkrepo>`_.

* Added an option to disable use of ``windows.h`` when ``FMT_USE_WINDOWS_H``
  is defined as 0 before including ``format.h``
  (`#171 <https://github.com/fmtlib/fmt/issues/171>`_).
  Thanks to `@alfps (Alf P. Steinbach) <https://github.com/alfps>`_.

* [Breaking] ``windows.h`` is now included with ``NOMINMAX`` unless
  ``FMT_WIN_MINMAX`` is defined. This is done to prevent breaking code using
  ``std::min`` and ``std::max`` and only affects the header-only configuration
  (`#152 <https://github.com/fmtlib/fmt/issues/152>`_,
  `#153 <https://github.com/fmtlib/fmt/pull/153>`_,
  `#154 <https://github.com/fmtlib/fmt/pull/154>`_).
  Thanks to `@DevO2012 <https://github.com/DevO2012>`_.

* Improved support for custom character types
  (`#171 <https://github.com/fmtlib/fmt/issues/171>`_).
  Thanks to `@alfps (Alf P. Steinbach) <https://github.com/alfps>`_.

* Added an option to disable use of IOStreams when ``FMT_USE_IOSTREAMS``
  is defined as 0 before including ``format.h``
  (`#205 <https://github.com/fmtlib/fmt/issues/205>`_,
  `#208 <https://github.com/fmtlib/fmt/pull/208>`_).
  Thanks to `@JodiTheTigger <https://github.com/JodiTheTigger>`_.

* Improved detection of ``isnan``, ``isinf`` and ``signbit``.

Optimization
~~~~~~~~~~~~

* Made formatting of user-defined types more efficient with a custom stream buffer
  (`#92 <https://github.com/fmtlib/fmt/issues/92>`_,
  `#230 <https://github.com/fmtlib/fmt/pull/230>`_).
  Thanks to `@NotImplemented <https://github.com/NotImplemented>`_.

* Further improved performance of ``fmt::Writer`` on integer formatting
  and fixed a minor regression. Now it is ~7% faster than ``karma::generate``
  on Karma's benchmark
  (`#186 <https://github.com/fmtlib/fmt/issues/186>`_).

* [Breaking] Reduced `compiled code size
  <https://github.com/fmtlib/fmt#compile-time-and-code-bloat>`_
  (`#143 <https://github.com/fmtlib/fmt/issues/143>`_,
  `#149 <https://github.com/fmtlib/fmt/pull/149>`_).

Distribution
~~~~~~~~~~~~

* [Breaking] Headers are now installed in
  ``${CMAKE_INSTALL_PREFIX}/include/cppformat``
  (`#178 <https://github.com/fmtlib/fmt/issues/178>`_).
  Thanks to `@jackyf (Eugene V. Lyubimkin) <https://github.com/jackyf>`_.

* [Breaking] Changed the library name from ``format`` to ``cppformat``
  for consistency with the project name and to avoid potential conflicts
  (`#178 <https://github.com/fmtlib/fmt/issues/178>`_).
  Thanks to `@jackyf (Eugene V. Lyubimkin) <https://github.com/jackyf>`_.

* C++ Format is now available in `Debian <https://www.debian.org/>`_ GNU/Linux
  (`stretch <https://packages.debian.org/source/stretch/cppformat>`_,
  `sid <https://packages.debian.org/source/sid/cppformat>`_) and 
  derived distributions such as
  `Ubuntu <https://launchpad.net/ubuntu/+source/cppformat>`_ 15.10 and later
  (`#155 <https://github.com/fmtlib/fmt/issues/155>`_)::

    $ sudo apt-get install libcppformat1-dev

  Thanks to `@jackyf (Eugene V. Lyubimkin) <https://github.com/jackyf>`_.

* `Packages for Fedora and RHEL <https://admin.fedoraproject.org/pkgdb/package/cppformat/>`_
  are now available. Thanks to Dave Johansen.
  
* C++ Format can now be installed via `Homebrew <http://brew.sh/>`_ on OS X
  (`#157 <https://github.com/fmtlib/fmt/issues/157>`_)::

    $ brew install cppformat

  Thanks to `@ortho <https://github.com/ortho>`_, Anatoliy Bulukin.

Documentation
~~~~~~~~~~~~~

* Migrated from ReadTheDocs to GitHub Pages for better responsiveness
  and reliability
  (`#128 <https://github.com/fmtlib/fmt/issues/128>`_).
  New documentation address is http://cppformat.github.io/.


* Added `Building the documentation
  <http://fmtlib.net/2.0.0/usage.html#building-the-documentation>`_
  section to the documentation.

* Documentation build script is now compatible with Python 3 and newer pip versions.
  (`#189 <https://github.com/fmtlib/fmt/pull/189>`_,
  `#209 <https://github.com/fmtlib/fmt/issues/209>`_).
  Thanks to `@JodiTheTigger <https://github.com/JodiTheTigger>`_ and
  `@xentec <https://github.com/xentec>`_.
  
* Documentation fixes and improvements
  (`#36 <https://github.com/fmtlib/fmt/issues/36>`_,
  `#75 <https://github.com/fmtlib/fmt/issues/75>`_,
  `#125 <https://github.com/fmtlib/fmt/issues/125>`_,
  `#160 <https://github.com/fmtlib/fmt/pull/160>`_,
  `#161 <https://github.com/fmtlib/fmt/pull/161>`_,
  `#162 <https://github.com/fmtlib/fmt/issues/162>`_,
  `#165 <https://github.com/fmtlib/fmt/issues/165>`_,
  `#210 <https://github.com/fmtlib/fmt/issues/210>`_).
  Thanks to `@syohex (Syohei YOSHIDA) <https://github.com/syohex>`_ and
  bug reporters.

* Fixed out-of-tree documentation build
  (`#177 <https://github.com/fmtlib/fmt/issues/177>`_).
  Thanks to `@jackyf (Eugene V. Lyubimkin) <https://github.com/jackyf>`_.

Fixes
~~~~~

* Fixed ``initializer_list`` detection
  (`#136 <https://github.com/fmtlib/fmt/issues/136>`_).
  Thanks to `@Gachapen (Magnus Bjerke Vik) <https://github.com/Gachapen>`_.

* [Breaking] Fixed formatting of enums with numeric format specifiers in
  ``fmt::(s)printf`` 
  (`#131 <https://github.com/fmtlib/fmt/issues/131>`_,
  `#139 <https://github.com/fmtlib/fmt/issues/139>`_):

  .. code:: c++

    enum { ANSWER = 42 };
    fmt::printf("%d", ANSWER);

  Thanks to `@Naios <https://github.com/Naios>`_.

* Improved compatibility with old versions of MinGW
  (`#129 <https://github.com/fmtlib/fmt/issues/129>`_,
  `#130 <https://github.com/fmtlib/fmt/pull/130>`_,
  `#132 <https://github.com/fmtlib/fmt/issues/132>`_).
  Thanks to `@cstamford (Christopher Stamford) <https://github.com/cstamford>`_.

* Fixed a compile error on MSVC with disabled exceptions
  (`#144 <https://github.com/fmtlib/fmt/issues/144>`_).

* Added a workaround for broken implementation of variadic templates in MSVC2012
  (`#148 <https://github.com/fmtlib/fmt/issues/148>`_).

* Placed the anonymous namespace within ``fmt`` namespace for the header-only
  configuration
  (`#171 <https://github.com/fmtlib/fmt/issues/171>`_).
  Thanks to `@alfps (Alf P. Steinbach) <https://github.com/alfps>`_.

* Fixed issues reported by Coverity Scan
  (`#187 <https://github.com/fmtlib/fmt/issues/187>`_,
  `#192 <https://github.com/fmtlib/fmt/issues/192>`_).

* Implemented a workaround for a name lookup bug in MSVC2010
  (`#188 <https://github.com/fmtlib/fmt/issues/188>`_).

* Fixed compiler warnings
  (`#95 <https://github.com/fmtlib/fmt/issues/95>`_,
  `#96 <https://github.com/fmtlib/fmt/issues/96>`_,
  `#114 <https://github.com/fmtlib/fmt/pull/114>`_,
  `#135 <https://github.com/fmtlib/fmt/issues/135>`_,
  `#142 <https://github.com/fmtlib/fmt/issues/142>`_,
  `#145 <https://github.com/fmtlib/fmt/issues/145>`_,
  `#146 <https://github.com/fmtlib/fmt/issues/146>`_,
  `#158 <https://github.com/fmtlib/fmt/issues/158>`_,
  `#163 <https://github.com/fmtlib/fmt/issues/163>`_,
  `#175 <https://github.com/fmtlib/fmt/issues/175>`_,
  `#190 <https://github.com/fmtlib/fmt/issues/190>`_,
  `#191 <https://github.com/fmtlib/fmt/pull/191>`_,
  `#194 <https://github.com/fmtlib/fmt/issues/194>`_,
  `#196 <https://github.com/fmtlib/fmt/pull/196>`_,
  `#216 <https://github.com/fmtlib/fmt/issues/216>`_,
  `#218 <https://github.com/fmtlib/fmt/pull/218>`_,
  `#220 <https://github.com/fmtlib/fmt/pull/220>`_,
  `#229 <https://github.com/fmtlib/fmt/pull/229>`_,
  `#233 <https://github.com/fmtlib/fmt/issues/233>`_,
  `#234 <https://github.com/fmtlib/fmt/issues/234>`_,
  `#236 <https://github.com/fmtlib/fmt/pull/236>`_,
  `#281 <https://github.com/fmtlib/fmt/issues/281>`_,
  `#289 <https://github.com/fmtlib/fmt/issues/289>`_).
  Thanks to `@seanmiddleditch (Sean Middleditch) <https://github.com/seanmiddleditch>`_,
  `@dixlorenz (Dix Lorenz) <https://github.com/dixlorenz>`_,
  `@CarterLi (李通洲) <https://github.com/CarterLi>`_,
  `@Naios <https://github.com/Naios>`_,
  `@fmatthew5876 (Matthew Fioravante) <https://github.com/fmatthew5876>`_,
  `@LevskiWeng (Levski Weng) <https://github.com/LevskiWeng>`_,
  `@rpopescu <https://github.com/rpopescu>`_,
  `@gabime (Gabi Melman) <https://github.com/gabime>`_,
  `@cubicool (Jeremy Moles) <https://github.com/cubicool>`_,
  `@jkflying (Julian Kent) <https://github.com/jkflying>`_,
  `@LogicalKnight (Sean L) <https://github.com/LogicalKnight>`_,
  `@inguin (Ingo van Lil) <https://github.com/inguin>`_ and
  `@Jopie64 (Johan) <https://github.com/Jopie64>`_.

* Fixed portability issues (mostly causing test failures) on ARM, ppc64, ppc64le,
  s390x and SunOS 5.11 i386 (
  `#138 <https://github.com/fmtlib/fmt/issues/138>`_,
  `#179 <https://github.com/fmtlib/fmt/issues/179>`_,
  `#180 <https://github.com/fmtlib/fmt/issues/180>`_,
  `#202 <https://github.com/fmtlib/fmt/issues/202>`_,
  `#225 <https://github.com/fmtlib/fmt/issues/225>`_,
  `Red Hat Bugzilla Bug 1260297 <https://bugzilla.redhat.com/show_bug.cgi?id=1260297>`_).
  Thanks to `@Naios <https://github.com/Naios>`_,
  `@jackyf (Eugene V. Lyubimkin) <https://github.com/jackyf>`_ and Dave Johansen.

* Fixed a name conflict with macro ``free`` defined in
  ``crtdbg.h`` when ``_CRTDBG_MAP_ALLOC`` is set
  (`#211 <https://github.com/fmtlib/fmt/issues/211>`_).

* Fixed shared library build on OS X
  (`#212 <https://github.com/fmtlib/fmt/pull/212>`_).
  Thanks to `@dean0x7d (Dean Moldovan) <https://github.com/dean0x7d>`_.

* Fixed an overload conflict on MSVC when ``/Zc:wchar_t-`` option is specified
  (`#214 <https://github.com/fmtlib/fmt/pull/214>`_).
  Thanks to `@slavanap (Vyacheslav Napadovsky) <https://github.com/slavanap>`_.

* Improved compatibility with MSVC 2008
  (`#236 <https://github.com/fmtlib/fmt/pull/236>`_).
  Thanks to `@Jopie64 (Johan) <https://github.com/Jopie64>`_.

* Improved compatibility with bcc32
  (`#227 <https://github.com/fmtlib/fmt/issues/227>`_).

* Fixed ``static_assert`` detection on Clang
  (`#228 <https://github.com/fmtlib/fmt/pull/228>`_).
  Thanks to `@dean0x7d (Dean Moldovan) <https://github.com/dean0x7d>`_.

1.1.0 - 2015-03-06
------------------

* Added ``BasicArrayWriter``, a class template that provides operations for
  formatting and writing data into a fixed-size array
  (`#105 <https://github.com/fmtlib/fmt/issues/105>`_ and
  `#122 <https://github.com/fmtlib/fmt/issues/122>`_):

  .. code:: c++
  
    char buffer[100];
    fmt::ArrayWriter w(buffer);
    w.write("The answer is {}", 42);

* Added `0 A.D. <http://play0ad.com/>`_ and `PenUltima Online (POL)
  <http://www.polserver.com/>`_ to the list of notable projects using C++ Format.

* C++ Format now uses MSVC intrinsics for better formatting performance
  (`#115 <https://github.com/fmtlib/fmt/pull/115>`_,
  `#116 <https://github.com/fmtlib/fmt/pull/116>`_,
  `#118 <https://github.com/fmtlib/fmt/pull/118>`_ and
  `#121 <https://github.com/fmtlib/fmt/pull/121>`_).
  Previously these optimizations where only used on GCC and Clang.
  Thanks to `@CarterLi <https://github.com/CarterLi>`_ and
  `@objectx <https://github.com/objectx>`_.

* CMake install target (`#119 <https://github.com/fmtlib/fmt/pull/119>`_).
  Thanks to `@TrentHouliston <https://github.com/TrentHouliston>`_.

  You can now install C++ Format with ``make install`` command.

* Improved `Biicode <http://www.biicode.com/>`_ support
  (`#98 <https://github.com/fmtlib/fmt/pull/98>`_ and
  `#104 <https://github.com/fmtlib/fmt/pull/104>`_). Thanks to
  `@MariadeAnton <https://github.com/MariadeAnton>`_ and
  `@franramirez688 <https://github.com/franramirez688>`_.

* Improved support for building with `Android NDK
  <https://developer.android.com/tools/sdk/ndk/index.html>`_
  (`#107 <https://github.com/fmtlib/fmt/pull/107>`_).
  Thanks to `@newnon <https://github.com/newnon>`_.
  
  The `android-ndk-example <https://github.com/fmtlib/android-ndk-example>`_
  repository provides and example of using C++ Format with Android NDK:

  .. image:: https://raw.githubusercontent.com/fmtlib/android-ndk-example/
            master/screenshot.png

* Improved documentation of ``SystemError`` and ``WindowsError``
  (`#54 <https://github.com/fmtlib/fmt/issues/54>`_).

* Various code improvements
  (`#110 <https://github.com/fmtlib/fmt/pull/110>`_,
  `#111 <https://github.com/fmtlib/fmt/pull/111>`_
  `#112 <https://github.com/fmtlib/fmt/pull/112>`_).
  Thanks to `@CarterLi <https://github.com/CarterLi>`_.

* Improved compile-time errors when formatting wide into narrow strings
  (`#117 <https://github.com/fmtlib/fmt/issues/117>`_).

* Fixed ``BasicWriter::write`` without formatting arguments when C++11 support
  is disabled (`#109 <https://github.com/fmtlib/fmt/issues/109>`_).

* Fixed header-only build on OS X with GCC 4.9
  (`#124 <https://github.com/fmtlib/fmt/issues/124>`_).

* Fixed packaging issues (`#94 <https://github.com/fmtlib/fmt/issues/94>`_).

* Added `changelog <https://github.com/fmtlib/fmt/blob/master/ChangeLog.rst>`_
  (`#103 <https://github.com/fmtlib/fmt/issues/103>`_).

1.0.0 - 2015-02-05
------------------

* Add support for a header-only configuration when ``FMT_HEADER_ONLY`` is
  defined before including ``format.h``:

  .. code:: c++

    #define FMT_HEADER_ONLY
    #include "format.h"

* Compute string length in the constructor of ``BasicStringRef``
  instead of the ``size`` method
  (`#79 <https://github.com/fmtlib/fmt/issues/79>`_).
  This eliminates size computation for string literals on reasonable optimizing
  compilers.

* Fix formatting of types with overloaded ``operator <<`` for ``std::wostream``
  (`#86 <https://github.com/fmtlib/fmt/issues/86>`_):

  .. code:: c++

    fmt::format(L"The date is {0}", Date(2012, 12, 9));

* Fix linkage of tests on Arch Linux
  (`#89 <https://github.com/fmtlib/fmt/issues/89>`_).

* Allow precision specifier for non-float arguments
  (`#90 <https://github.com/fmtlib/fmt/issues/90>`_):

  .. code:: c++

    fmt::print("{:.3}\n", "Carpet"); // prints "Car"

* Fix build on Android NDK
  (`#93 <https://github.com/fmtlib/fmt/issues/93>`_)

* Improvements to documentation build procedure.

* Remove ``FMT_SHARED`` CMake variable in favor of standard `BUILD_SHARED_LIBS
  <http://www.cmake.org/cmake/help/v3.0/variable/BUILD_SHARED_LIBS.html>`_.

* Fix error handling in ``fmt::fprintf``.

* Fix a number of warnings.

0.12.0 - 2014-10-25
-------------------

* [Breaking] Improved separation between formatting and buffer management.
  ``Writer`` is now a base class that cannot be instantiated directly.
  The new ``MemoryWriter`` class implements the default buffer management
  with small allocations done on stack. So ``fmt::Writer`` should be replaced
  with ``fmt::MemoryWriter`` in variable declarations.

  Old code:

  .. code:: c++

    fmt::Writer w;

  New code: 

  .. code:: c++

    fmt::MemoryWriter w;

  If you pass ``fmt::Writer`` by reference, you can continue to do so:

  .. code:: c++

      void f(fmt::Writer &w);

  This doesn't affect the formatting API.

* Support for custom memory allocators
  (`#69 <https://github.com/fmtlib/fmt/issues/69>`_)

* Formatting functions now accept `signed char` and `unsigned char` strings as
  arguments (`#73 <https://github.com/fmtlib/fmt/issues/73>`_):

  .. code:: c++

    auto s = format("GLSL version: {}", glGetString(GL_VERSION));

* Reduced code bloat. According to the new `benchmark results
  <https://github.com/fmtlib/fmt#compile-time-and-code-bloat>`_,
  cppformat is close to ``printf`` and by the order of magnitude better than
  Boost Format in terms of compiled code size.

* Improved appearance of the documentation on mobile by using the `Sphinx
  Bootstrap theme <http://ryan-roemer.github.io/sphinx-bootstrap-theme/>`_:

  .. |old| image:: https://cloud.githubusercontent.com/assets/576385/4792130/
                   cd256436-5de3-11e4-9a62-c077d0c2b003.png

  .. |new| image:: https://cloud.githubusercontent.com/assets/576385/4792131/
                   cd29896c-5de3-11e4-8f59-cac952942bf0.png
  
  +-------+-------+
  |  Old  |  New  |
  +-------+-------+
  | |old| | |new| |
  +-------+-------+

0.11.0 - 2014-08-21
-------------------

* Safe printf implementation with a POSIX extension for positional arguments:

  .. code:: c++

    fmt::printf("Elapsed time: %.2f seconds", 1.23);
    fmt::printf("%1$s, %3$d %2$s", weekday, month, day);

* Arguments of ``char`` type can now be formatted as integers
  (Issue `#55 <https://github.com/fmtlib/fmt/issues/55>`_):

  .. code:: c++

    fmt::format("0x{0:02X}", 'a');

* Deprecated parts of the API removed.

* The library is now built and tested on MinGW with Appveyor in addition to
  existing test platforms Linux/GCC, OS X/Clang, Windows/MSVC.

0.10.0 - 2014-07-01
-------------------

**Improved API**

* All formatting methods are now implemented as variadic functions instead
  of using ``operator<<`` for feeding arbitrary arguments into a temporary
  formatter object. This works both with C++11 where variadic templates are
  used and with older standards where variadic functions are emulated by
  providing lightweight wrapper functions defined with the ``FMT_VARIADIC``
  macro. You can use this macro for defining your own portable variadic
  functions:

  .. code:: c++

    void report_error(const char *format, const fmt::ArgList &args) {
      fmt::print("Error: {}");
      fmt::print(format, args);
    }
    FMT_VARIADIC(void, report_error, const char *)

    report_error("file not found: {}", path);

  Apart from a more natural syntax, this also improves performance as there
  is no need to construct temporary formatter objects and control arguments'
  lifetimes. Because the wrapper functions are very lightweight, this doesn't
  cause code bloat even in pre-C++11 mode.

* Simplified common case of formatting an ``std::string``. Now it requires a
  single function call:

  .. code:: c++

    std::string s = format("The answer is {}.", 42);

  Previously it required 2 function calls:

  .. code:: c++

    std::string s = str(Format("The answer is {}.") << 42);

  Instead of unsafe ``c_str`` function, ``fmt::Writer`` should be used directly
  to bypass creation of ``std::string``:

  .. code:: c++

    fmt::Writer w;
    w.write("The answer is {}.", 42);
    w.c_str();  // returns a C string

  This doesn't do dynamic memory allocation for small strings and is less error
  prone as the lifetime of the string is the same as for ``std::string::c_str``
  which is well understood (hopefully).

* Improved consistency in naming functions that are a part of the public API.
  Now all public functions are lowercase following the standard library
  conventions. Previously it was a combination of lowercase and
  CapitalizedWords.
  Issue `#50 <https://github.com/fmtlib/fmt/issues/50>`_.

* Old functions are marked as deprecated and will be removed in the next
  release.

**Other Changes**

* Experimental support for printf format specifications (work in progress):

  .. code:: c++

    fmt::printf("The answer is %d.", 42);
    std::string s = fmt::sprintf("Look, a %s!", "string");

* Support for hexadecimal floating point format specifiers ``a`` and ``A``:

  .. code:: c++

    print("{:a}", -42.0); // Prints -0x1.5p+5
    print("{:A}", -42.0); // Prints -0X1.5P+5

* CMake option ``FMT_SHARED`` that specifies whether to build format as a
  shared library (off by default).

0.9.0 - 2014-05-13
------------------

* More efficient implementation of variadic formatting functions.

* ``Writer::Format`` now has a variadic overload:

  .. code:: c++

    Writer out;
    out.Format("Look, I'm {}!", "variadic");

* For efficiency and consistency with other overloads, variadic overload of
  the ``Format`` function now returns ``Writer`` instead of ``std::string``.
  Use the ``str`` function to convert it to ``std::string``:

  .. code:: c++

    std::string s = str(Format("Look, I'm {}!", "variadic"));

* Replaced formatter actions with output sinks: ``NoAction`` -> ``NullSink``,
  ``Write`` -> ``FileSink``, ``ColorWriter`` -> ``ANSITerminalSink``.
  This improves naming consistency and shouldn't affect client code unless
  these classes are used directly which should be rarely needed.

* Added ``ThrowSystemError`` function that formats a message and throws
  ``SystemError`` containing the formatted message and system-specific error
  description. For example, the following code

  .. code:: c++

    FILE *f = fopen(filename, "r");
    if (!f)
      ThrowSystemError(errno, "Failed to open file '{}'") << filename;

  will throw ``SystemError`` exception with description
  "Failed to open file '<filename>': No such file or directory" if file
  doesn't exist.

* Support for AppVeyor continuous integration platform.

* ``Format`` now throws ``SystemError`` in case of I/O errors.

* Improve test infrastructure. Print functions are now tested by redirecting
  the output to a pipe.

0.8.0 - 2014-04-14
------------------

* Initial release
