-- Captain Welsington SAI (Source: Sniffs, videos)
SET @ID := 29489;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,5000,10000,10000,0,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Captain Welsington - In Combat - Cast 'Mortal Strike'"),
(@ID,0,1,0,0,0,100,0,10000,10000,15000,15000,0,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Captain Welsington - In Combat - Cast 'Intercept'"),
(@ID,0,2,0,0,0,100,0,25000,25000,25000,25000,0,11,32588,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Captain Welsington - In Combat - Cast 'Concussion Blow'"),
(@ID,0,3,0,0,0,100,0,5000,5000,20000,20000,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captain Welsington - In Combat - Say Line 1"),
(@ID,0,4,0,6,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Captain Welsington - On Death - Say Line 0");

-- http://web.archive.org/web/20111101111450/www.wowhead.com/npc=29489#.
DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Archbishop Landgren must know! Aaaaaagggghhhh.....!",12,0,100,0,0,0,30161,0,"Captain Welsington"),
(@ID,1,0,"Guards help!",12,0,100,0,0,0,30163,0,"Captain Welsington"),
(@ID,1,1,"Please... wait... stop! I don't know where the grand admiral is, but I'm sure we can work it out.",12,0,100,0,0,0,30164,0,"Captain Welsington"),
(@ID,1,2,"Did I mention that I have money and jewels? Don't kill me!",12,0,100,0,0,0,30165,0,"Captain Welsington"),
(@ID,1,3,"I have no idea where he's at. I haven't seen him since we landed!",12,0,100,0,0,0,30166,0,"Captain Welsington"),
(@ID,1,4,"Can anyone hear me? I'm being attacked!",12,0,100,0,0,0,30167,0,"Captain Welsington"),
(@ID,1,5,"Stop! I could be convinced to join you!",12,0,100,0,0,0,30168,0,"Captain Welsington"),
(@ID,1,6,"Not the face! Not the face!",12,0,100,0,0,0,30169,0,"Captain Welsington"),
(@ID,1,7,"How dare you! Do you have any idea who I am?",12,0,100,0,0,0,30170,0,"Captain Welsington");

-- Captain Hartford SAI (Source: Sniffs, videos)
SET @ID := 29490;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,79,30,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captain Hartford - On Respawn - Set Ranged Movement"),
(@ID,0,1,0,0,0,100,0,0,0,3000,4000,0,87,2949000,2949001,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captain Hartford - In Combat - Run Random Script"),
(@ID,0,2,0,0,0,100,0,10000,10000,20000,20000,0,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captain Hartford - In Combat - Cast 'Frost Nova'"),
(@ID,0,3,0,0,0,100,0,5000,5000,20000,20000,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captain Hartford - In Combat - Say Line 1"),
(@ID,0,4,0,6,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Captain Hartford - On Death - Say Line 0");

-- http://web.archive.org/web/20111122101100/http://www.wowhead.com/npc=29490
DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"I don't know where the grand admiral is. Go to hell!",12,0,100,0,0,0,30146,0,"Captain Hartford"),
(@ID,1,0,"You'll get nothing out of me!",12,0,100,0,0,0,30148,0,"Captain Hartford"),
(@ID,1,1,"I'll have your gizzard for breakfast!",12,0,100,0,0,0,30149,0,"Captain Hartford"),
(@ID,1,2,"Better than you have tried!",12,0,100,0,0,0,30151,0,"Captain Hartford"),
(@ID,1,3,"You may kill me, but I'll never tell you what you want!",12,0,100,0,0,0,30152,0,"Captain Hartford"),
(@ID,1,4,"I am Scarlet Onslaught. We don't rat out our leaders!",12,0,100,0,0,0,30153,0,"Captain Hartford"),
(@ID,1,5,"You're just a filthy pawn of the Ebon Blade. Die!",12,0,100,0,0,0,30154,0,"Captain Hartford"),
(@ID,1,6,"No, I don't know where he is and if I did, I wouldn't tell you -- even if my life depended on it!",12,0,100,0,0,0,30155,0,"Captain Hartford"),
(@ID,1,7,"Your corpse will adorn my mast!",12,0,100,0,0,0,30157,0,"Captain Hartford");

-- Onslaught Darkweaver SAI (Source: Sniffs)
SET @ID := 29614;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Only the ones with waypoints summons pets and casts Demon Armor
-- Hm, not sure anymore https://youtu.be/wM_Cm68CCZ0?t=143
(@ID,0,0,0,25,0,100,0,0,0,0,0,0,87,2961400,2961401,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Darkweaver - On Reset - Run Random Script"),
(@ID,0,1,0,1,0,100,1,1000,1000,0,0,0,11,33346,0,0,0,0,0,19,29649,10,0,0,0,0,0,0,"Onslaught Darkweaver - Out of Combat - Cast 'Green Beam' (No Repeat)"),
(@ID,0,2,0,1,0,100,0,0,0,30000,30000,0,11,13787,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Darkweaver - Out of Combat - Cast 'Demon Armor'"),
(@ID,0,3,0,0,0,100,0,0,0,3000,3500,0,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Onslaught Darkweaver - In Combat CMC - Cast 'Shadow Bolt'"),
(@ID,0,4,5,2,0,100,1,0,50,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Darkweaver - Between 0-50% Health - Say Line 0 (No Repeat)"),
(@ID,0,5,6,61,0,100,0,0,0,0,0,0,11,54840,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Darkweaver - On Link - Cast 'Metamorphosis'"),
(@ID,0,6,7,61,0,100,0,0,0,0,0,0,11,54879,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Darkweaver - On Link - Cast 'Metamorphosis'"),
(@ID,0,7,0,61,0,100,0,0,0,0,0,0,11,61610,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Darkweaver - On Link - Cast 'Metamorphosis'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"The darkweaver metamorphizes into something terrible and demonic.",16,0,100,0,0,0,30262,0,"Onslaught Darkweaver"),
(@ID,0,1,"A terrible change comes over the %s as he cackles maniacally.",16,0,100,0,0,0,30263,0,"Onslaught Darkweaver"),
(@ID,0,2,"With a horrible outcry, the %s transforms into a demonic nightmare.",16,0,100,0,0,0,30264,0,"Onslaught Darkweaver"),
(@ID,0,3,"The darkweaver pierces you with an evil grin as he shifts into an entirely different form.",16,0,100,0,0,0,30265,0,"Onslaught Darkweaver"),
(@ID,0,4,"Now you know. Now you must die!",12,0,100,0,0,0,30266,0,"Onslaught Darkweaver"),
(@ID,0,5,"Even in death there will be no escape for you!",12,0,100,0,0,0,30267,0,"Onslaught Darkweaver"),
(@ID,0,6,"I shall feast upon your soul!",12,0,100,0,0,0,30268,0,"Onslaught Darkweaver"),
(@ID,0,7,"You will not leave this cavern alive!",12,0,100,0,0,0,30269,0,"Onslaught Darkweaver");

UPDATE `creature` SET `position_x` = 7474.54, `position_y` = 4921.0747, `position_z` = -22.149136, `wander_distance` = 0, `MovementType` = 0 WHERE `guid` IN (123868,123869);
UPDATE `creature` SET `position_x` = 7454.685, `position_y` = 4867.244, `position_z` = -2.4262078, `wander_distance` = 0, `MovementType` = 0 WHERE `guid` IN (123859,123860);
UPDATE `creature` SET `position_x` = 7497.934, `position_y` = 4764.791, `position_z` = -12.954805, `wander_distance` = 0, `MovementType` = 0 WHERE `guid` IN (123865,123866);
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (123868,123859,123865);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (123868,123859,123865,131106);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(123868,123868,0,0,515,0,0),
(123868,123869,2,270,515,0,0),
(123859,123859,0,0,515,0,0),
(123859,123860,2,270,515,0,0),
(123865,123865,0,0,515,0,0),
(123865,123866,2,270,515,0,0),
(131106,131106,0,0,515,0,0),
(131106,131113,2,270,515,0,0);

DELETE FROM `creature_addon` WHERE `guid` IN (123868,123859,123865,131106);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(123868,1238680,0,0,1,0,0,""),
(123859,1238590,0,0,1,0,0,""),
(123865,1238650,0,0,1,0,0,""),
(131106,1311060,0,0,1,0,0,"");

DELETE FROM `waypoint_data` WHERE `id` IN (1238680,1238590,1238650,1311060);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(1238680,1,7474.54,4921.0747,-22.149136,0,0,0,0,0,0),
(1238680,2,7474.671,4900.776,-23.729225,0,0,0,0,0,0),
(1238680,3,7477.991,4884.178,-23.339146,0,0,0,0,0,0),
(1238680,4,7466.7563,4870.8027,-21.43956,0,0,0,0,0,0),
(1238680,5,7451.762,4852.8613,-18.365536,0,0,0,0,0,0),
(1238680,6,7466.666,4870.695,-21.40938,0,0,0,0,0,0),
(1238680,7,7477.991,4884.178,-23.339146,0,0,0,0,0,0),
(1238680,8,7474.671,4900.776,-23.729225,0,0,0,0,0,0),
(1238680,9,7474.54,4921.0747,-22.149136,0,0,0,0,0,0),
(1238680,10,7490.647,4931.679,-20.21695,0,0,0,0,0,0),
(1238680,11,7506.514,4922.942,-17.067787,0,0,0,0,0,0),
(1238680,12,7505.1196,4899.514,-13.800715,0,0,0,0,0,0), -- may be incomplete
(1238680,13,7506.514,4922.942,-17.067787,0,0,0,0,0,0),
(1238680,14,7490.647,4931.679,-20.21695,0,0,0,0,0,0),
(1238590,1,7454.685,4867.244,-2.4262078,0,0,0,0,0,0),
(1238590,2,7464.4985,4854.518,-4.9713507,0,0,0,0,0,0),
(1238590,3,7467.9697,4838.5176,-7.8081746,0,0,0,0,0,0),
(1238590,4,7465.059,4825.8975,-7.61516,0,0,0,0,0,0),
(1238590,5,7456.127,4814.1733,-12.918505,0,0,0,0,0,0),
(1238590,6,7431.289,4818.1685,-17.704645,0,0,0,0,0,0),
(1238590,7,7456.127,4814.1733,-12.918505,0,0,0,0,0,0),
(1238590,8,7465.059,4825.8975,-7.6084013,0,0,0,0,0,0),
(1238590,9,7467.9697,4838.5176,-7.8081746,0,0,0,0,0,0),
(1238590,10,7464.4985,4854.518,-4.9713507,0,0,0,0,0,0),
(1238590,11,7454.685,4867.244,-2.4262078,0,0,0,0,0,0),
(1238590,12,7438.1426,4871.414,0.7694678,0,0,0,0,0,0),
(1238590,13,7424.0034,4869.5854,0.5620718,0,0,0,0,0,0),
(1238590,14,7438.1426,4871.414,0.7694678,0,0,0,0,0,0),
(1238650,1,7497.934,4764.791,-12.954805,0,0,0,0,0,0),
(1238650,2,7486.9097,4750.312,-12.835154,0,0,0,0,0,0),
(1238650,3,7474.7354,4748.352,-12.663383,0,0,0,0,0,0),
(1238650,4,7457.9297,4756.4844,-13.180476,0,0,0,0,0,0),
(1238650,5,7445.0645,4769.046,-13.99918,0,0,0,0,0,0),
(1238650,6,7437.4946,4780.4062,-14.230126,0,0,0,0,0,0),
(1238650,7,7434.888,4792.1167,-15.694314,0,0,0,0,0,0),
(1238650,8,7437.0913,4802.535,-16.991375,0,0,0,0,0,0),
(1238650,9,7434.888,4792.1167,-15.694314,0,0,0,0,0,0),
(1238650,10,7437.4946,4780.4062,-14.230126,0,0,0,0,0,0),
(1238650,11,7445.0645,4769.046,-13.99918,0,0,0,0,0,0),
(1238650,12,7457.9297,4756.4844,-13.180476,0,0,0,0,0,0),
(1238650,13,7474.7354,4748.352,-12.663383,0,0,0,0,0,0),
(1238650,14,7486.9097,4750.312,-12.835154,0,0,0,0,0,0),
(1238650,15,7497.934,4764.791,-12.954805,0,0,0,0,0,0),
(1238650,16,7490.337,4789.397,-12.849622,0,0,0,0,0,0),
(1311060,1,7479.3003,4816.151,7.181603,0,0,0,0,0,0),
(1311060,2,7468.3037,4806.811,7.223208,0,0,0,0,0,0),
(1311060,3,7454.1206,4797.3506,7.1941895,0,0,0,0,0,0),
(1311060,4,7442.0645,4801.9966,7.1880302,0,0,0,0,0,0),
(1311060,5,7424.001,4813.178,6.246667,0,0,0,0,0,0),
(1311060,6,7413.251,4831.194,4.0834823,0,0,0,0,0,0),
(1311060,7,7404.444,4848.0244,1.4792968,0,0,0,0,0,0),
(1311060,8,7413.251,4831.194,4.0834823,0,0,0,0,0,0),
(1311060,9,7424.001,4813.178,6.246667,0,0,0,0,0,0),
(1311060,10,7442.0645,4801.9966,7.1880302,0,0,0,0,0,0),
(1311060,11,7454.1206,4797.3506,7.1941895,0,0,0,0,0,0),
(1311060,12,7468.3037,4806.811,7.223208,0,0,0,0,0,0);

UPDATE `creature` SET `position_x` = 7441.1, `position_y` = 4838.65, `position_z` = -17.2658, `orientation` = 3.56942 WHERE `guid` = 123867 AND `id` = 29614;

DELETE FROM `creature` WHERE `guid` IN (131101,131103,131106,131113) AND `id` = 29614;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(131101, 29614, 571, 1, 1, 1, 7436.48, 4840.54, -17.2343, 5.09763, 300, 0, 0, 0),
(131103, 29614, 571, 1, 1, 1, 7434.46, 4835.48, -17.2047, 0.460878, 300, 0, 0, 0),
(131106, 29614, 571, 1, 1, 1, 7479.3003, 4816.151, 7.181603, 0, 300, 0, 2, 0),
(131113, 29614, 571, 1, 1, 1, 7479.3003, 4816.151, 7.181603, 0, 300, 0, 0, 0);

-- Captured Death's Rise Spy
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0 WHERE `id` = 29649;
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 29649;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(29649,0,0,0,1,0,0);
