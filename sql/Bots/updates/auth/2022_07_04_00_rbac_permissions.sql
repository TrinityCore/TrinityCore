--
SET @PERMISSION_START = 70036;
SET @PERMISSION_END   = 70036;

DELETE FROM `rbac_permissions` WHERE id BETWEEN @PERMISSION_START AND @PERMISSION_END;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
('70036','Command: npcbot createnew');
