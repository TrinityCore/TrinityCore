DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_insidious_ire');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(373212, 'spell_pri_insidious_ire');

DELETE FROM `spell_proc` WHERE `SpellId` IN (373212);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(373212,0x00,6,0x00008000,0x00000400,0x00800000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Insidious Ire
