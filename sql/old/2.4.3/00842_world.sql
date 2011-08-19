ALTER TABLE `areatrigger_teleport`
ADD `heroic_required_quest_done` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0 AFTER `heroic_key2`,
ADD `heroic_required_failed_quest_text` TEXT NULL DEFAULT NULL AFTER `heroic_required_quest_done`;

UPDATE `areatrigger_teleport` SET `heroic_required_quest_done`=11492, `heroic_required_failed_quest_text`='Heroic Difficulty requires completion of the "Hard to Kill" quest.' WHERE `id`=4887;
