-- Template Updates
-- Brazie the Botanist Vehicle
UPDATE `creature_template` SET `VehicleId`= 1382, `InhabitType`= 9, `unit_class`= 4, `unit_flags2`= 0, `ScriptName`= 'npc_brazie_the_bonatist_vehicle' WHERE `entry`= 49176;
-- Fertilize-o-tron 2000
UPDATE `creature_template` SET `ScriptName`= 'npc_brazie_fertilitize_o_tron_2000', `minlevel`= 20, `maxlevel`= 20, `unit_flags`= 256, `unit_flags2`= 1140852736, `faction`= 2263 WHERE `entry`= 49192;
-- Target npc's
UPDATE `creature_template` SET `ScriptName`= 'npc_brazie_vehicle_notifier' WHERE `entry` IN (49385, 49210, 51098, 49194, 49604);
-- Empty Spot
UPDATE `creature_template` SET `ScriptName`= 'npc_brazie_spot', `BaseAttackTime`= 500, `InhabitType`= 9, `minlevel`= 20, `maxlevel`= 20, `faction`= 2263, `RegenHealth`= 0, `unit_flags2`= 1107361792, `unit_flags`= 256 WHERE `entry`= 49190;
-- Spitter
UPDATE `creature_template` SET `minlevel`= 20, `maxlevel`= 20, `unit_flags`= 256, `unit_flags2`= 1140916224, `RegenHealth`= 0, `BaseAttackTime`= 500, `faction`= 2263 WHERE `entry`= 49200;
-- Zombie
UPDATE `creature_template` SET `minlevel`= 20, `maxlevel`= 20, `unit_flags`= 256, `unit_flags2`= 104859648, `speed_walk`= 0.4, `speed_run`= 0.2857, `faction`= 2102, `RegenHealth`= 0, `DamageModifier`= 3, `BaseVariance`= 0.01, `ScriptName`= 'npc_brazie_zombie' WHERE `entry`= 49209;
-- Spitter Target
UPDATE `creature_template` SET `minlevel`= 20, `maxlevel`= 20, `unit_flags2`= 1140852736, `unit_flags`= 768 WHERE `entry`= 49385;
-- Goal Marker
UPDATE `creature_template` SET `minlevel`= 20, `maxlevel`= 20, `unit_flags2`= 1073743872, `unit_flags`= 256 WHERE `entry`= 49210;
-- Solar Power
UPDATE `creature_template` SET `minlevel`= 20, `maxlevel`= 20, `unit_flags2`= 1140852736, `unit_flags`= 768 WHERE `entry`= 49194;
-- Place it here
UPDATE `creature_template` SET `minlevel`= 20, `maxlevel`= 20, `unit_flags2`= 1140852736, `unit_flags`= 776 WHERE `entry`= 51098;
-- Sunflower
UPDATE `creature_template` SET `minlevel`= 20, `maxlevel`= 20, `unit_flags`= 256, `unit_flags2`= 1174470656, `RegenHealth`= 0, `faction`= 2263 WHERE `entry`= 49193;
-- Ghoul
UPDATE `creature_template` SET `minlevel`= 20, `maxlevel`= 20, `unit_flags`= 256, `unit_flags2`= 104859648, `speed_walk`= 0.8, `speed_run`= 0.2857, `faction`= 2102, `RegenHealth`= 0, `DamageModifier`= 6, `BaseVariance`= 0.01, `ScriptName`= 'npc_brazie_zombie' WHERE `entry`= 49232;
-- Freezya Sack
UPDATE `creature_template` SET `minlevel`= 20, `maxlevel`= 20, `unit_flags2`= 1140852736, `unit_flags`= 768, `BaseAttackTime`= 500 WHERE `entry`= 49604;
-- Freezya
UPDATE `creature_template` SET `minlevel`= 20, `maxlevel`= 20, `unit_flags`= 256, `unit_flags2`= 1140916224, `RegenHealth`= 0, `faction`= 2263, `BaseAttackTime`= 500 WHERE `entry`= 49618;


-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (51098, 49194, 49604);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(51098, '94025'),
(49194, '91707'),
(49604, '92373 92406');


-- Creature Brazie the Botanist 49687 SAI
SET @ENTRY := 49687;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 0, 0, 0, 0, 85, 91683, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts any quest - Invoker: Cast spell 91683 to Action invoker // ");

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (91649, 92276, 91646, 94032, 92435, 92440, 92084) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 2, 91649, 0, 0, 31, 0, 3, 49190, 0, 0, 0, '', 'Plant Spitter - Target Empty Spot'),
(13, 2, 91646, 0, 0, 31, 0, 3, 49190, 0, 0, 0, '', 'Plant Sunflower - Target Empty Spot'),
(13, 2, 92440, 0, 0, 31, 0, 3, 49190, 0, 0, 0, '', 'Plant Freezya - Target Empty Spot'),
(13, 2, 92276, 0, 0, 31, 0, 3, 49176, 0, 0, 0, '', 'Spitter Highlight - Target Brazie the Botanist'),
(13, 2, 94032, 0, 0, 31, 0, 3, 49176, 0, 0, 0, '', 'Sunflower Highlight - Target Brazie the Botanist'),
(13, 1, 92435, 0, 0, 31, 0, 3, 49176, 0, 0, 0, '', 'Create Random Freezya Sack - Target Brazie the Botanist'),
(13, 1, 92084, 0, 0, 31, 0, 3, 49209, 0, 0, 0, '', 'Plague Gas - Target Zombie'),
(13, 1, 92084, 0, 1, 31, 0, 3, 49232, 0, 0, 0, '', 'Plague Gas - Target Ghoul'),
(13, 2, 92084, 0, 0, 31, 0, 3, 49193, 0, 0, 0, '', 'Plague Gas - Target Sunflower'),
(13, 2, 92084, 0, 1, 31, 0, 3, 49200, 0, 0, 0, '', 'Plague Gas - Target Spitter'),
(13, 2, 92084, 0, 2, 31, 0, 3, 49618, 0, 0, 0, '', 'Plague Gas - Target Freezya');

-- Serverside spells
DELETE FROM `spell_dbc` WHERE `Id` IN (91676, 91741);
INSERT INTO `spell_dbc`(`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellInterruptsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `Comment`) VALUES
(91676, 0x29800100, 0x00000420, 0x10484005, 0x10130200, 0x00800080, 0x00060008, 0x00001200, 0, 0x00000008, 0, 0, 1, 30, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Create Empty Spot'),
(91741, 0x29800100, 0x00000420, 0x10484005, 0x10130200, 0x00800080, 0x00060008, 0x00001200, 0, 0x00000008, 0, 0, 1, 30, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Create Random Sun Power');

DELETE FROM `spelleffect_dbc` WHERE `Id` IN (160081, 160082);
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectBasePoints`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`, `Comment`) VALUES
(160081, 28, 0, 49190, 3077, 0, 0, 87, 0, 91676, 0, 'Create Empty Spot'),
(160082, 28, 0, 49194, 3077, 0, 0, 87, 0, 91741, 0, 'Create Random Sun Power');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_brazie_summon_plant',
'spell_brazie_highlight',
'spell_brazie_spit',
'spell_brazie_create_random_seed_sack');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(91649, 'spell_brazie_summon_plant'),
(91646, 'spell_brazie_summon_plant'),
(92440, 'spell_brazie_summon_plant'),
(92276, 'spell_brazie_highlight'),
(94032, 'spell_brazie_highlight'),
(91748, 'spell_brazie_spit'),
(92441, 'spell_brazie_spit'),
(92435, 'spell_brazie_create_random_seed_sack');

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (49194, 49604);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(49194, 91687, 1, 0),
(49604, 92434, 1, 0);

UPDATE `creature_model_info` SET `CombatReach`= 200 WHERE `DisplayId`= 36401;
UPDATE `creature_model_info` SET `CombatReach`= 3, `BoundingRadius`= 1.05 WHERE `DisplayId` IN (36407, 36888, 36890, 36557, 36891, 36889);
UPDATE `creature_model_info` SET `CombatReach`= 1.33, `BoundingRadius`= 0.4655 WHERE `DisplayId`= 37155;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 49176;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(49176, 0, 0, 'You gained Freeza seeds!', 42, 0, 100, 0, 0, 0, 49686, 'Brazie the Botanist to Player'),
(49176, 1, 0, 'You gained Strangler Vine seeds!', 42, 0, 100, 0, 0, 0, 49630, 'Brazie the Botanist to Player'),
(49176, 2, 0, 'Zombies ate your brains!', 41, 0, 100, 0, 0, 14560, 49692, 'Brazie the Botanist');


DELETE FROM `quest_poi` WHERE `QuestID` IN (28744, 28617, 28733, 28747, 28748);
INSERT INTO `quest_poi` (`QuestID`, `id`, `ObjectiveIndex`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `VerifiedBuild`) VALUES
(28744, 2, 32, 0, 24, 0, 0, 0, 26654), -- Ghouls Hate My Grains
(28744, 1, 0, 0, 24, 0, 0, 7, 26654), -- Ghouls Hate My Grains
(28744, 0, -1, 0, 24, 0, 0, 1, 26654), -- Ghouls Hate My Grains
(28617, 2, 32, 0, 24, 0, 0, 0, 26654), -- Flower Power
(28617, 1, 0, 0, 24, 0, 0, 7, 26654), -- Flower Power
(28617, 0, -1, 0, 24, 0, 0, 1, 26654), -- Flower Power
(28733, 2, 32, 0, 24, 0, 0, 0, 26654), -- Basic Botany
(28733, 1, 0, 0, 24, 0, 0, 7, 26654), -- Basic Botany
(28733, 0, -1, 0, 24, 0, 0, 1, 26654), -- Basic Botany
(28747, 2, 32, 0, 24, 0, 0, 0, 26654), -- Someone Setup the Pumpkin Bomb
(28747, 1, 0, 0, 24, 0, 0, 7, 26654), -- Someone Setup the Pumpkin Bomb
(28747, 0, -1, 0, 24, 0, 0, 1, 26654), -- Someone Setup the Pumpkin Bomb
(28748, 2, 32, 0, 24, 0, 0, 0, 26654), -- Lawn of the Dead
(28748, 1, 0, 0, 24, 0, 0, 7, 26654), -- Lawn of the Dead
(28748, 0, -1, 0, 24, 0, 0, 1, 26654); -- Lawn of the Dead

DELETE FROM `quest_poi_points` WHERE `QuestID` IN (28617, 28733);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(28617, 2, 0, -118, 220, 26654), -- Flower Power
(28617, 1, 0, -71, 185, 26654), -- Flower Power
(28617, 0, 0, -118, 220, 26654), -- Flower Power
(28733, 2, 0, -118, 220, 26654), -- Basic Botany
(28733, 1, 0, -79, 189, 26654), -- Basic Botany
(28733, 0, 0, -118, 220, 26654); -- Basic Botany

UPDATE `quest_poi_points` SET `X`=-118, `Y`=220, `VerifiedBuild`=26654 WHERE (`QuestID`=28748 AND `Idx1`=2 AND `Idx2`=0); -- Lawn of the Dead
UPDATE `quest_poi_points` SET `Y`=197, `VerifiedBuild`=26654 WHERE (`QuestID`=28748 AND `Idx1`=1 AND `Idx2`=0); -- Lawn of the Dead
UPDATE `quest_poi_points` SET `VerifiedBuild`=26654 WHERE (`QuestID`=28748 AND `Idx1`=0 AND `Idx2`=0); -- Lawn of the Dead

UPDATE `quest_poi_points` SET `X`=-118, `Y`=220, `VerifiedBuild`=26654 WHERE (`QuestID`=28747 AND `Idx1`=2 AND `Idx2`=0); -- Someone Setup the Pumpkin Bomb
UPDATE `quest_poi_points` SET `X`=-63, `Y`=193, `VerifiedBuild`=26654 WHERE (`QuestID`=28747 AND `Idx1`=1 AND `Idx2`=0); -- Someone Setup the Pumpkin Bomb
UPDATE `quest_poi_points` SET `VerifiedBuild`=26654 WHERE (`QuestID`=28747 AND `Idx1`=0 AND `Idx2`=0); -- Someone Setup the Pumpkin Bomb

UPDATE `quest_poi_points` SET `X`=-118, `Y`=220, `VerifiedBuild`=26654 WHERE (`QuestID`=28744 AND `Idx1`=2 AND `Idx2`=0); -- Ghouls Hate My Grains
UPDATE `quest_poi_points` SET `X`=-87, `Y`=197, `VerifiedBuild`=26654 WHERE (`QuestID`=28744 AND `Idx1`=1 AND `Idx2`=0); -- Ghouls Hate My Grains
UPDATE `quest_poi_points` SET `VerifiedBuild`=26654 WHERE (`QuestID`=28744 AND `Idx1`=0 AND `Idx2`=0); -- Ghouls Hate My Grains
