SET @POOLID := 40021;

DELETE FROM `quest_pool_template` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_template` (`poolId`, `numActive`, `description`) VALUES 
(@POOLID, 1, 'Armand Cromwell - Daily Quests');

DELETE FROM `quest_pool_members` WHERE `poolId`=@POOLID;
DELETE FROM `quest_pool_members` WHERE `questId` IN (29317, 29319, 29320, 29322, 29361);
INSERT INTO `quest_pool_members` (`questId`, `poolId`, `poolIndex`, `description`) VALUES 
(29317, @POOLID, 0, 'Fish Head'),
(29319, @POOLID, 1, 'Tadpole Terror'),
(29320, @POOLID, 2, 'Like Pike?'),
(29322, @POOLID, 3, 'Time for Slime'),
(29361, @POOLID, 4, 'Moat Monster!');

UPDATE `quest_template_addon` SET `RequiredSkillID` = 356, `RequiredSkillPoints` = 1 WHERE `ID` IN (29317, 29319, 29320, 29322, 29361);
