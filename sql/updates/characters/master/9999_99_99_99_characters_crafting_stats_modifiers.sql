ALTER TABLE `item_instance_modifiers`
    ADD COLUMN `craftingModifiedStat1` INT(10) UNSIGNED DEFAULT 0 NULL AFTER `artifactKnowledgeLevel`,
    ADD COLUMN `craftingModifiedStat2` INT(10) UNSIGNED DEFAULT 0 NULL AFTER `craftingModifiedStat1`;
