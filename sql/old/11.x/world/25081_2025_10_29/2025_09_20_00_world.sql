DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_lock_and_load';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(194595,'spell_hun_lock_and_load');

DELETE FROM `spell_proc` WHERE `SpellId` IN (194594);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(194594,0x00,9,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x4,0x0,0x0,0x0,0x8,0x0,0,0,0,0); -- Lock and Load
