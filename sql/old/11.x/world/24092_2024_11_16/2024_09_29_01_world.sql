DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_natures_grace_eclipse', 'spell_dru_natures_grace');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(48517, 'spell_dru_natures_grace_eclipse'),
(48518, 'spell_dru_natures_grace_eclipse'),
(450347, 'spell_dru_natures_grace');

DELETE FROM `spell_proc` WHERE `SpellId` IN (450346);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(450346,0x00,7,0x00000005,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x1,0x0,0x18,0x0,0,0,0,0); -- Dreamstate
