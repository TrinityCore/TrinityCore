DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_surging_shots';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(391559, 'spell_hun_surging_shots');

DELETE FROM `spell_proc` WHERE `SpellId` IN (391559);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(391559,0x00,9,0x00020000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0); -- Surging Shots
