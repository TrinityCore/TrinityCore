# Contributing

Want to contribute? Great!

1. Fork it.
2. Create a branch (`git checkout -b fixes`)
3. Commit your changes (`git commit -am "Added Snarkdown"`)
4. Push to the branch (`git push origin fixes`)
5. Open a [Pull Request][1]


When creating patches read:
- [TrinityCore Development Standards](http://www.trinitycore.org/f/topic/6-trinitycore-developing-standards/)
- [WDB Fields](http://www.trinitycore.org/f/topic/58-wdb-fields/)
- [Git Squash](https://ariejan.net/2011/07/05/git-squash-your-latests-commits-into-one/)

We suggest you to create one branch for each `C++` based fix: on that way you can continue creating more fixes without having to wait to get one pull request merged.
For the `SQL` files of `C++` based fixes the naming schema is: `YYYY_MM_DD_i_database_description.sql`, where `YYYY_MM_DD` is the date of the fix, `i_database` is the *ith* sql created that day for `database`.
When doing changes to `auth` or `characters` database remember to update the base files (`/sql/base/*`).
For SQL only fixes [create a ticket](https://github.com/TrinityCore/TrinityCore/issues/new).

Wiki
====

The wiki is located at [http://trinitycore.info](http://trinitycore.info).

You are welcome to create an account and help us improve and extend the wiki.


Issues
======

Read [this](http://www.trinitycore.org/f/topic/37-the-trinitycore-issuetracker-and-you/) before creating a ticket.
If you have problems with TrinityCore instalation, read http://www.trinitycore.org/f/topic/1518-trouble-with-your-trinity-install-readme-1st-faqs/


Requirements
============

Platform: Linux, Windows or Mac
Processor with SSE2 support
Boost ≥ 1.4.9
MySQL ≥ 5.1.0
CMake ≥ 2.8.11.2 / 2.8.9 (Windows / Linux)
OpenSSL ≥ 1.0.0
GCC ≥ 4.7.2 (Linux only)
MS Visual Studio ≥ 12 (2013) (Windows only)

In case you choose Linux, we recommend to use Debian 7, it's the Linux we use to test compilations.
Remember 4.3.4 branch is alpha, only intended for development, we don't recomend this branch to run a server.
