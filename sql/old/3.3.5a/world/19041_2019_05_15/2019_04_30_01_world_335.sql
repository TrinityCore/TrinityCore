-- 
-- Quest "Taking Back Silithus"
DELETE FROM `quest_details` WHERE `ID` IN (8275,8276);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8275,5,0,0,0,0,0,0,0,0),
(8276,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID` IN (8275,8276);

-- Quest "Securing the Supply Lines"
DELETE FROM `quest_details` WHERE `ID` IN (8280,8281);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=8280;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=8280;

-- Quest "Stepping Up Security"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=8281;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=8281;

-- Quest "Deadly Desert Venom"
DELETE FROM `quest_details` WHERE `ID`=8277;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8277,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=8277;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8277;

-- Quest "Noggle's Last Hope"
DELETE FROM `quest_details` WHERE `ID`=8278;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8278,274,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=8278;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=8278;

-- Quest "What Tomorrow Brings"
DELETE FROM `quest_details` WHERE `ID`=8286;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8286,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8286;

-- Quest "Only One May Rise"
DELETE FROM `quest_details` WHERE `ID`=8288;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8288,5,25,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=8288;
UPDATE `quest_offer_reward` SET `Emote1`=6, `RewardText`="Could you be the first to earn favor among the Bronze Flight in a thousand years?" WHERE `ID`=8288;

-- Quest "The Path of the Righteous"
DELETE FROM `quest_details` WHERE `ID`=8301;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8301,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1, `CompletionText`="There is much history rooted in their distrust of the mortal races; but alas, such is a tale better left for the Brood to tell when the time is right." WHERE `ID`=8301;
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`="You are not alone, hero. I will now grant you the ability to deputize others to help you in your quest. If you are to be the champion of your people, you will need assistance in your tasks and duties." WHERE `ID`=8301;

-- Quest "The Hand of the Righteous"
DELETE FROM `quest_details` WHERE `ID`=8302;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8302,25,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1, `CompletionText`="Perhaps one day the whole of Cenarion Hold will be working under your command." WHERE `ID`=8302;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=8302;

-- Quest "Anachronos"
DELETE FROM `quest_details` WHERE `ID`=8303;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8303,2,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8303;

-- Quest "Long Forgotten Memories"
DELETE FROM `quest_details` WHERE `ID`=8305;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8305,1,0,0,0,0,0,0,0,0);

-- Quest "Kris of Unspoken Names"
DELETE FROM `quest_details` WHERE `ID`=8710;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8710,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8710;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=8710;

-- Quest "Ring of Unspoken Names"
DELETE FROM `quest_details` WHERE `ID`=8702;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8702,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8702;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8702;

-- Quest "A Humble Offering"
DELETE FROM `quest_details` WHERE `ID`=9248;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9248,2,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6, `CompletionText`="Fandu-dath-belore? Oh, pardon me, $N. I did not recognize you. Have you the scepter?" WHERE `ID`=9248;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=9248;

-- Quest "Shroud of Unspoken Names"
DELETE FROM `quest_details` WHERE `ID`=8694;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8694,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8694;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=8694;

-- Quest "The Perfect Poison"
DELETE FROM `quest_details` WHERE `ID`=9023;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9023,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `EmoteOnComplete`=25 WHERE `ID`=9023;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9023;

-- Quest "Noggle's Lost Satchel"
DELETE FROM `quest_details` WHERE `ID`=8282;

-- Quest "Wanted - Deathclasp, Terror of the Sands"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `EmoteOnComplete`=25 WHERE `ID`=8283;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=8283;

-- Quest "Secret Communication"
DELETE FROM `quest_details` WHERE `ID`=8318;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8318,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8318;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=8318;

-- Quest "Encrypted Twilight Texts"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=8319;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8319;

-- Quest "Abyssal Contacts"
DELETE FROM `quest_details` WHERE `ID`=8361;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8361,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8361;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=8361;

-- Quest "Abyssal Crests"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=8362;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=8362;

-- Quest "Twilight Geolords"
DELETE FROM `quest_details` WHERE `ID`=8320;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8320,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8320;

-- Quest "Vyral the Vile"
DELETE FROM `quest_details` WHERE `ID`=8321;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8321,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8321;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8321;

-- Quest "Aurel Goldleaf"
DELETE FROM `quest_details` WHERE `ID`=8331;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8331,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=8331;

-- Quest "Dukes of the Council"
DELETE FROM `quest_details` WHERE `ID`=8332;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8332,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8332;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8332;

-- Quest "Bor Wildmane"
DELETE FROM `quest_details` WHERE `ID`=8349;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8349,1,2,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8349;

-- Quest "Medallion of Station"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=8333;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=8333;

-- Quest "Signet of the Dukes"
DELETE FROM `quest_details` WHERE `ID`=8348;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8348,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8348;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=8348;

-- Quest "Abyssal Signets"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=8363;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=8363;

-- Quest "Goldleaf's Discovery"
DELETE FROM `quest_details` WHERE `ID`=8343;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8343,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8343;

-- Quest "Lords of the Council"
DELETE FROM `quest_details` WHERE `ID`=8341;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8341,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8341;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8341;

-- Quest "Bor Wishes to Speak"
DELETE FROM `quest_details` WHERE `ID`=8351;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8351,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=8351;

-- Quest "Twilight Ring of Lordship"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=8342;

-- Quest "Scepter of the Council"
DELETE FROM `quest_details` WHERE `ID`=8352;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8352,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8352;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=8352;

-- Quest "Abyssal Scepters"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=8364;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=8364;

-- Quest "Field Duty"
DELETE FROM `quest_details` WHERE `ID`=8507;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8507,3,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=8507;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=8507;

-- Quest "Field Duty"
DELETE FROM `quest_details` WHERE `ID`=8731;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8731,3,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=8731;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=8731;

-- Quest "Field Duty Papers"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8508, 8732);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=25 WHERE `ID` IN (8508, 8732);

-- Quest "Cloak of Unending Life"
DELETE FROM `quest_details` WHERE `ID` IN (8557,8689,8690,8691,8692,8693,8694,8695,8696);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8557,1,1,2,0,0,0,0,0,0),
(8689,1,1,2,0,0,0,0,0,0),
(8690,1,1,2,0,0,0,0,0,0),
(8691,1,1,2,0,0,0,0,0,0),
(8692,1,1,2,0,0,0,0,0,0),
(8693,1,1,2,0,0,0,0,0,0),
(8694,1,1,2,0,0,0,0,0,0),
(8695,1,1,2,0,0,0,0,0,0),
(8696,1,1,2,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8557,8689,8690,8691,8692,8693,8694,8695,8696);
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=2 WHERE `ID` IN (8557,8689,8690,8691,8692,8693,8694,8695,8696);

-- Quest "Band of Unending Life"
DELETE FROM `quest_details` WHERE `ID` IN (8556,8697,8698,8699,8700,8701,8702,8703,8704);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8556,1,1,1,0,0,0,0,0,0),
(8697,1,1,1,0,0,0,0,0,0),
(8698,1,1,1,0,0,0,0,0,0),
(8699,1,1,1,0,0,0,0,0,0),
(8700,1,1,1,0,0,0,0,0,0),
(8701,1,1,1,0,0,0,0,0,0),
(8702,1,1,1,0,0,0,0,0,0),
(8703,1,1,1,0,0,0,0,0,0),
(8704,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8556,8697,8698,8699,8700,8701,8702,8703,8704);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (8556,8697,8698,8699,8700,8701,8702,8703,8704);

-- Quest "Mace of Unending Life"
DELETE FROM `quest_details` WHERE `ID` IN (8558,8705,8706,8707,8708,8709,8710,8711,8712);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8558,1,1,25,0,0,0,0,0,0),
(8705,1,1,25,0,0,0,0,0,0),
(8706,1,1,25,0,0,0,0,0,0),
(8707,1,1,25,0,0,0,0,0,0),
(8708,1,1,25,0,0,0,0,0,0),
(8709,1,1,25,0,0,0,0,0,0),
(8710,1,1,25,0,0,0,0,0,0),
(8711,1,1,25,0,0,0,0,0,0),
(8712,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8558,8705,8706,8707,8708,8709,8710,8711,8712);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID` IN (8558,8705,8706,8707,8708,8709,8710,8711,8712);

-- Quest "The Twilight Mystery"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=8284;

-- Quest "The Deserter"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=8285;

-- Quest "The Twilight Lexicon"
DELETE FROM `quest_details` WHERE `ID`=8279;

-- Quest "A Terrible Purpose"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=8287;

-- Quest "True Believers"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=8323;

-- Quest "Dearest Natalia"
DELETE FROM `quest_details` WHERE `ID`=8304;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8304,1,1,1,6,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6 WHERE `ID`=8304;

-- Quest "Into The Maw of Madness"
DELETE FROM `quest_details` WHERE `ID`=8306;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8306,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=8306;

-- Quest "Cenarion Battlegear"
DELETE FROM `quest_details` WHERE `ID`=8800;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8800,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=8800;

-- Quest "Volunteer's Battlegear" / "Veteran's Battlegear" / "Champion's Battlegear" / "Stalwart's Battlegear"
DELETE FROM `quest_details` WHERE `ID` IN (8548,8572,8573,8574);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8548,1,1,0,0,0,0,0,0,0),
(8572,1,1,0,0,0,0,0,0,0),
(8573,1,1,0,0,0,0,0,0,0),
(8574,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID` IN (8548,8572,8573,8574);

-- Quest "The Charge of the Dragonflights"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=8555;

-- Quest "Glyph Chasing"
DELETE FROM `quest_details` WHERE `ID`=8309;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8309,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=8309;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=8309;

-- Quest "Breaking the Code"
DELETE FROM `quest_details` WHERE `ID`=8310;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8310,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `EmoteOnComplete`=25 WHERE `ID`=8310;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=8310;

-- Quest "Unraveling the Mystery"
DELETE FROM `quest_details` WHERE `ID`=8314;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8314,5,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8314;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=8314;

-- Quest "Allegiance to Cenarion Circle"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9338;

-- Quest "Report to Marshal Bluewall"
DELETE FROM `quest_details` WHERE `ID`=9415;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9415,6,5,25,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9415;

-- Quest "Report to General Kirika"
DELETE FROM `quest_details` WHERE `ID`=9416;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9416,25,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=25 WHERE `ID`=9416;

-- Quest "Scouring the Desert"
DELETE FROM `quest_details` WHERE `ID`=9419;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9419,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9419;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=9419;

-- Quest "Scouring the Desert"
DELETE FROM `quest_details` WHERE `ID`=9422;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9422,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9422;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=9422;

-- Quest "Target: Hive'Ashi Defenders"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID` IN (8501,8502,8773,8539,8772,8770,8771,8774,8777,8776,8775,8687);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID` IN (8501,8502,8773,8539,8772,8770,8771,8774,8777,8776,8775,8687);

-- Quest "Bandages for the Field"
UPDATE `quest_request_items` SET `CompletionText`="You have something for me, $n?", `EmoteOnComplete`=0 WHERE `ID` IN (8782,8808,8496,8810,8783,8809,8829);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID` IN (8782,8808,8496,8810,8783,8809,8829);

-- Quest "Desert Survival Kits"
UPDATE `quest_request_items` SET `CompletionText`="You have something for me, $n?", `EmoteOnComplete`=0 WHERE `ID` IN (8497,8804);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID` IN (8497,8804);

-- Quest "Boots for the Guard"
UPDATE `quest_request_items` SET `CompletionText`="You have something for me, $n?", `EmoteOnComplete`=0 WHERE `ID` IN (8540,8805,8541,8806,8786,8781,8780,8787);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID` IN (8540,8805,8541,8806,8786,8781,8780,8787);

-- Quest "The Ironforge Brigade Needs Explosives!" / "The Orgrimmar Legion Needs Mojo!"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID` IN (8778,8785);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID` IN (8778,8785);

-- Quest "Scrying Materials"
UPDATE `quest_request_items` SET `CompletionText`="You have something for me, $n?", `EmoteOnComplete`=0 WHERE `ID` IN (8779,8807);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID` IN (8779);
DELETE FROM `quest_offer_reward` WHERE `ID`=8807;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(8807,2,0,0,0,0,0,0,0,"Why, yes... these will be of tremendous aid!  These materials are awfully hard to come by in the desert, $n.  Thank you.",0);

-- Quest "Azure Templar"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID` IN (8737,8537,8536,8535);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID` IN (8737,8537,8536,8535);

-- Quest "The Four Dukes"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID` IN (8538,8498);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID` IN (8538);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (8498);

-- Quest "Hive'Ashi Scout Report"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID` IN (8739,8738,8534,8740);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID` IN (8739,8738,8534);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID` IN (8740);

-- Quest "The Calling"
DELETE FROM `quest_details` WHERE `ID`=8315;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8315,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `EmoteOnComplete`=25 WHERE `ID`=8315;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=8315;

-- Quest "Desert Recipe"
DELETE FROM `quest_details` WHERE `ID`=8307;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8307,1,1,1,0,0,0,0,0,0);

-- Quest "Sharing the Knowledge"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8313;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=8313;

-- Quest "Kitchen Assistance"
DELETE FROM `quest_details` WHERE `ID`=8317;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8317,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8317;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=8317;

-- Quest "Brann Bronzebeard's Lost Letter"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=8308;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8308;

-- Quest "Examine the Vessel"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7785;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=7785;

-- Quest "Thunderaan the Windseeker"
DELETE FROM `quest_details` WHERE `ID`=7786;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7786,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=7786;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=25, `Emote3`=5, `Emote4`=22 WHERE `ID`=7786;
