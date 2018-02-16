/*
-- Quest "A Threat in Feralas"
DELETE FROM `quest_details` WHERE `ID`=2981;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2981,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2981;

-- Quest "The Ogres of Feralas"
DELETE FROM `quest_details` WHERE `ID`=2975;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2975,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2975;

-- Quest "The Ogres of Feralas (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=2980;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2980,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2980;

-- Quest "The Gordunni Scroll"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2978;

-- Quest "Dark Ceremony"
DELETE FROM `quest_details` WHERE `ID`=2979;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2979,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2979;

-- Quest "The Gordunni Orb"
DELETE FROM `quest_details` WHERE `ID`=3002;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3002,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=3002;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=3002;

-- Quest "A New Cloak's Sheen"
DELETE FROM `quest_details` WHERE `ID`=2973;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2973,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=2973;
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=2973;

-- Quest "A Grim Discovery"
DELETE FROM `quest_details` WHERE `ID`=2974;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2974,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=2974;

-- Quest "A Grim Discovery (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=2976;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2976,5,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=2976;

-- Quest "A Strange Request"
DELETE FROM `quest_details` WHERE `ID`=3121;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3121,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3121;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3121;

-- Quest "Return to Witch Doctor Uzer'i"
DELETE FROM `quest_details` WHERE `ID`=3122;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3122,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3122;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3122;

-- Quest "Natural Materials"
DELETE FROM `quest_details` WHERE `ID`=3128;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3128,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3128;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=3128;

-- Quest "War on the Woodpaw"
DELETE FROM `quest_details` WHERE `ID`=2862;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2862,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=2862;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=2862;

-- Quest "Alpha Strike"
DELETE FROM `quest_details` WHERE `ID`=2863;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2863,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=2863;

-- Quest "Woodpaw Investigation"
DELETE FROM `quest_details` WHERE `ID`=2902;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2902,1,1,0,0,0,0,0,0,0);

-- Quest "The Battle Plans"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=2903;

-- Quest "Stinglasher"
DELETE FROM `quest_details` WHERE `ID`=7731;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7731,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=7731;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7731;

-- Quest "Zukk'ash Infestation"
DELETE FROM `quest_details` WHERE `ID`=7730;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7730,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=7730;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=7730;

-- Quest "Zukk'ash Report"
DELETE FROM `quest_details` WHERE `ID`=7732;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7732,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=7732;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7732;

-- Quest "The Mark of Quality"
DELETE FROM `quest_details` WHERE `ID`=2822;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2822,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2822;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=2822;

-- Quest "Gordunni Cobalt"
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=2987;

-- Quest "Testing the Vessel"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3123;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3123;

-- Quest "Hippogryph Muisek"
DELETE FROM `quest_details` WHERE `ID`=3124;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3124,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3124;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3124;

-- Quest "Faerie Dragon Muisek"
DELETE FROM `quest_details` WHERE `ID`=3125;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3125,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3125;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3125;

-- Quest "Treant Muisek"
DELETE FROM `quest_details` WHERE `ID`=3126;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3126,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3126;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3126;

-- Quest "Mountain Giant Muisek"
DELETE FROM `quest_details` WHERE `ID`=3127;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3127,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3127;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4 WHERE `ID`=3127;

-- Quest "Weapons of Spirit"
DELETE FROM `quest_details` WHERE `ID`=3129;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3129,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4 WHERE `ID`=3129;

-- Quest "Dark Heart"
DELETE FROM `quest_details` WHERE `ID`=3062;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3062,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3062;
UPDATE `quest_offer_reward` SET `Emote1`=2, `EmoteDelay1`=1000 WHERE `ID`=3062;

-- Quest "Vengeance on the Northspring"
DELETE FROM `quest_details` WHERE `ID`=3063;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3063,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=3063;

-- Quest "The Strength of Corruption"
DELETE FROM `quest_details` WHERE `ID`=4120;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4120,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4120;

-- Quest "Improved Quality"
DELETE FROM `quest_details` WHERE `ID`=7734;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7734,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=7734;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7734;

-- Quest "Perfect Yeti Hide"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=7738;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7738;

-- Quest "Zapped Giants"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7003;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=7003;

-- Quest "Again With the Zapped Giants"
DELETE FROM `quest_details` WHERE `ID`=7725;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7725,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7725;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=7725;

-- Quest "Fuel for the Zapping"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7721;

-- Quest "Refuel for the Zapping"
DELETE FROM `quest_details` WHERE `ID`=7726;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7726,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7726;

-- Quest "Elven Legends"
DELETE FROM `quest_details` WHERE `ID`=7481;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7481,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6 WHERE `ID`=7481;
*/
