-- `gossip_menu` has empty data.
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=1582 AND `id`=0) OR (`menu_id`=1582 AND `id`=1) OR (`menu_id`=21 AND `id`=0) OR (`menu_id`=349 AND `id`=0) OR (`menu_id`=349 AND `id`=1) OR (`menu_id`=8076 AND `id`=0) OR (`menu_id`=1624 AND `id`=0) OR (`menu_id`=11767 AND `id`=0) OR (`menu_id`=11767 AND `id`=1) OR (`menu_id`=4341 AND `id`=0) OR (`menu_id`=344 AND `id`=0) OR (`menu_id`=344 AND `id`=1) OR (`menu_id`=4323 AND `id`=0) OR (`menu_id`=4324 AND `id`=0) OR (`menu_id`=5854 AND `id`=0) OR (`menu_id`=12460 AND `id`=0) OR (`menu_id`=4140 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(1582, 0, 5, 'Make this inn your home.', 0, 0, ''), -- -Unknown-
(1582, 1, 1, 'I want to browse your goods.', 0, 0, ''), -- -Unknown-
(21, 0, 0, 'How can I help?', 0, 0, ''), -- Sputtervalve
(349, 0, 5, 'Make this inn your home.', 0, 0, ''), -- -Unknown-
(349, 1, 1, 'I want to browse your goods.', 0, 0, ''), -- -Unknown-
(8076, 0, 9, 'I would like to go to the battleground.', 0, 0, ''), -- Gargok
(1624, 0, 1, 'I want to browse your goods.', 0, 0, ''), -- -Unknown-
(11767, 0, 3, 'I would like to train.', 0, 0, ''), -- -Unknown-
(11767, 1, 0, 'I wish to unlearn my talents.', 0, 0, ''), -- -Unknown-
(4341, 0, 1, 'Let me browse your goods.', 0, 0, ''), -- Zargh
(344, 0, 5, 'Make this inn your home.', 0, 0, ''), -- Innkeeper Boorand Plainswind
(344, 1, 1, 'Let me browse your goods.', 0, 0, ''), -- Innkeeper Boorand Plainswind
(4323, 0, 2, 'I need a ride.', 0, 0, ''), -- Devrak
(4324, 0, 1, 'Let me browse your goods.', 0, 0, ''), -- Jahan Hawkwing
(5854, 0, 3, 'Train me.', 0, 0, ''), -- Duhng
(12460, 0, 2, 'Show me where I can fly.', 0, 0, ''), -- Bragok
(4140, 0, 3, 'Train me.', 0, 0, ''); -- Tinkerwiz
