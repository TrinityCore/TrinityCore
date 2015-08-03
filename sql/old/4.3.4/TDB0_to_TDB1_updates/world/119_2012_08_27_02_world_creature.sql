SET @GUID = 42638; -- Set by TDB team (need X)
DELETE FROM `creature` WHERE `guid`=@GUID AND `id`=7172;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID,7172,70,1,1,0,0,150.466,306.014,-49.543,5.2359,300,0,0,1,0,0,0,0,0);
