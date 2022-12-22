-- Silvermoon Guardian (Falconwing Square)
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=16221;

UPDATE `gossip_menu_option` SET `ActionPoiID`=1734 WHERE `MenuID`=8185 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15222, `ActionPoiID`=0 WHERE `MenuID`=8185 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15224, `ActionPoiID`=2004 WHERE `MenuID`=8185 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15228, `ActionPoiID`=2003 WHERE `MenuID`=8185 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15234 WHERE `MenuID`=8185 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15250, `ActionPoiID`=3058 WHERE `MenuID`=8185 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15236 WHERE `MenuID`=8196 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15238, `ActionPoiID`=1998 WHERE `MenuID`=8196 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15240, `ActionPoiID`=1995 WHERE `MenuID`=8196 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15242, `ActionPoiID`=1999 WHERE `MenuID`=8196 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15241, `ActionPoiID`=1996 WHERE `MenuID`=8196 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15243, `ActionPoiID`=2000 WHERE `MenuID`=8196 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15244, `ActionPoiID`=1994 WHERE `MenuID`=8196 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2910, `ActionPoiID`=2554 WHERE `MenuID`=8196 AND `OptionID`=7;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=44730 WHERE `MenuID` IN (8185, 8196);

DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 10383 AND 10397;
DELETE FROM `points_of_interest` WHERE `ID` IN (10496, 10497);
DELETE FROM `points_of_interest` WHERE `ID` IN (1734, 1994, 1995, 1996, 1998, 1999, 2000, 2003, 2004, 2554, 3058);
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `PositionZ`, `Icon`, `Flags`, `Importance`, `Name`, `Unknown905`, `VerifiedBuild`) VALUES
(1734, 9379.4599609375, -7166, 11.52560043334960937, 7, 99, 0, 'Silvermoon City, Flight Master', 0, 44730),
(1994, 9467.6201171875, -6862.81982421875, 28.33079910278320312, 7, 583, 0, 'Falconwing Square, Warlock Trainer', 0, 44730),
(1995, 9462.33984375, -6853.60986328125, 28.377899169921875, 7, 583, 0, 'Falconwing Square, Mage Trainer', 0, 44730),
(1996, 9466.73046875, -6844.33984375, 28.377899169921875, 7, 583, 0, 'Falconwing Square, Priest Trainer', 0, 44730),
(1998, 9529.1904296875, -6864.509765625, 18.74930000305175781, 7, 583, 0, 'Falconwing Square, Hunter Trainer', 0, 44730),
(1999, 9516, -6871.02978515625, 18.75, 0, 0, 0, 'Falconwing Square, Paladin Trainer', 0, 44730),
(2000, 9534.2197265625, -6876.02978515625, 26.14879989624023437, 7, 583, 0, 'Falconwing Square, Rogue Trainer', 0, 44730),
(2003, 9487.66015625, -6830.490234375, 16.49360084533691406, 7, 583, 0, 'Falconwing Square, Stable Master', 0, 44730),
(2004, 9476.830078125, -6859.16015625, 17.34429931640625, 7, 583, 0, 'Falconwing Square, Innkeeper', 0, 44730),
(2554, 9523.2216796875, -6865.830078125, 18.74926376342773437, 7, 583, 0, 'Falconwing Square, Warrior Trainer', 0, 44730),
(3058, 9503.1767578125, -6897.720703125, 28.34722518920898437, 7, 583, 0, 'Falconwing Square, Profession Trainer', 0, 44730);

DELETE FROM `points_of_interest_locale` WHERE `ID` IN (1734, 1994, 1995, 1996, 1998, 1999, 2000, 2003, 2004, 2554, 3058);
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(1734, 'deDE', 'Flugmeister von Silbermond', 44730),
(1734, 'esES', 'Ciudad de Lunargenta, maestro de vuelo', 44730),
(1734, 'esMX', 'Ciudad de Lunargenta, maestro de vuelo', 44730),
(1734, 'frFR', 'Maître de vol de Lune-d’Argent', 44730),
(1734, 'itIT', 'Maestro di Volo di Lunargenta', 44730),
(1734, 'koKR', '실버문 비행 조련사', 44730),
(1734, 'ptBR', 'Luaprata, Mestre de Voo', 44730),
(1734, 'ruRU', 'Луносвет: распорядитель полетов', 44730),
(1734, 'zhCN', '银月城飞行管理员', 44730),
(1734, 'zhTW', '銀月城，飛行管理員', 44730),
(1994, 'deDE', 'Hexenmeisterlehrer des Falkenplatzes', 44730),
(1994, 'esES', 'Plaza Alalcón, instructor de brujos', 44730),
(1994, 'esMX', 'Plaza Alalcón, instructor de brujos', 44730),
(1994, 'frFR', 'Place de l''Épervier, maître des démonistes', 44730),
(1994, 'itIT', 'Istruttore degli Stregoni di Piazza del Falco', 44730),
(1994, 'koKR', '매날개 광장 상급 흑마법사', 44730),
(1994, 'ptBR', 'Praça Asa do Falcão, Treinamento de Bruxos', 44730),
(1994, 'ruRU', 'Площадь Соколиных Крыльев: настав', 44730), -- Площадь Соколиных Крыльев: настав� (truncated)
(1994, 'zhCN', '鹰翼广场术士训练师', 44730),
(1994, 'zhTW', '獵鷹之翼廣場，術士訓練師', 44730),
(1995, 'deDE', 'Magierlehrer des Falkenplatzes', 44730),
(1995, 'esES', 'Plaza Alalcón, instructor de magos', 44730),
(1995, 'esMX', 'Plaza Alalcón, instructor de magos', 44730),
(1995, 'frFR', 'Place de l''Épervier, maître des mages', 44730),
(1995, 'itIT', 'Istruttore dei Maghi di Piazza del Falco', 44730),
(1995, 'koKR', '매날개 광장 상급 마법사', 44730),
(1995, 'ptBR', 'Praça Asa do Falcão, Treinamento de Magos', 44730),
(1995, 'ruRU', 'Площадь Соколиных Крыльев: настав', 44730), -- Площадь Соколиных Крыльев: настав� (truncated)
(1995, 'zhCN', '鹰翼广场法师训练师', 44730),
(1995, 'zhTW', '獵鷹之翼廣場，法師訓練師', 44730),
(1996, 'deDE', 'Priesterlehrer des Falkenplatzes', 44730),
(1996, 'esES', 'Plaza Alalcón, instructor de sacerdotes', 44730),
(1996, 'esMX', 'Plaza Alalcón, instructor de sacerdotes', 44730),
(1996, 'frFR', 'Place de l''Épervier, maître des prêtres', 44730),
(1996, 'itIT', 'Istruttore dei Sacerdoti di Piazza del Falco', 44730),
(1996, 'koKR', '매날개 광장 상급 사제', 44730),
(1996, 'ptBR', 'Praça Asa do Falcão, Treinamento de Sacerdotes', 44730),
(1996, 'ruRU', 'Площадь Соколиных Крыльев: настав', 44730), -- Площадь Соколиных Крыльев: настав� (truncated)
(1996, 'zhCN', '鹰翼广场牧师训练师', 44730),
(1996, 'zhTW', '獵鷹之翼廣場，牧師訓練師', 44730),
(1998, 'deDE', 'Jägerlehrer des Falkenplatzes', 44730),
(1998, 'esES', 'Plaza Alalcón, instructor de cazadores', 44730),
(1998, 'esMX', 'Plaza Alalcón, instructor de cazadores', 44730),
(1998, 'frFR', 'Place de l''Épervier, maître des chasseurs', 44730),
(1998, 'itIT', 'Istruttore dei Cacciatori di Piazza del Falco', 44730),
(1998, 'koKR', '매날개 광장 상급 사냥꾼', 44730),
(1998, 'ptBR', 'Praça Asa do Falcão, Treinamento de Caçadores', 44730),
(1998, 'ruRU', 'Площадь Соколиных Крыльев: настав', 44730), -- Площадь Соколиных Крыльев: настав� (truncated)
(1998, 'zhCN', '鹰翼广场猎人训练师', 44730),
(1998, 'zhTW', '獵鷹之翼廣場，獵人訓練師', 44730),
(1999, 'deDE', 'Paladinlehrer des Falkenplatzes', 44730),
(1999, 'esES', 'Plaza Alalcón, instructor de paladines', 44730),
(1999, 'esMX', 'Plaza Alalcón, instructor de paladines', 44730),
(1999, 'frFR', 'Place de l''Épervier, maître des paladins', 44730),
(1999, 'itIT', 'Istruttore dei Paladini di Piazza del Falco', 44730),
(1999, 'koKR', '매날개 광장 상급 성기사', 44730),
(1999, 'ptBR', 'Praça Asa do Falcão, Treinamento de Paladinos', 44730),
(1999, 'ruRU', 'Площадь Соколиных Крыльев: настав', 44730), -- Площадь Соколиных Крыльев: настав� (truncated)
(1999, 'zhCN', '鹰翼广场圣骑士训练师', 44730),
(1999, 'zhTW', '獵鷹之翼廣場，聖騎士訓練師', 44730),
(2000, 'deDE', 'Schurkenlehrer des Falkenplatzes', 44730),
(2000, 'esES', 'Plaza Alalcón, instructor de pícaros', 44730),
(2000, 'esMX', 'Plaza Alalcón, instructor de pícaros', 44730),
(2000, 'frFR', 'Place de l''Épervier, maître des voleurs', 44730),
(2000, 'itIT', 'Istruttore dei Ladri di Piazza del Falco', 44730),
(2000, 'koKR', '매날개 광장 상급 도적', 44730),
(2000, 'ptBR', 'Praça Asa do Falcão, Treinamento de Ladinos', 44730),
(2000, 'ruRU', 'Площадь Соколиных Крыльев: настав', 44730), -- Площадь Соколиных Крыльев: настав� (truncated)
(2000, 'zhCN', '鹰翼广场潜行者训练师', 44730),
(2000, 'zhTW', '獵鷹之翼廣場，盜賊訓練師', 44730),
(2003, 'deDE', 'Stallmeister des Falkenplatzes', 44730),
(2003, 'esES', 'Plaza Alalcón, maestro de establos', 44730),
(2003, 'esMX', 'Plaza Alalcón, maestro de establos', 44730),
(2003, 'frFR', 'Place de l''Épervier, maître des écuries', 44730),
(2003, 'itIT', 'Stalliere di Piazza del Falco', 44730),
(2003, 'koKR', '매날개 광장 야수 관리인', 44730),
(2003, 'ptBR', 'Praça Asa do Falcão, Mestre de Estábulo', 44730),
(2003, 'ruRU', 'Площадь Соколиных Крыльев: смотри', 44730), -- Площадь Соколиных Крыльев: Смотритель стойл (truncated)
(2003, 'zhCN', '鹰翼广场兽栏管理员', 44730),
(2003, 'zhTW', '獵鷹之翼廣場，獸欄管理員', 44730),
(2004, 'deDE', 'Gastwirt des Falkenplatzes', 44730),
(2004, 'esES', 'Plaza Alalcón, tabernero', 44730),
(2004, 'esMX', 'Plaza Alalcón, tabernero', 44730),
(2004, 'frFR', 'Place de l''Épervier, aubergiste', 44730),
(2004, 'itIT', 'Locanda di Piazza del Falco', 44730),
(2004, 'koKR', '매날개 광장, 여관주인', 44730),
(2004, 'ptBR', 'Praça Asa do Falcão, Estalajadeiro', 44730),
(2004, 'ruRU', 'Площадь Соколиных Крыльев: тракти', 44730), -- Площадь Соколиных Крыльев: тракти� (truncated)
(2004, 'zhCN', '鹰翼广场旅店老板', 44730),
(2004, 'zhTW', '獵鷹之翼廣場，旅店老闆', 44730),
(2554, 'deDE', 'Kriegerlehrer des Falkenplatzes', 44730),
(2554, 'esES', 'Plaza Alalcón, instructor de guerreros', 44730),
(2554, 'esMX', 'Plaza Alalcón, instructor de guerreros', 44730),
(2554, 'frFR', 'Place de l''Épervier, maître des guerriers', 44730),
(2554, 'itIT', 'Istruttore dei Guerrieri di Piazza del Falco', 44730),
(2554, 'koKR', '매날개 광장 상급 전사', 44730),
(2554, 'ptBR', 'Praça Asa do Falcão, Treinamento de Guerreiros', 44730),
(2554, 'ruRU', 'Площадь Соколиных Крыльев, настав', 44730), -- Площадь Соколиных Крыльев, настав� (truncated)
(2554, 'zhCN', '鹰翼广场战士训练师', 44730),
(2554, 'zhTW', '獵鷹之翼廣場，戰士訓練師', 44730),
(3058, 'deDE', 'Berufsausbilder des Falkenplatzes', 44730),
(3058, 'esES', 'Plaza Alalcón, instructor de profesión', 44730),
(3058, 'esMX', 'Plaza Alalcón, instructor de profesión', 44730),
(3058, 'frFR', 'Place de l''Épervier, maître de métier', 44730),
(3058, 'itIT', 'Istruttore delle Professioni di Piazza del Falco', 44730),
(3058, 'koKR', '매날개 광장 기술 전문가', 44730),
(3058, 'ptBR', 'Praça Asa do Falcão, Treinamento de Profissão', 44730),
(3058, 'ruRU', 'Площадь Соколиных Крыльев: учител', 44730), -- Площадь Соколиных Крыльев: учител� (truncated)
(3058, 'zhCN', '鹰翼广场专业训练师', 44730),
(3058, 'zhTW', '獵鷹之翼廣場，專業技能訓練師', 44730);
