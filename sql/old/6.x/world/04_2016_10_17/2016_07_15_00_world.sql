-- Tol Barad --

-- Spawns are located half way down
SET @CGUID := 250970; -- 214 creature entries
SET @OGUID := 233475; -- 111 gameobject entries

-- CORRECTIONS --
-- Creatures 45069, 45070, 45071, 45072, 45077 should have same flags just like others, 45068 or 45074.
UPDATE `creature_template` SET `npcflag` = 32769, `unit_flags` = 2147484480 WHERE `entry` IN (45069, 45070, 45071, 45072, 45077);
-- (not needed since it's not handled anyway, missing on retail on 5.1.0a (16357))
-- UPDATE `gameobject_template` SET `Data4` = 26204, `Data5` = 26205 WHERE `entry` = 205103;
-- UPDATE `gameobject_template` SET `Data22` = 1 WHERE `entry` = 205138;

-- ADDONS --
DELETE FROM `creature_template_addon` WHERE `entry` IN (50167, 50173, 47550, 48066, 48039, 48061, 48074, 48069, 48062, 48070, 48071);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
-- Rhagha (50167), Maven Zara (50173)
(50167, 0, 0, 0, 0, 0, '32783'),
(50173, 0, 0, 0, 0, 0, '32783'),
-- Questgivers
(48066, 0, 17703, 50331648, 1, 0, ''),
(48039, 0, 17703, 50331648, 1, 0, ''),
(48061, 0, 17703, 50331648, 1, 0, ''),
(48074, 0, 17703, 50331648, 1, 0, ''),
(48069, 0, 17719, 50331648, 1, 0, ''),
(48062, 0, 17719, 50331648, 1, 0, ''),
(48070, 0, 17719, 50331648, 1, 0, ''),
(48071, 0, 17719, 50331648, 1, 0, '');

-- VEHICLES AND TRIGGERS --
-- Abandoned Siege Engine (45344)
SET @NPC = 45344;
UPDATE `creature_template` SET `npcflag` = 16777216, `RegenHealth` = 0, `mechanic_immune_mask` = 344276858 WHERE `entry` = @NPC;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (@NPC);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@NPC, 84754, 1, 0);
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 27, 0, 100, 0, 0, 0, 0, 0, 28, 95330, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abandoned Siege Engine - On Passenger Enter - Remove Thick Layer of Rust');

-- Siege Engine Turret (45564)
SET @NPC = 45564;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 85167, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Siege Engine Turret - On Spawn - Cast Siege Cannon on self');

-- Tower Range Finder (45492), Tower Cannon Target (45561)
UPDATE `creature_template` SET `InhabitType` = 7, `flags_extra` = 128 WHERE `entry` IN (45492, 45561);

-- SPELLS --
-- Tower Range Finder (84979)
SET @SPELL = 84979;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (@SPELL);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, @SPELL, 0, 0, 35, 0, 1, 60, 4, 0, 0, 0, '', 'Tower Range Finder''s targets must be within 60 yards'),
(13, 1, @SPELL, 0, 0, 31, 0, 3, 45344, 0, 0, 0, 0, '', 'Tower Range Finder targets NPC_ABANDONED_SIEGE_ENGINE');

-- Siege Cannon (85123) missile
SET @SPELL = 85123;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (85122, @SPELL);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, @SPELL, 0, 0, 31, 0, 3, 45561, 0, 0, 0, 0, '', 'Siege Cannon targets NPC_TOWER_CANNON_TARGET');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (85122, @SPELL);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(@SPELL, 'spell_siege_cannon');

-- SMART AI --
-- Problim (47593)
SET @NPC = 47593;
DELETE FROM `creature_template_addon` WHERE `entry` IN (@NPC);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@NPC, 0, 0, 0, 1, 0, '88361');
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 10000, 10000, 10000, 20000, 11, 88421, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Problim - IC Update - Cast Log Smash'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 15000, 10000, 20000, 11, 80146, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Problim - IC Update - Cast Bonk on victim');

-- Baradin Crocolisk (47591)
SET @NPC = 47591;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 20000, 20000, 11, 3604, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Baradin Crocolisk - IC Update - Cast Tendon Rip on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 15000, 10000, 20000, 11, 13445, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Baradin Crocolisk - IC Update - Cast Rend on victim');

-- Ghastly Convict (47590)
SET @NPC = 47590;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 0, 5000, 10000, 15000, 11, 37685, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Captive Spirit - IC Update - Cast Backstab on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 80576, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Captive Spirit - IC Update - Cast Shadowstep on victim');

-- Captive Spirit (47531)
SET @NPC = 47531;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 0, 5000, 10000, 15000, 11, 81193, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Captive Spirit - IC Update - Cast Unrelenting Anguish on victim');

-- Cellblock Ooze (47534)
SET @NPC = 47534;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 9459, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cellblock Ooze - IC Update - Cast Corrosive Ooze on victim');

-- Archmage Galus (47537)
SET @NPC = 47537;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 5000, 10000, 11, 79859, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Archmage Galus - IC Update - Cast Ice Lance on victim');

-- Shivarra Destroyer (47540)
SET @NPC = 47540;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 10000, 15000, 11, 37629, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shivarra Destroyer - IC Update - Cast Melt Flesh on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 36040, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Shivarra Destroyer - IC Update - Cast Fel Flamestrike on random hostile'),
(@NPC, 0, 2, 0, 0, 0, 100, 0, 10000, 15000, 15000, 20000, 11, 34017, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Shivarra Destroyer - IC Update - Cast Rain of Chaos on random hostile');

-- Cell Watcher (47542)
SET @NPC = 47542;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 10000, 15000, 11, 36398, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cell Watcher - IC Update - Cast Tongue Lash on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 36414, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cell Watcher - IC Update - Cast Focused Bursts on victim');

-- Jailed Wrathguard (47548)
-- Has no abilities??

-- Imprisoned Imp (47549)
UPDATE `creature_template` SET `spell1` = 36227, `AIName` = 'CasterAI' WHERE `entry` IN (47549);

-- Svarnos (47544)
SET @NPC = 47544;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 8000, 10000, 11, 84426, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Svarnos - IC Update - Cast Felbreath on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 81173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Svarnos - IC Update - Cast Pierce Frenzy on self');

-- Imprisoned Worker (47550)
SET @NPC = 47550;
DELETE FROM `creature_template_addon` WHERE `entry` IN (@NPC);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@NPC, 0, 0, 0, 1, 233, '');
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 0, 0, 9000, 9000, 11, 38557, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Imprisoned Worker - IC Update - Cast Throw on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 6016, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Imprisoned Worker - IC Update - Cast Pierce Armor on victim');

-- Exiled Mage (47552)
SET @NPC = 47552;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 3000, 15000, 15000, 20000, 11, 79880, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Exiled Mage - IC Update - Cast Slow on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 3000, 10000, 10000, 15000, 11, 22938, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Exiled Mage - IC Update - Cast Arcane Explosion'),
(@NPC, 0, 2, 0, 0, 0, 100, 0, 0, 5000, 5000, 10000, 11, 79869, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Exiled Mage - IC Update - Cast Arcane Missiles on victim');

-- Warden Guard (47561)
SET @NPC = 47561;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 0, 0, 30000, 30000, 11, 78710, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warden Guard - IC Update - Cast Threatening Shout on self'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 7000, 7000, 11, 85240, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Warden Guard - IC Update - Cast Sundering Cleave on victim');

-- Warden Silva (48036)
SET @NPC = 48036;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 7000, 7000, 15000, 20000, 11, 81219, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warden Silva - IC Update - Cast Battle Shout on self'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 7000, 7000, 7000, 7000, 11, 79878, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Warden Guard - IC Update - Cast Bloodthirst on victim'),
(@NPC, 0, 2, 0, 0, 0, 100, 0, 8000, 8000, 15000, 20000, 11, 11977, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Warden Silva - IC Update - Cast Rend on victim');

-- Alliance Hunter Infantry (47595)
SET @NPC = 47595;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 15000, 20000, 11, 22910, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alliance Hunter Infantry - IC Update - Cast Immolation Trap on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 15000, 20000, 11, 80009, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alliance Hunter Infantry - IC Update - Cast Serpent Sting on victim'),
(@NPC, 0, 2, 0, 0, 0, 100, 0, 0, 0, 2000, 2000, 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alliance Hunter Infantry - IC Update - Cast Shoot on victim');

-- Alliance Mage Infantry (47598) - casting Arcane Charge 36032??
SET @NPC = 47598;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 0, 0, 6000, 6000, 11, 79868, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alliance Mage Infantry - IC Update - Cast Arcane Blast on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 2500, 2500, 12000, 12000, 11, 22938, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Alliance Mage Infantry - IC Update - Cast Arcane Explosion'),
(@NPC, 0, 2, 0, 0, 0, 100, 0, 4000, 4000, 20000, 20000, 11, 21655, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Mage Infantry - IC Update - Cast Blink on self');

-- Alliance Warrior Infantry (47599)
SET @NPC = 47599;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 4, 0, 0, 100, 0, 0, 0, 0, 0, 11, 22120, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alliance Warrior Infantry - On Aggro - Cast Charge on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 0, 0, 120000, 120000, 11, 80983, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Warrior Infantry - IC Update - Cast Commanding Shout on self'),
(@NPC, 0, 2, 0, 0, 0, 100, 0, 1000, 5000, 5000, 10000, 11, 11971, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alliance Warrior Infantry - IC Update - Cast Sunder Armor on victim'),
(@NPC, 0, 3, 0, 0, 0, 100, 0, 5000, 10000, 10000, 20000, 11, 8078, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Alliance Warrior Infantry - IC Update - Cast Thunderclap');

-- Alliance Paladin Infantry (47600)
SET @NPC = 47600;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 4, 0, 0, 100, 0, 0, 0, 0, 0, 11, 79968, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Paladin Infantry - On Aggro - Cast Blessing of Kings on self'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 3000, 5000, 10000, 15000, 11, 79965, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alliance Paladin Infantry - IC Update - Cast Avenger''s Shield on victim'),
(@NPC, 0, 2, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 79966, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Alliance Paladin Infantry - IC Update - Cast Consecration');

-- Horde Druid Infantry (47607)
SET @NPC = 47607;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 0, 5000, 1000, 15000, 11, 78907, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Horde Druid Infantry - IC Update - Cast Starfire on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 79825, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Horde Druid Infantry - IC Update - Cast Summon Unstable Mushroom on random hostile');

-- Horde Mage Infantry (47608)
SET @NPC = 47608;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3000, 3000, 11, 79854, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Horde Mage Infantry - IC Update - Cast FireBall on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 79856, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Horde Mage Infantry - IC Update - Cast Flamestrike on random hostile'),
(@NPC, 0, 2, 0, 0, 0, 100, 0, 10000, 15000, 15000, 20000, 11, 79857, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Horde Mage Infantry - IC Update - Cast Blast Wave');

-- Horde Rogue Infantry (47609)
SET @NPC = 47609;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 7000, 7000, 15000, 20000, 11, 79851, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Horde Rogue Infantry - IC Update - Cast Fan of Knives'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 15000, 20000, 11, 79853, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Rogue Infantry - IC Update - Cast Evasion on self');

-- Horde Shaman Infantry (47610)
SET @NPC = 47610;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 0, 3000, 10000, 15000, 11, 79884, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Horde Shaman Infantry - IC Update - Cast Lightning Bolt on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 3000, 5000, 15000, 20000, 11, 79890, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Horde Shaman Infantry - IC Update - Cast Flame Shock on victim'),
(@NPC, 0, 2, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 79886, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Horde Shaman Infantry - IC Update - Cast Lava Burst on victim');

-- Baradin Guard (51165)
SET @NPC = 51165;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 10000, 20000, 11, 79878, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Baradin Guard - IC Update - Cast Bloodthirst on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 5000, 10000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Baradin Guard - IC Update - Cast Cleave on victim');

-- Hellscreams Sentry (51166)
SET @NPC = 51166;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 10000, 20000, 11, 79878, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Hellscreams Sentry - IC Update - Cast Bloodthirst on victim'),
(@NPC, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 5000, 10000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Hellscreams Sentry - IC Update - Cast Cleave on victim');

-- TEXTS --
DELETE FROM `creature_text` WHERE `entry` IN (43679, 47324, 47335);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `TextRange`, `comment`) VALUES
(43679, 1, 0, 'The East Spire has been heavily damaged!', 41, 0, 100, 0, 0, 0, 45453, 2, ''),
(43679, 2, 0, 'The East Spire has been destroyed!', 41, 0, 100, 0, 0, 0, 45454, 2, ''),
(43679, 3, 0, 'The West Spire has been heavily damaged!', 41, 0, 100, 0, 0, 0, 45456, 2, ''),
(43679, 4, 0, 'The West Spire has been destroyed!', 41, 0, 100, 0, 0, 0, 45457, 2, ''),
(43679, 5, 0, 'The South Spire has been heavily damaged!', 41, 0, 100, 0, 0, 0, 45458, 2, ''),
(43679, 6, 0, 'The South Spire has been destroyed!', 41, 0, 100, 0, 0, 0, 45459, 2, ''),
(43679, 7, 0, 'The Alliance has gained control of the Ironclad Garrison!', 41, 0, 100, 0, 0, 0, 45463, 2, ''),
(43679, 8, 0, 'The Alliance has lost control of the Ironclad Garrison!', 41, 0, 100, 0, 0, 0, 45462, 2, ''),
(43679, 9, 0, 'The Horde has taken the Ironclad Garrison!', 41, 0, 100, 0, 0, 0, 45464, 2, ''),
(43679, 10, 0, 'The Horde has lost the Ironclad Garrison!', 41, 0, 100, 0, 0, 0, 45465, 2, ''),
(43679, 11, 0, 'The Alliance has gained control of the Slagworks!', 41, 0, 100, 0, 0, 0, 45467, 2, ''),
(43679, 12, 0, 'The Alliance has lost control of the Slagworks!', 41, 0, 100, 0, 0, 0, 45466, 2, ''),
(43679, 13, 0, 'The Horde has taken the Slagworks!', 41, 0, 100, 0, 0, 0, 45468, 2, ''),
(43679, 14, 0, 'The Horde has lost the Slagworks!', 41, 0, 100, 0, 0, 0, 45469, 2, ''),
(43679, 15, 0, 'The Alliance has gained control of Warden''s Vigil!', 41, 0, 100, 0, 0, 0, 45471, 2, ''),
(43679, 16, 0, 'The Alliance has lost control of Warden''s Vigil!', 41, 0, 100, 0, 0, 0, 45470, 2, ''),
(43679, 17, 0, 'The Horde has taken Warden''s Vigil!', 41, 0, 100, 0, 0, 0, 45472, 2, ''),
(43679, 18, 0, 'The Horde has lost Warden''s Vigil!', 41, 0, 100, 0, 0, 0, 45473, 2, ''),
(43679, 19, 0, 'The Alliance has successfully defended Tol Barad!', 41, 0, 100, 0, 0, 8455, 45174, 2, ''),
(43679, 20, 0, 'The Horde has successfully defended Tol Barad!', 41, 0, 100, 0, 0, 8454, 45188, 2, ''),
(43679, 21, 0, 'The Alliance has successfully taken Tol Barad!', 41, 0, 100, 0, 0, 8455, 45189, 2, ''),
(43679, 22, 0, 'The Horde has successfully taken Tol Barad!', 41, 0, 100, 0, 0, 8454, 45190, 2, ''),
(43679, 23, 0, 'Warning: This vehicle is not permitted to operate outside of Tol Barad. Turn back now.', 41, 0, 100, 0, 0, 0, 45526, 0, ''),
(43679, 24, 0, 'Preparations for Tol Barad will begin in 5 minutes!', 41, 0, 100, 0, 0, 0, 50887, 2, ''),
(43679, 25, 0, 'Preparations for Tol Barad will begin in 2 minutes!', 41, 0, 100, 0, 0, 0, 50888, 2, ''),
(43679, 26, 0, 'Preparations for Tol Barad will begin in 1 minute!', 41, 0, 100, 0, 0, 0, 50889, 2, ''),
(47324, 1, 0, 'Victory in Tol Barad is ours! While the Horde offensive is crippled, we need your immediate efforts to gather resources and secure the island!', 41, 0, 100, 0, 0, 8455, 50894, 0, ''),
(47335, 1, 0, 'Victory in Tol Barad is ours! While the Alliance offensive is crippled, we need your immediate efforts to gather resources and secure the island!', 41, 0, 100, 0, 0, 8455, 50895, 0, '');

-- GRAVEYARDS -- 
-- Spirit Guides (45066 - 45079)
UPDATE `creature_template` SET `gossip_menu_id` = 45068, `ScriptName` = 'npc_tb_spirit_guide' WHERE `entry` IN (45068, 45074);
UPDATE `creature_template` SET `gossip_menu_id` = 45069, `ScriptName` = 'npc_tb_spirit_guide' WHERE `entry` IN (45069, 45075);
UPDATE `creature_template` SET `gossip_menu_id` = 45070, `ScriptName` = 'npc_tb_spirit_guide' WHERE `entry` IN (45070, 45078);
UPDATE `creature_template` SET `gossip_menu_id` = 45071, `ScriptName` = 'npc_tb_spirit_guide' WHERE `entry` IN (45071, 45079);
UPDATE `creature_template` SET `gossip_menu_id` = 45072, `ScriptName` = 'npc_tb_spirit_guide' WHERE `entry` IN (45072, 45077);
UPDATE `creature_template` SET `gossip_menu_id` = 45073, `ScriptName` = 'npc_tb_spirit_guide' WHERE `entry` IN (45073, 45076);

DELETE FROM `gossip_menu` WHERE `entry` IN (45068, 45069, 45070, 45071, 45072, 45073, 45074, 45075, 45076, 45077, 45078, 45079);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(45068, 14063), (45069, 14063), (45070, 14063), (45071, 14063), (45072, 14063), (45073, 14063),
(45074, 14063), (45075, 14063), (45076, 14063), (45077, 14063), (45078, 14063), (45079, 14063);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (45068, 45069, 45070, 45071, 45072, 45073);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(45068, 0, 0, 'Take me to the Slagworks.', 45327, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45068, 2, 0, 'Take me to the Warden''s Vigil.', 45330, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45068, 3, 0, 'Take me to the East Spire.', 45331, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45068, 4, 0, 'Take me to the West Spire.', 45332, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45068, 5, 0, 'Take me to the South Spire.', 45333, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45069, 0, 0, 'Take me to the Slagworks.', 45327, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45069, 1, 0, 'Take me to the Ironclad Garrison.', 45328, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45069, 3, 0, 'Take me to the East Spire.', 45331, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45069, 4, 0, 'Take me to the West Spire.', 45332, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45069, 5, 0, 'Take me to the South Spire.', 45333, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45070, 0, 0, 'Take me to the Slagworks.', 45327, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45070, 1, 0, 'Take me to the Ironclad Garrison.', 45328, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45070, 2, 0, 'Take me to the Warden''s Vigil.', 45330, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45070, 4, 0, 'Take me to the West Spire.', 45332, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45070, 5, 0, 'Take me to the South Spire.', 45333, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45071, 0, 0, 'Take me to the Slagworks.', 45327, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45071, 1, 0, 'Take me to the Ironclad Garrison.', 45328, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45071, 2, 0, 'Take me to the Warden''s Vigil.', 45330, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45071, 3, 0, 'Take me to the East Spire.', 45331, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45071, 4, 0, 'Take me to the West Spire.', 45332, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45072, 0, 0, 'Take me to the Slagworks.', 45327, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45072, 1, 0, 'Take me to the Ironclad Garrison.', 45328, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45072, 2, 0, 'Take me to the Warden''s Vigil.', 45330, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45072, 3, 0, 'Take me to the East Spire.', 45331, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45072, 5, 0, 'Take me to the South Spire.', 45333, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45073, 1, 0, 'Take me to the Ironclad Garrison.', 45328, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45073, 2, 0, 'Take me to the Warden''s Vigil.', 45330, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45073, 3, 0, 'Take me to the East Spire.', 45331, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45073, 4, 0, 'Take me to the West Spire.', 45332, 1, 32769, 0, 0, 0, 0, NULL, 0),
(45073, 5, 0, 'Take me to the South Spire.', 45333, 1, 32769, 0, 0, 0, 0, NULL, 0);

-- SPAWNS --
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+213;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
-- Cursed Depths area
-- Archmage Galus (47537)
(@CGUID+0, 47537, 732, 1, 1, 0, -1296.08, 875.828, 89.61353, 4.642576, 120, 0, 0), -- 47537 (Area: 5399) (Auras: 79865 - 79865) (possible waypoints or random movement)
-- Cellblock Ooze (47534)
(@CGUID+1, 47534, 732, 1, 1, 0, -1212.986, 837.8921, 89.57125, 0.1021679, 120, 5, 1), -- 47534 (Area: 0) (Auras: 3338 - 3338) (possible waypoints or random movement)
(@CGUID+2, 47534, 732, 1, 1, 0, -1239.17, 830.924, 89.5302, 3.068859, 120, 5, 1), -- 47534 (Area: 0) (Auras: 3338 - 3338) (possible waypoints or random movement)
(@CGUID+3, 47534, 732, 1, 1, 0, -1252.255, 788.9242, 89.56779, 1.396156, 120, 5, 1), -- 47534 (Area: 0) (Auras: 3338 - 3338)
(@CGUID+4, 47534, 732, 1, 1, 0, -1255.302, 814.4387, 89.52995, 1.56135, 120, 5, 1), -- 47534 (Area: 5400) (Auras: 3338 - 3338) (possible waypoints or random movement)
(@CGUID+5, 47534, 732, 1, 1, 0, -1263.07, 841.099, 89.55086, 4.601085, 120, 5, 1), -- 47534 (Area: 0) (Auras: 3338 - 3338) (possible waypoints or random movement)
-- (@CGUID+6, 47534, 732, 1, 1, 0, -1294.2, 856.8137, 89.52145, 1.342058, 120, 5, 1), -- 47534 (Area: 0) (Auras: 3338 - 3338)
(@CGUID+7, 47534, 732, 1, 1, 0, -1299.99, 858.802, 89.52593, 1.648581, 120, 5, 1), -- 47534 (Area: 0) (Auras: 3338 - 3338) (possible waypoints or random movement)
(@CGUID+8, 47534, 732, 1, 1, 0, -1218.347, 775.1534, 120.4299, 1.073848, 120, 5, 1), -- 47534 (Area: 5658) (Auras: 3338 - 3338) (possible waypoints or random movement)
(@CGUID+9, 47534, 732, 1, 1, 0, -1220.804, 799.319, 119.9041, 5.722214, 120, 5, 1), -- 47534 (Area: 0) (Auras: 3338 - 3338) (possible waypoints or random movement)
(@CGUID+10, 47534, 732, 1, 1, 0, -1232.599, 822.4125, 120.0886, 5.952512, 120, 5, 1), -- 47534 (Area: 0) (Auras: 3338 - 3338)
-- (@CGUID+11, 47534, 732, 1, 1, 0, -1240.221, 795.0685, 119.5391, 0.7272077, 120, 5, 1), -- duplicate
-- (@CGUID+12, 47534, 732, 1, 1, 0, -1242.709, 887.5302, 121.1437, 1.570796, 120, 5, 1), -- too far
(@CGUID+13, 47534, 732, 1, 1, 0, -1253.01, 790.9824, 120.6883, 1.1471, 120, 5, 1), -- 47534 (Area: 0) (Auras: 3338 - 3338) (possible waypoints or random movement)
(@CGUID+14, 47534, 732, 1, 1, 0, -1278.251, 787.2203, 121.4854, 0.1371973, 120, 5, 1), -- 47534 (Area: 5658) (Auras: 3338 - 3338) (possible waypoints or random movement)
-- Ghastly Convict (47590)
(@CGUID+15, 47590, 732, 1, 1, 0, -1195.389, 848.7443, 89.52411, 2.124159, 120, 5, 1), -- 47590 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+16, 47590, 732, 1, 1, 0, -1209.06, 793.809, 120.9663, 0, 120, 5, 1), -- 47590 (Area: 5658) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+17, 47590, 732, 1, 1, 0, -1209.049, 818.7425, 89.52, 4.151368, 120, 5, 1), -- 47590 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+18, 47590, 732, 1, 1, 0, -1222.843, 847.0756, 89.52644, 0.2871247, 120, 5, 1), -- 47590 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
-- (@CGUID+19, 47590, 732, 1, 1, 0, -1232.744, 825.5822, 120.3064, 3.545129, 120, 5, 1), -- duplicate
-- (@CGUID+20, 47590, 732, 1, 1, 0, -1236.111, 940.8, 119.7449, 1.929726, 120, 5, 1), -- too far
(@CGUID+21, 47590, 732, 1, 1, 0, -1238.51, 792.644, 89.60033, 0, 120, 5, 1), -- 47590 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+22, 47590, 732, 1, 1, 0, -1238.363, 790.1481, 89.53228, 4.054383, 120, 5, 1), -- 47590 (Area: 5400) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+23, 47590, 732, 1, 1, 0, -1238.99, 815.033, 120.1563, 0, 120, 5, 1), -- 47590 (Area: 5658) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+24, 47590, 732, 1, 1, 0, -1261.99, 786.42, 122.1203, 0, 120, 5, 1), -- 47590 (Area: 5658) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+25, 47590, 732, 1, 1, 0, -1266.856, 809.337, 89.51785, 6.238548, 120, 5, 1), -- 47590 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+26, 47590, 732, 1, 1, 0, -1280.313, 854.2625, 89.52263, 0.7536047, 120, 5, 1), -- 47590 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+27, 47590, 732, 1, 1, 0, -1285.851, 765.2222, 120.4499, 2.486316, 120, 5, 1), -- 47590 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+28, 47590, 732, 1, 1, 0, -1296.935, 857.2167, 89.52328, 4.994988, 120, 5, 1), -- 47590 (Area: 0) (Auras: 33900 - 33900)
(@CGUID+29, 47590, 732, 1, 1, 0, -1311.856, 838.0829, 89.51924, 2.179301, 120, 5, 1), -- 47590 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
-- Captive Spirit (47531)
(@CGUID+30, 47531, 732, 1, 1, 0, -1206.231, 831.345, 89.57715, 6.075672, 120, 5, 1), -- 47531 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
-- (@CGUID+31, 47531, 732, 1, 1, 0, -1213.282, 813.0681, 122.3386, 6.169728, 120, 5, 1), -- 47531 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+32, 47531, 732, 1, 1, 0, -1216.019, 773.1226, 120.6793, 2.570909, 120, 5, 1), -- 47531 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+33, 47531, 732, 1, 1, 0, -1216.65, 813.479, 122.2273, 0, 120, 5, 1), -- 47531 (Area: 5658) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+34, 47531, 732, 1, 1, 0, -1230.179, 773.1282, 132.0358, 0.1385303, 120, 5, 1), -- 47531 (Area: 5400) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+35, 47531, 732, 1, 1, 0, -1235.488, 831.7879, 89.52909, 5.159039, 120, 5, 1), -- 47531 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+36, 47531, 732, 1, 1, 0, -1236.23, 794.142, 119.5113, 0, 120, 5, 1), -- 47531 (Area: 5658) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+37, 47531, 732, 1, 1, 0, -1248.584, 777.0118, 120.92, 5.73749, 120, 5, 1), -- 47531 (Area: 5400) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+38, 47531, 732, 1, 1, 0, -1251.9, 810.561, 89.61324, 0, 120, 5, 1), -- 47531 (Area: 0) (Auras: 33900 - 33900)
(@CGUID+39, 47531, 732, 1, 1, 0, -1252.42, 787.99, 89.61294, 0, 120, 5, 1), -- 47531 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+40, 47531, 732, 1, 1, 0, -1262.59, 800.538, 121.1983, 0.8446221, 120, 5, 1), -- 47531 (Area: 5658) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+41, 47531, 732, 1, 1, 0, -1270.18, 834.712, 89.57574, 0, 120, 5, 1), -- 47531 (Area: 5658) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+42, 47531, 732, 1, 1, 0, -1295.02, 836.314, 89.59794, 0, 120, 5, 1), -- 47531 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
-- (@CGUID+43, 47531, 732, 1, 1, 0, -1294.654, 837.9826, 89.52651, 2.373157, 120, 5, 1), -- 47531 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)
(@CGUID+44, 47531, 732, 1, 1, 0, -1296.075, 856.1942, 89.52232, 4.353926, 120, 5, 1), -- 47531 (Area: 0) (Auras: 33900 - 33900) (possible waypoints or random movement)

-- D-Block area
-- Svarnos (47544)
(@CGUID+45, 47544, 732, 1, 1, 0, -973.3292, 1037.769, 84.58276, 4.374927, 120, 5, 1), -- 47544 (Area: 5657) (Auras: ) (possible waypoints or random movement)
-- Shivarra Destroyer (47540)
(@CGUID+46, 47540, 732, 1, 1, 0, -932.2653, 1211.319, 84.58222, 3.457197, 120, 5, 1), -- 47540 (Area: 5406) (possible waypoints or random movement)
(@CGUID+47, 47540, 732, 1, 1, 0, -950.8999, 1124.927, 84.58222, 0.4037961, 120, 5, 1), -- 47540 (Area: 0) (possible waypoints or random movement)
(@CGUID+48, 47540, 732, 1, 1, 0, -967.2576, 1215.213, 84.75766, 1.372793, 120, 5, 1), -- 47540 (Area: 0) (possible waypoints or random movement)
(@CGUID+49, 47540, 732, 1, 1, 0, -970.5422, 1090.48, 84.58208, 1.221984, 120, 5, 1), -- 47540 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+50, 47540, 732, 1, 1, 0, -975.3828, 1166.215, 84.63705, 3.473249, 120, 5, 1), -- 47540 (Area: 0) (possible waypoints or random movement)
(@CGUID+51, 47540, 732, 1, 1, 0, -1001.356, 1125.125, 84.53617, 3.382725, 120, 5, 1), -- 47540 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+52, 47540, 732, 1, 1, 0, -1090.846, 1173.593, 121.2136, 0.5052633, 120, 5, 1), -- 47540 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+53, 47540, 732, 1, 1, 0, -1095.88, 1130.87, 120.6383, 1.682269, 120, 5, 1), -- 47540 (Area: 5657) (Auras: ) (possible waypoints or random movement)
-- Jailed Wrathguard (47548)
(@CGUID+54, 47548, 732, 1, 1, 0, -924.803, 1126.199, 84.55935, 4.808213, 120, 5, 1), -- 47548 (Area: 0) (possible waypoints or random movement)
(@CGUID+55, 47548, 732, 1, 1, 0, -951.2297, 1217.013, 84.58209, 3.485332, 120, 5, 1), -- 47548 (Area: 0) (possible waypoints or random movement)
(@CGUID+56, 47548, 732, 1, 1, 0, -967.3814, 1189.272, 84.58223, 4.157693, 120, 5, 1), -- 47548 (Area: 0) (possible waypoints or random movement)
(@CGUID+57, 47548, 732, 1, 1, 0, -968.6911, 1143.253, 84.58223, 5.573256, 120, 5, 1), -- 47548 (Area: 0) (possible waypoints or random movement)
(@CGUID+58, 47548, 732, 1, 1, 0, -969.1525, 1074.581, 84.57933, 5.755729, 120, 5, 1), -- 47548 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+59, 47548, 732, 1, 1, 0, -972.2754, 1112.392, 84.7422, 4.607996, 120, 5, 1), -- 47548 (Area: 0) (possible waypoints or random movement)
-- (@CGUID+60, 47548, 732, 1, 1, 0, -973.6989, 1145.936, 84.58223, 3.13332, 120, 5, 1), -- duplicate
(@CGUID+61, 47548, 732, 1, 1, 0, -998.4377, 1216.844, 84.58224, 3.164948, 120, 5, 1), -- 47548 (Area: 0) (possible waypoints or random movement)
(@CGUID+62, 47548, 732, 1, 1, 0, -1074.634, 1193.721, 123.774, 5.227451, 120, 5, 1), -- 47548 (Area: 0) (possible waypoints or random movement)
(@CGUID+63, 47548, 732, 1, 1, 0, -1087.493, 1104.478, 123.0007, 3.280739, 120, 5, 1), -- 47548 (Area: 0) (possible waypoints or random movement)
(@CGUID+64, 47548, 732, 1, 1, 0, -1090.991, 1153.383, 120.6032, 0.1978158, 120, 5, 1), -- 47548 (Area: 0) (possible waypoints or random movement)
-- Imprisoned Imp (47549)
(@CGUID+65, 47549, 732, 1, 1, 0, -985.267, 1087.6, 84.66553, 0, 120, 5, 1), -- 47549 (Area: 5401) (possible waypoints or random movement)
(@CGUID+66, 47549, 732, 1, 1, 0, -985.707, 1072.09, 84.66544, 0, 120, 5, 1), -- 47549 (Area: 5401) (possible waypoints or random movement)
(@CGUID+67, 47549, 732, 1, 1, 0, -981.2574, 1169.884, 84.54282, 0.5450748, 120, 5, 1), -- 47549 (Area: 0) (possible waypoints or random movement)
(@CGUID+68, 47549, 732, 1, 1, 0, -952.9392, 1183.216, 84.58692, 0.6595569, 120, 5, 1), -- 47549 (Area: 0) (possible waypoints or random movement)
(@CGUID+69, 47549, 732, 1, 1, 0, -913.6049, 1138.662, 84.53633, 0.7554819, 120, 5, 1), -- 47549 (Area: 5406) (possible waypoints or random movement)
(@CGUID+70, 47549, 732, 1, 1, 0, -1057.171, 1188.644, 121.549, 0.09086681, 120, 5, 1), -- 47549 (Area: 0) (possible waypoints or random movement)
(@CGUID+71, 47549, 732, 1, 1, 0, -1069.791, 1173.958, 121.0715, 0.8833641, 120, 5, 1), -- 47549 (Area: 0) (possible waypoints or random movement)
(@CGUID+72, 47549, 732, 1, 1, 0, -1086.976, 1198.488, 124.8398, 1.662733, 120, 5, 1), -- 47549 (Area: 0) (possible waypoints or random movement)
(@CGUID+73, 47549, 732, 1, 1, 0, -1087.82, 1089.06, 124.5697, 1.437385, 120, 5, 1), -- 47549 (Area: 0) (possible waypoints or random movement)
(@CGUID+74, 47549, 732, 1, 1, 0, -1111.004, 1107.139, 121.0572, 0, 120, 5, 1), -- 47549 (Area: 5657) (possible waypoints or random movement)
-- Cell Watcher (47542)
(@CGUID+75, 47542, 732, 1, 1, 0, -949.13, 1209.23, 84.58218, 6.052577, 120, 5, 1), -- 47542 (Area: 0) (possible waypoints or random movement)
(@CGUID+76, 47542, 732, 1, 1, 0, -966.1711, 1163.418, 84.58683, 4.411592, 120, 5, 1), -- 47542 (Area: 0) (possible waypoints or random movement)
(@CGUID+77, 47542, 732, 1, 1, 0, -967.286, 1089.59, 84.58218, 5.101334, 120, 5, 1), -- 47542 (Area: 0) (Auras: 36414 - 36414) (possible waypoints or random movement)
(@CGUID+78, 47542, 732, 1, 1, 0, -969.722, 1196.15, 84.58218, 1.34372, 120, 5, 1), -- 47542 (Area: 0) (possible waypoints or random movement)
(@CGUID+79, 47542, 732, 1, 1, 0, -977.5602, 1213.567, 84.58195, 6.146002, 120, 5, 1), -- 47542 (Area: 0) (possible waypoints or random movement)
(@CGUID+80, 47542, 732, 1, 1, 0, -978.3185, 1114.742, 84.58222, 5.203272, 120, 5, 1), -- 47542 (Area: 0) (possible waypoints or random movement)
(@CGUID+81, 47542, 732, 1, 1, 0, -1097.13, 1120.07, 122.2209, 1.902061, 120, 5, 1), -- 47542 (Area: 0) (possible waypoints or random movement)
(@CGUID+82, 47542, 732, 1, 1, 0, -1102.26, 1151.38, 119.1974, 4.665674, 120, 5, 1), -- 47542 (Area: 0) (possible waypoints or random movement)
(@CGUID+83, 47542, 732, 1, 1, 0, -1068.836, 1101.926, 122.1348, 3.073104, 120, 5, 1), -- 47542 (Area: 5657) (Auras: 36414 - 36414) (possible waypoints or random movement)
(@CGUID+84, 47542, 732, 1, 1, 0, -1080.14, 1184.08, 122.3486, 3.137954, 120, 5, 1), -- 47542 (Area: 5657) (Auras: 36414 - 36414) (possible waypoints or random movement)

-- The Hole area
-- Warden Silva (48036)
(@CGUID+85, 48036, 732, 1, 1, 0, -1514.1, 1257.47, 102.9563, 3.054326, 120, 0, 0), -- 48036 (Area: 5402) 
-- Warden Guard (47561)
(@CGUID+86, 47561, 732, 1, 1, 0, -1604.98, 1212.27, 95.09824, 4.694936, 120, 0, 0), -- 47561 (Area: 5402)
(@CGUID+87, 47561, 732, 1, 1, 0, -1614.9, 1212.5, 95.09814, 4.694936, 120, 5, 1), -- 47561 (Area: 5659) (Auras: 78710 - 78710) (possible waypoints or random movement)
(@CGUID+88, 47561, 732, 1, 1, 0, -1604.63, 1240.18, 101.8843, 4.625123, 120, 0, 0), -- 47561 (Area: 5402)
(@CGUID+89, 47561, 732, 1, 1, 0, -1614.49, 1240.22, 101.8843, 4.625123, 120, 0, 0), -- 47561 (Area: 5402)
(@CGUID+90, 47561, 732, 1, 1, 0, -1596.49, 1252.69, 101.8843, 3.054326, 120, 0, 0), -- 47561 (Area: 5402)
(@CGUID+91, 47561, 732, 1, 1, 0, -1596.36, 1264.09, 101.8843, 3.054326, 120, 0, 0), -- 47561 (Area: 5402)
(@CGUID+92, 47561, 732, 1, 1, 0, -1534.83, 1263.74, 101.8843, 3.717551, 120, 0, 0), -- 47561 (Area: 5402)
(@CGUID+93, 47561, 732, 1, 1, 0, -1535.16, 1251.46, 101.8843, 2.565634, 120, 0, 0), -- 47561 (Area: 5402)
-- Imprisoned Worker (47550)
(@CGUID+94, 47550, 732, 1, 1, 0, -1486.66, 1137, 126.0763, 3.612832, 120, 0, 0), -- 47550 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+95, 47550, 732, 1, 1, 0, -1492.63, 1131.12, 139.1213, 2.199115, 120, 0, 0), -- 47550 (Area: 0)
(@CGUID+96, 47550, 732, 1, 1, 0, -1462.88, 1139.46, 125.5793, 0.8552113, 120, 0, 0), -- 47550 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+97, 47550, 732, 1, 1, 0, -1467.73, 1110.03, 124.1633, 5.305801, 120, 0, 0), -- 47550 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+98, 47550, 732, 1, 1, 0, -1497.92, 1152.61, 134.1723, 3.909538, 120, 0, 0), -- 47550 (Area: 0)
(@CGUID+99, 47550, 732, 1, 1, 0, -1495.45, 1098.02, 132.6423, 3.298672, 120, 0, 0), -- 47550 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+100, 47550, 732, 1, 1, 0, -1576.9, 1139.34, 95.09843, 4.014257, 120, 0, 0), -- 47550 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+101, 47550, 732, 1, 1, 0, -1591.41, 1149.89, 95.09814, 1.850049, 120, 0, 0), -- 47550 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+102, 47550, 732, 1, 1, 0, -1599.95, 1177.28, 95.09814, 5.77704, 120, 0, 0), -- 47550 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+103, 47550, 732, 1, 1, 0, -1600.2, 1188.39, 95.09814, 5.445427, 120, 0, 0), -- 47550 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+104, 47550, 732, 1, 1, 0, -1608.69, 1147.13, 95.09814, 3.403392, 120, 0, 0), -- 47550 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+105, 47550, 732, 1, 1, 0, -1611.36, 1097.49, 95.09814, 5.270895, 120, 0, 0), -- 47550 (Area: 5659)
(@CGUID+106, 47550, 732, 1, 1, 0, -1614.6, 1120.97, 95.09814, 4.572762, 120, 0, 0), -- 47550 (Area: 5659)
(@CGUID+107, 47550, 732, 1, 1, 0, -1616.38, 1198.68, 95.09814, 2.373648, 120, 0, 0), -- 47550 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+108, 47550, 732, 1, 1, 0, -1636.61, 1192.85, 95.09853, 2.478368, 120, 0, 0), -- 47550 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+109, 47550, 732, 1, 1, 0, -1641.03, 1075.81, 95.09814, 0.08726646, 120, 0, 0), -- 47550 (Area: 5659)
(@CGUID+110, 47550, 732, 1, 1, 0, -1668.52, 1083.85, 95.09814, 3.001966, 120, 0, 0), -- 47550 (Area: 5659)
-- Exiled Mage (47552)
(@CGUID+111, 47552, 732, 1, 1, 0, -1464.64, 1123.72, 123.5763, 0, 120, 15, 1), -- 47552 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+112, 47552, 732, 1, 1, 0, -1478.82, 1119.3, 124.9303, 0, 120, 15, 1), -- 47552 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+113, 47552, 732, 1, 1, 0, -1487.452, 1123.936, 124.8323, 4.674941, 120, 15, 1), -- 47552 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+114, 47552, 732, 1, 1, 0, -1491.67, 1099.97, 130.3373, 0, 120, 15, 1), -- 47552 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+115, 47552, 732, 1, 1, 0, -1495.36, 1157.36, 134.5704, 2.12216, 120, 15, 1), -- 47552 (Area: 5402) (possible waypoints or random movement)
(@CGUID+116, 47552, 732, 1, 1, 0, -1496.16, 1163.27, 134.6324, 1.70535, 120, 15, 1), -- 47552 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+117, 47552, 732, 1, 1, 0, -1506.25, 1122.917, 138.2912, 3.347771, 120, 15, 1), -- 47552 (Area: 0) (possible waypoints or random movement)
(@CGUID+118, 47552, 732, 1, 1, 0, -1531.87, 1257.65, 101.8012, 6.250657, 120, 5, 1), -- 47552 (Area: 5402) (possible waypoints or random movement)
(@CGUID+119, 47552, 732, 1, 1, 0, -1550.74, 1257.81, 101.801, 3.133104, 120, 5, 1), -- 47552 (Area: 5402) (possible waypoints or random movement)
(@CGUID+120, 47552, 732, 1, 1, 0, -1566.16, 1144.98, 95.19754, 6.218648, 120, 5, 1), -- 47552 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+121, 47552, 732, 1, 1, 0, -1564.804, 1257.772, 101.8013, 3.144281, 120, 5, 1), -- 47552 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+122, 47552, 732, 1, 1, 0, -1581.21, 1145.461, 95.12469, 3.109612, 120, 5, 1), -- 47552 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+123, 47552, 732, 1, 1, 0, -1609.95, 1204.91, 95.09814, 0, 120, 5, 1), -- 47552 (Area: 5659) (possible waypoints or random movement)
(@CGUID+124, 47552, 732, 1, 1, 0, -1610.475, 1259.285, 101.7939, 2.673294, 120, 5, 1), -- 47552 (Area: 5402) (possible waypoints or random movement)
-- (@CGUID+125, 47552, 732, 1, 1, 0, -1612.502, 1258.028, 101.7787, 4.163522, 120, 5, 1), -- 47552 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+126, 47552, 732, 1, 1, 0, -1612.47, 1133.11, 95.04543, 0.8622312, 120, 5, 1), -- 47552 (Area: 5659) (possible waypoints or random movement)
-- (@CGUID+127, 47552, 732, 1, 1, 0, -1613.311, 1260.801, 101.7723, 3.952588, 120, 5, 1), -- 47552 (Area: 5402) (possible waypoints or random movement)
(@CGUID+128, 47552, 732, 1, 1, 0, -1615.86, 1188.13, 95.01479, 6.259611, 120, 5, 1), -- 47552 (Area: 5659) (Auras: ) (possible waypoints or random movement)
(@CGUID+129, 47552, 732, 1, 1, 0, -1693.102, 1188.787, 101.7058, 0.2347284, 120, 5, 1), -- 47552 (Area: 5659) (Auras: ) (possible waypoints or random movement)


-- Critters, general
-- Baradin Fox Kit (48630)
(@CGUID+130, 48630, 732, 1, 1, 0, -912.768, 1117.728, 123.24, 6.011789, 120, 15, 1), -- 48630 (Area: 5406)
(@CGUID+131, 48630, 732, 1, 1, 0, -956.3405, 625.0203, 148.449, 0.7650959, 120, 15, 1), -- 48630 (Area: 5403)
(@CGUID+132, 48630, 732, 1, 1, 0, -1022.936, 913.9849, 124.215, 5.792886, 120, 15, 1), -- 48630 (Area: 0)
(@CGUID+133, 48630, 732, 1, 1, 0, -1058.411, 558.5327, 149.1433, 6.089482, 120, 15, 1), -- 48630 (Area: 0)
(@CGUID+134, 48630, 732, 1, 1, 0, -1098.219, 1226.92, 123.4584, 0.2466834, 120, 15, 1), -- 48630 (Area: 0)
(@CGUID+135, 48630, 732, 1, 1, 0, -1113.232, 873.2027, 119.7208, 5.30129, 120, 15, 1), -- 48630 (Area: 5399)
(@CGUID+136, 48630, 732, 1, 1, 0, -1113.244, 1033.672, 120.8223, 0.8740791, 120, 15, 1), -- 48630 (Area: 5399)
(@CGUID+137, 48630, 732, 1, 1, 0, -1220.485, 853.8242, 119.8953, 1.261872, 120, 15, 1), -- 48630 (Area: 0)
(@CGUID+138, 48630, 732, 1, 1, 0, -1247.064, 1350.98, 125.4886, 6.267562, 120, 15, 1), -- 48630 (Area: 0)
(@CGUID+139, 48630, 732, 1, 1, 0, -1316.931, 787.0962, 121.6236, 1.740777, 120, 15, 1), -- 48630 (Area: 5399)
(@CGUID+140, 48630, 732, 1, 1, 0, -1321.675, 658.7206, 121.8752, 0.7052379, 120, 15, 1), -- 48630 (Area: 0)
(@CGUID+141, 48630, 732, 1, 1, 0, -1386.296, 789.6034, 123.7091, 4.959026, 120, 15, 1), -- 48630 (Area: 0)
(@CGUID+142, 48630, 732, 1, 1, 0, -1391.811, 1057.938, 119.4652, 1.366293, 120, 15, 1), -- 48630 (Area: 0)
(@CGUID+143, 48630, 732, 1, 1, 0, -1441.078, 1191.825, 135.3289, 0.0703339, 120, 15, 1), -- 48630 (Area: 5402)
-- Prison Rat (48537)
(@CGUID+144, 48537, 732, 1, 1, 0, -924.951, 1120.53, 84.57797, 3.503213, 120, 5, 1), -- 48537 (Area: 5657)
(@CGUID+145, 48537, 732, 1, 1, 0, -952.55, 1181.728, 84.58473, 4.78621, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+146, 48537, 732, 1, 1, 0, -962.4899, 1151.187, 84.58222, 1.711781, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+147, 48537, 732, 1, 1, 0, -978.771, 1147.39, 84.58223, 0.5032376, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+148, 48537, 732, 1, 1, 0, -968.233, 1066.449, 84.57329, 4.395472, 120, 5, 1), -- 48537 (Area: 5401)
(@CGUID+149, 48537, 732, 1, 1, 0, -961.5362, 1177.174, 84.5821, 4.670433, 120, 5, 1), -- 48537 (Area: 5401)
(@CGUID+150, 48537, 732, 1, 1, 0, -971.0977, 1113.327, 84.69003, 0.6035722, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+151, 48537, 732, 1, 1, 0, -983.4948, 1166.894, 84.54896, 4.713494, 120, 5, 1), -- 48537 (Area: 5401)
(@CGUID+152, 48537, 732, 1, 1, 0, -981.4542, 1041.834, 84.58301, 0.6022658, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+153, 48537, 732, 1, 1, 0, -985.347, 1073.299, 84.58225, 0.1821429, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+154, 48537, 732, 1, 1, 0, -1002.32, 1132.832, 84.53664, 1.879077, 120, 5, 1), -- 48537 (Area: 5401)
(@CGUID+155, 48537, 732, 1, 1, 0, -1209.662, 817.3049, 89.52376, 3.652127, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+156, 48537, 732, 1, 1, 0, -1218.69, 839.863, 89.57114, 3.197569, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+157, 48537, 732, 1, 1, 0, -1224.097, 850.6351, 89.52282, 5.871431, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+158, 48537, 732, 1, 1, 0, -1242.541, 825.1813, 89.5302, 2.514852, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+159, 48537, 732, 1, 1, 0, -1257.722, 798.7971, 89.51856, 1.649774, 120, 5, 1), -- 48537 (Area: 5399)
(@CGUID+160, 48537, 732, 1, 1, 0, -1288.181, 870.2686, 89.5302, 1.18401, 120, 5, 1), -- 48537 (Area: 0)
(@CGUID+161, 48537, 732, 1, 1, 0, -1315.615, 837.4722, 89.52902, 1.516951, 120, 5, 1), -- 48537 (Area: 5399)
(@CGUID+162, 48537, 732, 1, 1, 0, -1527.536, 1270.957, 101.8012, 4.627024, 120, 5, 1), -- 48537 (Area: 5402)
-- Snake (2914)
(@CGUID+163, 2914, 732, 1, 1, 0, -1033.652, 801.1771, 122.8753, 3.927414, 120, 5, 1), -- 2914 (Area: 0) (possible waypoints or random movement)
(@CGUID+164, 2914, 732, 1, 1, 0, -1155.343, 1271.034, 121.115, 2.354961, 120, 5, 1), -- 2914 (Area: 0) (possible waypoints or random movement)
(@CGUID+165, 2914, 732, 1, 1, 0, -1056.713, 657.7767, 141.2766, 4.508464, 120, 5, 1), -- 2914 (Area: 0) (possible waypoints or random movement)
(@CGUID+166, 2914, 732, 1, 1, 0, -1167.115, 1132.512, 121.86, 4.459611, 120, 0, 0), -- 2914 (Area: 0)
(@CGUID+167, 2914, 732, 1, 1, 0, -1175.037, 1341.338, 124.6742, 3.705594, 120, 5, 1), -- 2914 (Area: 0) (possible waypoints or random movement)
(@CGUID+168, 2914, 732, 1, 1, 0, -1196.711, 921.5072, 119.7452, 0.1245318, 120, 5, 1), -- 2914 (Area: 5399) (possible waypoints or random movement)
(@CGUID+169, 2914, 732, 1, 1, 0, -1229.551, 1053.999, 119.6496, 2.009046, 120, 5, 1), -- 2914 (Area: 5399) (possible waypoints or random movement)
(@CGUID+170, 2914, 732, 1, 1, 0, -1282.493, 1185.489, 120.8472, 2.076537, 120, 5, 1), -- 2914 (Area: 0) (possible waypoints or random movement)
(@CGUID+171, 2914, 732, 1, 1, 0, -1316.819, 1286.664, 128.5771, 2.335887, 120, 5, 1), -- 2914 (Area: 0) (possible waypoints or random movement)
(@CGUID+172, 2914, 732, 1, 1, 0, -1322.526, 905.7576, 119.9727, 1.427795, 120, 5, 1), -- 2914 (Area: 0) (possible waypoints or random movement)
(@CGUID+173, 2914, 732, 1, 1, 0, -1322.229, 1276.019, 128.076, 3.908045, 120, 5, 1), -- 2914 (Area: 0) (possible waypoints or random movement)
(@CGUID+174, 2914, 732, 1, 1, 0, -1387.825, 1279.255, 135.1817, 0.2294089, 120, 5, 1), -- 2914 (Area: 0) (possible waypoints or random movement)
(@CGUID+175, 2914, 732, 1, 1, 0, -1403.362, 938.0353, 118.6887, 0.7460266, 120, 0, 0), -- 2914 (Area: 0)
(@CGUID+176, 2914, 732, 1, 1, 0, -1504.755, 769.7535, 124.5964, 5.682231, 120, 5, 1), -- 2914 (Area: 5400) (possible waypoints or random movement)
-- Baradin Crocolisk (47591)
(@CGUID+177, 47591, 732, 1, 1, 0, -1099.271, 1227.937, 123.4584, 1.089231, 120, 15, 1), -- 47591 (Area: 0) (possible waypoints or random movement)
(@CGUID+178, 47591, 732, 1, 1, 0, -1136.39, 1103.76, 118.8463, 0, 120, 15, 1), -- 47591 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+179, 47591, 732, 1, 1, 0, -1144.989, 1202.163, 120.7522, 4.369532, 120, 15, 1), -- 47591 (Area: 0) (possible waypoints or random movement)
(@CGUID+180, 47591, 732, 1, 1, 0, -1163.222, 1140.002, 121.7983, 0.2406246, 120, 15, 1), -- 47591 (Area: 0) (Auras: )
(@CGUID+181, 47591, 732, 1, 1, 0, -1183.716, 1307.183, 119.6709, 4.973243, 120, 15, 1), -- 47591 (Area: 0) (possible waypoints or random movement)
(@CGUID+182, 47591, 732, 1, 1, 0, -1183.25, 1232.32, 119.6923, 0, 120, 15, 1), -- 47591 (Area: 5399) (possible waypoints or random movement)
-- (@CGUID+183, 47591, 732, 1, 1, 0, -1198.97, 1224.732, 118.9178, 2.886917, 120, 15, 1), -- duplicate
-- (@CGUID+184, 47591, 732, 1, 1, 0, -1204.302, 1309.922, 122.1487, 0.407713, 120, 15, 1), -- duplicate
(@CGUID+185, 47591, 732, 1, 1, 0, -1215.161, 1194.385, 120.847, 4.482553, 120, 15, 1), -- 47591 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+186, 47591, 732, 1, 1, 0, -1223.21, 1257.42, 121.1063, 0, 120, 15, 1), -- 47591 (Area: 0) (possible waypoints or random movement)
(@CGUID+187, 47591, 732, 1, 1, 0, -1233.366, 1143.409, 119.9837, 0.7349917, 120, 15, 1), -- 47591 (Area: 5399)
(@CGUID+188, 47591, 732, 1, 1, 0, -1246.8, 1303.09, 119.2313, 0, 120, 15, 1), -- 47591 (Area: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+189, 47591, 732, 1, 1, 0, -1264.328, 1168.115, 119.8141, 0.4148644, 120, 15, 1), -- duplicate
(@CGUID+190, 47591, 732, 1, 1, 0, -1265.58, 1241.87, 121.5823, 0, 120, 15, 1), -- 47591 (Area: 0) (possible waypoints or random movement)
(@CGUID+191, 47591, 732, 1, 1, 0, -1274.22, 1167.16, 120.8103, 0, 120, 15, 1), -- 47591 (Area: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+192, 47591, 732, 1, 1, 0, -1300.003, 1110.957, 121.0026, 0.2005581, 120, 15, 1), -- 47591 (Area: 5399)
-- (@CGUID+193, 47591, 732, 1, 1, 0, -1314.573, 1182.476, 119.0194, 4.270839, 120, 15, 1), -- duplicate
(@CGUID+194, 47591, 732, 1, 1, 0, -1305.82, 1200.89, 119.9623, 0, 120, 15, 1), 
(@CGUID+195, 47591, 732, 1, 1, 0, -1305.22, 1262.41, 119.4313, 0, 120, 15, 1), -- 47591 (Area: 0) (possible waypoints or random movement)
-- (@CGUID+196, 47591, 732, 1, 1, 0, -1318.213, 1121.961, 119.4406, 1.919687, 120, 15, 1), -- duplicate
-- Problim (47593) waypoints needed
(@CGUID+197, 47593, 732, 1, 1, 0, -1344.739, 971.6679, 123.2955, 1.409069, 120, 5, 1), -- 47593 (Area: 0) (Auras: 88361 - 88361) (possible waypoints or random movement)
-- Tower Range Finder (45492)
(@CGUID+198, 45492, 732, 1, 1, 0, -951.21, 1469.55, 180.1893, 0, 120, 0, 0), -- 45492 (Area: 5546) (Auras: 85671 - 85671)
(@CGUID+199, 45492, 732, 1, 1, 0, -1234.6, 981.535, 155.5083, 5.51524, 120, 0, 0), -- 45492 (Area: 0)
(@CGUID+200, 45492, 732, 1, 1, 0, -1618.77, 953.587, 170.8923, 0, 120, 0, 0), -- 45492 (Area: 0) (Auras: 85671 - 85671)
-- Tower Cannon Target (45561)
(@CGUID+201, 45561, 732, 1, 1, 0, -937.667, 1462.98, 220.7583, 0, 120, 0, 0), -- 45561 (Area: 5546)
(@CGUID+202, 45561, 732, 1, 1, 0, -947.561, 1455.89, 233.0193, 0, 120, 0, 0), -- 45561 (Area: 0)
(@CGUID+203, 45561, 732, 1, 1, 0, -957.146, 1458.86, 242.6593, 0, 120, 0, 0), -- 45561 (Area: 0)
(@CGUID+204, 45561, 732, 1, 1, 0, -962.634, 1462.2, 220.7673, 0, 120, 0, 0), -- 45561 (Area: 0)
(@CGUID+205, 45561, 732, 1, 1, 0, -962.757, 1476.2, 235.8503, 0, 120, 0, 0), -- 45561 (Area: 0)
(@CGUID+206, 45561, 732, 1, 1, 0, -1000.18, 535.003, 196.6233, 0, 120, 0, 0), -- 45561 (Area: 0)
(@CGUID+207, 45561, 732, 1, 1, 0, -1010.87, 543.755, 203.4993, 0, 120, 0, 0), -- 45561 (Area: 0)
(@CGUID+208, 45561, 732, 1, 1, 0, -1025.64, 529.823, 208.0163, 0, 120, 0, 0), -- 45561 (Area: 5400)
(@CGUID+209, 45561, 732, 1, 1, 0, -1025.04, 536.807, 193.5913, 0, 120, 0, 0), -- 45561 (Area: 0)
(@CGUID+210, 45561, 732, 1, 1, 0, -1606.37, 948.302, 220.3123, 0, 120, 0, 0), -- 45561 (Area: 0)
(@CGUID+211, 45561, 732, 1, 1, 0, -1607.12, 961.814, 228.2583, 0, 120, 0, 0), -- 45561 (Area: 0)
(@CGUID+212, 45561, 732, 1, 1, 0, -1615.86, 966.875, 215.6943, 0, 120, 0, 0), -- 45561 (Area: 0)
(@CGUID+213, 45561, 732, 1, 1, 0, -1618.73, 940.462, 231.6113, 0, 120, 0, 0); -- 45561 (Area: 0)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+110;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `phaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
-- Doodad_TolBarad_Gates_01
(@OGUID+0, 206598, 732, 1, 1, 0, -834.201, 1188.167, 114.1249, 4.694937, 0, 0, -0.7132504, 0.7009093, 120, 255, 0), -- 206598 (Area: 5399)
-- Doodad_TolBarad_Door_01
(@OGUID+1, 206576, 732, 1, 1, 0, -1204.353, 1075.035, 123.6819, 0.02617911, 0, 0, 0.01308961, 0.9999143, 120, 255, 1), -- 206576 (Area: 5399)
-- Cursed Depths Gate
(@OGUID+2, 206843, 732, 1, 1, 0, -1233.36, 783.5536, 125.2064, 6.274459, 0, 0, -0.004363197, 0.9999905, 120, 255, 1), -- 206843 (Area: 5399)
-- D-Block gate
(@OGUID+3, 206844, 732, 1, 1, 0, -1087.148, 1150.346, 125.7371, 1.535887, 0, 0, 0.6946582, 0.71934, 120, 255, 1), -- 206844 (Area: 5399)
-- Gate to The Hole
(@OGUID+4, 206845, 732, 1, 1, 0, -1491.677, 1125.159, 130.985, 4.703663, 0, 0, -0.7101853, 0.7040147, 120, 255, 1), -- 206845 (Area: 5399)
-- Meeting Stone
(@OGUID+5, 206668, 732, 1, 1, 0, -1182.851, 1091.25, 120.216, 4.668757, 0, 0, 0, 1, 120, 255, 1), -- 206668 (Area: 0)
-- Forge
(@OGUID+6, 207705, 732, 1, 1, 0, -610.4271, 1379.63, 22.0371, 3.647738, 0, 0, 0, 1, 120, 255, 1), -- 207705 (Area: 0)
-- Anvil
(@OGUID+7, 207706, 732, 1, 1, 0, -605.5816, 1380.351, 21.9965, 2.495818, 0, 0, 0, 1, 120, 255, 1), -- 207706 (Area: 0)
-- Cauldron
(@OGUID+8, 206883, 732, 1, 1, 0, -602.8611, 1433.04, 22.0059, 1.937312, 0, 0, 0, 1, 120, 255, 1), -- 206883 (Area: 0)
-- Campfire
(@OGUID+9, 206045, 732, 1, 1, 0, -832.0087, 1032.271, 121.441, 5.497789, 0, 0, 0, 1, 120, 255, 1), -- 206045 (Area: 5401)
(@OGUID+10, 205963, 732, 1, 1, 0, -1417.37, 1295.899, 133.583, 5.497789, 0, 0, 0, 1, 120, 255, 1), -- 205963 (Area: 0)
(@OGUID+11, 205965, 732, 1, 1, 0, -1493.95, 1401.92, 133.593, 0.5061446, 0, 0, 0, 1, 120, 255, 1), -- 205965 (Area: 5402)
(@OGUID+12, 206044, 732, 1, 1, 0, -830.5833, 921.0851, 121.441, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- 206044 (Area: 5401)
(@OGUID+13, 207702, 732, 1, 1, 0, -565.7518, 1221.899, 92.6479, 4.01722, 0, 0, 0, 1, 120, 255, 1), -- 207702 (Area: 5406)
-- Bonfire
(@OGUID+14, 206043, 732, 1, 1, 0, -820.7292, 979.4618, 121.441, 5.497789, 0, 0, 0, 1, 120, 255, 1), -- 206043 (Area: 5401)
(@OGUID+15, 205964, 732, 1, 1, 0, -1490.5, 1238.67, 133.585, 5.497789, 0, 0, 0, 1, 120, 255, 1), -- 205964 (Area: 5402)
(@OGUID+16, 206884, 732, 1, 1, 0, -600.8108, 1402.189, 19.7069, 4.860743, 0, 0, 0, 1, 120, 255, 1), -- 206884 (Area: 0)
-- Questing: Dusty Prison Journal
(@OGUID+17, 206890, 732, 1, 1, 0, -1303.52, 881.998, 90.4816, 5.323256, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 5399)
(@OGUID+18, 206890, 732, 1, 1, 0, -1240.25, 857.958, 89.5302, 2.460913, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 5399)
(@OGUID+19, 206890, 732, 1, 1, 0, -1315.7, 835.108, 89.5292, 0.4537851, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+20, 206890, 732, 1, 1, 0, -1303.66, 851.564, 89.5258, 4.118979, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+21, 206890, 732, 1, 1, 0, -1286.26, 866.469, 90.67, 2.216565, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+22, 206890, 732, 1, 1, 0, -1288.63, 827.722, 89.5248, 0.3141584, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+23, 206890, 732, 1, 1, 0, -1277.78, 849.804, 89.5293, 2.321287, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+24, 206890, 732, 1, 1, 0, -1262.86, 820.609, 89.5674, 4.956738, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+25, 206890, 732, 1, 1, 0, -1276.8, 841.606, 89.5575, 2.35619, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+26, 206890, 732, 1, 1, 0, -1263.14, 852.521, 89.5343, 4.293513, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+27, 206890, 732, 1, 1, 0, -1233.98, 827.444, 89.5299, 2.234018, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+28, 206890, 732, 1, 1, 0, -1245.08, 810.75, 89.5278, 2.234018, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+29, 206890, 732, 1, 1, 0, -1247.1, 826.832, 89.5302, 2.478367, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+30, 206890, 732, 1, 1, 0, -1221.62, 852.878, 89.5287, 3.228859, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+31, 206890, 732, 1, 1, 0, -1213.19, 815.349, 89.5289, 4.991644, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+32, 206890, 732, 1, 1, 0, -1211.48, 840.946, 89.5804, 2.897245, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+33, 206890, 732, 1, 1, 0, -1197.37, 827.153, 89.5301, 0.5934101, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
(@OGUID+34, 206890, 732, 1, 1, 0, -1193.25, 847.568, 89.5307, 3.926996, 0, 0, 0, 1, 120, 255, 1), -- 206890 (Area: 0)
-- Questing: Cursed Shackles
(@OGUID+35, 206905, 732, 1, 1, 0, -912.163, 1143.02, 84.5428, 4.502952, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5406)
(@OGUID+36, 206905, 732, 1, 1, 0, -924.967, 1119.15, 84.5719, 3.525572, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+37, 206905, 732, 1, 1, 0, -925.073, 1226.1, 84.5822, 4.782203, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+38, 206905, 732, 1, 1, 0, -937.924, 1198.69, 84.5822, 4.782203, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+39, 206905, 732, 1, 1, 0, -939.785, 1132.5, 84.5778, 4.485497, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+40, 206905, 732, 1, 1, 0, -951.566, 1183.99, 84.5765, 4.01426, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+41, 206905, 732, 1, 1, 0, -956.759, 1041.07, 84.5822, 4.118979, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5657)
(@OGUID+42, 206905, 732, 1, 1, 0, -962.658, 1170.07, 84.5822, 3.944446, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5657)
(@OGUID+43, 206905, 732, 1, 1, 0, -963.444, 1129.26, 84.5822, 3.944446, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+44, 206905, 732, 1, 1, 0, -965.076, 1085.41, 84.5822, 0.03490625, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5657)
(@OGUID+45, 206905, 732, 1, 1, 0, -966.325, 1018.27, 84.8929, 5.602507, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5657)
(@OGUID+46, 206905, 732, 1, 1, 0, -972.693, 1222.21, 84.5819, 4.782203, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+47, 206905, 732, 1, 1, 0, -974.483, 1192, 84.5823, 3.944446, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5657)
(@OGUID+48, 206905, 732, 1, 1, 0, -978.684, 1066.77, 84.5818, 0.5585039, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5657)
(@OGUID+49, 206905, 732, 1, 1, 0, -983.701, 1111.76, 84.5822, 4.136433, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+50, 206905, 732, 1, 1, 0, -984.778, 1016.91, 84.8929, 4.398232, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5657)
(@OGUID+51, 206905, 732, 1, 1, 0, -986.189, 1170.42, 84.5459, 3.68265, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+52, 206905, 732, 1, 1, 0, -988.533, 1085.73, 84.5822, 3.68265, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5657)
(@OGUID+53, 206905, 732, 1, 1, 0, -988.764, 1033.74, 84.5822, 5.602507, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5657)
(@OGUID+54, 206905, 732, 1, 1, 0, -989.524, 1074.96, 84.5822, 3.68265, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 5657)
(@OGUID+55, 206905, 732, 1, 1, 0, -991.146, 1224.99, 84.5823, 3.124123, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+56, 206905, 732, 1, 1, 0, -996.352, 1134.94, 84.5368, 4.084071, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+57, 206905, 732, 1, 1, 0, -1003.33, 1122.25, 84.5362, 5.375615, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
(@OGUID+58, 206905, 732, 1, 1, 0, -1008.34, 1208.42, 84.5822, 3.944446, 0, 0, 0, 1, 120, 255, 1), -- 206905 (Area: 0)
-- Questing: Crate of Cellblock Rations
(@OGUID+59, 206996, 732, 1, 1, 0, -1588.94, 1138.56, 95.015, 5.881761, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+60, 206996, 732, 1, 1, 0, -1597.82, 1191.46, 95.0148, 4.939284, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+61, 206996, 732, 1, 1, 0, -1613.9, 1103.97, 95.0239, 4.904376, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+62, 206996, 732, 1, 1, 0, -1523.62, 1231.59, 101.797, 5.550147, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+63, 206996, 732, 1, 1, 0, -1610.42, 1125.81, 95.018, 5.951575, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+64, 206996, 732, 1, 1, 0, -1623.51, 1169.6, 94.9933, 5.602507, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+65, 206996, 732, 1, 1, 0, -1604.43, 1207.97, 95.0148, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+66, 206996, 732, 1, 1, 0, -1609.68, 1151.18, 95.0145, 5.427975, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+67, 206996, 732, 1, 1, 0, -1635.49, 1115.49, 95.0341, 5.480334, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+68, 206996, 732, 1, 1, 0, -1640.91, 1083.95, 95.0148, 4.991644, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+69, 206996, 732, 1, 1, 0, -1642, 1191.56, 95.0151, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+70, 206996, 732, 1, 1, 0, -1668.66, 1181.9, 101.801, 4.939284, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+71, 206996, 732, 1, 1, 0, -1635.05, 1061.26, 95.0515, 4.677484, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+72, 206996, 732, 1, 1, 0, -1675.7, 1102.37, 95.0475, 4.991644, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+73, 206996, 732, 1, 1, 0, -1603.85, 1245.88, 101.801, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+74, 206996, 732, 1, 1, 0, -1569.25, 1252.27, 101.801, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+75, 206996, 732, 1, 1, 0, -1622.11, 1263.69, 101.801, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+76, 206996, 732, 1, 1, 0, -1571.29, 1275.41, 101.801, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+77, 206996, 732, 1, 1, 0, -1561.1, 1275.22, 101.801, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+78, 206996, 732, 1, 1, 0, -1543.24, 1263.87, 101.801, 5.550147, 0, 0, 0, 1, 120, 255, 1), -- 206996 (Area: 5659)
(@OGUID+79, 206996, 732, 1, 1, 0, -1522.96, 1283.4, 101.797, 5.550147, 0, 0, 0, 1, 120, 255, 1); -- 206996 (Area: 5659)
/* To-do, missing spawns
-- Herbs: Cinderbloom (6/22 spawns)
-- (@OGUID+, 202747, 732, 1, 1, 0, -49.71007, 1948.488, 14.03951, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 5535)
-- (@OGUID+, 202747, 732, 1, 1, 0, -416.1076, 1589.439, 23.65213, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 5542)
-- (@OGUID+, 202747, 732, 1, 1, 0, -495.7483, 1318.233, 14.84083, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 0)
-- (@OGUID+, 202747, 732, 1, 1, 0, -544.9774, 1169.057, 89.61136, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 5406)
-- (@OGUID+, 202747, 732, 1, 1, 0, -606.9063, 1251.231, 85.83726, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 5546)
(@OGUID+80, 202747, 732, 1, 1, 0, -900.1805, 1123.745, 123.4317, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 5406)
(@OGUID+81, 202747, 732, 1, 1, 0, -1162.219, 889.8802, 121.3724, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 5399)
(@OGUID+82, 202747, 732, 1, 1, 0, -1322.17, 915.7604, 119.4951, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 5399)
(@OGUID+83, 202747, 732, 1, 1, 0, -1363.74, 613.9965, 126.0347, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 5400)
(@OGUID+84, 202747, 732, 1, 1, 0, -1381.306, 1229.365, 135.604, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 0)
(@OGUID+85, 202747, 732, 1, 1, 0, -1528.958, 1190.191, 139.3284, 0, 0, 0, 0, 1, 120, 255, 1), -- 202747 (Area: 0)
-- Herbs: Whiptail (15/19 spawns)
(@OGUID+86, 202752, 732, 1, 1, 0, -1102.552, 1274.609, 120.007, 0, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+87, 202752, 732, 1, 1, 0, -1108.129, 1096.498, 122.7865, 5.67232, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+88, 202752, 732, 1, 1, 0, -1232.319, 1140.254, 120.0816, 5.67232, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+89, 202752, 732, 1, 1, 0, -1132.92, 1132.563, 120.4844, 5.67232, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+90, 202752, 732, 1, 1, 0, -1139.731, 1304.658, 120.4041, 0, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+91, 202752, 732, 1, 1, 0, -1188.135, 1229.25, 119.3753, 5.67232, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 5399)
(@OGUID+92, 202752, 732, 1, 1, 0, -1207.754, 1193.16, 119.875, 5.67232, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+93, 202752, 732, 1, 1, 0, -1218.727, 1295.231, 119.3646, 5.270896, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+94, 202752, 732, 1, 1, 0, -1228.863, 1326.564, 126.1719, 5.270896, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+95, 202752, 732, 1, 1, 0, -1232.319, 1140.254, 120.0816, 5.67232, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+96, 202752, 732, 1, 1, 0, -1251.938, 1104.16, 120.9601, 5.67232, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 5399)
(@OGUID+97, 202752, 732, 1, 1, 0, -1267.78, 1199.09, 118.9367, 5.811947, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 5399)
(@OGUID+98, 202752, 732, 1, 1, 0, -1274.689, 1289.168, 119.1615, 5.270896, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+99, 202752, 732, 1, 1, 0, -1291.691, 1221.736, 119.4794, 5.811947, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
(@OGUID+100, 202752, 732, 1, 1, 0, -1313.983, 1166.955, 119.0399, 5.811947, 0, 0, 0, 1, 120, 255, 1), -- 202752 (Area: 0)
-- Mining: Rich Elementium Vein, Rich Pyrite Deposit, Elementium Vein (10/22 spawns) 
-- (@OGUID+, 202738, 732, 1, 1, 0, -535.4896, 1142.139, 89.60479, 0, 0, 0, 0, 1, 120, 255, 1), -- 202738 (Area: 0)
-- (@OGUID+, 202738, 732, 1, 1, 0, -541.8698, 1354.247, 24.02083, 0, 0, 0, 0, 1, 120, 255, 1), -- 202738 (Area: 5546)
(@OGUID+101, 202741, 732, 1, 1, 0, -953.9479, 1136.99, 125.4949, 0, 0, 0, 0, 1, 120, 255, 1), -- 43.3 29.1
(@OGUID+102, 202740, 732, 1, 1, 0, -956.7795, 1279.313, 131.099, 0, 0, 0, 0, 1, 120, 255, 1), -- 202740 (Area: 0)
(@OGUID+103, 202738, 732, 1, 1, 0, -1002.42, 1138.372, 124.6493, 5.009095, 0, 0, 0, 1, 120, 255, 1), -- 202738 (Area: 0)
(@OGUID+104, 202738, 732, 1, 1, 0, -1032.792, 1078.299, 125.4842, 0, 0, 0, 0, 1, 120, 255, 1), -- 202738 (Area: 0)
(@OGUID+105, 202738, 732, 1, 1, 0, -1234.997, 1431.396, 126.5013, 0, 0, 0, 0, 1, 120, 255, 1), -- 202738 (Area: 0)
(@OGUID+106, 202740, 732, 1, 1, 0, -1291.189, 1370.056, 130.3137, 0, 0, 0, 0, 1, 120, 255, 1), -- 202740 (Area: 0)
(@OGUID+107, 202738, 732, 1, 1, 0, -1341.788, 1337.564, 134.5677, 5.724681, 0, 0, 0, 1, 120, 255, 1), -- 33.4 58
(@OGUID+108, 202740, 732, 1, 1, 0, -1357.306, 1088.785, 123.8459, 0, 0, 0, 0, 1, 120, 255, 1), -- 202740 (Area: 5399)
(@OGUID+109, 202741, 732, 1, 1, 0, -1368.493, 603.5156, 127.235, 0, 0, 0, 0, 1, 120, 255, 1), -- 69.7 60.1
(@OGUID+110, 202741, 732, 1, 1, 0, -1425.139, 1038.675, 121.9771, 0, 0, 0, 0, 1, 120, 255, 1); -- 202741 (Area: 5399)
*/
