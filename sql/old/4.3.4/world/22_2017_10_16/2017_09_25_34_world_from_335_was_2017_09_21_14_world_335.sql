/*
-- Emotes for Quest "The Balance of Nature (Part 1)"
DELETE FROM `quest_details` WHERE `ID`=456;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(456,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=456;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=456;

-- Emotes for Quest "The Balance of Nature (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=457;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(457,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=457;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=457;

-- Emotes for Quest "Etched Sigil"
DELETE FROM `quest_details` WHERE `ID`=3117;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3117,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=3117;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=3117;

-- Emotes for Quest "Simple Sigil"
DELETE FROM `quest_details` WHERE `ID`=3116;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3116,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=3116;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=3116;

-- Emotes for Quest "Encrypted Sigil"
DELETE FROM `quest_details` WHERE `ID`=3118;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3118,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=3118;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=3118;

-- Emotes for Quest "Hallowed Sigil"
DELETE FROM `quest_details` WHERE `ID`=3119;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3119,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=3119;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=3119;

-- Emotes for Quest "Verdant Sigil"
DELETE FROM `quest_details` WHERE `ID`=3120;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3120,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=3120;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=3120;

-- Emotes for Quest "The Woodland Protector"
DELETE FROM `quest_details` WHERE `ID`=458;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(458,1,1,1,0,0,0,0,0,0);

-- Emotes for Quest "A Good Friend"
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=4495;

-- Emotes for Quest "Iverron's Antidote (Part 1)"
DELETE FROM `quest_details` WHERE `ID`=3521;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3521,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=3521;

-- Emotes for Quest "Iverron's Antidote (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=3522;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3522,1,0,0,0,0,0,0,0,0);

-- Emotes for Quest "Webwood Venom"
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=916;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=916;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=916;

-- Emotes for Quest "Webwood Egg"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=917;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=917;

-- Emotes for Quest "Tenaron's Summons"
DELETE FROM `quest_details` WHERE `ID`=920;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(920,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=920;

-- Emotes for Quest "Crown of the Earth (Part 1)"
DELETE FROM `quest_details` WHERE `ID`=921;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(921,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=921;

-- Emotes for Quest "Crown of the Earth (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=928;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(928,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=928;

-- Emotes for Quest "Dolanaar Delivery"
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=2159;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2159;
*/
