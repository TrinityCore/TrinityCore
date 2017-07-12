UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2097152 WHERE `entry` IN(30829,30830,30831,30698);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(15186,16069,15358,16445,15361) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1518600 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15186, 0, 1, 0, 8, 0, 100, 0, 24984, 0, 0, 0, 80, 1518600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murky - On Spellhit - Run Script'),
(15186, 0, 2, 3, 25, 0, 100, 0, 0, 0, 0, 0, 11, 24983, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murky - On Reset - Cast Baby Murloc Passive'),
(15186, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murky - On Reset - Set Emote State'),
(16069, 0, 1, 0, 8, 0, 100, 0, 24984, 0, 0, 0, 80, 1518600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gurky - On Spellhit - Run Script'),
(16069, 0, 2, 3, 25, 0, 100, 0, 0, 0, 0, 0, 11, 24983, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gurky - On Reset - Cast Baby Murloc Passive'),
(16069, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gurky - On Reset - Set Emote State'),
(15358, 0, 1, 0, 8, 0, 100, 0, 24984, 0, 0, 0, 80, 1518600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lurky - On Spellhit - Run Script'),
(15358, 0, 2, 3, 25, 0, 100, 0, 0, 0, 0, 0, 11, 24983, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lurky - On Reset - Cast Baby Murloc Passive'),
(15358, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lurky - On Reset - Set Emote State'),
(16445, 0, 1, 0, 8, 0, 100, 0, 24984, 0, 0, 0, 80, 1518600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Terky - On Spellhit - Run Script'),
(16445, 0, 2, 3, 25, 0, 100, 0, 0, 0, 0, 0, 11, 24983, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Terky - On Reset - Cast Baby Murloc Passive'),
(16445, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Terky - On Reset - Set Emote State'),
(15361, 0, 1, 0, 8, 0, 100, 0, 24984, 0, 0, 0, 80, 1518600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murki - On Spellhit - Run Script'),
(15361, 0, 2, 3, 25, 0, 100, 0, 0, 0, 0, 0, 11, 24983, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murki - On Reset - Cast Baby Murloc Passive'),
(15361, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murki - On Reset - Set Emote State'),
(1518600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - Script - Set Emote State'),
(1518600, 9, 1, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - Script - Set Emote State');
