-- 
UPDATE `gossip_menu_option` SET `npc_option_npcflag`=16 WHERE `menu_id` IN (11767, 6647);
UPDATE `gossip_menu_option` SET `option_id`=5 WHERE `menu_id` IN (11767, 6647) AND `id`=0;
UPDATE `gossip_menu_option` SET `option_id`=16 WHERE `menu_id` IN (11767, 6647) AND `id`=1;
UPDATE `gossip_menu_option` SET `option_id`=20, `action_menu_id`=10371, `OptionBroadcastTextID`=33762 WHERE `menu_id` IN (11767, 6647) AND `id`=2;
