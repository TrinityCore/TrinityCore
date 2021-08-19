-- Quest: Alliance Relations
DELETE FROM `quest_details` WHERE `ID`=1431;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1431,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1431;

-- Quest: Alliance Relations (Part 2)
DELETE FROM `quest_details` WHERE `ID`=1432;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1432,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1432;

-- Quest: Alliance Relations (Part 3)
DELETE FROM `quest_details` WHERE `ID`=1433;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1433,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1433;

-- Quest: The Burning of Spirits
DELETE FROM `quest_details` WHERE `ID`=1435;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1435,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1435;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1435;

-- Quest: Alliance Relations (Part 4)
DELETE FROM `quest_details` WHERE `ID`=1436;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1436,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1436;

-- Quest: Catch of the Day
DELETE FROM `quest_details` WHERE `ID`=5386;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5386,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5386;

-- Quest: Befouled by Satyr
DELETE FROM `quest_details` WHERE `ID`=1434;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1434,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1434;

-- Quest: Kodo Roundup
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5561;

-- Quest: Bone Collector
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5501;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=5501;

-- Quest: Khan Dez'hepah
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1365;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1365;

-- Quest: Centaur Bounty
DELETE FROM `quest_details` WHERE `ID`=1366;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1366,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1366;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=1366;

-- Quest: The Corrupter
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1480;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1480;

-- Quest: The Corrupter (Part 2)
DELETE FROM `quest_details` WHERE `ID`=1481;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1481,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1481;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1481;

-- Quest: The Corrupter (Part 3)
DELETE FROM `quest_details` WHERE `ID`=1482;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1482,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1482;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1482;

-- Quest: The Corrupter (Part 4)
DELETE FROM `quest_details` WHERE `ID`=1484;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1484,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1484;

-- Quest: The Corrupter (Part 5)
DELETE FROM `quest_details` WHERE `ID`=1488;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1488,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=15 WHERE `ID`=1488;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=1488;

-- Quest: Hunting in Stranglethorn
DELETE FROM `quest_details` WHERE `ID`=5763;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5763,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5763;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5763;

-- Quest: Hand of Iruxos
DELETE FROM `quest_details` WHERE `ID`=5381;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5381,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5381;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5381;

-- Quest: Portals of the Legion
DELETE FROM `quest_details` WHERE `ID`=5581;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5581,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=5581;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=5581;

-- Quest: Other Fish to Fry
DELETE FROM `quest_details` WHERE `ID`=6143;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6143,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6143;

-- Quest: Clam Bait
DELETE FROM `quest_details` WHERE `ID`=6142;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6142,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6142;

-- Quest: Fish in a Bucket
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=5421;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5421;

-- Quest: Sceptre of Light
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=5741;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`="Do you have the Sceptre of Light?" WHERE `ID`=5741;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5741;

-- Quest: Book of the Ancients
DELETE FROM `quest_details` WHERE `ID`=6027;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6027,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`="Ah, $N! It's good to see you again. Do you have the Book of the Ancients?" WHERE `ID`=6027;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=6027;

-- Quest: Twisted Evils
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7028;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=7028;
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=7028;

-- Quest: Ghost-o-plasm Round Up
DELETE FROM `quest_details` WHERE `ID`=6134;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6134;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=6134;

-- Quest: Get Me Out of Here!
DELETE FROM `quest_details` WHERE `ID`=6132;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6132,5,0,0,0,0,0,0,0,0);

-- Quest: Vyletongue Corruption
DELETE FROM `quest_details` WHERE `ID`=7029;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(7029,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=7029;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=7029;

-- Quest: Steelsnap
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1131;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1131;

-- Quest: The Sacred Flame
DELETE FROM `quest_details` WHERE `ID`=1195;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1195,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1195;

-- Quest: The Sacred Flame (Part 2)
DELETE FROM `quest_details` WHERE `ID`=1196;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1196,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1196;

-- Quest: The Sacred Flame (Part 3)
DELETE FROM `quest_details` WHERE `ID`=1197;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1197,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1197;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1197;

-- Quest: Message to Freewind Post
DELETE FROM `quest_details` WHERE `ID`=4542;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(4542,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=4542;

-- Quest: Pacify the Centaur
DELETE FROM `quest_details` WHERE `ID`=4841;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(4841,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=4841;

-- Quest: Grimtotem Spying
DELETE FROM `quest_details` WHERE `ID`=5064;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5064,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5064;

-- Quest: Alien Egg
DELETE FROM `quest_details` WHERE `ID`=4821;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(4821,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4821;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4821;

-- Quest: Serpent Wild
DELETE FROM `quest_details` WHERE `ID`=4865;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(4865,1,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=4865;

-- Quest: Sacred Fire
DELETE FROM `quest_details` WHERE `ID`=5062;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5062,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5062;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5062;

-- Quest: Arikara
DELETE FROM `quest_details` WHERE `ID`=5088;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5088,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5088;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2 WHERE `ID`=5088;

-- Quest: Wind Rider
DELETE FROM `quest_details` WHERE `ID`=4767;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(4767,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4767;

-- Quest: A Different Approach
DELETE FROM `quest_details` WHERE `ID`=9431;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9431,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9431;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9431;

-- Quest: A Dip in the Moonwell
DELETE FROM `quest_details` WHERE `ID`=9433;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9433,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9433;

-- Quest: Testing the Tonic
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9434;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=9434;

-- Quest: Test of Faith
DELETE FROM `quest_details` WHERE `ID`=1149;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1149,2,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1149;

-- Quest: Test of Endurance
DELETE FROM `quest_details` WHERE `ID`=1150;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1150,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1150;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1150;

-- Quest: Test of Strength
DELETE FROM `quest_details` WHERE `ID`=1151;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1151,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1151;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1151;

-- Quest: Test of Lore
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=1152;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1152;

-- Quest: Test of Lore (Part 2)
DELETE FROM `quest_details` WHERE `ID`=1154;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1154,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1154;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1154;

-- Quest: Test of Lore (Part 3)
DELETE FROM `quest_details` WHERE `ID`=6627;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6627,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6627;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6627;

-- Quest: Test of Lore (Part 4)
DELETE FROM `quest_details` WHERE `ID`=1159;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1159,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=274, `EmoteDelay2`=2000 WHERE `ID`=1159;

-- Quest: Test of Lore (Part 5)
DELETE FROM `quest_details` WHERE `ID`=1160;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1160,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1160;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1160;

-- Quest: Test of Lore (Part 6)
DELETE FROM `quest_details` WHERE `ID`=6628;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6628,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6628;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=6628;

-- Quest: Final Passage
DELETE FROM `quest_details` WHERE `ID`=1394;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1394,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1394;

-- Quest: Homeward Bound
UPDATE `quest_details` SET `Emote1`=20 WHERE `ID`=4770;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=4770;

-- Quest: Free at Last
DELETE FROM `quest_details` WHERE `ID`=4904;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(4904,1,0,0,0,0,0,0,0,0);

-- Quest: Assassination Plot
UPDATE `quest_offer_reward` SET `Emote1`=11, `EmoteDelay1`=1000 WHERE `ID`=4881;

-- Quest: Protect Kanati Greycloud
DELETE FROM `quest_details` WHERE `ID`=4966;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(4966,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4966;

-- Quest: Hypercapacitor Gizmo
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5151;

-- Quest: Wanted - Arnak Grimtotem
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5147;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5147;

-- Quest: Family Tree
DELETE FROM `quest_details` WHERE `ID`=5361;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5361,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5361;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5361;

-- Quest: A Bump in the Road
DELETE FROM `quest_details` WHERE `ID`=1175;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1175,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1175;

-- Quest: Hardened Shells
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1105;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=5, `Emote3`=11, `RewardText`="You got them! Thanks, $N!$B$BWow, these shells are harder than I thought! When I work with them I'll probably need a whole box full of tools!" WHERE `ID`=1105;

-- Quest: Salt Flat Venom
DELETE FROM `quest_details` WHERE `ID`=1104;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1104,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1104;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1104;

-- Quest: Wharfmaster Dizzywig
DELETE FROM `quest_details` WHERE `ID`=1111;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1111,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1111;

-- Quest: Parts for Kravel
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1112;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1112;

-- Quest: Delivery to the Gnomes
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1114;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1114;

-- Quest: Rocket Car Parts
DELETE FROM `quest_details` WHERE `ID`=1110;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1110,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1110;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1110;

-- Quest: Hemet Nesingwary Jr.
DELETE FROM `quest_details` WHERE `ID`=5762;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5762,1,0,0,0,0,0,0,0,0);

-- Quest: Load Lightening
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=1176;

-- Quest: Encrusted Tail Fins
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=1107;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1107;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1107;

-- Quest: Martek the Exiled
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=1106;
UPDATE `quest_request_items` SET `EmoteOnComplete`=35 WHERE `ID`=1106;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1106;

-- Quest: Indurium
DELETE FROM `quest_details` WHERE `ID`=1108;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1108,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1108;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1108;

-- Quest: News for Fizzle
DELETE FROM `quest_details` WHERE `ID`=1137;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1137,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=1137;

-- Quest: The Swarm Grows (Part 2)
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=1146;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1146;

-- Quest: The Swarm Grows (Part 3)
UPDATE `quest_offer_reward` SET `Emote3`=1, `Emote4`=2 WHERE `ID`=1147;

-- Quest: Parts of the Swarm
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1148;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1148;

-- Quest: Parts of the Swarm (Part 2)
DELETE FROM `quest_details` WHERE `ID`=1184;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1184,1,0,0,0,0,0,0,0,0);

-- Quest: The Brassbolts Brothers
DELETE FROM `quest_details` WHERE `ID`=2769;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(2769,6,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=2769;

-- Quest: Gahz'rilla
DELETE FROM `quest_details` WHERE `ID`=2770;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(2770,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2770;

-- Quest: The Rumormonger
DELETE FROM `quest_details` WHERE `ID`=1115;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1115,1,0,0,0,0,0,0,0,0);

-- Quest: Dream Dust in the Swamp
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1116;

-- Quest: Rumors for Kravel
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1117;

-- Quest: Back to Booty Bay
DELETE FROM `quest_details` WHERE `ID`=1118;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1118,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=1118;

-- Quest: Zanzil's Mixture and a Fool's Stout
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=1119;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1119;

-- Quest: Get the Goblins Drunk
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1121;

-- Quest: Get the Gnomes Drunk
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1120;

-- Quest: Report Back to Fizzlebub
DELETE FROM `quest_details` WHERE `ID`=1122;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1122,11,1,0,0,0,0,0,0,0);

-- Quest: Goblin Sponsorship
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1180;

-- Quest: Goblin Sponsorship (Part 3)
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1182;

-- Quest: The Eighteenth Pilot
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1186;

-- Quest: Razzeric's Tweaking
DELETE FROM `quest_details` WHERE `ID`=1187;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1187;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1187;

-- Quest: Safety First
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1188;

-- Quest: Welcome to the Jungle
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=583;

-- Quest: Raptor Mastery
DELETE FROM `quest_details` WHERE `ID`=194;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(194,6,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=194;

-- Quest: Raptor Mastery (Part 2)
DELETE FROM `quest_details` WHERE `ID`=195;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(195,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=195;

-- Quest: Raptor Mastery (Part 3)
DELETE FROM `quest_details` WHERE `ID`=196;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(196,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=196;

-- Quest: Raptor Mastery (Part 4)
DELETE FROM `quest_details` WHERE `ID`=197;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(197,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=197;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=197;

-- Quest: Tiger Mastery
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=185;

-- Quest: Tiger Mastery (Part 2)
DELETE FROM `quest_details` WHERE `ID`=186;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(186,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=186;

-- Quest: Tiger Mastery (Part 3)
DELETE FROM `quest_details` WHERE `ID`=187;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(187,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=187;

-- Quest: Tiger Mastery (Part 4)
DELETE FROM `quest_details` WHERE `ID`=188;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(188,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=188;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=188;

-- Quest: Panther Mastery
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=190;

-- Quest: Panther Mastery (Part 2)
DELETE FROM `quest_details` WHERE `ID`=191;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(191,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=191;

-- Quest: Panther Mastery (Part 3)
DELETE FROM `quest_details` WHERE `ID`=192;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(192,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=192;

-- Quest: Panther Mastery (Part 4)
DELETE FROM `quest_details` WHERE `ID`=193;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(193,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=193;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=193;

-- Quest: Big Game Hunter
DELETE FROM `quest_details` WHERE `ID`=208;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(208,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=208;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1, `Emote4`=4 WHERE `ID`=208;

-- Quest: The Green Hills of Stranglethorn
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=338;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=338;

-- Quest: Mok'thardin's Enchantment
DELETE FROM `quest_details` WHERE `ID`=570;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(570,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=570;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=570;

-- Quest: Mok'thardin's Enchantment (Part 2)
DELETE FROM `quest_details` WHERE `ID`=572;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(572,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=572;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=572;

-- Quest: Mok'thardin's Enchantment (Part 3)
DELETE FROM `quest_details` WHERE `ID`=571;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(571,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=571;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=571;

-- Quest: Mok'thardin's Enchantment (Part 4)
DELETE FROM `quest_details` WHERE `ID`=573;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(573,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=573;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=573;

-- Quest: The Defense of Grom'gol
DELETE FROM `quest_details` WHERE `ID`=568;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(568,66,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=568;

-- Quest: The Defense of Grom'gol (Part 2)
DELETE FROM `quest_details` WHERE `ID`=569;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(569,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=569;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=569;

-- Quest: Grim Message
DELETE FROM `quest_details` WHERE `ID`=2932;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(2932,1,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2932;

-- Quest: Hunt for Yenniku
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=581;

-- Quest: Bloody Bone Necklaces
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=596;

-- Quest: The Vile Reef
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=629;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote1`=2 WHERE `ID`=629;

-- Quest: Venture Company Mining
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=600;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=600;

-- Quest: Scaring Shaky
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `EmoteOnIncomplete`=25 WHERE `ID`=606;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=606;

-- Quest: Return to MacKinley
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=607;
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=607;

-- Quest: The Bloodsail Buccaneers (Part 1)
DELETE FROM `quest_details` WHERE `ID`=595;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(595,1,0,0,0,0,0,0,0,0);

-- Quest: The Bloodsail Buccaneers (Part 3)
DELETE FROM `quest_details` WHERE `ID`=599;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(599,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=599;

-- Quest: The Bloodsail Buccaneers (Part 4)
DELETE FROM `quest_details` WHERE `ID`=604;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(604,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=604;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=604;

-- Quest: The Bloodsail Buccaneers (Part 5)
DELETE FROM `quest_details` WHERE `ID`=608;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(608,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=608;

-- Quest: Whiskey Slim's Lost Grog
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=580;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=580;

-- Quest: Stoley's Debt
DELETE FROM `quest_details` WHERE `ID`=2872;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(2872,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2872;

-- Quest: Stoley's Shipment
DELETE FROM `quest_details` WHERE `ID`=2873;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(2873,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2873;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2873;

-- Quest: Deliver to MacKinley
DELETE FROM `quest_details` WHERE `ID`=2874;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(2874,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=2874;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2874;

-- Quest: Keep An Eye Out
DELETE FROM `quest_details` WHERE `ID`=576;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(576,6,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=3, `EmoteOnIncomplete`=3 WHERE `ID`=576;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=576;

-- Quest: Up to Snuff
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=587;

-- Quest: Hostile Takeover
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=213;

-- Quest: Bloodscalp Ears
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=189;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=189;

-- Quest: Skullsplitter Tusks
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=209;

-- Quest: Akiris by the Bundle
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=617;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=617;

-- Quest: Split Bone Necklace
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=598;

-- Quest: Message in a Bottle
DELETE FROM `quest_details` WHERE `ID`=630;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(630,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=630;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=630;

-- Quest: The Captain's Chest
DELETE FROM `quest_details` WHERE `ID`=614;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(614,1,5,0,0,0,2000,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=3, `EmoteOnIncomplete`=3 WHERE `ID`=614;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=614;

-- Quest: The Monogrammed Sash
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=8552;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=8552;

-- Quest: The Captain's Cutlass
DELETE FROM `quest_details` WHERE `ID`=8553;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8553,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3 WHERE `ID`=8553;

-- Quest: Facing Negolash
DELETE FROM `quest_details` WHERE `ID`=8554;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8554,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=8554;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=2 WHERE `ID`=8554;

-- Quest: Cracking Maury's Foot
DELETE FROM `quest_details` WHERE `ID`=613;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(613,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=613;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=613;
