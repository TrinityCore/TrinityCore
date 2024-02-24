DELETE FROM `spell_proc` WHERE `SpellId` IN (193063);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(193063,0x02,6,0x00000800,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x403,0x0,0x0,0,0,0,0); -- Protective Light

DELETE FROM `spell_script_names` WHERE `spell_id` IN (193063);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(193063, 'spell_pri_protective_light');
