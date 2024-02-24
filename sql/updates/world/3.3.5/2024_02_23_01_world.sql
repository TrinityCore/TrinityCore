-- Creature - 33200 - Elwynn Lamb
DELETE FROM `creature_template_addon` WHERE `entry` = 33200;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `auras`) VALUES
(33200, 0, 0, 0, 0, 0, 1, 0, 0, '62703');

UPDATE `creature_model_info` SET `BoundingRadius` = 0.65, `CombatReach` = 0.65 WHERE `DisplayID` = 16205;

-- Creature - 33286 - Elwynn Forest Wolf
UPDATE `creature_template` SET `unit_flags` = 768, `AIName` = '', `ScriptName` = 'npc_elwynn_forest_wolf' WHERE `entry` = 33286;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.85 WHERE `DisplayID` = 28545;

-- Spell - 62701 - Elwynn Forest Wolf
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 62701;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 62701, 0, 0, 31, 0, 3, 33200, 0, 0, 0, 0, '', 'Spell \'Elwynn Forest Wolf\' only targets NPC \'Elwynn Lamb\'');

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_elwynn_forest_wolf';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62701, 'spell_gen_elwynn_forest_wolf');

-- Spell - 62703 - Elwynn Lamb
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_elwynn_lamb';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62703, 'spell_gen_elwynn_lamb');
