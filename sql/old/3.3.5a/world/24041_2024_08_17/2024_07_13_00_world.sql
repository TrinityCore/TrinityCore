-- Add missing furbolg camp area triggers for quest "How Big a Threat?"
SET @QUEST := 984;
DELETE FROM `areatrigger_involvedrelation` WHERE `quest` = @QUEST;
INSERT INTO `areatrigger_involvedrelation` (`id`, `quest`) VALUES
(231, @QUEST),
(232, @QUEST),
(233, @QUEST),
(234, @QUEST),
(235, @QUEST),
(236, @QUEST),
(237, @QUEST),
(238, @QUEST);
