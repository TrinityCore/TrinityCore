UPDATE `quest_offer_reward` SET `RewardText`='Are you ready to set sail, $N?  Your people have been granted shelter in the lands of the kaldorei.$B$BDo not worry, $r.  Your people will get a chance to fight for Gilneas again.  This time, with the full strength of the Alliance.', `VerifiedBuild`=60192 WHERE `ID`=14434; -- Rut'theran Village
UPDATE `quest_offer_reward` SET `RewardText`='We did it, $N.  We\'ve started the evacuation.  If we leave soon we\'ll leave the Forsaken fleet in the dust.', `VerifiedBuild`=60192 WHERE `ID`=26706; -- Endgame
UPDATE `quest_offer_reward` SET `RewardText`='It\'s almost over, $N.  Only one obstacle remains between us and survival.', `VerifiedBuild`=60192 WHERE `ID`=24681; -- They Have Allies, But So Do We
UPDATE `quest_offer_reward` SET `RewardText`='It\'s good to see you again, $N.', `VerifiedBuild`=60192 WHERE `ID`=24680; -- Keel Harbor
UPDATE `quest_offer_reward` SET `RewardText`='It\'s done, $N.  The dead return to their slumber.', `VerifiedBuild`=60192 WHERE `ID`=24679; -- Patriarch's Blessing
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N.  Let us hope this works.', `VerifiedBuild`=60192 WHERE `ID`=24602; -- Laid to Rest
UPDATE `quest_offer_reward` SET `RewardText`='You\'re here, $N.  Most everyone made it through, but now we\'re stuck here... surrounded by our own... dead!', `VerifiedBuild`=60192 WHERE `ID`=24678; -- Knee-Deep
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done well, $N.  Almost everybody managed to make it through.  ', `VerifiedBuild`=60192 WHERE `ID`=24920; -- Slowing the Inevitable
UPDATE `quest_offer_reward` SET `RewardText`='You present me with the most difficult choice of my life, $N.', `VerifiedBuild`=60192 WHERE `ID`=24903; -- Vengeance or Survival
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done it again, $N.  The freed villagers are eager to help us against the Forsaken in any way they can.', `VerifiedBuild`=60192 WHERE `ID`=24575; -- Liberation Day
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $N.  Our people will no longer suffer under that monstrosity\'s yoke.', `VerifiedBuild`=60192 WHERE `ID`=24674; -- Slaves to No One
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $N.  Our men and women will have a last good meal before they set off for battle.', `VerifiedBuild`=60192 WHERE `ID`=24675; -- Last Meal

DELETE FROM `quest_request_items` WHERE `ID` IN (24676 /*Push Them Out*/, 24681 /*They Have Allies, But So Do We*/, 24902 /*The Hunt For Sylvanas*/, 24679 /*Patriarch's Blessing*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(24676, 0, 0, 0, 0, 'You\'re back, $N.', 60192), -- Push Them Out
(24681, 0, 0, 0, 0, 'You\'re back!', 60192), -- They Have Allies, But So Do We
(24902, 0, 0, 0, 0, 'Did you find her, $N?', 60192), -- The Hunt For Sylvanas
(24679, 0, 0, 0, 0, 'Is it done, $N?', 60192); -- Patriarch's Blessing
