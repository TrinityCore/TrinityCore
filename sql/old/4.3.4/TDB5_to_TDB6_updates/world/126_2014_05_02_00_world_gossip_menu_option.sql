UPDATE `gossip_menu_option` SET `option_id`=1,`npc_option_npcflag`=1 WHERE (`menu_id` IN (1971,2306,2422,1802,1801,1142,942,940,3624,4461,5262,5268,6186,6187,6211,7849,7859,8725,8891,8917,9200) AND `id`=0) OR (`menu_id` IN (942,5221,5262,5263,5268,6213,8391) AND `id`=1);
UPDATE `gossip_menu_option` SET `option_id`=1,`npc_option_npcflag`=1 WHERE `menu_id` IN (5262,5268) AND `id` IN (2,3,4,5,6); 
UPDATE `gossip_menu_option` SET `option_id`=1,`npc_option_npcflag`=1 WHERE `menu_id` IN (6185,6210) AND `id` IN (0,1,2); 
UPDATE `gossip_menu_option` SET `option_id`=1,`npc_option_npcflag`=1 WHERE `menu_id`=6185 AND `id`=3; 
UPDATE `gossip_menu_option` SET `option_id`=4,`npc_option_npcflag`=8192 WHERE `menu_id`=7149 AND `id`=0; 
UPDATE `gossip_menu_option` SET `option_id`=5,`npc_option_npcflag`=16 WHERE `menu_id` IN (646,1022,4149,4152,4166,4210,4354,4554,4822,4844,5221,5263,7429,7430) AND `id`=0;
UPDATE `gossip_menu_option` SET `option_id`=16,`npc_option_npcflag`=16 WHERE `menu_id`=4554 AND `id`=1;
UPDATE `gossip_menu_option` SET `option_id`=3,`npc_option_npcflag`=128 WHERE (`menu_id` IN (1802,3626) AND `id`=1) OR (`menu_id`=2890 AND `id`=5) OR (`menu_id` IN (2952,4746,7428) AND `id`=0) OR (`menu_id` IN (344,1293) AND `id`=3);
UPDATE `gossip_menu_option` SET `option_id`=8,`npc_option_npcflag`=65536 WHERE `menu_id`=2890 AND `id`=1;
