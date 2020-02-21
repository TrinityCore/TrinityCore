UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`= 35592;
DELETE FROM `creature_addon` WHERE `guid`= 259779;
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(259779, '78173');
