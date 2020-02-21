UPDATE `creature_template` SET `DamageModifier`= 120, `BaseVariance`= 0.5, `mechanic_immune_mask`= 650854271, `mingold`= 17000, `maxgold`= 23000 WHERE `entry`= 23574;
UPDATE `creature_template` SET `ScriptName`= 'npc_akilzon_soaring_eagle', `mechanic_immune_mask`= 650854271  WHERE `entry`= 24858;
UPDATE `creature_template` SET `speed_run`= 1.4285, `vehicleId`= 1612, `ScriptName`= 'npc_akilzon_amani_kidnapper', `mechanic_immune_mask`= 650854271, `flags_extra`= 256 WHERE `entry`= 52638;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (44008, 43648, 44007, 43658);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_akilzon_electrical_storm',
'spell_akilzon_teleport_self',
'spell_akilzon_electrical_overloard_graphic_pulse',
'spell_akilzon_electrical_storm_damage',
'spell_akilzon_grab_passenger',
'spell_akilzon_summon_amani_kidnapper');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43648, 'spell_akilzon_electrical_storm'),
(44006, 'spell_akilzon_teleport_self'),
(43658, 'spell_akilzon_electrical_overloard_graphic_pulse'),
(43657, 'spell_akilzon_electrical_storm_damage'),
(97300, 'spell_akilzon_electrical_storm_damage'),
(98869, 'spell_akilzon_grab_passenger'),
(97316, 'spell_akilzon_summon_amani_kidnapper');

DELETE FROM `creature_text` WHERE `CreatureID`= 23574;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(23574, 0, 0, 'I be da predator! You da prey...', 14, 0, 100, 0, 0, 12013, 23235, 'Akil\'zon to Player'),
(23574, 1, 0, 'Feed, me bruddahs!', 14, 0, 100, 0, 0, 12014, 23931, 'Akil\'zon to Akil\'zon'),
(23574, 2, 0, 'An electrical storm appears!', 41, 0, 100, 0, 0, 0, 23603, 'Akil\'zon to Player'),
(23574, 3, 0, 'Stop your cryin\'!', 14, 0, 100, 0, 0, 0, 23233, 'Akil\'zon to Player'),
(23574, 3, 1, 'Ya got nothin\'!', 14, 0, 100, 0, 0, 0, 23234, 'Akil\'zon to Player'),
(23574, 4, 0, 'You can\'t... kill... me spirit!', 14, 0, 100, 0, 0, 12019, 23232, 'Akil\'zon to Player');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (24858, 52638);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`) VALUES
(24858, 2, 1),
(52638, 1, 1);

DELETE FROM `creature` WHERE `guid` IN (291846, 291854, 291855, 291848, 291836, 291849, 291845, 291840, 291843, 291850, 291837, 291851, 291838, 291842, 291853, 291852);
DELETE FROM `creature_addon` WHERE `guid` IN (291846, 291854, 291855, 291848, 291836, 291849, 291845, 291840, 291843, 291850, 291837, 291851, 291838, 291842, 291853, 291852);

DELETE FROM `reference_loot_template` WHERE `Entry`= 34150;
DELETE FROM `creature_loot_template` WHERE `Entry`= 23574;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(23574, 69551, 0, 0, 1, 1, 1, 1),
(23574, 69552, 0, 0, 1, 1, 1, 1),
(23574, 69549, 0, 0, 1, 1, 1, 1),
(23574, 69550, 0, 0, 1, 1, 1, 1),
(23574, 69553, 0, 0, 1, 1, 1, 1);

DELETE FROM `creature_onkill_reward` WHERE `creature_id`= 23574;
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(23574, 395, 7000, 1162, 7, 0, 250, 0);
