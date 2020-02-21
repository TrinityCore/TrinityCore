UPDATE `quest_offer_reward` SET `RewardText`='Are you ready to set sail, $n?  Your people have been granted shelter in the lands of the kaldorei.$B$BDo not worry, $r.  Your people will get a chance to fight for Gilneas again.  This time, with the full strength of the Alliance.', `VerifiedBuild`=26365 WHERE `ID`=14434; -- Rut'theran Village
UPDATE `quest_offer_reward` SET `RewardText`='We did it, $n.  We\'ve started the evacuation.  If we leave soon we\'ll leave the Forsaken fleet in the dust.', `VerifiedBuild`=26365 WHERE `ID`=26706; -- Endgame
UPDATE `quest_offer_reward` SET `Emote1`=66, `RewardText`='It\'s almost over, $n.  Only one obstacle remains between us and survival.', `VerifiedBuild`=26365 WHERE `ID`=24681; -- They Have Allies, But So Do We
UPDATE `quest_offer_reward` SET `RewardText`='It\'s good to see you again, $n.', `VerifiedBuild`=26365 WHERE `ID`=24680; -- Keel Harbor
UPDATE `quest_offer_reward` SET `RewardText`='It\'s done, $n.  The dead return to their slumber.', `VerifiedBuild`=26365 WHERE `ID`=24679; -- Patriarch's Blessing
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $n.  Let us hope this works.', `VerifiedBuild`=26365 WHERE `ID`=24602; -- Laid to Rest
UPDATE `quest_offer_reward` SET `RewardText`='You\'re here, $n.  Most everyone made it through, but now we\'re stuck here... surrounded by our own... dead!', `VerifiedBuild`=26365 WHERE `ID`=24678; -- Knee-Deep
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done well, $n.  Almost everybody managed to make it through.  ', `VerifiedBuild`=26365 WHERE `ID`=24920; -- Slowing the Inevitable
UPDATE `quest_offer_reward` SET `RewardText`='You present me with the most difficult choice of my life, $n.', `VerifiedBuild`=26365 WHERE `ID`=24903; -- Vengeance or Survival
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=26365 WHERE `ID`=24676; -- Push Them Out
UPDATE `quest_offer_reward` SET `RewardText`='A disciple of the arcane always finds a way forward.  I\'m glad to see you, $n.', `VerifiedBuild`=26365 WHERE `ID`=14277; -- Arcane Inquiries

DELETE FROM `quest_details` WHERE `ID` IN (26706 /*Endgame*/, 24681 /*They Have Allies, But So Do We*/, 24680 /*Keel Harbor*/, 24679 /*Patriarch's Blessing*/, 24602 /*Laid to Rest*/, 24678 /*Knee-Deep*/, 24920 /*Slowing the Inevitable*/, 24903 /*Vengeance or Survival*/, 24902 /*The Hunt For Sylvanas*/, 24904 /*The Battle for Gilneas City*/, 14288 /*Safety in Numbers*/, 14277 /*Arcane Inquiries*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26706, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Endgame
(24681, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- They Have Allies, But So Do We
(24680, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Keel Harbor
(24679, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Patriarch's Blessing
(24602, 1, 0, 0, 0, 0, 0, 0, 0, 26365), -- Laid to Rest
(24678, 1, 0, 0, 0, 0, 0, 0, 0, 26365), -- Knee-Deep
(24920, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Slowing the Inevitable
(24903, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Vengeance or Survival
(24902, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Hunt For Sylvanas
(24904, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Battle for Gilneas City
(14288, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Safety in Numbers
(14277, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Arcane Inquiries

UPDATE `quest_request_items` SET `CompletionText`='You\'re back, $n.', `VerifiedBuild`=26365 WHERE `ID`=24602; -- Laid to Rest
UPDATE `quest_request_items` SET `CompletionText`='There aren\'t many of us left, $n.  We have to look out for those remaining Gilneans.', `VerifiedBuild`=26365 WHERE `ID`=14395; -- Gasping for Breath
