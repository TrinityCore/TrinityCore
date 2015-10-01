-- 
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=28253;

SET @ENTRY := 30736;
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`=33555200, `InhabitType`=4 WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,75,57806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Released Soul - Just summoned - Add aura"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,4,37,0,0,0,0,0,1,0,0,0,0,0,0,0,"Released Soul - Just summoned - Play sound"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Released Soul - Just summoned - Set run off"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,114,40,0,0,0,0,0,1,0,0,0,0,0,0,0,"Released Soul - Just summoned - Rise up"),
(@ENTRY,0,4,0,54,0,100,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Released Soul - Just summoned - Despawn");

UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry` IN (30850,30852,30841);

UPDATE `creature_template` SET `unit_flags`=131076, `flags_extra`=66 WHERE `entry`=25534;

UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=26271;
UPDATE `creature` SET `unit_flags`=537166592 WHERE `guid` IN (110812, 110813, 110814, 110815, 110816, 110817);

DELETE FROM `creature_addon` WHERE `guid` IN (110812, 110813, 110814, 110815, 110816, 110817);
INSERT INTO `creature_addon` (`guid`, `bytes2`, `auras`) VALUES 
(110812, 1, "29266"),
(110813, 1, "29266"),
(110814, 1, "29266"),
(110815, 1, "29266"),
(110816, 1, "29266"),
(110817, 1, "29266");

UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=31402;

UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=30501;

DELETE FROM `creature` WHERE `guid`=120496 AND `id`=28414;

DELETE FROM `creature_template_addon` WHERE `entry` IN (28413);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(28413, 0, "54450");

UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry` IN (28413);
