DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_empyreal_blaze', 'spell_pri_empyreal_blaze_extend');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(372616, 'spell_pri_empyreal_blaze'),
(14914, 'spell_pri_empyreal_blaze_extend');

DELETE FROM `spell_proc` WHERE `SpellId` IN (372617);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(372617,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x10,0x0,0,0,0,0); -- Empyreal Blaze
