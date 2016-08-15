-- ARGENT SQUIRE/GRUNTLING
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_mounting_check';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUE
(67039, 'spell_gen_mounting_check');
 
UPDATE `creature_template` SET `ScriptName` = 'npc_argent_squire' WHERE `entry` IN (33238, 33239);
 
DELETE FROM `spell_linked_spell` WHERE `spell_effect` = 67401;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`, `type`, `comment`) VALUES
(-67368, 67401, 0, 'Argent Squire - Bank'),
(-67377, 67401, 0, 'Argent Squire - Shop'),
(-67376, 67401, 0, 'Argent Squire - Mail');
