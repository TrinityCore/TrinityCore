DELETE FROM `gossip_menu_option` WHERE (`menu_id`=11189 AND `id`=0) OR (`menu_id`=11209 AND `id`=0) OR (`menu_id`=11240 AND `id`=0) OR (`menu_id`=11239 AND `id`=0) OR (`menu_id`=11239 AND `id`=1);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(11189, 0, 0, 'Can I catch a ride to Razor Hill?', 0, 0, ''), -- Raider Jhash
(11209, 0, 0, 'Can you tell me your fable, Shin?', 0, 0, ''), -- Shin Stonepillar
(11240, 0, 0, '<Attempt to remove the orb.>', 0, 0, ''), -- Fizzle Darkstorm
(11239, 0, 0, '<Attempt to remove Fizzle''s Hand, then.>', 0, 0, ''), -- Fizzle Darkstorm
(11239, 1, 0, '<Give up.  This is too scary.>', 0, 0, ''); -- Fizzle Darkstorm
