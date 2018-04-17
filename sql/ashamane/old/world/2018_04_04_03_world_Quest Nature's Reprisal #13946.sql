/*/////////////////////////////////////////////////
//  Ashamane - SAI DEV                           //
//  Copyright 2018 Ashamane                      //
//  All Rights Reserved                          //
///////////////////////////////////////////////////

############################
# Nature's Reprisal #13946 #
##########################*/

-- Rascal Sprite SAI
SET @ENTRY := 2002;
UPDATE `creature_template` SET `KillCredit1`=34440, `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,12000,30000,40000,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Faerie Fire"),
(@ENTRY,0,1,0,8,0,100,0,65455,0,10000,10000,11,65462,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Explode Demon Shrink Countdown on self"),
(@ENTRY,0,2,0,8,0,100,0,65455,0,10000,10000,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Despawn self after 5 sec"),
(@ENTRY,0,3,0,8,0,100,0,65455,0,10000,10000,33,34440,0,0,0,0,0,7,0,0,0,0,0,0,0,"Give Killcredit");

-- Shadow Sprite SAI
SET @ENTRY := 2003;
UPDATE `creature_template` SET `KillCredit1`=34440, `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Set Phase 1 on Aggro"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stop Moving on Aggro"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast bolt on Aggro"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4700,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast bolt"),
(@ENTRY,0,4,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Start Moving when not in bolt Range"),
(@ENTRY,0,5,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stop Moving at 15 Yards"),
(@ENTRY,0,6,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stop Moving when in bolt Range"),
(@ENTRY,0,7,0,3,1,100,0,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Set Phase 2 at 15% Mana"),
(@ENTRY,0,8,0,3,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Start Moving at 15% Mana"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Set Phase 1 When Mana is above 30%"),
(@ENTRY,0,10,0,2,2,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Set Phase 3 at 15% HP"),
(@ENTRY,0,11,0,2,3,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flee at 15% HP"),
(@ENTRY,0,12,0,7,3,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reset on Evade"),
(@ENTRY,0,13,0,2,3,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Say Text at 15% HP"),
(@ENTRY,0,14,0,8,0,100,0,65455,0,10000,10000,11,65462,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Explode Demon Shrink Countdown on self"),
(@ENTRY,0,15,0,8,0,100,0,65455,0,10000,10000,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Despawn self after 5 sec"),
(@ENTRY,0,16,0,8,0,100,0,65455,0,10000,10000,33,34440,0,0,0,0,0,7,0,0,0,0,0,0,0,"Give Killcredit");

-- Dark Sprite SAI
SET @ENTRY := 2004;
UPDATE `creature_template` SET `KillCredit1`=34440, `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,15000,21000,11,5514,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Darken Vision"),
(@ENTRY,0,1,0,8,0,100,0,65455,0,10000,10000,11,65462,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Explode Demon Shrink Countdown on self"),
(@ENTRY,0,2,0,8,0,100,0,65455,0,10000,10000,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Despawn self after 5 sec"),
(@ENTRY,0,3,0,8,0,100,0,65455,0,10000,10000,33,34440,0,0,0,0,0,7,0,0,0,0,0,0,0,"Give Killcredit");

-- Vicious Grell SAI
SET @ENTRY := 2005;
UPDATE `creature_template` SET `KillCredit1`=34440, `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,10000,16000,11,5515,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Savagery at 30% HP"),
(@ENTRY,0,1,0,8,0,100,0,65455,0,10000,10000,11,65462,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Explode Demon Shrink Countdown on self"),
(@ENTRY,0,2,0,8,0,100,0,65455,0,10000,10000,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Despawn self after 5 sec"),
(@ENTRY,0,3,0,8,0,100,0,65455,0,10000,10000,33,34440,0,0,0,0,0,7,0,0,0,0,0,0,0,"Give Killcredit");
