DELETE FROM `rbac_linked_permissions` where `linkedId` IN ("1003","1004","1005","1006","1007");
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) values
('195','1003'),
('195','1004'),
('195','1005'),
('195','1006'),
('195','1007');

DELETE FROM `rbac_permissions` WHERE `id` IN ("1003","1004","1005","1006","1007");
insert into `rbac_permissions` (`id`, `name`) values
('1003', 'spectate'),
('1004', 'spectate player'),
('1005', 'spectate view'),
('1006', 'spectate reset'),
('1007', 'spectate leave');