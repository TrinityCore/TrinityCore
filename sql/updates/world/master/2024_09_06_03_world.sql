DELETE FROM `spell_proc` WHERE `SpellId` IN (452999);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(452999,0x0,5,0x00000002,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Siphon Life

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_siphon_life';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(452999, 'spell_warl_siphon_life');
