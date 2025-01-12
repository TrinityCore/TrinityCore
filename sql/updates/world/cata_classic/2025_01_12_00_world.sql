DELETE FROM `quest_details` WHERE `ID` IN (25041 /*Lion's Pride*/, 25043 /*Fields of Blood*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25041, 1, 15, 0, 0, 0, 0, 0, 0, 58158), -- Lion's Pride
(25043, 1, 274, 25, 0, 0, 0, 0, 0, 58158); -- Fields of Blood

UPDATE `quest_request_items` SET `CompletionText`='We need more of those monstrosities destroyed, $N.', `VerifiedBuild`=58158 WHERE `ID`=26792; -- Fungal Monstrosities
