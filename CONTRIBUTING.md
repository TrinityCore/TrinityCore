# Contributing

Want to contribute? Great!  
Contributing don't means only creating fixes, also reporting bugs, before reporting a bug, be sure you have updated your core AND database to the latest avariable code.

Mandatory things when creating a ticket:  
========================================

Branch, commit hash (if you get something like TrinityCore rev. unknown 1970-01-01 00:00:00 +0000 (Archived branch) (Win64, Release) read [unknown](http://www.trinitycore.org/f/topic/345-howto-properly-install-git-on-windows-fix-trinitycore-rev-1970-01-01-000000-0000/) or clone this repository instead download source.  
Entries of afected creatures / items / quests please, use wowhead to link them.  
Clear title and description of the bug. If your english is very bad i sugest you to use google translate or yandex to translate to english and include one text on your native language.
  
We sugest the title and body to have the next style:
  
DB/Quest: The Collapse

4.3.4 branch  
hash 63f96a282307  
The quest "The Collapse" http://www.wowhead.com/quest=11706 lacks final event.

Issues
======

Read [this](http://www.trinitycore.org/f/topic/37-the-trinitycore-issuetracker-and-you/) before creating a ticket.  
If you have problems with TrinityCore instalation, read [this](http://www.trinitycore.org/f/topic/1518-trouble-with-your-trinity-install-readme-1st-faqs/)

1. Fork it.
2. Create a branch (`git checkout -b fixes`)
3. Commit your changes (`git commit -am "Added Snarkdown"`)
4. Push to the branch (`git push origin fixes`)
5. Open a Pull Request


When creating patches read:
- [TrinityCore Development Standards](http://www.trinitycore.org/f/topic/6-trinitycore-developing-standards/)
- [WDB Fields](http://www.trinitycore.org/f/topic/58-wdb-fields/)
- [Git Squash](https://ariejan.net/2011/07/05/git-squash-your-latests-commits-into-one/)

We suggest you to create one branch for each `C++` based fix: on that way you can continue creating more fixes without having to wait to get one pull request merged.  
For the `SQL` files of `C++` based fixes the naming schema is: `YYYY_MM_DD_i_database.sql`, where `YYYY_MM_DD` is the date of the fix, `i_database` is the *ith* sql created that day for `database`. 
When doing changes to `auth` or `characters` database remember to update the base files (`/sql/base/*`).  
For SQL only fixes [create a ticket](https://github.com/TrinityCore/TrinityCore/issues/new).
Since it's very unlikely the Pull Request you make will be merged on the same time you do it, we recomend to name the files for impossible date to avoid merging issues ie:
2015_13_32_00_world.sql

Wiki
====

The wiki is located at [http://trinitycore.info](http://trinitycore.info).

You are welcome to create an account and help us improve and extend the wiki.


Requirements
============

Platform: Linux, Windows or Mac  
Processor with SSE2 support  
Boost ≥ 1.4.9  
MySQL ≥ 5.1.0
CMake ≥ 2.8.11.2 / 2.8.9 (Windows / Linux) 
OpenSSL ≥ 1.0.0  
GCC ≥ 4.7.2 (Linux only)  
MS Visual Studio ≥ 12 (2013) Update 4 (Windows only)

In case you choose Linux, we recommend to use Debian 8, it's the Linux we use to test compilations.