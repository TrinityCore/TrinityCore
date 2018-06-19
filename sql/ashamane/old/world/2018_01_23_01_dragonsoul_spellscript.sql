
DELETE FROM `spell_script_names` WHERE (`spell_id`) IN ('105408', '105842', '106040', '106728', '106835', '108601', '109971', '110632');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105408', 'spell_madness_of_deathwing_burning_blood');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105842', 'spell_madness_of_deathwing_degenerative_bite');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('106040', 'spell_madness_of_deathwing_spellweaving');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('106728', 'spell_madness_of_deathwing_tetanus');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('106835', 'spell_madness_of_deathwing_corrupted_blood_dps');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('108601', 'spell_madness_of_deathwing_corrupting_parasite_dmg');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('109971', 'spell_madness_of_deathwing_fire_dragon_soul');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('110632', 'spell_madness_of_deathwing_elementium_meteor_aura_dps');

DELETE FROM `spell_script_names` WHERE (`ScriptName`) IN ('spell_ultraxion_fading_light');
DELETE FROM `spell_script_names` WHERE (`spell_id`) IN ('106415', '109406', '109397', '105592', '109405', '105900', '106108');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105925', 'spell_ultraxion_fading_light');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('109075', 'spell_ultraxion_fading_light');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('106415', 'spell_ultraxion_twilight_burst');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('109406', 'spell_ultraxion_cosmetic_intro');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('109397', 'spell_ultraxion_cosmetic_lightning');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105592', 'spell_ultraxion_cosmetic_intro');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('109405', 'spell_ultraxion_cosmetic_intro');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105900', 'spell_ultraxion_escense_of_dreams');

DELETE FROM `spell_script_names` WHERE (`spell_id`) IN ('103434', '103527', '103948', '105573', '105171');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('103434', 'spell_warlord_zonozz_disrupting_shadows_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('103527', 'spell_warlord_zonozz_void_diffusion_dmg');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('103948', 'spell_warlord_zonozz_disrupting_shadows_dmg');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105573', 'spell_yorsahj_the_unsleeping_digestive_acid_dmg');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105171', 'spell_yorsahj_the_unsleeping_deep_corruption_aoe');

DELETE FROM `spell_script_names` WHERE (`spell_id`) IN ('105287', '92203', '105314', '105316');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105287', 'spell_hagara_the_stormbinder_ice_lance_target');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('92203', 'spell_hagara_the_stormbinder_icicle_dmg');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105314', 'spell_hagara_the_stormbinder_icewave_dmg');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105316', 'spell_hagara_the_stormbinder_ice_lance_dmg');
