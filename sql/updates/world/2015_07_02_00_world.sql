UPDATE `creature_template` SET `ScriptName`='npc_flesh_eating_insect' WHERE  `entry`=37782;
UPDATE `creature_template` SET `ScriptName`='npc_putricide_trap' WHERE  `entry`=38879;
DELETE FROM `spell_script_names` where `spell_id` IN (70484,70485,70475);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(70484, 'spell_icc_summon_plagued_insect'),
(70475, 'spell_icc_giant_swarm');
