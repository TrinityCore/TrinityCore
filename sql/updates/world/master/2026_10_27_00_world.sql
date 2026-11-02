DELETE FROM `spell_proc` WHERE `SpellId` IN (355630);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(355630,0x00,11,0x00000000,0x08000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x1000,0x0,0x0,0,0,0,0); -- Windveil

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_windveil';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(355630, 'spell_sha_windveil');
