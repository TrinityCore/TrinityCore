-- Showdown (10742)
-- Showdown (10806)

DELETE FROM `creature_template_addon` WHERE `entry`=22448;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN(22496, 20555));
DELETE FROM `creature` WHERE `id` IN(22496, 20555);
DELETE FROM `waypoint_data` WHERE `id`=868810;

DELETE FROM `event_scripts` WHERE `id` IN(14462, 14525);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(14462, 0, 10, 20555, 300000, 0, 3703.51, 5387.74, -4.37, 5.9),
(14462, 0, 10, 22448, 300000, 0, 3688, 5353, 25, 0),
(14525, 0, 10, 20555, 300000, 0, 3703.51, 5387.74, -4.37, 5.9),
(14525, 0, 10, 22473, 300000, 0, 3718.36, 5361.27, -8.0, 2.14);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (39224,39223);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 39224, 0, 0, 29, 0, 20555, 100, 0, 1, 0, 0, '', 'Require no Goc nearby'),
(17, 0, 39223, 0, 0, 29, 0, 20555, 100, 0, 1, 0, 0, '', 'Require no Goc nearby');

DELETE FROM `creature_text` WHERE `CreatureID` IN (20555, 22473, 22448);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES 
(20555, 0, 0, 'Who dares place this affront upon the altar of Goc?', 14, 0, 100, 53, 0, 0, 20381, 'Goc'),
(20555, 1, 0, 'Who dares rouse Goc from his restful slumber?', 14, 0, 100, 53, 0, 0, 20317, 'Goc'),
(20555, 2, 0, 'Your name is as insignificant to me as the names of the thousands who have died under the might of Goc. I will crush you and $N', 14, 0, 100, 53, 0, 0, 20321, 'Goc'),
(22473, 0, 0, 'It''s only right that you know the name of the one who will take your life.', 14, 0, 100, 1, 0, 0, 20323, 'Baron Sablemane'),
(22473, 1, 0, 'Baron Sablemane. It will be on your lips as you gasp your dying breath.', 14, 0, 100, 1, 0, 0, 20324, 'Baron Sablemane'),
(22473, 2, 0, 'Let us begin.', 14, 0, 100, 15, 0, 0, 20325, 'Baron Sablemane'),
(22473, 3, 0, 'We will speak again, but away from here.', 14, 0, 100, 1, 0, 0, 20327, 'Baron Sablemane'),
(22448, 0, 0, 'I am Rexxar, son of the Mok''Nathal, champion of the Horde.', 14, 0, 100, 397, 0, 0, 20318, 'Rexxar'),
(22448, 1, 0, 'And their torment at your hands is at an end. By my name, I shall put an end to your life.', 14, 0, 100, 113, 0, 0, 20319, 'Rexxar'),
(22448, 2, 0, 'Prepare yourself for the end.', 14, 0, 100, 15, 0, 0, 20320, 'Rexxar'),
(22448, 3, 0, 'I could not have achieved this victory without you. We will speak back at Thunderlord Stronghold.', 14, 0, 100, 397, 0, 0, 20326, 'Rexxar');

UPDATE `creature_template` SET `InhabitType`=5, `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=22448;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry` IN (22473,20555);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20555,22473,22448) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(22473*100, 22473*100+1, 22448*100, 22448*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20555, 0, 0, 0, 38, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 22448, 100, 0, 0, 0, 0, 0, 'Goc - On Data Set - Set Orientation'),
(20555, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 1, 2, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Goc - On Data Set - Say Line 2'),
(20555, 0, 2, 9, 38, 0, 100, 0, 1, 2, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Goc - On Data Set - Attack Start'),
(20555, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 45106, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goc - On Death - Cast Showdown: Goc Kill Credit'),
(20555, 0, 4, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goc - On Evade - Despawn'),
(20555, 0, 5, 0, 0, 0, 100, 0, 9000, 12000, 11000, 15000, 11, 38784, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goc - In Combat - Cast Ground Smash'),
(20555, 0, 6, 0, 0, 0, 100, 0, 3000, 6000, 11000, 15000, 11, 38783, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Goc - In Combat - Cast Boulder Volley'),
(20555, 0, 7, 8, 25, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goc - On Reset - Set Unit Flags'),
(20555, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goc - On Reset - Set React Passive'),
(20555, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goc - Dataset - Remove Unit Flags'),
(20555, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Goc - Dataset - Set React Aggressive'),
(20555, 0, 11, 0, 38, 0, 100, 0, 1, 3, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 22473, 100, 0, 0, 0, 0, 0, 'Goc - On Data Set - Set Orientation'),
(20555, 0, 12, 0, 2, 0, 100, 1, 0, 50, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 22473, 60 , 0, 0, 0, 0, 0, "Goc - On health ptc - Set data"),
(22473, 0, 0, 0, 37, 0, 100, 257, 0, 0, 0, 0, 80, 22473*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Start Script'),
(22473, 0, 1, 0, 7, 0, 100, 257, 0, 0, 0, 0, 80, 22473*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Evade - Start Script'),
(22473, 0, 2, 0, 0, 1, 100, 0, 0, 1000, 3000, 3000, 11, 17290, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - In Combat - Cast Fireball'),
(22473, 0, 3, 0, 0, 1, 100, 0, 4000, 7000, 11000, 20000, 11, 39268, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - In Combat - Cast Chains of Ice'),
(22473*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Set Unit Flags'),
(22473*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 41232, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Cast Teleport Visual Only'),
(22473*100, 9, 2, 0, 0, 0, 100, 0, 500, 500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 20555, 100, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Say Line 1 Target'),
(22473*100, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Say Line 0'),
(22473*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 3, 0, 0, 0, 0, 19, 20555, 100, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Set Data'),
(22473*100, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Say Line 1'),
(22473*100, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 20555, 100, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Set Data'),
(22473*100, 9, 7, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Say Line 1'),
(22473*100, 9, 8, 0, 0, 0, 100, 0, 500, 500, 0, 0, 45, 1, 2, 0, 0, 0, 0, 19, 20555, 100, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Set Data'),
(22473*100, 9, 9, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Remove unitflag'),
(22473*100, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Start attack'),
(22473*100, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - In spell hit - Set event phase 1'),
(22473*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - demorph'),
(22473*100+1, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Say Line 3'),
(22473*100+1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set Orientation'),
(22473*100+1, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 41232, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Cast Teleport Visual Only'),
(22473*100+1, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - On Update - Despawn'),
(22473, 0, 6, 5, 38, 0, 100, 0, 0, 1, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - In data set - Set event phase 2'),
(22473, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 39255, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - In Data set - Cast Black Dragon Form'),
(22473, 0, 6, 7, 8, 0, 100, 1, 39255, 0, 0, 0, 3, 0, 21079, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - In spell hit - morph'),
(22473, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - In spell hit - Allow movements'),
(22473, 0, 8, 0, 0, 2, 100, 0, 7000, 9000, 9000, 12000, 11, 39263, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - In Combat - Flame Breath'),
(22473, 0, 9, 0, 0, 2, 100, 1, 5000, 5000, 0, 0, 3, 0, 21079, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baron Sablemane - IC Phase2 no repeat - morph in case the spell hit fails'),
(22448, 0, 0, 1, 37, 0, 100, 257, 0, 0, 0, 0, 43, 0 , 20964, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On AI Init - mount'),
(22448, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On AI Init - Set Flying'), 
(22448, 0, 2, 0, 60, 0, 100, 257, 0, 0, 0, 0, 80, 22448*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Start Script'),
(22448, 0, 3, 0, 7, 0, 100, 257, 0, 0, 0, 0, 80, 22448*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Evade - Start Script'),
(22448, 0, 4, 0, 0, 0, 100, 1, 4000, 4000, 0, 0, 11, 39269, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - In Combat - Cast Summon Misha'),
(22448, 0, 5, 0, 0, 0, 100, 1, 16000, 16000, 0, 0, 11, 39251, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - In Combat - Cast Summon Huffer'),
(22448, 0, 6, 0, 0, 0, 100, 1, 30000, 30000, 0, 0, 11, 39253, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - In Combat - Cast Summon Spirit'),
(22448*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set Unit Flags'),
(22448*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 27, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set Emote State'),
(22448*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3718.36, 5361.27, -6.5, 0, 'Rexxar - On Update - Move to Point'),
(22448*100, 9, 3, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 20555, 100, 0, 0, 0, 0, 0, 'Rexxar - On Update - Say Line 0 Target'),
(22448*100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 43, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Dismount'),
(22448*100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 2 , 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Remove hover'),
(22448*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 60, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set Fly off'),
(22448*100, 9, 7, 0, 0, 0, 100, 0, 500, 500, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 20555, 100, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set Orientation'),
(22448*100, 9, 8, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Say Line 0'),
(22448*100, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 19, 20555, 100, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set Data'),
(22448*100, 9, 10, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Say Line 1'),
(22448*100, 9, 11, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 20555, 100, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set Data'),
(22448*100, 9, 12, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Say Line 2'),
(22448*100, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set Home Position'),
(22448*100, 9, 14, 0, 0, 0, 100, 0, 500, 500, 0, 0, 45, 1, 2, 0, 0, 0, 0, 19, 20555, 100, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set Data'),
(22448*100, 9, 15, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Remove Unit Flags'),
(22448*100, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 20555, 100, 0, 0, 0, 0, 0, 'Rexxar - On Update - Attack Start'),
(22448*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 22492, 100, 0, 0, 0, 0, 0, 'Rexxar - On Update - Despawn Target'),
(22448*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 22498, 100, 0, 0, 0, 0, 0, 'Rexxar - On Update - Despawn Target'),
(22448*100+1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 22490, 100, 0, 0, 0, 0, 0, 'Rexxar - On Update - Despawn Target'),
(22448*100+1, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Say Line 3'),
(22448*100+1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set Orientation'),
(22448*100+1, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 43, 0, 20964, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Mount'),
(22448*100+1, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Set run'),
(22448*100+1, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 34873, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Cast fly'),
(22448*100+1, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 39333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Cast Rexxar Speed Increase'),
(22448*100+1, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 2, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3625, 5468, 104, 0, 'Rexxar - On Update - Move To Position'),
(22448*100+1, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rexxar - On Update - Despawn');
