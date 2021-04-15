-- `gossip_menu` has empty data.
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=12180 AND `id`=6) OR (`menu_id`=12180 AND `id`=8) OR (`menu_id`=10181 AND `id`=0) OR (`menu_id`=5856 AND `id`=0) OR (`menu_id`=3285 AND `id`=0) OR (`menu_id`=3285 AND `id`=1) OR (`menu_id`=3285 AND `id`=2) OR (`menu_id`=3285 AND `id`=3) OR (`menu_id`=3285 AND `id`=4) OR (`menu_id`=3285 AND `id`=5) OR (`menu_id`=11107 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(12180, 6, 3, 'Train me in Jewelcrafting.', 0, 0, ''), -- -Unknown-
(12180, 8, 3, 'Train me in Mining.', 0, 0, ''), -- -Unknown-
(10181, 0, 1, 'I want to browse your goods.', 0, 0, ''), -- Grimtak
(5856, 0, 3, 'Train me.', 0, 0, ''), -- Rawrk
(3285, 0, 0, 'The bank', 0, 0, ''), -- Razor Hill Grunt
(3285, 1, 0, 'The wind rider master', 0, 0, ''), -- Razor Hill Grunt
(3285, 2, 0, 'The inn', 0, 0, ''), -- Razor Hill Grunt
(3285, 3, 0, 'The stable master', 0, 0, ''), -- Razor Hill Grunt
(3285, 4, 0, 'A class trainer', 0, 0, ''), -- Razor Hill Grunt
(3285, 5, 0, 'A profession trainer', 0, 0, ''), -- Razor Hill Grunt
(11107, 0, 0, 'Take me back to Darkspear Hold if you would, Vanira.', 0, 0, ''); -- -Unknown-
