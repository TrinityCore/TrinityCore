DELETE FROM `creature_text` WHERE  `entry`=4968 AND `groupid`=6 AND `id`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=4968 AND `source_type`=0 AND `id` IN(1,2);
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=4968 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `gossip_menu_option` SET `action_menu_id`=5850 WHERE  `menu_id`=2465 AND `id`=0;
