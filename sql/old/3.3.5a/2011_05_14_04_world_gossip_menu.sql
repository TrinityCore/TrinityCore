-- Add Missing Options to Silvermoon Paladin Trainer
DELETE FROM `gossip_menu_option` WHERE `menu_id`=6647 AND `id` IN (1,2);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`, `box_money`, `box_text`) VALUES
(6647,1,2, 'I wish to unlearn my talents',16,16,0,0,0,0,0, ''),
(6647,2,2, 'Purchase a Dual Talent Specialization',18,16,0,0,0,0,10000000, 'Are you sure you wish to purchase a Dual Talent Specialization?');
