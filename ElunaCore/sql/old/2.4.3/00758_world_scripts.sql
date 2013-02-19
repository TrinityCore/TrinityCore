DELETE FROM `creature_template_addon` WHERE `entry`=17225;
UPDATE `creature_template` SET `ScriptName`='boss_nightbane' WHERE `entry`=17225;
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=17225;
DELETE FROM `event_scripts` WHERE `id`=10951;
INSERT INTO `event_scripts` VALUES
(10951,0,10,17651,180000,0,-11159,-1907.22,91.48,0);
