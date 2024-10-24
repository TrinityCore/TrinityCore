--
SET @PERMISSION_START = 70036;
SET @PERMISSION_END   = 70036;

DELETE FROM `rbac_linked_permissions` WHERE linkedId BETWEEN @PERMISSION_START AND @PERMISSION_END;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
('196','70036');
