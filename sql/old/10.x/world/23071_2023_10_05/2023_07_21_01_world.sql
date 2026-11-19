-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=20387;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(20387, 52596, 0, 50000);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=20387 AND `Idx` IN (1,2,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(20387, 89180, 1, 0, 0, 0, 0, 50000), -- Full: 0x202FD40000C238C0000097000026109E Creature/0 R3061/S151 Map: 0 (Eastern Kingdoms) Entry: 198883 (Vanessa VanCleef) Low: 2494622
(20387, 89175, 2, 0, 0, 0, 0, 50000), -- Full: 0x202FD40000C23C00000097000024C74A Creature/0 R3061/S151 Map: 0 (Eastern Kingdoms) Entry: 198896 (Master Mathias Shaw) Low: 2410314
(20387, 0, 0, 0, 0, 0, 1, 50000); -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775

DELETE FROM `conversation_line_template` WHERE `Id` IN (52595, 52594, 52593, 52596);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(52595, 0, 1, 0, 0, 50000),
(52594, 0, 2, 0, 0, 50000),
(52593, 0, 1, 0, 0, 50000),
(52596, 0, 0, 0, 0, 50000);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_the_new_classington_estate' WHERE `ID` = 20387;

UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = 198883;

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=72426;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(72426, 1, 1, 0, 0, 0, 0, 0, 0, 50000); -- The New Clessington Estate

DELETE FROM `creature_queststarter` WHERE (`id`=198896 AND `quest`=72426);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(198896, 72426, 50000); -- The New Clessington Estate offered Master Mathias Shaw

DELETE FROM `creature_questender` WHERE (`id`=198896 AND `quest`=72424);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(198896, 72424, 50000); -- Looking for Something Specific ended Master Mathias Shaw

DELETE FROM `quest_template_addon` WHERE `ID` = 72426;
INSERT INTO `quest_template_addon` (`ID`, `prevQuestID`) VALUES
(72426, 72424);

-- Update Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 19934 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 19934, 0, 0, 0, 47, 0, 72405, 2 | 64, 0, 0, 'Apply Phase 19933 if Quest 75265 is complete | rewarded'),
(26, 19934, 0, 0, 0, 47, 0, 72426, 2 | 8 | 64, 0, 1, 'Apply Phase 19933 if Quest 72426 is not in progress | complete | rewarded');

-- Waypoints for 198883 (Vanessa VanCleef)
SET @ENTRY := 198883;
SET @PATH := ((@ENTRY) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -9464.7, -8.180555, 50.05011, NULL, 0),
(@PATH, 1, -9462.712, -11.04861, 50.21397, NULL, 0),
(@PATH, 2, -9460.957, -10.8125, 50.16755, NULL, 0),
(@PATH, 3, -9460.654, -9.055555, 50.22908, NULL, 0);
