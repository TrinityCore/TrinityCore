DELETE FROM `spell_proc` WHERE `SpellId` IN (1239524);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1239524,0x00,107,0x00000000,0x00000000,0x00000000,0x00000040,0x0,0x0,0x0,0x1,0x0,0x10,0x0,0,0,0,0); -- Eradicate

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_eradicate_enabler';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(473728, 'spell_dh_eradicate_enabler');
