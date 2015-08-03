-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9918 AND `text_id`=13792;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9918,13792);
DELETE FROM `gossip_menu` WHERE `entry`=9859 AND `text_id`=13650;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9859,13650);
DELETE FROM `gossip_menu` WHERE `entry`=9857 AND `text_id`=13651;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9857,13651);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=10316 WHERE `entry`=33224;
UPDATE `creature_template` SET `gossip_menu_id`=9918 WHERE `entry`=29430;
UPDATE `creature_template` SET `gossip_menu_id`=9859 WHERE `entry`=29434;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10316,9857,9917) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10316,0,0, 'Glad to help, my lady. I''m told you were once the guardian of a fabled sword. Do you know where I might find it?',1,1,10315,0,0,0, ''),
(9857,0,0, 'I''m ready - lets get you out of here.',1,1,0,0,0,0, ''),
(9917,0,0, 'I am ready to head further into Storm Peaks.',1,1,0,0,0,0, '');
