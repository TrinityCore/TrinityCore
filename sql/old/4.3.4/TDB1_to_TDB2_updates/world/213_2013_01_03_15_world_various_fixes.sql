-- Issue 7541: Shambling Horror immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|1|2|4|8|16|64|512|1024|4096|8192|65536|131072|524288|4194304|536870912 WHERE `entry`=37698;

/* Removed 4.x
-- Issue 7436: Ground bound Highperch 
-- Highperch Soarer
SET @NPC := 21708;
SET @PATH := @NPC*10;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=6139;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5155.09,`position_y`=-1194.89,`position_z`=73.70869 WHERE `guid`=@NPC;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5155.09,-1194.89,73.70869,0,0,0,100,0),
(@PATH,2,-5155.986,-1199.748,81.49023,0,0,0,100,0),
(@PATH,3,-5166.314,-1220.043,81.76808,0,0,0,100,0),
(@PATH,4,-5170.551,-1226.347,76.71234,0,0,0,100,0),
(@PATH,5,-5178.024,-1237.037,72.43468,0,0,0,100,0),
(@PATH,6,-5190.296,-1239.181,71.90687,0,0,0,100,0),
(@PATH,7,-5215.796,-1225.133,69.76797,0,0,0,100,0),
(@PATH,8,-5221.52,-1209.387,67.79574,0,0,0,100,0),
(@PATH,9,-5219.366,-1194.92,67.15694,0,0,0,100,0),
(@PATH,10,-5209.852,-1187.224,65.96239,0,0,0,100,0),
(@PATH,11,-5194.886,-1188.915,70.71236,0,0,0,100,0),
(@PATH,12,-5181.055,-1199.332,60.29574,0,0,0,100,0),
(@PATH,13,-5158.846,-1213.597,57.6291,0,0,0,100,0),
(@PATH,14,-5122.129,-1222.279,42.46242,0,0,0,100,0),
(@PATH,15,-5110.988,-1230.767,15.32349,0,0,0,100,0),
(@PATH,16,-5084.673,-1227.625,-11.81538,0,0,0,100,0),
(@PATH,17,-5065.282,-1209.691,-34.89864,0,0,0,100,0),
(@PATH,18,-5052.477,-1181.261,-39.42649,0,0,0,100,0),
(@PATH,19,-5025.058,-1165.288,-32.56528,0,0,0,100,0),
(@PATH,20,-5004.282,-1140.431,-38.3154,0,0,0,100,0),
(@PATH,21,-4984.813,-1123.683,-38.17639,0,0,0,100,0),
(@PATH,22,-4971.478,-1109.776,-38.17639,0,0,0,100,0),
(@PATH,23,-4949.74,-1096.296,-32.42633,0,0,0,100,0),
(@PATH,24,-4927.954,-1090.275,-24.84298,0,0,0,100,0),
(@PATH,25,-4909.837,-1080.728,-14.0652,0,0,0,100,0),
(@PATH,26,-4914.713,-1066.641,-7.898551,0,0,0,100,0),
(@PATH,27,-4927.922,-1056.954,-3.352009,0,0,0,100,0),
(@PATH,28,-4942.696,-1055.217,8.220422,0,0,0,100,0),
(@PATH,29,-4951.954,-1049.145,14.62554,0,0,0,100,0),
(@PATH,30,-4960.176,-1028.92,20.03323,0,0,0,100,0),
(@PATH,31,-4970.474,-1008.432,22.08879,0,0,0,100,0),
(@PATH,32,-4980.969,-992.9671,23.42848,0,0,0,100,0),
(@PATH,33,-4993.734,-980.054,23.75917,0,0,0,100,0),
(@PATH,34,-5012.753,-967.9377,24.0925,0,0,0,100,0),
(@PATH,35,-5032.862,-971.138,30.92584,0,0,0,100,0),
(@PATH,36,-5052.127,-982.1085,39.0092,0,0,0,100,0),
(@PATH,37,-5060.675,-991.1913,52.28708,0,0,0,100,0),
(@PATH,38,-5072.277,-1008.99,67.84268,0,0,0,100,0),
(@PATH,39,-5090.256,-1005.558,79.18673,0,0,0,100,0),
(@PATH,40,-5106.005,-1004.311,73.88409,0,0,0,100,0);
*/

-- Issue 8639: Eyes of the Eagle
-- Talonshrike's Egg
SET @ENTRY := 186814;
SET @SOURCETYPE := 1;
UPDATE gameobject_template SET AIName="SmartGameObjectAI" WHERE entry IN(186814,190283);
UPDATE creature_template SET AIName="SmartAI" WHERE entry=24518;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(186814,190283) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24518 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- first egg
(186814,1,0,0,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,11,24518,500,0,0.0,0.0,0.0,0.0,"ON egg USE notify Talonshrike"),
(186814,1,1,0,70,0,100,0,2,0,0,0,45,0,2,0,0,0,0,11,24518,500,0,0.0,0.0,0.0,0.0,"ON egg USE notify Talonshrike to set attackable"),
-- second egg
(190283,1,0,0,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,11,24518,500,0,0.0,0.0,0.0,0.0,"ON egg USE notify Talonshrike"),
(190283,1,1,0,70,0,100,0,2,0,0,0,45,0,2,0,0,0,0,11,24518,500,0,0.0,0.0,0.0,0.0,"ON egg USE notify Talonshrike to set attackable"),
-- Talonshrike
(24518,0,0,0,38,0,100,0,0,1,0,0,69,0,0,0,0,0,0,8,0,0,0,1597.4,-3903.79,79.702,0.0,"ON notification fly TO nest"),
(24518,0,1,0,0,0,100,0,5000,5000,10000,12000,11,49865,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0," USE Eye Peck"),
(24518,0,2,0,0,0,100,0,3000,3000,5000,7000,11,32909,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0," USE Talon Strike"),
(24518,0,3,0,38,0,100,0,0,2,0,0,19,256,0,0,0,0,0,1, 0, 0, 0, 0, 0, 0, 0, "Talonshrike - On notification - Remove UNIT_FLAG_IMMUNE_TO_PC");
