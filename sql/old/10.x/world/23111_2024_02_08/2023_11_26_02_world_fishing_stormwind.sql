SET @POOLID = 40017;

DELETE FROM `quest_pool_template` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_template` (`poolId`, `numActive`, `description`) VALUES 
(@POOLID, 1, 'Catherine Leland - Daily Quests');

DELETE FROM `quest_pool_members` WHERE `questId` IN (26414, 26420, 26442, 26488, 26536);
INSERT INTO `quest_pool_members` (`questId`, `poolId`, `poolIndex`, `description`) VALUES 
(26414, @POOLID, 0, 'Hitting a Walleye'),
(26420, @POOLID, 1, 'Diggin'' for Worms'),
(26442, @POOLID, 2, 'Rock Lobster'),
(26488, @POOLID, 3, 'Big Gulp'),
(26536, @POOLID, 4, 'Thunder Falls');

UPDATE `quest_template_addon` SET `RequiredSkillID` = 356, `RequiredSkillPoints` = 1 WHERE `ID` IN (26414, 26420, 26442, 26488, 26536);
