-- Thistlefur Avenger casts Vengeance after Thistlefur Death spellhit
-- Apply corrections based on ACID's (3.3.0 Official Data)
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 3921 AND 3926 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3921,0,0,0,1,0,100,1,3000,3000,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thistlefur Ursa - Out of Combat - Cast 'Battle Stance' (No Repeat)"),
(3921,0,1,0,0,0,100,0,9000,15000,23900,38400,0,11,25712,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Thistlefur Ursa - In Combat - Cast 'Heroic Strike'"),
(3921,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Thistlefur Ursa - Between 0-15% Health - Flee For Assist (No Repeat)"),

(3922,0,0,0,0,0,100,0,4200,16800,48800,65500,0,11,6274,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thistlefur Totemic - In Combat - Cast 'Healing Ward'"),
(3922,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Thistlefur Totemic - Between 0-15% Health - Flee For Assist (No Repeat)"),

(3923,0,0,0,2,0,100,0,0,30,11200,21500,0,11,3490,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thistlefur Den Watcher - Between 0-30% Health - Cast 'Frenzied Rage'"),
(3923,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Thistlefur Den Watcher - Between 0-15% Health - Flee For Assist (No Repeat)"),

(3924,0,0,0,0,0,100,0,3200,8000,30500,45200,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thistlefur Shaman - In Combat - Cast Bloodlust"),
(3924,0,1,0,74,0,100,0,0,60,19500,35500,40,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Thistlefur Shaman - On Friendly Between 0-60% Health - Cast 'Healing Wave'"),
(3924,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Thistlefur Shaman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(3924,0,3,0,6,0,100,0,0,0,0,0,0,11,8603,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thistlefur Shaman - On Death - Cast 'Thistlefur Death'"),

(3925,0,0,0,2,0,100,1,0,30,0,0,0,11,8602,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thistlefur Avenger - Between 0-30% Health - Cast 'Vengeance' (No Repeat)"),
(3925,0,1,2,8,0,100,0,8603,0,0,0,0,11,8602,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thistlefur Avenger - On Spellhit 'Thistlefur Death' - Cast Vengeance"),
(3925,0,2,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thistlefur Avenger - On Link - Say Line 0"),
(3925,0,3,0,6,0,100,0,0,0,0,0,0,11,8603,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thistlefur Avenger - On Death - Cast 'Thistlefur Death'"),

(3926,0,0,0,0,0,100,0,0,0,2300,2800,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Thistlefur Pathfinder - In Combat CMC - Cast 'Shoot'"),
(3926,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 0-15% Health - Flee For Assist (No Repeat)"),
(3926,0,2,0,6,0,100,0,0,0,0,0,0,11,8603,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thistlefur Pathfinder - On Death - Cast 'Thistlefur Death'");

-- Migrate auras
UPDATE `creature_addon` SET `auras` = "6813" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` BETWEEN 3921 AND 3926);
UPDATE `creature_template_addon` SET `auras` = "6813" WHERE `entry` IN (3921,3923,3924);
DELETE FROM `creature_template_addon` WHERE `entry` IN (3922,3925,3926);
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(3922,"6813"),
(3925,"6813"),
(3926,"6813");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 8603;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,8603,0,0,31,0,3,3925,0,0,0,0,"","Group 0: Spell 'Thistlefur Death' (Effect 0) targets creature 'Thistlefur Avenger'");
