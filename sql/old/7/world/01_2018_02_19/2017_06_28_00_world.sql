-- 
-- Cenarion Emissary Jademoon
SET @CGUID = 452574;
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 15187, 0, 1, 169, -8338.65, 286.271, 156.916, 5.11218, 120, 0, 0);
UPDATE `creature` SET `PhaseGroup`=0 WHERE `PhaseGroup`=169;
UPDATE `creature` SET `PhaseId`=169 WHERE `PhaseId`=1;
