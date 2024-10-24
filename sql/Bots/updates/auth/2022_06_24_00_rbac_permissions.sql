--
SET @PERMISSION_START = 70035;
SET @PERMISSION_END   = 70035;

DELETE FROM `rbac_permissions` WHERE id BETWEEN @PERMISSION_START AND @PERMISSION_END;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
('70035','Command: npcbot command walk');
