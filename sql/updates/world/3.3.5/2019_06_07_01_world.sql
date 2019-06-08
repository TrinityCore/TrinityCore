-- 
UPDATE `creature_template` SET `unit_flags`=768, `RegenHealth`=1 WHERE `entry` IN (23625,23624,23626,23623,23619);
DELETE FROM `creature` WHERE `guid` IN (111035, 111036, 111037, 111039, 111040, 111074, 111076, 111077, 111078, 111079, 111080, 111081, 111082,111083);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(111035, 23854, 230, 1584, 1584, 1, 1, 0, 0, 843.4062, -178.1329, -49.66997, 2.042035, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23854 (Area: 1584 - Difficulty: 1)
(111036, 23850, 230, 1584, 1584, 1, 1, 0, 0, 846.0439, -177.7303, -49.67037, 2.111848, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23850 (Area: 1584 - Difficulty: 1)
(111037, 23852, 230, 1584, 1584, 1, 1, 0, 0, 842.7178, -181.5613, -49.66998, 1.937315, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23852 (Area: 1584 - Difficulty: 1)
(111039, 23853, 230, 1584, 1584, 1, 1, 0, 0, 847.6445, -175.8458, -49.67056, 2.076942, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23853 (Area: 1584 - Difficulty: 1)
(111040, 23855, 230, 1584, 1584, 1, 1, 0, 0, 847.5542, -180.6305, -49.67069, 2.042035, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23855 (Area: 1584 - Difficulty: 1)
(111074, 23830, 230, 1584, 1584, 1, 1, 0, 0, 846.5654, -178.9536, -49.67049, 2.076942, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23830 (Area: 1584 - Difficulty: 1)
(111076, 23845, 230, 1584, 1584, 1, 1, 0, 0, 851.3013, -177.1584, -49.67116, 2.146755, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23845 (Area: 1584 - Difficulty: 1)
(111077, 23625, 230, 1584, 1584, 1, 1, 0, 0, 847.6739, -175.8695, -49.67056, 2.111848, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23625 (Area: 1584 - Difficulty: 1)
(111078, 23624, 230, 1584, 1584, 1, 1, 0, 0, 842.7151, -181.571, -49.66998, 2.042035, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23624 (Area: 1584 - Difficulty: 1)
(111079, 23626, 230, 1584, 1584, 1, 1, 0, 0, 843.4564, -178.1454, -49.66998, 2.059489, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23626 (Area: 1584 - Difficulty: 1)
(111080, 23623, 230, 1584, 1584, 1, 1, 0, 0, 847.8387, -181.1154, -49.67075, 1.867502, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23623 (Area: 1584 - Difficulty: 1)
(111081, 23619, 230, 1584, 1584, 1, 1, 0, 0, 851.2717, -177.1259, -49.67115, 2.164208, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- 23619 (Area: 1584 - Difficulty: 1)
(111082, 28210, 230, 1584, 1584, 1, 1, 0, 2, 847.1571, -187.3589, -49.754269, 2.06561, 7200, 0, 0, 0, 0, 0, 0, 0, 0, -1),
(111083, 28209, 230, 1584, 1584, 1, 1, 0, 2, 853.8105, -183.515, -49.7542, 2.117463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, -1);

DELETE FROM `game_event_creature` WHERE `guid` IN (111035, 111036, 111037, 111039, 111040, 111074, 111076, 111077, 111078, 111079, 111080, 111081, 86803, 86801, 86802, 111082, 111083) AND `eventEntry` IN (81,-81);
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(81,111035),(81,111036),
(81,111037),(81,111039),
(81,111040),(81,111074),
(81,111076),(81,111077),
(81,111078),(81,111079),
(81,111080),(81,111081),
(-81,86803),(81,111082),
(81,111083),(-81,86802),
(-81,86801);

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=28209 AND `ID`=2) OR (`CreatureID`=28210 AND `ID`=2); 
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(28209, 2, 2704, 0, 0),
(28210, 2, 2704, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (111082,111083);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(111082, 0, 0, 0, 1, 10, ''), -- emote 423  for master
(111083, 0, 0, 0, 1, 10, ''); -- emote 423  for master

DELETE FROM `game_event` WHERE `eventEntry`=81;
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`description`,`world_event`) VALUES
(81, '2016-10-28 20:00:00', '2020-12-31 20:05:00',1440,5,0, 'L70ETC Grim Guzzler',0);

DELETE FROM `creature_text` WHERE `CreatureID`=28210;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(28210, 0, 0, "Let's wrap it up, Miz. They'll be here in a second.", 12, 0, 100, 396, 0, 0, 27603, 'Ognip Blastbolt');

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (9666,9667) AND `OptionID`=0;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `VerifiedBuild`) VALUES
(9666, 0, 0, 'But I drove my mole machine all the way down here...', 27600, 1, 1, 9667, 23420),
(9667, 0, 0, "I\'m ready.", 27602, 1, 1, 0, 23420);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (9666);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9666,0,0,2,37863,1,0,0,0,'','Ognip Blastbolt - Show gossip option if player has Direbrews Remote in bags'),
(15,9666,0,0,12,81,0,0,1,0,'','Ognip Blastbolt - Show gossip option if player has Direbrews Remote in bags');

UPDATE  `creature_template` SET `AIName`='SmartAI'  WHERE `entry` IN (28210,28209);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28210,28209) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2821000,2820900) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28210,0,0,0,62,0,100,0,9667,0,0,0,80,2821000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ognip Blastbolt - On gosip select - Action list"),
(2821000,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ognip Blastbolt - Action list - Close gossip"),
(2821000,9,1,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ognip Blastbolt - Action list - Remov npc flag"),
(2821000,9,2,0,0,0,100,0,0,0,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ognip Blastbolt - Action list - Set stand state"),
(2821000,9,3,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ognip Blastbolt - Action list - Say text"),
(2821000,9,4,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,19,28209,0,0,0,0,0,0,"Ognip Blastbolt - Action list - Set data"),
(2821000,9,5,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ognip Blastbolt - Action list - Set run off"),
(2821000,9,6,0,0,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,847.1571, -187.3589, -49.754269, 2.065617,"Ognip Blastbolt - Action list - Say text"),
(2821000,9,7,0,0,0,100,0,4000,4000,0,0,112,81,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ognip Blastbolt - Action list - Start game event"),
(2821000,9,8,0,0,0,100,0,300000,300000,0,0,111,81,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ognip Blastbolt - Action list - Stop game event"),
(2821000,9,9,0,0,0,100,0,2000,2000,0,0,69,2,0,0,0,0,0,8,0,0,0,845.88, -182.203, -49.6705, 1.186820,"Ognip Blastbolt - Action list - move to pos"),
(2821000,9,10,0,0,0,100,0,2000,2000,0,0,45,1,2,0,0,0,0,19,28209,0,0,0,0,0,0,"Ognip Blastbolt - Action list - Set data"),
(2821000,9,11,0,0,0,100,0,5000,5000,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ognip Blastbolt - Action list - Add npc flag"),
(28210,0,1,0,34,0,100,0,8,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.065617,"Ognip Blastbolt - On movement informer - Set Orientation"),
(28210,0,2,0,34,0,100,0,8,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.186820,"Ognip Blastbolt - On movement informer - Set Orientation"),
(28210,0,3,0,34,0,100,0,8,2,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ognip Blastbolt - On movement informer - Set Orientation"),
(28209,0,0,0,34,0,100,0,8,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.065617,"Mizli Crankwheel - On movement informer - Set Orientation"),
(28209,0,1,0,34,0,100,0,8,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.101520,"Mizli Crankwheel - On movement informer - Set Orientation"),
(28209,0,2,0,34,0,100,0,8,2,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mizli Crankwheel - On movement informer - Set Orientation"),
(28209,0,3,0,38,0,100,0,1,2,0,0,69,2,0,0,0,0,0,8,0,0,0,849.4899, -179.317, -49.671, 4.101520,"Mizli Crankwheel - On data set - Move to pos"),
(28209,0,4,0,38,0,100,0,1,1,0,0,80,2820900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mizli Crankwheel - On Data set - Action list"),
(2820900,9,0,0,0,0,100,0,2000,2000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mizli Crankwheel - Action list - Set run off"),
(2820900,9,1,0,0,0,100,0,0,0,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mizli Crankwheel - Action list - Set stand state"),
(2820900,9,2,0,0,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,853.8105, -183.515, -49.7542, 2.117463,"Mizli Crankwheel - Action list - Move to pos");
