-- 
DELETE FROM `rbac_permissions` WHERE `id`=705;
DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=705;
DELETE FROM `rbac_account_permissions` WHERE `permissionId`=705;
DELETE FROM `rbac_default_permissions` WHERE `permissionId`=705;
