-- 
DELETE FROM `spell_proc` WHERE `SpellId` IN (383103);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(383103,0x00,4,0x00080000,0x00000000,0x00400000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0); -- Fueled by Violence

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warr_fueled_by_violence';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(383103, 'spell_warr_fueled_by_violence');

