ALTER TABLE `item_instance_modifiers` 
ADD COLUMN `itemReforgeId` int UNSIGNED NULL DEFAULT 0 AFTER `artifactKnowledgeLevel`;
