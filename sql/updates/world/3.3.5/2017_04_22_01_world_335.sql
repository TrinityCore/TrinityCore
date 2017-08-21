-- Quest: An Unholy Alliance (14352) missing Progress text & Completion text & info
DELETE FROM `quest_request_items` WHERE `ID`= 14352;
INSERT INTO `quest_request_items` (`ID`,`EmoteOnComplete`,`EmoteOnIncomplete`,`CompletionText`,`VerifiedBuild`) VALUES
(14352, 0, 0, 'What do you want, $N?  This had better be important.', 12340);

DELETE FROM `quest_offer_reward` WHERE `ID`= 14352;
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(14352, 0, 0, 0, 0, 0, 0, 0, 0, "I've seen the insignia on this scroll before during my time in Northrend. You say this was on that crone who leads the pigs in Razorfen Kraul?$b$bI'll be damned if I'm going to let the Scourge get a foothold here. The one who wrote this - this Malcin - is one of the Lich King's servants, obviously, and that makes him a target. Your target.$b$bThey're not going to take Kalimdor.$b$b", 12340);
