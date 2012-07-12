-- Fixing Required Races on Quests 8553 and 8554 to allow for Alliance completion
UPDATE `quest_template` SET `RequiredRaces`=0 WHERE `id`=8554;
UPDATE `quest_template` SET `RequiredRaces`=0 WHERE `id`=8553;
-- Fixing Next Quest for Quest 8552
UPDATE `quest_template` SET `NextQuestIDChain`=8553 WHERE `id`=8552;
