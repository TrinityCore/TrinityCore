-- Based on old script & https://www.youtube.com/watch?v=3XA4PS0mSZA & small pieces of event in sniffs
DELETE FROM `spell_script_names` WHERE `spell_id` IN (73835,73836,73725,73837,73886) AND `ScriptName` = "spell_q25199_emote";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(73835,"spell_q25199_emote"),
(73836,"spell_q25199_emote"),
(73725,"spell_q25199_emote"),
(73837,"spell_q25199_emote"),
(73886,"spell_q25199_emote");

UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 39349;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (39368,39349) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3936800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Ideally action list should be re-started inside action list 10 seconds after last action
(39368,0,0,0,60,0,100,0,10000,10000,95000,95000,0,80,3936800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Update - Run Script"),
(39368,0,1,0,22,0,100,0,78,0,0,0,0,11,73771,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Emote Received 'Salute' - Cast '[DND] Salute Quest Credit'"),
(39368,0,2,0,22,0,100,0,75,0,0,0,0,11,73832,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Emote Received 'Roar' - Cast '[DND] Roar Quest Credit'"),
(39368,0,3,0,22,0,100,0,21,0,0,0,0,11,73833,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Emote Received 'Cheer' - Cast '[DND] Cheer Quest Credit'"),
(39368,0,4,0,22,0,100,0,34,0,0,0,0,11,73830,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Emote Received 'Dance' - Cast '[DND] Dance Quest Credit'"),

(3936800,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 0"),
(3936800,9,1,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 1"),
(3936800,9,2,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 2"),
(3936800,9,3,0,0,0,100,0,4000,4000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 3"),
(3936800,9,4,0,0,0,100,0,4000,4000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 4"),
(3936800,9,5,0,0,0,100,0,0,0,0,0,0,11,73770,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Cast '[DND] Salute Quest Valid'"),
(3936800,9,6,0,0,0,100,0,1500,1500,0,0,0,11,73835,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Cast '[DND] Test Salute'"),
(3936800,9,7,0,0,0,100,0,5000,5000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 5"),
(3936800,9,8,0,0,0,100,0,5000,5000,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 6"),
(3936800,9,9,0,0,0,100,0,4000,4000,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 7"),
(3936800,9,10,0,0,0,100,0,4000,4000,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 8"),
(3936800,9,11,0,0,0,100,0,0,0,0,0,0,11,73831,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Cast '[DND] Roar Quest Valid'"),
(3936800,9,12,0,0,0,100,0,1000,1000,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Play Emote 15"),
(3936800,9,13,0,0,0,100,0,1500,1500,0,0,0,11,73836,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Cast '[DND] Test Roar'"),
(3936800,9,14,0,0,0,100,0,5000,5000,0,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 9"),
(3936800,9,15,0,0,0,100,0,5000,5000,0,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 10"),
(3936800,9,16,0,0,0,100,0,4000,4000,0,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 11"),
(3936800,9,17,0,0,0,100,0,4000,4000,0,0,0,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 12"),
(3936800,9,18,0,0,0,100,0,0,0,0,0,0,11,73834,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Cast '[DND] Cheer Quest Valid'"),
(3936800,9,19,0,0,0,100,0,1000,1000,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Play Emote 4"),
(3936800,9,20,0,0,0,100,0,1500,1500,0,0,0,11,73725,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Cast '[DND] Test Cheer'"),
(3936800,9,21,0,0,0,100,0,5000,5000,0,0,0,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 13"),
(3936800,9,22,0,0,0,100,0,5000,5000,0,0,0,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 14"),
(3936800,9,23,0,0,0,100,0,4000,4000,0,0,0,1,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 15"),
(3936800,9,24,0,0,0,100,0,4000,4000,0,0,0,1,16,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 16"),
(3936800,9,25,0,0,0,100,0,0,0,0,0,0,11,73829,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Cast '[DND] Dance Quest Valid'"),
(3936800,9,26,0,0,0,100,0,1000,1000,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Set Emote State 10"),
(3936800,9,27,0,0,0,100,0,1000,1000,0,0,0,11,73837,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Cast '[DND] Test Dance'"),
(3936800,9,28,0,0,0,100,0,5000,5000,0,0,0,1,17,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 17"),
(3936800,9,29,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Set Emote State 0"),
(3936800,9,30,0,0,0,100,0,0,0,0,0,0,11,73886,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Cast '[DND] Test Stop Dance'"),
(3936800,9,31,0,0,0,100,0,5000,5000,0,0,0,1,18,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drill Sergeant Steamcrank - On Script - Say Line 18");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 39368 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,39368,0,0,1,1,73770,0,0,0,0,0,"","Group 0: Execute SAI (Action 1) if creature does have aura '[DND] Salute Quest Valid'"),
(22,3,39368,0,0,1,1,73831,0,0,0,0,0,"","Group 0: Execute SAI (Action 2) if creature does have aura '[DND] Roar Quest Valid'"),
(22,4,39368,0,0,1,1,73834,0,0,0,0,0,"","Group 0: Execute SAI (Action 3) if creature does have aura '[DND] Cheer Quest Valid'"),
(22,5,39368,0,0,1,1,73829,0,0,0,0,0,"","Group 0: Execute SAI (Action 4) if creature does have aura '[DND] Dance Quest Valid'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (73835,73836,73725,73837,73886);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,73835,0,0,31,0,3,39349,0,0,0,0,"","Group 0: Spell '[DND] Test Salute' (Effect 0) targets creature 'Gnomeregan Trainee'"),
(13,1,73836,0,0,31,0,3,39349,0,0,0,0,"","Group 0: Spell '[DND] Test Roar' (Effect 0) targets creature 'Gnomeregan Trainee'"),
(13,1,73725,0,0,31,0,3,39349,0,0,0,0,"","Group 0: Spell '[DND] Test Cheer' (Effect 0) targets creature 'Gnomeregan Trainee'"),
(13,1,73837,0,0,31,0,3,39349,0,0,0,0,"","Group 0: Spell '[DND] Test Dance' (Effect 0) targets creature 'Gnomeregan Trainee'"),
(13,1,73886,0,0,31,0,3,39349,0,0,0,0,"","Group 0: Spell '[DND] Test Stop Dance' (Effect 0) targets creature 'Gnomeregan Trainee'");
