UPDATE `command` SET `help` = 'Syntax: .reload all gossips\nReload gossip_menu, gossip_menu_option, gossip_scripts, points_of_interest tables.' WHERE `name` = 'reload all gossips';
UPDATE `command` SET `help` = 'Syntax: .reload all npc\nReload npc_option, npc_trainer, npc vendor, points of interest tables.' WHERE `name` = 'reload all npc';
DELETE FROM `command` WHERE `name` = 'reload npc_gossip';
