DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=26735);
DELETE FROM `creature_template_addon` WHERE `entry`=26735;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (26735,0,1,0, '');

-- Ashmane Boar SAI
SET @ENTRY := 5992;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,0,0,0,0,0,11,11351,33,0,0,0,0,1,0,0,0,0,0,0,0,"Ashmane Boar - Out of Combat - Cast 'Fire Shield'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,12898,33,0,0,0,0,1,0,0,0,0,0,0,0,"Ashmane Boar - Out of Combat - Cast 'Smoke Aura Visual"),
(@ENTRY,0,2,0,9,0,50,1,5,20,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashmane Boar - Within 5-20 Range - Cast 'Rushing Charge'");

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=5992);
DELETE FROM `creature_template_addon` WHERE `entry`=5992;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (5992,0,4097,0, '');

-- Spiteful Apparition SAI
SET @ENTRY := 36551;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,6,0,0,0,0,11,69105,32,0,0,0,0,1,0,0,0,0,0,0,0,"Spiteful Apparition - On Reset - Cast 'Soul Horror Visual' (Dungeon)"),
(@ENTRY,0,1,2,61,0,100,6,0,0,0,0,11,69136,32,0,0,0,0,1,0,0,0,0,0,0,0,"Spiteful Apparition - On Reset - Cast 'Spiteful Apparition Visual' (Dungeon)"),
(@ENTRY,0,2,0,61,0,100,6,0,0,0,0,11,41253,32,0,0,0,0,1,0,0,0,0,0,0,0,"Spiteful Apparition - On Reset - Cast 'Greater Invisibility' (Dungeon)"),
(@ENTRY,0,3,0,10,0,100,6,0,10,3000,4000,28,41253,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spiteful Apparition - Within 0-10 Range Out of Combat LoS - Remove Aura 'Greater Invisibility' (Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,7000,9000,7000,9000,11,68895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spiteful Apparition - In Combat - Cast 'Spite' (Normal)"),
(@ENTRY,0,5,0,0,0,100,4,7000,9000,7000,9000,11,70212,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spiteful Apparition - In Combat - Cast 'Spite' (Heroic)");
UPDATE `creature_template_addon`  SET `auras`= '' WHERE `entry` IN (36551);

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=26734);
DELETE FROM `creature_template_addon` WHERE `entry`=26734;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (26734,0,1,0, '');

-- Smoldering Construct SAI
SET @ENTRY := 27362;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,48460,32,0,0,0,0,1,0,0,0,0,0,0,0,"Smoldering Construct - On Reset - Cast 'Smoldering Flames'"),
(@ENTRY,0,1,0,0,0,100,0,4000,9000,12000,16000,11,51439,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smoldering Construct - In Combat - Cast 'Backlash'");
UPDATE `creature_template_addon`  SET `auras`= '' WHERE `entry` IN (27362);
