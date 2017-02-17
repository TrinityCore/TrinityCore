-- ==================
-- Isle of Quel'Danas -- 9
-- ==================

DELETE FROM `pool_template` WHERE `entry`= 959; -- Reuse poolentry 959 from previous commit
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(959,4,'Master Herb Pool - Isle of Quel''Danas'); -- 9 Total Spawns

DELETE FROM `gameobject` WHERE `guid` IN (13539,23985,27591,27592,27617,27742,27743);
DELETE FROM `gameobject_addon` WHERE `guid` IN (13539,23985,27591,27592,27617,27742,27743);

SET @QUELDANASGUID := 7400; -- 9 GUIDs SET BY TC
DELETE FROM `gameobject` WHERE `guid` BETWEEN @QUELDANASGUID+1 AND @QUELDANASGUID+9;
INSERT INTO `gameobject` (guid, id, map, spawnMask, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state) VALUES
((@QUELDANASGUID := @QUELDANASGUID + 1), 181280, 530, 1, 11621.3, -7061.17, 1.39133, 1.51908, 0, 0, 0, 0, 60, 255, 1),
((@QUELDANASGUID := @QUELDANASGUID + 1), 181281, 530, 1, 11743.6, -7218.65, 9.22726, 0.90757, 0, 0, 0, 0, 60, 255, 1),
((@QUELDANASGUID := @QUELDANASGUID + 1), 181281, 530, 1, 12330.4, -7352.54, 2.83294, -0.977383, 0, 0, 0, 0, 60, 255, 1),
((@QUELDANASGUID := @QUELDANASGUID + 1), 181281, 530, 1, 12696.2, -7066.53, 19.3097, 4.20522, 0, 0, 0, 0, 60, 255, 1),
((@QUELDANASGUID := @QUELDANASGUID + 1), 181281, 530, 1, 12599, -6930.48, 5.01902, 4.00416, 0, 0, 0, 0, 60, 255, 1),
((@QUELDANASGUID := @QUELDANASGUID + 1), 181281, 530, 1, 12588, -6619.87, 12.4062, 1.5278, 0, 0, 0, 0, 60, 255, 1),
((@QUELDANASGUID := @QUELDANASGUID + 1), 181281, 530, 1, 11744.2, -7218.29, 9.25358, 2.99719, 0, 0, 0, 0, 60, 255, 1),
((@QUELDANASGUID := @QUELDANASGUID + 1), 181281, 530, 1, 12330, -7353.95, 2.96635, 5.98563, 0, 0, 0, 0, 60, 255, 1),
((@QUELDANASGUID := @QUELDANASGUID + 1), 181281, 530, 1, 12669.1, -7420.74, 2.88691, 0.790224, 0, 0, 0, 0, 60, 255, 1);

-- Individual Gameobject Spawn Pools
DELETE FROM `pool_gameobject` WHERE `pool_entry` = 959;
SET @POOL_QUELDANASGUID := 7400; -- SAME AS @QUELDANASGUID IN THE BEGINNING
DELETE FROM `pool_gameobject` WHERE `guid` BETWEEN @POOL_QUELDANASGUID+1 AND @POOL_QUELDANASGUID+9;
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
((@POOL_QUELDANASGUID := @POOL_QUELDANASGUID + 1), 959, 0, 'Isle of QuelDanas - Nightmare Vine'),
((@POOL_QUELDANASGUID := @POOL_QUELDANASGUID + 1), 959, 0, 'Isle of QuelDanas - Mana Thistle'),
((@POOL_QUELDANASGUID := @POOL_QUELDANASGUID + 1), 959, 0, 'Isle of QuelDanas - Mana Thistle'),
((@POOL_QUELDANASGUID := @POOL_QUELDANASGUID + 1), 959, 0, 'Isle of QuelDanas - Mana Thistle'),
((@POOL_QUELDANASGUID := @POOL_QUELDANASGUID + 1), 959, 0, 'Isle of QuelDanas - Mana Thistle'),
((@POOL_QUELDANASGUID := @POOL_QUELDANASGUID + 1), 959, 0, 'Isle of QuelDanas - Mana Thistle'),
((@POOL_QUELDANASGUID := @POOL_QUELDANASGUID + 1), 959, 0, 'Isle of QuelDanas - Mana Thistle'),
((@POOL_QUELDANASGUID := @POOL_QUELDANASGUID + 1), 959, 0, 'Isle of QuelDanas - Mana Thistle'),
((@POOL_QUELDANASGUID := @POOL_QUELDANASGUID + 1), 959, 0, 'Isle of QuelDanas - Mana Thistle');
