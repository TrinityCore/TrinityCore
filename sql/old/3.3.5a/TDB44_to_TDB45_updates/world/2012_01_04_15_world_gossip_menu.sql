-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9475 AND `text_id`=12733;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9475,12733);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9475 WHERE `entry`=27060;
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9786 AND `text_id`=13466;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9786,13466);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9574 WHERE `entry`=27659;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9574) AND `id` IN (0,1,4);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9574,0,0, 'What should we do next?',1,1,9786,0,0,0, ''),
(9574,1,0, 'I want to fly on the wings of the Bronze Flight.',1,1,0,0,0,0, ''),
(9574,4,0, 'What abilities do Amber Drakes have?',1,1,0,0,0,0, '');
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9690 AND `text_id`=13157;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9690,13157);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9690 WHERE `entry`=26664;
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=10009 AND `text_id`=13873;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10009,13873);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=10009 WHERE `entry`=30871;
