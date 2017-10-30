DELETE FROM creature_text WHERE `entry` in(28116,28115);
INSERT INTO creature_text (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(28115, 0, 0, 'You feel a massive jolt of energy as your body binds with that of Soo-holu.', 42, 0, 100, 0, 0, 0, 29003, 'Soo-holu to Player'),
(28116, 0, 0, 'You feel rage rise within you as your body binds with Kartak.', 42, 0, 100, 0, 0, 0, 29005, 'Kartak the Abominable to Player');

UPDATE `creature_template` SET `spell1`=52316, `spell2`=52271, `spell3`=52311, `spell4`=52272, `spell5`=52274, `VehicleId`=257 WHERE  `entry`=28116;
UPDATE `creature_template` SET `spell1`=52331, `spell2`=52358, `spell3`=53032, `spell4`=52321, `spell5`=0, `VehicleId`=257 WHERE  `entry`=28115;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(28115,28116);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(28115,28116) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28115, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Soo-holu <Will of the Titans> - On Just Summoned - Set Passive'),
(28115, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Soo-holu <Will of the Titans> - On Just Summoned - Say'),
(28116, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kartak the Abominable - On Just Summoned - Set Passive'),
(28116, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kartak the Abominable - On Just Summoned - Say');

UPDATE `gameobject` SET `position_x`=5110.322754, `position_y`=5466.666504, `position_z`=-91.836319 WHERE  `guid`=99745;
UPDATE `creature_text` SET `BroadcastTextId`=29247 WHERE  `entry`=29043 AND `groupid`=4 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=29248 WHERE  `entry`=29043 AND `groupid`=5 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=29249 WHERE  `entry`=29043 AND `groupid`=6 AND `id`=0;
