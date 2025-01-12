DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warl_backdraft';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(17962, 'spell_warl_backdraft');

DELETE FROM `spell_proc` WHERE `SpellId` IN (117828);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(117828,0x00,5,0x00000000,0x00002040,0x00000002,0x00000000,0x0,0x0,0x1,0x2,0x0,0x18,0x0,0,0,0,0); -- Backdraft
