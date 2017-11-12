INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES (99914, 1); 
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionText`, `OptionType`, `OptionNpcflag`) VALUES (99914, 1, 'We will not forget your sacrifice', 1, 1); 

UPDATE `gameobject_template` SET `ScriptName` = 'go_mardum_portal_coilskar' WHERE entry = 241756; 

UPDATE `creature_template` SET `lootid` = '95226' WHERE `entry` = '95226'; 
UPDATE `creature_template` SET `ScriptName` = 'npc_mardum_inquisitor_pernissius' WHERE (entry = 93105);

DELETE FROM creature WHERE id = 96159;
INSERT INTO spell_script_names VALUES (192709, "spell_mardum_infernal_smash");

UPDATE `scene_template` SET `Flags` = '16' WHERE `SceneId` = '1061';
