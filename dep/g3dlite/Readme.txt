 Due to issues with G3D normally requiring X11 and the ZIP-library, the library version in this sourcetree contains a modified version.
The applied patches are added as .diff-files to the repository for future reference (knowing what was changed is quite handy).

G3D-v8.0_hotfix1.diff - 2010-08-27 - remove dependency on zip/z11 libraries, add support for 64-bit arch
G3D-v8.0_hotfix2.diff - 2012-01-14 - fix typo in isNaN(float x)
G3D-v8.0_hotfix3.diff - 2012-08-26 - fix compilation on Fedora Linux
G3D-v8.0_hotfix4.diff - 2012-11-09 - fix compilation on OSX
G3D-v8.0_hotfix5.diff - 2013-02-27 - fix compilation in cygwin environments
G3D-v8.0_hotfix6.diff - 2013-03-08 - fix compilation in mingw
G3D-v8.0_hotfix7.diff - 2013-08-31 - fix typo in Matrix4 == operator
G3D-v8.0_hotfix8.diff - 2013-09-01 - fix typo in Vector3int32 += operator
G3D-v8.0_hotfix9.diff - 2014-06-01 - only VS < 10 don't ship inttypes.h
G3D-v9.0 hotfix1.diff - 2014-08-22 - updated to G3D9, reapplied previous patches and removed unneeded changes
G3D-v9.0 hotfix2.diff - 2014-08-23 - fix some -Wconversion warnings
G3D-v9.0 hotfix3.diff - 2015-06-28 - fix some warnings
G3D-v9.0 hotfix4.diff - 2015-07-02 - backport G3D10 fix
G3D-v9.0 hotfix5.diff - 2015-07-31 - fix MSVC 2015 warning: dep/g3dlite/include/G3D/Quat.h(352): warning C4458: declaration of 'x' hides class member
G3D-v9.0 hotfix6.diff - 2015-11-04 - fix adding std::shared_ptr, std::weak_ptr, std::dynamic_pointer_cast, std::static_pointer_cast and std::enable_shared_from_this to global namespace
G3D-v9.0 hotfix7.diff - 2016-10-10 - fix warning on clang 3.8 backported from G3D 10
G3D-v9.0 hotfix8.diff - 2017-03-07 - fix MSVC 2017 build
G3D-v9.0 hotfix9.diff - 2020-07-13 - warning fixes
G3D-v9.0 hotfix10.diff - 2017-11-11 - static analysis issue fix
G3D-v9.0 hotfix11.diff - 2017-11-11 - static analysis issue fix
G3D-v9.0 hotfix12.diff - 2020-02-23 - ARM64 build fix
G3D-v9.0 hotfix13.diff - 2020-08-04 - MSVC build fix with /permissive-
G3D-v9.0 hotfix14.diff - 2022-01-16 - warning fixes
G3D-v9.0 hotfix16.diff - 2022-02-11 - Fix *BSD compile errors
