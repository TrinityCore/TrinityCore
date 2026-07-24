-- The Super Snapper FX
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=1 WHERE `ID`=2944;

-- Trouble In Darkshore?
UPDATE `quest_details` SET `Emote1`=2,`Emote2`=1,`Emote3`=1,`Emote4`=25 WHERE `ID`=730;

-- Sathrah's Sacrifice
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=2520;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2520;

-- The Temple of the Moon
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=2519;

-- The Hunter's Charm
UPDATE `quest_details` SET `Emote1`=396 WHERE `ID`=8151;

-- The Hunter's Path
DELETE FROM `quest_details` WHERE `ID`=6071;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6071,396,0,0,0,0,0,0,0,0);

-- A Lesson to Learn
DELETE FROM `quest_details` WHERE `ID`=26;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(26,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=26;

-- Lessons Anew
DELETE FROM `quest_details` WHERE `ID`=6121;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6121,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2,`Emote2`=1 WHERE `ID`=6121;

-- Heeding the Call
DELETE FROM `quest_details` WHERE `ID`IN (5923,5925);
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5923,1,0,0,0,0,0,0,0,0),
(5925,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (5923,5925);

-- The Shade of Elura
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1686;

-- The Barrens Port
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=1039;

-- Velinde's Effects
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=1038;

-- Weapons of Elunite
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=2 WHERE `ID`=1693;

-- Smith Mathiel
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1692;

-- Vorlus Vilehoof
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=1683;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1683;

-- Elanaria
DELETE FROM `quest_details` WHERE `ID`=1684;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1684,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1684;

-- Taming the Beast
DELETE FROM `quest_details` WHERE `ID`=6102;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6102,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=273,`Emote2`=2 WHERE `ID`=6102;

-- Taming the Beast
DELETE FROM `quest_details` WHERE `ID`=6101;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6101,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=273,`Emote2`=2 WHERE `ID`=6101;

-- Taming the Beast
DELETE FROM `quest_details` WHERE `ID`=6063;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6063,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=273,`Emote2`=2 WHERE `ID`=6063;

-- Garments of the Moon
DELETE FROM `quest_details` WHERE `ID`=5621;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5621,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5621;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=5621;

-- In Favor of Elune
DELETE FROM `quest_details` WHERE `ID`=5622;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5622,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2,`Emote2`=1 WHERE `ID`=5622;

-- Body and Heart
DELETE FROM `quest_details` WHERE `ID`=6001;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6001,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=6001;

-- Moonglade
DELETE FROM `quest_details` WHERE `ID`=5921;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5921,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5921;

-- Mortality Wanes
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6,`EmoteOncomplete`=6 WHERE `ID`=1142;
UPDATE `quest_offer_reward` SET `Emote1`=15,`Emote2`=18,`Emote3`=18 WHERE `ID`=1142;

-- Blackfathom Villainy
UPDATE `quest_offer_reward` SET `Emote3`=5,`Emote4`=66 WHERE `ID`=1200;

-- Return to Nessa
DELETE FROM `quest_details` WHERE `ID`=6343;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6343,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6343;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6,`EmoteOnComplete`=6 WHERE `ID`=6343;

-- Flight to Auberdine
DELETE FROM `quest_details` WHERE `ID`=6342;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6342,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=6342;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6342;

-- The Bounty of Teldrassil
DELETE FROM `quest_details` WHERE `ID`=6341;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6341,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6341;

-- Nessa Shadowsong
DELETE FROM `quest_details` WHERE `ID`=6344;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6344,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6344;

-- Destiny Calls
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=2242;

-- In Search of Thaelrid
UPDATE `quest_details` SET `Emote3`=1 WHERE `ID`=1198;

-- Crown of the Earth
UPDATE `quest_request_items` SET `EmoteOnComplete`=1,`EmoteOnIncomplete`=1 WHERE `ID`=935;

-- The Apple Falls
DELETE FROM `quest_details` WHERE `ID`=2241;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(2241,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=14 WHERE `ID`=2241;

-- Ursal the Mauler
UPDATE `quest_request_items` SET `EmoteOnComplete`=5,`EmoteOnIncomplete`=5 WHERE `ID`=486;

-- Rellian Greenspyre
DELETE FROM `quest_details` WHERE `ID`=922;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(922,1,2,0,0,0,0,0,0,0);

-- A Friend in Need
DELETE FROM `quest_details` WHERE `ID`=3519;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(3519,34,0,0,0,0,0,0,0,0);

-- Crown of the Earth
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=933;

-- The Relics of Wakening
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=483;

-- Twisted Hatred
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6,`EmoteOnComplete`=6 WHERE `ID`=932;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=932;
