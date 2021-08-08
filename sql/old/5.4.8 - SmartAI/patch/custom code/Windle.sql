
DELETE FROM `creature` WHERE `id`=29261;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(701297, 29261, 648, 1, 1, 0, 846, -8419.85, 1366.64, 104.683, 3.78562, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(701295, 29261, 530, 1, 1, 0, 846, 10356.8, -6360.38, 34.246, 2.58522, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(701286, 29261, 0, 1, 1, 0, 846, -8915.6, -138.262, 80.7076, 1.20794, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(701294, 29261, 1, 1, 1, 0, 846, -2907.98, -262.248, 59.4995, 2.48657, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(701293, 29261, 0, 1, 1, 0, 846, 1694.46, 1700.83, 136.457, 0.715848, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(102700, 29261, 571, 1, 1, 26078, 0, 5744.94, 681.546, 644.136, 5.65487, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(701292, 29261, 1, 1, 1, 0, 846, -613.903, -4247.12, 38.9565, 3.75577, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(701291, 29261, 638, 1, 1, 0, 846, -1445.89, 1400.07, 35.5561, 2.33735, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(701290, 29261, 530, 1, 1, 0, 846, -3967.65, -13927.8, 100.548, 5.95801, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(701289, 29261, 0, 1, 1, 0, 846, -4977.59, 875.326, 274.933, 2.88005, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(701288, 29261, 1, 1, 1, 0, 846, 10316.7, 833.608, 1326.38, 3.55611, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0),
(701287, 29261, 0, 1, 1, 0, 846, -6226.11, 336.117, 383.235, 3.95056, 300, 0, 0, 8508, 7981, 0, 0, 0, 0, 0);


SET @ENTRY := 29261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES

(@ENTRY,0,0,0,1,0,100,0,5000,5000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC');

-- NPC talk text insert
SET @ENTRY := 29261;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Hi!I\'m Windle! You are using SmartAI scripts made by user with nick ~cooler~. Mobs can use spells,cosmetic fixes approved,many texts for mobs,exclusive phases for difficult events - all are here. Thanks for your choice!( Contact by Skype: cooler19860212 ),',0,0,100,1,0,0, 'OOC say');
