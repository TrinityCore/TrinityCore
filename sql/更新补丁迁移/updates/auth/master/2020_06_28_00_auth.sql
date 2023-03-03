UPDATE `rbac_default_permissions`
SET `permissionId` =  195
WHERE `secId` = 0;

UPDATE `rbac_default_permissions`
SET `permissionId` = 195
WHERE `secId` = 1;

UPDATE `rbac_default_permissions`
SET `permissionId` = 194
WHERE `secId` = 2;

UPDATE `rbac_default_permissions`
SET `permissionId` = 193
WHERE `secId` = 3;

insert into `rbac_default_permissions` (`secId`, `permissionId`, `realmId`) values('5','192','-1');
insert into `rbac_default_permissions` (`secId`, `permissionId`, `realmId`) values('6','192','-1');
insert into `rbac_default_permissions` (`secId`, `permissionId`, `realmId`) values('7','192','-1');
insert into `rbac_default_permissions` (`secId`, `permissionId`, `realmId`) values('8','192','-1');
insert into `rbac_default_permissions` (`secId`, `permissionId`, `realmId`) values('4','193','-1');
