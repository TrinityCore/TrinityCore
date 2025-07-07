DELETE FROM `spell_proc` WHERE `SpellId` IN (195621);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(195621,0x00,15,0x00000000,0x04000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Frost Fever

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_frost_fever_proc';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(195621, 'spell_dk_frost_fever_proc');
