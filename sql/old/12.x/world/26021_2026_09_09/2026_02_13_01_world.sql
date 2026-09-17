DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warr_pain_and_gain_heal';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(382551,'spell_warr_pain_and_gain_heal');

DELETE FROM `spell_proc` WHERE `SpellId`=382549;
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(382549,0x00,4,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0,0,0,0); -- Pain and Gain
