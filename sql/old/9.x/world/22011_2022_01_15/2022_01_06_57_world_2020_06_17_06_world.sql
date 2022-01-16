-- It's just quest credit NPC
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 23393;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23393 AND `source_type` = 0;
