--
UPDATE `creature_template` SET `speed_walk` = 1, `minlevel` = 65, `maxlevel` = 65, `unit_flags` = 33554944 WHERE `entry` = 18225;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 18225;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(18225,1,0,1,0,0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 18225 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18225,0,0,0,11,0,100,0,0,0,0,0,0,11,31959,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fire Bomb Target - On Spawn - Cast 'Fire Bomb Target Summon Trigger'");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_nagrand_fire_bomb_target_summon_trigger','spell_nagrand_fire_bomb_target_summon_effect','spell_nagrand_fire_bomb_damage_missile');
DELETE FROM `spell_script_names` WHERE `spell_id` = 34658 AND `ScriptName` = 'spell_gen_despawn_aura';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(31959,'spell_nagrand_fire_bomb_target_summon_trigger'),
(31960,'spell_nagrand_fire_bomb_target_summon_effect'),
(31961,'spell_nagrand_fire_bomb_damage_missile'),
(34658,'spell_gen_despawn_aura');

DELETE FROM `spell_custom_attr` WHERE `entry` = 31960;
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(31960,262144);
