DELETE FROM `spell_proc` WHERE `SpellId` IN (372152);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(372152,0x00,7,0x00000040,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x10,0x0,0,0,0,0); -- Dream of Cenarius

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dru_dream_of_cenarius_guardian';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(372119,'spell_dru_dream_of_cenarius_guardian');
