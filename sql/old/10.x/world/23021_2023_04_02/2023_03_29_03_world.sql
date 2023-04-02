-- Creature Template
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `npcflag`=16777216, `speed_run`=1.142857193946838378 WHERE `entry`=43044; -- Unexploded Artillery Shell
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `npcflag`=16777216, `unit_flags3`=16777216 WHERE `entry`=43046; -- Unexploded Artillery Shell Mount
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `npcflag`=16777216, `unit_flags3`=8192, `dynamicflags`=0 WHERE `entry`=43032; -- Slain Cannoneer
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `npcflag`=16777216, `unit_flags3`=8192, `dynamicflags`=0 WHERE `entry`=43048; -- Captain Skullshatter

 -- Slain Cannoneer smart ai
SET @ENTRY := 43032;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 80393, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell 80393 hit - Caster: Talk 0 to invoker');

 -- Unexploded Artillery Shell smart ai
SET @ENTRY := 43044;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 80436, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell 80436 hit - Caster: Talk 0 to invoker');

 -- Captain Skullshatter smart ai
SET @ENTRY := 43048;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 80446, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell 80446 hit - Caster: Talk 0 to invoker');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 18 AND `SourceGroup` = 43048 AND `SourceEntry` = 80446) OR (`SourceTypeOrReferenceId` = 18 AND `SourceGroup` = 43032 AND `SourceEntry` = 80393) OR (`SourceTypeOrReferenceId` = 18 AND `SourceGroup` = 43044 AND `SourceEntry` = 80436);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 43048, 80446, 0, 0, 47, 0, 26245, 8 | 2, 0, 0, 0, 0, '', 'Allow Spellclick if Quest 26245 is in progress | complete'),
(18, 43032, 80393, 0, 0, 47, 0, 26245, 8 | 2, 0, 0, 0, 0, '', 'Allow Spellclick if Quest 26245 is in progress | complete'),
(18, 43044, 80436, 0, 0, 47, 0, 26245, 8 | 2, 0, 0, 0, 0, '', 'Allow Spellclick if Quest 26245 is in progress | complete');

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=43046 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(43046, 43044, 0, 1, 'Unexploded Artillery Shell Mount - Unexploded Artillery Shell', 6, 300000); -- Unexploded Artillery Shell Mount - Unexploded Artillery Shell

DELETE FROM `creature_template_movement` WHERE `CreatureID` IN (43046, 43044);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(43046, 0, 0, 1, 0, 0, 0, NULL),
(43044, 0, 0, 1, 1, 0, 0, NULL);

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (43048, 43032, 43046, 43044);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(43048, 80446, 1, 0),
(43032, 80393, 1, 0),
(43046, 46598, 0, 0),
(43044, 80436, 1, 0);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (43032, 43044, 43048);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(43032, 0, 0, 'The cannoneer\'s hands are black with gunpowder.', 42, 0, 100, 0, 0, 0, 42916, 0, 'Slain Cannoneer to Player'),
(43044, 0, 0, 'The shell\'s markings read: \"STORMWIND ROYAL INDUSTRIES\"', 42, 0, 100, 0, 0, 0, 42942, 0, 'Unexploded Artillery Shell to Player'),
(43048, 0, 0, 'The Captain\'s Log lies nearby.', 42, 0, 100, 0, 0, 0, 42930, 0, 'Captain Skullshatter to Player');

-- Quest POIs
DELETE FROM `quest_poi` WHERE (`QuestID`=26245 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=26245 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=26245 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=26245 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=26245 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(26245, 0, 4, 32, 0, 0, 646, 207, 0, 0, 0, 0, 0, 429240, 0, 48676), -- Gunship Down
(26245, 0, 3, 2, 265267, 43029, 646, 207, 0, 0, 0, 0, 0, 0, 0, 48676), -- Gunship Down
(26245, 0, 2, 1, 265266, 43028, 646, 207, 0, 0, 0, 0, 0, 429083, 0, 48676), -- Gunship Down
(26245, 0, 1, 0, 265265, 43027, 646, 207, 0, 0, 0, 0, 0, 429119, 0, 48676), -- Gunship Down
(26245, 0, 0, -1, 0, 0, 646, 207, 0, 0, 0, 0, 0, 0, 0, 48676); -- Gunship Down

UPDATE `quest_poi` SET `VerifiedBuild`=48676 WHERE (`QuestID`=50601 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42421 AND `BlobIndex`=0 AND `Idx1`=0);
DELETE FROM `quest_poi_points` WHERE (`QuestID`=26245 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=26245 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=26245 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=26245 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26245 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(26245, 4, 0, 996, 521, -49, 48676), -- Gunship Down
(26245, 3, 0, 220, 170, 37, 48676), -- Gunship Down
(26245, 2, 0, 274, 192, 43, 48676), -- Gunship Down
(26245, 1, 0, 288, 322, 0, 48676), -- Gunship Down
(26245, 0, 0, 996, 521, -49, 48676); -- Gunship Down

-- Scaling
UPDATE `gameobject_template` SET `ContentTuningId`=54, `VerifiedBuild`=48676 WHERE `entry`=204274; -- Captain's Log
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (43044,43046,43032,62921,43048,49758,43026));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(43044, 0, 0, 0, 54, 48676),
(43046, 0, 0, 0, 54, 48676),
(43032, 0, 0, 0, 54, 48676),
(62921, 0, 0, 0, 371, 48676),
(43048, 0, 0, 0, 54, 48676),
(49758, 0, 0, 0, 81, 48676),
(43026, 0, 0, 0, 54, 48676);
