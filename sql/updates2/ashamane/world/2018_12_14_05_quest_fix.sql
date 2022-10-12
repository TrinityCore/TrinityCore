UPDATE `creature_template` SET `VehicleId` = '6243' WHERE `entry` = '143096'; 
UPDATE `npc_spellclick_spells` SET `cast_flags` = '1' WHERE `npc_entry` = '143068' AND `spell_id` = '279049'; 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '13' AND `SourceGroup` = '1' AND `SourceEntry` = '279049' AND `SourceId` = '0' AND `ElseGroup` = '0' AND `ConditionTypeOrReference` = '31' AND `ConditionTarget` = '0' AND `ConditionValue1` = '5' AND `ConditionValue2` = '143068' AND `ConditionValue3` = '0'; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES ('13', '1', '279049', '31', '5', '143068'); 

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '18' AND `SourceGroup` = '143068' AND `SourceEntry` = '279049' AND `SourceId` = '0' AND `ElseGroup` = '0' AND `ConditionTypeOrReference` = '9' AND `ConditionTarget` = '0' AND `ConditionValue1` = '49403' AND `ConditionValue2` = '0' AND `ConditionValue3` = '0'; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('18', '143068', '279049', '9', '49403'); 


UPDATE `creature_template` SET `InhabitType` = '3' WHERE `entry` = '142873'; 
UPDATE `creature_template` SET `InhabitType` = '3' WHERE `entry` = '126719'; 

-- Table `creature_template`
UPDATE `creature_template` SET `npcflag` = 16777216 WHERE (entry = 143068);

-- Phase the quest npcs to phase 11659
UPDATE `creature` SET `PhaseId` = 11659 WHERE `id` IN (142873, 142876, 142887, 142890, 142891, 142892, 142894, 142898, 142899, 142902, 142909, 142957, 142959, 144188, 144190);

-- Setup waipoints for the escort
DELETE FROM `script_waypoint` WHERE `entry` = 143096;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(143096, 0, -1772.726, -728.2708, 70.57613, 0, "Riding Macaw"),
(143096, 1, -1774.686, -735.8629, 74.00386, 0, "Riding Macaw"),
(143096, 2, -1817.215, -786.8281, 76.95969, 0, "Riding Macaw"),
(143096, 3, -1895.068, -744.6441, 86.48824, 0, "Riding Macaw"),
(143096, 4, -1898.115, -708.2396, 90.98031, 0, "Riding Macaw"),
(143096, 5, -1809.507, -692.4965, 61.14921, 0, "Riding Macaw"),
(143096, 6, -1796.318, -644.8906, 68.57017, 0, "Riding Macaw"),
(143096, 7, -1841.417, -513.1649, 63.61824, 0, "Riding Macaw"),
(143096, 8, -1813.254, -473.0087, 66.68981, 0, "Riding Macaw"),
(143096, 9, -1776.608, -517.3195, 63.05386, 0, "Riding Macaw"),
(143096, 10, -1725.656, -594.0521, 34.28503, 0, "Riding Macaw"),
(143096, 11, -1714.25, -654.7483, 34.28503, 0, "Riding Macaw"),
(143096, 12, -1726.024, -692.6945, 76.95969, 0, "Riding Macaw"),
(143096, 13, -1762.814, -723.507, 78.96837, 0, "Riding Macaw");

-- Editing the SmartAI script of [Creature] ENTRIES (142873, 142876, 142887, 142890, 142891, 142892, 142894, 142898, 142899, 142902, 142909, 142957, 142959, 144188, 144190)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (142873, 142876, 142887, 142890, 142891, 142892, 142894, 142898, 142899, 142902, 142909, 142957, 142959, 144188, 144190);

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid IN (142873, 142876, 142887, 142890, 142891, 142892, 142894, 142898, 142899, 142902, 142909, 142957, 142959, 144188, 144190));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(142873, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Irontide Cutthroat - On Spellhit \'278992\' - Quest Credit \'\''),
(142876, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Irontide Trickshot - On Spellhit \'278992\' - Quest Credit \'\''),
(142887, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Irontide Ruffian - On Spellhit \'278992\' - Quest Credit \'\''),
(142890, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Vulpera Padfoot - On Spellhit \'278994\' - Quest Credit \'\''),
(142891, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Blacktooth Brute - On Spellhit \'278992\' - Quest Credit \'\''),
(142892, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Blacktooth Knuckleduster - On Spellhit \'278992\' - Quest Credit \'\''),
(142894, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Blacktooth Scrapper - On Spellhit \'278992\' - Quest Credit \'\''),
(142898, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bristleback Horker - On Spellhit \'278992\' - Quest Credit \'\''),
(142899, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cutwater Duelist - On Spellhit \'278992\' - Quest Credit \'\''),
(142902, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cutwater Knife Juggler - On Spellhit \'278992\' - Quest Credit \'\''),
(142909, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ookin Crewman - On Spellhit \'278992\' - Quest Credit \'\''),
(142957, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cutwater Reaver - On Spellhit \'278992\' - Quest Credit \'\''),
(142959, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Brinescale Wavecaller - On Spellhit \'278992\' - Quest Credit \'\''),
(144188, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Brinescale Gladiator - On Spellhit \'278992\' - Quest Credit \'\''),
(144190, 0, 0, 0, 8, 0, 100, 0, 278994, 0, 0, 0, '', 33, 145236, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Vulpera Mixologist - On Spellhit \'278992\' - Quest Credit \'\'');
