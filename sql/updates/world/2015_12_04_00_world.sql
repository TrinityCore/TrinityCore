--
DELETE FROM `gameobject` WHERE `id`=185295;
DELETE FROM `creature_text` WHERE `entry` IN (21514, 10204);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `TextRange`, `comment`, `BroadcastTextId`) VALUES
(10204, 0, 0, "Misha lets OUT a loud roar AS she rakes her claws AGAINST the gronn's altar.", 16, 0, 100, 0, 0, 0, 0, "Misha", 20261),
(21514, 0, 0, "Who dares defile the altar of Gorgrom the Dragon-Eater?", 14, 0, 100, 0, 0, 0, 0, "Gorgrom the Dragon-Eater", 20262),
(21514, 1, 0, "I will crush it and flay it and eat its meat and crack its bones one by one when I am done.", 14, 0, 100, 0, 0, 0, 0, "Gorgrom the Dragon-Eater", 20264);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (21514, 10204);
DELETE FROM `smart_scripts` WHERE source_type = 0 AND entryorguid IN (21514, 10204);
DELETE FROM `smart_scripts` WHERE source_type = 9 AND entryorguid IN (2151400, 1020400);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21514, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 2151400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgrom the Dragon-Eater - On Just summoned - Action list'),
(2151400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgrom the Dragon-Eater - Action list - Set unit flag'),
(2151400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgrom the Dragon-Eater - Action list  - Say text'),
(2151400, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgrom the Dragon-Eater - Action list - Say text'),
(2151400, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3608.135986, 7183.374023, 139.581833, 2.321033, 'Gorgrom the Dragon-Eater - Action list - Move to pos'),
(2151400, 9, 4, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 11, 35470, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgrom the Dragon-Eater - Action list - Cast explosion'),
(2151400, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 50, 185295, 60, 0, 0, 0, 0, 8, 0, 0, 0, 3608.135986, 7183.374023, 139.581833, 2.321033, 'Gorgrom the Dragon-Eater - Action list - Summon Gorgrom corpse spell focus object'),
(2151400, 9, 6, 0, 0, 0, 100, 0, 400, 400, 0, 0, 11, 58951, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgrom the Dragon-Eater - Action list - cast Permanent Feign Death'),
(2151400, 9, 7, 0, 0, 0, 100, 0, 40000, 40000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgrom the Dragon-Eater - Action list - Despawn'),
(10204, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 1020400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Misha - On Just summoned - Action list'),
(1020400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Misha - Action list - Set unit flag'),
(1020400, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Misha - Action list  - Say text'),
(1020400, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3612.911865, 7193.020508, 139.651291, 5.472856, 'Misha - Action list - Move to pos'),
(1020400, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3612.911865, 7193.020508, 139.651291, 5.472856, 'Misha - Action list - Set Orientation'),
(1020400, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Misha - Action list  - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (39264, 39220);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 39264, 0, 0, 29, 1, 21514, 30, 0, 1, 0, 0, '', "Sablemane's Trap Require Gorgrom the Dragon-Eater not around"),
(17, 0, 39220, 0, 0, 29, 1, 21514, 30, 0, 1, 0, 0, '', "Sablemane's Trap Require Gorgrom the Dragon-Eater not around"),
(17, 0, 39264, 0, 0, 28, 0, 10802, 0, 0, 1, 0, 0, '', "Sablemane's Trap RequireGorgrom the Dragon-Eater not Completed"),
(17, 0, 39220, 0, 0, 28, 0, 10723, 0, 0, 1, 0, 0, '', "Sablemane's Trap RequireGorgrom the Dragon-Eater not Completed");
