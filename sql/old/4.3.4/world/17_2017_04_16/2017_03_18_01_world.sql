-- Dun Morogh Guard Gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (3533,3545);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3533,0,0, 'Bank',0,1,1,3534,0,0,0, '',0,23420),
(3533,1,0, 'Gryphon Master',0,1,1,3535,0,0,0, '',0,23420),
(3533,2,0, 'Guild Master & Vendor',0,1,1,3536,0,0,0, '',0,23420),
(3533,3,0, 'The Inn',0,1,1,3537,76,0,0, '',0,23420),
(3533,4,0, 'Stable Master',0,1,1,4926,77,0,0, '',0,23420),
(3533,5,0, 'Class Trainer',0,1,1,3545,0,0,0, '',0,23420),
(3533,6,0, 'Profession Trainer',0,1,1,15730,580,0,0, '',0,23420),
(3545,0,0, 'Hunter',0,1,1,3538,78,0,0, '',0,23420),
(3545,1,0, 'Mage',0,1,1,3539,79,0,0, '',0,23420),
(3545,2,0, 'Paladin',0,1,1,3540,80,0,0, '',0,23420),
(3545,3,0, 'Priest',0,1,1,3541,81,0,0, '',0,23420),
(3545,4,0, 'Rogue',0,1,1,3542,82,0,0, '',0,23420),
(3545,5,0, 'Shaman',0,1,1,12608,581,0,0, '',0,23420),
(3545,6,0, 'Warlock',0,1,1,3543,83,0,0, '',0,23420),
(3545,7,0, 'Warrior',0,1,1,3544,84,0,0, '',0,23420);

-- Dun Morogh Points of Interest Update
DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 76 AND 84;
DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 580 AND 581;
INSERT INTO `points_of_interest` (`ID`,`PositionX`,`PositionY`,`Icon`,`Flags`,`Data`,`Name`,`VerifiedBuild`) VALUES
(76,-5584.11,-510.862,7,99,0, 'Thunderbrew Distillery',23420),
(77,-5606.17,-513.008,7,99,0, 'Shelby Stoneflint',23420),
(580,-5637.168,-497.8038,7,99,0, 'Wembil Taskwidget',23420),
(78,-5618.73,-453.72,7,99,0, 'Grif Wildheart',23420),
(79,-5587.37,-539.037,7,99,0, 'Magis Sparkmantle',23420),
(80,-5584.69,-542.492,7,99,0, 'Azar Stronghammer',23420),
(81,-5589.19,-530.288,7,99,0, 'Maxan Anvol',23420),
(82,-5604.48,-540.089,7,99,0, 'Hogral Bakkan',23420),
(581,-5581.787,-535.559,7,99,0, 'Halbin Frosthammer',23420),
(83,-5639.5,-528.501,7,99,0, 'Gimrizz Shadowcog',23420),
(84,-5605.01,-530.145,7,99,0, 'Granis Swiftaxe',23420);

-- Goldshire Guard Gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (3506,3519);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3506,0,0, 'Bank',0,1,1,3507,0,0,0, '',0,23420),
(3506,1,0, 'Gryphon Master',0,1,1,3508,0,0,0, '',0,23420),
(3506,2,0, 'Guild Master & Vendor',0,1,1,3509,0,0,0, '',0,23420),
(3506,3,0, 'Inn',0,1,1,3510,1,0,0, '',0,23420),
(3506,4,0, 'Stable Master',0,1,1,4924,17,0,0, '',0,23420),
(3506,5,0, 'Class Trainer',0,1,1,3519,0,0,0, '',0,23420),
(3506,6,0, 'Profession Trainer',0,1,1,15727,582,0,0, '',0,23420),
(3519,0,0, 'Druid',0,1,1,3511,0,0,0, '',0,23420),
(3519,1,0, 'Hunter',0,1,1,3512,583,0,0, '',0,23420),
(3519,2,0, 'Mage',0,1,1,3514,2,0,0, '',0,23420),
(3519,3,0, 'Paladin',0,1,1,3515,3,0,0, '',0,23420),
(3519,4,0, 'Priest',0,1,1,3513,4,0,0, '',0,23420),
(3519,5,0, 'Rogue',0,1,1,3516,5,0,0, '',0,23420),
(3519,6,0, 'Shaman',0,1,1,8160,0,0,0, '',0,23420),
(3519,7,0, 'Warlock',0,1,1,3518,6,0,0, '',0,23420),
(3519,8,0, 'Warrior',0,1,1,3517,7,0,0, '',0,23420);

-- Goldshire Points of Interest Update
DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 1 AND 7;
DELETE FROM `points_of_interest` WHERE `ID`=17;
DELETE FROM `points_of_interest` WHERE `ID` BETWEEN 582 AND 583;
INSERT INTO `points_of_interest` (`ID`,`PositionX`,`PositionY`,`Icon`,`Flags`,`Data`,`Name`,`VerifiedBuild`) VALUES
(1,-9459.35,42.0805,7,99,0, 'Lion''s Pride Inn',23420),
(17,-9466.62,45.8709,7,99,0, 'Erma',23420),
(582,-9494.002,79.28472,7,99,0, 'Lien Farner',23420),
(583,-9465.143,117.8681,7,99,0, 'Benjamin Foxworthy',23420),
(2,-9471.12,33.4441,7,99,0, 'Zaldimar Wefhellt',23420),
(3,-9469,108.053,7,99,0, 'Brother Wilhelm',23420),
(4,-9461.07,32.996,7,99,0, 'Priestess Josetta',23420),
(5,-9465.14,13.2936,7,99,0, 'Keryn Sylvius',23420),
(6,-9473.22,-4.08464,7,99,0, 'Maximillian Crowe',23420),
(7,-9461.82,109.505,7,99,0, 'Lyria Du Lac',23420);
