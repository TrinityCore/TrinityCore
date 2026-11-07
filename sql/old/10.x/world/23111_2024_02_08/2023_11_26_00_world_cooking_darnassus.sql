SET @POOLID = 40015;

DELETE FROM `quest_pool_template` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_template` (`poolId`, `numActive`, `description`) VALUES 
(@POOLID, 1, 'Alegorn - Daily Quests');

DELETE FROM `quest_pool_members` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_members` (`questId`, `poolId`, `poolIndex`, `description`) VALUES 
(29313, @POOLID, 0, 'The Secret to Perfect Kimchi'),
(29314, @POOLID, 1, 'Remembering the Ancestors'),
(29316, @POOLID, 2, 'Back to Basics'),
(29318, @POOLID, 3, 'Ribs for the Sentinels'),
(29357, @POOLID, 4, 'Spice Bread Aplenty');

UPDATE `quest_template_addon` SET `RequiredSkillID` = 185, `RequiredSkillPoints` = 1 WHERE `ID` IN (29313, 29314, 29316, 29318, 29357);
