DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_atonement','spell_pri_atonement_triggered');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(81749,'spell_pri_atonement'),
(194384,'spell_pri_atonement_triggered');
