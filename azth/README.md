# AzerothShard Development standards

AzerothShard follows an **open development model**, we share with TrinityCore all our blizzlike fixes.

So if you have a blizzlike fix for AzerothShard, try to merge it into TrinityCore first. In this way your code helps the global development and can be reviewed by many more developers, and **everyone gains**.

Following guidelines describe how to handle all of the custom code.
With **custom**, we mean all stuff we need that **can't** be merged into TrinityCore (for any reason).

## Custom Commits

- Every commit that introduces custom changes should be labelled with the **[AZTH]** tag in its commit name
- Try to [squash commits](https://ariejan.net/2011/07/05/git-squash-your-latests-commits-into-one/) when they are all about the same thing

## Custom Code

All custom code must be surrounded by ```// [AZTH]```  and ```// [/AZTH]``` tags. Example:

```
// [AZTH]

// custom code

// [/AZTH]
```

## Custom SQL files

### Directory structure

All custom SQL files are placed under **/azth/data/sql** folder, divided into 2 categories:

- Structure files in **/azth/data/sql/struct** 
- Contents files in **/azth/data/sql/content**

Each category has 3 folders, one for each database:

- world
- characters
- auth

### File names

Every SQL file must be named using the following format: azth_*database*_*description*.sql

Example: **azth_world_queue_announcer.sql**

For structure SQL files the *description* should be the *table name*.

### SQL code format

Every SQL file must be **re-executable**. That means that you have to ```DELETE``` before ```INSERT```, and ```DROP TABLE``` before ```CREATE TABLE IF NOT EXIST```.

In order to ensure that your SQL code is re-executable, try to **run it twice before committing it**.

