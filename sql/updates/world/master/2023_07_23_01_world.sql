DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_rog_rupture');
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_rog_rupture_aura');
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_rog_slice_and_dice');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(1943,'spell_rog_rupture'),
(1943,'spell_rog_rupture_aura'),
(315496,'spell_rog_slice_and_dice');
