-- 
DELETE FROM `quest_request_items` WHERE `ID` IN (11284, 13839);
INSERT INTO `quest_request_items` (`ID`, `CompletionText`, `VerifiedBuild`) VALUES
(11284, "Have you had any luck removing that stupid yeti from my mine? ", 0),
(13839, "Have you mastered the use of the charge?", 0);
