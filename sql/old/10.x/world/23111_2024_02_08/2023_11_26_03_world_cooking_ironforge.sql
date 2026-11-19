SET @POOLID = 40018;

DELETE FROM `quest_pool_template` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_template` (`poolId`, `numActive`, `description`) VALUES 
(@POOLID, 1, 'Daryl Riknussun - Daily Quests');

DELETE FROM `quest_pool_members` WHERE `poolId`=@POOLID;
INSERT INTO `quest_pool_members` (`questId`, `poolId`, `poolIndex`, `description`) VALUES 
(29351, @POOLID, 0, 'A Round for the Guards'),
(29352, @POOLID, 1, 'A Fowl Shortage'),
(29353, @POOLID, 2, 'Keepin'' the Haggis Flowin'''),
(29355, @POOLID, 3, 'Can''t Get Enough Spice Bread'),
(29356, @POOLID, 4, 'I Need to Cask a Favor');

UPDATE `quest_template_addon` SET `RequiredSkillID` = 185, `RequiredSkillPoints` = 1 WHERE `ID` IN (29351, 29352, 29353, 29355, 29356);
