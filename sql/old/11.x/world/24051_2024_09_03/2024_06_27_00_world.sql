DELETE FROM `spell_proc` WHERE `SpellId` IN (77616);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(77616,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x7,0x1,0x0,0x0,0x0,0,0,0,0); -- Dark Simulacrum

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_dark_simulacrum','spell_dk_dark_simulacrum_buff');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(77606,'spell_dk_dark_simulacrum'),
(77616,'spell_dk_dark_simulacrum_buff');
