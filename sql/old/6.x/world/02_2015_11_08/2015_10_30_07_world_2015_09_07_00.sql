--
UPDATE `smart_scripts` SET `action_param2`=2 WHERE `entryorguid` IN (2991401) AND `source_type`=9 AND `id`=0;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (30208);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30208) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2991401, 2991400) AND `source_type`=9 AND id>1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2991400,9,2,0,0,0,100,0,0,0,0,0,11,56230,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dead Iron Giant - On Script - Cast 'Create Fireforged Eyes'"),
(2991401,9,2,0,0,0,100,0,0,0,0,0,11,56243,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Iron Giant - On Script - Cast 'Summon Iron Dwarf'"),
(2991401,9,3,0,0,0,100,0,0,0,0,0,11,56243,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Iron Giant - On Script - Cast 'Summon Iron Dwarf'"),
(30208,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0,"Stormforged Ambusher - Just summoned - Start attack");
