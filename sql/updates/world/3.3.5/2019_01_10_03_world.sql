-- 
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry` = 733;
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag` = `npcflag`&~1 WHERE `entry` = 3139;
