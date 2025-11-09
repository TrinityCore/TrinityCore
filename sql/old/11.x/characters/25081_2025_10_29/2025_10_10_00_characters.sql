ALTER TABLE `character_trait_config` ADD `variationId` int DEFAULT NULL AFTER `traitSystemId`;

UPDATE `character_trait_config` SET `variationId`=0 WHERE `type`=3;
