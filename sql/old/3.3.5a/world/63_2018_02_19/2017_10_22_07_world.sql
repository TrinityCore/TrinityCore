-- Dr. Witherlimb SAI/waypoints and speech
SET @ENTRY := 22062;
SET @GUID_1 := 77937;
SET @GUID_2 := 77938;
SET @GUID_3 := 77939;
SET @GUID_4 := 77940;
SET @PATHID_1 := @GUID_1 * 10;
SET @PATHID_2 := @GUID_2 * 10;
SET @PATHID_3 := @GUID_3 * 10;
SET @PATHID_4 := @GUID_4 * 10;

-- Dr. Whitherlimb SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,2500,4000,6000,11,21067,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dr. Whitherlimb - In Combat CMC - Cast 'Poison Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8000,15000,15000,30000,11,38864,33,0,0,0,0,5,0,0,0,0,0,0,0,"Dr. Whitherlimb - In Combat CMC - Cast 'Withering Poison'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,35000,45000,11,38871,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dr. Whitherlimb - Between 0-50% Health - Cast 'Monstrous Elixir'"),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dr. Whitherlimb - On Aggro - Say Line 0"),
(@ENTRY,0,4,0,5,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dr. Whitherlimb - On Killed Unit - Say Line 1");

-- Add speech of Dr. Whitherlimb
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `BroadcastTextId`, `comment`) VALUES 
(@ENTRY, 0, 0, "Excellent!  Fresh parts!", 12, 0, 100, 19887, "Dr. Whitherlimb - Aggro"),
(@ENTRY, 1, 0, "It is very kind of you to donate your organs!", 12, 0, 0, 19888, "Dr. Whitherlimb - Kill"),
(@ENTRY, 1, 1, "Be proud, your brain will be put to good use in one of my abominations.", 12, 0, 0, 19889, "Dr. Whitherlimb - Kill");

-- Update spawn timer (20h previously) and MovementType
UPDATE `creature` SET `spawntimesecs`=7200, `MovementType`=2 WHERE `id`=@ENTRY;

-- Add waypoints of Dr. Whitherlimb
DELETE FROM `creature_addon` WHERE `guid` IN (@GUID_1, @GUID_2, @GUID_3, @GUID_4);
INSERT INTO `creature_addon` (`guid`, `path_id`) VALUES 
(@GUID_1, @PATHID_1),
(@GUID_2, @PATHID_2),
(@GUID_3, @PATHID_3),
(@GUID_4, @PATHID_4);

DELETE FROM `waypoint_data` WHERE `id` IN (@PATHID_1, @PATHID_2, @PATHID_3, @PATHID_4);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATHID_1, 1, 7160.109, -6607.731, 60.658),
(@PATHID_1, 2, 7157.843, -6617.142, 60.658),
(@PATHID_1, 3, 7162.991, -6624.500, 60.658),
(@PATHID_1, 4, 7171.727, -6626.077, 60.864),
(@PATHID_1, 5, 7176.713, -6622.445, 63.658),
(@PATHID_1, 6, 7179.540, -6610.650, 63.658),
(@PATHID_1, 7, 7175.270, -6604.530, 60.658),
(@PATHID_1, 8, 7167.625, -6603.202, 60.658),
(@PATHID_2, 1, 7224.314, -6404.754, 56.166),
(@PATHID_2, 2, 7215.937, -6405.194, 56.166),
(@PATHID_2, 3, 7211.889, -6409.292, 59.166),
(@PATHID_2, 4, 7212.473, -6421.642, 59.166),
(@PATHID_2, 5, 7216.754, -6426.262, 56.166),
(@PATHID_2, 6, 7225.599, -6425.639, 56.166),
(@PATHID_2, 7, 7231.386, -6419.246, 56.166),
(@PATHID_2, 8, 7230.532, -6411.129, 56.166),
(@PATHID_3, 1, 6294.176, -6468.075, 83.011),
(@PATHID_3, 2, 6301.176, -6475.325, 83.011),
(@PATHID_3, 3, 6309.716, -6475.180, 83.011),
(@PATHID_3, 4, 6315.844, -6468.936, 83.197),
(@PATHID_3, 5, 6315.235, -6462.805, 86.010),
(@PATHID_3, 6, 6306.685, -6453.575, 86.010),
(@PATHID_3, 7, 6300.742, -6453.973, 83.010),
(@PATHID_3, 8, 6294.723, -6459.484, 83.010),
(@PATHID_4, 1, 6305.395, -6258.748, 77.813),
(@PATHID_4, 2, 6312.150, -6258.673, 80.813),
(@PATHID_4, 3, 6319.655, -6250.082, 80.813),
(@PATHID_4, 4, 6320.900, -6243.770, 77.942),
(@PATHID_4, 5, 6314.049, -6237.902, 77.813),
(@PATHID_4, 6, 6305.433, -6238.323, 77.813),
(@PATHID_4, 7, 6299.604, -6244.360, 77.813),
(@PATHID_4, 8, 6299.698, -6253.437, 77.813);
