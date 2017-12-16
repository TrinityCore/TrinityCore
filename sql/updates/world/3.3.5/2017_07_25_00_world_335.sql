-- CompletionText for Quest ID 14350 'The Crimson Courier' (text missing)
DELETE FROM `quest_request_items` WHERE `ID` = 14350; -- Replaced quest ID 6145 (Varimathras)
INSERT INTO `quest_request_items` (`ID`,`EmoteOnComplete`,`EmoteOnIncomplete`,`CompletionText`,`VerifiedBuild`) VALUES
(14350, 1, 0, 'Succeed now and you will have almost earned my respect, $C.', 12340);

-- RewardText for Quest ID 14350 'The Crimson Courier' (text missing)
DELETE FROM `quest_offer_reward` WHERE `ID` = 14350; -- Replaced quest ID 6145 (Varimathras)
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(14350, 0, 0, 0, 0, 0, 0, 0, 0, '<Nathanos laughs.>$B$BExcellent! Finally! An opportunity to destroy the Scarlet Oracle!', 12340);

-- Minor typo in RewardText for quest ID 838 'Scholomance' (Horde)
UPDATE `quest_offer_reward` SET `RewardText`= "Yes, $C, the High Executor mentioned you might be the one to trust in the matter of the key. I've dedicated a fair portion of my recent studies to the Scholomance, and I believe I know a means by which you can acquire one that will let you past the front door at will.$b$bThis task will not be easy, but such tasks seldom are. You most assuredly look like the type to know this as fact." WHERE `ID` = 838;
