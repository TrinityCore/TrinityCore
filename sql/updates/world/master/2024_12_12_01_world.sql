DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_felblade', 'spell_dh_felblade_charge','spell_dh_felblade_cooldown_reset_proc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(232893, 'spell_dh_felblade'),
(213241, 'spell_dh_felblade_charge'),
(203557, 'spell_dh_felblade_cooldown_reset_proc'),
(236167, 'spell_dh_felblade_cooldown_reset_proc');

DELETE FROM `spell_proc` WHERE `SpellId` IN (203557,236167,204497);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(203557,0x00,107,0x00400000,0x00000000,0x00000020,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0), -- Felblade
(236167,0x00,107,0x00000001,0x00001000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x2,0x0,0,0,0,0), -- Felblade
(204497,0x00,107,0x40000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,1); -- Felblade
