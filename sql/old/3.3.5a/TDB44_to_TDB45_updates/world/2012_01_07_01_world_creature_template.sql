-- Template updates for creature 36595 (Unleashed Soul)
UPDATE `creature_template` SET `exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`speed_walk`=1.111112,`speed_run`=0.71429 WHERE `entry`=36595; -- Unleashed Soul
-- Model data 14594 (creature 36595 (Unleashed Soul))
UPDATE `creature_model_info` SET `bounding_radius`=1.1,`combat_reach`=1.65,`gender`=2 WHERE `modelid`=14594; -- Unleashed Soul
-- Addon data for creature 36595 (Unleashed Soul)
DELETE FROM `creature_template_addon` WHERE `entry`=36595;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(36595,0,0,1,0, NULL); -- Unleashed Soul
