DELETE FROM `class_expansion_requirement` WHERE `RaceID` IN (52, 70) AND `ClassID`=13;
INSERT INTO `class_expansion_requirement` (`ClassID`, `RaceID`, `ActiveExpansionLevel`, `AccountExpansionLevel`) VALUES 
(13, 52, 9, 9),
(13, 70, 9, 9);

DELETE FROM `playercreateinfo` WHERE `race` IN (52, 70) AND `class`=13;
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `npe_map`, `npe_position_x`, `npe_position_y`, `npe_position_z`, `npe_orientation`, `npe_transport_guid`, `intro_movie_id`, `intro_scene_id`, `npe_intro_scene_id`) VALUES 
(52, 13, 2570, 5827.53, -2982.55, 251.047, 3.86788, NULL, NULL, NULL, NULL, NULL, NULL, 969, NULL, NULL),
(70, 13, 2570, 5827.53, -2982.55, 251.047, 3.86788, NULL, NULL, NULL, NULL, NULL, NULL, 969, NULL, NULL);

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

DELETE FROM `playercreateinfo_cast_spell` WHERE `raceMask`=98304 AND `classMask`=4096 AND `spell` IN (97709, 365560, 369728);
INSERT INTO `playercreateinfo_cast_spell` (`raceMask`, `classMask`, `createMode`, `spell`, `note`) VALUES 
(98304, 4096, 0, 97709, 'Dracthyr - Evoker - Altered Form'),
(98304, 4096, 0, 365560, 'Dracthyr - Evoker - Stasis'),
(98304, 4096, 0, 369728, 'Dracthyr - Evoker - Dracthyr Login');

DELETE FROM `player_racestats` WHERE `race` IN (52, 70);
INSERT INTO `player_racestats` (`race`, `str`, `agi`, `sta`, `inte`) VALUES 
(52, 0, 0, 0, 0),
(70, 0, 0, 0, 0);

DELETE FROM `player_classlevelstats` WHERE `class`=13 AND `level`=1;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES 
(13, 1, 3, 4, 6, 6, 0);

DELETE FROM `quest_template_addon` WHERE `ID`=64864;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(64864, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, '');

DELETE FROM `race_unlock_requirement` WHERE `raceID` IN (52, 70);
INSERT INTO `race_unlock_requirement` (`raceID`, `expansion`, `achievementId`) VALUES 
(52, 9, 0),
(70, 9, 0);

DELETE FROM `scene_template` WHERE `SceneId` IN (2885, 2886, 3064, 2887);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`, `ScriptName`) VALUES
(2885, 17, 3427, 0, ''),
(2886, 25, 3581, 0, ''),
(3064, 25, 3730, 0, 'scene_dracthyr_evoker_intro'),
(2887, 16, 3429, 0, '');

DELETE FROM `spell_script_names` WHERE `spell_id`=369728;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(369728, 'spell_dracthyr_login');
