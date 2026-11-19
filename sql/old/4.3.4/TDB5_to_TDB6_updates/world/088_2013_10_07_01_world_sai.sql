-- Shattertusk Bull
SET @ENTRY      := 28380;
SET @SOURCETYPE := 0;

-- DELETE FROM `creature_ai_scripts` WHERE  `creature_id`=28380;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE `creature_template` SET AIName='SmartAI' WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,5000,5000,8000,11,51944,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Shattertusk Bull - In Combat - Cast Trample"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,7000,10000,13000,16000,11,55196,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Shattertusk Bull - In Combat - Cast Stomp");

-- Dreadsaber
SET @ENTRY      := 28001;
SET @SOURCETYPE := 0;

-- DELETE FROM `creature_ai_scripts` WHERE  `creature_id`=28001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE `creature_template` SET AIName='SmartAI' WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,3000,6000,5000,7000,11,24187,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Dreadsaber - In Combat - Cast Claw");

-- Shardhorn Rhino
SET @ENTRY      := 28009;
SET @SOURCETYPE := 0;

-- DELETE FROM `creature_ai_scripts` WHERE  `creature_id`=28009;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE `creature_template` SET AIName='SmartAI' WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,4,0,100,0,0,0,0,0,11,55193,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Shardhorn Rhino - On Aggro - Cast Rhino Charge"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,5000,9000,7000,12000,11,32019,32,0,0,0,0,4,0,0,0,0.0,0.0,0.0,0.0,"Shardhorn Rhino - In Combat - Cast Gore");

-- Shango
SET @ENTRY      := 28297;
SET @SOURCETYPE := 0;

-- DELETE FROM `creature_ai_scripts` WHERE  `creature_id`=28297;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE `creature_template` SET AIName='SmartAI' WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,5000,9000,7000,12000,11,32019,32,0,0,0,0,4,0,0,0,0.0,0.0,0.0,0.0,"Shango - In Combat - Cast Gore");

-- Mangal Crocolisk
SET @ENTRY      := 28002;
SET @SOURCETYPE := 0;

-- DELETE FROM `creature_ai_scripts` WHERE  `creature_id`=28002;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE `creature_template` SET AIName='SmartAI' WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,4,0,100,0,0,0,0,0,11,50502,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Mangal Crocolisk - On Aggro - Cast Thick Hide"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,6000,6000,9000,11,48287,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Mangal Crocolisk - In Combat - Cast Powerfull Bite");

-- Emperor Cobra
SET @ENTRY      := 28011;
SET @SOURCETYPE := 0;

-- DELETE FROM `creature_ai_scripts` WHERE  `creature_id`=28011;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE `creature_template` SET AIName='SmartAI' WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Emperor Cobra - On Spawn - Prevent Combat"),
(@ENTRY,@SOURCETYPE,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Emperor Cobra - Link - Set Phase to 0 on Spawn"),
(@ENTRY,@SOURCETYPE,2,3,4,0,100,0,0,0,0,0,11,32093,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Emperor Cobra - On Aggro - Cast Poison"),
(@ENTRY,@SOURCETYPE,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Emperor Cobra - On Link - Set Phase 1"),
(@ENTRY,@SOURCETYPE,4,0,9,1,100,0,0,40,3400,4800,11,32093,32,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Emperor Cobra - Cast Poison Spit (Phase 1)"),
(@ENTRY,@SOURCETYPE,5,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Emperor Cobra - Start Combat Movement at 35 Yards (Phase 1)"),
(@ENTRY,@SOURCETYPE,6,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Emperor Cobra - Prevent Combat Movement at 15 Yards (Phase 1)"),
(@ENTRY,@SOURCETYPE,7,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Emperor Cobra - Start Combat Movement Below 5 Yards (Phase 1)"),
(@ENTRY,@SOURCETYPE,8,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Emperor Cobra - Set Phase to 0 on Evade");
