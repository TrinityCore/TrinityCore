UPDATE `gossip_menu_option` SET
    `npc_option_npcflag` = 65536,
    `option_icon` = 5
WHERE
    `menu_id` = 1293 AND
    `id` = 1;

UPDATE `gossip_menu_option` SET
    `npc_option_npcflag` = 128
WHERE
    `menu_id` = 1293 AND
    `id` = 2;
