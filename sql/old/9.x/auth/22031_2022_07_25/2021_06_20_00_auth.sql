--
DROP VIEW IF EXISTS `vw_rbac`;

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
