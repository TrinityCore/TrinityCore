-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=27025;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(27025, 73843, 0, 63003);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=27025 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(27025, 102240, 10006837, 0, 0, 0, 0, 0, 63003); -- Full: 0x204258CD60E27BC000003400003A95CF Creature/0 R4246/S52 Map: 1643 (Kul Tiras) Entry: 231919 (Botanist Alaenra) Low: 3839439

DELETE FROM `conversation_line_template` WHERE `Id` IN (75661, 73843);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(75661, 0, 0, 0, 0, 63003),
(73843, 0, 0, 0, 0, 63003);

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (85076 /*Don't Bee Crazy*/, 85077 /*Sticky Fingers*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(85076, 1, 0, 0, 0, 0, 0, 0, 0, 63003), -- Don't Bee Crazy
(85077, 1, 0, 0, 0, 0, 0, 0, 0, 63003); -- Sticky Fingers

DELETE FROM `quest_request_items` WHERE `ID` IN (85077 /*Sticky Fingers*/, 85076 /*Don't Bee Crazy*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(85077, 0, 6, 0, 0, 'Did you get the honey?', 0), -- Sticky Fingers
(85076, 0, 274, 0, 0, 'The poor bees...', 63003); -- Don't Bee Crazy

DELETE FROM `creature_queststarter` WHERE (`id`=231919 AND `quest` IN (85076,85077));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(231919, 85076, 63003), -- Don't Bee Crazy offered by Botanist Alaenra
(231919, 85077, 63003); -- Sticky Fingers offered by Botanist Alaenra

DELETE FROM `creature_questender` WHERE (`id`=231919 AND `quest` IN (85076,85077));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(231919, 85076, 63003), -- Don't Bee Crazy ended by Botanist Alaenra
(231919, 85077, 63003); -- Sticky Fingers ended by Botanist Alaenra

 -- Botanist Alaenra smart ai
SET @ENTRY := 231919;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 85076, 0, 0, 0, 0, 143, 27025, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Don\'t Bee Crazy (85076) - Player who accepted quest: Start conversation 27025', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 85077, 0, 0, 0, 0, 143, 27025, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Sticky Fingers (85077) - Player who accepted quest: Start conversation 27025', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 231919 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 231919, 0, 0, 47, 0, 85077, 74, 0, '', 0, 'Action invoker has Sticky Fingers (85077) in state complete, incomplete, rewarded'),
(22, 2, 231919, 0, 0, 47, 0, 85076, 74, 0, '', 0, 'Action invoker has Don\'t Bee Crazy (85076) in state complete, incomplete, rewarded');
