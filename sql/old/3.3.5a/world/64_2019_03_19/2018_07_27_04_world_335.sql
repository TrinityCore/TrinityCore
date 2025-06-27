-- 
-- Quest "A New Threat"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=170;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=170;

-- Quest "A Refugee's Quandary"
DELETE FROM `quest_details` WHERE `ID`=3361;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3361,5,0,0,0,0,0,0,0,0);

-- Quest "The Boar Hunter"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=183;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=183;

-- Quest "The Troll Cave"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=182;
UPDATE `quest_offer_reward` SET `Emote1`=5, `RewardText`="Argh! Those Light-blasted trolls!$B$B<He takes a few breaths and seems to settle down... a bit.>$B$BA group of them came in the night and stole my journal! I knew better than to trust that good-for-nothing appr..." WHERE `ID`=182;

-- Quest "The Stolen Journal"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=218;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=218;

-- Quest "Scalding Mornbrew Delivery"
DELETE FROM `quest_details` WHERE `ID`=3364;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3364,5,0,0,0,0,0,0,0,0);

-- Quest "Senir's Observations"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=66, `EmoteOnComplete`=66 WHERE `ID`=282;

-- Quest "Supplies to Tannok"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=2160;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=2160;

UPDATE `creature_template` SET `ScriptName`="" WHERE `entry`=6806; -- Tannok Frosthammer is not an innkeeper

-- Quest "Speak with Bink"
DELETE FROM `quest_details` WHERE `ID`=1879;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1879,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1879;

-- Quest "Mage-tastic Gizmonitor"
DELETE FROM `quest_details` WHERE `ID`=1880;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1880,1,1,20,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1880;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2 WHERE `ID`=1880;

-- Quest "In Favor of the Light"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=5626;

-- Quest "Garments of the Light"
DELETE FROM `quest_details` WHERE `ID`=5625;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5625,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `RewardText`="Well done, $n. You got the Light inside you, that's for sure.$B$BHere, take this robe. It'll denote your role in the church and help people recognize you as a $c--wear it if you want.$B$BLater, there will be more tests that you'll have to go through. Do what you can to learn about your abilities and what you're capable of. Try your hand at a fight or two alone, and then again with other travelers.$B$BBut don't fret none... you're as powerful as they come." WHERE `ID`=5625;

-- Quest "Tools for Steelgrill"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=400;

-- Quest "Beer Basted Boar Ribs"
DELETE FROM `quest_details` WHERE `ID`=384;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(384,1,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=384;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=384;

-- Quest "Stocking Jetsteam"
DELETE FROM `quest_details` WHERE `ID`=317;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(317,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=317;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=317;

-- Quest "The Grizzled Den"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=313;

-- Quest "Evershine"
DELETE FROM `quest_details` WHERE `ID`=318;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(318,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=318;

-- Quest "A Favor for Evershine"
DELETE FROM `quest_details` WHERE `ID`=319;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(319,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=319;

-- Quest "Ammo for Rumbleshot"
DELETE FROM `quest_details` WHERE `ID`=5541;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5541,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5541;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=5541;

-- Quest "Operation Recombobulation"
DELETE FROM `quest_details` WHERE `ID`=412;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(412,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=412;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=412;

-- Quest "Tundra MacGrann's Stolen Stash"
DELETE FROM `quest_details` WHERE `ID`=312;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(312,1,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=312;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=312;

-- Quest "The Perfect Stout"
DELETE FROM `quest_details` WHERE `ID`=315;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(315,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=315;

-- Quest "Rejold's New Brew"
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=415;

-- Quest "Distracting Jarven"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=308;

-- Quest "Return to Bellowfiz"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=320;

-- Quest "Return to Marleth"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=311;

-- Quest "Protecting the Herd"
DELETE FROM `quest_details` WHERE `ID`=314;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(314,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=314;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=314;

-- Quest "Those Blasted Troggs!"
DELETE FROM `quest_details` WHERE `ID`=432;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(432,5,15,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=15 WHERE `ID`=432;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=432;

-- Quest "A Pilot's Revenge"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=417;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=417;

-- Quest "Shimmer Stout"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=413;
UPDATE `quest_offer_reward` SET `Emote1`=7, `Emote2`=4 WHERE `ID`=413;

-- Quest "Stout to Kadrell"
DELETE FROM `quest_details` WHERE `ID`=414;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(414,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=414;
UPDATE `quest_offer_reward` SET `Emote1`=7, `Emote2`=5 WHERE `ID`=414;

-- Quest "The Reports"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=291;

-- Quest "Deeprun Rat Roundup"
DELETE FROM `quest_details` WHERE `ID`=6661;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6661,25,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=6661;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6661;

-- Quest "Me Brother, Nipsy"
DELETE FROM `quest_details` WHERE `ID`=6662;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6662,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6662;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6662;

-- Quest "The New Frontier"
DELETE FROM `quest_details` WHERE `ID` IN (1000,1004,1015,1018,1019,1047);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1000,15,5,1,0,0,0,0,0,0),
(1004,15,5,1,0,0,0,0,0,0),
(1015,15,5,1,0,0,0,0,0,0),
(1018,15,5,1,0,0,0,0,0,0),
(1019,15,5,1,0,0,0,0,0,0),
(1047,15,5,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID` IN (1015,1019,1047);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID` IN (1000,1004,1018);

UPDATE `quest_template_addon` SET `NextQuestID`=6761 WHERE `ID` IN (1015,1019,1047);
UPDATE `quest_template_addon` SET `NextQuestID`=1123 WHERE `ID` IN (1000,1004,1018);

-- Quest "The New Frontier (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=6761;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6761,1,1,5,25,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=6761;

-- Quest "Rabine Saturna"
DELETE FROM `quest_details` WHERE `ID` IN (6762,1123);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6762,1,1,1,0,0,0,0,0,0),
(1123,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID` IN (6762,1123);

-- Quest "Wasteland"
DELETE FROM `quest_details` WHERE `ID`=1124;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1124,1,6,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=1124;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=1124;

-- Quest "The Spirits of Southwind"
DELETE FROM `quest_details` WHERE `ID`=1125;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1125,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=1125;

-- Quest "Hive in the Tower"
DELETE FROM `quest_details` WHERE `ID`=1126;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1126,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1126;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=1126;

-- Quest "Umber, Archivist"
DELETE FROM `quest_details` WHERE `ID`=6844;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6844,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=6844;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `Emote3`=1 WHERE `ID`=6844;

-- Quest "Uncovering Past Secrets"
DELETE FROM `quest_details` WHERE `ID`=6845;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6845,1,1,6,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=6845;

-- Quest "Under the Chitin Was..."
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=1185;

-- Quest "The Brassbolts Brothers"
DELETE FROM `quest_details` WHERE `ID`=1179;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1179,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=1179;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1179;

-- Quest "Arrows Are For Sissies"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=7342;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=7342;

-- Quest "The Smoldering Ruins of Thaurissan"
DELETE FROM `quest_details` WHERE `ID`=3702;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3702,6,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=3702;

-- Quest "The Smoldering Ruins of Thaurissan (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=3701;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3701,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=3701;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=3701;

-- Quest "Kharan Mighthammer"
DELETE FROM `quest_details` WHERE `ID`=4341;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4341,6,5,18,5,0,0,0,3000,0);
UPDATE `quest_offer_reward` SET `Emote1`=20 WHERE `ID`=4341;

-- Quest "Kharan Mighthammer"
DELETE FROM `quest_details` WHERE `ID`=4341;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4341,6,5,18,5,0,0,0,3000,0);
UPDATE `quest_offer_reward` SET `Emote1`=16 WHERE `ID`=4341;

-- Quest "Kharan's Tale"
DELETE FROM `quest_details` WHERE `ID`=4342;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4342,20,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4342;

-- Quest "The Bearer of Bad News"
DELETE FROM `quest_details` WHERE `ID`=4361;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4361,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=36 WHERE `ID`=4361;

-- Quest "The Fate of the Kingdom"
DELETE FROM `quest_details` WHERE `ID`=4362;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4362,1,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=18 WHERE `ID`=4362;

-- Quest "The Princess's Surprise"
DELETE FROM `quest_details` WHERE `ID`=4363;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4363,5,25,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=4363;

-- Quest "A Little Slime Goes a Long Way"
DELETE FROM `quest_details` WHERE `ID`=4512;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4512,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=4512;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=4512;

-- Quest "A Little Slime Goes a Long Way (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=4513;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4513,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=4513;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=4, `Emote3`=1 WHERE `ID`=4513;

-- Quest "Mythology of the Titans"
DELETE FROM `quest_details` WHERE `ID`=1050;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1050,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=1050;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2 WHERE `ID`=1050;

-- Quest "Powder to Ironband"
UPDATE `quest_details` SET `Emote1`=5 WHERE `ID`=302;

-- Quest "The Lost Dwarves"
DELETE FROM `quest_details` WHERE `ID`=2398;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2398,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=2398;

-- Quest "The Hidden Chamber"
DELETE FROM `quest_details` WHERE `ID`=2240;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2240,1,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `Emote3`=1 WHERE `ID`=2240;

-- Quest "Reclaimed Treasures"
DELETE FROM `quest_details` WHERE `ID`=1360;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1360,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1360;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1360;

-- Quest "Knowledge in the Deeps"
DELETE FROM `quest_details` WHERE `ID`=971;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(971,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=971;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=971;

-- Quest "Passing the Burden"
DELETE FROM `quest_details` WHERE `ID`=3448;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3448,6,1,0,0,0,0,0,0,0);

-- Quest "Arcane Runes"
DELETE FROM `quest_details` WHERE `ID`=3449;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3449,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=4 WHERE `ID`=3449;

-- Quest "An Easy Pickup"
DELETE FROM `quest_details` WHERE `ID`=3450;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3450,1,1,0,0,0,0,0,0,0);

-- Quest "Signal for Pickup"
DELETE FROM `quest_details` WHERE `ID`=3451;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3451,6,1,1,0,0,0,0,0,0);

-- Quest "Signal for Pickup"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=3483;

-- Quest "Return to Tymor"
DELETE FROM `quest_details` WHERE `ID`=3461;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3461,1,1,6,0,0,0,0,0,0);

-- Quest "Klockmort's Essentials"
DELETE FROM `quest_details` WHERE `ID`=2925;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2925,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=2925;

-- Quest "Essential Artificials"
DELETE FROM `quest_details` WHERE `ID`=2924;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2924,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2924;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=2924;

-- Quest "The Grand Betrayal"
DELETE FROM `quest_details` WHERE `ID`=2929;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2929,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=2929;

-- Quest "The Day After"
DELETE FROM `quest_details` WHERE `ID`=2927;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2927,6,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2927;

-- Quest "Gnogaine"
DELETE FROM `quest_details` WHERE `ID`=2926;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2926,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=2926;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2926;

-- Quest "The Only Cure is More Green Glow"
DELETE FROM `quest_details` WHERE `ID`=2962;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2962,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=2962;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2962;

-- Quest "Speak with Shoni"
DELETE FROM `quest_details` WHERE `ID`=2041;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2041,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=2041;

-- Quest "Sully Balloo's Letter"
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=637;

-- Quest "Sara Balloo's Plea"
DELETE FROM `quest_details` WHERE `ID`=683;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(683,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=683;

-- Quest "A King's Tribute"
DELETE FROM `quest_details` WHERE `ID`=686;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(686,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5 WHERE `ID`=686;

-- Quest "A King's Tribute (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=689;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(689,6,6,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=689;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=689;

-- Quest "A King's Tribute (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=700;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(700,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=700;

-- Quest "Supplying the Front"
DELETE FROM `quest_details` WHERE `ID`=1578;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1578,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1578;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1578;

-- Quest "Gearing Redridge"
DELETE FROM `quest_details` WHERE `ID`=1618;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1618,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1618;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1618;

-- Quest "Imperial Plate Armor"
DELETE FROM `quest_details` WHERE `ID` IN (10891,10892);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10891,1,0,0,0,0,0,0,0,0),
(10892,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (10891,10892);

-- Quest "A Blue Light Bargain"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7652;

-- Quest "Imperial Plate Belt"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=7653;
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`="A pleasure doin' business with ya.$B$BAnd $N, wipe that look of disgust off yer face." WHERE `ID`=7653;

-- Quest "Imperial Plate Boots"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=11, `EmoteOnComplete`=11 WHERE `ID`=7654;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7654;

-- Quest "Imperial Plate Bracer"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=7655;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7655;

-- Quest "Imperial Plate Chest"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`="For the chest piece plans, I'll be needin' 30 thorium bars.$B$BOh boy, there you go again. Are you gonna be runnin' to yer blue Gods, askin' why they have forsaken you?!? Toughen up, Nancy! Nobody ever said life's fair." WHERE `ID`=7656;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7656;

-- Quest "Imperial Plate Helm"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=7657;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7657;

-- Quest "Imperial Plate Leggings"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=7658;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7658;

-- Quest "Imperial Plate Shoulders"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=7659;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7659;

-- Quest "The Pledge of Secrecy"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID` IN (3640,3642,3638);

-- Quest "Membership Card Renewal"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID` IN (3646,3647,3644,3645);

-- Quest "I Know A Guy..."
DELETE FROM `quest_details` WHERE `ID` IN (6612,6611);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6612,1,1,273,0,0,0,0,0,0),
(6611,6,274,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=33, `Emote2`=5, `EmoteDelay2`=1000 WHERE `ID` IN (6612,6611);

-- Quest "Clamlette Surprise"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=6610;
UPDATE `quest_offer_reward` SET `Emote1`=25 WHERE `ID`=6610;

-- Quest "Alliance Trauma"
DELETE FROM `quest_details` WHERE `ID`=6625;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6625,1,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6625;

-- Quest "Triage"
DELETE FROM `quest_details` WHERE `ID`=6624;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6624,1,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=6624;

-- Quest "The Platinum Discs"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2279;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=2279;

-- Quest "The Platinum Discs (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=2439;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2439,4,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=2439;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2439;

-- Quest "Portents of Uldum"
DELETE FROM `quest_details` WHERE `ID`=2963;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2963,2,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2963;

-- Quest "Seeing What Happens"
DELETE FROM `quest_details` WHERE `ID`=2946;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2946,1,1,1,0,0,0,0,0,0);

-- Quest "Return to Ironforge"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=2977;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=2977;

-- Quest "A Future Task"
DELETE FROM `quest_details` WHERE `ID`=2964;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2964,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=2964;

-- Quest "Road to Salvation"
DELETE FROM `quest_details` WHERE `ID`=2218;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2218,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=2 WHERE `ID`=2218;

-- Quest "Simple Subterfugin'"
DELETE FROM `quest_details` WHERE `ID`=2238;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2238,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=2 WHERE `ID`=2238;

-- Quest "Onin's Report"
DELETE FROM `quest_details` WHERE `ID`=2239;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2239,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=2239;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=2239;

-- Quest "To Hulfdan!"
DELETE FROM `quest_details` WHERE `ID`=2299;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2299,6,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=25 WHERE `ID`=2299;

-- Quest "Kingly Shakedown"
DELETE FROM `quest_details` WHERE `ID`=2298;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2298,1,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2298;

-- Quest "Tome of Divinity"
DELETE FROM `quest_details` WHERE `ID`=2997;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2997,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2997;

-- Quest "Tome of Divinity"
DELETE FROM `quest_details` WHERE `ID`=3000;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3000,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=3000;

-- Quest "Tome of Divinity"
DELETE FROM `quest_details` WHERE `ID`=2999;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2999,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2999;

-- Quest "Tome of Divinity"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=1645;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=1645;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,1645,0,0,14,0,2997,0,0,0,0,0,"","Quest 'Tome of Divinity (1645)' can only be taken if quest 'Tome of Divinity (2997)' is not taken"),
(19,0,1645,0,0,14,0,3000,0,0,0,0,0,"","Quest 'Tome of Divinity (1645)' can only be taken if quest 'Tome of Divinity (3000)' is not taken"),
(19,0,1645,0,0,14,0,2999,0,0,0,0,0,"","Quest 'Tome of Divinity (1645)' can only be taken if quest 'Tome of Divinity (2999)' is not taken");

-- Quest "Tome of Divinity"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=6, `Emote3`=1, `Emote4`=1 WHERE `ID`=1645;

-- Quest "Tome of Divinity (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1647;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1647,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2, `Emote3`=1 WHERE `ID`=1647;

-- Quest "Tome of Divinity (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1648;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1648,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1648;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1, `Emote4`=2 WHERE `ID`=1648;

-- Quest "Tome of Divinity (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=1778;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1778,1,3,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=1778;

-- Quest "Tome of Divinity (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=1779;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1779,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=33, `Emote2`=2, `Emote3`=1, `Emote4`=1 WHERE `ID`=1779;

-- Quest "Tome of Divinity (Part 6)"
DELETE FROM `quest_details` WHERE `ID`=1783;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1783,1,1,1,6,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=1783;

-- Quest "Tome of Divinity (Part 7)"
DELETE FROM `quest_details` WHERE `ID`=1784;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1784,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1784;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=1784;

-- Quest "Tome of Divinity (Part 8)"
DELETE FROM `quest_details` WHERE `ID`=1785;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1785,1,1,2,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=2 WHERE `ID`=1785;

-- Quest "Taming the Beast"
DELETE FROM `quest_details` WHERE `ID` IN (6064,6084,6085,6086);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6064,1,0,0,0,0,0,0,0,0),
(6084,1,0,0,0,0,0,0,0,0),
(6085,1,0,0,0,0,0,0,0,0),
(6086,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID` IN (6064);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID` IN (6084,6085);
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=6064;
UPDATE `quest_offer_reward` SET `Emote1`=25 WHERE `ID`=6084;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6085;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=6086;

-- Quest "I Got Nothin' Left!"
DELETE FROM `quest_details` WHERE `ID`=6609;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6609,5,25,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6609;

-- Quest "Nat Pagle, Angler Extreme"
DELETE FROM `quest_details` WHERE `ID`=6607;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6607,1,1,5,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=6607;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=6607;

-- Quest "The Shattered Necklace"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2198;
UPDATE `quest_offer_reward` SET `Emote1`=25 WHERE `ID`=2198;

-- Quest "Lore for a Price"
DELETE FROM `quest_details` WHERE `ID`=2199;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2199,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2199;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=2199;

-- Quest "Back to Uldaman"
DELETE FROM `quest_details` WHERE `ID`=2200;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2200,1,0,0,0,0,0,0,0,0);

-- Quest "Replacement Phial"
DELETE FROM `quest_details` WHERE `ID`=3375;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3375,6,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=3375;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3375;

-- Quest "Find the Gems"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2201;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2201;

-- Quest "Restoring the Necklace"
DELETE FROM `quest_details` WHERE `ID`=2204;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2204,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2204;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2204;

-- Quest "Restoring the Necklace"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2361;

-- Quest "An Earnest Proposition"
DELETE FROM `quest_details` WHERE `ID` IN (8905,8906,8907,8908,8909,8910,8911,8912,10492,8913,8914,8915,8916,8917,8918,8919,8920,10493);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8905,2,1,1,0,0,0,0,0,0),
(8906,2,1,1,0,0,0,0,0,0),
(8907,2,1,1,0,0,0,0,0,0),
(8908,2,1,1,0,0,0,0,0,0),
(8909,2,1,1,0,0,0,0,0,0),
(8910,2,1,1,0,0,0,0,0,0),
(8911,2,1,1,0,0,0,0,0,0),
(8912,2,1,1,0,0,0,0,0,0),
(10492,2,1,1,0,0,0,0,0,0),
(8913,2,1,1,0,0,0,0,0,0),
(8914,2,1,1,0,0,0,0,0,0),
(8915,2,1,1,0,0,0,0,0,0),
(8916,2,1,1,0,0,0,0,0,0),
(8917,2,1,1,0,0,0,0,0,0),
(8918,2,1,1,0,0,0,0,0,0),
(8919,2,1,1,0,0,0,0,0,0),
(8920,2,1,1,0,0,0,0,0,0),
(10493,2,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8905,8906,8907,8908,8909,8910,8911,8912,10492,8913,8914,8915,8916,8917,8918,8919,8920,10493);
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1 WHERE `ID` IN (8905,8906,8907,8908,8909,8910,8911,8912,10492,8913,8914,8915,8916,8917,8918,8919,8920,10493);

-- Quest "A Supernatural Device"
DELETE FROM `quest_details` WHERE `ID` IN (8922,8923);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8922,1,1,0,0,0,0,0,0,0),
(8923,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID` IN (8922,8923);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=6 WHERE `ID` IN (8922,8923);

-- Quest "The Ectoplasmic Distiller"
DELETE FROM `quest_details` WHERE `ID`=8921;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8921,5,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=8921;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=8921;

-- Quest "Hunting for Ectoplasm"
DELETE FROM `quest_details` WHERE `ID`=8924;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8924,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8924;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8924;

-- Quest "A Portable Power Source"
DELETE FROM `quest_details` WHERE `ID`=8925;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8925,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8925;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=8925;

-- Quest "A Shifty Merchant"
DELETE FROM `quest_details` WHERE `ID`=8928;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8928,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8928;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=8928;

-- Quest "Return to Deliana"
DELETE FROM `quest_details` WHERE `ID`=8977;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8977,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8977;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8977;

-- Quest "Return to Mokvar"
DELETE FROM `quest_details` WHERE `ID`=8978;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8978,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8978;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8978;

-- Quest "Just Compensation"
DELETE FROM `quest_details` WHERE `ID` IN (8926,8931,8932,8933,8934,8935,8936,8937,10494,8927,8938,8939,8940,8941,8942,8943,8944,10495);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8926,1,1,0,0,0,0,0,0,0),
(8931,1,1,0,0,0,0,0,0,0),
(8932,1,1,0,0,0,0,0,0,0),
(8933,1,1,0,0,0,0,0,0,0),
(8934,1,1,0,0,0,0,0,0,0),
(8935,1,1,0,0,0,0,0,0,0),
(8936,1,1,0,0,0,0,0,0,0),
(8937,1,1,0,0,0,0,0,0,0),
(10494,1,1,0,0,0,0,0,0,0),
(8927,1,1,0,0,0,0,0,0,0),
(8938,1,1,0,0,0,0,0,0,0),
(8939,1,1,0,0,0,0,0,0,0),
(8940,1,1,0,0,0,0,0,0,0),
(8941,1,1,0,0,0,0,0,0,0),
(8942,1,1,0,0,0,0,0,0,0),
(8943,1,1,0,0,0,0,0,0,0),
(8944,1,1,0,0,0,0,0,0,0),
(10495,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8926,8931,8932,8933,8934,8935,8936,8937,10494,8927,8938,8939,8940,8941,8942,8943,8944,10495);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID` IN (8926,8931,8932,8933,8934,8935,8936,8937,10494,8927,8938,8939,8940,8941,8942,8943,8944,10495);

-- Quest "A Supernatural Device"
DELETE FROM `quest_details` WHERE `ID` IN (8929,8930);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8929,1,1,0,0,0,0,0,0,0),
(8930,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID` IN (8929,8930);

-- Quest "Dead Man's Plea"
DELETE FROM `quest_details` WHERE `ID`=8945;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8945,1,5,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=6 WHERE `ID`=8945;

-- Quest "Proof of Life"
DELETE FROM `quest_details` WHERE `ID`=8946;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8946,1,1,2,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8946;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=8946;

-- Quest "Anthion's Strange Request"
DELETE FROM `quest_details` WHERE `ID`=8947;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8947,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8947;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8947;

-- Quest "Anthion's Old Friend"
DELETE FROM `quest_details` WHERE `ID`=8948;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8948,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=8948;

-- Quest "Falrin's Vendetta"
DELETE FROM `quest_details` WHERE `ID`=8949;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8949,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8949;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=8949;

-- Quest "The Instigator's Enchantment"
DELETE FROM `quest_details` WHERE `ID`=8950;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8950,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=8950;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8950;

-- Quest "The Challenge"
DELETE FROM `quest_details` WHERE `ID`=9015;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9015,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=9015;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=9015;

-- Quest "Anthion's Parting Words"
DELETE FROM `quest_details` WHERE `ID` IN (8951,8952,8953,8954,8955,8956,8957,8958,8959,9016,9017,9018,9019,9020,9021,9022,10496,10497);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8951,1,1,1,2,0,0,0,0,0),
(8952,1,1,1,2,0,0,0,0,0),
(8953,1,1,1,2,0,0,0,0,0),
(8954,1,1,1,2,0,0,0,0,0),
(8955,1,1,1,2,0,0,0,0,0),
(8956,1,1,1,2,0,0,0,0,0),
(8957,1,1,1,2,0,0,0,0,0),
(8958,1,1,1,2,0,0,0,0,0),
(8959,1,1,1,2,0,0,0,0,0),
(9016,1,1,1,2,0,0,0,0,0),
(9017,1,1,1,2,0,0,0,0,0),
(9018,1,1,1,2,0,0,0,0,0),
(9019,1,1,1,2,0,0,0,0,0),
(9020,1,1,1,2,0,0,0,0,0),
(9021,1,1,1,2,0,0,0,0,0),
(9022,1,1,1,2,0,0,0,0,0),
(10496,1,1,1,2,0,0,0,0,0),
(10497,1,1,1,2,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID` IN (8951,8952,8953,8954,8955,8956,8957,8958,8959,9016,9017,9018,9019,9020,9021,9022);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID` IN (8951,8952,8953,8954,8955,8956,8958,8959);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID` IN (9016,9017,9018,9019,9020,9021,9022);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `RewardText`="This curse was bestowed upon us but for a mere medallion. Lord Valthalak certainly knows how to hold a grudge.$B$BWe'll endeavor to find the remaining pieces - hopefully before I meet an untimely demise. But before that, let us see about your reward." WHERE `ID`=8957;
DELETE FROM `quest_request_items` WHERE `ID` IN (10496,10497);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(10496,1,1,"You're back, $N. You must tell me all about what you've found out. But first let us arrange for your reward.",0),
(10497,1,1,"You've returned and I see in your eyes that you've much to tell me, $N. Let us take care of your reward first.",0);
DELETE FROM `quest_offer_reward` WHERE `ID` IN (10496,10497);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(10496,5,1,0,0,0,0,0,0,"I can't believe our lives are all but forfeit all because of a stupid medallion! And you're sure Anthion mentioned Bodley?$B$BWell, you've done your job so let's get your reward out of the way.",0),
(10497,6,1,0,0,0,0,0,0,"This curse was bestowed upon us but for a mere medallion. Lord Valthalak certainly knows how to hold a grudge.$B$BWe'll endeavor to find the remaining pieces - hopefully before I meet an untimely demise. But before that, let us see about your reward.",0);

-- Quest "Bodley's Unfortunate Fate"
DELETE FROM `quest_details` WHERE `ID` IN (8960,9032);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8960,6,1,1,0,0,0,0,0,0),
(9032,5,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=6, `Emote3`=1, `Emote4`=2 WHERE `ID` IN (8960,9032);

-- Quest "Three Kings of Flame"
DELETE FROM `quest_details` WHERE `ID`=8961;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8961,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=8961;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=8961;

-- Quest "Components of Importance"
DELETE FROM `quest_details` WHERE `ID` IN (8962,8963,8964,8965);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8962,1,1,1,0,0,0,0,0,0),
(8963,1,1,1,0,0,0,0,0,0),
(8964,1,1,1,0,0,0,0,0,0),
(8965,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8962,8963,8964,8965);
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1 WHERE `ID` IN (8962,8963,8964,8965);

-- Quest "The Left Piece of Lord Valthalak's Amulet"
DELETE FROM `quest_details` WHERE `ID` IN (8966,8967,8968,8969);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8966,1,1,1,0,0,0,0,0,0),
(8967,1,1,1,0,0,0,0,0,0),
(8968,1,1,1,0,0,0,0,0,0),
(8969,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8966,8967,8968,8969);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID` IN (8966,8967,8968,8969);

-- Quest "I See Alcaz Island In Your Future..."
DELETE FROM `quest_details` WHERE `ID`=8970;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8970,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=8970;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=8970;

-- Quest "More Components of Importance"
DELETE FROM `quest_details` WHERE `ID` IN (8985,8986,8987,8988);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8985,1,1,1,0,0,0,0,0,0),
(8986,1,1,1,0,0,0,0,0,0),
(8987,1,1,1,0,0,0,0,0,0),
(8988,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8985,8986,8987,8988);
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1 WHERE `ID` IN (8985,8986,8987,8988);

-- Quest "The Right Piece of Lord Valthalak's Amulet"
DELETE FROM `quest_details` WHERE `ID` IN (8989,8990,8991,8992);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8989,1,1,1,0,0,0,0,0,0),
(8990,1,1,1,0,0,0,0,0,0),
(8991,1,1,1,0,0,0,0,0,0),
(8992,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8989,8990,8991,8992);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID` IN (8989,8990,8991,8992);

-- Quest "Final Preparations"
DELETE FROM `quest_details` WHERE `ID`=8994;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8994,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2, `EmoteOnComplete`=2 WHERE `ID`=8994;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=8994;

-- Quest "Final Preparations"
DELETE FROM `quest_details` WHERE `ID`=8995;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8995,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=15, `EmoteOnComplete`=15 WHERE `ID`=8995;

-- Quest "Final Preparations"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=8996;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=2 WHERE `ID`=8996;

-- Quest "Back to the Beginning"
DELETE FROM `quest_details` WHERE `ID` IN (8997,8998);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8997,1,1,0,0,0,0,0,0,0),
(8998,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID` IN (8997,8998);

-- Quest "Saving the Best for Last"
DELETE FROM `quest_details` WHERE `ID` IN (8999,9000,9001,9002,9003,9004,9005,9006,9007,9008,9009,9010,9011,9012,9013,9014,10498,10499);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8999,1,1,0,0,0,0,0,0,0),
(9000,1,1,0,0,0,0,0,0,0),
(9001,1,1,0,0,0,0,0,0,0),
(9002,1,1,0,0,0,0,0,0,0),
(9003,1,1,0,0,0,0,0,0,0),
(9004,1,1,0,0,0,0,0,0,0),
(9005,1,1,0,0,0,0,0,0,0),
(9006,1,1,0,0,0,0,0,0,0),
(9007,1,1,0,0,0,0,0,0,0),
(9008,1,1,0,0,0,0,0,0,0),
(9009,1,1,0,0,0,0,0,0,0),
(9010,1,1,0,0,0,0,0,0,0),
(9011,1,1,0,0,0,0,0,0,0),
(9012,1,1,0,0,0,0,0,0,0),
(9013,1,1,0,0,0,0,0,0,0),
(9014,1,1,0,0,0,0,0,0,0),
(10498,1,1,0,0,0,0,0,0,0),
(10499,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (8999,9000,9001,9002,9003,9004,9005,9006,9007,9008,9009,9010,9011,9012,9013,9014);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID` IN (8999,9000,9001,9002,9003,9004,9005,9006,9007,9008,9009,9010,9011,9012,9013,9014);
DELETE FROM `quest_request_items` WHERE `ID` IN (10498,10499);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(10498,6,6,"As per our deal, are you ready to hand over your Wildheart pieces in exchange for your new Feralheart Cowl and Vest?",0),
(10499,6,6,"As per our deal, are you ready to hand over your Magister's pieces in exchange for your new Sorcerer's Crown and Robes?",0);
DELETE FROM `quest_offer_reward` WHERE `ID` IN (10498,10499);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(10498,1,2,0,0,0,0,0,0,"I'm going to miss you, $N. I owe you such a debt of gratitude; I think I'll never be able to repay it.$B$BI hope that you enjoy your new head and chest armor, and that it protects you for a long time to come.",0),
(10499,1,2,0,0,0,0,0,0,"I will truly miss you, $N. There is a debt that I owe you, which I may never be able to repay.$B$BEnjoy your new head and chest armor. May it protect you for a long time to come, and help you to achieve even greater honor!",0);

-- Quest "The Art of the Armorsmith"
DELETE FROM `quest_details` WHERE `ID`=5283;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5283,1,1,1,6,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=5283;
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1 WHERE `ID`=5283;

-- Quest "The Art of the Armorsmith"
DELETE FROM `quest_details` WHERE `ID`=5301;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5301,1,1,1,6,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=5301;
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1 WHERE `ID`=5301;

-- Quest "The Way of the Weaponsmith"
DELETE FROM `quest_details` WHERE `ID`=5284;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5284,1,1,1,25,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5284;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=5284;

-- Quest "The Way of the Weaponsmith"
DELETE FROM `quest_details` WHERE `ID`=5302;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5302,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=4, `EmoteOnComplete`=4 WHERE `ID`=5302;
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1 WHERE `ID`=5302;
