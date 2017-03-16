-- Fix Orgrimmar Guard Gossip 434
DELETE FROM `gossip_menu_option` WHERE `menu_id`=1951;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1951,0,0,'|cFF0008E8NEW|r: Reforging',0,1,1,0,0,0,0,'',0,0),
(1951,1,0,'|cFF0008E8NEW|r: Transmogrification',0,1,1,12246,458,0,0,'',0,0),
(1951,2,0,'|cFF0008E8NEW|r: Void Storage',0,1,1,12246,458,0,0,'',0,0),
(1951,3,0,'Auction House',5316,1,1,12639,0,0,0,'',0,0),
(1951,4,0,'Bank',3426,1,1,12638,0,0,0,'',0,0),
(1951,5,0,'Barber',31340,1,1,10018,188,0,0,'',0,0),
(1951,6,0,'Battlemasters',15232,1,1,8224,459,0,0,'',0,0),
(1951,7,0,'Class Trainer',45378,1,1,1949,0,0,0,'',0,0),
(1951,8,0,'Flight Master',4889,1,1,1902,507,0,0,'',0,0),
(1951,9,0,'Guild Master & Vendor',45380,1,1,1903,178,0,0,'',0,0),
(1951,10,0,'Inn',44629,1,1,12637,0,0,0,'',0,0),
(1951,11,0,'Officer''s Lounge',9749,1,1,5882,509,0,0,'',0,0),
(1951,12,0,'Portals',47507,1,1,12245,510,0,0,'',0,0),
(1951,13,0,'Profession Trainer',45382,1,1,1942,0,0,0,'',0,0),
(1951,14,0,'Stable Master',45383,1,1,4902,511,0,0,'',0,0),
(1951,15,0,'Zeppelin Master',5518,1,1,9727,0,0,0,'',0,0);

-- Auction House Gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id`=12639;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(12639,0,0,'The Valley of Strength',50627,1,1,2403,181,0,0,'',0,0),
(12639,1,0,'The Valley of Honor',50628,1,1,12628,504,0,0,'',0,0);

-- Bank Gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id`=12638;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(12638,0,0,'The Valley of Strength',50627,1,1,1901,505,0,0,'',0,0),
(12638,1,0,'The Valley of Honor',50628,1,1,12627,506,0,0,'',0,0);

-- Inn Gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id`=12637;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(12637,0,0,'The Valley of Strength',50627,1,1,1904,179,0,0,'',0,0),
(12637,1,0,'The Valley of Honor',50628,1,1,12626,508,0,0,'',0,0);

-- Zeppelin Gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9727;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(9727,0,0,'Eastern Zeppelin Tower',28607,1,1,2481,182,0,0,'',0,0),
(9727,1,0,'Western Zeppelin Tower',28608,1,1,9726,183,0,0,'',0,0);

-- Class Trainer Gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id`=1949;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1949,0,0,'Druid',45409,1,1,12654,518,0,0,'',0,0),
(1949,1,0,'Hunter',45403,1,1,1906,512,0,0,'',0,0),
(1949,2,0,'Mage',45404,1,1,12309,513,0,0,'',0,0),
(1949,3,0,'Paladin',48028,1,1,8644,514,0,0,'',0,0),
(1949,4,0,'Priest',45405,1,1,1908,515,0,0,'',0,0),
(1949,5,0,'Shaman',45410,1,1,1909,516,0,0,'',0,0),
(1949,6,0,'Rogue',45406,1,1,1910,304,0,0,'',0,0),
(1949,7,0,'Warlock',15244,1,1,1911,305,0,0,'',0,0),
(1949,8,0,'Warrior',45408,1,1,1912,517,0,0,'',0,0);

-- Profession Trainer Gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id`=1942;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1942,0,0,'Alchemy',52058,1,1,1845,519,0,0,'',0,0),
(1942,1,0,'Archaeology',44649,1,1,12308,520,0,0,'',0,0),
(1942,2,0,'Blacksmithing',45754,1,1,1846,308,0,0,'',0,0),
(1942,3,0,'Cooking',45763,1,1,1861,521,0,0,'',0,0),
(1942,4,0,'Enchanting',45755,1,1,1862,522,0,0,'',0,0),
(1942,5,0,'Engineering',45756,1,1,1981,523,0,0,'',0,0),
(1942,6,0,'First Aid',45765,1,1,1863,312,0,0,'',0,0),
(1942,7,0,'Fishing',45767,1,1,1864,524,0,0,'',0,0),
(1942,8,0,'Flying',44664,1,1,12654,525,0,0,'',0,0),
(1942,9,0,'Herbalism',45768,1,1,1865,526,0,0,'',0,0),
(1942,10,0,'Inscription',45757,1,1,10017,527,0,0,'',0,0),
(1942,11,0,'Jewelcrafting',45758,1,1,12654,528,0,0,'',0,0),
(1942,12,0,'Leatherworking',45759,1,1,1866,529,0,0,'',0,0),
(1942,13,0,'Mining',45769,1,1,1868,530,0,0,'',0,0),
(1942,14,0,'Riding',44663,1,1,12654,531,0,0,'',0,0),
(1942,15,0,'Skinning',45770,1,1,1869,529,0,0,'',0,0),
(1942,16,0,'Tailoring',45760,1,1,1871,532,0,0,'',0,0);

-- Point of Interest updates and additions
UPDATE `points_of_interest` SET `PositionX`=1572.304,`PositionY`=-4436.325 WHERE `ID`=179;
UPDATE `points_of_interest` SET `PositionX`=1617.56,`PositionY`=-4425.31 WHERE `ID`=181;
UPDATE `points_of_interest` SET `PositionX`=1843.63,`PositionY`=-4394.62 WHERE `ID`=182;
UPDATE `points_of_interest` SET `PositionX`=1738.83,`PositionY`=-4280.79 WHERE `ID`=183;
UPDATE `points_of_interest` SET `PositionX`=1782.49,`PositionY`=-4212.75 WHERE `ID`=188;
UPDATE `points_of_interest` SET `PositionX`=2077.391,`PositionY`=-4807.912 WHERE `ID`=308;
UPDATE `points_of_interest` SET `PositionX`=1472.905,`PositionY`=-4148.616 WHERE `ID`=312;

DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 504 AND 532;
INSERT INTO `points_of_interest` (`ID`,`PositionX`,`PositionY`,`Icon`,`Flags`,`Data`,`Name`,`VerifiedBuild`) VALUES
(504,2041.32,-4674.58,7,99,0, 'Orgrimmar Auction House',23420),
(505,1537.41,-4364.21,7,99,0, 'Orgrimmar Bank',23420),
(506,1898.15,-4683.27,7,99,0, 'Orgrimmar Bank',23420),
(507,1800.22,-4369.74,7,99,0, 'Orgrimmar Flight Master',23420),
(508,1918.094,-4730.686,7,99,0, 'Orgrimmar Inn',23420),
(509,1650.37,-4225.17,7,99,0, 'Orgrimmar Hall of Legends',23420),
(510,2047.94,-4377.4,7,99,0, 'Orgrimmar Portals',23420),
(511,2077.635,-4587.134,7,99,0, 'Orgrimmar Stable Master',23420),
(512,2109.26,-4630.1,7,99,0, 'Orgrimmar Hunter Trainer',23420),
(513,1767.12,-4343.18,7,99,0, 'Orgrimmar Mage Trainer',23420),
(514,1863.972,-4292.818,7,99,0, 'Orgrimmar Paladin Trainer',23420),
(515,1664.37,-4361.8,7,99,0, 'Orgrimmar Priest Trainer',23420),
(516,1884.111,-4282.452,7,99,0, 'Orgrimmar Shaman Trainer',23420),
(517,1962.52,-4766.58,7,99,0, 'Orgrimmar Warrior Trainer',23420),
(518,1888.885,-4285.238,7,99,0, 'Orgrimmar Druid Trainer',23420),
(519,1946.59,-4472.42,7,99,0, 'Orgrimmar Alchemy',23420),
(520,1668.48,-4359.67,7,99,0, 'Orgrimmar Archaeology',23420),
(521,1773.28,-4493.09,7,99,0, 'Orgrimmar Cooking',23420),
(522,1926.54,-4430.92,7,99,0, 'Orgrimmar Enchanting',23420),
(523,1833.67,-4497.54,7,99,0, 'Orgrimmar Engineering',23420),
(524,2000.15,-4664.54,7,99,0, 'Orgrimmar Fishing',23420),
(525,1799.538,-4357.022,7,99,0, 'Orgrimmar Flying Trainer',23420),
(526,1896.35,-4450.83,7,99,0, 'Orgrimmar Herbalism',23420),
(527,1842.33,-4477.9,7,99,0, 'Orgrimmar Inscription',23420),
(528,2088.818,-4767.181,7,99,0, 'Orgrimmar Jewelcrafting',23420),
(529,1848,-4555.32,7,99,0, 'Orgrimmar Leatherworking',23420),
(530,2081.972,-4764.094,7,99,0, 'Orgrimmar Mining',23420),
(531,2085.344,-4572.828,7,99,0, 'Orgrimmar Riding Trainer',23420),
(532,1803.03,-4547.34,7,99,0, 'Orgrimmar Tailoring',23420);
