UPDATE `creature_text` SET `Probability` = 25 WHERE `CreatureID` = 7800 AND `GroupID` = 1;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854271, `flags_extra` = 256 WHERE `entry`=7915;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (7800,7915);
UPDATE `creature_template` SET `ScriptName`='boss_mekgineer_thermaplugg', `AIName`='' WHERE entry=7800;
UPDATE `creature_template` SET `ScriptName`='npc_walking_bomb', `AIName`='' WHERE entry=7915;

UPDATE `gameobject_template` SET `ScriptName`='go_button' WHERE `entry` IN (142214,142215,142216,142217,142218,142219);
UPDATE `gameobject_template` SET `ScriptName`='go_gnome_face' WHERE `entry` IN (142211,142210,142209,142208,142213,142212);

-- SPELL Activate Bomb A (11511)
DELETE FROM `spell_target_position` WHERE `ID`=11511;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(11511, 0, 90, -531.14, 670.136, -310.0, 0.0);
