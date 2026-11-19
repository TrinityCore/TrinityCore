-- Azuremyst Peacekeeper (Azure Watch)
UPDATE `creature_template` SET `gossip_menu_id`=8129, `minlevel`=30, `maxlevel`=30 WHERE `entry`=18038;

DELETE FROM `gossip_menu` WHERE `MenuID`=15735;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(15735, 22595, -1);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3426 WHERE `MenuID`=8129 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=5330 WHERE `MenuID`=8129 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=5513, `ActionPoiID`=1973 WHERE `MenuID`=8129 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8508, `ActionPoiID`=1972 WHERE `MenuID`=8129 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2868 WHERE `MenuID`=8129 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2869, `ActionMenuID`=15735, `ActionPoiID`=3059 WHERE `MenuID`=8129 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2914 WHERE `MenuID`=8137 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2924, `ActionPoiID`=1978 WHERE `MenuID`=8137 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2902, `ActionPoiID`=1976 WHERE `MenuID`=8137 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2922, `ActionPoiID`=1974 WHERE `MenuID`=8137 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2918, `ActionPoiID`=1975 WHERE `MenuID`=8137 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3450, `ActionPoiID`=1970 WHERE `MenuID`=8137 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2910, `ActionPoiID`=1977 WHERE `MenuID`=8137 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=44325 WHERE `MenuID` IN (8129, 8137);

DELETE FROM `points_of_interest` WHERE `ID` IN (10219, 10220, 10221, 10222, 10223, 10224, 10225, 10226, 10227, 10230, 10231, 10233, 10235);
DELETE FROM `points_of_interest` WHERE `ID` IN (1970, 1972, 1973, 1974, 1975, 1976, 1977, 1978, 3059);
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `PositionZ`, `Icon`, `Flags`, `Importance`, `Name`, `Unknown905`, `VerifiedBuild`) VALUES
(1970, -4162.2998046875, -12456, 44.256500244140625, 7, 583, 0, 'Azure Watch, Shaman Trainer', 0, 44325),
(1972, -4146.419921875, -12492.7001953125, 44.53310012817382812, 7, 583, 0, 'Azure Watch, Stable Master', 0, 44325),
(1973, -4127.580078125, -12467.400390625, 44.08489990234375, 7, 583, 0, 'Azure Watch, Innkeeper', 0, 44325),
(1974, -4138.990234375, -12468.5, 44.57989883422851562, 7, 583, 0, 'Azure Watch, Paladin Trainer', 0, 44325),
(1975, -4131.64013671875, -12478.7001953125, 44.57410049438476562, 7, 583, 0, 'Azure Watch, Priest Trainer', 0, 44325),
(1976, -4149.81982421875, -12530, 45.10990142822265625, 7, 583, 0, 'Azure Watch, Mage Trainer', 0, 44325),
(1977, -4165.0498046875, -12536.400390625, 44.83119964599609375, 7, 583, 0, 'Azure Watch, Warrior Trainer', 0, 44325),
(1978, -4203.5, -12526.5, 45.4264984130859375, 7, 583, 0, 'Azure Watch, Hunter Trainer', 0, 44325),
(3059, -4216.68408203125, -12481.62890625, 45.24339675903320312, 7, 583, 0, 'Azure Watch, Profession Trainer', 0, 44325);

DELETE FROM `points_of_interest_locale` WHERE `ID` IN (1970, 1972, 1973, 1974, 1975, 1976, 1977, 1978, 3059);
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(1970, 'deDE', 'Schamanenlehrer der Azurwacht', 44325),
(1970, 'esES', 'Avanzada Azur, instructor de chamanes', 44325),
(1970, 'esMX', 'Avanzada Azur, instructor de chamanes', 44325),
(1970, 'frFR', 'Guet d''azur, maître des chamans', 44325),
(1970, 'itIT', 'Istruttore degli Sciamani di Presidio Azzurro', 44325),
(1970, 'koKR', '하늘 감시초소 상급 주술사', 44325),
(1970, 'ptBR', 'Entreposto Lazúli, Treinamento de Xamãs', 44325),
(1970, 'ruRU', 'Лазурная застава: наставник шаман', 44325), -- Лазурная застава: наставник шаманов (truncated)
(1970, 'zhCN', '碧蓝岗哨萨满祭司训练师', 44325),
(1970, 'zhTW', '藍色守望，薩滿訓練師', 44325),
(1972, 'deDE', 'Stallmeister der Azurwacht', 44325),
(1972, 'esES', 'Avanzada Azur, maestro de establos', 44325),
(1972, 'esMX', 'Avanzada Azur, maestro de establos', 44325),
(1972, 'frFR', 'Guet d''azur, maître des écuries', 44325),
(1972, 'itIT', 'Stalliere di Presidio Azzurro', 44325),
(1972, 'koKR', '하늘 감시초소 야수 관리인', 44325),
(1972, 'ptBR', 'Entreposto Lazúli, Mestre de Estábulo', 44325),
(1972, 'ruRU', 'Лазурная застава: смотритель стой', 44325), -- Лазурная застава: смотритель стойл (truncated)
(1972, 'zhCN', '碧蓝岗哨兽栏管理员', 44325),
(1972, 'zhTW', '藍色守望，獸欄管理員', 44325),
(1973, 'deDE', 'Gastwirt der Azurwacht', 44325),
(1973, 'esES', 'Avanzada Azur, tabernero', 44325),
(1973, 'esMX', 'Avanzada Azur, tabernero', 44325),
(1973, 'frFR', 'Guet d''azur, aubergiste', 44325),
(1973, 'itIT', 'Locanda di Presidio Azzurro', 44325),
(1973, 'koKR', '하늘 감시초소, 여관주인', 44325),
(1973, 'ptBR', 'Entreposto Lazúli, Estalajadeiro', 44325),
(1973, 'ruRU', 'Лазурная застава: трактирщик', 44325),
(1973, 'zhCN', '碧蓝岗哨旅店老板', 44325),
(1973, 'zhTW', '藍色守望，旅店老闆', 44325),
(1974, 'deDE', 'Paladinlehrer der Azurwacht', 44325),
(1974, 'esES', 'Avanzada Azur, instructor de paladines', 44325),
(1974, 'esMX', 'Avanzada Azur, instructor de paladines', 44325),
(1974, 'frFR', 'Guet d''azur, maître des paladins', 44325),
(1974, 'itIT', 'Istruttore dei Paladini di Presidio Azzurro', 44325),
(1974, 'koKR', '하늘 감시초소 상급 성기사', 44325),
(1974, 'ptBR', 'Entreposto Lazúli, Treinamento de Paladinos', 44325),
(1974, 'ruRU', 'Лазурная застава: наставник палад', 44325), -- Лазурная застава: наставник паладинов (truncated)
(1974, 'zhCN', '碧蓝岗哨圣骑士训练师', 44325),
(1974, 'zhTW', '藍色守望，聖騎士訓練師', 44325),
(1975, 'deDE', 'Priesterlehrer der Azurwacht', 44325),
(1975, 'esES', 'Avanzada Azur, instructor de sacerdotes', 44325),
(1975, 'esMX', 'Avanzada Azur, instructor de sacerdotes', 44325),
(1975, 'frFR', 'Guet d''azur, maître des prêtres', 44325),
(1975, 'itIT', 'Istruttore dei Sacerdoti di Presidio Azzurro', 44325),
(1975, 'koKR', '하늘 감시초소 상급 사제', 44325),
(1975, 'ptBR', 'Entreposto Lazúli, Treinamento de Sacerdotes', 44325),
(1975, 'ruRU', 'Лазурная застава: наставник жрецо', 44325), -- Лазурная застава: наставник жрецов (truncated)
(1975, 'zhCN', '碧蓝岗哨牧师训练师', 44325),
(1975, 'zhTW', '藍色守望，牧師訓練師', 44325),
(1976, 'deDE', 'Magierlehrer der Azurwacht', 44325),
(1976, 'esES', 'Avanzada Azur, instructor de magos', 44325),
(1976, 'esMX', 'Avanzada Azur, instructor de magos', 44325),
(1976, 'frFR', 'Guet d''azur, maître des mages', 44325),
(1976, 'itIT', 'Istruttore dei Maghi di Presidio Azzurro', 44325),
(1976, 'koKR', '하늘 감시초소 상급 마법사', 44325),
(1976, 'ptBR', 'Entreposto Lazúli, Treinamento de Magos', 44325),
(1976, 'ruRU', 'Лазурная застава: наставник магов', 44325),
(1976, 'zhCN', '碧蓝岗哨法师训练师', 44325),
(1976, 'zhTW', '藍色守望，法師訓練師', 44325),
(1977, 'deDE', 'Kriegerlehrer der Azurwacht', 44325),
(1977, 'esES', 'Avanzada Azur, instructor de guerreros', 44325),
(1977, 'esMX', 'Avanzada Azur, instructor de guerreros', 44325),
(1977, 'frFR', 'Guet d''azur, maître des guerriers', 44325),
(1977, 'itIT', 'Istruttore dei Guerrieri di Presidio Azzurro', 44325),
(1977, 'koKR', '하늘 감시초소 상급 전사', 44325),
(1977, 'ptBR', 'Entreposto Lazúli, Treinamento de Guerreiros', 44325),
(1977, 'ruRU', 'Лазурная застава: наставник воино', 44325), -- Лазурная застава: наставник воинов (truncated)
(1977, 'zhCN', '碧蓝岗哨战士训练师', 44325),
(1977, 'zhTW', '藍色守望，戰士訓練師', 44325),
(1978, 'deDE', 'Jägerlehrer der Azurwacht', 44325),
(1978, 'esES', 'Avanzada Azur, instructor de cazadores', 44325),
(1978, 'esMX', 'Avanzada Azur, instructor de cazadores', 44325),
(1978, 'frFR', 'Guet d''azur, maître des chasseurs', 44325),
(1978, 'itIT', 'Istruttore dei Cacciatori di Presidio Azzurro', 44325),
(1978, 'koKR', '하늘 감시초소 상급 사냥꾼', 44325),
(1978, 'ptBR', 'Entreposto Lazúli, Treinamento de Caçadores', 44325),
(1978, 'ruRU', 'Лазурная застава: наставник охотн', 44325), -- Лазурная застава: наставник охотников (truncated)
(1978, 'zhCN', '碧蓝岗哨猎人训练师', 44325),
(1978, 'zhTW', '藍色守望，獵人訓練師', 44325),
(3059, 'deDE', 'Berufsausbilder der Azurwacht', 44325),
(3059, 'esES', 'Avanzada Azur, instructor de profesión', 44325),
(3059, 'esMX', 'Avanzada Azur, instructor de profesión', 44325),
(3059, 'frFR', 'Guet d''azur, maître de métier', 44325),
(3059, 'itIT', 'Istruttore delle Professioni di Presidio Azzurro', 44325),
(3059, 'koKR', '하늘 감시초소 기술 전문가', 44325),
(3059, 'ptBR', 'Entreposto Lazúli, Treinamento de Profissão', 44325),
(3059, 'ruRU', 'Лазурная застава: учитель професс', 44325), -- Лазурная застава: учитель профессии (truncated)
(3059, 'zhCN', '碧蓝岗哨专业训练师', 44325),
(3059, 'zhTW', '藍色守望，專業技能訓練師', 44325);
