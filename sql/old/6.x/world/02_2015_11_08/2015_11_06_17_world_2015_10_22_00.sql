-- 
-- Orbaz Bloodbane (NPC 28914) condition for gossip option 9769 to be visible only for quest 12757, Scarlet Armies Approach...
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9769 AND `ConditionValue1`=39654;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9769,0,0,0,2,0,39654,1,0,0,0,0,'','Orbaz Bloodbane - Show gossip option only if player has received item 39654, The Path of Redemption, from quest 12757');

-- Orbaz Bloodbane SAI
SET @ENTRY := 28914;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,12757,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Orbaz Bloodbane - On Quest 'Scarlet Armies Approach' Taken - Run Script"),
(@ENTRY,0,1,2,62,0,100,0,9769,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orbaz Bloodbane - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,2,0,61,0,100,0,9769,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Orbaz Bloodbane - On Gossip Option 0 Selected - Run Script");
