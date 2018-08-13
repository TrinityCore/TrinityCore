-- fix the falling down from sky mobs
UPDATE creature_template SET inhabittype=4 WHERE entry IN (97018,91048,97020,108187,73828,111898,90480,49842,106648,108552,97126,97722,108060,98356,95718,99862,94986,112905 ,106609,34527,109138,98143,103841,98042,98090,100411,91122,92388,38821,109809,112010,111433,98006,109682,103079,97735,101677,35845,23837,96287,90558
,107455,108927,99223);
-- remove wrong aura and flags  the mobs was line down but moves in the same time
UPDATE `creature_template_addon` SET `auras`='' WHERE (`entry`='110043');
UPDATE `creature_template` SET `unit_flags`='0', `InhabitType`='1' WHERE (`entry`='110042');
UPDATE `creature_template` SET `unit_flags`='0' WHERE (`entry`='110043');
DELETE FROM creature_addon WHERE guid IN (20516821,20516809,20516798,20516705,20516676,20516675,20516636,20516633,20516628,20516623,20516620,20516613,20516610,20516601,20516596,20516594,20516589,20516236,20516232,20516211,20516209,20516208,20516191,20516187,20516162,20516152,20516144,20516056,20516822,20516810,20516807,20516800,20516704,20516684,20516680,20516677,20516674,20516626,20516625,20516619,20516618,20516614,20516611,20516607,20516604,20516592,20516587,20516586,20516510,20516252,20516235,20516234,20516233,20516214,20516207,20516206,20516197,20516193,20516179,20516171,20516167,20516161,20516160,20516157,20516156,20516155,20516153,20516148,20516031,20516012,20516002);
DELETE FROM creature_template_addon WHERE entry IN (110042,110043);
UPDATE `creature_template` SET `unit_flags2`='2048' WHERE entry IN (110042,110043);
-- fix loot of the chest
DELETE FROM gameobject_loot_template WHERE entry='251792';
UPDATE `gameobject_template` SET `Data1`='251792' WHERE (`entry`='251792');

INSERT INTO gameobject_loot_template (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES 
('251792', '121374', '1.16', '1', '0', '1', '1'),
('251792', '121376', '1.39', '1', '0', '1', '1'),
('251792', '121377', '1.15', '1', '0', '1', '1'),
('251792', '121378', '1.13', '1', '0', '1', '1'),
('251792', '121380', '1.18', '1', '0', '1', '1'),
('251792', '121384', '1.31', '1', '0', '1', '1'),
('251792', '121385', '1.27', '1', '0', '1', '1'),
('251792', '121386', '1.31', '1', '0', '1', '1'),
('251792', '121387', '1.39', '1', '0', '1', '1'),
('251792', '121389', '1.37', '1', '0', '1', '1'),
('251792', '121390', '1.98', '1', '0', '1', '1'),
('251792', '121391', '1.21', '1', '0', '1', '1'),
('251792', '121392', '2.26', '1', '0', '1', '1'),
('251792', '121393', '1.27', '1', '0', '1', '1'),
('251792', '121394', '1.32', '1', '0', '1', '1'),
('251792', '121395', '1.96', '1', '0', '1', '1'),
('251792', '121397', '1.2', '1', '0', '1', '1'),
('251792', '121398', '1.21', '1', '0', '1', '1'),
('251792', '121399', '1.22', '1', '0', '1', '1'),
('251792', '121400', '1.44', '1', '0', '1', '1'),
('251792', '121401', '1.37', '1', '0', '1', '1'),
('251792', '121402', '1.4', '1', '0', '1', '1'),
('251792', '121403', '1.27', '1', '0', '1', '1'),
('251792', '121404', '1.22', '1', '0', '1', '1'),
('251792', '121405', '1.62', '1', '0', '1', '1'),
('251792', '121406', '1.71', '1', '0', '1', '1'),
('251792', '121407', '1.52', '1', '0', '1', '1'),
('251792', '121408', '1.57', '1', '0', '1', '1'),
('251792', '121409', '1.23', '1', '0', '1', '1'),
('251792', '121410', '1.64', '1', '0', '1', '1'),
('251792', '121411', '1.29', '1', '0', '1', '1'),
('251792', '121412', '1.33', '1', '0', '1', '1'),
('251792', '121413', '1.31', '1', '0', '1', '1'),
('251792', '121414', '1.42', '1', '0', '1', '1'),
('251792', '121415', '1.98', '1', '0', '1', '1'),
('251792', '138242', '5.42', '1', '0', '1', '1'),
('251792', '138243', '3.57', '1', '0', '1', '1'),
('251792', '138244', '3.29', '1', '0', '1', '10'),
('251792', '138245', '1.94', '1', '0', '1', '5'),
('251792', '138246', '5.02', '1', '0', '1', '3'),
('251792', '138247', '3.69', '1', '0', '1', '1'),
('251792', '138248', '4.69', '1', '0', '1', '1'),
('251792', '138249', '7.27', '1', '0', '1', '1'),
('251792', '138250', '4.14', '1', '0', '1', '2'),
('251792', '138251', '3.97', '1', '0', '1', '5'),
('251792', '138307', '3.3', '1', '0', '1', '5'),
('251792', '138783', '2.33', '1', '0', '1', '1'),
('251792', '138885', '2.77', '1', '0', '1', '1'),
('251792', '140310', '1.47', '1', '0', '1', '1');

-- fix the loot of the chest
DELETE FROM gameobject_loot_template WHERE entry='257291';
UPDATE `gameobject_template` SET `Data1`='257291' WHERE (`entry`='257291');

INSERT INTO gameobject_loot_template (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES 
('257291', '121374', '1.27', '1', '0', '1', '1'),
('257291', '121375', '1.27', '1', '0', '1', '1'),
('257291', '121376', '1.54', '1', '0', '1', '1'),
('257291', '121377', '1.54', '1', '0', '1', '1'),
('257291', '121378', '1.36', '1', '0', '1', '1'),
('257291', '121379', '1.2', '1', '0', '1', '1'),
('257291', '121380', '1.52', '1', '0', '1', '1'),
('257291', '121382', '1.33', '1', '0', '1', '1'),
('257291', '121383', '1.32', '1', '0', '1', '1'),
('257291', '121384', '1.37', '1', '0', '1', '1'),
('257291', '121385', '1.52', '1', '0', '1', '1'),
('257291', '121386', '1.62', '1', '0', '1', '1'),
('257291', '121387', '1.65', '1', '0', '1', '1'),
('257291', '121388', '1.48', '1', '0', '1', '1'),
('257291', '121389', '2.02', '1', '0', '1', '1'),
('257291', '121390', '1.61', '1', '0', '1', '1'),
('257291', '121391', '1.14', '1', '0', '1', '1'),
('257291', '121392', '1.37', '1', '0', '1', '1'),
('257291', '121393', '1.4', '1', '0', '1', '1'),
('257291', '121394', '1.61', '1', '0', '1', '1'),
('257291', '121395', '1.51', '1', '0', '1', '1'),
('257291', '121396', '1.77', '1', '0', '1', '1'),
('257291', '121397', '1.85', '1', '0', '1', '1'),
('257291', '121398', '1.6', '1', '0', '1', '1'),
('257291', '121399', '1.5', '1', '0', '1', '1'),
('257291', '121400', '1.72', '1', '0', '1', '1'),
('257291', '121401', '1.59', '1', '0', '1', '1'),
('257291', '121402', '1.47', '1', '0', '1', '1'),
('257291', '121403', '1.46', '1', '0', '1', '1'),
('257291', '121404', '1.02', '1', '0', '1', '1'),
('257291', '121405', '2.7', '1', '0', '1', '1'),
('257291', '121406', '1.6', '1', '0', '1', '1'),
('257291', '121407', '1.63', '1', '0', '1', '1'),
('257291', '121408', '1.85', '1', '0', '1', '1'),
('257291', '121409', '1.37', '1', '0', '1', '1'),
('257291', '121410', '1.81', '1', '0', '1', '1'),
('257291', '121411', '1.63', '1', '0', '1', '1'),
('257291', '121412', '1.33', '1', '0', '1', '1'),
('257291', '121413', '1.4', '1', '0', '1', '1'),
('257291', '121414', '1.44', '1', '0', '1', '1'),
('257291', '121415', '1.57', '1', '0', '1', '1'),
('257291', '138242', '5.37', '1', '0', '1', '1'),
('257291', '138243', '5.43', '1', '0', '1', '1'),
('257291', '138244', '5.26', '1', '0', '1', '10'),
('257291', '138245', '6.15', '1', '0', '1', '5'),
('257291', '138246', '5.63', '1', '0', '1', '3'),
('257291', '138247', '4.91', '1', '0', '1', '1'),
('257291', '138248', '7.29', '1', '0', '1', '1'),
('257291', '138249', '6.46', '1', '0', '1', '1'),
('257291', '138250', '5.79', '1', '0', '1', '2'),
('257291', '138251', '4.07', '1', '0', '1', '5'),
('257291', '138307', '1.17', '1', '0', '1', '5'),
('257291', '139792', '1.89', '1', '0', '1', '1'),
('257291', '139795', '1.77', '1', '0', '1', '1'),
('257291', '139801', '1.15', '1', '0', '1', '1'),
('257291', '139813', '1.53', '1', '0', '1', '1'),
('257291', '139814', '1.13', '1', '0', '1', '1'),
('257291', '139816', '1.32', '1', '0', '1', '1'),
('257291', '140581', '1.22', '1', '0', '1', '1'),
('257291', '140582', '1.16', '1', '0', '1', '1'),
('257291', '141888', '1.96', '1', '0', '1', '1');
-- fix the loot for mob
UPDATE creature_template SET lootid='108521' WHERE entry='108521';
-- fix the faction for some mobs
UPDATE `creature_template` SET `faction`='16' WHERE entry IN (95935,94688,94691,101077,93237,96268);
UPDATE `creature_template` SET `faction`='2786' WHERE entry IN (99386);
-- fix mob  loot
DELETE FROM creature_loot_template WHERE entry='95937';
UPDATE creature_template SET lootid='95937' WHERE entry='95937';
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121056, 1.26, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121057, 2.33, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121058, 1.15, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121059, 1.23, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121060, 1.19, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121061, 1.13, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121062, 1.16, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121067, 1.59, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121069, 1.13, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121070, 1.51, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121071, 1.05, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121072, 1.22, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121073, 1.3, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121074, 1.18, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121075, 1.48, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121076, 1.17, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121077, 1.16, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121078, 1.27, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121079, 1.11, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121082, 1.25, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121083, 1.63, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121095, 1.17, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121096, 1.16, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121097, 1.21, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121098, 1.17, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121099, 1.24, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121100, 1.11, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121101, 1.3, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121102, 1.18, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121103, 1.32, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121104, 1.31, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121105, 1.14, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121106, 1.14, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121107, 1.21, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121108, 1.31, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121109, 2.04, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121110, 1.59, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121331, 1.17, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121332, 1.36, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121333, 1.23, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121334, 7.48, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121335, 2.51, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121336, 1.2, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121337, 1.33, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121338, 1.73, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121339, 1.22, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121340, 1.27, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121341, 1.38, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121342, 1.37, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121343, 8.03, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121344, 1.49, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121345, 1.27, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121346, 1.18, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121348, 1.32, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121349, 1.36, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121350, 1.64, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121351, 1.2, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121352, 1.43, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121353, 1.28, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121354, 1.28, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121356, 1.38, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121357, 1.58, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121358, 1.24, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121359, 1.45, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121360, 1.59, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121361, 1.51, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121362, 1.36, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121363, 1.25, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121364, 1.27, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121365, 1.33, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121366, 1.32, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121367, 1.35, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121368, 1.64, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121369, 1.4, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121370, 1.71, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121371, 1.18, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121372, 1.39, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121373, 3.38, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121374, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121375, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121376, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121378, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121379, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121380, 1.02, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121381, 1.02, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121383, 1.02, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121384, 1.02, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121385, 1.02, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121386, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121387, 1.04, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121388, 1.02, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121389, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121393, 1.08, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121394, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121395, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121397, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121398, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121400, 1.04, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121401, 1.02, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121402, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121403, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121404, 1.02, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121406, 1.05, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121407, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121409, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121410, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121411, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121412, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121413, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 121414, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 124117, 1.52, 1, 0, 1, 2);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 124119, 1.93, 1, 0, 1, 2);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 124437, 3.24, 1, 0, 1, 3);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 124438, 1.15, 1, 0, 1, 4);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 124439, 1.25, 1, 0, 1, 4);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 128436, 1.41, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 132185, 1.05, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 132186, 1.46, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 132231, 1.81, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 132237, 1.89, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 138781, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 138782, 1.08, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 139523, 1.77, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 139524, 1.02, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 139525, 1.03, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 140220, 1.17, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 140221, 1.17, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 140222, 1.19, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 140224, 1.04, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 140225, 1.05, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 140226, 1.21, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 140227, 1.63, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 141288, 7.84, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 141289, 1.25, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 141574, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 141578, 1, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 142119, 1.01, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 143845, 1.92, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 144330, 1.02, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 144345, 1.05, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 153202, 1.04, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Chance`, `lootmode`, `groupid`, `mincount`, `maxcount`) VALUES (95937, 153248, 1.08, 1, 0, 1, 1);
-- fix gold exploit from repetable quest reward item who can be sell
UPDATE `quest_template_addon` SET `SpecialFlags`='0' WHERE id IN (7662,7663);
