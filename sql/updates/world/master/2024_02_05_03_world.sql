DELETE FROM `spell_proc` WHERE `SpellId` IN (114255);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(114255,0x03,6,0x00000800,0x00000000,0x00000000,0x00000000,0x4000,0x0,0x2,0x2,0x403,0x10,0x0,0,0,0,0); -- Surge of Light (Proc)

DELETE FROM `spell_script_names` WHERE `spell_id` = 109186;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(109186, 'spell_pri_surge_of_light');
