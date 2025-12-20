DELETE FROM `spell_proc` WHERE `SpellId` IN (207387);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(207387,0x00,107,0x00100000,0x00000000,0x00000000,0x00000000,0x4000,0x0,0x2,0x2,0x0,0x2,0x0,0,100,0,0); -- Painbringer

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_painbringer', 'spell_dh_painbringer_reduce_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(207387, 'spell_dh_painbringer'),
(212988, 'spell_dh_painbringer_reduce_damage');
