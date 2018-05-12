/*
-- 
-- Quest "Forces of Jaedenar"
DELETE FROM `quest_details` WHERE `ID`=5155;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5155,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=5155;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1 WHERE `ID`=5155;

-- Quest "Collection of the Corrupt Water"
DELETE FROM `quest_details` WHERE `ID`=5157;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5157,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5157;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=5157;

-- Quest "Seeking Spiritual Aid"
DELETE FROM `quest_details` WHERE `ID`=5158;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5158,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=5158;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=5158;

-- Quest "Cleansed Water Returns to Felwood"
DELETE FROM `quest_details` WHERE `ID`=5159;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5159,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=5159;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=5159;

-- Quest "Dousing the Flames of Protection"
DELETE FROM `quest_details` WHERE `ID`=5165;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5165,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5165;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=5165;

-- Quest "A Final Blow"
DELETE FROM `quest_details` WHERE `ID`=5242;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5242,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5242;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2 WHERE `ID`=5242;

-- Quest "Verifying the Corruption"
DELETE FROM `quest_details` WHERE `ID`=5156;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5156,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5156;

-- Quest "Cleansing Felwood"
DELETE FROM `quest_details` WHERE `ID` IN (4101,4102);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4101,1,0,0,0,0,0,0,0,0),
(4102,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID` IN (4101,4102);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (4101,4102);

-- Quest "Salve via Hunting"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID` IN (4103,4108,5882,5887);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (4103,4108,5882,5887);

-- Quest "A Strange One"
DELETE FROM `quest_details` WHERE `ID`=6605;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6605,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=6605;

-- Quest "Well of Corruption"
DELETE FROM `quest_details` WHERE `ID`=4505;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4505,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=4505;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4505;

-- Quest "Corrupted Sabers"
DELETE FROM `quest_details` WHERE `ID`=4506;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4506,1,11,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=4506;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=11 WHERE `ID`=4506;

-- Quest "A Husband's Last Battle"
DELETE FROM `quest_details` WHERE `ID`=6162;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6162,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=6162;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=6162;

-- Quest "Timbermaw Ally"
DELETE FROM `quest_details` WHERE `ID`=8460;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8460,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8460;

-- Quest "Speak to Nafien"
DELETE FROM `quest_details` WHERE `ID`=8462;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8462,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8462;

-- Quest "Feathers for Grazle"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=0 WHERE `ID`=8466;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8466;

-- Quest "Feathers for Nafien"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=0 WHERE `ID`=8467;

-- Quest "Wild Guardians"
DELETE FROM `quest_details` WHERE `ID`=4521;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4521,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=4521;

-- Quest "Wild Guardians (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=4741;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4741,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4741;

-- Quest "Wild Guardians (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=4721;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4721,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=4721;

-- Quest "The Corruption of the Jadefire"
DELETE FROM `quest_details` WHERE `ID`=4421;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4421,1,2,1,0,0,0,0,0,0);

-- Quest "Further Corruption"
DELETE FROM `quest_details` WHERE `ID`=4906;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4906,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=20 WHERE `ID`=4906;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=4906;

-- Quest "Flute of Xavaric"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=939;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=939;

-- Quest "Felbound Ancients"
DELETE FROM `quest_details` WHERE `ID`=4441;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4441,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4441;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=4441;

-- Quest "Purified!"
DELETE FROM `quest_details` WHERE `ID`=4442;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4442,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=4442;

-- Quest "Ancient Spirit"
UPDATE `quest_offer_reward` SET `Emote1`=2, `RewardText`="Yes, $N. Felwood has been through much hardship. Thank you for what you have done.$B$BOne day, we may be able to reclaim Felwood from the corruption; every kind deed helps." WHERE `ID`=4261;

-- Quest "A Strange Red Key"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5202;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=5202;

-- Quest "Rescue From Jaedenar"
DELETE FROM `quest_details` WHERE `ID`=5203;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5203,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=5203;

-- Quest "Retribution of the Light"
DELETE FROM `quest_details` WHERE `ID`=5204;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5204,1,1,1,0,0,0,0,0,0);

-- Quest "The Remains of Trey Lightforge"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5385;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=5385;

-- Quest "An Imp's Request"
DELETE FROM `quest_details` WHERE `ID`=8419;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8419,1,0,0,0,0,0,0,0,0);

-- Quest "What Niby Commands"
DELETE FROM `quest_details` WHERE `ID`=7601;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7601,1,1,1,1,0,0,0,0,0);

-- Quest "Kroshius' Infernal Core"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7603;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=7603;

-- Quest "Sacred Cloth"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6032;

-- Quest "The Root of All Evil"
DELETE FROM `quest_details` WHERE `ID`=8481;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8481,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=8481;

-- Quest "The Brokering of Peace"
DELETE FROM `quest_details` WHERE `ID` IN (8484,8485);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8484,1,1,0,0,0,0,0,0,0),
(8485,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID` IN (8484,8485);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID` IN (8484,8485);
*/
