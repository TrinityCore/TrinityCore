-- Template updates for creature 31798 (Athan)
-- Model data 23823 (creature 31798 (Athan))
UPDATE `creature_model_info` SET `bounding_radius`=2.06,`combat_reach`=0,`gender`=2 WHERE `modelid`=23823; -- Athan
-- Addon data for creature 31798 (Athan)
DELETE FROM `creature_template_addon` WHERE `entry`=31798;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31798,0,0,1,0, NULL); -- Athan
