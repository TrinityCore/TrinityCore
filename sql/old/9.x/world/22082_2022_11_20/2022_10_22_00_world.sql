-- The Golden Skipper
DELETE FROM `gossip_menu_option` WHERE `MenuID`=23225;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(23225, 0, 0, 'Where is the ship now?', 160873, 0, 23227, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `transports` WHERE `guid` IN (32);
INSERT INTO `transports` (`guid`,`entry`,`name`,`phaseUseFlags`,`phaseid`,`phasegroup`,`ScriptName`) VALUES
(32,272677,'Echo Isles and Zuldazar ("Ship (The Golden Skipper)")',0,0,0,'');

-- The Golden Skipper transport SAI
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (272677);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (272677) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(272677,1,0,0,71,0,100,0,59433,0,0,0,0,45,1,1,0,0,0,0,19,141897,100,0,0,0,0,0,0,'The Golden Skipper - On Event 59433 Inform - Set Data 1 (Toranko)'),
(272677,1,1,0,71,0,100,0,59434,0,0,0,0,45,1,0,0,0,0,0,19,141897,100,0,0,0,0,0,0,'The Golden Skipper - On Event 59434 Inform - Set Data 0 (Toranko)'),
(272677,1,2,0,71,0,100,0,59435,0,0,0,0,45,1,1,0,0,0,0,19,142943,100,0,0,0,0,0,0,'The Golden Skipper - On Event 59435 Inform - Set Data 1 (Mith\'aka)'),
(272677,1,3,0,71,0,100,0,59436,0,0,0,0,45,1,0,0,0,0,0,19,142943,100,0,0,0,0,0,0,'The Golden Skipper - On Event 59436 Inform - Set Data 0 (Mith\'aka)');

UPDATE `creature_template` SET `ScriptName`='npc_mithaka' WHERE `entry`=142943;
