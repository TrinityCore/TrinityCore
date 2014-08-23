DELETE FROM  `creature_text` WHERE `entry` IN(28092,28033);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(28092, 0, 0, 'Omega Rune deployed.  Activation successful.', 12, 0, 100, 51, 0, 0, 'The Etymidian',33004),
(28033, 0, 0, 'Finally, we have the parts to repair the Spirit of Gnomeregan.', 12, 0, 100, 1, 0, 0, 'Weslex Quickwrench',29878),
(28033, 1, 0, 'Let''s see, just a tweak here and an adjustment there...', 12, 0, 100, 432, 0, 0, 'Weslex Quickwrench',29879),
(28033, 2, 0, 'And there she is, the Spirit of Gnomeregan!', 12, 0, 100, 25, 0, 0, 'Weslex Quickwrench',29880),
(28033, 3, 0, 'You can use her, but I don''t want to hear any complaints about saw blades in your seat. I had to fix ''er with what we could find.', 12, 0, 100, 1, 0, 0, 'Weslex Quickwrench',29881);

DELETE FROM `creature_template_addon` WHERE `entry`=28037;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(28037, 0, 0x10000, 0x1, '51114'); -- 28037 - 51114

DELETE FROM `spell_area` WHERE `spell`=51116 AND `area` =4284;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(51116,4284, 12523, 0, 0, 0, 2, 1, 64, 11);

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(28092,28568,28033,28047,27986);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(28092,28033) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2803300) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28092, 0, 0, 0, 20, 0, 100, 0, 12547, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Etymidian - On Quest Reward (The Activation Rune) - Say'), 
(28033, 0, 0, 0, 20, 0, 100, 0, 12523, 0, 0, 0, 80, 2803300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Weslex Quickwrench - On Quest Reward (Have a Part, Give a Part) - Run script'), 

(2803300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Weslex Quickwrench - Script - Say Line 1'), 
(2803300, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Weslex Quickwrench - Script - Say Line 2'), 
(2803300, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Weslex Quickwrench - Script - Say Line 3'), 
(2803300, 9, 3, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Weslex Quickwrench - Script - Say Line 4');
