DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_matted_fur_absorb');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(385787, 'spell_dru_matted_fur_absorb');

DELETE FROM `spell_proc` WHERE `SpellId` IN (385786);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(385786,0x00,7,0x00000000,0x00040000,0x00000080,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Matted Fur
