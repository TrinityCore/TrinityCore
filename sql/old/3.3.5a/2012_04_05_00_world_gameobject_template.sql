DELETE FROM `gameobject_template` WHERE `entry`=202931;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `WDBVerified`) VALUES
(202931, 5, 9463, 'Serpent Offering', '', '', '', 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.17, 0, 0, 0, 0, 0, 0, 12340); -- -Unknown-

UPDATE `gameobject_template` SET `questItem1`=30527, `questItem2`=30524, `questItem3`=30525, `questItem4`=30526 WHERE `entry`=184815; -- Sealed Coffin
-- UPDATE `gameobject_template` SET `data0`=2061, `WDBVerified`=12340 WHERE `entry`=151951; -- Idol Oven Fire
-- UPDATE `gameobject_template` SET `type`=5, `data3`=0, `data5`=0 WHERE `entry`=188187; -- Snow Pile
UPDATE `gameobject_template` SET `size`=0.45 WHERE `entry`=190169; -- Tiger Lily
UPDATE `gameobject_template` SET `unk1`='' WHERE `entry`=190549; -- The Zephyr
-- UPDATE `gameobject_template` SET `data0`=2061 WHERE `entry`=191300; -- Fire
UPDATE `gameobject_template` SET `displayId`=7836 WHERE `entry`=196485; -- Saronite Rock
--  UPDATE `gameobject_template` SET `data0`=2061 WHERE `entry`=126337; -- 126337
--  UPDATE `gameobject_template` SET `data0`=2061 WHERE `entry`=126338; -- 126338
--  UPDATE `gameobject_template` SET `data0`=2061 WHERE `entry`=126339; -- 126339
--  UPDATE `gameobject_template` SET `data0`=2061 WHERE `entry`=126340; -- 126340
--  UPDATE `gameobject_template` SET `data0`=2061 WHERE `entry`=126341; -- 126341
--  UPDATE `gameobject_template` SET `data0`=2061 WHERE `entry`=126345; -- 126345
UPDATE `gameobject_template` SET `data2`=23787, `data7`=3605, `data19`=0 WHERE `entry`=202443; -- Dedication of Honor
UPDATE `gameobject_template` SET `type`=10 WHERE `entry`=166872; -- Supply Crate
UPDATE `gameobject_template` SET `data6`=-1000 WHERE `entry`=178559; -- Larva Spewer

/*
GameObject (Entry: 126337 GoType: 8) have data0=2061 but SpellFocus (Id: 2061) not exist.
GameObject (Entry: 126338 GoType: 8) have data0=2061 but SpellFocus (Id: 2061) not exist.
GameObject (Entry: 126339 GoType: 8) have data0=2061 but SpellFocus (Id: 2061) not exist.
GameObject (Entry: 126340 GoType: 8) have data0=2061 but SpellFocus (Id: 2061) not exist.
GameObject (Entry: 126341 GoType: 8) have data0=2061 but SpellFocus (Id: 2061) not exist.
GameObject (Entry: 126345 GoType: 8) have data0=2061 but SpellFocus (Id: 2061) not exist.
GameObject (Entry: 151951 GoType: 8) have data0=2061 but SpellFocus (Id: 2061) not exist.
GameObject (Entry: 191300 GoType: 8) have data0=2061 but SpellFocus (Id: 2061) not exist.
Gameobject (Entry: 188192 GoType: 3) have data7=188187 but GO (Entry 188187) have not GAMEOBJECT_TYPE_TRAP (6) type.
*/
