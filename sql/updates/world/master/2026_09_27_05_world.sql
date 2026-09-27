DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_hun_windrunner_quiver';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(473523, 'spell_hun_windrunner_quiver');

DELETE FROM `spell_proc` WHERE `SpellId` IN (473523);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(473523,0x00,9,0x00000000,0x00000000,0x00000000,0x00400000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Windrunner Quiver
