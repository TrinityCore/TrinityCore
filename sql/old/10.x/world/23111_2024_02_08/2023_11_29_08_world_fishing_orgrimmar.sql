SET @POOLID := 40019;

DELETE FROM `quest_pool_template` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_template` (`poolId`, `numActive`, `description`) VALUES 
(@POOLID, 1, 'Razgar - Daily Quests');

DELETE FROM `quest_pool_members` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_members` (`questId`, `poolId`, `poolIndex`, `description`) VALUES 
(26543, @POOLID, 0, 'Clammy Hands'),
(26556, @POOLID, 1, 'No Dumping Allowed'),
(26557, @POOLID, 2, 'A Staggering Effort'),
(26572, @POOLID, 3, 'A Golden Opportunity'),
(26588, @POOLID, 4, 'A Furious Catch');

UPDATE `quest_template_addon` SET `RequiredSkillID` = 356, `RequiredSkillPoints` = 1 WHERE `ID` IN (26543, 26556, 26557, 26572, 26588);
