-- Template update
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry` IN (42747, 42757); -- Slain Crew Member's Spirit
UPDATE `creature_template` SET `unit_flags3`=8192, `dynamicflags`=0 WHERE `entry` IN (42681, 42682); -- Slain Crew Member
UPDATE `creature_template` SET `speed_run`=1, `unit_flags3`=1 WHERE `entry`=42728; -- Spirit Totem

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (42747, 42757);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(42747, 0, 0, 'Twilight scum!  You did this to us!', 12, 0, 100, 0, 0, 0, 42637, 0, 'Slain Crew Member\'s Spirit to Player'),
(42747, 1, 0, 'They poisoned our supplies... we had cultists onboard all along...', 12, 0, 100, 0, 0, 0, 42633, 0, 'Slain Crew Member\'s Spirit to Player'),
(42747, 1, 1, 'They tricked us into ambushing the Horde gunship... but why?', 12, 0, 100, 0, 0, 0, 42634, 0, 'Slain Crew Member\'s Spirit to Player'),
(42747, 1, 2, 'I heard them praying to their dark gods as everything went black... the Twilight\'s Hammer did this!', 12, 0, 100, 0, 0, 0, 42635, 0, 'Slain Crew Member\'s Spirit to Player'),
(42747, 1, 3, 'Everyone started dropping like flies... everyone who ate the rations.', 12, 0, 100, 0, 0, 0, 42636, 0, 'Slain Crew Member\'s Spirit to Player'),
(42757, 0, 0, 'Twilight scum!  You did this to us!', 12, 0, 100, 0, 0, 0, 42637, 0, 'Slain Crew Member\'s Spirit to Player'),
(42757, 1, 0, 'I heard them praying to their dark gods as everything went black... the Twilight\'s Hammer did this!', 12, 0, 100, 0, 0, 0, 42635, 0, 'Slain Crew Member\'s Spirit to Player'),
(42757, 1, 1, 'They poisoned our supplies... we had cultists onboard all along...', 12, 0, 100, 0, 0, 0, 42633, 0, 'Slain Crew Member\'s Spirit to Player'),
(42757, 1, 2, 'Everyone started dropping like flies... everyone who ate the rations.', 12, 0, 100, 0, 0, 0, 42636, 0, 'Slain Crew Member\'s Spirit to Player');

-- Creature Movement data
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 42728;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(42728, 0, 0, 1, 1, 0, 0, NULL);

-- SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (42682, 42681, 42757, 42747);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (42682, 42681, 42757, 42747) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4268200, 4268100, 4275700, 4275701, 4274700, 4274701) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- Slain Crewmember Female
(42682, 0, 0, 0, 8, 0, 100, 0, 79614, 0, 0, 0, 0, 80, 4268200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnSpellHit 79614 - start Actionlist - to self'),
(4268200, 9, 0, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 11, 49414, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6s - cast "Generic Quest Invisibility 1" - to self'),
(4268200, 9, 1, 0, 0, 0, 100, 0, 40000, 40000, 0, 0, 0, 28, 49414, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 40s - remove Aura "Generic Quest Invisibility 1" - to self'),
-- Slain Crewmember Male
(42681, 0, 0, 0, 8, 0, 100, 0, 79614, 0, 0, 0, 0, 80, 4268100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnSpellHit 79614 - start Actionlist - to self'),
(4268100, 9, 0, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 11, 49414, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6s - cast "Generic Quest Invisibility 1" - to self'),
(4268100, 9, 1, 0, 0, 0, 100, 0, 40000, 40000, 0, 0, 0, 28, 49414, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 40s - remove Aura "Generic Quest Invisibility 1" - to self'),
-- Crewmember Spirit Female
(42757, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 87, 4275700, 4275701, 4275700, 4275700, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnSummon - start random Actionlist - to self'),
(42757, 0, 1, 2, 6, 0, 100, 0, 0, 0, 0, 0, 0, 33, 42758, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'OnDeath - reward Credit 42758 - to Summoner/Owner'),
(42757, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SAI Linked to 1 - despawn creature after 3s - to self'),
(4275700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - set Orientation - to Summoner/Owner'),
(4275700, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Say Text GroupID 1 - to Summoner/Owner'),
(4275700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 42758, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - reward Credit 42758 - to Summoner/Owner'),
(4275700, 9, 3, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 7s - despawn creature - to self'),
(4275701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - set Faction 14 - to self'),
(4275701, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Say Text GroupID 0 - to self'),
(4275701, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Attack start - to Summoner/Owner'),
-- Crewmember Spirit Male
(42747, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 87, 4274700, 4274701, 4274700, 4274700, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnSummon - start random Actionlist - to self'),
(42747, 0, 1, 2, 6, 0, 100, 0, 0, 0, 0, 0, 0, 33, 42758, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'OnDeath - reward Credit 42758 - to Summoner/Owner'),
(42747, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SAI Linked to 1 - despawn creature after 3s - to self'),
(4274700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - set Orientation - to Summoner/Owner'),
(4274700, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Say Text GroupID 1 - to Summoner/Owner'),
(4274700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 42758, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - reward Credit 42758 - to Summoner/Owner'),
(4274700, 9, 3, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 7s - despawn creature - to self'),
(4274701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - set Faction 14 - to self'),
(4274701, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Say Text GroupID 0 - to self'),
(4274701, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Attack start - to Summoner/Owner');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 79614) OR (`SourceTypeOrReferenceId` = 17 AND `SourceGroup` = 0 AND `SourceEntry` = 79614);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 79614, 0, 0, 31, 0, 3, 42682, 0, 0, 0, 0, '', 'Spirit Totem - can only Target Slain Crew Member (42682)'),
(13, 1, 79614, 0, 1, 31, 0, 3, 42681, 0, 0, 0, 0, '', 'Spirit Totem - can only Target Slain Crew Member (42681)'),
(17, 0, 79614, 0, 0, 31, 1, 3, 42682, 0, 0, 0, 0, '', 'Spirit Totem - Explicit Target Slain Crew Member (42682)'),
(17, 0, 79614, 0, 1, 31, 1, 3, 42681, 0, 0, 0, 0, '', 'Spirit Totem - Explicit Target Slain Crew Member (42681)');

-- SpellScripts
DELETE FROM `spell_script_names` WHERE `spell_id` = 79614;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79614, 'spell_spirit_totem');

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (45084,45988,53894,62927,53739,43370,42747,44403,42757,42728,42921,43082,42684,42823,62915,42716,42801,42925,42926,42809,44189,42917,42885,43681,42900,42924,42681,42682));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(45084, 0, 0, 0, 54, 48749),
(45988, 0, 0, 0, 54, 48749),
(53894, 0, 0, 0, 192, 48749),
(62927, 0, 0, 0, 371, 48749),
(53739, 0, 0, 0, 192, 48749),
(43370, 0, 0, 0, 54, 48749),
(42747, 0, 0, 0, 54, 48749),
(44403, 0, 0, 0, 181, 48749),
(42757, 0, 0, 0, 54, 48749),
(42728, 0, 0, 0, 54, 48749),
(42921, 0, 0, 0, 54, 48749),
(43082, 0, 0, 0, 54, 48749),
(42684, 0, 0, 0, 54, 48749),
(42823, 0, 0, 0, 54, 48749),
(62915, 0, 0, 0, 371, 48749),
(42716, 0, 0, 0, 54, 48749),
(42801, 0, 0, 0, 54, 48749),
(42925, 0, 0, 0, 54, 48749),
(42926, 0, 0, 0, 54, 48749),
(42809, 0, 0, 0, 54, 48749),
(44189, 0, 0, 0, 54, 48749),
(42917, 0, 0, 0, 54, 48749),
(42885, 0, 0, 0, 54, 48749),
(43681, 0, 0, 0, 54, 48749),
(42900, 0, 0, 0, 54, 48749),
(42924, 0, 0, 0, 54, 48749),
(42681, 0, 0, 0, 54, 48749),
(42682, 0, 0, 0, 54, 48749);
