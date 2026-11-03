DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dh_infernal_armor';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(258920, 'spell_dh_infernal_armor'),
(427912, 'spell_dh_infernal_armor'),
(427913, 'spell_dh_infernal_armor'),
(427914, 'spell_dh_infernal_armor'),
(427915, 'spell_dh_infernal_armor'),
(1241937, 'spell_dh_infernal_armor');

DELETE FROM `spell_proc` WHERE `SpellId` IN (258920,427912,427913,427914,427915,1241937);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(258920,0x00,107,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x403,0x0,0x0,0,0,0,0), -- Immolation Aura
(427912,0x00,107,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x403,0x0,0x0,0,0,0,0), -- Immolation Aura
(427913,0x00,107,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x403,0x0,0x0,0,0,0,0), -- Immolation Aura
(427914,0x00,107,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x403,0x0,0x0,0,0,0,0), -- Immolation Aura
(427915,0x00,107,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x403,0x0,0x0,0,0,0,0), -- Immolation Aura
(1241937,0x00,107,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x403,0x0,0x0,0,0,0,0); -- Soul Immolation
