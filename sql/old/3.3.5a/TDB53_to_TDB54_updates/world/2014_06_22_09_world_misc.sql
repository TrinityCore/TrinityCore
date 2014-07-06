--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (29368, 29801, 30152);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29368, 29801, 30152, 2936800, 2980100, 3015200);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29368, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Set Phase 1 on Aggro'),
(29368, 0, 1, 0, 4, 1, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving on Aggro'),
(29368, 0, 2, 0, 4, 1, 100, 1, 0, 0, 0, 0, 11, 56326, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast bolt on Aggro'),
(29368, 0, 3, 0, 9, 1, 100, 0, 0, 40, 3400, 4700, 11, 56326, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast bolt'),
(29368, 0, 4, 0, 9, 1, 100, 0, 40, 100, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving when not in bolt Range'),
(29368, 0, 5, 0, 9, 1, 100, 0, 10, 15, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving at 15 Yards'),
(29368, 0, 6, 0, 9, 1, 100, 0, 0, 40, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving when in bolt Range'),
(29368, 0, 7, 0, 3, 1, 100, 0, 0, 15, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Set Phase 2 at 15% Mana'),
(29368, 0, 8, 0, 3, 2, 100, 0, 0, 15, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving at 15% Mana'),
(29368, 0, 9, 0, 3, 2, 100, 0, 30, 100, 100, 100, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Set Phase 1 When Mana is above 30%'),
(29368, 0, 10, 0, 0, 1, 100, 0, 15000, 18000, 29000, 33000, 11, 56322, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Spark Frenzy'),
(29368, 0, 11, 0, 0, 1, 100, 0, 3000, 8000, 23000, 26000, 11, 56319, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Cast Ball Lightning'),
(29368, 0, 12, 13, 8, 0, 100, 0, 56189, 0, 0, 0, 11, 44762, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spellhit - Cast Camera Shake'),
(29368, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 28, 56220, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On link - Remove aura'),
(29368, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On link - Stop emote'),
(29368, 0, 15, 0, 38, 0, 100, 0, 0, 1, 0, 0, 80, 2936800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data - Run script'),
(29368, 0, 16, 0, 25, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Reset - Set fly'),
(29368, 0, 17, 18, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 29801, 20, 0, 0, 0, 0, 0, 'On Death - Set data'),
(29368, 0, 18, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 30152, 20, 0, 0, 0, 0, 0, 'On link - Set data'),
(2936800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Talk'),
(2936800, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 4000, 4000, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Talk'),
(2936800, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 60, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Remove hover'),
(2936800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 61361, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Cast teleport'),
(2936800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 99, 3, 0, 0, 0, 0, 0, 20, 191510, 10, 0, 0, 0, 0, 0, 'Timed - Set gob state'),
(2936800, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 2102, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Set faction'),
(2936800, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Remove flags'),
(29801, 0, 0, 0, 2, 0, 100, 1, 0, 30, 0, 0, 11, 56330, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Iron''s Bane at 30% HP'),
(29801, 0, 1, 2, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 29801, 0, 12984, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'On summoned - Start WP'),
(29801, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On link - Remove npc flags'),
(29801, 0, 3, 4, 58, 0, 100, 0, 0, 0, 0, 0, 66, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On WP end - Set orientation'),
(29801, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2980100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On link - Start script'),
(29801, 0, 5, 6, 38, 0, 100, 0, 1, 1, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data - Despawn'),
(29801, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data - Talk'),
(2980100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 1, 0, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Talk'),
(2980100, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 4000, 4000, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Play emote'),
(2980100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 1770, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Set faction'),
(2980100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 30152, 20, 0, 0, 0, 0, 0, 'Timed - Set data'),
(30152, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 30152, 0, 12984, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'On summoned - Start WP'),
(30152, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On link - Remove npc flags'),
(30152, 0, 2, 0, 58, 0, 100, 0, 0, 0, 0, 0, 66, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On summoned - Set orintation'),
(30152, 0, 3, 0, 38, 0, 100, 0, 0, 1, 0, 0, 80, 3015200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data - Run script'),
(30152, 0, 4, 5, 38, 0, 100, 0, 1, 1, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data - Despawn'),
(30152, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On link - Talk'),
(3015200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Talk'),
(3015200, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 4000, 4000, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Talk'),
(3015200, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Play emote'),
(3015200, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 1770, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timed - Set faction'),
(3015200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 29368, 20, 0, 0, 0, 0, 0, 'Timed - Set data');

DELETE FROM `creature_text` WHERE `entry` IN (29368, 29801, 30152);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(29368, 0, 0, 'How predictable! But then, who would expect a rock to think like anything other than one?', 12, 0, 100, 11, 0, 0, '', 30895),
(29368, 1, 0, 'If you''re so eager to fight, I''ll oblige you. But know that nothing you do here can prevent the completion of the iron colossus!', 12, 0, 100, 274, 0, 0, '', 30896),
(29801, 0, 0, 'At last, the tyranny of the stormforged is at its end!', 12, 0, 100, 25, 0, 0, '', 30891),
(29801, 1, 0, 'We''ve defeated Valduran and we''ll fell his colossus.', 12, 0, 100, 0, 25, 0, '', 33052),
(30152, 0, 0, 'No more will your minions assail the creatures of stone and their allies.', 12, 0, 100, 1, 0, 0, '', 30893),
(30152, 1, 0, 'I am your doom, Valduran!', 12, 0, 100, 15, 0, 0, '', 30894),
(30152, 2, 0, 'Well fought! The day is ours, but the war goes on!', 12, 0, 100, 4, 0, 0, '', 33053);

DELETE FROM `waypoints` WHERE `entry` IN (29801, 30152);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(29801, 1, 7749.77, 77.0172, 1009.29, ''),
(29801, 2, 7729.19, 107.101, 1010.16, ''),
(29801, 3, 7725.79, 106.92, 1010.64, ''),
(30152, 1, 7752.48, 79.0734, 1009.24, ''),
(30152, 2, 7730.57, 108.277, 1010.05, ''),
(30152, 3, 7732.23, 111.521, 1010.64, '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56189;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56189, 0, 0, 31, 0, 3, 29368, 0, 0, 0, 0, '', 'Horn target Valduran');

DELETE FROM `creature_template_addon` WHERE `entry` =29368;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(29368, 0, 0, 0, 1, 382, '56220');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (29801, 30152);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 29801, 0, 0, 23, 0, 4434, 0, 0, 0, 0, 0, '', 'execute sai only if npc in area Nidavelir(4434)'),
(22, 1, 30152, 0, 0, 23, 0, 4434, 0, 0, 0, 0, 0, '', 'execute sai only if npc in area Nidavelir(4434)');

DELETE FROM `event_scripts` WHERE `id`=19576;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`,`z`,`o`) VALUES
(19576, 0, 10, 29801, 300000, 0, 7750.35, 76.9334, 1009.43, 1.69),
(19576, 0, 10, 30152, 300000, 0, 7752.38, 78.3693, 1009.43, 2.71);
