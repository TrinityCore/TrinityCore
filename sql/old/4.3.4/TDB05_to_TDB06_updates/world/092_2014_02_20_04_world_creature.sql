-- 
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|512 WHERE `entry`=18672; -- Thomas Yance
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33600 WHERE `entry`=18093; -- Tarren Mill Protector
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33600 WHERE `entry`=18092; -- Tarren Mill Guardsman

DELETE FROM `creature_equip_template` WHERE `entry`=18672;
DELETE FROM `creature_equip_template` WHERE `entry`=18093;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES 
(18672,1,1903,0,0), -- Equipment of 18672 (Thomas Yance)
(18093,1,5491,0,0), -- Equipment of 18093 (Tarren Mill Protector)
(18092,1,1899,1984,0); -- Equipment of 18092 (Tarren Mill Guardsman)

-- Model data 18064 (creature 18672 (Thomas Yance))
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5 WHERE `modelid`=18064; -- Thomas Yance

-- Addon data for creature 18672 (Thomas Yance)
DELETE FROM `creature_template_addon` WHERE `entry`=18672;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(18672,0,0,257,0, NULL), -- Thomas Yance
(18093,0,0,1,0, NULL), -- Tarren Mill Protector
(18092,0,0,1,0, NULL); -- Tarren Mill Guardsman
