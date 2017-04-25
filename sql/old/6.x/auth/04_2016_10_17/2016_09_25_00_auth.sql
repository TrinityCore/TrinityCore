DELETE FROM `rbac_permissions` WHERE `id` IN (844, 845, 846, 847, 848, 849, 850);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(844, 'Command: scene'),
(845, 'Command: scene debug'),
(846, 'Command: scene play'),
(847, 'Command: scene play package'),
(848, 'Command: scene cancel'),
(849, 'Command: list scenes'),
(850, 'Command: reload scenes');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (844, 845, 846, 847, 848, 849, 850);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(192, 844),
(192, 845),
(192, 846),
(192, 847),
(192, 848),
(192, 849),
(192, 850);
