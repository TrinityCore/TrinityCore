--
SET @PERMISSION_START = 70037;
SET @PERMISSION_END   = 70037;

DELETE FROM `rbac_permissions` WHERE id BETWEEN @PERMISSION_START AND @PERMISSION_END;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
('70037','Command: npcbot sendto');
