--
SET @SPAWN_GROUP_ID := 376; -- 1

-- Jan'alai
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1112, `DamageModifier`=35, `GoldMin`=80000, `GoldMax`=100000, `StaticFlags1`=0x10080000, `VerifiedBuild`=68453 WHERE `Entry`=23578 AND `DifficultyID`=2;
UPDATE `creature` SET `guid`=89322 WHERE `guid`=339123 AND `id`=23578;

DELETE FROM `creature_text` WHERE `CreatureID` = 23578 AND `GroupID` IN (7,8);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23578,7,0,"Come, strangers. The spirit of da dragonhawk be hungry for worthy souls.",14,0,100,0,0,12039,23314,0,"janalai SAY_EVENT_1"),
(23578,7,1,"Come, friends. Your bodies gonna feed ma hatchlings, and your souls gonna fill me with power!",14,0,100,0,0,12040,23313,0,"janalai SAY_EVENT_2"),
(23578,8,0,"%s goes into a frenzy!",41,0,100,0,0,0,10645,0,"janalai EMOTE_FRENZY");

-- Amani Dragonhawk Hatchling
UPDATE `creature_template` SET `speed_walk` = 1, `ScriptName` = 'npc_amani_dragonhawk_hatchling' WHERE `entry` = 23598;
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1112, `StaticFlags1`=0x10080000, `VerifiedBuild`=68453 WHERE `Entry`=23598 AND `DifficultyID`=2; -- 23598 (Amani Dragonhawk Hatchling) - CanSwim

UPDATE `creature_model_info` SET `BoundingRadius` = 0.165, `CombatReach` = 0.82500005 WHERE `DisplayID` = 17546;

-- Dragonhawk Egg
UPDATE `creature_template` SET `ScriptName` = 'npc_dragonhawk_egg' WHERE `entry` = 23817;
UPDATE `creature_template_addon` SET `PvpFlags`=0 WHERE `entry` IN (24312,23817);

UPDATE `creature_model_info` SET `BoundingRadius`=0.167448967695236206, `CombatReach`=0.837244868278503417, `VerifiedBuild`=68453 WHERE `DisplayID`=37574;

DELETE FROM `creature` WHERE `id`=23817;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(89226, 23817, 568, 0, 0, '2', 0, 0, 0, -38.8813, 1084.2, 18.7948, 0.575959, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89227, 23817, 568, 0, 0, '2', 0, 0, 0, -40.7069, 1088.51, 18.7948, 0.017453, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89228, 23817, 568, 0, 0, '2', 0, 0, 0, -38.9577, 1207.25, 18.7947, 4.06662, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89300, 23817, 568, 0, 0, '2', 0, 0, 0, -38.2802, 1088.14, 18.7948, 1.27409, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
-- (89301, 23817, 568, 0, 0, '2', 0, 0, 0, -39.536, 1213.3, 18.7947, 5.58505, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89302, 23817, 568, 0, 0, '2', 0, 0, 0, -38.5764, 1218.68, 18.7947, 4.97419, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89314, 23817, 568, 0, 0, '2', 0, 0, 0, -42.8135, 1085.94, 18.7948, 2.04204, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
-- (89315, 23817, 568, 0, 0, '2', 0, 0, 0, -37.6035, 1085.87, 18.7948, 0.296706, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89316, 23817, 568, 0, 0, '2', 0, 0, 0, -36.2872, 1218.11, 18.7947, 0.034907, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89317, 23817, 568, 0, 0, '2', 0, 0, 0, -39.7272, 1216.09, 18.7947, 5.58505, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89319, 23817, 568, 0, 0, '2', 0, 0, 0, -39.7956, 1081.47, 18.7948, 2.74017, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89320, 23817, 568, 0, 0, '2', 0, 0, 0, -39.3636, 1209.73, 18.7947, 0.593412, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89321, 23817, 568, 0, 0, '2', 0, 0, 0, -37.3368, 1212.53, 18.7947, 0.314159, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89323, 23817, 568, 0, 0, '2', 0, 0, 0, -41.177, 1084.59, 18.7948, 1.06465, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89328, 23817, 568, 0, 0, '2', 0, 0, 0, -36.4398, 1209.93, 18.7947, 0.331613, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89332, 23817, 568, 0, 0, '2', 0, 0, 0, -40.0005, 1090.55, 18.7948, 1.11701, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89333, 23817, 568, 0, 0, '2', 0, 0, 0, -33.6638, 1087.02, 18.7948, 0.959931, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89334, 23817, 568, 0, 0, '2', 0, 0, 0, -36.2434, 1088.15, 18.7948, 1.72788, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89335, 23817, 568, 0, 0, '2', 0, 0, 0, -31.0391, 1088.33, 18.7948, 2.70526, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89336, 23817, 568, 0, 0, '2', 0, 0, 0, -35.0347, 1084.92, 18.7948, 5.21853, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89337, 23817, 568, 0, 0, '2', 0, 0, 0, -28.4201, 1082.09, 18.7948, 4.01426, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89338, 23817, 568, 0, 0, '2', 0, 0, 0, -30.5146, 1084.72, 18.7948, 1.79769, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89339, 23817, 568, 0, 0, '2', 0, 0, 0, -34.0568, 1082.02, 18.7947, 2.67035, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89340, 23817, 568, 0, 0, '2', 0, 0, 0, -31.6647, 1081.88, 18.7948, 6.17846, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89341, 23817, 568, 0, 0, '2', 0, 0, 0, -33.5926, 1090.16, 18.7948, 5.13127, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89342, 23817, 568, 0, 0, '2', 0, 0, 0, -29.1757, 1090.27, 18.7948, 0.680678, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0),
(89343, 23817, 568, 0, 0, '2', 0, 0, 0, -33.1212, 1209.77, 18.7947, 2.77507, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89344, 23817, 568, 0, 0, '2', 0, 0, 0, -28.0851, 1214.22, 18.7947, 3.38594, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89345, 23817, 568, 0, 0, '2', 0, 0, 0, -27.0043, 1211.99, 18.7947, 3.94444, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89346, 23817, 568, 0, 0, '2', 0, 0, 0, -29.8651, 1211.38, 18.7947, 2.94961, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89347, 23817, 568, 0, 0, '2', 0, 0, 0, -29.7244, 1208.43, 18.7947, 4.93928, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89348, 23817, 568, 0, 0, '2', 0, 0, 0, -34.0586, 1207.23, 18.7947, 4.60767, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89349, 23817, 568, 0, 0, '2', 0, 0, 0, -28.0705, 1216.81, 18.7947, 1.39626, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89350, 23817, 568, 0, 0, '2', 0, 0, 0, -30.4304, 1216.39, 18.7947, 4.90438, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
-- (89351, 23817, 568, 0, 0, '2', 0, 0, 0, -32.37, 1212.68, 18.7947, 1.0472, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89352, 23817, 568, 0, 0, '2', 0, 0, 0, -32.0784, 1218.55, 18.7947, 5.65487, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89353, 23817, 568, 0, 0, '2', 0, 0, 0, -34.4183, 1213.35, 18.7947, 2.26893, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89354, 23817, 568, 0, 0, '2', 0, 0, 0, -32.7619, 1215.33, 18.7947, 2.80998, 7200, 0, 0, 0, '', 'JanalaiEggsL', 0),
(89355, 23817, 568, 0, 0, '2', 0, 0, 0, -26.5745, 1084.44, 18.7948, 2.79253, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0);
-- (89356, 23817, 568, 0, 0, '2', 0, 0, 0, -27.2051, 1087.54, 18.7948, 1.76278, 7200, 0, 0, 0, '', 'JanalaiEggsR', 0);

DELETE FROM `spawn_group` WHERE `spawnId` IN (89226,89227,89228,89300,89301,89302,89314,89315,89316,89317,89319,89320,89321,89323,89328,89332,89333,89334,89335,89336,89337,89338,89339,89340,89341,89342,89343,89344,89345,89346,89347,89348,89349,89350,89351,89352,89353,89354,89355,89356) AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,89226),
(@SPAWN_GROUP_ID+0,0,89227),
(@SPAWN_GROUP_ID+0,0,89228),
(@SPAWN_GROUP_ID+0,0,89300),
-- (@SPAWN_GROUP_ID+0,0,89301),
(@SPAWN_GROUP_ID+0,0,89302),
(@SPAWN_GROUP_ID+0,0,89314),
-- (@SPAWN_GROUP_ID+0,0,89315),
(@SPAWN_GROUP_ID+0,0,89316),
(@SPAWN_GROUP_ID+0,0,89317),
(@SPAWN_GROUP_ID+0,0,89319),
(@SPAWN_GROUP_ID+0,0,89320),
(@SPAWN_GROUP_ID+0,0,89321),
(@SPAWN_GROUP_ID+0,0,89323),
(@SPAWN_GROUP_ID+0,0,89328),
(@SPAWN_GROUP_ID+0,0,89332),
(@SPAWN_GROUP_ID+0,0,89333),
(@SPAWN_GROUP_ID+0,0,89334),
(@SPAWN_GROUP_ID+0,0,89335),
(@SPAWN_GROUP_ID+0,0,89336),
(@SPAWN_GROUP_ID+0,0,89337),
(@SPAWN_GROUP_ID+0,0,89338),
(@SPAWN_GROUP_ID+0,0,89339),
(@SPAWN_GROUP_ID+0,0,89340),
(@SPAWN_GROUP_ID+0,0,89341),
(@SPAWN_GROUP_ID+0,0,89342),
(@SPAWN_GROUP_ID+0,0,89343),
(@SPAWN_GROUP_ID+0,0,89344),
(@SPAWN_GROUP_ID+0,0,89345),
(@SPAWN_GROUP_ID+0,0,89346),
(@SPAWN_GROUP_ID+0,0,89347),
(@SPAWN_GROUP_ID+0,0,89348),
(@SPAWN_GROUP_ID+0,0,89349),
(@SPAWN_GROUP_ID+0,0,89350),
-- (@SPAWN_GROUP_ID+0,0,89351),
(@SPAWN_GROUP_ID+0,0,89352),
(@SPAWN_GROUP_ID+0,0,89353),
(@SPAWN_GROUP_ID+0,0,89354),
(@SPAWN_GROUP_ID+0,0,89355);
-- (@SPAWN_GROUP_ID+0,0,89356);

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP_ID+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Zul'Aman - Dragonhawk Eggs",4);

-- Amani'shi Hatcher
UPDATE `creature_template` SET `speed_walk` = 1, `ScriptName` = 'npc_amanishi_hatcher' WHERE `entry` IN (23818,24504);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1112, `StaticFlags1`=0x10080000, `VerifiedBuild`=68453 WHERE `Entry` IN (23818,24504) AND `DifficultyID`=2;

UPDATE `creature` SET `guid` = 86476, `StringId` = 'AmanishiHatcherTrigger' WHERE `guid` = 339110 AND `id` = 22515;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (43962,45340);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,43962,0,0,58,0,0,0,0,"AmanishiHatcherTrigger",0,0,0,"","Group 0: Spell 'Summon Amani'shi Hatcher' (Effect 0) targets creature 'World Trigger'"),
(13,1,45340,0,0,58,0,0,0,0,"AmanishiHatcherTrigger",0,0,0,"","Group 0: Spell 'Summon Amani'shi Hatcher' (Effect 0) targets creature 'World Trigger'");

-- Fire Bomb (Zul'Aman)
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags2`=0x0, `ScriptName` = 'npc_fire_bomb_zulaman' WHERE `entry` = 23920;
UPDATE `creature_template_difficulty` SET `ContentTuningID`=261, `StaticFlags1`=0x20000100, `VerifiedBuild`=68453 WHERE `Entry`=23920 AND `DifficultyID`=0;

-- Misc
UPDATE `spell_target_position` SET `PositionX` = -34.6677, `PositionY` = 1149.56, `PositionZ` = 19.1438, `Orientation` = 3.14159, `VerifiedBuild` = 15595 WHERE `ID` = 43098;

UPDATE `creature` SET `guid`=86475 WHERE `guid`=339089 AND `id`=21252;
UPDATE `creature` SET `guid`=130814 WHERE `guid`=339071 AND `id`=21252;
UPDATE `creature` SET `guid`=86474 WHERE `guid`=339072 AND `id`=21252;
UPDATE `creature` SET `guid`=86477 WHERE `guid`=339065 AND `id`=21252;
UPDATE `creature` SET `guid`=86478 WHERE `guid`=339069 AND `id`=21252;

UPDATE `creature` SET `StringId` = 'JanalaiFireWallTrigger' WHERE `guid` IN (86474,86475,86477,86478) AND `id` = 21252;

UPDATE `creature` SET `StringId` = 'JanalaiEggsR' WHERE `guid` IN (89226,89227,89300,89314,89315,89319,89323,89332,89333,89334,89335,89336,89337,89338,89339,89340,89341,89342,89355,89356) AND `id` = 23817;

UPDATE `creature` SET `StringId` = 'JanalaiEggsL' WHERE `guid` IN (89228,89301,89302,89316,89317,89320,89321,89328,89343,89344,89345,89346,89347,89348,89349,89350,89351,89352,89353,89354) AND `id` = 23817;

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_janalai_summon_all_players',
'spell_janalai_fire_bomb',
'spell_janalai_hatch_eggs');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43096, 'spell_janalai_summon_all_players'),
(42621, 'spell_janalai_fire_bomb'),
(42471, 'spell_janalai_hatch_eggs');
