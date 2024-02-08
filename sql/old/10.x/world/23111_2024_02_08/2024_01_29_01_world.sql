DELETE FROM `spell_proc` WHERE `SpellId` IN (390615);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390615,0x24,6,0x00008000,0x00000000,0x00000000,0x00000010,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0); -- From Darkness Comes Light

DELETE FROM `spell_proc` WHERE `SpellId` IN (390617);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390617,0x02,6,0x00000800,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x403,0x0,0x0,0,0,0,1); -- From Darkness Comes Light

DELETE FROM `spell_script_names` WHERE `spell_id` IN (390615);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(390615, 'spell_pri_from_darkness_comes_light');
