DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_evo_fire_breath','spell_evo_fire_breath_damage','spell_evo_scouring_flame');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(357208,'spell_evo_fire_breath'),
(382266,'spell_evo_fire_breath'),
(357209,'spell_evo_fire_breath_damage'),
(357209,'spell_evo_scouring_flame');
