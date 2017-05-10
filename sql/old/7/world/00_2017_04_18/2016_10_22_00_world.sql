DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_earthen_rage_passive','spell_sha_earthen_rage_proc_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(170374,'spell_sha_earthen_rage_passive'),
(170377,'spell_sha_earthen_rage_proc_aura');
