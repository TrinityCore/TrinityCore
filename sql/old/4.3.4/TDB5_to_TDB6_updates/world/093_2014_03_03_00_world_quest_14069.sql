-- Good Help is Hard to Find (14069) quest script
DELETE FROM `conditions` WHERE `SourceGroup` = 34830;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 34830, 66306, 0, 7, 9, 0, 14069, 0, 0, 0, 0, 0, '', 'Requires Good Help is Hard to Find quest active for spellclick');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 34830;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(34830, 66306, 1, 0);

DELETE FROM `creature_text` WHERE `entry` = 34830;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34830, 0, 0, 'Don''t tase me, mon!', 12, 0, 100, 0, 0, 0, 'Defiant Troll'),
(34830, 0, 1, 'I report you to HR!', 12, 0, 100, 0, 0, 0, 'Defiant Troll'),
(34830, 0, 2, 'I''m going. I''m going!', 12, 0, 100, 0, 0, 0, 'Defiant Troll'),
(34830, 0, 3, 'Oops, break''s over.', 12, 0, 100, 0, 0, 0, 'Defiant Troll'),
(34830, 0, 4, 'Sorry, mon. It won''t happen again.', 12, 0, 100, 0, 0, 0, 'Defiant Troll'),
(34830, 0, 5, 'What I doin'' wrong? Don''t I get a lunch and two breaks a day, mon?', 12, 0, 100, 0, 0, 0, 'Defiant Troll'),
(34830, 0, 6, 'Work was bettah in da Undermine!', 12, 0, 100, 0, 0, 0, 'Defiant Troll');

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = '' WHERE `entry` = 34830;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34830, 3483000, 3483001, 3483002, 3483003, 3483004);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34830, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 11, 45111, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - on spawn - cast Enrage on self (45111)'),
(34830, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 87, 3483001, 3483002, 3483003, 3483004, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - linked - random actionlist/emote state'),
(3483001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - emote state'),
(3483002, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - emote state'),
(3483003, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - emote state'),
(3483004, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 378, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - emote state'),
(34830, 0, 5, 0, 8, 0, 100, 1, 66306, 0, 0, 0, 80, 3483000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - on spellhit (66306) - run actionlist (3483000)'),
(3483000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 16777216, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - remove npc_spellclick_spells flag'),
(3483000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 45111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - remove Enrage (45111)'),
(3483000, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - set emote state (26)'),
(3483000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 34830, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - give quest credit (34830)'),
(3483000, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - say text 0'),
(3483000, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - set random movement'),
(3483000, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defiant Troll - actionlist - despawn');
