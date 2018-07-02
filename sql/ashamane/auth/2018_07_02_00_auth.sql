DELETE FROM rbac_permissions WHERE id = 2007;
INSERT INTO rbac_permissions VALUES
(2007, "Command: lfg debug");

DELETE FROM `rbac_linked_permissions` WHERE linkedid = 2007;
INSERT INTO `rbac_linked_permissions` VALUES
(192, 2007);
