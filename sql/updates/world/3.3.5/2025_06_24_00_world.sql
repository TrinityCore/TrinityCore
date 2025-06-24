--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_scourging_crystal_controller' WHERE `ScriptName` = 'spell_q11396_11399_scourging_crystal_controller';
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_q11396_11399_scourging_crystal_controller_dummy','spell_q11396_11399_force_shield_arcane_purple_x3');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 24464 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24464,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourging Crystal - On AI Initialize - Set Reactstate Passive"),
(24464,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourging Crystal - On AI Initialize - Set Corpse Delay"),
(24464,0,2,0,8,0,100,0,43882,0,0,0,0,28,43874,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourging Crystal - On Spellhit 'Scourging Crystal Controller' - Remove Aura 'Scourge Mur'gul Camp: Force Shield Arcane Purple x3'"),
(24464,0,3,0,8,0,100,0,43882,0,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourging Crystal - On Spellhit 'Scourging Crystal Controller' - Remove ImmunePC");

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_sholazar_despawn_fruit_tosser' WHERE `ScriptName` = 'spell_q12634_despawn_fruit_tosser';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_zuldrak_summon_stefan' WHERE `ScriptName` = 'spell_q12661_q12669_q12676_q12677_q12713_summon_stefan';

--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_q12659_ahunaes_knife';

DELETE FROM `smart_scripts` WHERE `entryorguid` = 28465 AND `source_type` = 0 AND `id` IN (4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28600 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28600;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28465,0,4,0,8,0,100,0,52090,0,0,0,0,33,28622,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Heb'Drakkar Striker - On Spellhit 'Ahunae's Knife' - Quest Credit 'Scalps!'"),
(28465,0,5,0,8,0,100,0,52090,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Heb'Drakkar Striker - On Spellhit 'Ahunae's Knife' - Delayed Despawn"),

(28600,0,0,0,8,0,100,0,52090,0,0,0,0,33,28622,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Heb'Drakkar Headhunter - On Spellhit 'Ahunae's Knife' - Quest Credit 'Scalps!'"),
(28600,0,1,0,8,0,100,0,52090,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Heb'Drakkar Headhunter - On Spellhit 'Ahunae's Knife' - Delayed Despawn");

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_zuldrak_quenching_mist' WHERE `ScriptName` = 'spell_q12730_quenching_mist';
