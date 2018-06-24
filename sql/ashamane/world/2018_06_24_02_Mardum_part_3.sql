    /*//////////////////////////////////////////////////////////////////////
   //  FunSocietyWoW - SAI DEV                                           //
  //  Copyright 2018 FunSocietyWoW and Ashamane Core //
 //  All Rights Reserved                                                       //
//////////////////////////////////////////////////////////////////////////

/*#############
# Mardum Part - 3   #
#############*/

-- Doom Commander Beliash SAI
SET @DOOM_COMMANDER_BELIASH := 93221;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@DOOM_COMMANDER_BELIASH;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DOOM_COMMANDER_BELIASH AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DOOM_COMMANDER_BELIASH,0,0,0,0,0,100,0,5000,8000,12000,15000,11,195401,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doom Commander Beliash - In Combat - Cast 'Shadow Blaze'"),
(@DOOM_COMMANDER_BELIASH,0,1,0,0,0,100,0,10000,10000,10000,25000,11,196403,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doom Commander Beliash - In Combat - Cast 'Bolt Volley'");

DELETE FROM `creature_text` WHERE `CreatureID` = 93221;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(93221, 0, 0, 'They will die.', 14, 0, 100, 0, 0, 55133, 0, 0, 'Doom Commander Beliash to Player'),
(93221, 1, 0, 'You won''t survive Inferno Peak...', 12, 0, 100, 0, 0, 55134, 0, 0, 'Doom Commander Beliash to Player');

-- Doomguard Eradicator SAI
SET @DOOMGUARD_ERADICATOR := 94654;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@DOOMGUARD_ERADICATOR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DOOMGUARD_ERADICATOR AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DOOMGUARD_ERADICATOR,0,0,0,0,0,100,0,5000,8000,12000,15000,11,200608,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doomguard Eradicator - In Combat - Cast 'Shadowflame'");

-- Fel Visage SAI
SET @FEL_VISAGE := 100992;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@FEL_VISAGE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FEL_VISAGE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FEL_VISAGE,0,0,0,0,0,100,0,0,0,3400,4700,11,199100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Visage - In Combat - Cast 'Fel Bolt'"),
(@FEL_VISAGE,0,1,0,0,0,100,0,5000,8000,12000,15000,11,199105,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Visage - In Combat - Cast 'Fel Drill'");

-- Fury Champion SAI
SET @FURY_CHAMPION := 97034;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@FURY_CHAMPION;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FURY_CHAMPION AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FURY_CHAMPION,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Fury Champion- In Combat - Say Line 0 (No Repeat)"),
(@FURY_CHAMPION,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200753,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fury Champion - In Combat - Cast 'Furious Flurry'");

DELETE FROM `creature_text` WHERE `CreatureID` = 97034;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97034, 0, 0, 'I live to serve.', 12, 0, 100, 0, 0, 55363, 0, 0, 'Fury Champion to Demon Hunter');