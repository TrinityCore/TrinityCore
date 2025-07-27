--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sunwell_plateau_cataclysm_breath', 'spell_arcatraz_chaos_breath', 'spell_arcatraz_death_count');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46292, 'spell_sunwell_plateau_cataclysm_breath'),
(36677, 'spell_arcatraz_chaos_breath'),
(36660, 'spell_arcatraz_death_count'),
(38820, 'spell_arcatraz_death_count');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 20867 AND `source_type` = 0 AND `id` IN (8,9);
