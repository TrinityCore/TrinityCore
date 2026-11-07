DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_harsh_discipline';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(194509,'spell_pri_harsh_discipline');

DELETE FROM `spell_proc` WHERE `SpellId` IN (373183);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(373183,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x1A,0x0,0,0,0,0); -- Harsh Discipline
