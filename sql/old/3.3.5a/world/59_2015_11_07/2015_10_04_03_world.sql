-- 
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (11206,11207);
INSERT IGNORE INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `OptionBroadcastTextID`) VALUE 
(11206, 0, 0, 'Northrend requires your attention Overlord Hellscream. We will deal with the Lich King and his minions without your aid.', 1, 1, 11207, 0, 0, 0, '', 39416),
(11207, 0, 0, 'The word is given. The Lich King will die by our hands!', 1, 1, 11208, 0, 0, 0, '', 39415);
UPDATE `npc_text` SET `text0_0`="You turn away the might of the Warsong Offensive? Has the chaos of battle turned you mad? With my help, victory is at hand! Without my help, your fight will be difficult.", `BroadcastTextID0`=39418 WHERE `id`=15608;
UPDATE `npc_text` SET `text0_0`="Glory to the Horde!", `BroadcastTextID0`=39419 WHERE `id`=15609;
