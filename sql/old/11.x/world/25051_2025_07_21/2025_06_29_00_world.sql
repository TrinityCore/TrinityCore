DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_meteor';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(153561, 'spell_mage_meteor');

UPDATE `areatrigger_create_properties` SET `ScriptName`='at_mage_meteor' WHERE `Id`=3467;
UPDATE `areatrigger_create_properties` SET `ScriptName`='at_mage_meteor_burn' WHERE `Id`=1712;
