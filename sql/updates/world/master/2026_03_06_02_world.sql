DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_galactic_guardian_moonfire','spell_dru_lunar_wrath');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(164812,'spell_dru_galactic_guardian_moonfire'),
(1253600,'spell_dru_lunar_wrath');

DELETE FROM `spell_proc` WHERE `SpellId` IN (203964,1253600);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(203964,0x00,7,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0), -- Galactic Guardian
(1253600,0x00,7,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x10,0x0,0,0,0,0); -- Lunar Wrath
