ALTER TABLE `quest_template_addon` 
    ADD COLUMN `AcceptConversationID` int UNSIGNED NULL DEFAULT NULL AFTER `SpecialFlags`,
    ADD COLUMN `RewardConversationID` int UNSIGNED NULL DEFAULT NULL AFTER `AcceptConversationID`;
