DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_deaths_torment');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(1240364,'spell_pri_deaths_torment');

DELETE FROM `spell_proc` WHERE `SpellId` IN (1240364);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1240364,0x00,6,0x00000000,0x00000002,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Death's Torment
