UPDATE `creature_template` SET `gossip_menu_id`=1285 WHERE  `entry`=8436;
UPDATE `smart_scripts` SET `event_param1`=1286 WHERE  `entryorguid`=8436 AND `source_type`=0 AND `id`=0;
UPDATE `gossip_menu_option` SET `action_menu_id`=0 WHERE  `menu_id`=1286;
