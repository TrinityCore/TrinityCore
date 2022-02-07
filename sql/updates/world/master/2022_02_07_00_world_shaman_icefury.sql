DELETE FROM `spell_proc` WHERE `SpellId` IN (210714);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(210714,0x00,11,0x80000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x0,0x8,0x0,0,0,0,0); -- Icefury

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_icefury';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(210714,'spell_sha_icefury');
