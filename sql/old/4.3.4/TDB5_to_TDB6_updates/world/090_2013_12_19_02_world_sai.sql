-- Bloodscalp Shaman
SET @ENTRY := 697;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,4097,0, '');

-- Defias Conjurer SAI
SET @ENTRY := 619;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Conjurer - In Combat - Cast Fireball"),
(@ENTRY,0,2,0,2,0,100,0,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjurer - Between 0-15% Health - Flee For Assist");

-- Razormane Stalker SAI
SET @ENTRY := 3457;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature` SET `modelid`=0, `curhealth`=1 WHERE `id`=3457;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1000,1000,11,22766,32,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Stalker - In Combat - Cast Sneak"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,1000,1000,11,1758,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Stalker - In Combat - Cast Sinister Strike");

-- Dark Rune Elementalist SAI
SET @ENTRY := 27962;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (126700,126702,126704);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,4097,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,6,0,0,0,0,11,51475,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Out Of Combat - Cast Summon Air Elemental (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,600000,600000,11,51776,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Out Of Combat - Cast Lightning Shield (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,0,0,4000,6000,11,53314,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Elementalist - In Combat - Cast Lightning Bolt (Normal Dungeon)"),
(@ENTRY,0,3,0,1,0,100,4,1000,1000,600000,600000,11,59025,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Out Of Combat - Cast Lightning Shield (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,4,0,0,4000,6000,11,59024,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Elementalist - In Combat - Cast Lightning Bolt (Heroic Dungeon)"),
(@ENTRY,0,5,0,2,0,100,7,0,30,0,0,11,32693,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Elementalist - Between 0-30% Health - Cast Arcane Haste (Dungeon Only)");

-- Felboar SAI
SET @ENTRY := 21878;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,33908,32,0,0,0,0,1,0,0,0,0,0,0,0,"Felboar - On Spawn - Cast Burning Spikes"),
(@ENTRY,0,1,0,0,0,100,0,100,100,30000,55000,11,35570,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felboar - In Combat - Cast Charge");
