DELETE FROM `spell_proc` WHERE `SpellId` IN (438590);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_keep_your_feet_on_the_ground');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(438590, 'spell_warr_keep_your_feet_on_the_ground');
