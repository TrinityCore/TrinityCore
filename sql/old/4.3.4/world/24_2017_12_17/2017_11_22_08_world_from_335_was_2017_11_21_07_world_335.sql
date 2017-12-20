/*
-- 
-- Quest "Blood Feeders"
DELETE FROM `quest_details` WHERE `ID`=6461;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6461,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=6461;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6461;

-- Quest "Jin'Zil's Forest Magic"
DELETE FROM `quest_details` WHERE `ID`=1058;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1058,4,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=11, `EmoteOnComplete`=11 WHERE `ID`=1058;

-- Quest "Report to Kadrak"
DELETE FROM `quest_details` WHERE `ID`=6542;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6542,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3 WHERE `ID`=6542;

-- Quest "Boulderslide Ravine"
DELETE FROM `quest_details` WHERE `ID`=6421;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6421,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6421;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6421;

-- Quest "Earthen Arise"
DELETE FROM `quest_details` WHERE `ID`=6481;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6481,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6481;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6481;

-- Quest "Cenarius' Legacy"
DELETE FROM `quest_details` WHERE `ID`=1087;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1087,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1087;

-- Quest "Ordanus"
DELETE FROM `quest_details` WHERE `ID`=1088;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1088,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1088;

-- Quest "The Den"
DELETE FROM `quest_details` WHERE `ID`=1089;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1089,1,0,0,0,0,0,0,0,0);

-- Quest "Cycle of Rebirth"
DELETE FROM `quest_details` WHERE `ID`=6301;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6301,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6301;

-- Quest "New Life"
DELETE FROM `quest_details` WHERE `ID`=6381;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6381,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6381;

-- Quest "Harpies Threaten"
DELETE FROM `quest_details` WHERE `ID`=6282;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6282,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6282;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6282;

-- Quest "Bloodfury Bloodline"
DELETE FROM `quest_details` WHERE `ID`=6283;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6283,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6283;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6283;

-- Quest "Calling in the Reserves"
DELETE FROM `quest_details` WHERE `ID`=5881;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5881,1,0,0,0,0,0,0,0,0);

-- Quest "Arachnophobia"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6284;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6284;

-- Quest "Super Reaper 6000"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1093;

-- Quest "Further Instructions"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=1094;

-- Quest "Further Instructions (Part 2)"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1095;

-- Quest "Gerenzo Wrenchwhistle"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1096;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1096;

-- Quest "Gerenzo's Orders"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1090;

-- Quest "Gerenzo's Orders (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1092;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1092;

-- Quest "Trouble in the Deeps"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6562;

-- Quest "Warsong Scout Update"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6547;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6547;

-- Quest "Warsong Runner Update"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6545;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6545;

-- Quest "Warsong Outrider Update"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6546;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6546;

-- Quest "Ashenvale Outrunners"
DELETE FROM `quest_details` WHERE `ID`=6503;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6503,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6503;

-- Quest "Satyr Horns"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6441;

-- Quest "The Ashenvale Hunt"
DELETE FROM `quest_details` WHERE `ID`=6382;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6382,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6382;

-- Quest "The Ashenvale Hunt"
DELETE FROM `quest_details` WHERE `ID`=235;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(235,22,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=235;

-- Quest "The Ashenvale Hunt"
DELETE FROM `quest_details` WHERE `ID`=742;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(742,22,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=742;

-- Quest "The Ashenvale Hunt (Part 2)"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6383;

-- Quest "Shadumbra's Head"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=24;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=24;

-- Quest "Ursangous's Paw"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=23;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=23;

-- Quest "Stonetalon Standstill"
DELETE FROM `quest_details` WHERE `ID`=25;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25,6,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=25;

-- Quest "The Befouled Element"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1918;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1918;

-- Quest "Je'neu of the Earthen Ring"
DELETE FROM `quest_details` WHERE `ID`=824;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(824,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=824;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=824;

-- Quest "Warsong Supplies"
DELETE FROM `quest_details` WHERE `ID`=6571;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6571,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6571;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=6571;

-- Quest "Naga at the Zoram Strand"
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=6442;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6442;

-- Quest "Vorsha the Lasher"
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=6641;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=6641;

-- Quest "Between a Rock and a Thistlefur"
UPDATE `quest_details` SET `Emote1`=5 WHERE `ID`=216;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=216;

-- Quest "King of the Foulweald"
DELETE FROM `quest_details` WHERE `ID`=6621;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6621,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=6621;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=6621;

-- Quest "Troll Charm"
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=6462;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=14 WHERE `ID`=6462;

-- Quest "Amongst the Ruins"
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=6921;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=6921;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=6921;

-- Quest "The Essence of Aku'Mai"
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=6563;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=6563;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=6563;

-- Quest "Allegiance to the Old Gods"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6564;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6564;

-- Quest "Allegiance to the Old Gods (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=6565;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6565,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=6565;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=6565;

-- Quest "Freedom to Ruul"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=6482;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=2 WHERE `ID`=6482;

-- Quest "Destroy the Legion"
UPDATE `quest_details` SET `Emote1`=5 WHERE `ID`=9534;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=9534;

-- Quest "Diabolical Plans"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9535;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=9535;

-- Quest "Never Again!"
DELETE FROM `quest_details` WHERE `ID`=9536;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9536,25,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=9536;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2 WHERE `ID`=9536;

-- Quest "The Lost Pages"
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=6504;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=6504;

-- Quest "Torek's Assault"
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=6544;
*/
