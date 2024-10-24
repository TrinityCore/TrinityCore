--
SET @PERMISSION_START = 70034;
SET @PERMISSION_END   = 70034;

DELETE FROM `rbac_permissions` WHERE id BETWEEN @PERMISSION_START AND @PERMISSION_END;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
('70034','Command: npcbot spawned');
