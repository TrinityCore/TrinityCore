-- Dragonflayer Metalworker SAI
SET @ENTRY := 24078;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,1,233, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,0,11,0,100,6,0,0,0,0,11,43929,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Metalworker - On Spawn - Cast Fiery Weapon Proc");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'Dragonflayer Metalworker');

-- Zeth'Gor Quest Credit Marker, They Must Burn, Tower Foothill
SET @ENTRY := 24078;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,4097,0, '');

-- Plagued Dragonflayer Handler SAI
SET @ENTRY := 24199;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=10;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,10,0,11,0,100,6,0,0,0,0,11,21862,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Handler - On Spawn - Cast Radiation");

-- Plagued Dragonflayer Tribesman SAI
SET @ENTRY := 23564;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=12;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,12,0,11,0,100,6,0,0,0,0,11,21862,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Tribesman - On Spawn - Cast Radiation");

-- Murkgill Lord SAI
SET @ENTRY := 4460;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,1,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Murkgill Lord - In Combat CMC - Cast Frostbolt"),
(@ENTRY,0,2,0,0,0,100,0,9800,11100,16100,25700,11,38033,1,1,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - In Combat - Cast Frost Nova"),
(@ENTRY,0,3,0,2,0,100,1,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murkgill Lord - Between 0-15% Health - Flee For Assist");

-- Fordragon Marksman SAI
SET @ENTRY := 27540;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,65536,258,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,5000,7000,11,32103,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fordragon Marksman - In Combat CMC - Cast Shoot"),
(@ENTRY,0,1,0,0,0,100,0,10000,17000,10000,17000,11,7896,0,0,0,0,0,5,0,0,0,0,0,0,0,"Fordragon Marksman - Between In Combat - Cast Exploding Shot"),
(@ENTRY,0,2,0,0,0,100,0,12000,17000,22000,26000,11,49474,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fordragon Marksman - In Combat - Cast Rapid Shot");

-- Sunfury Nethermancer SAI
SET @ENTRY := 20248;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=@ENTRY) AND `bytes1`=0 AND `emote`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,300000,300000,11,36477,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - Out Of Combat - Cast Summon Mana Beast"),
(@ENTRY,0,1,0,9,0,100,0,500,500,3400,4800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Nethermancer - Combat CMC - Cast Shadow Bolt"),
(@ENTRY,0,2,0,0,0,100,0,0,0,30000,35000,11,35778,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunfury Nethermancer - In Combat - Cast Bloodcrystal Surge"),
(@ENTRY,0,3,0,2,0,100,0,0,75,15000,20000,11,17173,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 0-75% Health - Cast Drain Life"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Nethermancer - Between 0-15% Health - Flee For Assist");

-- Darkspear Axe Thrower SAI
SET @ENTRY := 18970;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,4097,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Axe Thrower - In Combat CMC - Cast Throw"),
(@ENTRY,0,1,0,2,0,100,1,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Darkspear Axe Thrower - Between 0-15% Health - Flee For Assist");

-- Blood of the Old God SAI
SET @ENTRY := 28854;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,52561,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood of the Old God - On Spawn - Cast Oil Coat"),
(@ENTRY,0,1,0,9,0,100,1,0,2,0,0,11,52564,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood of the Old God - Range 2 yards - Cast Corruption of the Old God");

-- Scourge Necromancer SAI
SET @ENTRY := 31096;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20298,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Necromancer - In Combat CMC - Cast Shadow Bolt"),
(@ENTRY,0,1,0,0,0,100,0,12000,15000,16000,19000,11,51337,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - In Combat - Cast Shadowflame"),
(@ENTRY,0,2,0,2,0,100,1,0,0,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - At 15% HP - Flee For Assist");

-- Venture Co. Geologist SAI
SET @ENTRY := 1096;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,4097,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Geologist - In Combat CMC - Cast 9532"),
(@ENTRY,0,1,0,0,0,100,0,5400,9600,24000,37200,11,184,1,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - In Combat - Cast 184"),
(@ENTRY,0,2,0,2,0,100,0,0,50,10100,19800,11,4979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-50% Health - Cast 4979"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-15% Health - Flee For Assist");

-- Death Knight Champion
SET @ENTRY := 27288;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;

-- Citizen of New Avalon
SET @ENTRY := 28942;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,1,0, '');

-- Deadwood Shaman SAI
SET @ENTRY := 7158;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_addon` SET `bytes2`=4097 WHERE `guid`=40394;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=@ENTRY) AND `path_id`=0;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,4097,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,600000,600000,11,13585,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwood Shaman - Out Of Combat - Cast 13585"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat CMC - Cast 9532"),
(@ENTRY,0,2,0,0,0,100,0,2500,7000,120000,130000,11,13583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat - Cast 13583"),
(@ENTRY,0,3,0,0,0,100,0,5500,9000,6500,9500,11,12058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwood Shaman - In Combat - Cast 12058");

-- Ahn'kahar Swarmer SAI
SET @ENTRY := 30338;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,1,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,6,0,0,0,0,11,56158,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Swarmer - On Spawn - Cast Swarm (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,56281,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Swarmer - On Spawn - Cast Swarm (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,100,6,1000,1000,35000,45000,11,56354,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Swarmer - In Combat - Cast Sprint (Dungeon Only)");

-- Deep Crawler SAI
SET @ENTRY := 30279;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY) AND `path_id`=0;
UPDATE `creature_addon` SET `auras`= '' WHERE `guid` IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,1,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,6,0,0,0,0,11,56583,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Crawler - On Spawn - Cast Combined Toxins (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,9000,12000,11,56580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deep Crawler - In Combat - Cast 56580 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,4000,7000,9000,12000,11,59108,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deep Crawler - In Combat - Cast 59108 (Heroic Dungeon)"),
(@ENTRY,0,3,0,12,0,100,2,0,20,14000,17000,11,56581,33,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Crawler - On Target Between 0-20% Health - Cast 56581 (Normal Dungeon)"),
(@ENTRY,0,4,0,12,0,100,4,0,20,14000,17000,11,59109,33,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Crawler - On Target Between 0-20% Health - Cast 59109 (Heroic Dungeon)");

UPDATE `smart_scripts` SET `comment`= "Inquisitor Salrand - On Spawn - Cast Cosmetic - Divine Shield Blue" WHERE `entryorguid`=25584 AND `source_type`=0 AND `id`=5;

-- Tree Warden Chawn SAI
SET @ENTRY := 22007;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,25000,25000,300000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tree Warden Chawn - Out of Combat - Say text 0"),
(@ENTRY,0,1,0,1,0,100,0,30000,30000,305000,305000,1,0,0,0,0,0,0,19,21983,10,0,0,0,0,0,"Tree Warden Chawn - Out of Combat - Samia Inkling Say text 0");
DELETE FROM `creature_text` WHERE `entry` IN (22007,21983);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(22007,0,0, 'Samia, do you know who Kolphis Darkscale is?',12,0,100,6,0,0, 'Tree Warden Chawn OOC text'),
(21983,0,0, 'Yes, he''s the second-in-command of the wyrmcult at the Blackwing Coven to the west.',12,0,100,1,0,0, 'Samia Inkling OOC text');
