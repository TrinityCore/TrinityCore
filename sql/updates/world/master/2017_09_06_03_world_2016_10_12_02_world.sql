--
DELETE FROM `creature_text` WHERE `entry`=24251 AND `groupid`=0 AND `id`=1;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24251, 0, 1, "It's alive!", 14, 0, 100, 0, 0, 0, 23099, 0, "Chief Plaguebringer Harris");
