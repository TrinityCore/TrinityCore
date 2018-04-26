-- Assign scriptname to instance
UPDATE `instance_template` SET `script`= 'instance_grim_batol' WHERE `map`= 670;

-- Template Updates
UPDATE `creature_template` SET `scriptname`= 'boss_general_umbriss', `flags_extra`= `flags_extra`| 0x40000000 WHERE `entry`= 39625;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `BaseAttackTime`= 1500, `unit_flags`= 67141696, `lootid`= 48337, `mechanic_immune_mask`= 617299839, `flags_extra`= `flags_extra`| 0x40000000 WHERE `entry`= 48337;
-- Blitz / Ground Siege
UPDATE `creature_template` SET `faction`= 35, `unit_flags`= 33554688, `flags_extra`= 131 WHERE `entry` IN (40040, 40030);

-- Remove db side spawned Malignant Trogg
DELETE FROM `creature` WHERE `guid`= 340015;
DELETE FROM `creature_addon` WHERE `guid`= 340015;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 39625;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(39625, 0, 0, 'Cover the rear! Alexstrasza''s brood decimate our ranks!', 14, 0, 100, 0, 0, 18537, 40642, 'General Umbriss'),
(39625, 0, 1, 'Reinforce the front! We are being invaded!', 14, 0, 100, 0, 0, 18536, 40640, 'General Umbriss'),
(39625, 1, 0, 'A million more await my orders. What chance do you have?', 14, 0, 100, 0, 0, 18530, 47784, 'General Umbriss to Player'),
(39625, 2, 0, 'Attack you cowardly vermin!', 14, 0, 100, 0, 0, 18535, 47799, 'General Umbriss'),
(39625, 2, 1, 'Vermin, your dinner awaits!', 14, 0, 100, 0, 0, 18531, 47785, 'General Umbriss'),

(39625, 3, 0, 'Messy...', 14, 0, 100, 0, 0, 18532, 47786, 'General Umbriss'),
(39625, 4, 0, '|TInterface\\Icons\\ability_warrior_charge.blp:20|tGeneral Umbriss sets his eyes on |cFFFF0000$n|r and begins to cast |cFFFF0000|Hspell:74670|h[Blitz]|h|r!', 41, 0, 100, 0, 0, 0, 39994, 'General Umbriss to Player'),
(39625, 5, 0, '|TInterface\\Icons\\spell_nature_earthquake.blp:20|tGeneral Umbriss begins to cast |cFFFF0000|Hspell:74634|h[Ground Siege]|h|r!', 41, 0, 100, 0, 0, 0, 50666, 'General Umbriss to Ground Siege'),
(39625, 6, 0, '%s goes into a frenzy!', 41, 0, 100, 0, 0, 0, 10645, 'General Umbriss');

-- Spell scriptnames
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_umbriss_summon_blitz_trigger',
'spell_umbriss_summon_ground_siege_trigger',
'spell_umbriss_bleeding_wound',
'spell_umbriss_modguds_malice');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(74668, 'spell_umbriss_summon_blitz_trigger'),
(74640, 'spell_umbriss_summon_ground_siege_trigger'),
(74846, 'spell_umbriss_bleeding_wound'),
(91937, 'spell_umbriss_bleeding_wound'),
(74699, 'spell_umbriss_modguds_malice'),
(90169, 'spell_umbriss_modguds_malice');

DELETE FROM `conditions` WHERE `SourceEntry` IN (74670, 90250, 74634, 90249, 90170) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 74670, 0, 0, 31, 0, 3, 40040, 0, 0, 0, '', 'Blitz - Target Blitz Stalker'),
(13, 1, 90250, 0, 0, 31, 0, 3, 40040, 0, 0, 0, '', 'Blitz - Target Blitz Stalker'),
(13, 1, 74634, 0, 0, 31, 0, 3, 40030, 0, 0, 0, '', 'Ground Siege - Target Ground Siege Stalker'),
(13, 1, 90249, 0, 0, 31, 0, 3, 40030, 0, 0, 0, '', 'Ground Siege - Target Ground Siege Stalker'),
(13, 1, 90170, 0, 0, 31, 0, 3, 39625, 0, 0, 0, '', 'Modgud''s Malice - Target General Umbriss'),
(13, 2, 90170, 0, 0, 31, 0, 3, 39625, 0, 0, 0, '', 'Modgud''s Malice - Target General Umbriss'),
(13, 4, 90170, 0, 0, 31, 0, 3, 45467, 0, 0, 0, '', 'Modgud''s Malice - Target Trogg Dweller');

-- Creature Malignant Trogg 39984 SAI
SET @ENTRY := 39984;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 3000, 3000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 3000 and 3000 ms (and later repeats every 0 and 0 ms) - Self: Attack Players in 100 yards // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 6000, 7000, 6000, 7000, 11, 76507, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 7000 ms (and later repeats every 6000 and 7000 ms) - Self: Cast spell 76507 on Victim // ");

DELETE FROM `creature_template_addon` WHERE `entry`= 48350;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(48350, 1, 74699);

-- Creature Trogg Dweller 45467 SAI
SET @ENTRY := 45467;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 3000, 3000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 3000 and 3000 ms (and later repeats every 0 and 0 ms) - Self: Attack Players in 100 yards // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 6000, 7000, 6000, 7000, 11, 76507, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 7000 ms (and later repeats every 6000 and 7000 ms) - Self: Cast spell 76507 on Victim // ");

-- Remove pathfinding from troggs since they have to pass ugly terrain
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x20000000 WHERE `entry` IN (45467, 39984, 48350, 48348);
