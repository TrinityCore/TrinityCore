-- Hurley Blackbreath script fix
UPDATE `creature_text` SET `Emote`=5 WHERE `CreatureID`=9537;

UPDATE `waypoints` SET `position_x`=892.9590,`position_y`=-141.4704,`position_z`=-49.7570 WHERE `entry`=9537 AND `pointid`=2;
UPDATE `waypoints` SET `position_x`=888.984,`position_y`=-152.599,`position_z`=-49.76 WHERE `entry`=9541 AND `pointid`=1;
UPDATE `waypoints` SET `position_x`=889.8773,`position_y`=-141.2147,`position_z`=-49.7567 WHERE `entry`=9541 AND `pointid`=2;
UPDATE `waypoints` SET `position_x`=885.926,`position_y`=-145.908,`position_z`=-49.76 WHERE `entry`=9541000 AND `pointid`=1;
UPDATE `waypoints` SET `position_x`=892.9106,`position_y`=-140.2764,`position_z`=-49.7557 WHERE `entry`=9541000 AND `pointid`=2;
UPDATE `waypoints` SET `position_x`=897.1912,`position_y`=-136.4424,`position_z`=-49.7516 WHERE `entry`=9541001 AND `pointid`=2;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (9537,-71997,-71998,-71999);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (953700,7199700,7199800,7199900) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9537,0,0,0,2,0,100,0,0,30,30000,45000,0,11,14872,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Less than 30% HP - Cast 'Drunken Rage'"),
(9537,0,1,0,9,0,100,0,0,5,10000,15000,0,11,9573,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Range - Cast 'Flame Breath'"),
(9537,0,2,0,0,0,100,0,5000,6000,10000,14000,0,11,26211,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Hurley Blackbreath - IC - Cast 'Hamstring'"),
(9537,0,3,0,0,0,100,0,5000,8000,8000,13000,0,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Hurley Blackbreath - IC - Cast 'Mortal Strike'"),
(9537,0,4,5,11,0,100,0,0,0,0,0,0,144,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Spawn - Set Immune to Players"),
(9537,0,5,6,61,0,100,0,0,0,0,0,0,145,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Link - Set Immune to NPC's"),
(9537,0,6,0,61,0,100,0,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Link - Set Invisible"),
(9537,0,7,8,38,0,100,1,1,1,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Data Set 1 1 - Set Visible"),
(9537,0,8,9,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,11,9541,50,0,0,0,0,0,0,"Hurley Blackbreath - On Link - Set Data 1 1 to 'Blackbreath Crony'"),
(9537,0,9,10,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Link - Say Line 0"),
(9537,0,10,0,61,0,100,0,0,0,0,0,0,53,1,9537,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Link - Start Waypoint"),
(9537,0,11,12,40,0,100,0,3,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Waypoint 3 Reached - Set Home Position"),
(9537,0,12,0,61,0,100,0,0,0,0,0,0,80,953700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Link - Run Script"),
(9537,0,13,14,4,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,11,9541,50,0,0,0,0,0,0,"Hurley Blackbreath - On Agro - Set Data 1 2 to 'Blackbreath Crony'"),
(9537,0,14,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Link - Attack"),
(9537,0,15,0,38,0,100,0,1,2,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Hurley Blackbreath - On Data Set 1 2 - Attack"),

(953700,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Hurley Blackbreath - On Script - Set Orientation"),
(953700,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Script - Say Line 1"),
(953700,9,2,0,0,0,100,0,3000,3000,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Script - Remove Immune to Players"),
(953700,9,3,0,0,0,100,0,0,0,0,0,0,145,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Script - Remove Immune to NPC's"),
(953700,9,4,0,0,0,100,0,0,0,0,0,0,89,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hurley Blackbreath - On Script - Set Random Movement"),

(-71997,0,0,0,0,0,100,0,1000,3000,4000,7000,0,11,15581,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Blackbreath Crony - IC - Cast 'Sinister Strike'"),
(-71997,0,1,0,0,0,100,0,2000,2000,11000,12000,0,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Blackbreath Crony - IC - Cast 'Rupture'"),
(-71997,0,2,3,11,0,100,0,0,0,0,0,0,144,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Spawn - Set Immune to Players"),
(-71997,0,3,4,61,0,100,0,0,0,0,0,0,145,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Set Immune to NPC's"),
(-71997,0,4,0,61,0,100,0,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Set Invisible"),
(-71997,0,5,6,38,0,100,0,1,1,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Data Set 1 1 - Set Visible"),
(-71997,0,6,0,61,0,100,0,0,0,0,0,0,53,1,9541,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Start Waypoint"),
(-71997,0,7,8,40,0,100,0,3,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Waypoint 3 Reached - Set Home Position"),
(-71997,0,8,0,61,0,100,0,0,0,0,0,0,80,7199700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Run Script"), 
(-71997,0,9,10,4,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,11,9541,50,0,0,0,0,0,0,"Blackbreath Crony - On Agro - Set Data 1 2 to 'Blackbreath Crony'"),
(-71997,0,10,11,61,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,11,9537,50,0,0,0,0,0,0,"Blackbreath Crony - On Agro - Set Data 1 2 to 'Hurley Blackbreath'"),
(-71997,0,11,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Attack"),
(-71997,0,12,0,38,0,100,0,1,2,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Blackbreath Crony - On Data Set 1 2 - Attack"),

(7199700,9,0,0,0,0,100,0,3500,3500,0,0,0,89,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Script - Set Random Movement"),
(7199700,9,1,0,0,0,100,0,0,0,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Script - Remove Immune to Players"),
(7199700,9,2,0,0,0,100,0,0,0,0,0,0,145,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Script - Remove Immune to NPC's"),

(-71998,0,0,0,0,0,100,0,1000,3000,4000,7000,0,11,15581,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Blackbreath Crony - IC - Cast 'Sinister Strike'"),
(-71998,0,1,0,0,0,100,0,2000,2000,11000,12000,0,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Blackbreath Crony - IC - Cast 'Rupture'"),
(-71998,0,2,3,11,0,100,0,0,0,0,0,0,144,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Spawn - Set Immune to Players"),
(-71998,0,3,4,61,0,100,0,0,0,0,0,0,145,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Set Immune to NPC's"),
(-71998,0,4,0,61,0,100,0,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Set Invisible"),
(-71998,0,5,6,38,0,100,0,1,1,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Data Set 1 1 - Set Visible"),
(-71998,0,6,0,61,0,100,0,0,0,0,0,0,53,1,9541000,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Start Waypoint"),
(-71998,0,7,8,40,0,100,0,3,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Waypoint 3 Reached - Set Home Position"),
(-71998,0,8,0,61,0,100,0,0,0,0,0,0,80,7199800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Run Script"),
(-71998,0,9,10,4,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,11,9541,50,0,0,0,0,0,0,"Blackbreath Crony - On Agro - Set Data 1 2 to 'Blackbreath Crony'"),
(-71998,0,10,11,61,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,11,9537,50,0,0,0,0,0,0,"Blackbreath Crony - On Agro - Set Data 1 2 to 'Hurley Blackbreath'"),
(-71998,0,11,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Attack"),
(-71998,0,12,0,38,0,100,0,1,2,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Blackbreath Crony - On Data Set 1 2 - Attack"),

(7199800,9,0,0,0,0,100,0,4000,4000,0,0,0,89,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Script - Set Random Movement"),
(7199800,9,1,0,0,0,100,0,0,0,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Script - Remove Immune to Players"),
(7199800,9,2,0,0,0,100,0,0,0,0,0,0,145,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Script - Remove Immune to NPC's"),

(-71999,0,0,0,0,0,100,0,2000,2000,11000,12000,0,11,15581,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Blackbreath Crony - IC - Cast 'Sinister Strike'"),
(-71999,0,1,0,0,0,100,0,3000,5000,15000,20000,0,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Blackbreath Crony - IC - Cast 'Rupture'"),
(-71999,0,2,3,11,0,100,0,0,0,0,0,0,144,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Spawn - Set Immune to Players"),
(-71999,0,3,4,61,0,100,0,0,0,0,0,0,145,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Set Immune to NPC's"),
(-71999,0,4,0,61,0,100,0,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Set Invisible"),
(-71999,0,5,6,38,0,100,0,1,1,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Data Set 1 1 - Set Visible"),
(-71999,0,6,0,61,0,100,0,0,0,0,0,0,53,1,9541001,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Start Waypoint"),
(-71999,0,7,8,40,0,100,0,3,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Waypoint 3 Reached - Set Home Position"),
(-71999,0,8,0,61,0,100,0,0,0,0,0,0,80,7199900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Run Script"),
(-71999,0,9,10,4,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,11,9541,50,0,0,0,0,0,0,"Blackbreath Crony - On Agro - Set Data 1 2 to 'Blackbreath Crony'"),
(-71999,0,10,11,61,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,11,9537,50,0,0,0,0,0,0,"Blackbreath Crony - On Agro - Set Data 1 2 to 'Hurley Blackbreath'"),
(-71999,0,11,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Link - Attack"),
(-71999,0,12,0,38,0,100,0,1,2,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Blackbreath Crony - On Data Set 1 2 - Attack"),

(7199900,9,0,0,0,0,100,0,3000,3000,0,0,0,89,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Script - Set Random Movement"),
(7199900,9,1,0,0,0,100,0,0,0,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Script - Remove Immune to Players"),
(7199900,9,2,0,0,0,100,0,0,0,0,0,0,145,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blackbreath Crony - On Script - Remove Immune to NPC's");
