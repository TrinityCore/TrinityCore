-- Stormwind Guard (Goldshire)
UPDATE `creature_template` SET `gossip_menu_id`=3506 WHERE `entry`=1423;

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3426 WHERE `MenuID`=3506 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=5081 WHERE `MenuID`=3506 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=5513, `ActionPoiID`=658 WHERE `MenuID`=3506 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8508, `ActionPoiID`=869 WHERE `MenuID`=3506 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3429 WHERE `MenuID`=3506 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3430, `ActionPoiID`=3053 WHERE `MenuID`=3506 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2914 WHERE `MenuID`=3519 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2924, `ActionPoiID`=2552 WHERE `MenuID`=3519 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2902, `ActionPoiID`=652 WHERE `MenuID`=3519 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2922, `ActionPoiID`=660 WHERE `MenuID`=3519 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2918, `ActionPoiID`=653 WHERE `MenuID`=3519 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2906, `ActionPoiID`=657 WHERE `MenuID`=3519 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3450 WHERE `MenuID`=3519 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2926, `ActionPoiID`=656 WHERE `MenuID`=3519 AND `OptionID`=7;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2910, `ActionPoiID`=661 WHERE `MenuID`=3519 AND `OptionID`=8;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=44325 WHERE `MenuID` IN (3506, 3519);

DELETE FROM `points_of_interest` WHERE `ID` IN (10001, 10002, 10003, 10004, 10005, 10006, 10007, 10017, 10582, 10583);
DELETE FROM `points_of_interest` WHERE `ID` IN (652, 653, 656, 657, 658, 660, 661, 869, 2552, 3053);
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `PositionZ`, `Icon`, `Flags`, `Importance`, `Name`, `Unknown905`, `VerifiedBuild`) VALUES
(652, -9471.1201171875, 33.44409942626953125, 63.82049942016601562, 7, 99, 0, 'Zaldimar Wefhellt', 0, 44325),
(653, -9461.0703125, 32.99599838256835937, 63.82049942016601562, 7, 99, 0, 'Priestess Josetta', 0, 44325),
(656, -9473.2197265625, -4.08464002609252929, 49.79430007934570312, 7, 99, 0, 'Maximillian Crowe', 0, 44325),
(657, -9465.1396484375, 13.29360008239746093, 63.82049942016601562, 7, 99, 0, 'Keryn Sylvius', 0, 44325),
(658, -9459.349609375, 42.08050155639648437, 56.9496002197265625, 7, 99, 0, 'Lion''s Pride Inn', 0, 44325),
(660, -9469, 108.0530014038085937, 57.408599853515625, 7, 99, 0, 'Brother Wilhelm', 0, 44325),
(661, -9461.8203125, 109.5049972534179687, 57.70470046997070312, 7, 99, 0, 'Lyria Du Lac', 0, 44325),
(869, -9466.6201171875, 45.87089920043945312, 56.77500152587890625, 7, 99, 0, 'Erma', 0, 44325),
(2552, -9465.142578125, 117.8680572509765625, 57.9773712158203125, 7, 99, 0, 'Benjamin Foxworthy', 0, 44325),
(3053, -9494.001953125, 79.28472137451171875, 56.20418930053710937, 7, 99, 0, 'Lien Farner', 0, 44325);

DELETE FROM `points_of_interest_locale` WHERE `ID` IN (652, 653, 656, 657, 658, 660, 661, 869, 2552, 3053);
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
( 652, 'deDE', 'Zaldimar Wefhellt', 44325),
( 652, 'esES', 'Zaldimar Wefhellt', 44325),
( 652, 'esMX', 'Zaldimar Wefhellt', 44325),
( 652, 'frFR', 'Zaldimar Wefhellt', 44325),
( 652, 'itIT', 'Zaldimar Wefhellt', 44325),
( 652, 'koKR', '잘디마르 웨펠트', 44325),
( 652, 'ptBR', 'Zaldimar Wefhellt', 44325),
( 652, 'ruRU', 'Залдимар Вефхеллт', 44325),
( 652, 'zhCN', '扎尔迪玛·维夫希尔特', 44325),
( 652, 'zhTW', '札爾迪瑪‧維夫希爾特', 44325),
( 653, 'deDE', 'Priesterin Josetta', 44325),
( 653, 'esES', 'Sacerdotisa Josetta', 44325),
( 653, 'esMX', 'Sacerdotisa Josetta', 44325),
( 653, 'frFR', 'Prêtresse Josetta', 44325),
( 653, 'itIT', 'Sacerdotessa Josetta', 44325),
( 653, 'koKR', '여사제 조세타', 44325),
( 653, 'ptBR', 'Sacerdotisa Joselita', 44325),
( 653, 'ruRU', 'Жрица Жозетта', 44325),
( 653, 'zhCN', '女牧师洁塞塔', 44325),
( 653, 'zhTW', '女牧師潔塞塔', 44325),
( 656, 'deDE', 'Maximillian Raab', 44325),
( 656, 'esES', 'Maximillian Crowe', 44325),
( 656, 'esMX', 'Maximillian Crowe', 44325),
( 656, 'frFR', 'Maximillian Crowe', 44325),
( 656, 'itIT', 'Maximillian Crowe', 44325),
( 656, 'koKR', '맥시밀리언 크로우', 44325),
( 656, 'ptBR', 'Wagner Nascimento', 44325),
( 656, 'ruRU', 'Максимилиан Кроу', 44325),
( 656, 'zhCN', '玛克西米利安·克洛文', 44325),
( 656, 'zhTW', '瑪克西米利安‧克洛文', 44325),
( 657, 'deDE', 'Keryn Sylvius', 44325),
( 657, 'esES', 'Keryn Sylvius', 44325),
( 657, 'esMX', 'Keryn Sylvius', 44325),
( 657, 'frFR', 'Keryn Sylvius', 44325),
( 657, 'itIT', 'Keryn Sylvius', 44325),
( 657, 'koKR', '케린 실비우스', 44325),
( 657, 'ptBR', 'Anabela Cabreira', 44325),
( 657, 'ruRU', 'Керин Сильвиус', 44325),
( 657, 'zhCN', '科瑞恩·塞尔留斯', 44325),
( 657, 'zhTW', '科瑞恩‧塞爾留斯', 44325),
( 658, 'deDE', 'Gasthaus "Zur Höhle des Löwen"', 44325),
( 658, 'esES', 'Posada Orgullo de León', 44325),
( 658, 'esMX', 'Posada Orgullo de León', 44325),
( 658, 'frFR', 'Auberge de la Fierté du lion', 44325),
( 658, 'itIT', 'Locanda del Fiero Leone', 44325),
( 658, 'koKR', '사자무리 여관', 44325),
( 658, 'ptBR', 'Estalagem do Leão Orgulhoso', 44325),
( 658, 'ruRU', 'Таверна "Гордость льва"', 44325),
( 658, 'zhCN', '狮王之傲旅店', 44325),
( 658, 'zhTW', '獅王之傲旅店', 44325),
( 660, 'deDE', 'Bruder Wilhelm', 44325),
( 660, 'esES', 'Hermano Wilhelm', 44325),
( 660, 'esMX', 'Hermano Wilhelm', 44325),
( 660, 'frFR', 'Frère Wilhelm', 44325),
( 660, 'itIT', 'Fratello Wilhelm', 44325),
( 660, 'koKR', '수사 빌헬름', 44325),
( 660, 'ptBR', 'Irmão Guilhermino', 44325),
( 660, 'ruRU', 'Брат Вильгельм', 44325),
( 660, 'zhCN', '威尔海姆修士', 44325),
( 660, 'zhTW', '維爾海姆修士', 44325),
( 661, 'deDE', 'Lyria Du Lac', 44325),
( 661, 'esES', 'Lyria Du Lac', 44325),
( 661, 'esMX', 'Lyria Du Lac', 44325),
( 661, 'frFR', 'Lyria Du Lac', 44325),
( 661, 'itIT', 'Lyria Du Lac', 44325),
( 661, 'koKR', '리리아 뒤 라크', 44325),
( 661, 'ptBR', 'Lyria Du Lac', 44325),
( 661, 'ruRU', 'Лирия дю Лак', 44325),
( 661, 'zhCN', '里瑞亚·杜拉克', 44325),
( 661, 'zhTW', '里瑞亞‧杜拉克', 44325),
( 869, 'deDE', 'Erma', 44325),
( 869, 'esES', 'Erma', 44325),
( 869, 'esMX', 'Erma', 44325),
( 869, 'frFR', 'Erma', 44325),
( 869, 'itIT', 'Erma', 44325),
( 869, 'koKR', '엘마', 44325),
( 869, 'ptBR', 'Erma', 44325),
( 869, 'ruRU', 'Ирма', 44325),
( 869, 'zhCN', '艾玛', 44325),
( 869, 'zhTW', '旅店老闆艾瑪', 44325),
(2552, 'deDE', 'Benjamin Fuchsfell', 44325),
(2552, 'esES', 'Benjamin Tratazorro', 44325),
(2552, 'esMX', 'Benjamin Tratazorro', 44325),
(2552, 'frFR', 'Benjamin Dignerenard', 44325),
(2552, 'itIT', 'Benjamin Volpechiara', 44325),
(2552, 'koKR', '벤자민 폭스워디', 44325),
(2552, 'ptBR', 'Benjamim Raposo', 44325),
(2552, 'ruRU', 'Бенджамин Лисохват', 44325),
(2552, 'zhCN', '本杰明·福柯沃斯', 44325),
(2552, 'zhTW', '班傑明‧佛克斯沃西', 44325),
(3053, 'deDE', 'Lien Farner', 44325),
(3053, 'esES', 'Lien Farner', 44325),
(3053, 'esMX', 'Lien Farner', 44325),
(3053, 'frFR', 'Lien Farner', 44325),
(3053, 'itIT', 'Lien Farner', 44325),
(3053, 'koKR', '리엔 파너', 44325),
(3053, 'ptBR', 'Luiz Faro', 44325),
(3053, 'ruRU', 'Лиен Фарнер', 44325),
(3053, 'zhCN', '莱恩·法尔娜', 44325),
(3053, 'zhTW', '里恩‧法諾爾', 44325);
