
ALTER TABLE `realmlist` MODIFY `population` float NOT NULL DEFAULT '0';

SET NAMES 'utf8mb4' COLLATE 'utf8mb4_unicode_ci'; -- views do not have explicit charset/collation options but record whatever the connection settings were as their own (visible in mysqldump)

DROP VIEW IF EXISTS `vw_log_history`;
DROP VIEW IF EXISTS `vw_rbac`;

CREATE SQL SECURITY INVOKER VIEW `vw_log_history` AS (SELECT FROM_UNIXTIME(MIN(`logs`.`time`)) AS `First Logged` ,FROM_UNIXTIME(MAX(`logs`.`time`)) AS `Last Logged` ,COUNT(*) AS `Occurrences` ,`realmlist`.`name` AS `Realm` ,`logs`.`type` ,`logs`.`level` ,`logs`.`string` FROM `logs` LEFT JOIN realmlist ON `logs`.`realm` = `realmlist`.`id` GROUP BY `logs`.`string`, `logs`.`type`, `logs`.`realm`);

CREATE SQL SECURITY INVOKER VIEW `vw_rbac` AS
(
    SELECT `t1`.`linkedId` AS `Permission ID`,
           `t1`.`id` AS `Permission Group`,
           IFNULL(`t2`.`secId`, 'linked') AS `Security Level`,
       `t3`.`name` AS `Permission`
    FROM `rbac_linked_permissions` `t1`
    LEFT JOIN `rbac_default_permissions` `t2` ON `t1`.`id` = `t2`.`permissionId`
    LEFT JOIN `rbac_permissions` `t3` ON `t1`.`linkedId` = `t3`.`id`
);
