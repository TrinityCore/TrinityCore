-- Remove wrong unconfirmed by sniffs Soul Mirror spawns
DELETE FROM `gameobject` WHERE `guid` IN (50349,50350,50351,50352,50353) AND `id` = 183441;
DELETE FROM `gameobject_addon` WHERE `guid` IN (50349,50350,50351,50352,50353);

DELETE FROM `creature_template_addon` WHERE `entry` IN (18498,20321,18521,20315,18524,20298,18556,20311,18700,20317);
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(18498,"32828"), -- Protection Aura -- Unliving Soldier
(20321,"32828"), -- Protection Aura -- Unliving Soldier
(18521,"10095"), -- Hate to Zero -- Angered Skeleton
(20315,"10095"), -- Hate to Zero -- Angered Skeleton
(18524,"32885"), -- Infuriate -- Angered Skeleton
(20298,"32885"), -- Infuriate -- Angered Skeleton
(18556,"32828"), -- Protection Aura -- Phasing Soldier
(20311,"32828"), -- Protection Aura -- Phasing Soldier
(18700,"19818"), -- Double Attack -- Reanimated Bones
(20317,"19818"); -- Double Attack -- Reanimated Bones

-- Avatar of the Martyred SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
-- Original script was without initial timers for the 'Sunder Armor'
SET @ID := 18478;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,6500,11500,6200,15700,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avatar of the Martyred - In Combat - Cast 'Sunder Armor'"),
(@ID,0,1,0,0,0,100,0,12100,16800,10900,24100,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Avatar of the Martyred - In Combat - Cast 'Mortal Strike'");

-- Auchenai Soulpriest SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18493;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,2,0,0,3600,4800,11,32860,64,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,0,0,3600,4800,11,38378,64,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,2,10800,19300,18300,33700,11,32858,1,0,0,0,0,5,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Cast 'Touch of the Forgotten' (Normal Dungeon)"),
(@ID,0,4,0,0,0,100,4,10800,13300,16900,27700,11,38377,1,0,0,0,0,5,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Cast 'Touch of the Forgotten' (Heroic Dungeon)"),
(@ID,0,5,0,2,0,100,0,0,50,19200,37400,11,32859,33,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - Between 0-50% Health - Cast 'Falter'"),
(@ID,0,6,0,0,0,100,1,2000,5000,0,0,88,@ID*100+0,@ID*100+4,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - In Combat - Run Random Script (No Repeat)");

-- Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+4 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,11,32853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Script - Cast 'Summon Unliving Soldier'"),
(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,11,32854,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Script - Cast 'Summon Unliving Sorcerer'"),
(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,11,32855,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Script - Cast 'Summon Unliving Cleric'"),
(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,11,32856,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Script - Cast 'Summon Unliving Stalker'"),
(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,11,32857,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Soulpriest - On Script - Cast 'Summon Phantasmal Possessor'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"You will rest with the honored dead.",12,0,100,0,0,0,16788,0,"Auchenai Soulpriest"),
(@ID,0,1,"You have chosen death.",12,0,100,0,0,0,16791,0,"Auchenai Soulpriest"),
(@ID,0,2,"You will pay for this violation.",12,0,100,0,0,0,16793,0,"Auchenai Soulpriest"),
(@ID,0,3,"Shhh! The spirits are sleeping!",12,0,100,0,0,0,16797,0,"Auchenai Soulpriest");

-- Auchenai Vindicator SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18495;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,2,1000,1000,30000,30000,11,32861,32,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - Out of Combat - Cast 'Shadowguard' (Normal Dungeon)"),
(@ID,0,1,0,1,0,100,4,1000,1000,30000,30000,11,38379,32,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - Out of Combat - Cast 'Shadowguard' (Heroic Dungeon)"),
(@ID,0,2,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Auchenai Vindicator - On Aggro - Say Line 0"),
(@ID,0,3,0,0,0,100,2,3100,5300,3100,5300,11,32861,32,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - In Combat - Cast 'Shadowguard' (Normal Dungeon)"),
(@ID,0,4,0,0,0,100,4,3100,5300,3100,5300,11,38379,32,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - In Combat - Cast 'Shadowguard' (Heroic Dungeon)"),
(@ID,0,5,0,0,0,100,2,7200,13300,18100,25300,11,17439,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Vindicator - In Combat - Cast 'Shadow Shock' (Normal Dungeon)"),
(@ID,0,6,0,0,0,100,4,7200,10900,15700,24100,11,17289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Vindicator - In Combat - Cast 'Shadow Shock' (Heroic Dungeon)"),
(@ID,0,7,0,0,0,100,1,2000,5000,0,0,88,1849300,1849304,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Vindicator - In Combat - Run Random Script (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"You will rest with the honored dead.",12,0,100,0,0,0,16788,0,"Auchenai Vindicator"),
(@ID,0,1,"You have chosen death.",12,0,100,0,0,0,16791,0,"Auchenai Vindicator"),
(@ID,0,2,"You will pay for this violation.",12,0,100,0,0,0,16793,0,"Auchenai Vindicator"),
(@ID,0,3,"Shhh! The spirits are sleeping!",12,0,100,0,0,0,16797,0,"Auchenai Vindicator");

-- Auchenai Monk SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18497;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,1000,3000,30000,30000,11,38168,32,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - Out of Combat - Cast 'Spiritual Sight'"),
(@ID,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Auchenai Monk - On Aggro - Say Line 0"),
(@ID,0,2,0,0,0,100,0,3100,5300,3100,5300,11,38168,32,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - In Combat - Cast 'Spiritual Sight'"),
(@ID,0,3,0,0,0,100,0,11500,14000,16900,30100,11,32849,0,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - In Combat - Cast 'Cyclone Strike'"),
(@ID,0,4,0,0,0,100,0,18100,40400,20500,33700,11,37321,0,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Monk - In Combat - Cast 'Overpower'"),
(@ID,0,5,0,13,0,100,0,8400,19300,0,0,11,32846,1,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Monk - Target Casting - Cast 'Counter Kick'"),
(@ID,0,6,0,0,0,100,1,2000,5000,0,0,88,1849300,1849304,0,0,0,0,1,0,0,0,0,0,0,0,"Auchenai Monk - In Combat - Run Random Script (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"You will rest with the honored dead.",12,0,100,0,0,0,16788,0,"Auchenai Monk"),
(@ID,0,1,"You have chosen death.",12,0,100,0,0,0,16791,0,"Auchenai Monk"),
(@ID,0,2,"You will pay for this violation.",12,0,100,0,0,0,16793,0,"Auchenai Monk"),
(@ID,0,3,"Shhh! The spirits are sleeping!",12,0,100,0,0,0,16797,0,"Auchenai Monk");

-- Unliving Soldier SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18498;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,11,33422,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Soldier - On Just Summoned - Cast 'Phase In'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Soldier - On Link - Set In Combat With Zone"),
(@ID,0,2,0,0,0,100,0,4800,10900,7200,14500,11,11972,32,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Soldier - In Combat - Cast 'Shield Bash'"),
(@ID,0,3,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Soldier - On Evade - Despawn (0)");

-- Unliving Sorcerer SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18499;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,11,33422,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - On Just Summoned - Cast 'Phase In'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - On Link - Set In Combat With Zone"),
(@ID,0,2,0,0,0,100,2,0,0,2400,3800,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Sorcerer - In Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,0,0,2400,3800,11,17290,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Sorcerer - In Combat CMC - Cast 'Fireball' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,2,3600,7800,7800,14500,11,15043,1,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Sorcerer - In Combat - Cast 'Frostbolt' (Normal Dungeon)"),
(@ID,0,5,0,0,0,100,4,6000,8000,7800,14500,11,15530,1,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Sorcerer - In Combat - Cast 'Frostbolt' (Heroic Dungeon)"),
(@ID,0,6,0,0,0,100,2,10900,16900,9700,15700,11,15744,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - In Combat - Cast 'Blast Wave' (Normal Dungeon)"),
(@ID,0,7,0,0,0,100,4,10900,16900,7200,10900,11,22424,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - In Combat - Cast 'Blast Wave' (Heroic Dungeon)"),
(@ID,0,8,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Sorcerer - On Evade - Despawn (0)");

-- Unliving Cleric SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18500;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,11,33422,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Cleric - On Just Summoned - Cast 'Phase In'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Cleric - On Link - Set In Combat With Zone"),
(@ID,0,2,0,74,0,100,2,0,85,9700,16800,11,25058,0,0,0,0,0,9,0,0,20,0,0,0,0,"Unliving Cleric - On Friendly Between 0-85% Health - Cast 'Renew' (Normal Dungeon)"),
(@ID,0,3,0,74,0,100,4,0,85,9700,16800,11,38210,0,0,0,0,0,9,0,0,20,0,0,0,0,"Unliving Cleric - On Friendly Between 0-85% Health - Cast 'Renew' (Heroic Dungeon)"),
(@ID,0,4,0,74,0,100,2,0,70,12100,16900,11,33324,1,0,0,0,0,9,0,0,20,0,0,0,0,"Unliving Cleric - On Friendly Between 0-70% Health - Cast 'Major Heal' (Normal Dungeon)"),
(@ID,0,5,0,74,0,100,4,0,70,10800,16900,11,22883,1,0,0,0,0,9,0,0,20,0,0,0,0,"Unliving Cleric - On Friendly Between 0-70% Health - Cast 'Heal' (Heroic Dungeon)"),
(@ID,0,6,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Cleric - On Evade - Despawn (0)");

-- Unliving Stalker SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18501;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,11,33422,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - On Just Summoned - Cast 'Phase In'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - On Link - Set In Combat With Zone"),
(@ID,0,2,0,0,0,100,2,0,0,2400,4800,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Stalker - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,0,0,2400,4800,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Stalker - In Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,2,10000,14000,13300,22900,11,31975,0,0,0,0,0,5,0,0,0,0,0,0,0,"Unliving Stalker - In Combat - Cast 'Serpent Sting' (Normal Dungeon)"),
(@ID,0,5,0,0,0,100,4,10000,14000,15700,22900,11,35511,0,0,0,0,0,5,0,0,0,0,0,0,0,"Unliving Stalker - In Combat - Cast 'Serpent Sting' (Heroic Dungeon)"),
(@ID,0,6,0,0,0,100,4,6000,11000,12000,16000,11,37551,1,0,0,0,0,6,0,0,0,0,0,0,0,"Unliving Stalker - In Combat - Cast 'Viper Sting' (Heroic Dungeon)"),
(@ID,0,7,0,0,0,100,0,2400,10400,3900,7200,11,32829,32,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - In Combat - Cast 'Spirit Vengeance'"),
(@ID,0,8,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Stalker - On Evade - Despawn (0)");

-- Phantasmal Possessor SAI (Source: ACID)
SET @ID := 18503;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,11,33422,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Possessor - On Just Summoned - Cast 'Phase In'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Possessor - On Link - Set In Combat With Zone"),
(@ID,0,2,0,0,0,100,0,5000,10000,20000,30000,11,33401,0,0,0,0,0,6,0,0,0,0,0,0,0,"Phantasmal Possessor - In Combat - Cast 'Possess'"),
(@ID,0,3,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantasmal Possessor - On Evade - Despawn (0)");

-- Raging Soul SAI (Source: ACID & Movies)
-- TO-DO: Use spells 'Raging Soul' (32887)(N) & 'Raging Soul' (38381)(H) if they're related
-- TO-DO: This script is incomplete and probably wrong, sniffs tells absolutely nothing to me
-- Seems they shouldn't despawn like this
-- Seems like they shouldn't be invisible because of actions used right now
SET @ID := 18506;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,25,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Soul - On Reset - Stop Attacking"),
(@ID,0,1,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Soul - On Reset - Set Visibility Off"),
(@ID,0,2,0,4,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Soul - On Aggro - Set Visibility On"),
-- Initial min and initial max are not supported
-- but if I'm not wrong they should start it if they're close enough to target
-- and after 2000-5000 sec after aggro
(@ID,0,3,5,9,0,100,3,0,2,0,0,11,32888,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Soul - Within 0-2 Range - Cast 'Rage' (Normal Dungeon) (No Repeat)"),
(@ID,0,4,5,9,0,100,5,0,2,0,0,11,38380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Soul - Within 0-2 Range - Cast 'Rage' (Heroic Dungeon) (No Repeat)"),
(@ID,0,5,0,61,0,100,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Soul - On Link - Despawn (6000)");

-- Phasing Soldier SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18556;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,13,0,100,1,7200,18100,0,0,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Soldier - Target Casting - Cast 'Shield Bash' (No Repeat)");

-- Phasing Cleric SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18557;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,74,0,100,2,0,85,9700,16800,11,25058,0,0,0,0,0,9,0,0,20,0,0,0,0,"Phasing Cleric - On Friendly Between 0-85% Health - Cast 'Renew' (Normal Dungeon)"),
(@ID,0,1,0,74,0,100,4,0,85,9700,16800,11,38210,0,0,0,0,0,9,0,0,20,0,0,0,0,"Phasing Cleric - On Friendly Between 0-85% Health - Cast 'Renew' (Heroic Dungeon)"),
(@ID,0,2,0,74,0,100,2,0,70,12100,16900,11,33324,1,0,0,0,0,9,0,0,20,0,0,0,0,"Phasing Cleric - On Friendly Between 0-70% Health - Cast 'Major Heal' (Normal Dungeon)"),
(@ID,0,3,0,74,0,100,4,0,70,10800,16900,11,22883,1,0,0,0,0,9,0,0,20,0,0,0,0,"Phasing Cleric - On Friendly Between 0-70% Health - Cast 'Heal' (Heroic Dungeon)");

-- Phasing Sorcerer SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18558;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,0,0,2400,3800,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Sorcerer - In Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,0,0,2400,3800,11,17290,64,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Sorcerer - In Combat CMC - Cast 'Fireball' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,3600,7800,7800,14500,11,15043,1,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Sorcerer - In Combat - Cast 'Frostbolt' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,6000,8000,7800,14500,11,15530,1,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Sorcerer - In Combat - Cast 'Frostbolt' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,2,10900,16900,9700,15700,11,15744,1,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - In Combat - Cast 'Blast Wave' (Normal Dungeon)"),
(@ID,0,5,0,0,0,100,4,10900,16900,7200,10900,11,22424,1,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Sorcerer - In Combat - Cast 'Blast Wave' (Heroic Dungeon)");

-- Phasing Stalker SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18559;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,0,0,2400,4800,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Stalker - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,0,0,2400,4800,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Phasing Stalker - In Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,10000,14000,13300,22900,11,31975,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phasing Stalker - In Combat - Cast 'Serpent Sting' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,10000,14000,15700,22900,11,35511,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phasing Stalker - In Combat - Cast 'Serpent Sting' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,4,6000,11000,12000,16000,11,37551,1,0,0,0,0,6,0,0,0,0,0,0,0,"Phasing Stalker - In Combat - Cast 'Viper Sting' (Heroic Dungeon)"),
(@ID,0,5,0,0,0,100,0,2400,10400,3900,7200,11,32829,32,0,0,0,0,1,0,0,0,0,0,0,0,"Phasing Stalker - In Combat - Cast 'Spirit Vengeance'");

-- Reanimated Bones SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18700;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,9000,5000,9000,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reanimated Bones - In Combat - Cast 'Sunder Armor'"),
(@ID,0,1,0,0,0,100,0,6000,14000,8000,14000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reanimated Bones - In Combat - Cast 'Strike'");

-- Auchenai Necromancer SAI (Source: ACID 4.3.4 Official Data - Normal/Heroic)
SET @ID := 18702;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,40,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Auchenai Necromancer - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,1000,15200,4800,15700,11,35839,32,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Necromancer - In Combat - Cast 'Drain Soul'"),
(@ID,0,2,0,0,0,100,2,12100,29000,22900,35000,11,32863,33,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Necromancer - In Combat - Cast 'Seed of Corruption' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,12100,17500,4800,9600,11,38252,33,0,0,0,0,2,0,0,0,0,0,0,0,"Auchenai Necromancer - In Combat - Cast 'Seed of Corruption' (Heroic Dungeon)"),
(@ID,0,4,0,74,0,100,2,0,70,15700,26500,11,33325,1,0,0,0,0,9,0,0,15,0,0,0,0,"Auchenai Necromancer - On Friendly Between 0-70% Health - Cast 'Shadow Mend' (Normal Dungeon)"),
(@ID,0,5,0,74,0,100,4,0,70,6100,8400,11,37367,1,0,0,0,0,9,0,0,15,0,0,0,0,"Auchenai Necromancer - On Friendly Between 0-70% Health - Cast 'Shadow Mend' (Heroic Dungeon)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"This is sacred ground!",12,0,100,0,0,10530,17641,0,"Auchenai Necromancer"),
(@ID,0,1,"How dare you come here?",12,0,100,0,0,10531,17642,0,"Auchenai Necromancer"),
(@ID,0,2,"Outsiders are forbidden!",12,0,100,0,0,10532,17643,0,"Auchenai Necromancer"),
(@ID,0,3,"This is sacred ground!",12,0,100,0,0,10533,17641,0,"Auchenai Necromancer"),
(@ID,0,4,"How dare you come here?",12,0,100,0,0,10534,17642,0,"Auchenai Necromancer"),
(@ID,0,5,"Outsiders are forbidden!",12,0,100,0,0,10535,17643,0,"Auchenai Necromancer"),
(@ID,0,6,"This is sacred ground!",12,0,100,0,0,10536,17641,0,"Auchenai Necromancer"),
(@ID,0,7,"How dare you come here?",12,0,100,0,0,10537,17642,0,"Auchenai Necromancer"),
(@ID,0,8,"Outsiders are forbidden!",12,0,100,0,0,10538,17643,0,"Auchenai Necromancer");
