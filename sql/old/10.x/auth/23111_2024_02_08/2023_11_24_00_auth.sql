-- drop .reload waypoint_scripts
DELETE FROM `rbac_permissions` WHERE `id`=706;
DELETE FROM `rbac_linked_permissions` WHERE `id`=706 OR `linkedId`=706;
DELETE FROM `rbac_account_permissions` WHERE `permissionId`=706;
DELETE FROM `rbac_default_permissions` WHERE `permissionId`=706;
