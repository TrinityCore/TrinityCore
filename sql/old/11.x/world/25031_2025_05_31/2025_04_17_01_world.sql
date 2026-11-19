-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=5667;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(5667, 12683, 0, 60257);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=5667 AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(5667, 59853, 7002088, 1, 0, 0, 0, 0, 60257), -- Full: 0x20426CCD607A74800050CB000000B17A Creature/0 R4251/S20683 Map: 1643 (Kul Tiras) Entry: 125394 (Constable Henry Framer) Low: 45434
(5667, 61576, 7002090, 0, 0, 0, 0, 0, 60257); -- Full: 0x20426CCD607A72400050CB000080B17A Creature/0 R4251/S20683 Map: 1643 (Kul Tiras) Entry: 125385 (Marshal Everit Reade) Low: 8434042

DELETE FROM `conversation_line_template` WHERE `Id` IN (12686, 12685, 12684, 12683);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(12686, 0, 1, 1, 0, 60257),
(12685, 0, 1, 0, 0, 60257),
(12684, 0, 0, 0, 1, 60257),
(12683, 0, 0, 0, 0, 60257);

-- Quest
DELETE FROM `quest_details` WHERE `ID`=48111;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48111, 1, 0, 0, 0, 0, 0, 0, 0, 60257); -- Trial by Superstition

DELETE FROM `creature_queststarter` WHERE (`id`=125380 AND `quest`=48111);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(125380, 48111, 60257); -- Trial by Superstition offered by Lucille Waycrest

DELETE FROM `creature_questender` WHERE (`id`=125380 AND `quest`=48111);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(125380, 48111, 60257); -- Trial by Superstition ended by Lucille Waycrest

-- Marshal Everit Reade smart ai
SET @ENTRY := 125385;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 20, 0, 100, 0, 48109, 0, 0, 0, 0, 143, 5667, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player rewarded quest The Woods Have Eyes (48109) - Rewarded player: Start conversation 5667', ''),
(@ENTRY, 0, 1, 0, 20, 0, 100, 0, 48110, 0, 0, 0, 0, 143, 5667, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player rewarded quest In Case of Ambush (48110) - Rewarded player: Start conversation 5667', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 125385 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 125385, 0, 0, 47, 0, 48110, 64, 0, '', 0, 'Action invoker has In Case of Ambush (48110) in state rewarded'),
(22, 2, 125385, 0, 0, 47, 0, 48109, 64, 0, '', 0, 'Action invoker has The Woods Have Eyes (48109) in state rewarded');
