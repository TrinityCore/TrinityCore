DELETE FROM `trinity_string` WHERE `entry` in (1010,1012,1013,1015);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1010, '[         Account][   Character][             IP][GMLev][Expansion][Map][Zone]'),
(1012, '=============================================================================='),
(1013, '-[%16s][%12s][%15s][%5d][%9d][%3d][%4d]'),
(1015, '============================== Characters Online =============================');