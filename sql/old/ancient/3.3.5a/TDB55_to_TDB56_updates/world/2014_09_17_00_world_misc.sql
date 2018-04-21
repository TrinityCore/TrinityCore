DELETE FROM `creature_text` WHERE `entry` IN(17843,17875,17853,17664);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(17843, 0, 0, 'I want all of your trackers out in search of the criminal, Matis the Cruel. I have given trusted agents of the Hand flare guns. Should you or one of your trackers see the flare, it means that an agent has found Matis and needs assistance. And remember, tracker, Matis is to be brought back to me alive.', 12, 7, 100, 1, 0, 0, 'Vindicator Kuros',14454),
(17875, 0, 0, 'I am at your service, my lord.', 12, 7, 100, 0, 0, 0, 'Hunter of the Hand',14453),
(17875, 1, 0, 'It will be done, my lord.', 12, 7, 100, 1, 0, 0, 'Hunter of the Hand',14455),
(17875, 2, 0, '%s calls forth their bretheren.', 16, 7, 100, 22, 0, 0, 'Hunter of the Hand',14456),
(17875, 3, 0, 'Brothers and sisters, tonight we hunt! A blood elf known as Matis must be brought to justice! The first to find him gets one week''s vacation aboard the Exodar!', 12, 7, 100, 1, 0, 0, 'Hunter of the Hand',14457),
(17875, 4, 0, 'Onward! The wilds of Bloodmyst await!', 12, 7, 100, 1, 0, 0, 'Hunter of the Hand',14458),
(17853, 0, 0, 'We''ve got you now, Matis the Cruel!', 12, 0, 100, 0, 0, 0, 'Tracker of the Hand',0), -- 14446 but tc fills $n with player name rather than npc name
(17853, 1, 0, 'Return to Kuros. I will bring him to Blood Watch.', 12, 7, 100, 0, 0, 0, 'Tracker of the Hand',14445),
(17664, 0, 0, 'You will regret this, maggot.', 12, 0, 100, 0, 0, 0, 'Matis the Cruel',14449),
(17664, 1, 0, '%s falls unconscious.', 16, 0, 100, 0, 0, 0, 'Matis the Cruel',14444);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN(17843,17875,17853,17664);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(17843,17875,17853,17664) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(1784300,1785300,1787500) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17843, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - On Spawn - Set Phase 1'),
(17843, 0, 1, 0, 19, 1, 100, 0, 9711, 0, 0, 0, 80, 1784300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - On Quest Accept (Matis the Cruel) - Run Script (Phase 1)'),

(17875, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 17875, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hunter of the Hand - On Data Set - Start WP'),
(17875, 0, 1, 2, 40, 0, 100, 0, 7, 17875, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 17843, 0, 0, 0, 0, 0, 0, 'Hunter of the Hand - On Reached WP7 - Set Orientation'),
(17875, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hunter of the Hand - On Reached WP7 - Set Bytes 1'),
(17875, 0, 3, 4, 38, 0, 100, 0, 2, 2, 0, 0, 29, 10, 0, 0, 0, 0, 0, 19, 17843, 0, 0, 0, 0, 0, 0, 'Hunter of the Hand - On Data Set - Start Closest path'),
(17875, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1787500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hunter of the Hand - On Data Set - Run Script'),
(17875, 0, 5, 6, 38, 0, 100, 0, 3, 3, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hunter of the Hand - On Data Set - Remove Bytes 1'),
(17875, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hunter of the Hand - On Data Set - Play emote OneShotRoar'),
(17875, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 1787500, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hunter of the Hand - On Data Set - Start WP (Path 06)'),
(17875, 0, 8, 0, 40, 0, 100, 0, 9, 1787500, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hunter of the Hand - On Reached WP9 (Path 06) - Despawn'),

(17853, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 17664, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Just Summoned - Face Matis the Cruel'),
(17853, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Just Summoned - Say Line 1'),
(17853, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Just Summoned - Set Aggresive'),
(17853, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Just Summoned - Set Data to Matis the Cruel'),
(17853, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Just Summoned - Set Phase 2'),
(17853, 0, 5, 0, 38, 2, 100, 0, 1, 1, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 17664, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Data Set 1 1 (Phase 2) - Set Data 2 2 on Matis the Cruel'),
(17853, 0, 6, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 1785300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Data Set 2 2 - Run Script'),

(17664, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Face Tracker of the Hand'),
(17664, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Say Line 1'),
(17664, 0, 2, 12, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Attack Tracker of the hand'),
(17664, 0, 3, 0, 9, 0, 100, 0, 5, 30, 0, 0, 11, 6660, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Range - Cast Shoot'),
(17664, 0, 4, 0, 2, 0, 100, 1, 25, 50, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Between 25 - 50% HP - Set Data on Tracker of the Hand'),
(17664, 0, 5, 6, 38, 0, 100, 0, 2, 2, 0, 0, 90, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Set Bytes 1'),
(17664, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Disable Combat Movement'),
(17664, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Disable Auto Attack'),
(17664, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Say Line 2'),
(17664, 0, 9, 10, 61, 0, 100, 0, 25, 50, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 17853, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Set Data 2 2 Tracker of the Hand'),
(17664, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 11, 31336, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Cast Matis Captured DND'),
(17664, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Despawn After 15 Seconds'),
(17664, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Data Set - Set Invincibility HP'),

(1787500, 9, 0, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hunter of the Hand - Script - Set Bytes 1'),
(1785300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - Script - Evade'),
(1785300, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - Script - Say Line 2'),
(1785300, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - Script - Despawn'),


(1784300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - Script - Set Phase 2'),
(1784300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 17875, 1, 90000, 0, 0, 0, 8, 0, 0, 0, -1968.402, -11914.17, 51.70642, 1.356192, 'Vindicator Kuros - Script - Summon Hunter of the Hand'),
(1784300, 9, 2, 0, 0, 0, 100, 0, 500, 500, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 17875, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - Script - Set Data on Hunter of the Hand'),
(1784300, 9, 3, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 17875, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - Script - Say Line 1 on Hunter of the Hand'),
(1784300, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - Script - Say Line 1'),
(1784300, 9, 5, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 17875, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - Script - Say Line 2 on Hunter of the Hand'),
(1784300, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 17875, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - Script - Say Line 3 on Hunter of the Hand'),
(1784300, 9, 7, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - Script - Summon Group'),
(1784300, 9, 8, 0, 0, 0, 100, 0, 500, 500, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 17875, 20, 200, 0, 0, 0, 0, 'Vindicator Kuros - Script - Set Data Hunter of the Hand'),
(1784300, 9, 9, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 17875, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - Script - Say Line 4 on Hunter of the Hand'),
(1784300, 9, 10, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 17875, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - Script - Say Line 5 on Hunter of the Hand'),
(1784300, 9, 11, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 3, 3, 0, 0, 0, 0, 9, 17875, 0, 200, 0, 0, 0, 0, 'Vindicator Kuros - Script - Say Line 5 on Hunter of the Hand'),
(1784300, 9, 12, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Kuros - Script - Set Phase 1');

DELETE FROM `waypoints` WHERE `entry` IN(17875,1787500);

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(17875, 1,-1969.763, -11915.72, 52.07651, 'Hunter of the Hand'),
(17875, 2,-1968.785, -11915.93, 52.07651, 'Hunter of the Hand'),
(17875, 3,-1967.934, -11912.02, 51.25421, 'Hunter of the Hand'),
(17875, 4,-1967.082, -11908.12, 50.62921, 'Hunter of the Hand'),
(17875, 5,-1966.443, -11905.19, 50.00854, 'Hunter of the Hand'),
(17875, 6,-1965.19, -11899.45, 49.74685, 'Hunter of the Hand'),
(17875, 7,-1965.19, -11899.45, 49.74685, 'Hunter of the Hand'),
(1787500, 1,-1944.068, -11891.86, 48.60638, 'Hunter of the Hand'),
(1787500, 2,-1940.068, -11890.86, 47.85638, 'Hunter of the Hand'),
(1787500, 3,-1934.318, -11889.36, 47.35638, 'Hunter of the Hand'),
(1787500, 4,-1929.568, -11888.36, 46.60638, 'Hunter of the Hand'),
(1787500, 5,-1924.818, -11887.11, 46.10638, 'Hunter of the Hand'),
(1787500, 6,-1920.068, -11885.86, 45.35638, 'Hunter of the Hand'),
(1787500, 7,-1917.068, -11885.11, 44.60638, 'Hunter of the Hand'),
(1787500, 8,-1914.318, -11884.36, 44.10638, 'Hunter of the Hand'),
(1787500, 9,-1910.318, -11883.36, 42.60638, 'Hunter of the Hand');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=17843;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(17843, 0, 1, 17875, -1928.623, -11922.95, 47.65023, 1.884956, 1, 60000),
(17843, 0, 1, 17875, -1910.806, -11892.78, 43.87496, 0.541052, 1, 60000),
(17843, 0, 1, 17875, -1921.778, -11862.54, 51.3028, 3.892084, 1, 60000),
(17843, 0, 1, 17875, -1932.146, -11854.41, 51.7948, 2.9147, 1, 60000),
(17843, 0, 1, 17875, -1909.906, -11867.79, 44.27838, 4.642576, 1, 60000),
(17843, 0, 1, 17875, -1918.49, -11907.37, 46.20815, 0.541052, 1, 60000);
