-- Gameobject updates based on sniffs
UPDATE `gameobject_template` SET `size` =2.5,`questItem1`=30876,`data0`=57,`data1`=21583 WHERE `entry`=185032;
UPDATE `gameobject` SET `position_x`=-3420.991,`position_y`=1373.175,`position_z`=257.5233,`orientation`=3.141593 WHERE `id`=185032;
-- Gameobject loot template
DELETE FROM `gameobject_loot_template` WHERE `entry`=21583;
INSERT INTO `gameobject_loot_template` VALUES
(21583,30876,100,1,0,1,1); -- Quenched Illidari-Bane Blade
