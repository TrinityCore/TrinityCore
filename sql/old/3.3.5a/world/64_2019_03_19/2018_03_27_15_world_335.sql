-- Quest "Bathran's Hair"
DELETE FROM `quest_details` WHERE `ID`=1010;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1010,1,1,6,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1010;

-- Quest "Elune's Tear"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1033;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2 WHERE `ID`=1033;

-- Quest "The Ruins of Stardust"
DELETE FROM `quest_details` WHERE `ID`=1034;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1034,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1034;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2 WHERE `ID`=1034;

-- Quest "Fallen Sky Lake"
DELETE FROM `quest_details` WHERE `ID`=1035;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1035,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1035;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=1035;

-- Quest "Journey to Stonetalon Peak"
DELETE FROM `quest_details` WHERE `ID`=1056;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1056,1,1,0,0,0,0,0,0,0);

-- Quest "Raene's Cleansing"
DELETE FROM `quest_details` WHERE `ID`=991;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(991,1,1,20,0,0,0,0,0,0);

-- Quest "Raene's Cleansing (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2 WHERE `ID`=1023;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=1023;

-- Quest "Raene's Cleansing (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1024;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1024,1,1,0,0,0,0,0,0,0);

-- Quest "Raene's Cleansing (Part 8)"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1029;

-- Quest "Raene's Cleansing (Part 9)"
DELETE FROM `quest_details` WHERE `ID`=1030;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1030,6,1,1,0,0,0,0,0,0);

-- Quest "Raene's Cleansing (Part 10)"
DELETE FROM `quest_details` WHERE `ID`=1045;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1045,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1045;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1045;

-- Quest "Raene's Cleansing (Part 11)"
DELETE FROM `quest_details` WHERE `ID`=1046;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1046,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1046;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=2, `Emote4`=1 WHERE `ID`=1046;

-- Quest "Culling the Threat"
DELETE FROM `quest_details` WHERE `ID`=1054;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1054,1,1,2,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1054;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1054;

-- Quest "The Ancient Statuette"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1007;

-- Quest "Ruuzel"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1009;

-- Quest "Elemental Bracers"
DELETE FROM `quest_details` WHERE `ID`=1016;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1016,66,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1016;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6 WHERE `ID`=1016;

-- Quest "Mage Summoner"
DELETE FROM `quest_details` WHERE `ID`=1017;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1017,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1017;
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1 WHERE `ID`=1017;

-- Quest "An Aggressive Defense"
DELETE FROM `quest_details` WHERE `ID`=1025;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1025,1,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1025;

-- Quest "The Zoram Strand"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1008;

-- Quest "Pridewings of Stonetalon"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1134;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1134;

-- Quest "Kayneth Stillwind"
DELETE FROM `quest_details` WHERE `ID`=4581;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4581,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=4581;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=4581;

-- Quest "Forsaken Diseases"
DELETE FROM `quest_details` WHERE `ID`=1011;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1011,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1011;

-- Quest "Insane Druids"
DELETE FROM `quest_details` WHERE `ID`=1012;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1012,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1012;

-- Quest "The Howling Vale"
DELETE FROM `quest_details` WHERE `ID`=1022;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1022,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1022;

-- Quest "Velinde Starsong"
DELETE FROM `quest_details` WHERE `ID`=1037;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1037,1,1,0,0,0,0,0,0,0);

-- Quest "Velinde's Effects"
DELETE FROM `quest_details` WHERE `ID`=1038;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1038,6,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1038;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1038;

-- Quest "The Barrens Port"
DELETE FROM `quest_details` WHERE `ID`=1039;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1039,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1039;

-- Quest "The Caravan Road"
DELETE FROM `quest_details` WHERE `ID`=1041;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1041,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1041;

-- Quest "The Carevin Family"
DELETE FROM `quest_details` WHERE `ID`=1042;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1042,274,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1042;

-- Quest "The Scythe of Elune"
DELETE FROM `quest_details` WHERE `ID`=1043;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1043,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1043;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1043;

-- Quest "Answered Questions"
DELETE FROM `quest_details` WHERE `ID`=1044;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1044,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=2 WHERE `ID`=1044;

-- Quest "A Helping Hand"
DELETE FROM `quest_details` WHERE `ID`=9533;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9533,1,274,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9533;

-- Quest "A Shameful Waste"
DELETE FROM `quest_details` WHERE `ID`=9517;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9517,1,0,0,0,0,0,0,0,0);

-- Quest "The Lost Chalice"
DELETE FROM `quest_details` WHERE `ID`=9519;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9519,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9519;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9519;

-- Quest "Destroy the Legion"
DELETE FROM `quest_details` WHERE `ID`=9516;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9516,5,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9516;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=9516;

-- Quest "Diabolical Plans"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9520;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=274 WHERE `ID`=9520;

-- Quest "Never Again!"
DELETE FROM `quest_details` WHERE `ID`=9522;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9522,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9522;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=66 WHERE `ID`=9522;

-- Quest "Agents of Destruction"
DELETE FROM `quest_details` WHERE `ID`=9518;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9518,1,5,25,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=5, `Emote3`=6 WHERE `ID`=9518;

-- Quest "Report from the Northern Front"
DELETE FROM `quest_details` WHERE `ID`=9521;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9521,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9521;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=9521;

-- Quest "Supplies to Auberdine"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=976;

-- Quest "In Search of Thaelrid"
DELETE FROM `quest_details` WHERE `ID`=1198;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1198,1,1,0,0,0,0,0,0,0);

-- Quest "Twilight Falls"
DELETE FROM `quest_details` WHERE `ID`=1199;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1199,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1199;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=1199;

-- Quest "Blackfathom Villainy"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1200;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=66 WHERE `ID`=1200;

-- Quest "The Tower of Althalaxx (Part 2)"
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=966;
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=5 WHERE `ID`=966;

-- Quest "The Tower of Althalaxx (Part 3)"
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=967;

-- Quest "The Tower of Althalaxx (Part 6)"
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=1140;

-- Quest "The Tower of Althalaxx (Part 7)"
DELETE FROM `quest_details` WHERE `ID`=1167;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1167,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=6 WHERE `ID`=1167;

-- Quest "The Tower of Althalaxx (Part 8)"
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=1143;

-- Quest "The Tower of Althalaxx (Part 9)"
DELETE FROM `quest_details` WHERE `ID`=981;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(981,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=2 WHERE `ID`=981;

-- Quest "Cave Mushrooms"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=947;

-- Quest "The Corruption Abroad"
DELETE FROM `quest_details` WHERE `ID`=3765;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3765,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=3765;

-- Quest "Researching the Corruption"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=1275;

-- Quest "The Powers Below"
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=6 WHERE `ID`=968;

-- Quest "Reclaiming the Charred Vale (Part 2)"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1059;

-- Quest "On Guard in Stonetalon"
DELETE FROM `quest_details` WHERE `ID`=1070;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1070,3,6,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=1070;

-- Quest "On Guard in Stonetalon (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1085;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1085,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1085;

-- Quest "A Gnome's Respite"
DELETE FROM `quest_details` WHERE `ID`=1071;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1071,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=1071;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1071;

-- Quest "A Scroll from Mauren"
DELETE FROM `quest_details` WHERE `ID`=1075;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1075,1,0,0,0,0,0,0,0,0);

-- Quest "Devils in Westfall"
DELETE FROM `quest_details` WHERE `ID`=1076;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1076,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1076;

-- Quest "Special Delivery for Gaxim"
DELETE FROM `quest_details` WHERE `ID`=1077;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1077,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=1077;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=1077;

-- Quest "An Old Colleague"
DELETE FROM `quest_details` WHERE `ID`=1072;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1072,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1072;

-- Quest "Ineptitude + Chemicals = Fun"
DELETE FROM `quest_details` WHERE `ID`=1073;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1073,11,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1073;
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1 WHERE `ID`=1073;

-- Quest "Ineptitude + Chemicals = Fun (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1074;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1074,1,11,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1074;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=1074;

-- Quest "Covert Ops - Alpha"
DELETE FROM `quest_details` WHERE `ID`=1079;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1079,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1079;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1079;

-- Quest "Covert Ops - Beta"
DELETE FROM `quest_details` WHERE `ID`=1080;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1080,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1080;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1080;

-- Quest "Kaela's Update"
DELETE FROM `quest_details` WHERE `ID`=1091;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1091,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1091;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=1091;

-- Quest "Enraged Spirits"
DELETE FROM `quest_details` WHERE `ID`=1083;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1083,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1083;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1083;

-- Quest "Enraged Spirits"
DELETE FROM `quest_details` WHERE `ID`=1084;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1084,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=1084;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1084;

-- Quest "Update for Sentinel Thenysil"
DELETE FROM `quest_details` WHERE `ID`=1082;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1082,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1082;

-- Quest "Reception from Tyrande"
DELETE FROM `quest_details` WHERE `ID`=1081;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1081,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1081;

-- Quest "Castpipe's Task"
DELETE FROM `quest_details` WHERE `ID`=2931;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2931,5,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2931;

-- Quest "Data Rescue"
DELETE FROM `quest_details` WHERE `ID`=2930;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2930,5,1,1,6,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2930;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=2930;
