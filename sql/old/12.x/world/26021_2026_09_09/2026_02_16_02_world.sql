DELETE FROM `spell_proc` WHERE `SpellId` IN (184783,199854);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(184783,0x00,4,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0), -- Tactician
(199854,0x00,4,0x00000004,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Tactician

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warr_tactician';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(184783,'spell_warr_tactician');
