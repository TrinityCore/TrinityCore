ALTER TABLE `conversation_actors` ADD COLUMN `ConversationActorNearId` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `ConversationActorGuid`; 
