--
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 15181;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 15181 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15181,0,0,0,20,0,100,0,8791,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Commander Mar'alith - On Quest 'The Fall of Ossirian' Finished - Say Line 0");

-- Probably sent to zone
DELETE FROM `creature_text` WHERE `CreatureID` = 15181;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(15181,0,0,"Soldiers of Kalimdor! Heroes of Silithus! One among you has dealt a vicious blow to our mortal enemies! $n and $g his:her; allies have relieved the Ruins of Ahn'Qiraj of its merciless leader! Ossirian the Unscarred, scourge of Silithus, has finally been destroyed and his armies wholly dismantled!",14,0,100,0,0,0,11355,0,"Commander Mar'alith");
