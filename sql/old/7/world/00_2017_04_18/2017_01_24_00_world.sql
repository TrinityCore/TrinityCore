-- Incorrect S.A.F.E Operatives positions
UPDATE `creature` SET `position_x`= -4982.51 ,`position_y`= 841.753,`position_z`= 276.3153, `orientation` =  4.639863 WHERE `guid`= 304615;
UPDATE `creature` SET `position_x`= -4986.46 ,`position_y`= 842.205,`position_z`= 276.3153, `orientation` =  4.510144 WHERE `guid`= 304616;
UPDATE `creature` SET `position_x`= -4990.14 ,`position_y`= 842.663,`position_z`= 276.3153, `orientation` =  4.867120 WHERE `guid`= 304617;

-- Injured Gnomes aura and state
UPDATE `creature_template_addon` SET `bytes1` = 3, `auras` = "80653" WHERE `entry`= 46447;
UPDATE `creature` SET `equipment_id` = 1 WHERE `guid` IN (304587,304588,304589,304593,304602,304609,304610,304615,304616,304617,304647,304653);

-- S.A.F.E Operatives missing equipment
DELETE FROM `creature_addon` WHERE `guid` IN (304587,304588,304589,304593,304602,304609,304610,304615,304616,304617,304647,304653);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(304587, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304588, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304589, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304593, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304602, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304609, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304610, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304615, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304616, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304617, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304647, 0, 0, 0, 2, 0, 0, 0, 0, 0),
(304653, 0, 0, 0, 2, 0, 0, 0, 0, 0);
--
