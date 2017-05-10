UPDATE `creature_template` SET `AIName`='SmartAI',`InhabitType`=4,`VehicleId`=113 WHERE  `entry`=32292;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(32236,32292) AND `source_type`=0 ;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(3229200) AND `source_type`=9 ;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(32292, 0, 0, 1, 54,  0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Aldur''thar Sentry - On Just Summoned - Store target'),
(32292, 0, 1, 0, 61,  0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 32236, 0, 0, 0, 0, 0, 0, 'Aldur''thar Sentry - On Just Summoned - Move to Target'),
(32292, 0, 2, 0, 1,  0, 100, 1, 1500, 1500, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 32236, 0, 0, 0, 0, 0, 0, 'Aldur''thar Sentry - OOC - Set Data on target'),
(32292, 0, 3, 0, 8,  0, 100, 1, 46598, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, 'Aldur''thar Sentry - On Spellhit - Move to Target'),
(32292, 0, 4, 0, 75,  0, 100, 1, 0, 23837, 2, 15000, 80, 3229200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aldur''thar Sentry - On Creature in Range - Run Script'),
(32236, 0, 0, 0, 0,  0, 100, 0, 0, 0, 3000, 5000, 11, 32000, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - IC - Cast Mind Seer'),
(32236, 0, 1, 0, 0,  0, 100, 0, 0, 3000, 5000, 6000, 11, 32026, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - IC - Cast Pain Spike'),
(32236, 0, 2, 3, 8,  0, 100, 0, 5513, 0, 60000, 60000, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - On Spellhit Orb of Illusion - Store Targetlist'),
(32236, 0, 3, 4,61,  0, 100, 0, 0, 0, 0, 0, 11, 4329, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - On Spellhit Orb of Illusion - Cast Drag and Drop: Dark Subjugator Transform'),
(32236, 0, 4, 5,61,  0, 100, 0, 0, 0, 0, 0, 4, 15131, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Linked with Previous Event - Play Sound'),
(32236, 0, 5, 6,61,  0, 100, 0, 0, 0, 0, 0, 89, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Linked with Previous Event - Turn random movement off'),
(32236, 0, 6, 7,61,  0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Linked with Previous Event - Set immune'),
(32236, 0, 7, 8,61,  0, 100, 0, 0, 0, 0, 0, 11, 4328, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Linked with Previous Event - Cast Drag and Drop: Summon Aldur''thar Sentry'),
(32236, 0, 8, 9,61,  0, 100, 0, 0, 0, 0, 0, 1, 0, 3000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - On Spellhit - Say'),
(32236, 0, 9, 10,61,  0, 100, 0, 0, 0, 0, 0, 33, 32229, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Linked with Previous Event - Kill Credit'),
(32236, 0, 10, 0,61,  0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - Linked with Previous Event - Evade'),
(32236, 0, 11, 0,8,  0, 100, 0, 46598, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - On Spellhit - Say'),
(32236, 0, 12, 13,38,  0, 100, 0, 2, 2, 0, 0, 4, 15128, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - On Data Set - Play Sound'),
(32236, 0, 13, 0,61,  0, 100, 0, 2, 2, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - On Data Set - Despawn After 5 seconds'),
(32236, 0, 14, 0,38,  0, 100, 0, 1, 1, 0, 0, 11, 46598, 0, 0, 0, 0, 0, 19, 32292, 0, 0, 0, 0, 0, 0, 'Dark Subjugator - On Data Set - Cast Ride Vehicle Hardcoded'),
(3229200, 9, 0, 0, 0,  0, 100, 0, 0, 0, 0, 0, 46, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aldur''thar Sentry - Script - Move forward'),
(3229200, 9, 1, 0, 0,  0, 100, 0, 2000, 2000, 0, 0, 11, 50630, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aldur''thar Sentry - On reached WP2 - Cast Eject All Passengers'),
(3229200, 9, 2, 0, 0,  0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 32236, 0, 0, 0, 0, 0, 0, 'Aldur''thar Sentry - On reached WP2 - Set Data'),
(3229200, 9, 3, 0, 0,  0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aldur''thar Sentry - On reached WP2 - Despawn After 5 seconds');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 32292;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(32292, 46598, 1, 0);
