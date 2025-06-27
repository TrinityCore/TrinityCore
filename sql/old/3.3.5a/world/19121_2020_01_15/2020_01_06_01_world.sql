-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (19674);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19674) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19674,0,0,0,1,0,100,0,2000,5000,40000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-Prince Haramad - Ooc - Say line");

DELETE FROM `creature_text` WHERE `CreatureID` IN (19674);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(19674,0,0,"I don't give a damn what Shaffar's ethereals have placed over the entrance to the Mana-Tombs. You will work until those wards are removed and the Consortium can move in safely and take what's rightfully ours!", 12, 0, 100, 0, 0, 0, 17224, 'Nexus-Prince Haramad'),
(19674,0,1,"I don't pay you engineers exorbitant amounts of gold so that I can hear the words 'no' or 'can't' exit your wrappings. Bring that barrier down or you'll find yourselves working the energy reclamation line on X-17.", 12, 0, 100, 0, 0, 0, 17225, 'Nexus-Prince Haramad'),
(19674,0,2,"I'm close to the edge, Morphalius. Another screw up and it'll be you running through that portal for Kaftiz's tests.", 12, 0, 100, 0, 0, 0, 17226, 'Nexus-Prince Haramad'); -- Remove this line for cata+
