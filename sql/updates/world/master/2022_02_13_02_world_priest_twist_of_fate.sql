DELETE FROM `spell_proc` WHERE `SpellId` IN (109142,265259);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(109142,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0), -- Twist of Fate (Shadow)
(265259,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x0,0x0,0x0,0,0,0,0); -- Twist of Fate (Discipline)

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pri_twist_of_fate';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(109142, 'spell_pri_twist_of_fate'),
(265259, 'spell_pri_twist_of_fate');
