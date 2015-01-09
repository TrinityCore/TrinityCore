-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=752 AND `text_id`=1302;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (752,1302);
DELETE FROM `gossip_menu` WHERE `entry`=1541 AND `text_id`=2213;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1541,2213);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=752 WHERE `entry`=7363;
UPDATE `creature_template` SET `gossip_menu_id`=11618 WHERE `entry`=9540;
UPDATE `creature_template` SET `gossip_menu_id`=1541 WHERE `entry`=8816;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1541) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(1541,0,0, 'I wish to face the Defiler.',1,1,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9735 AND `text_id`=13342;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9735,13342);
DELETE FROM `gossip_menu` WHERE `entry`=9754 AND `text_id`=13397;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9754,13397);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9735 WHERE `entry`=28760;
UPDATE `creature_template` SET `gossip_menu_id`=9769 WHERE `entry`=28914;
UPDATE `creature_template` SET `gossip_menu_id`=9762 WHERE `entry`=28912;
UPDATE `creature_template` SET `gossip_menu_id`=9795 WHERE `entry`=29173;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9735,9769,9795) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9735,0,1, 'Yes, Hargus. I wish to purchase supplies.',3,128,0,0,0,0, ''),
(9769,0,0, 'I missed the gate to Acherus, Orbaz. Could you please open another?',1,1,0,0,0,0, ''),
(9795,0,0, 'I am ready, Highlord. Let the siege of Light''s Hope begin!',1,1,0,0,0,0, '');
