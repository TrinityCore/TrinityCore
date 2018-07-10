-- Quest "Vahlarriel's Search"
DELETE FROM `quest_details` WHERE `ID`=1437;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1437,2,1,1,0,0,0,0,0,0);

-- Quest "Vahlarriel's Search (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1465;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=6, `Emote4`=1 WHERE `ID`=1465;

-- Quest "Vahlarriel's Search (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1438;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1438,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=20, `Emote2`=1, `Emote3`=1 WHERE `ID`=1438;

-- Quest "Search for Tyranis"
DELETE FROM `quest_details` WHERE `ID`=1439;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1439,1,5,1,274,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1439;
UPDATE `quest_offer_reward` SET `Emote1`=18, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=3000 WHERE `ID`=1439;

-- Quest "Return to Vahlarriel"
DELETE FROM `quest_details` WHERE `ID`=1440;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1440,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=1440;

-- Quest "Vyletongue Corruption"
DELETE FROM `quest_details` WHERE `ID`=7041;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7041,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=7041;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=7041;

-- Quest "Down the Scarlet Path"
DELETE FROM `quest_details` WHERE `ID`=261;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(261,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=261;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=261;

-- Quest "Down the Scarlet Path (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1052;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1052,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1052;

-- Quest "Centaur Bounty"
DELETE FROM `quest_details` WHERE `ID`=1387;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1387,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1387;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=1387;

-- Quest "Sceptre of Light"
UPDATE `quest_offer_reward` SET `RewardText`="The elusive Sceptre of Light! Your acquisition of it has removed a grave threat to the world. Well done, $C, well done." WHERE `ID`=5741;

-- Quest "Book of the Ancients"
UPDATE `quest_offer_reward` SET `RewardText`="The long lost Book of the Ancients! I will ensure this book is passed on to the high council. You've done well today, and for that you are to be thanked... as a hero should be thanked!" WHERE `ID`=6027;

-- Quest "Reclaimers' Business in Desolace"
DELETE FROM `quest_details` WHERE `ID`=1453;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1453,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1453;

-- Quest "Reagents for Reclaimers Inc."
DELETE FROM `quest_details` WHERE `ID`=1458;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1458,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1458;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1458;

-- Quest "Reagents for Reclaimers Inc. (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1459;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1459,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1459;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1459;

-- Quest "Reagents for Reclaimers Inc. (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1466;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1466,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID` IN (1466,1192);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1466;

-- Quest "Reagents for Reclaimers Inc. (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=1467;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1467,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1467;

-- Quest "The Karnitol Shipwreck"
DELETE FROM `quest_details` WHERE `ID`=1454;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1454,1,1,0,0,0,0,0,0,0);

-- Quest "The Karnitol Shipwreck (Part 2)"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6 WHERE `ID`=1455;

-- Quest "The Karnitol Shipwreck (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1456;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1456,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1456;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=1456;

-- Quest "The Karnitol Shipwreck (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=1457;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1457,1,11,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `Emote3`=1 WHERE `ID`=1457;

-- Quest "The Glowing Shard"
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=6981;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6981;

-- Quest "In Nightmares"
DELETE FROM `quest_details` WHERE `ID` IN (3370,3369);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3370,1,1,1,0,0,0,0,0,0),
(3369,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID` IN (3370,3369);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=1, `EmoteDelay3`=2000 WHERE `ID` IN (3370,3369);

-- Quest "Hemet Nesingwary Jr."
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5762;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=5762;
