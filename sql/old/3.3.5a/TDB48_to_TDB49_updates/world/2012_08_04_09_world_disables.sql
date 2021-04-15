DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (9111,9112,9113,9114,9115,9116,9117,9118);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,9111,0,'','','Deprecated quest: Robe of Faith'),
(1,9112,0,'','','Deprecated quest: Leggings of Faith'),
(1,9113,0,'','','Deprecated quest: Circlet of Faith'),
(1,9114,0,'','','Deprecated quest: Shoulderpads of Faith'),
(1,9115,0,'','','Deprecated quest: Sandals of Faith'),
(1,9116,0,'','','Deprecated quest: Gloves of Faith'),
(1,9117,0,'','','Deprecated quest: Belt of Faith'),
(1,9118,0,'','','Deprecated quest: Bindings of Faith');
