DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_chaos_theory';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_chaos_theory_drop_charge';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(210152, 'spell_dh_chaos_theory'),
(188499, 'spell_dh_chaos_theory'),
(390195, 'spell_dh_chaos_theory_drop_charge');

DELETE FROM `spell_proc` WHERE `SpellId` IN (390195);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390195,0x00,107,0x00004040,0x00040000,0x00000000,0x80000000,0x1010,0x0,0x0,0x2,0x0,0xA,0x0,0,100,0,1); -- Chaos Theory
