/*
-- Quest "The Greenwarden"
DELETE FROM `quest_details` WHERE `ID`=463;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(463,1,0,0,0,0,0,0,0,0);

-- Quest "Daily Delivery"
DELETE FROM `quest_details` WHERE `ID`=469;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(469,3,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=469;

-- Quest "In Search of The Excavation Team"
DELETE FROM `quest_details` WHERE `ID`=305;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(305,5,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=305;

-- Quest "In Search of The Excavation Team"
DELETE FROM `quest_details` WHERE `ID`=306;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(306,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=306;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `Emote3`=1 WHERE `ID`=306;

-- Quest "Uncovering the Past"
DELETE FROM `quest_details` WHERE `ID`=299;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(299,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=299;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=299;

-- Quest "Ormer's Revenge"
DELETE FROM `quest_details` WHERE `ID`=294;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(294,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=294;

-- Quest "Ormer's Revenge (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=295;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(295,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=295;

-- Quest "Ormer's Revenge (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=296;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(296,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=296;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=296;

-- Quest "Digging Through the Ooze"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=470;

-- Quest "The Third Fleet"
DELETE FROM `quest_details` WHERE `ID`=288;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(288,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=288;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=288;

-- Quest "The Cursed Crew"
DELETE FROM `quest_details` WHERE `ID`=289;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(289,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=20, `EmoteOnComplete`=20 WHERE `ID`=296;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=289;

-- Quest "Lifting the Curse"
DELETE FROM `quest_details` WHERE `ID`=290;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(290,1,1,0,0,0,0,0,0,0);

-- Quest "The Eye of Paleth"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=292;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=292;

-- Quest "Cleansing the Eye"
DELETE FROM `quest_details` WHERE `ID`=293;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(293,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=293;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=293;

-- Quest "Young Crocolisk Skins"
DELETE FROM `quest_details` WHERE `ID`=484;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(484,2,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=484;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=484;

-- Quest "Apprentice's Duties"
DELETE FROM `quest_details` WHERE `ID`=471;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(471,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=18, `EmoteOnComplete`=18 WHERE `ID`=471;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=11 WHERE `ID`=471;

-- Quest "Apprentice's Duties"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=279;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=279;

-- Quest "Return the Statuette"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=286;

-- Quest "Report to Captain Stoutfist"
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=473;

-- Quest "War Banners"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=464;

-- Quest "Defeat Nek'rosh"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=474;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=474;

-- Quest "Fall of Dun Modr"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=472;

-- Quest "A Grim Task"
DELETE FROM `quest_details` WHERE `ID`=304;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(304,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=304;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=304;

-- Quest "The Dark Iron War"
DELETE FROM `quest_details` WHERE `ID`=303;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(303,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=303;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=303;

-- Quest "The Fury Runs Deep"
DELETE FROM `quest_details` WHERE `ID`=378;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(378,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=378;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=378;

-- Quest "The Thandol Span"
DELETE FROM `quest_details` WHERE `ID`=631;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(631,5,1,6,0,0,0,0,0,0);

-- Quest "The Thandol Span (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=632;
UPDATE `quest_offer_reward` SET `Emote1`=18 WHERE `ID`=632;

-- Quest "The Thandol Span (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=633;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(633,5,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=633;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=633;

-- Quest "Plea To The Alliance"
DELETE FROM `quest_details` WHERE `ID`=634;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(634,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=634;
*/
