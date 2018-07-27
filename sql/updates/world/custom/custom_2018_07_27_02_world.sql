-- Template Updates
-- Runty
UPDATE `creature_template` SET `flags_extra`= 2 WHERE `entry` IN (40015, 40016);
-- Pups
UPDATE `creature_template` SET `ScriptName`= 'npc_beauty_puppy', `DamageModifier`= 12, `BaseVariance`= 0.5 WHERE `entry` IN (40008, 40011, 40013);
UPDATE `creature_template` SET `DamageModifier`= 25, `BaseVariance`= 0.5 WHERE `entry` IN (40009, 40012, 40014);
UPDATE `creature_template` SET `mechanic_immune_mask`= 1 | 512 | 65536 | 131072	 WHERE `entry` IN (0008, 40011, 40013, 40009, 40012, 40014);
-- Spot
UPDATE `creature_template` SET `difficulty_entry_1`= 40012 WHERE `entry`= 40011;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_walk`= 1.6, `speed_run`= 1.28571, `unit_flags`= 32832 WHERE `entry`= 40012;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_beauty_magma_spit');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76031, 'spell_beauty_magma_spit');

-- Creature corrections
-- Runty
UPDATE `creature` SET `MovementType`= 0, `spawndist`= 0 WHERE `guid`= 361807;
-- Buster (4.0.6 nerf: only two of the three pups are available on heroic difficulty)
UPDATE `creature` SET `spawnMask`= 1 WHERE `guid`= 361806;

-- Creature addons
DELETE FROM `creature_addon` WHERE `guid`= 361807;
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(361807, '77783');
