DELETE FROM `gossip_menu_option` WHERE (`menu_id`=8654 AND `id`=0) OR (`menu_id`=8638 AND `id`=0) OR (`menu_id`=8035 AND `id`=0) OR (`menu_id`=7857 AND `id`=0) OR (`menu_id`=7857 AND `id`=5) OR (`menu_id`=9200 AND `id`=0) OR (`menu_id`=9297 AND `id`=0) OR (`menu_id`=9297 AND `id`=1) OR (`menu_id`=12125 AND `id`=0) OR (`menu_id`=11541 AND `id`=0) OR (`menu_id`=11544 AND `id`=0) OR (`menu_id`=11289 AND `id`=0) OR (`menu_id`=11461 AND `id`=0) OR (`menu_id`=11461 AND `id`=1) OR (`menu_id`=12014 AND `id`=0) OR (`menu_id`=12014 AND `id`=1) OR (`menu_id`=12003 AND `id`=0) OR (`menu_id`=12268 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(8654, 0, 0, 'I''m with you, Akama.', 0, 0, ''), -- Akama
(8638, 0, 0, 'We''re ready to face Illidan.', 0, 0, ''), -- Akama
(8035, 0, 1, 'Let''s see what you have.', 0, 0, ''), -- Spirit Sage Gartok
(7857, 0, 5, 'Make this inn your home.', 0, 0, ''), -- Matron Tikkit
(7857, 5, 1, 'What do you have for sale?', 0, 0, ''), -- Matron Tikkit
(9200, 0, 0, 'What can we do to assist you?', 0, 0, ''), -- Kalecgos
(9297, 0, 0, 'You''re not alone here?', 0, 0, ''), -- Kalecgos
(9297, 1, 0, 'What would Kil''jaeden want with a mortal woman?', 0, 0, ''), -- Kalecgos
(12125, 0, 0, 'Could you please send me to Moonglade, Emissary?', 0, 0, ''), -- Cenarion Emissary Blackhoof
(11541, 0, 0, 'Tell me about the wolf ancient, Lo''Gosh.', 0, 0, ''), -- Takrik Ragehowl
(11544, 0, 0, 'Yes, tell me more.', 0, 0, ''), -- Takrik Ragehowl
(11289, 0, 0, 'Okay, let''s try this again.', 0, 0, ''), -- Kristoff Manheim
(11461, 0, 0, '<Soften her up.>', 0, 0, ''), -- Marion Wormwing
(11461, 1, 0, 'Why are you stealing eggs?', 0, 0, ''), -- Marion Wormwing
(12014, 0, 1, 'Can you repair equipment?', 0, 0, ''), -- Earthmender Doros
(12014, 1, 0, 'Do you have any supplies?', 0, 0, ''), -- Earthmender Doros
(12003, 0, 5, 'Make this inn your home.', 0, 0, ''), -- Caretaker Nuunwa
(12268, 0, 1, 'Show me your wares, quartermaster.', 0, 0, ''); -- Krom'gar Quartermaster
