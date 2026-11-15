DELETE FROM `spell_proc` WHERE `SpellId` IN (388933);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(388933,0x00,4,0x00100000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x4,0x0,0x0,0x0,0,0,0,0); -- Tenderize

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_tenderize');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(388933, 'spell_warr_tenderize');
