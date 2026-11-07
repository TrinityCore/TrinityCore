DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_precise_shots';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(260240,'spell_hun_precise_shots');

DELETE FROM `spell_proc` WHERE `SpellId` IN (260240,260242);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(260240,0x00,9,0x00020000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0), -- Precise Shots
(260242,0x00,9,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x18,0x0,0,0,0,0); -- Precise Shots
