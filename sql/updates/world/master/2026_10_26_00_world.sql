DELETE FROM `spell_proc` WHERE `SpellId` IN (462762);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(462762,0x00,11,0x80000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Encasing Cold

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_encasing_cold';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(462762, 'spell_sha_encasing_cold');
