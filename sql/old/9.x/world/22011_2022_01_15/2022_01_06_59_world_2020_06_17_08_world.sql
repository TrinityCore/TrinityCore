-- Dark Iron Kidnapper SAI (Source: Movies)
SET @ID := 15692;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Dark Iron Kidnapper - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ye'll be feasting on me blade this Winter Veil!  Yeargh!",12,0,100,0,0,0,11397,0,"Dark Iron Kidnapper"),
(@ID,0,1,"No scallywag $c is taking our Winter Veil plunder!  Get 'em!",12,0,100,0,0,0,11398,0,"Dark Iron Kidnapper"),
(@ID,0,2,"These land lubbers are here for the reindeer!  Give 'em the shank!",12,0,100,0,0,0,11399,0,"Dark Iron Kidnapper"),
(@ID,0,3,"It's a rescue attempt!  Let no one escape!",12,0,100,0,0,0,11400,0,"Dark Iron Kidnapper"),
(@ID,0,4,"Let me give you my regards for Greatfather Winter, scum...",12,0,100,0,0,0,11401,0,"Dark Iron Kidnapper"),
(@ID,0,5,"Humbug!  Die!",12,0,100,0,0,0,11402,0,"Dark Iron Kidnapper"),
(@ID,0,6,"It's a rescue attempt!  Slay them all!",12,0,100,0,0,0,11403,0,"Dark Iron Kidnapper"),
(@ID,0,7,"The only thing Metzen is going to be doing this Winter Veil is roasting on a spit!",12,0,100,0,0,0,11404,0,"Dark Iron Kidnapper");
