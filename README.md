⚔️ TrinityCore + Wrapper (WP) — Stable WoW World Platform with Runtime Modules 🛠️

Welcome to my TrinityCore + Dev. yukoNw !
This repository combines official TrinityCore updates with my custom enhancements, creating a stable and playable WoW world platform. The key difference: game logic is handled by runtime modules, loaded as DLL libraries, without needing to rebuild the server.

📌 What's Inside
🔄 Synchronized Master Branch

All recent TrinityCore commits are carefully merged with my local modifications and optimizations. The commit history is clean, and conflicts are resolved locally with minimal changes.

🧩 Adapter + Library (WP)

WP Adapter — a minimal layer inside worldserver that intercepts only the necessary TrinityCore methods (spells, damage, combat, movement, etc.)

WP Library — a runtime library that processes events, routes them to modules, and returns the results back to the adapter

Support for dynamic DLL modules, which can be loaded, unloaded, and updated without rebuilding the server

Configured pipelines and utilities for fast testing and module integration

⚡ Hook Preservation & Compatibility

Modifications are designed to keep standard TrinityCore hooks intact. This allows official features to continue working while extending functionality through runtime modules.

🎯 Fork Objective

The goal of this repository is to create a stable and playable WoW world on top of TrinityCore with the ability to:

🛠️ Use runtime modules via the adapter + library for any game mechanics

🔗 Minimize interference with the official server hooks

🌐 Integrate official TrinityCore updates into a single working repository

🧪 Safely test, extend, and fix logic without rebuilding the worldserver

💡 Advantages

✅ Single repository containing both official and custom changes
🧩 Adapter + runtime library supporting DLL modules
🔄 Up-to-date server with regular upstream synchronization
🚀 Ready for local build and testing immediately after cloning
📝 Transparent commit history for easy tracking and rollback

MY DISCORD: yukoNw



# ![logo](https://community.trinitycore.org/public/style_images/1_trinitycore.png) TrinityCore (master)

[![Average time to resolve an issue](https://isitmaintained.com/badge/resolution/TrinityCore/TrinityCore.svg)](https://isitmaintained.com/project/TrinityCore/TrinityCore "Average time to resolve an issue") [![Percentage of issues still open](https://isitmaintained.com/badge/open/TrinityCore/TrinityCore.svg)](https://isitmaintained.com/project/TrinityCore/TrinityCore "Percentage of issues still open")

--------------


* [Build Status](#build-status)
* [Introduction](#introduction)
* [Requirements](#requirements)
* [Install](#install)
* [Reporting issues](#reporting-issues)
* [Submitting fixes](#submitting-fixes)
* [Copyright](#copyright)
* [Authors &amp; Contributors](#authors--contributors)
* [Links](#links)



## Build Status

master | 3.3.5 | cata_classic
:------------: | :------------: | :------------:
[![master Build Status](https://circleci.com/gh/TrinityCore/TrinityCore/tree/master.svg?style=shield)](https://circleci.com/gh/TrinityCore/TrinityCore/tree/master) | [![3.3.5 Build Status](https://circleci.com/gh/TrinityCore/TrinityCore/tree/3.3.5.svg?style=shield)](https://circleci.com/gh/TrinityCore/TrinityCore/tree/3.3.5) | [![cata_classic Build Status](https://circleci.com/gh/TrinityCore/TrinityCore/tree/cata_classic.svg?style=shield)](https://circleci.com/gh/TrinityCore/TrinityCore/tree/cata_classic)
[![master Build status](https://ci.appveyor.com/api/projects/status/54d0u1fxe50ad80o/branch/master?svg=true)](https://ci.appveyor.com/project/DDuarte/trinitycore/branch/master) | [![Build status](https://ci.appveyor.com/api/projects/status/54d0u1fxe50ad80o/branch/3.3.5?svg=true)](https://ci.appveyor.com/project/DDuarte/trinitycore/branch/3.3.5) | [![Build status](https://ci.appveyor.com/api/projects/status/54d0u1fxe50ad80o/branch/cata_classic?svg=true)](https://ci.appveyor.com/project/DDuarte/trinitycore/branch/cata_classic)
[![master GCC Build status](https://github.com/TrinityCore/TrinityCore/actions/workflows/gcc-build.yml/badge.svg?branch=master&event=push)](https://github.com/TrinityCore/TrinityCore/actions?query=workflow%3AGCC+branch%3Amaster+event%3Apush) | [![3.3.5 GCC Build status](https://github.com/TrinityCore/TrinityCore/actions/workflows/gcc-build.yml/badge.svg?branch=3.3.5&event=push)](https://github.com/TrinityCore/TrinityCore/actions?query=workflow%3AGCC+branch%3A3.3.5+event%3Apush) | [![cata_classic GCC Build status](https://github.com/TrinityCore/TrinityCore/actions/workflows/gcc-build.yml/badge.svg?branch=cata_classic&event=push)](https://github.com/TrinityCore/TrinityCore/actions?query=workflow%3AGCC+branch%3Acata_classic+event%3Apush)
[![master macOS arm64 Build status](https://github.com/TrinityCore/TrinityCore/actions/workflows/macos-arm-build.yml/badge.svg?branch=master&event=push)](https://github.com/TrinityCore/TrinityCore/actions?query=workflow%3AGCC+branch%3Amaster+event%3Apush) | | [![cata_classic macOS arm64 Build status](https://github.com/TrinityCore/TrinityCore/actions/workflows/macos-arm-build.yml/badge.svg?branch=cata_classic&event=push)](https://github.com/TrinityCore/TrinityCore/actions?query=workflow%3AGCC+branch%3Acata_classic+event%3Apush)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/435/badge.svg)](https://scan.coverity.com/projects/435) | [![Coverity Scan Build Status](https://scan.coverity.com/projects/4656/badge.svg)](https://scan.coverity.com/projects/4656) |

## Introduction

TrinityCore is a *MMORPG* Framework based mostly in C++.

It is derived from *MaNGOS*, the *Massive Network Game Object Server*, and is
based on the code of that project with extensive changes over time to optimize,
improve and cleanup the codebase at the same time as improving the in-game
mechanics and functionality.

It is completely open source; community involvement is highly encouraged.

If you wish to contribute ideas or code, please visit our site linked below or
make pull requests to our [Github repository](https://github.com/TrinityCore/TrinityCore/pulls).

For further information on the TrinityCore project, please visit our project
website at [TrinityCore.org](https://www.trinitycore.org).

## Requirements


Software requirements are available in the [wiki](https://trinitycore.info/en/install/requirements) for
Windows, Linux and macOS.


## Install

Detailed installation guides are available in the [wiki](https://trinitycore.info/en/home) for
Windows, Linux and macOS.


## Reporting issues

Issues can be reported via the [Github issue tracker](https://github.com/TrinityCore/TrinityCore/labels/Branch-master).

Please take the time to review existing issues before submitting your own to
prevent duplicates.

In addition, thoroughly read through the [issue tracker guide](https://community.trinitycore.org/topic/37-the-trinitycore-issuetracker-and-you/) to ensure
your report contains the required information. Incorrect or poorly formed
reports are wasteful and are subject to deletion.


## Submitting fixes

C++ fixes are submitted as pull requests via Github. For more information on how to
properly submit a pull request, read the [how-to: maintain a remote fork](https://community.trinitycore.org/topic/9002-howto-maintain-a-remote-fork-for-pull-requests-tortoisegit/).
For SQL only fixes, open a ticket; if a bug report exists for the bug, post on an existing ticket.


## Copyright

License: GPL 2.0

Read file [COPYING](COPYING).


## Authors &amp; Contributors

Read file [AUTHORS](AUTHORS).


## Links

* [Website](https://www.trinitycore.org)
* [Wiki](https://www.trinitycore.info)
* [Forums](https://talk.trinitycore.org/)
* [Discord](https://discord.trinitycore.org/)
