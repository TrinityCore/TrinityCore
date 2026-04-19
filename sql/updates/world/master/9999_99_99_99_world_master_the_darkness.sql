DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_master_the_darkness');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47758, 'spell_pri_master_the_darkness'),
(47757, 'spell_pri_master_the_darkness');

DELETE FROM `spell_proc` WHERE `SpellId` IN (1253591);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1253591,0x00,6,0x00000001,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,1); -- Master the Darkness
