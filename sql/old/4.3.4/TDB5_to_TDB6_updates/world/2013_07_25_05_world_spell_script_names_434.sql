DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_pal_eye_for_an_eye',
'spell_warr_second_wind_proc',
'spell_hun_thrill_of_the_hunt',
'spell_dk_improved_blood_presence',
'spell_dk_improved_unholy_presence',
'spell_sha_tidal_waves',
'spell_sha_focused_insight',
'spell_sha_telluric_currents',
'spell_mage_nether_vortex',
'spell_sha_feedback',
'spell_mage_nether_vortex',
'spell_sha_rolling_thunder',
'spell_sha_lava_surge'
);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-9799, 'spell_pal_eye_for_an_eye'),
(-29834, 'spell_warr_second_wind_proc'),
(-34497, 'spell_hun_thrill_of_the_hunt'),
(-50365, 'spell_dk_improved_blood_presence'),
(-50391, 'spell_dk_improved_unholy_presence'),
(-51562, 'spell_sha_tidal_waves'),
(-77794, 'spell_sha_focused_insight'),
(-82984, 'spell_sha_telluric_currents'),
(-86181, 'spell_mage_nether_vortex'),
(-86183, 'spell_sha_feedback'),
(-88756, 'spell_sha_rolling_thunder'),
(-77755, 'spell_sha_lava_surge');
