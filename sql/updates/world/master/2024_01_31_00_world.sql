DELETE FROM `conversation_actors` WHERE (`ConversationId`=9679 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(9679, 0, 0, 130365, 86014, 0, 0, 27165);

DELETE FROM `conversation_line_template` WHERE `Id` IN (22138, 22246);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(22138, 607, 0, 0, 0, 27165),
(22246, 607, 0, 0, 0, 27165);

DELETE FROM `conversation_template` WHERE `Id`=9679;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(9679, 22138, 0, 27165);

DELETE FROM `quest_details` WHERE `ID`=50476;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(50476, 0, 0, 0, 0, 0, 0, 0, 0, 27165); -- The Warchief Awaits

DELETE FROM `creature_questender` WHERE `id`=134554 AND `quest`=50476;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(134554, 50476, 27178);

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=-1, `TypeFlags`=262144 WHERE (`Entry`=134554 AND `DifficultyID`=0); -- Lady Sylvanas Windrunner
UPDATE `creature_template_difficulty` SET `ContentTuningID`=288, `VerifiedBuild`=27178 WHERE (`DifficultyID`=0 AND `Entry` IN (134554,135003,144434)); -- Lady Sylvanas Windrunner

UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=134554;

DELETE FROM `quest_offer_reward` WHERE `ID`=50476;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(50476, 1, 0, 0, 0, 0, 0, 0, 0, 'Glad you could make it so quickly, $n.', 27178); -- The Warchief Awaits

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=134554 AND `MenuID`=22418);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(134554, 22418, 27178); -- Lady Sylvanas Windrunner

UPDATE `gossip_menu_option` SET `ActionMenuID`=22419, `VerifiedBuild`=27178 WHERE (`MenuID`=22418 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `ActionMenuID`=22420, `VerifiedBuild`=27178 WHERE (`MenuID`=22419 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `ActionMenuID`=23392, `VerifiedBuild`=27178 WHERE (`MenuID`=22420 AND `OptionID`=0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=22418 AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 22418, 0, 0, 0, 8, 0, 50476, 0, 0, '', 0, 0, 0, '', 'Gossip Option requires quest 50476 rewarded');

 -- The Warchief Awaits
SET @ENTRY := 50476;
DELETE FROM `quest_template_addon` WHERE `ID`=@ENTRY;
INSERT INTO `quest_template_addon` (`ID`, `ScriptName`) VALUES 
(@ENTRY, 'SmartQuest');

DELETE FROM `smart_scripts` WHERE `source_type` = 5 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 5, 0, 0, '', 47, 0, 100, 0, 0, 0, 0, 0, 143, 9679, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Start conversation conversation with first line id: 22138 (9679)');
