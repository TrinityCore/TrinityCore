--
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 24177;
UPDATE `creature` SET `spawntimesecs` = 2 WHERE `id` = 24177;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24177 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2417700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24177,0,0,0,37,0,100,0,0,0,0,0,0,116,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Decomposing Ghoul - On AI Initialize - Set Corpse Delay"),
(24177,0,1,0,63,0,100,0,0,0,0,0,0,11,20480,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Decomposing Ghoul - On Just Created - Cast 'Birth'"),
(24177,0,2,0,4,0,2,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Decomposing Ghoul - On Aggro - Say Line 0"),
-- They should be scripted in C++ because with SAI we can't move them to random position and we can't load random movement in combat
-- Actually it doesn't look like random position
(24177,0,3,0,8,0,100,1,43203,0,0,0,0,80,2417700,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Decomposing Ghoul - On Spellhit 'Shining Light' - Run Script (No Repeat)"),

(2417700,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Decomposing Ghoul - On Script - Set Reactstate Passive"),
(2417700,9,1,0,0,0,2,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Decomposing Ghoul - On Script - Say Line 1"),
-- No idea when exactly they can cast it
(2417700,9,2,0,0,0,100,0,4000,10000,0,0,0,11,43201,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Decomposing Ghoul - On Script - Cast 'Decompose'");

DELETE FROM `creature_text` WHERE `CreatureID` = 24177;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24177,0,0,"BRAINNNS!",12,0,100,0,0,0,22892,0,"Decomposing Ghoul"),
(24177,0,1,"So... Hungry...",12,0,100,0,0,0,22893,0,"Decomposing Ghoul"),
(24177,0,2,"FEED ME...",12,0,100,0,0,0,22894,0,"Decomposing Ghoul"),
(24177,0,3,"FOOD! EAT YOU!",12,0,100,0,0,0,22895,0,"Decomposing Ghoul"),
(24177,0,4,"Closer... come closer...",12,0,100,0,0,0,22896,0,"Decomposing Ghoul"),
(24177,1,0,"BURNS! IT BURNS!",12,0,100,0,0,0,22898,0,"Decomposing Ghoul"),
(24177,1,1,"ARGHHHH...",12,0,100,0,0,0,22899,0,"Decomposing Ghoul"),
(24177,1,2,"Light... light so bright...",12,0,100,0,0,0,22900,0,"Decomposing Ghoul"),
(24177,1,3,"Bad light... hurt...",12,0,100,0,0,0,22901,0,"Decomposing Ghoul"),
(24177,1,4,"Away... go...",12,0,100,0,0,0,22902,0,"Decomposing Ghoul");

UPDATE `smart_scripts` SET `action_type` = 11, `action_param2` = 2, `comment` = "Ares the Oathbound - On Quest 'The Shining Light' Taken - Cast 'Shining Light'" WHERE `entryorguid` = 24189 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param2` = 2, `comment` = "Ares the Oathbound - On Quest 'Guided by Honor' Taken - Cast 'Guided by the Oathbound QC'" WHERE `entryorguid` = 24189 AND `source_type` = 0 AND `id` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24189 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24189,0,2,0,20,0,100,0,11288,0,0,0,0,28,43202,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Ares the Oathbound - On Quest 'The Shining Light' Finished - Remove Aura 'Shining Light'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 43203;
