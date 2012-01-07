DELETE FROM `gameobject_questrelation` WHERE `quest` IN (12345, 12377);
INSERT INTO `gameobject_questrelation` VALUES
(190035, 12345),
(190079, 12377);
DELETE FROM `gameobject_involvedrelation` WHERE `quest` IN (12345, 12377);
INSERT INTO `gameobject_involvedrelation` VALUES
(190035, 12345),
(190079, 12377);
