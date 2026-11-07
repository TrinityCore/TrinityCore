DELETE FROM `spell_proc` WHERE `SpellId` IN (16870);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(16870,0x00,7,0x00000000,0x00000000,0x00000000,0x00000000,0x4000,0x0,0x2,0x2,0x0,0x18,0x0,0,0,0,0); -- Clearcasting

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dru_omen_of_clarity_restoration';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(113043, 'spell_dru_omen_of_clarity_restoration');
