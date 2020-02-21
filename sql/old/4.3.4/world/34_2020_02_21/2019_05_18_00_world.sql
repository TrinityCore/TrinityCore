-- Fix Quest 27941 "Fashionism" 

-- Dead Trooper SAI
SET @ENTRY := 47213;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,73,0,100,0,0,0,10000,10000,0,85,88068,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Cast 'Create Uniform'"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,0,11,87983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Cast 'Dead Trooper Transform 01'"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Set Unit Flag"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,0,28,85500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Remove aura 'Uldum Mercenary Kit'"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,0,28,85549,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Remove aura 'Cosmetic - Loot Sparkles (Mod Aura Vision 1)'"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Despawn"),
(@ENTRY,0,6,0,25,0,100,0,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Reset - Remove Unit Flag");

-- Dead Trooper SAI
SET @ENTRY := 47216;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,73,0,100,0,0,0,10000,10000,0,85,88068,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Cast 'Create Uniform'"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,0,11,87983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Cast 'Dead Trooper Transform 01'"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Set Unit Flag"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,0,28,85500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Remove aura 'Uldum Mercenary Kit'"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,0,28,85549,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Remove aura 'Cosmetic - Loot Sparkles (Mod Aura Vision 1)'"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Despawn"),
(@ENTRY,0,6,0,25,0,100,0,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Reset - Remove Unit Flag");

-- Dead Trooper SAI
SET @ENTRY := 47219;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,73,0,100,0,0,0,10000,10000,0,85,88068,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Cast 'Create Uniform'"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,0,11,87983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Cast 'Dead Trooper Transform 01'"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Set Unit Flag"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,0,28,85500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Remove aura 'Uldum Mercenary Kit'"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,0,28,85549,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Remove aura 'Cosmetic - Loot Sparkles (Mod Aura Vision 1)'"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Despawn"),
(@ENTRY,0,6,0,25,0,100,0,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Reset - Remove Unit Flag");

-- Dead Trooper SAI
SET @ENTRY := 47207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,73,0,100,0,0,0,10000,10000,0,85,88068,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Cast 'Create Uniform'"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,0,11,87983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Cast 'Dead Trooper Transform 01'"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Set Unit Flag"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,0,28,85500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Remove aura 'Uldum Mercenary Kit'"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,0,28,85549,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Remove aura 'Cosmetic - Loot Sparkles (Mod Aura Vision 1)'"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Spellclick - Despawn"),
(@ENTRY,0,6,0,25,0,100,0,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Trooper - On Reset - Remove Unit Flag");

-- Add Spell click to Dead Troopers
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (47213,47216,47219,47207);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(47213,87975,1,0),(47216,87975,1,0),(47219,87975,1,0),(47207,87975,1,0);

-- Fix Dead Troopers
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry` IN (47213,47216,47219,47207);
