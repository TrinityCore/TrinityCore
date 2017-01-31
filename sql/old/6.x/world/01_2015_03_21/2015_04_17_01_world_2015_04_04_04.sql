--
SET @ENTRY := 10978;
SET @Sprinkle:=7583;
SET @Quixxil:=10977;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY, @Sprinkle, @Quixxil);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Sprinkle AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Quixxil AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,17166,0,0,0,80,1097800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Legacki - On Spellhit 'Release Umi's Yeti' - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,15,10978,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Legacki - On Waypoint 15 Reached - Run Script"),
(@Sprinkle,0,0,0,8,0,100,0,17166,0,0,0,80,@Sprinkle*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Spellhit 'Release Umi's Yeti' - Run Script"),
(@Sprinkle,0,1,0,40,0,100,0,7,@Sprinkle,0,0,80,@Sprinkle*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Waypoint 7 Reached - Run Script"),
(@Quixxil,0,0,0,8,0,100,0,17166,0,0,0,80,@Quixxil*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Quixxil - On Spellhit 'Release Umi's Yeti' - Run Script"),
(@Quixxil,0,1,0,40,0,100,0,11,@Quixxil,0,0,80,@Quixxil*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Quixxil - On Waypoint 11 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1097800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Sprinkle*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Quixxil*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legacki - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,53,1,10978,0,0,0,2,1,0,0,0,0,0,0,0,"Legacki -On Script - Start Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,10980,20,0,0,0,0,0,"Legacki -On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legacki -On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Legacki -On Script  - Store target"),
(@Sprinkle*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Say Line 0"),
(@Sprinkle*100,9,1,0,0,0,100,0,1000,1000,0,0,53,1,@Sprinkle,0,0,0,2,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Start Waypoint"),
(@Sprinkle*100,9,2,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,19,10980,20,0,0,0,0,0,"Sprinkle - On Script - Say Line 1"),
(@Sprinkle*100,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Say Line 1"),
(@Sprinkle*100,9,4,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sprinkle - On Script  - Store target"),
(@Quixxil*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quixxil - On Script - Say Line 0"),
(@Quixxil*100,9,1,0,0,0,100,0,1000,1000,0,0,53,1,@Quixxil,0,0,0,2,1,0,0,0,0,0,0,0,"Quixxil - On Script - Start Waypoint"),
(@Quixxil*100,9,2,0,0,0,100,0,0,0,0,0,45,0,3,0,0,0,0,19,10980,20,0,0,0,0,0,"Quixxil - On Script - Say Line 1"),
(@Quixxil*100,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quixxil - On Script - Say Line 1"),
(@Quixxil*100,9,4,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quixxil - On Script - Say Line 2"),
(@Quixxil*100,9,5 ,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quixxil - On Script  - Store target");

-- Actionlist SAI
SET @ENTRY := 1097801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Sprinkle*100+1 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Quixxil*100+1 AND `source_type`=9;


INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legacki - On Script - Say Line 2"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legacki - On Script - Say Line 3"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legacki - On Script - Say Line 4"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,33,10978,0,0,0,0,0,12,1,0,0,0,0,0,0,"Legacki - On Script - Credit quest"),
(@Sprinkle*100+1,9,0,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Say Line 2"),
(@Sprinkle*100+1,9,1,0,0,0,100,0,2000,2000,0,0,33,@Sprinkle,0,0,0,0,0,12,1,0,0,0,0,0,0,"Sprinkle - On Script - Credit quest"),
(@Quixxil*100+1,9,1,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quixxil - On Script - Say Line 3"),
(@Quixxil*100+1,9,2,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quixxil - On Script - Say Line 4"),
(@Quixxil*100+1,9,3,0,0,0,100,0,2000,2000,0,0,33,@Quixxil,0,0,0,0,0,12,1,0,0,0,0,0,0,"Quixxil - On Script - Credit quest");

-- Umi's Mechanical Yeti SAI
SET @ENTRY := 10980;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,0,1,0,0,29,5,10,0,0,0,0,19,10978,10,0,0,0,0,0,"Umi's Mechanical Yeti - On Just Summoned - Start Follow Closest Creature 'Legacki'"),
(@ENTRY,0,1,0,38,0,100,0,0,2,0,0,29,5,10,0,0,0,0,19,@Sprinkle,10,0,0,0,0,0,"Umi's Mechanical Yeti - On Just Summoned - Start Follow Closest Creature 'Legacki'"),
(@ENTRY,0,2,0,38,0,100,0,0,3,0,0,29,5,10,0,0,0,0,19,@Quixxil,10,0,0,0,0,0,"Umi's Mechanical Yeti - On Just Summoned - Start Follow Closest Creature 'Legacki'"),
(@ENTRY,0,3,4,54,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,"Umi's Mechanical Yeti - On Just Summoned - Say Line 0"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umi's Mechanical Yeti - On Just Summoned - Despawn In 30000 ms"),
(@ENTRY,0,5,0,52,0,100,0,0,10980,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umi's Mechanical Yeti - On Text 0 Over - Say Line 1");

DELETE FROM `creature_text` WHERE `entry` IN (10980, 10978, @Quixxil, @Sprinkle);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10978, 0, 0, '%s jumps in fright!', 16, 0, 100, 0, 0, 0, 6301, 0, 'Legacki'),
(10978, 1, 0, 'Ahhhhh!!!', 12, 0, 100, 0, 0, 0, 6302, 0, 'Legacki'),
(10978, 2, 0, 'You big meanie! Who put you up to this?', 12, 0, 100, 0, 0, 0, 6303, 0, 'Legacki'),
(10978, 3, 0, 'It was Umi, wasn''t it?! She''s always playing jokes on me, and now she''s got you in on it too!', 12, 0, 100, 0, 0, 0, 6304, 0, 'Legacki'),
(10978, 4, 0, '%s sighs.', 16, 0, 100, 0, 0, 0, 6305, 0, 'Legacki'),
(@Quixxil, 0, 0, 'Oh!!! Get that thing away from me!', 12, 0, 100, 0, 0, 0, 6314, 0, 'Quixxil'),
(@Quixxil, 1, 0, '%s runs quickly away from Umi''s Mechanical yeti.', 16, 0, 100, 0, 0, 0, 6318, 0, 'Quixxil'),
(@Quixxil, 2, 0, 'Why do you chase me, Mechanical yeti?! WHY?!', 12, 0, 100, 0, 0, 0, 6317, 0, 'Quixxil'),
(@Quixxil, 3, 0, '%s looks relieved.', 16, 0, 100, 0, 0, 0, 6322, 0, 'Quixxil'),
(@Quixxil, 4, 0, 'I''m jumpy as it is... and people insist on scaring me... Next time, though, I''ll be ready!', 12, 0, 100, 0, 0, 0, 6320, 0, 'Quixxil'),
(@Sprinkle, 0, 0, '%s jumps in fright!', 16, 0, 100, 0, 0, 0, 6306, 0, 'Legacki'),
(@Sprinkle, 1, 0, 'Ahhhhh!!! What is that thing?!', 12, 0, 100, 0, 0, 0, 6307, 0, 'Legacki'),
(@Sprinkle, 2, 0, 'Umi sent you, didn''t she? She told me to expect a surprise, but I never thought that this is what she meant!', 12, 0, 100, 0, 0, 0, 6308, 0, 'Legacki'),
(10980, 0, 0, '%s marches around, roaring and making a ruckus.', 16, 0, 100, 0, 0, 0, 6327, 0, 'Umi''s Mechanical Yeti'),
(10980, 1, 0, 'RAAAAAAAR!', 12, 0, 100, 0, 0, 0, 6329, 0, 'Umi''s Mechanical Yeti');


DELETE FROM `waypoints` WHERE `entry` IN (10978, @Quixxil, @Sprinkle);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(10978, 1,6713.694,-4682.374,721.6163, 'Legacki'),
(10978, 2,6731.523,-4675.635,721.2076, 'Legacki'),
(10978, 3,6736.806,-4672.955,721.9132, 'Legacki'),
(10978, 4,6749.889,-4662.13,725.0011, 'Legacki'),
(10978, 5,6750.157,-4661.562,724.9875, 'Legacki'),
(10978, 6,6732.859,-4641.781,722.8784, 'Legacki'),
(10978, 7,6727.719,-4641.233,721.6862, 'Legacki'),
(10978, 8,6715.982,-4643.644,721.1971, 'Legacki'),
(10978, 9,6719.307,-4652.817,721.231, 'Legacki'),
(10978, 10,6715.004,-4685.518,721.466, 'Legacki'),
(10978, 11,6718.75,-4705.675,721.9097, 'Legacki'),
(10978, 12,6712.263,-4717.947,721.5077, 'Legacki'),
(10978, 13,6701.636,-4714.284,721.6529, 'Legacki'),
(10978, 14,6701.108,-4695.846,722.3613, 'Legacki'),
(10978, 15,6705.608,-4686.181,721.9736, 'Legacki'),
(@Quixxil, 1, -6186.462402, -1096.938965, -213.828033, 'Quixxil'),
(@Quixxil, 2, -6165.831543, -1100.158203, -210.395004, 'Quixxil'),
(@Quixxil, 3, -6146.718750, -1120.232056, -212.840530, 'Quixxil'),
(@Quixxil, 4, -6160.913574, -1141.027466, -217.996246, 'Quixxil'),
(@Quixxil, 5, -6184.303711, -1125.439087, -217.041824, 'Quixxil'),
(@Quixxil, 6, -6203.271484, -1111.438354, -219.371887, 'Quixxil'),
(@Quixxil, 7, -6213.762695, -1080.857422, -211.627533, 'Quixxil'),
(@Quixxil, 8, -6184.807129, -1050.598633, -191.913223, 'Quixxil'),
(@Quixxil, 9, -6173.853516, -1054.144165, -190.152405, 'Quixxil'),
(@Quixxil, 10, -6179.203613, -1041.906372, -185.499283, 'Quixxil'),
(@Quixxil, 11, -6197.859863, -1082.170044, -209.164001, 'Quixxil'),
(@Sprinkle, 1, -7114.151855, -3811.191406, 8.390815, 'Sprinkle'),
(@Sprinkle, 2, -7155.397949, -3820.387695, 8.370462, 'Sprinkle'),
(@Sprinkle, 3, -7178.134766, -3791.506836, 8.370436, 'Sprinkle'),
(@Sprinkle, 4, -7160.750488, -3758.740723, 8.370436, 'Sprinkle'),
(@Sprinkle, 5, -7136.473145, -3747.802246, 8.407521, 'Sprinkle'),
(@Sprinkle, 6, -7109.993652, -3739.603760, 9.105528, 'Sprinkle'),
(@Sprinkle, 7, -7111.109863, -3741.780029, 8.609260, 'Sprinkle');
