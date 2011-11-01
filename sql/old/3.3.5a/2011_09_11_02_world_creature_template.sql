UPDATE `creature_template` SET `exp`=0,`speed_run`=0.78571 WHERE `entry`=28239; -- Arcane Beam
DELETE FROM `creature_template_addon` WHERE `entry`=28239;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28239,0,0,1,0, '51019'); -- Arcane Beam
