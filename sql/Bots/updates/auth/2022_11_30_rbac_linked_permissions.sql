--
SET @PERMISSION_START = 70037;
SET @PERMISSION_END   = 70037;

DELETE FROM `rbac_linked_permissions` WHERE linkedId BETWEEN @PERMISSION_START AND @PERMISSION_END;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
('199','70037');
