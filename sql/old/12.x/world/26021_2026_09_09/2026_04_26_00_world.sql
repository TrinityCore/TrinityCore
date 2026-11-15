DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_moment_of_craving';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(473728, 'spell_dh_moment_of_craving');

DELETE FROM `spell_proc` WHERE `SpellId` IN (1238495);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1238495,0x00,107,0x00000000,0x00000000,0x00000000,0x00000008,0x0,0x0,0x1,0x2,0x0,0x12,0x0,0,0,0,0); -- Moment of Craving
