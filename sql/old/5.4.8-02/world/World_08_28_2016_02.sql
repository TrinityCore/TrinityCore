-- Actionlist SAI
SET @ENTRY := 4246500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,43809,5,980000,0,0,0,8,0,0,0,2339.98,195.193,179.936,2.95537,"Script - Summon Torunscar"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Therazane Says 1"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,4000,4000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Therazane Says 2"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,4000,4000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Therazane Says 3"),
(@ENTRY,9,4,0,0,0,100,0,4000,4000,4000,4000,1,0,0,0,0,0,0,19,43809,40,0,0,0,0,0,"Script - Torunscar Says 1"),
(@ENTRY,9,5,0,0,0,100,0,4000,4000,4000,4000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Therazane Says 4"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,4000,4000,1,1,0,0,0,0,0,19,43809,40,0,0,0,0,0,"Script -Torunscar Says 2"),
(@ENTRY,9,7,0,0,0,100,0,4000,4000,4000,4000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Therazane Says 5"),
(@ENTRY,9,8,0,0,0,100,0,4000,4000,4000,4000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Therazane Says 6"),
(@ENTRY,9,9,0,0,0,100,0,4000,4000,4000,4000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Therazane Says 7"),
(@ENTRY,9,10,0,0,0,100,0,4000,4000,4000,4000,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Therazane Says 8"),
(@ENTRY,9,11,0,0,0,100,0,4000,4000,4000,4000,1,2,0,0,0,0,0,19,43809,40,0,0,0,0,0,"Script - Torunscar Says 3"),
(@ENTRY,9,12,0,0,0,100,0,4000,4000,4000,4000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Therazane Says 9");

-- Actionlist SAI
SET @ENTRY := 4486000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,53,0,44860,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Start WP 1 Harrison Jones"),
(@ENTRY,9,1,0,0,0,100,0,6000,6000,6000,6000,12,46720,5,45000,0,0,0,8,0,0,0,-8948.19,-1528.95,94.4531,4.89651,"Script - Summon Pygmy Ambusher"),
(@ENTRY,9,2,0,0,0,100,0,200,200,200,200,20,0,0,0,0,0,0,11,46720,30,0,0,0,0,0,"Script - Pygmy Attacks"),
(@ENTRY,9,3,0,0,0,100,0,10,10,10,10,9,1,0,0,0,0,0,20,205388,30,0,0,0,0,0,"Script - Activate Brazier"),
(@ENTRY,9,4,0,0,0,100,0,100,100,100,100,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Says 1"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,2000,2000,53,0,44861,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ WP 2"),
(@ENTRY,9,6,0,0,0,100,0,100,100,100,100,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Says 2"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,1000,1000,53,0,44862,0,0,0,0,17,0,20,0,0,0,0,0,"Script - Player Go Waypoint"),
(@ENTRY,9,9,0,0,0,100,0,10,10,10,10,11,110263,2,0,0,0,0,1,0,0,0,0,0,0,0,"Script - Cast Explosion"),
(@ENTRY,9,10,0,0,0,100,0,200,200,200,200,62,1,0,0,0,0,0,17,0,20,0,-9210.32,-1554.97,65.4522,3.27979,"Script - Teleport Player");


-- Actionlist SAI
SET @ENTRY := 4518000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,200,200,200,200,1,0,200,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Says 1"),
(@ENTRY,9,1,0,0,0,100,0,300,300,300,300,53,1,45180,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ WP Start"),
(@ENTRY,9,2,0,0,0,100,0,11000,11000,11000,11000,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Says 2"),
(@ENTRY,9,4,0,0,0,100,0,600,600,600,600,53,1,45181,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ WP Start 2"),
(@ENTRY,9,5,0,0,0,100,0,1,1,1,1,11,82929,2,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Jump 1"),
(@ENTRY,9,6,0,0,0,100,0,200,200,200,200,1,2,1,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Says 3"),
(@ENTRY,9,7,0,0,0,100,0,1,1,1,1,11,82929,2,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Jump 2"),
(@ENTRY,9,8,0,0,0,100,0,600,600,600,600,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Despawn");


-- Actionlist SAI
SET @ENTRY := 4529601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,1000,1000,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Says 2"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,3000,3000,53,1,45298,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Start WP 3"),
(@ENTRY,9,2,0,0,0,100,0,16000,16000,16000,16000,53,1,45299,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Start WP 4"),
(@ENTRY,9,3,0,0,0,100,0,200,200,200,200,11,82929,2,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Jump 1"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,1000,1000,11,82929,2,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Jump 2"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,2000,2000,11,82929,2,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Jump 3"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,2000,2000,11,82929,2,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Jump 4"),
(@ENTRY,9,7,0,0,0,100,0,2000,2000,2000,2000,11,82929,2,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Jump 5"),
(@ENTRY,9,8,0,0,0,100,0,2000,2000,2000,2000,11,82929,2,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Jump 6"),
(@ENTRY,9,9,0,0,0,100,0,12000,12000,12000,12000,53,82929,45300,0,0,0,0,1,0,0,0,0,0,0,0,"Script - HJ Start WP 5");

-- Actionlist SAI
SET @ENTRY := 4801900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 4868100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 4868101;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 4868102;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;


-- Actionlist SAI
SET @ENTRY := 4933700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"talk 0"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,3000,3000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"talk 1"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnell - On spawn - Talk1");

-- Actionlist SAI
SET @ENTRY := 4934000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,46598,1,0,0,0,0,19,49337,10,0,0,0,0,0,"Corpse - Action list - cast spell");


-- Actionlist SAI
SET @ENTRY := 5037400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,500,500,500,500,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Text 1"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,3000,3000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Text 2 and kill himself"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,5000,5000,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Die self"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,75,44427,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Add Aura 'Enrage'"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Despawn In 9000 ms");


-- Actionlist SAI
SET @ENTRY := 5041400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,53,0,5041400,0,0,20000,0,1,0,0,0,0,0,0,0,"waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,3000,3000,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kneel after 3 sec"),
(@ENTRY,9,2,0,0,0,100,0,11000,11000,11000,11000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Type a script description here."),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,2000,2000,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"resume wp"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,19,1568,10,0,0,0,0,0,"On Script - Play Emote 25"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,19,1568,10,0,0,0,0,0,"On Script - Say Line 1"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 26"),
(@ENTRY,9,7,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,8,0,0,0,100,0,2000,2000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 66"),
(@ENTRY,9,10,0,0,0,100,0,6000,6000,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn In 2000 ms");

DELETE FROM `smart_scripts` WHERE `entryorguid`IN (56056,56047,56046,56048,56045,56049,56059,57100,57102,57103,57106,57105,56033,56021,56020,56019,56018,56017,56016,56015,56014,56012,56011,56010,56009,56008,55765,56037,56038,56039,57100,56070,56067,56066,56065,56064,56063,56060,58964,51111,722);


-- Silverwing Warrior SAI
SET @ENTRY := 12897;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25000,28000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Rend");

-- Short John Mithril SAI
SET @ENTRY := 14508;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,40,0,100,0,1,14508,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Waypoint 1 Reached - Say Line 0"),
(@ENTRY,0,2,3,40,0,100,0,16,14508,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Waypoint 16 Reached - Say Line 1"),
(@ENTRY,0,3,0,61,0,100,0,16,14508,0,0,11,23176,0,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Waypoint 16 Reached - Cast 'Summon Pirate Booty (DND)'"),
(@ENTRY,0,4,0,40,0,100,0,33,14508,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.41568,"Short John Mithril - On Waypoint 33 Reached - Set Orientation 4,41568");

-- Cyrukh the Firelord SAI
SET @ENTRY := 21181;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,12000,14000,11,39429,0,0,0,0,0,4,0,0,0,0,0,0,0,"Cast Fel Flamestrike"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,22000,11,18945,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Knock Away"),
(@ENTRY,0,2,0,9,0,100,0,0,10,25000,26500,11,39425,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Trample on Close"),
(@ENTRY,0,3,0,11,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyrukh the Firelord <The Dirge of Karabor> - On Spawn - Set Unit Flags"),
(@ENTRY,0,5,6,40,0,100,0,1,21181,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Set Home Position"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Set Unit Flags"),
(@ENTRY,0,7,8,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Set Aggresive"),
(@ENTRY,0,8,9,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,21685,0,0,0,0,0,0,"Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Start Attack"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,21686,0,0,0,0,0,0,"Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Start Attack"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,21687,0,0,0,0,0,0,"Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Start Attack"),
(@ENTRY,0,11,0,1,0,100,0,0,0,15000,30000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyrukh the Firelord <The Dirge of Karabor> - IC - Say"),
(@ENTRY,0,12,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,21024,0,0,0,0,0,0,"Cyrukh the Firelord <The Dirge of Karabor> - On Death - Set Data"),
(@ENTRY,0,13,0,54,0,100,0,0,0,0,0,11,36329,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyrukh the Firelord <The Dirge of Karabor> - On Just SUmmoned - Cast Cyrukh Fire Kit");

-- Rona Greenteeth SAI
SET @ENTRY := 56041;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,0,24699,1,60,60,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Despawn Par Athena");


-- Infernal SAI
SET @ENTRY := 56036;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,7,0,100,0,0,0,0,0,41,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"");

-- Rona Greenteeth SAI
SET @ENTRY := 56041;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,0,24699,1,60,60,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Despawn Par Athena");

-- Mule SAI
SET @ENTRY := 56042;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2200,2200,11,59710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tir simple"),
(@ENTRY,0,1,0,0,0,100,0,15000,15000,70000,70000,11,59712,1,0,0,0,0,2,0,0,0,0,0,0,0,"Fleche noire"),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,59713,1,0,0,0,0,18,30,0,0,0,0,0,0,"Tir multiples"),
(@ENTRY,0,3,0,23,0,100,0,24699,1,60,60,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Despawn Par Athena");

--  SAI
SET @ENTRY := 191124;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;

-- Barnil Stonepot SAI
SET @ENTRY := 716;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Barnil Stonepot - Link - Say Line"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Barnil Stonepot - Link - Close Gossip");

-- Angus SAI
SET @ENTRY := 10610;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Data Set 1 0 - Set Active On"),
(@ENTRY,0,2,0,61,0,100,0,1,0,0,0,4,6598,0,0,0,0,0,21,50,0,0,0,0,0,0,"Angus - On Data Set 1 0 - Play Sound 6598"),
(@ENTRY,0,3,4,40,0,100,0,4,10610,0,0,54,250000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,61,0,100,0,4,10610,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angus - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,5,0,38,0,100,0,2,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6009.25,-202.65,406.983,2,"Shorty - On Data Set 2 0 - Move To Position"),
(@ENTRY,0,6,0,38,0,100,0,3,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.58825,"Shorty - On Data Set 3 0 - Set Orientation 1.58825");

-- Rifleman Wheeler SAI
SET @ENTRY := 10803;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,61,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wheeler - On Data Set 1 0 - Set Active On"),
(@ENTRY,0,2,0,38,0,100,0,2,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.44346,"Wheeler - On Data Set 2 0 - Set Orientation 2,443461"),
(@ENTRY,0,3,0,38,0,100,0,3,0,0,0,11,16767,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wheeler - On Data Set 3 0 - Cast 'Shoot'"),
(@ENTRY,0,4,0,38,0,100,0,4,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.00565,"Wheeler - On Data Set 4 0 - Set Orientation 4.00565"),
(@ENTRY,0,5,0,38,0,100,0,5,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.44346,"Wheeler - On Data Set 5 0 - Set Orientation 2.443461"),
(@ENTRY,0,6,0,38,0,100,0,6,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.00565,"Wheeler - On Data Set 6 0 - Set Orientation 4.00565"),
(@ENTRY,0,7,0,38,0,100,0,7,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.44346,"Wheeler - On Data Set 7 0 - Set Orientation 2.443461"),
(@ENTRY,0,8,0,38,0,100,0,8,0,0,0,11,16775,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wheeler - On Data Set 8 0 - Cast 'Shoot'"),
(@ENTRY,0,9,0,38,0,100,0,9,0,0,0,11,16778,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wheeler - On Data Set 9 0 - Cast 'Shoot'"),
(@ENTRY,0,10,0,38,0,100,0,10,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.00565,"Wheeler - On Data Set 10 0 - Set Orientation 4.00565"),
(@ENTRY,0,11,0,38,0,100,0,11,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.44346,"Wheeler - On Data Set 11 0 - Set Orientation 4.00565"),
(@ENTRY,0,12,0,38,0,100,0,12,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.00565,"Wheeler - On Data Set 12 0 - Set Orientation 4.00565"),
(@ENTRY,0,13,0,38,0,100,0,13,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.77803,"Wheeler - On Data Set 13 0 - Set Orientation 4.77803"),
(@ENTRY,0,14,0,38,0,100,0,14,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.01942,"Wheeler - On Data Set 14 0 - Set Orientation 3.01942"),
(@ENTRY,0,15,0,38,0,100,0,15,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6008.53,-199.145,406.687,4.37218,"Wheeler - On Data Set 15 0 - Move To Position"),
(@ENTRY,0,16,0,38,0,100,0,16,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.37218,"Wheeler - On Data Set 16 0 - Set Orientation 4.372177");

-- Spotter Klemmy SAI
SET @ENTRY := 10805;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,61,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klemmy - On Data Set 1 0 - Set Active On"),
(@ENTRY,0,2,0,38,0,100,0,2,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.59936,"Spotter Klemmy - On Data Set 2 0 - Set Orientation 5,59936"),
(@ENTRY,0,3,0,38,0,100,0,3,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6077.43,-213.257,424.05,5.59936,"Spotter Klemmy - On Data Set 3 0 - Move To Position"),
(@ENTRY,0,4,0,38,0,100,0,4,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6065.9,-202.298,424.369,5,"Spotter Klemmy - On Data Set 4 0 - Move To Position"),
(@ENTRY,0,5,0,38,0,100,0,5,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.59936,"Spotter Klemmy - On Data Set 5 0 - Set Orientation 5.59936"),
(@ENTRY,0,6,0,38,0,100,0,6,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.0985,"Spotter Klemmy - On Data Set 6 0 - Set Orientation 4.0985"),
(@ENTRY,0,7,0,38,0,100,0,7,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.0985,"Spotter Klemmy - On Data Set 7 0 - Set Orientation 4.0985"),
(@ENTRY,0,8,0,38,0,100,0,8,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6077.43,-213.257,424.05,5.59936,"Spotter Klemmy - On Data Set 8 0 - Move To Position"),
(@ENTRY,0,9,0,38,0,100,0,9,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.84489,"Spotter Klemmy - On Data Set 9 0 - Set Orientation 2.844887"),
(@ENTRY,0,10,0,38,0,100,0,10,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6071.88,-212.831,422.929,5,"Spotter Klemmy - On Data Set 10 0 - Move To Position"),
(@ENTRY,0,11,0,38,0,100,0,11,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.04228,"Spotter Klemmy - On Data Set 11 0 - Set Orientation 6.04228"),
(@ENTRY,0,12,0,38,0,100,0,12,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6065.9,-202.298,424.369,5,"Spotter Klemmy - On Data Set 12 0 - Move To Position"),
(@ENTRY,0,13,0,38,0,100,0,13,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.0985,"Spotter Klemmy - On Data Set 13 0 - Set Orientation 4.0985"),
(@ENTRY,0,14,0,38,0,100,0,14,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6064.07,-209.851,421.98,6.10275,"Spotter Klemmy - On Data Set 14 0 - Move To Position"),
(@ENTRY,0,15,0,38,0,100,0,15,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6061.97,-218.956,421.085,5.92054,"Spotter Klemmy - On Data Set 15 0 - Move To Position"),
(@ENTRY,0,16,0,38,0,100,0,16,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6040.96,-221.929,414.921,5.92054,"Spotter Klemmy - On Data Set 16 0 - Move To Position"),
(@ENTRY,0,17,0,38,0,100,0,17,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6007.3,-200.348,406.777,3.28222,"Spotter Klemmy - On Data Set 17 0 - Move To Position"),
(@ENTRY,0,18,0,38,0,100,0,18,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.28222,"Spotter Klemmy - On Data Set 18 0 - Set Orientation 3.282219");

-- Noxxious Scion SAI
SET @ENTRY := 13696;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,63,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Noxxious Scion - On Just created - Attack");

-- Highlord Demitrian SAI
SET @ENTRY := 14347;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,7786,0,0,0,12,14435,2,180000,0,0,0,7,0,0,0,0,0,0,0,"Highlord Demitrian - On Quest 'Thunderaan the Windseeker' Finished - Summon Creature 'Prince Thunderaan'"),
(@ENTRY,0,1,0,20,0,100,0,7786,0,0,0,12,14435,6,60000,0,0,0,8,0,0,0,-6241.77,1717.14,4.25042,0.680879,"Highlord Demitrian - On Quest Thunderaan the Windseeker Finished - Summon Creature Prince Thunderaan at XYZO");

-- Ambassador Sunsorrow SAI
SET @ENTRY := 16287;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,98,7178,10378,0,0,0,0,7,0,0,0,0,0,0,0,"Ambassador Sunsorrow - On Gossip Option 0 Selected - SEND_GOSSIP_MENU TEXT"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,98,7178,8458,0,0,0,0,7,0,0,0,0,0,0,0,"Ambassador Sunsorrow - On Gossip Hello - SEND_GOSSIP_MENU TEXT");

-- Sangrias Stillblade SAI
SET @ENTRY := 17716;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,30,0,0,11,22120,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sangrias Stillblade - Within 0-30 Range - Cast 'Charge' (No Repeat)");

UPDATE `quest_template` SET `SpecialFlags` = 2 WHERE `Id` IN (27868,9678,27866,27863,13899,12274,12473,11198,10299,10329,10330,10321,10338,10322,10365,10323);

-- Ruul the Darkener SAI
SET @ENTRY := 21315;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,14000,15000,11,39153,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Darkfury"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,12000,27000,11,35871,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Spellbreaker"),
(@ENTRY,0,2,0,9,0,100,0,0,5,8000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Cleave on Close"),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Ruul the Darkener - On aggro -  ActionList"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,85,38343,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ruul the Darkener - On death -  Summon Ruul's Nether Drake With Invoker_cast"),
(@ENTRY,0,5,0,0,0,100,0,3000,3000,6000,6000,11,36073,0,0,0,0,0,2,0,0,0,0,0,0,0,"ENTRY - IC - CAST"),
(@ENTRY,0,6,0,0,0,100,0,5000,5000,5000,5000,11,39153,0,0,0,0,0,2,0,0,0,0,0,0,0,"ENTRY - IC - CAST"),
(@ENTRY,0,7,0,0,0,100,0,1000,1000,4000,4000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"ENTRY - IC - CAST");

-- Bjorn Halgurdsson SAI
SET @ENTRY := 24238;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,11000,13800,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,0,5800,6200,18900,21200,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Crush Armor"),
(@ENTRY,0,1,2,8,0,100,1,43315,0,0,0,84,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Spellhit 'Vrykul Insult' - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,8,0,100,0,40085,0,6000,6000,11,43315,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cast Vrykul Insult Spell"),
(@ENTRY,0,2,24,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - Within 0-10 Range - Say Line 1 (No Repeat)"),
(@ENTRY,0,3,4,9,0,100,1,0,10,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - Within 0-10 Range - Dismount (No Repeat)"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Spellhit 'Vrykul Insult' - Set Fly On (No Repeat)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,91,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On target within 10y - Remove unit_field_bytes1 (hovering)"),
(@ENTRY,0,6,0,8,0,100,0,6660,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Spellhit 'Shoot' - Start Attacking (No Repeat)"),
(@ENTRY,0,7,0,8,0,100,0,11971,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Spellhit 'Sunder Armor' - Start Attacking (No Repeat)"),
(@ENTRY,0,8,0,8,0,100,0,18802,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Spellhit 'Frost Shot' - Start Attacking (No Repeat)"),
(@ENTRY,0,9,0,8,0,100,0,43895,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Spellhit 'Lydell's Poison' - Start Attacking (No Repeat)"),
(@ENTRY,0,10,0,6,0,100,0,0,0,0,0,11,43371,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Just Died - Cast 'Bjorn Kill Credit' (No Repeat)"),
(@ENTRY,0,11,0,0,0,100,0,5000,10000,10000,15000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bjorn Halgurdsson - In Combat - Cast 'Mortal Strike' (No Repeat)"),
(@ENTRY,0,12,0,0,0,100,0,0,5000,10000,15000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bjorn Halgurdsson - In Combat - Cast 'Crush Armor' (No Repeat)"),
(@ENTRY,0,13,22,11,0,100,0,0,0,0,0,43,0,22657,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Respawn - Mount To Model 22657 (No Repeat)"),
(@ENTRY,0,14,15,7,0,100,0,0,0,0,0,43,0,22657,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Evade - Mount To Model 22657"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Evade - Set Fly Off"),
(@ENTRY,0,16,18,61,0,100,0,0,0,0,0,90,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On evade - Set unit_field_bytes1 (hovering)"),
(@ENTRY,0,17,0,0,0,100,0,1000,1000,1000,1000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - IC - Update Home Position"),
(@ENTRY,0,19,20,34,0,100,0,0,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.41052,"Bjorn Halgurdsson - On Reached WP1 - Set Orientation"),
(@ENTRY,0,20,21,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - Reached WP1 - Set Home Position"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - Reached WP1 - Reset Script"),
(@ENTRY,0,22,23,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Spawn - Set Passive"),
(@ENTRY,0,23,0,61,0,100,0,0,0,0,0,18,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Spawn - Set Non Attackable"),
(@ENTRY,0,24,25,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson -  On Spellhit  - Set Hostile"),
(@ENTRY,0,25,26,61,0,100,0,0,0,0,0,19,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson -  On Spellhit  - Set Attackable"),
(@ENTRY,0,26,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bjorn Halgurdsson -  On Spellhit  - Attack Invoker"),
(@ENTRY,0,27,28,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Evade - Set Passive"),
(@ENTRY,0,28,0,61,0,100,0,0,0,0,0,18,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Halgurdsson - On Evade - Set Non Attackable");

-- Icestorm SAI
SET @ENTRY := 26287;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,17000,22000,11,47425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Frost Breath"),
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,3,0,24165,0,0,0,0,1,0,0,0,0,0,0,0,"Icestorm - Just created - set model"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icestorm - Just created - turn fly on"),
(@ENTRY,0,3,0,0,0,100,0,1000,3000,3000,5000,11,47425,0,0,0,0,0,5,0,0,0,0,0,0,0,"Icestorm - Combat - Cast Frost Breath"),
(@ENTRY,0,4,5,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icestorm - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,4,11,6,0,100,0,0,0,0,0,11,49695,3,0,0,0,0,1,0,0,0,0,0,0,0,"Icestorm - On death - Cast Summon Thel'zan's Phylactery"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icestorm - Between 0-7% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,27843,100,0,0,0,0,0,"Wyrmbait - reach waypoint path 1 wp 5 - set data"),
(@ENTRY,0,6,0,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icestorm - Between 25-80 Range - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmbait - reach waypoint path 1 wp 5 - Run Script"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmbait - reach waypoint path 1 wp 5 - Run Script"),
(@ENTRY,0,8,0,4,0,100,0,0,0,0,0,91,50331648,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icestorm - Just created - turn fly on"),
(@ENTRY,0,9,0,40,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icestorm - On WP - Set Home Position"),
(@ENTRY,0,10,0,40,0,100,0,5,@ENTRY*100+00,0,0,1,0,0,0,0,0,0,19,27844,0,0,0,0,0,0,"Wyrmbait - reach waypoint path 1 wp 5 - Say"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icestorm - On Death - Say");

-- Overlord Agmar SAI
SET @ENTRY := 26379;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,12140,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Set Npc Flags"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,91,257,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Set Bytes 1"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Say Line 1"),
(@ENTRY,0,4,0,40,0,100,0,10,0,0,0,66,0,0,0,0,0,0,19,26810,0,0,0,0,0,0,"Overlord Agmar - On reached WP10 - Set Orientation"),
(@ENTRY,0,5,0,38,0,100,0,1,1,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Agmar - On Data Set - Evade"),
(@ENTRY,0,6,0,21,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Agmar - On Reached Home - Set Unit Flags");


-- Forgotten Footman SAI
SET @ENTRY := 27229;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,9000,12000,11,32587,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Shield Block"),
(@ENTRY,0,0,1,62,0,100,0,9545,0,0,0,11,48832,0,0,0,0,0,21,10,0,0,0,0,0,0,"Forgotten Footman - On gossip option select quest credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Forgotten Footman - Close Gossip"),
(@ENTRY,0,2,0,23,0,100,0,48143,0,0,0,11,48143,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forgotten Footman - Add Forgotten Aura if missing"),
(@ENTRY,0,3,0,0,0,100,0,3000,7000,9000,12000,11,32587,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forgotten Footman - Cast Shield Block");

-- Devout Bodyguard SAI
SET @ENTRY := 27247;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,10000,15000,11,38256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Piercing Howl"),
(@ENTRY,0,1,2,38,0,100,0,1,1,0,0,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devout Bodyguard - On Data Set - Set Data"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devout Bodyguard - Linked with Previous Event - Say"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devout Bodyguard - Linked with Previous Event - Set Phase 2"),
(@ENTRY,0,5,0,40,0,100,0,14,27247,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devout Bodyguard - On Reached WP 14 - Say"),
(@ENTRY,0,6,7,40,0,100,0,27,27247,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devout Bodyguard - On Reached WP 27 - Stop WP"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devout Bodyguard - Linked with Previous Event - Evade"),
(@ENTRY,0,8,0,11,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Devout Bodyguard - On Spawn - Set Home Position");

-- Thel'zan the Duskbringer SAI
SET @ENTRY := 27383;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,42719,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cast bolt"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,31256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Frost Armor on Spawn"),
(@ENTRY,0,2,0,9,0,100,0,0,35,9000,11000,11,39268,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Chains of Ice on Close"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,42719,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - On Aggro - Cast 42719"),
(@ENTRY,0,3,0,9,0,100,0,0,10,14000,15000,11,22643,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Frostbolt Volley on Close"),
(@ENTRY,0,4,0,0,0,100,0,10000,10000,25000,29000,11,50497,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Scream of Chaos"),
(@ENTRY,0,5,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel zan the Duskbringer - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,5,6,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 0-7% Mana - Allow Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel zan the Duskbringer - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,7,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel zan the Duskbringer - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,8,0,2,0,100,1,0,50,0,0,11,50497,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thel zan the Duskbringer - Between 0-50% Health - Cast  Scream of Chaos  (Phase 1) (No Repeat)"),
(@ENTRY,0,9,0,2,0,100,1,0,15,0,0,11,50497,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thel zan the Duskbringer - Between 0-15% Health - Cast  Scream of Chaos  (Phase 1) (No Repeat)"),
(@ENTRY,0,10,0,9,1,100,0,0,10,15000,20000,11,22643,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel zan the Duskbringer - Within 0-10 Range - Cast  Frostbolt Volley  (Phase 1) (No Repeat)"),
(@ENTRY,0,11,0,0,1,100,0,7000,11000,14000,18000,11,39268,0,0,0,0,0,5,0,0,0,0,0,0,0,"Thel zan the Duskbringer - In Combat - Cast  Chains of Ice  (Phase 1) (No Repeat)"),
(@ENTRY,0,12,0,9,0,100,0,0,10,15000,20000,11,22643,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 0-10 Range - Cast 22643"),
(@ENTRY,0,12,13,11,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel  zan the Duskbringer - On Spawn - Say"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,11,50497,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thel'zan the Duskbringer - Between 0-15% Health - Cast 50497"),
(@ENTRY,0,14,15,40,0,100,0,1,27383,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel  zan the Duskbringer - On Reached WP1 - Run Script"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,27713,0,0,0,0,0,0,"Thel  zan the Duskbringer - On Reached WP1 - Run Script"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,27857,0,0,0,0,0,0,"Thel  zan the Duskbringer - On Reached WP1 - Set Data"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Thel  zan the Duskbringer - On Reached WP1 - Run Script"),
(@ENTRY,0,18,0,7,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thel  zan the Duskbringer - On Evade- Set Unit Flags"),
(@ENTRY,0,19,20,6,0,100,0,0,0,0,0,15,12473,0,0,0,0,0,17,0,100,0,0,0,0,0,"Thel  zan the Duskbringer - On Death - Quest Credit"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,27857,0,0,0,0,0,0,"Thel  zan the Duskbringer - On Death - Set Data");


-- Har'koa SAI
SET @ENTRY := 29050;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,10000,8000,12000,11,53498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Swipe"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,8000,15000,11,53499,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Rake"),
(@ENTRY,0,2,0,38,0,100,0,0,1,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Har'koa - On Data Set 0 1 - Set Orientation Invoker (Phase 4)"),
(@ENTRY,0,3,0,38,0,100,0,0,2,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Har'koa - On Data Set 0 2 - Run Script (Phase 4)"),
(@ENTRY,0,4,5,7,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Har'koa - On Evade - Say Line 3"),
(@ENTRY,0,6,0,0,0,100,0,15000,16000,9000,10000,11,53499,0,0,0,0,0,2,0,0,0,0,0,0,0,"Har'koa - In Combat - Cast 'Rake'"),
(@ENTRY,0,7,0,0,0,100,0,16000,17000,10000,10000,11,53498,0,0,0,0,0,2,0,0,0,0,0,0,0,"Har'koa - In Combat - Cast 'Swipe'"),
(@ENTRY,0,8,0,0,0,100,0,10000,12000,12000,15000,86,53350,0,19,29028,30,0,1,0,0,0,0,0,0,0,"Har'koa - In Combat - Cross Cast 'Quenching Mist'"),
(@ENTRY,0,9,0,40,0,100,0,8,290500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Har'koa - On Waypoint 8 Reached - Despawn Instant");

-- Bruor Ironbane SAI
SET @ENTRY := 30152;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,56330,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Iron's Bane at 30% HP"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"On link - Remove npc flags"),
(@ENTRY,0,2,0,58,0,100,0,0,0,0,0,66,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"On summoned - Set orintation"),
(@ENTRY,0,3,0,38,0,100,0,0,1,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"On data - Run script"),
(@ENTRY,0,4,5,38,0,100,0,1,1,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On data - Despawn"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On link - Talk");

-- Father Kamaros SAI
SET @ENTRY := 31279;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,25054,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cast bolt"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,74973,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Power Word: Fortitude on Spawn"),
(@ENTRY,0,2,0,0,0,100,0,5000,6200,11700,15600,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cast Shadow Word: Pain"),
(@ENTRY,0,3,0,2,0,100,1,0,50,0,0,11,32595,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Power Word: Shield at 50% HP"),
(@ENTRY,0,4,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Within 40-100 Range - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,5,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Within 10-15 Range - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,6,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Within 0-40 Range - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,7,0,3,1,100,0,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Between 0-15% Mana - Set Event Phase 2 (No Repeat)"),
(@ENTRY,0,8,0,3,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Between 0-15% Mana - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Between 30-100% Mana - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,10,0,1,0,100,0,500,1000,600000,600000,11,74973,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Power Word: Fortitude on Spawn"),
(@ENTRY,0,11,0,0,1,100,0,5000,6200,11700,15600,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,"Father Kamaros - In Combat - Cast 'Shadow Word: Pain' (No Repeat)"),
(@ENTRY,0,12,0,2,0,100,1,0,50,0,0,11,32595,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Between 0-50% Health - Cast 'Power Word: Shield' (No Repeat)"),
(@ENTRY,0,13,14,19,0,100,0,0,0,0,0,75,58921,0,0,0,0,0,7,0,0,0,0,0,0,0,"Father Kamaros - On Quest Taken - Add Aura 'Power Word: Fortitude'"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Quest Taken - Say Line 1"),
(@ENTRY,0,18,0,40,0,100,0,12,0,0,0,1,3,2900,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Waypoint 13 Reached - Say Line 3"),
(@ENTRY,0,19,0,52,0,100,0,3,31279,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Text 3 Over - Say Line 4"),
(@ENTRY,0,20,0,52,0,100,0,4,31279,0,0,15,13229,0,0,0,0,0,18,30,0,0,0,0,0,0,"Father Kamaros - On Text 4 Over - Quest Credit 'I'm Not Dead Yet!'"),
(@ENTRY,0,21,0,52,0,100,0,4,31279,0,0,15,13221,0,0,0,0,0,18,30,0,0,0,0,0,0,"Father Kamaros - On Text 4 Over - Quest Credit 'I'm Not Dead Yet!'"),
(@ENTRY,0,22,0,52,0,100,0,4,31279,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Text 4 Over - Despawn In 1000 ms");


-- Actionlist SAI
SET @ENTRY := 488000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinky Ignatz - Script - Set NPC Flags"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinky Ignatz - Script - Set Faction"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinky Ignatz - Script - Set Bytes 1"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinky Ignatz - Script - Set aggresive"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinky Ignatz - Script - Say Line 0");

-- Actionlist SAI
SET @ENTRY := 1093600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,30000,30000,0,0,41,0,0,0,0,0,0,19,10945,100,0,0,0,0,0,"Davil - despawn - action list"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Joseph - Start Script - remove npcflag");

-- Actionlist SAI
SET @ENTRY := 1094600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,19,10944,100,0,0,0,0,0,"Lightfire -  talk 2 - action list"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,19,10948,100,0,0,0,0,0,"Defender - talk 2 - action list"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,19,10944,100,0,0,0,0,0,"Lightfire -  talk 3 - action list"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,19,10944,100,0,0,0,0,0,"Lightfire -  talk 3 - action list"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,19,10944,100,0,0,0,0,0,"Lightfire - On Script - Set React Passive"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,18,512,0,0,0,0,0,19,10944,100,0,0,0,0,0,"Lightfire - On Script - Set Immune To NPC"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,19,10944,100,0,0,0,0,0,"Lightfire - On Script - evade"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,5,65,0,0,0,0,0,19,10944,100,0,0,0,0,0,"Lightfire - play emote - action list"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,10944,100,0,0,0,0,0,"Lightfire - despawn - action list"),
(@ENTRY,9,9,0,0,0,100,0,3000,3000,0,0,47,1,0,0,0,0,0,19,10937,100,0,0,0,0,0,"Redpath - Visible On - action list"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,10937,100,0,0,0,0,0,"Redpath -  talk 1 - action list"),
(@ENTRY,9,12,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,19,10945,100,0,0,0,0,0,"Redpath -  talk 2 - action list"),
(@ENTRY,9,13,0,0,0,100,0,5000,5000,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redpath - Spawn g1 wave3 - action list"),
(@ENTRY,9,14,0,0,0,100,0,25000,25000,0,0,107,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redpath - Spawn g4 wave1 - action list"),
(@ENTRY,9,15,0,0,0,100,0,25000,25000,0,0,107,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redpath - Spawn g4 wave2 - action list"),
(@ENTRY,9,16,0,0,0,100,0,10000,10000,0,0,86,18650,2,19,10937,50,0,19,10937,50,0,0,0,0,0,"Redpath - Spawn Marduk - action list"),
(@ENTRY,9,17,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,19,10939,100,0,0,0,0,0,"Marduk - talk 1 - action list"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,19,10937,100,0,0,0,0,0,"Redpath - On Script - Set React Passive"),
(@ENTRY,9,19,0,0,0,100,0,0,0,0,0,18,512,0,0,0,0,0,19,10937,100,0,0,0,0,0,"Redpath - On Script - Set Immune To NPC"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,19,10937,100,0,0,0,0,0,"Redpath - On Script - evade"),
(@ENTRY,9,21,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,19,10937,100,0,0,0,0,0,"Redpath - set visible off - action list"),
(@ENTRY,9,22,0,0,0,100,0,1000,1000,0,0,12,10938,6,60000,0,0,0,8,0,0,0,1494.08,-3676.04,80.8468,6.26998,"Redpath - Spawn CorruptedRed - action list"),
(@ENTRY,9,23,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,10938,40,0,0,0,0,0,"CorruptedRed - talk 1 - action list"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,19,10938,40,0,0,0,0,0,"CorruptedRed - On talk 2 - action list"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,41,2,0,0,0,0,0,19,10939,40,0,0,0,0,0,"Marduk - Despawn - action list");

-- Actionlist SAI
SET @ENTRY := 1097800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 1612801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 1724600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,1,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,19,17240,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Set Data 1 1 on Admiral Odesyus"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,19,17240,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Say Line 1 on Admiral Odesyus"),
(@ENTRY,9,3,0,0,0,100,0,9000,9000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Say Line 2"),
(@ENTRY,9,5,0,0,0,100,0,9000,9000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Say Line 3"),
(@ENTRY,9,6,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,17240,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Say Line 2 on Admiral Odesyus"),
(@ENTRY,9,7,0,0,0,100,0,9000,9000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Say Line 4"),
(@ENTRY,9,8,0,0,0,100,0,4000,4000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Say Line 6"),
(@ENTRY,9,9,0,0,0,100,0,1000,1000,0,0,11,30221,0,0,0,0,0,19,620,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Cast Shoot (Target Closest chicken)"),
(@ENTRY,9,10,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,19,17240,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Say Line 3 on Admiral Odesyus"),
(@ENTRY,9,11,0,0,0,100,0,5000,5000,0,0,45,2,2,0,0,0,0,19,17240,0,0,0,0,0,0,"Cookie McWeaksauce - Script - Set Data 2 2 on Admiral Odesyus");

-- Actionlist SAI
SET @ENTRY := 1783101;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Watcher Leesa'oh - Script 2 - Set Npc Flags"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,0,7000,0,0,0,0,12,1,0,0,0,0,0,0,"Watcher Leesa'oh - Script 2 - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,7000,7000,0,0,45,1,1,0,0,0,0,19,17953,0,0,0,0,0,0,"Watcher Leesa'oh - Script 2 - Set Data 1 1 on Buddy");

-- Actionlist SAI
SET @ENTRY := 1852801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 1852802;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

--  SAI
SET @ENTRY := 479010;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

--  SAI
SET @ENTRY := 56057;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Jenny SAI
SET @ENTRY := 25969;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,46340,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jenny - On Just Summoned - Cast Crates Carried"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jenny - On Just Summoned - Set Passive"),
(@ENTRY,0,2,0,32,0,100,0,50,20000,3000,5000,11,46342,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jenny - On Damage - Cast Drop Crate"),
(@ENTRY,0,3,0,23,0,100,0,46340,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jenny - On Has No Aura (Crates Carried) - Despawn");

--  SAI
SET @ENTRY := 44315;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;

--  SAI
SET @ENTRY := 191578;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;

-- Actionlist SAI
SET @ENTRY := 2225800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,38672,0,0,0,0,0,1,0,0,0,0,0,0,0,"Demoniac Scryer - Script - Cast Magic Sucker Device timer"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,38690,0,0,0,0,0,1,0,0,0,0,0,0,0,"Demoniac Scryer - Script - Cast Magic Sucker Device Bunny Appearance"),
(@ENTRY,9,29,0,0,0,100,0,0,0,0,0,28,38672,0,0,0,0,0,1,0,0,0,0,0,0,0,"Demoniac Scryer - Script - Remove Aura Magic Sucker Device timer"),
(@ENTRY,9,30,0,0,0,100,0,84000,84000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Demoniac Scryer - Script - Remove Aura Magic Sucker Device timer");

-- Actionlist SAI
SET @ENTRY := 2598300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dorain Frosthoof - Script - Set Phase 2"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dorain Frosthoof - Script - Set Phase 1");

-- Actionlist SAI
SET @ENTRY := 2620902;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,1,1,0,100,0,1000,1000,24000,25000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"q26209 - say text");

-- Actionlist SAI
SET @ENTRY := 2620903;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,1,1,0,100,0,1000,1000,24000,25000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"q26209 - say text");

-- Actionlist SAI
SET @ENTRY := 2620904;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,1,1,0,100,0,1000,1000,24000,25000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"q26209 - say text");

-- Actionlist SAI
SET @ENTRY := 2620905;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,1,1,0,100,0,1000,1000,24000,25000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"q26209 - say text #4");

-- Waters of Farseeing SAI
SET @ENTRY := 207414;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,1,0,61,0,100,0,0,0,0,0,28,94687,0,0,0,0,0,7,0,0,0,0,0,0,0,"Waters of Farseeing - On link - Remove Waters of Farseeing");

-- Waters of Farseeing SAI
SET @ENTRY := 207416;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,1,0,61,0,100,0,0,0,0,0,28,94687,0,0,0,0,0,7,0,0,0,0,0,0,0,"Waters of Farseeing - On link - Remove Waters of Farseeing");

-- Broken Tablet SAI
SET @ENTRY := 186718;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;

-- Iron Rune Construct SAI
SET @ENTRY := 24806;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Construct - Just Summoned - Set phase 1"),
(@ENTRY,0,2,3,8,1,100,0,44498,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Construct - spell hit - Say text"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Construct - spell hit - Set phase 2"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Construct - spell hit - Set fly"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,65653,186956,0,0,0,0,0,"Iron Rune Construct - spell hit - Activate Gobject"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,80,2471700,0,0,0,0,0,19,24717,30,0,0,0,0,0,"Iron Rune Construct - spell hit - ActionList"),
(@ENTRY,0,8,9,40,0,100,0,5,24806,0,0,11,44499,0,0,0,0,0,23,0,0,0,0,0,0,0,"Iron Rune Construct - Waypoint reached - cast credit spell"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Construct - Waypoint reached - Set phase 3"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,65654,186957,0,0,0,0,0,"Iron Rune Construct - Just Summoned - Activate gob"),
(@ENTRY,0,11,0,1,4,100,1,7000,7000,0,0,28,46598,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Construct - OOC (phase 3) - Remove Vehicle aura");

-- Steam Rager SAI
SET @ENTRY := 24601;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,11000,14000,11,50375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Steam Blast"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,11000,14000,11,50375,1,0,0,0,0,2,0,0,0,0,0,0,0,"Steam Rager - In Combat - Cast 'Steam Blast'");

-- Injured 7th Legion Soldier SAI
SET @ENTRY := 27788;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,4,7,0,100,0,0,0,0,0,11,49774,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On Evade  - cast Cower + Fear Visual"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,64,2,0,0,0,0,0,12,1,0,0,0,0,0,0,"Injured 7th Legion Soldier - On 7th Legion cannon within 3 yards  - Disable Combat movement"),
(@ENTRY,0,5,0,6,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On Death  - Reset all scripts"),
(@ENTRY,0,8,9,61,0,100,0,0,0,0,0,33,27788,0,0,0,0,0,12,1,0,0,0,0,0,0,"Injured 7th Legion Soldier - On 7th Legion Cannon within 5 yards  - Give kill credit to stored target"),
(@ENTRY,0,9,13,61,0,100,0,0,0,0,0,28,49774,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On 7th Legion Cannon within 5 yards  - Remove aura Cower + Fear Visual"),
(@ENTRY,0,10,0,1,0,100,0,500,500,7500,7500,29,0,0,0,0,0,0,12,2,0,0,0,0,0,0,"Injured 7th Legion Soldier - OOC - Follow stored target 2"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,28,49775,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier -  On 7th Legion Cannon within 15 yards  - Remove aura Cower + Fear Visual"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier -  On 7th Legion Cannon within 15 yards  - Set Unit Flags"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On 7th Legion Cannon within 15 yards  - Set Run"),
(@ENTRY,0,16,0,7,0,100,0,0,0,0,0,29,0,0,0,0,0,0,12,2,0,0,0,0,0,0,"Injured 7th Legion Soldier - On Evade Follow stored targetlist 2");

-- Seasoned Magister SAI
SET @ENTRY := 22863;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cast bolt"),
(@ENTRY,0,2,0,0,0,100,0,1000,1000,4000,4000,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Akama - IC - Cast Spell");

-- Stinker SAI
SET @ENTRY := 23274;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,8,9,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - Linked with Previous Event - Cast Stinker In Love - Set Phase 1"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,11,62002,2,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - Linked with Previous Event - Cast Stinker In Love"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,11,62001,2,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - Linked with Previous Event - Cast Stinker Passive"),
(@ENTRY,0,11,12,1,1,100,0,0,0,2000,5000,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - OOC (Phase 1) - Set Run"),
(@ENTRY,0,12,13,61,1,100,0,0,0,0,0,11,62002,2,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - Linked with Previous Event (Phase 1) - Cast Stinker In Love"),
(@ENTRY,0,13,0,61,1,100,0,0,0,0,0,29,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Stinker - Linked with Previous Event (Phase 1) - Follow Stored Target"),
(@ENTRY,0,14,0,1,1,100,0,30000,45000,30000,45000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - OOC (Phase 1) - Set Phase 2"),
(@ENTRY,0,15,16,23,1,100,0,62002,0,0,0,11,62004,2,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - On Has No Aura (Stinker in love) (Phase 1) - Cast Stinker Heartbroken"),
(@ENTRY,0,16,17,61,1,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - Linked with Previous Event (Phase 1) - Set Phase 0"),
(@ENTRY,0,17,21,61,0,100,0,0,0,0,0,28,62001,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - Linked with Previous Event  - Remove aura stinker passive"),
(@ENTRY,0,18,19,23,2,100,0,62002,0,0,0,11,62004,2,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - On Has No Aura (Stinker in love) (Phase 2) - Cast Stinker Heartbroken"),
(@ENTRY,0,19,20,61,2,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - Linked with Previous Event (Phase 2) - Set Phase 0"),
(@ENTRY,0,20,21,61,0,100,0,0,0,0,0,28,62001,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stinker - Linked with Previous Event  - Remove aura stinker passive"),
(@ENTRY,0,21,22,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Stinker - Linked with Previous Event  - Follow"),
(@ENTRY,0,22,0,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Stinker - Linked with Previous Event  - Follow");

-- Ysiel Windsinger SAI
SET @ENTRY := 17841;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Ravandwyr SAI
SET @ENTRY := 19217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,87,@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,0,0,0,1,0,0,0,0,0,0,0,"Ravandwyr - On Data Set - Run Script"),
(@ENTRY,0,1,2,1,0,100,0,420000,600000,420000,600000,45,1,1,0,0,0,0,10,74522,19610,0,0,0,0,0,"Ravandwyr - OOC - Set Data"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,74523,19610,0,0,0,0,0,"Ravandwyr - OOC - Set Data"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,74524,19610,0,0,0,0,0,"Ravandwyr - OOC - Set Data"),
(@ENTRY,0,4,5,38,0,100,0,2,2,0,0,45,1,1,0,0,0,0,10,74522,19610,0,0,0,0,0,"Ravandwyr - On Data Set - Set Data"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,74523,19610,0,0,0,0,0,"Ravandwyr - On Data Set - Set Data"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,74524,19610,0,0,0,0,0,"Ravandwyr - On Data Set - Set Data"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ravandwyr - On Gossip Option 0 Selected - Close Gossip");

-- Runetog Wildhammer SAI
SET @ENTRY := 20234;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,12,9526,4,30000,0,0,0,1,0,0,0,0,0,0,0,"Runetog Wildhammer - On Aggro - Summon Creature 'Enraged Gryphon'"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,12,9526,4,30000,0,0,0,1,0,0,0,0,0,0,0,"Runetog Wildhammer - On Aggro - Summon Creature 'Enraged Gryphon'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runetog Wildhammer - On Aggro - Say Line 0");

-- Scalewing Serpent SAI
SET @ENTRY := 20749;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,8000,9000,11,37841,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Lightning Strike on Close");

-- Nexus-Prince Razaan SAI
SET @ENTRY := 21057;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,18000,20000,11,35924,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Energy Flux on Close"),
(@ENTRY,0,0,1,38,0,100,0,1,1,45000,45000,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-Prince Razaan - On Data Set 1 1 - Set Data 10"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,19,756,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-Prince Razaan - Linked with Previous Event - Remove unit flags"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-Prince Razaan - Linked with Previous Event - Set Visible"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-Prince Razaan - Linked with Previous Event - Say"),
(@ENTRY,0,4,5,25,0,100,0,0,0,0,0,18,756,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-Prince Razaan - On spawn - Add unit flags"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-Prince Razaan - Linked with Previous Event - Set Invisible"),
(@ENTRY,0,6,7,21,0,100,0,0,0,0,0,18,756,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-Prince Razaan - On Creature reached home - Add unit flags"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-Prince Razaan - Linked with Previous Event - Set Invisible"),
(@ENTRY,0,8,0,9,0,100,0,0,8,8000,11000,11,35924,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-Prince Razaan - On Range - Cast Energy Flux");

-- Borak, Son of Oronok SAI
SET @ENTRY := 21293;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,17,50,100,0,0,0,0,0,"Borak, Son of Oronok - On Data Set 1 1 - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,38,0,100,0,2,2,0,0,1,1,0,0,0,0,0,17,50,100,0,0,0,0,0,"Borak, Son of Oronok - On Data Set 2 2 - Say Line 1 (No Repeat)"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Borak, Son of Oronok - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,17,50,100,0,0,0,0,0,"Borak, Son of Oronok - On Gossip Option 0 Selected - Say Line 2");

-- Cursed Scarab SAI
SET @ENTRY := 21306;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,18000,20000,11,3256,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Plague Cloud"),
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,89,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Scarab - On Spawn - Set Random Movement"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Scarab - On Spawn - Set Run On"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,36556,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Scarab - On Spawn - Cast Cursed Scarab Periodic"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,36559,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Scarab - On Spawn - Cast Cursed Scarab Despawn Timer"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,11,31309,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Scarab - On Spawn - Cast Spirit Particles (red, big)"),
(@ENTRY,0,6,7,1,0,100,1,5000,90000,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Scarab - OOC - Set faction"),
(@ENTRY,0,7,8,61,0,100,1,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Scarab - OOC - Set Hostile"),
(@ENTRY,0,8,0,61,0,100,1,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Cursed Scarab - OOC - Attack Sumoner");

-- Vision of the Raven God SAI
SET @ENTRY := 21861;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Vision of Raven God - Link - Say 0"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,21,20,0,0,0,0,0,0,"Vision of Raven God - Link - Say 1"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,21,20,0,0,0,0,0,0,"Vision of Raven God - Link - Say 2"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,21,20,0,0,0,0,0,0,"Vision of Raven God - Link - Say 3");

-- Magic Sucker Device Buttress SAI
SET @ENTRY := 22267;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,38719,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magic Sucker Device Buttress - On Just Summoned - Cast Magic Sucker Device Buttress Appearance"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,22258,0,0,0,0,0,0,"Magic Sucker Device Buttress - On Just Summoned - Set Orientation"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,38721,0,0,0,0,0,19,22258,0,0,0,0,0,0,"Magic Sucker Device Buttress - On Just Summoned - Cast Magic Sucker Device Channel(dnd)"),
(@ENTRY,0,4,0,8,0,100,0,38691,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magic Sucker Device Buttress - On Spellhit (Magic Sucker Device Despawner, Mob AE) - Despawn"),
(@ENTRY,0,5,3,1,0,100,0,0,0,3000,3000,11,38719,2,0,0,0,0,1,0,0,0,0,0,0,0,"Magic Sucker Device Buttress - IC - Cast Magic Sucker Device Buttress Appearance"),
(@ENTRY,0,6,3,0,0,100,0,0,0,3000,3000,11,38919,2,0,0,0,0,1,0,0,0,0,0,0,0,"Magic Sucker Device Buttress - OOC - Cast Magic Sucker Device Buttress Appearance");


-- Lilian Voss SAI
SET @ENTRY := 39038;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,2000,9000,87,@ENTRY*100+00,@ENTRY*100+01,0,0,0,0,1,0,0,0,0,0,0,0,"on aggro do random action"),
(@ENTRY,0,1,0,1,0,100,1,2000,2000,2000,2000,11,73392,0,0,0,0,0,1,0,0,0,0,0,0,0,"update ooc cast stealth"),
(@ENTRY,0,2,0,0,0,100,0,0,0,5000,5000,11,73309,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow - IC - CastSpell"),
(@ENTRY,0,2,5,38,0,100,0,0,1,0,0,80,@ENTRY*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"data set 1 do actiontime"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"follow owner"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,18,776,0,0,0,0,0,1,0,0,0,0,0,0,0,"set unit flag");

-- Actionlist SAI
SET @ENTRY := 1965600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 1965601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Veneratus Spawn Node SAI
SET @ENTRY := 21334;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,2000,2000,45,3,3,0,0,0,0,19,21332,40,0,0,0,0,0,"Veneratus Spawn Node - OOC - Set Data to Spirit Hunter");

-- Tally Zapnabber SAI
SET @ENTRY := 21460;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tally Zapnabber - On Gossip Option 0 Selected - Close Gossip");

-- Overlord Or'barokh SAI
SET @ENTRY := 21769;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,120000,120000,300000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Or'barokh - Out of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,123000,123000,303000,303000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Or'barokh - Out of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,0,125500,125500,305500,305500,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Or'barokh - Out of Combat - Say Line 2"),
(@ENTRY,0,3,4,62,0,100,0,8443,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Overlord Or'barokh - On Gossip Option 0 Selected - Close Gossip");

-- Thane Yoregar SAI
SET @ENTRY := 21773;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,120000,120000,200000,260000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thane Yoregar - Out of Combat - Say Line 0"),
(@ENTRY,0,1,2,62,0,100,0,8457,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Thane Yoregar - On Gossip Option 0 Selected - Close Gossip");

-- Morbidus SAI
SET @ENTRY := 30698;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,16700,18500,11,72728,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Corrode Flesh"),
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morbidus - On Data Set 1 1 - Set Unit Flags"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,25000,28900,11,31277,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Stomp"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morbidus - On Data Set 1 1 - Set Hostile"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,31306,0,0,0,0,0,0,"Morbidus - On Data Set 1 1 - Set Data 1 1 on Margrave Dhakar"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,31428,0,0,0,0,0,0,"Morbidus - On Data Set 1 1 - Set Data 1 1 on Crusader Olakin Sainrith"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,31314,0,200,0,0,0,0,"Morbidus - On Data Set 1 1 - Set Data 1 1 on Ebon Blade Veteran"),
(@ENTRY,0,5,6,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morbidus - On Reset - Set Passive"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morbidus - On Reset - Set Unit Flags");

-- Illidan Stormrage SAI
SET @ENTRY := 32588;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidan - On Just Summoned - Talk - Self"),
(@ENTRY,0,1,0,0,0,100,0,15000,16000,15000,16000,11,60744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidan - In combat - Immolate"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,6000,7000,11,61101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidan - In combat - Heart Rip"),
(@ENTRY,0,4,0,0,0,100,0,19000,19000,19000,19000,11,60742,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidan - In combat - Shear");

-- Thug SAI
SET @ENTRY := 42387;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Harrison Jones SAI
SET @ENTRY := 44860;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,11929,1,0,0,53,0,26814,0,0,9000,0,0,0,0,0,0,0,0,0,"Harrison Jones - On Gossip Option 1 Selected - Start Waypoint"),
(@ENTRY,0,1,0,19,0,100,0,27141,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harrison Jones - On PE Quest Accept Start Script"),
(@ENTRY,0,1,2,61,0,100,0,11929,1,0,0,72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Harrison Jones - On Gossip Option 1 Selected - Close Gossip"),
(@ENTRY,0,3,4,58,0,100,0,4,0,0,0,33,42793,0,0,0,0,0,7,0,0,0,0,0,0,0,"Harrison Jones - On Waypoint Finished - Quest Credit 'On to Something'"),
(@ENTRY,0,4,0,61,0,100,0,4,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harrison Jones - On Waypoint Finished - Despawn In 5000 ms");

-- Broken Tablet SAI
SET @ENTRY := 45188;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Skylord Omnuron SAI
SET @ENTRY := 52490;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Goldwing Hawk SAI
SET @ENTRY := 52594;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"molten front quests fix");

-- Alpine Songbird SAI
SET @ENTRY := 52595;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"molten front quests fix");

-- Forest Owl SAI
SET @ENTRY := 52596;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"molten front quests fix");

-- Wounded Hyjal Defender SAI
SET @ENTRY := 52834;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,8,0,100,0,97670,0,0,0,41,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"molten front quests fix");


-- Deldren Ravenelm SAI
SET @ENTRY := 52921;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Hyjal Wisp SAI
SET @ENTRY := 53083;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,530830,0,29143,2000,0,1,0,0,0,0,0,0,0,"molten front quests fix"),
(@ENTRY,0,1,0,40,0,100,0,4,530830,0,0,70,2,0,0,0,0,0,20,208899,20,0,0,0,0,0,"molten front quests fix");

-- Northwestern Pool Credit SAI
SET @ENTRY := 53190;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Northeastern Pool Credit SAI
SET @ENTRY := 53191;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Central Pool Credit SAI
SET @ENTRY := 53192;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Windcaller Voramus SAI
SET @ENTRY := 53217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,53,1,533550,0,29206,2000,1,1,0,0,0,0,0,0,0,"molten front quests fix"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,72,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"molten front quests fix"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"molten front quests fix");

-- Injured Druid of the Talon SAI
SET @ENTRY := 53243;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"molten front quests fix");

-- Windcaller Nordrala SAI
SET @ENTRY := 53355;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,53,1,533550,0,29206,2000,1,1,0,0,0,0,0,0,0,"molten front quests fix"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,72,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"molten front quests fix"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"molten front quests fix");

-- Actionlist SAI
SET @ENTRY := 2021800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2021804;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2043900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2021802;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2021805;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2021801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2021803;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2043901;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2131600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Set fly off"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,28,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Remove aura"),
(@ENTRY,9,3,0,0,0,100,0,13000,13000,0,0,86,33346,0,19,20683,15,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Cross cast"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,86,36656,0,19,20683,15,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Cross cast"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,11,36658,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Cast Transform"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Set fly On");


-- Actionlist SAI
SET @ENTRY := 2131601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Set fly off"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,28,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Remove aura"),
(@ENTRY,9,3,0,0,0,100,0,12000,12000,0,0,86,33346,0,19,20683,15,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Cross cast"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,86,36656,0,19,20683,15,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Cross cast"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,11,36658,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Cast Transform"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathforged Infernal - Action list - Set fly On");

-- Actionlist SAI
SET @ENTRY := 2141100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Set NPC Flags"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,71,0,0,20468,0,0,0,1,0,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Equip Item"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,5,92,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Play Emote OneShotEatNoSheathe"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Set Orientation"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - UnEquip Item"),
(@ENTRY,9,6,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Say Line 1"),
(@ENTRY,9,8,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Say Line 2"),
(@ENTRY,9,9,0,0,0,100,0,3000,3000,0,0,11,36823,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Cast Overwhelming Odor"),
(@ENTRY,9,10,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.54479,"Tobias the Filth Gorger - Script - Set Orientation"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,11,36824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Cast Overwhelming Odor"),
(@ENTRY,9,12,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Say Line 2"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tobias the Filth Gorger - Script - Set NPC Flags");

-- Actionlist SAI
SET @ENTRY := 2404402;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2404400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2389900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tethyr - Action list - REGEN HEALTH OFF"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,18,128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tethyr - Action list - Add unit flag");

-- Actionlist SAI
SET @ENTRY := 2404401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2404403;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2448400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,1,0,0,0,100,0,1000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Script - Say Line 0 (random)"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,11,50696,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Script - Cast Throw Mug");

-- Actionlist SAI
SET @ENTRY := 2448401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,1,0,0,0,100,0,1000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Script - Say Line 0 (random)"),
(@ENTRY,9,2,0,0,0,100,0,1000,3000,3000,3000,11,50696,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Script - Cast Throw Mug");

-- Actionlist SAI
SET @ENTRY := 2474200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Jonah Sterling - Script - Set HP Regen off"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Jonah Sterling - Script - Evade"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Jonah Sterling - Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Jonah Sterling - Script - Say Line 2"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,85,44458,1,0,0,0,0,19,24547,0,0,0,0,0,0,"Mad Jonah Sterling - Script - Invoker Cast Hozzer Feeds"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,24547,0,0,0,0,0,0,"Mad Jonah Sterling - Script - Say Line 1 - Hozzer"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Jonah Sterling - Script - Despawn");

-- Actionlist SAI
SET @ENTRY := 2485200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Construct script - Say line"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,44687,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Rune Construct script - Spellcast Rocket Jump");

-- Actionlist SAI
SET @ENTRY := 2533500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Longrunner Proudhoof - Script - Set NPC Flags"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,25336,0,0,0,0,0,0,"Longrunner Proudhoof - Script - Set Data to Grunt Ragefist"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,25338,0,200,0,0,0,0,"Longrunner Proudhoof - Script - Set Data to Warsong Caravan Guard"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Longrunner Proudhoof - Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,2,232,0,0,0,0,0,1,0,0,0,0,0,0,0,"Longrunner Proudhoof - Script - Set Faction"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Longrunner Proudhoof - Script - Set Hostile"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Longrunner Proudhoof - Script - Switch HP Regen off"),
(@ENTRY,9,7,0,0,0,100,0,11000,11000,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Longrunner Proudhoof - Script - Say Line 0"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,19,25336,0,0,0,0,0,0,"Longrunner Proudhoof - Script - Set Data to Grunt Ragefist"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,25338,0,200,0,0,0,0,"Longrunner Proudhoof - Script - Set Data to Warsong Caravan Guard");

-- Actionlist SAI
SET @ENTRY := 2967700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frosthound - Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,55026,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frosthound - Script - Cast Frosthound Boss Emote"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frosthound - Script - Say Line 1");


-- Actionlist SAI
SET @ENTRY := 2990300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Bite - Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,55476,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Bite - Script - Cast Frostbite Boss Emote");

-- Actionlist SAI
SET @ENTRY := 2628700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmbait - reach waypoint path 2 wp 1 - turn fly off");

-- Actionlist SAI
SET @ENTRY := 2662600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Say Line 0");

-- Actionlist SAI
SET @ENTRY := 3013400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,19,30107,10,0,0,0,0,0,"Brann - On Script - Set React Passive"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Machine - On Script - Set React Passive"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,18,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Machine - On Script - set PACIFIED");

-- Actionlist SAI
SET @ENTRY := 3033100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,56649,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - Cast spell to summon"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - Root"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - Talk2"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - Emote"),
(@ENTRY,9,4,0,0,0,100,0,24000,24000,0,0,1,0,0,0,0,0,0,19,30390,30,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,6,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,19,30390,30,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,7,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,19,30390,30,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,8,0,0,0,100,0,9000,9000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,28,68442,0,0,0,0,0,19,30390,30,0,0,0,0,0,"Jokkum - ActionList - remove kneel"),
(@ENTRY,9,10,0,0,0,100,0,8000,8000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,11,0,0,0,100,0,9000,9000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,12,0,0,0,100,0,2000,2000,0,0,80,3039001,0,0,0,0,0,19,30390,30,0,0,0,0,0,"Jokkum - ActionList - Actionlist"),
(@ENTRY,9,13,0,0,0,100,0,4000,4000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,14,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,19,30390,30,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,15,0,0,0,100,0,9000,9000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,16,0,0,0,100,0,5000,5000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - talk"),
(@ENTRY,9,17,0,0,0,100,0,0,0,0,0,11,56545,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jokkum - ActionList - Cast credit"),
(@ENTRY,9,18,0,0,0,100,0,4000,4000,0,0,11,50630,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - Cast eject passenger"),
(@ENTRY,9,19,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jokkum - ActionList - remove root");

-- Actionlist SAI
SET @ENTRY := 3523100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 3590500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 3039900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Set NPC Flags"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,12,30396,1,180000,0,0,0,8,0,0,0,8564.41,-580.366,925.641,5.5676,"Thorim - Script - Spawn Loken"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Thorim - Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,15000,15000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 3"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,5,333,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Play Emote 333"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,19,30396,30,0,0,0,0,0,"Thorim - Script - Set Data 1 1 to Loken"),
(@ENTRY,9,7,0,0,0,100,0,6000,6000,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Set Run On"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,46,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Cast Move to Loken"),
(@ENTRY,9,9,0,0,0,100,0,6000,6000,0,0,11,56688,0,0,0,0,0,19,30396,30,0,0,0,0,0,"Thorim - Script - Cast Thorim's Knockback"),
(@ENTRY,9,10,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 4"),
(@ENTRY,9,11,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 5"),
(@ENTRY,9,12,0,0,0,100,0,2000,2000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thorim - Script - Say Line 6"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,11,56694,0,0,0,0,0,19,30396,30,0,0,0,0,0,"Thorim - Script - Cast Lightning Fury"),
(@ENTRY,9,14,0,0,0,100,0,3000,3000,0,0,11,56695,0,0,0,0,0,19,30396,30,0,0,0,0,0,"Thorim - Script - Cast Thorim's Hammer");

-- Actionlist SAI
SET @ENTRY := 3712000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,7000,7000,0,0,11,70471,0,0,0,0,0,19,37702,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Cast Mograine Forge Beam"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,17000,17000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Say Line 2"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,19,37702,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Set Data on Runeforge Bunny"),
(@ENTRY,9,6,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Say Line 3"),
(@ENTRY,9,7,0,0,0,100,0,12000,12000,0,0,11,71310,0,0,0,0,0,19,38191,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Cast Pull Shadows Edge"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,81,3,0,0,0,0,0,19,38191,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Set NPC Flags"),
(@ENTRY,9,9,0,0,0,100,0,150,150,0,0,11,43671,0,0,0,0,0,19,38191,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Cast Ride Vehicle"),
(@ENTRY,9,10,0,0,0,100,0,1000,1000,0,0,11,71385,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Cast Mograine Axe Timer Aura"),
(@ENTRY,9,11,0,0,0,100,0,0,1000,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highlord Darion Mograine - Script - Cast Mograine Axe Timer Aura");

-- Actionlist SAI
SET @ENTRY := 3780100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,7000,7000,0,0,11,70509,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadows Edge Bunny - Script - Cast Blue Explosion"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,11,70509,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadows Edge Bunny - Script - Cast Blue Explosion"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,11,70509,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadows Edge Bunny - Script - Cast Blue Explosion"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,11,70509,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadows Edge Bunny - Script - Cast Blue Explosion"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,11,70509,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadows Edge Bunny - Script - Cast Blue Explosion"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,11,70509,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadows Edge Bunny - Script - Cast Blue Explosion"),
(@ENTRY,9,6,0,0,0,100,0,1000,1000,0,0,11,70504,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadows Edge Bunny - Script - Cast Shadows Edge Aura"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,12,38191,1,24000,0,0,0,1,0,0,0,0,0,0,0,"Shadows Edge Bunny - Script - Summon Shadows Edge"),
(@ENTRY,9,9,0,0,0,100,0,13000,13000,0,0,11,70529,0,0,0,0,0,19,38191,0,0,0,0,0,0,"Shadows Edge Bunny - Script - Cast Shadows Edge Axe"),
(@ENTRY,9,10,0,0,0,100,0,8000,8000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadows Edge Bunny - Script - Despawn");

-- Actionlist SAI
SET @ENTRY := 3795200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,70785,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script - Cast Holy Bomb Visual"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,70789,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script - Cast Zap Ghouls Aura");

-- Actionlist SAI
SET @ENTRY := 3891001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Emote State 26"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,2000,2000,33,38910,0,0,0,0,0,17,0,30,0,0,0,0,0,"Lilian Voss - On Script - Quest Credit 'The Truth of the Grave'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Event Phase 1");

-- Actionlist SAI
SET @ENTRY := 2665400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Roanauk Icemist - Script - Say Line 1"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,28,47273,0,0,0,0,0,1,0,0,0,0,0,0,0,"Roanauk Icemist - Script - Remove Aura Icemist's Prison"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,26656,0,200,0,0,0,0,"Roanauk Icemist - Script - Set Data 2 2 on Anub'ar Prison"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Roanauk Icemist - Script - Set Phase 2");

-- Actionlist SAI
SET @ENTRY := 2732800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,48368,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 0 - Spellcast Bearform"),
(@ENTRY,9,1,0,0,0,100,0,300,300,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 0 - Set faction"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 0 - Remove unit_field_bytes1 (kneel)"),
(@ENTRY,9,3,0,0,0,100,0,2500,2500,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tur Ragepaw script 0 - Say line"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 0 - Set event phase 1"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 0 - Set reaction aggressive");

-- Actionlist SAI
SET @ENTRY := 2784300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Wyrmbait - script - close gossip"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,18,33280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmbait - script - set unit flags"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmbait - script - remove npc flag"),
(@ENTRY,9,3,0,0,0,100,0,500,500,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmbait - script - emote"),
(@ENTRY,9,4,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmbait - script - say 0"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmbait - script - turn fly on"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,27839,100,0,0,0,0,0,"Wyrmbait - script - set data on 7th Legion Harpoon Gun");


-- Actionlist SAI
SET @ENTRY := 2785700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Legion Commander Yorik - Script - Say"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,45,5,5,0,0,0,0,10,133697,27851,0,0,0,0,0,"Legion Commander Yorik - Script - Set Data"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,133700,27851,0,0,0,0,0,"Legion Commander Yorik - Script - Set Data"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,133701,27851,0,0,0,0,0,"Legion Commander Yorik - Script - Set Data"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,133702,27851,0,0,0,0,0,"Legion Commander Yorik - Script - Set Data"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,133694,27851,0,0,0,0,0,"Legion Commander Yorik - Script - Set Data"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,133698,27851,0,0,0,0,0,"Legion Commander Yorik - Script - Set Data"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,133699,27851,0,0,0,0,0,"Legion Commander Yorik - Script - Set Data"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Legion Commander Yorik - Script - Say"),
(@ENTRY,9,10,0,0,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Commander Yorik - Script - Set Home Position"),
(@ENTRY,9,11,0,0,0,100,0,5000,5000,0,0,45,3,3,0,0,0,0,10,133695,27851,0,0,0,0,0,"Legion Commander Yorik - Script - Set Data");

-- Actionlist SAI
SET @ENTRY := 2732802;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,48371,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 2 - Spellcast Tree of Life"),
(@ENTRY,9,1,0,0,0,100,0,100,100,0,0,11,52553,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 2 - Spellcast Empowered Tree of Life"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 2 - Set faction"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 2 - Remove unit_field_bytes1 (kneel)"),
(@ENTRY,9,4,0,0,0,100,0,2600,2600,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tur Ragepaw script 2 - Say line"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 2 - Set event phase 3");

-- Actionlist SAI
SET @ENTRY := 2732801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,48369,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 1 - Spellcast Moonkin Form"),
(@ENTRY,9,1,0,0,0,100,0,300,300,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 1 - Set faction"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 1 - Remove unit_field_bytes1 (kneel)"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,11,24905,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 1 - Spellcast Moonkin Form (Passive)"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,11,24907,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 1 - Spellcast Moonkin Aura"),
(@ENTRY,9,5,0,0,0,100,0,400,400,0,0,11,52503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 1 - Spellcast Empowered Moonkin Aura"),
(@ENTRY,9,6,0,0,0,100,0,2500,2500,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tur Ragepaw script 1 - Say line"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 1 - Set reaction aggressive"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tur Ragepaw script 1 - Set event phase 2");

-- Actionlist SAI
SET @ENTRY := 2745500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Arthas - On Script - Set Data 0 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,4820.17,-581.226,163.616,0,"Prince Arthas - On Script - Move To Position"),
(@ENTRY,9,2,0,0,0,100,0,8000,8000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Arthas - On Script - Say Line 6"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Arthas - On Script - Say Line 7"),
(@ENTRY,9,4,0,0,0,100,0,6000,6000,0,0,11,49824,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Arthas - On Script - Cast 'Arthas Calls to Spirits'"),
(@ENTRY,9,5,0,0,0,100,0,10000,10000,0,0,69,0,0,0,0,0,0,8,0,0,0,4819.66,-582.522,163.752,0,"Prince Arthas - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,71,0,7,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Arthas - On Script - Change Equipment"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,5,397,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Arthas - On Script - Play Emote 397"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,71,0,7,33350,0,0,0,1,0,0,0,0,0,0,0,"Prince Arthas - On Script - Change Equipment"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,20,190332,5,0,0,0,0,0,"Prince Arthas - On Script - Activate Gameobject"),
(@ENTRY,9,10,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,4814.56,-577.26,162.252,0,"Prince Arthas - On Script - Move To Position"),
(@ENTRY,9,11,0,0,0,100,0,3500,3500,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Arthas - On Script - Play Emote 15");

-- Actionlist SAI
SET @ENTRY := 2748001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muradin - On Script - Set Sheath Unarmed"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,18,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"Muradin - On Script - Set Flag Server Controlled"),
(@ENTRY,9,2,0,0,0,100,0,13000,13000,0,0,19,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"Muradin - On Script - Remove Flag Server Controlled"),
(@ENTRY,9,3,0,0,0,100,0,500,500,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muradin - On Script - Set Emote State 64"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muradin - On Script - Say Line 4"),
(@ENTRY,9,5,0,0,0,100,0,3000,3000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muradin - On Script - Say Line 5"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muradin - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,11,49829,3,0,0,0,0,1,0,0,0,0,0,0,0,"Muradin - On Script - Cast 'Frostmourne Cavern Quest Credit'");

-- Actionlist SAI
SET @ENTRY := 2819200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Machine - Action List - Set Fly ON"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,85,46598,0,0,0,0,0,1,0,0,0,0,0,0,0,"Machine - Action List - CrossCast"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,5832.7,436.761,669.141,0.612513,"Machine - Action List - InvokerCast"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,11,50987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Machine - Action List - cast teleportation");

-- Actionlist SAI
SET @ENTRY := 2849801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,4000,4000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script 2 - Say"),
(@ENTRY,9,1,0,0,0,100,0,10000,10000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script 2 - Say"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,11,54236,0,0,0,0,0,19,28998,0,0,0,0,0,0,"The Lich King - Script 2 - Cast Touch of Death"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,28998,0,0,0,0,0,0,"The Lich King - Script 2 - Set Orientation"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"The Lich King - Script 2 - Set Orientation"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script 2 - Say"),
(@ENTRY,9,6,0,0,0,100,0,5000,5000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script 2 - Say"),
(@ENTRY,9,7,0,0,0,100,0,12000,12000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script 2 - Say"),
(@ENTRY,9,8,0,0,0,100,0,5000,5000,0,0,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script 2 - Say");

-- Actionlist SAI
SET @ENTRY := 2866900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;

-- Actionlist SAI
SET @ENTRY := 2795101;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Barean Westwind - Script 2 - Set Unit Flags Immune to NPC/PC"),
(@ENTRY,9,1,0,0,0,100,0,100,100,0,0,11,50161,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Barean Westwind - Script 2 - Cast Protection Spear"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Admiral Barean Westwind - Script 2 - Face Player"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Barean Westwind - Script 2 - Say Line 2"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,19,27210,0,0,0,0,0,0,"Admiral Barean Westwind - Script 2 - Face High General Abbendis"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Barean Westwind - Script 2 - Set Kneel"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Barean Westwind - Script 2 - Say Line 3"),
(@ENTRY,9,7,0,0,0,100,0,5000,5000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Barean Westwind - Script 2 - Set Stand");












































