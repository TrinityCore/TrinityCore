ALTER TABLE `broadcast_text` ADD `VoiceOverPriorityID` int DEFAULT 0 NOT NULL AFTER `ChatBubbleDurationMs`;

ALTER TABLE `item_sparse` MODIFY `StartQuestID` int DEFAULT 0 NOT NULL;
ALTER TABLE `item_sparse` MODIFY `LanguageID` int DEFAULT 0 NOT NULL;

ALTER TABLE `languages` ADD `Flags` int DEFAULT 0 NOT NULL AFTER Name;
ALTER TABLE `languages` ADD `UiTextureKitID` int DEFAULT 0 NOT NULL AFTER `Flags`;
ALTER TABLE `languages` ADD `UiTextureKitElementCount` int DEFAULT 0 NOT NULL AFTER `UiTextureKitID`;

ALTER TABLE `taxi_nodes` MODIFY `Flags` smallint unsigned DEFAULT 0 NOT NULL;

-- purge blob hotfixes
DELETE hd, hb FROM `hotfix_data` hd INNER JOIN `hotfix_blob` hb ON hd.`TableHash` = hb.`TableHash` AND hd.`RecordId` = hb.`RecordId`;
