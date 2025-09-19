DELETE FROM `spell_proc` WHERE `SpellId` IN (157642);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(157642,0x0,3,0x00000001,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Pyrotechnics

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_pyrotechnics';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(157642, 'spell_mage_pyrotechnics');
