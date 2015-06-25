-- ethereal sphere heroic version
UPDATE `creature_template` SET `scriptname` = 'npc_ethereal_sphere' WHERE `entry` = 32582;
-- spell script names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (58694,54102,54164,54396,54438,54442,57804,59523,59524,61337);
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES 
(54102,'spell_xevozz_summon_ethereal_sphere'),
(54164,'spell_xevozz_summon_players'),
(54396,'spell_moragg_optic_link'),
(54438,'spell_moragg_ray_of_pain'),
(54442,'spell_moragg_ray_of_suffering'),
(57804,'spell_crystal_activation'),
(59523,'spell_moragg_ray_of_pain'),
(59524,'spell_moragg_ray_of_suffering'),
(61337,'spell_xevozz_summon_ethereal_sphere');
--  arcane vacuum summon effect
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 58694;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(58694,21150,1,'Cyanigosa: Arcane Vacuum teleport effect');
