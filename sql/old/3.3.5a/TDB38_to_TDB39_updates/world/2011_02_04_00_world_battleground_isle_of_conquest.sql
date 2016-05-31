-- Alliance Gunship Cannon
UPDATE `creature_template` SET `spell1`=69495,`VehicleId`=452 WHERE `entry`=34929;
-- Horde Gunship Cannon
UPDATE `creature_template` SET `spell1`=68825,`VehicleId`=453 WHERE `entry`=34935;
-- Keep Cannon
UPDATE `creature_template` SET `VehicleId`=160,`spell1`=67452,`spell2`=68169 WHERE `entry`=34944;
-- Catapult
UPDATE `creature_template` SET `VehicleId`=438,`spell1`=66218,`spell2`=66296 WHERE `entry`=34793;
-- Demolisher
UPDATE `creature_template` SET `VehicleId`=509,`spell1`=67442,`spell2`=68068 WHERE `entry`=34775;
-- Siege Engine
UPDATE `creature_template` SET `VehicleId`=447,`spell1`=67816,`spell2`=69502 WHERE `entry`=34776;
-- Siege Engine
UPDATE `creature_template` SET `VehicleId`=436,`spell1`=67816,`spell2`=69502 WHERE `entry`=35069;
-- Glaive Thrower
UPDATE `creature_template` SET `VehicleId`=447,`spell1`=68827,`spell2`=69515 WHERE `entry`=34802;
-- Glaive Thrower
UPDATE `creature_template` SET `VehicleId`=447,`spell1`=68827,`spell2`=69515 WHERE `entry`=35273;
-- Flame Turret
UPDATE `creature_template` SET `spell1`=68832 WHERE `entry`=34778;
-- Flame Turret
UPDATE `creature_template` SET `spell1`=68832 WHERE `entry`=36356;
-- Siege Turret
UPDATE `creature_template` SET `spell1`=67462,`spell2`=69505 WHERE `entry`=34777;
-- Siege Turret
UPDATE `creature_template` SET `spell1`=67462,`spell2`=69505 WHERE `entry`=36355;
-- Catapult speed
UPDATE `creature_template` SET `speed_run`=2.428571,`speed_walk`=2.8 WHERE `entry`=34793;

-- Update alliance boss faction
UPDATE `creature_template` SET `faction_A`=84, `faction_H`=84 WHERE `entry`=34924;
-- Update horde boss faction
UPDATE `creature_template` SET `faction_A`=83, `faction_H`=83 WHERE `entry`=34922;
-- Update Kor Kron Guard faction
UPDATE `creature_template` SET `faction_A`=83, `faction_H`=83 WHERE `entry`=34918;
-- Update Npc Seven TH Legion Infantry faction
UPDATE `creature_template` SET `faction_A`=84, `faction_H`=84 WHERE `entry`=34919;

-- those doors are not selectables
UPDATE `gameobject_template` SET `flags`=0x00000021 WHERE `entry` IN (195223,195703,195491,195451,195452,195437,195436);

-- alliance bombs, they can be only used by the horde
UPDATE `gameobject_template` SET `faction`=1995 WHERE `entry`=195332;
-- horde bombs, they can be only used by the alliance
UPDATE `gameobject_template` SET `faction`=1997 WHERE `entry`=195333;

-- horde teleporters
UPDATE `gameobject_template` SET `faction`=1995 WHERE `entry` IN  (195314,195313);
-- alliance teleporters
UPDATE `gameobject_template` SET `faction`=1997 WHERE `entry` IN (195315,195316);

-- Achievement Glaive Grave
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=12183;

-- Achievement Mowed Down
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (12068,12114);

-- Refinery's and Quarry's spells.
DELETE FROM `spell_area` WHERE `spell` IN (68719,68720);
INSERT INTO `spell_area` (`spell`,`area`) VALUES
(68719,4741),
(68719,4747),
(68719,4748),
(68719,4749),
(68719,4750),
(68719,4751),
(68719,4752),
(68719,4753),
(68719,4710),
(68720,4741),
(68720,4747),
(68720,4748),
(68720,4749),
(68720,4750),
(68720,4751),
(68720,4752),
(68720,4710),
(68720,4753);
