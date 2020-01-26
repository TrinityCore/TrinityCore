DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_pri_item_greater_heal_refund',
'spell_gen_reverse_cast_ride_vehicle',
'spell_gen_revserse_cast_mirror_image',
'spell_gen_mirror_image_aura',
'spell_baleroc_tormented_debuff',
'spell_pos_ice_shards');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (41055, 45206) AND `ScriptName`= 'spell_gen_clone_weapon';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37594, 'spell_pri_item_greater_heal_refund'),
(69425, 'spell_pos_ice_shards'),
(99257, 'spell_baleroc_tormented_debuff'),
(99402, 'spell_baleroc_tormented_debuff'),
(99403, 'spell_baleroc_tormented_debuff'),
(99404, 'spell_baleroc_tormented_debuff'),
(82721, 'spell_gen_reverse_cast_ride_vehicle'),
(82315, 'spell_gen_reverse_cast_ride_vehicle'),
(84301, 'spell_gen_reverse_cast_ride_vehicle'),
(84318, 'spell_gen_reverse_cast_ride_vehicle'),
(86783, 'spell_gen_revserse_cast_mirror_image'),
(86784, 'spell_gen_mirror_image_aura'),
(41055, 'spell_gen_clone_weapon'),
(45206, 'spell_gen_clone_weapon');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15989;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15989, 11, 0, 0, 'achievement_straw_broke_camels_back');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 4244;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(4244, 11, 0, 0, 'achievement_hadronox_denied');

DELETE FROM `npc_text` WHERE `ID`= 10884;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES
(10884, 'Missing npc_text');
