ALTER TABLE `quest_template_addon`
ADD COLUMN `BreadcrumbForQuestId` MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `ExclusiveGroup`;

-- Assisting Arch Druid Runetotem
UPDATE `quest_template_addon` SET `NextQuestID` = 0,`ExclusiveGroup`=0,`BreadcrumbForQuestId` = 3761 WHERE `ID` IN (936, 3762, 3784);

-- Assisting Arch Druid Staghelm
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0, `BreadcrumbForQuestId` = 3764 WHERE `ID` IN (3763, 3789, 3790, 10520);

-- Lost Deathstalkers
DELETE FROM `quest_template_addon` WHERE `ID` IN (428,429);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (428, 429);

-- On Guard in Stonetalon
DELETE FROM `quest_template_addon` WHERE `ID` IN (1070);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (1070, 1085);

-- The Crown of Will
DELETE FROM `quest_template_addon` WHERE `ID` IN (495,518);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (495,518);

-- Camp Mojache
DELETE FROM `quest_template_addon` WHERE `ID` IN (7489,7492);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (7492,7489);

-- Feathermoon Stronghold
DELETE FROM `quest_template_addon` WHERE `ID` IN (7488,7494);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (7494,7488);

-- Journey to Stonetalon Peak
DELETE FROM `quest_template_addon` WHERE `ID` IN (1056);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (1056,1057);

-- Castpipe's Task
DELETE FROM `quest_template_addon` WHERE `ID` IN (2931);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (2931,2930);

-- Kayneth Stillwind
DELETE FROM `quest_template_addon` WHERE `ID` IN (1011);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1011 WHERE `ID`=4581;

-- Carendin Summons
UPDATE `quest_template` SET `AllowableRaces` = 512 WHERE `Id` = 10605;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1472 WHERE `ID`=10605;


-- Seeking Strahad (Horde)
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0,`BreadcrumbForQuestId` = 1801 WHERE `ID` IN (2996,3001);

-- Seeking Strahad (Alliance)
DELETE FROM `quest_template_addon` WHERE `ID` IN (1758);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1758 WHERE `ID`=1798;

-- A Helping Hand
DELETE FROM `quest_template_addon` WHERE `ID` IN (9533);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (9533,9517);

-- Trouble In Darkshore?
UPDATE `quest_template` SET `AllowableRaces` = 1101  WHERE `Id` IN (729,730,731,741,942,943);
DELETE FROM `quest_template_addon` WHERE `ID` IN (730);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (730,729);

-- Yorus Barleybrew
UPDATE `quest_template_addon` SET `NextQuestID`=0, `ExclusiveGroup`=0, `BreadcrumbForQuestId` = 1699 WHERE `ID` IN (1698,10371);

-- Speak with Ruga
UPDATE `quest_template_addon` SET `PrevQuestId`=0 WHERE `ID`=1824;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1824 WHERE `ID`=1823;

-- A Strange One
DELETE FROM `quest_template_addon` WHERE `ID` IN (6605);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (6605,4505);

-- A Call to Arms: The Plaguelands! (horde)
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0,`BreadcrumbForQuestId`=5096 WHERE `ID` IN (5093, 5094, 5095, 10374);

-- A Call to Arms: The Plaguelands! (alliance)
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0,`BreadcrumbForQuestId`=5092 WHERE `ID` IN (5066, 5090, 5091, 10373);

-- Trouble in Winterspring!
DELETE FROM `quest_template_addon` WHERE `ID` IN (5082, 6603);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (6603,5082);

-- Neeka Bloodscar
DELETE FROM `quest_template_addon` WHERE `ID` IN (1418);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (1418,1420);

-- Taking Back Silithus
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0,`BreadcrumbForQuestId`=8280 WHERE `ID` IN (8275,8276);

-- To Winterspring! & Starfall
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0,`BreadcrumbForQuestId` = 5244 WHERE `ID` IN (5249,5250);

-- Tinkee Steamboil
UPDATE `quest_template_addon` SET `PrevQuestID`=4810 WHERE `ID`=4734;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=4734 WHERE `ID`=4907;

-- Westbrook Garrison Needs Help!
DELETE FROM `quest_template_addon` WHERE `ID` IN (11);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=11 WHERE `ID`=239;

-- Elmore's Task
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=353;
DELETE FROM `quest_template_addon` WHERE `ID` IN (1097);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (1097,353);

-- Brother Anton
DELETE FROM `quest_template_addon` WHERE `ID` IN (6141);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (6141,261);

-- Chillwind Camp
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=8414;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=8414 WHERE `ID`=8415;

-- Report to Jennea
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1920 WHERE `ID`=1919;

-- High Sorcerer Andromath
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1938 WHERE `ID`=1939;

-- Vital Supplies
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=1395;
DELETE FROM `quest_template_addon` WHERE `ID` IN (1477);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (1477,1395);

-- Tabetha's Task
DELETE FROM `quest_template_addon` WHERE `ID` IN (2861);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (2861,2846);

-- James Hyal
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=1302;
DELETE FROM `quest_template_addon` WHERE `ID` IN (1301);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (1301,1302);

-- Morgan Stern
DELETE FROM `quest_template_addon` WHERE `ID` IN (1204, 1260);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (1260,1204);

-- Mayara Brightwing
DELETE FROM `quest_template_addon` WHERE `ID` IN (4764,4766);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (4766,4764);

-- Tinkmaster Overspark
DELETE FROM `quest_template_addon` WHERE `ID` IN (2922,2923);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (2923,2922);

-- Knowledge of the Orb of Orahil
UPDATE `quest_template` SET `AllowableRaces` = 690  WHERE `Id` IN (4967);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0,`BreadcrumbForQuestId`=1799 WHERE `ID` IN (4965,4967,4968,4969);

-- In Search of Menara Voidrender
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0,`BreadcrumbForQuestId`=1796 WHERE `ID` IN (4736,4737,4738,4739);

-- Gakin's Summons / The Slaughtered Lamb
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0,`BreadcrumbForQuestId`=1688 WHERE `ID` IN (1685, 1715);

-- Gakin's Summons
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=1716;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1716 WHERE `ID` = 1717;

-- Jonespyre's Request
UPDATE `quest_template` SET `AllowableRaces` = 1101  WHERE `Id` = 3787;
UPDATE `quest_template_addon` SET `PrevQuestID`=3785 WHERE `ID` = 3791;
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0, `BreadcrumbForQuestId`=3791 WHERE `ID` IN (3787,3788);

-- Malin's Request
DELETE FROM `quest_template_addon` WHERE `ID` IN (690,691);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (690,691);

-- Report to Anastasia
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1960 WHERE `ID` = 1959;

-- Speak with Deino
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1944 WHERE `ID` = 1943;

-- Torwa Pathfinder
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=9052;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=9052 WHERE `ID` = 9063;

-- The Hermit
DELETE FROM `quest_template_addon` WHERE `ID` IN (165,148);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (165,148);

-- Deliveries to Sven
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=95 WHERE `ID` = 164;

-- Raven Hill
DELETE FROM `quest_template_addon` WHERE `ID` IN (5, 163);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (163,5);

-- Enraged Wildkin
DELETE FROM `quest_template_addon` WHERE `ID` IN (6604);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (6604,4861);

-- Ironband's Excavation
DELETE FROM `quest_template_addon` WHERE `ID` IN (436);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (436,297);

-- Stonegear's Search
DELETE FROM `quest_template_addon` WHERE `ID` IN (466,467);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (467,466);

-- Mountaineer Stormpike's Task
DELETE FROM `quest_template_addon` WHERE `ID` IN (1339);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (1339,1338);

-- Report to Mountaineer Rockgar
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=455;
DELETE FROM `quest_template_addon` WHERE `ID` IN (468);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (468,455);

-- Find Bingles
DELETE FROM `quest_template_addon` WHERE `ID` IN (2039);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (2039,2038);

-- The Greenwarden
DELETE FROM `quest_template_addon` WHERE `ID` IN (463);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (463,276);

-- Rejold's New Brew
UPDATE `quest_template_addon` SET `PrevQuestID` = 315 WHERE `ID` = 413;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 413 WHERE `Id` = 415;

-- Klockmort's Essentials
DELETE FROM `quest_template_addon` WHERE `ID` IN (2925);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (2925,2924);

-- Speak with Shoni
DELETE FROM `quest_template_addon` WHERE `ID` IN (2041);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (2041,2040);

-- Imperial Plate Armor
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 7652 WHERE `Id` IN (10891,10892);

-- I Know A Guy... / To Gadgetzan You Go!
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 6610 WHERE `Id` IN (6611,6612);

-- Alliance Trauma
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 6624 WHERE `Id` IN (6625);

-- I Got Nothin' Left!
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 6607 WHERE `Id` IN (6609);

-- Trollbane
DELETE FROM `quest_template_addon` WHERE `ID` IN (638, 639);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (638, 639);

-- Horde Trauma
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 6622 WHERE `Id` IN (6623);

-- The Hermit of Witch Hill / The Hermit of Swamplight Manor
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1218 WHERE `Id` IN (11177);
DELETE FROM `quest_template_addon` WHERE `ID` IN (11225);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (11225, 1218);

-- Vivian Lagrave
DELETE FROM `quest_template_addon` WHERE `ID` IN (4133, 4134);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (4133, 4134);

-- Vivian Lagrave and the Darkstone Tablet
DELETE FROM `quest_template_addon` WHERE `ID` IN (4768, 4769);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (4769, 4768);

-- Yuka Screwspigot
DELETE FROM `quest_template_addon` WHERE `ID` IN (4136, 4324);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (4324, 4136);

-- Help Watcher Biggs
DELETE FROM `quest_template_addon` WHERE `ID` IN (9609);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (9609, 1396);

-- Taking a Stand
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 12503 WHERE `Id` IN (12795);
UPDATE `quest_template_addon` SET `PrevQuestID` = 0 WHERE `ID` IN (12503, 12596);

-- The Exiles of Ulduar
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 12930 WHERE `Id` IN (12885);

-- Assist Exarch Orelis
UPDATE `quest_template_addon` SET `PrevQuestID` = 0 WHERE `ID` = 10241;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 10241 WHERE `ID` = 11038;

-- Off To Area 52 / Out of This World Produce! / A Strange Vision / Parts for the Rocket-Chief / A Mystifying Vision
UPDATE `quest_template_addon` SET `ExclusiveGroup` = 0,`BreadcrumbForQuestId` = 10186 WHERE `ID` IN (10183, 11036, 11037, 11040, 11042);

-- Horde Warlock Voidwalker questlines
UPDATE `quest_template_addon` SET `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `ID` IN (10789,1478,1473,1471,10790,1506,1501,1504,10788,9529,9619);
UPDATE `quest_template_addon` SET `PrevQuestId` = 1473 WHERE `ID` = 1471;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1473 WHERE `ID` IN (10789, 1478);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1501 WHERE `ID` IN (10790, 1506);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 9529 WHERE `ID` IN (10788);

-- Horde Mage level 10 quests
-- Speak with Anastasia (1881) b-> The Balnir Farmstead (1882)
-- Speak with Un'thuwa (1883) b-> Ju-Ju Heaps (1884)
-- Fetch! (9402) -> The Purest Water (9403) -> Recently Living (9404)
UPDATE `quest_template_addon` SET `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `ID` IN (1881,1883,9402);
UPDATE `quest_template_addon` SET `PrevQuestId` = 0 WHERE `ID` IN (1884);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1882 WHERE `ID` IN (1881);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1884 WHERE `ID` IN (1883);
UPDATE `quest_template_addon` SET `ExclusiveGroup` = 1882 WHERE `ID` IN (1882,1884,9402);

-- Alliance Mage level 10 quests
-- Speak with Jennea (1860) b-> Mirror Lake (1861)
-- Speak with Bink (1879) b-> Mage-tastic Gizmonitor (1880)
-- Control (9595)
UPDATE `quest_template` SET `AllowableRaces` = 1101  WHERE `Id` = 1861;
UPDATE `quest_template_addon` SET `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `ID` IN (1860,1879);
UPDATE `quest_template_addon` SET `PrevQuestId` = 0 WHERE `ID` IN (1880);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1861 WHERE `ID` IN (1860);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1880 WHERE `ID` IN (1879);
UPDATE `quest_template_addon` SET `NextQuestId` = 0, `ExclusiveGroup` = 1861 WHERE `ID` IN (1861,1880,9595);

-- SI:7 / Erion's Behest / Kingly Shakedown
UPDATE `quest_template_addon` SET `NextQuestId` = 0,`ExclusiveGroup`=0,`BreadcrumbForQuestId` = 2260 WHERE `ID` IN (2259);
UPDATE `quest_template_addon` SET `NextQuestId` = 0,`ExclusiveGroup`=0,`BreadcrumbForQuestId` = 2298 WHERE `ID` IN (2299);
UPDATE `quest_template_addon` SET `NextQuestId` = 0,`ExclusiveGroup`=0,`BreadcrumbForQuestId` = 2281 WHERE `ID` IN (2260,2298,2300);

-- Alliance Rogue level 10 quests
-- Road to Salvation (2218) b-> Simple Subterfugin' (2238) -> Onin's Report (2239)
-- Seek out SI:7 (2205) b-> Snatch and Grab (2206)
-- The Apple Falls (2241) b-> Destiny Calls (2242)
UPDATE `quest_template_addon` SET `PrevQuestId` = 0,`ExclusiveGroup`= 2206 WHERE `ID` IN (2206,2238,2242);
UPDATE `quest_template_addon` SET `NextQuestId` = 0,`ExclusiveGroup`= 0 WHERE `ID` IN (2218,2205,2241);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 2238 WHERE `ID` IN (2218);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 2206 WHERE `ID` IN (2205);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 2242 WHERE `ID` IN (2241);
