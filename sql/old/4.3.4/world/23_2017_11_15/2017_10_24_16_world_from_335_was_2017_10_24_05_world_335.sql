/*
-- Quest "Your Place In The World"
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=4641;

-- Quest "Vile Familiars"
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=792;

-- Quest "Galgar's Cactus Apple Surprise"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=4402;

-- Quest "Burning Blade Medallion"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=794;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=794;

-- Quest "Thazz'ril's Pick"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6394;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6394;

-- Quest "Report to Sen'jin Village"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=805;

-- Quest "Thwarting Kolkar Aggression"
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=786;

-- Quest "A Peon's Burden"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=2161;

-- Quest "Report to Orgnil"
DELETE FROM `quest_details` WHERE `ID`=823;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(823,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=823;

-- Quest "Minshina's Skull"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=808;

-- Quest "Zalazane"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=826;

-- Quest "A Solvent Spirit"
DELETE FROM `quest_details` WHERE `ID`=818;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(818,1,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=818;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=818;

-- Quest "Practical Prey"
DELETE FROM `quest_details` WHERE `ID`=817;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(817,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=817;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=817;

-- Quest "Vanquish the Betrayers"
DELETE FROM `quest_details` WHERE `ID`=784;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(784,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=784;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=784;

-- Quest "Break a Few Eggs"
DELETE FROM `quest_details` WHERE `ID`=815;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(815,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=815;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=815;

-- Quest "Carry Your Weight"
DELETE FROM `quest_details` WHERE `ID`=791;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(791,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=791;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=791;

-- Quest "From The Wreckage...."
DELETE FROM `quest_details` WHERE `ID`=825;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(825,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=825;
UPDATE `quest_offer_reward` SET `Emote1`=66, `EmoteDelay1`=1000 WHERE `ID`=825;

-- Quest "The Admiral's Orders"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=830;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=830;

-- Quest "The Admiral's Orders (Part 2)"
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=831;

-- Quest "Lost But Not Forgotten"
DELETE FROM `quest_details` WHERE `ID`=816;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(816,18,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=816;
UPDATE `quest_offer_reward` SET `Emote1`=18 WHERE `ID`=816;

-- Quest "Winds in the Desert"
DELETE FROM `quest_details` WHERE `ID`=834;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(834,2,0,0,0,0,0,0,0,0);

-- Quest "Securing the Lines"
DELETE FROM `quest_details` WHERE `ID`=835;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(835,1,1,0,0,0,0,0,0,0);

-- Quest "Need for a Cure"
DELETE FROM `quest_details` WHERE `ID`=812;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(812,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=812;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=812;

-- Quest "Hidden Enemies"
DELETE FROM `quest_details` WHERE `ID`=5726;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5726,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5726;
UPDATE `quest_offer_reward` SET `Emote1`=15 WHERE `ID`=5726;

-- Quest "Hidden Enemies (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=5727;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5727,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=5727;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=5727;

-- Quest "Finding the Antidote"
DELETE FROM `quest_details` WHERE `ID`=813;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(813,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=813;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=813;

-- Quest "Dark Storms"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=806;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=806;

-- Quest "Margoz"
DELETE FROM `quest_details` WHERE `ID`=828;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(828,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=828;

-- Quest "Skull Rock"
DELETE FROM `quest_details` WHERE `ID`=827;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(827,1,0,0,0,0,0,0,0,0);

-- Quest "Neeru Fireblade"
DELETE FROM `quest_details` WHERE `ID`=829;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(829,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2, `EmoteOnComplete`=2 WHERE `ID`=829;

-- Quest "Burning Shadows"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=832;
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=1000 WHERE `ID`=832;

-- Quest "Ak'Zeloth"
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=809;

-- Quest "Taming the Beast"
DELETE FROM `quest_details` WHERE `ID`=6062;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6062,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6062;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=6062;

-- Quest "Taming the Beast (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=6083;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6083,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6083;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=6083;

-- Quest "Taming the Beast (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=6082;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6082,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6082;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=6082;

-- Quest "Taming the Beast (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=6081;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6081,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6081;
*/
