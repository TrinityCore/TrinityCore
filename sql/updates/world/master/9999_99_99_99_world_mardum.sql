--
DELETE FROM `conversation_actors` WHERE `ConversationId`=705 AND `ConversationActorId`=50124;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(705, 50124, 0, 36839);

--
DELETE FROM `conversation_actor_template` WHERE `Id`=50124;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(50124, 98075, 21135, 36839);

--
DELETE FROM `conversation_template` WHERE `Id`=705;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(705, 1683, 13608, 0, 36839);

--
DELETE FROM `conversation_line_template` WHERE `Id` IN (1683,1684);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(1683,    0, 296, 0, 0, 36839),
(1684, 6896, 296, 0, 0, 36839);

-- Map:  1481 - Mardum
-- Zone: 7705 - Mardum, the Shattered Abyss
-- Area: 7705 - Mardum, the Shattered Abyss
SET @CGUID := 460000;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- PhaseGroup 372
(@CGUID+0, 99656, 1481, 7705, 7705, '0', 0, 372, 0, 0, 1178.32, 3218.36, 55.0906, 1.79942, 300,  0, 0,     5, 0, 0, 0, 0, 0, 36839), -- Red Broodling
(@CGUID+1, 94655, 1481, 7705, 7705, '0', 0, 372, 0, 0, 1173.61, 3289.81, 69.6789, 0.84459, 300,  0, 0,   647, 0, 0, 0, 0, 0, 36839), -- Soul Leech
(@CGUID+2, 94655, 1481, 7705, 7705, '0', 0, 372, 0, 0, 1115.17, 3280.68, 58.8887, 0.13126, 300, 10, 0,   647, 0, 1, 0, 0, 0, 36839), -- Soul Leech
(@CGUID+3, 94655, 1481, 7705, 7705, '0', 0, 372, 0, 0, 1112.23, 3214.00, 40.9979, 0.75865, 300, 10, 0,   647, 0, 1, 0, 0, 0, 36839), -- Soul Leech
(@CGUID+4, 65183, 1481, 7705, 7705, '0', 0, 372, 0, 0, 1180.05, 3306.37, 74.8179, 4.77173, 300,  0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- Spirit Healer
(@CGUID+5, 98191, 1481, 7705, 0, '0', 0, 372, 0, 0, 1472.08, 2596.69, 243.188, 4.58721, 300, 10, 0, 1779, 0, 1, 0, 0, 0, 36839), -- Legion Command Center
(@CGUID+6, 94744, 1481, 7705, 0, '0', 0, 372, 65203, 0, 1080.31, 3119.64, 26.8446, 0.64684, 300, 10, 0, 1779, 0, 1, 0, 0, 0, 36839), -- Dread Felbat
(@CGUID+7, 94744, 1481, 7705, 0, '0', 0, 372, 65203, 0, 1087.54, 3118.70, 25.8875, 0.60149, 300, 10, 0, 1779, 0, 1, 0, 0, 0, 36839), -- Dread Felbat
(@CGUID+8, 94744, 1481, 7705, 0, '0', 0, 372, 65203, 0, 1086.72, 3110.37, 26.8439, 0.64777, 300, 10, 0, 1779, 0, 1, 0, 0, 0, 36839), -- Dread Felbat
-- Phase 170
(@CGUID+9,  93011, 1481, 7705, 7705, '0', 170, 0, 0, 0, 1179.56, 3202.60, 51.3431, 4.87376, 300, 0, 0, 17790, 0, 0, 0, 0, 0, 36839), -- Kayn Sunfury
(@CGUID+10, 98227, 1481, 7705, 7705, '0', 170, 0, 0, 0, 1177.00, 3203.06, 51.3637, 4.88746, 300, 0, 0, 17790, 0, 0, 0, 0, 0, 36839), -- Allari the Souleater
(@CGUID+11, 98228, 1481, 7705, 7705, '0', 170, 0, 0, 0, 1182.35, 3202.91, 51.5215, 4.88566, 300, 0, 0, 19569, 0, 0, 0, 0, 0, 36839), -- Jace Darkweaver
(@CGUID+12, 98290, 1481, 7705, 7705, '0', 170, 0, 0, 0, 1171.48, 3203.68, 51.3145, 3.45639, 300, 0, 0, 17790, 0, 0, 0, 0, 0, 36839), -- Cyana Nightglaive
(@CGUID+13, 98292, 1481, 7705, 7705, '0', 170, 0, 0, 0, 1170.74, 3204.71, 51.5426, 3.36743, 300, 0, 0, 16901, 0, 0, 0, 0, 0, 36839), -- Kor'vas Bloodthorn
(@CGUID+14, 99918, 1481, 7705, 7705, '0', 170, 0, 0, 0, 1172.91, 3207.81, 52.3934, 3.73185, 300, 0, 0, 16011, 0, 0, 0, 0, 0, 36839); -- Sevis Brightflame

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Red Broodling
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soul Leech
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soul Leech
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soul Leech
(@CGUID+4, 0, 0, 65536, 1, 0, 0, 0, 0, '9036 9617 22011'), -- Spirit Healer - 9036 - Ghost, 9617 - Ghost Visual, 22011 - Spirit Heal Channel
(@CGUID+5, 0, 0, 50331648, 1, 0, 0, 0, 0, '217773'), -- Legion Command Center - 217773 - Legion Command Center: Engine Plume
(@CGUID+6, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Dread Felbat
(@CGUID+7, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Dread Felbat
(@CGUID+8, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Dread Felbat
(@CGUID+9, 0, 0, 0, 1, 333, 0, 0, 0, ''), -- Kayn Sunfury
(@CGUID+10, 0, 0, 0, 1, 375, 0, 0, 0, ''), -- Allari the Souleater
(@CGUID+11, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Jace Darkweaver
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Cyana Nightglaive
(@CGUID+13, 0, 0, 0, 1, 333, 0, 0, 0, ''), -- Kor'vas Bloodthorn
(@CGUID+14, 0, 0, 0, 1, 333, 0, 0, 0, ''); -- Sevis Brightflame

--
UPDATE `creature_model_info` SET `BoundingRadius`=1.70615, `VerifiedBuild`=36839 WHERE `DisplayID`=32803;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=60079;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=60791;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=61698;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=63986;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=64294;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=65202;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=65203;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=65204;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=65683;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=66159;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=66210;
UPDATE `creature_model_info` SET `VerifiedBuild`=36839 WHERE `DisplayID`=66396;

--
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=65183; -- Spirit Healer
UPDATE `creature_template` SET  `gossip_menu_id`=0, `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=93011; -- Kayn Sunfury
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=94655; -- Soul Leech
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_run`=3, `RangeAttackTime`=0, `MovementType`=2, `InhabitType`=4 WHERE `entry`=94744; -- Dread Felbat
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=99656; -- Red Broodling
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `MovementType`=2, `InhabitType`=4 WHERE `entry`=98191; -- Legion Command Center
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=98227; -- Allari the Souleater
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=98228; -- Jace Darkweaver
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=98290; -- Cyana Nightglaive
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=98292; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=99918; -- Sevis Brightflame

--
DELETE FROM `creature_template_addon` WHERE `entry` IN (65183 /*65183 (Spirit Healer) - Ghost, Ghost Visual, Spirit Heal Channel*/, 93011 /*93011 (Kayn Sunfury)*/, 94655 /*94655 (Soul Leech)*/, 94744 /*94744 (Dread Felbat)*/, 98191 /*98191 (Legion Command Center) - Legion Command Center: Engine Plume*/, 98227 /*98227 (Allari the Souleater)*/, 98228 /*98228 (Jace Darkweaver)*/, 98229 /*98229 (Kayn Sunfury)*/, 98290 /*98290 (Cyana Nightglaive)*/, 98292 /*98292 (Kor'vas Bloodthorn)*/, 99656 /*99656 (Red Broodling)*/, 99918 /*99918 (Sevis Brightflame)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(65183, 0, 0, 65536, 1, 0, 0, 0, 0, '9036 9617 22011'), -- 65183 (Spirit Healer) - Ghost, Ghost Visual, Spirit Heal Channel
(93011, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 93011 (Kayn Sunfury)
(94655, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 94655 (Soul Leech)
(94744, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 94744 (Dread Felbat)
(98227, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98227 (Allari the Souleater)
(98228, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 98228 (Jace Darkweaver)
(98229, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 98229 (Kayn Sunfury)
(98290, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98290 (Cyana Nightglaive)
(98292, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98292 (Kor'vas Bloodthorn)
(99656, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99656 (Red Broodling)
(99918, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 99918 (Sevis Brightflame)

--
DELETE FROM `creature_template_scaling` WHERE `Entry` IN (65183,93011,94655,94744,98191,98227,98228,98229,98290,98292,99656,99918) AND `DifficultyID`=0;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(65183, 0,  1, 60, 0, 0, 328, 36839), -- Spirit Healer
(93011, 0,  8, 45, 0, 0, 699, 36839), -- Kayn Sunfury
(94655, 0, 10, 45, 0, 0, 773, 36839), -- Soul Leech
(94744, 0,  8, 45, 0, 0, 699, 36839), -- Dread Felbat
(98191, 0,  8, 45, 0, 0, 699, 36839), -- Legion Command Center
(98227, 0,  8, 45, 0, 0, 699, 36839), -- Allari the Souleater
(98228, 0,  8, 45, 0, 0, 699, 36839), -- Jace Darkweaver
(98229, 0,  8, 45, 0, 0, 699, 36839), -- Kayn Sunfury
(98290, 0,  8, 45, 0, 0, 699, 36839), -- Cyana Nightglaive
(98292, 0,  8, 45, 0, 0, 699, 36839), -- Kor'vas Bloodthorn
(99656, 0,  1,  1, 0, 0,  81, 36839), -- Red Broodling
(99918, 0,  8, 45, 0, 0, 699, 36839); -- Sevis Brightflame

--
DELETE FROM `creature_equip_template` WHERE `ID`=1 AND `CreatureID` IN (93011,98227,98228,98229,98290,98292,99918);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(93011, 1, 128359, 0, 0, 128371, 0, 0, 0, 0, 0), -- Kayn Sunfury
(98227, 1, 122430, 0, 0,      0, 0, 0, 0, 0, 0), -- Allari the Souleater
(98228, 1, 128360, 0, 0, 128370, 0, 0, 0, 0, 0), -- Jace Darkweaver
(98229, 1, 128359, 0, 0, 128371, 0, 0, 0, 0, 0), -- Kayn Sunfury
(98290, 1, 128359, 0, 0, 128371, 0, 0, 0, 0, 0), -- Cyana Nightglaive
(98292, 1, 128359, 0, 0, 128371, 0, 0, 0, 0, 0), -- Kor'vas Bloodthorn
(99918, 1, 128361, 0, 0, 128369, 0, 0, 0, 0, 0); -- Sevis Brightflame

-- Kayn Sunfury
DELETE FROM `creature_queststarter` WHERE `id`=93011;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(93011, 40077); -- The Invasion Begins

--
DELETE FROM `graveyard_zone` WHERE `ID`=5082 AND `GhostZone`=7705;
INSERT INTO `graveyard_zone`(`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(5082, 7705, 0, '7.0 DH-Mardum - (01) Start - Mardum, the Shattered Abyss');

-- 7705 - Mardum, the Shattered Abyss
DELETE FROM `phase_area` WHERE `AreaId`=7705;
INSERT INTO `phase_area`(`AreaId`, `PhaseId`, `Comment`) VALUES 
(7705, 169, 'Mardum - Demon Hunters Start');

--
DELETE FROM `scene_template` WHERE `SceneId`=1106 AND `ScriptPackageID`=1487;
INSERT INTO `scene_template`(`SceneId`, `Flags`, `ScriptPackageID`, `ScriptName`) VALUES 
(1106, 20, 1487, ''); -- Mardum Start

--
DELETE FROM `spell_area` WHERE `spell` IN (2584,59073,59074,59087) AND `area`=7705;
INSERT INTO `spell_area`(`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(2584, 7705, 0, 0, 8326, 0, 2, 3,  0, 0),
(59073, 7705, 40077, 0, 0, 0, 2, 3,  1, 0), -- Phase 170
(59074, 7705, 40077, 0, 0, 0, 2, 3, 40, 0), -- Phase 171
(59087, 7705, 40077, 0, 0, 0, 2, 3, 66, 0); -- Phase 172

-- Scene 1106 SAI
UPDATE `scene_template` SET `ScriptName`="SmartScene" WHERE `SceneId`=1106;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1106 AND `source_type`=10;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1106,10,0,0,81,0,100,0,0,0,0,0,85,59073,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scene 1106 - Scene Complete - Invoker Cast 'Spell 59073' - Target: Invoker");

-- Pathing for Dread Felbat Entry: 94744 'TDB FORMAT'
SET @NPC :=@CGUID+6;
SET @PATH :=@NPC * 10;
UPDATE `creature` SET `spawndist`=0, `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH,  1, 1077.30, 3025.50,  6.78712, 0, 0, 1, 0, 100, 0),
(@PATH,  2, 1026.30, 3046.94,  8.17988, 0, 0, 1, 0, 100, 0),
(@PATH,  3, 982.477, 3064.01,  2.20963, 0, 0, 1, 0, 100, 0),
(@PATH,  4, 923.642, 3087.89, -26.1024, 0, 0, 1, 0, 100, 0),
(@PATH,  5, 898.475, 3107.68, -27.8867, 0, 0, 1, 0, 100, 0),
(@PATH,  6, 865.710, 3106.81, -29.1494, 0, 0, 1, 0, 100, 0),
(@PATH,  7, 833.244, 3077.80, -26.8813, 0, 0, 1, 0, 100, 0),
(@PATH,  8, 824.369, 3041.93, -22.6826, 0, 0, 1, 0, 100, 0),
(@PATH,  9, 862.635, 2987.65, -13.6702, 0, 0, 1, 0, 100, 0),
(@PATH, 10, 901.541, 2988.09, -4.26469, 0, 0, 1, 0, 100, 0),
(@PATH, 11, 1013.29, 3042.69,  12.3939, 0, 0, 1, 0, 100, 0),
(@PATH, 12, 1072.45, 3107.60,  23.7799, 0, 0, 1, 0, 100, 0),
(@PATH, 13, 1140.27, 3141.84,  31.0454, 0, 0, 1, 0, 100, 0),
(@PATH, 14, 1206.82, 3122.37,  31.0454, 0, 0, 1, 0, 100, 0),
(@PATH, 15, 1236.44, 3082.24,  26.2215, 0, 0, 1, 0, 100, 0),
(@PATH, 16, 1230.82, 3046.75,  19.2208, 0, 0, 1, 0, 100, 0),
(@PATH, 17, 1203.12, 3018.21,  12.4618, 0, 0, 1, 0, 100, 0),
(@PATH, 18, 1161.30, 3000.92,  6.45870, 0, 0, 1, 0, 100, 0),
(@PATH, 19, 1108.82, 3011.71,  2.66937, 0, 0, 1, 0, 100, 0);

--
DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+6;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+6,@CGUID+6, 0,  0,512,0,0),
(@CGUID+6,@CGUID+7,10, 90,512,0,0),
(@CGUID+6,@CGUID+8,10,270,512,0,0);

-- Pathing for Legion Command Center Entry: 98191 'TDB FORMAT'
SET @NPC :=@CGUID+5;
SET @PATH :=@NPC * 10;
UPDATE `creature` SET `spawndist`=0, `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH,  1, 1472.18, 2597.50, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH,  2, 1423.20, 2449.32, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH,  3, 1321.24, 2331.15, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH,  4, 1181.82, 2261.00, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH,  5, 1026.17, 2249.55, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH,  6, 877.985, 2298.53, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH,  7, 759.822, 2400.49, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH,  8, 689.673, 2539.91, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH,  9, 678.216, 2695.56, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH, 10, 727.196, 2843.75, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH, 11, 829.157, 2961.91, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH, 12, 968.576, 3032.06, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH, 13, 1124.22, 3043.51, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH, 14, 1272.41, 2994.53, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH, 15, 1390.57, 2892.57, 243.188, 0, 0, 1, 0, 100, 0),
(@PATH, 16, 1460.72, 2753.15, 243.188, 0, 0, 1, 0, 100, 0);
