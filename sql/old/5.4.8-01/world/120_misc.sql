DELETE FROM `quest_start_scripts` WHERE `id`=28390;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(28390, 0, 15, 95540, 2, 0, 0, 0, 0, 0);
UPDATE `quest_template` SET `StartScript`=28390 WHERE `Id`=28390;

REPLACE INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(1235, 17, 1550, 1599, '');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=42571 AND `spell_id`=94350;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=42608 AND `spell_id`=94350;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=14822;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(14822, 17, 0, 0, '');

REPLACE INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(96543, 5087, 29128, 0, 0, 0, 2, 1, 8, 0);

REPLACE INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES (0, 83086, 7, '', '', 'Shallow grave summon');
REPLACE INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES (0, 101673, 7, '', '', 'Summon trampoline');
REPLACE INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES (0, 98279, 7, '', '', 'Ammani Power');

UPDATE `item_template` SET `spellcooldown_1` = 30000 WHERE `entry` = 31742;

DELETE FROM `spell_bonus_data` WHERE `entry` IN (15438,21142,26168);
INSERT INTO `spell_bonus_data` VALUES
(15438, 0, 0, 0, 0, 'Thorns (item)'),
(21142, 0, 0, 0, 0, 'Immolation (item)'),
(26168, 0, 0, 0, 0, 'Chitinous Spikes (item)');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 45043;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(45043, 45044, 2, 'Shifting Naaru Silver');

REPLACE INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (77764, 96223, 2, 'Stampending Roar (cat) + run speed marker');
REPLACE INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (77761, 96223, 2, 'Stampending Roar (bear) + run speed marker');
REPLACE INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (2983, 96223, 2, 'Sprint + run speed marker');
REPLACE INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (1850, 96223, 2, 'Dash + run speed marker');
REPLACE INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (68992, 96223, 2, 'Darkflight + run speed marker');

REPLACE INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(52417, 59077, 0, 'Carrying Seaforium - Remove');
