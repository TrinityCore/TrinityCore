-- Phases
DELETE FROM `phase_name` WHERE `ID` IN (19125, 19823, 19168, 19825);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(19125, 'Toddy Whiskers in Stormwind Keep'),
(19168, 'Wrathion and Commanders in Stormwind Keep'),
(19823, 'Thaelin Darkanvil in Stormwind City Cemetery'),
(19825, 'Wrathion and Commanders in Stormwind Harbor');

DELETE FROM `phase_area` WHERE `AreaId`=6292 AND `PhaseId` IN (19125, 19168) OR `AreaId`=4411 AND `PhaseId` IN (19823, 19825);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(6292, 19125, 'Cosmetic phase for Toddy Whiskers in Stormwind Keep'),
(6292, 19168, 'Cosmetic phase for Wrathion and Commanders in Stormwind Keep'),
(4411, 19823, 'Cosmetic phase for Thaeilin Darkanvil in Stormwind Stormwind Harbor'),
(4411, 19825, 'Cosmetic phase for Wrathion and Commanders in Stormwind Harbor');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup` IN (19168, 19125, 19122, 19123);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 19168, 0, 0, 0, 27, 0, 10, 3, 0, 0, 0, 0, '', 'Apply phase 19168 if player level >= 10'),
(26, 19125, 0, 0, 0, 27, 0, 10, 3, 0, 0, 0, 0, '', 'Apply phase 19125 if player level >= 10'),
(26, 19122, 0, 0, 0, 27, 0, 10, 3, 0, 0, 0, 0, '', 'Apply phase 19122 if player level >= 10'),
(26, 19123, 0, 0, 0, 27, 0, 10, 3, 0, 0, 0, 0, '', 'Apply phase 19123 if player level >= 10');

-- The Dragon Isles Await (65436)
SET @CGUID := 50000000;

DELETE FROM `creature_queststarter` WHERE (`id`=189569 AND `quest`=65436);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(189569, 65436, 64978); -- The Dragon Isles Await offered by Wrathion

UPDATE `creature_questender` SET `VerifiedBuild`=64978 WHERE (`id`=189569 AND `quest`=65436);

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID`=451775;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES 
(451775, NULL, 1224573, 17844, 1, 1);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+1 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+1, 189569, 0, 1519, 6292, '0', '19168', 0, 0, 0, -8308.78125, 336.317718505859375, 155.429229736328125, 3.818917512893676757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Wrathion (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+2, 189600, 0, 1519, 6292, '0', '19168', 0, 0, 1, -8310.4794921875, 338.227447509765625, 155.4304962158203125, 4.177308559417724609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- High Exarch Turalyon (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+3, 189603, 0, 1519, 6292, '0', '19168', 0, 0, 0, -8308.2294921875, 333.90277099609375, 155.4304962158203125, 3.477343320846557617, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Scalecommander Azurathel (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+4, 189767, 0, 1519, 5346, '0', '19123', 0, 0, 0, -8402.4599609375, 1060.921875, 31.71354866027832031, 5.077036380767822265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Thaelin Darkanvil (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1
(@CGUID+5, 198383, 0, 1519, 5346, '0', '19123', 0, 0, 0, -8399.875, 1059.5555419921875, 31.71354866027832031, 2.991660833358764648, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Dracthyr Smith (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1 (Auras: 374209 - Channel: Hold Jewelry Box(Dragon) + TalkQuestion [DNT])
(@CGUID+6, 198383, 0, 1519, 5346, '0', '19123', 0, 0, 0, -8401.669921875, 1057.9600830078125, 31.71354866027832031, 1.865920424461364746, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978); -- Dracthyr Smith (Area: Stormwind City Cemetery - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+2 OR `guid`=@CGUID+4 OR `guid`=@CGUID+5 OR `guid`=@CGUID+6;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- High Exarch Turalyon
(@CGUID+4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Thaelin Darkanvil
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '374209'), -- Dracthyr Smith - 374209 - Channel: Hold Jewelry Box(Dragon) + TalkQuestion [DNT]
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''); -- Dracthyr Smith

DELETE FROM `creature_template_addon` WHERE `entry` IN (189600 /*189600 (High Exarch Turalyon)*/, 189767 /*189767 (Thaelin Darkanvil)*/, 198383 /*198383 (Dracthyr Smith)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(189600, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 189600 (High Exarch Turalyon)
(189767, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 189767 (Thaelin Darkanvil)
(198383, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '374209'); -- 198383 (Dracthyr Smith) - Channel: Hold Jewelry Box(Dragon) + TalkQuestion [DNT]

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=189603 AND `DifficultyID`=0); -- 189603 (Scalecommander Azurathel) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=189569 AND `DifficultyID`=0); -- 189569 (Wrathion) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=189602 AND `DifficultyID`=0); -- 189602 (Toddy Whiskers) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=189600 AND `DifficultyID`=0); -- 189600 (High Exarch Turalyon) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=189767 AND `DifficultyID`=0); -- 189767 (Thaelin Darkanvil) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry`=198383 AND `DifficultyID`=0); -- 198383 (Dracthyr Smith) - CanSwim

UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=198383; -- Dracthyr Smith
UPDATE `creature_template` SET `npcflag`=2, `unit_flags2`=0x800 WHERE `entry`=189602; -- Toddy Whiskers

UPDATE `creature_template_gossip` SET `VerifiedBuild`=64978 WHERE (`CreatureID`=189603 AND `MenuID`=30065) OR (`CreatureID`=189600 AND `MenuID`=28720);
UPDATE `gossip_menu` SET `VerifiedBuild`=64978 WHERE (`MenuID`=30065 AND `TextID`=590014) OR (`MenuID`=28720 AND `TextID`=590012);

DELETE FROM `creature_text` WHERE `CreatureID`=189569 AND `comment`='The Dragon Isles Awaits - Wrathion to Player';
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(189569, 0, 0, 'Ah, here is the hero I spoke of.', 12, 0, 100, 1, 0, 204308, 227404, 0, 'The Dragon Isles Awaits - Wrathion to Player'); -- BroadcastTextID: 224604 - 227404

DELETE FROM `conversation_line_template` WHERE `Id` IN (45416, 45415);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(45416, 1450, 1, 0, 0, 64978),
(45415, 1450, 1, 0, 0, 64978);

DELETE FROM `conversation_template` WHERE `Id`=17844;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(17844, 45415, 0, 64978);

 -- Wrathion smart ai
SET @ENTRY := 189569;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `id` IN (0, 1) AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 64, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player opened gossip - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 153, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player opened gossip - Gossip player: Complete Meet Wrathion in Stormwind objective (189569)', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 189569 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 189569, 0, 0, 9, 0, 65436, 0, 0, '', 0, 'Action invoker has quest The Dragon Isles Await (65436) active');

-- Item: Lost Dragonscale - Teleport position
DELETE FROM `spell_target_position` WHERE (`ID`=410137 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(410137, 0, 0, 0, -8330.240234375, 319.970001220703125, 155.350006103515625, 64978); -- Spell: 410137 (Lost Dragonscale) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)
