SET @CGUID := 9004555;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 189569, 0, 1519, 6292, '0', 19168, 0, 0, 0, -8308.78125, 336.317718505859375, 155.429229736328125, 3.818917512893676757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65299), -- Wrathion (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+1, 189603, 0, 1519, 6292, '0', 19258, 0, 0, 0, -8308.2294921875, 333.90277099609375, 155.4304962158203125, 3.477343320846557617, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65299); -- Scalecommander Azurathel (Area: Stormwind Keep - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `npcflag`=2, `unit_flags2`=0x800 WHERE `entry`=189602; -- Toddy Whiskers

-- Phases
DELETE FROM `phase_name` WHERE `ID` IN (19168,19258,24300);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(19168, 'Cosmetic - See Wrathion in Stormwind Keep'),
(19258, 'Cosmetic - See Scalecommander Azurathel in Stormwind Keep'),
(24300, 'Cosmetic - See Portal to near Stormwind Harbor in Stormwind Keep');

DELETE FROM `phase_area` WHERE `PhaseId` IN (19168,19258);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(1519, 19168, 'See Wrathion in Stormwind Keep'),
(1519, 19258, 'See Scalecommander Azurathel in Stormwind Keep');

-- Correct condition for Toddy
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 19125;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 19125, 1519, 0, 0, 47, 0, 66589, 74, 0, '', 1, 0, 0, '', 'Apply Phase 19125 If Quest 66589 is not In Progress | complete | rewarded');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=189569 AND `quest`=65436);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(189569, 65436, 64978); -- The Dragon Isles Await offered by Wrathion

UPDATE `creature_questender` SET `VerifiedBuild`=64978 WHERE (`id`=189569 AND `quest`=65436);

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=65299 WHERE (`Entry`=189602 AND `DifficultyID`=0); -- 189602 (Toddy Whiskers) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=65299 WHERE (`Entry`=189603 AND `DifficultyID`=0); -- 189603 (Scalecommander Azurathel) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=65299 WHERE (`Entry`=189569 AND `DifficultyID`=0); -- 189569 (Wrathion) - CanSwim

-- Gossip
UPDATE `creature_template_gossip` SET `VerifiedBuild`=64978 WHERE (`CreatureID`=189603 AND `MenuID`=30065) OR (`CreatureID`=189600 AND `MenuID`=28720);
UPDATE `gossip_menu` SET `VerifiedBuild`=64978 WHERE (`MenuID`=30065 AND `TextID`=590014) OR (`MenuID`=28720 AND `TextID`=590012);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID`=189569 AND `comment`='The Dragon Isles Awaits - Wrathion to Player';
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(189569, 0, 0, 'Ah, here is the hero I spoke of.', 12, 0, 100, 1, 0, 204308, 227404, 5, 'The Dragon Isles Awaits - Wrathion to Player'); -- BroadcastTextID: 224604 - 227404

-- Conversation
DELETE FROM `conversation_actors` WHERE (`ConversationId`=17844 AND `Idx`=1);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(17844, 64220, 1, 184650, 107146, 0, 0, 65299);

DELETE FROM `conversation_line_template` WHERE `Id` IN (45416, 45415);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(45416, 1450, 1, 0, 0, 64978),
(45415, 1450, 1, 0, 0, 64978);

DELETE FROM `conversation_template` WHERE `Id`=17844;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(17844, 45415, 0, 64978);

-- Item: Lost Dragonscale - Teleport position
DELETE FROM `spell_target_position` WHERE (`ID`=410137 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(410137, 0, 0, 0, -8330.240234375, 319.970001220703125, 155.350006103515625, 64978); -- Spell: 410137 (Lost Dragonscale) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)

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

-- The Dragon Isles Await
SET @ENTRY := 65436;
INSERT IGNORE INTO `quest_template_addon` (`ID`) VALUES (@ENTRY);
UPDATE `quest_template_addon` SET `ScriptName` = 'SmartQuest' WHERE `ID` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 5 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 143, 17844, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Start conversation 17844', '');
