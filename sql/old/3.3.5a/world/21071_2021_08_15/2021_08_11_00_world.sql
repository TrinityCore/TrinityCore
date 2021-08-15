-- Ended up using some timers from https://www.youtube.com/watch?v=s8qTBCDPJIU because sniff was without ms
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8284 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 828400 AND 828406 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8284,0,0,0,11,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Spawn - Set Flag Standstate Dead"),
(8284,0,1,0,4,0,50,0,0,0,0,0,0,1,8,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Aggro - Say Line 8"),
(8284,0,2,0,19,0,100,0,3367,0,0,0,0,80,828400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Quest 'Suntara Stones' Taken - Run Script"),
(8284,0,3,0,40,0,100,0,23,0,0,0,0,80,828401,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Waypoint 23 Reached - Run Script"),
(8284,0,4,0,40,0,100,0,36,0,0,0,0,80,828402,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Waypoint 36 Reached - Run Script"),
(8284,0,5,0,40,0,100,0,47,0,0,0,0,80,828403,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Waypoint 47 Reached - Run Script"),
(8284,0,6,0,40,0,100,0,53,0,0,0,0,80,828404,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Waypoint 53 Reached - Run Script"),
(8284,0,7,0,40,0,100,0,77,0,0,0,0,80,828405,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Waypoint 77 Reached - Run Script"),
(8284,0,8,0,38,0,100,0,0,1,0,0,0,80,828406,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Data Set 0 1 - Run Script"),
(8284,0,9,0,6,0,100,0,0,0,0,0,0,6,3367,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Death - Fail Quest 'Suntara Stones'"),

/*
The way ambush is handled is just mind-blowing. He forces two objects (first 147516 and second 147517) to cast spell to summon creature.
After cast object despawns. Easy, right? That even was implemented and even almost correctly.

However here's the thing, in sniff I used only pair of 147517 casted that spell. 147516 only despawned.

In (change speed to 0.25) https://youtu.be/NYxkWKPkwjg?list=PL28173C4849CA7E04&t=146 147516 again only despawned. And again only 147517
casted the spell.

Here https://youtu.be/s8qTBCDPJIU?t=109 147516 casted the spell.
Let's now check 147517 in that video... here https://youtu.be/s8qTBCDPJIU?t=265

It's not just random but there is also chance that there will be another pair of 147517. Great.
*/

(828400,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Store Targetlist"),
(828400,9,1,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Remove Flags Immune To Players & Immune To NPC's"),
(828400,9,2,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Remove Flag Standstate Dead"),
(828400,9,3,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Remove NPC Flag Questgiver"),
(828400,9,4,0,0,0,100,0,0,0,0,0,0,53,0,8284,0,0,0,3,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Start Waypoint"),

(828401,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Say Line 0"),
(828401,9,1,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Set Flag Standstate Kneel"),
(828401,9,2,0,0,0,100,0,5000,5000,0,0,0,45,0,1,0,0,0,0,15,147516,50,0,0,0,0,0,0,"Dorius Stonetender - On Script - Set Data 0 1 (Dark Iron)"),
(828401,9,3,0,0,0,100,0,5000,5000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Remove Flag Standstate Kneel"),

(828402,9,0,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Say Line 1"),
(828402,9,1,0,0,0,100,0,3000,3000,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Set Orientation Stored Target 1"),
(828402,9,2,0,0,0,100,0,0,0,0,0,0,1,9,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Say Line 9"),

(828403,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Set Orientation Stored Target 1"),
(828403,9,1,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Say Line 2"),
(828403,9,2,0,0,0,100,0,2000,2000,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Play Emote 16"),
(828403,9,3,0,0,0,100,0,1000,1000,0,0,0,45,0,1,0,0,0,0,15,147517,50,0,0,0,0,0,0,"Dorius Stonetender - On Script - Set Data 0 1 (Dark Iron)"),

(828404,9,0,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Set Run On"),
(828404,9,1,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Set Orientation Stored Target 1"),
(828404,9,2,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Say Line 3"),

(828405,9,0,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Say Line 4"),
(828405,9,1,0,0,0,100,0,0,0,0,0,0,12,8338,8,0,0,0,0,8,0,0,0,0,-6369.839,-1974.8733,256.84335,3.543018341064453125,"Dorius Stonetender - On Script - Summon Creature 'Dark Iron Marksman'"),

(828406,9,0,0,0,0,100,0,0,0,0,0,0,11,12218,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Cast 'Man Down!'"),
(828406,9,1,0,0,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Say Line 5"),
(828406,9,2,0,0,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Add Flag Immune To NPC's"),
(828406,9,3,0,0,0,100,0,0,0,0,0,0,15,3367,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Quest Credit 'Suntara Stones'"),
(828406,9,4,0,0,0,100,0,3000,3000,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Say Line 6"),
(828406,9,5,0,0,0,100,0,2000,2000,0,0,0,50,175704,60,1,0,0,0,8,0,0,0,0,-6386.894,-1984.0505,246.73004,-1.27409064769744873,"Dorius Stonetender - On Script - Summon GameObject 'Singed Letter'"),
(828406,9,6,0,0,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Set Flag Standstate Dead"),
-- Hack, no despawn packet even after 2 min, don't wanna use here SetActive
(828406,9,7,0,0,0,100,0,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius Stonetender - On Script - Delayed Despawn");

-- Dark Iron Marksman
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 8338;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8338 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 833800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8338,0,0,0,63,0,100,0,0,0,0,0,0,80,833800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Marksman - On Just Created - Run Script"),

(833800,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Marksman - On Script - Say Line 0"),
(833800,9,1,0,0,0,100,0,3000,3000,0,0,0,66,0,0,0,0,0,0,19,8284,0,0,0,0,0,0,0,"Dark Iron Marksman - On Script - Set Orientation Closest Creature 'Dorius Stonetender'"),
(833800,9,2,0,0,0,100,0,0,0,0,0,0,11,12198,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Marksman - On Script - Cast 'Marksman Hit'"),
(833800,9,3,0,0,0,100,0,2000,2000,0,0,0,45,0,1,0,0,0,0,19,8284,0,0,0,0,0,0,0,"Dark Iron Marksman - On Script - Set Data 0 1 (Dorius Stonetender)"),
(833800,9,4,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Marksman - On Script - Say Line 1"),
(833800,9,5,0,0,0,100,0,0,0,0,0,0,11,12244,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Marksman - On Script - Cast 'Poof'"),
(833800,9,6,0,0,0,100,0,0,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron Marksman - On Script - Delayed Despawn");

-- Dark Iron
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (147516,147517) AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (14751600,14751700) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(147516,1,0,0,38,0,100,0,0,1,0,0,0,11,12168,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron - On Data Set 0 1 - Cast 'Dark Iron Steelshifter Surprise'"),
(147516,1,1,0,38,0,100,0,0,1,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron - On Data Set 0 1 - Despawn Instant"),
(147517,1,0,0,38,0,100,0,0,1,0,0,0,11,12168,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron - On Data Set 0 1 - Cast 'Dark Iron Steelshifter Surprise'"),
(147517,1,1,0,38,0,100,0,0,1,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Iron - On Data Set 0 1 - Despawn Instant");

UPDATE `creature_text` SET `Emote` = 5 WHERE `CreatureID` = 8284 AND `GroupID` = 9;
UPDATE `creature_text` SET `Emote` = 34 WHERE `CreatureID` = 8284 AND `GroupID` = 5;
UPDATE `creature_text` SET `Type` = 12 WHERE `CreatureID` = 8337;

DELETE FROM `waypoints` WHERE `entry` IN (8284,82840);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(8284,1,-7007.35,-1739.4038,234.22345,0,0,"Dorius Stonetender"),
(8284,2,-7007.5977,-1733.5464,234.22345,0,0,"Dorius Stonetender"),
(8284,3,-7008.2,-1729.9734,234.13889,0,0,"Dorius Stonetender"),
(8284,4,-7004.6772,-1725.7087,234.13889,0,0,"Dorius Stonetender"),
(8284,5,-6999.761,-1727.7898,235.7844,0,0,"Dorius Stonetender"),
(8284,6,-6994.8945,-1732.6509,238.0344,0,0,"Dorius Stonetender"),
(8284,7,-6988.9473,-1736.3281,240.19566,0,0,"Dorius Stonetender"),
(8284,8,-6975.559,-1736.8402,241.82066,0,0,"Dorius Stonetender"),
(8284,9,-6966.643,-1738.5826,241.99365,0,0,"Dorius Stonetender"),
(8284,10,-6949.428,-1739.8962,241.74365,0,0,"Dorius Stonetender"),
(8284,11,-6935.871,-1737.2726,241.24365,0,0,"Dorius Stonetender"),
(8284,12,-6933.8896,-1726.99,241.99365,0,0,"Dorius Stonetender"),
(8284,13,-6933.8853,-1720.4655,241.86865,0,0,"Dorius Stonetender"),
(8284,14,-6928.8735,-1718.0385,242.65321,0,0,"Dorius Stonetender"),
(8284,15,-6922.6333,-1717.234,241.65321,0,0,"Dorius Stonetender"),
(8284,16,-6911.9966,-1716.894,241.77821,0,0,"Dorius Stonetender"),
(8284,17,-6898.189,-1721.564,242.9963,0,0,"Dorius Stonetender"),
(8284,18,-6879.2607,-1735.6318,241.9963,0,0,"Dorius Stonetender"),
(8284,19,-6875.3813,-1740.9135,244.4963,0,0,"Dorius Stonetender"),
(8284,20,-6870.965,-1744.6965,246.7463,0,0,"Dorius Stonetender"),
(8284,21,-6868.163,-1747.5757,249.3713,0,0,"Dorius Stonetender"),
(8284,22,-6864.226,-1749.0392,251.09106,0,0,"Dorius Stonetender"),
(8284,23,-6856.3267,-1751.0432,251.59106,0,10000,"Dorius Stonetender"), --
(8284,24,-6852.3125,-1747.7596,251.59106,0,0,"Dorius Stonetender"),
(8284,25,-6857.2495,-1739.843,251.59106,0,0,"Dorius Stonetender"),
(8284,26,-6860.625,-1731.1506,251.83485,0,0,"Dorius Stonetender"),
(8284,27,-6861.4917,-1725.185,251.70985,0,0,"Dorius Stonetender"),
(8284,28,-6860.8384,-1717.3593,251.58485,0,0,"Dorius Stonetender"),
(8284,29,-6857.7095,-1709.6969,251.45985,0,0,"Dorius Stonetender"),
(8284,30,-6852.437,-1699.1887,250.52197,0,0,"Dorius Stonetender"),
(8284,31,-6849.2607,-1690.6925,250.89697,0,0,"Dorius Stonetender"),
(8284,32,-6843.33,-1683.049,251.52197,0,0,"Dorius Stonetender"),
(8284,33,-6835.1846,-1680.0264,251.52197,0,0,"Dorius Stonetender"),
(8284,34,-6828.133,-1678.4764,251.63634,0,0,"Dorius Stonetender"),
(8284,35,-6821.616,-1675.821,251.63634,0,0,"Dorius Stonetender"),
(8284,36,-6816.5176,-1672.6562,250.88634,0,10000,"Dorius Stonetender"), --
(8284,37,-6809.266,-1681.4537,250.26134,0,0,"Dorius Stonetender"),
-- (8284,38,-6806.062,-1686.4592,250.51134,0,0,"Dorius Stonetender"),
-- (8284,39,-6805.2173,-1687.8234,251.01134,0,0,"Dorius Stonetender"),
-- (8284,40,-6803.182,-1691.2994,251.51134,0,0,"Dorius Stonetender"),
(8284,38,-6798.365,-1698.1028,259.5818,0,0,"Dorius Stonetender"),
(8284,39,-6792.0083,-1704.2106,259.56085,0,0,"Dorius Stonetender"),
(8284,40,-6785.5254,-1712.6486,259.56085,0,0,"Dorius Stonetender"),
(8284,41,-6781.8535,-1721.8246,259.56085,0,0,"Dorius Stonetender"),
(8284,42,-6778.1675,-1733.2856,259.56085,0,0,"Dorius Stonetender"),
(8284,43,-6776.8794,-1743.4701,259.60727,0,0,"Dorius Stonetender"),
(8284,44,-6775.84,-1762.4336,257.35727,0,0,"Dorius Stonetender"),
(8284,45,-6776.2915,-1771.599,256.96143,0,0,"Dorius Stonetender"),
(8284,46,-6776.532,-1781.5063,256.96143,0,0,"Dorius Stonetender"),
(8284,47,-6774.147,-1791.1455,256.96143,0,5000,"Dorius Stonetender"), --
(8284,48,-6768.5728,-1798.2551,256.92804,0,0,"Dorius Stonetender"),
(8284,49,-6755.3813,-1804.1647,256.29108,0,0,"Dorius Stonetender"),
(8284,50,-6743.6665,-1809.9576,254.29108,0,0,"Dorius Stonetender"),
(8284,51,-6732.5605,-1813.1914,253.66483,0,0,"Dorius Stonetender"),
(8284,52,-6722.552,-1815.0754,252.78983,0,0,"Dorius Stonetender"),
(8284,53,-6711.7485,-1815.8403,251.66483,0,5000,"Dorius Stonetender"), --
(8284,54,-6696.8335,-1817.226,249.99365,0,0,"Dorius Stonetender"),
(8284,55,-6686.947,-1819.9214,249.49365,0,0,"Dorius Stonetender"),
(8284,56,-6678.1753,-1824.6239,249.86865,0,0,"Dorius Stonetender"),
(8284,57,-6667.781,-1832.7863,248.36865,0,0,"Dorius Stonetender"),
(8284,58,-6660.8374,-1836.0184,247.49791,0,0,"Dorius Stonetender"),
(8284,59,-6648.6987,-1859.2858,244.87291,0,0,"Dorius Stonetender"),
(8284,60,-6638.862,-1871.7513,244.23521,0,0,"Dorius Stonetender"),
(8284,61,-6633.4673,-1886.3053,244.23521,0,0,"Dorius Stonetender"),
(8284,62,-6623.089,-1899.7131,244.39366,0,0,"Dorius Stonetender"),
(8284,63,-6605.815,-1914.2263,244.2755,0,0,"Dorius Stonetender"),
(8284,64,-6588.8276,-1919.0641,244.27594,0,0,"Dorius Stonetender"),
(8284,65,-6566.911,-1924.0061,244.27594,0,0,"Dorius Stonetender"),
(8284,66,-6544.987,-1938.3533,244.2755,0,0,"Dorius Stonetender"),
(8284,67,-6530.4478,-1956.4531,245.6505,0,0,"Dorius Stonetender"),
(8284,68,-6518.979,-1964.602,245.7755,0,0,"Dorius Stonetender"),
(8284,69,-6499.173,-1969.9186,244.4005,0,0,"Dorius Stonetender"),
(8284,70,-6483.0522,-1969.9032,244.2755,0,0,"Dorius Stonetender"),
(8284,71,-6466.489,-1967.2472,244.7761,0,0,"Dorius Stonetender"),
(8284,72,-6453.063,-1969.6393,245.1511,0,0,"Dorius Stonetender"),
(8284,73,-6442.995,-1978.2552,244.5261,0,0,"Dorius Stonetender"),
(8284,74,-6414.674,-1978.6744,247.37137,0,0,"Dorius Stonetender"),
(8284,75,-6404.737,-1978.191,247.87137,0,0,"Dorius Stonetender"),
(8284,76,-6393.585,-1979.3717,247.45772,0,0,"Dorius Stonetender"),
(8284,77,-6388.7646,-1983.4796,246.83272,0,0,"Dorius Stonetender"); --
