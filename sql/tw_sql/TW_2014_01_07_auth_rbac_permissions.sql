/* add rbac permissions to new commands */
 
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1002,   'Command: qc');
 
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1003,   'Command: qc status');
 
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1004,   'Command: qc add');
 
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1005,   'Command: qc del');
 
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1006,   'Command: online');
 
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1007,   'Command: online account');
 
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1008,   'Command: online character');
 
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1009,   'Command: instance setdata');
 
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1010,   'Command: instance getdata');
 
/* adds qc to players */
INSERT INTO `rbac_linked_permissions` VALUES
(195, 1002);
 
/* adds qc status to players */
INSERT INTO `rbac_linked_permissions` VALUES
(195, 1003);
 
/* adds qc add to GMs */
INSERT INTO `rbac_linked_permissions` VALUES
(193, 1004);
 
/* adds qc del to GMs */
INSERT INTO `rbac_linked_permissions` VALUES
(193, 1005);
 
/* adds online to mods+ */
INSERT INTO `rbac_linked_permissions` VALUES
(195, 1006);
 
/* adds online account to mods+ */
INSERT INTO `rbac_linked_permissions` VALUES
(194, 1007);
 
/* adds online character to mods+ */
INSERT INTO `rbac_linked_permissions` VALUES
(194, 1008);
 
/* adds instance setdata to GMs */
INSERT INTO `rbac_linked_permissions` VALUES
(193, 1009);
 
/* adds instance getdata to GMs */
INSERT INTO `rbac_linked_permissions` VALUES
(193, 1010);