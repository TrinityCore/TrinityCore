--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17998,17999,18000,18002) AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17998,0,1,0,8,0,100,0,31736,0,0,0,12,18340,4,30000,0,0,0,8,0,0,0,-752.349, 5940.811, 18.261, 4.444397,"Umbrafen Steam Pump Credit Marker - On Spellhit 'Ironvine Seeds' - Summon Creature 'Steam Pump Overseer'"),
(17999,0,1,0,8,0,100,0,31736,0,0,0,12,18340,4,30000,0,0,0,8,0,0,0,-227.935, 6307.861, 21.967, 5.719622,"Lagoon Steam Pump Credit Marker - On Spellhit 'Ironvine Seeds' - Summon Creature 'Steam Pump Overseer'"),
(18000,0,1,0,8,0,100,0,31736,0,0,0,12,18340,4,30000,0,0,0,8,0,0,0,579.913, 6342.902, 23.849, 2.159061,"Serpent Steam Pump Credit Marker - On Spellhit 'Ironvine Seeds' - Summon Creature 'Steam Pump Overseer'"),
(18002,0,1,0,8,0,100,0,31736,0,0,0,12,18340,4,30000,0,0,0,8,0,0,0,477.12, 8189.803, 21.985, 0.486592,"Marshlight Steam Pump Credit Marker - On Spellhit 'Ironvine Seeds' - Summon Creature 'Steam Pump Overseer'");

SET @ENTRY := 18340;

UPDATE `creature_template_addon` SET `auras`="6961 33962" WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,21,40,0,0,0,0,0,0,'Steam Pump Overseer - Just summoned - Say text'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,'Steam Pump Overseer - Just summoned - Start attack');

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I will show you not to cross us again!',12,0,100,0,0,0, 'Steam Pump Overseer', 15202),
(@ENTRY,0,1, 'Warlord Kalithresh will hear of this insolence!',12,0,100,0,0,0, 'Steam Pump Overseer', 15201),
(@ENTRY,0,2, 'I''ll make you pay for that!',12,0,100,0,0,0, 'Steam Pump Overseer', 15199);
