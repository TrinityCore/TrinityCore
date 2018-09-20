-- [NPC][WotlK] Iron Sentinel <Servant of Loken>, missing spawn 
SET @GUID := 74019;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@GUID, 29984, 571, 67, 4446, 1, 1, 27092, 0, 8474.9, -1601.15, 1037.59, 0.126558, 300, 0, 0, 50400, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` = @GUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@GUID, 0, 0, 0, 1, 333, "");
