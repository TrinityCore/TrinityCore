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