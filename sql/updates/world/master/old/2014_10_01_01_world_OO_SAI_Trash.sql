delete from spell_script_names where ScriptName = 'spell_self_absorbed';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (145861, 'spell_self_absorbed');

update creature_template set ainame = 'SmartAI' where entry in (72662,72661);

delete from smart_scripts where entryorguid in (72662,72661);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(72662, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 72661, 500, 0, 0, 0, 0, 0, 'On Death - Send Data'),
(72662, 0, 1, 0, 0, 0, 100, 0, 40000, 40000, 40000, 40000, 11, 145861, 0, 0, 0, 0, 0, 125, 0, 0, 0, 0, 0, 0, 0, 'IC - Cast Spell'),

(72661, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 28, 145942, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Update Data - Remove Aura'),
(72661, 0, 1, 0, 60, 0, 100, 0, 0, 0, 0, 0, 75, 145942, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Update Data - Remove Aura'),
(72661, 0, 2, 0, 0, 0, 100, 0, 30000, 30000, 30000, 30000, 11, 145861, 0, 0, 0, 0, 0, 125, 0, 0, 0, 0, 0, 0, 0, 'IC - Cast Spell'),
(72661, 0, 3, 0, 0, 0, 100, 0, 40000, 40000, 40000, 40000, 11, 145944, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'IC - Cast Spell');

delete from conditions where SourceEntry = 72661 and SourceTypeOrReferenceId = 22;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 2, 72661, 0, 0, 29, 0, 72662, 500, 0, 0, 0, '', 'Smart - If near Creature'),
(22, 3, 72661, 0, 0, 1, 0, 145942, 0, 0, 0, 0, '', 'Smart - If Creature Has Aura');

update creature_template set movementtype = 2, speed_walk = 2.5 where entry = 72662;

delete from creature_template_addon where entry = 72662;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(72662, 633959, 0, 0, 1, 0, '');

delete from waypoint_data where id = 633959;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `entry`, `wpguid`) VALUES 
(633959, 1, 1108.66, 893.446, 403.514, 0, 0, 0, 0, 100, 0, 0),
(633959, 2, 1063.65, 887.541, 384.975, 0, 0, 0, 0, 100, 0, 0),
(633959, 3, 1064.24, 862.768, 385.755, 0, 0, 0, 0, 100, 0, 0),
(633959, 4, 1070.92, 835.408, 381.833, 0, 0, 0, 0, 100, 0, 0),
(633959, 5, 1056.56, 820.858, 379.159, 0, 0, 0, 0, 100, 0, 0),
(633959, 6, 1028.45, 816.231, 380.614, 0, 0, 0, 0, 100, 0, 0),
(633959, 7, 1012.6, 838.957, 380.0660, 0, 0, 0, 0, 100, 0, 0),
(633959, 8, 1016.08, 862.062, 378.338, 0, 0, 0, 0, 100, 0, 0),
(633959, 9, 1041.23, 873.799, 379.470, 0, 0, 0, 0, 100, 0, 0),
(633959, 10, 1113.05, 896.063, 404.09 ,0, 0, 0, 0, 100, 0, 0),
(633959, 11, 1131.71, 898.71, 404.101, 0, 0, 0, 0, 100, 0, 0);

delete from creature where guid = 633959;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(633959, 72662, 1136, 6738, 6798, 16632, 1, 50900, 0, 1131.71, 898.71, 404.101, -2.92693, 14400, 0, 0, 84318400, 84318400, 2, 0, 32768, 0, 0);