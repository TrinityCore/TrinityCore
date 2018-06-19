DELETE FROM `gameobject_addon` WHERE  `guid` IN (71124,72620,160950,183327,183328,183329,183332,183333,183334);
UPDATE `creature_template` SET `npcflag`='83' WHERE  `entry`=26905;
UPDATE `gameobject` SET `ScriptName`='' WHERE  `guid`=0;
DELETE FROM `creature_text` WHERE `CreatureID`=35229 AND `GroupID`=0 AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(35229, 0, 0, 'Now you will die ...!', 16, 0, 100, 0, 0, 0, 7798, 0, 'Bloodfang Stalker');

DELETE FROM `smart_scripts` WHERE `entryorguid`=203282;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(203282, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, '', 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(203282, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, '', 100, 1, 0, 0, 0, 0, 0, 19, 41410, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(203282, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, '', 45, 1, 1, 0, 0, 0, 0, 19, 41410, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(203282, 1, 3, 4, 8, 0, 100, 0, 42703, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Spell Hit - Despawn'),
(203282, 1, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, '', 50, 186468, 20000, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Spell Hit - Summon ore'),
(203282, 1, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, '', 50, 186466, 20000, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Spell Hit - Summon ore'),
(203282, 1, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, '', 50, 186468, 20000, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Spell Hit - Summon ore'),
(203282, 1, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, '', 50, 186466, 20000, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Spell Hit - Summon ore'),
(203282, 1, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, '', 50, 186468, 20000, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Spell Hit - Summon ore'),
(203282, 1, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 50, 186466, 20000, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'on Spell Hit - Summon ore');

UPDATE `smart_scripts` SET `action_type`='89' WHERE  `entryorguid`=2403500 AND `source_type`=9 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`='89' WHERE  `entryorguid`=2408800 AND `source_type`=9 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`='89' WHERE  `entryorguid`=2408900 AND `source_type`=9 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`='89' WHERE  `entryorguid`=2409000 AND `source_type`=9 AND `id`=1 AND `link`=0;

UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24087 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=23924 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=23922 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24100 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24514 AND `source_type`=0 AND `id`=2 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24381 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24092 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24284 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=27959 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24102 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24098 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24345 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=23921 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=23923 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24093 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24094 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=24290 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='3' WHERE  `entryorguid`=35231 AND `source_type`=0 AND `id`=1 AND `link`=2;

