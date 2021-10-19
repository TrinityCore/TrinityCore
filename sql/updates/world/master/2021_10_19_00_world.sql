-- Add Conversation Stuff
DELETE FROM `conversation_actors` WHERE (`ConversationId`=6798 AND `Idx` IN (0,1));
INSERT INTO `conversation_actors`(`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `VerifiedBuild`) VALUES
(6798, 62451, 650011, 0, 0, 0, 40593),
(6798, 62619, 650035, 1, 0, 0, 40593);

DELETE FROM `conversation_line_template` WHERE `Id` IN (15509, 15508, 15507, 15506, 15505);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(15509, 33213, 0, 0, 0, 40593),
(15508, 28181, 0, 1, 0, 40593),
(15507, 15696, 0, 1, 0, 40593),
(15506, 8589, 0, 0, 0, 40593),
(15505, 0, 0, 0, 0, 40593);

DELETE FROM `conversation_template` WHERE `Id`=6798;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(6798, 15505, 43909, 0, 40593);

-- Update SAI in Template
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` = 131345;

-- SAI Conversation Script for Alleria GUID: 650011
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650011 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650011, 0, 0, 0, 19, 0, 100, 0, 49788, 0, 0, 0, 0, '', 143, 6798, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Alleria - On Quest accept 49788 - Start Conversation 6798 - To Invoker');
