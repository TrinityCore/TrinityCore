-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=6768 AND `text_id`=6194;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6768,6194);
DELETE FROM `gossip_menu` WHERE `entry`=8703 AND `text_id`=10948;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8703,10948);
DELETE FROM `gossip_menu` WHERE `entry`=8672 AND `text_id`=10910;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8672,10910);
DELETE FROM `gossip_menu` WHERE `entry`=8673 AND `text_id`=10911;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8673,10911);
DELETE FROM `gossip_menu` WHERE `entry`=8678 AND `text_id`=10916;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8678,10916);
DELETE FROM `gossip_menu` WHERE `entry`=8677 AND `text_id`=10921;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8677,10921);
DELETE FROM `gossip_menu` WHERE `entry`=8677 AND `text_id`=10913;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8677,10913); -- Needs condition of 10 Apexis Shards
DELETE FROM `gossip_menu` WHERE `entry`=8676 AND `text_id`=10914;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8676,10914);
DELETE FROM `gossip_menu` WHERE `entry`=8704 AND `text_id`=10949;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8704,10949);
DELETE FROM `gossip_menu` WHERE `entry`=8681 AND `text_id`=10927;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8681,10927);
DELETE FROM `gossip_menu` WHERE `entry`=8671 AND `text_id`=10951;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8671,10951);
DELETE FROM `gossip_menu` WHERE `entry`=8680 AND `text_id`=10923;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8680,10923);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=6768 WHERE `entry`=13418;
UPDATE `creature_template` SET `gossip_menu_id`=8678 WHERE `entry`=23316;
UPDATE `creature_template` SET `gossip_menu_id`=8681 WHERE `entry`=23233;
UPDATE `creature_template` SET `gossip_menu_id`=8680 WHERE `entry`=23300;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (6768,8703,8672,8673,8677,8676,8704) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(6768,0,1, 'Let me browse your seasonal fare.',3,128,0,0,0,0, ''),
(8703,0,0, 'Insert an Apexis Shard, and begin!',1,1,0,0,0,0, ''),
(8672,0,0, 'Purchase 1 Unstable Flask of the Beast for the cost of 10 Apexis Shards',1,1,8673,0,0,0, ''),  -- Needs condition of 10 Apexis Shards
(8673,0,0, 'Use the fel crystalforge to make another purchase.',1,1,8672,0,0,0, ''),
(8677,0,0, 'Purchase 1 Unstable Flask of the Sorcerer for the cost of 10 Apexis Shards',1,1,8676,0,0,0, ''),  -- Needs condition of 10 Apexis Shards
(8676,0,0, 'Use the Bash''ir crystalforge to make another purchase.',1,1,8677,0,0,0, ''),
(8704,0,0, 'Insert 35 Apexis Shards, and begin!',1,1,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8689 AND `text_id`=10931;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8689,10931);
DELETE FROM `gossip_menu` WHERE `entry`=8669 AND `text_id`=10938;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8669,10938);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8669 WHERE `entry`=23334;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8689) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8689,0,0, 'Place 35 Apexis Shards near the dragon egg to crack it open.',1,1,0,0,0,0, '');
