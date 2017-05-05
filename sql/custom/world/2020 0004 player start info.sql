-- playercreateinfo

DELETE FROM `world`.`playercreateinfo` WHERE `race` = 3 AND `class` = 6;
DELETE FROM `world`.`playercreateinfo` WHERE `race` = 4 AND `class` = 6;
DELETE FROM `world`.`playercreateinfo` WHERE `race` = 6 AND `class` = 6;

UPDATE `world`.`playercreateinfo` SET `map` = 0, `zone` = 12, `position_x` = -8949.95, `position_y` = -132.493, `position_z` = 83.5312, `orientation` = 0 WHERE `race` = 1 AND `class` = 6;
UPDATE `world`.`playercreateinfo` SET `map` = 1, `zone` = 14, `position_x` = -618.518, `position_y` = -4251.67, `position_z` = 38.718, `orientation` = 0 WHERE `race` = 2 AND `class` = 6;
UPDATE `world`.`playercreateinfo` SET `map` = 0, `zone` = 85, `position_x` = 1676.71, `position_y` = 1678.31, `position_z` = 121.67, `orientation` = 2.70526 WHERE `race` = 5 AND `class` = 6;
UPDATE `world`.`playercreateinfo` SET `position_x` = -6240, `position_y` = 331, `position_z` = 383 WHERE `race` = 7 AND `class` = 1;
UPDATE `world`.`playercreateinfo` SET `map` = 0, `zone` = 1, `position_x` = -6240, `position_y` = 331, `position_z` = 383, `orientation` = 0 WHERE `race` = 7 AND `class` = 6;
UPDATE `world`.`playercreateinfo` SET `map` = 1, `zone` = 14, `position_x` = -618.518, `position_y` = -4251.67, `position_z` = 38.718, `orientation` = 0 WHERE `race` = 8 AND `class` = 6;
UPDATE `world`.`playercreateinfo` SET `map` = 530, `zone` = 3431, `position_x` = 10349.6, `position_y` = -6357.29, `position_z` = 33.4026, `orientation` = 5.31605 WHERE `race` = 10 AND `class` = 6;
UPDATE `world`.`playercreateinfo` SET `map` = 530, `zone` = 3526, `position_x` = -3961.64, `position_y` = -13931.2, `position_z` = 100.615, `orientation` = 2.08364 WHERE `race` = 11 AND `class` = 6;

INSERT INTO `world`.`playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`)
VALUES (1, 3, 0, 12, -8949.95, -132.493, 83.5312, 0);
INSERT INTO `world`.`playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`)
VALUES (1, 7, 0, 12, -8949.95, -132.493, 83.5312, 0);
INSERT INTO `world`.`playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`)
VALUES (2, 8, 1, 14, -618.518, -4251.67, 38.718, 0);
INSERT INTO `world`.`playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`)
VALUES (3, 7, 0, 1, -6240.32, 331.033, 382.758, 6.17716);
INSERT INTO `world`.`playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`)
VALUES (4, 8, 1, 141, 10311.3, 832.463, 1326.41, 5.69632);
INSERT INTO `world`.`playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`)
VALUES (5, 3, 0, 85, 1676.71, 1678.31, 121.67, 2.70526);
INSERT INTO `world`.`playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`)
VALUES (8, 9, 1, 14, -618.518, -4251.67, 38.718, 0);
INSERT INTO `world`.`playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`)
VALUES (10, 1, 530, 3431, 10349.6, -6357.29, 33.4026, 5.31605);
INSERT INTO `world`.`playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`)
VALUES (11, 9, 530, 3526, -3961.64, -13931.2, 100.615, 2.08364);