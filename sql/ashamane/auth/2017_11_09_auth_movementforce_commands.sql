INSERT IGNORE INTO `rbac_permissions` (`id`, `name`) VALUES ('2000', 'Command: .debug movementforce');
INSERT IGNORE INTO `rbac_permissions` (`id`, `name`) VALUES ('2001', 'Command: .debug movementforce apply');
INSERT IGNORE INTO `rbac_permissions` (`id`, `name`) VALUES ('2002', 'Command: .debug movementforce remove');

INSERT IGNORE INTO `rbac_linked_permissions` VALUES (192, 2000), (192, 2001), (192, 2002);
