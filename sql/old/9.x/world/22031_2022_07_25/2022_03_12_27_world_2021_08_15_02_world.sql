-- Dragonflayer Rune-Seer
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23656;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 23656;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23656,0,0,0,0,0,100,0,0,5000,13000,23000,0,11,48262,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragonflayer Rune-Seer - In Combat - Cast 'Rune of Asvior'"),
(23656,0,1,0,74,0,100,0,0,50,15000,18000,30,11,48264,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Dragonflayer Rune-Seer - On Friendly Between 0-50% Health - Cast 'Rune of Ubbi'");

-- Blood Shade
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24872;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 24872;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24872,0,0,0,0,0,100,0,2000,5000,14000,18000,0,11,49843,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Blood Shade - In Combat - Cast 'Vexed Blood of the Ancestors'");

-- Winterskorn Hunter
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 26663;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 26663;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26663,0,0,0,0,0,100,0,0,0,2300,3900,0,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Winterskorn Hunter - In Combat CMC - Cast 'Shoot'"),
(26663,0,1,0,0,0,100,0,4000,6000,8000,12000,0,11,18651,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Winterskorn Hunter - In Combat - Cast 'Multi-Shot'"),
(26663,0,2,0,0,0,100,0,6000,8000,12000,19000,0,11,36828,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Winterskorn Hunter - In Combat - Cast 'Rapid Fire'");

-- Valgarde Defender
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23739;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 23739;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23739,0,0,0,0,0,100,0,0,0,2300,3900,0,11,42476,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Valgarde Defender - In Combat CMC - Cast 'Shoot'"),
(23739,0,1,0,0,0,100,0,3000,10000,9000,15000,0,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Valgarde Defender - In Combat - Cast 'Revenge'");

-- Necrotech
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24540;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 24540;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24540,0,0,0,0,0,100,0,2000,3000,11000,16000,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Necrotech - In Combat - Cast 'Shadow Bolt'"),
(24540,0,1,0,0,0,100,0,6000,8000,12000,19000,0,11,17173,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Necrotech - In Combat - Cast 'Drain Life'"),
(24540,0,2,0,0,0,100,0,3000,7000,14000,20000,0,11,18267,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Necrotech - In Combat - Cast 'Curse of Weakness'");

-- Chillmere Oracle
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24461;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 24461;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24461,0,0,0,0,0,100,0,7000,10000,12000,14000,0,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Chillmere Oracle - In Combat - Cast 'Frost Nova'"),
(24461,0,1,0,0,0,100,0,15000,20000,20000,25000,0,11,49935,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Chillmere Oracle - In Combat - Cast 'Hex of the Murloc'"),
(24461,0,2,0,0,0,100,0,4000,6000,8000,10000,0,11,49906,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Chillmere Oracle - In Combat - Cast 'Ice Lance'"),
(24461,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Chillmere Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Unstable Mur'ghoul
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23643;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 23643;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23643,0,0,1,2,0,100,1,0,10,0,0,0,11,49948,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Mur'ghoul - Between 0-10% Health - Cast 'Unstable Explosion' (No Repeat)"),
(23643,0,1,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Mur'ghoul - Between 0-10% Health - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = 23643;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23643,0,0,"The Unstable Mur'ghoul is about to explode!",16,0,100,0,0,0,27262,0,"Unstable Mur'ghoul");

-- Putrid Wight
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23992;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 23992;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23992,0,0,0,0,0,100,0,0,5000,12000,14000,0,11,43506,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Putrid Wight - In Combat - Cast 'Plague Blight'"),
(23992,0,1,0,0,0,100,0,4000,7000,10000,15000,0,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Putrid Wight - In Combat - Cast 'Thunderclap'");

-- Glacion
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24019;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 24019;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24019,0,0,0,0,0,100,0,5000,10000,5000,10000,0,11,43562,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Glacion - In Combat - Cast 'Frost Breath'"),
(24019,0,1,0,0,0,100,0,5000,15000,5000,15000,0,11,11264,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Glacion - In Combat - Cast 'Ice Blast'");

-- Iron Rune Binder
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23796;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 23796;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23796,0,0,0,0,0,100,0,6000,11000,19000,24000,0,11,15039,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Iron Rune Binder - In Combat - Cast 'Flame Shock'"),
(23796,0,1,0,0,0,100,0,8000,14000,13000,16000,0,11,48599,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Iron Rune Binder - In Combat - Cast 'Rune of Binding'");

-- Iron Rune Guardian
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24212;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 24212;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24212,0,0,0,0,0,100,0,5000,7000,15000,20000,0,11,49643,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Rune Guardian - In Combat - Cast 'Guardian Rune'"),
(24212,0,1,0,0,0,100,0,8000,14000,13000,16000,0,11,49644,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Iron Rune Guardian - In Combat - Cast 'Guardian Strike'");

-- Winterskorn Bonegrinder
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23655;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 23655;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23655,0,0,0,0,0,100,0,7000,10000,12000,14000,0,11,43951,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Winterskorn Bonegrinder - In Combat - Cast 'Bonegrinder'");

-- Captain Olster
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23962;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 23962;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23962,0,0,0,0,0,100,0,6000,10000,18000,20000,0,11,32588,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Captain Olster - In Combat - Cast 'Concussion Blow'"),
(23962,0,1,0,0,0,100,0,10000,10000,15000,15000,0,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Captain Olster - In Combat - Cast 'Intercept'"),
(23962,0,2,0,0,0,100,0,4000,7000,7000,9000,0,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Captain Olster - In Combat - Cast 'Mortal Strike'");

-- Vengeance Landing Deathguard
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23779;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 23779;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23779,0,0,0,0,0,100,0,4000,8000,12000,15000,0,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Vengeance Landing Deathguard - In Combat - Cast 'Mortal Strike'"),
(23779,0,1,0,0,0,100,0,6000,10000,18000,20000,0,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Vengeance Landing Deathguard - In Combat - Cast 'Snap Kick'");

-- Howling Wolvar Shaman
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 26825;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 26825;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26825,0,0,0,0,0,100,0,2000,6000,9000,12000,0,11,13281,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Howling Wolvar Shaman - In Combat - Cast 'Earth Shock'"),
(26825,0,1,0,0,0,100,0,7000,9000,18000,20000,0,11,15786,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Howling Wolvar Shaman - In Combat - Cast 'Earthbind Totem'"),
(26825,0,2,0,0,0,100,0,3000,4000,7000,9000,0,11,26098,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Howling Wolvar Shaman - In Combat - Cast 'Lightning Bolt'");

-- Howling Wolvar Trainer
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 26823;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 26823;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26823,0,0,0,0,0,100,0,3000,7000,14000,20000,0,11,31290,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Howling Wolvar Trainer - In Combat - Cast 'Net'"),
(26823,0,1,0,0,0,100,0,8000,14000,13000,20000,0,11,50054,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Howling Wolvar Trainer - In Combat - Cast 'Quick Feet'"),
(26823,0,2,0,13,0,100,0,12000,19000,0,0,0,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Howling Wolvar Trainer - On Target Casting Spell - Cast 'Pummel'");
