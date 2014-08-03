SET @MECHANIC_CHARM     = 1;
SET @MECHANIC_FEAR      = 16;
SET @MECHANIC_ROOT      = 64;
SET @MECHANIC_SLEEP     = 512;
SET @MECHANIC_FREEZE    = 4096;
SET @MECHANIC_POLYMORPH = 65536;
SET @MECHANIC_SAPPED    = 536870912;

UPDATE `creature_template`
    SET `mechanic_immune_mask`= `mechanic_immune_mask`|@MECHANIC_CHARM|@MECHANIC_FEAR|@MECHANIC_ROOT|@MECHANIC_SLEEP|@MECHANIC_FREEZE|@MECHANIC_POLYMORPH|@MECHANIC_SAPPED
    WHERE `ScriptName` LIKE 'boss_%' OR
    `entry` IN (SELECT `difficulty_entry_1` FROM (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `ScriptName` LIKE 'boss_%') AS diff1) OR
    `entry` IN (SELECT `difficulty_entry_2` FROM (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `ScriptName` LIKE 'boss_%') AS diff2) OR
    `entry` IN (SELECT `difficulty_entry_3` FROM (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `ScriptName` LIKE 'boss_%') AS diff3);
