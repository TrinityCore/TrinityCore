-- Control (9595)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9595;

-- Mage Training (9290)
UPDATE `quest_offer_reward` SET `Emote2`=6 WHERE `ID`=9290;

-- Help Tavara (9586)
DELETE FROM `quest_details` WHERE `ID`=9586;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9586,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9586;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9586;

-- Priest Training (9291)
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=9291;

-- Beast Training (9675)
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=9675;

-- Taming the Beast (9593)
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=9593;
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=9593;

-- Taming the Beast (9592)
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=5 WHERE `ID`=9592;

-- Taming the Beast (9591)
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=9591;

-- Hunter Training (9288)
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote3`=6 WHERE `ID`=9288;

-- Redemption (9600)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9600;

-- Redemption (9598)
UPDATE `quest_offer_reward` SET `Emote3`=1 WHERE `ID`=9598;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9598;

-- Behomat (10350)
UPDATE `quest_offer_reward` SET `Emote1`=2,`Emote2`=1 WHERE `ID`=10350;
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=10350;

-- Strength of One (9582)
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=9582;
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=9582;

-- A Cry For Help
DELETE FROM `quest_details` WHERE `ID`=9528;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9528,1,1,1,6,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6,`Emote2`=1,`Emote3`=1,`Emote2`=1 WHERE `ID`=9528;

-- A Hearty Thanks! (9612)
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=4 WHERE `ID`=9612;

-- Call of Water (9501)
DELETE FROM `quest_details` WHERE `ID`=9501;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9501,1,1,1,0,0,0,0,0,0);

-- Call of Water (9500)
DELETE FROM `quest_details` WHERE `ID`=9500;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9500,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9500;

-- The Unwritten Prophecy (9762)
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1,`Emote4`=1 WHERE `ID`=9762;

-- Truth or Fiction (9699)
DELETE FROM `quest_details` WHERE `ID`=9699;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9699,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9699;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9699;

-- The Way to Auberdine (9633)
DELETE FROM `quest_details` WHERE `ID`=9633;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9633,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9633;

-- Return to Topher Loaal (9606)
DELETE FROM `quest_details` WHERE `ID`=9606;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9606,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9606;

-- Hippogryph Master Stephanos (9605)
DELETE FROM `quest_details` WHERE `ID`=9605;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9605,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9605;

-- Call of Fire (9555)
DELETE FROM `quest_details` WHERE `ID`=9555;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9555,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9555;

-- Elekks Are Serious Business (9625)
DELETE FROM `quest_details` WHERE `ID`=9625;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9625,5,1,1,0,0,0,0,0,0);

-- Call of Fire (9461)
DELETE FROM `quest_details` WHERE `ID`=9461;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9461,1,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9461;

-- Call of Fire (9468)
UPDATE `quest_request_items` SET `EmoteOncomplete`=6 WHERE `ID`=9468;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9468;

-- Call of Fire (9464)
DELETE FROM `quest_details` WHERE `ID`=9464;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9464,1,1,1,0,0,0,0,0,0);

-- Call of Fire (9462)
DELETE FROM `quest_details` WHERE `ID`=9462;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9462,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9462;

-- Volatile Mutations (10302)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10302;

-- Call of Earth (9451)
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=9451;

-- Call of Earth (9449)
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=9449;

-- Shaman Training (9421)
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=9421;

-- Urgent Delivery! (9409)
UPDATE `quest_offer_reward` SET `Emote2`=6 WHERE `ID`=9409;
