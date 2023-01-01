--
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 27212;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(27212,1,0,1,1,0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27212 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2721200 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27212,0,0,0,11,0,100,0,0,0,0,0,0,80,2721200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of Loken - On Spawn - Run Script"),

(2721200,9,0,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Image of Loken - On Script - Say Line 0"),
(2721200,9,1,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Image of Loken - On Script - Say Line 1"),
(2721200,9,2,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Image of Loken - On Script - Say Line 2"),
(2721200,9,3,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Image of Loken - On Script - Say Line 3"),
(2721200,9,4,0,0,0,100,0,6000,6000,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Image of Loken - On Script - Say Line 4"),
(2721200,9,5,0,0,0,100,0,0,0,0,0,0,33,27212,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Image of Loken - On Script - Quest Credit");
