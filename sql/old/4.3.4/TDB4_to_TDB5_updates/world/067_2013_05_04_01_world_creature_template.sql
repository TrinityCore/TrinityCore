UPDATE `creature_text` SET `sound`=16912 WHERE `entry`=36494 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `sound`=16916 WHERE `entry`=36494 AND `groupid`=1 AND `id`=0;
UPDATE `creature_text` SET `sound`=16917 WHERE `entry`=36494 AND `groupid`=2 AND `id`=0;
UPDATE `creature_text` SET `sound`=16915 WHERE `entry`=36494 AND `groupid`=3 AND `id`=0;
UPDATE `creature_text` SET `type`=14, `sound`=16913 WHERE `entry`=36494 AND `groupid`=4 AND `id`=0;
UPDATE `creature_text` SET `type`=14, `sound`=16914 WHERE `entry`=36494 AND `groupid`=4 AND `id`=1;
UPDATE `creature_text` SET `type`=42 WHERE `entry`=36494 AND `groupid`=5 AND `id`=0;

DELETE FROM `creature_template_addon` WHERE `entry`=36494;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(36494, 0, 0x0, 0x1, '68792');
