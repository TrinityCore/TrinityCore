-- Underlight Mines
SET @PATHID_1 := 826050;
SET @PATHID_2 := 825820;

UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (82605, 82582);
DELETE FROM `creature_addon` WHERE `guid` IN (82605, 82582);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES 
(82605, @PATHID_1, 4097),
(82582, @PATHID_2, 4097);

-- Add waypoints
DELETE FROM `waypoint_data` WHERE `id` IN (@PATHID_1, @PATHID_2);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
-- Blackpaw Shaman #1
(@PATHID_1,  1, 7126.29, -6221.997, 21.801),
(@PATHID_1,  2, 7110.97, -6227.314, 21.194),
(@PATHID_1,  3, 7105.31, -6209.855, 21.509),
(@PATHID_1,  4, 7081.72, -6205.795, 21.952),
(@PATHID_1,  5, 7071.54, -6199.641, 22.810),
(@PATHID_1,  6, 7071.65, -6189.511, 21.062),
(@PATHID_1,  7, 7071.54, -6199.641, 22.810),
(@PATHID_1,  8, 7077.39, -6207.805, 22.138),
(@PATHID_1,  9, 7076.12, -6218.441, 23.908),
(@PATHID_1, 10, 7068.51, -6227.06,  23.479),
(@PATHID_1, 11, 7061.94, -6227.88,  22.943),
(@PATHID_1, 12, 7068.51, -6227.06,  23.479),
(@PATHID_1, 13, 7076.12, -6218.44,  23.908),
(@PATHID_1, 14, 7077.39, -6207.80,  22.138),
(@PATHID_1, 15, 7071.54, -6199.64,  22.810),
(@PATHID_1, 16, 7071.65, -6189.51,  21.062),
(@PATHID_1, 17, 7071.54, -6199.64,  22.810),
(@PATHID_1, 18, 7081.72, -6205.79,  21.952),
(@PATHID_1, 19, 7105.31, -6209.85,  21.509),
(@PATHID_1, 20, 7110.97, -6227.31,  21.194),
(@PATHID_1, 21, 7126.29, -6221.99,  21.801),
-- Blackpaw Shaman #2
(@PATHID_2,  1, 7001.19, -6262.55,  6.511),
(@PATHID_2,  2, 7009.89, -6270.94,  5.008),
(@PATHID_2,  3, 7022.81, -6275.65,  7.483),
(@PATHID_2,  4, 7039.36, -6277.72,  8.733),
(@PATHID_2,  5, 7054.01, -6276.99, 12.318),
(@PATHID_2,  6, 7069.66, -6269.71, 15.899),
(@PATHID_2,  7, 7076.94, -6260.30, 17.073),
(@PATHID_2,  8, 7072.61, -6244.68, 19.408),
(@PATHID_2,  9, 7068.06, -6234.58, 22.018),
(@PATHID_2, 10, 7072.61, -6244.68, 19.408),
(@PATHID_2, 11, 7076.94, -6260.30, 17.073),
(@PATHID_2, 12, 7069.66, -6269.71, 15.899),
(@PATHID_2, 13, 7054.01, -6276.99, 12.318),
(@PATHID_2, 14, 7039.36, -6277.72,  8.733),
(@PATHID_2, 15, 7022.81, -6275.65,  7.483),
(@PATHID_2, 16, 7009.89, -6270.94,  5.008),
(@PATHID_2, 17, 7001.19, -6262.55,  6.511),
(@PATHID_2, 18, 7006.29, -6247.67,  6.112);

-- Add correct weapons to specific Blackpaw Gnolls and Blackpaw Scavengers
DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (16334, 16335) AND `id`=2;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`) VALUES
(16334, 2, 2901), -- This weapon isn't sniffed, but looks exactly like the one used in retail. If someone has the sniffed weapon I can update the SQL
(16335, 2, 2901);

UPDATE `creature` SET `equipment_id`=2 WHERE `guid` IN (82576, 82580, 82583, 82584, 82586, 82587, 82591, 82593, 82594, 82595, 82596, 82598, 82601, 82644);

-- Blackpaw Shaman SAI
SET @ENTRY := 16337;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,4500,11,20802,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blackpaw Shaman - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,28902,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackpaw Shaman - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Blackpaw Shaman - Between 0-15% Health - Flee For Assist (No Repeat)");
