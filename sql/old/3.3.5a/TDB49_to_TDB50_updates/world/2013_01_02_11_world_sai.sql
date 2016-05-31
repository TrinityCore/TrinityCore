UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (176346,176349,176350,176351,176352,176353);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (176346,176349,176350,176351,176352,176353) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (17634600,17634900,17635000,17635100,17635200,17635300) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(176346,1,0,0,70,0,100,0,2,0,0,0,80,17634600,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Market Row Postbox - On Activate - Start Script'),
(176349,1,0,0,70,0,100,0,2,0,0,0,80,17634900,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusaders Square Postbox - On Activate - Start Script'),
(176350,1,0,0,70,0,100,0,2,0,0,0,80,17635000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Festival Lane Postbox - On Activate - Start Script'),
(176351,1,0,0,70,0,100,0,2,0,0,0,80,17635100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Elders Square Postbox - On Activate - Start Script'),
(176352,1,0,0,70,0,100,0,2,0,0,0,80,17635200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kings Square Postbox - On Activate - Start Script'),
(176353,1,0,0,70,0,100,0,2,0,0,0,80,17635300,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fras Siabis Postbox - On Activate - Start Script'),
-- Market Row Postbox Script
(17634600,9,0,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3675.35,-3395.92,132.86,5.83,'MR Postbox Script - After 2s - Summon Undead Postman'),
(17634600,9,1,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3679.93,-3408.58,133.18,1.04,'MR Postbox Script - After 2s - Summon Undead Postman'),
(17634600,9,2,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3687.89,-3410.59,133.04,1.64,'MR Postbox Script - After 2s - Summon Undead Postman'),
-- Crusaders' Square Postbox Script
(17634900,9,0,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3664.55,-3176.47,126.42,2.20,'CS Postbox Script - After 2s - Summon Undead Postman'),
(17634900,9,1,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3656.82,-3160.63,129.03,4.84,'CS Postbox Script - After 2s - Summon Undead Postman'),
(17634900,9,2,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3644.62,-3168.25,128.52,5.93,'CS Postbox Script - After 2s - Summon Undead Postman'),
-- Festival Lane Postbox Script
(17635000,9,0,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3651.67,-3477.88,138.05,5.59,'FL Postbox Script - After 2s - Summon Undead Postman'),
(17635000,9,1,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3657.14,-3475.36,138.70,4.91,'FL Postbox Script - After 2s - Summon Undead Postman'),
(17635000,9,2,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3669.61,-3478.49,137.49,3.39,'FL Postbox Script - After 2s - Summon Undead Postman'),
-- Elders' Square Postbox Script
(17635100,9,0,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3659.46,-3634.96,138.33,1.28,'ES Postbox Script - After 2s - Summon Undead Postman'),
(17635100,9,1,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3656.25,-3635.08,138.36,1.02,'ES Postbox Script - After 2s - Summon Undead Postman'),
(17635100,9,2,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3661.24,-3621.00,138.40,3.58,'ES Postbox Script - After 2s - Summon Undead Postman'),
-- King's Square Postbox Script
(17635200,9,0,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3568.50,-3356.91,131.06,2.07,'KS Postbox Script - After 2s - Summon Undead Postman'),
(17635200,9,1,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3570.91,-3351.01,130.57,2.71,'KS Postbox Script - After 2s - Summon Undead Postman'),
(17635200,9,2,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3562.79,-3353.38,130.78,0.81,'KS Postbox Script - After 2s - Summon Undead Postman'),
-- Fras Siabi's Postbox Script
(17635300,9,0,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3493.00,-3300.28,130.47,0.07,'FS Postbox Script - After 2s - Summon Undead Postman'),
(17635300,9,1,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3503.16,-3294.90,131.09,4.28,'FS Postbox Script - After 2s - Summon Undead Postman'),
(17635300,9,2,0,0,0,100,0,2000,2000,0,0,12,11142,1,300000,0,1,0,8,0,0,0,3496.26,-3295.40,130.98,5.34,'FS Postbox Script - After 2s - Summon Undead Postman');
