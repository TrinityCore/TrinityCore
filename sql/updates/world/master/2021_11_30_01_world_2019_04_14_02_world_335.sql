-- 
DELETE FROM `creature` WHERE `guid` IN (62786,62787);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnDifficulties`, `phaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`,`spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(62786, 16070, 0, '0', 0, 0, 0, -4641.5908203125, -1106.9654541015625, 501.388641357421875, 1.117010712623596191, 300, 0, 0, 0, 0, 0),
(62787, 16069, 0, '0', 0, 0, 0, -4643.2109375, -1105.5833740234375, 501.389617919921875, 0.820304751396179199, 300, 0, 0, 0, 0, 0);
UPDATE `creature` SET `guid`=1792,`position_x`=-4638.04931640625,`position_y`=-1108.7071533203125,`position_z`=501.31317138671875,`orientation`=0.820304751396179199 WHERE `guid`=307572;
