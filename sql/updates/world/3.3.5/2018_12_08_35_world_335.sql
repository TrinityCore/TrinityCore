--
-- Lotwil Veriatus
UPDATE `creature_template` SET `unit_class`=2 WHERE `entry`=2921;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2921 AND `source_type`=0 AND `id` IN (1,2,3,4,5,6,7);
DELETE FROM `smart_scripts` WHERE `entryorguid`=292100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2921,0,1,0,25,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Reset - Add Unit Flags 'Immune to Player' & 'Immune to NPC'"),
(2921,0,2,0,25,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Reset - Set Faction 35"),
(2921,0,3,0,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Data Set - Remove Unit Flags 'Immune to Player' & 'Immune to NPC'"),
(2921,0,4,0,38,0,100,0,1,1,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Data Set - Set Faction 113"),
(2921,0,5,0,38,0,100,0,1,1,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Data Set - Say Line 2"),
(2921,0,6,0,38,0,100,0,1,1,0,0,49,0,0,0,0,0,0,19,2919,0,0,0,0,0,0,"Lotwil Veriatus - On Data Set - Start Attacking"),
(2921,0,7,0,0,0,100,0,1000,1000,3000,5000,11,13901,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lotwil Veriatus - In Combat - Cast 'Arcane Bolt'"),
(292100,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Script - Remove Npc Flag Questgiver"),
(292100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Script - Say Line 0"),
(292100,9,2,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,2920,0,0,0,0,0,0,"Lotwil Veriatus - On Script - Say Line 0 (Lucien Tosselwrench)"),
(292100,9,3,0,0,0,100,0,1000,1000,0,0,11,5001,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Script - Cast 'Lotwil's Summoning'"),
(292100,9,4,0,0,0,100,0,1000,1000,0,0,12,2919,1,240000,0,0,0,8,0,0,0,-6666.27,-2728.12,243.136,6.28,"Lotwil Veriatus - On Script - Summon Creature 'Fam'retor Guardian'"),
(292100,9,5,0,0,0,100,0,0,0,0,0,11,5002,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Script - Cast 'Lotwil's Summon Complete'"),
(292100,9,6,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,19,2919,0,0,0,0,0,0,"Lotwil Veriatus - On Script - Set Data to Fam'retor Guardian"),
(292100,9,7,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Script - Say Line 1"),
(292100,9,8,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,19,2922,0,0,0,0,0,0,"Lotwil Veriatus - On Script - Say Line 2 (Servo)"),
(292100,9,9,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lotwil Veriatus - On Script - Add Npc Flag Questgiver");

-- Fam'retor Guardian
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2919;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2919 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2919,0,0,0,38,0,100,0,1,1,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Fam'retor Guardian - On Data Set - Start Attacking"),
(2919,0,1,0,2,0,100,1,0,30,0,0,0,45,1,1,0,0,0,0,19,2921,0,0,0,0,0,0,"Fam'retor Guardian - Between 0-30% Health - Set Data to Lotwil Veriatus"),
(2919,0,2,0,6,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fam'retor Guardian - On Just Died - Say Line 0");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (2921,2920,2919);
DELETE FROM `creature_text` WHERE `CreatureID`=2922 AND `GroupID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2921,0,0,"Now to test my design!",12,0,100,1,0,0,948,0,"Lotwil Veriatus"),
(2921,1,0,"Oh no!  It's out of control!  Run!",12,0,100,5,0,0,949,0,"Lotwil Veriatus"),
(2921,2,0,"I guess I'd better do something about this!",12,0,100,0,0,0,950,0,"Lotwil Veriatus"),
(2920,0,0,"%s looks over at Lotwil nervously.",16,0,100,0,0,0,959,0,"Lucien Tosselwrench"),
(2922,2,0,"Protect master!",12,0,100,0,0,0,951,0,"Servo"),
(2919,0,0,"%s is ripped apart as it is banished from this world.",16,0,100,0,0,0,853,0,"Fam'retor Guardian");
