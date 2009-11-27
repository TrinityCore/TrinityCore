update creature_template set ScriptName = 'npc_iruk' where entry = 26219;
UPDATE creature_template SET ScriptName = 'npc_corastrasza' WHERE entry = 32548;

DELETE FROM `spell_script_target` WHERE entry = 61245;
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(61245, 1, 32535);
