--
SET @PERMISSION_START = 70001;
SET @PERMISSION_END   = 70033;

DELETE FROM `rbac_permissions` WHERE id BETWEEN @PERMISSION_START AND @PERMISSION_END;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
('70001','Command: npcbot'),
('70002','Command: npcbot add'),
('70003','Command: npcbot remove'),
('70004','Command: npcbot spawn'),
('70005','Command: npcbot move'),
('70006','Command: npcbot delete'),
('70007','Command: npcbot lookup'),
('70008','Command: npcbot revive'),
('70009','Command: npcbot reloadconfig'),
('70010','Command: npcbot info'),
('70011','Command: npcbot hide'),
('70012','Command: npcbot unhide'),
('70013','Command: npcbot recall'),
('70014','Command: npcbot kill'),
('70015','Command: npcbot debug raid'),
('70016','Command: npcbot debug mount'),
('70017','Command: npcbot debug spellvisual'),
('70018','Command: npcbot debug states'),
('70019','Command: npcbot toggle flags'),
('70020','Command: npcbot set faction'),
('70021','Command: npcbot set owner'),
('70022','Command: npcbot set spec'),
('70023','Command: npcbot command standstill'),
('70024','Command: npcbot command stopfully'),
('70025','Command: npcbot command follow'),
('70026','Command: npcbot distance attack short'),
('70027','Command: npcbot distance attack long'),
('70028','Command: npcbot distance attack'),
('70029','Command: npcbot distance'),
('70030','Command: npcbot order cast'),
('70031','Command: npcbot vehicle eject'),
('70032','Command: npcbot dump load'),
('70033','Command: npcbot dump write');
