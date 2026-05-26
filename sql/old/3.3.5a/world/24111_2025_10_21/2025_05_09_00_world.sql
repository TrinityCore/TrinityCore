--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_gen_cancel_aura' WHERE `ScriptName` = 'spell_love_is_in_the_air_fragrant_air_analysis'; -- 70192
UPDATE `spell_script_names` SET `ScriptName` = 'spell_gen_cancel_aura' WHERE `ScriptName` = 'spell_storm_peaks_remove_collapsing_cave_aura'; -- 55693
UPDATE `spell_script_names` SET `ScriptName` = 'spell_gen_cancel_aura' WHERE `ScriptName` = 'spell_deathbringer_remove_marks'; -- 72257

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_cancel_aura' AND `spell_id` IN (45604,56923,59556,60654,69171,69298,70079,69098);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45604, 'spell_gen_cancel_aura'),
(56923, 'spell_gen_cancel_aura'),
(59556, 'spell_gen_cancel_aura'),
(60654, 'spell_gen_cancel_aura'),
(69171, 'spell_gen_cancel_aura'),
(69298, 'spell_gen_cancel_aura'),
(70079, 'spell_gen_cancel_aura'),
(69098, 'spell_gen_cancel_aura');
