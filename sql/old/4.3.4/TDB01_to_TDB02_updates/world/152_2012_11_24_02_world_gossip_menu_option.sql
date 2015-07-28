-- 4.x values in DB

/*
UPDATE `creature_template` SET `gossip_menu_id`=2352 WHERE `entry`=4262;

DELETE FROM `gossip_menu` WHERE `entry`=2352 AND `text_id`=3016;
DELETE FROM `gossip_menu` WHERE `entry`=2323 AND `text_id`=3018;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(2352, 3016),(2323, 3018);

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=2352 AND `id`=0) OR (`menu_id`=2352 AND `id`=1) OR (`menu_id`=2352 AND `id`=2) OR (`menu_id`=2352 AND `id`=3) OR (`menu_id`=2352 AND `id`=4) OR (`menu_id`=2352 AND `id`=5) OR (`menu_id`=2352 AND `id`=6) OR (`menu_id`=2352 AND `id`=7) OR (`menu_id`=2352 AND `id`=8) OR (`menu_id`=2352 AND `id`=9) OR (`menu_id`=2352 AND `id`=10) OR (`menu_id`=2352 AND `id`=11);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(2352, 0, 0, 'Auction House', 1, 1, 3101, 89, 0, 0, ''),
(2352, 1, 0, 'The Bank', 1, 1, 2322, 90, 0, 0, ''),
(2352, 2, 0, 'Hippogryph Master', 1, 1, 2323, 91, 0, 0, ''),
(2352, 3, 0, 'Guild Master', 1, 1, 2324, 92, 0, 0, ''),
(2352, 4, 0, 'The Inn', 1, 1, 2325, 93, 0, 0, ''),
(2352, 5, 0, 'Mailbox', 1, 1, 2326, 94, 0, 0, ''),
(2352, 6, 0, 'Stable Master', 1, 1, 4921, 95, 0, 0, ''),
(2352, 7, 0, 'Weapons Trainer', 1, 1, 3722, 96, 0, 0, ''),
(2352, 8, 0, 'Battlemaster', 1, 1, 8221, 97, 0, 0, ''),
(2352, 9, 0, 'Class Trainer', 1, 1, 2343, 0, 0, 0, ''),
(2352, 10, 0, 'Profession Trainer', 1, 1, 2351, 0, 0, 0, ''),
(2352, 11, 0, 'Lexicon of Power', 1, 1, 10205, 107, 0, 0, '');
*/
