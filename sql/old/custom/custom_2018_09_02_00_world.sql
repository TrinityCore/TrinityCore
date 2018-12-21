-- Scalding Rock Elemental
UPDATE `creature_template` SET `DamageModifier`= 2.3 WHERE `entry`= 40229;
-- Hyjal Warden
UPDATE `creature_template` SET `DamageModifier`= 2.3 WHERE `entry`= 38915;
-- Furious Hyjal Warden
UPDATE `creature_template` SET `DamageModifier`= 2.3 WHERE `entry`= 43427;
-- Faerie Dragon
UPDATE `creature_template` SET `ScriptName`= 'npc_mh_faerie_dragon' WHERE `entry`= 39921;
-- Twilight Inciter
UPDATE `creature_template` SET `DamageModifier`= 1.5, `flags_extra`= 2048, `ScriptName`= 'npc_mh_twilight_inciter' WHERE `entry`= 39926;
-- Emerald Flameweaver
UPDATE `creature_template` SET `InhabitType`= 4, `ScriptName`= 'npc_mh_emerald_flameweaver' WHERE `entry`= 40856;
-- Twilight Infiltrator
UPDATE `creature_template` SET `DamageModifier`= 2.3, `mingold`= 2000, `maxgold`= 2500 WHERE `entry`= 40882;
-- Aronus
UPDATE `creature_template` SET `npcflag`= 16777216, `InhabitType`= 4 WHERE `entry`= 39140;
-- Aronus (summoned vehicle)
UPDATE `creature_template` SET `InhabitType`= 4, `VehicleId`= 726, `unit_flags`= 33032, `ScriptName`= 'npc_mh_aronus' WHERE `entry`= 39128;
-- Ragnaros
UPDATE `creature_template` SET `InhabitType`= 4, `flags_extra`= 2 WHERE `entry`= 38806;
-- Deathwing
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 39867;
-- Generic Bunny - PRK (Large AOI)
UPDATE `creature_template` SET `InhabitType`= 4, `flags_extra`= 128 WHERE `entry`= 44775;

-- Sparring Data
DELETE FROM `creature_sparring_template` WHERE `AttackerEntry` IN (38915, 40229, 43427);
INSERT INTO `creature_sparring_template` (`AttackerEntry`, `VictimEntry`, `HealthLimitPct`) VALUES
-- Scalding Rock Elemental vs. Hyjal Warden
(38915, 40229, 90),
(40229, 38915, 90),
-- Scalding Rock Elemental vs. Furious Hyjal Warden
(43427, 40229, 90),
(40229, 43427, 90);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (39921, 39926, 38806, 39128);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Nordrassil Quests
(39921, 0, 0, 'We find evil ones now!  Follow!', 12, 0, 100, 0, 0, 0, 40300, 'Faerie Dragon to Player'),
(39921, 0, 1, 'They hide this way!  Quick!', 12, 0, 100, 0, 0, 0, 40301, 'Faerie Dragon to Player'),
(39921, 0, 2, 'Meep!  $R is good friend.  Follow now!  We find intruder!', 12, 0, 100, 0, 0, 0, 39943, 'Faerie Dragon to Player'),
(39921, 0, 3, 'We look for the evil ones now, yes?', 12, 0, 100, 0, 0, 0, 40302, 'Faerie Dragon to Player'),
(39921, 1, 0, 'You must fight now, $n!', 14, 0, 100, 0, 0, 0, 40304, 'Faerie Dragon to Player'),
(39921, 1, 1, 'Over here!  You must stop them!', 14, 0, 100, 0, 0, 0, 40303, 'Faerie Dragon to Player'),
(39921, 1, 2, 'Over here, $n!', 14, 0, 100, 0, 0, 0, 40305, 'Faerie Dragon to Player'),
(39921, 1, 3, 'We finds evil one!  Quick!', 14, 0, 100, 0, 0, 0, 39944, 'Faerie Dragon to Player'),
(39926, 0, 0, 'You will not give away my position, $c!', 12, 0, 100, 0, 0, 0, 39947, 'Twilight Inciter to Player'),
(39926, 0, 1, 'I\'ve been spotted?  Time to die!', 12, 0, 100, 0, 0, 0, 39946, 'Twilight Inciter to Player'),
(39926, 0, 2, 'How did you find me?  It matters little... you will die!', 12, 0, 100, 0, 0, 0, 39945, 'Twilight Inciter to Player'),
(39926, 0, 3, 'You might have found me, but you won\'t bring word back to the others!', 12, 0, 100, 0, 0, 0, 39948, 'Twilight Inciter to Player'),
-- As Hyjal Burns
(38806, 0, 0, 'BY FIRE BE PURGED!!!!', 14, 0, 100, 449, 0, 23335, 39839, 'Ragnaros to Player'),
(39128, 0, 0, 'No... it can\'t be.  Our forward outpost has been obliterated!', 12, 0, 100, 0, 0, 20950, 39185, 'Aronus to Player'),
(39128, 1, 0, 'Is it too late?  I feel Deathwing\'s presence nearby!', 12, 0, 100, 0, 0, 20951, 39186, 'Aronus to Player'),
(39128, 2, 0, 'The Firelord has risen!  We must send word to the others.  Let us hurry!', 12, 0, 100, 0, 0, 20952, 39189, 'Aronus to Player');

UPDATE `creature_text` SET `TextRange`= 1 WHERE `CreatureID`= 38806;

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (39140, 39128);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(39140, 73518, 1, 0),
(39128, 76649, 1, 0);

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_mh_summon_emerald_flameweaver',
'spell_mh_ragnaros');

DELETE FROM `spell_script_names` WHERE `spell_id`= 51254;

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76212, 'spell_mh_summon_emerald_flameweaver'),
(74436, 'spell_mh_ragnaros'),
(51254, 'spell_gen_eject_all_passengers');

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

-- Gameobject focus (203087)
DELETE FROM `gameobject` WHERE `guid`= 19;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseID`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(19, 203087, 1, 0, 0, 1, 169, 5758.737, -3297.48, 1604.599, 0, 0, 0, 0, 1, 6000, 100, 1, 0);

-- Quest chains
DELETE FROM `quest_template_addon` WHERE `ID` IN (25584, 27874, 25612, 25611, 29437, 25830, 25520, 25514, 25519, 25807);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`) VALUES
(25584, 25578, 0, 0),
(27874, 25612, 0, 0),
(25612, 25600, 0, 25612),
(25611, 25600, 0, 25612),
(29437, 29326, 0, 0),
(25830, 25520, 0, 0),
(25520, 25514, 0, -25520),
(25807, 25795, 0, -25520),
(25514, 25510, 0, -25514),
(25519, 25510, 0, -25514);

-- Spell Area
DELETE FROM `spell_area` WHERE `area` IN (493, 5040) AND `spell`= 49416;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `autocast`, `gender`, `quest_start_status`, `quest_end_status`) VALUES
(49416, 493, 25316, 25316, 1, 2, 2, 11),
(49416, 5040, 25316, 25316, 1, 2, 2, 11);

-- SAI corrections and additions
-- Creature Furious Hyjal Warden 43427 SAI
SET @ENTRY := 43427;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5000, 6000, 22000, 30000, 11, 18328, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 6000 ms (and later repeats every 22000 and 30000 ms) - Self: Cast spell 18328 on Self // Furious Hyjal Warden - In Combat - Cast 'Incapacitating Shout'"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 1000, 3000, 7000, 14000, 11, 19643, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1000 and 3000 ms (and later repeats every 7000 and 14000 ms) - Self: Cast spell 19643 on Victim // Furious Hyjal Warden - In Combat - Cast 'Mortal Strike'"),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 1000, 3000, 11000, 13000, 11, 15618, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1000 and 3000 ms (and later repeats every 11000 and 13000 ms) - Self: Cast spell 15618 on Victim // "),
(@ENTRY, 0, 3, 0, 1, 0, 100, 0, 1000, 1000, 3000, 3000, 49, 0, 0, 0, 0, 0, 0, 11, 40229, 10, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1000 and 1000 ms (and later repeats every 3000 and 3000 ms) - Self: Attack Creature Scalding Rock Elemental (40229) in 10 yd // ");

-- Creature Hyjal Warden 38915 SAI
SET @ENTRY := 38915;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 11000, 14000, 11, 19643, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 11000 and 14000 ms) - Self: Cast spell 19643 on Victim // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 1000, 1000, 3000, 3000, 49, 0, 0, 0, 0, 0, 0, 11, 40229, 10, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1000 and 1000 ms (and later repeats every 3000 and 3000 ms) - Self: Attack Creature Scalding Rock Elemental (40229) in 10 yd // ");

-- Creature Scalding Rock Elemental 40229 SAI
SET @ENTRY := 40229;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 8000, 10000, 15000, 19000, 11, 80638, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 10000 ms (and later repeats every 15000 and 19000 ms) - Self: Cast spell 80638 on Victim // ");

-- Creature Cenarion Emissary Jademoon 15187 SAI
SET @ENTRY := 15187;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 512, 12129, 0, 0, 0, 86, 86587, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 12129 selected - SMART_TARGET_ACTION_INVOKER: Cast spell 86587 at Action invoker // ");

-- Creature Cenarion Emissary Blackhoof 15188 SAI
SET @ENTRY := 15188;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 512, 12125, 0, 0, 0, 86, 86565, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 12125 selected - SMART_TARGET_ACTION_INVOKER: Cast spell 86565 at Action invoker // ");

-- Creature Ragnaros 38806 SAI
SET @ENTRY := 38806;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 3500, 3500, 0, 0, 5, 53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 3500 and 3500 ms) - Self: Play emote 53 // ");
