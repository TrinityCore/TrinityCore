DELETE FROM `spell_proc` WHERE `SpellId` IN (394058);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(394058,0x00,7,0x00000005,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Astral Smolder

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dru_astral_smolder';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(394058, 'spell_dru_astral_smolder');
