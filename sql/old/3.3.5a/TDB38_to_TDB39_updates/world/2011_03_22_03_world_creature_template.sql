-- Template updates for creature 33778 (Tournament Hippogryph)
UPDATE `creature_template` SET `vehicleid`=108,`InhabitType`=4 WHERE `entry`=33778; -- Tournament Hippogryph
-- Model data 22471 (creature 33778 (Tournament Hippogryph))
UPDATE `creature_model_info` SET `bounding_radius`=0,`combat_reach`=0,`gender`=2 WHERE `modelid`=22471; -- Tournament Hippogryph
-- Addon data for creature 33778 (Tournament Hippogryph)
DELETE FROM `creature_template_addon` WHERE `entry`=33778;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33778,0,1,1,0, NULL); -- Tournament Hippogryph
