-- Quest: Training the Beast (Tauren)
DELETE FROM `quest_offer_reward` WHERE `ID`= 6089;
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(6089, 1, 0, 0, 0, 0, 0, 0, 0, "A young $c, I see. Yes, I can bestow you with the skills you need to train and guide your pet. Not only will you be able to teach your pet new abilities, you will now be able to feed your pet, as well as revive it, should it fall in battle.$B$BNow, go forth. May the Earthmother guide you on your path. We shall speak again, at a later date.", 12340);
