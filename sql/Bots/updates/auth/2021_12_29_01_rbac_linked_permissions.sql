--
SET @PERMISSION_START = 70034;
SET @PERMISSION_END   = 70034;

DELETE FROM `rbac_linked_permissions` WHERE linkedId BETWEEN @PERMISSION_START AND @PERMISSION_END;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
('196','70034');
