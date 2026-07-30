-- Warrior Custom Spell Scripts

-- Remove existing entries for warrior custom spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
    'spell_warr_berserker_rage',
    'spell_warr_dreadnaught',
    'spell_warr_cleave_dmg',
    'spell_warr_whirlwind',
    'spell_warr_whirlwind_dmg',
    'spell_warr_wrecking_throw_damage',
    'spell_warr_shield_wall',
    'spell_warr_rend',
    'spell_warr_defensive_stance',
    'spell_warr_second_wind_proc',
    'spell_warr_second_wind_6pc',
    'spell_warr_second_wind_2pc',
    'spell_warr_indomitable',
    'spell_warr_fervor_of_battle',
    'spell_warr_ravager',
    'spell_warr_ravager_damage_rage_gain',
    'spell_warr_shattering_throw_damage'
);

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(772, 'spell_warr_rend'),
(845, 'spell_warr_cleave_dmg'),
(845, 'spell_warr_fervor_of_battle'),
(871, 'spell_warr_shield_wall'),
(18499, 'spell_warr_berserker_rage'),
(29838, 'spell_warr_second_wind_proc'),
(202147, 'spell_warr_second_wind_6pc'),
(458245, 'spell_warr_second_wind_2pc'),
(156287, 'spell_warr_ravager_damage_rage_gain'),
(190411, 'spell_warr_whirlwind'),
(199658, 'spell_warr_fervor_of_battle'),
(202095, 'spell_warr_indomitable'),
(228920, 'spell_warr_ravager'),
(262150, 'spell_warr_dreadnaught'),
(386208, 'spell_warr_defensive_stance'),
(394352, 'spell_warr_shattering_throw_damage'),
(394354, 'spell_warr_wrecking_throw_damage');

-- Champion's Spear AreaTrigger
DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (25558, 25559) AND `IsCustom` = 0;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(25558, 0, 29927, 0, 0, 0, 0, 0, 0, -1, 0, 0, 376081, 4000, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_warr_champions_spear', 64877),
(25559, 0, 29927, 0, 0, 0, 0, 0, 0, -1, 0, 0, 376081, 4000, 0, 0, 0, 5, 15, 0, 0, 0, 0, 0, 0, 'at_warr_champions_spear', 64877);

-- Remove incorrect/deprecated scripts that are now core handled
-- Rend/Improved whirlwind cleave (394062,394063)
-- Intimidating shout 
-- Sweeping Strikes 12328 no longer exists and core handles the effect
DELETE FROM `spell_script_names` WHERE `spell_id` IN (394062,394063);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_intimidating_shout', 'spell_warr_sweeping_strikes');
