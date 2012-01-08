-- Paralyze -- Filter targets -- cast only on sacrafacing target
DELETE FROM `spell_script_names` WHERE `spell_id` = 48278;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(48278, 'spell_paralyze_pinnacle');
