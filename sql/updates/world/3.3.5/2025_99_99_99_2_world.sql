--
-- =========================================================
-- Creature Text: Captain SAEED
-- =========================================================
DELETE FROM `creature_text` WHERE `CreatureID`=20985;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(20985,0,0,'You heard the fleshling! MOVE OUT!',12,0,100,15,0,0,0,0,'Captain Saeed'),
(20985,1,0,'Tell me when you are ready $N. We will attack on your command.',12,0,100,0,0,0,0,0,'Captain Saeed'),
(20985,2,0,'It\'s now or never, soldiers! Let\'s do this! For K\'aresh! For the Protectorate!',12,0,100,0,0,0,0,0,'Captain Saeed'),
(20985,3,0,'The time for your destruction has finally come, Dimensius!',12,0,100,0,0,0,0,0,'Captain Saeed');

DELETE FROM `creature_text_locale` WHERE `CreatureID`=20985 AND `Locale`='deDE';
INSERT INTO `creature_text_locale` (`CreatureID`,`GroupID`,`ID`,`Locale`,`Text`) VALUES
(20985,0,0,'deDE','Ihr habt den Fleischling gehört! AUSRÜCKEN!'),
(20985,1,0,'deDE','Sagt mir Bescheid, wenn Ihr bereit seid, $N. Wir werden auf Euer Kommando hin angreifen.'),
(20985,2,0,'deDE','Jetzt oder nie, Soldaten! Auf in den Kampf! Für K\'aresh! Für das Protektorat!'),
(20985,3,0,'deDE','Die Zeit für Euren Untergang ist endlich gekommen, Dimensius!');

-- =========================================================
-- Creature Text: Protectorate Regenerator
-- =========================================================

DELETE FROM `creature_text` WHERE `CreatureID`=21783;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(21783,0,0,'We are victorious! Dimensius is no more! Report back to the Professor, hero.',12,0,100,0,0,0,0,0,'Protectorate Regenerator');

DELETE FROM `creature_text_locale` WHERE `CreatureID`=21783 AND `Locale`='deDE';
INSERT INTO `creature_text_locale` (`CreatureID`,`GroupID`,`ID`,`Locale`,`Text`) VALUES
(21783,0,0,'deDE','Wir haben gesiegt! Dimensius ist tot! Meldet Euch bei dem Professor, Held!');

-- =========================================================
-- Creature Text: Dimensius the All-Devouring
-- =========================================================

DELETE FROM `creature_text` WHERE `CreatureID`=19554;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(19554,0,0,'You only hasten the inevitable. In time, all will be devoured!',14,0,100,0,0,0,0,1,'Dimensius the All-Devouring'),
(19554,1,0,'Time only has meaning to mortals, insect. Dimensius is infinite!',14,0,100,0,0,0,0,1,'Dimensius the All-Devouring'),
(19554,2,0,'I hunger! Feed me the power of this forge, my children!',14,0,100,0,0,0,0,1,'Dimensius the All-Devouring');

DELETE FROM `creature_text_locale` WHERE `CreatureID`=19554 AND `Locale`='deDE';
INSERT INTO `creature_text_locale` (`CreatureID`,`GroupID`,`ID`,`Locale`,`Text`) VALUES
(19554,0,0,'deDE','Ihr zögert das Unvermeidliche nur heraus. Bald wird alles verschlungen sein!'),
(19554,1,0,'deDE','Zeit ist nur für Sterbliche von Bedeutung, Insekt. Dimensius ist zeitlos!'),
(19554,2,0,'deDE','Ich hungere! Ich brauche die Kraft dieser Schmiede als Nahrung. Gebt sie mir, meine Kinder!');

-- =========================================================
-- Waypoints: Captain SAEED (20985)
-- =========================================================

DELETE FROM `script_waypoint` WHERE `entry`=20985;
INSERT INTO `script_waypoint` (`entry`,`pointid`,`location_x`,`location_y`,`location_z`,`waittime`,`point_comment`) VALUES
(20985,1,4254.23,2108.69,144.247,0,''),
(20985,2,4239.06,2114.86,146.952,0,''),
(20985,3,4225.45,2118.14,152.244,0,''),
(20985,4,4211.32,2107.93,156.698,0,''),
(20985,5,4206.56,2104.48,160.319,0,''),
(20985,6,4178.02,2075.21,163.157,0,''),
(20985,7,4175.38,2061.21,167.984,0,''),
(20985,8,4188.63,2023.8,184.663,0,''),
(20985,9,4173.8,1993.33,204.116,0,''),
(20985,10,4142.52,1973.01,218.002,0,''),
(20985,11,4101.52,2007.56,230.967,0,''),
(20985,12,4092.63,2026.51,236.429,0,''),
(20985,13,4059.49,2060.78,250.161,0,''),
(20985,14,4032.52,2077.06,254.449,0,''),
(20985,15,4001.34,2099.2,254.212,0,''),
(20985,16,3993.95,2090.21,254.32,0,''),
(20985,17,3989.37,2083.43,256.391,0,''),
(20985,18,3951.24,2024.99,257.005,0,''),
(20985,19,3936.4,2003,255.68,0,'');

-- =========================================================
-- Gossip Buttons
-- =========================================================

DELETE FROM `trinity_string` WHERE `entry` IN (30000,30001);
INSERT INTO `trinity_string` (`entry`,`content_default`,`content_loc3`) VALUES
(30000,'I am that fleshling, Saeed. Let''s go!','Ich bin dieser Fleischling, Saeed. Lass uns gehen!'),
(30001,'I am ready. Let''s make history!','Ich bin bereit. Lasst uns Geschichte schreiben!');

-- =========================================================
-- CreatureTemplate Scripts
-- =========================================================

UPDATE `creature_template` SET AIName='', ScriptName='npc_saeed_follower' WHERE entry IN (20984,21783,21805);
UPDATE `creature_template` SET AIName='', ScriptName='npc_captain_saeed' WHERE entry=20985;

-- =========================================================
-- SmartAI: Dimensius (19554)
-- =========================================================

SET @ENTRY := 19554;
UPDATE `creature_template` SET AIName='SmartAI', ScriptName='' WHERE entry=@ENTRY;
DELETE FROM `smart_scripts` WHERE source_type=0 AND entryOrGuid=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,0,0,0,0,0,63,1,0,1,0,0,0,1,0,0,0,0,0,0,0,'On reset - Self: Set script counter_1 to 0'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,35939,2,0,0,0,0,1,0,0,0,0,0,0,0,'On reset - Self: Cast spell 35939 with flags triggered on Self'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On reset - Self: Set rooted'),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On aggro - Self: Talk 0 to invoker'),
(@ENTRY,0,4,0,0,0,100,0,2000,3000,5000,10000,11,37425,0,0,0,0,0,1,0,0,0,0,0,0,0,'Every 5-10s (2-3s init) - Self: Cast 37425'),
(@ENTRY,0,5,0,0,0,100,0,3000,4000,7000,10000,11,37500,64,0,0,0,0,5,0,0,0,0,0,0,0,'Every 7-10s (3-4s init) - Self: Cast 37500 on Random hostile'),
(@ENTRY,0,6,0,0,0,100,0,5000,7000,10000,16000,11,37412,0,0,0,0,0,5,50,1,0,0,0,0,0,'Every 10-16s (5-7s init) - Self: Cast 37412 on Random hostile'),
(@ENTRY,0,7,8,2,0,100,1,0,75,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'When HP 0-75% (once) - Talk 2'),
(@ENTRY,0,8,9,61,0,100,0,0,0,0,0,12,21780,4,30000,0,0,0,1,0,0,0,28,0,0,0,'When HP 0-75% (once) - Summon Spawn 21780 offset 28,0,0,0'),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,12,21780,4,30000,0,0,0,1,0,0,0,-28,0,0,0,'When HP 0-75% (once) - Summon Spawn 21780 offset -28,0,0,0'),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,12,21780,4,30000,0,0,0,1,0,0,0,0,28,0,0,'When HP 0-75% (once) - Summon Spawn 21780 offset 0,28,0,0'),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,12,21780,4,30000,0,0,0,1,0,0,0,0,-28,0,0,'When HP 0-75% (once) - Summon Spawn 21780 offset 0,-28,0,0'),
(@ENTRY,0,12,13,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'On death - Talk 1'),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,11,21780,100,0,0,0,0,0,0,'On death - Despawn Spawn 21780'),
(@ENTRY,0,14,0,77,0,100,0,1,4,0,0,28,0,0,1,0,0,0,1,0,0,0,0,0,0,0,'On counter_1=4 - Remove all auras');

UPDATE `creature_template` SET mechanic_immune_mask=650870782 WHERE entry=19554;

-- =========================================================
-- SmartAI: Spawn of Dimensius (21780)
-- =========================================================

SET @ENTRY := 21780;
UPDATE `creature_template` SET AIName='SmartAI', ScriptName='' WHERE entry=@ENTRY;
DELETE FROM `smart_scripts` WHERE source_type=0 AND entryOrGuid=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,37,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On AI init - Set react state Passive'),
(@ENTRY,0,1,2,60,0,100,257,0,0,0,0,11,37450,2,0,0,0,0,19,19554,50,0,0,0,0,0,0,'Once - Cast 37450 on closest Dimensius in 50y'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Once - Talk 0'),
(@ENTRY,0,3,0,6,0,100,0,0,0,0,0,63,1,1,0,0,0,0,19,19554,80,0,0,0,0,0,0,'On death - Add 1 to Dimensius counter_1');

-- =========================================================
-- Conditions
-- =========================================================

DELETE FROM `conditions` WHERE (SourceTypeOrReferenceId,SourceEntry) IN ((22,21780),(22,19554));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
(22,5,19554,0,0,29,1,21780,100,0,0,'Spawn 21780 within 100y');

-- =========================================================
-- SpellScript Names
-- =========================================================

DELETE FROM `spell_script_names` WHERE spell_id=37425;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (37425,'spell_37425_logic_tick');
