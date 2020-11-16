--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 25401 AND `SourceId` = 0;
UPDATE `creature_template` SET `speed_run` = 1, `unit_flags` = 256 WHERE `entry` = 25401;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` BETWEEN 25402 AND 25405;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 25401 AND 25405 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2540100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25401,0,0,0,63,0,100,0,0,0,0,0,0,80,2540100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Just Created - Run Script"),

(2540100,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Script - Say Line 0"),
(2540100,9,1,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Script - Say Line 1"),
(2540100,9,2,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Script - Say Line 2"),
(2540100,9,3,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Script - Say Line 3"),
(2540100,9,4,0,0,0,100,0,1000,1000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Script - Say Line 4"),
(2540100,9,5,0,0,0,100,0,1000,1000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Script - Say Line 5"),
(2540100,9,6,0,0,0,100,0,1000,1000,0,0,0,11,45502,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seaforium Depth Charge - On Script - Cast 'Seaforium Depth Charge Explosion'"),

(25402,0,0,0,8,0,100,0,45502,0,0,0,0,11,45505,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nerub'ar Sinkhole (South) - On Spellhit 'Seaforium Depth Charge Explosion' - Cast 'Nerub'ar Sinkhole Credit (SW)'"),
(25403,0,0,0,8,0,100,0,45502,0,0,0,0,11,45507,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nerub'ar Sinkhole (East) - On Spellhit 'Seaforium Depth Charge Explosion' - Cast 'Nerub'ar Sinkhole Credit (SE)'"),
(25404,0,0,0,8,0,100,0,45502,0,0,0,0,11,45509,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nerub'ar Sinkhole (West) - On Spellhit 'Seaforium Depth Charge Explosion' - Cast 'Nerub'ar Sinkhole Credit (NW)'"),
(25405,0,0,0,8,0,100,0,45502,0,0,0,0,11,45511,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nerub'ar Sinkhole (North) - On Spellhit 'Seaforium Depth Charge Explosion' - Cast 'Nerub'ar Sinkhole Credit (NE)'");

DELETE FROM `spell_scripts` WHERE `id` IN (45505,45507,45509,45511);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`Comment`) VALUES
(45505,0,0,15,45506,3,0,0,0,0,0,"Nerub'ar Sinkhole Credit (SW) - On Effect Hit (Dummy) - Target Cast 'Nerub'ar Sinkhole Credit (SW)'"),
(45507,0,0,15,45508,3,0,0,0,0,0,"Nerub'ar Sinkhole Credit (SE) - On Effect Hit (Dummy) - Target Cast 'Nerub'ar Sinkhole Credit (SE)'"),
(45509,0,0,15,45510,3,0,0,0,0,0,"Nerub'ar Sinkhole Credit (NW) - On Effect Hit (Dummy) - Target Cast 'Nerub'ar Sinkhole Credit (NW)'"),
(45511,0,0,15,45512,3,0,0,0,0,0,"Nerub'ar Sinkhole Credit (NE) - On Effect Hit (Dummy) - Target Cast 'Nerub'ar Sinkhole Credit (NE)'"),
(45505,0,0,18,100,0,0,0,0,0,0,"Nerub'ar Sinkhole Credit (SW) - On Effect Hit (Dummy) - Target Despawn"),
(45507,0,0,18,100,0,0,0,0,0,0,"Nerub'ar Sinkhole Credit (SE) - On Effect Hit (Dummy) - Target Despawn"),
(45509,0,0,18,100,0,0,0,0,0,0,"Nerub'ar Sinkhole Credit (NW) - On Effect Hit (Dummy) - Target Despawn"),
(45511,0,0,18,100,0,0,0,0,0,0,"Nerub'ar Sinkhole Credit (NE) - On Effect Hit (Dummy) - Target Despawn");
