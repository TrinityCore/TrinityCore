-- High Prophet Barim
UPDATE `creature_template` SET `difficulty_entry_1`= 48951, `mechanic_immune_mask`= 667893759, `lootid`= 43612, `mingold`= 19800, `maxgold`= 19900, `scriptname`= 'boss_high_prophet_barim'  WHERE `entry`= 43612;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `exp`= 3, `mechanic_immune_mask`= 667893759, `lootid`= 48951, `mingold`= 19800, `maxgold`= 19900, `movementId`= 138 WHERE `entry`= 48951;
UPDATE `creature` SET `PhaseID`= 0, `PhaseGroup`= 391 WHERE `guid`= 306829;
-- Heavens Fury
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 43801;
-- Wail of Twilight
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 43926;
-- Repentance
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 14, `unit_flags`= 33554432, `flags_extra`=  2, `scriptname`= 'npc_barim_repentance' WHERE `entry`= 43817;
-- Harbinger of Darkness
UPDATE `creature_template` SET  `difficulty_entry_1`= 48953, `minlevel`= 86, `maxlevel`= 86, `faction`= 16, `mechanic_immune_mask`= 667893759, `scriptname`= 'npc_barim_harbinger_of_darkness' WHERE `entry`= 43927;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `exp`= 3, `mechanic_immune_mask`= 667893759 WHERE `entry`= 48953;
-- Blaze of the Heavens Dummy
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 48904;
-- Blaze of the Heavens
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `mechanic_immune_mask`= 667893759, `scriptname`= 'npc_barim_blaze_of_the_heavens' WHERE `entry`= 48906;
-- Blaze of the Heavens Fire Dummy
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `unit_flags`= 33554496, `flags_extra`= 128 WHERE `entry`= 48907;
-- Soul Fragment
UPDATE `creature_template` SET `mechanic_immune_mask`= 667893759, `difficulty_entry_1`= 48954, `faction`= 16, `exp`= 3, `minlevel`= 84, `maxlevel`= 84, `scriptname`= 'npc_barim_soul_fragment' WHERE `entry`= 43934;
UPDATE `creature_template` SET `mechanic_immune_mask`= 667893759, `faction`= 16, `exp`= 3, `minlevel`= 85, `maxlevel`= 85 WHERE `entry`= 48954;
-- Burning Soul
UPDATE `creature_template` SET `difficulty_entry_1`= 49220, `minlevel`= 84, `maxlevel`= 84, `unit_flags`= 33554432, `faction`= 16, `flags_extra`= 128 WHERE `entry`= 49219;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `unit_flags`= 33554432, `faction`= 16, `flags_extra`= 131 WHERE `entry`= 49220;

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (43612, 43934);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(43612, 0, 0, 'Begone infidels, you are not welcome here!', 14, 0, 100, 0, 0, 19735, 44791, 'High Prophet Barim'),
(43612, 1, 0, 'May peace find you now.', 14, 0, 100, 0, 0, 19738, 44793, 'High Prophet Barim'),
(43612, 1, 1, 'The heavens take you!', 14, 0, 100, 0, 0, 19736, 44794, 'High Prophet Barim'),
(43612, 2, 0, 'Kneel before me and repent!', 14, 0, 100, 0, 0, 19737, 44795, 'High Prophet Barim'),
(43612, 3, 0, 'Death is only the beginning!', 14, 0, 100, 0, 0, 19733, 44792, 'High Prophet Barim'),
(43934, 0, 0, 'A soul fragment merges souls with the Harbinger of Darkness!', 41, 0, 100, 0, 0, 0, 52151, 'Soul Fragment');

-- Spell Script Names
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_barim_plague_of_ages_first',
 'spell_barim_plague_of_ages_second',
 'spell_barim_repentance_script',
 'spell_barim_repentance_pull');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(82637, 'spell_barim_plague_of_ages_first'),
(89996, 'spell_barim_plague_of_ages_first'),
(82640, 'spell_barim_plague_of_ages_second'),
(89995, 'spell_barim_plague_of_ages_second'),
(82009, 'spell_barim_repentance_script'),
(81960, 'spell_barim_repentance_script'),
(82220, 'spell_barim_repentance_script'),
(82168, 'spell_barim_repentance_pull');

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (43801, 43926, 48907);
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(43801, '81940 81941'),
(48907, '91195');

-- Creature Veil of Twilight 43926 SAI
SET @ENTRY := 43926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 11, 82197, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 1000 and 1000 ms) - Self: Cast spell 82197 on Self // "),
(@ENTRY, 0, 1, 2, 60, 0, 100, 1, 2000, 2000, 0, 0, 41, 4000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 2000 and 2000 ms) - Self: Despawn in 4000 ms // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 82203, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 82203 on Self // ");

-- Creature Blaze of the Heavens 48904 SAI
SET @ENTRY := 48904;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 11, 91179, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 1000 and 1000 ms) - Self: Cast spell 91179 on Self // "),
(@ENTRY, 0, 1, 2, 60, 0, 100, 1, 2000, 2000, 0, 0, 41, 4000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 2000 and 2000 ms) - Self: Despawn in 4000 ms // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 91180, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 91180 on Self // ");

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (91196, 91277, 82224, 82263) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO conditions (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 2, 91196, 0, 0, 31, 0, 3, 48907, 0, 0, 0, '', 'Blaze of the Heavens - Target Blaze of the Heavens'),
(13, 2, 91196, 0, 0, 31, 0, 3, 48906, 0, 0, 0, '', 'Blaze of the Heavens - Target Blaze of the Heavens'),
(13, 1, 91277, 0, 0, 31, 0, 3, 43934, 0, 0, 0, '', 'Burning Soul  - Target Soul Fragment'),
(13, 1, 82224, 0, 0, 31, 0, 3, 43927, 0, 0, 0, '', 'Soul Fragment  - Target Harbinger of Darkness'),
(13, 7, 82263, 0, 0, 31, 0, 3, 43927, 0, 0, 0, '', 'Soul Fragment  - Target Harbinger of Darkness');

-- Loot
DELETE FROM `creature_loot_template` WHERE `Entry` IN (43612, 48951);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `LootMode`, `MinCount`, `MaxCount`) VALUES
(43612, 436120, 436120, 100, 1, 1, 1),
(48951, 489510, 489510, 100, 1, 1, 1);

DELETE FROM `reference_loot_template` WHERE `Entry` IN (436120, 489510);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `MinCount`, `MaxCount`, `GroupId`) VALUES
-- Normal Mode
(436120, 55865, 0, 1, 1, 1, 1),
(436120, 55864, 0, 1, 1, 1, 1),
(436120, 55861, 0, 1, 1, 1, 1),
(436120, 55862, 0, 1, 1, 1, 1),
(436120, 55863, 0, 1, 1, 1, 1),
-- Heroic Mode
(489510, 56384, 0, 1, 1, 1, 1),
(489510, 56385, 0, 1, 1, 1, 1),
(489510, 56386, 0, 1, 1, 1, 1),
(489510, 56387, 0, 1, 1, 1, 1),
(489510, 56388, 0, 1, 1, 1, 1);
