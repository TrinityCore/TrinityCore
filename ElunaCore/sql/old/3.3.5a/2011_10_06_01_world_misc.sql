-- Pathing for Conquest Hold Berserker Entry: 27500
SET @NPC := 105857;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2721.081,`position_y`=-1832.136,`position_z`=4.838899 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2710.015,-1832.177,4.838899,0,0,0,100,0),
(@PATH,2,2700.421,-1833.964,4.838899,0,0,0,100,0),
(@PATH,3,2693.419,-1835.334,4.867931,0,0,0,100,0),
(@PATH,4,2700.177,-1834.009,4.838899,0,0,0,100,0),
(@PATH,5,2710.015,-1832.177,4.838899,0,0,0,100,0),
(@PATH,6,2721.081,-1832.136,4.838899,0,0,0,100,0),
(@PATH,7,2732.511,-1831.47,4.838899,0,0,0,100,0),
(@PATH,8,2737.419,-1830.768,4.838899,0,0,0,100,0),
(@PATH,9,2732.511,-1831.47,4.838899,0,0,0,100,0),
(@PATH,10,2721.081,-1832.136,4.838899,0,0,0,100,0);
-- Pathing for Conquest Hold Berserker Entry: 27500
SET @NPC := 105821;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2738.191,`position_y`=-1784.905,`position_z`=5.87062 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2734.5,-1775.514,6.962903,0,0,0,100,0),
(@PATH,2,2738.191,-1784.905,5.87062,0,0,0,100,0),
(@PATH,3,2741.883,-1793.762,5.804742,0,0,0,100,0),
(@PATH,4,2746.422,-1807.012,5.22166,0,0,0,100,0),
(@PATH,5,2748.496,-1816.049,5.223536,0,0,0,100,0),
(@PATH,6,2750.136,-1823.419,5.425339,0,0,0,100,0),
(@PATH,7,2748.496,-1816.049,5.223536,0,0,0,100,0),
(@PATH,8,2746.422,-1807.012,5.22166,0,0,0,100,0),
(@PATH,9,2741.883,-1793.762,5.804742,0,0,0,100,0),
(@PATH,10,2738.191,-1784.905,5.87062,0,0,0,100,0);
-- Pathing for Conquest Hold Berserker Entry: 27500
SET @NPC := 105859;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2753.638,`position_y`=-1895.846,`position_z`=5.03679 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2754.177,-1888.177,5.087607,0,0,0,100,0),
(@PATH,2,2754.56,-1879.827,5.126619,0,0,0,100,0),
(@PATH,3,2754.854,-1867.842,5.131936,0,0,0,100,0),
(@PATH,4,2754.627,-1856.456,5.450566,0,0,0,100,0),
(@PATH,5,2753.946,-1848.716,5.450566,0,0,0,100,0),
(@PATH,6,2751.545,-1837.476,5.39562,0,0,0,100,0),
(@PATH,7,2753.931,-1848.54,5.450566,0,0,0,100,0),
(@PATH,8,2754.627,-1856.456,5.450566,0,0,0,100,0),
(@PATH,9,2754.854,-1867.842,5.131936,0,0,0,100,0),
(@PATH,10,2754.56,-1879.827,5.126619,0,0,0,100,0),
(@PATH,11,2754.177,-1888.177,5.087607,0,0,0,100,0),
(@PATH,12,2753.638,-1895.846,5.03679,0,0,0,100,0);
-- Pathing for Conquest Hold Berserker Entry: 27500
SET @NPC := 105810;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2805.754,`position_y`=-1824.487,`position_z`=10.76279 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2811.704,-1833.185,11.26279,0,0,0,100,0),
(@PATH,2,2825.015,-1839.888,11.25652,0,0,0,100,0),
(@PATH,3,2811.704,-1833.185,11.26279,0,0,0,100,0),
(@PATH,4,2805.754,-1824.487,10.76279,0,0,0,100,0),
(@PATH,5,2806.472,-1815.43,10.76279,0,0,0,100,0),
(@PATH,6,2806.509,-1806.167,10.63779,0,0,0,100,0),
(@PATH,7,2806.472,-1815.43,10.76279,0,0,0,100,0),
(@PATH,8,2805.754,-1824.487,10.76279,0,0,0,100,0);
-- Pathing for Conquest Hold Berserker Entry: 27500
SET @NPC := 105750;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2691.886,`position_y`=-1764.669,`position_z`=9.601107 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2681.84,-1768.02,9.601107,0,0,0,100,0),
(@PATH,2,2691.886,-1764.669,9.601107,0,0,0,100,0),
(@PATH,3,2705.537,-1760.065,9.601107,0,0,0,100,0),
(@PATH,4,2714.329,-1758.981,9.601107,0,0,0,100,0),
(@PATH,5,2705.537,-1760.065,9.601107,0,0,0,100,0),
(@PATH,6,2691.886,-1764.669,9.601107,0,0,0,100,0);
-- Pathing for Conquest Hold Berserker Entry: 27500
SET @NPC := 105854;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2683.998,`position_y`=-1873.36,`position_z`=14.20639 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2681.924,-1863.327,14.19665,0,0,0,100,0),
(@PATH,2,2691.357,-1860.246,13.94065,0,0,0,100,0),
(@PATH,3,2705.164,-1860.508,13.85815,0,0,0,100,0),
(@PATH,4,2706.999,-1867.629,13.94356,0,0,0,100,0),
(@PATH,5,2702.301,-1873.661,13.86975,0,0,0,100,0),
(@PATH,6,2690.931,-1875.133,13.94601,0,0,0,100,0),
(@PATH,7,2683.998,-1873.36,14.20639,0,0,0,100,0);

-- Pathing for Westfall Brigade Marine Entry: 27501
SET @NPC := 105933;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2670.551,`position_y`=-2010.984,`position_z`=18.17214 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2673.404,-2006.613,18.2068,0,0,0,100,0),
(@PATH,2,2670.639,-2010.848,18.17313,0,0,0,100,0),
(@PATH,3,2667.047,-2016.413,18.20223,0,0,0,100,0),
(@PATH,4,2670.551,-2010.984,18.17214,0,0,0,100,0);
-- Pathing for Westfall Brigade Marine Entry: 27501
SET @NPC := 105932;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2633.481,`position_y`=-1987.501,`position_z`=8.764043 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2632.814,-1993.635,8.538836,0,0,0,100,0),
(@PATH,2,2638.163,-1998.093,8.282835,0,0,0,100,0),
(@PATH,3,2643.552,-2000.655,8.280496,0,0,0,100,0),
(@PATH,4,2646.837,-1997.753,8.30875,0,0,0,100,0),
(@PATH,5,2649.113,-1994.113,8.310638,0,0,0,100,0),
(@PATH,6,2649.836,-1989.002,8.284628,0,0,0,100,0),
(@PATH,7,2645.433,-1984.703,8.336969,0,0,0,100,0),
(@PATH,8,2638.931,-1981.989,8.592985,0,0,0,100,0),
(@PATH,9,2633.481,-1987.501,8.764043,0,0,0,100,0);

-- Missing spawn for Purkom "Venture Coin Vendor" Horde
DELETE FROM `creature` WHERE `id`=27730;
DELETE FROM `creature` WHERE `guid`=107018 AND `id`=27511;
INSERT INTO creature (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(107018,27730,571,1,1,0,0,2492.467,-1839.655,11.72851,5.532694,120,0,0,1,0,0);

-- Rogue Voidwalkers Shouldn't have weapons
UPDATE `creature_template` SET `equipment_id`=0 WHERE `entry`=16974;

-- Add Missing Spawn
DELETE FROM `creature` WHERE `guid` IN (13425,13426,13427,13428,14241);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
-- Bubb Lazarr
(13425,27628,571,1,1,0,0,2404.771,-1823.437,1.99793,5.078908,300,0,0,1,0,0),
-- Rocket Propelled Warhead
(13426,27593,571,1,1,0,0,2394.92358,-1832.18921,-1.69907868,2.687807,300,0,0,1,0,0),
(13427,27593,571,1,1,0,0,2396.13013,-1829.49475,-1.6780616,2.75762,300,0,0,1,0,0),
(13428,27593,571,1,1,0,0,2397.40283,-1826.75,-1.65229559,2.72271371,300,0,0,1,0,0),
(14241,27593,571,1,1,0,0,2398.62329,-1824.14063,-1.66098964,2.740167,300,0,0,1,0,0);

-- Template updates Rocket Propelled Warhead
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`InhabitType`=4,`unit_flags`=`unit_flags`|16384,`speed_walk`=12,`speed_run`=4.28571 WHERE `entry`=27593;

UPDATE `creature_model_info` SET `bounding_radius`=0.534723,`combat_reach`=3.5,`gender`=2 WHERE `modelid`=26611; -- Rocket Propelled Warhead

DELETE FROM `creature_template_addon` WHERE `entry`=27593;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(27593,0,0,1,0, NULL); -- Rocket Propelled Warhead

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=27593;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`, `aura_required`, `aura_forbidden`, `user_type`) VALUES
(27593, 49177, 0, 0, 0, 1, 0, 0, 0); -- Ride Rocket Propelled Warhead

-- Fix requirements for Element 115 from Nayd
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=4 AND `SourceEntry`=37664;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(4, 24095, 37664, 0, 9, 12433, 0, 0, 0, '', 'Element 115 - Seeking Solvent'),
(4, 24095, 37664, 1, 9, 12434, 0, 0, 0, '', 'Element 115 - Always Seeking Solvent'),
(4, 24095, 37664, 2, 9, 12443, 0, 0, 0, '', 'Element 115 - Seeking Solvent'),
(4, 24095, 37664, 3, 9, 12446, 0, 0, 0, '', 'Element 115 - Always Seeking Solvent'),
(4, 24095, 37664, 4, 9, 12437, 0, 0, 0, '', 'Element 115 - Riding the Red Rocket A'),
(4, 24095, 37664, 5, 9, 12432, 0, 0, 0, '', 'Element 115 - Riding the Red Rocket H');
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=100 WHERE `entry`=24095 AND `item`=37664;

-- Add some missing Azure Scalebane Spawns to crystalsong Forest
DELETE FROM `creature` WHERE `guid` IN (6499,6627,7630,10504,12599,12954,13423,13424);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`unit_flags`,`dynamicflags`) VALUES
(6499,31402,571,1,1,0,0,5220.886,591.7798,187.861328,4.866286,180,10,0,1,0,1,0,0),
(6627,31402,571,1,1,0,0,5344.32,595.7,183.07399,4.99164152,180,10,0,1,0,1,0,0),
(7630,31402,571,1,1,0,0,5411.67773,623.1622,178.355133,0.87266463,180,10,0,1,0,1,0,0),
(10504,31402,571,1,1,0,0,5434.40332,783.9654,182.770508,0.5726554,180,10,0,1,0,1,0,0),
(12599,31402,571,1,1,0,0,5464.40771,716.290344,171.820313,2.65290046,180,10,0,1,0,1,0,0),
(12954,31402,571,1,1,0,0,5573.34326,862.8543,161.738586,1.48352981,180,10,0,1,0,1,0,0),
(13423,31402,571,1,1,0,0,5659.52734,987.839844,174.5677,0.314159274,180,0,0,1,0,0,570688256,32),
(13424,31402,571,1,1,0,0,5660.18652,1028.454,174.562653,2.79252672,180,0,0,1,0,0,570688256,32);
-- Addons for dead appearance
DELETE FROM `creature_addon` WHERE `guid` IN (13423,13424);
INSERT INTO `creature_addon` (`guid`,`bytes2`,`auras`) VALUES
(13423,1,29266),
(13424,1,29266);
UPDATE `creature_model_info` SET `bounding_radius`=0.465,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=25195; -- Azure Scalebane
DELETE FROM `creature_template_addon` WHERE `entry`=31402;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31402,0,0,1,0, NULL); -- Azure Scalebane
