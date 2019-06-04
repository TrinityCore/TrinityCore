-- Quest "The Hunt Begins"
DELETE FROM `quest_details` WHERE `ID`=747;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(747,3,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=747;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=747;

-- Quest "The Hunt Continues"
DELETE FROM `quest_details` WHERE `ID`=750;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(750,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=750;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=750;

-- Quest "The Battleboars"
DELETE FROM `quest_details` WHERE `ID`=780;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(780,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=780;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=780;

-- Quest "Simple Note" / "Etched Note" / "Rune-Inscribed Note" / "Verdant Note"
DELETE FROM `quest_details` WHERE `ID` IN (3091,3092,3093,3094);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3091,1,0,0,0,0,0,0,0,0),
(3092,1,0,0,0,0,0,0,0,0),
(3093,1,0,0,0,0,0,0,0,0),
(3094,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2, `EmoteOnComplete`=2 WHERE `ID` IN (3091,3092,3093,3094);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID` IN (3091,3092,3093,3094);

-- Quest "A Humble Task"
DELETE FROM `quest_details` WHERE `ID`=752;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(752,1,6,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=24 WHERE `ID`=752;

-- Quest "A Humble Task"
DELETE FROM `quest_details` WHERE `ID`=753;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(753,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=753;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=753;

-- Quest "Rites of the Earthmother"
DELETE FROM `quest_details` WHERE `ID`=755;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(755,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=755;

-- Quest "Rite of Strength"
DELETE FROM `quest_details` WHERE `ID`=757;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(757,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=757;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=757;

-- Quest "Break Sharptusk!"
DELETE FROM `quest_details` WHERE `ID`=3376;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3376,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=3376;

-- Quest "Attack on Camp Narache"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (781,24857);

-- Quest "Rites of the Earthmother"
DELETE FROM `quest_details` WHERE `ID`=763;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(763,25,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=763;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=763;

-- Quest "A Task Unfinished"
DELETE FROM `quest_details` WHERE `ID`=1656;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1656,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1656;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=1656;

-- Quest "Dangers of the Windfury"
DELETE FROM `quest_details` WHERE `ID`=743;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(743,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=743;

-- Quest "Poison Water"
DELETE FROM `quest_details` WHERE `ID`=748;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(748,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=748;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=748;

-- Quest "Swoop Hunting"
DELETE FROM `quest_details` WHERE `ID`=761;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(761,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=761;

-- Quest "Mazzranache"
DELETE FROM `quest_details` WHERE `ID`=766;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(766,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=766;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=766;

-- Quest "Rite of Vision"
DELETE FROM `quest_details` WHERE `ID`=767;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(767,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=767;

-- Quest "Rite of Vision (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=771;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(771,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=771;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=771;

-- Quest "Rite of Vision (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=772;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(772,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=772;

-- Quest "Dwarven Digging"
DELETE FROM `quest_details` WHERE `ID`=746;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(746,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=746;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=746;

-- Quest "Winterhoof Cleansing"
DELETE FROM `quest_details` WHERE `ID`=754;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(754,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=754;

-- Quest "Thunderhorn Totem"
DELETE FROM `quest_details` WHERE `ID`=756;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(756,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=756;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=756;

-- Quest "Thunderhorn Cleansing"
DELETE FROM `quest_details` WHERE `ID`=758;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(758,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=758;

-- Quest "Wildmane Totem"
DELETE FROM `quest_details` WHERE `ID`=759;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(759,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=759;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=759;

-- Quest "Wildmane Cleansing"
DELETE FROM `quest_details` WHERE `ID`=760;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(760,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=760;

-- Quest "Rite of Wisdom"
DELETE FROM `quest_details` WHERE `ID`=773;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(773,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=773;

-- Quest "Sharing the Land"
DELETE FROM `quest_details` WHERE `ID`=745;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(745,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=745;

-- Quests "The Ravaged Caravan" / "Supervisor Fizsprocket"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID` IN (751,765);

-- Quest "The Hunter's Way"
DELETE FROM `quest_details` WHERE `ID`=861;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(861,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=861;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=861;

-- Quest "A Sacred Burial"
DELETE FROM `quest_details` WHERE `ID`=833;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(833,1,2,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=833;

-- Quest "Journey into Thunder Bluff"
DELETE FROM `quest_details` WHERE `ID`=775;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(775,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=775;

-- Quest "Rites of the Earthmother"
DELETE FROM `quest_details` WHERE `ID`=776;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(776,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=776;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=776;

-- Quest "The Demon Scarred Cloak"
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2 WHERE `ID`=770;

-- Quest "Taming the Beast"
DELETE FROM `quest_details` WHERE `ID` IN (6061,6087,6088,6089);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6061,1,0,0,0,0,0,0,0,0),
(6087,1,0,0,0,0,0,0,0,0),
(6088,1,0,0,0,0,0,0,0,0),
(6089,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID` IN (6061,6088);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=6087;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=6061;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=6087;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=6088;

-- Quest "A Vengeful Fate"
DELETE FROM `quest_details` WHERE `ID`=1102;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1102,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1102;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1102;

-- Quest "A Bundle of Hides"
DELETE FROM `quest_details` WHERE `ID`=6361;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6361,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=6361;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6361;

-- Quest "Ride to Thunder Bluff"
DELETE FROM `quest_details` WHERE `ID`=6362;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6362,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=6362;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=6362;

-- Quest "Tal the Wind Rider Master"
DELETE FROM `quest_details` WHERE `ID`=6363;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6363,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=6363;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=6363;

-- Quest "Return to Jahan"
DELETE FROM `quest_details` WHERE `ID`=6364;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6364,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=6364;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6364;

-- Quest "Compendium of the Fallen"
DELETE FROM `quest_details` WHERE `ID`=1049;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1049,1,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=1049;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2 WHERE `ID`=1049;

-- Quest "The Platinum Discs"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=2280;

-- Quest "The Platinum Discs"
DELETE FROM `quest_details` WHERE `ID`=2440;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2440,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=2440;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=2440;

-- Quest "Portents of Uldum"
DELETE FROM `quest_details` WHERE `ID`=2965;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2965,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2965;

-- Quest "Seeing What Happens"
DELETE FROM `quest_details` WHERE `ID`=2966;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2966,1,1,1,0,0,0,0,0,0);

-- Quest "Return to Thunder Bluff"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2967;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=2967;

-- Quest "A Future Task"
DELETE FROM `quest_details` WHERE `ID`=2968;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2968,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=2968;

-- Quest "Gathering Leather"
DELETE FROM `quest_details` WHERE `ID`=768;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(768,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=768;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=768;

-- Quest "Kodo Hide Bag"
DELETE FROM `quest_details` WHERE `ID`=769;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(769,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=769;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=769;

-- Quest "Serpentbloom"
DELETE FROM `quest_details` WHERE `ID`=962;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(962,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=962;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=962;

-- Quest "Searching for the Lost Satchel"
DELETE FROM `quest_details` WHERE `ID`=5722;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5722,1,0,0,0,0,0,0,0,0);

-- Quest "Returning the Lost Satchel"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5724;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5724;

-- Quest "Testing an Enemy's Strength"
DELETE FROM `quest_details` WHERE `ID`=5723;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5723,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=5723;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=5723;
