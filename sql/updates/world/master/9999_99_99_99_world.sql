DELETE FROM `class_expansion_requirement` WHERE `ClassID`=52 AND `RaceID`=13;
INSERT INTO `class_expansion_requirement` (`ClassID`, `RaceID`, `ActiveExpansionLevel`, `AccountExpansionLevel`) VALUES (52, 13, 9, 9);
DELETE FROM `class_expansion_requirement` WHERE `ClassID`=70 AND `RaceID`=13;
INSERT INTO `class_expansion_requirement` (`ClassID`, `RaceID`, `ActiveExpansionLevel`, `AccountExpansionLevel`) VALUES (70, 13, 9, 9);

DELETE FROM `playercreateinfo` WHERE `race`=52 AND `class`=13;
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `npe_map`, `npe_position_x`, `npe_position_y`, `npe_position_z`, `npe_orientation`, `npe_transport_guid`, `intro_movie_id`, `intro_scene_id`, `npe_intro_scene_id`) VALUES (52, 13, 2570, 5827.53, -2982.55, 251.047, 3.86788, NULL, NULL, NULL, NULL, NULL, NULL, 969, NULL, NULL);
DELETE FROM `playercreateinfo` WHERE `race`=70 AND `class`=13;
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `npe_map`, `npe_position_x`, `npe_position_y`, `npe_position_z`, `npe_orientation`, `npe_transport_guid`, `intro_movie_id`, `intro_scene_id`, `npe_intro_scene_id`) VALUES (70, 13, 2570, 5827.53, -2982.55, 251.047, 3.86788, NULL, NULL, NULL, NULL, NULL, NULL, 969, NULL, NULL);

DELETE FROM `playercreateinfo_action` WHERE `race` IN (52, 70) AND `class`=13;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES 
(52, 13, 0, 361469, 0),
(52, 13, 1, 362969, 0),
(52, 13, 2, 357214, 0),
(52, 13, 3, 368970, 0),
(52, 13, 10, 358733, 0),
(70, 13, 0, 361469, 0),
(70, 13, 1, 362969, 0),
(70, 13, 2, 357214, 0),
(70, 13, 3, 368970, 0),
(70, 13, 10, 358733, 0);

DELETE FROM `playercreateinfo_cast_spell` WHERE `raceMask`=98304 AND `classMask`=4096 AND `createMode`=0 AND `spell`=97709;
INSERT INTO `playercreateinfo_cast_spell` (`raceMask`, `classMask`, `createMode`, `spell`, `note`) VALUES (98304, 4096, 0, 97709, 'Dracthyr - Evoker - Altered Form');
DELETE FROM `playercreateinfo_cast_spell` WHERE `raceMask`=98304 AND `classMask`=4096 AND `createMode`=0 AND `spell`=365560;
INSERT INTO `playercreateinfo_cast_spell` (`raceMask`, `classMask`, `createMode`, `spell`, `note`) VALUES (98304, 4096, 0, 365560, 'Dracthyr - Evoker - Stasis');
DELETE FROM `playercreateinfo_cast_spell` WHERE `raceMask`=98304 AND `classMask`=4096 AND `createMode`=0 AND `spell`=369728;
INSERT INTO `playercreateinfo_cast_spell` (`raceMask`, `classMask`, `createMode`, `spell`, `note`) VALUES (98304, 4096, 0, 369728, 'Dracthyr - Evoker - Dracthyr Login');

DELETE FROM `player_racestats` WHERE `race`=52;
INSERT INTO `player_racestats` (`race`, `str`, `agi`, `sta`, `inte`) VALUES (52, 0, 0, 0, 0);
DELETE FROM `player_racestats` WHERE `race`=70;
INSERT INTO `player_racestats` (`race`, `str`, `agi`, `sta`, `inte`) VALUES (70, 0, 0, 0, 0);

DELETE FROM `race_unlock_requirement` WHERE `raceID`=52;
INSERT INTO `race_unlock_requirement` (`raceID`, `expansion`, `achievementId`) VALUES (52, 9, 0);
DELETE FROM `race_unlock_requirement` WHERE `raceID`=70;
INSERT INTO `race_unlock_requirement` (`raceID`, `expansion`, `achievementId`) VALUES (70, 9, 0);

DELETE FROM `scene_template` WHERE `SceneId` IN (2885, 2886, 3064, 2887);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`, `ScriptName`) VALUES
(2885, 17, 3427, 0, ''),
(2886, 25, 3581, 0, ''),
(3064, 25, 3730, 0, 'scene_dracthyr_evoker_intro'),
(2887, 16, 3429, 0, '');

DELETE FROM `spell_script_names` WHERE `spell_id`=369728 AND `ScriptName`='spell_dracthyr_login';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (369728, 'spell_dracthyr_login');
