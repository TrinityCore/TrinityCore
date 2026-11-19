-- Novice Elreth (Quest & NPC name), quest completion text (missing)
DELETE FROM `quest_offer_reward` WHERE `ID` = 28651;
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(28651, 0, 0, 0, 0, 0, 0, 0, 0, 'May the Dark Lady watch over you, $n.', 24015);
