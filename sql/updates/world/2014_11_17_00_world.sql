--
-- Corrected SAI errors at startup which noticed by issue #13318.
-- This fix contains fixes for EVENT_LINK entry which have bad link values.--
--
 
-- Infinite Chronomancer SAI
SET @ENTRY := 17892;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Out of Combat - Disable Combat Movement (No Repeat) (Dungeon)"),
(@ENTRY,0,1,0,1,0,100,7,1000,1000,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Out of Combat - Cast 'Corrupt Medivh' (No Repeat) (Dungeon)"),
(@ENTRY,0,2,0,0,0,20,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Say Line 0 (No Repeat) (Dungeon)"),
(@ENTRY,0,3,0,4,0,100,7,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Remove Aura 'Corrupt Medivh' (No Repeat) (Dungeon)"),
(@ENTRY,0,4,0,4,0,100,7,0,0,0,0,30,1,1,3,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Set Random Phase(1, 1, 3) (No Repeat) (Dungeon)"),
(@ENTRY,0,5,8,4,2,100,3,0,0,0,0,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Cast 'Frostbolt' (Phase 2) (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,6,7,9,2,100,2,0,40,2900,5400,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 0-40 Range - Cast 'Frostbolt' (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,7,8,61,2,100,3,0,40,2900,5400,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 0-40 Range - Cast 'Frostbolt' (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Increment Phase (Phase 2) (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,9,0,9,2,100,4,0,40,2900,5400,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 0-40 Range - Cast 'Frostbolt' (Phase 2) (Heroic Dungeon)"),
(@ENTRY,0,10,11,3,2,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-15% Mana - Enable Combat Movement (Phase 2) (No Repeat) (Dungeon)"),
(@ENTRY,0,11,0,61,2,100,0,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-15% Mana - Increment Phase (Phase 2) (No Repeat) (Dungeon)"),
(@ENTRY,0,12,0,9,2,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 35-80 Range - Enable Combat Movement (Phase 2) (No Repeat) (Dungeon)"),
(@ENTRY,0,13,0,9,2,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 5-15 Range - Disable Combat Movement (Phase 2) (No Repeat) (Dungeon)"),
(@ENTRY,0,14,0,9,2,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 0-5 Range - Enable Combat Movement (Phase 2) (No Repeat) (Dungeon)"),
(@ENTRY,0,15,0,0,2,100,2,3700,12900,33800,39800,11,15063,1,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 'Frost Nova' (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,16,0,0,2,100,4,3600,8300,22200,25700,11,15531,1,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 'Frost Nova' (Phase 2) (Heroic Dungeon)"),
(@ENTRY,0,17,0,3,4,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 30-100% Mana - Decrement Phase (Phase 4) (Dungeon)"),
(@ENTRY,0,18,21,4,8,100,3,0,0,0,0,11,15124,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Cast 'Arcane Bolt' (Phase 8) (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,19,20,9,8,100,2,0,40,2900,5400,11,15124,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 0-40 Range - Cast 'Arcane Bolt' (Phase 8) (Normal Dungeon)"),
(@ENTRY,0,20,21,61,8,100,0,0,40,2900,5400,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 0-40 Range - Cast 'Arcane Bolt' (Phase 8) (Normal Dungeon)"),
(@ENTRY,0,21,0,61,8,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Increment Phase (Phase 8) (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,22,0,9,8,100,4,0,40,1200,3400,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 0-40 Range - Cast 'Arcane Bolt' (Phase 8) (Heroic Dungeon)"),
(@ENTRY,0,23,24,3,8,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-15% Mana - Enable Combat Movement (Phase 8) (No Repeat) (Dungeon)"),
(@ENTRY,0,24,0,61,8,100,0,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-15% Mana - Increment Phase (Phase 8) (No Repeat) (Dungeon)"),
(@ENTRY,0,25,0,9,8,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 35-80 Range - Enable Combat Movement (Phase 8) (No Repeat) (Dungeon)"),
(@ENTRY,0,26,0,9,8,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 5-15 Range - Disable Combat Movement (Phase 8) (No Repeat) (Dungeon)"),
(@ENTRY,0,27,0,9,8,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Within 0-5 Range - Enable Combat Movement (Phase 8) (No Repeat) (Dungeon)"),
(@ENTRY,0,28,0,0,8,100,2,8600,18200,9500,10100,11,33860,1,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 'Arcane Explosion' (Phase 8) (Normal Dungeon)"),
(@ENTRY,0,29,0,0,8,100,2,8600,18200,8000,10100,11,33623,1,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 'Arcane Explosion' (Phase 8) (Normal Dungeon)"),
(@ENTRY,0,30,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 30-100% Mana - Decrement Phase (Dungeon)"),
(@ENTRY,0,31,0,7,0,100,7,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Evade - Set Event Phase 0 (No Repeat) (Dungeon)"),
(@ENTRY,0,32,0,7,0,100,7,0,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Evade - Cast 'Corrupt Medivh' (No Repeat) (Dungeon)");

-- Father Kamaros SAI
SET @ENTRY := 31279;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Aggro - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,11,25054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Father Kamaros - On Aggro - Cast 'Holy Smite' (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,0,40,3400,4700,11,25054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Father Kamaros - Within 0-40 Range - Cast 'Holy Smite' (Phase 1)"),
(@ENTRY,0,4,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Within 40-100 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Within 10-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Within 0-40 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,3,1,100,0,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Between 0-15% Mana - Set Event Phase 2 (Phase 1)"),
(@ENTRY,0,8,0,3,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Between 0-15% Mana - Enable Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Between 30-100% Mana - Set Event Phase 1 (Phase 2)"),
(@ENTRY,0,11,0,0,1,100,0,5000,6200,11700,15600,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,"Father Kamaros - In Combat - Cast 'Shadow Word: Pain' (Phase 1)"),
(@ENTRY,0,12,0,2,0,100,1,0,50,0,0,11,32595,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - Between 0-50% Health - Cast 'Power Word: Shield' (No Repeat)"),
(@ENTRY,0,13,14,19,0,100,0,0,0,0,0,75,58921,0,0,0,0,0,7,0,0,0,0,0,0,0,"Father Kamaros - On Quest Taken - Add Aura 'Power Word: Fortitude'"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Quest Taken - Say Line 1"),
(@ENTRY,0,15,16,52,0,100,0,1,31279,0,0,1,2,1000,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Text 1 Over - Say Line 2"),
(@ENTRY,0,16,0,61,0,100,0,1,31279,0,0,1,2,1000,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Text 1 Over - Say Line 2"),
(@ENTRY,0,17,0,52,0,100,0,2,31279,0,0,53,0,31279,0,0,0,1,1,0,0,0,0,0,0,0,"Father Kamaros - On Text 2 Over - Start Waypoint"),
(@ENTRY,0,18,0,40,0,100,0,13,0,0,0,1,3,2900,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Waypoint 13 Reached - Say Line 3"),
(@ENTRY,0,19,0,52,0,100,0,3,31279,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Text 3 Over - Say Line 4"),
(@ENTRY,0,20,0,52,0,100,0,4,31279,0,0,15,13229,0,0,0,0,0,18,30,0,0,0,0,0,0,"Father Kamaros - On Text 4 Over - Quest Credit 'I'm Not Dead Yet!'"),
(@ENTRY,0,21,0,52,0,100,0,4,31279,0,0,15,13221,0,0,0,0,0,18,30,0,0,0,0,0,0,"Father Kamaros - On Text 4 Over - Quest Credit 'I'm Not Dead Yet!'"),
(@ENTRY,0,22,0,52,0,100,0,4,31279,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Kamaros - On Text 4 Over - Despawn In 1000 ms");

-- Moodle SAI
SET @ENTRY := 28122;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2812000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,2,100,1,51420,0,60000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Spellhit 'Digging for Treasure Ping' - Say Line 0 (Phase 2) (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,0,51420,0,60000,60000,80,2812000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Spellhit 'Digging for Treasure Ping' - Run Script (Phase 2) (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,3000,3000,3000,3000,11,51793,2,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - Out of Combat - Cast 'Gorloc Location Periodic'"),
(@ENTRY,0,3,0,1,0,100,0,3000,3000,3000,3000,11,51623,2,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - Out of Combat - Cast 'Sholazar Guardian Heartbeat'"),
(@ENTRY,0,4,0,0,0,100,0,0,5000,20000,30000,11,52974,2,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - In Combat - Cast 'Vicious Roar'"),
(@ENTRY,0,5,0,20,0,100,0,12580,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Quest 'The Mosswalker Savior' Finished - Say Line 6"),
(@ENTRY,0,6,0,0,0,100,0,0,5000,20000,24000,11,52973,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moodle - In Combat - Cast 'Frost Breath'"),
(@ENTRY,0,7,0,0,0,100,0,9000,15000,20000,25000,11,52979,0,0,0,0,0,5,0,0,0,0,0,0,0,"Moodle - In Combat - Cast 'Frigid Absorbtion'"),
(@ENTRY,0,8,0,0,0,100,0,2000,10000,40000,50000,11,52972,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - In Combat - Cast 'Dispersal'"),
(@ENTRY,0,9,0,2,0,100,0,0,50,60000,60000,11,52979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - Between 0-50% Health - Cast 'Frigid Absorbtion'"),
(@ENTRY,0,10,0,11,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Respawn - Set Reactstate Defensive"),
(@ENTRY,0,11,0,5,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Killed Unit - Say Line 1"),
(@ENTRY,0,12,0,1,0,100,0,10000,40000,45000,90000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - Out of Combat - Say Line 2"),
(@ENTRY,0,13,0,8,0,100,0,51639,0,45000,70000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Spellhit 'Rainspeaker Canopy Aura' - Say Line 3"),
(@ENTRY,0,14,0,8,0,100,1,53163,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Spellhit 'Dessawn Retainer' - Despawn Instant (No Repeat)"),
(@ENTRY,0,15,16,8,2,100,0,51644,0,40000,70000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Spellhit 'Mosswalker Village Aura' - Say Line 4 (Phase 2)"),
(@ENTRY,0,16,0,61,0,100,0,51644,0,40000,70000,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Spellhit 'Mosswalker Village Aura' - Set Reactstate Passive (Phase 2)"),
(@ENTRY,0,17,0,19,0,100,0,12581,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Quest 'A Hero's Burden' Taken - Say Line 5"),
(@ENTRY,0,18,0,1,0,100,0,10000,10000,10000,10000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - Out of Combat - Set Event Phase 2"),
(@ENTRY,0,19,0,4,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - On Aggro - Set Event Phase 0"),
(2812000,9,0,0,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,11,28362,10,0,0,0,0,0,"Moodle - INCORRECT EVENT TYPE - Move To Closest Creature 'Glinting Dirt' (Phase 2) (No Repeat)"),
(2812000,9,1,0,61,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,9,28362,0,2,0,0,0,0,"Moodle - INCORRECT EVENT TYPE - Set Data 1 1 (Phase 2) (No Repeat)"),
(2812000,9,2,0,61,0,100,0,1500,1500,0,0,11,51405,2,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - INCORRECT EVENT TYPE - Cast 'Digging for Treasure'"),
(2812000,9,3,0,61,0,100,0,5000,5000,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moodle - INCORRECT EVENT TYPE - Evade");

-- Grand Necrolord Antiok SAI
SET @ENTRY := 28006;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,7000,18000,18000,11,32863,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - In Combat - Cast 'Seed of Corruption'"),
(@ENTRY,0,1,0,0,0,100,0,1100,1100,20000,20000,11,50455,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,1,0,100,0,10000,10000,40000,40000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - Out of Combat - Say Line 1"),
(@ENTRY,0,3,0,2,0,100,1,0,25,0,0,11,50497,1,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - Between 0-25% Health - Cast 'Scream of Chaos' (No Repeat)"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,11,50472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Just Died - Cast 'Drop Scythe of Antiok'"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Say Line 0"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,11,55984,1,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Cast 'Shadow Bolt'"),
(@ENTRY,0,7,8,4,0,100,0,0,0,0,0,51,0,0,0,0,0,0,19,27996,20,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Kill Target"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,28,50494,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Remove Aura 'Shroud of Lightning'");

-- Injured 7th Legion Soldier SAI
SET @ENTRY := 27788;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On Just Summoned - Store Targetlist"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,49774,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On Just Summoned - Cast cast Cower + Fear Visual"),
(@ENTRY,0,2,12,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - Run Script"),
(@ENTRY,0,3,4,7,0,100,0,0,0,0,0,11,49774,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On Evade  - cast Cower + Fear Visual"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,64,2,0,0,0,0,0,12,1,0,0,0,0,0,0,"Injured 7th Legion Soldier - On 7th Legion cannon within 3 yards  - Disable Combat movement"),
(@ENTRY,0,5,0,6,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On Death  - Reset all scripts"),
(@ENTRY,0,6,4,75,0,100,1,0,27714,10,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On 7th Legion Cannon within 15 yards  - Remove aura Cower + Fear Visual"),
(@ENTRY,0,7,8,75,0,100,1,0,27714,3,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Injured 7th Legion Soldier - On 7th Legion Cannon within 5 yards  - Say"),
(@ENTRY,0,8,9,61,0,100,0,0,0,0,0,33,27788,0,0,0,0,0,12,1,0,0,0,0,0,0,"Injured 7th Legion Soldier - On 7th Legion Cannon within 5 yards  - Give kill credit to stored target"),
(@ENTRY,0,9,13,61,0,100,0,0,0,0,0,28,49774,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On 7th Legion Cannon within 5 yards  - Remove aura Cower + Fear Visual"),
(@ENTRY,0,10,11,1,0,100,0,500,500,7500,7500,29,0,0,0,0,0,0,12,2,0,0,0,0,0,0,"Injured 7th Legion Soldier - OOC - Follow stored target 2"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - Just Summoned  - Disable melee combat"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - Just Summoned  - Disable Combat movement"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,28,49775,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier -  On 7th Legion Cannon within 15 yards  - Remove aura Cower + Fear Visual"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier -  On 7th Legion Cannon within 15 yards  - Set Unit Flags"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured 7th Legion Soldier - On 7th Legion Cannon within 15 yards  - Set Run"),
(@ENTRY,0,16,0,7,0,100,0,0,0,0,0,29,0,0,0,0,0,0,12,2,0,0,0,0,0,0,"Injured 7th Legion Soldier - On Evade Follow stored targetlist 2"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,64,2,0,0,0,0,0,19,27792,0,0,0,0,0,0,"Injured 7th Legion Soldier - Script - Store Targetlist 2 closest Injured Soldier Waypoint 01 "),
(@ENTRY*100+00,9,1,0,0,0,100,0,15000,15000,0,0,64,2,0,0,0,0,0,19,27793,0,0,0,0,0,0,"Injured 7th Legion Soldier - Script - Store Targetlist 2 closest Injured Soldier Waypoint 02"),
(@ENTRY*100+00,9,2,0,0,0,100,0,15000,15000,0,0,64,2,0,0,0,0,0,19,27794,0,0,0,0,0,0,"Injured 7th Legion Soldier - Script - Store Targetlist 2 closest Injured Soldier Waypoint 03"),
(@ENTRY*100+00,9,3,0,0,0,100,0,15000,15000,0,0,64,2,0,27714,0,0,0,19,27714,0,0,0,0,0,0,"Injured 7th Legion Soldier - Script - Store Targetlist 2  7th legion chain gun");

-- Image of Drakuru SAI
SET @ENTRY := 26701;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,12068,0,0,0,11,47403,0,0,0,0,0,7,0,0,0,0,0,0,0,"Image of Drakuru - On Quest 'Voices From the Dust' Taken - Cast 'Strip Detect Drakuru 03'"),
(@ENTRY,0,1,0,61,0,100,0,12068,0,0,0,5,66,0,0,0,0,0,0,0,0,0,0,0,0,0,"Image of Drakuru - On Quest 'Voices From the Dust' Taken - Play Emote 66");

-- Ymirjar Flesh Hunter SAI
SET @ENTRY := 26670;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,6,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Out of Combat - Disable Combat Movement (Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Out of Combat - Stop Attacking (Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,48854,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Aggro - Cast 'Shoot' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Aggro - Increment Phase (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,4,5,9,1,100,2,5,30,5000,8000,11,48854,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 5-30 Range - Cast 'Shoot' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,5,30,5000,8000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 5-30 Range - Set Sheath Ranged (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,59241,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Aggro - Cast 'Shoot' (No Repeat) (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Aggro - Increment Phase (No Repeat) (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,1,100,4,5,30,5000,8000,11,59241,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 5-30 Range - Cast 'Shoot' (Phase 1) (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,5,30,5000,8000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 5-30 Range - Set Sheath Ranged (Phase 1) (Heroic Dungeon)"),
(@ENTRY,0,10,11,9,1,100,6,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 25-80 Range - Enable Combat Movement (Phase 1) (Dungeon)"),
(@ENTRY,0,11,0,61,0,100,0,25,80,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 25-80 Range - Start Attacking (Phase 1) (Dungeon)"),
(@ENTRY,0,12,13,9,1,100,6,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 0-5 Range - Enable Combat Movement (Phase 1) (Dungeon)"),
(@ENTRY,0,13,14,61,0,100,0,0,5,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 0-5 Range - Set Sheath Melee (Phase 1) (Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,5,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 0-5 Range - Start Attacking (Phase 1) (Dungeon)"),
(@ENTRY,0,15,16,9,1,100,6,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 5-15 Range - Disable Combat Movement (Phase 1) (Dungeon)"),
(@ENTRY,0,16,0,61,0,100,0,5,15,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Within 5-15 Range - Stop Attacking (Phase 1) (Dungeon)"),
(@ENTRY,0,17,18,0,0,100,2,9000,14000,22000,26000,11,48871,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast 'Aimed Shot' (Normal Dungeon)"),
(@ENTRY,0,18,0,61,0,100,0,9000,14000,22000,26000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,19,20,0,0,100,4,9000,14000,22000,26000,11,59243,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast 'Aimed Shot' (Heroic Dungeon)"),
(@ENTRY,0,20,0,61,0,100,0,9000,14000,22000,26000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,21,22,0,0,100,2,14000,17000,24000,27000,11,48872,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast 'Multi-Shot' (Normal Dungeon)"),
(@ENTRY,0,22,0,61,0,100,0,14000,17000,24000,27000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,23,24,0,0,100,4,14000,17000,24000,27000,11,59244,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast 'Multi-Shot' (Heroic Dungeon)"),
(@ENTRY,0,24,0,61,0,100,0,14000,17000,24000,27000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,25,0,7,0,100,6,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Evade - Set Sheath Melee (Dungeon)");

-- Image of Drakuru SAI
SET @ENTRY := 26787;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,12238,0,0,0,11,48417,0,0,0,0,0,7,0,0,0,0,0,0,0,"Image of Drakuru - On Quest 'Cleansing Drak'Tharon' Taken - Cast 'Strip Detect Drakuru 04'"),
(@ENTRY,0,1,2,11,0,100,0,0,0,0,0,11,43167,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Drakuru - On Respawn - Cast 'Spirit Particles (green)'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,47119,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Drakuru - On Respawn - Cast 'Drakuru (Quest Invis)'");

-- Areatrigger SAI
SET @ENTRY := 4857;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,4857,0,0,0,85,45627,2,0,0,0,0,7,0,0,0,0,0,0,0,"Areatrigger - On Trigger - Invoker Cast 'Temple A Credit'");

-- Areatrigger SAI
SET @ENTRY := 4860;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,4860,0,0,0,85,45629,2,0,0,0,0,7,0,0,0,0,0,0,0,"Areatrigger - On Trigger - Invoker Cast 'Temple C Credit'");

-- Areatrigger SAI
SET @ENTRY := 4858;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,4858,0,0,0,85,45628,2,0,0,0,0,7,0,0,0,0,0,0,0,"Areatrigger - On Trigger - Invoker Cast 'Temple B Credit'");
