SET @CGUID := 11003;

UPDATE `spelleffect_dbc` SET `EffectBasePoints`=20 WHERE `EffectSpellId`=70507 AND `EffectIndex`=0;
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry` IN(40142,40143,40144,40145);
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (40081,40470,40471,40472);

DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 40146, 724, 0, 0, 15, 33, 0, 0, 3156.037, 533.2656, 72.97205, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN( 'spell_halion_blazing_aura','spell_halion_combustion_consumption_periodic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75886, 'spell_halion_blazing_aura'),
(75887, 'spell_halion_blazing_aura'),
(74803, 'spell_halion_combustion_consumption_periodic'),
(74629, 'spell_halion_combustion_consumption_periodic');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(75886,75887);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 75886, 0, 0, 31, 0, 3, 40683, 0, 0, 0, 0, '', 'Blazing Aura can only target Living Embers'),
(13, 2, 75887, 0, 0, 31, 0, 3, 40683, 0, 0, 0, 0, '', 'Blazing Aura can only target Living Embers');
