-- Recover the Bones
DELETE FROM `quest_details` WHERE `ID`=10030;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10030,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=10030;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=10030;

-- Helping the Lost Find Their Way
DELETE FROM `quest_details` WHERE `ID`=10031;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10031,1,1,6,0,0,0,0,0,0);

-- Rather Be Fishin'
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10037;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10037;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=10037;

-- Brother Against Brother
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=10097;

-- Terokk's Legacy
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=10098;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10098;

-- Trouble at Auchindoun
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10177;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=10177;

-- Can't Stay Away
DELETE FROM `quest_details` WHERE `ID`=10180;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10180,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=10180;

-- Veil Skith: Darkstone of Terokk
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10839;

-- The Tomb of Lights
DELETE FROM `quest_details` WHERE `ID`=10840;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10840,1,0,0,0,0,0,0,0,0);

-- Vengeful Souls
DELETE FROM `quest_details` WHERE `ID`=10842;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10842,1,0,0,0,0,0,0,0,0);

-- The Eyes of Skettis
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10847;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10847;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10847;

-- Veil Rhaze: Unliving Evil
DELETE FROM `quest_details` WHERE `ID`=10848;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10848,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10848;

-- Seek Out Kirrik
DELETE FROM `quest_details` WHERE `ID`=10849;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10849,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10849;

-- Veil Lithic: Preemptive Strike
DELETE FROM `quest_details` WHERE `ID`=10861;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10861,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10861;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10861;

-- Taken in the Night
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=10873;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=10873;

-- Veil Shalas: Signal Fires
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10874;

-- The Skettis Offensive
DELETE FROM `quest_details` WHERE `ID`=10879;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10879,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10879;

-- Return to Shattrath
DELETE FROM `quest_details` WHERE `ID`=10889;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10889,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10889;

-- An Improper Burial
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10913;

-- A Hero Is Needed
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=10914;

-- The Fallen Exarch
DELETE FROM `quest_details` WHERE `ID`=10915;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10915,1,1,1,5,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10915;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=10915;

-- The Outcast's Plight
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10917;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10917;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10917;

-- More Feathers
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10918;

-- For the Fallen
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=10920;

-- Digging Through Bones
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=273 WHERE `ID`=10922;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=10922;

-- Fumping
DELETE FROM `quest_details` WHERE `ID`=10929;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10929,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=10929;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=5 WHERE `ID`=10929;

-- The Big Bone Worm
DELETE FROM `quest_details` WHERE `ID`=10930;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10930,5,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10930;

-- Mog'dorg the Wizened
DELETE FROM `quest_details` WHERE `ID`=10983;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10983,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10983;

-- Speak with the Ogre
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=10984;

-- Zorus the Judicator
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=11045;
