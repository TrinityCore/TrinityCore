SET @CGUID := 11000000;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 246156, 0, 1519, 5390, '0', 27073, 0, 0, 1, -8690.58203125, 474.2257080078125, 95.44113922119140625, 2.275526762008666992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65655); -- Magister Umbric (Area: The Canals - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Magister Umbric

-- Template
UPDATE `creature_template` SET `faction`=1732, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x140, `unit_flags2`=0x800 WHERE `entry`=246156; -- Magister Umbric

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=30072;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(30072, 83103, 0, 65655);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=30072 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(30072, 108744, 0, 237506, 128688, 0, 0, 65655);

DELETE FROM `conversation_line_template` WHERE `Id` IN (83102, 83103);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(83102, 1209, 0, 0, 0, 65655),
(83103, 1209, 0, 0, 0, 65655);

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 27073;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(27073, 'Cosmetic - See Magister Umbric at The Old Town in Stormwind');

DELETE FROM `phase_area` WHERE `PhaseId` = 27073;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 27073, 'See Magister Umbric at The Old Town in Stormwind');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 246156;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(246156, 0, 0, 'Over here, $p. The rumors I mentioned began in this part of the city.', 12, 0, 100, 1, 0, 300619, 296405, 5, 'Magister Umbric to Player');

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (246156));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(246156, 1, 126782, 0, 0, 0, 0, 0, 0, 0, 0, 65655); -- Magister Umbric

-- Quest
DELETE FROM `quest_offer_reward` WHERE `ID`=90759;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(90759, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you for coming, $p. The Twilight\'s Blade cannot be allowed to roam our cities.', 65655); -- The Cult Within

DELETE FROM `quest_details` WHERE `ID`=90759;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(90759, 1, 0, 0, 0, 0, 0, 0, 0, 65655); -- The Cult Within

DELETE FROM `creature_queststarter` WHERE (`id`=246156 AND `quest`=90759);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(246156, 90759, 65655); -- The Cult Within offered by Magister Umbric

DELETE FROM `creature_questender` WHERE (`id`=246156 AND `quest`=90759);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(246156, 90759, 65655); -- The Cult Within ended by Magister Umbric

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3313, `StaticFlags1`=0x10000000, `VerifiedBuild`=65655 WHERE (`Entry`=246156 AND `DifficultyID`=0); -- 246156 (Magister Umbric) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (128688, 129519, 140382, 140378, 129516, 140376);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(128688, 0.399305284023284912, 1.724999904632568359, 0, 65655),
(129519, 0.208000004291534423, 1.5, 0, 65655),
(140382, 1, 1.5, 0, 65655),
(140378, 0.305999994277954101, 1.5, 0, 65655),
(129516, 0.305999994277954101, 1.5, 0, 65655),
(140376, 0.347222000360488891, 1.5, 0, 65655);

-- The Cult Within
SET @ENTRY := 90759;
INSERT IGNORE INTO `quest_template_addon` (`ID`) VALUES (@ENTRY);
UPDATE `quest_template_addon` SET `ScriptName` = 'SmartQuest' WHERE `ID` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 5 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 143, 30072, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Start conversation 30072', '');
