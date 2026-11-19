DELETE FROM `spell_proc` WHERE `SpellId` IN (215768);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(215768,0x02,6,0x00000000,0x00800000,0x00000080,0x00000000,0x0,0x0,0x4,0x2,0x403,0x0,0x0,0,0,0,0); -- Blaze of Light

DELETE FROM `spell_script_names` WHERE `spell_id` IN (215768);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(215768, 'spell_pri_blaze_of_light');
