-- Power Strikes
DELETE FROM `spell_proc` WHERE `SpellId` IN (129914);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(129914,0x00,53,0x00000400,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x10,0x0,0,0,0,0); -- Power Strikes (consume procc)

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_monk_power_strike_periodic', 'spell_monk_power_strike_proc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(121817, 'spell_monk_power_strike_periodic'),
(129914, 'spell_monk_power_strike_proc');
