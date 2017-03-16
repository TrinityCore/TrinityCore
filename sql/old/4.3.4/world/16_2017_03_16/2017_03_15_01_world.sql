-- 434 Fixup for Thunder Buff Guard Gossip this is not for master
-- Point of interest fixes for Thunder Bluff
UPDATE `points_of_interest` SET `PositionX`=-1057.35,`PositionY`=-261.014 WHERE `ID`=285;
UPDATE `points_of_interest` SET `PositionX`=-1116.56,`PositionY`=-45.6337 WHERE `ID`=292;
DELETE FROM `points_of_interest` WHERE `ID` IN (500,501,502,503);
INSERT INTO `points_of_interest` (`ID`,`PositionX`,`PositionY`,`Icon`,`Flags`,`Data`,`Name`,`VerifiedBuild`) VALUES
(500,-1404.26,-130.934,7,99,0, 'Sunwalker Lodge',23420),
(501,-1045.52,-266.559,7,99,0, 'Thunder Bluff Archaeology',23420),
(502,-1266.255,139.4323,7,99,0, 'Thunder Bluff Engineering',23420),
(503,-1224.127,150.967,7,99,0, 'Thunder Bluff Jewelcrafting',23420);
 
-- Thunder Buff Guard Gossip
-- Top Menu
DELETE FROM `gossip_menu_option` WHERE `menu_id`=721 AND `id` IN (10,11,12);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=5515,`option_id`=1, `npc_option_npcflag`=1,`action_menu_id`=2463,`action_poi_id`=280 WHERE `menu_id`=721 AND `id`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=7066,`option_id`=1, `npc_option_npcflag`=1,`action_menu_id`=743,`action_poi_id`=275 WHERE `menu_id`=721 AND `id`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=7078,`option_id`=1, `npc_option_npcflag`=1,`action_menu_id`=740 WHERE `menu_id`=721 AND `id`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=5332,`option_id`=1, `npc_option_npcflag`=1,`action_menu_id`=742,`action_poi_id`=277 WHERE `menu_id`=721 AND `id`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=5513,`option_id`=1, `npc_option_npcflag`=1,`action_menu_id`=2461,`action_poi_id`=278 WHERE `menu_id`=721 AND `id`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=5514,`option_id`=1, `npc_option_npcflag`=1,`action_menu_id`=2462,`action_poi_id`=279 WHERE `menu_id`=721 AND `id`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=7095,`option_id`=1, `npc_option_npcflag`=1,`action_menu_id`=751 WHERE `menu_id`=721 AND `id`=6;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=8524,`option_id`=1, `npc_option_npcflag`=1,`action_menu_id`=4904,`action_poi_id`=282 WHERE `menu_id`=721 AND `id`=7;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=6720,`option_id`=1, `npc_option_npcflag`=1,`action_menu_id`=744,`action_poi_id`=276 WHERE `menu_id`=721 AND `id`=8;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=5518,`option_id`=1, `npc_option_npcflag`=1,`action_menu_id`=10596,`action_poi_id`=284 WHERE `menu_id`=721 AND `id`=9;

-- Class Trainer
DELETE FROM `gossip_menu_option` WHERE `menu_id`=740;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(740,0,0,'Druid',45409,1,1,745,285,0,0,'',0,0),
(740,1,0,'Hunter',45403,1,1,746,286,0,0,'',0,0),
(740,2,0,'Mage',45404,1,1,747,287,0,0,'',0,0),
(740,3,0,'Paladin',48028,1,1,12328,500,0,0,'',0,0),
(740,5,0,'Priest',45405,1,1,12329,285,0,0,'',0,0),
(740,6,0,'Shaman',45410,1,1,749,288,0,0,'',0,0),
(740,7,0,'Warrior',45408,1,1,750,286,0,0,'',0,0);

-- Profession Menu
DELETE FROM `gossip_menu_option` WHERE `menu_id`=751;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(751,0,0,'Alchemy',52058,1,1,780,289,0,0,'',0,0),
(751,1,0,'Archaeology',44649,1,1,12327,501,0,0,'',0,0),
(751,2,0,'Blacksmithing',51346,1,1,781,290,0,0,'',0,0),
(751,3,0,'Cooking',45763,1,1,782,291,0,0,'',0,0),
(751,4,0,'Enchanting',52063,1,1,783,292,0,0,'',0,0),
(751,5,0,'Engineering',45756,1,1,12780,502,0,0,'',0,0),
(751,6,0,'First Aid',52066,1,1,784,293,0,0,'',0,0),
(751,7,0,'Fishing',45767,1,1,785,294,0,0,'',0,0),
(751,8,0,'Herbalism',45768,1,1,786,295,0,0,'',0,0),
(751,9,0,'Inscription',48811,1,1,10021,296,0,0,'',0,0),
(751,10,0,'Jewelcrafting',18338,1,1,12781,503,0,0,'',0,0),
(751,11,0,'Leatherworking',52071,1,1,787,297,0,0,'',0,0),
(751,12,0,'Mining',51348,1,1,788,298,0,0,'',0,0),
(751,13,0,'Skinning',52076,1,1,791,299,0,0,'',0,0),
(751,14,0,'Tailoring',52077,1,1,789,297,0,0,'',0,0);