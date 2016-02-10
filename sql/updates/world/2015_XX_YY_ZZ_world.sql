-- Using ignis in Ulduar for testing (no mobs there whom are constantly casting stuff and making the combat log unusable compard to Naxxramas).
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 512 WHERE `entry`=33118;

-- Query to update every boss. this flag should be remove either in script or by db queries for the known exceptions.
-- UPDATE `creature_template`
-- SET `flags_extra` = `flags_extra` | 512
-- WHERE `ScriptName` LIKE 'boss_%' OR
-- `entry` IN (SELECT `difficulty_entry_1` FROM (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `ScriptName` LIKE 'boss_%') AS diff1) OR
-- `entry` IN (SELECT `difficulty_entry_2` FROM (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `ScriptName` LIKE 'boss_%') AS diff2) OR
-- `entry` IN (SELECT `difficulty_entry_3` FROM (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `ScriptName` LIKE 'boss_%') AS diff3);