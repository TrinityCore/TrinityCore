DROP VIEW IF EXISTS `vw_log_history`;

CREATE VIEW `vw_log_history` AS (SELECT FROM_UNIXTIME(MIN(`logs`.`time`)) AS `First Logged` ,FROM_UNIXTIME(MAX(`logs`.`time`)) AS `Last Logged` ,COUNT(*) AS `Occurrences` ,`realmlist`.`name` AS `Realm` ,`logs`.`type` ,`logs`.`level` ,`logs`.`string` FROM `logs` LEFT JOIN realmlist ON `logs`.`realm` = `realmlist`.`id` GROUP BY `logs`.`string`, `logs`.`type`, `logs`.`realm`);
