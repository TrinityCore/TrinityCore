DELETE FROM `spell_script_names` WHERE `spell_id`=200128;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(200128, 'spell_pri_trail_of_light');

DELETE FROM `spell_proc` WHERE `SpellId` IN (200128);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(200128,0x00,6,0x00001800,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x3,0x0,0x0,0,0,0,0); -- Trail of Light

