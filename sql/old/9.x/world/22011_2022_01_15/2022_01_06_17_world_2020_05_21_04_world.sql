-- (Source: https://www.youtube.com/watch?v=aR2UoUn-Q1A & other similar)
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` IN (186566,186567,186568,186569,186570,186571,186572,186573,186574,186575);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (186566,186567,186568,186569,186570,186571,186572,186573,186574,186575) AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18656600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(186566,1,0,0,70,0,100,0,2,0,0,0,0,80,18656600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Gameobject State Changed - Run Script"),
(186567,1,0,0,70,0,100,0,2,0,0,0,0,80,18656600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Gameobject State Changed - Run Script"),
(186568,1,0,0,70,0,100,0,2,0,0,0,0,80,18656600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Gameobject State Changed - Run Script"),
(186569,1,0,0,70,0,100,0,2,0,0,0,0,80,18656600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Gameobject State Changed - Run Script"),
(186570,1,0,0,70,0,100,0,2,0,0,0,0,80,18656600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Gameobject State Changed - Run Script"),
(186571,1,0,0,70,0,100,0,2,0,0,0,0,80,18656600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Gameobject State Changed - Run Script"),
(186572,1,0,0,70,0,100,0,2,0,0,0,0,80,18656600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Gameobject State Changed - Run Script"),
(186573,1,0,0,70,0,100,0,2,0,0,0,0,80,18656600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Gameobject State Changed - Run Script"),
(186574,1,0,0,70,0,100,0,2,0,0,0,0,80,18656600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Gameobject State Changed - Run Script"),
(186575,1,0,0,70,0,100,0,2,0,0,0,0,80,18656600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Gameobject State Changed - Run Script"),

(18656600,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Dragonflayer Cage - On Script - Store Targetlist"),
(18656600,9,1,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,24086,5,0,0,0,0,0,0,"Dragonflayer Cage - On Script - Send Target 1 (Captured Valgarde Priest)"),
(18656600,9,2,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,24088,5,0,0,0,0,0,0,"Dragonflayer Cage - On Script - Send Target 1 (Captured Valgarde Mage)"),
(18656600,9,3,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,24089,5,0,0,0,0,0,0,"Dragonflayer Cage - On Script - Send Target 1 (Captured Valgarde Warrior)"),
(18656600,9,4,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,24090,5,0,0,0,0,0,0,"Dragonflayer Cage - On Script - Send Target 1 (Captured Valgarde Paladin)"),
(18656600,9,5,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,24086,5,0,0,0,0,0,0,"Dragonflayer Cage - On Script - Set Data 0 1 (Captured Valgarde Priest)"),
(18656600,9,6,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,24088,5,0,0,0,0,0,0,"Dragonflayer Cage - On Script - Set Data 0 1 (Captured Valgarde Mage)"),
(18656600,9,7,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,24089,5,0,0,0,0,0,0,"Dragonflayer Cage - On Script - Set Data 0 1 (Captured Valgarde Warrior)"),
(18656600,9,8,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,24090,5,0,0,0,0,0,0,"Dragonflayer Cage - On Script - Set Data 0 1 (Captured Valgarde Paladin)");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (24086,24088,24089,24090);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24086,24088,24089,24090) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2408600,2408800,2408900,2409000) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24086,0,0,0,38,0,100,0,0,1,0,0,0,80,2408600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Priest - On Data Set 0 1 - Run Script"),
(24088,0,0,0,38,0,100,0,0,1,0,0,0,80,2408800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Mage - On Data Set 0 1 - Run Script"),
(24089,0,0,0,38,0,100,0,0,1,0,0,0,80,2408900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Warrior - On Data Set 0 1 - Run Script"),
(24090,0,0,0,38,0,100,0,0,1,0,0,0,80,2409000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Paladin - On Data Set 0 1 - Run Script"),

(2408600,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Priest - On Script - Say Line 0"),
(2408600,9,1,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Priest - On Script - Pause Waypoint"),
(2408600,9,2,0,0,0,100,0,2000,2000,0,0,0,11,43094,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Priest - On Script - Cast 'Valgarde Prisoner Credit'"),
(2408600,9,3,0,0,0,100,0,0,0,0,0,0,85,43030,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Priest - On Script - Self Cast 'Summon Valgarde Mage'"),
(2408600,9,4,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Priest - On Script - Despawn (0)"),

(2408800,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Mage - On Script - Say Line 0"),
(2408800,9,1,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Mage - On Script - Pause Waypoint"),
(2408800,9,2,0,0,0,100,0,2000,2000,0,0,0,11,43094,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Mage - On Script - Cast 'Valgarde Prisoner Credit'"),
(2408800,9,3,0,0,0,100,0,0,0,0,0,0,85,43028,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Mage - On Script - Self Cast 'Summon Valgarde Mage'"),
(2408800,9,4,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Mage - On Script - Despawn (0)"),

(2408900,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Warrior - On Script - Say Line 0"),
(2408900,9,1,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Warrior - On Script - Pause Waypoint"),
(2408900,9,2,0,0,0,100,0,2000,2000,0,0,0,11,43094,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Warrior - On Script - Cast 'Valgarde Prisoner Credit'"),
(2408900,9,3,0,0,0,100,0,0,0,0,0,0,85,42984,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Warrior - On Script - Self Cast 'Summon Valgarde Mage'"),
(2408900,9,4,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Warrior - On Script - Despawn (0)"),

(2409000,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Paladin - On Script - Say Line 0"),
(2409000,9,1,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Paladin - On Script - Pause Waypoint"),
(2409000,9,2,0,0,0,100,0,2000,2000,0,0,0,11,43094,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Paladin - On Script - Cast 'Valgarde Prisoner Credit'"),
(2409000,9,3,0,0,0,100,0,0,0,0,0,0,85,43032,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Captured Valgarde Paladin - On Script - Self Cast 'Summon Valgarde Mage'"),
(2409000,9,4,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Valgarde Paladin - On Script - Despawn (0)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (24086,24088,24089,24090);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24086,0,0,"You have my thanks, hero. If you don't mind, I'd like to stay by your side and exact a little vengeance upon my captors!",12,7,100,1,0,0,22753,0,"Captured Valgarde Priest"),
(24086,0,1,"Many thanks! Allow me to repay you by killing a few dozen of these beasts!",12,7,100,1,0,0,22760,0,"Captured Valgarde Priest"),
(24086,0,2,"Thanks, friend. Looking for another to join your group?",12,7,100,1,0,0,22761,0,"Captured Valgarde Priest"),
(24086,0,3,"I will help you out before I head back to Valgarde. It's the least I could do.",12,7,100,1,0,0,22762,0,"Captured Valgarde Priest"),
(24088,0,0,"You have my thanks, hero. If you don't mind, I'd like to stay by your side and exact a little vengeance upon my captors!",12,7,100,1,0,0,22753,0,"Captured Valgarde Mage"),
(24088,0,1,"Many thanks! Allow me to repay you by killing a few dozen of these beasts!",12,7,100,1,0,0,22760,0,"Captured Valgarde Mage"),
(24088,0,2,"Thanks, friend. Looking for another to join your group?",12,7,100,1,0,0,22761,0,"Captured Valgarde Mage"),
(24088,0,3,"I will help you out before I head back to Valgarde. It's the least I could do.",12,7,100,1,0,0,22762,0,"Captured Valgarde Mage"),
(24089,0,0,"You have my thanks, hero. If you don't mind, I'd like to stay by your side and exact a little vengeance upon my captors!",12,7,100,1,0,0,22753,0,"Captured Valgarde Warrior"),
(24089,0,1,"Many thanks! Allow me to repay you by killing a few dozen of these beasts!",12,7,100,1,0,0,22760,0,"Captured Valgarde Warrior"),
(24089,0,2,"Thanks, friend. Looking for another to join your group?",12,7,100,1,0,0,22761,0,"Captured Valgarde Warrior"),
(24089,0,3,"I will help you out before I head back to Valgarde. It's the least I could do.",12,7,100,1,0,0,22762,0,"Captured Valgarde Warrior"),
(24090,0,0,"You have my thanks, hero. If you don't mind, I'd like to stay by your side and exact a little vengeance upon my captors!",12,7,100,1,0,0,22753,0,"Captured Valgarde Paladin"),
(24090,0,1,"Many thanks! Allow me to repay you by killing a few dozen of these beasts!",12,7,100,1,0,0,22760,0,"Captured Valgarde Paladin"),
(24090,0,2,"Thanks, friend. Looking for another to join your group?",12,7,100,1,0,0,22761,0,"Captured Valgarde Paladin"),
(24090,0,3,"I will help you out before I head back to Valgarde. It's the least I could do.",12,7,100,1,0,0,22762,0,"Captured Valgarde Paladin");
