DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_earthquake_tick';

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(77478, 'spell_sha_earthquake_tick'); -- Earthquake

UPDATE `areatrigger_create_properties` SET `ScriptName`='areatrigger_sha_earthquake' WHERE `Id`=3691;

DELETE FROM `spell_proc` WHERE `SpellId` IN (273221);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(273221,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Aftershock
