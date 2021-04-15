-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=7610 AND `text_id`=9261;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7610,9261);
DELETE FROM `gossip_menu` WHERE `entry`=8249 AND `text_id`=10266;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8249,10266);
DELETE FROM `gossip_menu` WHERE `entry`=7612 AND `text_id`=9263;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7612,9263);
DELETE FROM `gossip_menu` WHERE `entry`=7611 AND `text_id`=9262;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7611,9262);
DELETE FROM `gossip_menu` WHERE `entry`=7588 AND `text_id`=9236;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7588,9236);
DELETE FROM `gossip_menu` WHERE `entry`=7590 AND `text_id`=9238;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7590,9238);
DELETE FROM `gossip_menu` WHERE `entry`=7591 AND `text_id`=9239;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7591,9239);
DELETE FROM `gossip_menu` WHERE `entry`=7589 AND `text_id`=9237;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7589,9237);
DELETE FROM `gossip_menu` WHERE `entry`=7526 AND `text_id`=9128;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7526,9128);
DELETE FROM `gossip_menu` WHERE `entry`=7614 AND `text_id`=9265;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7614,9265);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=7610 WHERE `entry`=18004;
UPDATE `creature_template` SET `gossip_menu_id`=8249 WHERE `entry`=21172;
UPDATE `creature_template` SET `gossip_menu_id`=7612 WHERE `entry`=18005;
UPDATE `creature_template` SET `gossip_menu_id`=7611 WHERE `entry`=18006;
UPDATE `creature_template` SET `gossip_menu_id`=7588 WHERE `entry`=18010;
UPDATE `creature_template` SET `gossip_menu_id`=7590 WHERE `entry`=18019;
UPDATE `creature_template` SET `gossip_menu_id`=7589 WHERE `entry`=18009;
UPDATE `creature_template` SET `gossip_menu_id`=7614 WHERE `entry`=18003;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8249,7612,7611,7588,7590,7589,7495) AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=7590 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8249,0,1, 'I want to browse your goods.',3,128,0,0,0,0, ''),
(7612,0,1, 'I wish to buy from you.',3,128,0,0,0,0, ''),
(7611,0,1, 'I would like to buy from you.',3,128,0,0,0,0, ''),
(7588,0,1, 'Show me your wares, Maktu.',3,128,0,0,0,0, ''),
(7590,0,1, 'Let me browse your reagents and poison supplies.',3,128,0,0,0,0, ''),
(7590,1,0, 'Specialist, eh? Just what kind of specialist are you, anyway?',1,1,7591,0,0,0, ''),
(7589,0,1, 'I wish to browse your wares.',3,128,0,0,0,0, ''),
(7495,0,0, 'Watcher Leesa''oh, why are you out here?',1,1,7526,0,0,0, '');
