--
UPDATE `creature_template` SET `npcflag`=4096 WHERE `entry`=2404;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=2910;
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry`=7231;
UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=8121;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=15309;

DELETE FROM `npc_vendor` WHERE `entry`=8121;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`) VALUES
(8121, 0, 5740),
(8121, 0, 8624),
(8121, 0, 8625),
(8121, 0, 8626),
(8121, 0, 9312),
(8121, 0, 9313),
(8121, 0, 9314),
(8121, 0, 9315),
(8121, 0, 9317),
(8121, 0, 9318);
