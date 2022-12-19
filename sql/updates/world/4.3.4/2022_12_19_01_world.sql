DELETE FROM `spell_proc` WHERE `SpellId`= 85646;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask2`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(85646, 10, 0x4000, 2, 2);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_guarded_by_the_light';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(85646, 'spell_pal_guarded_by_the_light');
