DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_blizzard_damage';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(190357,'spell_mage_blizzard_damage');

UPDATE `areatrigger_create_properties` SET `TimeToTargetScale`=0, `ScriptName`='areatrigger_mage_blizzard', `VerifiedBuild`=42010 WHERE `Id`=4658; -- SpellId : 190356

