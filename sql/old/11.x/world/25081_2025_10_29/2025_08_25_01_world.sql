DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_master_marksman';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(260309,'spell_hun_master_marksman');

DELETE FROM `spell_proc` WHERE `SpellId` IN (260309);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(260309,0x00,9,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x2,0x0,0x0,0,0,0,0); -- Master Marksman
