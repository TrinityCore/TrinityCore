DELETE FROM  `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` IN ( 50036,51518,50087);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(13, 1, 50036, 31, 3, 27641),
(13, 1, 51518, 31, 3, 27641),
(13, 1, 50087, 31, 3, 27641);

DELETE FROM `spelldifficulty_dbc` WHERE `id` = 50044;
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES (50044, 50044, 59213);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=27641;

DELETE FROM `creature_template_addon` WHERE `entry` IN (27641,30905);
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES 
(27641,'50044'),
(30905,'59213');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27639 AND `source_type` = 0 AND `id` = 16;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27640 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27641 AND `source_type` = 0 AND `id` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27639, 0, 16, 0, 1, 0, 100, 0, 1000, 1000, 0, 0, 11, 51518, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ring-Lord Sorceress - Out of Combat - Cast Beam Visual'),
(27640, 0, 2, 0, 1, 0, 100, 0, 1000, 1000, 0, 0, 11, 51518, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ring-Lord Conjurer - Out of combat - Cast Visual'),
(27641, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 50088, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Centrifuge Core - Out of Combat - Cast Energy Link');