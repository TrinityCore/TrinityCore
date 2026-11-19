DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_gen_slow_roasted_turkey',
'spell_gen_cranberry_chutney',
'spell_gen_spice_bread_stuffing',
'spell_gen_pumpkin_pie',
'spell_gen_candied_sweet_potato'
);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(65422, 'spell_gen_slow_roasted_turkey'),   -- Slow-Roasted Turkey
(65420, 'spell_gen_cranberry_chutney'),     -- Cranberry Chutney
(65419, 'spell_gen_spice_bread_stuffing'),  -- Spice Bread Stuffing
(65421, 'spell_gen_pumpkin_pie'),           -- Pumpkin Pie
(65418, 'spell_gen_candied_sweet_potato');  -- Candied Sweet Potato
