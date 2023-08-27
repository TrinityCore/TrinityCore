DELETE FROM `spell_proc` WHERE `SpellId` IN (392124);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(392124,0x00,7,0x00000000,0x04000000,0x00000000,0x00000000,0x0,0x0,0x4,0x4,0x1,0x0,0x0,0,0,0,0); -- Embrace of the Dream

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_embrace_of_the_dream', 'spell_dru_embrace_of_the_dream_effect');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(392124, 'spell_dru_embrace_of_the_dream'),
(392146, 'spell_dru_embrace_of_the_dream_effect');
