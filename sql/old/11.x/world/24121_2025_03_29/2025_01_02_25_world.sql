-- Creature templates
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x4000800, `unit_flags3`=0x5000000, `VehicleId`=7262 WHERE `entry`=170715; -- Stormwind Gryphon

DELETE FROM `creature_template_addon` WHERE `entry` IN (170715);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(170715, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 170715 (Stormwind Gryphon)

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=57689 WHERE (`Idx`=1 AND `CreatureID` IN (66890,62167,66399,66398,66382)) OR (`Idx`=0 AND `CreatureID` IN (66890,66510,66299,66527,54617,66297,66434,66559,66889,66509,54618,54615,62167,66530,66399,66435,66398,66382,66397,65840)) OR (`Idx`=3 AND `CreatureID`=66398) OR (`Idx`=2 AND `CreatureID`=66398);

UPDATE `creature_model_info` SET `VerifiedBuild`=57689 WHERE `DisplayID` IN (96422, 23257, 45191, 44868, 45102, 44961, 44962, 46033, 46037, 46036, 46035, 46085, 17188, 44981, 25587, 28038, 38873);

-- Difficulties
UPDATE `creature_template_difficulty` SET `ContentTuningID`=864, `StaticFlags1`=0x30000000, `VerifiedBuild`=57689 WHERE (`Entry`=170715 AND `DifficultyID`=0); -- 170715 (Stormwind Gryphon) - CanSwim, Floating
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (170715) AND `DifficultyID`=1;

-- Gossips
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=25369 AND `OptionID`=1);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(25369, 54294, 1, 0, 'I need a flight to The Skyfire.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (14971,15111) AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (25369) AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,14971,0,0,0,47,0,29548,8,0,'',0,0,0,'','Show gossip option if quest 29548 is taken'),
(15,15111,0,0,0,47,0,29548,8,0,'',0,0,0,'','Show gossip option if quest 29548 is taken'),
(15,25369,1,0,0,47,0,29548,8,0,'',0,0,0,'','Show gossip option if quest 29548 is taken');

-- Quests
UPDATE `quest_poi` SET `VerifiedBuild`=57689 WHERE (`QuestID`=29548 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=29548 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29548 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29548 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=83492 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=76108 AND `BlobIndex`=2 AND `Idx1`=5) OR (`QuestID`=76108 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=76108 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=76108 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=76108 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=76108 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=32009 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=32009 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=32008 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=32008 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=82672 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=82672 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=82672 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=82672 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=82672 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=62567 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=46729 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=46729 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=46729 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=46729 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=46729 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=57689 WHERE (`QuestID`=29548 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29548 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29548 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29548 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=83492 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=76108 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=76108 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=76108 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=76108 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=76108 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=76108 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=32009 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=32009 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=32008 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=32008 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=82672 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=82672 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=82672 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=82672 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=82672 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=62567 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=46729 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=46729 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=46729 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=46729 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=46729 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=57689 WHERE `ID`=29548;

UPDATE `quest_request_items` SET `VerifiedBuild`=57689 WHERE `ID`=29548;

UPDATE `quest_offer_reward` SET `VerifiedBuild`=57689 WHERE `ID`=29548;

UPDATE `creature_queststarter` SET `VerifiedBuild`=57689 WHERE (`id`=55789 AND `quest`=29548);

UPDATE `creature_questender` SET `VerifiedBuild`=57689 WHERE (`id`=66292 AND `quest`=29548);

-- Spells
UPDATE `spell_target_position` SET `PositionX`=-671.29998779296875, `PositionY`=-1480.4300537109375, `PositionZ`=130.1999969482421875, `VerifiedBuild`=57689 WHERE (`ID`=130321 AND `EffectIndex`=0); -- Spell: 130321 (The Mission: Teleport Player) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_teleport_prep', 'spell_teleport_timer', 'spell_teleport_prep_horde', 'spell_teleport_timer_horde', 'spell_admiral_rogers_script_effect', 'spell_teleport_prep_alliance', 'spell_teleport_timer_alliance', 'spell_the_mission_scene_jf', 'spell_the_mission_scene_end');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(130810, 'spell_teleport_prep_horde'),
(132034, 'spell_teleport_timer_horde'),
(140885, 'spell_admiral_rogers_script_effect'),
(130832, 'spell_teleport_prep_alliance'),
(132032, 'spell_teleport_timer_alliance'),
(131057, 'spell_the_mission_scene_jf'),
(131059, 'spell_the_mission_scene_end');

-- Smart scripts
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (165505, 170715);

UPDATE `scene_template` SET `ScriptName`='SmartScene' WHERE `SceneId`=94;

DELETE FROM `areatrigger_scripts` WHERE `entry`=8514;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(8514, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=66292 AND `source_type`=0 AND `id` IN (1, 2, 3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=8514 AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=94 AND `source_type`=10;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66292,0,1,3,'',62,0,100,0,14971,0,0,0,0,'',134,140885,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Sky Admiral Rogers - On gossip option 0 selected - Invoker casts ''Admiral Rogers Script Effect'''),
(66292,0,2,3,'',62,0,100,0,15111,0,0,0,0,'',134,140885,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Sky Admiral Rogers - On gossip option 0 selected - Invoker casts ''Admiral Rogers Script Effect'''),
(66292,0,3,0,'',61,0,100,0,0,0,0,0,0,'',72,0,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Sky Admiral Rogers - Event linked - Close gossip'),

(8514,2,0,0,'',46,0,100,0,0,0,0,0,0,'',134,131057,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Areatrigger 8514 - On trigger - Invoker casts ''The Mission Scene - JF'''),

(94,10,0,0,'',81,0,100,0,0,0,0,0,0,'',134,131059,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Scene 94 - On scene complete - Invoker casts ''The Mission Scene End'''),
(94,10,1,0,'',80,0,100,0,0,0,0,0,0,'',134,131059,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Scene 94 - On scene cancel - Invoker casts ''The Mission Scene End''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=30 AND `SourceEntry`=8514;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(30,0,8514,0,0,47,0,29548,8,0,'',0,0,0,'','Areatrigger 8514 triggers if quest 29548 is taken');

DELETE FROM `smart_scripts` WHERE `entryorguid`=165505 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(165505,0,0,1,'',62,0,100,0,25369,1,0,0,0,'',134,332912,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Loretta Banks - On gossip option 1 selected - Invoker casts ''Summon Gryphon'''),
(165505,0,1,0,'',61,0,100,0,0,0,0,0,0,'',72,0,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Loretta Banks - Event linked - Close gossip');

SET @ENTRY := 170715;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `smart_scripts` WHERE `entryorguid`=170715 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(170715,0,0,0,'',54,0,100,0x200,0,0,0,0,0,'',11,333201,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Stormwind Gryphon - On summon - Cast ''Dust Cloud'''),
(170715,0,1,0,'',27,0,100,0x200,0,0,0,0,0,'',53,0,@PATH,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Stormwind Gryphon - On passenger boarded - Start scripted path'),
(170715,0,2,3,'',58,0,100,0x200,0xFFFFFFFF,@PATH,0,0,0,'',28,46598,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Stormwind Gryphon - On scripted path ended - Remove aura ''Ride Vehicle Hardcoded'''),
(170715,0,3,0,'',61,0,100,0x200,0,0,0,0,0,'',114,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,40,0,0,'Stormwind Gryphon - Event linked - Move forward 40 yards');

DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, 160, 'Stormwind Gryphon - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8450.799, 373.03647, 140.616, NULL, 0),
(@PATH, 1, -8487.316, 392.80728, 151.9025, NULL, 0),
(@PATH, 2, -8524.299, 439.342, 145.4894, NULL, 0),
(@PATH, 3, -8552.4375, 562.0816, 158.73732, NULL, 0),
(@PATH, 4, -8479.377, 762.59894, 177.70232, NULL, 0),
(@PATH, 5, -8344.817, 1010.0746, 224.7482, NULL, 0),
(@PATH, 6, -8119.9775, 1255.1216, 276.97183, NULL, 0),
(@PATH, 7, -7877.993, 1333.3298, 366.3707, NULL, 0),
(@PATH, 8, -7806.0767, 1247.5729, 364, NULL, 0),
(@PATH, 9, -7838.8506, 1210.7031, 364, NULL, 0),
(@PATH, 10, -7885.481, 1218.2448, 364, NULL, 0),
(@PATH, 11, -7883.363, 1261.1094, 364.3392, NULL, 0);

DELETE FROM `vehicle_template` WHERE `creatureId`=170715;
INSERT INTO `vehicle_template` (`creatureId`, `despawnDelayMs`) VALUES
(170715, 800);

-- Terrain swap
DELETE FROM `terrain_swap_defaults` WHERE `MapId`=870 AND `TerrainSwapMap`=971;
INSERT INTO `terrain_swap_defaults` (`MapId`, `TerrainSwapMap`, `Comment`) VALUES
(870, 971, 'The Jade Forest - Jade Forest Alliance Hub Phase');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=25 AND `SourceEntry`=971;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25,0,971,0,0,6,0,469,0,0,'',0,0,0,'','Apply terrain swap 971 if player is Alliance'),
(25,0,971,0,0,47,0,31736,64,0,'',1,0,0,'','Apply terrain swap 971 if quest 31736 is not rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=25 AND `SourceEntry`=1074;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25,0,1074,0,0,6,0,67,0,0,'',0,0,0,'','Apply terrain swap 1074 if player is Horde'),
(25,0,1074,0,0,-40002,0,0,0,0,'',0,0,0,'','Apply terrain swap 1074 if condition reference 40002 is fulfilled');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=25 AND `SourceEntry`=1066;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25,0,1066,0,0,6,0,469,0,0,'',0,0,0,'','Apply terrain swap 1066 if player is Alliance'),
(25,0,1066,0,0,47,0,29548,8,0,'',0,0,0,'','Apply terrain swap 1066 if quest 29548 is taken');
