-- Generic NPC phasing fixups
UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 371 WHERE `id` IN (39095, 34863);

-- Generic trigger bunny (multiphase)
UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 372 WHERE `id` IN (35374, 35830, 35010, 35011) AND `map`= 654 AND `areaId`= 4756;

UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 367 WHERE `id` IN (35906);
UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 460 WHERE `id` IN (35229, 35317, 35566);
UPDATE `creature` SET `phaseId`= 172, `phaseGroup`= 0 WHERE `id` IN (35618, 36057);

UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 367 WHERE `id` IN (35906);
UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 460 WHERE `id` IN (35229, 35317, 35566);
UPDATE `creature` SET `phaseId`= 172, `phaseGroup`= 0 WHERE `id` IN (35618, 36057);

DELETE FROM `creature` WHERE `id` IN (35456, 35457);

-- Fix flags for not selectable gameobjects
UPDATE `gameobject_template_addon` SET `flags`= `flags`|16 WHERE `entry` IN (195466, 195465, 195430, 195454, 195453);
-- Put barricades in correct phase
UPDATE `gameobject` SET `phaseId`= 0, `phaseGroup`= 507 WHERE `guid` IN (235561, 235562, 235560, 235559);
-- Corrected trigger phase id's
UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 372 WHERE `id`= 35374 AND `map`= 654;

UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 35374;
-- Turn multiple npc's into civillians to avoid aggro
UPDATE `creature_template` SET `flags_extra`= 2 WHERE `entry` IN (35112, 35115, 47091, 35912, 35873, 32768, 35869, 35874, 38832, 35550, 35618, 51947, 35906, 35753, 44469, 44461, 44463, 44465, 35554, 44455, 35552, 35911, 44470, 44468, 44459, 35551);

-- Remove questgiver entry from rampaging worgens
DELETE FROM `creature_queststarter` WHERE `id`= 34884;

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (34981,35660,35836,34913,34936,34916,34884,34850,35006,34863,35830,39095,35010,34867,44086,34864,44426,35374,34851) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=34981 AND `DifficultyID`=0); -- 34981 (Frightened Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=35660 AND `DifficultyID`=0); -- 35660 (Rampaging Worgen) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=35836 AND `DifficultyID`=0); -- 35836 (Frightened Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100, `StaticFlags3`=0x40000, `VerifiedBuild`=63305 WHERE (`Entry`=34913 AND `DifficultyID`=0); -- 34913 (Prince Liam Greymane) - Sessile, CanSwim, Floating - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=34936 AND `DifficultyID`=0); -- 34936 (Gwen Armstead) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=34916 AND `DifficultyID`=0); -- 34916 (Gilneas City Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=34884 AND `DifficultyID`=0); -- 34884 (Rampaging Worgen) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=34850 AND `DifficultyID`=0); -- 34850 (Prince Liam Greymane) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=63305 WHERE (`Entry`=35006 AND `DifficultyID`=0); -- 35006 (Gilneas Market Evacuation Credit) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100, `VerifiedBuild`=63305 WHERE (`Entry`=34863 AND `DifficultyID`=0); -- 34863 (Lieutenant Walden) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=63305 WHERE (`Entry`=35830 AND `DifficultyID`=0); -- 35830 (Gilneas Evacuation Facing Marker (First)) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=63305 WHERE (`Entry`=39095 AND `DifficultyID`=0); -- 39095 (Slain Guard) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=63305 WHERE (`Entry`=35010 AND `DifficultyID`=0); -- 35010 (Gilneas Evacuation Facing Marker (Near)) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=34867 AND `DifficultyID`=0); -- 34867 (Shadowy Figure) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=44086 AND `DifficultyID`=0); -- 44086 (Panicked Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=63305 WHERE (`Entry`=34864 AND `DifficultyID`=0); -- 34864 (Gilneas City Guard) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=63305 WHERE (`Entry`=44426 AND `DifficultyID`=0); -- 44426 (Frightened Chicken) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=63305 WHERE (`Entry`=35374 AND `DifficultyID`=0); -- 35374 (Generic Trigger LAB - Multiphase) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=34851 AND `DifficultyID`=0); -- 34851 (Panicked Citizen) - CanSwim

-- SpellArea
DELETE FROM `spell_area` WHERE (`spell` = 59073 AND `area` IN (4756, 4755, 4757, 4714)) OR (`spell` = 49416 AND `area` = 4756) OR (`spell` = 68630 AND `area` = 4786);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(59073, 4756, 14078, 14159, 0, 0, 2, 3, 64, 1|2|8|32),
(59073, 4755, 14099, 14159, 0, 0, 2, 3, 2|64, 1|2|8|32),
(59073, 4757, 14099, 14159, 0, 0, 2, 3, 2|64, 1|2|8|32),
(59073, 4714, 14099, 14159, 0, 0, 2, 3, 2|64, 1|2|8|32),
(49416, 4756, 14078, 14099, 0, 0, 2, 3, 64, 1|8|32),
(68630, 4786, 0, 14375, 0, 0, 2, 3, 0, 1|2|8|32);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (34913);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(34913, 0, 0, 'Stand your ground, men!', 14, 0, 100, 0, 0, 19617, 35166, 'Prince Liam Greymane'),
(34913, 0, 1, 'Defeat these foul beasts!', 14, 0, 100, 0, 0, 19618, 35167, 'Prince Liam Greymane'),
(34913, 0, 2, 'Protect the civilians!', 14, 0, 100, 0, 0, 19619, 35168, 'Prince Liam Greymane'),
(34913, 0, 3, 'Push them back!', 14, 0, 100, 0, 0, 19620, 35169, 'Prince Liam Greymane'),
(34913, 0, 4, 'Take heart, men!  We must protect our city!', 14, 0, 100, 0, 0, 19621, 35170, 'Prince Liam Greymane');

-- Creature Prince Liam Greymane 34913 SAI
SET @ENTRY := 34913;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 0, 0, 2000, 2000, 11, 50092, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 2000 and 2000 ms) - Self: Cast spell 50092 on Victim // ");
