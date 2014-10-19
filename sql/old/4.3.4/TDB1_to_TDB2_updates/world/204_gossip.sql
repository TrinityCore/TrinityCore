UPDATE `creature_template` SET `gossip_menu_id`=12797 WHERE `entry`=52924; -- Vol'jin

UPDATE `gossip_menu_option` SET `option_id`=1, `npc_option_npcflag`=1 WHERE `menu_id`=12797;
DELETE FROM `gossip_menu` WHERE (`entry`=12804 AND `text_id`=18002) OR (`entry`=12797 AND `text_id`=17988);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(12804, 18002), -- Bakkalzu
(12797, 17988); -- Vol'jin
