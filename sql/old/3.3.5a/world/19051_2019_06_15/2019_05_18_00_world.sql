-- 
DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_gen_charmed_unit_spell_cooldown" AND `spell_id` IN (37917,37918,37919);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37917, "spell_gen_charmed_unit_spell_cooldown"),
(37918, "spell_gen_charmed_unit_spell_cooldown"),
(37919, "spell_gen_charmed_unit_spell_cooldown");
