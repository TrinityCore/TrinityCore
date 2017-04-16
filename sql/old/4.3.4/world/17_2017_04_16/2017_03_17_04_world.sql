-- Darnassus Guard Gossip 434
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (2352,2351,2343);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2352,0,0, 'Auction House',0,1,1,3101,89,0,0, '',0,23420),
(2352,1,0, 'The Bank',0,1,1,2322,90,0,0, '',0,23420),
(2352,2,0, 'Hippogryph Master',0,1,1,12654,91,0,0, '',0,23420),
(2352,3,0, 'Guild Master & Vendor',0,1,1,2324,92,0,0, '',0,23420),
(2352,4,0, 'The Inn',0,1,1,2325,93,0,0, '',0,23420),
(2352,5,0, 'Mailbox',0,1,1,2326,94,0,0, '',0,23420),
(2352,6,0, 'Stable Master',0,1,1,4921,95,0,0, '',0,23420),
(2352,7,0, 'Battlemaster',0,1,1,8221,571,0,0, '',0,23420),
(2352,8,0, 'Class Trainer',0,1,1,2343,0,0,0, '',0,23420),
(2352,9,0, 'Profession Trainer',0,1,1,2351,0,0,0, '',0,23420),
(2351,0,0, 'Alchemy',0,1,1,2344,102,0,0, '',0,23420),
(2351,1,0, 'Archaeology',0,1,1,12323,572,0,0, '',0,23420),
(2351,2,0, 'Blacksmithing',0,1,1,12778,462,0,0, '',0,23420),
(2351,3,0, 'Cooking',0,1,1,2345,103,0,0, '',0,23420),
(2351,4,0, 'Enchanting',0,1,1,2347,104,0,0, '',0,23420),
(2351,5,0, 'Engineering',0,1,1,12777,573,0,0, '',0,23420),
(2351,6,0, 'First Aid',0,1,1,2348,105,0,0, '',0,23420),
(2351,7,0, 'Fishing',0,1,1,2349,106,0,0, '',0,23420),
(2351,8,0, 'Herbalism',0,1,1,2350,268,0,0, '',0,23420),
(2351,9,0, 'Inscription',0,1,1,10015,107,0,0, '',0,23420),
(2351,10,0, 'Jewelcrafting',0,1,1,12779,574,0,0, '',0,23420),
(2351,11,0, 'Leatherworking',0,1,1,2354,108,0,0, '',0,23420),
(2351,12,0, 'Mining',0,1,1,12776,575,0,0, '',0,23420),
(2351,13,0, 'Skinning',0,1,1,2356,109,0,0, '',0,23420),
(2351,14,0, 'Tailoring',0,1,1,2358,110,0,0, '',0,23420),
(2343,0,0, 'Druid',0,1,1,2328,98,0,0, '',0,23420),
(2343,1,0, 'Hunter',0,1,1,2327,99,0,0, '',0,23420),
(2343,2,0, 'Mage',0,1,1,12700,265,0,0, '',0,23420),
(2343,3,0, 'Paladin',0,1,1,11422,266,0,0, '',0,23420),
(2343,4,0, 'Priest',0,1,1,2329,267,0,0, '',0,23420),
(2343,5,0, 'Rogue',0,1,1,2341,100,0,0, '',0,23420),
(2343,6,0, 'Shaman',0,1,1,11422,576,0,0, '',0,23420),
(2343,7,0, 'Warlock',0,1,1,12704,577,0,0, '',0,23420),
(2343,8,0, 'Warrior',0,1,1,2342,101,0,0, '',0,23420);

-- Darnassus Points of Interest Update 434
DELETE FROM `points_of_interest` WHERE `ID` IN (91,265,266,268);
DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 102 AND 106;
DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 108 AND 110;
DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 571 AND 577;
INSERT INTO `points_of_interest` (`ID`,`PositionX`,`PositionY`,`Icon`,`Flags`,`Data`,`Name`,`VerifiedBuild`) VALUES
(91,9972.819,2623.863,7,99,0, 'Darnassus Hippogryph Master',23420),
(265,9638.622,2607.958,7,99,0, 'Darnassus Mage Trainer',23420),
(266,9657.61,2513.117,7,99,0, 'Darnassus Paladin Trainer',23420),
(268,9757.18,2430.17,7,99,0, 'Darnassus Herbalism',23420),
(102,10075.9,2356.76,7,99,0, 'Darnassus Alchemy',23420),
(103,10088.6,2419.22,7,99,0, 'Darnassus Cooking',23420),
(104,10146.1,2313.43,7,99,0, 'Darnassus Enchanting',23420),
(105,10150.1,2390.44,7,99,0, 'Darnassus First Aid',23420),
(106,9836.21,2432.18,7,99,0, 'Darnassus Fishing',23420),
(108,10086.6,2255.77,7,99,0, 'Darnassus Leatherworking',23420),
(109,10081.4,2257.19,7,99,0, 'Darnassus Skinning',23420),
(110,10079.7,2268.2,7,99,0, 'Darnassus Tailoring',23420),
(571,9982.61,2319.79,7,99,0, 'Darnassus Battlemasters',23420),
(572,9608.43,2531.16,7,99,0, 'Darnassus Archaeology',23420),
(573,10127.96,2422.82,7,99,0, 'Darnassus Engineering',23420),
(574,10147.66,2353.578,7,99,0, 'Darnassus Jewelcrafting',23420),
(575,10124.69,2415.28,7,99,0, 'Darnassus Mining',23420),
(576,9654.393,2510.8,7,99,0, 'Darnassus Shaman Trainer',23420),
(577,10300.74,2418.637,7,99,0, 'Darnassus Warlock Trainer',23420);

-- Teldrassil Guard Gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (3580,3564);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3580,0,0, 'The Bank',0,1,1,3560,0,0,0, '',0,23420),
(3580,2,0, 'The Guild Master & Vendor.',0,1,1,3562,0,0,0, '',0,23420),
(3580,3,0, 'The Inn',0,1,1,3563,111,0,0, '',0,23420),
(3580,4,0, 'Stable Master',0,1,1,4923,112,0,0, '',0,23420),
(3580,5,0, 'Class Trainer',0,1,1,3564,0,0,0, '',0,23420),
(3580,6,0, 'Profession Trainer',0,1,1,15733,578,0,0, '',0,23420),
(3580,7,0, 'Hippogryph Master',0,1,1,12632,0,0,0, '',0,23420),
(3564,0,0, 'Druid',0,1,1,3565,113,0,0, '',0,23420),
(3564,1,0, 'Hunter',0,1,1,3566,114,0,0, '',0,23420),
(3564,2,0, 'Mage',0,1,1,12633,579,0,0, '',0,23420),
(3564,3,0, 'Priest',0,1,1,3567,115,0,0, '',0,23420),
(3564,4,0, 'Rogue',0,1,1,3568,116,0,0, '',0,23420),
(3564,5,0, 'Warrior',0,1,1,3569,117,0,0, '',0,23420);

-- Teldrassil Points of Interest Update
DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 578 AND 579;
INSERT INTO `points_of_interest` (`ID`,`PositionX`,`PositionY`,`Icon`,`Flags`,`Data`,`Name`,`VerifiedBuild`) VALUES
(578,9803.2,945.7222,7,99,0, 'Iranis Shadebloom',23420),
(579,9835.054,956.3629,7,99,0, 'Irriende',23420);

-- Add Missing Gossip Menus
DELETE FROM `gossip_menu` WHERE `entry` IN (12633,12700,12704,12776,12777,12778,13866,15733);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(12633,17760),(12700,17831),(12704,17835),(12776,17965),(12777,17966),(12778,17967),(13866,20036),(15733,22593);
-- 434 is missing npc_text 17760,17831,17835,17965,17966,20036,22593
--
