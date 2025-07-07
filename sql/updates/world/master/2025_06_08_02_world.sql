DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_enrage_proc', 'spell_warr_rampage_enrage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`)  VALUES
(184361, 'spell_warr_enrage_proc');

DELETE FROM `spell_proc` WHERE `SpellId` IN (184361);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(184361,0x00,4,0x00000000,0x00000400,0x00000000,0x08000000,0x0,0x0,0x0,0x4,0x0,0x0,0x0,0,0,0,0); -- Enrage
