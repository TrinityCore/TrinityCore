DROP TABLE IF EXISTS `quest_tracker`;
CREATE TABLE `quest_tracker` (
    `id` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `character_guid` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `quest_accept_time` DATETIME NOT NULL,
    `quest_complete_time` DATETIME DEFAULT NULL,
    `quest_abandon_time` DATETIME DEFAULT NULL,
    `completed_by_gm` BOOL NOT NULL DEFAULT '0',
    `core_hash` VARCHAR(120) NOT NULL DEFAULT '0',
    `core_revision` VARCHAR(120) NOT NULL DEFAULT '0'
)
ENGINE=InnoDB;
