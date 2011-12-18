-- Closes https://github.com/TrinityCore/TrinityCore/issues/4007

SET @GUID := XXXXX; -- Set by TDB team (need 2)

-- Grand Apothecary Putress location
DELETE FROM `creature` WHERE (`guid`=@GUID);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@GUID+0, 28318, 530, 1, 1, '', '',  -1775.148438,  5548.291992,  -12.428190,  4.146070, 300, '', '', '', '', '', 2, '32768$B32768', 8);

-- Apothecary Karlov location
DELETE FROM `creature` WHERE (`guid`=@GUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@GUID+1, 29346, 1, 1, 1, '', '',  1925,  -4123.1899,  43.1780,  4.79965, 300, '', '', '', '', '', 2, 32768, 8);