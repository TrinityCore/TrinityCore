--
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=3977 AND `groupid`=1 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=29 AND `groupid`=1 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=22515 AND `groupid`=6 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=22515 AND `groupid`=7 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=22515 AND `groupid`=8 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=22515 AND `groupid`=9 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=0 WHERE `entry`=22515 AND `groupid`=10 AND `id`=0;

UPDATE `creature_template` SET `minlevel`=82, `maxlevel`=82 WHERE `entry` IN (37302,37398,37415,37475,37477,38396,38632,38633,38395,38634,38635,38397,39000,39001,38398,38630,38631,34648,35655,35656,35441,35442,35443);
UPDATE `creature_template` SET `minlevel`=56, `maxlevel`=57 WHERE `entry` IN (11838,11839,13448);
UPDATE `creature_template` SET `minlevel`=57, `maxlevel`=57 WHERE `entry` IN (12051,12127);

UPDATE `creature` SET `guid`=88777 WHERE `guid`=185 AND `id`=37967;

UPDATE `smart_scripts` SET `entryorguid`=-3620 WHERE `entryorguid`=-142407;
UPDATE `smart_scripts` SET `entryorguid`=-3621 WHERE `entryorguid`=-142408;
