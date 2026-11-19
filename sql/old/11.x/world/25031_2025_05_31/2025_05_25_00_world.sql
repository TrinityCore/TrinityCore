DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_rog_shot_in_the_dark', 'spell_rog_shot_in_the_dark_buff');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1784, 'spell_rog_shot_in_the_dark'),
(185313, 'spell_rog_shot_in_the_dark'),
(185422, 'spell_rog_shot_in_the_dark_buff'),
(158185, 'spell_rog_shot_in_the_dark_buff');

DELETE FROM `spell_proc` WHERE `SpellId` IN (257506);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(257506,0x00,8,0x00000400,0x00000000,0x00000000,0x00000000,0x0,0x0,0x4,0x2,0x0,0x10,0x0,0,0,0,0); -- Shot in the Dark
