--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 30642;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,30642,0,0,31,0,3,17309,0,0,0,0,"","Group 0: Spell 'Request Heal' (Effect 0) targets creature 'Hellfire Watcher'");

DELETE FROM `creature_text` WHERE `CreatureID` = 17309;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17309,0,0,"We are the true Horde!",12,0,100,0,0,0,16697,0,"Hellfire Watcher"),
(17309,0,1,"For Kargath!  For Victory!",12,0,100,0,0,0,16698,0,"Hellfire Watcher"),
(17309,0,2,"Gakarah ma!",12,0,100,0,0,0,16699,0,"Hellfire Watcher"),
(17309,0,3,"The blood is our power! ",12,0,100,0,0,0,16700,0,"Hellfire Watcher"),
(17309,0,4,"Lok'tar Illadari!\n",12,0,100,0,0,0,16701,0,"Hellfire Watcher"),
(17309,0,5,"This world is OURS!",12,0,100,0,0,0,16702,0,"Hellfire Watcher"),
(17309,0,6,"Lok narash!",12,0,100,0,0,0,16703,0,"Hellfire Watcher");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17309 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17309,0,0,0,4,0,15,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Hellfire Watcher - On Aggro - Say Line 0"),
(17309,0,1,0,0,0,100,0,2400,6100,10500,23400,0,11,14032,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Hellfire Watcher - In Combat - Cast 'Shadow Word: Pain'"),
(17309,0,2,0,74,0,100,0,0,50,20000,25000,40,11,8362,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Hellfire Watcher - On Friendly Between 0-50% Health - Cast 'Renew'"),
(17309,0,3,0,74,0,100,0,0,40,12000,20000,40,11,12039,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Hellfire Watcher - On Friendly Between 0-40% Health - Cast 'Heal'"),
(17309,0,4,0,8,0,100,0,30642,0,0,0,0,11,30643,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Hellfire Watcher - On Spellhit 'Request Heal' - Cast 'Heal'");
