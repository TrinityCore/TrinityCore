UPDATE `command` SET `help` = 'Syntax: .reload all gossips\nReload gossip_menu, gossip_menu_option, gossip_scripts, points_of_interest tables.' WHERE `name`='reload all gossips';
DELETE FROM `command` WHERE `name` = 'reload gossip_scripts';
DROP TABLE IF EXISTS `gossip_scripts`;
ALTER TABLE `gossip_menu_option` DROP `action_script_id`;
