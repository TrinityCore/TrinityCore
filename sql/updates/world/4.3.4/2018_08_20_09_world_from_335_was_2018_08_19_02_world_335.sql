/*
--
-- Quest "To Steal From Thieves"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=1164;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=1164;

-- Quest "The Hammer May Fall"
DELETE FROM `quest_details` WHERE `ID`=676;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(676,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=676;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=676;

-- Quest "Call to Arms"
DELETE FROM `quest_details` WHERE `ID`=677;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(677,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=677;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=677;

-- Quest "Call to Arms (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=678;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=678;

-- Quest "Call to Arms (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=679;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(679,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=679;

-- Quest "Trollbane"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=638;

-- Quest "Sigil of Strom"
DELETE FROM `quest_details` WHERE `ID`=639;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(639,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=639;

-- Quest "The Broken Sigil"
DELETE FROM `quest_details` WHERE `ID`=640;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(640,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=66, `EmoteOnComplete`=66 WHERE `ID`=640;

-- Quest "Sigil of Thoradin"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=641;

-- Quest "Sigil of Arathor"
DELETE FROM `quest_details` WHERE `ID`=643;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(643,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=643;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=643;

-- Quest "Sigil of Trollbane"
DELETE FROM `quest_details` WHERE `ID`=644;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(644,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=644;

-- Quest "Trol'kalar"
DELETE FROM `quest_details` WHERE `ID`=645;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(645,6,1,0,0,0,0,0,0,0);

-- Quest "Trol'kalar (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=646;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=646;

-- Quest "Hammerfall"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=655;

-- Quest "Raising Spirits"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=672;

-- Quest "Raising Spirits (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=675;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(675,61,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=675;

-- Quest "Guile of the Raptor (Part 1)"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=701;

-- Quest "Guile of the Raptor (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=847;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(847,23,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=847;

-- Quests "Foul Magics"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID` IN (671, 672, 673, 674, 701, 702);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=673;

-- Quest "Horde Trauma"
DELETE FROM `quest_details` WHERE `ID`=6623;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6623,1,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6623;

-- Quest "Triage"
DELETE FROM `quest_details` WHERE `ID`=6622;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6622,1,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=6622;

-- Quest "The Real Threat"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=680;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=680;

-- Quest "Myzrael's Allies"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID` IN (688,653);

-- Quest "Theldurin the Lost"
DELETE FROM `quest_details` WHERE `ID`=687;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(687,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3, `Emote2`=5, `Emote3`=1 WHERE `ID`=687;

-- Quest "The Lost Fragments"
DELETE FROM `quest_details` WHERE `ID`=692;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(692,6,5,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=692;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=692;

-- Quest "Summoning the Princess"
DELETE FROM `quest_details` WHERE `ID`=656;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(656,1,5,6,1,0,0,0,0,0);

-- Quest "Elemental Leatherworking"
DELETE FROM `quest_details` WHERE `ID`=5146;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5146,1,25,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=5146;
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1 WHERE `ID`=5146;

-- Quest "The Battle for Arathi Basin!"
DELETE FROM `quest_details` WHERE `ID` IN (8120,8169,8170,8171,8105,8166,8167,8168);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8120,1,0,0,0,0,0,0,0,0),
(8169,1,0,0,0,0,0,0,0,0),
(8170,1,0,0,0,0,0,0,0,0),
(8171,1,0,0,0,0,0,0,0,0),
(8105,1,0,0,0,0,0,0,0,0),
(8166,1,0,0,0,0,0,0,0,0),
(8167,1,0,0,0,0,0,0,0,0),
(8168,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID` IN (8120,8169,8170,8171,8105,8166,8167,8168);

-- Quest "Take Four Bases" / "Take Five Bases"
DELETE FROM `quest_details` WHERE `ID` IN (8121,8122);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8121,1,0,0,0,0,0,0,0,0),
(8122,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID` IN (8121,8122);

-- Quest "Control Four Bases" / "Control Five Bases"
DELETE FROM `quest_details` WHERE `ID` IN (8114,8115);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8114,1,0,0,0,0,0,0,0,0),
(8115,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID` IN (8114,8115);

-- Quest "Arathor Basic Care Package"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID` IN (8260,8261,8262,8263,8264,8265);

-- Quest "Arathi Basin Resources!"
DELETE FROM `quest_details` WHERE `ID` IN (8080,8154,8155,8156,8297);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8080,1,0,0,0,0,0,0,0,0),
(8154,1,0,0,0,0,0,0,0,0),
(8155,1,0,0,0,0,0,0,0,0),
(8156,1,0,0,0,0,0,0,0,0),
(8297,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8080,8154,8155,8156,8297);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID` IN (8080,8154,8155,8156,8297);

-- Quest "Wanted!  Marez Cowl"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=684;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=684;

-- Quest "Wanted!  Otto and Falconcrest"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=685;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=685;

-- Quest "Northfold Manor"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=681;

-- Quest "Stromgarde Badges"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=682;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=682;

-- Quest "Worth Its Weight in Gold"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=691;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=691;

-- Quest "Wand over Fist"
DELETE FROM `quest_details` WHERE `ID`=693;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(693,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=693;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=693;

-- Quest "Trelane's Defenses"
DELETE FROM `quest_details` WHERE `ID`=694;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(694,6,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=694;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=694;

-- Quest "Attack on the Tower"
DELETE FROM `quest_details` WHERE `ID`=696;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(696,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=696;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=696;

-- Quest "Malin's Request"
DELETE FROM `quest_details` WHERE `ID`=697;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(697,1,2,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=697;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=2, `EmoteDelay1`=1000 WHERE `ID`=697;

-- Quest "Land Ho!"
UPDATE `quest_offer_reward` SET `Emote1`=3, `Emote2`=1, `Emote3`=1 WHERE `ID`=663;

-- Quest "Sunken Treasure"
DELETE FROM `quest_details` WHERE `ID`=665;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(665,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=665;

-- Quest "Sunken Treasure (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=666;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(666,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=666;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=666;

-- Quest "Sunken Treasure (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=668;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(668,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=668;
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=668;

-- Quest "Sunken Treasure (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=669;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(669,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=669;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=669;

-- Quest "Sunken Treasure (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=670;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(670,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=670;

-- Quest "Drowned Sorrows"
DELETE FROM `quest_details` WHERE `ID`=664;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(664,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=664;

-- Quest "Death From Below"
DELETE FROM `quest_details` WHERE `ID`=667;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(667,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=667;
*/
