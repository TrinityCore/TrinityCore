DELETE FROM `spell_proc` WHERE `SpellId` IN (335077);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(335077,0x00,4,0x00000000,0x00000000,0x00000000,0x08000000,0x0,0x0,0x0,0x4,0x0,0x0,0x0,0,0,0,0); -- Frenzy

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_frenzy_rampage', 'spell_warr_frenzy');
