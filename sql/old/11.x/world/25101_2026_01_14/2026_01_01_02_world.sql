DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_voice_of_harmony';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(390994, 'spell_pri_voice_of_harmony');

DELETE FROM `spell_proc` WHERE `SpellId` IN (390994);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390994,0x00,6,0x00100000,0x00000000,0x00008000,0x00404040,0x0,0x4,0x0,0x0,0x0,0x0,0x0,0,100,0,0); -- Voice of Harmony
