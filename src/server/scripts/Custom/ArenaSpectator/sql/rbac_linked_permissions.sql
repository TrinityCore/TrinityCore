DELETE FROM `rbac_linked_permissions` where `linkedId` IN ("1003","1004","1005","1006","1007");
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) values
('195','1003'),
('195','1004'),
('195','1005'),
('195','1006'),
('195','1007');