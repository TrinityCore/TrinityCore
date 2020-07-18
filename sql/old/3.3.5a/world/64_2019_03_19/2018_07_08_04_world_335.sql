-- Quest "Trouble in Winterspring!"
DELETE FROM `quest_details` WHERE `ID`=6603;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6603,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3 WHERE `ID`=6603;

-- Quest "Threat of the Winterfall"
DELETE FROM `quest_details` WHERE `ID`=5082;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5082,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=6 WHERE `ID`=5082;

-- Quest "Mystery Goo"
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=5085;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=5085;

-- Quest "Toxic Horrors"
DELETE FROM `quest_details` WHERE `ID`=5086;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5086,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5086;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5086;

-- Quest "Winterfall Runners"
DELETE FROM `quest_details` WHERE `ID`=5087;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5087,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5087;

-- Quest "Are We There, Yeti?"
DELETE FROM `quest_details` WHERE `ID`=3783;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3783,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3783;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3783;

-- Quest "Are We There, Yeti? (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=977;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(977,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=977;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=977;

-- Quest "Are We There, Yeti? (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=5163;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5163,4,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=5163;
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=11 WHERE `ID`=5163;

-- Quest "Ursius of the Shardtooth"
DELETE FROM `quest_details` WHERE `ID`=5054;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5054,1,2,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5054;

-- Quest "Brumeran of the Chillwind"
DELETE FROM `quest_details` WHERE `ID`=5055;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5055,1,2,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=5055;

-- Quest "Shy-Rotam"
DELETE FROM `quest_details` WHERE `ID`=5056;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5056,1,2,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5056;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=5056;

-- Quest "Past Endeavors"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `RewardText`="We learn from our life experiences, $N. I am sure that you have only become stronger and wiser as a result of yours. You have grown much since we first spoke.$b$bTake this in remembrance of the difficult tasks you have accomplished as a $R $C, and know that you will always have my respect and admiration." WHERE `ID`=5057;

-- Quest "Luck Be With You"
DELETE FROM `quest_details` WHERE `ID`=969;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(969,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=11, `EmoteOnComplete`=11 WHERE `ID`=969;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=969;

-- Quest "Cache of Mau'ari"
DELETE FROM `quest_details` WHERE `ID`=975;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(975,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=975;

-- Quest "Guarding Secrets"
DELETE FROM `quest_details` WHERE `ID`=4883;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4883,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4883;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4883;

-- Quest "To Winterspring!"
DELETE FROM `quest_details` WHERE `ID`=5249;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5249,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2 WHERE `ID`=5249;

-- Quest "Starfall"
DELETE FROM `quest_details` WHERE `ID`=5250;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5250,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2 WHERE `ID`=5250;

-- Quest "The Ruins of Kel'Theril"
DELETE FROM `quest_details` WHERE `ID`=5244;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5244,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=5244;

-- Quest "Troubled Spirits of Kel'Theril"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5245;

-- Quest "Fragments of the Past"
DELETE FROM `quest_details` WHERE `ID`=5246;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5246,2,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5246;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5246;

-- Quest "Fragments of the Past (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=5247;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5247,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5247;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5247;

-- Quest "Tormented By the Past"
DELETE FROM `quest_details` WHERE `ID`=5248;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5248,1,1,2,0,0,0,0,0,0);

-- Quest "Remorseful Highborne"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5252;

-- Quest "The Crystal of Zin-Malor"
DELETE FROM `quest_details` WHERE `ID`=5253;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5253,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5253;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=5253;

-- Quest "Snakestone of the Shadow Huntress"
DELETE FROM `quest_details` WHERE `ID`=5306;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5306,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=5306;
UPDATE `quest_offer_reward` SET `Emote1`=15 WHERE `ID`=5306;

-- Quest "Sweet Serenity"
DELETE FROM `quest_details` WHERE `ID`=5305;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5305,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=5305;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=5305;

-- Quest "Corruption"
DELETE FROM `quest_details` WHERE `ID`=5307;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5307,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5307;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5307;

-- Quest "Favored of Elune?"
DELETE FROM `quest_details` WHERE `ID`=3661;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3661,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=3661;

-- Quest "Moontouched Wildkin"
DELETE FROM `quest_details` WHERE `ID`=978;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(978,1,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=978;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=978;

-- Quest "Find Ranshalla"
DELETE FROM `quest_details` WHERE `ID`=979;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(979,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3 WHERE `ID`=979;

-- Quest "Guardians of the Altar"
DELETE FROM `quest_details` WHERE `ID`=4901;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4901,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=4901;

-- Quest "Wildkin of Elune"
DELETE FROM `quest_details` WHERE `ID`=4902;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4902,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=4902;

-- Quest "Enraged Wildkin"
DELETE FROM `quest_details` WHERE `ID`=6604;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6604,6,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=6604;

-- Quest "Enraged Wildkin (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=4861;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4861,3,1,0,0,0,0,0,0,0);

-- Quest "Enraged Wildkin (Part 4)"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4864;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=4864;

-- Quest "The Everlook Report"
DELETE FROM `quest_details` WHERE `ID`=6028;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6028,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=66 WHERE `ID`=6028;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6028;

-- Quest "Frostsaber E'ko"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID` IN (4801,4802,4803,4804,4805,4806,4807);

-- Quest "High Chief Winterfall"
DELETE FROM `quest_details` WHERE `ID`=5121;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5121,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=5121;

-- Quest "The Final Piece"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5123;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5123;

-- Quest "Words of the High Chief"
DELETE FROM `quest_details` WHERE `ID`=5128;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5128,1,2,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=5128;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=5128;

-- Quest "Making Amends"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9266;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9266;

-- Quest "Finkle Einhorn, At Your Service!"
DELETE FROM `quest_details` WHERE `ID`=5047;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5047,1,25,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5047;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=5047;

-- Quest "Frostsaber Provisions"
DELETE FROM `quest_details` WHERE `ID`=4970;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4970,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4970;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=4970;

-- Quest "Winterfall Intrusion"
DELETE FROM `quest_details` WHERE `ID`=5201;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5201,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5201;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5201;

-- Quest "Rampaging Giants"
DELETE FROM `quest_details` WHERE `ID`=5981;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5981,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5981;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=5981;

-- Quest "Cap of the Scarlet Savant"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5063;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=5063;

-- Quest "Leggings of Arcana"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5067;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=5067;

-- Quest "Breastplate of Bloodthirst"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5068;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5068;
