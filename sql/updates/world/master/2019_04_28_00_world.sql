-- Spell Area
DELETE FROM `spell_area` WHERE `area` IN (493, 5040) AND `spell`= 49416;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `flags`, `gender`, `quest_start_status`, `quest_end_status`) VALUES
(49416, 493, 25316, 25316, 3, 2, 2, 11),
(49416, 5040, 25316, 25316, 3, 2, 2, 11);

-- Gameobject focus (203087)
DELETE FROM `gameobject` WHERE `guid`= 200888;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseID`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(200888, 203087, 1, 0, 0, "0", 169, 5758.737, -3297.48, 1604.599, 0, 0, 0, 0, 1, 6000, 100, 1, 0);

-- Remove  duplicate spawns
DELETE FROM `creature` WHERE `guid` IN (394598, 384268);
DELETE FROM `creature_addon` WHERE `guid` IN (394598, 384268);

-- Make quest items quest related
UPDATE `creature_loot_template` SET `QuestRequired`= 1 WHERE `Item` IN (52506, 53139);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (75206, 75192) AND `SourceTypeOrReferenceId`= 17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(17, 0, 75206, 0, 0, 31, 1, 3, 38896, 0, 0, 0, '', 'Flamebreaker - Only allow Blazebound Elemental'),
(17, 0, 75192, 0, 0, 31, 1, 3, 40147, 0, 0, 0, '', 'Weakening - Only allow Baron Geddon');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (76205, 73518) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 76205, 0, 0, 31, 0, 5, 203065, 0, 0, 0, '', 'Emerald Flameweaver Drake Breath - Target Emerald Flames'),
(13, 1, 73518, 0, 0, 31, 0, 3, 39140, 0, 0, 0, '', 'Hyjal Intro Flight - Target Aronus');

DELETE FROM `conditions` WHERE `SourceEntry` IN (73518) AND `SourceTypeOrReferenceId`= 18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(18, 39140, 73518, 0, 0, 28, 0, 25316, 0, 0, 0, 0, '', 'Required quest complete for spellclick');

-- Update Movements
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 0 WHERE `id`= 39921;
UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `id`= 40229;
UPDATE `creature` SET `spawndist`= 5, `MovementType`= 1 WHERE `id`= 49844;

-- Template Updates
-- Scalding Rock Elemental
UPDATE `creature_template` SET `DamageModifier`= 2.3 WHERE `entry`= 40229;
-- Hyjal Warden
UPDATE `creature_template` SET `DamageModifier`= 2.3 WHERE `entry`= 38915;
-- Furious Hyjal Warden
UPDATE `creature_template` SET `DamageModifier`= 2.3 WHERE `entry`= 43427;
-- Twilight Infiltrator
UPDATE `creature_template` SET `DamageModifier`= 2.3, `mingold`= 2000, `maxgold`= 2500 WHERE `entry`= 40882;
-- Aronus
UPDATE `creature_template` SET `npcflag`= 16777216, `InhabitType`= 4 WHERE `entry`= 39140;
-- Ragnaros
UPDATE `creature_template` SET `InhabitType`= 4, `flags_extra`= 2 WHERE `entry`= 38806;
-- Deathwing
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 39867;
-- Generic Bunny - PRK (Large AOI)
UPDATE `creature_template` SET `InhabitType`= 4, `flags_extra`= 128 WHERE `entry`= 44775;
-- Twilight Vanquisher
UPDATE `creature_template` SET `DamageModifier`= 1.5, `flags_extra`= 2048, `BaseAttackTime`= 2000, `mingold`= 1000, `maxgold`= 4000 WHERE `entry`= 38913;
-- Twilight Flamecaller
UPDATE `creature_template` SET `DamageModifier`= 2.3, `mingold`= 1000, `maxgold`= 4000 WHERE `entry`= 38926;
-- Twilight Overseer
UPDATE `creature_template` SET `DamageModifier`= 2.3, `mingold`= 1000, `maxgold`= 4000 WHERE `entry`= 40123;
-- Blazebound Elemental
UPDATE `creature_template` SET `DamageModifier`= 2.3 WHERE `entry`= 38896;
-- Unbound Flame Spirit
UPDATE `creature_template` SET `unit_flags`= 33587968 WHERE `entry`= 40080;
-- Unbound Flame Spirit
UPDATE `creature_template` SET `unit_class`=2 WHERE `entry` IN (40065,40080);

-- Blazebound Elemental Entry: 38896 SAI
SET @ENTRY := 38896;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12500,15300,11,80031,0,0,0,0,0,2,0,0,0,0,0,0,0, "Blazebound Elemental - Combat - Cast 'Flaming Slice'"),
(@ENTRY,0,1,0,8,0,100,0,74723,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Blazebound Elemental - On Spell Hit  - Die");

-- Unbound Flame Spirit Entry: 40080 SAI
SET @ENTRY := 40080;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,116,2,0,0,0,0,0,1,0,0,0,0,0,0,0, "Unbound Flame Spirit - Just summoned - Set corpse delay"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,3,40065,0,0,0,0,0,1,0,0,0,0,0,0,0, "Unbound Flame Spirit - Just summoned - Morph to entry 40065"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,19,33554688,0,0,0,0,0,1,0,0,0,0,0,0,0, "Unbound Flame Spirit - Just summoned - Remove UNIT_FLAGS - UNIT_FLAG_IMMUNE_TO_PC, UNIT_FLAG_NOT_SELECTABLE"),
(@ENTRY,0,3,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0, "Unbound Flame Spirit - Just summoned - Attack Summoner"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,33,40065,0,0,0,0,0,7,0,0,0,0,0,0,0, "Unbound Flame Spirit - On death - Killcredit");

-- Twilight Vanquisher Entry: 38913 SAI
SET @ENTRY := 38913;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,14000,18000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0, "Twilight Vanquisher - Combat - Cast 'Slam'"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,5000,5000,49,0,0,0,0,0,0,11,38915,6,0,0,0,0,0, "Twilight Vanquisher - OOC - Attack Hyjal Warden");

-- Twilight Flamecaller Entry: 38926 SAI
SET @ENTRY := 38926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15536,64,0,0,0,0,2,0,0,0,0,0,0,0, "Twilight Flamecaller - Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,11000,12000,11,20794,0,0,0,0,0,2,0,0,0,0,0,0,0, "Twilight Flamecaller - Combat - Cast 'Flamestrike'"),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,21000,22000,11,11990,0,0,0,0,0,2,0,0,0,0,0,0,0, "Twilight Flamecaller - Combat - Cast 'Rain of Fire'"),
(@ENTRY,0,3,0,1,0,100,0,1000,1000,5000,5000,49,0,0,0,0,0,0,11,38915,10,0,0,0,0,0, "Twilight Flamecaller - Combat - Attack Hyjal Warden"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0, "Twilight Flamecaller - HP 0% - 15% - Flee for assist (No Repeat)");

-- SAI corrections and additions
-- Furious Hyjal Warden Entry: 43427 SAI
SET @ENTRY := 43427;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,22000,30000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0, "Furious Hyjal Warden - Combat - Cast 'Incapacitating Shout'"),
(@ENTRY,0,1,0,0,0,100,0,1000,3000,7000,14000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0, "Furious Hyjal Warden - Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,2,0,0,0,100,0,1000,3000,11000,13000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0, "Furious Hyjal Warden - Combat - Cast Snap Kick"),
(@ENTRY,0,3,0,1,0,100,0,1000,1000,3000,3000,49,0,0,0,0,0,0,11,40229,10,0,0,0,0,0, "Furious Hyjal Warden - OOC - Attack Scalding Rock Elemental");

-- Hyjal Warden Entry: 38915 SAI
SET @ENTRY := 38915;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11000,14000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0, "Hyjal Warden - Combat - Cast Snap Kick"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,3000,3000,49,0,0,0,0,0,0,11,40229,10,0,0,0,0,0, "Hyjal Warden - OOC - Attack Scalding Rock Elemental");

-- Scalding Rock Elemental Entry: 40229 SAI
SET @ENTRY := 40229;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,10000,15000,19000,11,80638,0,0,0,0,0,2,0,0,0,0,0,0,0, "Scalding Rock Elemental - Combat - Cast Searing Touch");

-- Cenarion Emissary Jademoon Entry: 15187 SAI
SET @ENTRY := 15187;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,0,0,0,62,0,100,512,12129,0,0,0,86,86587,0,7,0,0,0,7,0,0,0,0,0,0,0, "Cenarion Emissary Jademoon - Gossip Option Select - Invoker Cast Teleport to Moonglade");

-- Cenarion Emissary Blackhoof Entry: 15188 SAI
SET @ENTRY := 15188;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,0,0,0,62,0,100,512,12125,0,0,0,86,86565,0,7,0,0,0,7,0,0,0,0,0,0,0, "Cenarion Emissary Blackhoof - Gossip Option Select - Invoker Cast Teleport to Moonglade");

-- Ragnaros Entry: 38806 SAI
SET @ENTRY := 38806;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Ragnaros - Just Created - Say 0"),
(@ENTRY,0,1,0,60,0,100,1,3500,3500,0,0,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0, "Ragnaros - Update - Emote 53");

-- As Hyjal Burns Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (38806, 39128);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(38806, 0, 0, 'BY FIRE BE PURGED!!!!', 14, 0, 100, 449, 0, 23335, 39839, 'Ragnaros to Player'),
(39128, 0, 0, 'No... it can\'t be.  Our forward outpost has been obliterated!', 12, 0, 100, 0, 0, 20950, 39185, 'Aronus to Player'),
(39128, 1, 0, 'Is it too late?  I feel Deathwing\'s presence nearby!', 12, 0, 100, 0, 0, 20951, 39186, 'Aronus to Player'),
(39128, 2, 0, 'The Firelord has risen!  We must send word to the others.  Let us hurry!', 12, 0, 100, 0, 0, 20952, 39189, 'Aronus to Player');
UPDATE `creature_text` SET `TextRange`= 1 WHERE `CreatureID`= 38806;

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (39140, 39128);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(39140, 73518, 1, 0),(39128, 76649, 1, 0);
