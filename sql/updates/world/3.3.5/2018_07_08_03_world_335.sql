-- Quest "Feathermoon Stronghold"
DELETE FROM `quest_details` WHERE `ID`=7494;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7494,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=7494;

-- Quest "Lethtendris's Web"
DELETE FROM `quest_details` WHERE `ID`=7488;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7488,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7488;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1, `Emote4`=2 WHERE `ID`=7488;

-- Quest "The Ruins of Solarsal"
DELETE FROM `quest_details` WHERE `ID`=2866;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2866,1,1,0,0,0,0,0,0,0);

-- Quest "Return to Feathermoon Stronghold"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=2867;

-- Quest "Against the Hatecrest"
DELETE FROM `quest_details` WHERE `ID`=3130;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3130,1,1,66,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1 WHERE `ID`=3130;

-- Quest "Against the Hatecrest (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=2869;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2869,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2869;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=25 WHERE `ID`=2869;

-- Quest "Against Lord Shalzaru"
DELETE FROM `quest_details` WHERE `ID`=2870;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2870,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2870;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2 WHERE `ID`=2870;

-- Quest "Delivering the Relic"
DELETE FROM `quest_details` WHERE `ID`=2871;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2871,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=2871;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=2871;

-- Quest "The Mark of Quality"
DELETE FROM `quest_details` WHERE `ID`=2821;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2821,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2821;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=2 WHERE `ID`=2821;

-- Quest "Improved Quality"
DELETE FROM `quest_details` WHERE `ID`=7733;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7733,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=7733;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=7733;

-- Quest "Elven Legends"
DELETE FROM `quest_details` WHERE `ID`=7482;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7482,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=7482;

-- Quest "Jonespyre's Request"
DELETE FROM `quest_details` WHERE `ID` IN (3787,3788);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3787,1,0,0,0,0,0,0,0,0),
(3788,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID` IN (3787,3788);

-- Quest "The Mystery of Morrowgrain"
DELETE FROM `quest_details` WHERE `ID`=3791;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3791,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=3791;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=3791;

-- Quest "Morrowgrain to Feathermoon Stronghold"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=3792;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=3792;

-- Quest "In Search of Knowledge"
DELETE FROM `quest_details` WHERE `ID`=2939;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2939,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=2939;

-- Quest "Feralas: A History"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=2940;

-- Quest "The Borrower"
DELETE FROM `quest_details` WHERE `ID`=2941;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2941,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=2941;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=2941;

-- Quest "The Super Snapper FX"
DELETE FROM `quest_details` WHERE `ID`=2944;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2944,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2944;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2944;

-- Quest "Return to Troyas"
DELETE FROM `quest_details` WHERE `ID`=2943;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2943,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=2943;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2943;

-- Quest "The Stave of Equinex"
DELETE FROM `quest_details` WHERE `ID`=2879;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2879,5,1,1,0,0,0,0,0,0);

-- Quest "The Morrow Stone"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2942;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=2942;

-- Quest "The High Wilderness"
DELETE FROM `quest_details` WHERE `ID`=2982;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2982,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2982;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2982;

-- Quest "Wild Leather Armor"
DELETE FROM `quest_details` WHERE `ID`=2847;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2847,21,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2847;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2847;

-- Quest "Wild Leather Shoulders"
DELETE FROM `quest_details` WHERE `ID`=2848;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2848,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2848;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`="These armor kits are of solid quality, $N. If there is one thing I demand in not only my work, but the work of those in my employ, it is quality.$B$BYou've done well to earn this pattern; I hope it brings you the rewards it has brought me." WHERE `ID`=2848;

-- Quest "Wild Leather Vest"
DELETE FROM `quest_details` WHERE `ID`=2849;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2849,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2849;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2849;

-- Quest "Wild Leather Helmet"
DELETE FROM `quest_details` WHERE `ID`=2850;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2850,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2850;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2850;

-- Quest "Wild Leather Boots"
DELETE FROM `quest_details` WHERE `ID`=2851;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2851,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2851;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2851;

-- Quest "Wild Leather Leggings"
DELETE FROM `quest_details` WHERE `ID`=2852;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2852,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2852;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2852;

-- Quest "Master of the Wild Leather"
DELETE FROM `quest_details` WHERE `ID`=2853;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2853,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2, `EmoteOnComplete`=2 WHERE `ID`=2853;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=2853;

-- Quest "Moonglow Vest"
DELETE FROM `quest_details` WHERE `ID`=1582;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1582,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1582;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1582;

-- Quest "The Missing Courier"
DELETE FROM `quest_details` WHERE `ID`=4124;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4124,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=4124;

-- Quest "The Missing Courier (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=4125;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4125,1,1,1,0,0,0,0,0,0);

-- Quest "Boat Wreckage"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2, `EmoteOnComplete`=2 WHERE `ID`=4127;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6 WHERE `ID`=4127;

-- Quest "The Knife Revealed"
DELETE FROM `quest_details` WHERE `ID`=4129;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4129,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=4129;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4129;

-- Quest "Psychometric Reading"
DELETE FROM `quest_details` WHERE `ID`=4130;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4130,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=4130;

-- Quest "The Woodpaw Gnolls"
DELETE FROM `quest_details` WHERE `ID`=4131;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4131,1,1,1,0,0,0,0,0,0);

-- Quest "Freed from the Hive"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=4265;

-- Quest "A Hero's Welcome"
DELETE FROM `quest_details` WHERE `ID`=4266;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4266,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1 WHERE `ID`=4266;

-- Quest "Rise of the Silithid"
DELETE FROM `quest_details` WHERE `ID`=4267;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4267,1,1,66,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2, `EmoteOnComplete`=2 WHERE `ID`=4267;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=4267;

-- Quest "Thalanaar Delivery"
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=4281;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=2 WHERE `ID`=4281;

-- Quest "Tribal Leatherworking"
DELETE FROM `quest_details` WHERE `ID`=5143;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5143,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5143;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=5143;

-- Quest "Lonebrow's Journal"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1100;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1100;

-- Quest "The Crone of the Kraul"
DELETE FROM `quest_details` WHERE `ID`=1101;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1101,18,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1101;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=1101;

-- Quest "Pusillin and the Elder Azj'Tordin"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=7441;

-- Quest "Freedom for All Creatures"
DELETE FROM `quest_details` WHERE `ID`=2969;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2969,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=2969;

-- Quest "Doling Justice"
DELETE FROM `quest_details` WHERE `ID`=2970;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2970,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2970;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2970;

-- Quest "Doling Justice"
DELETE FROM `quest_details` WHERE `ID`=2972;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2972,1,1,2,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2972;

-- Quest "An Orphan Looking For a Home"
DELETE FROM `quest_details` WHERE `ID`=3841;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3841,1,1,6,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=3841;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6 WHERE `ID`=3841;

-- Quest "A Short Incubation"
DELETE FROM `quest_details` WHERE `ID`=3842;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3842,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=3842;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=3842;

-- Quest "The Newest Member of the Family"
DELETE FROM `quest_details` WHERE `ID`=3843;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3843,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=3843;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=3843;

-- Quest "Food for Baby"
DELETE FROM `quest_details` WHERE `ID`=4297;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4297,1,1,6,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4297;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `Emote3`=11 WHERE `ID`=4297;

-- Quest "Becoming a Parent"
DELETE FROM `quest_details` WHERE `ID`=4298;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4298,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=4298;

-- Quest "Rescue OOX-22/FE!"
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID` IN (2767,648,836);

-- Quest "Pristine Yeti Hide"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=7735;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=2 WHERE `ID`=7735;

-- Quest "The Giant Guardian"
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2844;

-- Quest "Wandering Shay"
DELETE FROM `quest_details` WHERE `ID`=2845;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2845,6,1,0,0,0,0,0,0,0);

-- Fix availability for quest "March of the Silithid"
UPDATE `quest_template_addon` SET `NextQuestID`=4493 WHERE `ID` IN (162,4267);
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=4493;

-- Fix "Wild Leather Armor" quest chain
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-2851 WHERE `ID` IN (2851,2852);
UPDATE `quest_template_addon` SET `NextQuestID`=2851 WHERE `ID` IN (2848,2849);
UPDATE `quest_template_addon` SET `NextQuestID`=2852 WHERE `ID`=2850;
