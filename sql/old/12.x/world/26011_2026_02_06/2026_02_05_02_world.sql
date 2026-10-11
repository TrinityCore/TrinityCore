DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_guardian_of_elune_healing');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(22842, 'spell_dru_guardian_of_elune_healing');

DELETE FROM `spell_proc` WHERE `SpellId` IN (155578);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(155578,0x00,7,0x00000000,0x00000040,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x403,0x0,0x0,0,0,0,0); -- Guardian of Elune

DELETE FROM `spell_proc` WHERE `SpellId` IN (213680);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(213680,0x00,7,0x00000000,0x40000000,0x00004000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Guardian of Elune
