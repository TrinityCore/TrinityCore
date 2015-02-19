--
SET @newestguid := 45208;
DELETE FROM `creature` WHERE `guid`=@newestguid AND `id`=25654;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@newestguid, 25654, 571, 1, 1, 0, 0, 4207.15, 4057.02, 91.6273, 1.38362, 300, 0, 0, 42, 0, 0, 0, 0, 0);
