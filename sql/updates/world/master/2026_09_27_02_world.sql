DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_hun_quick_draw', 'spell_hun_quick_draw_speed');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(459794, 'spell_hun_quick_draw'),
(1279347, 'spell_hun_quick_draw_speed');

DELETE FROM `spell_proc` WHERE `SpellId` IN (459794);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(459794,0x00,9,0x00020000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Quick Draw
