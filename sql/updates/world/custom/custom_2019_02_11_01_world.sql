UPDATE `creature_template` SET `ScriptName`= 'npc_pet_dk_army_of_the_dead_ghoul' WHERE `entry`= 24207;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dk_army_of_the_dead';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42650, 'spell_dk_army_of_the_dead');
