-- Fix gossip menu for Salfa
UPDATE `creature_template` SET `gossip_menu_id`=3624 WHERE `entry`=11556;
UPDATE `gossip_menu_option` SET `ActionMenuID`=3623 WHERE `MenuID`=3624;
