--
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 21133;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21133 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2113300 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21133,0,0,0,20,0,100,0,10483,0,0,0,0,80,2113300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Corporal Ironridge - On Quest 'Ill Omens' Finished - Run Script"),

(2113300,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Corporal Ironridge - On Script - Say Line 0"),
(2113300,9,1,0,0,0,100,0,4000,4000,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Corporal Ironridge - On Script - Say Line 1"),
(2113300,9,2,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.565634012222290039,"Corporal Ironridge - On Script - Set Orientation"),
(2113300,9,3,0,0,0,100,0,0,0,0,0,0,1,2,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Corporal Ironridge - On Script - Say Line 2"),
(2113300,9,4,0,0,0,100,0,3000,3000,0,0,0,1,3,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Corporal Ironridge - On Script - Say Line 3"),
(2113300,9,5,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Corporal Ironridge - On Script - Set Orientation Home Position");

DELETE FROM `creature_text` WHERE `CreatureID` = 21133;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(21133,0,0,"%s inspects the talisman $n gave him...",16,0,100,0,0,0,20178,0,"Corporal Ironridge"),
(21133,1,0,"Ah, this was from Private Denning.  I remember when he fell...",12,0,100,1,0,0,20179,0,"Corporal Ironridge"),
(21133,1,1,"This one was from Corporal Stonewell... he died protecting a field hospital...",12,0,100,1,0,0,20180,0,"Corporal Ironridge"),
(21133,1,2,"Ah, yes... Private Guarding.  He always was quick to laugh... until a Bleeding Hollow Raid tore out his throat!",12,0,100,1,0,0,20181,0,"Corporal Ironridge"),
(21133,1,3,"This insignia is from Sergeant Rantack, once my superior.  You'd never find a tougher soldier than old Rantack...",12,0,100,1,0,0,20182,0,"Corporal Ironridge"),
(21133,2,0,"%s faces the Bleeding Hollow fort of Zeth'Gor...",16,0,100,0,0,0,20183,0,"Corporal Ironridge"),
(21133,3,0,"Damn you!  Damn all of you bleeding fel orcs!  May your souls rot in the belly of whatever Dark Power that fuels you!",12,0,100,15,0,0,20184,0,"Corporal Ironridge");
