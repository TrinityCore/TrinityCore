-- ScriptEffect for 32348 from sniffs. 32352 probably used on heroic only or not used at all
DELETE FROM `spell_scripts` WHERE `id` = 32348;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(32348,0,0,15,32349,2,0,0,0,0,0),
(32348,0,0,15,32353,2,0,0,0,0,0);

-- Ethereal Darkcaster
DELETE FROM `creature_addon` WHERE `guid` IN (83332,83335,83338,83339,83341,83345,83348,86396,91124,91186,91187);
UPDATE `creature_addon` SET `auras` = "16592" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 18331);
DELETE FROM `creature_template_addon` WHERE `entry` IN (18331,20256);
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(18331,"16592"), -- Shadowform
(20256,"16592"); -- Shadowform

-- Ethereal Scavenger SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18309;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Scavenger - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,2400,4800,7200,21700,11,33871,32,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Scavenger - In Combat - Cast 'Shield Bash'"),
(@ID,0,2,0,0,0,100,0,2400,8300,12100,20500,11,33865,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Scavenger - In Combat - Cast 'Singe'"),
(@ID,0,3,0,0,0,100,0,14100,28200,8100,16200,11,34920,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Scavenger - In Combat - Cast 'Strike'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"What have the netherwinds brought us?",12,0,100,0,0,0,16721,0,"Ethereal Scavenger"),
(@ID,0,1,"You're far from home, stranger.",12,0,100,0,0,0,16722,0,"Ethereal Scavenger"),
(@ID,0,2,"Welcome to the Void...",12,0,100,0,0,0,16723,0,"Ethereal Scavenger"),
(@ID,0,3,"If you hear the whisper, you're dying...",12,0,100,0,0,0,16724,0,"Ethereal Scavenger");

-- Ethereal Crypt Raider SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18311;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Crypt Raider - On Aggro - Say Line 0"),
(@ID,0,1,0,9,0,100,1,8,25,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Crypt Raider - Within 8-25 Range - Cast 'Charge' (No Repeat)"),
(@ID,0,2,0,0,0,100,0,5800,8400,60200,66200,11,31403,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Crypt Raider - In Combat - Cast 'Battle Shout'"),
(@ID,0,3,0,0,0,100,0,3600,13300,12100,18300,11,32315,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Crypt Raider - In Combat - Cast 'Soul Strike'"),
(@ID,0,4,5,2,0,100,1,0,25,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Crypt Raider - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(@ID,0,5,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Crypt Raider - On Link - Say Line 1"),
(@ID,0,6,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,19671,0,0,0,0,0,0,"Ethereal Crypt Raider - On Just Summoned - Start Attacking Closest Creature 'Cryo-Engineer Sha'heen'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"What have the netherwinds brought us?",12,0,100,0,0,0,16721,0,"Ethereal Crypt Raider"),
(@ID,0,1,"You're far from home, stranger.",12,0,100,0,0,0,16722,0,"Ethereal Crypt Raider"),
(@ID,0,2,"Welcome to the Void...",12,0,100,0,0,0,16723,0,"Ethereal Crypt Raider"),
(@ID,0,3,"If you hear the whisper, you're dying...",12,0,100,0,0,0,16724,0,"Ethereal Crypt Raider"),
(@ID,1,0,"%s goes into a frenzy!",16,0,100,0,0,0,2384,0,"Ethereal Crypt Raider");

-- Ethereal Spellbinder SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18312;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Spellbinder - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,4800,12400,14500,28900,11,17883,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Spellbinder - In Combat - Cast 'Immolate' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,4800,12400,14500,28900,11,37668,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Spellbinder - In Combat - Cast 'Immolate' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,0,7200,14500,6100,16900,11,37470,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Spellbinder - In Combat - Cast 'Counterspell'"),
(@ID,0,4,0,0,0,100,1,15700,20900,0,0,11,32316,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Spellbinder - In Combat - Cast 'Summon Ethereal Wraith' (No Repeat)"),
(@ID,0,5,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,19671,0,0,0,0,0,0,"Ethereal Spellbinder - On Just Summoned - Start Attacking Closest Creature 'Cryo-Engineer Sha'heen'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"What have the netherwinds brought us?",12,0,100,0,0,0,16721,0,"Ethereal Spellbinder"),
(@ID,0,1,"You're far from home, stranger.",12,0,100,0,0,0,16722,0,"Ethereal Spellbinder"),
(@ID,0,2,"Welcome to the Void...",12,0,100,0,0,0,16723,0,"Ethereal Spellbinder"),
(@ID,0,3,"If you hear the whisper, you're dying...",12,0,100,0,0,0,16724,0,"Ethereal Spellbinder");

-- Ethereal Sorcerer SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18313;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Sorcerer - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,5200,15700,15200,21200,11,15790,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat - Cast 'Arcane Missiles' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,5200,15700,15200,21200,11,22272,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat - Cast 'Arcane Missiles' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,0,5100,11600,10800,21700,11,25603,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat - Cast 'Slow'"),
(@ID,0,4,0,0,0,100,0,14000,25600,70700,71100,11,32348,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sorcerer - In Combat - Cast 'Summon Arcane Fiends'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"What have the netherwinds brought us?",12,0,100,0,0,0,16721,0,"Ethereal Sorcerer"),
(@ID,0,1,"You're far from home, stranger.",12,0,100,0,0,0,16722,0,"Ethereal Sorcerer"),
(@ID,0,2,"Welcome to the Void...",12,0,100,0,0,0,16723,0,"Ethereal Sorcerer"),
(@ID,0,3,"If you hear the whisper, you're dying...",12,0,100,0,0,0,16724,0,"Ethereal Sorcerer");

-- Nexus Stalker SAI (Source: ACID 4.3.4 OD - N/H)
-- Phantom Strike is used on random target
SET @ID := 18314;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nexus Stalker - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,4300,12100,9700,22100,11,34940,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Stalker - In Combat - Cast 'Gouge'"),
(@ID,0,2,0,0,0,100,2,5900,12100,10900,21700,11,33925,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nexus Stalker - In Combat - Cast 'Phantom Strike' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,5900,12100,10900,21700,11,39332,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nexus Stalker - In Combat - Cast 'Phantom Strike' (Heroic Dungeon)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"What have the netherwinds brought us?",12,0,100,0,0,0,16721,0,"Nexus Stalker"),
(@ID,0,1,"You're far from home, stranger.",12,0,100,0,0,0,16722,0,"Nexus Stalker"),
(@ID,0,2,"Welcome to the Void...",12,0,100,0,0,0,16723,0,"Nexus Stalker"),
(@ID,0,3,"If you hear the whisper, you're dying...",12,0,100,0,0,0,16724,0,"Nexus Stalker");
 
-- Ethereal Theurgist SAI (Source: ACID 4.3.4 OD - N/H)
-- Original script was without initial timers for the 'Strike'
SET @ID := 18315;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Theurgist - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,5300,10300,7700,14400,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Theurgist - In Combat - Cast 'Strike' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,5300,10300,7700,14400,11,34920,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Theurgist - In Combat - Cast 'Strike' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,2,4200,13300,18100,24100,11,17145,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Theurgist - In Combat - Cast 'Blast Wave' (Normal Dungeon)"),
(@ID,0,4,0,0,0,100,4,4200,13300,18100,24100,11,38064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Theurgist - In Combat - Cast 'Blast Wave' (Heroic Dungeon)"),
(@ID,0,5,0,0,0,100,0,2400,7200,18000,24000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ethereal Theurgist - In Combat - Cast 'Polymorph'"),
(@ID,0,6,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,19671,0,0,0,0,0,0,"Ethereal Theurgist - On Just Summoned - Start Attacking Closest Creature 'Cryo-Engineer Sha'heen'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"What have the netherwinds brought us?",12,0,100,0,0,0,16721,0,"Ethereal Theurgist"),
(@ID,0,1,"You're far from home, stranger.",12,0,100,0,0,0,16722,0,"Ethereal Theurgist"),
(@ID,0,2,"Welcome to the Void...",12,0,100,0,0,0,16723,0,"Ethereal Theurgist"),
(@ID,0,3,"If you hear the whisper, you're dying...",12,0,100,0,0,0,16724,0,"Ethereal Theurgist");

-- Ethereal Priest SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18317;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Priest - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,3400,9600,10800,18100,11,17139,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Priest - In Combat - Cast 'Power Word: Shield' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,3400,9600,10800,18100,11,35944,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Priest - In Combat - Cast 'Power Word: Shield' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,2,4800,7700,10800,20500,11,34944,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Priest - In Combat - Cast 'Holy Nova' (Normal Dungeon)"),
(@ID,0,4,0,0,0,100,4,4800,7700,10800,20500,11,37669,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Priest - In Combat - Cast 'Holy Nova' (Heroic Dungeon)"),
(@ID,0,5,0,74,0,100,2,0,70,25000,35000,11,22883,1,0,0,0,0,9,0,0,40,0,0,0,0,"Ethereal Priest - On Friendly Between 0-70% Health - Cast 'Heal' (Normal Dungeon)"),
(@ID,0,6,0,74,0,100,4,0,70,25000,35000,11,34945,1,0,0,0,0,9,0,0,40,0,0,0,0,"Ethereal Priest - On Friendly Between 0-70% Health - Cast 'Heal' (Heroic Dungeon)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"What have the netherwinds brought us?",12,0,100,0,0,0,16721,0,"Ethereal Priest"),
(@ID,0,1,"You're far from home, stranger.",12,0,100,0,0,0,16722,0,"Ethereal Priest"),
(@ID,0,2,"Welcome to the Void...",12,0,100,0,0,0,16723,0,"Ethereal Priest"),
(@ID,0,3,"If you hear the whisper, you're dying...",12,0,100,0,0,0,16724,0,"Ethereal Priest");

-- Ethereal Darkcaster SAI (Source: ACID 4.3.4 OD - N/H & sniffs)
SET @ID := 18331;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,2,0,0,0,0,11,34928,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Darkcaster - On Respawn - Cast 'Vampiric Aura' (Normal Dungeon)"),
(@ID,0,1,0,11,0,100,4,0,0,0,0,11,38060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Darkcaster - On Respawn - Cast 'Vampiric Aura' (Heroic Dungeon)"),
(@ID,0,2,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Darkcaster - On Aggro - Say Line 0"),
(@ID,0,3,0,0,0,100,0,4300,8400,8400,18100,11,34942,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Darkcaster - In Combat - Cast 'Shadow Word: Pain'"),
(@ID,0,4,0,0,0,100,2,5600,10800,15600,25300,11,34930,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Darkcaster - In Combat - Cast 'Mana Burn' (Normal Dungeon)"),
(@ID,0,5,0,0,0,100,4,5600,10800,15600,25300,11,34931,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Darkcaster - In Combat - Cast 'Mana Burn' (Heroic Dungeon)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"What have the netherwinds brought us?",12,0,100,0,0,0,16721,0,"Ethereal Darkcaster"),
(@ID,0,1,"You're far from home, stranger.",12,0,100,0,0,0,16722,0,"Ethereal Darkcaster"),
(@ID,0,2,"Welcome to the Void...",12,0,100,0,0,0,16723,0,"Ethereal Darkcaster"),
(@ID,0,3,"If you hear the whisper, you're dying...",12,0,100,0,0,0,16724,0,"Ethereal Darkcaster");

-- Tavarok SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18343;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,7400,16800,7200,15500,11,8374,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tavarok - In Combat - Cast 'Arcing Smash' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,5400,12300,7200,15500,11,38761,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tavarok - In Combat - Cast 'Arcing Smash' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,0,8500,17400,21700,27700,11,33919,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tavarok - In Combat - Cast 'Earthquake'"),
(@ID,0,3,0,0,0,100,0,16900,37400,13300,25300,11,32361,1,0,0,0,0,5,0,0,0,0,0,0,0,"Tavarok - In Combat - Cast 'Crystal Prison'");

-- Ethereal Wraith SAI (Source: ACID 4.3.4 OD - N/H)
-- Original script was without initial timers for 'Shadowbolt Volley'
SET @ID := 18394;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,3000,7000,7800,13300,11,34934,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Wraith - In Combat - Cast 'Shadowbolt Volley'"),
(@ID,0,1,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Wraith - On Evade - Despawn (0)");

-- Arcane Fiend SAI (Source: ACID 4.3.4 OD - N/H)
-- Original script was without initial timers for 'Arcane Explosion'
SET @ID := 18429;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,3400,5300,8400,10200,11,15253,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Fiend - In Combat - Cast 'Arcane Explosion' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,1300,5300,6600,10200,11,33860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Fiend - In Combat - Cast 'Arcane Explosion' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,0,8400,13700,10800,13300,11,15122,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Fiend - In Combat - Cast 'Counterspell'"),
(@ID,0,3,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Fiend - On Evade - Despawn (0)");

-- Mana Leech SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 19306;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,8200,14500,13300,20500,11,15785,1,0,0,0,0,5,0,0,0,0,0,0,0,"Mana Leech - In Combat - Cast 'Mana Burn'"),
(@ID,0,1,0,0,0,100,0,5800,10800,14600,18100,11,25602,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mana Leech - In Combat - Cast 'Faerie Fire'"),
(@ID,0,2,0,6,0,100,0,0,0,0,0,11,34933,7,0,0,0,0,1,0,0,0,0,0,0,0,"Mana Leech - On Death - Cast 'Arcane Explosion'");

-- Nexus Terror SAI (Source: ACID 4.3.4 OD - N/H)
-- Death Coil used only in heroic
SET @ID := 19307;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,4800,19700,10800,21700,11,34322,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Terror - In Combat - Cast 'Psychic Scream'"),
(@ID,0,1,0,0,0,100,0,3600,16900,15700,24100,11,34922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Terror - In Combat - Cast 'Shadows Embrace'"),
(@ID,0,2,0,0,0,100,0,7100,20900,26500,37400,11,34925,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nexus Terror - In Combat - Cast 'Curse of Impotence'"),
(@ID,0,3,0,0,0,100,4,8400,17100,15700,25300,11,38065,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nexus Terror - In Combat - Cast 'Death Coil' (Heroic Dungeon)"),
(@ID,0,4,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,19671,0,0,0,0,0,0,"Nexus Terror - On Just Summoned - Start Attacking Closest Creature 'Cryo-Engineer Sha'heen'");
