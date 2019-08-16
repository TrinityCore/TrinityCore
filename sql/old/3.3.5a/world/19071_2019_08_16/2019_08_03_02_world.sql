-- 
DELETE FROM `creature` WHERE `id`=27622 AND `guid`=113668; 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(113668, 27622, 0, 0, 0, 1, 1, 0, 0, -456.28103, 1498.40258, 16.98966, 5.96903, 60, 0, 0, 0, 0, 2, 0, 0, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=49129;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 49129, 0, 0, 31, 0, 3, 27622, 0, 0, 0, 0, "", "Arugal Rotation Channel");

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 27622;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(27622, 0, 0, 1, 0);

DELETE FROM `creature_addon` WHERE `guid`=113668;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`, `auras`) VALUES (113668,11366800,1,"49130");

DELETE FROM `waypoint_data` WHERE `id`=11366800;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(11366800,1,-456.28103, 1498.40258, 18.98966,0,0,0,100,0),
(11366800,2,-457.36898, 1496.58203, 18.98966,0,0,0,100,0),
(11366800,3,-458.51434, 1495.57177, 18.98966,0,0,0,100,0),
(11366800,4,-459.83737, 1494.41711, 18.98966,0,0,0,100,0),
(11366800,5,-461.39898, 1493.54296, 18.98966,0,0,0,100,0),
(11366800,6,-463.41326, 1493.34252, 18.98966,0,0,0,100,0),
(11366800,7,-465.08398, 1493.76220, 18.98966,0,0,0,100,0),
(11366800,8,-466.54000, 1494.80603, 18.98966,0,0,0,100,0),
(11366800,9,-468.04928, 1495.84643, 18.98966,0,0,0,100,0),
(11366800,10,-468.82998, 1497.45105, 18.98966,0,0,0,100,0),
(11366800,11,-469.37039, 1498.89978, 18.98966,0,0,0,100,0),
(11366800,12,-469.66574, 1500.14770, 18.98966,0,0,0,100,0),
(11366800,13,-469.05099, 1501.69104, 18.98966,0,0,0,100,0),
(11366800,14,-468.74670, 1502.91992, 18.98966,0,0,0,100,0),
(11366800,15,-467.51672, 1504.24365, 18.98966,0,0,0,100,0),
(11366800,16,-466.30108, 1505.15417, 18.98966,0,0,0,100,0),
(11366800,17,-464.70126, 1505.50427, 18.98966,0,0,0,100,0),
(11366800,18,-462.18228, 1505.41296, 18.98966,0,0,0,100,0),
(11366800,19,-459.59301, 1504.72680, 18.98966,0,0,0,100,0),
(11366800,20,-458.37594, 1503.59375, 18.98966,0,0,0,100,0),
(11366800,21,-456.90499, 1502.40295, 18.98966,0,0,0,100,0),
(11366800,22,-456.62875, 1500.67981, 18.98966,0,0,0,100,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27620) AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27620, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 49129, 0, 0, 0, 0, 0, 19, 27622, 0, 0, 0, 0, 0, 0, "Shade of Arugal - On reset - cast Arugal Rotation Channel");
