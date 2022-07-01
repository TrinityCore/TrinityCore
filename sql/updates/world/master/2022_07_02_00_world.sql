-- Selina Dourman
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_selina_dourman' WHERE `entry`=10445;

UPDATE `gossip_menu_option` SET `VerifiedBuild`=44127 WHERE `MenuID`=13076;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=13075;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=13113;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,13075,18362,0,0,22,1,974,0,0,1,0,0,'','Show gossip text 18362 if creature is not located in Darkmoon Faire'),
(14,13075,18372,0,0,22,1,974,0,0,0,0,0,'','Show gossip text 18372 if creature is located in Darkmoon Faire'),
(15,13113,0,0,0,2,0,71634,1,1,1,0,0,'','Show gossip option if player does not have has Darkmoon Adventurer''s Guide'),
(15,13113,0,0,0,47,0,7905,64,0,0,0,0,'','Show gossip option if quest 7905 is rewarded'),
(15,13113,0,0,1,2,0,71634,1,1,1,0,0,'','Show gossip option if player does not have has Darkmoon Adventurer''s Guide'),
(15,13113,0,0,1,47,0,7926,64,0,0,0,0,'','Show gossip option if quest 7926 is rewarded');

DELETE FROM `creature_text` WHERE `CreatureID`=10445;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10445, 0, 0, 'Welcome to the Darkmoon Faire, $c!', 12, 0, 100, 70, 0, 0, 0, 53804, 0, 'Selina Dourman - Welcome Random text'),
(10445, 0, 1, 'Welcome to the Darkmoon Faire!', 12, 0, 100, 70, 0, 0, 0, 53805, 0, 'Selina Dourman - Welcome Random text'),
(10445, 0, 2, 'Welcome!', 12, 0, 100, 70, 0, 0, 0, 53806, 0, 'Selina Dourman - Welcome Random text'),
(10445, 0, 3, 'Greetings!', 12, 0, 100, 70, 0, 0, 0, 53808, 0, 'Selina Dourman - Welcome Random text');

DELETE FROM `smart_scripts` WHERE `entryorguid`=10445;

DELETE FROM `areatrigger_scripts` WHERE `entry`=7016;
INSERT INTO `areatrigger_scripts` VALUES
(7016, 'at_darkmoon_faire_entrance');

DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 10463 AND 10468;
DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 2716 AND 2721;
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `PositionZ`, `Icon`, `Flags`, `Importance`, `Name`, `Unknown905`, `VerifiedBuild`) VALUES
(2716, -3998.494873046875, 6280.140625, 13.06377983093261718, 7, 99, 0, 'AAA Whack-a-Gnoll', 0, 44127),
(2717, -4018.01904296875, 6292.56103515625, 13.03492259979248046, 7, 99, 0, 'AAA Cannon', 0, 44127),
(2718, -4076.423583984375, 6351.39599609375, 13.00009632110595703, 7, 99, 0, 'AAA Shooting Gallery', 0, 44127),
(2719, -4128.34033203125, 6324.9287109375, 13.11676025390625, 7, 99, 0, 'AAA Tonk Arena', 0, 44127),
(2720, -4263.24853515625, 6281.23095703125, 13.11678886413574218, 7, 99, 0, 'AAA Fortune Teller', 0, 44127),
(2721, -4290.15625, 6308.5537109375, 13.11675357818603515, 7, 99, 0, 'AAA Ring Toss', 0, 44127);

DELETE FROM `points_of_interest_locale` WHERE `ID` BETWEEN 2716 AND 2721;
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(2716, 'deDE', 'Hau-den-Gnoll', 44127),
(2716, 'esES', 'AAA Whack-a-Gnoll', 44127),
(2716, 'esMX', 'AAA Whack-a-Gnoll', 44127),
(2716, 'frFR', 'AAA Cogne-Gnoll', 44127),
(2716, 'itIT', 'AAA Pesta-lo-Gnoll', 44127),
(2716, 'koKR', 'AAA 놀 때려잡기', 44127),
(2716, 'ptBR', 'AAA Pancada-no-Gnoll', 44127),
(2716, 'ruRU', 'ААА Гноллобой', 44127),
(2716, 'zhCN', '3A级打豺狼人', 44127),
(2716, 'zhTW', 'AAA痛扁豺狼人', 44127),
(2717, 'deDE', 'Kanone', 44127),
(2717, 'esES', 'AAA Cannon', 44127),
(2717, 'esMX', 'AAA Cannon', 44127),
(2717, 'frFR', 'AAA Canon', 44127),
(2717, 'itIT', 'AAA Cannone', 44127),
(2717, 'koKR', 'AAA 대포', 44127),
(2717, 'ptBR', 'AAA Canhão', 44127),
(2717, 'ruRU', 'ААА Пушка', 44127),
(2717, 'zhCN', '3A级暗月大炮', 44127),
(2717, 'zhTW', 'AAA火砲', 44127),
(2718, 'deDE', 'Schießbude', 44127),
(2718, 'esES', 'AAA Shooting Gallery', 44127),
(2718, 'esMX', 'AAA Shooting Gallery', 44127),
(2718, 'frFR', 'AAA Stand de tir', 44127),
(2718, 'itIT', 'AAA Tiro a Segno', 44127),
(2718, 'koKR', 'AAA 사격 연습장', 44127),
(2718, 'ptBR', 'AAA Galeria de Tiro', 44127),
(2718, 'ruRU', 'ААА Тир', 44127),
(2718, 'zhCN', '3A级射击场', 44127),
(2718, 'zhTW', 'AAA打靶場', 44127),
(2719, 'deDE', 'Panzerarena', 44127),
(2719, 'esES', 'AAA Tonk Arena', 44127),
(2719, 'esMX', 'AAA Tonk Arena', 44127),
(2719, 'frFR', 'AAA Arène à chariottes', 44127),
(2719, 'itIT', 'AAA Arena dei Carri Giocattoli', 44127),
(2719, 'koKR', 'AAA 통통 전차 게임장', 44127),
(2719, 'ptBR', 'AAA Arena de Tonques', 44127),
(2719, 'ruRU', 'ААА Танковая арена', 44127),
(2719, 'zhCN', '3A级蒸汽坦克竞技场', 44127),
(2719, 'zhTW', 'AAA坦克競技場', 44127),
(2720, 'deDE', 'Wahrsager', 44127),
(2720, 'esES', 'AAA Fortune Teller', 44127),
(2720, 'esMX', 'AAA Fortune Teller', 44127),
(2720, 'frFR', 'AAA Diseuse de bonne aventure', 44127),
(2720, 'itIT', 'AAA Indovina', 44127),
(2720, 'koKR', 'AAA 점술소', 44127),
(2720, 'ptBR', 'AAA Cartomante', 44127),
(2720, 'ruRU', 'ААА Предсказание судьбы', 44127),
(2720, 'zhCN', '3A级占卜师', 44127),
(2720, 'zhTW', 'AAA占卜師', 44127),
(2721, 'deDE', 'Ringwurf', 44127),
(2721, 'esES', 'AAA Ring Toss', 44127),
(2721, 'esMX', 'AAA Ring Toss', 44127),
(2721, 'frFR', 'AAA Lancer d\’anneaux', 44127),
(2721, 'itIT', 'AAA Lancio degli Anelli', 44127),
(2721, 'koKR', 'AAA 고리 던지기', 44127),
(2721, 'ptBR', 'AAA Arremesso de Argolas', 44127),
(2721, 'ruRU', 'ААА Метание колец', 44127),
(2721, 'zhCN', '3A级套圈圈', 44127),
(2721, 'zhTW', 'AAA丟圈圈', 44127);
