-- Braves (Bloodhoof Village)
UPDATE `creature_template` SET `gossip_menu_id`=3331 WHERE `entry` IN (3215, 3218, 3219, 3222, 3223);

DELETE FROM `gossip_menu` WHERE `MenuID`=15772;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(15772,22658,-1);

DELETE FROM `npc_text` WHERE `ID`=22658;
INSERT INTO `npc_text` (`ID`, `Probability0`, `BroadcastTextID0`, `VerifiedBuild`) VALUES
(22658,1,74782,-1);

UPDATE `npc_text` SET `Probability0`=0, `Probability1`=0 WHERE `ID`=4052;

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6719, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=3311 WHERE `MenuID`=3331 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=3312 WHERE `MenuID`=3331 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6721, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=3313, `ActionPoiID`=604 WHERE `MenuID`=3331 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8515, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=4903, `ActionPoiID`=849 WHERE `MenuID`=3331 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6722, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=3329 WHERE `MenuID`=3331 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6723, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=15772, `ActionPoiID`=3085 WHERE `MenuID`=3331 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2914, `ActionPoiID`=606 WHERE `MenuID`=3329 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2924, `ActionPoiID`=608 WHERE `MenuID`=3329 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2922, `ActionMenuID`=8192, `ActionPoiID`=2556 WHERE `MenuID`=3329 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2918, `ActionMenuID`=8193, `ActionPoiID`=2555 WHERE `MenuID`=3329 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3450, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=3316, `ActionPoiID`=607 WHERE `MenuID`=3329 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2910, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=3317, `ActionPoiID`=609 WHERE `MenuID`=3329 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=44325 WHERE `MenuID` IN (3331, 3329);

DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 10419 AND 10424;
DELETE FROM `points_of_interest` WHERE `ID` IN (604, 606, 607, 608, 609, 849, 2555, 2556, 3085);
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `PositionZ`, `Icon`, `Flags`, `Importance`, `Name`, `Unknown905`, `VerifiedBuild`) VALUES
(604, -2361.389892578125, -349.1929931640625, -8.95697021484375, 7, 99, 0, 'Bloodhoof Village Inn', 0, 44325),
(606, -2312.159912109375, -443.6929931640625, -5.43839979171752929, 7, 99, 0, 'Gennia Runetotem', 0, 44325),
(607, -2301.5, -439.871002197265625, -5.43839979171752929, 7, 99, 0, 'Narm Skychaser', 0, 44325),
(608, -2178.14990234375, -406.144012451171875, -4.59803009033203125, 7, 99, 0, 'Yaw Sharpmane', 0, 44325),
(609, -2345.43994140625, -494.114013671875, -8.89953041076660156, 7, 99, 0, 'Krang Stonehoof', 0, 44325),
(849, -2338.860107421875, -357.563995361328125, -8.71675014495849609, 7, 99, 0, 'Seikwa', 0, 44325),
(2555, -2301.428955078125, -451.81597900390625, -5.43838787078857421, 7, 99, 0, 'Seer Alsoomse', 0, 44325),
(2556, -2309.585205078125, -452.520843505859375, -5.43839073181152343, 7, 99, 0, 'Sunwalker Iopi', 0, 44325),
(3085, -2264.005126953125, -324.8194580078125, -9.42490959167480468, 7, 99, 0, 'Lalum Darkmane', 0, 44325);

DELETE FROM `points_of_interest_locale` WHERE `ID` IN (604, 606, 607, 608, 609, 849, 2555, 2556, 3085);
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
( 604, 'deDE', 'Gasthaus der Bluthufe', 44325),
( 604, 'esES', 'Posada del Poblado Pezuña de Sangre', 44325),
( 604, 'esMX', 'Posada del Poblado Pezuña de Sangre', 44325),
( 604, 'frFR', 'Auberge de Sabot-de-Sang', 44325),
( 604, 'itIT', 'Locanda del Villaggio di Zoccolo Sanguinario', 44325),
( 604, 'koKR', '블러드후프 마을 여관', 44325),
( 604, 'ptBR', 'Estalagem da Aldeia Casco Sangrento', 44325),
( 604, 'ruRU', 'Таверна в деревне Кровавого Копыт', 44325), -- Таверна в деревне Кровавого Копыта (truncated)
( 604, 'zhCN', '血蹄村旅店', 44325),
( 604, 'zhTW', '血蹄村旅店', 44325),
( 606, 'deDE', 'Gennia Runentotem', 44325),
( 606, 'esES', 'Gennia Tótem de Runa', 44325),
( 606, 'esMX', 'Gennia Tótem de Runa', 44325),
( 606, 'frFR', 'Gennia Totem-Runique', 44325),
( 606, 'itIT', 'Gennia Totem Runico', 44325),
( 606, 'koKR', '제니아 룬토템', 44325),
( 606, 'ptBR', 'Gennia Runa Totem', 44325),
( 606, 'ruRU', 'Генния Рунический Тотем', 44325),
( 606, 'zhCN', '根妮亚·符文图腾', 44325),
( 606, 'zhTW', '潔妮亞‧符文圖騰', 44325),
( 607, 'deDE', 'Narm Himmelsjäger', 44325),
( 607, 'esES', 'Narm Cazacielo', 44325),
( 607, 'esMX', 'Narm Cazacielo', 44325),
( 607, 'frFR', 'Narm Chasse-le-Ciel', 44325),
( 607, 'itIT', 'Narm Preda Cielo', 44325),
( 607, 'koKR', '나름 스카이체이서', 44325),
( 607, 'ptBR', 'Narm Persegue-céus', 44325),
( 607, 'ruRU', 'Нарм Небесный Охотник', 44325),
( 607, 'zhCN', '纳姆·逐星', 44325),
( 607, 'zhTW', '納姆‧逐星', 44325),
( 608, 'deDE', 'Yaw Scharfmähne', 44325),
( 608, 'esES', 'Yaw Crinafilada', 44325),
( 608, 'esMX', 'Yaw Crinafilada', 44325),
( 608, 'frFR', 'Yaw Crin-tranchant', 44325),
( 608, 'itIT', 'Yaw Chioma Rasa', 44325),
( 608, 'koKR', '요 샤프메인', 44325),
( 608, 'ptBR', 'Yaw Crina Cortante', 44325),
( 608, 'ruRU', 'Йо Колкая Грива', 44325),
( 608, 'zhCN', '雅文·刺鬃', 44325),
( 608, 'zhTW', '雅文‧刺鬃', 44325),
( 609, 'deDE', 'Krang Steinhuf', 44325),
( 609, 'esES', 'Krang Pezuña Pétrea', 44325),
( 609, 'esMX', 'Krang Pezuña Pétrea', 44325),
( 609, 'frFR', 'Krang Sabot-de-Pierre', 44325),
( 609, 'itIT', 'Krang Zoccolo Granitico', 44325),
( 609, 'koKR', '크랑 스톤후프', 44325),
( 609, 'ptBR', 'Krang Casco de Pedra', 44325),
( 609, 'ruRU', 'Кранг Каменное Копыто', 44325),
( 609, 'zhCN', '克朗·石蹄', 44325),
( 609, 'zhTW', '克朗‧石蹄', 44325),
( 849, 'deDE', 'Seikwa', 44325),
( 849, 'esES', 'Seikwa', 44325),
( 849, 'esMX', 'Seikwa', 44325),
( 849, 'frFR', 'Seikwa', 44325),
( 849, 'itIT', 'Seikwa', 44325),
( 849, 'koKR', '세이크와', 44325),
( 849, 'ptBR', 'Seikwa', 44325),
( 849, 'ruRU', 'Сейква', 44325),
( 849, 'zhCN', '希克瓦', 44325),
( 849, 'zhTW', '希克瓦', 44325),
(2555, 'deDE', 'Seherin Alsoomse', 44325),
(2555, 'esES', 'Vidente Alsoomse', 44325),
(2555, 'esMX', 'Vidente Alsoomse', 44325),
(2555, 'frFR', 'Voyante Alsoomse', 44325),
(2555, 'itIT', 'Alsoomse il Veggente', 44325),
(2555, 'koKR', '예언자 알숨세', 44325),
(2555, 'ptBR', 'Vidente Alsoomse', 44325),
(2555, 'ruRU', 'Провидица Алсумс', 44325),
(2555, 'zhCN', '先知艾尔苏', 44325),
(2555, 'zhTW', '先知艾爾蘇姆', 44325),
(2556, 'deDE', 'Sonnenläufer Iopi', 44325),
(2556, 'esES', 'Caminasol Iopi', 44325),
(2556, 'esMX', 'Caminasol Iopi', 44325),
(2556, 'frFR', 'Marche-soleil Iopi', 44325),
(2556, 'itIT', 'Campione del Sole Iopi', 44325),
(2556, 'koKR', '태양길잡이 아이오피', 44325),
(2556, 'ptBR', 'Andarilho do Sol Iopi', 44325),
(2556, 'ruRU', 'Служитель Солнца Лопи', 44325),
(2556, 'zhCN', '烈日行者艾乌比', 44325),
(2556, 'zhTW', '日行者伊歐畢', 44325),
(3085, 'deDE', 'Lalum Dunkelmähne', 44325),
(3085, 'esES', 'Lalum Crin Oscura', 44325),
(3085, 'esMX', 'Lalum Crinoscura', 44325),
(3085, 'frFR', 'Lalum Sombre-Crin', 44325),
(3085, 'itIT', 'Lalum Chioma Nera', 44325),
(3085, 'koKR', '랄룸 다크메인', 44325),
(3085, 'ptBR', 'Lalum Crina Negra', 44325),
(3085, 'ruRU', 'Лалум Темная Грива', 44325),
(3085, 'zhCN', '拉鲁姆·黑鬃', 44325),
(3085, 'zhTW', '菈盧姆‧黑鬃', 44325);
