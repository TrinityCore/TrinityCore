-- 
UPDATE `creature_addon` SET `auras`="44792" WHERE `guid`=100024;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (24883, 24876, 24877, 24875);
UPDATE `creature` SET `MovementType`=0, `spawndist`=0, `position_z`=329.648 WHERE `id`=24883;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (24883);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24883) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24883,0,0,0,1,0,70,0,0,5000,6000,10000,11,44788,0,0,0,0,0,19,24876,20,0,0,0,0,0,"Rodin Lightning Enabler - Ooc - Cast Rodin's Lightning Bolt"),
(24883,0,1,0,1,0,70,0,0,5000,6000,10000,11,44787,0,0,0,0,0,19,24876,20,0,0,0,0,0,"Rodin Lightning Enabler - Ooc - Cast Rodin's Lightning Bolt"),
(24883,0,2,0,1,0,70,0,0,5000,6000,10000,11,44789,0,0,0,0,0,19,24876,20,0,0,0,0,0,"Rodin Lightning Enabler - Ooc - Cast Rodin's Lightning Bolt"),
(24883,0,3,0,1,0,70,0,0,5000,6000,10000,11,44791,0,0,0,0,0,19,24876,20,0,0,0,0,0,"Rodin Lightning Enabler - Ooc - Cast Rodin's Lightning Bolt"),
(24883,0,4,0,1,0,70,0,0,5000,6000,10000,11,44790,0,0,0,0,0,19,24876,20,0,0,0,0,0,"Rodin Lightning Enabler - Ooc - Cast Rodin's Lightning Bolt");

DELETE FROM `creature_text` WHERE `entry` IN (24876, 24875, 24877, 24874) AND `groupid`=1;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(24874, 1, 0, 'From sundered ground the sacrament was stolen. The Shield of Aesirites is lost. Unrest will be eternal.', 12, 0, 100, 0, 0, 0, 'Fengir the Disgraced', 23970),
(24876, 1, 0, 'The Staff of Storm''s Fury pilfered. A curse upon this land! The storms will never cease!', 12, 0, 100, 0, 0, 0, 'Rodin the Reckless', 23971),
(24877, 1, 0, 'The Frozen Heart of Isuldof will consume this land until it is returned. Woe unto those that hold the heart as the curse of frozen blood besets them...', 12, 0, 100, 0, 0, 0, 'Isuldof Iceheart', 23972),
(24875, 1, 0, 'The anguish of ten-thousand years awaits any foolish enough to don the Ancient Armor of the Kvaldir. Beware the mist and fog, mortals; for with them comes your end.', 12, 0, 100, 0, 0, 0, 'Windan of the Kvaldir', 23973);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (187023, 187026, 187022, 187027);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (187023, 187026, 187022, 187027) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24876, 24875, 24877, 24874) AND `source_type`=0 AND id=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(187023, 1, 0, 0, 70, 0, 100, 0, 1, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 24876, 30, 0, 0, 0, 0, 0, 'Relic - On State 1 - Set data'),
(187026, 1, 0, 0, 70, 0, 100, 0, 1, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 24877, 30, 0, 0, 0, 0, 0, 'Relic - On State 1 - Set data'), 
(187022, 1, 0, 0, 70, 0, 100, 0, 1, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 24874, 30, 0, 0, 0, 0, 0, 'Relic - On State 1 - Set data'), 
(187027, 1, 0, 0, 70, 0, 100, 0, 1, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 24875, 30, 0, 0, 0, 0, 0, 'Relic - On State 1 - Set data'),
(24876, 0, 2, 0, 38, 0, 100, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rodin the Reckless - On data set - Say line 2'),
(24877, 0, 2, 0, 38, 0, 100, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Isuldof Iceheart - On data set - Say line 2'),
(24874, 0, 2, 0, 38, 0, 100, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fengir the Disgraced - On data set - Say line 2'),
(24875, 0, 2, 0, 38, 0, 100, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Windan of the Kvaldir - On data set - Say line 2');

UPDATE `creature_template` SET `MovementType`=0 WHERE `entry`=30331; -- fix a DB error not related to the quest
