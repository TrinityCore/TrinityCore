-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (39221) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 39221, 0, 0, 31, 0, 3, 22471, 0, 0, 0, 0, '', 'Spell Death''s Door Fel Cannon (effect 0) will hit the potential target of the spell if target is Death''s Door North Warp-Gate.'),
(13, 1, 39221, 0, 1, 31, 0, 3, 22472, 0, 0, 0, 0, '', 'Spell Death''s Door Fel Cannon (effect 0) will hit the potential target of the spell if target is Death''s Door South Warp-Gate.'),
(13, 1, 39221, 0, 2, 31, 0, 3, 23116, 0, 0, 0, 0, '', 'Spell Death''s Door Fel Cannon (effect 0) will hit the potential target of the spell if target is Warp-Gate Shield');

-- Update creature movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (22443,22471,22472);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(22443,0,0,0,1,0,0,NULL), -- Death's Door Fel Cannon should be rooted
(22471,0,0,1,0,0,0,NULL), -- Death's Door North Warp-Gate trigger should be in the air
(22472,0,0,1,0,0,0,NULL); -- Death's Door South Warp-Gate trigger should be in the air

-- Add Pet spells for Death's Door Fel Cannon
DELETE FROM `creature_template_spell` WHERE `CreatureID`=22443;
INSERT INTO `creature_template_spell` (`CreatureID`,`Index`,`Spell`,`VerifiedBuild`) VALUES
(22443,0,39221,12340),(22443,1,39222,12340);

-- Fix flags and add script for Death's Door Fel Cannon
UPDATE `creature_template` SET `unit_flags`=256, `unit_flags2`=0, `ScriptName` = "npc_deaths_door_fel_cannon" WHERE `entry`=22443;

-- Add script for Death's Door Warp Gates
UPDATE `creature_template` SET `ScriptName` = "npc_deaths_door_warp_gate" WHERE `entry` IN (22471,22472);

-- Unstable Fel-Imp are only spawned during quest
DELETE FROM `creature` WHERE `id`=22474;

-- Add missing quest credit spells
DELETE FROM `spell_dbc` WHERE `Id` IN (39281,39282);
INSERT INTO `spell_dbc` (`Id`,`Attributes`,`CastingTimeIndex`,`ProcChance`,`RangeIndex`,`EquippedItemClass`,`Effect1`,`EffectImplicitTargetA1`,`EffectMiscValue1`,`SpellName`,`SchoolMask`) VALUES
(39281,256,1,101,11,-1,90,25,22503,'Warp-Gate North Kill Bunny Credit',1),
(39282,256,1,101,11,-1,90,25,22504,'Warp-Gate South Kill Bunny Credit',1);

-- Fix flags and aura for Unstable Fel-Imp
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=0, `flags_extra`=64 WHERE `entry`=22474;
UPDATE `creature_template_addon` SET `auras`='39227' WHERE `entry`=22474;
