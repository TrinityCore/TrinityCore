DELETE FROM `spell_script_names` WHERE `spell_id` IN (114239);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(114239, 'spell_pri_phantasm');

DELETE FROM `spell_proc` WHERE `SpellId` IN (108942);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(108942,0x00,6,0x00004000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x4,0x2,0x0,0x0,0x0,0,0,0,0); -- Phantasm
