-- Size adjustment on a hand-made template
UPDATE `gameobject_template` SET `size`=2, `WDBVerified`=-1 WHERE `entry`=194328;
-- Add some missing templates, need WDB data (data1/lootId is guessed based on logic sequence, rest is copied based on other templates of the chest)
DELETE FROM `gameobject_template` WHERE `entry` IN(194326,194329,194330);
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`size`,`data0`,`data1`,`data3`,`data11`,`data13`,`data15`,`WDBVerified`) VALUES
(194326,3,8628,'Freya\'s Gift',2,1634,27080,1,1,1,1,-1),
(194329,3,8628,'Freya\'s Gift',2,1634,27082,1,1,1,1,-1),
(194330,3,8628,'Freya\'s Gift',2,1634,27083,1,1,1,1,-1);

