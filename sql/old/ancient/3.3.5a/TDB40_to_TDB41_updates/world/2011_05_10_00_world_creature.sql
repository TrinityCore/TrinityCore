-- Trapdoor Crawler
UPDATE `creature` SET `modelid`=0 WHERE `id`=28221;
UPDATE `creature_model_info` SET `bounding_radius`=2,`combat_reach`=4.6,`gender`=1 WHERE `modelid`=18043;
DELETE FROM `creature_template_addon` WHERE `entry`=28221;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28221,0,0,1,0, '11959');
