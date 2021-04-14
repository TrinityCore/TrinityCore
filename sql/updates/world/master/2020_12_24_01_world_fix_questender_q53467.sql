-- Anachronos must complete the quest
REPLACE INTO `creature_questender` VALUES (15192, 53467);

-- continue the quest chain
UPDATE `quest_template` SET `RewardNextQuest`='53354' WHERE `id`='53467';
-- update quest_template_addon
REPLACE INTO `quest_template_addon` VALUES (53467, 0, 0, 0, 53466, 53354, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');
