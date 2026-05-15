DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_moonless_night');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(400278, 'spell_dru_moonless_night');

DELETE FROM `spell_proc` WHERE `SpellId` IN (400278);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(400278,0x01,7,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Moonless Night
