-- ------------------------------------- --
-- Collectable critters for daily quests --
-- ------------------------------------- --
 
-- ------+----------------------+-------------+------ --
-- Entry | Name                 | Spells used | Quest --
-- ------+----------------------+-------------+------ --
-- 42548 | Muddy Crawfish       | 79276,79277 | 26226 --
-- 53517 | Squirming Slime Mold | 99325,99328 | 29322 --
-- 53526 | Brightwater Snail    | 99356,99357 | 29333 --
-- 53561 | Stonebull Crayfish   | 99471,99473 | 29349 --
-- ------+----------------------+-------------+------ --
 
DELETE FROM `conditions` WHERE `SourceGroup` IN (42548, 53517, 53526, 53561);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Muddy Crawfish
        (18, 42548, 79276, 0, 0, 8, 0, 26226, 0, 0, 1, 0, 0, '', 'Quest can''t be rewarded for spellclick'),
        (18, 42548, 79276, 0, 0, 9, 0, 26226, 0, 0, 0, 0, 0, '', 'Quest must be active for spellclick'),
        (18, 42548, 79277, 0, 0, 8, 0, 26226, 0, 0, 1, 0, 0, '', 'Quest can''t be rewarded for spellclick'),
        (18, 42548, 79277, 0, 0, 9, 0, 26226, 0, 0, 0, 0, 0, '', 'Quest must be active for spellclick'),
-- Squirming Slime Mold
        (18, 53517, 99325, 0, 0, 8, 0, 29322, 0, 0, 1, 0, 0, '', 'Quest can''t be rewarded for spellclick'),
        (18, 53517, 99325, 0, 0, 9, 0, 29322, 0, 0, 0, 0, 0, '', 'Quest must be active for spellclick'),
        (18, 53517, 99328, 0, 0, 8, 0, 29322, 0, 0, 1, 0, 0, '', 'Quest can''t be rewarded for spellclick'),
        (18, 53517, 99328, 0, 0, 9, 0, 29322, 0, 0, 0, 0, 0, '', 'Quest must be active for spellclick'),
-- Brightwater Snail
        (18, 53526, 99356, 0, 0, 8, 0, 29333, 0, 0, 1, 0, 0, '', 'Quest can''t be rewarded for spellclick'),
        (18, 53526, 99356, 0, 0, 9, 0, 29333, 0, 0, 0, 0, 0, '', 'Quest must be active for spellclick'),
        (18, 53526, 99357, 0, 0, 8, 0, 29333, 0, 0, 1, 0, 0, '', 'Quest can''t be rewarded for spellclick'),
        (18, 53526, 99357, 0, 0, 9, 0, 29333, 0, 0, 0, 0, 0, '', 'Quest must be active for spellclick'),
-- Stonebull Crayfish
        (18, 53561, 99471, 0, 0, 8, 0, 29349, 0, 0, 1, 0, 0, '', 'Quest can''t be rewarded for spellclick'),
        (18, 53561, 99471, 0, 0, 9, 0, 29349, 0, 0, 0, 0, 0, '', 'Quest must be active for spellclick'),
        (18, 53561, 99473, 0, 0, 8, 0, 29349, 0, 0, 1, 0, 0, '', 'Quest can''t be rewarded for spellclick'),
        (18, 53561, 99473, 0, 0, 9, 0, 29349, 0, 0, 0, 0, 0, '', 'Quest must be active for spellclick');
 
-- Add spellclick flag and set SmartAI for scripting
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`AIName`='SmartAI' WHERE `entry` IN (42548, 53517, 53526, 53561);
 
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (42548, 53517, 53526, 53561);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
        (42548, 79276, 1, 0), -- Muddy Crawfish - Crawfish Creole: Create Muddy Crawfish Cover
        (42548, 79277, 2, 0), -- Muddy Crawfish - Crawfish Creole: Create Muddy Crawfish
        (53517, 99325, 1, 0), -- Squirming Slime Mold - Time for Slime: Create Slime Mold Cover
        (53517, 99328, 2, 0), -- Squirming Slime Mold - Time for Slime: Create Slime Mold
        (53526, 99356, 1, 0), -- Brightwater Snail - Escargot A Go-Go: Create Snail Cover
        (53526, 99357, 2, 0), -- Brightwater Snail - Escargot A Go-Go: Create Snail
        (53561, 99471, 1, 0), -- Stonebull Crayfish - Craving Crayfish: Create Stonebull Crayfish Cover
        (53561, 99473, 2, 0); -- Stonebull Crayfish - Craving Crayfish: Create Stonebull Crayfish
 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (42548, 53517, 53526, 53561);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
        (42548, 0, 0, 0, 8, 0, 100, 0, 79276, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muddy Crawfish - On spell hit of Crawfish Creole: Create Muddy Crawfish Cover - Despawn'),
        (53517, 0, 0, 0, 8, 0, 100, 0, 99325, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Squirming Slime Mold - On spell hit of Time for Slime: Create Slime Mold Cover - Despawn'),
        (53526, 0, 0, 0, 8, 0, 100, 0, 99356, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brightwater Snail - On spell hit of Cast Escargot A Go-Go: Create Snail Cover - Despawn'),
        (53561, 0, 0, 0, 8, 0, 100, 0, 99471, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stonebull Crayfish - On spell hit of Craving Crayfish: Create Stonebull Crayfish Cover - Despawn');