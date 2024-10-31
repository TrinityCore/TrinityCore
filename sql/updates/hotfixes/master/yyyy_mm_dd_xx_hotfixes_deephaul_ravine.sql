SET @TEXT_ID := 1000000;

DELETE FROM `broadcast_text` WHERE `ID` BETWEEN @TEXT_ID+0 AND @TEXT_ID+5;
INSERT INTO `broadcast_text` (`ID`, `Text`, `Text1`, `LanguageID`, `ConditionID`, `EmotesID`, `Flags`, `ChatBubbleDurationMs`, `VoiceOverPriorityID`, `SoundKitID1`, `SoundKitID2`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `VerifiedBuild`) VALUES
(@TEXT_ID+0, '$n has taken the crystal!', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1),
(@TEXT_ID+1, '$n has taken the crystal! The crystal can be captured outside an Earthen cart building!', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1),
(@TEXT_ID+2, 'The Alliance has taken control of a Mine Cart!', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1),
(@TEXT_ID+3, 'The Horde has taken control of a Mine Cart!', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1),
(@TEXT_ID+4, 'The Alliance has captured a Mine Cart!', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1),
(@TEXT_ID+5, 'The Horde has captured a Mine Cart!', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1);
