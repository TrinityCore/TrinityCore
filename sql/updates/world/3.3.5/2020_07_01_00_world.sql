-- 
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_war_intervene','spell_warr_intervene');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(3411,'spell_warr_intervene');
