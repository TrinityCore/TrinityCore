-- Creates things
INSERT INTO `rbac_permissions` VALUES(17688,"Command: at");
INSERT INTO `rbac_permissions` VALUES(17689,"Command: clearat");
INSERT INTO `rbac_permissions` VALUES(17690,"Command: id");
INSERT INTO `rbac_permissions` VALUES(17691,"Command: test");

-- Makes these commands available to administrators
INSERT INTO `rbac_linked_permissions` VALUES(192,17688);
INSERT INTO `rbac_linked_permissions` VALUES(192,17689);
INSERT INTO `rbac_linked_permissions` VALUES(192,17690);
INSERT INTO `rbac_linked_permissions` VALUES(192,17691);