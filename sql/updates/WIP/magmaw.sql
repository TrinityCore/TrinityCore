-- Template Updates
-- Magmaw
UPDATE `creature_template` SET `InhabitType`= 12, `ScriptName`= 'boss_magmaw' WHERE `entry`= 41570;
UPDATE `creature_template` SET `InhabitType`= 12 WHERE `entry` IN (51101, 51102, 51103);
-- Magmaw's Pincer
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (41620, 41789);

-- Vehicle accessories
DELETE FROM `vehicle_template_accessory` WHERE `entry`= 41570;

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 41570;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(41570, 77901, 1, 1);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (89743);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 89743, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Ride Vehicle - Target Magmaw');

-- Delete encounter related ceatures
DELETE FROM `creature` WHERE `guid` IN (250054, 250053, 250052);
DELETE FROM `creature_addon` WHERE `guid` IN (250054, 250053, 250052);
