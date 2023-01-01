-- https://www.youtube.com/watch?v=qZN2eSzQjuo
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 8421;
UPDATE `creature_template` SET `unit_flags` = 64 WHERE `entry` = 8391;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 8417 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8417,0,0,1,19,0,100,0,3566,0,0,0,0,12,8421,8,0,0,0,0,8,0,0,0,0,-6474.7,-1245.67,180.246,2.79601,"Dying Archaeologist - On Quest 'Rise, Obsidion!' Taken - Summon Creature 'Dorius'"),
(8417,0,1,2,61,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Dying Archaeologist - On Quest 'Rise, Obsidion!' Taken - Store TargetList"),
(8417,0,2,0,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,8421,0,0,0,0,0,0,0,"Dying Archaeologist - On Quest 'Rise, Obsidion!' Taken - Send Target 1 (Dorius)");

-- Not entirely correct, check comments of quest
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 8417 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,8417,0,0,29,0,8421,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Dorius' is not near"),
(22,1,8417,0,0,29,0,8391,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Lathoric the Black' is not near");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 148498 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(148498,1,0,1,62,0,100,0,1282,0,0,0,0,12,8421,8,0,0,0,0,8,0,0,0,0,-6474.7,-1245.67,180.246,2.79601,"Altar of Suntara - On Gossip Option 0 Selected - Summon Creature 'Dorius'"),
(148498,1,1,2,61,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Altar of Suntara - On Gossip Option 0 Selected - Store TargetList"),
(148498,1,2,3,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,8421,0,0,0,0,0,0,0,"Altar of Suntara - On Gossip Option 0 Selected - Send Target 1 (Dorius)"),
(148498,1,3,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Altar of Suntara - On Gossip Option 0 Selected - Close Gossip");

-- Not entirely correct, check comments of quest
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 148498 AND `SourceId` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,148498,1,0,29,0,8421,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Dorius' is not near"),
(22,1,148498,1,0,29,0,8391,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Lathoric the Black' is not near");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 8421 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 842100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8421,0,0,0,63,0,100,0,0,0,0,0,0,80,842100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Just Created - Run Script"),

(842100,9,0,0,0,0,100,0,1000,1000,0,0,0,5,21,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Script - Play Emote 21"),
(842100,9,1,0,0,0,100,0,4000,4000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Script - Say Line 0"),
(842100,9,2,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Script - Say Line 1"),
(842100,9,3,0,0,0,100,0,7000,7000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Script - Say Line 2"),
(842100,9,4,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Script - Say Line 3"),
(842100,9,5,0,0,0,100,0,6000,6000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Script - Say Line 4"),
(842100,9,6,0,0,0,100,0,6000,6000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Script - Say Line 5"),
(842100,9,7,0,0,0,100,0,6000,6000,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Script - Say Line 6"),
(842100,9,8,0,0,0,100,0,0,0,0,0,0,12,8391,4,300000,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Script - Summon Creature 'Lathoric the Black'"),
(842100,9,9,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,8391,0,0,0,0,0,0,0,"Dorius - On Script - Send Target 1 (Lathoric the Black)"),
(842100,9,10,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dorius - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `CreatureID` = 8421;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(8421,0,0,"Bravo! Bravo! Good show. What? You thought I was dead?",12,0,100,11,0,0,4393,0,"Dorius"),
(8421,1,0,"Fools, I knew that if I played upon my brother's feeble emotions, he would send 'rescuers.'",12,0,100,0,0,0,4394,0,"Dorius"),
(8421,2,0,"How easy it was to manipulate you into recovering the last Suntara stone from those imbeciles of the Twilight's Hammer.",12,0,100,0,0,0,4395,0,"Dorius"),
(8421,3,0,"When I stumbled upon the Suntara stones at the Grimesilt Digsite, the power of Ragnaros surged through my being. It was Ragnaros that gave me a purpose.",12,0,100,0,0,0,4396,0,"Dorius"),
(8421,4,0,"It was the will of Ragnaros that Obsidion be built. Obsidion will destroy the Blackrock orcs of Blackrock Spire, uniting us with our bretheren in the fiery depths.",12,0,100,5,0,0,4397,0,"Dorius"),
(8421,5,0,"And ultimately, it was Ragnaros that named me when I was reborn as an acolyte of fire: Lathoric... Lathoric the Black.",12,0,100,0,0,0,4398,0,"Dorius"),
(8421,6,0,"%s's laughter trails off...",16,0,100,0,0,0,4399,0,"Dorius");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 8391 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 839100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8391,0,0,0,63,0,100,0,0,0,0,0,0,80,839100,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lathoric the Black - On Just Created - Run Script"),

(839100,9,0,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lathoric the Black - On Script - Say Line 0"),
(839100,9,1,0,0,0,100,0,1500,1500,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lathoric the Black - On Script - Set Faction 14"),
(839100,9,2,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lathoric the Black - On Script - Start Attack Stored Target 1"),
(839100,9,3,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lathoric the Black - On Script - Say Line 1"),
(839100,9,4,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,8400,0,0,0,0,0,0,0,"Lathoric the Black - On Script - Send Target 1 (Obsidion)"),
(839100,9,5,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,19,8400,0,0,0,0,0,0,0,"Lathoric the Black - On Script - Remove Flag Immune To Players (Obsidion)"),
(839100,9,6,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,8400,0,0,0,0,0,0,0,"Lathoric the Black - On Script - Set Data 0 1 (Obsidion)"),
(839100,9,7,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,19,8400,0,0,0,0,0,0,0,"Lathoric the Black - On Script - Remove Flag Standstate Dead (Obsidion)");

UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = 8400;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8400 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Interesting mechanic, he becomes a companion of Lathoric the Black https://youtu.be/qZN2eSzQjuo?t=367
(8400,0,0,0,63,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Obsidion - On Just Created - Set Flag Standstate Dead"),
(8400,0,1,0,38,0,100,0,0,1,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Obsidion - On Data Set 0 1 - Start Attack Stored Target 1"),
(8400,0,2,3,1,0,100,0,300000,300000,300000,300000,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Obsidion - Out of Combat - Set Flag Standstate Dead"),
(8400,0,3,0,61,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Obsidion - Out of Combat - Add Flag Immune To Players"),
(8400,0,4,0,0,0,100,0,15000,15000,15000,30000,0,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Obsidion - In Combat - Cast 'Knock Away'"),
(8400,0,5,0,0,0,100,0,10000,10000,20000,30000,0,11,12734,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Obsidion - In Combat - Cast 'Floor Smash'");
