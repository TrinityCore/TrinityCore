-- Lockmaw
UPDATE `creature_template` SET `difficulty_entry_1`= 49043, `mechanic_immune_mask`= 667893759, `scriptname`= 'boss_lockmaw' WHERE `entry`= 43614;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `exp`= 3, `mechanic_immune_mask`= 667893759 WHERE `entry`= 49043;
-- Dust Flail Front
UPDATE `creature_template` SET `minlevel`= 80, `maxlevel`= 80, `faction`= 14, `unit_flags`= 33554944, `flags_extra`= 128 WHERE `entry`= 43655;
-- Dust Flail Back
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 14, `unit_flags`= 33554944, `flags_extra`= 128 WHERE `entry`= 43650;
-- Frenzied Crocolisk
UPDATE `creature_template` SET `minlevel`= 84, `maxlevel`= 84, `difficulty_entry_1`= 49311, `flags_extra`= 256, `scriptname`= 'npc_lockmaw_frenzied_crocolisk' WHERE `entry`= 43658;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `flags_extra`= 256 WHERE `entry`= 49311;
-- Augh 1 and 2
UPDATE `creature_template` SET `unit_flags`= 32832, `mechanic_immune_mask`= 667893759, `scriptname`= 'npc_lockmaw_augh' WHERE `entry` IN (45379, 45378);
-- Augh
UPDATE `creature_template` SET `mechanic_immune_mask`= 667893759, `scriptname`= 'boss_augh' WHERE `entry`= 49045;
-- Add Stalker
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 131 WHERE `entry`= 45124;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_lockmaw_paralytic_blow_dart',
'spell_lockmaw_scent_of_blood',
'spell_lockmaw_random_aggro_taunt');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84799, 'spell_lockmaw_paralytic_blow_dart'),
(89989, 'spell_lockmaw_paralytic_blow_dart'),
(81690, 'spell_lockmaw_scent_of_blood'),
(89998, 'spell_lockmaw_scent_of_blood'),
(50230, 'spell_lockmaw_random_aggro_taunt');

DELETE FROM `creature_template_addon` WHERE `entry`= 43650;
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(43650, '81646');

DELETE FROM `creature_text` WHERE `CreatureID`= 49045;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(49045, 0, 0, 'Augh appears from the distance!', 41, 0, 0, 0, 0, 0, 50638, 'Augh - Intro 1'),
(49045, 1, 0, 'GAAAH! How you kill croc?!', 12, 0, 0, 53, 0, 0, 49169, 'Augh - Intro 2'),
(49045, 2, 0, 'Augh smart! Augh already steal treasure while you no looking!', 12, 0, 0, 1, 0, 0, 49170, 'Augh - Intro 3'),
(49045, 3, 0, 'Augh da boss! Oh yeah!', 12, 0, 0, 0, 0, 0, 49171, 'Augh Taunt'),
(49045, 4, 0, 'Augh steal your treasure. Uhn uhn uhnnn!', 12, 0, 0, 0, 0, 0, 49173, 'Augh Taunt'),
(49045, 5, 0, 'Who bad?! Augh bad!! Ugn!', 12, 0, 0, 0, 0, 0, 49172, 'Augh Taunt');
