ALTER TABLE `quest_template_locale` 
  CHANGE `Title` `LogTitle` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`,
  CHANGE `Objectives` `LogDescription` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `LogTitle`,
  CHANGE `Details` `QuestDescription` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `LogDescription`,
  CHANGE `EndText` `AreaDescription` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `QuestDescription`,
  CHANGE `CompletedText` `QuestCompletionLog` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `AreaDescription`;
