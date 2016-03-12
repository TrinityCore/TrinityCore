--
SET @CGUID			 := 142705;

DELETE FROM `creature` WHERE `id`=24439;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@CGUID+0, 24439, 571, 1, 1, 24780, 0, 2088.714, -3263.196, 82.50323, 0.2792527, 120, 0, 0, 42, 0, 0, 0, 0, 0), -- Sack of Relics (Area: 0)
(@CGUID+1, 24439, 571, 1, 1, 24780, 0, 2047.712, -3236.201, 62.82506, 3.682645, 120, 0, 0, 42, 0, 0, 0, 0, 0), -- Sack of Relics (Area: Steel Gate)
(@CGUID+2, 24439, 571, 1, 1, 24780, 0, 2017.764, -3243.003, 74.95174, 3.246312, 120, 0, 0, 42, 0, 0, 0, 0, 0), -- Sack of Relics (Area: Steel Gate)
(@CGUID+3, 24439, 571, 1, 1, 24780, 0, 2068.706, -3318.71, 98.2312, 5.72468, 120, 0, 0, 42, 0, 0, 0, 0, 0), -- Sack of Relics (Area: Steel Gate)
(@CGUID+4, 24439, 571, 1, 1, 24780, 0, 1996.727, -3323.912, 99.77941, 5.532694, 120, 0, 0, 42, 0, 0, 0, 0, 0), -- Sack of Relics (Area: Steel Gate)
(@CGUID+5, 24439, 571, 1, 1, 24780, 0, 2068.706, -3318.71, 98.2312, 5.72468, 120, 0, 0, 42, 0, 0, 0, 0, 0); -- Sack of Relics (Area: 0)
