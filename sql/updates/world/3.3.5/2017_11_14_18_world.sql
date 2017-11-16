DELETE FROM `smart_scripts` WHERE `entryorguid`=15958 AND `source_type`=0 AND id=5;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15656 AND `source_type`=0 AND id=7;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15402 AND `source_type`=0 AND id>4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15958,0,5,0,6,2,100,0,0,0,0,0,63,1,1,0,0,0,0,19,15402,100,0,0,0,0,0,"Gharsul the Remorseless - On death - Set counter"),
(15656,0,7,0,6,2,100,0,0,0,0,0,63,1,1,0,0,0,0,19,15402,100,0,0,0,0,0,"AngerShadee - On death - Set counter"),
(15402,0,5,6,77,1,100,0,1,3,0,0,15,8488,0,0,0,0,0,12,1,0,0,0,0,0,0,"Apprentice Mirveda - On counter - Complete Quest Unexpected Results"),
(15402,0,6,7,61,1,100,0,0,0,0,0,63,1,0,1,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Mirveda - On counter - Reset counter"),
(15402,0,7,0,61,1,100,0,0,0,0,0,80,1540202,2,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Mirveda - Linked with Previous Event - Run Script"),
(15402,0,8,0,11,0,100,512,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Mirveda - On Spawn - Set Immune to NPC");

DELETE FROM `waypoints` WHERE `entry` IN(15958,15656);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(15958, 1, 8711.897, -7160.284, 42.592, 'Gharsul the Remorseless'),
(15656, 1, 8712.909, -7159.269, 41.493, 'Angershade');
