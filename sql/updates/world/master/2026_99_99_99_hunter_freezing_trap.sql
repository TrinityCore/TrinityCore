UPDATE `areatrigger_create_properties` SET `ScriptName`='areatrigger_hun_freezing_trap' WHERE `Id`=4424 AND `IsCustom`=0;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_freezing_trap_targeting_spell';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(177419, 'spell_hun_freezing_trap_targeting_spell');
