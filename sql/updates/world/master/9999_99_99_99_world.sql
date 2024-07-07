<<<<<<< HEAD
DELETE FROM `spell_proc` WHERE `SpellId` IN (392507);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(392507,0x00,6,0x00008000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0); -- Deathspeaker

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_deathspeaker_consumer');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32379, 'spell_pri_deathspeaker_consumer');
=======
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_shadow_word_death');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32379, 'spell_pri_shadow_word_death');
>>>>>>> 2553a65b115700d8d0e357f44c09cb6b50c0d993
