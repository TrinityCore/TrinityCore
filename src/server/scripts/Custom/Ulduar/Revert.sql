UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 32865;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=62042;

-- Pre adds
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 32885;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 32883;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 32908;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 32907;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 32882;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 32886;

-- Thorim Mini bosses
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 32872;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 32873;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 33196;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (32876, 32904, 32878, 32877, 32874, 32875, 33110);

DELETE FROM `creature_addon` WHERE `guid`IN (136059, 136816);

DELETE FROM `conditions` WHERE `SourceEntry` = 62016 AND `SourceTypeOrReferenceId` = 13;

DELETE FROM `spell_script_names` WHERE `spell_id`=62560;

UPDATE `creature_template` SET `ScriptName` = 'npc_runic_smash' WHERE `entry` = 33140; -- Creature had no ScriptName set

DELETE FROM `spell_dbc` WHERE `Id` IN (64980);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10440, 10457, 10314, 10289) AND `type` IN (18, 11);

DELETE FROM `conditions` WHERE `SourceEntry` = 64098 AND `SourceTypeOrReferenceId` = 13;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10305, 10309) AND `type` IN (18, 11);

DELETE FROM `conditions` WHERE `SourceEntry` = 62466 AND `SourceTypeOrReferenceId` = 13;

-- Properly script his trap bunnies
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (33725, 33054);

-- Thorim Runic Fortification
DELETE FROM `spell_script_names` WHERE `spell_id`=62942;

-- Revert chests
UPDATE `gameobject_template` SET `data1` = 27073 WHERE `entry` = 194312;
UPDATE `gameobject_template` SET `data1` = 27073 WHERE `entry` = 194313;
UPDATE `gameobject_template` SET `data1` = 26956 WHERE `entry` = 194315;
UPDATE `gameobject_template` SET `data1` = 26955 WHERE `entry` = 194314;

DELETE FROM `gameobject_loot_template` WHERE `entry` BETWEEN 196000 AND 196003;

DELETE FROM `creature_text` WHERE `entry` = 32865 AND `groupid` = 20;

-- Mimiron

DELETE FROM `conditions` WHERE `SourceEntry` = 64623 AND `SourceTypeOrReferenceId` = 13;

UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35 WHERE `entry` IN (34149, 34361); -- Frost Bombs

DELETE FROM `achievement_criteria_data` WHERE `ScriptName` = 'TW_achievement_firefighter';

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'TW_spell_rapid_burst';

-- Revert Not-So-Friendly Fire
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`='10405' AND `type`='18'; 
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`='10406' AND `type`='18'; 
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`) VALUES
(10406, 18),
(10405, 18);

-- Revert Set Us Up The Bomb
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10543, 10544, 10545, 10548, 10547, 10546) AND `type` = 11;

-- Revert conqueror of ulduar
DELETE FROM `achievement_criteria_data` WHERE `type` = '11' AND `criteria_id` IN
(10042, 10352,
10342, 10355,
10340, 10353,
10341, 10354,
10598, 10599,
10348, 10357,
10351, 10363,
10439, 10719,
10403, 10404,
10582, 10583,
10347, 10361,
10349, 10362,
10350, 10364
);
 
DELETE FROM `achievement_criteria_data` WHERE `type` = '18' AND `criteria_id` IN
(10042, 10352,
10342, 10355,
10340, 10353,
10341, 10354,
10598, 10599,
10348, 10357,
10351, 10363,
10439, 10719,
10403, 10404,
10582, 10583,
10347, 10361,
10349, 10362,
10350, 10364
);