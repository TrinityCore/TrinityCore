-- Quest "Look To The Stars"
DELETE FROM `quest_details` WHERE `ID`=174;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(174,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=174;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=174;

-- Quest "Look To The Stars (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=175;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(175,1,0,0,0,0,0,0,0,0);

-- Quest "Look To The Stars (Part 3)"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=177;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=177;

-- Quest "Look To The Stars (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=181;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(181,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=181;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=181;

-- Quest "The Totem of Infliction"
DELETE FROM `quest_details` WHERE `ID`=101;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(101,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=101;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=101;

-- Quest "The Legend of Stalvan"
DELETE FROM `quest_details` WHERE `ID`=66;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(66,5,1,1,25,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=66;

-- Quest "The Legend of Stalvan (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=67;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(67,6,1,5,1,0,0,0,0,0);

-- Quest "The Legend of Stalvan (Part 3)"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=68;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=68;

-- Quest "The Legend of Stalvan (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=69;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(69,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=69;

-- Quest "The Legend of Stalvan (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=70;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(70,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=70;
UPDATE `quest_offer_reward` SET `Emote1`=14 WHERE `ID`=70;

-- Quest "The Legend of Stalvan (Part 6)"
DELETE FROM `quest_details` WHERE `ID`=72;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(72,1,1,0,0,0,0,0,0,0);

-- Quest "The Legend of Stalvan (Part 7)"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=74;

-- Quest "The Legend of Stalvan (Part 8)"
DELETE FROM `quest_details` WHERE `ID`=75;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(75,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=75;

-- Quest "The Legend of Stalvan (Part 9)"
DELETE FROM `quest_details` WHERE `ID`=78;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(78,1,25,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=78;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=78;

-- Quest "The Legend of Stalvan (Part 10)"
DELETE FROM `quest_details` WHERE `ID`=79;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(79,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=79;

-- Quest "The Legend of Stalvan (Part 11)"
DELETE FROM `quest_details` WHERE `ID`=80;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(80,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=80;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=80;

-- Quest "The Legend of Stalvan (Part 12)"
DELETE FROM `quest_details` WHERE `ID`=97;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(97,25,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=97;

-- Quest "The Legend of Stalvan (Part 13)"
DELETE FROM `quest_details` WHERE `ID`=98;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(98,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=98;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=16 WHERE `ID`=98;

-- Quest "Seasoned Wolf Kabobs"
DELETE FROM `quest_details` WHERE `ID`=90;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(90,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=90;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=90;

-- Quest "The Night Watch"
DELETE FROM `quest_details` WHERE `ID`=56;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(56,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=56;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=56;

-- Quest "The Night Watch (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=57;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(57,5,25,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=57;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=57;

-- Quest "The Night Watch (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=58;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(58,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=58;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=58;

-- Quest "Crime and Punishment"
DELETE FROM `quest_details` WHERE `ID`=377;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(377,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=377;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=377;

-- Quest "Worgen in the Woods (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=223;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(223,66,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=223;

-- Quest "The Hermit"
DELETE FROM `quest_details` WHERE `ID`=165;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(165,1,0,0,0,0,0,0,0,0);

-- Quest "Supplies from Darkshire"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=148;

-- Quest "Ghost Hair Thread"
DELETE FROM `quest_details` WHERE `ID`=149;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(149,1,1,0,0,0,0,0,0,0);

-- Quest "Return the Comb"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=154;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=154;

-- Quest "Deliver the Thread"
DELETE FROM `quest_details` WHERE `ID`=157;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(157,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=157;

-- Quest "Gather Rot Blossoms"
DELETE FROM `quest_details` WHERE `ID`=156;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(156,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=156;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=156;

-- Quest "Juice Delivery"
DELETE FROM `quest_details` WHERE `ID`=159;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(159,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=159;

-- Quest "Ghoulish Effigy"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=133;

-- Quest "Ogre Thieves"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=134;

-- Quest "Note to the Mayor"
DELETE FROM `quest_details` WHERE `ID`=160;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(160,11,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=160;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=160;

-- Quest "Translate Abercrombie's Note"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=251;

-- Quest "Translation to Ello"
DELETE FROM `quest_details` WHERE `ID`=252;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(252,5,0,0,0,0,0,0,0,0);

-- Quest "Bride of the Embalmer"
DELETE FROM `quest_details` WHERE `ID`=253;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(253,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=253;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=253;

-- Quest "Wolves at Our Heels"
DELETE FROM `quest_details` WHERE `ID`=226;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(226,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=226;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=226;

-- Quest "Deliveries to Sven"
DELETE FROM `quest_details` WHERE `ID`=164;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(164,6,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=164;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=164;

-- Quest "Sven's Revenge"
DELETE FROM `quest_details` WHERE `ID`=95;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(95,1,1,0,0,0,0,0,0,0);

-- Quest "Sven's Revenge"
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=230;

-- Quest "The Shadowy Figure"
DELETE FROM `quest_details` WHERE `ID`=262;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(262,1,20,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=262;

-- Quest "The Shadowy Search Continues"
DELETE FROM `quest_details` WHERE `ID`=265;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(265,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=265;

-- Quest "Inquire at the Inn"
DELETE FROM `quest_details` WHERE `ID`=266;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(266,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=266;

-- Quest "Finding the Shadowy Figure"
DELETE FROM `quest_details` WHERE `ID`=453;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(453,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=453;

-- Quest "Return to Sven"
DELETE FROM `quest_details` WHERE `ID`=268;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(268,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=268;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=268;

-- Quest "Proving Your Worth"
DELETE FROM `quest_details` WHERE `ID`=323;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(323,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=323;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=323;

-- Quest "Seeking Wisdom"
DELETE FROM `quest_details` WHERE `ID`=269;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(269,1,1,0,0,0,0,0,0,0);

-- Quest "The Doomed Fleet"
DELETE FROM `quest_details` WHERE `ID`=270;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(270,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=270;

-- Quest "Lightforge Iron"
DELETE FROM `quest_details` WHERE `ID`=321;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(321,1,1,0,0,0,0,0,0,0);

-- Quest "The Lost Ingots"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=324;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=324;

-- Quest "Blessed Arm"
DELETE FROM `quest_details` WHERE `ID`=322;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(322,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=322;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=322;

-- Quest "Armed and Ready"
DELETE FROM `quest_details` WHERE `ID`=325;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(325,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=325;

-- Quest "Morbent Fel"
DELETE FROM `quest_details` WHERE `ID`=55;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(55,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=55;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=55;

-- Quest "The Weathered Grave"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=225;

-- Quest "The Weathered Grave"
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=6, `Emote3`=1, `Emote4`=1 WHERE `ID`=227;

-- Quest "Mor'Ladim"
DELETE FROM `quest_details` WHERE `ID`=228;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(228,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=228;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=66 WHERE `ID`=228;

-- Quest "The Daughter Who Lived"
DELETE FROM `quest_details` WHERE `ID`=229;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(229,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=229;

-- Quest "A Daughter's Love"
DELETE FROM `quest_details` WHERE `ID`=231;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(231,1,2,0,0,0,1000,0,0,0);

-- Quest "Raven Hill"
DELETE FROM `quest_details` WHERE `ID`=163;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(163,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=430 WHERE `ID`=163;

-- Quest "Jitters' Growling Gut"
DELETE FROM `quest_details` WHERE `ID`=5;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=5;

-- Quest "Dusky Crab Cakes"
DELETE FROM `quest_details` WHERE `ID`=93;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(93,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=93;
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1 WHERE `ID`=93;

-- Quest "Return to Jitters"
DELETE FROM `quest_details` WHERE `ID`=240;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(240,4,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=240;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=240;
