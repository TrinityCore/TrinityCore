UPDATE `quest_template` SET `QuestType` = 0 WHERE (ID = 12641);

DELETE FROM `areatrigger` WHERE guid IN (43, 44);
INSERT INTO `areatrigger` VALUES
(43, 100002, 609, 1, 2383.80, -5645.20, 421.77, ""),
(44, 100002, 609, 1, 2390.11, -5640.82, 378.10, "");

DELETE FROM `areatrigger_teleport` WHERE Id IN (-43, -44);
INSERT INTO `areatrigger_teleport` VALUES
(-43, 3828, "DK begin Acherus to lower"),
(-44, 3827, "DK begin Acherus to upper");
