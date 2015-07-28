-- `gossip_menu` has empty data.
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=4688 AND `id`=0) OR (`menu_id`=10526 AND `id`=0) OR (`menu_id`=12180 AND `id`=11) OR (`menu_id`=12180 AND `id`=12) OR (`menu_id`=12185 AND `id`=11) OR (`menu_id`=12185 AND `id`=12) OR (`menu_id`=12185 AND `id`=13) OR (`menu_id`=12185 AND `id`=14) OR (`menu_id`=11778 AND `id`=0) OR (`menu_id`=2021 AND `id`=0) OR (`menu_id`=3923 AND `id`=0) OR (`menu_id`=9821 AND `id`=1) OR (`menu_id`=3580 AND `id`=0) OR (`menu_id`=3580 AND `id`=2) OR (`menu_id`=3580 AND `id`=3) OR (`menu_id`=3580 AND `id`=4) OR (`menu_id`=3580 AND `id`=5) OR (`menu_id`=3580 AND `id`=6) OR (`menu_id`=3580 AND `id`=7) OR (`menu_id`=3564 AND `id`=0) OR (`menu_id`=3564 AND `id`=1) OR (`menu_id`=3564 AND `id`=2) OR (`menu_id`=3564 AND `id`=3) OR (`menu_id`=3564 AND `id`=4) OR (`menu_id`=3564 AND `id`=5) OR (`menu_id`=3572 AND `id`=0) OR (`menu_id`=3572 AND `id`=1) OR (`menu_id`=3572 AND `id`=2) OR (`menu_id`=3572 AND `id`=3) OR (`menu_id`=3572 AND `id`=4) OR (`menu_id`=3572 AND `id`=5) OR (`menu_id`=3572 AND `id`=6) OR (`menu_id`=3572 AND `id`=7) OR (`menu_id`=3572 AND `id`=8) OR (`menu_id`=3572 AND `id`=9) OR (`menu_id`=1293 AND `id`=0) OR (`menu_id`=1293 AND `id`=1) OR (`menu_id`=1293 AND `id`=2) OR (`menu_id`=6944 AND `id`=0) OR (`menu_id`=5855 AND `id`=0) OR (`menu_id`=10517 AND `id`=0) OR (`menu_id`=10517 AND `id`=1) OR (`menu_id`=10517 AND `id`=5) OR (`menu_id`=2352 AND `id`=0) OR (`menu_id`=2352 AND `id`=1) OR (`menu_id`=2352 AND `id`=2) OR (`menu_id`=2352 AND `id`=3) OR (`menu_id`=2352 AND `id`=4) OR (`menu_id`=2352 AND `id`=5) OR (`menu_id`=2352 AND `id`=6) OR (`menu_id`=2352 AND `id`=7) OR (`menu_id`=2352 AND `id`=8) OR (`menu_id`=2352 AND `id`=9) OR (`menu_id`=3924 AND `id`=0) OR (`menu_id`=4571 AND `id`=0) OR (`menu_id`=1403 AND `id`=0) OR (`menu_id`=3185 AND `id`=0) OR (`menu_id`=7690 AND `id`=0) OR (`menu_id`=8517 AND `id`=0) OR (`menu_id`=698 AND `id`=0) OR (`menu_id`=5853 AND `id`=0) OR (`menu_id`=4131 AND `id`=0) OR (`menu_id`=4349 AND `id`=0) OR (`menu_id`=4241 AND `id`=0) OR (`menu_id`=4163 AND `id`=0) OR (`menu_id`=12539 AND `id`=0) OR (`menu_id`=12677 AND `id`=1) OR (`menu_id`=12677 AND `id`=2) OR (`menu_id`=4305 AND `id`=0) OR (`menu_id`=11821 AND `id`=0) OR (`menu_id`=2404 AND `id`=0) OR (`menu_id`=8521 AND `id`=0) OR (`menu_id`=12992 AND `id`=0) OR (`menu_id`=4174 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(4688, 0, 3, 'I seek training as a druid.', 0, 0, ''), -- Mardant Strongoak
(10526, 0, 1, 'Let me browse your goods.', 0, 0, ''), -- Dellylah
(12180, 11, 0, 'Tell me about gathering professions.', 0, 0, ''), -- -Unknown-
(12180, 12, 0, 'Tell me about production professions.', 0, 0, ''), -- -Unknown-
(12185, 11, 0, 'Tell me about Herbalism.', 0, 0, ''), -- -Unknown-
(12185, 12, 0, 'Tell me about Mining.', 0, 0, ''), -- -Unknown-
(12185, 13, 0, 'Tell me about Skinning.', 0, 0, ''), -- -Unknown-
(12185, 14, 0, 'Tell me about production professions.', 0, 0, ''), -- -Unknown-
(11778, 0, 1, 'Show me what you have for sale.', 0, 0, ''), -- Nyoma
(2021, 0, 3, 'I''d like to train in cooking.', 0, 0, ''), -- Zarrin
(3923, 0, 3, 'I seek training as a druid.', 0, 0, ''), -- Kal
(9821, 1, 1, 'I''m looking for a lost companion.', 0, 0, ''), -- Seriadne
(3580, 0, 0, 'The Bank', 0, 0, ''), -- Teldrassil Sentinel
(3580, 2, 0, 'The Guild Master & Vendor.', 0, 0, ''), -- Teldrassil Sentinel
(3580, 3, 0, 'The Inn', 0, 0, ''), -- Teldrassil Sentinel
(3580, 4, 0, 'Stable Master', 0, 0, ''), -- Teldrassil Sentinel
(3580, 5, 0, 'Class Trainer', 0, 0, ''), -- Teldrassil Sentinel
(3580, 6, 0, 'Profession Trainer', 0, 0, ''), -- Teldrassil Sentinel
(3580, 7, 0, 'Hippogryph Master', 0, 0, ''), -- Teldrassil Sentinel
(3564, 0, 0, 'Druid', 0, 0, ''), -- Teldrassil Sentinel
(3564, 1, 0, 'Hunter', 0, 0, ''), -- Teldrassil Sentinel
(3564, 2, 0, 'Mage', 0, 0, ''), -- Teldrassil Sentinel
(3564, 3, 0, 'Priest', 0, 0, ''), -- Teldrassil Sentinel
(3564, 4, 0, 'Rogue', 0, 0, ''), -- Teldrassil Sentinel
(3564, 5, 0, 'Warrior', 0, 0, ''), -- Teldrassil Sentinel
(3572, 0, 0, 'Alchemy', 0, 0, ''), -- Teldrassil Sentinel
(3572, 1, 0, 'Cooking', 0, 0, ''), -- Teldrassil Sentinel
(3572, 2, 0, 'Enchanting', 0, 0, ''), -- Teldrassil Sentinel
(3572, 3, 0, 'First Aid', 0, 0, ''), -- Teldrassil Sentinel
(3572, 4, 0, 'Fishing', 0, 0, ''), -- Teldrassil Sentinel
(3572, 5, 0, 'Herbalism', 0, 0, ''), -- Teldrassil Sentinel
(3572, 6, 0, 'Inscription', 0, 0, ''), -- Teldrassil Sentinel
(3572, 7, 0, 'Leatherworking', 0, 0, ''), -- Teldrassil Sentinel
(3572, 8, 0, 'Skinning', 0, 0, ''), -- Teldrassil Sentinel
(3572, 9, 0, 'Tailoring', 0, 0, ''), -- Teldrassil Sentinel
(1293, 0, 0, 'What can I do at an inn?', 0, 0, ''), -- Innkeeper Keldamyr
(1293, 1, 5, 'Make this inn your home.', 0, 0, ''), -- Innkeeper Keldamyr
(1293, 2, 1, 'I want to browse your goods.', 0, 0, ''), -- Innkeeper Keldamyr
(6944, 0, 2, 'Show me where I can fly.', 0, 0, ''), -- -Unknown-
(5855, 0, 3, 'Train me.', 0, 0, ''), -- Byancie
(10517, 0, 0, 'Where is the Rune of Nesting?', 0, 0, ''), -- -Unknown-
(10517, 1, 0, 'Where is the Sapphire of Sky?', 0, 0, ''), -- -Unknown-
(10517, 5, 0, 'Can you lead me to the exit?', 0, 0, ''), -- -Unknown-
(2352, 0, 0, 'Auction House', 0, 0, ''), -- Darnassus Sentinel
(2352, 1, 0, 'The Bank', 0, 0, ''), -- Darnassus Sentinel
(2352, 2, 0, 'Hippogryph Master', 0, 0, ''), -- Darnassus Sentinel
(2352, 3, 0, 'Guild Master & Vendor', 0, 0, ''), -- Darnassus Sentinel
(2352, 4, 0, 'The Inn', 0, 0, ''), -- Darnassus Sentinel
(2352, 5, 0, 'Mailbox', 0, 0, ''), -- Darnassus Sentinel
(2352, 6, 0, 'Stable Master', 0, 0, ''), -- Darnassus Sentinel
(2352, 7, 0, 'Battlemaster', 0, 0, ''), -- Darnassus Sentinel
(2352, 8, 0, 'Class Trainer', 0, 0, ''), -- Darnassus Sentinel
(2352, 9, 0, 'Profession Trainer', 0, 0, ''), -- Darnassus Sentinel
(3924, 0, 3, 'I seek training as a druid.', 0, 0, ''), -- Denatharion
(4571, 0, 3, 'I seek training as a druid.', 0, 0, ''), -- Fylerian Nightwing
(1403, 0, 3, 'I am here for training.', 0, 0, ''), -- Mathrengyl Bearwalker
(3185, 0, 1, 'I would like to buy from you.', 0, 0, ''), -- Lelanai
(7690, 0, 3, 'Train me.', 0, 0, ''), -- -Unknown-
(8517, 0, 3, 'Train me.', 0, 0, ''), -- -Unknown-
(698, 0, 1, 'I want to browse your goods.', 0, 0, ''), -- -Unknown-
(5853, 0, 3, 'Train me.', 0, 0, ''), -- Alegorn
(4131, 0, 3, 'Train me.', 0, 0, ''), -- Ainethil
(4349, 0, 3, 'Train me.', 0, 0, ''), -- Me'lynn
(4241, 0, 3, 'Train me.', 0, 0, ''), -- Telonis
(4163, 0, 3, 'Train me.', 0, 0, ''), -- Taladan
(12539, 0, 3, 'I seek training as a druid.', 0, 0, ''), -- -Unknown-
(12677, 1, 5, 'Make this inn your home.', 0, 0, ''), -- -Unknown-
(12677, 2, 1, 'Let me browse your goods.', 0, 0, ''), -- -Unknown-
(4305, 0, 1, 'Let me browse your goods.', 0, 0, ''), -- Mydrannul
(11821, 0, 3, 'Train me.', 0, 0, ''), -- -Unknown-
(2404, 0, 6, 'I would like to check my deposit box.', 0, 0, ''), -- Idriana
(8521, 0, 3, 'Train me.', 0, 0, ''), -- -Unknown-
(12992, 0, 0, 'Take me to the faire staging area.', 0, 25, 'Travel to the faire staging area will cost:'), -- -Unknown-
(4174, 0, 3, 'Train me.', 0, 0, ''); -- Nadyia Maneweaver
