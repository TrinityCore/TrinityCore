/*
-- Quest "Conscript of the Horde"
UPDATE `quest_request_items` SET `EmoteOnComplete`=15 WHERE `ID`=840;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=840;

-- Quest "Crossroads Conscription"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=842;

-- Quest "Meats to Orgrimmar"
DELETE FROM `quest_details` WHERE `ID`=6365;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6365,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6365;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6365;

-- Quest "Ride to Orgrimmar"
DELETE FROM `quest_details` WHERE `ID`=6384;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6384,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6384;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=6384;

-- Quest "Doras the Wind Rider Master"
DELETE FROM `quest_details` WHERE `ID`=6385;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6385,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6385;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6385;

-- Quest "Return to the Crossroads"
DELETE FROM `quest_details` WHERE `ID`=6386;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6386,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6386;
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1 WHERE `ID`=6386;

-- Quest "Plainstrider Menace"
DELETE FROM `quest_details` WHERE `ID`=844;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(844,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=844;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=844;

-- Quest "The Zhevra"
DELETE FROM `quest_details` WHERE `ID`=845;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(845,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=845;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=845;

-- Quest "Prowlers of the Barrens"
DELETE FROM `quest_details` WHERE `ID`=903;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(903,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=903;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=903;

-- Quest "Echeyakee"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=881;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=881;

-- Quest "The Angry Scytheclaws"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=905;

-- Quest "Jorn Skyseer"
DELETE FROM `quest_details` WHERE `ID`=3261;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3261,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3261;

-- Quest "Ishamuhale"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=882;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=882;

-- Quest "Enraged Thunder Lizards"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=907;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=907;

-- Quest "Cry of the Thunderhawk"
DELETE FROM `quest_details` WHERE `ID`=913;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(913,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=913;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=913;

-- Quest "Mahren Skyseer"
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=874;

-- Quest "Isha Awak"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=873;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=873;

-- Quest "Washte Pawne"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=885;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=885;

-- Quest "Lakota'mani"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=883;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=883;

-- Quest "Owatanka"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=884;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=884;

-- Quest "The Harvester"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=897;
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1 WHERE `ID`=897;

-- Quest "The Forgotten Pools"
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=870;

-- Quest "The Stagnant Oasis"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=877;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=877;

-- Quest "Altered Beings"
DELETE FROM `quest_details` WHERE `ID`=880;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(880,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=880;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=880;

-- Quest "Mura Runetotem"
DELETE FROM `quest_details` WHERE `ID`=3301;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3301;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=2 WHERE `ID`=3301;

-- Quest "Hamuul Runetotem"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1489;

-- Quest "Nara Wildmane"
DELETE FROM `quest_details` WHERE `ID`=1490;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1490,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=1490;

-- Quest "Leaders of the Fang"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=914;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2 WHERE `ID`=914;

-- Quest "Raptor Thieves"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=869;

-- Quest "Stolen Silver"
DELETE FROM `quest_details` WHERE `ID`=3281;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3281,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3281;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3281;

-- Quest "Wharfmaster Dizzywig"
DELETE FROM `quest_details` WHERE `ID`=1492;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1492,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1492;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1492;

-- Quest "Fungal Spores"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=848;

-- Quest "Apothecary Zamah"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=853;

-- Quest "Disrupt the Attacks"
DELETE FROM `quest_details` WHERE `ID`=871;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(871,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=871;

-- Quest "The Disruption Ends"
DELETE FROM `quest_details` WHERE `ID`=872;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(872,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=872;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=872;

-- Quest "Supplies for the Crossroads"
DELETE FROM `quest_details` WHERE `ID`=5041;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5041,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=5041;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=11 WHERE `ID`=5041;

-- Quest "Harpy Raiders"
DELETE FROM `quest_details` WHERE `ID`=867;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(867,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=867;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=867;

-- Quest "Harpy Lieutenants"
DELETE FROM `quest_details` WHERE `ID`=875;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(875,11,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=875;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=875;

-- Quest "Serena Bloodfeather"
DELETE FROM `quest_details` WHERE `ID`=876;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(876,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=876;
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=876;

-- Quest "Letter to Jin'Zil"
DELETE FROM `quest_details` WHERE `ID`=1060;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1060,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1060;

-- Quest "Southsea Freebooters"
DELETE FROM `quest_details` WHERE `ID`=887;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(887,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=887;

-- Quest "The Guns of Northwatch"
DELETE FROM `quest_details` WHERE `ID`=891;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(891,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=891;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=891;

-- Quest "Trouble at the Docks"
DELETE FROM `quest_details` WHERE `ID`=959;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(959,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=959;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=959;

-- Quest "The Missing Shipment"
DELETE FROM `quest_details` WHERE `ID`=890;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(890,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=890;

-- Quest "The Missing Shipment (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=892;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=892;

-- Quest "Stolen Booty"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=888;

-- Quest "WANTED: Baron Longshore"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=895;

-- Quest "Miner's Fortune"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=896;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=896;

-- Quest "Ziz Fizziks"
DELETE FROM `quest_details` WHERE `ID`=1483;

-- Quest "Wenikee Boltbucket"
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=3921;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3921;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=3921;

-- Quest "Nugget Slugs"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3922;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=3922;

-- Quest "Rilli Greasygob"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3923;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=3923;

-- Quest "Samophlange Manual"
DELETE FROM `quest_details` WHERE `ID`=3924;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3924,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3924;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=3924;

-- Quest "Raptor Horns"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=865;

-- Quest "Deepmoss Spider Eggs"
DELETE FROM `quest_details` WHERE `ID`=1069;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1069,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1069;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1069;

-- Quest "Blueleaf Tubers"
DELETE FROM `quest_details` WHERE `ID`=1221;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1221,22,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1221;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1221;

-- Quest "Smart Drinks"
DELETE FROM `quest_details` WHERE `ID`=1491;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1491,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1491;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1491;

-- Quest "Lost in Battle"
DELETE FROM `quest_details` WHERE `ID`=4921;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4921,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=4921;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=4921;

-- Quest "Consumed by Hatred"
DELETE FROM `quest_details` WHERE `ID`=899;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(899,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=899;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=899;

-- Quest "Centaur Bracers"
DELETE FROM `quest_details` WHERE `ID`=855;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(855,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=855;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=855;

-- Quest "Kolkar Leaders"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=850;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=850;

-- Quest "Verog the Dervish"
DELETE FROM `quest_details` WHERE `ID`=851;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(851,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=851;

-- Quest "Hezrul Bloodmark"
DELETE FROM `quest_details` WHERE `ID`=852;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(852,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=852;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=852;

-- Quest "Counterattack!"
DELETE FROM `quest_details` WHERE `ID`=4021;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4021,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4021;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=66 WHERE `ID`=4021;

-- Quest "Avenge My Village"
DELETE FROM `quest_details` WHERE `ID`=6548;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6548,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=6548;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6548;

-- Quest "Kill Grundig Darkcloud"
DELETE FROM `quest_details` WHERE `ID`=6629;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6629,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=6629;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=6629;

-- Quest "Protect Kaya"
DELETE FROM `quest_details` WHERE `ID`=6523;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6523,2,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=6523;

-- Quest "Kaya's Alive"
DELETE FROM `quest_details` WHERE `ID`=6401;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6401,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=6401;

-- Quest "The Spirits of Stonetalon"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1061;

-- Quest "Goblin Invaders"
DELETE FROM `quest_details` WHERE `ID`=1062;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1062,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1062;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1062;

-- Quest "The Elder Crone"
DELETE FROM `quest_details` WHERE `ID`=1063;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1063,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1063;

-- Quest "Forsaken Aid"
DELETE FROM `quest_details` WHERE `ID`=1064;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1064,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1064;

-- Quest "Journey to Tarren Mill"
DELETE FROM `quest_details` WHERE `ID`=1065;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1065,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5 WHERE `ID`=1065;

-- Quest "Blood of Innocents"
DELETE FROM `quest_details` WHERE `ID`=1066;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1066,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1066;
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1 WHERE `ID`=1066;

-- Quest "Return to Thunder Bluff"
DELETE FROM `quest_details` WHERE `ID`=1067;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1067,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1067;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1067;

-- Quest "The Flying Machine Airport"
DELETE FROM `quest_details` WHERE `ID`=1086;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1086,1,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1 WHERE `ID`=1086;

-- Quest "Shredding Machines"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1068;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=1068;

-- Quest "Egg Hunt"
DELETE FROM `quest_details` WHERE `ID`=868;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(868,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=868;

-- Quest "Report to Kadrak"
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=6541;
UPDATE `quest_offer_reward` SET `Emote1`=3 WHERE `ID`=6541;

-- Quest "Weapons of Choice"
DELETE FROM `quest_details` WHERE `ID`=893;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(893,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=893;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=893;

-- Quest "A New Ore Sample"
DELETE FROM `quest_details` WHERE `ID`=1153;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1153,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1153;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1153;

-- Quest "Chen's Empty Keg"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=819;
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=1000 WHERE `ID`=819;

-- Quest "Chen's Empty Keg (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=821;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(821,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=821;
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1 WHERE `ID`=821;

-- Quest "Chen's Empty Keg (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=822;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(822,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=822;
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1 WHERE `ID`=822;

-- Quest "Free From the Hold"
DELETE FROM `quest_details` WHERE `ID`=898;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(898,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=898;

-- Quest "Gann's Reclamation"
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=843;

-- Quest "Revenge of Gann (Part 1)"
DELETE FROM `quest_details` WHERE `ID`=846;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(846,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=846;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=846;

-- Quest "Revenge of Gann (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=849;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(849,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=849;

-- Quest "Betrayal from Within (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=906;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=4, `Emote3`=1 WHERE `ID`=906;

-- Quest "Melor Sends Word"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1130;

-- Quest "The Tear of the Moons"
DELETE FROM `quest_details` WHERE `ID`=857;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(857,5,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=857;
UPDATE `quest_offer_reward` SET `Emote1`=15 WHERE `ID`=857;

-- Quest "The Runed Scroll"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3513;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=3513;

-- Quest "Horde Presence"
DELETE FROM `quest_details` WHERE `ID`=3514;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3514,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=3514;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2 WHERE `ID`=3514;

-- Quest "The Warsong Reports"
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=6543;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6543;

-- Quest "Regthar Deathgate"
DELETE FROM `quest_details` WHERE `ID`=1361;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1361,1,0,0,0,0,0,0,0,0);

-- Quest "The Kolkar of Desolace"
DELETE FROM `quest_details` WHERE `ID`=1362;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1362,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1362;

-- Quest "The Swarm Grows"
DELETE FROM `quest_details` WHERE `ID`=1145;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1145,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=1145;

-- Quest "The Swarm Grows (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1146;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1146,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1146;

-- Quest "The Swarm Grows (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1147;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1147,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1 WHERE `ID`=1147;

-- Quest "Deviate Hides"
DELETE FROM `quest_details` WHERE `ID`=1486;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1486,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1486;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1486;

-- Quest "Deviate Eradication"
DELETE FROM `quest_details` WHERE `ID`=1487;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1487,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=1487;
*/
