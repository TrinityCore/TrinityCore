SET @NPCTEXTID := 570001;

-- Ipfelkofer Ironkeg | La'gar Brewshout (Brewfest)
UPDATE `creature_template` SET `gossip_menu_id`=8994, `minlevel`=60, `maxlevel`=60 WHERE `entry`=24710;
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=155194;

DELETE FROM `creature_template_addon` WHERE `entry`=155194;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(155194, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry` IN (24710, 155194);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(24710, 0, 0, 0, 298, 45338),
(155194, 0, 0, 0, 298, 45338);

DELETE FROM `gossip_menu` WHERE `MenuID` IN (24346, 24441);
DELETE FROM `gossip_menu` WHERE `MenuID` BETWEEN 24374 AND 24381;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(24346, @NPCTEXTID+0, -1),
(24441, @NPCTEXTID+1, -1),
(24374, 38231, -1),
(24375, @NPCTEXTID+2, -1),
(24376, @NPCTEXTID+3, -1),
(24377, @NPCTEXTID+4, -1),
(24378, @NPCTEXTID+5, -1),
(24379, @NPCTEXTID+6, -1),
(24380, @NPCTEXTID+7, -1),
(24381, 12876, -1);

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+7;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 176845, 0, 0, 0, 0, 0, 0, 0, 45338),
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 177596, 0, 0, 0, 0, 0, 0, 0, 45338),
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 177038, 0, 0, 0, 0, 0, 0, 0, 45338),
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 177039, 0, 0, 0, 0, 0, 0, 0, 45338),
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 177042, 0, 0, 0, 0, 0, 0, 0, 45338),
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 177058, 0, 0, 0, 0, 0, 0, 0, 45338),
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 177065, 0, 0, 0, 0, 0, 0, 0, 45338),
(@NPCTEXTID+7, 1, 0, 0, 0, 0, 0, 0, 0, 177087, 0, 0, 0, 0, 0, 0, 0, 45338);

UPDATE `gossip_menu_option` SET `ActionPoiID`=2092 WHERE `MenuID`=8994 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2091 WHERE `MenuID`=8994 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2102 WHERE `MenuID`=8994 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionText`='Campground Chaos', `OptionBroadcastTextId`=176844, `ActionMenuID`=24346 WHERE `MenuID`=8994 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2092 WHERE `MenuID`=9025 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2091 WHERE `MenuID`=9025 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2102 WHERE `MenuID`=9025 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionText`='Campground Chaos', `OptionBroadcastTextId`=176844, `ActionMenuID`=24346 WHERE `MenuID`=9025 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2092 WHERE `MenuID`=8995 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2091 WHERE `MenuID`=8995 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2102 WHERE `MenuID`=8995 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionText`='Campground Chaos', `OptionBroadcastTextId`=176844, `ActionMenuID`=24346 WHERE `MenuID`=8995 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2091 WHERE `MenuID`=8996 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2102 WHERE `MenuID`=8996 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionText`='Campground Chaos', `OptionBroadcastTextId`=176844, `ActionMenuID`=24346 WHERE `MenuID`=8996 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2092 WHERE `MenuID`=8997 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2102 WHERE `MenuID`=8997 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionText`='Campground Chaos', `OptionBroadcastTextId`=176844, `ActionMenuID`=24346 WHERE `MenuID`=8997 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2092 WHERE `MenuID`=9558 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2091 WHERE `MenuID`=9558 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionText`='Campground Chaos', `OptionBroadcastTextId`=176844, `ActionMenuID`=24346 WHERE `MenuID`=9558 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=45338 WHERE `MenuID` IN (8994, 9025, 8995, 8996, 8997, 9558);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=8994 AND `OptionID`=6;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (8995, 8996, 8997, 9025, 9558) AND `OptionID`=5;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (24346, 24441);
DELETE FROM `gossip_menu_option` WHERE `MenuID` BETWEEN 24374 AND 24381;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8994, 6, 0, 'Brewfest Chowdown', 177078, 1, 0, 24441, 6137, 0, 0, NULL, 0, 45338),
(8995, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24441, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(8996, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24441, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(8997, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24441, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(9025, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24441, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(9558, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24441, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(24346, 0, 0, 'The Tapping of the Keg', 23877, 1, 0, 9025, 0, 0, 0, NULL, 0, 45338),
(24346, 1, 0, 'Food & Drink', 23755, 1, 0, 8995, 0, 0, 0, NULL, 0, 45338),
(24346, 2, 0, 'Tokens & Souvenirs', 23756, 1, 0, 8996, 2092, 0, 0, NULL, 0, 45338),
(24346, 3, 0, 'Ram Racing', 23757, 1, 0, 8997, 2091, 0, 0, NULL, 0, 45338),
(24346, 4, 0, 'Brew of the Month Club', 26734, 1, 0, 9558, 2102, 0, 0, NULL, 0, 45338),
(24346, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24441, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(24441, 0, 0, 'The Tapping of the Keg', 23877, 1, 0, 9025, 0, 0, 0, NULL, 0, 45338),
(24441, 1, 0, 'Food & Drink', 23755, 1, 0, 8995, 0, 0, 0, NULL, 0, 45338),
(24441, 2, 0, 'Tokens & Souvenirs', 23756, 1, 0, 8996, 2092, 0, 0, NULL, 0, 45338),
(24441, 3, 0, 'Ram Racing', 23757, 1, 0, 8997, 2091, 0, 0, NULL, 0, 45338),
(24441, 4, 0, 'Brew of the Month Club', 26734, 1, 0, 9558, 2102, 0, 0, NULL, 0, 45338),
(24441, 5, 0, 'Campground Chaos', 176844, 1, 0, 24346, 0, 0, 0, NULL, 0, 45338),
(24374, 0, 0, 'The Tapping of the Keg', 23877, 1, 0, 24375, 0, 0, 0, NULL, 0, 45338),
(24374, 1, 0, 'Food & Drink', 23755, 1, 0, 24376, 0, 0, 0, NULL, 0, 45338),
(24374, 2, 0, 'Tokens & Souvenirs', 23756, 1, 0, 24377, 2094, 0, 0, NULL, 0, 45338),
(24374, 3, 0, 'Ram Racing', 23757, 1, 0, 24378, 2093, 0, 0, NULL, 0, 45338),
(24374, 4, 0, 'Brew of the Month Club', 26734, 1, 0, 24381, 2103, 0, 0, NULL, 0, 45338),
(24374, 5, 0, 'Campground Chaos', 176844, 1, 0, 24379, 0, 0, 0, NULL, 0, 45338),
(24374, 6, 0, 'Brewfest Chowdown', 177078, 1, 0, 24380, 6136, 0, 0, NULL, 0, 45338),
(24375, 0, 0, 'Food & Drink', 23755, 1, 0, 24376, 0, 0, 0, NULL, 0, 45338),
(24375, 1, 0, 'Tokens & Souvenirs', 23756, 1, 0, 24377, 2094, 0, 0, NULL, 0, 45338),
(24375, 2, 0, 'Ram Racing', 23757, 1, 0, 24378, 2093, 0, 0, NULL, 0, 45338),
(24375, 3, 0, 'Brew of the Month Club', 26734, 1, 0, 24381, 2103, 0, 0, NULL, 0, 45338),
(24375, 4, 0, 'Campground Chaos', 176844, 1, 0, 24379, 0, 0, 0, NULL, 0, 45338),
(24375, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24380, 6136, 0, 0, NULL, 0, 45338),
(24376, 0, 0, 'The Tapping of the Keg', 23877, 1, 0, 24375, 0, 0, 0, NULL, 0, 45338),
(24376, 1, 0, 'Tokens & Souvenirs', 23756, 1, 0, 24377, 2094, 0, 0, NULL, 0, 45338),
(24376, 2, 0, 'Ram Racing', 23757, 1, 0, 24378, 2093, 0, 0, NULL, 0, 45338),
(24376, 3, 0, 'Brew of the Month Club', 26734, 1, 0, 24381, 2103, 0, 0, NULL, 0, 45338),
(24376, 4, 0, 'Campground Chaos', 176844, 1, 0, 24379, 0, 0, 0, NULL, 0, 45338),
(24376, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24380, 6136, 0, 0, NULL, 0, 45338),
(24377, 0, 0, 'The Tapping of the Keg', 23877, 1, 0, 24375, 0, 0, 0, NULL, 0, 45338),
(24377, 1, 0, 'Food & Drink', 23755, 1, 0, 24376, 0, 0, 0, NULL, 0, 45338),
(24377, 2, 0, 'Ram Racing', 23757, 1, 0, 24378, 2093, 0, 0, NULL, 0, 45338),
(24377, 3, 0, 'Brew of the Month Club', 26734, 1, 0, 24381, 2103, 0, 0, NULL, 0, 45338),
(24377, 4, 0, 'Campground Chaos', 176844, 1, 0, 24379, 0, 0, 0, NULL, 0, 45338),
(24377, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24380, 6136, 0, 0, NULL, 0, 45338),
(24378, 0, 0, 'The Tapping of the Keg', 23877, 1, 0, 24375, 0, 0, 0, NULL, 0, 45338),
(24378, 1, 0, 'Food & Drink', 23755, 1, 0, 24376, 0, 0, 0, NULL, 0, 45338),
(24378, 2, 0, 'Tokens & Souvenirs', 23756, 1, 0, 24377, 2094, 0, 0, NULL, 0, 45338),
(24378, 3, 0, 'Brew of the Month Club', 26734, 1, 0, 24381, 2103, 0, 0, NULL, 0, 45338),
(24378, 4, 0, 'Campground Chaos', 176844, 1, 0, 24379, 0, 0, 0, NULL, 0, 45338),
(24378, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24380, 6136, 0, 0, NULL, 0, 45338),
(24379, 0, 0, 'The Tapping of the Keg', 23877, 1, 0, 24375, 0, 0, 0, NULL, 0, 45338),
(24379, 1, 0, 'Food & Drink', 23755, 1, 0, 24376, 0, 0, 0, NULL, 0, 45338),
(24379, 2, 0, 'Tokens & Souvenirs', 23756, 1, 0, 24377, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(24379, 3, 0, 'Ram Racing', 23757, 1, 0, 24378, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(24379, 4, 0, 'Brew of the Month Club', 26734, 1, 0, 24381, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(24379, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24380, 6136, 0, 0, NULL, 0, 45338),
(24380, 0, 0, 'The Tapping of the Keg', 23877, 1, 0, 24375, 0, 0, 0, NULL, 0, 45338),
(24380, 1, 0, 'Food & Drink', 23755, 1, 0, 24376, 0, 0, 0, NULL, 0, 45338),
(24380, 2, 0, 'Tokens & Souvenirs', 23756, 1, 0, 24377, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(24380, 3, 0, 'Ram Racing', 23757, 1, 0, 24378, 0, 0, 0, NULL, 0, 45338), -- Blizzlike
(24380, 4, 0, 'Brew of the Month Club', 26734, 1, 0, 24381, 2103, 0, 0, NULL, 0, 45338),
(24380, 5, 0, 'Campground Chaos', 176844, 1, 0, 24379, 0, 0, 0, NULL, 0, 45338),
(24381, 0, 0, 'The Tapping of the Keg', 23877, 1, 0, 24375, 0, 0, 0, NULL, 0, 45338),
(24381, 1, 0, 'Food & Drink', 23755, 1, 0, 24376, 0, 0, 0, NULL, 0, 45338),
(24381, 2, 0, 'Tokens & Souvenirs', 23756, 1, 0, 24377, 2094, 0, 0, NULL, 0, 45338),
(24381, 3, 0, 'Ram Racing', 23757, 1, 0, 24378, 2093, 0, 0, NULL, 0, 45338),
(24381, 4, 0, 'Campground Chaos', 176844, 1, 0, 24379, 0, 0, 0, NULL, 0, 45338),
(24381, 5, 0, 'Brewfest Chowdown', 177078, 1, 0, 24380, 6136, 0, 0, NULL, 0, 45338);

DELETE FROM `points_of_interest` WHERE `ID` IN (10448, 10449, 10450, 10451, 10452, 10453, 10460);
DELETE FROM `points_of_interest` WHERE `ID` IN (2091, 2092, 2093, 2094, 2102, 2103, 2722, 6136, 6137);
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `PositionZ`, `Icon`, `Flags`, `Importance`, `Name`, `Unknown905`, `VerifiedBuild`) VALUES
(2091, -5200.93017578125, -484.6820068359375, 388.80499267578125, 7, 75, 0, 'Brewfest Ram Racing', 0, 45338),
(2092, -5176.77978515625, -623.989990234375, 397.175994873046875, 7, 75, 0, 'Brewfest Souvenirs', 0, 45338),
(2093, 1282.989990234375, -4410.58984375, 26.42609977722167968, 7, 75, 0, 'Goblin Brewfest Ram Racing', 0, 45338),
(2094, 1174.56005859375, -4292.919921875, 21.27400016784667968, 7, 75, 0, 'Goblin Brewfest Souvenirs', 0, 45338),
(2102, -4847.830078125, -862.60601806640625, 501.91400146484375, 7, 75, 0, 'Brew of the Month Club, Ironforge', 0, 45338),
(2103, 1634.52001953125, -4382.18994140625, 21.1902008056640625, 7, 75, 0, 'Brew of the Month Club, Orgrimmar', 0, 45338),
(2722, -4088.888916015625, 6359.15087890625, 13.04977226257324218, 7, 99, 0, 'Darkmoon Game Tokens', 0, 45338),
(6136, 1162.530029296875, -4198.5, 22.41909980773925781, 7, 75, 0, 'Brewfest Chowdown', 0, 45338),
(6137, -5201.830078125, -545.9639892578125, 396.824005126953125, 7, 75, 0, 'Brewfest Chowdown', 0, 45338);

DELETE FROM `points_of_interest_locale` WHERE `ID` IN (2091, 2092, 2093, 2094, 2102, 2103, 2722, 6136, 6137);
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(2091, 'deDE', 'Widderrennen des Braufests', 45338),
(2091, 'esES', 'Carrera de carneros de la Fiesta de la Cerveza', 45338),
(2091, 'esMX', 'Carrera de carneros de la Fiesta de la Cerveza', 45338),
(2091, 'frFR', 'Course de béliers de la fête des Brasseurs', 45338),
(2091, 'itIT', 'Gara degli Arieti della Festa della Birra', 45338),
(2091, 'koKR', '가을 축제 산양 경주장', 45338),
(2091, 'ptBR', 'Corrida de Carneiros da CervaFest', 45338),
(2091, 'ruRU', 'Хмельной фестиваль: скачки на бара', 45338),
(2091, 'zhCN', '美酒节赛羊会', 45338),
(2091, 'zhTW', '啤酒節山羊競速', 45338),
(2092, 'deDE', 'Souvenirs des Braufests', 45338),
(2092, 'esES', 'Recuerdos de la Fiesta de la Cerveza', 45338),
(2092, 'esMX', 'Recuerdos de la Fiesta de la Cerveza', 45338),
(2092, 'frFR', 'Souvenirs de la fête des Brasseurs', 45338),
(2092, 'itIT', 'Souvenir della Festa della Birra', 45338),
(2092, 'koKR', '가을 축제 기념품점', 45338),
(2092, 'ptBR', 'Brindes da Cervafest', 45338),
(2092, 'ruRU', 'Хмельной фестиваль: сувениры', 45338),
(2092, 'zhCN', '美酒节兑奖处', 45338),
(2092, 'zhTW', '啤酒節紀念品', 45338),
(2093, 'deDE', 'Goblinwidderrennen des Braufests', 45338),
(2093, 'esES', 'Carrera de carneros de la Fiesta de la Cerveza goblin', 45338),
(2093, 'esMX', 'Carrera de carneros de la Fiesta de la Cerveza goblin', 45338),
(2093, 'frFR', 'Course de béliers de la fête des Brasseurs gobeline', 45338),
(2093, 'itIT', 'Gara degli Arieti della Festa della Birra dei Goblin', 45338),
(2093, 'koKR', '가을 축제 고블린 산양 경주장', 45338),
(2093, 'ptBR', 'Corrida Goblínica de Carneiros da CervaFest', 45338),
(2093, 'ruRU', 'Гоблинский Хмельной фестиваль: ск', 45338), -- Гоблинский Хмельной фестиваль: ск� (truncated)
(2093, 'zhCN', '地精美酒节赛羊会', 45338),
(2093, 'zhTW', '哥布林啤酒節山羊競速', 45338),
(2094, 'deDE', 'Goblinsouvenirs des Braufests', 45338),
(2094, 'esES', 'Recuerdos de la Fiesta de la Cerveza goblin', 45338),
(2094, 'esMX', 'Recuerdos de la Fiesta de la Cerveza goblin', 45338),
(2094, 'frFR', 'Souvenirs de la fête des Brasseurs gobeline', 45338),
(2094, 'itIT', 'Souvenir della Festa della Birra dei Goblin', 45338),
(2094, 'koKR', '가을 축제 고블린 기념품점', 45338),
(2094, 'ptBR', 'Brindes Goblínicos da Cervafest', 45338),
(2094, 'ruRU', 'Гоблинский Хмельной фестиваль: су', 45338), -- Гоблинский Хмельной фестиваль: су� (truncated)
(2094, 'zhCN', '地精美酒节兑奖处', 45338),
(2094, 'zhTW', '哥布林啤酒節紀念品', 45338),
(2102, 'deDE', 'Bier des Monats e.V., Eisenschmiede', 45338),
(2102, 'esES', 'Club de la Cerveza del Mes, Forjaz', 45338),
(2102, 'esMX', 'Club de la Cerveza del Mes, Forjaz', 45338),
(2102, 'frFR', 'Club de la bière du mois, Forgefer', 45338),
(2102, 'itIT', 'Club della Birra del Mese di Forgiardente', 45338),
(2102, 'koKR', '아이언포지 맥주 사랑 동호회', 45338),
(2102, 'ptBR', 'Clube da Cerveja do Mês, Altaforja', 45338),
(2102, 'ruRU', 'Клуб "Пиво месяца", Стальгорн', 45338),
(2102, 'zhCN', '本月美酒俱乐部，铁炉堡', 45338),
(2102, 'zhTW', '每月啤酒俱樂部，鐵爐堡', 45338),
(2103, 'deDE', 'Bier des Monats e.V., Orgrimmar', 45338),
(2103, 'esES', 'Club de la Cerveza del Mes, Orgrimmar', 45338),
(2103, 'esMX', 'Club de la Cerveza del Mes, Orgrimmar', 45338),
(2103, 'frFR', 'Club de la bière du mois, Orgrimmar', 45338),
(2103, 'itIT', 'Club della Birra del Mese di Orgrimmar', 45338),
(2103, 'koKR', '오그리마 맥주 사랑 동호회', 45338),
(2103, 'ptBR', 'Clube da Cerveja do Mês, Orgrimmar', 45338),
(2103, 'ruRU', 'Клуб "Пиво месяца", Оргриммар', 45338),
(2103, 'zhCN', '本月美酒俱乐部，奥格瑞玛', 45338),
(2103, 'zhTW', '每月啤酒俱樂部，奧格瑪', 45338),
(2722, 'deDE', 'Spieljetons des Dunkelmond-Jahrmarkts', 45338),
(2722, 'esES', 'Fichas de la Feria de la Luna Negra', 45338),
(2722, 'esMX', 'Fichas de la Feria de la Luna Negra', 45338),
(2722, 'frFR', 'Jetons de la foire de Sombrelune', 45338),
(2722, 'itIT', 'Gettoni dei Giochi di Lunacupa', 45338),
(2722, 'koKR', '다크문 게임 동전 상인', 45338),
(2722, 'ptBR', 'Fichas de Jogo de Negraluna', 45338),
(2722, 'ruRU', 'Жетоны ярмарки Новолуния', 45338),
(2722, 'zhCN', '暗月游戏代币', 45338),
(2722, 'zhTW', '暗月遊戲代幣', 45338),
(6136, 'deDE', 'Braufestmampfkampf', 45338),
(6136, 'esES', 'Comilona de la Fiesta de la Cerveza', 45338),
(6136, 'esMX', 'Panzada cervecera', 45338),
(6136, 'frFR', 'Gueulethon de la fête des Brasseurs', 45338),
(6136, 'itIT', 'Ingozzatutto della Festa della Birra', 45338),
(6136, 'koKR', '가을 축제 먹기 대회', 45338),
(6136, 'ptBR', 'Bate-rango da CervaFest', 45338),
(6136, 'ruRU', '"Сарделирий" Хмельного фестиваля', 45338),
(6136, 'zhCN', '美酒节大胃王比赛', 45338),
(6136, 'zhTW', '啤酒節大胃王比賽', 45338),
(6137, 'deDE', 'Braufestmampfkampf', 45338),
(6137, 'esES', 'Comilona de la Fiesta de la Cerveza', 45338),
(6137, 'esMX', 'Panzada cervecera', 45338),
(6137, 'frFR', 'Gueulethon de la fête des Brasseurs', 45338),
(6137, 'itIT', 'Ingozzatutto della Festa della Birra', 45338),
(6137, 'koKR', '가을 축제 먹기 대회', 45338),
(6137, 'ptBR', 'Bate-rango da CervaFest', 45338),
(6137, 'ruRU', '"Сарделирий" Хмельного фестиваля', 45338),
(6137, 'zhCN', '美酒节大胃王比赛', 45338),
(6137, 'zhTW', '啤酒節大胃王比賽', 45338);
