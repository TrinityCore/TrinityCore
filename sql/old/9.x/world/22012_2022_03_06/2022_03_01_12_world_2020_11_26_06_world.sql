-- Texts for pooled Eredar Soul-Eater & Deathbringer
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-52356,-213224) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-52356,0,0,0,1,0,100,0,30000,30000,120000,180000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Eredar Soul-Eater - Out of Combat - Say Line 0"),
(-52356,0,1,0,0,0,100,2,9000,12000,15000,17000,0,11,36786,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Eredar Soul-Eater - In Combat - Cast 'Soul Chill' (Normal Dungeon)"),
(-52356,0,2,0,0,0,100,4,9000,12000,15000,17000,0,11,38843,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Eredar Soul-Eater - In Combat - Cast 'Soul Chill' (Heroic Dungeon)"),
(-52356,0,3,0,0,0,100,0,15000,17000,14000,21000,0,11,36778,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Eredar Soul-Eater - In Combat - Cast 'Soul Steal'"),
(-52356,0,4,0,31,0,100,0,36778,0,0,0,0,11,36782,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Eredar Soul-Eater - On Target Spellhit 'Soul Steal' - Cast 'Soul Steal'"),

(-213224,0,0,0,1,0,100,0,30000,30000,120000,180000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Eredar Deathbringer - Out of Combat - Say Line 0"),
(-213224,0,1,0,0,0,100,2,8000,11000,10000,16000,0,11,36787,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Eredar Deathbringer - In Combat - Cast 'Forceful Cleave' (Normal Dungeon)"),
(-213224,0,2,0,0,0,100,4,8000,11000,10000,16000,0,11,38846,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Eredar Deathbringer - In Combat - Cast 'Forceful Cleave' (Heroic Dungeon)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (20879,20880);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
-- Emote for 1 & 2 guessed
(20879,0,0,"My portal creation spells do not appear to work here. The damned naaru constructed this place well.",12,0,100,5,0,0,19129,0,"Eredar Soul-Eater"),
(20879,0,1,"Our time is finally at hand. The naaru and their allies will learn the true meaning of suffering.",12,0,100,5,0,0,19130,0,"Eredar Soul-Eater"),
(20879,0,2,"Our imprisonment was intolerable. The sooner we can leave this accursed place, the better.",12,0,100,5,0,0,19131,0,"Eredar Soul-Eater"),
(20880,0,0,"My portal creation spells do not appear to work here. The damned naaru constructed this place well.",12,0,100,5,0,0,19129,0,"Eredar Deathbringer"),
(20880,0,1,"Our time is finally at hand. The naaru and their allies will learn the true meaning of suffering.",12,0,100,5,0,0,19130,0,"Eredar Deathbringer"),
(20880,0,2,"Our imprisonment was intolerable. The sooner we can leave this accursed place, the better.",12,0,100,5,0,0,19131,0,"Eredar Deathbringer");

-- Waypoints for Unbound Devastator & Spiteful Temptress
UPDATE `creature` SET `position_x` = 199.71545, `position_y` = 135.69438, `position_z` = 22.45939 WHERE `guid` = 79532 AND `id` = 20881;
UPDATE `creature` SET `position_x` = 189.29553, `position_y` = 157.5333, `position_z` = 22.44115 WHERE `guid` = 79534 AND `id` = 20883;
DELETE FROM `waypoint_data` WHERE `id` IN (795320,795340);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(795320,1,199.71545,135.69438,22.45939,0,0,0,0,0,0),
(795320,2,188.94356,135.94778,22.441149,0,0,0,0,0,0),
(795320,3,178.95024,136.18616,22.441147,0,40000,0,0,0,0), -- random movement (10 yards)
(795320,4,193.13338,134.66946,22.571707,0,0,0,0,0,0),
(795320,5,199.70131,134.85092,22.437534,0,0,0,0,0,0),
(795320,6,200.01999,143.80635,22.404247,0,30000,0,0,0,0), -- random movement (4 yards)
(795340,1,189.29553,157.5333,22.44115,0,0,0,0,0,0),
(795340,2,198.717,156.83224,22.364504,0,30000,0,0,0,0), -- random movement (4 yards)
(795340,3,189.48445,157.87857,22.44115,0,0,0,0,0,0),
(795340,4,180.3669,158.23933,22.441147,0,0,0,0,0,0),
(795340,5,180.26875,151.43074,22.441147,0,40000,0,0,0,0), -- random movement (10 yards)
(795340,6,179.83174,157.97197,22.441147,0,0,0,0,0,0);

-- Standardize respawn time
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `id` IN (20870,20885,20886,20904);
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` = 21186;
