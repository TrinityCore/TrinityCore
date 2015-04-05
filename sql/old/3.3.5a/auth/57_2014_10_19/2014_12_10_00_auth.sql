ALTER TABLE `rbac_default_permissions` 
ADD COLUMN `realmId` INT(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
DROP PRIMARY KEY, ADD PRIMARY KEY (`secId`, `permissionId`, `realmId`);
