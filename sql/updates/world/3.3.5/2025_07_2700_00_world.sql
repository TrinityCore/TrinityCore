--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sunwell_plateau_cataclysm_breath', 'spell_arcatraz_chaos_breath');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46292, 'spell_sunwell_plateau_cataclysm_breath'),
(36677, 'spell_arcatraz_chaos_breath');
