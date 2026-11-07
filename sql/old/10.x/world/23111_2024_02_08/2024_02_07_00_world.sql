DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_heavens_wrath';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(421558,'spell_pri_heavens_wrath');

DELETE FROM `spell_proc` WHERE `SpellId` IN (421558);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(421558,0x00,6,0x00000000,0x00018000,0x00000000,0x00000000,0x0,0x0,0x3,0x2,0x403,0x0,0x0,0,0,0,0); -- Heaven's Wrath
