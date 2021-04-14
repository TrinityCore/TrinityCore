ALTER TABLE `conversation_actors`
  CHANGE COLUMN `ConversationActorId` `ConversationActorId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  ADD COLUMN `ConversationActorGuid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0' AFTER `ConversationActorId`,
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ConversationId`, `Idx`);
