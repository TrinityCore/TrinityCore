-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=20345;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(20345, 56092, 0, 49801);

DELETE FROM `conversation_line_template` WHERE `Id` IN (52475, 53706, 53705, 53704, 56092);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(52475, 0, 1, 0, 49801),
(53706, 0, 2, 0, 49801),
(53705, 0, 2, 0, 49801),
(53704, 0, 1, 0, 49801),
(56092, 0, 0, 0, 49801);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=20345 AND `Idx` IN (1,2,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(20345, 89175, 9003909, 1, 0, 0, 0, 0, 49801), -- Full: 0x202FD40000C23C0000007C0000791B26 Creature/0 R3061/S124 Map: 0 (Eastern Kingdoms) Entry: 198896 (Master Mathias Shaw) Low: 7936806
(20345, 89180, 9003910, 2, 0, 0, 0, 0, 49801), -- Full: 0x202FD40000C238C000007C000076C164 Creature/0 R3061/S124 Map: 0 (Eastern Kingdoms) Entry: 198883 (Vanessa VanCleef) Low: 7782756
(20345, 0, 0, 0, 0, 0, 0, 1, 49801); -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775

 -- Vanessa VanCleef smart ai
SET @ENTRY := 198883;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 72409, 0, 0, 0, 143, 20345, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Rotten Old Memories (72409) - Player who accepted quest: Start conversation 20345');

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 30837 AND `SourceEntry` IN (0,1,2));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(15, 30837, 0, 0, 0, 8, 0, 72408, 0, 0, 0, 'Show Gossip Option Menu 30837 0 if Quest 72405 is rewarded'),
(15, 30837, 1, 0, 0, 8, 0, 72408, 0, 0, 0, 'Show Gossip Option Menu 30837 1 if Quest 72405 is rewarded'),
(15, 30837, 2, 0, 0, 8, 0, 72408, 0, 0, 0, 'Show Gossip Option Menu 30837 2 if Quest 72405 is rewarded');
