-- Port Trainer changes from master to 3.3.5
DELETE FROM `rbac_permissions` WHERE `id`=672;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (672, 'Command: reload trainer');
