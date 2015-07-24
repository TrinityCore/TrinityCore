-- Too many or incorrect npc spawns
DELETE FROM `creature` WHERE `guid` IN (105129,97882,97881,97886,97888,97880,97898,111144,111168, 99232);

-- Pathing for Rustler Burnhoof Entry: 27750 'TDB FORMAT' 
SET @NPC := 105130;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4903.906,`position_y`=1220.93,`position_z`=223.7604 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4903.906,1220.93,223.7604,0,1000,0,0,100,0),
(@PATH,2,4907.209,1219.953,222.8496,0,0,0,0,100,0),
(@PATH,3,4905.934,1220.017,223.2021,0,0,0,0,100,0),
(@PATH,4,4902.668,1221.12,224.2068,0,1000,0,0,100,0),
(@PATH,5,4903.906,1220.93,223.7604,0,0,0,0,100,0),
(@PATH,6,4907.628,1220.036,222.8975,0,0,0,0,100,0),
(@PATH,7,4905.934,1220.017,223.2021,0,0,0,0,100,0),
(@PATH,8,4902.884,1221.202,224.2569,0,0,0,0,100,0);
-- 0x1C10F047601B198000000900001F1A2A .go 4903.906 1220.93 223.7604

-- Update SAI for waypoints
-- Darkspear Spear Thrower SAI
SET @ENTRY := 27560;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Out of Combat - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Out of Combat - Stop Attacking (No Repeat)"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Spear Thrower - On Aggro - Cast 'Shoot' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - On Aggro - Increment Phase By 1 (No Repeat)"),
(@ENTRY,0,4,5,9,1,100,0,5,35,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 5-35 Range - Cast 'Shoot' (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 5-35 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,30,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 30-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 30-80 Range - Start Attacking (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 0-5 Range - Start Attacking (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 5-15 Range - Stop Attacking (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,20,9000,14000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 0-20 Range - Cast 'Net' (Phase 1)"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - On Evade - Set Sheath Melee (Phase 1)");

-- Pathing for Darkspear Spear Thrower Entry: 27560 'TDB FORMAT' 
SET @NPC := 111723;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5064.595,`position_y`=1152.95,`position_z`=256.9933 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5064.595,1152.95,256.9933,0,0,0,0,100,0),
(@PATH,2,5070.195,1148.834,258.9739,0,0,0,0,100,0),
(@PATH,3,5073.693,1146.814,259.7574,0,0,0,0,100,0),
(@PATH,4,5064.595,1152.95,256.9933,0,0,0,0,100,0),
(@PATH,5,5070.188,1148.872,259.0485,0,0,0,0,100,0),
(@PATH,6,5073.804,1146.81,259.5706,0,0,0,0,100,0),
(@PATH,7,5078.612,1145.942,259.8978,0,0,0,0,100,0),
(@PATH,8,5067.567,1150.284,258.2607,0,0,0,0,100,0),
(@PATH,9,5063.21,1155.218,255.487,0,0,0,0,100,0);
-- 0x1C10F047601AEA0000000B00019A427C .go 5064.595 1152.95 256.9933

-- Pathing for Darkspear Spear Thrower Entry: 27560 'TDB FORMAT' 
SET @NPC := 111724;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4911.591,`position_y`=1159.036,`position_z`=236.6868 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4911.591,1159.036,236.6868,0,0,0,0,100,0),
(@PATH,2,4911.276,1158.72,236.4579,0,0,0,0,100,0),
(@PATH,3,4911.188,1158.772,236.7394,0,0,0,0,100,0),
(@PATH,4,4899.376,1152.87,236.8453,0,0,0,0,100,0),
(@PATH,5,4894.586,1145.359,234.9626,0,0,0,0,100,0),
(@PATH,6,4897.318,1151.077,236.903,0,0,0,0,100,0),
(@PATH,7,4901.86,1152.988,236.7417,0,0,0,0,100,0),
(@PATH,8,4906.159,1153.659,236.4303,0,0,0,0,100,0);
-- 0x1C10F047601AEA0000000B00009A427C .go 4911.591 1159.036 236.6868

-- Pathing for Darkspear Spear Thrower Entry: 27560 'TDB FORMAT' 
SET @NPC := 111725;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4920.973,`position_y`=1199.484,`position_z`=220.5279 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4920.973,1199.484,220.5279,0,10000,0,0,100,0),
(@PATH,2,4906.262,1193.945,216.8263,0,0,0,0,100,0),
(@PATH,3,4896.307,1191.923,213.5118,0,0,0,0,100,0),
(@PATH,4,4877.854,1191.151,207.1242,0,0,0,0,100,0),
(@PATH,5,4869.318,1191.457,203.3286,0,0,0,0,100,0),
(@PATH,6,4861.047,1185.213,197.0835,0,0,0,0,100,0),
(@PATH,7,4855.936,1177.188,191.9594,0,0,0,0,100,0),
(@PATH,8,4851.635,1166.61,185.649,0,0,0,0,100,0),
(@PATH,9,4851.767,1158.619,182.5839,0,0,0,0,100,0),
(@PATH,10,4851.611,1145.529,178.0937,0,0,0,0,100,0),
(@PATH,11,4848.171,1135.259,173.5705,0,0,0,0,100,0),
(@PATH,12,4841.896,1128.136,169.8648,0,0,0,0,100,0),
(@PATH,13,4829.645,1127.843,162.5515,0,0,0,0,100,0),
(@PATH,14,4817.105,1120.131,150.2594,0,0,0,0,100,0),
(@PATH,15,4837.624,1131.328,167.8283,0,0,0,0,100,0),
(@PATH,16,4843.094,1133.076,170.812,0,0,0,0,100,0),
(@PATH,17,4849.752,1146.139,177.2836,0,0,0,0,100,0),
(@PATH,18,4851.623,1160.048,182.5452,0,0,0,0,100,0),
(@PATH,19,4853.529,1172.237,188.9928,0,0,0,0,100,0),
(@PATH,20,4860.48,1186.084,197.2776,0,0,0,0,100,0),
(@PATH,21,4865.775,1191.164,201.062,0,0,0,0,100,0),
(@PATH,22,4882.853,1189.864,208.7863,0,0,0,0,100,0),
(@PATH,23,4898.756,1190.01,214.2629,0,0,0,0,100,0),
(@PATH,24,4903.106,1189.946,216.3225,0,0,0,0,100,0),
(@PATH,25,4916.818,1193.317,219.5798,0,0,0,0,100,0),
(@PATH,26,4927.818,1197.552,223.1037,0,0,0,0,100,0),
(@PATH,27,4934.524,1200.075,224.6629,0,0,0,0,100,0);
-- 0x1C10F047601AEA0000000900001F18A3 .go 4920.973 1199.484 220.5279

DELETE FROM `creature_formations` WHERE `leaderGUID`=111218;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(111218, 111218, 0, 0, 2),
(111218, 111212, 3, 270, 2);

-- Make the second guard sit on a wolf 
DELETE FROM `creature_addon` WHERE `guid`=111212;
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes2`) VALUES (111212, 14574, 1);

-- Pathing for Kor'kron Vanguard Entry: 27553 'TDB FORMAT' 
SET @NPC := 111218;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4924.406,`position_y`=1275.88,`position_z`=226.2913 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,14574,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4924.406,1275.88,226.2913,0,0,0,0,100,0),
(@PATH,2,4937.631,1293.169,231.839,0,0,0,0,100,0),
(@PATH,3,4942.635,1298.434,233.2347,0,0,0,0,100,0),
(@PATH,4,4945.541,1308.453,235.1535,0,0,0,0,100,0),
(@PATH,5,4945.916,1311.464,235.4867,0,0,0,0,100,0),
(@PATH,6,4933.331,1328.104,234.9145,0,0,0,0,100,0),
(@PATH,7,4920.956,1329.519,232.9218,0,0,0,0,100,0),
(@PATH,8,4910.192,1318.32,229.7501,0,0,0,0,100,0),
(@PATH,9,4907.542,1298.864,227.4101,0,0,0,0,100,0),
(@PATH,10,4920.273,1273.854,225.6455,0,0,0,0,100,0),
(@PATH,11,4921.565,1272.237,225.4687,0,0,0,0,100,0),
(@PATH,12,4934.279,1260.357,225.9705,0,0,0,0,100,0),
(@PATH,13,4942.9,1231.032,225.8454,0,0,0,0,100,0),
(@PATH,14,4937.212,1219.435,224.397,0,0,0,0,100,0),
(@PATH,15,4911.338,1207.108,217.914,0,0,0,0,100,0),
(@PATH,16,4891.614,1199.313,212.0708,0,0,0,0,100,0),
(@PATH,17,4863.26,1198.326,202.0412,0,0,0,0,100,0),
(@PATH,18,4850.935,1180.464,192.229,0,0,0,0,100,0),
(@PATH,19,4847.402,1162.623,182.7594,0,0,0,0,100,0),
(@PATH,20,4841.849,1139.334,171.3826,0,0,0,0,100,0),
(@PATH,21,4820.599,1131.604,157.3213,0,0,0,0,100,0),
(@PATH,22,4801.356,1123.592,143.7112,0,0,0,0,100,0),
(@PATH,23,4793.032,1123.066,139.6156,0,0,0,0,100,0),
(@PATH,24,4768.374,1127.539,137.6369,0,0,0,0,100,0),
(@PATH,25,4754.815,1120.818,134.7707,0,0,0,0,100,0),
(@PATH,26,4756.951,1111.815,133.9409,0,0,0,0,100,0),
(@PATH,27,4783.79,1110.19,135.937,0,0,0,0,100,0),
(@PATH,28,4794.232,1119.631,139.188,0,0,0,0,100,0),
(@PATH,29,4821.204,1132.168,157.943,0,0,0,0,100,0),
(@PATH,30,4839.43,1138.844,170.0454,0,0,0,0,100,0),
(@PATH,31,4845.836,1150.71,177.3853,0,0,0,0,100,0),
(@PATH,32,4845.682,1166.896,184.5937,0,0,0,0,100,0),
(@PATH,33,4851.188,1179.674,191.6429,0,0,0,0,100,0),
(@PATH,34,4856.156,1191.45,197.6969,0,0,0,0,100,0),
(@PATH,35,4866.021,1197.9,202.6528,0,0,0,0,100,0),
(@PATH,36,4877.186,1197.585,207.2055,0,0,0,0,100,0),
(@PATH,37,4886.485,1195.461,210.3322,0,0,0,0,100,0),
(@PATH,38,4899.135,1196.966,214.2494,0,0,0,0,100,0),
(@PATH,39,4918.985,1205.409,219.7656,0,0,0,0,100,0),
(@PATH,40,4937.731,1213.068,223.7986,0,0,0,0,100,0),
(@PATH,41,4945.257,1216.732,225.4393,0,0,0,0,100,0),
(@PATH,42,4964.039,1213.632,227.3908,0,0,0,0,100,0),
(@PATH,43,4977.262,1211.667,228.8397,0,0,0,0,100,0),
(@PATH,44,4995.401,1220.229,230.2568,0,0,0,0,100,0),
(@PATH,45,5005.794,1216.344,229.7073,0,0,0,0,100,0),
(@PATH,46,4999.293,1203.755,229.2162,0,0,0,0,100,0),
(@PATH,47,4998.588,1202.614,228.9512,0,0,0,0,100,0),
(@PATH,48,4990.875,1206.203,228.9671,0,0,0,0,100,0),
(@PATH,49,4981.535,1210.325,228.6667,0,0,0,0,100,0),
(@PATH,50,4954.279,1220.26,226.6951,0,0,0,0,100,0),
(@PATH,51,4947.755,1223.85,226.0268,0,0,0,0,100,0),
(@PATH,52,4940.268,1236.863,226.4474,0,0,0,0,100,0),
(@PATH,53,4938.791,1241.772,226.2903,0,0,0,0,100,0),
(@PATH,54,4938.446,1241.541,226.0408,0,0,0,0,100,0),
(@PATH,55,4942.353,1231.415,225.6545,0,0,0,0,100,0),
(@PATH,56,4951.323,1221.968,226.2391,0,0,0,0,100,0),
(@PATH,57,4968.059,1214.005,228.1602,0,0,0,0,100,0),
(@PATH,58,4968.759,1213.868,228.1815,0,0,0,0,100,0),
(@PATH,59,4981.347,1210.41,228.6719,0,0,0,0,100,0),
(@PATH,60,4990.792,1206.41,229.0509,0,0,0,0,100,0),
(@PATH,61,5001.532,1208.859,229.2795,0,0,0,0,100,0),
(@PATH,62,5006.636,1217.603,229.9853,0,0,0,0,100,0),
(@PATH,63,4988.494,1214.931,229.4006,0,0,0,0,100,0),
(@PATH,64,4970.586,1211.76,228.4952,0,0,0,0,100,0),
(@PATH,65,4955.156,1216.567,226.4764,0,0,0,0,100,0),
(@PATH,66,4920.63,1206.658,220.0801,0,0,0,0,100,0),
(@PATH,67,4908.19,1199.289,216.899,0,0,0,0,100,0),
(@PATH,68,4888.762,1195.545,210.6963,0,0,0,0,100,0),
(@PATH,69,4878.838,1197.535,207.8827,0,0,0,0,100,0),
(@PATH,70,4868.977,1198.564,204.075,0,0,0,0,100,0),
(@PATH,71,4857.268,1192.864,198.429,0,0,0,0,100,0),
(@PATH,72,4852.329,1182.311,193.1272,0,0,0,0,100,0),
(@PATH,73,4846.871,1170.936,186.4543,0,0,0,0,100,0),
(@PATH,74,4846.116,1153.266,178.4778,0,0,0,0,100,0),
(@PATH,75,4840.938,1140.415,171.2645,0,0,0,0,100,0),
(@PATH,76,4822.356,1132.747,159.001,0,0,0,0,100,0),
(@PATH,77,4795.46,1120.689,140.3265,0,0,0,0,100,0),
(@PATH,78,4786.737,1111.815,136.5621,0,0,0,0,100,0),
(@PATH,79,4761.876,1105.746,133.8939,0,0,0,0,100,0),
(@PATH,80,4754.403,1118.203,134.364,0,0,0,0,100,0),
(@PATH,81,4764.019,1125.688,136.6772,0,0,0,0,100,0),
(@PATH,82,4782.308,1124.246,137.7441,0,0,0,0,100,0),
(@PATH,83,4797.498,1123.224,141.726,0,0,0,0,100,0),
(@PATH,84,4818.895,1130.859,156.3943,0,0,0,0,100,0),
(@PATH,85,4839.273,1137.457,169.8718,0,0,0,0,100,0),
(@PATH,86,4846.415,1158.605,180.5813,0,0,0,0,100,0),
(@PATH,87,4849.638,1177.232,190.3028,0,0,0,0,100,0),
(@PATH,88,4860.67,1196.271,200.4404,0,0,0,0,100,0),
(@PATH,89,4886.715,1198.448,210.6501,0,0,0,0,100,0),
(@PATH,90,4906.66,1204.837,216.6283,0,0,0,0,100,0),
(@PATH,91,4934.462,1217.512,223.728,0,0,0,0,100,0),
(@PATH,92,4940.261,1224.569,225.2942,0,0,0,0,100,0),
(@PATH,93,4940.506,1242.196,226.2575,0,0,0,0,100,0),
(@PATH,94,4933.305,1263.189,225.7185,0,0,0,0,100,0),
(@PATH,95,4931.952,1265.79,225.6381,0,0,0,0,100,0),
(@PATH,96,4907.601,1289.275,226.642,0,0,0,0,100,0),
(@PATH,97,4907.739,1309.926,228.4361,0,0,0,0,100,0),
(@PATH,98,4916.103,1327.044,231.7567,0,0,0,0,100,0),
(@PATH,99,4928.627,1329.424,234.3804,0,0,0,0,100,0),
(@PATH,100,4940.942,1320.479,235.4543,0,0,0,0,100,0),
(@PATH,101,4944.531,1301.983,234.3128,0,0,0,0,100,0),
(@PATH,102,4940.48,1296.446,232.8031,0,0,0,0,100,0),
(@PATH,103,4924.831,1276.205,226.2591,0,0,0,0,100,0);
-- 0x1C10F047601AE84000000A00001FFDD8 .go 4924.406 1275.88 226.2913

-- Pathing for Kor'kron Battle Wyvern Entry: 31269 'TDB FORMAT' 
SET @NPC := 99228;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5001.591,`position_y`=1222.632,`position_z`=256.7944 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5001.591,1222.632,256.7944,0,0,0,0,100,0),
(@PATH,2,5030.151,1242.143,268.1555,0,0,0,0,100,0),
(@PATH,3,5016.198,1276.81,265.4842,0,0,0,0,100,0),
(@PATH,4,4991.751,1280.123,265.4842,0,0,0,0,100,0),
(@PATH,5,4956.835,1268.773,265.4842,0,0,0,0,100,0),
(@PATH,6,4938.806,1223.236,259.9842,0,0,0,0,100,0),
(@PATH,7,4926.227,1191.379,255.3177,0,0,0,0,100,0),
(@PATH,8,4900.753,1152.352,243.8777,0,0,0,0,100,0),
(@PATH,9,4881.784,1164.878,242.3777,0,0,0,0,100,0),
(@PATH,10,4851.181,1199.767,234.0444,0,0,0,0,100,0),
(@PATH,11,4846.833,1226.647,234.0444,0,0,0,0,100,0),
(@PATH,12,4855.959,1279.159,239.3777,0,0,0,0,100,0),
(@PATH,13,4911.077,1262.704,243.6555,0,0,0,0,100,0),
(@PATH,14,4964.954,1234.062,250.3221,0,0,0,0,100,0);
-- 0x2010F047601E894000000B00029A427C .go 5001.591 1222.632 256.7944

-- Pathing for Kor'kron Battle Wyvern Entry: 31269 'TDB FORMAT' 
SET @NPC := 99227;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4875.777,`position_y`=1347.747,`position_z`=240.9708 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4875.777,1347.747,240.9708,0,0,0,0,100,0),
(@PATH,2,4900.708,1348.037,250.7207,0,0,0,0,100,0),
(@PATH,3,4926.32,1316.925,257.1653,0,0,0,0,100,0),
(@PATH,4,4938.213,1286.196,257.1653,0,0,0,0,100,0),
(@PATH,5,4947.025,1253.411,257.1653,0,0,0,0,100,0),
(@PATH,6,4945.441,1212.37,257.1653,0,0,0,0,100,0),
(@PATH,7,4948.411,1192.561,257.1653,0,0,0,0,100,0),
(@PATH,8,4972.647,1168.416,257.1653,0,0,0,0,100,0),
(@PATH,9,4995.961,1172.082,257.1653,0,0,0,0,100,0),
(@PATH,10,5004.243,1187.687,257.1653,0,0,0,0,100,0),
(@PATH,11,4989.543,1213.347,257.1653,0,0,0,0,100,0),
(@PATH,12,4965.152,1218.435,257.1653,0,0,0,0,100,0),
(@PATH,13,4923.045,1229.254,257.1653,0,0,0,0,100,0),
(@PATH,14,4887.481,1234.967,253.9984,0,0,0,0,100,0),
(@PATH,15,4851.523,1249.735,247.804,0,0,0,0,100,0),
(@PATH,16,4823.958,1288.316,234.6374,0,0,0,0,100,0),
(@PATH,17,4814.918,1327.853,230.693,0,0,0,0,100,0),
(@PATH,18,4853.216,1355.696,237.3319,0,0,0,0,100,0);
-- 0x2010F047601E894000000B00021A427C .go 4875.777 1347.747 240.9708

-- Pathing for Kor'kron Battle Wyvern Entry: 31269 'TDB FORMAT' 
SET @NPC := 99230;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5079.162,`position_y`=1142.135,`position_z`=267.7354 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5079.162,1142.135,267.7354,0,0,0,0,100,0),
(@PATH,2,5078.512,1126.875,267.7354,0,0,0,0,100,0),
(@PATH,3,5055.61,1116.456,267.7354,0,0,0,0,100,0),
(@PATH,4,5039.365,1121.131,267.7354,0,0,0,0,100,0),
(@PATH,5,4967.615,1187.905,260.0954,0,0,0,0,100,0),
(@PATH,6,4945.081,1216.898,260.0954,0,0,0,0,100,0),
(@PATH,7,4956.427,1234.148,260.0954,0,0,0,0,100,0),
(@PATH,8,4960.777,1262.983,260.0954,0,0,0,0,100,0),
(@PATH,9,4914.742,1284.397,254.9566,0,0,0,0,100,0),
(@PATH,10,4891.905,1273.239,254.5677,0,0,0,0,100,0),
(@PATH,11,4867.362,1252.014,255.6233,0,0,0,0,100,0),
(@PATH,12,4872.584,1220.825,255.6233,0,0,0,0,100,0),
(@PATH,13,4921.48,1192.52,255.6233,0,0,0,0,100,0),
(@PATH,14,4940.803,1188.571,255.6233,0,0,0,0,100,0),
(@PATH,15,4982.143,1184.493,255.6233,0,0,0,0,100,0),
(@PATH,16,5063.028,1170.208,265.2344,0,0,0,0,100,0),
(@PATH,17,5072.713,1157.194,267.7354,0,0,0,0,100,0);
-- 0x2010F047601E894000000B00009A427C .go 5079.162 1142.135 267.7354

-- Some specific Kor'kron Battle Wyvern's shouldn't move.
UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN (99246,99225,99226,99233);

-- Make those peon's work
SET @NPC := 27558;
DELETE FROM `creature_template_addon` WHERE `entry`=@NPC;
INSERT INTO `creature_template_addon` (`entry`, `emote`) VALUES (@NPC, 234);

-- Pathing for Warsong Peon Entry: 27558 'TDB FORMAT' 
SET @NPC := 111465;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5033.687,`position_y`=1241.426,`position_z`=231.0835 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,234, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5033.687,1241.426,231.0835,0,10000,0,0,100,0),
(@PATH,2,5035.556,1229.439,230.2363,0,0,0,0,100,0),
(@PATH,3,5040.211,1214.877,229.068,0,0,0,0,100,0),
(@PATH,4,5040.954,1202.383,228.5539,0,0,0,0,100,0),
(@PATH,5,5040.104,1193.25,228.4282,0,0,0,0,100,0),
(@PATH,6,5031.986,1186.173,228.1725,0,10000,0,0,100,0),
(@PATH,7,5040.118,1194.927,228.1124,0,0,0,0,100,0),
(@PATH,8,5040.393,1195.888,228.1124,0,0,0,0,100,0),
(@PATH,9,5042.309,1202.575,228.527,0,0,0,0,100,0),
(@PATH,10,5040.336,1213.374,228.7625,0,0,0,0,100,0),
(@PATH,11,5040.336,1213.374,228.7625,0,0,0,0,100,0),
(@PATH,12,5038.792,1223.162,229.6375,0,0,0,0,100,0),
(@PATH,13,5033.343,1233.986,230.8479,0,0,0,0,100,0);
-- 0x1C10F047601AE98000000B00029A427C .go 5033.687 1241.426 231.0835
