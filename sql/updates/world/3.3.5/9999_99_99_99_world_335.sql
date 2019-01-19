DELETE FROM `spell_script_names` WHERE `spell_id`= 52267;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_deliver_stolen_horse';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52264, 'spell_deliver_stolen_horse');