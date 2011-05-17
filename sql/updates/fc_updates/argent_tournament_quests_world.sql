UPDATE `creature_template` SET `ScriptName`='npc_training_dummy_argent' WHERE `entry`=33229;
UPDATE `creature_template` SET `ScriptName`='npc_training_dummy_argent' WHERE `entry`=33272;
UPDATE `creature_template` SET `ScriptName`='npc_training_dummy_argent' WHERE `entry`=33243;

-- npc_lake_frog
UPDATE `creature_template` SET `ScriptName` = 'npc_lake_frog' WHERE `entry` IN (33211,33224);
UPDATE `creature_template` SET `gossip_menu_id` = 33220 WHERE `entry` = 33220;
REPLACE INTO `gossip_menu_option` (`menu_id`, `option_text`, `option_id`, `npc_option_npcflag`, `action_script_id`) VALUES ('33220', 'Do you know, where I can find Ashwood Brand Sword?', '1', '1', '33220');
REPLACE INTO `gossip_scripts` (`id`, `command`, `datalong`, `datalong2`) VALUES ('33220', '15', '62554', '3');