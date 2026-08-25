-- Creature
UPDATE `creature` SET `StringID` = 'ShipFar' WHERE `guid` IN (349114,349250,349240,349239,349206,349142,349132,349115);
UPDATE `creature` SET `StringID` = 'ShipNear' WHERE `guid` IN (349120,349238,349113,349133);
UPDATE `creature` SET `StringID` = 'ShipEnter' WHERE `guid` IN (349119,349122);
UPDATE `creature` SET `StringID` = 'ShipFinish' WHERE `guid` IN (349121);

-- Template Addon
UPDATE `creature_template_addon` SET `visibilityDistanceType`=3 WHERE `entry`=46316; -- 46316 (Gimme Shelter Kill Credit 00)
UPDATE `creature_template_addon` SET `movementAnimKit`=587 WHERE `entry`=40309; -- 40309 (Glittergill Grouper)
UPDATE `creature_template_addon` SET `visibilityDistanceType`=3 WHERE `entry`=39316; -- 39316 (Vashj'ir Rescue Bunny)
UPDATE `creature_template_addon` SET `visibilityDistanceType`=3 WHERE `entry`=39848; -- 39848 (Vashj'ir Waypoint)
UPDATE `creature_template_addon` SET `emote`=473 WHERE `entry`=39663; -- 39663 (Drowning Soldier)

-- Template
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=39848; -- Vashj'ir Waypoint
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=39316; -- Vashj'ir Rescue Bunny
UPDATE `creature_template` SET `RegenHealth` = 0 WHERE `entry`= 39663;

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_vashjir_drowning_soldier' WHERE `entry` = 39663;

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=68453 WHERE (`Entry`=46316 AND `DifficultyID`=0); -- 46316 (Gimme Shelter Kill Credit 00) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100, `VerifiedBuild`=68453 WHERE (`Entry`=40676 AND `DifficultyID`=0); -- 40676 (Drowned Soldier) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=68453 WHERE (`Entry`=39316 AND `DifficultyID`=0); -- 39316 (Vashj'ir Rescue Bunny) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000100, `VerifiedBuild`=68453 WHERE (`Entry`=39886 AND `DifficultyID`=0); -- 39886 (Drowned Soldier) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=68453 WHERE (`Entry`=39848 AND `DifficultyID`=0); -- 39848 (Vashj'ir Waypoint) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000100, `VerifiedBuild`=68453 WHERE (`Entry`=40661 AND `DifficultyID`=0); -- 40661 (Drowned Crewman) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000000, `VerifiedBuild`=68453 WHERE (`Entry`=39663 AND `DifficultyID`=0); -- 39663 (Drowning Soldier) - CanSwim

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceEntry` IN (74151));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(17, 0, 74151, 0, 0, 51, 1, 5, 39663, 0, '', 0, 'Explicit target of the spell (only for spells which take object selected by caster into account) is TYPEID_UNIT, entry is 39663'),
(17, 0, 74151, 0, 0, 1, 1, 74416, 0, 0, '', 1, 'Explicit target of the spell (only for spells which take object selected by caster into account) has not aura of spell 74416, effect EFFECT_0');

-- SpellScriptNames
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_vashjir_low_health';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76143, 'spell_vashjir_low_health');
