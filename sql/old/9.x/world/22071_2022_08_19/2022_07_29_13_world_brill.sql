-- Deathguards (Brill)
UPDATE `creature_template` SET `gossip_menu_id`=3356 WHERE `entry` IN (1738, 1742, 1743, 2209, 2210, 5725);
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=1652;
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `npcflag`=0 WHERE `entry`=1735;
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=8388608 WHERE `entry`=7980;

DELETE FROM `gossip_menu` WHERE `MenuID` IN (12264, 15731);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(12264,17226,-1),
(15731,22591,-1);

UPDATE `npc_text` SET `Probability0`=0, `Probability1`=0 WHERE `ID` IN (4075, 4076, 4077, 4078);
UPDATE `npc_text` SET `Probability0`=0, `Probability1`=0, `Probability2`=1, `BroadcastTextID2`=50493 WHERE `ID`=4079;
UPDATE `npc_text` SET `Probability0`=0, `Probability1`=0, `Probability2`=1, `BroadcastTextID2`=50495 WHERE `ID`=4080;
UPDATE `npc_text` SET `Probability0`=0, `Probability1`=0, `Probability2`=1, `BroadcastTextID2`=50496 WHERE `ID`=4081;

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6789 WHERE `MenuID`=3356 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6791, `ActionPoiID`=615 WHERE `MenuID`=3356 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8515, `ActionPoiID`=851 WHERE `MenuID`=3356 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=5338 WHERE `MenuID`=3356 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6723, `ActionMenuID`=15731, `ActionPoiID`=3055 WHERE `MenuID`=3356 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2924, `ActionMenuID`=12264, `ActionPoiID`=2521 WHERE (`MenuID`=3354 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2902, `ActionMenuID`=3337, `ActionPoiID`=616 WHERE (`MenuID`=3354 AND `OptionID`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2922, `ActionMenuID`=8166, `ActionPoiID`=0 WHERE (`MenuID`=3354 AND `OptionID`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2918, `ActionMenuID`=3338, `ActionPoiID`=617 WHERE (`MenuID`=3354 AND `OptionID`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2906, `ActionMenuID`=3339, `ActionPoiID`=618 WHERE (`MenuID`=3354 AND `OptionID`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2926, `ActionMenuID`=3340, `ActionPoiID`=619 WHERE (`MenuID`=3354 AND `OptionID`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2910, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=3341, `ActionPoiID`=620 WHERE `MenuID`=3354 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=44325 WHERE `MenuID` IN (3356, 3354);

DELETE FROM `points_of_interest` WHERE `ID` IN (10433, 10434, 10435, 10436, 10437, 10446, 10447, 10461);
DELETE FROM `points_of_interest` WHERE `ID` IN (615, 616, 617, 618, 619, 620, 851, 2521, 3055);
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `PositionZ`, `Icon`, `Flags`, `Importance`, `Name`, `Unknown905`, `VerifiedBuild`) VALUES
(615, 2281.679931640625, 283.709991455078125, 33.24229812622070312, 7, 99, 0, 'Gallows'' End Tavern', 0, 44325),
(616, 2235.24658203125, 317.696197509765625, 34.23265838623046875, 7, 99, 0, 'Cain Firesong', 0, 44325),
(617, 2248.017333984375, 229.08160400390625, 34.50976943969726562, 7, 99, 0, 'Dark Cleric Beryl', 0, 44325),
(618, 2294.82470703125, 266.138885498046875, 33.35695266723632812, 7, 99, 0, 'Marion Call', 0, 44325),
(619, 2318.298583984375, 277.005218505859375, 22.73082923889160156, 7, 99, 0, 'Rupert Boch', 0, 44325),
(620, 2283.3837890625, 308.133697509765625, 33.96213150024414062, 7, 99, 0, 'Austil de Mon', 0, 44325),
(851, 2265.609375, 240.1493072509765625, 33.69063568115234375, 7, 99, 0, 'Morganus', 0, 44325),
(2521, 2231.169921875, 241.610992431640625, 33.57360076904296875, 7, 99, 0, 'Dedlow Wormwood', 0, 44325),
(3055, 2299.302001953125, 270.555572509765625, 33.35696792602539062, 7, 99, 0, 'Nedric Sallow', 0, 44325);

DELETE FROM `points_of_interest_locale` WHERE `ID` IN (615, 616, 617, 618, 619, 620, 851, 2521, 3055);
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
( 615, 'deDE', 'Taverne Zur Galgenschlinge', 44325),
( 615, 'esES', 'Mesón La Horca', 44325),
( 615, 'esMX', 'Mesón La Horca', 44325),
( 615, 'frFR', 'Taverne des Pendus', 44325),
( 615, 'itIT', 'Taverna dell''Impiccato', 44325),
( 615, 'koKR', '교수대끝 선술집', 44325),
( 615, 'ptBR', 'Taberna Finda Forca', 44325),
( 615, 'ruRU', 'Таверна "Петля висельника"', 44325),
( 615, 'zhCN', '恐惧之末旅店', 44325),
( 615, 'zhTW', '恐懼之末旅店', 44325),
( 616, 'deDE', 'Cain Feuerlied', 44325),
( 616, 'esES', 'Cain Pirosón', 44325),
( 616, 'esMX', 'Cain Pirosón', 44325),
( 616, 'frFR', 'Cain Chantefeu', 44325),
( 616, 'itIT', 'Cain Cantafuoco', 44325),
( 616, 'koKR', '케인 파이어송', 44325),
( 616, 'ptBR', 'Caio Cantígnea', 44325),
( 616, 'ruRU', 'Кейн Песнь Пламени', 44325),
( 616, 'zhCN', '凯恩·火歌', 44325),
( 616, 'zhTW', '凱恩‧火歌', 44325),
( 617, 'deDE', 'Dunkler Kleriker Beryll', 44325),
( 617, 'esES', 'Clérigo oscuro Beryl', 44325),
( 617, 'esMX', 'Clérigo oscuro Beryl', 44325),
( 617, 'frFR', 'Sombre clerc Beryl', 44325),
( 617, 'itIT', 'Chierico Oscuro Beryl', 44325),
( 617, 'koKR', '어둠의 사제 베릴', 44325),
( 617, 'ptBR', 'Clérigo das Trevas Beryl', 44325),
( 617, 'ruRU', 'Темный священник Берил', 44325),
( 617, 'zhCN', '黑暗牧师贝里尔', 44325),
( 617, 'zhTW', '黑暗教士貝里爾', 44325),
( 618, 'deDE', 'Marion Kall', 44325),
( 618, 'esES', 'Marion Call', 44325),
( 618, 'esMX', 'Marion Call', 44325),
( 618, 'frFR', 'Marion Call', 44325),
( 618, 'itIT', 'Marion Call', 44325),
( 618, 'koKR', '매리언 콜', 44325),
( 618, 'ptBR', 'Marion Calder', 44325),
( 618, 'ruRU', 'Марион Зов', 44325),
( 618, 'zhCN', '马里恩·考尔', 44325),
( 618, 'zhTW', '馬里恩‧考爾', 44325),
( 619, 'deDE', 'Rupert Boch', 44325),
( 619, 'esES', 'Rupert Boch', 44325),
( 619, 'esMX', 'Rupert Boch', 44325),
( 619, 'frFR', 'Rupert Boch', 44325),
( 619, 'itIT', 'Rupert Boch', 44325),
( 619, 'koKR', '루퍼트 보흐', 44325),
( 619, 'ptBR', 'Rupertino Boch', 44325),
( 619, 'ruRU', 'Руперт Бош', 44325),
( 619, 'zhCN', '鲁伯特·鲍什', 44325),
( 619, 'zhTW', '魯伯特‧鮑什', 44325),
( 620, 'deDE', 'Austil de Mon', 44325),
( 620, 'esES', 'Austil de Mon', 44325),
( 620, 'esMX', 'Austil de Mon', 44325),
( 620, 'frFR', 'Austil de Mon', 44325),
( 620, 'itIT', 'Austil de Mon', 44325),
( 620, 'koKR', '오스틸 드 몽', 44325),
( 620, 'ptBR', 'Austil de Mon', 44325),
( 620, 'ruRU', 'Остил де Мон', 44325),
( 620, 'zhCN', '奥斯蒂尔·德·蒙', 44325),
( 620, 'zhTW', '奧斯蒂爾‧德‧蒙', 44325),
( 851, 'deDE', 'Morganus', 44325),
( 851, 'esES', 'Morganus', 44325),
( 851, 'esMX', 'Morganus', 44325),
( 851, 'frFR', 'Morganus', 44325),
( 851, 'itIT', 'Morganus', 44325),
( 851, 'koKR', '모르가누스', 44325),
( 851, 'ptBR', 'Morganus', 44325),
( 851, 'ruRU', 'Морганус', 44325),
( 851, 'zhCN', '莫加努斯', 44325),
( 851, 'zhTW', '莫加努斯', 44325),
(2521, 'deDE', 'Dedlow Wermut', 44325),
(2521, 'esES', 'Dedlow Ajenjo', 44325),
(2521, 'esMX', 'Dedlow Ajenjo', 44325),
(2521, 'frFR', 'Morlow Armoise', 44325),
(2521, 'itIT', 'Dedlow Legnomarcio', 44325),
(2521, 'koKR', '데들로우 웜우드', 44325),
(2521, 'ptBR', 'Dedálio Absinthus', 44325),
(2521, 'ruRU', 'Дедлоу Полынник', 44325),
(2521, 'zhCN', '戴德洛·沃姆伍德', 44325),
(2521, 'zhTW', '迪羅‧蟲林', 44325),
(3055, 'deDE', 'Nedric Bleich', 44325),
(3055, 'esES', 'Nedric Cetrino', 44325),
(3055, 'esMX', 'Nedric Cetrino', 44325),
(3055, 'frFR', 'Nedric Saule', 44325),
(3055, 'itIT', 'Nedric Sallow', 44325),
(3055, 'koKR', '네드릭 살로', 44325),
(3055, 'ptBR', 'Pedrico Mendes', 44325),
(3055, 'ruRU', 'Недрик Сэллоу', 44325),
(3055, 'zhCN', '尼德里奇·沙洛', 44325),
(3055, 'zhTW', '奈德里克‧薩洛', 44325);
