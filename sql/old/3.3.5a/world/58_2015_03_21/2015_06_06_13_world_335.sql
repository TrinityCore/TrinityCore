--
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`IN (23535, 5753, 5750, 5749, 16649, 16267, 15494, 5815, 6027, 12776, 6374, 5520, 6382, 6328, 6373, 6376);
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`IN (16267, 6328, 6373, 15494, 6374);
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`IN (6027, 5753, 5750, 5520, 6376, 6382, 12776, 5749, 5815, 16649, 23535);
