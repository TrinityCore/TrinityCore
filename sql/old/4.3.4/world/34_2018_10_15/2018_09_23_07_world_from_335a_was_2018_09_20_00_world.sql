-- Quest: Springing the Trap (11969)

SET @CGUID             := 86530;
SET @SOLDIER           := 24769;
SET @KERISTRASZA       := 26237;
SET @SARAGOSA          := 26299;
SET @MALYGOS           := 26310;
SET @COLDARRA_INVISMAN := 26373;
SET @MALYGOS2          := 29655;
SET @INVISMAN          := 33087;
SET @SIGNALFIRE        := 194151;

UPDATE `creature_template` SET `speed_walk`=3.6, `speed_run`=2.857143, `unit_flags`=832 WHERE `entry`=@KERISTRASZA;
UPDATE `creature_template` SET `speed_walk`=2, `speed_run`=1.714286, `unit_flags`=768 WHERE `entry`=@SARAGOSA;
UPDATE `creature_template` SET `speed_walk`=8, `speed_run`=4.714286, `unit_flags`=832 WHERE `entry`=@MALYGOS;

/*
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (@SOLDIER,@KERISTRASZA,@MALYGOS);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(@SOLDIER,0,0,1,0),
(@KERISTRASZA,1,0,2,0),
(@MALYGOS,0,0,1,0);
*/

DELETE FROM `creature_template_addon` WHERE `entry` IN (@KERISTRASZA,@SARAGOSA,@MALYGOS,@SOLDIER);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES
(@KERISTRASZA,50331648,1,''),
(@SARAGOSA,0,1,'29266'),
(@MALYGOS,50331648,1,'65137'),
(@SOLDIER,50331648,1,'65185');

DELETE FROM `creature` WHERE `guid`= @CGUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@CGUID, @INVISMAN, 571, 1, 1, 15435, 0, 4062.013, 7108.927, 170.0696, 0, 300, 0, 0);

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (@INVISMAN);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@KERISTRASZA,@SARAGOSA,@MALYGOS,@COLDARRA_INVISMAN,@MALYGOS2,@INVISMAN,@SOLDIER);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@KERISTRASZA,@SARAGOSA,@MALYGOS,@COLDARRA_INVISMAN,@MALYGOS2,@INVISMAN,@SOLDIER) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@KERISTRASZA*100+0,@KERISTRASZA*100+1,@KERISTRASZA*100+2,@MALYGOS*100,@MALYGOS2*100,@INVISMAN*100,@MALYGOS*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KERISTRASZA,0,0,0,38,0,100,0,0,1,0,0,53,0,@KERISTRASZA,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza - On data set - Start WP movement'),
(@KERISTRASZA,0,1,2,40,0,100,0,4,@KERISTRASZA,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza - On WP 4 reached - Pause WP movement 20 seconds'),
(@KERISTRASZA,0,2,0,61,0,100,0,0,0,0,0,80,@KERISTRASZA*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza - On WP 4 reached - Start script 0'),
(@KERISTRASZA,0,3,4,40,0,100,0,6,0,0,0,12,@SARAGOSA,3,40000,0,0,0,8,0,0,0,4032.4,7086.208,166.6852,4.328416, 'Keristrasza - On WP 6 reached - Summon Corpse of Saragosa'),
(@KERISTRASZA,0,4,5,61,0,100,0,0,0,0,0,55,40000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza - On WP 6 reached - Pause WP movement 40 seconds'),
(@KERISTRASZA,0,5,0,61,0,100,0,0,0,0,0,80,@KERISTRASZA*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza - On WP 6 reached - Start script 1'),
(@KERISTRASZA,0,6,0,38,0,100,0,0,2,0,0,69,7,0,0,0,0,0,8,0,0,0,3782.786, 6543.079, 174.591, 0.709225, 'Keristrasza - On data 0 1 set - Move to position'),
(@KERISTRASZA,0,7,0,34,0,100,0,0,7,0,0,80,@KERISTRASZA*100+2,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza - On movement inform - Run script'),
(@KERISTRASZA,0,8,0,8,0,100,0,46882,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza - On spellhit Ice block - Say line'),
(@KERISTRASZA,0,9,0,8,0,100,0,46902,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza - On spellhit Malygos Teleport - Despawn after 1 second'),
(@SARAGOSA,0,0,0,38,0,100,0,0,1,0,0,11,42726,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Corpse of Saragosa - On data 0 1 set - Spellcast Cosmetic - Immolation (Whole Body)'),
(@MALYGOS,0,0,0,1,0,100,1,65000,65000,0,0,53,0,@MALYGOS,0,0,0,0,1,0,0,0,0,0,0,0, 'Maylgos - On LOS OOC - Start WP movement'),
(@MALYGOS,0,2,0,40,0,100,0,10,@MALYGOS,0,0,80,@MALYGOS*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Maylgos - On WP 10 reached - Run script'),
(@MALYGOS,0,3,0,54,0,100,0,0,0,0,0,80,@MALYGOS*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Maylgos - just summoned - Run script'),
(@MALYGOS*100+1,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Malygos script - Set active'),
(@MALYGOS*100+1,9,1,0,0,0,100,0,0,0,0,0,12,@SOLDIER,3,65000,0,0,0,1,0,0,0,0,0,0,0, 'Malygos script - Say line'),
(@MALYGOS*100+1,9,2,0,0,0,100,0,1500,1500,0,0,45,0,1,0,0,0,0,19,@SOLDIER,100,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz'' Spark - Set data 0 1 Keristrasza'),
(@MALYGOS*100+1,9,3,0,0,0,100,0,1500,1500,0,0,12,@SOLDIER,3,65000,0,0,0,1,0,0,0,0,0,0,0, 'Malygos script - Say line'),
(@MALYGOS*100+1,9,4,0,0,0,100,0,1500,1500,0,0,45,0,2,0,0,0,0,19,@SOLDIER,100,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz'' Spark - Set data 0 1 Keristrasza'),
(@MALYGOS*100+1,9,5,0,0,0,100,0,1500,1500,0,0,12,@SOLDIER,3,65000,0,0,0,1,0,0,0,0,0,0,0, 'Malygos script - Say line'),
(@MALYGOS*100+1,9,6,0,0,0,100,0,1500,1500,0,0,45,0,3,0,0,0,0,19,@SOLDIER,100,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz'' Spark - Set data 0 1 Keristrasza'),
(@SOLDIER,0,0,0,63,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'SOLDIER - Just created - Set active'),
(@SOLDIER,0,1,0,38,0,100,0,0,1,0,0,53,1,@SOLDIER*10,1,0,0,0,1,0,0,0,0,0,0,0, 'SOLDIER - On data 0 1 set - Start wp'),
(@SOLDIER,0,2,0,38,0,100,0,0,2,0,0,53,1,@SOLDIER*10+1,1,0,0,0,1,0,0,0,0,0,0,0, 'SOLDIER - On data 0 2 set - Start wp'),
(@SOLDIER,0,3,0,38,0,100,0,0,3,0,0,53,1,@SOLDIER*10+2,1,0,0,0,1,0,0,0,0,0,0,0, 'SOLDIER - On data 0 3 set - Start wp'),
(@MALYGOS*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Malygos script - Say line'),
(@MALYGOS*100,9,1,0,0,0,100,0,0,0,0,0,28,65137,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Maylgos - On LOS OOC - Remove aura Malygos Periodic Aura'),
(@MALYGOS*100,9,2,0,0,0,100,0,7000,7000,0,0,66,0,0,0,0,0,0,19,@KERISTRASZA,50,0,0,0,0,0, 'Malygos script - Turn to'),
(@MALYGOS*100,9,3,0,0,0,100,0,0,0,0,0,11,46886,0,0,0,0,0,19,@KERISTRASZA,50,0,0,0,0,0, 'Malygos script - Spellcast Frost Breath'),
(@MALYGOS*100,9,4,0,0,0,100,0,500,500,0,0,85,46882,0,0,0,0,0,19,@KERISTRASZA,50,0,0,0,0,0, 'Malygos script - Self cast Ice block'),
(@MALYGOS*100,9,5,0,0,0,100,0,7000,7000,0,0,11,46902,0,0,0,0,0,19,@KERISTRASZA,0,0,0,0,0,0, 'Malygos script - Spellcast Malygos Teleport'),
(@MALYGOS*100,9,6,0,0,0,100,0,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Malygos script - Despawn'),
(@COLDARRA_INVISMAN,0,0,1,54,0,100,0,0,0,0,0,12,@KERISTRASZA,8,0,0,0,0,8,0,0,0,3755.632, 6530.289, 194.888, 0.129601, 'Coldarra Spell FX InvisMan - On LOS OOC - Summon Keristrasza'),
(@COLDARRA_INVISMAN,0,1,2,61,0,100,0,0,0,0,0,45,0,2,0,0,0,0,19,@KERISTRASZA,50,0,0,0,0,0, 'Coldarra Spell FX InvisMan - On LOS OOC - Send data 0 2 Keristrasza'),
(@COLDARRA_INVISMAN,0,2,0,61,0,100,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coldarra Spell FX InvisMan - On LOS OOC - Send data 0 2 Keristrasza'),
(@MALYGOS2,0,0,0,38,0,100,0,0,1,0,0,80,@MALYGOS2*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Maylgos - On data 0 1 set - Run script'),
(@MALYGOS2*100,9,0,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Malygos script - Say line'),
(@INVISMAN,0,0,0,8,0,100,0,62272,0,70000,70000,80,@INVISMAN*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz'' Spark - Action list'),
(@INVISMAN*100,9,0,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz'' Spark - Store target'),
(@INVISMAN*100,9,1,0,0,0,100,0,0,0,0,0,12,@KERISTRASZA,8,60000,0,0,0,8,0,0,0,4098.674,7064.292,198.7698,0, 'Signal Fire Invisman - On spellhit Raelorasz'' Spark - Summon Keristrasza'),
(@INVISMAN*100,9,2,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@KERISTRASZA,100,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz'' Spark - Send targetlist'),
(@INVISMAN*100,9,3,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,20,@SIGNALFIRE,5,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz'' Spark - Activate object'),
(@INVISMAN*100,9,4,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@KERISTRASZA,100,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz'' Spark - Set data 0 1 Keristrasza'),
(@INVISMAN*100,9,5,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz - Set active'),
(@INVISMAN*100,9,6,0,0,0,100,0,69000,69000,0,0,9,0,0,0,0,0,0,20,@SIGNALFIRE,5,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz'' Spark - Activate object'),
(@INVISMAN*100,9,7,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Signal Fire Invisman - On spellhit Raelorasz - Set active'),
(@KERISTRASZA*100+0,9,0,0,0,0,100,0,0,0,0,0,91,2,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza script 2 - Remove unit_field_bytes1 (flying + hovering)'),
(@KERISTRASZA*100+0,9,1,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Keristrasza script 0 - Turn to'),
(@KERISTRASZA*100+0,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Keristrasza script 0 - Say line'),
(@KERISTRASZA*100+0,9,3,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza script 0 - Say line'),
(@KERISTRASZA*100+1,9,0,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza script 1 - Say line'),
(@KERISTRASZA*100+1,9,1,0,0,0,100,0,4000,4000,0,0,11,45852,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza script 1 - Spellcast Cosmetic - Dragon''s Breath'),
(@KERISTRASZA*100+1,9,2,0,0,0,100,0,3500,3500,0,0,45,0,1,0,0,0,0,19,@SARAGOSA,20,0,0,0,0,0, 'Keristrasza script 1 - Say line'),
(@KERISTRASZA*100+1,9,3,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza script 1 - Say line'),
(@KERISTRASZA*100+1,9,4,0,0,0,100,0,10000,10000,0,0,11,46853,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza script 1 - Spellcast Malygos in Coldarra'),
(@KERISTRASZA*100+1,9,5,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Keristrasza script 1 - Turn to'),
(@KERISTRASZA*100+1,9,6,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Keristrasza script 1 - Say line'),
(@KERISTRASZA*100+1,9,7,0,0,0,100,0,4000,4000,0,0,11,46813,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Keristrasza script 1 - Spellcast Taxi - Coldarra Ledge to Transitus Shield'),
(@KERISTRASZA*100+1,9,8,0,0,0,100,0,1000,1000,0,0,45,0,1,0,0,0,0,19,@MALYGOS2,20,0,0,0,0,0, 'Keristrasza script 1 - Set data 0 1 Malygos'),
(@KERISTRASZA*100+1,9,9,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza script 1 - Despawn'),
(@KERISTRASZA*100+2,9,0,0,0,0,100,0,0,0,0,0,91,2,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza script 2 - Remove unit_field_bytes1 (flying + hovering)'),
(@KERISTRASZA*100+2,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,21,30,0,0,0,0,0,0, 'Keristrasza script 2 - Turn to'),
(@KERISTRASZA*100+2,9,2,0,0,0,100,0,500,500,0,0,5,293,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Keristrasza script 2 - Play emote'),
(@KERISTRASZA*100+2,9,3,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,21,30,0,0,0,0,0,0, 'Keristrasza script 2 - Say line');

DELETE FROM `event_scripts` WHERE `id` IN (17497, 17500, 17499);
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(17497,0,8,26237,0,0,0,0,0,0),
(17497,0,10,@MALYGOS,130000,0,3767.673, 6843.96, 544.4875, 4.066617),
(17499,5,10,@COLDARRA_INVISMAN,5000,0,3791.796, 6545.934, 173.470032, 0);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-46813;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-46813,46814,0,'On spellfade Taxi - Coldarra Ledge to Transitus Shield - Spellcast Coldarra to Transitus');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=62272;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(0,62272,64,0,0,'Disable LOS for spell Raelorasz'' Spark');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (46886,46900,46902,62272);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,46886,0,0,31,0,3,@SOLDIER,0,0,'','Spell Frost Breath targets Red Dragon Soldier'),
(13,1,46886,0,1,31,0,3,@KERISTRASZA,0,0,'','Spell Frost Breath targets Keristrasza'),
(13,1,46900,0,0,31,0,3,@MALYGOS,0,0,'','Spell Dragon Fireball targets Malygos'),
(13,1,46902,0,0,31,0,3,@KERISTRASZA,0,0,'','Spell Malygos Teleport effect0 targets Keristrasza'),
(13,1,62272,0,0,31,0,3,@INVISMAN,0,0,'','Spell Raelorasz'' Spark targets Signal Fire Invisman');

DELETE FROM `creature_text` WHERE `CreatureID` IN (@KERISTRASZA,@MALYGOS,@MALYGOS2,@INVISMAN);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@KERISTRASZA,0,0,'Stay close to me, $n. I could not bear for any harm to come to you.',12,0,100,1,0,0,25474,'Keristrasza'),
(@KERISTRASZA,1,0,'MALYGOS!!',14,0,100,15,0,7274,25475,'Keristrasza'),
(@KERISTRASZA,2,0,'Come, Lord of Magic, and recover your precious consort....',14,0,100,1,0,0,25477,'Keristrasza'),
(@KERISTRASZA,3,0,'...what remains of her!',14,0,100,0,0,0,25478,'Keristrasza'),
(@KERISTRASZA,4,0,'Come, $n. Let us see the fruits of our efforts.',12,0,100,0,0,0,25479,'Keristrasza'),
(@KERISTRASZA,5,0,'Hurry, $n! Flee! Live to finish what we''ve begun here....',12,0,100,0,0,0,25491,'Keristrasza'),
(@KERISTRASZA,6,0,'Never!',14,0,100,0,0,0,25489,'Keristrasza'),
(@MALYGOS,0,0,'Keristrasza! You''ve bested my consort... and now YOU shall take her place!',14,0,100,0,0,0,25485,'Malygos'),
(@MALYGOS2,0,0,'Saragosa! What has become of you?',14,0,100,0,0,0,25480,'Malygos');

DELETE FROM `waypoints` WHERE `entry` IN (@KERISTRASZA,@MALYGOS,24769*10, 24769*10+1, 24769*10+2);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@KERISTRASZA, 1, 4098.674, 7064.292, 198.7698, 'Keristrasza'),
(@KERISTRASZA, 2, 4092.762, 7067.315, 193.3262, 'Keristrasza'),
(@KERISTRASZA, 3, 4079.077, 7074.162, 176.2149, 'Keristrasza'),
(@KERISTRASZA, 4, 4063.685, 7083.67, 167.8817, 'Keristrasza'),
(@KERISTRASZA, 5, 4045.307, 7083.389, 168.241, 'Keristrasza'),
(@KERISTRASZA, 6, 4040.892, 7083.875, 168.116, 'Keristrasza'),
(@MALYGOS, 1, 3736.729, 6813.358, 533.4736, 'Malygos'),
(@MALYGOS, 2, 3732.188, 6794.312, 487.0847, 'Malygos'),
(@MALYGOS, 3, 3730.688, 6769.336, 444.0849, 'Malygos'),
(@MALYGOS, 4, 3726.533, 6750.502, 398.3348, 'Malygos'),
(@MALYGOS, 5, 3725.144, 6735.662, 351.0848, 'Malygos'),
(@MALYGOS, 6, 3733.896, 6705.199, 312.0294, 'Malygos'),
(@MALYGOS, 7, 3735.563, 6692.039, 264.474, 'Malygos'),
(@MALYGOS, 8, 3739.076, 6675.249, 218.3628, 'Malygos'),
(@MALYGOS, 9, 3746.836, 6657.269, 186.8073, 'Malygos'),
(@MALYGOS,10, 3751.5, 6635.882, 186.8073, 'Malygos'),
(@MALYGOS,11, 3766.236, 6622.118, 186.8073, 'Malygos'),
(@MALYGOS,12, 3794.761, 6612.983, 186.8073, 'Malygos'),
(@MALYGOS,13, 3788.3405, 6580.367, 204.335, 'Malygos'),
(@MALYGOS,14, 3788.3405, 6580.367, 204.335, 'Malygos'),
(24769*10, 1,3780.585,6961.891,615.3891,'Red Dragon Soldier'),
(24769*10, 2,3781.443,6961.375,615.3891,'Red Dragon Soldier'),
(24769*10, 3,3788.726,6952.882,619.7848,'Red Dragon Soldier'),
(24769*10, 4,3809.698,6939.206,609.7292,'Red Dragon Soldier'),
(24769*10, 5,3829.648,6917.982,597.0071,'Red Dragon Soldier'),
(24769*10, 6,3845.798,6899.093,586.6738,'Red Dragon Soldier'),
(24769*10, 7,3864.757,6857.222,572.757,'Red Dragon Soldier'),
(24769*10, 8,3862.349,6824.601,561.4517,'Red Dragon Soldier'),
(24769*10, 9,3850.486,6797.143,559.7294,'Red Dragon Soldier'),
(24769*10,10,3828.732,6772.135,562.8682,'Red Dragon Soldier'),
(24769*10,11,3795.058,6761.407,568.9792,'Red Dragon Soldier'),
(24769*10,12,3760.513,6774.492,581.5349,'Red Dragon Soldier'),
(24769*10,13,3720.332,6799.233,597.9792,'Red Dragon Soldier'),
(24769*10,14,3697.16,6835.938,619.7848,'Red Dragon Soldier'),
(24769*10,15,3681.756,6872.03,619.7848,'Red Dragon Soldier'),
(24769*10,16,3672.802,6901.496,619.7848,'Red Dragon Soldier'),
(24769*10,17,3672.081,6921.473,619.7848,'Red Dragon Soldier'),
(24769*10,18,3675.869,6947.217,619.7848,'Red Dragon Soldier'),
(24769*10,19,3696.144,6973.719,619.7848,'Red Dragon Soldier'),
(24769*10,20,3723.596,6980.155,619.7848,'Red Dragon Soldier'),
(24769*10,21,3761.115,6971.517,619.7848,'Red Dragon Soldier'),
(24769*10,22,3788.726,6952.882,619.7848,'Red Dragon Soldier'),
(24769*10,23,3809.698,6939.206,609.7292,'Red Dragon Soldier'),
((24769*10+1), 1,3694.591,6905.624,588.2004,'Red Dragon Soldier'),
((24769*10+1), 2,3694.486,6904.629,588.2004,'Red Dragon Soldier'),
((24769*10+1), 3,3687.71,6887.773,599.449,'Red Dragon Soldier'),
((24769*10+1), 4,3681.292,6860.081,599.449,'Red Dragon Soldier'),
((24769*10+1), 5,3684.588,6828.854,601.2267,'Red Dragon Soldier'),
((24769*10+1), 6,3702.324,6800.028,602.0601,'Red Dragon Soldier'),
((24769*10+1), 7,3742.879,6774.088,612.5878,'Red Dragon Soldier'),
((24769*10+1), 8,3786.845,6777.308,626.338,'Red Dragon Soldier'),
((24769*10+1), 9,3803.426,6793.12,641.338,'Red Dragon Soldier'),
((24769*10+1),10,3818.26,6820.016,651.0602,'Red Dragon Soldier'),
((24769*10+1),11,3824.966,6848.016,656.3936,'Red Dragon Soldier'),
((24769*10+1),12,3813.837,6884.006,649.3936,'Red Dragon Soldier'),
((24769*10+1),13,3787.394,6910.689,636.1436,'Red Dragon Soldier'),
((24769*10+1),14,3762.704,6925.763,628.9214,'Red Dragon Soldier'),
((24769*10+1),15,3741.792,6934.354,621.9214,'Red Dragon Soldier'),
((24769*10+1),16,3720.52,6935.709,615.1437,'Red Dragon Soldier'),
((24769*10+1),17,3702.77,6929.314,607.838,'Red Dragon Soldier'),
((24769*10+1),18,3692.661,6917.933,604.2271,'Red Dragon Soldier'),
((24769*10+1),19,3689.077,6901.22,601.1439,'Red Dragon Soldier'),
((24769*10+1),20,3687.71,6887.773,599.449,'Red Dragon Soldier'),
((24769*10+1),21,3681.292,6860.081,599.449,'Red Dragon Soldier'),
((24769*10+2), 1,3715.599,6790.909,576.1764,'Red Dragon Soldier'),
((24769*10+2), 2,3733.311,6795.495,575.6484,'Red Dragon Soldier'),
((24769*10+2), 3,3746.552,6797.681,571.1484,'Red Dragon Soldier'),
((24769*10+2), 4,3758.14,6796.333,567.8428,'Red Dragon Soldier'),
((24769*10+2), 5,3769.744,6788.941,566.5097,'Red Dragon Soldier'),
((24769*10+2), 6,3774.698,6775.426,565.4541,'Red Dragon Soldier'),
((24769*10+2), 7,3772.478,6758.345,564.0373,'Red Dragon Soldier'),
((24769*10+2), 8,3761.064,6744.284,561.3151,'Red Dragon Soldier'),
((24769*10+2), 9,3742.062,6734.352,558.0375,'Red Dragon Soldier'),
((24769*10+2),10,3722.155,6732.545,558.4818,'Red Dragon Soldier'),
((24769*10+2),11,3710.604,6738.485,558.4818,'Red Dragon Soldier'),
((24769*10+2),12,3702.351,6755.943,553.5372,'Red Dragon Soldier'),
((24769*10+2),13,3702.623,6781.31,558.315,'Red Dragon Soldier'),
((24769*10+2),14,3710.322,6803.959,558.4818,'Red Dragon Soldier'),
((24769*10+2),15,3707.133,6828.621,558.4818,'Red Dragon Soldier'),
((24769*10+2),16,3694.577,6842.447,558.4818,'Red Dragon Soldier'),
((24769*10+2),17,3677.345,6846.772,558.4818,'Red Dragon Soldier'),
((24769*10+2),18,3658.489,6838.999,562.2039,'Red Dragon Soldier'),
((24769*10+2),19,3643.681,6818.719,570.5095,'Red Dragon Soldier'),
((24769*10+2),20,3640.345,6800.429,574.6765,'Red Dragon Soldier'),
((24769*10+2),21,3649.234,6780.53,576.1764,'Red Dragon Soldier'),
((24769*10+2),22,3662.512,6771.815,576.1764,'Red Dragon Soldier'),
((24769*10+2),23,3689.853,6776.469,576.1764,'Red Dragon Soldier'),
((24769*10+2),24,3715.599,6790.909,576.1764,'Red Dragon Soldier'),
((24769*10+2),25,3733.311,6795.495,575.6484,'Red Dragon Soldier'),
((24769*10+2),26,3746.552,6797.681,571.1484,'Red Dragon Soldier');

UPDATE `creature` SET `position_x`=3952.028076, `position_y`=6567.808594, `position_z`=176.627365, `orientation`=2.203855 WHERE `guid`=122548; 
UPDATE `creature` SET `position_x`=3939.199219, `position_y`=6601.528809, `position_z`=170.125626, `orientation`=1.995724 WHERE `guid`=122668; 
UPDATE `creature` SET `position_x`=3911.590576, `position_y`=6598.076172, `position_z`=167.979401, `orientation`=3.311266 WHERE `guid`=122747; 
