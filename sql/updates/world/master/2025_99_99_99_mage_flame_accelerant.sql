DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_flame_accelerant', 'spell_mage_flame_accelerant_proc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(453282, 'spell_mage_flame_accelerant'),
(453283, 'spell_mage_flame_accelerant_proc');

DELETE FROM `spell_proc` WHERE `SpellId` IN (453283);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(453283,0x04,3,0x00400005,0x00000000,0x00000000,0x00000000,0x10000,0x0,0x1,0x2,0x0,0x12,0x0,0,101,0,1); -- Flame Accelerant
