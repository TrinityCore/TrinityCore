--
DELETE FROM `quest_request_items` WHERE `ID` = 14488;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(14488, 1, 0, "I don't remember ordering a cleaning service... why yes, I am Apothecary Hummel.$B$B...wait, what is the meaning of this? You think these meaningless papers can stop me? Hah!", 12340);

DELETE FROM `quest_offer_reward` WHERE `ID` = 14488;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(14488, 1, 0, 0, 0, 0, 0, 0, 0, "What we do here is none of your business...", 12340);
