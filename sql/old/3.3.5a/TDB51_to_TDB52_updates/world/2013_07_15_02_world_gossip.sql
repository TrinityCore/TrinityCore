-- Gossip fixup for Morridune
UPDATE `creature_template` SET `gossip_menu_id`=321 WHERE `entry`=6729;
DELETE FROM `gossip_menu` WHERE `entry` IN (321);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (321,818);
-- Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (321);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(321,0,0, 'Please port me to Darnassus.',1,1,0);
