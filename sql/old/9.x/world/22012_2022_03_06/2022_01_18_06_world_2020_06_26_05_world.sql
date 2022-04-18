--
UPDATE `creature` SET `position_x` = -1890.8405, `position_y` = 5364.6646, `position_z` = -12.344814, `orientation` = 0.855211 WHERE `id` = 17076;
UPDATE `creature` SET `position_x` = -1892.8138, `position_y` = 5358.005, `position_z` = -12.344588, `orientation` = 1.41371 WHERE `id` = 23131 AND `guid` = 121269;
UPDATE `creature` SET `position_x` = -1891.7179, `position_y` = 5361.508, `position_z` = -12.344777, `orientation` = 1.27409 WHERE `id` = 23131 AND `guid` = 121277;

-- I found only info about her respawn timer when she was attackable(as boss in Silvermoon)
UPDATE `creature` SET `spawntimesecs` = 600 WHERE `id` = 17076;
UPDATE `creature` SET `spawntimesecs` = 600 WHERE `id` = 23131 AND `guid` = 121269;
UPDATE `creature` SET `spawntimesecs` = 600 WHERE `id` = 23131 AND `guid` = 121277;

DELETE FROM `creature_formations` WHERE `leaderGUID` = 68464;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(68464,68464,0,0,512,0,0),
(68464,121277,5,310,512,0,0),
(68464,121269,5,50,512,0,0);

UPDATE `creature_template_addon` SET `mount` = 19085 WHERE `entry` = 17076;
DELETE FROM `creature_addon` WHERE `guid` IN (121277,121269);
INSERT INTO `creature_addon` (`guid`,`mount`) VALUES
(121277,19296),
(121269,19296);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (17076,25167);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17076,25167) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 1707600 AND 1707603 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2516700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17076,0,0,0,63,0,100,0,0,0,0,0,0,80,1707600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Just Created - Run Script"),
(17076,0,1,0,40,0,100,0,9,0,0,0,0,80,1707601,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Waypoint 9 Reached - Run Script"),
(17076,0,2,0,40,0,100,0,10,0,0,0,0,80,1707602,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Waypoint 10 Reached - Run Script"),
(17076,0,3,0,40,0,100,0,22,0,0,0,0,80,1707603,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Waypoint 22 Reached - Run Script"),
(17076,0,4,0,38,0,100,0,1,1,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Data Set 1 1 - Resume Waypoint"),

(1707600,9,0,0,0,0,100,0,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Remove NPC Flag Gossip"),
(1707600,9,1,0,0,0,100,0,4000,4000,0,0,0,53,0,17076,0,0,0,2,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Start Waypoint"),

(1707601,9,0,0,0,0,100,0,0,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Pause Waypoint"),
(1707601,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.436332,"Lady Liadrin - On Script - Set Orientation"),
(1707601,9,2,0,0,0,100,0,0,0,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Dismount"),
(1707601,9,3,0,0,0,100,0,0,0,0,0,0,43,0,0,0,0,0,0,11,23131,30,0,0,0,0,0,0,"Lady Liadrin - On Script - Dismount (Blood Knight Honor Guard)"),

(1707602,9,0,0,0,0,100,0,0,0,0,0,0,54,300000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Pause Waypoint"),
(1707602,9,1,0,0,0,100,0,1000,1000,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Play Emote 2"),
(1707602,9,2,0,0,0,100,0,0,0,0,0,0,5,25,0,0,0,0,0,19,25167,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Play Emote 25 (General Tiras'alan)"),
(1707602,9,3,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,19,25167,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 0 (General Tiras'alan)"), -- 03:08:21.000
(1707602,9,4,0,0,0,100,0,7000,7000,0,0,0,1,4,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 4 (A'dal)"),
(1707602,9,5,0,0,0,100,0,7000,7000,0,0,0,1,5,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 5 (A'dal)"),
(1707602,9,6,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 0"), -- 03:08:41.000
(1707602,9,7,0,0,0,100,0,7000,7000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 1"), -- 03:08:48.000
(1707602,9,8,0,0,0,100,0,7000,7000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 2"), -- 03:08:55.000
(1707602,9,9,0,0,0,100,0,12000,12000,0,0,0,1,6,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 6 (A'dal)"),
(1707602,9,10,0,0,0,100,0,9000,9000,0,0,0,1,7,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 7 (A'dal)"),
(1707602,9,11,0,0,0,100,0,3000,3000,0,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Play Emote 6"), -- 03:09:19.000
(1707602,9,12,0,0,0,100,0,3000,3000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 3"), -- 03:09:22.000
(1707602,9,13,0,0,0,100,0,7000,7000,0,0,0,1,8,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 8 (A'dal)"),
(1707602,9,14,0,0,0,100,0,7000,7000,0,0,0,1,9,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 9 (A'dal)"),
(1707602,9,15,0,0,0,100,0,7000,7000,0,0,0,1,10,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 10 (A'dal)"),
(1707602,9,16,0,0,0,100,0,7000,7000,0,0,0,1,11,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 11 (A'dal)"),
(1707602,9,17,0,0,0,100,0,7000,7000,0,0,0,1,12,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 12 (A'dal)"),
(1707602,9,18,0,0,0,100,0,7000,7000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 4"), -- 03:10:04.000
(1707602,9,19,0,0,0,100,0,7000,7000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 5"), -- 03:10:11.000
(1707602,9,20,0,0,0,100,0,5000,5000,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 6"), -- 03:10:16.000
(1707602,9,21,0,0,0,100,0,4000,4000,0,0,0,1,13,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Say Line 13 (A'dal)"),
(1707602,9,22,0,0,0,100,0,2000,2000,0,0,0,45,1,1,0,0,0,0,19,25167,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Set Data 1 1 (General Tiras'alan)"),

(25167,0,0,0,38,0,100,0,1,1,0,0,0,53,0,25167,0,0,0,2,1,0,0,0,0,0,0,0,0,"General Tiras'alan - On Data Set 1 1 - Start Waypoint"),
(25167,0,1,0,40,0,100,0,6,0,0,0,0,80,2516700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"General Tiras'alan - On Waypoint 6 Reached - Run Script"),
(25167,0,2,0,40,0,100,0,12,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.75246,"General Tiras'alan - On Waypoint 12 Reached - Set Orientation"),

(2516700,9,0,0,0,0,100,0,0,0,0,0,0,54,17000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"General Tiras'alan - On Script - Pause Waypoint"),
(2516700,9,1,0,0,0,100,0,3000,3000,0,0,0,5,2,0,0,0,0,0,19,17076,0,0,0,0,0,0,0,"General Tiras'alan - On Script - Play Emote 2 (Lady Liadrin)"), -- 03:10:46.000
(2516700,9,2,0,0,0,100,0,3000,3000,0,0,0,86,45372,0,19,17076,0,0,19,17076,0,0,0,0,0,0,0,"General Tiras'alan - On Script - Cross Cast 'Lady Liadrin Transform' (Lady Liadrin)"), -- 03:10:49.000
(2516700,9,3,0,0,0,100,0,5000,5000,0,0,0,1,14,0,0,0,0,0,19,18481,0,0,0,0,0,0,0,"General Tiras'alan - On Script - Say Line 14 (A'dal)"),
(2516700,9,4,0,0,0,100,0,6000,6000,0,0,0,45,1,1,0,0,0,0,19,17076,0,0,0,0,0,0,0,"General Tiras'alan - On Script - Set Data 1 1 (Lady Liadrin)"), -- 03:11:00.000

(1707603,9,0,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,11,23131,30,0,0,0,0,0,0,"Lady Liadrin - On Script - Despawn (1000) (Blood Knight Honor Guard)"),
(1707603,9,1,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Liadrin - On Script - Despawn (1000)");

DELETE FROM `waypoints` WHERE `entry` IN (17076,25167);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(17076,1,-1889.4803,5367.829,-12.428146,"Lady Liadrin"),
(17076,2,-1886.6562,5374.237,-12.428158,"Lady Liadrin"),
(17076,3,-1884.9547,5379.1855,-12.428162,"Lady Liadrin"),
(17076,4,-1882.9539,5389.4424,-12.428177,"Lady Liadrin"),
(17076,5,-1887.939,5393.2563,-12.428234,"Lady Liadrin"),
(17076,6,-1895.2999,5398.5,-12.428314,"Lady Liadrin"),
(17076,7,-1901.1967,5407.4243,-12.428253,"Lady Liadrin"),
(17076,8,-1898.3171,5413.7007,-12.428177,"Lady Liadrin"),
(17076,9,-1891.4534,5417.7334,-12.428192,"Lady Liadrin"), --
(17076,10,-1884.4406,5419.7715,-12.428157,"Lady Liadrin"), --
(17076,11,-1890.5408,5416.6855,-12.428154,"Lady Liadrin"),
(17076,12,-1898.2704,5412.5674,-12.428158,"Lady Liadrin"),
(17076,13,-1908.1675,5407.589,-12.428158,"Lady Liadrin"),
(17076,14,-1922.0374,5400.8384,-12.428452,"Lady Liadrin"),
(17076,15,-1930.2853,5396.7983,-12.428349,"Lady Liadrin"),
(17076,16,-1938.9174,5392.78,-12.428242,"Lady Liadrin"),
(17076,17,-1944.8556,5383.025,-12.428135,"Lady Liadrin"),
(17076,18,-1941.9391,5387.816,-12.428187,"Lady Liadrin"),
(17076,19,-1945.7522,5373.704,-12.428147,"Lady Liadrin"),
(17076,20,-1943.0194,5349.0454,-12.428154,"Lady Liadrin"),
(17076,21,-1915.2404,5312.3843,-12.428154,"Lady Liadrin"),
(17076,22,-1905.5239,5302.4785,-12.428154,"Lady Liadrin"),
(25167,1,-1856.5751,5438.3955,-10.463867,"General Tiras'alan"),
(25167,2,-1863.747559,5440.479492,-10.463867,"General Tiras'alan"),
(25167,3,-1871.633667,5436.593262,-10.463867,"General Tiras'alan"),
(25167,4,-1874.043823,5430.138672,-10.463867,"General Tiras'alan"),
(25167,5,-1873.248291,5425.577148,-10.463867,"General Tiras'alan"),
(25167,6,-1883.137329,5420.372070,-12.428157,"General Tiras'alan"), --
(25167,7,-1873.248291,5425.577148,-10.463867,"General Tiras'alan"),
(25167,8,-1874.043823,5430.138672,-10.463867,"General Tiras'alan"),
(25167,9,-1871.633667,5436.593262,-10.463867,"General Tiras'alan"),
(25167,10,-1863.747559,5440.479492,-10.463867,"General Tiras'alan"),
(25167,11,-1856.5751,5438.3955,-10.463867,"General Tiras'alan"), -- sniffed
(25167,12,-1854.0193,5435.058,-10.4803505,"General Tiras'alan"); -- sniffed

DELETE FROM `creature_text` WHERE `CreatureID` IN (17076,25167);
DELETE FROM `creature_text` WHERE `CreatureID` = 18481 AND `GroupID` BETWEEN 4 AND 14;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25167,0,0,"Why do you suffer the presence of this despicable Lady Liadrin? She and her followers distort the Light and make a mockery of all we stand for!",12,0,100,5,0,0,24461,0,"General Tiras'alan"),
(18481,4,0,"Patience, general. The Light embraces all who enter Shattrath in good faith.",12,0,100,0,0,0,24462,0,"A'dal"),
(18481,5,0,"You are welcome in Shattrath, Lady Liadrin. We have long awaited your arrival.",12,0,100,0,0,0,24463,0,"A'dal"),
(17076,0,0,"Thank you for allowing me to speak, A'dal. I know many of your allies despise me and my knights for our treatment of M'uru.",12,0,100,1,0,0,24464,0,"Lady Liadrin"),
(17076,1,0,"When he was given to us by 'Prince' Kael'thas, we believed his power would help us lead our people into a new age.",12,0,100,1,0,0,24485,0,"Lady Liadrin"),
(17076,2,0,"I've come to realize our path was a false one. We were betrayed by the man we called our prince. In his lust for power, he sent the felblood to attack us, and to spirit M'uru away to the Sunwell.",12,0,100,1,0,0,24465,0,"Lady Liadrin"),
(18481,6,0,"Both our peoples have suffered greatly at the hands of Kael'thas and his agents, Lady Liadrin. Your people were not the authors of their own fate, but they will die if they do not change.",12,0,100,0,0,0,24466,0,"A'dal"),
(18481,7,0,"M'uru accepted his role in this long ago, knowing full well what would happen to him. Will you accept your own?",12,0,100,0,0,0,24467,0,"A'dal"),
(17076,3,0,"I... I don't understand. You -- and M'uru -- knew all along that this would occur?",12,0,100,1,0,0,24468,0,"Lady Liadrin"),
(18481,8,0,"It wasn't I who foretold it, but Velen of the Draenei:",12,0,100,0,0,0,24469,0,"A'dal"),
(18481,9,0,"'Silvery moon, washed in blood,'",12,0,100,0,0,0,24470,0,"A'dal"),
(18481,10,0,"'Led astray into the night, armed with sword of broken Light.'",12,0,100,0,0,0,24471,0,"A'dal"),
(18481,11,0,"'Broken, then betrayed by one, standing there bestride the sun.'",12,0,100,0,0,0,24472,0,"A'dal"),
(18481,12,0,"'At darkest hour, redemption comes, in knightly lady sworn to blood.'",12,0,100,0,0,0,24473,0,"A'dal"),
(17076,4,0,"I see it clearly now. I renounce my loyalties to House Sunstrider and its false prince.",12,0,100,1,0,0,24474,0,"Lady Liadrin"),
(17076,5,0,"I pledge the blades of my Blood Knights to the defeat of Kil'jaeden and the restoration of Silvermoon.",12,0,100,1,0,0,24484,0,"Lady Liadrin"),
(17076,6,0,"We will fight beside you, A'dal.",12,0,100,66,0,0,24477,0,"Lady Liadrin"),
(18481,13,0,"The Shattered Sun Offensive will surely benefit from the addition of your knights, Lady Liadrin.",12,0,100,0,0,0,24480,0,"A'dal"),
(18481,14,0,"The battle for the Sunwell is but the first step on your new path, Lady Liadrin. Shattrath is open to you and all who follow you.",12,0,100,0,0,0,24481,0,"A'dal");
