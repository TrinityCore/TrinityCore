-- Template Updates
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

-- Sparring Data
DELETE FROM `creature_sparring_template` WHERE `AttackerEntry`= 38915 AND `VictimEntry` IN (38913, 38926, 38896, 40123);
DELETE FROM `creature_sparring_template` WHERE `AttackerEntry` IN (38913, 38926, 38902, 38896, 40123, 38952);
INSERT INTO `creature_sparring_template` (`AttackerEntry`, `VictimEntry`, `HealthLimitPct`) VALUES
-- Hyjal Warden vs. Twilight Vanquisher
(38915, 38913, 90),
(38913, 38915, 90),
-- Hyjal Warden vs. Twilight Flamecaller
(38915, 38926, 90),
(38926, 38915, 90),
-- Hyjal Warden vs. Blazebound Elemental
(38915, 38896, 90),
(38896, 38915, 90),
-- Hyjal Warden vs. Twilight Overseer
(38915, 40123, 90),
(40123, 38915, 90),
-- Ironbark Ancient vs. Twilight Vanquisher
(38902, 38913, 90),
(38913, 38902, 90),
-- Ironbark Ancient vs. Twilight Flamecaller
(38902, 38926, 90),
(38926, 38902, 90),
-- Ironbark Ancient vs. Blazebound Elemental
(38902, 38896, 90),
(38896, 38902, 90),
-- Nordrassil Druid vs. Twilight Vanquisher
(38952, 38913, 90),
(38913, 38952, 90),
-- Nordrassil Druid vs. Twilight Flamecaller
(38952, 38926, 90),
(38926, 38952, 90),
-- Nordrassil Druid vs. Blazebound Elemental
(38952, 38896, 90),
(38896, 38952, 90),
-- Nordrassil Druid vs. Twilight Overseer
(38952, 40123, 90),
(40123, 38952, 90);

-- Quest chains
DELETE FROM `quest_template_addon` WHERE `ID` IN (25472, 25430, 25323, 25319);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`) VALUES
(25472, 25317, 0, -25472),
(25319, 25317, 0, -25472),
(25430, 25464, 0, 0),
(25323, 25472, 0, 0);

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_mh_flamebreaker');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75206, 'spell_mh_flamebreaker');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (75206, 75192) AND `SourceTypeOrReferenceId`= 17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(17, 0, 75206, 0, 0, 31, 1, 3, 38896, 0, 0, 0, '', 'Flamebreaker - Only allow Blazebound Elemental'),
(17, 0, 75192, 0, 0, 31, 1, 3, 40147, 0, 0, 0, '', 'Weakening - Only allow Baron Geddon');

-- Make quest items quest related
UPDATE `creature_loot_template` SET `QuestRequired`= 1 WHERE `Item` IN (52506, 53139);

-- Remove  duplicate spawns
DELETE FROM `creature` WHERE `guid` IN (394598, 384268);
DELETE FROM `creature_addon` WHERE `guid` IN (394598, 384268);

-- Creature Nordrassil Druid SAI
SET @ENTRY := -384003;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 74492, 0, 0, 0, 0, 0, 10, 384034, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 74492 on Creature Ysera 40289 (384034) // ");

SET @ENTRY := -383996;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 74492, 0, 0, 0, 0, 0, 10, 384034, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 74492 on Creature Ysera 40289 (384034) // ");

SET @ENTRY := -384013;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 74492, 0, 0, 0, 0, 0, 10, 384034, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 74492 on Creature Ysera 40289 (384034) // ");

-- Creature Blazebound Elemental 38896 SAI
SET @ENTRY := 38896;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 12500, 15300, 11, 80031, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 12500 and 15300 ms) - Self: Cast spell 80031 on Victim // "),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 74723, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell 74723 hit  - Self: Die // ");

-- Creature Unbound Flame Spirit 40080 SAI
SET @ENTRY := 40080;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 60, 0, 100, 1, 2000, 2000, 0, 0, 3, 0, 8409, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 2000 and 2000 ms) - Self: Morph to model 8409 // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 19, 33555200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Remove UNIT_FLAGS to UNIT_FLAG_IMMUNE_TO_PC, UNIT_FLAG_IMMUNE_TO_NPC, UNIT_FLAG_NOT_SELECTABLE // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Attack Owner/Summoner // "),
(@ENTRY, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 33, 40065, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On death - Action invoker: Give kill credit Unbound Flame Spirit (40065) // "),
(@ENTRY, 0, 4, 0, 63, 0, 100, 0, 0, 0, 0, 0, 116, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Sets corpse delay of Self to 2ms // ");

-- Creature Twilight Vanquisher 38913 SAI
SET @ENTRY := 38913;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 8000, 14000, 18000, 11, 79881, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 8000 ms (and later repeats every 14000 and 18000 ms) - Self: Cast spell 79881 on Victim // Twilight Vanquisher - In Combat - Cast 'Slam'"),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 1000, 1000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 11, 38915, 6, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1000 and 1000 ms (and later repeats every 5000 and 5000 ms) - Self: Attack Creature Hyjal Warden (38915) in 6 yd // ");

-- Creature Twilight Flamecaller 38926 SAI
SET @ENTRY := 38926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, 11, 15536, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 3400 and 4700 ms) - Self: Cast spell 15536 on Victim // Twilight Flamecaller - In Combat - Cast 'Fireball'"),
(@ENTRY, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 15% (check every 0 - 0 ms) - Self: Flee for assist // Twilight Flamecaller - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 3000, 6000, 11000, 12000, 11, 20794, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3000 and 6000 ms (and later repeats every 11000 and 12000 ms) - Self: Cast spell 20794 on Victim // Twilight Flamecaller - In Combat - Cast 'Flamestrike'"),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 9000, 9000, 21000, 22000, 11, 11990, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9000 and 9000 ms (and later repeats every 21000 and 22000 ms) - Self: Cast spell 11990 on Victim // Twilight Flamecaller - In Combat - Cast 'Rain of Fire'"),
(@ENTRY, 0, 4, 0, 1, 0, 100, 0, 1000, 1000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 11, 38915, 10, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1000 and 1000 ms (and later repeats every 5000 and 5000 ms) - Self: Attack Creature Hyjal Warden (38915) in 10 yd // ");
