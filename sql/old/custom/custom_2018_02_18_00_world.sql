-- Template Updates
-- Foe Reaper 5000
UPDATE `creature_template` SET `unit_flags2`= 0, `ScriptName`= 'boss_foe_reaper_5000' WHERE `entry`= 43778;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `unit_flags2`= 0, `flags_extra`= 1 WHERE `entry`= 48941;
-- Prototype Reaper
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857, `spell1`= 91734, `spell2`= 91735, `spell3`= 91736, `unit_flags2`= 0 WHERE `entry`= 49208;
UPDATE `npc_spellclick_spells` SET `spell_id`= 43671 WHERE `npc_entry`= 49208;
-- Defias Watcher
UPDATE `creature_template` SET `unit_flags2`= 0, `RegenHealth`= 0, `ScriptName`= 'npc_deadmines_defias_watcher' WHERE `entry`= 47404;
UPDATE `creature_template` SET `unit_flags2`= 0, `RegenHealth`= 0 WHERE `entry`= 48803;
-- Defias Reaper
UPDATE `creature_template` SET `unit_flags2`= 0, `ScriptName`= 'npc_deadmines_defias_watcher' WHERE `entry`= 47403;
UPDATE `creature_template` SET `unit_flags2`= 0 WHERE `entry`= 48804;
-- Deadmines Foe Reaper Targeting Bunny
UPDATE `creature_template` SET `faction`= 35, `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 47468;
-- Molten Slag
UPDATE `creature_template` SET `DamageModifier`= 30, `ScriptName`= 'npc_foe_reaper_5000_molten_slag' WHERE `entry`= 49229;


DELETE FROM `creature_text` WHERE `CreatureID` IN (43778, 45979);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
-- Foe Reaper 5000
(43778, 0, 0, 'Foe Reaper 5000 on-line.  All systems nominal.', 14, 0, 100, 0, 0, 22137, 47596, 'Foe Reaper 5000'),
(43778, 1, 0, '|TInterface\\Icons\\ability_whirlwind.blp:20|t Foe Reaper 5000 begins to activate |cFFFF0000|Hspell:88481|h[Overdrive]|h|r!', 41, 0, 100, 0, 0, 0, 48812, 'Foe Reaper 5000'),
(43778, 2, 0, 'Overdrive engine activated.', 14, 0, 100, 0, 0, 22142, 47609, 'Foe Reaper 5000'),
(43778, 3, 0, 'Acquiring target...', 14, 0, 100, 0, 0, 22140, 47628, 'Foe Reaper 5000 to Player'),
(43778, 4, 0, 'Target acquired.  Harvesting servos engaged.', 14, 0, 100, 0, 0, 22141, 47629, 'Foe Reaper 5000'),
(43778, 5, 0, 'Safety restrictions off-line.  Catastrophic system failure imminent.', 14, 0, 100, 0, 0, 22143, 47642, 'Foe Reaper 5000'),
(43778, 6, 0, '|TInterface\Icons\spell_fire_totemofwrath.blp:20|t Foe Reaper 5000 |cFFFF0000|Hspell:88522|h[Safety Restrictions are Off-line]|h|r!', 41, 0, 100, 0, 0, 0, 50713, 'Foe Reaper 5000'),
(43778, 7, 0, 'Target destroyed.', 14, 0, 100, 0, 0, 22139, 47630, 'Feindschnitter 5000 to Player'),
(43778, 8, 0, 'Overheat threshold exceeded.  System failure.  Wheat clog in port two.  Shutting down.', 14, 0, 100, 0, 0, 22138, 47643, 'Foe Reaper 5000'),
-- General Purpose Bunny
(45979, 0, 0, 'A stray jolt from the Foe Reaper has disrupted the foundry controls!', 41, 0, 100, 0, 0, 0, 49315, 'General Purpose Bunny JMF'),
(45979, 1, 0, 'The molten slag begins to bubble furiously!', 41, 0, 100, 0, 0, 0, 49316, 'General Purpose Bunny JMF');

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry`= 47468;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(47468, 88508);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (89132, 91839, 91841, 91842, 91843) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 89132, 0, 0, 31, 0, 3, 43778, 0, 0, 0, '', 'Energize - Target Foe Reaper 5000'),
(13, 1, 91839, 0, 0, 31, 0, 5, 123207, 0, 0, 0, '', 'Summon Molten Slag - Target Goblin Smelthing Pot'),
(13, 1, 91841, 0, 0, 31, 0, 5, 123208, 0, 0, 0, '', 'Summon Molten Slag - Target Goblin Smelthing Pot'),
(13, 1, 91842, 0, 0, 31, 0, 5, 123209, 0, 0, 0, '', 'Summon Molten Slag - Target Goblin Smelthing Pot'),
(13, 1, 91843, 0, 0, 31, 0, 5, 123210, 0, 0, 0, '', 'Summon Molten Slag - Target Goblin Smelthing Pot');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_deadmines_on_fire',
'spell_foe_reaper_5000_acquire_target',
'spell_foe_reaper_5000_fixate_targeting',
'spell_foe_reaper_5000_fixate');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(91737, 'spell_deadmines_on_fire'),
(88492, 'spell_foe_reaper_5000_acquire_target'),
(91831, 'spell_foe_reaper_5000_fixate_targeting'),
(91830, 'spell_foe_reaper_5000_fixate');

-- Loot
UPDATE `creature_template` SET `lootid`= 43778 WHERE `entry` = 43778;
DELETE FROM creature_loot_template WHERE `Entry` IN (43778, 48941);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(43778, 1937, 0, 1, 1, 1, 1),
(43778, 5187, 0, 1, 1, 1, 1),
(43778, 5201, 0, 1, 1, 1, 1);

UPDATE `creature_template` SET `lootid` = 48941 WHERE `entry` = 48941;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(48941, 65166, 0, 1, 1, 1, 1),
(48941, 65165, 0, 1, 1, 1, 1),
(48941, 65167, 0, 1, 1, 1, 1);

-- SAI
-- Creature General Purpose Bunny JMF (Look 2) 47242 SAI
SET @ENTRY := 47242;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
SET @ENTRY := -375839;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 72, 0, 100, 0, 1, 0, 0, 0, 67, 0, 150, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On DoAction 1 - Trigger timed event #0"),
(@ENTRY, 0, 1, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 89202, 2, 0, 0, 0, 0, 10, 375842, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 89202 on Creature General Purpose Bunny JMF (Look 2)");

SET @ENTRY := -375846;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 72, 0, 100, 0, 1, 0, 0, 0, 67, 0, 2500, 2500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On DoAction 1 - Trigger timed event #0"),
(@ENTRY, 0, 1, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 89202, 2, 0, 0, 0, 0, 10, 375841, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 89202 on Creature General Purpose Bunny JMF (Look 2)");

SET @ENTRY := -375922;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 72, 0, 100, 0, 1, 0, 0, 0, 67, 0, 2500, 2500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On DoAction 1 - Trigger timed event #0"),
(@ENTRY, 0, 1, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 89202, 2, 0, 0, 0, 0, 10, 375840, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 89202 on Creature General Purpose Bunny JMF (Look 2)");

SET @ENTRY := -375844;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 72, 0, 100, 0, 1, 0, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On DoAction 1 - Trigger timed event #0"),
(@ENTRY, 0, 1, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 89202, 2, 0, 0, 0, 0, 10, 375923, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 89202 on Creature General Purpose Bunny JMF (Look 2)");

SET @ENTRY := -375843;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 72, 0, 100, 0, 1, 0, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On DoAction 1 - Trigger timed event #0"),
(@ENTRY, 0, 1, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 89202, 2, 0, 0, 0, 0, 10, 375848, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 89202 on Creature General Purpose Bunny JMF (Look 2)");

SET @ENTRY := -375847;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 72, 0, 100, 0, 1, 0, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On DoAction 1 - Trigger timed event #0"),
(@ENTRY, 0, 1, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 89202, 2, 0, 0, 0, 0, 10, 375921, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 89202 on Creature General Purpose Bunny JMF (Look 2)");
