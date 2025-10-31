DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_divine_procession');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(472361, 'spell_pri_divine_procession');

DELETE FROM `spell_proc` WHERE `SpellId` IN (472361);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(472361,0x00,6,0x00000080,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0); -- Divine Procession
