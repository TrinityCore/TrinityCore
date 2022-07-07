--
DELETE FROM `creature_template_addon` WHERE `entry` IN (39623,39253);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(39623, 0, 0, 0, 1, 0, '73929'), -- 39623 (Gnome Citizen) - Citizen Costume
(39253, 0, 0, 0, 1, 0, '73930'); -- 39253 (Gnome Citizen) - Citizen Costume

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (35007);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35007) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(35007,0,0,0,60,0,100,0,0,0,10000,10000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lixa Felflinger - On Update - Cast 'Frost Armor'");

UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=14365; -- 14365 (Thief Catcher Farmountain)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=14367; -- 14367 (Thief Catcher Thunderbrew)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=14363; -- 14363 (Thief Catcher Shadowdelve)
UPDATE `creature_addon` SET `bytes2`=257, `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 14365);
UPDATE `creature_addon` SET `bytes2`=257, `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 14367);
UPDATE `creature_addon` SET `bytes2`=257, `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 14363);
UPDATE `creature_addon` SET `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 853);

UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=713; -- Balir Frosthammer
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=658; -- Sten Stoutarm
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=829; -- Adlin Pridedrift

UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=8503; -- Gibblewilt
UPDATE `creature` SET `position_x` = -5065.525, `position_y` = 455.10654, `position_z` = 410.40417, `orientation` = 0.978891611099243164, `wander_distance` = 0, `MovementType` = 0, `VerifiedBuild` = 12340 WHERE `guid` = 2470 AND `id` = 8503;

UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=1211; -- Leper Gnome
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=35600; -- Arcanist Laniria
UPDATE `creature_template` SET `unit_flags`=576 WHERE `entry`=35025; -- Lynette Bracer
UPDATE `creature_template` SET `BaseAttackTime`=2000 WHERE `entry`=31144; -- Training Dummy
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=39623; -- Gnome Citizen
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=39253; -- Gnome Citizen

DELETE FROM `creature_text` WHERE `CreatureID` = 6175;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(6175,0,0,"Don't forget the orphans of Stormwind!",12,0,100,0,0,0,2401,0,"John Turner"),
(6175,0,1,"Help the children of Stormwind... victims of the war and plague!",12,0,100,0,0,0,2402,0,"John Turner"),
(6175,0,2,"Give to the charities who seek to help the victims of these hard times! Please.",12,0,100,0,0,0,2403,0,"John Turner"),
(6175,0,3,"Give of your hearts and your purses! Give to the children of Stormwind who have lost their parents.",12,0,100,0,0,0,2404,0,"John Turner");

-- Remove previously added scripts, handled in core
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` IN (32169,32170,35596);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32169,32170,35596) AND `source_type` = 0;
