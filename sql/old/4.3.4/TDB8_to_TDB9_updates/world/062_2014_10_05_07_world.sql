UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(25285,31033);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(25285,31033) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =2528500 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25285, 0, 0, 0, 10, 0, 100, 0, 1, 50, 120000, 300000, 80, 2528500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Harbinger Vurenn - OOC LOS - Run Script'),
(31033, 0, 0, 0, 10, 0, 100, 0, 1, 20, 600000, 900000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Crusader of Virtue - OOC LOS - Say Line'),
(2528500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Harbinger Vurenn - Script - Say Line 0'),
(2528500, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 25301, 0, 0, 0, 0, 0, 0, 'Harbinger Vurenn - Script - Say Line 0 (Counselor Talbot)'),
(2528500, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 25250, 0, 0, 0, 0, 0, 0, 'Harbinger Vurenn - Script - Say Line 2 (General Arlos)'),
(2528500, 9, 3, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Harbinger Vurenn - Script - Say Line 1');

DELETE FROM `creature_text` WHERE `entry` IN(25301,25285,31033);
DELETE FROM `creature_text` WHERE `entry` =25250 AND `groupid`=2;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(25250, 2, 0, 'Your offer will be carefully considered, harbinger.  In the meantime we will make use of your delegation in an advisory role.', 12, 7, 100, 1, 0, 0, 'General Arlos',24790),
(25301, 0, 0, 'Our troops, general, consist mostly of villagers and peasants.  Good men, but not quite rid of the prejudices and superstitions of their upbringing.  They''re not ready to fight alongside our more exotic allies.', 12, 7, 100, 1, 0, 0, 'Counselor Talbot',24789),
(25285, 0, 0, 'Give the word, general.  I will have two regiments at your disposal in a month''s time.', 12, 7, 100, 0, 0, 0, 'Harbinger Vurenn',24787),
(25285, 1, 0, 'Very well, general.  Should you change your mind, my people will be more than willing to provide military assistance.', 12, 7, 100, 0, 0, 0, 'Harbinger Vurenn',24788),
(31033, 0, 0, 'There goes the hero of the Vanguard!', 12, 0, 100, 66, 0, 0, 'Crusader of Virtue',31385),
(31033, 0, 1, '%s cheers at you.', 16, 1, 100, 71, 0, 0, 'Crusader of Virtue',25275),
(31033, 0, 2, 'We couldn''t have done it without you, $g sir:ma''am;.', 12, 0, 100, 66, 0, 0, 'Crusader of Virtue',31384),
(31033, 0, 3, 'You honor us with your presence, $n.', 12, 0, 100, 66, 0, 0, 'Crusader of Virtue',31386),
(31033, 0, 4, 'Thank you, $n. From the bottom of my heart. Thank you.', 12, 0, 100, 66, 0, 0, 'Crusader of Virtue',31388),
(31033, 0, 5, 'Call on me anytime, $n.', 12, 0, 100, 66, 0, 0, 'Crusader of Virtue',31389);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=31033;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 31033, 0, 0, 8, 0, 13157, 0, 0, 0, 0, 0, '', 'Crusader of Virtue - Only run SAI if player is rewarded for quest 13157');
