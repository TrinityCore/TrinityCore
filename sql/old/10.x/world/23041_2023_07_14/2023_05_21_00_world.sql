DELETE FROM `spell_script_names` WHERE `spell_id`= 389306;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(389306,'spell_warr_critical_thinking');

DELETE FROM `spell_proc` WHERE `SpellId` IN (389306);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(389306,0x00,4,0x20000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x4,0x2,0x1,0x4,0x0,0,0,0,0); -- Critical Thinking
