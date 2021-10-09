# Contributing

So, you want to contribute? Great!  
Contributing is not only about creating fixes, but also reporting bugs. Before reporting a bug, please make sure to use the latest core and database revision.  


Issues
======

Read [this](https://community.trinitycore.org/topic/37-the-trinitycore-issuetracker-and-you/) before creating a ticket.  
If you have problems with TrinityCore installation, read [this](https://community.trinitycore.org/topic/13962-trouble-with-your-trinity-install-starting-login-readme-1st-faqs/).

Mandatory things when creating a ticket:  
========================================

- Branch  
- commit hash (if you get something like TrinityCore rev. unknown 1970-01-01 00:00:00 +0000 (Archived branch) (Win64, Release), please read this [post](https://community.trinitycore.org/topic/345-howto-properly-install-git-on-windows-fix-trinitycore-rev-1970-01-01-000000-0000/) or clone this repository instead downloading the source code.  
- entries of affected creatures / items / quests with a link to the relevant wowhead page.  
- clear title and description of the bug - if your english is very bad, please use google translate or yandex to translate to english and include one text in your native language.

When reporting a crash, you MUST compile in debug mode because release dumps are useless (not enough information) - if you don't know how to compile in debug, read [this](https://community.trinitycore.org/topic/13962-trouble-with-your-trinity-install-starting-login-readme-1st-faqs/?tab=comments#comment-47672)

We sugest the title and body to have the next style:

DB/Quest: The Collapse

4.3.4 branch  
hash 63f96a282307  
The quest "The Collapse" http://www.wowhead.com/quest=11706 lacks final event.

Creating Pull Requests:
=======================

1. Fork it.
2. Create a branch (`git checkout -b fixes`) (Note: fixes is an arbitrary name, choose whatever you want here)
3. Commit your changes (`git commit -am "Added Snarkdown"`)
4. Push to the branch (`git push origin fixes`)
5. Open a Pull Request


When creating patches read:
- [TrinityCore Development Standards](https://trinitycore.atlassian.net/wiki/spaces/tc/pages/2130103/C+Development+Standards)
- [WDB Fields](https://community.trinitycore.org/topic/58-wdb-fields/)
- [Git Squash](https://ariejan.net/2011/07/05/git-squash-your-latests-commits-into-one/)


We suggest that you create one branch for each C++ based fix: this will allow you to create more fixes without having to wait for your pull request to be merged.  
For the SQL files coming with C++ based fixes the naming schema is `YYYY_MM_DD_i_database.sql`, where `YYYY_MM_DD` is the date of the fix, `i_database` is the *ith* sql created that day for `database`.  
When doing changes to `auth` or `characters` database remember to update the base files (`/sql/base/*`).  
For SQL only fixes, please [create a ticket](https://github.com/TrinityCore/TrinityCore/issues/new/choose).
Since it's very unlikely that your Pull Request will be merged on the day that you open it, please name the files with an impossible date to avoid merging issues ie: 2015_13_32_00_world.sql

Wiki
====

The wiki is located at [http://trinitycore.info](http://trinitycore.info).

You are welcome to create an account and help us improve and extend the wiki.


Requirements
============


Software requirements are available in the [wiki](http://www.trinitycore.info/display/tc/Requirements) for
Windows, Linux and Mac OSX.

If you choose Linux, we recommend to use Debian 8, since it's the Linux that we use to test compilations.
