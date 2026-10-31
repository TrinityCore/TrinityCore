DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_hungering_slash', 'spell_dh_hungering_slash_enabler', 'spell_dh_hungering_slash_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1239123, 'spell_dh_hungering_slash'),
(1246167, 'spell_dh_hungering_slash_enabler'),
(1245412, 'spell_dh_hungering_slash_enabler'),
(1239127, 'spell_dh_hungering_slash_damage');

DELETE FROM `spell_proc` WHERE `SpellId` IN (1223157);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1223157,0x00,107,0x00000008,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x10,0x0,0,0,0,0); -- Voidstep
