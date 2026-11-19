DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=23789;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `comment`) VALUES
(0, 23789, 8, 'Stoneclaw Totem TEST - can crash client by spawning too many totems');
