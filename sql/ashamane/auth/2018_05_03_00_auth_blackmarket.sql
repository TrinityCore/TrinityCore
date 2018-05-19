DELETE FROM `rbac_permissions` WHERE id IN (2004, 2005);
INSERT INTO `rbac_permissions` VALUES
(2004, "Command: blackmarket"),
(2005, "Command: blackmarket setduration");

DELETE FROM `rbac_linked_permissions` WHERE id = 192 AND linkedid IN (2004, 2005);
INSERT INTO `rbac_linked_permissions` VALUES
(192, 2004),
(192, 2005);
