DELETE FROM `spell_proc` WHERE `SpellId` IN (389718);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(389718,0x00,107,0x00000000,0x00000000,0x00000002,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Cycle of Binding

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_cycle_of_binding';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(389718,'spell_dh_cycle_of_binding');
