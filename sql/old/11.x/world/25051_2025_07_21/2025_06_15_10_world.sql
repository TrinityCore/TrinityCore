SET @CGUID := 6003594;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 102700, 1220, 7502, 7581, '0', 5852, 0, 0, 1, -843.19964599609375, 4431.20068359375, 742.6202392578125, 4.81061410903930664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265); -- Meryl Felstorm (Area: Dalaran City - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 9858, 0, 0, 0, ''); -- Meryl Felstorm

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (5852,5853);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(5852, 'Cosmetic - See Meryl Felstorm in the Violet Gate'),
(5853, 'Cosmetic - See Meryl Felstorm at the Violet Hold');

DELETE FROM `phase_area` WHERE `PhaseId` = 5852;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7502, 5852, 'See Meryl Felstorm in the Violet Gate');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5852 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 5852, 0, 0, 0, 47, 0, 41035, 2|8|64, 0, 0, 'Apply Phase 5852 if Quest 41035 is in progress | complete | rewarded'),
(26, 5852, 0, 0, 0, 47, 0, 41036, 2|8|64, 0, 1, 'Apply Phase 5852 if Quest 41036 is not in progress | complete | rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=1263;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(1263, 2981, 0, 61265);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=1263 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(1263, 51396, 0, 102850, 67760, 0, 0, 61265);

DELETE FROM `conversation_line_template` WHERE `Id`=2981;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(2981, 130, 0, 0, 0, 61265);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=102700 AND `MenuID`=19321);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(102700, 19321, 61265); -- Meryl Felstorm

UPDATE `gossip_menu` SET `VerifiedBuild`=61265 WHERE (`MenuID`=19321 AND `TextID`=28451) OR (`MenuID`=19322 AND `TextID`=28454) OR (`MenuID`=19323 AND `TextID`=28455);

UPDATE `gossip_menu_option` SET `GossipOptionID`=45568, `OptionBroadcastTextID`=106049, `VerifiedBuild`=61265 WHERE (`MenuID`=19321 AND `OptionID`=2); -- OptionBroadcastTextID: 106049 - 128607
UPDATE `gossip_menu_option` SET `GossipOptionID`=45567, `VerifiedBuild`=61265 WHERE (`MenuID`=19321 AND `OptionID`=1);

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (41036 /*The Dreadlord's Prize*/, 41035 /*Felstorm's Plea*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(41036, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- The Dreadlord's Prize
(41035, 0, 0, 0, 0, 0, 0, 0, 0, 61265); -- Felstorm's Plea

DELETE FROM `creature_queststarter` WHERE (`id`=102700 AND `quest`=41036);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(102700, 41036, 61265); -- The Dreadlord's Prize offered by Meryl Felstorm

DELETE FROM `quest_template_addon` WHERE `ID` IN (41035,41036);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(41035, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Felstorm's Plea
(41036, 0, 0, 0, 41035, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- The Dreadlord's Prize

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=627 AND `QuestLineId` IN (5638,314,237));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(627, 5638, 61265),
(627, 314, 61265),
(627, 237, 61265);

-- Felstorm's Plea
SET @ENTRY := 41035;
UPDATE `quest_template_addon` SET `ScriptName` = 'SmartQuest' WHERE `ID` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 5 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 143, 1263, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Start conversation 1263', '');
