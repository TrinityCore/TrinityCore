-- Localized name for gameobject entry 1638 and 2035 (English name "Deathknell")
DELETE FROM `gameobject_template_locale` WHERE `entry` IN (1638,2035);
INSERT INTO `gameobject_template_locale` (`entry`,`locale`,`name`,`castBarCaption`,`VerifiedBuild`) VALUES
(1638,'deDE','Todesend','',0),
(1638,'esES','Camposanto','',0),
(1638,'esMX','Camposanto','',0),
(1638,'frFR','Le Glas','',0),
(1638,'koKR','죽음의 종소리 마을','',0),
(1638,'ruRU','Похоронный Звон','',0),
(1638,'zhCN','丧钟镇','',0),
(1638,'zhTW','喪鐘鎮','',0),
(2035,'deDE','Todesend','',0),
(2035,'esES','Camposanto','',0),
(2035,'esMX','Camposanto','',0),
(2035,'frFR','Le Glas','',0),
(2035,'koKR','죽음의 종소리 마을','',0),
(2035,'ruRU','Похоронный Звон','',0),
(2035,'zhCN','丧钟镇','',0),
(2035,'zhTW','喪鐘鎮','',0);
