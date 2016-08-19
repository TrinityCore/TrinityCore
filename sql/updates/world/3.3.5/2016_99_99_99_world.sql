UPDATE `creature_template` SET `ScriptName`='npc_pit_of_saron_icicle' WHERE `entry`=36847;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=12994 AND `type`=18;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pos_ice_shards';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(70827, 'spell_pos_ice_shards');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5580,5581);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5580, 'at_pit_cavern_entrance'),
(5581, 'at_pit_cavern_end');
