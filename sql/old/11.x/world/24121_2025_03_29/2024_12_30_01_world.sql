DELETE FROM `spell_proc` WHERE `SpellId` IN (390212);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390212,0x00,107,0x00001000,0x00000040,0x00000000,0x00000000,0x0,0x0,0x1,0x1,0x0,0x12,0x0,0,0,0,0); -- Restless Hunter

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_restless_hunter';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(162264, 'spell_dh_restless_hunter');
