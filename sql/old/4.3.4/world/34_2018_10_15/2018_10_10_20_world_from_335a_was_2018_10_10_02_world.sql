-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25291;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25291 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25291,0,0,1,62,0,100,0,9761,0,0,0,0,11,52909,0,0,0,0,0,7,0,0,0,0,0,0,0,"Librarian Garren - On Gossip Option Selected - Cast Water Breathing"),
(25291,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Librarian Garren - On Gossip Option Selected - Close Gossip"),
(25291,0,2,0,19,0,100,0,11582,0,0,0,0,11,52909,0,0,0,0,0,7,0,0,0,0,0,0,0,"Librarian Garren - On quest taken - Cast Water Breathing");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9761;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9761,0,0,0,9,0,11582,0,0,0,0,0,"","Show gossip option 9761 if quest 'Monitoring the Rift: Sundered Chasm' is taken"),
(15,9761,0,0,0,1,0,52909,0,0,1,0,0,"","Show gossip option 9761 if Th palayer doesn't have the aura Water Breathing");
