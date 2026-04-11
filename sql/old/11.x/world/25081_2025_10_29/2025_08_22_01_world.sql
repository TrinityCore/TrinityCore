DELETE FROM `spell_proc` WHERE `SpellId` IN (377210);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(377210,0x00,7,0x00000800,0x00000000,0x08000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Ursoc's Fury

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dru_ursocs_fury';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(377210,'spell_dru_ursocs_fury');
