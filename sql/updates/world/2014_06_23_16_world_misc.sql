--
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=32236;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=5513;

DELETE FROM `smart_scripts` WHERE `entryorguid` =32236;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(32236, 0, 0, 0, 0,  0, 100, 0, 0, 0, 3000, 5000, 11, 32000, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - IC - Cast Mind Seer'),
(32236, 0, 1, 0, 0,  0, 100, 0, 0, 3000, 5000, 6000, 11, 32026, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - IC - Cast Pain Spike'),
(32236, 0, 3, 4, 8,  0, 100, 0, 5513, 0, 60000, 60000, 11, 4329, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - On Spellhit Orb of Illusion - Cast Drag and Drop: Dark Subjugator Transform'),
(32236, 0, 4, 5,61,  0, 100, 0, 0, 0, 0, 0, 11, 4328, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Linked with Previous Event - Cast Drag and Drop: Summon Aldur''thar Sentry'),
(32236, 0, 5, 6,61,  0, 100, 0, 0, 0, 0, 0, 1, 0, 3000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Linked with Previous Event - Say'),
(32236, 0, 6, 0,61,  0, 100, 0, 0, 0, 0, 0, 33, 32229, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Linked with Previous Event - Kill Credit'),
(32236, 0, 7, 8,52,  0, 100, 0, 0, 32236, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - On Text Over - Say'),
(32236, 0, 8, 0,61,  0, 100, 0, 0, 0, 0, 0, 41, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Linked with Previous Event - Despawn After 10 seconds');

DELETE FROM `creature_text` WHERE `entry` =32236;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(32236, 1, 1, 'You\'ve got it all wrong. I\'m a subjugator!', 12, 0, 100, 0, 0, 0, 'Dark Subjugator', 32636),
(32236, 1, 0, 'It was an accident. I was framed. Don\'t drop me!', 12, 0, 100, 0, 0, 0, 'Dark Subjugator', 32637),
(32236, 0, 2, 'What?!', 12, 0, 100, 0, 0, 0, 'Dark Subjugator', 32630),
(32236, 0, 1, 'Okay, who\'s the joker that threw an orb at me?', 12, 0, 100, 0, 0, 0, 'Dark Subjugator', 32633),
(32236, 0, 0, 'I feel funny all of a sudden. Er?!', 12, 0, 100, 0, 0, 0, 'Dark Subjugator', 32632),
(32236, 1, 2, 'NOOOOOO!', 12, 0, 100, 0, 0, 0, 'Dark Subjugator', 32634);
