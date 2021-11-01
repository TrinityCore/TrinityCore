--
DELETE FROM `creature_template_addon` WHERE `entry` = 23784;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(23784,0,0,0,1,0,0,'5680');

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 23784;

UPDATE `creature` SET `spawntimesecs` = 0 WHERE `id` = 23784;

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 23784;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 23784 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2378400 AND 2378407 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23784,0,0,0,11,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Spawn - Set Flag Standstate Kneel"),
(23784,0,1,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Spawn - Set Event Phase 1"),

(23784,0,2,0,1,1,100,0,2000,2000,25000,25000,0,5,20,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - Out of Combat - Play Emote 20 (Phase 1)"),
(23784,0,3,0,2,0,100,0,0,75,10000,10000,0,11,17534,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - Between 0-75% Health - Cast 'Healing Potion'"),

(23784,0,4,0,19,0,100,0,11241,0,0,0,0,80,2378400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Quest 'Trail of Fire' Taken - Run Script"),

(23784,0,5,0,58,0,100,0,0,2378400,0,0,0,80,2378401,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Waypoint Finished - Run Script"),
(23784,0,6,0,58,0,100,0,0,2378401,0,0,0,80,2378402,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Waypoint Finished - Run Script"),
(23784,0,7,0,58,0,100,0,0,2378402,0,0,0,80,2378403,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Waypoint Finished - Run Script"),
(23784,0,8,0,58,0,100,0,0,2378403,0,0,0,80,2378404,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Waypoint Finished - Run Script"),
(23784,0,9,0,58,0,100,0,0,2378404,0,0,0,80,2378405,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Waypoint Finished - Run Script"),
(23784,0,10,0,58,0,100,0,0,2378405,0,0,0,80,2378406,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Waypoint Finished - Run Script"),
(23784,0,11,0,58,0,100,0,0,2378406,0,0,0,80,2378407,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Waypoint Finished - Run Script"),

(23784,0,12,0,6,0,100,0,0,0,0,0,0,6,11241,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Death - Fail Quest 'Trail of Fire'"),

(2378400,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Store Targetlist"),
(2378400,9,1,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Set Event Phase 0"),
(2378400,9,2,0,0,0,100,0,0,0,0,0,0,2,232,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Set Faction 232"),
(2378400,9,3,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Remove NPC Flag Questgiver"),
(2378400,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Say Line 0"),
(2378400,9,5,0,0,0,100,0,5000,5000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Remove Flag Standstate Kneel"),
(2378400,9,6,0,0,0,100,0,0,0,0,0,0,53,1,2378400,0,0,0,3,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Start Waypoint"),

(2378401,9,0,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Say Line 1"),
(2378401,9,1,0,0,0,100,0,4000,4000,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Play Emote 16"),
(2378401,9,2,0,0,0,100,0,0,0,0,0,0,71,0,1,1906,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Set Mainhand Item"),
(2378401,9,3,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Say Line 2"),
(2378401,9,4,0,0,0,100,0,5000,5000,0,0,0,53,1,2378401,0,0,0,3,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Start Waypoint"),

(2378402,9,0,0,0,0,100,0,0,0,0,0,0,11,42685,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Cast 'Burn'"),
(2378402,9,1,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Say Line 3"),
(2378402,9,2,0,0,0,100,0,6000,6000,0,0,0,53,1,2378402,0,0,0,3,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Start Waypoint"),

(2378403,9,0,0,0,0,100,0,0,0,0,0,0,11,42685,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Cast 'Burn'"),
(2378403,9,1,0,0,0,100,0,2000,2000,0,0,0,53,1,2378403,0,0,0,3,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Start Waypoint"),

(2378404,9,0,0,0,0,100,0,0,0,0,0,0,11,42685,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Cast 'Burn'"),
(2378404,9,1,0,0,0,100,0,2000,2000,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Say Line 4"),
(2378404,9,2,0,0,0,100,0,6000,6000,0,0,0,53,1,2378404,0,0,0,3,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Start Waypoint"),

(2378405,9,0,0,0,0,100,0,0,0,0,0,0,11,42685,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Cast 'Burn'"),
(2378405,9,1,0,0,0,100,0,4000,4000,0,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Play Emote 11"),
(2378405,9,2,0,0,0,100,0,2000,2000,0,0,0,5,14,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Play Emote 14"),
(2378405,9,3,0,0,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Say Line 5"),
(2378405,9,4,0,0,0,100,0,7000,7000,0,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Say Line 6"),
(2378405,9,5,0,0,0,100,0,7000,7000,0,0,0,53,1,2378405,0,0,0,3,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Start Waypoint"),

(2378406,9,0,0,0,0,100,0,1000,1000,0,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Say Line 7"),
(2378406,9,1,0,0,0,100,0,0,0,0,0,0,53,1,2378406,0,0,0,3,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Start Waypoint"),

(2378407,9,0,0,0,0,100,0,0,0,0,0,0,15,11241,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Quest Credit 'Trail of Fire'"),
(2378407,9,1,0,0,0,100,0,4000,4000,0,0,0,1,8,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Say Line 8"),
(2378407,9,2,0,0,0,100,0,7000,7000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Hanes - On Script - Despawn");

DELETE FROM `script_waypoint` WHERE `entry` = 23784;
DELETE FROM `waypoints` WHERE `entry` BETWEEN 2378400 AND 2378406;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(2378400,1,1379.8127,-6409.2007,1.5396829,"Apothecary Hanes"),
(2378400,2,1380.1144,-6401.7446,2.5179543,"Apothecary Hanes"),

(2378401,1,1386.2698,-6393.396,3.5779068,"Apothecary Hanes"),
(2378401,2,1394.7676,-6387.7085,3.68069,"Apothecary Hanes"),
(2378401,3,1405.6936,-6380.924,4.6247597,"Apothecary Hanes"),
(2378401,4,1416.1797,-6370.6562,5.9504433,"Apothecary Hanes"),
(2378401,5,1425.0476,-6361.604,6.354269,"Apothecary Hanes"),
(2378401,6,1427.9548,-6350.528,6.354269,"Apothecary Hanes"),
(2378401,7,1424.6168,-6340.581,5.786398,"Apothecary Hanes"),
(2378401,8,1416.3439,-6335.9087,5.7054653,"Apothecary Hanes"),
(2378401,9,1404.9205,-6335.286,6.229269,"Apothecary Hanes"),
(2378401,10,1400.8588,-6340.079,6.4763393,"Apothecary Hanes"),

(2378402,1,1419.2825,-6332.3086,5.531731,"Apothecary Hanes"),
(2378402,2,1428.4545,-6335.082,5.604269,"Apothecary Hanes"),
(2378402,3,1446.9548,-6338.7773,7.9524603,"Apothecary Hanes"),
(2378402,4,1457.2695,-6343.141,8.380317,"Apothecary Hanes"),
(2378402,5,1465.7235,-6345.1685,7.788642,"Apothecary Hanes"),

(2378403,1,1471.4004,-6349.006,8.6504135,"Apothecary Hanes"),

(2378404,1,1462.0583,-6341.999,7.9957952,"Apothecary Hanes"),
(2378404,2,1461.3224,-6337.461,7.834174,"Apothecary Hanes"),
(2378404,3,1465.0768,-6331.357,7.562849,"Apothecary Hanes"),
(2378404,4,1475.6212,-6327.219,7.1195745,"Apothecary Hanes"),
(2378404,5,1490.5508,-6315.3184,8.244208,"Apothecary Hanes"),
(2378404,6,1497.6818,-6311.0225,7.41413,"Apothecary Hanes"),
(2378404,7,1505.3026,-6313.5127,6.890468,"Apothecary Hanes"),
(2378404,8,1506.4313,-6317.528,7.3721576,"Apothecary Hanes"),

(2378405,1,1504.4158,-6305.0034,6.825893,"Apothecary Hanes"),
(2378405,2,1513.4985,-6287.4907,5.8186994,"Apothecary Hanes"),
(2378405,3,1513.9366,-6277.724,5.5831037,"Apothecary Hanes"),
(2378405,4,1523.0132,-6259.2554,4.5991592,"Apothecary Hanes"),
(2378405,5,1538.9414,-6220.414,6.434206,"Apothecary Hanes"),
(2378405,6,1554.7721,-6204.8276,6.6884785,"Apothecary Hanes"),
(2378405,7,1566.7456,-6192.293,7.5899744,"Apothecary Hanes"),

(2378406,1,1583.7823,-6168.5923,8.31788,"Apothecary Hanes"),
(2378406,2,1588.5541,-6163.325,7.8191605,"Apothecary Hanes"),
(2378406,3,1600.5142,-6157.163,8.667747,"Apothecary Hanes"),
(2378406,4,1606.8141,-6158.777,8.844871,"Apothecary Hanes"),
(2378406,5,1615.0626,-6157.8174,9.339622,"Apothecary Hanes");
