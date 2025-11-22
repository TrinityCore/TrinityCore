DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_idol_of_nzoth');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(373280, 'spell_pri_idol_of_nzoth');

DELETE FROM `spell_proc` WHERE `SpellId` IN (373280);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(373280,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Idol of N'Zoth
