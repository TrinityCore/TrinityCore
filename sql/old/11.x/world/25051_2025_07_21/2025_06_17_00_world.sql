SET @CGUID := 6003595;

SET @NPCTEXTID := 560010;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 102478, 1220, 7502, 7581, '0', 6084, 0, 0, 1, -876.65802001953125, 4379.09033203125, 739.22369384765625, 0.680814743041992187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265); -- Emmarel Shadewarden (Area: Dalaran City - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=100786; -- Snowfeather
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=102478; -- Emmarel Shadewarden

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 100786;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(100786, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- 100786 (Snowfeather)

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=642, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100786 AND `DifficultyID`=0); -- 100786 (Snowfeather) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=488, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=102478 AND `DifficultyID`=0); -- 102478 (Emmarel Shadewarden) - CanSwim

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 100786;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(100786, 0, 0, 'Snowfeather swoops down and hovers expectantly. She has a message!', 41, 0, 100, 0, 0, 0, 103162, 0, 'Snowfeather to Player');

-- Equip Template
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=102478 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(102478, 1, 0, 0, 0, 0, 0, 0, 65972, 0, 0, 61265); -- Emmarel Shadewarden

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 6084;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(6084, 'Cosmetic - See Emmarel Shadewarden in Dalaran - The Hunters Reach');

DELETE FROM `phase_area` WHERE `PhaseId` = 6084;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7502, 6084, 'See Emmarel Shadewarden in Dalaran - The Hunters Reach');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5852 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 5852, 0, 0, 0, 47, 0, 44184, 2|8|64, 0, 0, 'Apply Phase 5852 if Quest 44184 is rewarded'),
(26, 5852, 0, 0, 0, 15, 0, 4, 0, 0, 0, 'Apply Phase 5852 if player is class Hunter');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=102478 AND `MenuID`=19115);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(102478, 19115, 61265); -- Emmarel Shadewarden

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 103161, 0, 0, 0, 0, 0, 0, 0, 61265); -- 102478 (Emmarel Shadewarden)

DELETE FROM `gossip_menu` WHERE (`MenuID`=19115 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(19115, @NPCTEXTID+0, 61265); -- 102478 (Emmarel Shadewarden)

-- Quest
DELETE FROM `quest_details` WHERE `ID`=40384;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(40384, 0, 0, 0, 0, 0, 0, 0, 0, 61265); -- Needs of the Hunters

DELETE FROM `quest_offer_reward` WHERE `ID`=40384;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(40384, 1, 0, 0, 0, 0, 0, 0, 0, 'Your reputation precedes you, $n.$b$bIt is important that we speak.', 61265); -- Needs of the Hunters

DELETE FROM `creature_queststarter` WHERE (`id`=100786 AND `quest`=40384);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(100786, 40384, 61265); -- Needs of the Hunters offered by Snowfeather

-- Snowfeather smart ai
SET @ENTRY := 100786;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 10078600, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Snowfeather #0 (10078600) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 40384, 0, 0, 0, 0, 80, 10078601, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Needs of the Hunters (40384) - Self: Start timed action list id #Snowfeather #1 (10078601) (update out of combat)', '');

-- Timed list 10078600 smart ai
SET @ENTRY := 10078600;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 29, 2, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Follow Owner/Summoner by distance 2, angle 0', '');

-- Timed list 10078601 smart ai
SET @ENTRY := 10078601;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 20, 0, 0, 'After 0 seconds - Self: Move forward by 0, left by 20, up by 0 yards', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Despawn instantly', '');
