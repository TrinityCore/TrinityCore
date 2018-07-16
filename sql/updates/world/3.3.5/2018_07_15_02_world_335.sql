-- Quest "Rat Catching"
DELETE FROM `quest_details` WHERE `ID`=416;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(416,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=416;
UPDATE `quest_offer_reward` SET `Emote1`=34, `Emote2`=1, `EmoteDelay2`=1000 WHERE `ID`=416;

-- Quest "WANTED: Chok'sul"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=256;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=256;

-- Quest "Mercenaries"
DELETE FROM `quest_details` WHERE `ID`=255;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(255,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=255;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=255;

-- Quest "Bailor's Ore Shipment"
DELETE FROM `quest_details` WHERE `ID`=1655;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1655,5,6,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=11, `EmoteOnComplete`=11 WHERE `ID`=1655;
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `Emote3`=1 WHERE `ID`=1655;

-- Quest "Badlands Reagent Run"
DELETE FROM `quest_details` WHERE `ID`=2500;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2500,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2500;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1 WHERE `ID`=2500;

-- Quest "Uldaman Reagent Run"
DELETE FROM `quest_details` WHERE `ID`=17;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(17,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=17;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1 WHERE `ID`=17;

-- Quest "Badlands Reagent Run II"
DELETE FROM `quest_details` WHERE `ID`=2501;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2501,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2501;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=2501;

-- Quest "Thelsamar Blood Sausages"
DELETE FROM `quest_details` WHERE `ID`=418;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(418,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=418;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=418;

-- Quest "Stonegear's Search"
DELETE FROM `quest_details` WHERE `ID`=467;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(467,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3 WHERE `ID`=467;

-- Quest "Search for Incendicite"
DELETE FROM `quest_details` WHERE `ID`=466;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(466,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=466;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=466;

-- Quest "Mountaineer Stormpike's Task"
DELETE FROM `quest_details` WHERE `ID`=1339;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1339,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1339;

-- Quest "Stormpike's Order"
DELETE FROM `quest_details` WHERE `ID`=1338;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1338,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1338;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1338;

-- Quest "The Trogg Threat"
DELETE FROM `quest_details` WHERE `ID`=267;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(267,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=267;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=267;

-- Quest "In Defense of the King's Lands"
DELETE FROM `quest_details` WHERE `ID`=224;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(224,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=224;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=224;

-- Quest "In Defense of the King's Lands (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=237;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(237,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=237;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=237;

-- Quest "In Defense of the King's Lands (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=263;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(263,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=263;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=263;

-- Quest "In Defense of the King's Lands (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=217;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(217,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=217;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=217;

-- Quest "The Horn of the Beast"
UPDATE `quest_request_items` SET `EmoteOnComplete`=274 WHERE `ID`=3181;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `Emote3`=1 WHERE `ID`=3181;

-- Quest "Proof of Deed"
DELETE FROM `quest_details` WHERE `ID`=3182;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3182,6,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3182;

-- Quest "At Last!"
UPDATE `quest_request_items` SET `EmoteOnComplete`=274 WHERE `ID`=3201;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=3201;

-- Quest "Crocolisk Hunting"
DELETE FROM `quest_details` WHERE `ID`=385;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(385,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=385;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=385;

-- Quest "A Hunter's Boast"
DELETE FROM `quest_details` WHERE `ID`=257;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(257,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=257;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=257;

-- Quest "A Hunter's Challenge"
DELETE FROM `quest_details` WHERE `ID`=258;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(258,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=258;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6 WHERE `ID`=258;

-- Quest "Vyrin's Revenge"
DELETE FROM `quest_details` WHERE `ID`=271;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(271,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=271;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=5, `EmoteDelay2`=1000, `EmoteDelay3`=1000 WHERE `ID`=271;

-- Quest "Vyrin's Revenge (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=531;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(531,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=11 WHERE `ID`=531;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=531;

-- Quest "Report to Mountaineer Rockgar"
DELETE FROM `quest_details` WHERE `ID`=468;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(468,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1 WHERE `ID`=468;

-- Quest "Ironband's Excavation"
DELETE FROM `quest_details` WHERE `ID`=436;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(436,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=5 WHERE `ID`=436;

-- Quest "Gathering Idols"
DELETE FROM `quest_details` WHERE `ID`=297;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(297,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=297;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=297;

-- Quest "Excavation Progress Report"
DELETE FROM `quest_details` WHERE `ID`=298;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(298,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6 WHERE `ID`=298;

-- Quest "Report to Ironforge"
DELETE FROM `quest_details` WHERE `ID`=301;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(301,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=301;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6 WHERE `ID`=301;

-- Quest "Powder to Ironband"
DELETE FROM `quest_details` WHERE `ID`=302;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(302,1,1,25,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=302;

-- Quest "Resupplying the Excavation"
DELETE FROM `quest_details` WHERE `ID`=273;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(273,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=273;

-- Quest "After the Ambush"
DELETE FROM `quest_details` WHERE `ID`=454;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(454,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=454;

-- Quest "Protecting the Shipment"
DELETE FROM `quest_details` WHERE `ID`=309;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(309,6,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=309;

-- Quest "Find Bingles"
DELETE FROM `quest_details` WHERE `ID`=2039;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2039,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=2039;

-- Quest "Bingles' Missing Supplies"
DELETE FROM `quest_details` WHERE `ID`=2038;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2038,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2038;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2038;

-- Quest "Honor Students"
DELETE FROM `quest_details` WHERE `ID`=6387;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6387,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6387;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6387;

-- Quest "Ride to Ironforge"
DELETE FROM `quest_details` WHERE `ID`=6391;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6391,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6391;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6391;

-- Quest "Gryth Thurden"
DELETE FROM `quest_details` WHERE `ID`=6388;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6388,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6388;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6388;

-- Quest "Return to Brock"
DELETE FROM `quest_details` WHERE `ID`=6392;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6392,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6392;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=6392;

-- Quest "Filthy Paws"
DELETE FROM `quest_details` WHERE `ID`=307;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(307,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=307;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=307;

-- Quest "A Dark Threat Looms"
DELETE FROM `quest_details` WHERE `ID`=250;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(250,5,1,25,0,0,0,0,0,0);

-- Quest "A Dark Threat Looms (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=199;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=199;

-- Quest "A Dark Threat Looms (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=161;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(161,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=161;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=161;

-- Quest "A Dark Threat Looms (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=274;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(274,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=274;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=274;

-- Quest "A Dark Threat Looms (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=278;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(278,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=278;

-- Quest "A Dark Threat Looms (Part 6)"
DELETE FROM `quest_details` WHERE `ID`=280;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(280,1,5,0,0,0,0,0,0,0);

-- Quest "A Dark Threat Looms (Part 7)"
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=283;

-- Quest "Ironband Wants You!"
DELETE FROM `quest_details` WHERE `ID`=707;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(707,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=707;

-- Quest "Find Agmond"
DELETE FROM `quest_details` WHERE `ID`=738;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(738,1,1,1,0,0,0,0,0,0);

-- Quest "Murdaloc"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=739;

-- Quest "Agmond's Fate"
DELETE FROM `quest_details` WHERE `ID`=704;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(704,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=704;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=2 WHERE `ID`=704;
