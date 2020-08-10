-- Tanaris
-- [Q] Rumors for Kravel -- http://wotlk.openwow.com/quest=1117
-- https://www.youtube.com/watch?reload=9&v=9bW2cscKMc8
-- (c) Toxic/ICC
-- Kravel Koalbeard SAI
SET @ID := 4452;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ID;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ID AND `source_type`=0 and `id` =3;
INSERT INTO `smart_scripts` VALUES (@ID, 0, 3, 0, 20, 0, 100, 0, 1117, 0, 0, 0, 0, 80, @ID*100+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Kravel Koalbeard - On Quest \'Rumors for Kravel\' Finished - Run Script');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ID*100+2 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Remove Npc Flag Questgiver"),
(@ID*100+2,9,1,0,0,0,100,0,1000,1000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Say Line 6"),
(@ID*100+2,9,2,0,0,0,100,0,1000,1000,0,0,5,94,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Emote Dance"),
(@ID*100+2,9,3,0,0,0,100,0,5000,5000,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Emote None"),
(@ID*100+2,9,4,0,0,0,100,0,1000,1000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Say Line 7"),
(@ID*100+2,9,5,0,0,0,100,0,2000,2000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID`=@ID AND `GroupID` IN (6,7);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,6,0,"%s begins to dance.",16,0,100,0,0,0,1480,0,"Kravel Koalbeard"),
(@ID,7,0,"Hahah! $n, you make quite a partner!",12,0,100,11,0,0,1481,0,"Kravel Koalbeard");
