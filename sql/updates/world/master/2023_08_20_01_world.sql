DELETE FROM `spell_proc` WHERE `SpellId` IN (392302, 392303);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(392302,0x00,7,0x00000000,0x04000000,0x00000000,0x00000000,0x0,0x0,0x4,0x4,0x1,0x0,0x0,0,0,0,0), -- Power of the Archdruid
(392303,0x00,7,0x00000050,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x403,0x0,0x0,0,0,0,0); -- Power of the Archdruid

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_power_of_the_archdruid');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(392303, 'spell_dru_power_of_the_archdruid');
