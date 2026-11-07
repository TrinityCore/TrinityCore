DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_improved_scorch';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(383604, 'spell_mage_improved_scorch');

DELETE FROM `spell_proc` WHERE `SpellId` IN (383604);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(383604,0x00,3,0x00000010,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Improved Scorch
