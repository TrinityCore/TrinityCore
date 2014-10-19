--
SET @GUID = 271994;
DELETE FROM `creature` WHERE `guid` = @GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, 
`spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID, 37113, 0, 1, 1, 0, 0, -6245.788, 305.4635, 383.9363, 2.565634, 300, 0, 0, 42, 0, 0, 0, 0, 0);
