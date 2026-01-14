DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_mental_decay';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(375994,'spell_pri_mental_decay');

DELETE FROM `spell_proc` WHERE `SpellId` IN (375994);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(375994,0x00,6,0x00000000,0x00000000,0x00000040,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Mental Decay
