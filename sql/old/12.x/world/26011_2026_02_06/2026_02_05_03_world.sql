DELETE FROM `spell_proc` WHERE `SpellId` IN (395446);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(395446,0x00,107,0x00000000,0x00000002,0x00000000,0x00000000,0x0,0x0,0x5,0x2,0x403,0x0,0x0,0,0,0,0); -- Soul Sigils

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_soul_sigils';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(395446, 'spell_dh_soul_sigils');
