DELETE FROM `rbac_permissions` WHERE `id` IN (861,862,863,864);
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(861, 'Command: group set'),
(862, 'Command: group set assistant'),
(863, 'Command: group set maintank'),
(864, 'Command: group set mainassist');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (473,861,862,863,864);
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(197,473),(197,861),(197,862),(197,863),(197,864);
