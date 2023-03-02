UPDATE `creature_template` SET `gossip_menu_id`='4486'  WHERE entry IN (5497,5498,7311,45714,47247,47246,47248,4568,4566,4567,3049,3047,16651,16652,16653  ,50010,50021,7312,5144,5145,50717,50720,50716,5146,50690,50715,50714,16749,17513,17514,28956,28958);
DELETE FROM npc_trainer WHERE entry=200200;
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 3561, 5100, 904, 0, 17);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 3562, 5100, 904, 0, 17);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 3565, 5100, 904, 0, 17);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 10059, 16500, 904, 0, 42);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 11416, 16500, 904, 0, 42);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 11419, 16500, 904, 0, 42);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 32266, 16500, 904, 0, 42);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 32271, 5100, 904, 0, 17);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 33690, 810000, 904, 0, 62);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 33691, 105000, 904, 0, 66);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 49359, 5100, 904, 0, 17);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 49360, 16500, 904, 0, 42);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 53140, 150000, 904, 0, 71);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 53142, 168000, 904, 0, 74);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 88342, 282000, 904, 0, 85);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 88345, 282000, 904, 0, 85);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 132620, 423000, 904, 0, 90);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200200, 132621, 423000, 904, 0, 90);
DELETE FROM gossip_menu_option WHERE menu_id=7777;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 0, 0, 'Auction House', 1, 1, 7778, 190, 0, 0, '');
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 1, 0, 'Bank', 1, 1, 7779, 191, 0, 0, '');
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 2, 0, 'Hippogryph Master', 1, 1, 7780, 192, 0, 0, '');
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 3, 0, 'Guild Master & Vendor', 1, 1, 7781, 193, 0, 0, '');
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 4, 0, 'Inn', 1, 1, 7782, 194, 0, 0, '');
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 5, 0, 'Mailbox', 1, 1, 7783, 195, 0, 0, '');
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 6, 0, 'Stable Master', 1, 1, 7784, 196, 0, 0, '');
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 7, 0, 'Battlemasters', 1, 1, 7786, 263, 0, 0, '');
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 8, 0, 'Class Trainer', 1, 1, 7787, 0, 0, 0, '');
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 9, 0, 'Profession Trainer', 1, 1, 7788, 0, 0, 0, '');
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES (7777, 10, 0, 'Reforging', 1, 1, 7789, 0, 0, 0, '');
DELETE FROM `points_of_interest` WHERE (`entry`='7789');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `icon_name`) VALUES ('7789', '-4241', '-11709.9794', '7', '99', 'Exodar Reforging');
DELETE FROM creature_template WHERE entry=100043;
DELETE FROM creature WHERE id=100043;
UPDATE `creature_template` SET `gossip_menu_id`='0' WHERE (`entry`='45139');
DELETE FROM npc_trainer WHERE entry=200201;
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 11417, 16500, 904, 0, 42); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 35717, 105000, 904, 0, 66);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 35715, 105000, 904, 0, 66);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 53142, 168000, 904, 0, 74);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 32267, 16500, 904, 0, 42); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 32272, 16500, 904, 0, 42); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 49361, 22500, 904, 0, 52); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 49358, 22500, 904, 0, 52); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 11420, 16500, 904, 0, 42); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 88346, 282000, 904, 0, 85); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 88344, 282000, 904, 0, 85); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 11418, 16500, 904, 0, 42); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 132626, 423000, 904, 0, 90); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 132627, 423000, 904, 0, 90); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 53140, 150000, 904, 0, 71); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 3567, 5100, 904, 0, 17); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 3566, 5100, 904, 0, 17); 
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES (200201, 3563, 5100, 904, 0, 17); 
UPDATE `creature` SET `MovementType`='0' WHERE (`id`='37966');
UPDATE `creature_template` SET `gossip_menu_id`=10769 WHERE entry IN (5624,36213);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10769,10768,10767);
INSERT INTO `gossip_menu_option` VALUES ('10769', '0', '0', 'The auction house', '1', '1', '10737', '318', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '1', '0', 'The bank', '1', '1', '10738', '319', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '2', '0', 'Barber', '1', '1', '10739', '320', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '3', '0', 'The bat handler', '1', '1', '10740', '321', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '4', '0', 'The battlemaster', '1', '1', '10741', '322', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '5', '0', 'The guild master', '1', '1', '10748', '323', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '6', '0', 'The inn', '1', '1', '10750', '324', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '7', '0', 'Locksmith', '1', '1', '10753', '325', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '8', '0', 'The mailbox', '1', '1', '10755', '326', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '9', '0', 'The stable master', '1', '1', '10761', '327', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '10', '0', 'The weapon master', '1', '1', '10765', '328', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '11', '0', 'The zeppelin master', '1', '1', '10766', '329', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '12', '0', 'A class trainer', '1', '1', '10768', '0', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10769', '13', '0', 'A profession trainer', '1', '1', '10767', '0', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10768', '0', '0', 'Mage', '1', '1', '10754', '331', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10768', '1', '0', 'Paladin', '1', '1', '10757', '330', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10768', '2', '0', 'Priest', '1', '1', '10758', '332', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10768', '3', '0', 'Rogue', '1', '1', '10759', '333', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10768', '4', '0', 'Warlock', '1', '1', '10763', '334', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10768', '5', '0', 'Warrior', '1', '1', '10764', '335', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10768', '6', '0', 'Hunter', '1', '1', '10769', '349', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '0', '0', 'Alchemy', '1', '1', '10736', '336', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '1', '0', 'Blacksmithing', '1', '1', '10742', '337', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '2', '0', 'Cooking', '1', '1', '10743', '338', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '3', '0', 'Enchanting', '1', '1', '10744', '339', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '4', '0', 'Engineering', '1', '1', '10745', '340', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '5', '0', 'First Aid', '1', '1', '10746', '341', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '6', '0', 'Fishing', '1', '1', '10747', '342', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '7', '0', 'Herbalism', '1', '1', '10749', '343', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '8', '0', 'Inscription', '1', '1', '10751', '344', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '9', '0', 'Leatherworking', '1', '1', '10752', '345', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '10', '0', 'Mining', '1', '1', '10756', '347', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '11', '0', 'Skinning', '1', '1', '10760', '346', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('10767', '12', '0', 'Tailoring', '1', '1', '10762', '348', '0', '0', '');
DELETE FROM `points_of_interest` WHERE entry In (10745, 10741, 10753, 10737, 10738, 10739, 10740, 10741, 10748, 10750, 10755, 10761, 10765, 10766, 10754, 10757, 10758, 10759, 10763, 10764, 10742, 10743, 10744, 10745, 10746, 10747, 10749, 10751, 10752, 10760, 10762,10769);
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES
(10741, 1299.13, 347.983, 7, 99, 0, 'Battlemasters Undercity'),
(10753, 1499.75, 53.1442, 7, 103, 0, 'Undercity Locksmith'),
(10737, 1650.31, 240.191, 7, 99, 0, 'Undercity Auction House'),
(10738, 1595.64, 232.456, 7, 99, 0, 'Undercity Bank'),
(10739, 1576.99, 195.566, 7, 99, 0, 'Undercity Barber'),
(10740, 1565.9, 271.435, 7, 99, 0, 'Undercity Bat Handler'),
(10748, 1594.17, 205.572, 7, 99, 0, 'Undercity Guild Master'),
(10750, 1639.43, 220.998, 7, 99, 0, 'Undercity Inn'),
(10755, 1632.69, 219.403, 7, 99, 0, 'Undercity Mailbox'),
(10761, 1634.18, 226.768, 7, 99, 0, 'Anya Maulray'),
(10765, 1670.31, 324.666, 7, 99, 0, 'Archibald'),
(10766, 2059.04, 274.869, 7, 99, 0, 'Undercity Zeppelin'),
(10754, 1781.09, 53.0096, 7, 99, 0, 'Undercity Mage Trainers'),
(10757, 1299.26, 316.787, 7, 99, 0, 'Champion Cyssa Dawnrose'),
(10758, 1758.34, 401.507, 7, 99, 0, 'Undercity Priest Trainers'),
(10759, 1418.56, 65.0243, 7, 99, 0, 'Undercity Rogue Trainers'),
(10763, 1780.92, 53.1697, 7, 99, 0, 'Undercity Warlock Trainers'),
(10764, 1775.6, 418.193, 7, 99, 0, 'Undercity Warrior Trainers'),
(10742, 1696, 285.042, 7, 99, 0, 'Undercity Blacksmithing Trainer'),
(10743, 1596.35, 274.684, 7, 99, 0, 'Undercity Cooking Trainer'),
(10744, 1488.54, 280.194, 7, 99, 0, 'Undercity Enchanting Trainer'),
(10745, 1408.59, 143.431, 7, 99, 0, 'Undercity Engineering Trainer'),
(10746, 1519.65, 167.199, 7, 99, 0, 'Undercity First Aid Trainer'),
(10747, 1679.9, 89.0227, 7, 99, 0, 'Undercity Fishing Trainer'),
(10749, 1558.09, 349.37, 7, 99, 0, 'Undercity Herbalism Trainer'),
(10751, 1502.57, 285.859, 7, 99, 0, 'Undercity Inscription'),
(10752, 1498.76, 196.433, 7, 99, 0, 'Undercity Leatherworking Trainer'),
(10760, 1498.61, 196.466, 7, 99, 0, 'Undercity Skinning Trainer'),
(10762, 1689.55, 193.023, 7, 99, 0, 'Undercity Tailoring Trainer'),
(10769, 1691, 400.0343, 7, 99, 0, 'Undercity Tailoring Trainer');

UPDATE `creature_template` SET `gossip_menu_id`='10675'  WHERE entry IN (39100,45023,45019,3352,47788,47767,3040,3038,3039,39116,50609,16672,16673,16674,50020,50157,50144,50032,50013,50024,45337,45339,43870,43004,43796,16660,16658,16659,50163,50148,44723,45019,46667,3354,3353,50149,3041,3042,3043,4594,4595,50018,44129,44128,47233,3327,50147,4582,50016,16686,16685,23128,44725,50150,43001,8664,50012,16681,16679,16680,44740,45029,50153,51638,51640,50130,45138,3326,3324,50142,43883,43892,4565,4564,50128,16647,16646,44726,50152,3033,3036,50137,50136,16655,13476,5113,5114,1901,1229,5479,5480,914,913,17120,16771,17504,50155,7315,4087,50018,50025,5148,5149,5147,5492,928,5491,50160,32581,17509,17121,16761,50012,50023,5117,5116,5115,4146,4205,5516,5515,5517,16738,17122,17505,50007,50020,50157,5165,5166,5167,13283,51998,4214,4215,4163,50127,50016,50158,5143,5142,11406,5141,5489,376,5484,11401,4092,4090,17511,17510,16756,50024,50013,50163,45306,50732,50729,5172,5171,50723,5173,5496,461,5495,50128,50017,50156,66854,64975,64980,62464,62419,29196,29195,29194,23127,17219,17520,17204,44393,20407,44394,50130,50019,50174,4219,4218,4217,44395,50136,50137,50171,62445);
UPDATE `creature_template` SET `gossip_menu_id`=3331 WHERE `entry` IN (3212,3215,3217,3218,3219,3220,3221,3222,3223,3224);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (3331,3329,3330);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(3331,0,0, 'Mailbox',1,1,3311,417,0,0, ''), 
(3331,1,0, 'The wind rider master',1,1,3312,418,0,0, ''), 
(3331,2,0, 'The Innkeeper',1,1,3313,419,0,0, ''),  
(3331,3,0, 'The stable master',1,1,4903,420,0,0, ''), 
(3331,4,0, 'Riding trainer',1,1,4903,420,0,0, ''), 
(3331,5,0, 'A class trainer',1,1,3329,0,0,0, ''), 
(3331,6,0, 'A profession trainer',1,1,3330,0,0,0, ''), 
(3329,0,0, 'Druid',1,1,3314,421,0,0, ''), 
(3329,1,0, 'Hunter',1,1,3315,422,0,0, ''), 
(3329,2,0, 'Shaman',1,1,3333,423,0,0, ''), 
(3329,3,0, 'Warrior',1,1,3317,424,0,0, ''), 
(3329,4,0, 'Paladin',1,1,3316,424,0,0, ''), 
(3329,5,0, 'Priest',1,1,3332,424,0,0, ''), 
(3330,0,0, 'Alchemy',1,1,3318,0,0,0, ''), 
(3330,1,0, 'Blacksmithing',1,1,3319,0,0,0, ''), 
(3330,2,0, 'Cooking',1,1,3320,425,0,0, ''), 
(3330,3,0, 'Enchanting',1,1,3321,0,0,0, ''), 
(3330,4,0, 'First Aid',1,1,3322,426,0,0, ''), 
(3330,5,0, 'Fishing',1,1,3323,427,0,0, ''),  
(3330,6,0, 'Herbalism',1,1,3324,0,0,0, ''), 
(3330,7,0, 'Inscription',1,1,10021,296,0,0, ''), 
(3330,8,0, 'Leatherworking',1,1,3325,428,0,0, ''), 
(3330,9,0, 'Mining',1,1,3326,0,0,0, ''), 
(3330,10,0, 'Skinning',1,1,3327,429,0,0, ''), 
(3330,11,0, 'Tailoring',1,1,3328,0,0,0, ''); 

DELETE FROM `points_of_interest` WHERE entry In (3311,3312,3313,4903,3329,3330,3314,3315,3316,3317,3318,3319,3320,3321,3322,3323,3324,10021,3325,3326,3327,3328,3333,3332,3331);
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3313', '-2365', '-347.3084', '7', '99', '0', 'The Innkeeper');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3322', '-2357', '-356.7123', '7', '99', '0', 'First Aid');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3331', '-2340', '-354.5899', '7', '99', '0', 'The stable master');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3312', '-2340', '-354.5899', '7', '99', '0', 'The wind rider master');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3311', '-2340', '-354.5899', '7', '99', '0', 'Mailbox');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3314', '-2308', '-444.6804', '7', '99', '0', 'Druid Trainer');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3316', '-2308', '-444.6804', '7', '99', '0', 'Paladin Trainer');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3332', '-2308', '-444.6804', '7', '99', '0', 'Priest Trainer');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3333', '-2308', '-444.6804', '7', '99', '0', 'Shaman Trainer');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3317', '-2348', '-496.4156', '7', '99', '0', 'Warrior Trainer');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3320', '-2257', '-287.5747', '7', '99', '0', 'Cooking Trainer');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3325', '-2257', '-287.575', '7', '99', '0', 'Leatherworking');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3327', '-2257', '-287.575', '7', '99', '0', 'Skinning');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3318', '-2263', '-324.860', '7', '99', '0', 'Alchemy');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3319', '-2263', '-324.860', '7', '99', '0', 'Blacksmithing');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3321', '-2263', '-324.860', '7', '99', '0', 'Enchanting');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3323', '-2263', '-324.860', '7', '99', '0', 'Fishing');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3324', '-2263', '-324.860', '7', '99', '0', 'Herbalism');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('10021', '-2263', '-324.860', '7', '99', '0', 'Inscription');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3326', '-2263', '-324.860', '7', '99', '0', 'Mining');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3328', '-2263', '-324.860', '7', '99', '0', 'Tailoring');
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES ('3315', '-2180', '-408.403', '7', '99', '0', 'Hunter Trainer');
