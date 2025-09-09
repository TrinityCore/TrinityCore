DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_cold_steel_hot_blood_bloodthirst';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(23881, 'spell_warr_cold_steel_hot_blood_bloodthirst'),
(335096, 'spell_warr_cold_steel_hot_blood_bloodthirst');

DELETE FROM `spell_proc` WHERE `SpellId` IN (383959);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(383959,0x01,4,0x00000000,0x00000400,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x2,0x0,0x0,0,0,0,0); -- Cold Steel, Hot Blood
