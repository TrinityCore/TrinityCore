DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dru_blood_in_the_water',
'spell_dru_blood_in_the_water_script');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-80318, 'spell_dru_blood_in_the_water'),
(80863, 'spell_dru_blood_in_the_water_script');

DELETE FROM `spell_proc` WHERE `SpellId`= -80318;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Chance`) VALUES
(-80318, 7, 0x00800000, 0x00000010, 1, 2, 0, 100);
