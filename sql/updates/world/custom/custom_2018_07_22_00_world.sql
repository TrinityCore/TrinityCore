DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_flame_warden_lava_eruption',
'spell_omega_stance_spider_effect');

DELETE FROM `achievement_criteria_data` WHERE `ScriptName`= 'achievement_hate_that_song';

DELETE FROM `spell_proc` WHERE `SpellId` IN (62600);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(62600, 0, 0, 0, 0, 0, 1, 2, 2, 32, 0, 0, 50);
