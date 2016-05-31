UPDATE `creature_text` SET `emote`=51 WHERE  `entry`=27212;
UPDATE `creature_text` SET `emote`=1 WHERE  `entry`=27439 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `emote`=6 WHERE  `entry`=27439 AND `groupid`=1 AND `id`=0;
UPDATE `creature_text` SET `emote`=1 WHERE  `entry`=27439 AND `groupid`=2 AND `id`=0;
UPDATE `creature_text` SET `emote`=25 WHERE  `entry`=27439 AND `groupid`=3 AND `id`=0;
UPDATE `creature_text` SET `emote`=274 WHERE  `entry`=27439 AND `groupid`=4 AND `id`=0;
UPDATE `creature_text` SET `sound`=2943 WHERE  `entry`=27439 AND `groupid`=5 AND `id`=0;

UPDATE `smart_scripts` SET `event_param1`=30 WHERE  `entryorguid`=17831 AND `source_type`=0 AND `id`=4 AND `link`=5;
