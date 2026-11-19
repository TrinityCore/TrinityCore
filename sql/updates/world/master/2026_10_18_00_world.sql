DELETE FROM `spell_proc` WHERE `SpellId` IN (1266329);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1266329,0x00,107,0x00080000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x1000,0x0,0x0,0,0,0,0); -- Demon Muzzle

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_demon_muzzle';
