
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=19380;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19380 AND `source_type`=0;
DELETE FROM `creature_text` WHERE `entry` IN(19380,19383);

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(19383, 0, 0, 'I don''t understand you!', 12, 7, 100, 18, 0, 0, 16540, 'Captured Gnome to Guard Untula'),
(19383, 0, 1, 'Please don''t beat me!', 12, 7, 100, 33, 0, 0, 16541, 'Captured Gnome to Guard Untula'),
(19380, 0, 0, 'Hurry up with that axe, you! I want it sharp enough to cut the wind!', 12, 1, 100, 60, 0, 1040, 16532, 'Guard Untula to 0'),
(19380, 0, 1, 'If you''re no good at fixing, we''ll see if you''re good for eating. Now WORK!', 12, 1, 100, 5, 0, 0, 16538, 'Guard Untula to 0');

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19380, 0, 0, 1, 1, 0, 100, 0, 15000, 45000, 120000, 180000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Guard Untula - OOC - Say Line 0'),
(19380, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 19383, 0, 0, 0, 0, 0,0,'Guard Untula - OOC - Say Line 0 on Captured Gnome');
