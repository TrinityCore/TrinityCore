-- Aldor Vindicator | Scryer Arcane Guardian | Shattrath City Peacekeeper (Shattrath)
DELETE FROM `gossip_menu` WHERE `MenuID` IN (12338, 12749, 12944, 12945, 12946, 12947, 12948, 12955, 12961, 12962, 12963, 12964);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(12338,10518,-1),
(12749,17896,-1),
(12944,18214,-1),
(12945,18214,-1),
(12946,18214,-1),
(12947,18214,-1),
(12948,18214,-1),
(12955,18227,-1),
(12961,18229,-1),
(12962,18230,-1),
(12963,18232,-1),
(12964,18233,-1);

UPDATE `npc_text` SET `BroadcastTextID0`=19655 WHERE `ID`=10528;

DELETE FROM `npc_text` WHERE `ID` IN (18214);
INSERT INTO `npc_text` (`ID`, `Probability0`, `BroadcastTextID0`, `VerifiedBuild`) VALUES
(18214,1,52733,-1);

UPDATE `gossip_menu_option` SET `ActionPoiID`=2029 WHERE `MenuID`=8419 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19201, `ActionPoiID`=2028 WHERE `MenuID`=8419 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19202, `ActionPoiID`=2047 WHERE `MenuID`=8419 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19203, `ActionPoiID`=2035 WHERE `MenuID`=8419 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19204, `ActionPoiID`=2047 WHERE `MenuID`=8419 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19208, `ActionPoiID`=2049 WHERE `MenuID`=8419 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionText`='Class Trainer', `OptionBroadcastTextId`=15234, `ActionMenuID`=12748, `ActionPoiID`=2646 WHERE `MenuID`=8419 AND `OptionID`=7;
UPDATE `gossip_menu_option` SET `OptionText`='Profession Trainer', `OptionBroadcastTextId`=19210, `ActionMenuID`=8424, `ActionPoiID`=0 WHERE `MenuID`=8419 AND `OptionID`=8;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2055 WHERE `MenuID`=8419 AND `OptionID`=9;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2057 WHERE `MenuID`=8419 AND `OptionID`=10;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2036 WHERE `MenuID`=8323 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2037 WHERE `MenuID`=8323 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2095 WHERE `MenuID`=8323 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2038 WHERE `MenuID`=8424 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionText`='Archaeology', `OptionBroadcastTextId`=44649, `ActionMenuID`=12337, `ActionPoiID`=2538 WHERE `MenuID`=8424 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionText`='Blacksmithing', `OptionBroadcastTextId`=19249, `ActionMenuID`=8335, `ActionPoiID`=2042 WHERE `MenuID`=8424 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionText`='Cooking', `OptionBroadcastTextId`=19233, `ActionMenuID`=8328, `ActionPoiID`=2041 WHERE `MenuID`=8424 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionText`='Enchanting', `OptionBroadcastTextId`=19234, `ActionMenuID`=8425, `ActionPoiID`=2043 WHERE `MenuID`=8424 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionText`='Engineering', `OptionBroadcastTextId`=15259, `ActionMenuID`=12961, `ActionPoiID`=2700 WHERE `MenuID`=8424 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionText`='First Aid', `OptionBroadcastTextId`=19238, `ActionMenuID`=8331, `ActionPoiID`=2045 WHERE `MenuID`=8424 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `OptionText`='Fishing', `OptionBroadcastTextId`=15263, `ActionMenuID`=15400, `ActionPoiID`=2923 WHERE `MenuID`=8424 AND `OptionID`=7;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2029 WHERE `MenuID`=8357 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19201, `ActionPoiID`=2027 WHERE `MenuID`=8357 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19202, `ActionPoiID`=2046 WHERE `MenuID`=8357 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19203, `ActionPoiID`=2035 WHERE `MenuID`=8357 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19204, `ActionPoiID`=2046 WHERE `MenuID`=8357 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19208, `ActionPoiID`=2048 WHERE `MenuID`=8357 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15234, `ActionMenuID`=12749, `ActionPoiID`=2646 WHERE `MenuID`=8357 AND `OptionID`=7;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19210, `ActionMenuID`=8403, `ActionPoiID`=0 WHERE `MenuID`=8357 AND `OptionID`=8;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2055 WHERE `MenuID`=8357 AND `OptionID`=9;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2056 WHERE `MenuID`=8357 AND `OptionID`=10;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2036 WHERE `MenuID`=8365 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2037 WHERE `MenuID`=8365 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19232, `ActionPoiID`=2038 WHERE `MenuID`=8403 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionText`='Archaeology', `OptionBroadcastTextId`=44649, `ActionMenuID`=12338, `ActionPoiID`=2538 WHERE `MenuID`=8403 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionText`='Blacksmithing', `OptionBroadcastTextId`=19249, `ActionMenuID`=8412, `ActionPoiID`=2042 WHERE `MenuID`=8403 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionText`='Cooking', `OptionBroadcastTextId`=19233, `ActionMenuID`=8413, `ActionPoiID`=2041 WHERE `MenuID`=8403 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionText`='Enchanting', `OptionBroadcastTextId`=19234, `ActionMenuID`=8414, `ActionPoiID`=2043 WHERE `MenuID`=8403 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionText`='Engineering', `OptionBroadcastTextId`=15259, `ActionMenuID`=12944, `ActionPoiID`=2698 WHERE `MenuID`=8403 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionText`='First Aid', `OptionBroadcastTextId`=19238, `ActionMenuID`=8415, `ActionPoiID`=2045 WHERE `MenuID`=8403 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `OptionText`='Herbalism', `OptionBroadcastTextId`=15265, `ActionMenuID`=12945, `ActionPoiID`=2698 WHERE `MenuID`=8403 AND `OptionID`=7;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=31542, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=12946, `ActionPoiID`=2698 WHERE `MenuID`=8403 AND `OptionID`=8;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19235, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=8416, `ActionPoiID`=2044 WHERE `MenuID`=8403 AND `OptionID`=9;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19236, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=8417, `ActionPoiID`=2039 WHERE `MenuID`=8403 AND `OptionID`=10;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15271, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=12947, `ActionPoiID`=2698 WHERE `MenuID`=8403 AND `OptionID`=11;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19237, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=8418, `ActionPoiID`=2040 WHERE `MenuID`=8403 AND `OptionID`=12;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15275, `OptionType`=1, `OptionNpcFlag`=1, `ActionMenuID`=12948, `ActionPoiID`=2698 WHERE `MenuID`=8403 AND `OptionID`=13;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2029 WHERE `MenuID`=8282 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19201 WHERE `MenuID`=8282 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19202 WHERE `MenuID`=8282 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19203, `ActionPoiID`=2035 WHERE `MenuID`=8282 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19204 WHERE `MenuID`=8282 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19208 WHERE `MenuID`=8282 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2645 WHERE `MenuID`=8282 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15234, `ActionPoiID`=2646 WHERE `MenuID`=8282 AND `OptionID`=7;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19210, `ActionPoiID`=0 WHERE `MenuID`=8282 AND `OptionID`=8;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19209, `ActionMenuID`=8323, `ActionPoiID`=0 WHERE `MenuID`=8282 AND `OptionID`=9;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2055 WHERE `MenuID`=8282 AND `OptionID`=10;
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuID`=8282 AND `OptionID`=11;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2028 WHERE `MenuID`=8315 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2027 WHERE `MenuID`=8315 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2047 WHERE `MenuID`=8317 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2046 WHERE `MenuID`=8317 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2028 WHERE `MenuID`=8320 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2047 WHERE `MenuID`=8320 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2027 WHERE `MenuID`=8320 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2046 WHERE `MenuID`=8320 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2049 WHERE `MenuID`=8321 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2048 WHERE `MenuID`=8321 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2038 WHERE `MenuID`=8326 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2538 WHERE `MenuID`=8326 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19249, `ActionPoiID`=2042 WHERE `MenuID`=8326 AND `OptionID`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19233, `ActionPoiID`=2041 WHERE `MenuID`=8326 AND `OptionID`=3;
UPDATE `gossip_menu_option` SET `OptionText`='Enchanting', `OptionBroadcastTextId`=19234, `ActionMenuID`=8425, `ActionPoiID`=2917 WHERE `MenuID`=8326 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionText`='Engineering', `OptionBroadcastTextId`=15259, `ActionMenuID`=12961, `ActionPoiID`=2700 WHERE `MenuID`=8326 AND `OptionID`=6;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19234, `ActionPoiID`=2043 WHERE `MenuID`=8326 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15259, `ActionPoiID`=2698 WHERE `MenuID`=8326 AND `OptionID`=7;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19238, `OptionType`=1, `OptionNpcFlag`=1, `ActionPoiID`=2045 WHERE `MenuID`=8326 AND `OptionID`=8;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15263, `OptionType`=1, `OptionNpcFlag`=1, `ActionPoiID`=2923 WHERE `MenuID`=8326 AND `OptionID`=9;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15265, `OptionType`=1, `OptionNpcFlag`=1, `ActionPoiID`=2698 WHERE `MenuID`=8326 AND `OptionID`=11;
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1, `ActionPoiID`=2698 WHERE `MenuID`=8326 AND `OptionID`=13;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19235, `OptionType`=1, `OptionNpcFlag`=1, `ActionPoiID`=2698 WHERE `MenuID`=8326 AND `OptionID`=15;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19236, `OptionType`=1, `OptionNpcFlag`=1, `ActionPoiID`=2039 WHERE `MenuID`=8326 AND `OptionID`=16;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15271, `OptionType`=1, `OptionNpcFlag`=1, `ActionPoiID`=2698 WHERE `MenuID`=8326 AND `OptionID`=18;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15275, `OptionType`=1, `OptionNpcFlag`=1, `ActionPoiID`=2698 WHERE `MenuID`=8326 AND `OptionID`=20;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19237, `OptionType`=1, `OptionNpcFlag`=1, `ActionPoiID`=2040 WHERE `MenuID`=8326 AND `OptionID`=21;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2057 WHERE `MenuID`=8548 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `ActionPoiID`=2056 WHERE `MenuID`=8548 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=44908 WHERE `MenuID` IN (8419, 8323, 8424, 8357, 8365, 8403, 8282, 8315, 8317, 8320, 8321, 8326, 8548);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=8326 AND `OptionID` IN (10, 12, 14, 17, 19);
DELETE FROM `gossip_menu_option` WHERE `MenuID`=8424 AND `OptionID` IN (8, 9, 10, 11, 12, 13, 14);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8326, 10, 0, 'Herbalism', 15265, 1, 1, 0, 12962, 2701, 0, 0, NULL, 0, 44908),
(8326, 12, 0, 'Inscription', 31542, 1, 1, 0, 12955, 2699, 0, 0, NULL, 0, 44908),
(8326, 14, 0, 'Jewelcrafting', 19235, 1, 1, 0, 8426, 2918, 0, 0, NULL, 0, 44908),
(8326, 17, 0, 'Mining', 15271, 1, 1, 0, 12963, 2702, 0, 0, NULL, 0, 44908),
(8326, 19, 0, 'Tailoring', 15275, 1, 1, 0, 12964, 2703, 0, 0, NULL, 0, 44908),
(8424, 8, 0, 'Herbalism', 15265, 1, 1, 0, 12962, 2701, 0, 0, NULL, 0, 44908),
(8424, 9, 0, 'Inscription', 31542, 1, 1, 0, 12955, 2699, 0, 0, NULL, 0, 44908),
(8424, 10, 0, 'Jewelcrafting', 19235, 1, 1, 0, 8426, 2044, 0, 0, NULL, 0, 44908),
(8424, 11, 0, 'Leatherworking', 19236, 1, 1, 0, 8334, 2039, 0, 0, NULL, 0, 44908),
(8424, 12, 0, 'Mining', 15271, 1, 1, 0, 12963, 2702, 0, 0, NULL, 0, 44908),
(8424, 13, 0, 'Skinning', 19237, 1, 1, 0, 8333, 2040, 0, 0, NULL, 0, 44908),
(8424, 14, 0, 'Tailoring', 15275, 1, 1, 0, 12964, 2703, 0, 0, NULL, 0, 44908);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8326;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,8326,4,0,0,5,0,932,240,0,0,0,0,'','Show gossip option if the player is friendly with the Aldor'),
(15,8326,5,0,0,5,0,932,240,0,1,0,0,'','Show gossip option if the player is not friendly with the Aldor'),
(15,8326,6,0,0,5,0,932,240,0,0,0,0,'','Show gossip option if the player is friendly with the Aldor'),
(15,8326,7,0,0,5,0,932,240,0,1,0,0,'','Show gossip option if the player is not friendly with the Aldor'),
(15,8326,10,0,0,5,0,932,240,0,0,0,0,'','Show gossip option if the player is friendly with the Aldor'),
(15,8326,11,0,0,5,0,932,240,0,1,0,0,'','Show gossip option if the player is not friendly with the Aldor'),
(15,8326,12,0,0,5,0,932,240,0,0,0,0,'','Show gossip option if the player is friendly with the Aldor'),
(15,8326,13,0,0,5,0,932,240,0,1,0,0,'','Show gossip option if the player is not friendly with the Aldor'),
(15,8326,14,0,0,5,0,932,240,0,0,0,0,'','Show gossip option if the player is friendly with the Aldor'),
(15,8326,15,0,0,5,0,932,240,0,1,0,0,'','Show gossip option if the player is not friendly with the Aldor'),
(15,8326,17,0,0,5,0,932,240,0,0,0,0,'','Show gossip option if the player is friendly with the Aldor'),
(15,8326,18,0,0,5,0,932,240,0,1,0,0,'','Show gossip option if the player is not friendly with the Aldor'),
(15,8326,19,0,0,5,0,932,240,0,0,0,0,'','Show gossip option if the player is friendly with the Aldor'),
(15,8326,20,0,0,5,0,932,240,0,1,0,0,'','Show gossip option if the player is not friendly with the Aldor');

DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 10240 AND 10262;
DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 10610 AND 10614;
DELETE FROM `points_of_interest` WHERE `ID` IN (2027, 2028, 2029, 2035, 2036, 2037, 2038, 2039, 2040, 2041, 2042, 2043, 2044, 2045, 2046, 2047, 2048, 2049, 2055, 2056, 2057, 2095, 2538, 2645, 2646, 2698, 2699, 2700, 2701, 2702, 2703, 2917, 2918, 2923);
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `PositionZ`, `Icon`, `Flags`, `Importance`, `Name`, `Unknown905`, `VerifiedBuild`) VALUES
(2027, -2002.219970703125, 5360.93994140625, -9.35093021392822265, 7, 99, 0, 'Shattrath Bank Scryer', 0, 44908),
(2028, -1725.9300537109375, 5498.330078125, -9.79944038391113281, 7, 99, 0, 'Shattrath Bank Aldor', 0, 44908),
(2029, -1758.280029296875, 5162.919921875, -37.2048988342285156, 7, 99, 0, 'Shattrath Cantina', 0, 44908),
(2035, -1833.510009765625, 5300.31005859375, -12.4280996322631835, 7, 99, 0, 'Shattrath Taxi', 0, 44908),
(2036, -1770.7099609375, 5259.7900390625, -38.8263015747070312, 7, 99, 0, 'Shattrath Battlemasters Alliance', 0, 44908),
(2037, -1964.780029296875, 5264.259765625, -38.8272018432617187, 7, 99, 0, 'Shattrath Battlemasters Horde', 0, 44908),
(2038, -1657.6300048828125, 5537.6201171875, -5.09409999847412109, 7, 99, 0, 'Shattrath Alchemist', 0, 44908),
(2039, -2061.010009765625, 5256.4599609375, -38.4651985168457031, 7, 99, 0, 'Shattrath Leatherworker', 0, 44908),
(2040, -2047.9599609375, 5299.77978515625, -38.5919990539550781, 7, 99, 0, 'Shattrath Skinner', 0, 44908),
(2041, -2067.639892578125, 5316.7900390625, -37.3235015869140625, 7, 99, 0, 'Shattrath Cook', 0, 44908),
(2042, -1847.52001953125, 5221.919921875, -38.0453987121582031, 7, 99, 0, 'Shattrath Armor/Weapon Crafter', 0, 44908),
(2043, -2254.669921875, 5560.77001953125, 67.01740264892578125, 7, 99, 0, 'Shattrath Enchanters', 0, 44908),
(2044, -1653.9100341796875, 5665.02978515625, 132.6909942626953125, 7, 99, 0, 'Shattrath Jewelcrafter', 0, 44908),
(2045, -1590.8900146484375, 5263.10009765625, -13.9913997650146484, 7, 99, 0, 'Shattrath First Aid', 0, 44908),
(2046, -2183.820068359375, 5402.47998046875, 51.88249969482421875, 7, 99, 0, 'Shattrath Inn Scryer', 0, 44908),
(2047, -1900.5999755859375, 5769.1201171875, 131.212005615234375, 7, 99, 0, 'Shattrath Inn Aldor', 0, 44908),
(2048, -2170.070068359375, 5403.830078125, 50.22790145874023437, 7, 99, 0, 'Shattrath Stable Scryer', 0, 44908),
(2049, -1890.22998046875, 5759.7099609375, 129.5500030517578125, 7, 99, 0, 'Shattrath Stable Aldor', 0, 44908),
(2055, -1644.8499755859375, 5566.9501953125, -4.90904998779296875, 7, 99, 0, 'Shattrath Alchemy Lab', 0, 44908),
(2056, -2194.360107421875, 5422.41015625, 50.22790145874023437, 7, 99, 0, 'Scryer Gem Vendor', 0, 44908),
(2057, -1643.77001953125, 5669.4599609375, 132.6790008544921875, 7, 99, 0, 'Aldor Gem Vendor', 0, 44908),
(2095, -1961.7900390625, 5175.169921875, -37.8599014282226562, 7, 99, 0, 'Shattrath Arena Battlemasters', 0, 44908),
(2538, -2086.52001953125, 5316.64013671875, -37.3236007690429687, 7, 99, 0, 'Shattrath Archaeology', 0, 44908),
(2645, -1877.3333740234375, 5365.51220703125, -12.5046892166137695, 7, 99, 0, 'Shattrath Guild Services', 0, 44908),
(2646, -1863.638916015625, 5430.00634765625, -9.70548534393310546, 7, 99, 0, 'Shattrath City Center', 0, 44908),
(2698, -2258.86279296875, 5563.9296875, 67.01284027099609375, 7, 99, 0, 'The Seer''s Library', 0, 44908),
(2699, -1854.30908203125, 5663.3505859375, 128.4940948486328125, 7, 99, 0, 'Aldor Inscription Trainer', 0, 44908),
(2700, -1750.96875, 5642.0009765625, 129.0659942626953125, 7, 99, 0, 'Aldor Engineering Trainer', 0, 44908),
(2701, -1737.53125, 5635.62841796875, 128.023193359375, 7, 99, 0, 'Aldor Herbalism Trainer', 0, 44908),
(2702, -1897.407958984375, 5664.32666015625, 128.5052490234375, 7, 99, 0, 'Aldor Mining Trainer', 0, 44908),
(2703, -1708.85595703125, 5642.91162109375, 129.0735015869140625, 7, 99, 0, 'Aldor Tailoring Trainer', 0, 44908),
(2917, -1858.8853759765625, 5659.35009765625, 127.458251953125, 7, 99, 0, 'Aldor Enchanting Trainer', 0, 44908),
(2918, -1892, 5664.9833984375, 127.458251953125, 7, 99, 0, 'Aldor Jewelcrafting Trainer', 0, 44908),
(2923, -1460.84033203125, 4992.25, -9.08193111419677734, 7, 99, 0, 'Old Man Barlo', 0, 44908);

DELETE FROM `points_of_interest_locale` WHERE `ID` IN (2027, 2028, 2029, 2035, 2036, 2037, 2038, 2039, 2040, 2041, 2042, 2043, 2044, 2045, 2046, 2047, 2048, 2049, 2055, 2056, 2057, 2095, 2538, 2645, 2646, 2698, 2699, 2700, 2701, 2702, 2703, 2917, 2918, 2923);
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(2027, 'deDE', 'Seherbank von Shattrath', 44908),
(2027, 'esES', 'Shattrath, banco del Arúspice', 44908),
(2027, 'esMX', 'Shattrath, banco del Arúspice', 44908),
(2027, 'frFR', 'Banque des Clairvoyants de Shattrath', 44908),
(2027, 'itIT', 'Banca dei Veggenti di Shattrath', 44908),
(2027, 'koKR', '샤트라스 점술가 길드 은행', 44908),
(2027, 'ptBR', 'Banco de Shattrath, Áugures', 44908),
(2027, 'ruRU', 'Банк Шаттрата (Провидцы)', 44908),
(2027, 'zhCN', '沙塔斯银行：占星者', 44908),
(2027, 'zhTW', '撒塔斯銀行占卜者', 44908),
(2028, 'deDE', 'Bank der Aldor von Shattrath', 44908),
(2028, 'esES', 'Shattrath, banco Aldor', 44908),
(2028, 'esMX', 'Shattrath, banco Aldor', 44908),
(2028, 'frFR', 'Banque de l''Aldor de Shattrath', 44908),
(2028, 'itIT', 'Banca degli Aldor di Shattrath', 44908),
(2028, 'koKR', '샤트라스 알도르 사제회 은행', 44908),
(2028, 'ptBR', 'Banco de Shattrath, Aldor', 44908),
(2028, 'ruRU', 'Банк Шаттрата (Алдор)', 44908),
(2028, 'zhCN', '沙塔斯银行：奥尔多', 44908),
(2028, 'zhTW', '撒塔斯銀行奧多爾', 44908),
(2029, 'deDE', 'Wirtshaus von Shattrath', 44908),
(2029, 'esES', 'Shattrath, cantina', 44908),
(2029, 'esMX', 'Shattrath, cantina', 44908),
(2029, 'frFR', 'La cantina de Shattrath', 44908),
(2029, 'itIT', 'Taverna di Shattrath', 44908),
(2029, 'koKR', '샤트라스 선술집', 44908),
(2029, 'ptBR', 'Cantina de Shattrath', 44908),
(2029, 'ruRU', 'Шаттрат: бакалейная лавка', 44908),
(2029, 'zhCN', '沙塔斯酒吧', 44908),
(2029, 'zhTW', '撒塔斯小酒店', 44908),
(2035, 'deDE', 'Flugmeister von Shattrath', 44908),
(2035, 'esES', 'Shattrath, taxi', 44908),
(2035, 'esMX', 'Shattrath, taxi', 44908),
(2035, 'frFR', 'Transports de Shattrath', 44908),
(2035, 'itIT', 'Trasporto di Shattrath', 44908),
(2035, 'koKR', '샤트라스 비행 조련사', 44908),
(2035, 'ptBR', 'Táxi de Shattrath', 44908),
(2035, 'ruRU', 'Shattrath Taxi', 44908), -- Blizzlike
(2035, 'zhCN', '沙塔斯飞行点', 44908),
(2035, 'zhTW', '撒塔斯飛行點', 44908),
(2036, 'deDE', 'Kampfmeister der Allianz von Shattrath', 44908),
(2036, 'esES', 'Shattrath, maestros de batalla de la Alianza', 44908),
(2036, 'esMX', 'Shattrath, maestros de batalla de la Alianza', 44908),
(2036, 'frFR', 'Maîtres de guerre de l''Alliance de Shattrath', 44908),
(2036, 'itIT', 'Maestri di Guerra dell''Alleanza di Shattrath', 44908),
(2036, 'koKR', '샤트라스 얼라이언스 전투모병관', 44908),
(2036, 'ptBR', 'Mestres de Batalha de Shattrath, Aliança', 44908),
(2036, 'ruRU', 'Военачальники Шаттрата (Альянс)', 44908),
(2036, 'zhCN', '沙塔斯联盟军官', 44908),
(2036, 'zhTW', '撒塔斯戰場軍官聯盟', 44908),
(2037, 'deDE', 'Kampfmeister der Horde von Shattrath', 44908),
(2037, 'esES', 'Shattrath, maestros de batalla de la Horda', 44908),
(2037, 'esMX', 'Shattrath, maestros de batalla de la Horda', 44908),
(2037, 'frFR', 'Maîtres de guerre de la Horde de Shattrath', 44908),
(2037, 'itIT', 'Maestri di Guerra dell''Orda di Shattrath', 44908),
(2037, 'koKR', '샤트라스 호드 전투모병관', 44908),
(2037, 'ptBR', 'Mestres de Batalha de Shattrath, Horda', 44908),
(2037, 'ruRU', 'Военачальники Шаттрата (Орда)', 44908),
(2037, 'zhCN', '沙塔斯部落军官', 44908),
(2037, 'zhTW', '撒塔斯戰場軍官部落', 44908),
(2038, 'deDE', 'Alchemist von Shattrath', 44908),
(2038, 'esES', 'Shattrath, alquimista', 44908),
(2038, 'esMX', 'Shattrath, alquimista', 44908),
(2038, 'frFR', 'Alchimiste de Shattrath', 44908),
(2038, 'itIT', 'Alchimia di Shattrath', 44908),
(2038, 'koKR', '샤트라스 전문 연금술사', 44908),
(2038, 'ptBR', 'Alquimista de Shattrath', 44908),
(2038, 'ruRU', 'Шаттратский алхимик', 44908),
(2038, 'zhCN', '沙塔斯炼金师', 44908),
(2038, 'zhTW', '撒塔斯鍊金師', 44908),
(2039, 'deDE', 'Lederverarbeiter von Shattrath', 44908),
(2039, 'esES', 'Shattrath, peletero', 44908),
(2039, 'esMX', 'Shattrath, peletero', 44908),
(2039, 'frFR', 'Travailleur du cuir de Shattrath', 44908),
(2039, 'itIT', 'Conciatura di Shattrath', 44908),
(2039, 'koKR', '샤트라스 전문 가죽세공인', 44908),
(2039, 'ptBR', 'Coureiro de Shattrath', 44908),
(2039, 'ruRU', 'Шаттратский кожевник', 44908),
(2039, 'zhCN', '沙塔斯制皮师', 44908),
(2039, 'zhTW', '撒塔斯製皮師', 44908),
(2040, 'deDE', 'Kürschner von Shattrath', 44908),
(2040, 'esES', 'Shattrath, desollador', 44908),
(2040, 'esMX', 'Shattrath, desollador', 44908),
(2040, 'frFR', 'Dépeceur de Shattrath', 44908),
(2040, 'itIT', 'Scuoiatura di Shattrath', 44908),
(2040, 'koKR', '샤트라스 전문 무두장이', 44908),
(2040, 'ptBR', 'Esfolador de Shattrath', 44908),
(2040, 'ruRU', 'Шаттратский учитель снятия шкур', 44908),
(2040, 'zhCN', '沙塔斯剥皮师', 44908),
(2040, 'zhTW', '撒塔斯剝皮師', 44908),
(2041, 'deDE', 'Koch von Shattrath', 44908),
(2041, 'esES', 'Shattrath, cocinero', 44908),
(2041, 'esMX', 'Shattrath, cocinero', 44908),
(2041, 'frFR', 'Cuisinier de Shattrath', 44908),
(2041, 'itIT', 'Cucina di Shattrath', 44908),
(2041, 'koKR', '샤트라스 요리사', 44908),
(2041, 'ptBR', 'Cozinheiro de Shattrath', 44908),
(2041, 'ruRU', 'Повар Шаттрата', 44908),
(2041, 'zhCN', '沙塔斯厨师', 44908),
(2041, 'zhTW', '撒塔斯廚師', 44908),
(2042, 'deDE', 'Rüstungs- und Waffenmacher von Shattrath', 44908),
(2042, 'esES', 'Shattrath, artesano de armaduras/armas', 44908),
(2042, 'esMX', 'Shattrath, artesano de armaduras/armas', 44908),
(2042, 'frFR', 'Fabricant d''armes et armures de Shattrath', 44908),
(2042, 'itIT', 'Forgiatura di Shattrath', 44908),
(2042, 'koKR', '샤트라스 무기 및 방어구 제작자', 44908),
(2042, 'ptBR', 'Artesãos de Armaduras/Armas de Shattrath', 44908),
(2042, 'ruRU', 'Шаттрат: оружейник и бронник', 44908),
(2042, 'zhCN', '沙塔斯护甲/武器铸造师', 44908),
(2042, 'zhTW', '撒塔斯護甲/武器鑄造師', 44908),
(2043, 'deDE', 'Verzauberer von Shattrath', 44908),
(2043, 'esES', 'Shattrath, encantadores', 44908),
(2043, 'esMX', 'Shattrath, encantadores', 44908),
(2043, 'frFR', 'Enchanteurs de Shattrath', 44908),
(2043, 'itIT', 'Incantamento di Shattrath', 44908),
(2043, 'koKR', '샤트라스 전문 마법부여사', 44908),
(2043, 'ptBR', 'Encantadores de Shattrath', 44908),
(2043, 'ruRU', 'Шаттратские зачаровыватели', 44908),
(2043, 'zhCN', '沙塔斯附魔师', 44908),
(2043, 'zhTW', '撒塔斯附魔師', 44908),
(2044, 'deDE', 'Juwelierskunst von Shattrath', 44908),
(2044, 'esES', 'Shattrath, joyero', 44908),
(2044, 'esMX', 'Shattrath, joyero', 44908),
(2044, 'frFR', 'Joaillier de Shattrath', 44908),
(2044, 'itIT', 'Oreficeria di Shattrath', 44908),
(2044, 'koKR', '샤트라스 전문 보석세공인', 44908),
(2044, 'ptBR', 'Joalheiro de Shattrath', 44908),
(2044, 'ruRU', 'Шаттратский ювелир', 44908),
(2044, 'zhCN', '沙塔斯珠宝匠', 44908),
(2044, 'zhTW', '撒塔斯珠寶設計師', 44908),
(2045, 'deDE', 'Erste Hilfe von Shattrath', 44908),
(2045, 'esES', 'Shattrath, primeros auxilios', 44908),
(2045, 'esMX', 'Shattrath, primeros auxilios', 44908),
(2045, 'frFR', 'Secourisme de Shattrath', 44908),
(2045, 'itIT', 'Pronto Soccorso di Shattrath', 44908),
(2045, 'koKR', '샤트라스 응급치료사', 44908),
(2045, 'ptBR', 'Primeiros Socorros de Shattrath', 44908),
(2045, 'ruRU', 'Шаттрат: первая помощь', 44908),
(2045, 'zhCN', '沙塔斯急救师', 44908),
(2045, 'zhTW', '撒塔斯急救', 44908),
(2046, 'deDE', 'Gasthaus der Seher von Shattrath', 44908),
(2046, 'esES', 'Shattrath, posada del Arúspice', 44908),
(2046, 'esMX', 'Shattrath, posada del Arúspice', 44908),
(2046, 'frFR', 'Auberge des Clairvoyants de Shattrath', 44908),
(2046, 'itIT', 'Locanda dei Veggenti di Shattrath', 44908),
(2046, 'koKR', '샤트라스 점술가 길드 여관', 44908),
(2046, 'ptBR', 'Estalagem de Shattrath, Áugures', 44908),
(2046, 'ruRU', 'Таверна Шаттрата (Провидцы)', 44908),
(2046, 'zhCN', '沙塔斯旅店：占星者', 44908),
(2046, 'zhTW', '撒塔斯旅店占卜者', 44908),
(2047, 'deDE', 'Gasthaus der Aldor von Shattrath', 44908),
(2047, 'esES', 'Shattrath, posada Aldor', 44908),
(2047, 'esMX', 'Shattrath, posada Aldor', 44908),
(2047, 'frFR', 'Auberge de l''Aldor de Shattrath', 44908),
(2047, 'itIT', 'Locanda degli Aldor di Shattrath', 44908),
(2047, 'koKR', '샤트라스 알도르 사제회 여관', 44908),
(2047, 'ptBR', 'Estalagem de Shattrath, Aldor', 44908),
(2047, 'ruRU', 'Таверна Шаттрата (Алдор)', 44908),
(2047, 'zhCN', '沙塔斯旅店：奥尔多', 44908),
(2047, 'zhTW', '撒塔斯旅店奧多爾', 44908),
(2048, 'deDE', 'Stall der Seher von Shattrath', 44908),
(2048, 'esES', 'Shattrath, establo del Arúspice', 44908),
(2048, 'esMX', 'Shattrath, establo del Arúspice', 44908),
(2048, 'frFR', 'Écuries de Shattrath, Clairvoyants', 44908),
(2048, 'itIT', 'Scuderie dei Veggenti di Shattrath', 44908),
(2048, 'koKR', '샤트라스 점술가 길드 야수 관리인', 44908),
(2048, 'ptBR', 'Estábulo de Shattrath, Áugures', 44908),
(2048, 'ruRU', 'Шаттрат: стойла (Провидцы)', 44908),
(2048, 'zhCN', '沙塔斯兽栏：占星者', 44908),
(2048, 'zhTW', '撒塔斯獸欄占卜者', 44908),
(2049, 'deDE', 'Stall der Aldor von Shattrath', 44908),
(2049, 'esES', 'Shattrath, establo Aldor', 44908),
(2049, 'esMX', 'Shattrath, establo Aldor', 44908),
(2049, 'frFR', 'Écuries de Shattrath, Aldor', 44908),
(2049, 'itIT', 'Scuderie degli Aldor di Shattrath', 44908),
(2049, 'koKR', '샤트라스 알도르 사제회 야수 관리인', 44908),
(2049, 'ptBR', 'Estábulo de Shattrath, Aldor', 44908),
(2049, 'ruRU', 'Стойла Шаттрата (Алдор)', 44908),
(2049, 'zhCN', '沙塔斯兽栏：奥尔多', 44908),
(2049, 'zhTW', '撒塔斯獸欄奧多爾', 44908),
(2055, 'deDE', 'Alchemielabor von Shattrath', 44908),
(2055, 'esES', 'Laboratorio de Alquimia de Shattrath', 44908),
(2055, 'esMX', 'Laboratorio de Alquimia de Shattrath', 44908),
(2055, 'frFR', 'Laboratoire d''alchimie de Shattrath', 44908),
(2055, 'itIT', 'Laboratorio Alchemico di Shattrath', 44908),
(2055, 'koKR', '샤트라스 연금술 실험실', 44908),
(2055, 'ptBR', 'Laboratório de Alquimia de Shattrath', 44908),
(2055, 'ruRU', 'Шаттратская алхимическая лаборат', 44908), -- Шаттратская алхимическая лаборат� (truncated)
(2055, 'zhCN', '沙塔斯炼金房', 44908),
(2055, 'zhTW', '撒塔斯鍊金實驗室', 44908),
(2056, 'deDE', 'Edelsteinhändler der Seher', 44908),
(2056, 'esES', 'Vendedor de Gemas de los Arúspices', 44908),
(2056, 'esMX', 'Vendedor de Gemas de los Arúspices', 44908),
(2056, 'frFR', 'Vendeur de gemmes des Clairvoyants', 44908),
(2056, 'itIT', 'Venditore di Gemme dei Veggenti', 44908),
(2056, 'koKR', '샤트라스 점술가 길드 보석 상인', 44908),
(2056, 'ptBR', 'Comerciante de gemas dos Áugures', 44908),
(2056, 'ruRU', 'Торговец самоцветами (Провидцы)', 44908),
(2056, 'zhCN', '占星者宝石商人', 44908),
(2056, 'zhTW', '占卜者寶石商人', 44908),
(2057, 'deDE', 'Edelsteinhändler der Aldor', 44908),
(2057, 'esES', 'Vendedor de Gemas de los Aldor', 44908),
(2057, 'esMX', 'Vendedor de Gemas de los Aldor', 44908),
(2057, 'frFR', 'Vendeur de gemmes de l''Aldor', 44908),
(2057, 'itIT', 'Venditore di Gemme degli Aldor', 44908),
(2057, 'koKR', '샤트라스 알도르 사제회 보석 상인', 44908),
(2057, 'ptBR', 'Comerciante de gemas de Aldor', 44908),
(2057, 'ruRU', 'Торговец самоцветами (Алдор)', 44908),
(2057, 'zhCN', '奥尔多宝石商人', 44908),
(2057, 'zhTW', '奧多爾寶石商人', 44908),
(2095, 'deDE', 'Arenakampfmeister von Shattrath', 44908),
(2095, 'esES', 'Maestros de batalla de Shattrath', 44908),
(2095, 'esMX', 'Maestros de batalla de Shattrath', 44908),
(2095, 'frFR', 'Maîtres de guerre de l''arène de Shattrath', 44908),
(2095, 'itIT', 'Maestri d''Arena di Shattrath', 44908),
(2095, 'koKR', '샤트라스 투기장 사무관', 44908),
(2095, 'ptBR', 'Senhores de Batalha da Arena de Shattrath', 44908),
(2095, 'ruRU', 'Распорядитель Арены (Шаттрат)', 44908),
(2095, 'zhCN', '沙塔斯竞技场管理员', 44908),
(2095, 'zhTW', '撒塔斯競技場戰場軍官', 44908),
(2538, 'deDE', 'Archäologie von Shattrath', 44908),
(2538, 'esES', 'Arqueología de Shattrath', 44908),
(2538, 'esMX', 'Arqueología de Shattrath', 44908),
(2538, 'frFR', 'Archéologie de Shattrath', 44908),
(2538, 'itIT', 'Archeologia di Shattrath', 44908),
(2538, 'koKR', '샤트라스 고고학자', 44908),
(2538, 'ptBR', 'Arqueologia de Shattrath', 44908),
(2538, 'ruRU', 'Шаттрат: археология', 44908),
(2538, 'zhCN', '沙塔斯考古学训练师', 44908),
(2538, 'zhTW', '撒塔斯城考古學', 44908),
(2645, 'deDE', 'Gildendienste von Shattrath', 44908),
(2645, 'esES', 'Servicios de hermandad de Shattrath', 44908),
(2645, 'esMX', 'Servicios de hermandad de Shattrath', 44908),
(2645, 'frFR', 'Services de guilde de Shattrath', 44908),
(2645, 'itIT', 'Mastro di Gilda di Shattrath', 44908),
(2645, 'koKR', '샤트라스 길드 서비스', 44908),
(2645, 'ptBR', 'Serviços de Guilda de Shattrath', 44908),
(2645, 'ruRU', 'Регистратор гильдий Шаттрата', 44908),
(2645, 'zhCN', '沙塔斯公会服务', 44908),
(2645, 'zhTW', '撒塔斯公會服務', 44908),
(2646, 'deDE', 'Stadtmitte von Shattrath', 44908),
(2646, 'esES', 'Centro de la Ciudad de Shattrath', 44908),
(2646, 'esMX', 'Centro de la Ciudad de Shattrath', 44908),
(2646, 'frFR', 'Centre de Shattrath', 44908),
(2646, 'itIT', 'Centro Cittadino di Shattrath', 44908),
(2646, 'koKR', '샤트라스 도시 중심', 44908),
(2646, 'ptBR', 'Centro da Cidade de Shattrath', 44908),
(2646, 'ruRU', 'Центр Шаттрата', 44908),
(2646, 'zhCN', '沙塔斯城市中心', 44908),
(2646, 'zhTW', '撒塔斯城中心', 44908),
(2698, 'deDE', 'Bibliothek der Seher', 44908),
(2698, 'esES', 'La Biblioteca del Profeta', 44908),
(2698, 'esMX', 'La Biblioteca del Profeta', 44908),
(2698, 'frFR', 'La bibliothèque du Voyant', 44908),
(2698, 'itIT', 'Biblioteca dei Veggenti', 44908),
(2698, 'koKR', '현자의 도서관', 44908),
(2698, 'ptBR', 'A Biblioteca do Vidente', 44908),
(2698, 'ruRU', 'Библиотека Провидца', 44908),
(2698, 'zhCN', '先知的图书馆', 44908),
(2698, 'zhTW', '先知書庫', 44908),
(2699, 'deDE', 'Inschriftenkundelehrer der Aldor', 44908),
(2699, 'esES', 'Instructor de inscripción de los Aldor', 44908),
(2699, 'esMX', 'Instructor de inscripción de los Aldor', 44908),
(2699, 'frFR', 'Maître des calligraphes de l''Aldor', 44908),
(2699, 'itIT', 'Runografia degli Aldor', 44908),
(2699, 'koKR', '알도르 사제회 전문 주문각인사', 44908),
(2699, 'ptBR', 'Treinamento de Escrivania dos Aldor', 44908),
(2699, 'ruRU', 'Учитель начертания Алдоров', 44908),
(2699, 'zhCN', '奥尔多铭文训练师', 44908),
(2699, 'zhTW', '奧多爾銘文學訓練師', 44908),
(2700, 'deDE', 'Ingenieurskunstlehrer der Aldor', 44908),
(2700, 'esES', 'Instructor de ingeniería de los Aldor', 44908),
(2700, 'esMX', 'Instructor de ingeniería de los Aldor', 44908),
(2700, 'frFR', 'Maître des ingénieurs de l''Aldor', 44908),
(2700, 'itIT', 'Ingegneria degli Aldor', 44908),
(2700, 'koKR', '알도르 사제회 전문 기계공학자', 44908),
(2700, 'ptBR', 'Treinamento de Engenharia dos Aldor', 44908),
(2700, 'ruRU', 'Учитель инженерного дела Алдоров', 44908),
(2700, 'zhCN', '奥尔多工程学训练师', 44908),
(2700, 'zhTW', '奧多爾工程學訓練師', 44908),
(2701, 'deDE', 'Kräuterkundelehrer der Aldor', 44908),
(2701, 'esES', 'Instructor de herboristería de los Aldor', 44908),
(2701, 'esMX', 'Instructor de herboristería de los Aldor', 44908),
(2701, 'frFR', 'Maître des herboristes de l''Aldor', 44908),
(2701, 'itIT', 'Erbalismo degli Aldor', 44908),
(2701, 'koKR', '알도르 사제회 전문 약초채집사', 44908),
(2701, 'ptBR', 'Treinamento de Herborismo dos Aldor', 44908),
(2701, 'ruRU', 'Учитель травничества Алдоров', 44908),
(2701, 'zhCN', '奥尔多草药学训练师', 44908),
(2701, 'zhTW', '奧多爾草藥學訓練師', 44908),
(2702, 'deDE', 'Bergbaulehrer der Aldor', 44908),
(2702, 'esES', 'Instructor de minería de los Aldor', 44908),
(2702, 'esMX', 'Instructor de minería de los Aldor', 44908),
(2702, 'frFR', 'Maître des mineurs de l''Aldor', 44908),
(2702, 'itIT', 'Estrazione degli Aldor', 44908),
(2702, 'koKR', '알도르 사제회 전문 광부', 44908),
(2702, 'ptBR', 'Treinamento de Mineração dos Aldor', 44908),
(2702, 'ruRU', 'Учитель горного дела Алдоров', 44908),
(2702, 'zhCN', '奥尔多采矿训练师', 44908),
(2702, 'zhTW', '奧多爾採礦訓練師', 44908),
(2703, 'deDE', 'Schneiderlehrer der Aldor', 44908),
(2703, 'esES', 'Instructor de sastrería de los Aldor', 44908),
(2703, 'esMX', 'Instructor de sastrería de los Aldor', 44908),
(2703, 'frFR', 'Maître des couturiers de l''Aldor', 44908),
(2703, 'itIT', 'Sartoria degli Aldor', 44908),
(2703, 'koKR', '알도르 사제회 전문 재봉사', 44908),
(2703, 'ptBR', 'Treinamento de Alfaiataria dos Aldor', 44908),
(2703, 'ruRU', 'Учитель портняжного дела Алдоров', 44908),
(2703, 'zhCN', '奥尔多裁缝训练师', 44908),
(2703, 'zhTW', '奧多爾裁縫訓練師', 44908),
(2917, 'deDE', 'Verzauberkunstlehrer der Aldor', 44908),
(2917, 'esES', 'Instructor de encantamiento de los Aldor', 44908),
(2917, 'esMX', 'Instructor de encantamiento de los Aldor', 44908),
(2917, 'frFR', 'Maître des enchanteurs de l''Aldor', 44908),
(2917, 'itIT', 'Incantamento degli Aldor', 44908),
(2917, 'koKR', '알도르 사제회 전문 마법부여사', 44908),
(2917, 'ptBR', 'Treinamento de Encantamentos Aldor', 44908),
(2917, 'ruRU', 'Учитель наложения чар Алдоров', 44908),
(2917, 'zhCN', '奥尔多附魔训练师', 44908),
(2917, 'zhTW', '奧多爾附魔訓練師', 44908),
(2918, 'deDE', 'Juwelierskunstlehrer der Aldor', 44908),
(2918, 'esES', 'Instructor de joyería de los Aldor', 44908),
(2918, 'esMX', 'Instructor de joyería de los Aldor', 44908),
(2918, 'frFR', 'Maître des joailliers de l''Aldor', 44908),
(2918, 'itIT', 'Oreficeria degli Aldor', 44908),
(2918, 'koKR', '알도르 사제회 전문 보석세공인', 44908),
(2918, 'ptBR', 'Treinamento de Joalheria Aldor', 44908),
(2918, 'ruRU', 'Учитель ювелирного дела Алдоров', 44908),
(2918, 'zhCN', '奥尔多珠宝加工训练师', 44908),
(2918, 'zhTW', '奧多爾珠寶設計訓練師', 44908),
(2923, 'deDE', 'Der alte Barlo', 44908),
(2923, 'esES', 'Viejo Barlo', 44908),
(2923, 'esMX', 'Viejo Barlo', 44908),
(2923, 'frFR', 'Vieux Barlo', 44908),
(2923, 'itIT', 'Vecchio Barlo', 44908),
(2923, 'koKR', '노인 발로', 44908),
(2923, 'ptBR', 'Velho Barlo', 44908),
(2923, 'ruRU', 'Старина Барло', 44908),
(2923, 'zhCN', '老渔夫巴尔洛', 44908),
(2923, 'zhTW', '老人巴洛', 44908);
