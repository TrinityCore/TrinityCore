DELETE FROM `spell_proc` WHERE `SpellId` IN (53576,54149);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(53576,0x00,10,0x00200000,0x00010000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x2,0x0,0x0,0,0,0,0), -- Infusion of Light (proc from holy shock)
(54149,0x00,10,0x40000000,0x00000000,0x00000400,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Infusion of Light (buff)

DELETE FROM `spell_script_names` WHERE `spell_id`=54149 AND `ScriptName`='spell_pal_infusion_of_light';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(54149, 'spell_pal_infusion_of_light');
