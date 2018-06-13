-- Witch Doctor Uzer'i
DELETE FROM `creature_text` WHERE `CreatureID`=8115 AND `GroupID` IN (0,1);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(8115,0,0,"%s begins the ritual.",16,0,100,0,0,0,4181,0,"Witch Doctor Uzer'i"),
(8115,1,0,"The muisek vessels are now ready, $n.",12,0,100,0,0,0,4180,0,"Witch Doctor Uzer'i");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8115;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8115 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=811500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8115,0,0,0,20,0,100,0,3122,0,0,0,80,811500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Quest 'Return to Witch Doctor Uzer'i' Finished - Run Script"),
(811500,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Remove Npc Flag Questgiver+Gossip"),
(811500,9,1,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4388.65,274.297,25.4396,0,"Witch Doctor Uzer'i - On Script - Move to Position"),
(811500,9,2,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Say Line 0"),
(811500,9,3,0,0,0,100,0,0,0,0,0,17,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Set Emote State 'Cheer'"),
(811500,9,4,0,0,0,100,0,6500,6500,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Set Emote State 'None'"),
(811500,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-4391.53,274.703,25.6304,0,"Witch Doctor Uzer'i - On Script - Move to Position"),
(811500,9,6,0,0,0,100,0,1500,1500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.59658,"Witch Doctor Uzer'i - On Script - Set Orientation"),
(811500,9,7,0,0,0,100,0,500,500,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Set Emote State 'Dance'"),
(811500,9,8,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Set Emote State 'None'"),
(811500,9,9,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-4375.68,269.717,25.4947,0,"Witch Doctor Uzer'i - On Script - Move to Position"),
(811500,9,10,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Say Line 1"),
(811500,9,11,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.72984,"Witch Doctor Uzer'i - On Script - Set Orientation"),
(811500,9,12,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Add Npc Flag Questgiver+Gossip");
