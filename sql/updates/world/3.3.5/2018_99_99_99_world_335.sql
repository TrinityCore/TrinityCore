-- Baron Rivendare (Stratholme) - Set position for each Raise Dead spell (1-6)
DELETE FROM `spell_target_position` WHERE `ID` IN (17475, 17476, 17477, 17478, 17479, 17480);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES 
(17475, 0, 329, 4017.403809, -3339.703369, 115.057655, 5.487860, 0),
(17476, 0, 329, 4013.189209, -3351.808350, 115.052254, 0.134280, 0),
(17477, 0, 329, 4017.738037, -3363.478016, 115.057274, 0.723313, 0),
(17478, 0, 329, 4048.877197, -3363.223633, 115.054253, 3.627735, 0),
(17479, 0, 329, 4051.777588, -3350.893311, 115.055351, 3.066176, 0),
(17480, 0, 329, 4048.375977, -3339.966309, 115.055222, 2.457497, 0);

-- Baron Rivendare (Stratholme) - Add missing emotes
DELETE FROM `creature_text` WHERE `CreatureID` IN (10440);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10440, 0, 0, '%s raises an undead servant back to life!'      , 16, 0, 0, 0, 0, 0, 6511, 0, 'Baron Rivendare (Stratholme) - EMOTE_RAISE_DEAD'),
(10440, 1, 0, '%s attempts to cast Death Pact on his servants!', 16, 0, 0, 0, 0, 0, 6512, 0, 'Baron Rivendare (Stratholme) - EMOTE_DEATH_PACT');

-- Baron Rivendare (Stratholme) - Use skeletons as target
DELETE FROM `conditions` WHERE `SourceEntry` IN (17698, 17471, 17472, 17473);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES 
(13, 1, 17698, 0, 0, 31, 0, 3, 11197, 0, 0, 0, 0, 'Baron Rivendare (Stratholme) - Death Pact (Heal)'),
(13, 1, 17471, 0, 0, 31, 0, 3, 11197, 0, 0, 0, 0, 'Baron Rivendare (Stratholme) - Death Pact (Periodic aura)');

-- Baron Rivendare (Stratholme) - Link heal and damage to visual
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (17698);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES
(17698, 17471, 'Baron Rivendare (Stratholme) - Link to serverside Death Pact');

-- Baron Rivendare (Stratholme) - Skeletons should die after beeing affected by Death Pact
DELETE FROM `creature_template` WHERE entry IN (11197);
INSERT INTO `wow_tc_world`.`creature_template` (`entry`, `modelid1`, `modelid2`, `modelid3`, `name`, `minlevel`, `maxlevel`, `faction`, `speed_walk`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags2`, `type`, `MovementType`, `HealthModifier`, `mechanic_immune_mask`, `ScriptName`, `VerifiedBuild`) VALUES
(11197, 9784, 7550, 7555, 'Mindless Skeleton', 62, 62, 21, 1.25, 2000, 1562, 1, 2048, 6, 1, 0.11, 8388624, 'npc_summoned_skeleton', 12340);
