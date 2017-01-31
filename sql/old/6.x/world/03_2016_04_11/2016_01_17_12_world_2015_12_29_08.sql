-- 
-- Update (insert) missing CompletionText for Quest 2358, Horns of Nez'ra
UPDATE `quest_request_items` SET `CompletionText`="Do you have the demon prince's horns?" WHERE `ID`= 2358;

-- Insert completely missing `quest_offer_reward` info
DELETE FROM `quest_offer_reward` WHERE `ID`= 2358;
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(2358, 0, 0, 0, 0, 0, 0, 0, 0, "To deny Ravenholdt the artifact, would be to deny one's own existence. Well done, $C. You may yet walk among the assassins of Ravenholdt.$B$B As a young rogue adventuring in Darkshore, I discovered a tea that replenishes energy in combat. It has served me well throughout the years and now I pass on a taste of the thistle tea to you. Drink of it when you tire, $N, and fight with vigor once more!$B$B", 0);
