UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=28330;

-- Ghostwing needs spell 59091 in relation to Crusader Olakin Sainrith in phase 64
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 31432 AND `spell_id`= 59091;

INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(31432, 59091, 1, 0);

DELETE FROM `vehicle_template_accessory` WHERE  `entry`=31432 AND `seat_id`=0;

DELETE FROM `creature` WHERE  `guid`=145119;

DELETE FROM `spell_area` WHERE `spell`=58139 AND `area`IN(4588);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(58139, 4588, 13144, 0, 0, 0, 2, 1, 64, 11); -- Blackwatch after Killing two scourge with one skeleton
UPDATE `creature` SET `phaseMask`=65 WHERE  `guid`=123657;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`IN(30631,31432);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(30631,31432) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(31428) AND `source_type`=0 AND `id`>4;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30631, 0, 0, 1, 20, 0, 100, 0, 13144, 0, 0, 0, 12, 31432, 1, 90000, 0, 0, 0, 8, 0, 0, 0, 6588.43, 3278.2, 818.203, 5.044, 'Darkrider Arly - On Quest Reward - Summon Ghostwing'),
(30631, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 31428, 1, 90000, 0, 0, 0, 8, 0, 0, 0, 6648.77, 3217.7, 810.501, 1.55334, 'Darkrider Arly - On Quest Reward - Summon Crusader Olakin Sainrith'),
(31428, 0, 5, 6, 54, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 40598, 42543, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crusader Olakin Sainrith - On Just Summoned - Equip Items'),
(31428, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 44, 64, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crusader Olakin Sainrith - On Just Summoned - Set Ingame Phase 64'),
(31428, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crusader Olakin Sainrith - On Just Summoned - Dismount'),
(31428, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Crusader Olakin Sainrith - On Just Summoned - Say Line 1'),
(31428, 0, 9, 0, 38, 0, 100, 0, 2, 2, 0, 0, 11, 59091, 2, 0, 0, 0, 0, 19, 31432, 0, 0, 0, 0, 0, 0, 'Crusader Olakin Sainrith - On Data Set - Cast Ride Ghostwing'),
(31432, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 44, 64, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostwing - On Just Summoned - Set Ingame Phase 64'),
(31432, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostwing - On Just Summoned - Start WP'),
(31432, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 31432, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostwing - On Just Summoned - Set Active'),
(31432, 0, 3, 4, 40, 0, 100, 0, 1, 31432, 0, 0, 54, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostwing - On Reached WP1 - Pause WP'),
(31432, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 31428, 0, 0, 0, 0, 0, 0, 'Ghostwing - On Reached WP1 - Set Data on Crusader Olakin Sainrith'),
(31432, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostwing - On Reached WP1 - Say Line 0'),
(31432, 0, 6, 7, 40, 0, 100, 0, 2, 31432, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 30631, 0, 0, 0, 0, 0, 0, 'Ghostwing - On Reached WP2 - Say Line 0 on Darkrider Arly'),
(31432, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 31432, 0, 0, 0, 0, 0, 0, 'Ghostwing - On Reached WP2 - Despawn Crusader Olakin Sainrith'),
(31432, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostwing - On Reached WP2 - Despawn ');

DELETE FROM `creature_text` WHERE `entry` IN(30631,31432);
DELETE FROM `creature_text` WHERE `entry` IN(31428) AND `groupid`=1;


INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(30631, 0, 0, 'Damn it, Olakin, get your arse back here! There''s work to be done!', 12, 0, 100, 5, 0, 0, 32195, 'Darkrider Arly to Crusader Olakin Sainrith'),
(31428, 1, 0, 'Look! What''s a frostwyrm doing here? It''s coming straight for us.', 12, 0, 100, 25, 0, 0, 32173, 'Crusader Olakin Sainrith to Player'),
(31432, 0, 0, 'Destroy our raw materials, will you? Well, the master has a special plan in mind for you... ', 12, 0, 100, 460, 0, 0, 32171, 'Ghostwing to Player');

DELETE FROM `waypoints` WHERE `entry`=31432;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(31432, 1, 6644.43, 3222.912, 823.0705, 'Ghostwing'),
(31432, 2, 6690.65, 3177.279, 860.5705, 'Ghostwing');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=59091;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 59091, 0, 0, 31, 0, 3, 31432, 0, 0, 0, 0, '', 'Ride Ghostwing');
