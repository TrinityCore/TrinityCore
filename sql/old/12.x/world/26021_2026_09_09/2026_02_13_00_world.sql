DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_elunes_favored', 'spell_dru_elunes_favored_proc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(5487, 'spell_dru_elunes_favored'),
(370588, 'spell_dru_elunes_favored_proc');

DELETE FROM `spell_proc` WHERE `SpellId` IN (370588);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(370588,0x40,7,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Elune's Favored
