DELETE FROM `rbac_permissions` WHERE id IN (2006);
INSERT INTO `rbac_permissions` VALUES
(2006, "Command: npc reload");

DELETE FROM `rbac_linked_permissions` WHERE id = 192 AND linkedid IN (2006);
INSERT INTO `rbac_linked_permissions` VALUES
(192, 2006);
