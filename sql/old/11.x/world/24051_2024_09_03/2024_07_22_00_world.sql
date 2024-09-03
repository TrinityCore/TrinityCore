UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54205 WHERE (`Entry`=41200 AND `DifficultyID`=0); -- Generic Bunny - PRK
UPDATE `creature_template_difficulty` SET `ContentTuningID`=80, `LootID` = 54631, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=54631 AND `DifficultyID`=0); -- Living Air
UPDATE `creature_template` SET `unit_flags3`=16777216, `AIName`='SmartAI' WHERE `entry`=41200; -- Generic Bunny - PRK
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=524288, `AIName`='SmartAI' WHERE `entry`=54631; -- Living Air

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=106299;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 106299, 0, 0, 31, 0, 3, 41200, 0, '', 0, 0, 0, '', 'Spell \'Summon Living Air\' EFFECT_0 can only hit \'Generic Bunny - PRK\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=109062;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 109062, 0, 0, 31, 0, 3, 41200, 0, '', 0, 0, 0, '', 'Spell \'Summon Lightning\' EFFECT_0 can only hit \'Generic Bunny - PRK\'');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-450483, 54631) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450483, 0, 0, 0, 8, 0, 100, 0, 106299, 0, 0, 0, 0, 85, 102207, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Generic Bunny - On Spellhit - Invoker Cast Summon Living Air'),
-- Living Air
(54631, 0, 1, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, 11, 109062, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Air - Just Spawned - Cast Summon Lightning'),
(54631, 0, 2, 0, 0, 0, 100, 0, 1000, 2000, 4000, 7000, 0, 11, 73212, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Living Air - Update IC - Cast Lightning Bolt'),
(54631, 0, 3, 0, 0, 0, 50, 0, 8000, 12000, 8000, 12000, 0, 11, 108693, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Living Air - Update IC - Cast Lightning Cloud');

DELETE FROM `creature_loot_template` WHERE `Entry`=54631;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(54631, 72112, 0, 100, 1, 1, 0, 1, 1, ''),
(54631, 55983, 0, 29.5787, 0, 1, 0, 1, 1, ''),
(54631, 55973, 0, 59.7762, 0, 1, 0, 1, 1, ''),
(54631, 8182, 0, 0.00625078, 0, 1, 0, 1, 1, ''),
(54631, 8181, 0, 0.00625078, 0, 1, 0, 1, 1, ''),
(54631, 5572, 0, 0.0437555, 0, 1, 0, 1, 1, ''),
(54631, 5571, 0, 0.0437555, 0, 1, 0, 1, 1, ''),
(54631, 4496, 0, 0.106263, 0, 1, 0, 1, 1, ''),
(54631, 805, 0, 0.443805, 0, 1, 0, 1, 1, ''),
(54631, 3189, 0, 0.00625078, 0, 1, 0, 1, 1, ''),
(54631, 828, 0, 0.556319, 0, 1, 0, 1, 1, '');
