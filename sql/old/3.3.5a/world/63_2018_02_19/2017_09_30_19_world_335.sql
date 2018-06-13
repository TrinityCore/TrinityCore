-- Emotes for Quest "Seek Redemption!"
DELETE FROM `quest_details` WHERE `ID`=489;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(489,1,5,0,0,0,0,0,0,0);

-- Emotes for Quest "A Troubling Breeze"
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=25 WHERE `ID`=475;

-- Emotes for Quest "Twisted Hatred"
DELETE FROM `quest_details` WHERE `ID`=932;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(932,2,0,0,0,500,0,0,0,0);

-- Emotes for Quest "The Emerald Dreamcatcher"
DELETE FROM `quest_details` WHERE `ID`=2438;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2438,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=2438;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2438;

-- Emotes for Quest "Gnarlpine Corruption"
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=476;

-- Emotes for Quest "The Relics of Wakening"
DELETE FROM `quest_details` WHERE `ID`=483;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(483,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=483;

-- Emotes for Quest "Ursal the Mauler"
DELETE FROM `quest_details` WHERE `ID`=486;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(486,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=486;

-- Emotes for Quest "Ferocitas the Dream Eater"
DELETE FROM `quest_details` WHERE `ID`=2459;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2459,15,1,0,0,0,100,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=2459;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2459;

-- Emotes for Quest "Denalan's Earth"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=997;

-- Emotes for Quest "The Road to Darnassus"
DELETE FROM `quest_details` WHERE `ID`=487;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(487,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=487;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=487;

-- Emotes for Quest "Crown of the Earth (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=929;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(929,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=929;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=929;

-- Emotes for Quest "Crown of the Earth (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=933;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(933,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=933;

-- Emotes for Quest "Crown of the Earth (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=7383;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7383,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=7383;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7383;

-- Emotes for Quest "Crown of the Earth (Part 6)"
DELETE FROM `quest_details` WHERE `ID`=935;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(935,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=935;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=935;

-- Emotes for Quest "Timberling Seeds"
DELETE FROM `quest_details` WHERE `ID`=918;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(918,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=918;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=918;

-- Emotes for Quest "Timberling Sprouts"
DELETE FROM `quest_details` WHERE `ID`=919;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(919,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=919;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=919;

-- Emotes for Quest "Rellian Greenspyre"
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=922;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=922;

-- Emotes for Quest "The Glowing Fruit"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=930;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=930;

-- Emotes for Quest "The Shimmering Frond"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=931;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2 WHERE `ID`=931;

-- Emotes for Quest "Planting the Heart"
DELETE FROM `quest_details` WHERE `ID`=941;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(941,1,0,0,0,0,0,0,0,0);

-- Emotes for Quest "Tumors"
DELETE FROM `quest_details` WHERE `ID`=923;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(923,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=923;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=923;

-- Emotes for Quest "Return to Denalan"
DELETE FROM `quest_details` WHERE `ID`=2498;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2498,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2498;

-- Emotes for Quest "Oakenscowl"
DELETE FROM `quest_details` WHERE `ID`=2499;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2499,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2499;
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=200 WHERE `ID`=2499;

-- Emotes for Quest "The Sleeping Druid"
DELETE FROM `quest_details` WHERE `ID`=2541;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2541,2,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2541;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2541;

-- Emotes for Quest "Druid of the Claw"
DELETE FROM `quest_details` WHERE `ID`=2561;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2561,2,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2561;

-- Emotes for Quest "The Enchanted Glade"
DELETE FROM `quest_details` WHERE `ID`=937;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(937,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=937;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=937;

-- Emotes for Quest "Teldrassil"
DELETE FROM `quest_details` WHERE `ID`=940;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(940,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=940;

-- Emotes for Quest "Grove of the Ancients"
DELETE FROM `quest_details` WHERE `ID`=952;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(952,1,0,0,0,0,0,0,0,0);

-- Emotes for Quest "The Temple of the Moon"
DELETE FROM `quest_details` WHERE `ID`=2519;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2519,1,0,0,0,0,0,0,0,0);

-- Emotes for Quest "Tears of the Moon"
DELETE FROM `quest_details` WHERE `ID`=2518;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2518,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=18, `EmoteOnComplete`=18 WHERE `ID`=2518;
UPDATE `quest_offer_reward` SET `Emote1`=2, `EmoteDelay1`=100 WHERE `ID`=2518;

-- Emotes for Quest "Sathrah's Sacrifice"
DELETE FROM `quest_details` WHERE `ID`=2520;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2520,1,0,0,0,0,0,0,0,0);
