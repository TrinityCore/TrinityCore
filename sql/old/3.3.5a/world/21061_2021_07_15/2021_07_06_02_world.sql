--
UPDATE `creature` SET `position_x` = 9494.6796875, `position_y` = -7332.8515625, `position_z` = 28.1516876220703125, `orientation` = 6.143558979034423828, `VerifiedBuild` = 12340 WHERE `id` = 25148;
UPDATE `creature` SET `position_x` = 9492.2041015625, `position_y` = -7327.0458984375, `position_z` = 28.15168190002441406, `orientation` = 1.239183783531188964, `VerifiedBuild` = 12340 WHERE `id` = 25149;
UPDATE `creature` SET `position_x` = 9492.4462890625, `position_y` = -7334.36474609375, `position_z` = 28.15168952941894531, `orientation` = 5.113814830780029296, `VerifiedBuild` = 12340 WHERE `id` = 25150;
UPDATE `creature` SET `position_x` = 9495.0849609375, `position_y` = -7330.59033203125, `position_z` = 28.15167236328125, `orientation` = 0.03490658476948738, `VerifiedBuild` = 12340 WHERE `id` = 25151;
UPDATE `creature` SET `position_x` = 9494.4560546875, `position_y` = -7328.3203125, `position_z` = 28.15168380737304687, `orientation` = 0.802851438522338867, `VerifiedBuild` = 12340 WHERE `id` = 25152;

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (25148,25149,25150,25151,25152);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25148,25149,25150,25151,25152) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2514800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- For future: they probably responds to various emotes so try to use same scripts from guards if they're same
(25148,0,0,0,22,0,100,0,101,0,0,0,0,80,2514800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bergrisst - On Received Emote 'Wave' - Run Script"),
(25149,0,0,0,22,0,100,0,101,0,0,0,0,80,2514800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Chief Thunder-Skins - On Received Emote 'Wave' - Run Script"),
(25150,0,0,0,22,0,100,0,101,0,0,0,0,80,2514800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mai'Kyl - On Received Emote 'Wave' - Run Script"),
(25151,0,0,0,22,0,100,0,101,0,0,0,0,80,2514800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Samuro - On Received Emote 'Wave' - Run Script"),
(25152,0,0,0,22,0,100,0,101,0,0,0,0,80,2514800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sig Nicious - On Received Emote 'Wave' - Run Script"),

(2514800,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bergrisst - On Script - Set Orientation Invoker"),
(2514800,9,1,0,0,0,100,0,1000,1000,0,0,0,5,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bergrisst - On Script - Play Emote 3"),
(2514800,9,2,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bergrisst - On Script - Set Orientation Home Position");
