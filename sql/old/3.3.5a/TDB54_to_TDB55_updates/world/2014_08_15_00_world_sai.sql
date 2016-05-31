DELETE FROM `creature_text` WHERE `entry`=27683;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(27683, 0, 0, 'I''ve lived here and kept this shrine with the blessing of the Alexstrasza for longer than I can remember.  In its darkest hour, I''ve failed... I fell at the feet of that damned death knight...  Bloodbane.', 12, 0, 100, 0, 0, 0, 'Remnant of Dahlia Suntouch',26939),
(27683, 1, 0, 'Dahlia spits on the ground at the thought of the name.', 16, 0, 100, 0, 0, 0, 'Remnant of Dahlia Suntouch',26943),
(27683, 2, 0, 'The Lich King is stretching his hand far now... fearlessly treading on the most sacred lands of all of the flights.  He intends to force us to action.', 12, 0, 100, 0, 0, 0, 'Remnant of Dahlia Suntouch',26940),
(27683, 3, 0, 'My time is done... I offered myself to Alexstrasza in life, but I have nothing left to offer in death.  She will need a new keeper for her shrine.', 12, 0, 100, 0, 0, 0, 'Remnant of Dahlia Suntouch',26941),
(27683, 4, 0, 'And thank you... thank you for freeing me from the shackles of the damned.  You are a hero... I know you will go on to great deeds.', 12, 0, 100, 0, 0, 0, 'Remnant of Dahlia Suntouch',26942),
(27683, 5, 0, 'The Remnant of Dahlia Suntouch fades away...', 16, 0, 100, 0, 0, 0, 'Remnant of Dahlia Suntouch',26944);

DELETE FROM `waypoints` WHERE `entry` IN(27683);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(27683,1, 3711.944, 938.4294, 55.09203,'Remnant of Dahlia Suntouch'),
(27683,2, 3711.274, 937.6862, 55.09203,'Remnant of Dahlia Suntouch'),
(27683,3, 3722.171, 943.1833, 54.70838,'Remnant of Dahlia Suntouch'),
(27683,4, 3723.844, 944.0275, 53.94967,'Remnant of Dahlia Suntouch'),
(27683,5, 3725.486, 944.8557, 54.00668,'Remnant of Dahlia Suntouch'),
(27683,6, 3729.952, 947.1088, 53.98567,'Remnant of Dahlia Suntouch'),
(27683,7, 3733.333, 948.8146, 53.49077,'Remnant of Dahlia Suntouch'),
(27683,8, 3737.499, 950.9161, 53.46587,'Remnant of Dahlia Suntouch'),
(27683,9, 3737.499, 950.9161, 53.46587,'Remnant of Dahlia Suntouch'),
(27683,10, 3736.349, 956.1506, 53.60175,'Remnant of Dahlia Suntouch');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` =27683;
DELETE FROM `smart_scripts` WHERE `entryorguid` =27683 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =27680 AND `source_type`=0 AND `id`=12;

DELETE FROM `smart_scripts` WHERE `entryorguid` =2768300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27683, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 27683, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remnant of Dahlia Suntouch - On Just Summoned - Start WP'),
(27683, 0, 1, 2, 40, 0, 100, 0, 9, 27683, 0, 0, 54, 25000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remnant of Dahlia Suntouch - On Reached WP9 - Pause WP'),
(27683, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2768300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remnant of Dahlia Suntouch - On Reached WP9 - Run Script'),
(27680, 0, 12, 0, 6, 0, 100, 0, 0, 0, 0, 0, 12, 27683, 1, 60000, 0, 0, 0, 8, 0, 0, 0, 3712.014, 938.0595, 55.06598, 0.4672305, 'Dahlia Suntouch - On Death - Summon Remnant of Dahlia Suntouch'),
(2768300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remnant of Dahlia Suntouch - Script - Say Line 1'),
(2768300, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remnant of Dahlia Suntouch - Script - Say Line 2'),
(2768300, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remnant of Dahlia Suntouch - Script - Say Line 3'),
(2768300, 9, 3, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remnant of Dahlia Suntouch - Script - Say Line 4'),
(2768300, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remnant of Dahlia Suntouch - Script - Say Line 5'),
(2768300, 9, 5, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remnant of Dahlia Suntouch - Script - Say Line 6'),
(2768300, 9, 6, 0, 0, 0, 100, 0, 500, 500, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remnant of Dahlia Suntouch - Despawn - Say Line 6');
