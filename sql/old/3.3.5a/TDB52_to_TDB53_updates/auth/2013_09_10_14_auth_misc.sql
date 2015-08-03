-- Remove obsolete permissions

DELETE FROM `rbac_role_permissions` WHERE `permissionId` IN (7, 8, 9, 10, 12);
DELETE FROM `rbac_permissions` WHERE `id` IN (7, 8, 9, 10, 12);
