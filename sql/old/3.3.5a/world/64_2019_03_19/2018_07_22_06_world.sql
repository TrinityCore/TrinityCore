-- Sharth and Pathaleon conversation
DELETE FROM `creature_text` WHERE `CreatureID`=21504 AND `GroupID`=13;
DELETE FROM `creature_text` WHERE `CreatureID`=18554;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18554,0,0,"You come into my house and threaten ME?  I think not!'",12,0,100,1,0,0,15542,0,"Sharth Voldoun"),
(18554,1,0,"My master, we are honored by your presence.  How may I serve thee?",12,0,100,0,0,0,19156,0,"Sharth Voldoun"),
(18554,2,0,"All goes exceedingly well, my lord.  Testing of the smaller prototype at the Cenarion Thicket was a complete success.  The second bomb is being ritually fueled in the courtyard below even as we speak.  And, I''ve sent a courier to Tuurem to bring the rest of the parts to us here.",12,0,100,1,0,0,19159,0,"Sharth Voldoun"),
(18554,3,0,'You are satisfied?',12,0,100,6,0,0,19160,0,"Sharth Voldoun"),
(18554,4,0,'I can assure you that we will not fail, my master.  I am personally overseeing every aspect of the construction, and I hold the final codes, myself.  Within a day''s time, I will have the bomb detonated on those nearby pests.',12,0,100,2,0,0,19164,0,"Sharth Voldoun"),
(21504,13,0,'Rise, young Voldoun.  Do not worry yourself with pleasantries.  I come at the behest of our master, Prince Kael''thas.  He bids me to check on the progress of the mana bomb.',12,0,100,1,0,0,19157,0,"Pathaleon the Calculator's Image");

-- Incorrect spawning of Pathaleon the Calculators Image
DELETE FROM `creature` WHERE `guid`=85566 AND `id`=21504;

-- Sharth Voldoun, fix position and weapon sheathed
UPDATE `creature` SET `position_x` = -2288.34839, `position_y` = 3091.4968, `orientation` = 3.2263 WHERE `guid` = 86925;
DELETE FROM `creature_template_addon` WHERE `entry`=18554;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(18554,0,0,0,0,0,"");

-- Sharth Voldoun
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 18554;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18554 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1855400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18554,0,0,0,0,0,100,0,3000,5000,40000,45000,0,11,15277,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharth Voldoun - IC - Cast Seal of Reckoning"),
(18554,0,1,0,2,0,100,0,0,40,15000,20000,0,11,13952,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharth Voldoun - On Below 40% HP - Cast Holy Light"),
(18554,0,2,3,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharth Voldoun - On Aggro - Say Line 0"),
(18554,0,3,0,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,21504,50,0,0,0,0,0,"Sharth Voldoun - On Aggro - Set Data"),
(18554,0,4,0,1,0,100,0,30000,30000,120000,120000,0,80,1855400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharth Voldoun - OOC - RunScript"),
(1855400,9,0,0,0,0,100,0,0,0,0,0,0,12,21504,8,0,0,0,0,8,0,0,0,-2293.5210,3091.34302,152.817734,6.17546,"Sharth Voldoun - On Script - Summon Pathaleon the Calculators Image"),
(1855400,9,1,0,0,0,100,0,2000,2000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharth Voldoun - On Script - Set Flag Standstate 'Kneel'"),
(1855400,9,2,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharth Voldoun - On Script - Say Line 1"),
(1855400,9,3,0,0,0,100,0,7000,7000,0,0,0,1,13,0,0,0,0,0,19,21504,0,0,0,0,0,0,"Sharth Voldoun - On Script - Say Line 13 (Pathaleon the Calculators Image)"),
(1855400,9,4,0,0,0,100,0,3000,3000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharth Voldoun - On Script - Remove Flag Standstate 'Kneel'"),
(1855400,9,5,0,0,0,100,0,8000,8000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharth Voldoun - On Script - Say Line 2"),
(1855400,9,6,0,0,0,100,0,14000,14000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharth Voldoun - On Script - Say Line 3"),
(1855400,9,7,0,0,0,100,0,4000,4000,0,0,0,1,4,0,0,0,0,0,19,21504,0,0,0,0,0,0,"Sharth Voldoun - On Script - Say Line 4 (Pathaleon the Calculators Image)"),
(1855400,9,8,0,0,0,100,0,16000,16000,0,0,0,1,5,0,0,0,0,0,19,21504,0,0,0,0,0,0,"Sharth Voldoun - On Script - Say Line 5 (Pathaleon the Calculators Image)"),
(1855400,9,9,0,0,0,100,0,16000,16000,0,0,0,1,6,0,0,0,0,0,19,21504,0,0,0,0,0,0,"Sharth Voldoun - On Script - Say Line 6 (Pathaleon the Calculators Image)"),
(1855400,9,10,0,0,0,100,0,10000,10000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharth Voldoun - On Script - Say Line 4"),
(1855400,9,11,0,0,0,100,0,13000,13000,0,0,0,1,7,0,0,0,0,0,19,21504,0,0,0,0,0,0,"Sharth Voldoun - On Script - Say Line 7 (Pathaleon the Calculators Image)"),
(1855400,9,12,0,0,0,100,0,0,0,0,0,0,45,3,3,0,0,0,0,19,21504,0,0,0,0,0,0,"Sharth Voldoun - On Script - Set Data to Pathaleon the Calculators Image");

-- Pathaleon the Calculators Image
DELETE FROM `smart_scripts` WHERE `entryorguid`=21504 AND `ID`>1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2150401 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2150402 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21504 AND `ID`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21504,0,2,0,54,0,100,0,0,0,0,0,0,11,34427,2,0,0,0,0,1,0,0,0,0,0,0,0,"Pathaleon the Calculator's Image - On Just Summoned - Cast Ethereal Teleport"),
(21504,0,3,0,54,0,100,0,0,0,0,0,0,11,33900,2,0,0,0,0,1,0,0,0,0,0,0,0,"Pathaleon the Calculator's Image - On Just Summoned - Cast Shroud of Death"),
(21504,0,4,0,38,0,100,0,3,3,0,0,0,80,2150401,2,0,0,0,0,1,0,0,0,0,0,0,0,"Pathaleon the Calculator's Image - On Data Set - Run Script"),
(2150401,9,0,0,0,0,100,0,8000,8000,0,0,0,11,34427,2,0,0,0,0,1,0,0,0,0,0,0,0,"Pathaleon the Calculator's Image - On Script - Cast Ethereal Teleport"),
(2150401,9,1,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pathaleon the Calculator's Image - On Script - Despawn"),
(21504,0,0,0,38,0,100,0,1,1,0,0,0,80,2150402,2,0,0,0,0,1,0,0,0,0,0,0,0,"Pathaleon the Calculator's Image - On Data Set - Run Script"),
(2150402,9,0,0,0,0,100,0,1000,1000,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pathaleon the Calculator's Image - On Script - Say text"),
(2150402,9,1,0,0,0,100,0,5000,5000,0,0,0,11,34427,2,0,0,0,0,1,0,0,0,0,0,0,0,"Pathaleon the Calculator's Image - On Script - Cast Ethereal Teleport"),
(2150402,9,2,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pathaleon the Calculator's Image - On Script - Despawn");
