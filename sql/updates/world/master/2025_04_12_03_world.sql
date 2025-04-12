SET @NPCTEXTID := 530007;
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 1, 0, 0, 0, 0, 0, 0, 242822, 242815, 0, 0, 0, 0, 0, 0, 57564), -- 205890 (Zidormi)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 284310, 0, 0, 0, 0, 0, 0, 0, 60192); -- 240309 (Wyrmrest Defender)

DELETE FROM `broadcast_text` WHERE `VerifiedBuild`>0 AND `ID` IN (242815, 242822, 284310);
INSERT INTO `broadcast_text` (`Text`, `Text1`, `ID`, `LanguageID`, `ConditionID`, `EmotesID`, `Flags`, `ChatBubbleDurationMs`, `VoiceOverPriorityID`, `SoundKitID1`, `SoundKitID2`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `VerifiedBuild`) VALUES
('', 'This lair is a place of darkness and danger.\n\nDo you wish to battle the past incarnation of the broodmother, Onyxia.', 242815, 0, 0, 0, 0, 0, 4, 0, 0, 1, 0, 0, 0, 0, 0, 57564),
('', 'The present is a place of uncertainty and challenge, but also great opportunity.\n\nDo you wish to return?', 242822, 0, 0, 0, 0, 0, 4, 0, 0, 1, 0, 0, 0, 0, 0, 57564),
('I\'ve been ordered here to assist you. Which of the following gifts will the dragonflights bestow upon you?', 'I\'ve been ordered here to assist you. Which of the following gifts will the dragonflights bestow upon you?', 284310, 0, 0, 0, 256, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 60192);
