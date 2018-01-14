/*
-- Chemist Cuely
DELETE FROM `creature_text` WHERE `CreatureID`=8390;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(8390,0,0,"There! Job's done.",12,0,100,1,0,0,4522,0,'Chemist Cuely');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=8390;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8390 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=839000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8390,0,0,0,20,0,100,0,3568,0,0,0,80,839000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chemist Cuely - On Quest 'Seeping Corruption' Finished - Run Script"),
(839000,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chemist Cuely - On Script - Remove Npc Flag Questgiver"),
(839000,9,1,0,0,0,100,0,0,0,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chemist Cuely - On Script - Set Emote State 133"),
(839000,9,2,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chemist Cuely - On Script - Set Emote State 0"),
(839000,9,3,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chemist Cuely - On Script - Say Line 0"),
(839000,9,4,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chemist Cuely - On Script - Add Npc Flag Questgiver");

-- Thersa Windsong
DELETE FROM `creature_text` WHERE `CreatureID`=8393;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(8393,0,0,"Wha... what's happening?",12,0,100,15,0,0,4533,0,'Thersa Windsong');

UPDATE `creature` SET `spawntimesecs`= 30 WHERE `guid`=31905;
UPDATE `creature_addon` SET `auras`=19502 WHERE `guid`=31905;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=8393;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8393 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=839300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8393,0,0,0,20,0,100,0,3569,0,0,0,80,839300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thersa Windsong - On Quest 'Seeping Corruption (Part 2)' Finished - Run Script"),
(8393,0,1,0,6,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thersa Windsong - On Just Died - Despawn In 5000 ms"),
(839300,9,0,0,0,0,100,0,0,0,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thersa Windsong - On Script - Play Emote 7"),
(839300,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thersa Windsong - On Script - Say Line 0"),
(839300,9,2,0,0,0,100,0,3000,3000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thersa Windsong - On Script - Kill Self");

-- Quest "Seeping Corruption (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=3569;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(3569,1,11,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3569;

-- Quest "Seeping Corruption (Part 3)"
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=11, `RewardText`="I never dreamed the elixir would take hold that quickly. Thank you, $n. I will get to work on the rest of these samples right away. I'm sure they'll be usable by the Lady Sylvanas and the Forsaken soon enough." WHERE `ID`=3570;
*/
