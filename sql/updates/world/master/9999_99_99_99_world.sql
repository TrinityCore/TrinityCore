DELETE FROM `spell_proc` WHERE `SpellId` IN (405554);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(405554, 0x00, 6, 0x00000000, 0x00000020, 0x00000000, 0x00400000, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (33076, 411097, 41635, 33110, 405554);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(33076, 'spell_pri_prayer_of_mending_dummy'),
(411097, 'spell_pri_prayer_of_mending_dummy'),
(41635, 'spell_pri_prayer_of_mending'),
(33110, 'spell_pri_prayer_of_mending_heal'),
(405554, 'spell_pri_holy_10_1_class_set_2pc');
