DROP TABLE IF EXISTS `log_gm`;
CREATE TABLE `log_gm` (
    `id` bigint (20) UNSIGNED NOT NULL AUTO_INCREMENT,
    `date` datetime ,
    `gm_account_id` bigint (20),
    `gm_account_name` blob ,
    `gm_character_id` bigint (20),
    `gm_character_name` blob ,
    `gm_ip` text ,
    `target_account_id` bigint (20),
    `target_account_name` blob ,
    `target_character_id` bigint (20),
    `target_character_name` blob ,
    `target_ip` text ,
    `command` blob,
    PRIMARY KEY (`id`)
); 
