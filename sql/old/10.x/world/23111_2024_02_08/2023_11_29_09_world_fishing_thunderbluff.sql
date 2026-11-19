SET @POOLID := 40020;

DELETE FROM `quest_pool_template` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_template` (`poolId`, `numActive`, `description`) VALUES 
(@POOLID, 1, 'Kah Mistrunner - Daily Quests');

DELETE FROM `quest_pool_members` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_members` (`questId`, `poolId`, `poolIndex`, `description`) VALUES 
(29345, @POOLID, 0, 'Pond Predators'),
(29346, @POOLID, 1, 'The Ring''s the Thing'),
(29348, @POOLID, 2, 'The Race to Restock'),
(29349, @POOLID, 3, 'Craving Crayfish'),
(29354, @POOLID, 4, 'Shiny Baubles');

UPDATE `quest_template_addon` SET `RequiredSkillID` = 356, `RequiredSkillPoints` = 1 WHERE `ID` IN (29345, 29346, 29348, 29349, 29354);
