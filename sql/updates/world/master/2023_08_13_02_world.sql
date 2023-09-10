DELETE FROM `spell_proc` WHERE `SpellId` IN (392315);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(392315,0x00,7,0x00000010,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x403,0x0,0x0,0,0,0,0); -- Luxuriant Soil

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_luxuriant_soil', 'spell_dru_germination');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(774, 'spell_dru_germination'),
(392315, 'spell_dru_luxuriant_soil');
