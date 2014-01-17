UPDATE `creature_template` SET `equipment_id`=36561 WHERE `entry` IN (36561,36571);

DELETE FROM `creature_equip_template` WHERE `entry`=36561;
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(36561, 38488, 0, 0); -- Onyxian Lair Guard
