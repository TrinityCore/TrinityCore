-- Warden Belamoore
DELETE FROM `smart_scripts` WHERE `entryorguid`=2415 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2415,0,1,0,9,0,100,0,0,10,14000,19000,11,20828,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - Within 0-10 Range - Cast Cone of Cold");

-- Dalaran Theurgist
UPDATE `smart_scripts` SET `event_flags`=0, `action_param2`=0 WHERE `entryorguid`=2272 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2272 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2272,0,3,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Dalaran Theurgist - Just Summoned - Start Attacking");

-- Spirit of Old
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2623;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2623 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2623,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Spirit of Old - Just Summoned - Start Attacking");

-- Dalaran Summoner
UPDATE `smart_scripts` SET `event_param3`=3200 WHERE `entryorguid`=2358 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=2358 AND `source_type`=0 AND `id` IN (1,3);

-- Dalaran Shield Guard
DELETE FROM `smart_scripts` WHERE `entryorguid`=2271 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2271,0,2,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Dalaran Shield Guard - Just Summoned - Start Attacking");

-- Mountain Yeti
DELETE FROM `smart_scripts` WHERE `entryorguid`=2250 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2250,0,0,0,0,0,100,0,4000,11000,10000,17000,11,3131,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mountain Yeti - In Combat - Cast Frost Breath");

-- Giant Yeti
DELETE FROM `smart_scripts` WHERE `entryorguid`=2251 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2251,0,0,0,0,0,100,0,4000,11000,10000,17000,11,3131,0,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Yeti - In Combat - Cast Frost Breath");

-- Crushridge Ogres
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid` IN (2252,2253,2254,2255,2287,2416) AND `source_type`=0 AND `id`=0;

-- Crushridge Mage
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=2255 AND `source_type`=0 AND `id`=2;

-- Crushridge Plunderer
DELETE FROM `smart_scripts` WHERE `entryorguid`=2416 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2416,0,1,0,0,0,100,0,5000,7000,8000,12000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crushridge Plunderer - In Combat - Cast Cleave");

-- Crushridge Enforcer
DELETE FROM `smart_scripts` WHERE `entryorguid`=2256 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2256,0,1,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Enforcer - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=2256;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2256,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Crushridge Enforcer"),
(2256,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Crushridge Enforcer"),
(2256,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Crushridge Enforcer");

-- Mug'thol
DELETE FROM `smart_scripts` WHERE `entryorguid`=2257 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2257,0,0,0,0,0,100,0,5000,7000,9000,13000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mug'thol - In Combat - Cast Strike"),
(2257,0,1,0,0,0,100,0,9000,12000,18000,24000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mug'thol - In Combat - Cast Demoralizing Shout");

-- Lo'Grosh
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=2453 AND `source_type`=0;

-- Syndicate Assassin
DELETE FROM `smart_scripts` WHERE `entryorguid`=2246 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2246,0,1,0,0,0,100,0,4000,14000,8000,18000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Assassin - In Combat - Cast Poison");

-- Syndicate Thief
DELETE FROM `smart_scripts` WHERE `entryorguid`=2241 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2241,0,0,0,0,0,100,0,4000,12000,18000,26000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Thief - In Combat - Cast Disarm"),
(2241,0,1,0,0,0,100,0,4000,14000,8000,18000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Thief - In Combat - Cast Poison");

-- Drunken Footpad
DELETE FROM `smart_scripts` WHERE `entryorguid`=2440 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2440,0,0,0,0,0,100,0,5000,8000,9000,15000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drunken Footpad - In Combat - Cast Strike"),
(2440,0,1,0,0,0,100,0,5000,25000,30000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drunken Footpad - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=2440 AND `GroupID`=0 AND `ID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2440,0,1,"Southshore stout, how do I love thee? Let me count the ways...",12,7,100,0,0,0,606,0,"Drunken Footpad");

-- Pooling for Araga
DELETE FROM `creature` WHERE `guid` IN (82864, 82870);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(82864,14222,0,0,0,1,1,0,0,-198.314,-306.058,157.444,6.23466,72000,15,0,1342,0,1,0,0,0,"",0),
(82870,14222,0,0,0,1,1,0,0,-105.223,-104.623,137.257,3.78422,72000,15,0,1342,0,1,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=1117;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(1117,1,"Araga");

DELETE FROM `pool_creature` WHERE `pool_entry`=1117;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(82864,1117,0,"Araga (14222) - Spawn 1"),
(82870,1117,0,"Araga (14222) - Spawn 2"),
(17066,1117,0,"Araga (14222) - Spawn 3");

UPDATE `creature` SET `position_x`=139.819, `position_y`=-63.8495, `position_z`=101.407, `spawndist`=10, `MovementType`=1 WHERE `guid`=17066;

-- Pathing for Gravis Slipknot
UPDATE `creature` SET `position_x`=688.872, `position_y`=-937.22, `position_z`=164.95, `spawndist`=0, `MovementType`=2 WHERE `guid`=86756;

DELETE FROM `creature_addon` WHERE `guid`=86756;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(86756,867560,0,0,1,0,"");

DELETE FROM `waypoint_data` WHERE `id`=867560;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(867560,1,688.872,-937.22,164.95,0,0,0,0,100,0),
(867560,2,681.325,-937.484,164.935,0,0,0,0,100,0),
(867560,3,680.741,-951.257,164.289,0,0,0,0,100,0),
(867560,4,665.078,-953.5,164.342,0,0,0,0,100,0),
(867560,5,657.901,-957.89,164.342,0,0,0,0,100,0),
(867560,6,654.432,-964.331,164.531,0,0,0,0,100,0),
(867560,7,657.184,-973.619,164.927,0,0,0,0,100,0),
(867560,8,661.672,-977.083,164.781,0,0,0,0,100,0),
(867560,9,671.532,-975.53,164.356,0,0,0,0,100,0),
(867560,10,686.471,-965.257,164.29,0,0,0,0,100,0),
(867560,11,708.6,-961.881,164.292,0,0,0,0,100,0),
(867560,12,732.751,-960.906,166.226,0,0,0,0,100,0),
(867560,13,732.826,-947.077,165.326,0,0,0,0,100,0),
(867560,14,742.555,-946.404,166.228,0,0,0,0,100,0),
(867560,15,745.466,-953.826,166.228,0,0,0,0,100,0),
(867560,16,746.201,-960.484,166.228,0,0,0,0,100,0),
(867560,17,746.416,-949.084,166.228,0,0,0,0,100,0),
(867560,18,742.495,-947.208,166.228,0,0,0,0,100,0),
(867560,19,733.151,-946.913,165.326,0,0,0,0,100,0),
(867560,20,732.868,-960.773,166.227,0,0,0,0,100,0),
(867560,21,717.405,-961.266,166.227,0,0,0,0,100,0),
(867560,22,708.584,-960.933,164.299,0,0,0,0,100,0),
(867560,23,684.935,-954.861,164.292,0,0,0,0,100,0),
(867560,24,681.499,-946.261,164.935,0,0,0,0,100,0),
(867560,25,681.944,-937.438,164.936,0,0,0,0,100,0),
(867560,26,688.632,-937.48,164.95,0,0,0,0,100,0),
(867560,27,688.207,-926.509,164.325,0,0,0,0,100,0),
(867560,28,696.862,-921.751,164.706,0,0,0,0,100,0),
(867560,29,697.017,-913.874,168.168,0,0,0,0,100,0),
(867560,30,691.865,-913.407,168.173,0,0,0,0,100,0),
(867560,31,691.63,-922.2,171.806,0,0,0,0,100,0),
(867560,32,688.334,-925.043,171.806,0,0,0,0,100,0),
(867560,33,691.635,-924.719,171.806,0,0,0,0,100,0),
(867560,34,691.644,-920.726,171.806,0,0,0,0,100,0),
(867560,35,691.839,-913.313,168.175,0,0,0,0,100,0),
(867560,36,697.023,-913.94,168.169,0,0,0,0,100,0),
(867560,37,696.323,-922.92,164.325,0,0,0,0,100,0),
(867560,38,688.325,-927.531,164.325,0,0,0,0,100,0),
(867560,39,688.301,-934.973,164.951,0,0,0,0,100,0);

-- Delete wrong spawns
DELETE FROM `creature` WHERE `guid` IN (16668,16669,17553,16806); -- These mobs are summoned by Dalaran Summoneres.
DELETE FROM `creature_addon` WHERE `guid` IN (16668,16669,17553,16806);
