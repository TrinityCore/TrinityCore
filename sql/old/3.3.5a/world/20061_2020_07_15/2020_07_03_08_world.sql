-- https://www.wowhead.com/npc=21277/vindicator-vuuleen#comments:id=172687:reply=39786
-- https://youtu.be/EiXYromDsfc?t=112
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 184702;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 184702 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(184702,1,0,1,70,0,100,0,2,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Cage - On Gameobject State Changed - Store Targetlist"),
(184702,1,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,21277,0,0,0,0,0,0,0,"Cage - On Link - Send Target 1 (Vindicator Vuuleen)"),
(184702,1,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,21277,0,0,0,0,0,0,0,"Cage - On Link - Set Data 0 1 (Vindicator Vuuleen)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 184702 AND `SourceId` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,184702,1,0,8,0,10518,0,0,1,0,0,"","Group 0: Execute SAI (Action 0) if quest 'Planting the Banner' is not rewarded");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 4542 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4542,2,0,1,46,0,100,0,4542,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Bladespire Hold) - On Trigger - Store Targetlist"),
(4542,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,21277,0,0,0,0,0,0,0,"Areatrigger (Bladespire Hold) - On Link - Send Target 1 (Vindicator Vuuleen)"),
(4542,2,2,0,61,0,100,0,0,0,0,0,0,45,0,2,0,0,0,0,19,21277,0,0,0,0,0,0,0,"Areatrigger (Bladespire Hold) - On Link - Set Data 0 2 (Vindicator Vuuleen)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4542;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4542,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4542 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4542,2,0,8,0,10516,0,0,1,0,0,"","Group 0: Execute SAI (Action 0) if quest 'The Trappings of a Vindicator' is not rewarded"),
(22,1,4542,2,0,9,0,10516,0,0,1,0,0,"","Group 0: Execute SAI (Action 0) if player has not taken quest 'The Trappings of a Vindicator'");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 21277;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21277 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21277,0,0,0,38,0,100,0,0,1,10000,10000,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Vindicator Vuuleen - On Data Set 0 1 - Say Line 0"),
(21277,0,1,0,38,0,100,0,0,2,30000,30000,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Vindicator Vuuleen - On Data Set 0 2 - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 21277;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(21277,0,0,"Hi.  Thanks for the help.  But please don't open the cage.",15,0,100,0,0,0,18918,0,"Vindicator Vuuleen"),
(21277,0,1,"Yes, the ogres are so stupid that they forgot to lock my cage.  But that's exactly how I like it, so please don't open it again.",15,0,100,0,0,0,18919,0,"Vindicator Vuuleen"),
(21277,0,2,"No.  Don't open the cage.  One of them might notice!",15,0,100,0,0,0,18920,0,"Vindicator Vuuleen"),
(21277,0,3,"Please leave the cage door closed.  Thanks.",15,0,100,0,0,0,18921,0,"Vindicator Vuuleen"),
(21277,1,0,"Psst, $r, up here near the entrance.  I'm in the cage.  Hurry!",15,0,100,0,0,0,18922,0,"Vindicator Vuuleen");
