UPDATE `creature_template_movement` SET `Ground`= 0, `Flight`= 1, `Rooted`= 1 WHERE `CreatureId` IN (44840, 44798, 44796, 44712);
UPDATE `creature_template` SET `ScriptName`= '', `AIName`= 'NullCreatureAI' WHERE `entry` IN (44840, 44798);
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 44796;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 44798;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(44798, 46598, 1, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`= 44798;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(44798, 44796, 0, 1, 'Tol''Vir Land Mine', 6, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_husam_land_mine_player_search_effect';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83112 , 'spell_husam_land_mine_player_search_effect');

UPDATE `creature_template` SET `ScriptName`= 'npc_husam_bad_intentions_target', `AIName`='' WHERE `entry`= 44586;
DELETE FROM `smart_scripts` WHERE `entryorguid`= 44586 AND `source_type`= 0;

UPDATE `creature_template` SET `ScriptName`= 'npc_husam_shockwave_visual', `AIName`='' WHERE `entry`= 44712;
DELETE FROM `smart_scripts` WHERE `entryorguid`= 44712 AND `source_type`= 0;
UPDATE `creature_template_addon` SET `auras`= '83127' WHERE `entry`= 44712;
