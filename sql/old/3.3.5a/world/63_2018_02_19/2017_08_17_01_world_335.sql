-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=233;
DELETE FROM `creature_text` WHERE `CreatureID`=233;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(233,0,0, "Now how am I supposed to get those mechanical wretches out of my fields?", 12,7,100,0,0,0,58,0,'Farmer Saldean'),
(233,0,1, "A bunch of thugs and thieves aren't going to get me to leave my land!", 12,7,100,0,0,0,59,0,'Farmer Saldean'),
(233,0,2, "They might have run all the other farmers off, but the Saldean's will never leave Westfall.", 12,7,100,0,0,0,60,0,'Farmer Saldean');

DELETE FROM `smart_scripts` WHERE `entryorguid`=233;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(233,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Farmer Saldean - Out of Combat - Say Line 0');
