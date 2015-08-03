DELETE FROM `gossip_menu_option` WHERE (`menu_id`=10638 AND `id`=1) OR (`menu_id`=10486 AND `id`=0) OR (`menu_id`=10278 AND `id`=0) OR (`menu_id`=12035 AND `id`=2);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(10638, 1, 17, 'I wish to start gaining experience again.', 0, 100000, 'Are you certain you wish to start gaining experience again?'), -- Behsten
(10486, 0, 0, 'Who are the Old Ones?', 0, 0, ''), -- Kathrena Winterwisp
(10278, 0, 0, 'Coax Taldan''s corpse to give up its spirit.', 0, 0, ''), -- Taldan
(12035, 2, 0, 'Ride Fiona''s Caravan to its next destination.', 0, 0, ''); -- Fiona's Caravan
