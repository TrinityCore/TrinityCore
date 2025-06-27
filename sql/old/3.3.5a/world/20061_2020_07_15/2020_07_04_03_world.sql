-- https://www.youtube.com/watch?v=NHHkFiHvxWA https://youtu.be/NHHkFiHvxWA?t=349
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4501,4502,4503) AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4501,2,0,1,46,0,100,0,4501,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Southshore) - On Trigger - Store Targetlist"),
(4501,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,20365,0,0,0,0,0,0,0,"Areatrigger (Southshore) - On Link - Send Target 1 (Bartolo Ginsetti)"),
(4501,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,20365,0,0,0,0,0,0,0,"Areatrigger (Southshore) - On Link - Set Data 0 1 (Bartolo Ginsetti)"),
(4502,2,0,1,46,0,100,0,4502,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Southshore) - On Trigger - Store Targetlist"),
(4502,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,20432,0,0,0,0,0,0,0,"Areatrigger (Southshore) - On Link - Send Target 1 (Beggar)"),
(4502,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,20432,0,0,0,0,0,0,0,"Areatrigger (Southshore) - On Link - Set Data 0 1 (Beggar)"),
(4503,2,0,1,46,0,100,0,4503,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Southshore) - On Trigger - Store Targetlist"),
(4503,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,20432,0,0,0,0,0,0,0,"Areatrigger (Southshore) - On Link - Send Target 1 (Beggar)"),
(4503,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,20432,0,0,0,0,0,0,0,"Areatrigger (Southshore) - On Link - Set Data 0 1 (Beggar)");

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4501,4502,4503);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4501,"SmartTrigger"),
(4502,"SmartTrigger"),
(4503,"SmartTrigger");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (20365,20432);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20365,20432) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2036500 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20365,0,0,0,38,0,100,0,0,1,60000,60000,0,80,2036500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bartolo Ginsetti - On Data Set 0 1 - Run Script"),
(2036500,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bartolo Ginsetti - On Script - Say Line 0"),
(2036500,9,1,0,0,0,100,0,4000,4000,0,0,0,5,23,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bartolo Ginsetti - On Script - Play Emote 23"),
(2036500,9,2,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bartolo Ginsetti - On Script - Say Line 1"),
(20432,0,0,0,38,0,100,0,0,1,60000,60000,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Beggar - On Data Set 0 1 - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (20365,20432);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(20365,0,0,"You there! Yes, you, peasant $g boy:girl;. Come quickly, I must tell you something... I must tell you about my greatness, lest such things are lost in the void!",12,0,100,25,0,0,18137,0,"Bartolo Ginsetti"),
(20365,1,0,"Ooooh, YAH! Gaze upon my rippling musculature. Bask in the glow of my physique.",12,0,100,0,0,0,18138,0,"Bartolo Ginsetti"),
(20432,0,0,"Spare a silver, friend?",12,0,100,20,0,0,18148,0,"Beggar"),
(20432,0,1,"Spare a copper? You won't need it soon. The end of days nears...",12,0,100,20,0,0,18149,0,"Beggar"),
(20432,0,2,"Got any food?",12,0,100,20,0,0,18150,0,"Beggar"),
(20432,0,3,"Please, $g sir:madam;, I have three hungry children! Did I say three? TEN HUNGRY CHILDREN!",12,0,100,20,0,0,18151,0,"Beggar"),
(20432,0,4,"Psst... Spare a copper for some grog?",12,0,100,20,0,0,18152,0,"Beggar"),
(20432,0,5,"Will work for food...",12,0,100,20,0,0,18153,0,"Beggar"),
(20432,0,6,"Allow me to shine your shoes! Only one copper for the service!",12,0,100,20,0,0,18154,0,"Beggar");
