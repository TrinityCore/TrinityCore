-- Restore original DBC value, the spell is supposed to be scripted, also that was wrong TriggerSpell
UPDATE `serverside_spell_effect` SET `EffectTriggerSpell` = 0 WHERE `SpellID` = 30576 AND `EffectIndex` = 0;

-- Restore original DBC values
UPDATE `serverside_spell` SET `AttributesEx3` = 0, `MaxAffectedTargets` = 0, `RangeIndex` = 1 WHERE `Id` = 30630;
UPDATE `serverside_spell_effect` SET `Effect` = 28, `ImplicitTarget1` = 18, `EffectRadiusIndex1` = 0, `EffectMiscValue2` = 64 WHERE `SpellID` = 30630 AND `EffectIndex` = 0;

-- Remove linked spell, wrongly linked
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 30658;

-- Magtheridon's Room
UPDATE `creature_template` SET `unit_flags` = 33554944 WHERE `entry` = 17516;

-- Magtheridon
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71429 WHERE `entry` = 17257;

-- Burning Abyssal
UPDATE `creature_template` SET `speed_run` = 0.857143 WHERE `entry` = 17454;

-- Target Trigger
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 0.992063 WHERE `entry` = 17474;

-- Hellfire Warder
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 18829;

-- Manticron Cube
UPDATE `gameobject_template` SET `ScriptName` = '' WHERE `entry` = 181713;

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_magtheridon_quake_initial',
'spell_magtheridon_quake_target_selector',
'spell_magtheridon_debris',
'spell_magtheridon_shadow_grasp_cube');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(30576, 'spell_magtheridon_quake_initial'),
(30572, 'spell_magtheridon_quake_target_selector'),
(30629, 'spell_magtheridon_debris'),
(30420, 'spell_magtheridon_shadow_grasp_cube');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (30572,30629);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,30572,0,0,31,0,3,17474,0,0,0,0,"","Group 0: Spell 'Quake' (Effect 0) targets creature 'Target Trigger'"),
-- Completely guessed, don't know what it targets
(13,1,30629,0,0,31,0,3,17474,0,0,0,0,"","Group 0: Spell 'Debris' (Effect 0) targets creature 'Target Trigger'");
