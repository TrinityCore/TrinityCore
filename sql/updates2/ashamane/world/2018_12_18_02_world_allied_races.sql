UPDATE `playercreateinfo` SET map = 0, position_x = -8177.655273, position_y = 792.195435, position_z = 73.996414, orientation = 0.781548 WHERE race = 34;
UPDATE `playercreateinfo` SET map = 1, position_x = 1567.376343, position_y = -4189.125000, position_z = 53.679371, orientation = 2.287397 WHERE race = 36;

DELETE FROM `race_unlock_requirement` WHERE raceID IN (34, 36);
INSERT INTO `race_unlock_requirement` (raceID, expansion, achievementId) VALUES
(34, 8, 0),
(36, 8, 0);
