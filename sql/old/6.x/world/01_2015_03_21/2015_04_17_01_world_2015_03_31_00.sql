-- Fix for quest ID 5561, Kodo Roundup
-- Add the missing link between npc_text and gossip_menu_id :
DELETE FROM `gossip_menu` WHERE `entry`=3650 AND `text_id`=4449;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (3650, 4449);
-- Link the npc_text from gossip_menu:
UPDATE `creature_template` SET `gossip_menu_id`=3650 WHERE `entry`=11627;
