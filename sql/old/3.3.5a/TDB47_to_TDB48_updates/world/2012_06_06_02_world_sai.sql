-- Fix Quest 11307 "Field Test"

-- Remove hack
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=43385;

-- Fix Plagued Proto-Dragon
UPDATE `creature_addon` SET `bytes1`=50331648 WHERE guid=107626;

-- Plagued Dragonflayer Tribesman SAI
SET @ENTRY  := 23564;
SET @SPELL1 := 15496; -- Cleave
SET @SPELL2 := 32736; -- Mortal Strike
SET @SPELL3 := 43506; -- Plague Blight
SET @SPELL4 := 43381; -- Plague Spray
SET @SPELL5 := 43384; -- Plague Credit
SET @SPELL6 := 43327; -- Vomit
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
UPDATE `creature_addon` SET `auras`= '21862' WHERE guid IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (@ENTRY,1,'21862');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,95,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - HP@95% - Set Phase 1'),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,4000,5000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - Combat - Cast Cleave'),
(@ENTRY,0,2,0,0,0,100,0,2000,4000,5000,8000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - Combat - Cast Mortal Strike'),
(@ENTRY,0,3,0,2,0,100,1,0,75,0,0,11,@SPELL3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - HP@75% - Cast Plague Blight'),
(@ENTRY,0,4,0,23,1,100,0,@SPELL4,1,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - On Aura - Set phase 0 (phase 1)'),
(@ENTRY,0,5,0,0,1,100,0,1000,1000,1000,1000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - Combat - Set phase 2 (phase 1)'),
(@ENTRY,0,6,0,23,2,100,0,@SPELL4,1,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - On Spell Hit - Set Phase 3 (phase 2)'),
(@ENTRY,0,7,0,0,4,100,0,0,0,10000,10000,49,0,0,0,0,0,0,5,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - Combat - Attack Random target (phase 3)'),
(@ENTRY,0,8,0,6,4,100,0,0,0,0,0,85,@SPELL5,0,0,0,0,0,16,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - On Death - Give Killcredit (phase 3)'),
(@ENTRY,0,9,0,1,0,35,0,0,30000,25000,45000,11,@SPELL6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - OOC - Cast 43327 on self'),
(@ENTRY,0,10,11,23,0,100,1,@SPELL4,1,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - On Spell Hit - Say 0'),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,2,1925,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Tribesman - On Spell Hit - Set Faction');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s loses all self control and begins to attack friend and foe alike!',16,0,100,0,0,0,'Plagued Dragonflayer Tribesman');

-- Plagued Dragonflayer Rune-Caster SAI
SET @ENTRY  := 24199;
SET @SPELL1 := 47782; -- Corruption
SET @SPELL2 := 15616; -- Flame Shock
SET @SPELL3 := 43381; -- Plague Spray
SET @SPELL4 := 43384; -- Plague Credit
SET @SPELL5 := 43327; -- Vomit
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
UPDATE `creature_addon` SET `auras`= '21862' WHERE guid IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (@ENTRY,1,'21862');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,95,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - HP@95% - Set Phase 1'),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - On aggro - Cast Corruption'),
(@ENTRY,0,2,0,0,0,100,0,2000,4000,15000,17000,11,@SPELL2,0,0,0,0,0,5,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - Combat - Cast Flame Shock'),
(@ENTRY,0,3,0,23,1,100,0,@SPELL3,1,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - On Aura - Set phase 0 (phase 1)'),
(@ENTRY,0,4,0,0,1,100,0,1000,1000,1000,1000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - Combat - Set phase 2 (phase 1)'),
(@ENTRY,0,5,0,23,2,100,0,@SPELL3,1,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - On Spell Hit - Set Phase 3 (phase 2)'),
(@ENTRY,0,6,0,0,4,100,0,0,0,10000,10000,49,0,0,0,0,0,0,5,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - Combat - Attack Random target (phase 3)'),
(@ENTRY,0,7,0,6,4,100,0,0,0,0,0,85,@SPELL4,0,0,0,0,0,16,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - On Death - Give Killcredit (phase 3)'),
(@ENTRY,0,8,0,1,0,35,0,0,30000,25000,45000,11,@SPELL5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - OOC - Cast 43327 on self'),
(@ENTRY,0,9,10,23,0,100,1,@SPELL3,1,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - On Spell Hit - Say 0'),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,2,1925,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Rune-Caster - On Spell Hit - Set Faction');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s loses all self control and begins to attack friend and foe alike!',16,0,100,0,0,0,'Plagued Dragonflayer Rune-Caster');

-- Plagued Dragonflayer Handler SAI
SET @ENTRY  := 24199;
SET @SPELL1 := 43506; -- Plague Blight
SET @SPELL2 := 43381; -- Plague Spray
SET @SPELL3 := 43384; -- Plague Credit
SET @SPELL4 := 43327; -- Vomit
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
UPDATE `creature_addon` SET `auras`= '21862' WHERE guid IN (SELECT guid FROM creature WHERE id=@ENTRY);
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (@ENTRY,1,'21862');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,95,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Handler - HP@95% - Set Phase 1'),
(@ENTRY,0,1,0,2,0,100,1,0,75,0,0,11,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Handler - HP@75% - Cast Plague Blight'),
(@ENTRY,0,2,0,23,1,100,0,@SPELL2,1,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Handler - On Aura - Set phase 0 (phase 1)'),
(@ENTRY,0,3,0,0,1,100,0,1000,1000,1000,1000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Handler - Combat - Set phase 2 (phase 1)'),
(@ENTRY,0,4,0,23,2,100,0,@SPELL2,1,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Handler - On Spell Hit - Set Phase 3 (phase 2)'),
(@ENTRY,0,5,0,0,4,100,0,0,0,10000,10000,49,0,0,0,0,0,0,5,0,0,0,0,0,0,0,'Plagued Dragonflayer Handler - Combat - Attack Random target (phase 3)'),
(@ENTRY,0,6,0,6,4,100,0,0,0,0,0,85,@SPELL3,0,0,0,0,0,16,0,0,0,0,0,0,0,'Plagued Dragonflayer Handler - On Death - Give Killcredit (phase 3)'),
(@ENTRY,0,7,0,1,0,35,0,0,30000,25000,45000,11,@SPELL4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Handler - OOC - Cast 43327 on self'),
(@ENTRY,0,8,9,23,0,100,1,@SPELL2,1,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,'Plagued Dragonflayer Handler - On Spell Hit - Say 0'),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,2,1925,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Dragonflayer Handler - On Spell Hit - Set Faction');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s loses all self control and begins to attack friend and foe alike!',16,0,100,0,0,0,'Plagued Dragonflayer Handler');
