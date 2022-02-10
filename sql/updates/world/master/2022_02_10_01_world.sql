DELETE FROM `spell_proc` WHERE `SpellId` IN (248033);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(248033,0x00,10,0x00000000,0x00000000,0x00044000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Awakening

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_awakening';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(248033,'spell_pal_awakening');

DELETE FROM `spell_group` WHERE `id`=1107;
DELETE FROM `spell_group_stack_rules` WHERE `group_id`=1107;
