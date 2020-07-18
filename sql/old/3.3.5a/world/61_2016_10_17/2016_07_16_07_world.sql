-- enable 2 new spell scripts: spell_hallow_end_candy & spell_hallow_end_candy_pirate
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_hallow_end_candy','spell_hallow_end_candy_pirate');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(24930,'spell_hallow_end_candy'),
(24926,'spell_hallow_end_candy_pirate');
