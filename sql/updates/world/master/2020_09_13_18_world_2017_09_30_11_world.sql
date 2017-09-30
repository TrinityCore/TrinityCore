-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=7273 AND `source_type`=0 AND `id` IN (3,4,5,6);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7273,0,3,0,54,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gahz'rilla - Just Summoned - Add Unit Flag Immune to PC"),
(7273,0,4,0,54,0,100,0,0,0,0,0,53,0,7273,0,0,0,0,1,0,0,0,0,0,0,0,"Gahz'rilla - Just Summoned - Start Waypoint"),
(7273,0,5,0,40,0,100,0,2,7273,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gahz'rilla - On Waypoint 2 Reached - Start Random Movement"),
(7273,0,6,0,40,0,100,0,2,7273,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gahz'rilla - On Waypoint 2 Reached - Remove Unit Flag Immune to PC");

DELETE FROM `waypoints` WHERE `entry`=7273;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(7273,1,1686.55,1207.18,9.79578,"Gahz'rilla"),
(7273,2,1700.54,1220.82,8.87687,"Gahz'rilla");
