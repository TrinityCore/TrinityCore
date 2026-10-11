SET @CGUID := 10006925;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 250839, 2552, 14771, 14771, '0', 27399, 0, 0, 1, 2659.1015625, -2615.791748046875, 224.5410003662109375, 5.009862899780273437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978); -- Silver Hand Squire (Area: Dornogal - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (250839);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(250839, 0, 81753, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 250839 (Silver Hand Squire)

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=281474976710658, `BaseAttackTime`=1000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=250839; -- Silver Hand Squire

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=250839 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(250839, 1, 141368, 0, 0, 0, 0, 0, 0, 0, 0, 64978); -- Silver Hand Squire

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 27399;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(27399, 'Cosmetic - See Silver Hand Squire in Dornogal');

DELETE FROM `phase_area` WHERE `PhaseId` = 27399;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14771, 27399, 'See Silver Hand Squire in Dornogal');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 27399 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 27399, 0, 0, 0, 47, 0, 92405, 2|8|64, 0, 1, 'Apply Phase 27399 if Quest 92405 is not taken|complete|rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=27487;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(27487, 75363, 0, 64978);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=27487 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(27487, 102972, 0, 231039, 130420, 0, 0, 64978);

DELETE FROM `conversation_line_template` WHERE `Id` IN (75365, 75363);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(75365, 119, 0, 0, 0, 64978),
(75363, 119, 0, 0, 0, 64978);

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (250839));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(250839, 0, 10, 1, 1, 330442, 0x0, 32768, 0); -- Silver Hand Squire

UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=250839 AND `DifficultyID`=0); -- 250839 (Silver Hand Squire) - CanSwim

-- Model
DELETE FROM `creature_template_model` WHERE (`CreatureID`=231039 AND `Idx`=0) OR (`CreatureID`=250839 AND `Idx` IN (3,2,1,0));
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(231039, 0, 130420, 1, 1, 64978), -- Arator
(250839, 3, 140022, 1, 1, 64978), -- Silver Hand Squire
(250839, 2, 140020, 1, 1, 64978), -- Silver Hand Squire
(250839, 1, 140021, 1, 1, 64978), -- Silver Hand Squire
(250839, 0, 140019, 1, 1, 64978); -- Silver Hand Squire

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (116386, 140021, 137558, 137559, 114737, 140022, 125826, 137621, 131998);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(116386, 0.49456837773323059, 1.5, 0, 64978),
(140021, 0.305999994277954101, 1.5, 0, 64978),
(137558, 0.372000008821487426, 1.5, 0, 64978),
(137559, 0.372000008821487426, 1.5, 0, 64978),
(114737, 1.581808328628540039, 1.5, 0, 64978),
(140022, 0.208000004291534423, 1.5, 0, 64978),
(125826, 0.305999994277954101, 1.5, 0, 64978),
(137621, 0.305999994277954101, 1.5, 0, 64978),
(131998, 1.176657438278198242, 0, 0, 64978);

-- Quest
UPDATE `quest_poi_points` SET `VerifiedBuild`=64978 WHERE (`QuestID`=90719 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50605 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50601 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50600 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=43179 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42170 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=42170 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=91138 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=91138 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=86456 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=86456 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=86456 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=86456 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=85079 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=85079 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=85079 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=85079 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=85079 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=85079 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=85079 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=85079 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=85079 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=85079 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=85079 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=85079 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=85079 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=85079 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=85078 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=85078 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=85078 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=85078 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=85078 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=85078 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=85078 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=64012 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=53436 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=53436 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID`=92405;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(92405, 2, 25, 0, 0, 0, 0, 0, 0, 64978); -- Meet Arator

DELETE FROM `quest_description_conditional` WHERE (`QuestId`=93057 AND `PlayerConditionId`=923 AND `QuestgiverCreatureId`=0 AND `locale`='enUS');
INSERT INTO `quest_description_conditional` (`QuestId`, `PlayerConditionId`, `QuestgiverCreatureId`, `locale`, `Text`, `OrderIndex`, `VerifiedBuild`) VALUES
(93057, 923, 0, 'enUS', '<A glowing parchment appears in front of you with the symbol of a home in front of it.>\n\nGreetings, $n!\n\nHave you ever wanted to own a home? Have a place to call your own? Now you can!\n\nJoin us in Razorwind Shores, the new Housing Neighborhood. Get your very own slice of Azeroth!', 0, 64978); -- A House For You

UPDATE `quest_description_conditional` SET `VerifiedBuild`=64978 WHERE (`QuestId`=91138 AND `PlayerConditionId`=140702 AND `QuestgiverCreatureId`=245915 AND `locale`='enUS');

DELETE FROM `creature_queststarter` WHERE (`id`=250839 AND `quest`=92405);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(250839, 92405, 64978); -- Meet Arator offered by Silver Hand Squire

-- Silver Hand Squire smart ai
SET @ENTRY := 250839;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 19, 0, 100, 0, 92405, 0, 0, 0, 0, 80, 25083900, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Meet Arator (92405) - Self: Start timed action list id #Silver Hand Squire #0 (25083900) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 143, 27487, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Meet Arator (92405) - Player who accepted quest: Start conversation (27487) Actors<Arator (102972)> (first line 75363)', ''),
(@ENTRY, 0, 2, 0, 58, 0, 100, 0, 5, 25083900, 0, 0, 0, 53, 0, 25083901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 25083900 ended - Self: Start path #25083901, walk, do not repeat, Passive', ''),
(@ENTRY, 0, 3, 0, 40, 0, 100, 0, 4, 25083901, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On wapoint 4 of path 25083901 reached - Self: Despawn in 1 s', '');

-- Timed list 25083900 smart ai
SET @ENTRY := 25083900;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 53, 0, 25083900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Start path #25083900, walk, do not repeat, Passive', '');

-- Path for Silver Hand Squire
SET @ENTRY := 250839;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Silver Hand Squire - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2660.8364, -2618.6830, 224.63777, NULL, 0),
(@PATH, 1, 2660.3364, -2621.1830, 224.63777, NULL, 0),
(@PATH, 2, 2656.3364, -2624.4330, 224.63777, NULL, 0),
(@PATH, 3, 2653.3364, -2624.9330, 224.63777, NULL, 0),
(@PATH, 4, 2649.5864, -2620.6830, 224.63777, NULL, 0),
(@PATH, 5, 2643.0713, -2613.5747, 219.65121, NULL, 0);

-- Path for Silver Hand Squire
SET @ENTRY := 250839;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Silver Hand Squire - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2640.6206, -2607.3647, 219.90115, NULL, 0),
(@PATH, 1, 2638.6206, -2597.3647, 219.90115, NULL, 0),
(@PATH, 2, 2637.6206, -2587.6147, 219.90115, NULL, 0),
(@PATH, 3, 2636.6206, -2576.6147, 219.90115, NULL, 0),
(@PATH, 4, 2634.3706, -2559.6147, 219.90115, NULL, 0),
(@PATH, 5, 2632.3706, -2544.8647, 219.90115, NULL, 0),
(@PATH, 6, 2630.1702, -2531.1545, 219.65115, NULL, 0);
