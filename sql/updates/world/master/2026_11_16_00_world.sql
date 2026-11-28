DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_mastery_harmony','spell_pal_mastery_lightbringer','spell_pri_mastery_grace','spell_evo_mastery_life_binder');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77495, 'spell_dru_mastery_harmony'),
(183997, 'spell_pal_mastery_lightbringer'),
(271534, 'spell_pri_mastery_grace'),
(363510, 'spell_evo_mastery_life_binder');
