UPDATE `smart_scripts` SET `id`=15 WHERE  `entryorguid`=20417 AND `source_type`=0 AND `id`=13 AND `link`=0;
UPDATE `smart_scripts` SET `event_param1`=9, `event_param2`=9 WHERE  `entryorguid`=20417 AND `source_type`=0 AND `id`=4 AND `link`=5;
UPDATE `smart_scripts` SET `action_param1`=9, `action_param2`=9 WHERE  `entryorguid`=18395600 AND `source_type`=9 AND `id`=10 AND `link`=0;
UPDATE `creature_summon_groups` SET `summonTime`=900000 WHERE  `summonerId`=35501;

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(30209,30211,30212);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(30209,30211,30212) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30209, 0, 0, 0, 8, 0, 100, 0, 56275, 0, 0, 0, 33, 30209, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'North Lightning Forge - On Spellhit "Bouldercrags Bomb" - Give Kill Credit'),
(30211, 0, 0, 0, 8, 0, 100, 0, 56275, 0, 0, 0, 33, 30211, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Central Lightning Forge - On Spellhit "Bouldercrags Bomb" - Give Kill Credit'),
(30212, 0, 0, 0, 8, 0, 100, 0, 56275, 0, 0, 0, 33, 30212, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'South Lightning Forge - On Spellhit "Bouldercrags Bomb" - Give Kill Credit');

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN(95645,96491,96864);
