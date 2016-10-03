--
UPDATE `creature_text` SET `language`=7, `BroadcastTextid`=13770 WHERE `entry`=17312 AND `groupid`=1;
UPDATE `creature_text` SET `emote`=5 WHERE `entry`=17312 AND `groupid`=2;
UPDATE `creature_text` SET `emote`=22 WHERE `entry`=17312 AND `groupid`=3;
UPDATE `creature_text` SET `emote`=5 WHERE `entry`=17312 AND `groupid`=4;

DELETE FROM `creature_text` WHERE `entry`=17311;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17311, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=13749), 12, 7, 100, 0, 0, 0, 13749, 0, "Cowlen");

UPDATE `script_waypoint` SET `waittime`=3000 WHERE `entry`=17312 AND `pointid`=28;
UPDATE `script_waypoint` SET `waittime`=5000 WHERE `entry`=17312 AND `pointid`=29;
