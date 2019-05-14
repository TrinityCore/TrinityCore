-- Spawn and Pathing for Commander Schnottz Entry: 47159 'TDB FORMAT' 
SET @NPC := 250021;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@NPC,47159,1,0,0,1,1,169,0,0,0,-10675.04,927.8924,26.33434,3.84814,120,0,0,1,0,2,0,0,0,'',0);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10675.04,927.8924,26.33434,0,0,0,0,100,0),
(@PATH,2,-10682.8,926.523,26.23682,0,0,0,0,100,0),
(@PATH,3,-10676.4,927.597,26.30432,0,0,0,0,100,0);
