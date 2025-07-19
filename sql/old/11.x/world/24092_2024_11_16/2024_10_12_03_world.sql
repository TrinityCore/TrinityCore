DELETE FROM `spell_proc` WHERE `SpellId` IN (194878);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(194878,0x00,15,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Icy Talons

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_icy_talons','spell_dk_icy_talons_buff');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(194878, 'spell_dk_icy_talons'),
(194879, 'spell_dk_icy_talons_buff');
