-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2667800) AND `source_type`=9 AND `id`=6;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26678) AND `source_type`=0 AND `id` IN (3,4);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26676) AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2667800,9,6,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Quest Credit"),
(26678,0,3,0,54,0,100,0,0,0,0,0,84,1,0,0,0,0,0,23,0,0,0,0,0,0,0,"Warsong Battle Standard - Just Summoned - Simple talk"),
(26678,0,4,0,6,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Battle Standard - On death - Simple talk"),
(26676,0,1,0,54,0,60,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Invader - Just Summoned - Simple talk"),
(26676,0,2,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Invader - On evade - despawn");

DELETE FROM `creature_text` WHERE `CreatureID` IN (26676,26678);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(26676,0,0,"Anub'ar fear nothing, mortal...",12,0,100,0,0,0,25895,0,'Anubar Invader'),
(26676,0,1,"A fine meal you will make...",12,0,100,0,0,0,25896,0,'Anubar Invader'),
(26676,0,2,"Anub'arak may have uses for your carcass...",12,0,100,0,0,0,25897,0,'Anubar Invader'),
(26676,0,3,"The feast has arrived! DIE!",12,0,100,0,0,0,25898,0,'Anubar Invader'),
(26678,0,0,"The Anub'ar have destroyed the %s!",16,0,100,0,0,0,25899,0,'Warsong Battle Standard'),
(26678,1,0,"Come, cowards! FACE THE HORDE!",12,0,100,0,0,0,25888,0,'Warsong Battle Standard'),
(26678,1,1,"Do you that dare challenge the Horde? Then come...",12,0,100,0,0,0,25889,0,'Warsong Battle Standard'),
(26678,1,2,"I will crush you all! For the Horde!",12,0,100,0,0,0,25890,0,'Warsong Battle Standard'),
(26678,1,3,"Come! Come face your doom!",12,0,100,0,0,0,25891,0,'Warsong Battle Standard'),
(26678,1,4,"Leave this place or I will thrash you soundly!",12,0,100,0,0,0,25892,0,'Warsong Battle Standard'),
(26678,1,5,"Show yourselves so that I may crack your insectoid skeletons with my bare hands!",12,0,100,0,0,0,25893,0,'Warsong Battle Standard'),
(26678,1,6,"Hearty beatings will be dispensed in the name of the Horde!",12,0,100,0,0,0,25894,0,'Warsong Battle Standard');
