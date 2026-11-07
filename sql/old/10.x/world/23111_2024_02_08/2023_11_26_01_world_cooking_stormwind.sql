SET @POOLID = 40016;

DELETE FROM `quest_pool_template` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_template` (`poolId`, `numActive`, `description`) VALUES 
(@POOLID, 1, 'Robby Flay - Daily Quests');

DELETE FROM `quest_pool_members` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_members` (`questId`, `poolId`, `poolIndex`, `description`) VALUES 
(26153, @POOLID, 0, 'Penny''s Pumpkin Pancakes'),
(26177, @POOLID, 1, 'Feeling Crabby'),
(26183, @POOLID, 2, 'The King''s Cider'),
(26190, @POOLID, 3, 'A Fisherman''s Feast'),
(26192, @POOLID, 4, 'Orphans Like Cookies Too!');

UPDATE `quest_template_addon` SET `RequiredSkillID` = 185, `RequiredSkillPoints` = 1 WHERE `ID` IN (26153, 26177, 26183, 26190, 26192);
