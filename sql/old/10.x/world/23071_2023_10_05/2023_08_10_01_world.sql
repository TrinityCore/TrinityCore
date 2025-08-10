DELETE FROM `spell_proc` WHERE `SpellId` IN (414553, 409479);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(414553,0x00,6,0x10200400,0x00000000,0x00000020,0x00000000,0x0,0x0,0x3,0x2,0x403,0x0,0x0,0,0,0,0), -- Epiphany
(409479,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x8,0x0,0,0,0,1); -- Inspired Word

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_prayer_of_mending_heal', 'spell_pri_benediction', 'spell_pri_divine_service', 'spell_pri_focused_mending', 
'spell_pri_epiphany', 'spell_pri_holy_10_1_class_set_2pc_chooser', 'spell_pri_holy_10_1_class_set_4pc', 'spell_pri_holy_10_1_class_set_4pc_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(33110, 'spell_pri_benediction'), -- Benediction
(33110, 'spell_pri_divine_service'), -- Divine Service
(33110, 'spell_pri_focused_mending'), -- Focused Mending
(414553, 'spell_pri_epiphany'), -- Epiphany
(411097, 'spell_pri_holy_10_1_class_set_2pc_chooser'), -- Priest Holy 10.1 Class Set 2pc (Chooser)
(155793, 'spell_pri_holy_10_1_class_set_4pc'), -- Priest Holy 10.1 Class Set 4pc
(41635, 'spell_pri_holy_10_1_class_set_4pc_aura'); -- Priest Holy 10.1 Class Set 4pc
