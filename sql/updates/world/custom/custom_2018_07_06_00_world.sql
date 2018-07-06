-- High Priesess Azil
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87 WHERE `entry`= 49624;
UPDATE `creature_template` SET `InhabitType`= 1, `flags_extra`= `flags_extra` | 512 | 536870912 WHERE `entry` IN (42333, 49624);

UPDATE `spell_script_names` SET `ScriptName`= 'spell_azil_summon_wave_south' WHERE `ScriptName`= 'spell_summon_wave_south';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_azil_summon_wave_west' WHERE `ScriptName`= 'spell_summon_wave_west';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_azil_gravity_well_damage_nearby' WHERE `ScriptName`= 'spell_gravity_well_damage_nearby';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_azil_gravity_well_damage' WHERE `ScriptName`= 'spell_gravity_well_damage';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_azil_gravity_well_pull' WHERE `ScriptName`= 'spell_gravity_well_pull';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_azil_seismic_shard_change_seat' WHERE `ScriptName`= 'spell_seismic_shard_change_seat';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_azil_seismic_shard' WHERE `ScriptName`= 'spell_seismic_shard';

UPDATE `creature_template` SET `ScriptName`= 'npc_azil_devout_follower' WHERE `ScriptName`= 'npc_devout_follower';
UPDATE `creature_template` SET `ScriptName`= 'npc_azil_gravity_well' WHERE `ScriptName`= 'npc_gravity_well';
UPDATE `creature_template` SET `ScriptName`= 'npc_azil_seismic_shard' WHERE `ScriptName`= 'npc_seismic_shard';

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_azil_force_grip',
'spell_azil_force_grip_change_seat');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79351, 'spell_azil_force_grip'),
(79359, 'spell_azil_force_grip_change_seat');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (79021, 92665) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 2, 79021, 0, 0, 31, 0, 3, 42428, 0, 0, 0, '', 'Seismic Shard - Target Devout Follower'),
(13, 2, 92665, 0, 0, 31, 0, 3, 42428, 0, 0, 0, '', 'Seismic Shard - Target Devout Follower');
