-- Tosamina
DELETE FROM `creature_text` WHERE `CreatureID`=14498;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(14498,0,0,"You are mine now, children.  You will grow up to be a strong part of the Horde!",12,1,100,0,0,0,9693,0,"Tosamina"),
(14498,0,1,"Stop whining!",12,1,100,0,0,0,9694,0,"Tosamina"),
(14498,0,2,"Clean this place up! We will not live in such squalor.",12,1,100,0,0,0,9695,0,"Tosamina"),
(14498,0,3,"It's my way or the Gold Road.  Is that understood?",12,1,100,0,0,0,9696,0,"Tosamina");
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14498;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14498;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14498,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tosamina - Out of Combat - Say Line 0");
