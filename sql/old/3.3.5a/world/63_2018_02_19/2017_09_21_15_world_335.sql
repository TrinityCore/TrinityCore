-- Marshal Gryan Stoutmantle
DELETE FROM `creature_text` WHERE `CreatureID`=234 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(234,1,0,"Everywhere I look I see thieves.  We, The People\'s Miltia, must return this land to the farmers.",12,7,100,0,0,0,39,0,"Marshal Gryan Stoutmantle"),
(234,1,1,"The farms must be liberated.  Stormwind may have deserted these people, but I\'ll be damned if I will.",12,7,100,0,0,0,40,0,"Marshal Gryan Stoutmantle"),
(234,1,2,"Stormwind\'s desertion shall not be forgiven by the people of Westfall.",12,7,100,0,0,0,44,0,"Marshal Gryan Stoutmantle");
DELETE FROM `smart_scripts` WHERE `entryorguid`=234 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(234,0,1,0,1,0,100,0,1000,15000,150000,180000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal Gryan Stoutmantle - Out of Combat - Say Line 1");

-- Protector Gariel
UPDATE `creature_model_info` SET `Gender`=1 WHERE `DisplayID`=2367;
DELETE FROM `creature_text` WHERE `CreatureID`=490;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(490,0,0,"Defias activity reported on the costal horizon.  All clear on Sentinel Hill.",12,7,100,0,0,0,41,0,"Protector Gariel");
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=490;
DELETE FROM `smart_scripts` WHERE `entryorguid`=490 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(490,0,0,0,1,0,100,0,30000,45000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Protector Gariel - Out of Combat - Say Line 0");

-- Protector Bialon
DELETE FROM `creature_text` WHERE `CreatureID`=487;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(487,0,0,"Lots of gnoll activity reported in the Gold Coast Quarry and the Jangolode Mine.",12,7,100,0,0,0,42,0,"Protector Bialon");
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=487;
DELETE FROM `smart_scripts` WHERE `entryorguid`=487;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(487,0,0,0,1,0,100,0,75000,90000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Protector Bialon - Out of Combat - Say Line 0");

-- Captain Danuvin
DELETE FROM `creature_text` WHERE `CreatureID`=821;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(821,0,0,"All clear on Sentinel Hill, Lord Stoutmantle.  Heavy Defias movement reported in Moonbrook, however.",12,7,100,0,0,0,43,0,"Captain Danuvin");
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=821;
DELETE FROM `smart_scripts` WHERE `entryorguid`=821;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(821,0,0,0,1,0,100,0,120000,135000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Danuvin - Out of Combat - Say Line 0");

-- Barkeep Hann
DELETE FROM `creature_text` WHERE `CreatureID`=274;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(274,0,0,"Psssst.  We just got some Moonshine in. . . .",12,7,100,0,0,0,80,0,"Barkeep Hann"),
(274,0,1,"Step right up and wet your whistle.",12,7,100,0,0,0,81,0,"Barkeep Hann");
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=274;
DELETE FROM `smart_scripts` WHERE `entryorguid`=274;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(274,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tavernkeep Smitts - Out of Combat - Say Line 0");
