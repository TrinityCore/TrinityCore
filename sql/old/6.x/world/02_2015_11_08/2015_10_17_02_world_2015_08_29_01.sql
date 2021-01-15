--
DELETE FROM `creature_template_addon` WHERE `entry` IN (30477, 30487);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(30477, 0, 0, 33554432, 0, 0, '55971'),
(30487, 0, 0, 33554432, 0, 0, '55971');
UPDATE `creature_template` SET `vehicleid`=110 WHERE `entry`=28192;
UPDATE `creature_template` SET `Inhabittype`=4 WHERE `entry`=24767;

UPDATE `creature_template` SET `InhabitType`=4, `speed_run`=2.14286, `unit_flags`=33288 WHERE `entry`=27923;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27923) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27923,0,0,0,54,0,100,0,0,0,0,0,1,0,2000,0,0,0,0,7,0,0,0,0,0,0,0,'Lou the Cabin Boy - On summon - Say line'),
(27923,0,1,0,52,0,100,0,0,27923,0,0,53,1,27923,0,0,0,0,1,0,0,0,0,0,0,0,'Lou the Cabin Boy - On text over - Start WP movement'),
(27923,0,3,0,40,0,100,0,13,27923,0,0,1,1,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Lou the Cabin Boy - On WP 13 reached - Say line'),
(27923,0,4,0,52,0,100,0,1,27923,0,0,28,46598,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lou the Cabin Boy - On text over - Remove aura Ride Vehicle Hardcoded');

DELETE FROM `creature_template_addon` WHERE `entry`=23982;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(23982,0,0,1,0,0,'29266');

SET @CGUID := 88474;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@CGUID+0,0,0,1,0,0,'45319'),
(@CGUID+1,0,0,1,0,0,'45319'),
(@CGUID+2,0,0,1,0,0,'45319'),
(@CGUID+3,0,0,1,0,0,'45319'),
(@CGUID+4,0,0,1,0,0,'45319'),
(@CGUID+5,0,0,1,0,0,'45319'),
(@CGUID+6,0,0,1,0,0,'45319'),
(@CGUID+7,0,0,1,0,0,'45319'),
(@CGUID+8,0,0,1,0,0,'45319'),
(@CGUID+9,0,0,1,0,0,'45319'),
(@CGUID+10,0,0,1,0,0,'45319'),
(@CGUID+11,0,0,1,0,0,'45319');
