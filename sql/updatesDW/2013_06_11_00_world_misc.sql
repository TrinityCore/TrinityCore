UPDATE `creature_template` SET `flags_extra` = '128' WHERE `entry` =53832;

UPDATE `creature_template` SET `IconName` = 'Pickup' WHERE `entry` =53796;

DELETE FROM `spell_script_names` WHERE `spell_id` = 100255;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(100255, 'spell_branch_of_nordrassil_summon');

UPDATE `creature_template` SET `AIName` = '' WHERE `entry` =52409;

UPDATE `creature_template` SET `minlevel` = '87', `maxlevel` = '87', `exp` = '3', `faction_A` = '16', `faction_H` = '16', `mindmg` = '9023', `maxdmg` = '10891', `attackpower` = '1000', `dmg_multiplier` = '3.5', `ScriptName` = 'npc_tormented_protector' WHERE `entry` =53825;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 53796;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(53796, 100255, 0, 0);

DELETE FROM `creature_template` WHERE `entry` = 53796;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Mana_mod_extra`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(53796, 0, 0, 0, 0, 0, 38680, 0, 0, 0, 'Branch of Nordrassil', '', 'openhandglow', 0, 1, 1, 0, 0, 35, 35, 16777216, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1, 2000, 2000, 1, 32768, 2048, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 4, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_branch_of_nordrassil', 15595);

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `exp` = '3', `faction_A` = '16', `faction_H` = '16',  `ScriptName` = 'npc_burning_treant', `flags_extra` = '0' WHERE `entry` =53832;

DELETE FROM `creature` WHERE `id` = 53832;

DELETE FROM `creature_text` WHERE `entry` = 53825;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(53825, 0, 0, 'Enough...stop...', 12, 0, 100, 0, 0, 0, 'Phase 1 Stop'),
(53825, 1, 0, 'The fires...torment me no longer. But...I am consumed...', 12, 0, 100, 0, 0, 0, 'Phase 2 Start'),
(53825, 2, 0, 'You...friend of Nordrassil...take what remains of my strength...and fight back the flames...', 12, 0, 100, 0, 0, 0, 'Phase 2 Start'),
(53825, 3, 0, 'May the spirit of the Great Tree shelter you...', 12, 0, 100, 0, 0, 0, 'Phase 2 Start');

UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (53691,52558,52571);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (53691,52558,52571);
