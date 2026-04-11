DELETE FROM `spell_proc` WHERE `SpellId` IN (390705,390706,390707);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390705,0x22,6,0x00000000,0x00000000,0x00000000,0x00000000,0x11000,0x0,0x1,0x2,0x0,0x0,0x0,0,101,0,0), -- Twilight Equilibrium
(390706,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x8,0x0,0,0,0,0), -- Twilight Equilibrium
(390707,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x8,0x0,0,0,0,0); -- Twilight Equilibrium

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_twilight_equilibrium','spell_pri_twilight_equilibrium_shadow_word_pain');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(390705, 'spell_pri_twilight_equilibrium'),
(589, 'spell_pri_twilight_equilibrium_shadow_word_pain');
