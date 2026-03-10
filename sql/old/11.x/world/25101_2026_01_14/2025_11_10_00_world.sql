DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_flame_accelerant';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(453282, 'spell_mage_flame_accelerant');

DELETE FROM `spell_proc` WHERE `SpellId`=453283;
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(453283,0x00,3,0x00400005,0x00000000,0x00000000,0x00000000,0x10000,0x0,0x0,0x1,0x0,0x8,0x0,0,101,0,1); -- Flame Accelerant
