DELETE FROM `event_scripts` WHERE `id` IN (3201,3202,3203,3204);
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` IN (149025,149030,149031,149032);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (149025,149030,149031,149032) AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (14902500,14903000,14903100,14903200) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(149025,1,0,0,71,0,100,0,3201,0,0,0,0,80,14902500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentry Brazier - On Event 3201 Inform - Run Script"),
(149030,1,0,0,71,0,100,0,3202,0,0,0,0,80,14903000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentry Brazier - On Event 3202 Inform - Run Script"),
(149031,1,0,0,71,0,100,0,3203,0,0,0,0,80,14903100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentry Brazier - On Event 3203 Inform - Run Script"),
(149032,1,0,0,71,0,100,0,3204,0,0,0,0,80,14903200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentry Brazier - On Event 3204 Inform - Run Script"),

(14902500,9,0,0,0,0,100,0,2000,2000,0,0,0,70,600,0,0,0,0,0,15,149020,50,0,0,0,0,0,0,"Sentry Brazier - On Script - Respawn Closest Gameobject 'Tower Fire'"),
(14902500,9,1,0,0,0,100,0,0,0,0,0,0,70,600,0,0,0,0,0,15,149022,50,0,0,0,0,0,0,"Sentry Brazier - On Script - Respawn Closest Gameobject 'Tower Smoke'"),
(14903000,9,0,0,0,0,100,0,2000,2000,0,0,0,70,600,0,0,0,0,0,15,149017,50,0,0,0,0,0,0,"Sentry Brazier - On Script - Respawn Closest Gameobject 'Tower Fire'"),
(14903000,9,1,0,0,0,100,0,0,0,0,0,0,70,600,0,0,0,0,0,15,149018,50,0,0,0,0,0,0,"Sentry Brazier - On Script - Respawn Closest Gameobject 'Tower Smoke'"),
(14903100,9,0,0,0,0,100,0,2000,2000,0,0,0,70,600,0,0,0,0,0,15,149019,50,0,0,0,0,0,0,"Sentry Brazier - On Script - Respawn Closest Gameobject 'Tower Fire'"),
(14903100,9,1,0,0,0,100,0,0,0,0,0,0,70,600,0,0,0,0,0,15,149021,50,0,0,0,0,0,0,"Sentry Brazier - On Script - Respawn Closest Gameobject 'Tower Smoke'"),
(14903200,9,0,0,0,0,100,0,2000,2000,0,0,0,70,600,0,0,0,0,0,15,148996,50,0,0,0,0,0,0,"Sentry Brazier - On Script - Respawn Closest Gameobject 'Tower Fire'"),
(14903200,9,1,0,0,0,100,0,0,0,0,0,0,70,600,0,0,0,0,0,15,148997,50,0,0,0,0,0,0,"Sentry Brazier - On Script - Respawn Closest Gameobject 'Tower Smoke'");
