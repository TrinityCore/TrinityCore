-- 
DELETE FROM `rbac_permissions` WHERE `id`= 874;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES (874, 'Command: debug asan');
