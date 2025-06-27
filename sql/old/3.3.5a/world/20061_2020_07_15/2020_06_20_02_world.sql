-- Cabal Ritualist, handled in script
UPDATE `creature` SET `equipment_id` = 0 WHERE `id` = 18794;

-- Cabal Ritualist, 3 per pack in normal, 4 in heroic
UPDATE `creature` SET `spawnMask` = 2 WHERE `guid` IN (68738,67088,67087,66893,66888,66883) AND `id` = 18794;

-- Took from CMaNGOS
UPDATE `creature_template_addon` SET `auras` = "8876" WHERE `entry` = 18631;
UPDATE `creature_template_addon` SET `auras` = "30982 30991 30998" WHERE `entry` = 18636;
UPDATE `creature_template_addon` SET `auras` = "16592" WHERE `entry` = 18637;
DELETE FROM `creature_template_addon` WHERE `entry` IN (20640,20639,20646);
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(20640,"8876"),
(20639,"30982 30991 30998"),
(20646,"16592");

-- Cabal Cultist SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18631;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Cultist - On Aggro - Say Line 0"),
(@ID,0,1,0,13,0,100,0,5000,10000,0,0,11,15614,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Cultist - Target Casting - Cast 'Kick'"),
(@ID,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Cabal Cultist - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Cultist"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Cultist"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Cultist"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Cultist"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Cultist"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Cultist");

-- Cabal Executioner SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18632;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Executioner - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,7200,15900,15700,32500,11,33500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Executioner - In Combat - Cast 'Whirlwind' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,7200,15900,15700,32500,11,15578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Executioner - In Combat - Cast 'Whirlwind' (Heroic Dungeon)"),
(@ID,0,3,0,12,0,100,0,0,20,8000,12000,11,7160,1,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Executioner - Target Between 0-20% Health - Cast 'Execute'"),
(@ID,0,4,0,2,0,100,1,0,25,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Executioner - Between 0-25% Health - Cast 'Enrage' (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Executioner"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Executioner"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Executioner"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Executioner"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Executioner"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Executioner");

-- Cabal Acolyte SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18633;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,1000,1000,30000,30000,11,33482,32,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Acolyte - Out of Combat - Cast 'Shadow Defense'"),
(@ID,0,1,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Acolyte - On Aggro - Say Line 0"),
(@ID,0,2,0,74,0,100,2,0,60,15700,27700,11,12039,0,0,0,0,0,9,0,0,15,0,0,0,0,"Cabal Acolyte - On Friendly Between 0-60% Health - Cast 'Heal' (Normal Dungeon)"),
(@ID,0,3,0,74,0,100,4,0,60,15700,27700,11,38209,0,0,0,0,0,9,0,0,15,0,0,0,0,"Cabal Acolyte - On Friendly Between 0-60% Health - Cast 'Heal' (Heroic Dungeon)"),
(@ID,0,4,0,74,0,100,2,0,50,13200,19300,11,25058,0,0,0,0,0,9,0,0,15,0,0,0,0,"Cabal Acolyte - On Friendly Between 0-50% Health - Cast 'Renew' (Normal Dungeon)"),
(@ID,0,5,0,74,0,100,4,0,50,13200,19300,11,38210,0,0,0,0,0,9,0,0,15,0,0,0,0,"Cabal Acolyte - On Friendly Between 0-50% Health - Cast 'Renew' (Heroic Dungeon)"),
(@ID,0,6,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Cabal Acolyte - At 15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Acolyte"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Acolyte"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Acolyte"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Acolyte"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Acolyte"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Acolyte");

-- Cabal Summoner SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: Use the 'Summon Aid' (33505) spell if related to this NPC
SET @ID := 18634;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Summoner - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,1800,6200,4800,16900,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Summoner - In Combat - Cast 'Fireball' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,1800,6200,4800,16900,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Summoner - In Combat - Cast 'Fireball' (Heroic Dungeon)"),
(@ID,0,3,5,0,0,100,0,4300,17200,13300,25300,11,33506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - In Combat - Cast 'Summon Cabal Deathsworn'"),
(@ID,0,4,6,0,0,100,0,3600,33200,12100,27900,11,33507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - In Combat - Cast 'Summon Cabal Acolyte'"),
(@ID,0,5,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - On Link - Say Line 1"),
(@ID,0,6,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - On Link - Say Line 2"),
(@ID,0,7,0,17,0,100,0,19208,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - On Summoned Unit - Say Line 3"),
(@ID,0,8,0,17,0,100,0,19209,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Summoner - On Summoned Unit - Say Line 4");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Summoner"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Summoner"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Summoner"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Summoner"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Summoner"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Summoner"),
(@ID,1,0,"%s begins to summon in a Cabal Deathsworn!",16,0,100,0,0,0,16271,0,"Cabal Summoner"),
(@ID,2,0,"%s begins to summon in a Cabal Acolyte!",16,0,100,0,0,0,16275,0,"Cabal Summoner"),
(@ID,3,0,"%s summons a Cabal Acolyte to his aid!",16,0,100,0,0,0,16278,0,"Cabal Summoner"),
(@ID,4,0,"%s summons a Cabal Deathsworn to his aid!",16,0,100,0,0,0,16280,0,"Cabal Summoner");

-- Cabal Deathsworn SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18635;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Deathsworn - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,10200,18100,14100,26200,11,33480,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Deathsworn - In Combat - Cast 'Black Cleave' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,10200,18100,14100,26200,11,38226,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Deathsworn - In Combat - Cast 'Black Cleave' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,0,10900,28200,12100,22900,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Deathsworn - In Combat - Cast 'Knockdown'"),
(@ID,0,4,5,2,0,100,1,0,25,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Deathsworn - Between 0-25% Health - Cast 'Enrage'(No Repeat)"),
(@ID,0,5,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Deathsworn - On Link - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Deathsworn"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Deathsworn"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Deathsworn"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Deathsworn"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Deathsworn"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Deathsworn"),
(@ID,1,0,"%s goes into a frenzy!",16,0,100,0,0,0,2384,0,"Cabal Deathsworn");

-- Cabal Assassin SAI (Source: ACID)
-- TO-DO: Wound Poison (30983 36975) isn't related?
SET @ID := 18636;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,7000,4500,6500,11,30992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Assassin - In Combat - Cast 'Backstab'");

-- Cabal Shadow Priest SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18637;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Shadow Priest - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,3200,10800,4800,9700,11,17165,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Shadow Priest - In Combat - Cast 'Mind Flay' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,3200,10800,2400,4800,11,38243,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Shadow Priest - In Combat - Cast 'Mind Flay' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,2,3600,12100,5400,12900,11,14032,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cabal Shadow Priest - In Combat - Cast 'Shadow Word: Pain' (Normal Dungeon)"),
(@ID,0,4,0,0,0,100,4,3100,12100,4800,7200,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cabal Shadow Priest - In Combat - Cast 'Shadow Word: Pain' (Heroic Dungeon)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Shadow Priest"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Shadow Priest"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Shadow Priest"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Shadow Priest"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Shadow Priest"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Shadow Priest");

-- Cabal Zealot SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18638;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Zealot - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,0,0,3400,4500,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Zealot - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,0,0,3400,4500,11,15472,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Zealot - In Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(@ID,0,3,4,2,0,100,1,0,50,0,0,11,33949,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - Between 0-50% Health - Cast 'Shape of the Beast' (No Repeat)"),
(@ID,0,4,5,61,0,100,0,0,0,0,0,11,33499,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - On Link - Cast 'Shape of the Beast'"),
(@ID,0,5,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Zealot - On Link - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Zealot"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Zealot"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Zealot"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Zealot"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Zealot"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Zealot"),
(@ID,1,0,"%s makes some strange gestures.",16,8,100,0,0,0,16259,0,"Cabal Zealot");

-- Cabal Spellbinder SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18639;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Spellbinder - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,5700,19300,9600,16900,11,32691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Spellbinder - In Combat - Cast 'Spell Shock'"),
(@ID,0,2,0,0,0,100,0,8000,12000,20000,30000,11,33502,1,0,0,0,0,6,0,0,0,0,0,0,0,"Cabal Spellbinder - In Combat - Cast 'Brain Wash'"),
(@ID,0,3,0,23,0,100,1,8734,1,0,0,11,8734,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Spellbinder - On Has Aura - Cast 'Blackfathom Channeling' (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Spellbinder"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Spellbinder"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Spellbinder"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Spellbinder"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Spellbinder"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Spellbinder");

-- Cabal Warlock SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18640;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,1000,1000,30000,30000,11,13787,32,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - Out of Combat - Cast 'Demon Armor'"),
(@ID,0,1,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Warlock - On Aggro - Say Line 0"),
(@ID,0,2,0,0,0,100,2,0,0,3600,4800,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Warlock - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,0,0,3600,4800,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Warlock - In Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,2,7800,24100,19300,36200,11,32863,32,0,0,0,0,5,0,0,0,0,0,0,0,"Cabal Warlock - In Combat - Cast 'Seed of Corruption' (Normal Dungeon)"),
(@ID,0,5,0,0,0,100,4,7800,24100,19300,36200,11,38252,32,0,0,0,0,5,0,0,0,0,0,0,0,"Cabal Warlock - In Combat - Cast 'Seed of Corruption' (Heroic Dungeon)"),
(@ID,0,6,0,0,0,100,0,3100,5300,3100,5300,11,13787,32,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Warlock - In Combat - Cast 'Demon Armor'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Warlock"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Warlock"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Warlock"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Warlock"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Warlock"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Warlock");

-- Cabal Familiar SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18641;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,0,0,2400,3600,11,20801,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Familiar - In Combat CMC - Cast 'Firebolt' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,0,0,2400,3600,11,38239,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Familiar - In Combat CMC - Cast 'Firebolt' (Heroic Dungeon)");

-- Fel Guardhound SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18642;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,4800,14500,12100,18100,11,30849,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Guardhound - In Combat - Cast 'Spell Lock'");

-- Maiden of Discipline SAI (Source: ACID)
SET @ID := 18663;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,11000,12000,18000,11,31865,0,0,0,0,0,6,0,0,0,0,0,0,0,"Maiden of Discipline - In Combat - Cast 'Seduction' (Dungeon)"),
(@ID,0,1,0,0,0,100,0,9100,9100,8000,12000,11,32202,0,0,0,0,0,2,0,0,0,0,0,0,0,"Maiden of Discipline - In Combat - Cast 'Lash of Pain' (Dungeon)");

-- Cabal Ritualist SAI (Source: ACID 4.3.4 OD - N/H)
-- Phases and equipment are linked together
-- (Source: https://www.youtube.com/watch?v=OM-TmH_3UVM & Wowhead)
SET @ID := 18794;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,1,1000,1000,0,0,11,32958,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Out of Combat - Cast 'Crystal Channel' (No Repeat)"),
-- Do not reset
(@ID,0,1,0,1,0,100,257,0,0,0,0,31,1,4,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Out of Combat - Set Random Phase (1-4) (No Repeat) (No Reset)"),
(@ID,0,2,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Ritualist - On Aggro - Say Line 0"),
-- Frost Bolt & Nova - White staff 12421
(@ID,0,3,0,66,0,100,0,1,0,0,0,71,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - On Enter Phase 1 - Change Equipment"),
(@ID,0,4,0,0,1,100,2,0,0,3400,4500,11,15497,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon) (Phase 1)"),
(@ID,0,5,0,0,1,100,4,0,0,3400,4500,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat CMC - Cast 'Frostbolt' (Heroic Dungeon) (Phase 1)"),
(@ID,0,6,0,0,1,100,2,10000,18000,12100,16900,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Frost Nova' (Normal Dungeon) (Phase 1)"),
(@ID,0,7,0,0,1,100,4,10000,18000,12100,16900,11,15063,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Frost Nova' (Normal Dungeon) (Phase 1)"),
-- Arcane Missiles - Yellow staff 14618
(@ID,0,8,0,66,0,100,0,2,0,0,0,71,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - On Enter Phase 2 - Change Equipment"),
(@ID,0,9,0,0,2,100,2,0,0,5000,5000,11,33832,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat CMC - Cast 'Arcane Missiles' (Normal Dungeon) (Phase 2)"),
(@ID,0,10,0,0,2,100,4,0,0,5000,5000,11,38263,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat CMC - Cast 'Arcane Missiles' (Heroic Dungeon) (Phase 2)"),
(@ID,0,11,0,0,2,100,0,2400,14300,5200,21700,11,33487,1,0,0,0,0,5,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Addle Humanoid' (Phase 2)"),
-- Flame Buffet & Fire Blast - Sword 13718
(@ID,0,12,0,66,0,100,0,4,0,0,0,71,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - On Enter Phase 3 - Change Equipment"),
(@ID,0,13,0,0,4,100,0,3600,6200,4800,11200,11,9574,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Flame Buffet' (Phase 3)"),
(@ID,0,14,0,0,4,100,2,6100,20200,8400,22900,11,20795,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Fire Blast' (Normal Dungeon) (Phase 3)"),
(@ID,0,15,0,0,4,100,4,6100,20200,8400,22900,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Fire Blast' (Heroic Dungeon) (Phase 3)"),
-- Gouge - Daggers 19980
(@ID,0,16,0,66,0,100,0,8,0,0,0,71,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - On Enter Phase 4 - Change Equipment"),
(@ID,0,17,0,0,8,100,0,10000,15000,12100,19300,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Gouge' (Phase 4)"),
(@ID,0,18,0,15,0,100,4,15,15000,20000,0,11,17201,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Ritualist - Friendly Crowd Controlled - Cast 'Dispel Magic' (Heroic Dungeon)"),
(@ID,0,19,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Ritualist"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Ritualist"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Ritualist"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Ritualist"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Ritualist"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Ritualist");

-- Fel Overseer SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18796;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fel Overseer - On Aggro - Say Line 0"),
(@ID,0,1,0,4,0,100,0,0,0,0,0,11,27577,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fel Overseer - On Aggro - Cast 'Intercept'"),
(@ID,0,2,0,0,0,100,4,4800,9300,15700,20300,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Overseer - In Combat - Cast 'Mortal Strike' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,4,30000,30000,30000,30000,11,19134,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Overseer - In Combat - Cast 'Frightening Shout' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,0,13300,18900,15700,26500,11,30471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Overseer - In Combat - Cast 'Uppercut'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"This world shall burn!",12,0,100,0,0,0,16805,0,"Fel Overseer"),
(@ID,0,1,"The end is come!",12,0,100,0,0,0,16807,0,"Fel Overseer"),
(@ID,0,2,"Embrace the Nothing!",12,0,100,0,0,0,16808,0,"Fel Overseer"),
(@ID,0,3,"Pathetic worm!",12,0,100,0,0,0,16809,0,"Fel Overseer"),
(@ID,0,4,"None can stand against the Legion!",12,0,100,0,0,0,16810,0,"Fel Overseer"),
(@ID,0,5,"I'll feast on your soul!",12,0,100,0,0,0,16811,0,"Fel Overseer"),
(@ID,0,6,"You shall not escape.",12,0,100,0,0,0,16812,0,"Fel Overseer"),
(@ID,0,7,"The only justice is death!",12,0,100,0,0,0,16813,0,"Fel Overseer");

-- Cabal Fanatic SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18830;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cabal Fanatic - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,9600,20500,13300,22900,11,12021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cabal Fanatic - In Combat - Cast 'Fixate'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Ruin finds us all!",12,0,100,0,0,0,16798,0,"Cabal Fanatic"),
(@ID,0,1,"In Sargeras' name!",12,0,100,0,0,0,16799,0,"Cabal Fanatic"),
(@ID,0,2,"The end comes for you!",12,0,100,0,0,0,16800,0,"Cabal Fanatic"),
(@ID,0,3,"I do as I must!",12,0,100,0,0,0,16801,0,"Cabal Fanatic"),
(@ID,0,4,"The Legion reigns!",12,0,100,0,0,0,16802,0,"Cabal Fanatic"),
(@ID,0,5,"I shall be rewarded!",12,0,100,0,0,0,16803,0,"Cabal Fanatic");

-- Malicious Instructor SAI (Source: ACID 4.3.4 OD - N/H)
SET @ID := 18848;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Malicious Instructor - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,4,16100,25300,21700,25300,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Malicious Instructor - In Combat - Cast 'Disarm' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,0,10800,15700,18100,29100,11,33493,32,0,0,0,0,2,0,0,0,0,0,0,0,"Malicious Instructor - In Combat - Cast 'Mark of Malice'"),
(@ID,0,3,0,0,0,100,0,9600,16900,7200,18100,11,33501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malicious Instructor - In Combat - Cast 'Shadow Nova'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"This world shall burn!",12,0,100,0,0,0,16805,0,"Malicious Instructor"),
(@ID,0,1,"The end is come!",12,0,100,0,0,0,16807,0,"Malicious Instructor"),
(@ID,0,2,"Embrace the Nothing!",12,0,100,0,0,0,16808,0,"Malicious Instructor"),
(@ID,0,3,"Pathetic worm!",12,0,100,0,0,0,16809,0,"Malicious Instructor"),
(@ID,0,4,"None can stand against the Legion!",12,0,100,0,0,0,16810,0,"Malicious Instructor"),
(@ID,0,5,"I'll feast on your soul!",12,0,100,0,0,0,16811,0,"Malicious Instructor"),
(@ID,0,6,"You shall not escape.",12,0,100,0,0,0,16812,0,"Malicious Instructor"),
(@ID,0,7,"The only justice is death!",12,0,100,0,0,0,16813,0,"Malicious Instructor");

-- Summoned Cabal Acolyte SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: What exactly happens after evade?
-- TO-DO: Spawn spell missing
SET @ID := 19208;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,11,33482,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - On Just Summoned - Cast 'Shadow Defense'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - On Link - Set In Combat With Zone"),
(@ID,0,2,0,74,0,100,2,0,60,15700,27700,11,12039,0,0,0,0,0,9,0,0,15,0,0,0,0,"Summoned Cabal Acolyte - On Friendly Between 0-60% Health - Cast 'Heal' (Normal Dungeon)"),
(@ID,0,3,0,74,0,100,4,0,60,15700,27700,11,38209,0,0,0,0,0,9,0,0,15,0,0,0,0,"Summoned Cabal Acolyte - On Friendly Between 0-60% Health - Cast 'Heal' (Heroic Dungeon)"),
(@ID,0,4,0,74,0,100,2,0,50,13200,19300,11,25058,0,0,0,0,0,9,0,0,15,0,0,0,0,"Summoned Cabal Acolyte - On Friendly Between 0-50% Health - Cast 'Renew' (Normal Dungeon)"),
(@ID,0,5,0,74,0,100,4,0,50,13200,19300,11,38210,0,0,0,0,0,9,0,0,15,0,0,0,0,"Summoned Cabal Acolyte - On Friendly Between 0-50% Health - Cast 'Renew' (Heroic Dungeon)"),
(@ID,0,6,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ID,0,7,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - On Evade - Despawn (0)"),
(@ID,0,8,0,7,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Acolyte - On Evade - Set Flag Not Selectable");

-- Summoned Cabal Deathsworn SAI (Source: ACID 4.3.4 OD - N/H)
-- TO-DO: What exactly happens after evade?
-- TO-DO: Spawn spell missing
SET @ID := 19209;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - On Just Summoned - Set In Combat With Zone"),
(@ID,0,1,0,0,0,100,2,10200,18100,14100,26200,11,33480,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - In Combat - Cast 'Black Cleave' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,10200,18100,14100,26200,11,38226,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - In Combat - Cast 'Black Cleave' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,0,10900,28200,12100,22900,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - In Combat - Cast 'Knockdown'"),
(@ID,0,4,5,2,0,100,1,0,25,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(@ID,0,5,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - On Link - Say Line 0"),
(@ID,0,6,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - On Evade - Despawn (0)"),
(@ID,0,7,0,7,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Cabal Deathsworn - On Evade - Set Flag Not Selectable");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,2384,0,"Summoned Cabal Deathsworn");
