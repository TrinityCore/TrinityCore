DELETE FROM `spell_proc` WHERE `SpellId` IN (343173);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(343173,0x00,8,0x2000040C,0x00000000,0x00000808,0x80002100,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Premeditation

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_rog_premeditation', 'spell_rog_shadow_focus', 'spell_rog_premeditation_proc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1784, 'spell_rog_premeditation'),
(343173, 'spell_rog_premeditation_proc'),
(1784, 'spell_rog_shadow_focus'),
(185313, 'spell_rog_shadow_focus');
