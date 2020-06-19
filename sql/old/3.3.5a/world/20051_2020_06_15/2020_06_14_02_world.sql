--
UPDATE `creature_template` SET `flags_extra` = `flags_extra` |2 WHERE `entry` = 14081;
UPDATE `creature_template` SET `unit_flags` = 33555200, `AIName` = "" WHERE `entry` = 22336;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22336 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2233600 AND `source_type` = 9;
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (14081,22336);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(14081,1,1,0,1,0,0),
(22336,1,1,0,1,0,0);
DELETE FROM `creature_template_addon` WHERE `entry` IN (14081,22336);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(14081,"22391"),
(22336,"38878");
