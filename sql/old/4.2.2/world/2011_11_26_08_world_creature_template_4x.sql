ALTER TABLE `creature_template` ADD `exp_unk` SMALLINT(2) NOT NULL DEFAULT '0' AFTER `exp`;
ALTER TABLE `creature_template` ADD `type_flags2` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `type_flags`;
