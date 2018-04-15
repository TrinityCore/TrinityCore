 -- Prince Toreth <Dragon Riders of Loreth'Aran>
UPDATE `creature_template` SET `gossip_menu_id`=7478 WHERE `entry`=17674;
-- Creature Gossip_menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=7474 AND `text_id`=9060;
DELETE FROM `gossip_menu` WHERE `entry`=7475 AND `text_id`=9059;
DELETE FROM `gossip_menu` WHERE `entry`=7476 AND `text_id`=9058;
DELETE FROM `gossip_menu` WHERE `entry`=7477 AND `text_id`=9057;
DELETE FROM `gossip_menu` WHERE `entry`=7478 AND `text_id`=9056;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7474,9060),(7475, 9059),(7476,9058),(7477,9057),(7478,9056);
-- Creature Gossip_menu_option insert from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7478,7477,7476,7475) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(7478,0,0, 'Why do you suffer?',1,1,7477,0,0,0, ''),
(7477,0,0, 'What is Ysera and how were you blessed?',1,1,7476,0,0,0, ''),
(7476,0,0, 'Until what?',1,1,7475,0,0,0, ''),
(7475,0,0, 'So why are you still here?',1,1,7474,0,0,0, '');
