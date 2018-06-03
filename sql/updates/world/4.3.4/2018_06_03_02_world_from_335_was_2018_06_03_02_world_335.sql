/*
-- Quest "Kobold Camp Cleanup"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7;

-- Quest "Investigate Echo Ridge"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=15;

-- Quest "Skirmish at Echo Ridge"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=21;

-- Quest "Brotherhood of Thieves"
DELETE FROM `quest_details` WHERE `ID`=18;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(18,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=18;

-- Quest "Bounty on Garrick Padfoot"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6;

-- Quest "Milly's Harvest"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3904;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3904;

-- Quest "Grape Manifest"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3905;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4 WHERE `ID`=3905;

-- Quest "In Favor of the Light"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5623;

-- Quest "Garments of the Light"
DELETE FROM `quest_details` WHERE `ID`=5624;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5624,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5624;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5624;

-- Quest "Report to Goldshire"
UPDATE `quest_offer_reward` SET `Emote2`=66 WHERE `ID`=54;

-- Quest "Rest and Relaxation"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2158;

-- Quest "The Fargodeep Mine"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=62;

-- Quest "The Jasperlode Mine"
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=76;

-- Quest "Report to Gryan Stoutmantle"
DELETE FROM `quest_details` WHERE `ID`=109;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(109,1,25,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=109;

-- Quest "Westbrook Garrison Needs Help!"
DELETE FROM `quest_details` WHERE `ID`=239;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(239,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=239;

-- Quest "Kobold Candles"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=60;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=60;

-- Quest "Shipment to Stormwind"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=61;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=61;

-- Quest "Gold Dust Exchange"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=47;

-- Quest "A Fishy Peril"
DELETE FROM `quest_details` WHERE `ID`=40;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(40,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=40;

-- Quest "Further Concerns"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=35;

-- Quest "Protect the Frontier"
DELETE FROM `quest_details` WHERE `ID`=52;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(52,66,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=52;

-- Quest "Report to Thomas"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=71;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=71;

-- Quest "Cloth and Leather Armor"
DELETE FROM `quest_details` WHERE `ID`=59;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(59,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=59;

-- Quest "Red Linen Goods"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=83;

-- Quest "A Bundle of Trouble"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5545;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5545;

-- Quest "Bounty on Murlocs"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=46;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=46;

-- Quest "A Watchful Eye"
DELETE FROM `quest_details` WHERE `ID`=94;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(94,1,0,0,0,0,0,0,0,0);

-- Quest "Tome of Divinity"
DELETE FROM `quest_details` WHERE `ID`=2998;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2998,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2998;

-- Quest "Tome of Divinity"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=1641;

-- Quest "Tome of Divinity"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=6, `Emote3`=1, `Emote4`=1 WHERE `ID`=1642;

-- Quest "Tome of Divinity (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1643;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1643,2,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=1643;

-- Quest "Tome of Divinity (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1644;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1644,1,1,1,16,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1644;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1, `Emote4`=2 WHERE `ID`=1644;

-- Quest "Tome of Divinity (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=1780;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1780,1,1,3,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=1780;

-- Quest "Tome of Divinity (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=1781;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1781,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=33, `Emote2`=2, `Emote3`=1, `Emote4`=1 WHERE `ID`=1781;

-- Quest "Tome of Divinity (Part 6)"
DELETE FROM `quest_details` WHERE `ID`=1786;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1786,1,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=1786;

-- Quest "Tome of Divinity (Part 7)"
DELETE FROM `quest_details` WHERE `ID`=1787;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1787,1,1,6,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1787;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=1787;

-- Quest "Tome of Divinity (Part 8)"
DELETE FROM `quest_details` WHERE `ID`=1788;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1788,1,1,2,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=2 WHERE `ID`=1788;

-- Quest "Give Gerard a Drink"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=16;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=16;

-- Quest "Young Lovers"
DELETE FROM `quest_details` WHERE `ID`=106;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(106,18,20,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=106;

-- Quest "Speak with Gramma"
DELETE FROM `quest_details` WHERE `ID`=111;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(111,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=111;

-- Quest "Note to William"
DELETE FROM `quest_details` WHERE `ID`=107;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(107,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=107;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=107;

-- Quest "Collecting Kelp"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=112;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=112;

-- Quest "The Escape"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=114;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=114;

-- Quest "Princess Must Die!"
DELETE FROM `quest_details` WHERE `ID`=88;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(88,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=88;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=88;

-- Quest "Lost Necklace"
DELETE FROM `quest_details` WHERE `ID`=85;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(85,1,0,0,0,0,0,0,0,0);

-- Quest "Pie for Billy"
DELETE FROM `quest_details` WHERE `ID`=86;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(86,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=86;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=86;

-- Quest "Back to Billy"
DELETE FROM `quest_details` WHERE `ID`=84;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(84,1,0,0,0,0,0,0,0,0);

-- Quest "Goldtooth"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=87;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=87;

-- Quest "Riverpaw Gnoll Bounty"
DELETE FROM `quest_details` WHERE `ID`=11;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=11;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=11;

-- Quest "Wanted: Hogger"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=176;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=176;

-- Quest "The Collector"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=123;

-- Quest "Manhunt"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=147;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=147;

-- Quest "Elmore's Task"
DELETE FROM `quest_details` WHERE `ID`=1097;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1097,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1097;

-- Quest "Stormpike's Delivery"
DELETE FROM `quest_details` WHERE `ID`=353;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(353,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=353;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=353;

-- Quest "Wine Shop Advert"
DELETE FROM `quest_details` WHERE `ID`=332;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(332,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=332;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=332;

-- Quest "Harlan Needs a Resupply"
DELETE FROM `quest_details` WHERE `ID`=333;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(333,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=333;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=333;

-- Quest "Package for Thurman"
DELETE FROM `quest_details` WHERE `ID`=334;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(334,1,1,0,0,0,0,0,0,0);

-- Quest "Retrieval for Mauren"
DELETE FROM `quest_details` WHERE `ID`=1078;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1078,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2, `EmoteOnComplete`=2 WHERE `ID`=1078;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1078;

-- Quest "The Color of Blood"
DELETE FROM `quest_details` WHERE `ID`=388;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(388,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=388;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=388;

-- Quest "Quell The Uprising"
DELETE FROM `quest_details` WHERE `ID`=387;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(387,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=387;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=387;

-- Quest "Mazen's Behest"
DELETE FROM `quest_details` WHERE `ID`=1363;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1363,1,6,1,6,0,0,0,0,0);

-- Quest "Mazen's Behest (Part 2)"
DELETE FROM `quest_template_addon` WHERE `ID`=1364;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(1364,0,0,0,1363,0,0,0,0,0,0,0,0,0,0,0,0);
DELETE FROM `quest_details` WHERE `ID`=1364;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1364,1,1,5,6,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1364;

-- Quest "The Corruption Abroad"
DELETE FROM `quest_details` WHERE `ID`=3765;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3765,2,1,1,0,0,0,0,0,0);

-- Quest "Speaking of Fortitude"
DELETE FROM `quest_details` WHERE `ID`=343;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(343,1,1,2,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=343;

-- Quest "Brother Paxton"
DELETE FROM `quest_details` WHERE `ID`=344;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(344,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=344;

-- Quest "Ink Supplies"
DELETE FROM `quest_details` WHERE `ID`=345;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(345,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=345;

-- Quest "Rethban Ore"
DELETE FROM `quest_details` WHERE `ID`=347;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(347,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=347;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=347;

-- Quest "Return to Kristoff"
DELETE FROM `quest_details` WHERE `ID`=346;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(346,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=346;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=346;

-- Quest "Humble Beginnings"
DELETE FROM `quest_details` WHERE `ID`=399;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(399,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=399;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=399;

-- Quest "Bring the Light"
DELETE FROM `quest_details` WHERE `ID`=3636;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3636,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=3636;

-- Quest "Underground Assault"
DELETE FROM `quest_details` WHERE `ID`=2040;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2040,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2040;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2040;

-- Quest "Gyrodrillmatic Excavationators"
DELETE FROM `quest_details` WHERE `ID`=2928;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2928,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2928;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2928;

-- Quest "Collecting Memories"
DELETE FROM `quest_details` WHERE `ID`=168;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(168,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=168;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=168;

-- Quest "Oh Brother. . ."
DELETE FROM `quest_details` WHERE `ID`=167;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(167,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=167;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=167;

-- Quest "Furlbrow's Deed"
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=184;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=184;

-- Quest "The Forgotten Heirloom"
DELETE FROM `quest_details` WHERE `ID`=64;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(64,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=64;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=64;

-- Quest "Poor Old Blanchy"
DELETE FROM `quest_details` WHERE `ID`=151;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(151,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=151;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=151;

-- Quest "Westfall Stew"
DELETE FROM `quest_details` WHERE `ID`=36;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(36,1,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=36;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=36;

-- Quest "Westfall Stew (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=38;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(38,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=38;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=38;

-- Quest "Goretusk Liver Pie"
DELETE FROM `quest_details` WHERE `ID`=22;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(22,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=6 WHERE `ID`=22;

-- Quest "The Killing Fields"
DELETE FROM `quest_details` WHERE `ID`=9;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=9;

-- Quest "The People's Militia"
DELETE FROM `quest_details` WHERE `ID`=12;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(12,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=12;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=12;

-- Quest "The People's Militia (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=13;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(13,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=13;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=13;

-- Quest "The People's Militia (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=14;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(14,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=14;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=14;

-- Quest "Patrolling Westfall"
DELETE FROM `quest_details` WHERE `ID`=102;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(102,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=102;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=102;

-- Quest "A Swift Message"
DELETE FROM `quest_details` WHERE `ID`=6181;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6181,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6181;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6181;

-- Quest "Continue to Stormwind"
DELETE FROM `quest_details` WHERE `ID`=6281;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6281,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6281;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6281;

-- Quest "Dungar Longdrink"
DELETE FROM `quest_details` WHERE `ID`=6261;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6261,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=6261;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6261;

-- Quest "Return to Lewis"
DELETE FROM `quest_details` WHERE `ID`=6285;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6285,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6285;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=6285;

-- Quest "Red Leather Bandanas"
DELETE FROM `quest_details` WHERE `ID`=153;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(153,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=153;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=153;

-- Quest "Thunderbrew Lager"
DELETE FROM `quest_details` WHERE `ID`=117;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(117,94,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=94, `EmoteOnComplete`=94 WHERE `ID`=117;
UPDATE `quest_offer_reward` SET `Emote1`=94 WHERE `ID`=117;

-- Quest "Sweet Amber"
DELETE FROM `quest_details` WHERE `ID`=48;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48,94,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=94, `EmoteOnComplete`=94 WHERE `ID`=48;
UPDATE `quest_offer_reward` SET `Emote1`=33 WHERE `ID`=48;

-- Quest "Sweet Amber (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=49;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(49,94,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=94, `EmoteOnComplete`=94 WHERE `ID`=49;
UPDATE `quest_offer_reward` SET `Emote1`=33 WHERE `ID`=49;

-- Quest "Sweet Amber (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=50;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(50,94,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=94, `EmoteOnComplete`=94 WHERE `ID`=50;
UPDATE `quest_offer_reward` SET `Emote1`=33 WHERE `ID`=50;

-- Quest "Sweet Amber (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=51;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(51,94,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=94, `EmoteOnComplete`=94 WHERE `ID`=51;
UPDATE `quest_offer_reward` SET `Emote1`=33 WHERE `ID`=51;

-- Quest "Sweet Amber (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=53;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(53,94,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=94, `EmoteOnComplete`=94 WHERE `ID`=53;
UPDATE `quest_offer_reward` SET `Emote1`=94 WHERE `ID`=53;

-- Quest "Keeper of the Flame" / "The Coastal Menace"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID` IN (103,104);

-- Quest "The Defias Brotherhood"
DELETE FROM `quest_details` WHERE `ID`=65;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(65,1,25,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=65;

-- Quest "The Defias Brotherhood (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=132;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(132,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=132;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=132;

-- Quest "The Defias Brotherhood (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=135;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(135,6,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=135;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=135;

-- Quest "The Defias Brotherhood (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=141;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(141,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=141;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=141;

-- Quest "The Defias Brotherhood (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=142;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(142,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=142;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=25 WHERE `ID`=142;

-- Quest "The Defias Brotherhood (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=155;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(155,6,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=155;

-- Quest "The Defias Brotherhood (Part 6)"
DELETE FROM `quest_details` WHERE `ID`=166;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(166,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=166;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=166;

-- Quest "Red Silk Bandanas"
DELETE FROM `quest_details` WHERE `ID`=214;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(214,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=214;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=214;

-- Quest "Brother Anton"
DELETE FROM `quest_details` WHERE `ID`=6141;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6141,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6141;

-- Quest "Lord Grayson Shadowbreaker"
DELETE FROM `quest_details` WHERE `ID` IN (7638,7670);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7638,1,1,0,0,0,0,0,0,0),
(7670,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=25 WHERE `ID` IN (7638,7670);

-- Quest "Emphasis on Sacrifice"
DELETE FROM `quest_details` WHERE `ID`=7637;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7637,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=7637;

-- Quest "To Show Due Judgment"
DELETE FROM `quest_details` WHERE `ID`=7639;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7639,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=7639;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7639;

-- Quest "Exorcising Terrordale"
DELETE FROM `quest_details` WHERE `ID`=7640;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7640,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7640;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=7640;

-- Quest "The Work of Grimand Elmore"
DELETE FROM `quest_details` WHERE `ID`=7641;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7641,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3, `Emote2`=1 WHERE `ID`=7641;

-- Quest "Collection of Goods"
DELETE FROM `quest_details` WHERE `ID`=7642;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7642,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7642;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7642;

-- Quest "Grimand's Finest Work"
DELETE FROM `quest_details` WHERE `ID`=7648;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7648,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7648;

-- Quest "Ancient Equine Spirit"
UPDATE `quest_template_addon` SET `PrevQuestID`=7648 WHERE `ID`=7643;
DELETE FROM `quest_details` WHERE `ID`=7643;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7643,1,1,0,0,0,0,0,0,0);

-- Quest "Manna-Enriched Horse Feed"
DELETE FROM `quest_details` WHERE `ID`=7645;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7645,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=7645;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `Emote3`=1 WHERE `ID`=7645;

-- Quest "Blessed Arcanite Barding"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7644;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7644;

-- Quest "The Divination Scryer"
DELETE FROM `quest_details` WHERE `ID`=7646;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7646,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=7646;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7646;

-- Quest "Judgment and Redemption"
DELETE FROM `quest_details` WHERE `ID`=7647;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7647,1,1,2,0,0,0,0,0,0);

-- Quest "Again Into the Great Ossuary"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=7666;

-- Quest "The Tome of Valor"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6, `Emote4`=1 WHERE `ID`=1793;

-- Quest "The Tome of Valor (Part 2)"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `Emote4`=6 WHERE `ID`=1649;

-- Quest "The Tome of Valor (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1650;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1650,21,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `Emote4`=24 WHERE `ID`=1650;

-- Quest "The Tome of Valor (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=1651;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1651,1,1,1,5,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1 WHERE `ID`=1651;

-- Quest "The Tome of Valor (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=1652;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1652,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4, `Emote3`=1 WHERE `ID`=1652;

-- Quest "The Test of Righteousness"
DELETE FROM `quest_details` WHERE `ID`=1653;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1653,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `Emote4`=6 WHERE `ID`=1653;

-- Quest "The Test of Righteousness (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1654;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1654,6,2,1,6,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1654;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1 WHERE `ID`=1654;

-- Quest "The Test of Righteousness (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1806;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1806,6,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=1806;

-- Quest "A Warrior's Training"
DELETE FROM `quest_details` WHERE `ID`=1638;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1638,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6 WHERE `ID`=1638;

-- Quest "Bartleby the Drunk"
DELETE FROM `quest_details` WHERE `ID`=1639;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1639,1,6,11,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3, `Emote2`=6 WHERE `ID`=1639;

-- Quest "Beat Bartleby"
DELETE FROM `quest_details` WHERE `ID`=1640;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1640,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=1640;

-- Quest "Bartleby's Mug"
DELETE FROM `quest_details` WHERE `ID`=1665;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1665,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1665;
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1 WHERE `ID`=1665;

-- Quest "Marshal Haggard"
DELETE FROM `quest_details` WHERE `ID`=1666;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1666,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=5 WHERE `ID`=1666;

-- Quest "Dead-tooth Jack"
DELETE FROM `quest_details` WHERE `ID`=1667;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1667,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1667;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=1667;

-- Quest "Speak with Jennea"
DELETE FROM `quest_details` WHERE `ID`=1860;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1860,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1860;

-- Quest "Mirror Lake"
DELETE FROM `quest_details` WHERE `ID`=1861;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1861,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1861;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1861;

-- Quest "Report to Jennea"
DELETE FROM `quest_details` WHERE `ID`=1919;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1919,1,6,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1919;

-- Quest "Investigate the Blue Recluse"
DELETE FROM `quest_details` WHERE `ID`=1920;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1920,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1920;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=1920;

-- Quest "Gathering Materials"
DELETE FROM `quest_details` WHERE `ID`=1921;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1921,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=1921;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=1921;

-- Quest "Manaweave Robe"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1941;

-- Quest "High Sorcerer Andromath"
DELETE FROM `quest_details` WHERE `ID`=1939;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1939,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1939;

-- Quest "Ur's Treatise on Shadow Magic"
DELETE FROM `quest_details` WHERE `ID`=1938;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1938,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1938;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1938;

-- Quest "Pristine Spider Silk"
DELETE FROM `quest_details` WHERE `ID`=1940;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1940,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1940;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=1940;

-- Quest "Astral Knot Garment"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `Emote3`=11 WHERE `ID`=1942;

-- Quest "Vital Supplies"
DELETE FROM `quest_details` WHERE `ID`=1477;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1477,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1477;

-- Quest "Supplies for Nethergarde"
DELETE FROM `quest_details` WHERE `ID`=1395;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1395,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=1395;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=1395;

-- Quest "Journey to the Marsh"
DELETE FROM `quest_details` WHERE `ID`=1947;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1947,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1947;

-- Quest "Items of Power"
UPDATE `quest_template_addon` SET `PrevQuestID`=1947 WHERE `ID`=1948;
DELETE FROM `quest_details` WHERE `ID`=1948;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1948,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=1948;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=6 WHERE `ID`=1948;

-- Quest "Hidden Secrets"
DELETE FROM `quest_details` WHERE `ID`=1949;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1949,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=25 WHERE `ID`=1949;

-- Quest "Get the Scoop"
DELETE FROM `quest_details` WHERE `ID`=1950;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1950,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=1950;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1950;

-- Quest "Rituals of Power"
DELETE FROM `quest_details` WHERE `ID`=1951;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1951,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2, `EmoteOnComplete`=2 WHERE `ID`=1951;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1951;

-- Quest "Mage's Wand"
DELETE FROM `quest_details` WHERE `ID`=1952;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1952,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1952;

-- Quest "Return to the Marsh"
DELETE FROM `quest_details` WHERE `ID`=1953;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1953,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1953;

-- Quest "The Infernal Orb"
DELETE FROM `quest_details` WHERE `ID`=1954;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1954,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1954;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5 WHERE `ID`=1954;

-- Quest "The Exorcism"
DELETE FROM `quest_details` WHERE `ID`=1955;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1955,1,25,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1955;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1 WHERE `ID`=1955;

-- Quest "Power in Uldaman"
DELETE FROM `quest_details` WHERE `ID`=1956;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1956,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1956;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1 WHERE `ID`=1956;

-- Quest "Mana Surges"
DELETE FROM `quest_details` WHERE `ID`=1957;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1957,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1957;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=1957;

-- Quest "Celestial Power"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1958;

-- Quest "Tabetha's Task"
DELETE FROM `quest_details` WHERE `ID`=2861;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2861,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6 WHERE `ID`=2861;

-- Quest "Tiara of the Deep"
DELETE FROM `quest_details` WHERE `ID`=2846;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2846,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=2846;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=2846;

-- Quest "Magecraft"
DELETE FROM `quest_details` WHERE `ID`=8250;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8250,1,0,0,0,0,0,0,0,0);

-- Quest "A Meal Served Cold"
DELETE FROM `quest_details` WHERE `ID`=212;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(212,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=212;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=212;

-- Quest "James Hyal"
DELETE FROM `quest_details` WHERE `ID`=1301;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1301,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1301;

-- Quest "James Hyal (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1302;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1302,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1302;

-- Quest "Morgan Stern"
DELETE FROM `quest_details` WHERE `ID`=1260;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1260,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1260;

-- Quest "The Perenolde Tiara"
DELETE FROM `quest_details` WHERE `ID`=543;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(543,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=543;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=543;

-- Quest "Mayara Brightwing"
DELETE FROM `quest_details` WHERE `ID`=4766;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4766,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4766;

-- Quest "Tinkmaster Overspark"
DELETE FROM `quest_details` WHERE `ID`=2923;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2923,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=18, `Emote2`=6 WHERE `ID`=2923;

-- Quest "Save Techbot's Brain!"
DELETE FROM `quest_details` WHERE `ID`=2922;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2922,1,5,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2922;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=2922;

-- Quest "Seek out SI: 7"
DELETE FROM `quest_details` WHERE `ID`=2205;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2205,6,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2205;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6 WHERE `ID`=2205;

-- Quest "Snatch and Grab"
DELETE FROM `quest_details` WHERE `ID`=2206;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2206,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `EmoteOnComplete`=25 WHERE `ID`=2206;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2206;

-- Quest "Mathias and the Defias"
DELETE FROM `quest_details` WHERE `ID`=2360;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2360,1,1,1,25,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=2360;

-- Quest "Klaven's Tower"
DELETE FROM `quest_details` WHERE `ID`=2359;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2359,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2359;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=2359;

-- Quest "The Touch of Zanzil"
DELETE FROM `quest_details` WHERE `ID`=2607;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2607,1,6,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=2607;

-- Quest "The Touch of Zanzil (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=2608;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2608,1,11,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=22, `EmoteDelay1`=1500 WHERE `ID`=2608;

-- Quest "The Touch of Zanzil (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=2609;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2609,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=2609;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5 WHERE `ID`=2609;

-- Quest "A Simple Request"
DELETE FROM `quest_details` WHERE `ID`=8233;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8233,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=6 WHERE `ID`=8233;

-- Quest "Sealed Azure Bag"
DELETE FROM `quest_details` WHERE `ID`=8234;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8234,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8234;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8234;

-- Quest "Encoded Fragments"
DELETE FROM `quest_details` WHERE `ID`=8235;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8235,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8235;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8235;

-- Quest "The Azure Key"
DELETE FROM `quest_details` WHERE `ID`=8236;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8236,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8236;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote1`=1 WHERE `ID`=8236;

-- Quest "SI:7"
DELETE FROM `quest_details` WHERE `ID`=2300;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2300,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=2300;

-- Quest "Redridge Rendezvous"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=11 WHERE `ID`=2281;

-- Quest "Alther's Mill"
UPDATE `quest_template_addon` SET `PrevQuestID`=2281 WHERE `ID`=2282;
DELETE FROM `quest_details` WHERE `ID`=2282;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2282,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2282;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote1`=25 WHERE `ID`=2282;

-- Quest "Cenarion Aid"
DELETE FROM `quest_details` WHERE `ID`=8254;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8254,1,0,0,0,0,0,0,0,0);

-- Quest "Of Coursers We Know"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=8255;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8255;

-- Quest "The Ichor of Undeath"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=8256;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8256;

-- Quest "Blood of Morphaz"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8257;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote1`=1 WHERE `ID`=8257;

-- Quest "Gakin's Summons"
DELETE FROM `quest_details` WHERE `ID` IN (1685,1717);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1685,1,1,0,0,0,0,0,0,0),
(1717,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID` IN (1685,1717);

-- Quest "The Slaughtered Lamb"
DELETE FROM `quest_details` WHERE `ID`=1715;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1715,1,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1715;

-- Quest "Surena Caledon"
DELETE FROM `quest_details` WHERE `ID`=1688;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1688,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1688;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1688;

-- Quest "The Binding"
DELETE FROM `quest_details` WHERE `ID`=1689;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1689,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1689;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1689;

-- Quest "A Noble Brew"
DELETE FROM `quest_details` WHERE `ID`=335;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(335,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=335;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=335;

-- Quest "A Noble Brew (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=336;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(336,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=336;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=336;

-- Quest "You Have Served Us Well"
DELETE FROM `quest_details` WHERE `ID`=397;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(397,11,1,0,0,0,0,0,0,0);

-- Quest "Knowledge of the Orb of Orahil"
DELETE FROM `quest_details` WHERE `ID` IN (4965,4967,4968,4969);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4965,21,1,0,0,0,0,0,0,0),
(4967,1,25,0,0,0,0,0,0,0),
(4968,21,1,0,0,0,0,0,0,0),
(4969,11,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID` IN (4965,4967,4968,4969);

-- Quest "Fragments of the Orb of Orahil"
DELETE FROM `quest_details` WHERE `ID`=1799;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1799,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1799;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1799;

-- Quest "Shard of an Infernal"
DELETE FROM `quest_details` WHERE `ID`=4963;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4963,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4963;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=4963;

-- Quest "Shard of a Felhound"
DELETE FROM `quest_details` WHERE `ID`=4962;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4962,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4962;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=4962;

-- Quest "Cleansing of the Orb of Orahil"
DELETE FROM `quest_details` WHERE `ID`=4961;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4961,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=4961;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=4961;

-- Quest "Returning the Cleansed Orb"
DELETE FROM `quest_details` WHERE `ID`=4976;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4976,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4976;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=4976;

-- Quest "The Completed Orb of Noh'Orahil"
DELETE FROM `quest_details` WHERE `ID`=4975;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4975,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=4975;

-- Quest "The Completed Orb of Dar'Orahil"
DELETE FROM `quest_details` WHERE `ID`=4964;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4964,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=4964;

-- Quest "In Search of Menara Voidrender"
DELETE FROM `quest_details` WHERE `ID` IN (4736,4737,4738,4739);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4736,3,1,0,0,0,0,0,0,0),
(4737,1,25,0,0,0,0,0,0,0),
(4738,1,1,0,0,0,0,0,0,0),
(4739,25,1,0,0,500,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID` IN (4736,4737,4738,4739);

-- Quest "Components for the Enchanted Gold Bloodrobe"
DELETE FROM `quest_details` WHERE `ID`=1796;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1796,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1796;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1796;

-- Quest "Components for the Enchanted Gold Bloodrobe (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=4781;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4781,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2, `EmoteOnComplete`=2 WHERE `ID`=4781;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=4781;

-- Quest "Components for the Enchanted Gold Bloodrobe (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=4782;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4782,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=4782;

-- Quest "Components for the Enchanted Gold Bloodrobe (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=4783;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4783,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4783;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=6 WHERE `ID`=4783;

-- Quest "Components for the Enchanted Gold Bloodrobe (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=4784;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4784,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4784;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=4784;

-- Quest "The Completed Robe"
DELETE FROM `quest_details` WHERE `ID`=4786;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4786,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=4786;

-- Quest "Devourer of Souls"
DELETE FROM `quest_details` WHERE `ID`=1716;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1716,1,1,1,0,0,0,0,0,0);

-- Quest "Heartswood"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1738;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1738;

-- Quest "The Binding"
DELETE FROM `quest_details` WHERE `ID`=1739;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1739,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=11, `EmoteOnComplete`=11 WHERE `ID`=1739;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=1739;

-- Quest "The Missing Diplomat"
DELETE FROM `quest_details` WHERE `ID`=1274;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1274,1,1,2,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=1274;

-- Quest "The Missing Diplomat (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1241;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1241,2,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6, `EmoteDelay1`=1000 WHERE `ID`=1241;

-- Quest "The Missing Diplomat (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1242;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1242,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1242;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=11 WHERE `ID`=1242;

-- Quest "The Missing Diplomat (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=1243;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1243,1,6,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1243;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=11, `Emote3`=6 WHERE `ID`=1243;

-- Quest "The Missing Diplomat (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=1244;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1244,6,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=1244;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1244;

-- Quest "The Missing Diplomat (Part 6)"
DELETE FROM `quest_details` WHERE `ID`=1245;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1245,5,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1245;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1245;

-- Quest "The Missing Diplomat (Part 7)"
DELETE FROM `quest_details` WHERE `ID`=1246;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1246,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=14, `Emote2`=1 WHERE `ID`=1246;

-- Quest "The Missing Diplomat (Part 8)"
DELETE FROM `quest_details` WHERE `ID`=1447;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1447,14,6,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6 WHERE `ID`=1447;

-- Quest "The Missing Diplomat (Part 9)"
DELETE FROM `quest_details` WHERE `ID`=1247;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1247,11,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3, `Emote2`=1, `Emote3`=1 WHERE `ID`=1247;

-- Quest "The Missing Diplomat (Part 10)"
DELETE FROM `quest_details` WHERE `ID`=1248;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1248,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3, `Emote2`=1, `Emote3`=6, `Emote4`=1 WHERE `ID`=1248;

-- Quest "The Missing Diplomat (Part 11)"
DELETE FROM `quest_details` WHERE `ID`=1249;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1249,6,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=6 WHERE `ID`=1249;

-- Quest "The Missing Diplomat (Part 12)"
DELETE FROM `quest_details` WHERE `ID`=1250;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1250,18,1,1,5,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=1250;

-- Quest "The Missing Diplomat (Part 13)"
DELETE FROM `quest_details` WHERE `ID`=1264;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1264,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `Emote3`=1 WHERE `ID`=1264;

-- Quest "The Missing Diplomat (Part 14)"
DELETE FROM `quest_details` WHERE `ID`=1265;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1265,6,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=1265;

-- Quest "The Missing Diplomat (Part 15)"
DELETE FROM `quest_details` WHERE `ID`=1266;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1266,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=1266;

-- Quest "The Missing Diplomat (Part 16)"
DELETE FROM `quest_details` WHERE `ID`=1324;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1324,5,14,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=1324;

-- Quest "The Missing Diplomat (Part 17)"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1267;

-- Quest "Yorus Barleybrew"
DELETE FROM `quest_details` WHERE `ID` IN (1698,10371);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1698,1,0,0,0,0,0,0,0,0),
(10371,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=25 WHERE `ID` IN (1698,10371);

-- Quest "The Rethban Gauntlet"
DELETE FROM `quest_details` WHERE `ID`=1699;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1699,1,25,1,6,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=1699;

-- Quest "The Shieldsmith"
DELETE FROM `quest_details` WHERE `ID`=1702;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1702,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=1702;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=273 WHERE `ID`=1702;

-- Quest "Fire Hardened Mail"
DELETE FROM `quest_details` WHERE `ID`=1701;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1701,1,1,6,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1701;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=1701;

-- Quest "Furen's Armor"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1782;

-- Quest "Mathiel"
DELETE FROM `quest_details` WHERE `ID`=1703;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1703,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=1703;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=1703;

-- Quest "Sunscorched Shells"
DELETE FROM `quest_details` WHERE `ID`=1710;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1710,1,6,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1710;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1710;

-- Quest "Mathiel's Armor"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=1711;

-- Quest "Grimand Elmore"
DELETE FROM `quest_details` WHERE `ID`=1700;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1700,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=1700;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5 WHERE `ID`=1700;

-- Quest "Burning Blood"
DELETE FROM `quest_details` WHERE `ID`=1705;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1705,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1705;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1705;

-- Quest "Grimand's Armor"
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=1706;

-- Quest "Klockmort Spannerspan"
DELETE FROM `quest_details` WHERE `ID`=1704;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1704,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=1704;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=1704;

-- Quest "Iron Coral"
DELETE FROM `quest_details` WHERE `ID`=1708;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1708,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=1708;
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=5 WHERE `ID`=1708;

-- Quest "Klockmort's Creation"
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=5 WHERE `ID`=1709;

-- Quest "The Islander"
DELETE FROM `quest_details` WHERE `ID`=1718;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1718,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3 WHERE `ID`=1718;

-- Quest "The Affray"
DELETE FROM `quest_details` WHERE `ID`=1719;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1719,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=1719;

-- Quest "The Windwatcher"
DELETE FROM `quest_details` WHERE `ID`=1791;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1791,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1791;

-- Quest "Cyclonian"
DELETE FROM `quest_details` WHERE `ID`=1712;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1712,1,25,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1712;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1712;

-- Quest "The Summoning"
DELETE FROM `quest_details` WHERE `ID`=1713;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1713,1,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=1713;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1713;

-- Quest "Whirlwind Weapon"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1792;

-- Quest "A Troubled Spirit"
DELETE FROM `quest_details` WHERE `ID`=8417;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8417,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8417;

-- Quest "Warrior Kinship"
DELETE FROM `quest_details` WHERE `ID`=8423;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8423,25,1,0,0,500,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=8423;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8423;

-- Quest "War on the Shadowsworn"
DELETE FROM `quest_details` WHERE `ID`=8424;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8424,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=8424;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=8424;

-- Quest "Voodoo Feathers"
DELETE FROM `quest_details` WHERE `ID`=8425;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8425,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=8425;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=8425;

-- Quest "A Donation of Wool" / "A Donation of Silk" / "A Donation of Mageweave" / "A Donation of Runecloth" / "Additional Runecloth"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID` IN (7791,7792,7793,7794,7795,7796,7798,7799,7800,10352,10354,7802,7803,7804,7805,7806,7807,7808,7809,7811,7812,7813,7814,7817,7818,7819,7820,7821,7822,7823,7824,7825,7826,7827,7831,7832,7833,7834,7835,7836,7837,10356,10361,10357,10360,10359);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID` IN (7791,7792,7793,7794,7798,7799,10352,10354,7802,7803,7804,7807,7808,7809,7813,7814,7817,7820,7821,7822,7826,7827,7831,7833,7834,7835,10356,10361,10362,10360,10359);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID` IN (7795,7800,7805,7811,7818,7823,7824,7836,10357,10362);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID` IN (7796,7801,7806,7812,7819,7825,7832,7837,10358,10363);

-- Quest "Malin's Request"
DELETE FROM `quest_details` WHERE `ID`=690;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(690,2,1,6,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=690;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=690;

-- Quest "The Unsent Letter"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=373;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2, `Emote3`=1 WHERE `ID`=373;

-- Quest "Bazil Thredd"
DELETE FROM `quest_details` WHERE `ID`=389;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(389,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `Emote3`=1, `Emote4`=1 WHERE `ID`=389;

-- Quest "The Stockade Riots"
DELETE FROM `quest_details` WHERE `ID`=391;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(391,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=391;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=391;

-- Quest "The Curious Visitor"
DELETE FROM `quest_details` WHERE `ID`=392;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(392,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=392;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=392;

-- Quest "Shadow of the Past"
DELETE FROM `quest_details` WHERE `ID`=393;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(393,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=393;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=393;

-- Quest "Look to an Old Friend"
DELETE FROM `quest_details` WHERE `ID`=350;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(350,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=11, `Emote4`=1 WHERE `ID`=350;

-- Quest "Infiltrating the Castle"
DELETE FROM `quest_details` WHERE `ID`=2745;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2745,1,1,6,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=6, `Emote4`=5 WHERE `ID`=2745;

-- Quest "Items of Some Consequence"
DELETE FROM `quest_details` WHERE `ID`=2746;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2746,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2746;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=2746;

-- Quest "The Attack!"
DELETE FROM `quest_details` WHERE `ID`=434;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(434,1,1,6,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=434;

-- Quest "The Head of the Beast"
DELETE FROM `quest_details` WHERE `ID`=394;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(394,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=11, `Emote4`=2 WHERE `ID`=394;

-- Quest "Brotherhood's End"
DELETE FROM `quest_details` WHERE `ID`=395;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(395,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=395;

-- Quest "An Audience with the King"
DELETE FROM `quest_details` WHERE `ID`=396;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(396,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=396;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=396;

-- Quest "Travel to Darkshire"
DELETE FROM `quest_details` WHERE `ID`=9429;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9429,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=9429;

-- Quest "Stormwind Library"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=579;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=579;

-- Quest "An Old History Book"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=337;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=2 WHERE `ID`=337;

-- Quest "Southshore"
DELETE FROM `quest_details` WHERE `ID`=538;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(538,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=538;

-- Quest "Preserving Knowledge"
DELETE FROM `quest_details` WHERE `ID`=540;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(540,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=540;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=540;

-- Quest "Return to Milton"
DELETE FROM `quest_details` WHERE `ID`=542;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(542,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=542;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2, `Emote3`=1 WHERE `ID`=542;

-- Quest "The Symbol of Life"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID` IN (1789,1790);

-- Quest "Goblin Engineering"
DELETE FROM `quest_details` WHERE `ID` IN (3526,3629,3633,4181);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3526,1,1,0,0,0,0,0,0,0),
(3629,1,1,0,0,0,0,0,0,0),
(3633,1,1,0,0,0,0,0,0,0),
(4181,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1 WHERE `ID` IN (3526,3629,3633,4181);

-- Quest "The Pledge of Secrecy"
DELETE FROM `quest_details` WHERE `ID` IN (3638,3640,3642);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3638,1,0,0,0,0,0,0,0,0),
(3640,1,0,0,0,0,0,0,0,0),
(3642,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID` IN (3638,3640,3642);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID` IN (3638,3640,3642);

-- Quest "Show Your Work"
DELETE FROM `quest_details` WHERE `ID` IN (3639,3641,3643);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3639,1,1,25,0,0,0,0,0,0),
(3641,1,1,25,0,0,0,0,0,0),
(3643,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID` IN (3639,3641,3643);

-- Quest "Gnome Engineering"
DELETE FROM `quest_details` WHERE `ID` IN (3630,3632,3634,3635,3637);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3630,1,1,0,0,0,0,0,0,0),
(3632,1,1,0,0,0,0,0,0,0),
(3634,1,1,0,0,0,0,0,0,0),
(3635,1,1,0,0,0,0,0,0,0),
(3637,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID` IN (3630,3632,3634);
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID` IN (3635,3637);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID` IN (3630,3632,3634);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID` IN (3635,3637);

-- Quest "The Origins of Smithing"
DELETE FROM `quest_details` WHERE `ID`=2758;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2758,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2758;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=2758;

-- Quest "The Old Ways"
DELETE FROM `quest_details` WHERE `ID`=2756;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2756,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=2756;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5 WHERE `ID`=2756;

-- Quest "Booty Bay or Bust!" / "In Search of Galvan"
DELETE FROM `quest_details` WHERE `ID` IN (2757,2759);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2757,25,1,0,0,0,0,0,0,0),
(2759,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID` IN (2757,2759);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID` IN (2757,2759);

-- Quest "The Mithril Order"
DELETE FROM `quest_details` WHERE `ID`=2760;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2760,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2, `EmoteOnIncomplete`=2 WHERE `ID`=2760;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2760;

-- Quest "Smelt On, Smelt Off"
DELETE FROM `quest_details` WHERE `ID`=2761;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2761,1,6,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2761;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=2761;

-- Quest "The Great Silver Deceiver"
DELETE FROM `quest_details` WHERE `ID`=2762;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2762,1,1,2,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2762;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5 WHERE `ID`=2762;

-- Quest "The Art of the Imbue"
DELETE FROM `quest_details` WHERE `ID`=2763;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2763,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2763;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=2763;

-- Quest "Galvan's Finest Pupil"
DELETE FROM `quest_details` WHERE `ID`=2764;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2764,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2 WHERE `ID`=2764;

-- Quest "Expert Blacksmith!"
DELETE FROM `quest_details` WHERE `ID`=2765;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2765,1,1,2,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=2765;

-- Quest "In Search of The Temple"
DELETE FROM `quest_details` WHERE `ID`=1448;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1448,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1448;

-- Quest "To The Hinterlands"
DELETE FROM `quest_details` WHERE `ID`=1449;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1449,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5 WHERE `ID`=1449;

-- Quest "Gryphon Master Talonaxe"
DELETE FROM `quest_details` WHERE `ID`=1450;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1450,1,25,6,5,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=1450;

-- Quest "Rhapsody Shindigger"
DELETE FROM `quest_details` WHERE `ID`=1451;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1451,1,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=33, `Emote2`=14, `Emote3`=33, `Emote4`=5 WHERE `ID`=1451;

-- Quest "Rhapsody's Kalimdor Kocktail"
DELETE FROM `quest_details` WHERE `ID`=1452;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1452,33,6,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1452;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=33 WHERE `ID`=1452;

-- Quest "Rhapsody's Tale"
DELETE FROM `quest_details` WHERE `ID`=1469;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1469,1,33,5,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1469;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=1469;

-- Quest "Into The Temple of Atal'Hakkar"
DELETE FROM `quest_details` WHERE `ID`=1475;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1475,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1475;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2 WHERE `ID`=1475;
*/
