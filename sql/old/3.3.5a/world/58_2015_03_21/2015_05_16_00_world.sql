UPDATE `creature_text` SET `emote`=25 WHERE  `entry`=21797 AND `groupid`=0 AND `id`=0;
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128 WHERE  `entry`=21876;
UPDATE `creature_template` SET  `flags_extra`=128 WHERE  `entry`=21872;

UPDATE `creature_template` SET `spell1`=37729, `spell2`=37727, `spell3`=39658, `spell4`=37728 WHERE  `entry`=21867;

DELETE FROM `creature_text` WHERE `entry`in(21877,21872,21867);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(21877, 0, 0, 'Your pathetic attempt to escape will be short lived, Gorefiend. Let the $g boy:girl, go and submit! Even with your armor and weapons, you cannot defeat the ancients!', 12, 0, 100, 1, 0, 0, 19504, 0, 'Karsius the Ancient Watcher to Player'),
(21877, 1, 0, 'What ... have you done...', 14, 0, 100, 0, 0, 0, 19506, 0, 'Karsius the Ancient Watcher to Player'),
(21867, 0, 0, 'We will meet again... Someday.', 12, 0, 100, 273, 0, 0, 19508, 0, 'Teron Gorefiend'),
(21867, 1, 0, 'Death incarnate has been released upon the world once more! Teron Gorefiend has returned...', 14, 0, 100, 22, 0, 0, 19509, 0, 'Teron Gorefiend'),
(21872, 0, 0, 'Waste no time, fool! Use our power to kill those that stand in our way! Destroy Karsius before you are subdued!', 15, 0, 100, 1, 0, 0, 19503, 0, 'The Voice of Gorefiend');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(21797,21876,21877,21867);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN(21797,21876,21877,21867);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN(2179700,2179701);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21797, 0, 0, 1, 19, 0, 100, 0, 10645, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Quest \'Teron Gorefiend, I am...\' Taken - Store Targetlist'),
(21797, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2179700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Quest \'Teron Gorefiend, I am...\' Taken - Run Script'),
(21797, 0, 2, 3, 19, 0, 100, 0, 10639, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Quest \'Teron Gorefiend, I am...\' Taken - Store Targetlist'),
(21797, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2179700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Quest \'Teron Gorefiend, I am...\' Taken - Run Script'),
(21797, 0, 4, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 2179701, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Data Set - Run Script 2'),
(21797, 0, 5, 0, 40, 0, 100, 0, 3, 21867, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Reached WP7 - Despawn'),
(21797, 0, 6, 7, 6, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 21877, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Death - Set Data 2 2 on Karsius the Ancient Watcher'),
(21797, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 28, 37782, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - Just Died - Remove Aura Disembodied Spirit'),
(21797, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 37748, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - Just Died - Remove Aura Teron Gorefiend'),

(21876, 0, 0, 1, 11, 0, 100, 1, 0, 0, 0, 0, 11, 37761, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chain of Shadows - On Respawn - Cast \'Ancient Draenei Warden\''),
(21876, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chain of Shadows - On Respawn - Set Emote State 333'),
(21876, 0, 2, 0, 1, 0, 33, 0, 8000, 21000, 8000, 21000, 11, 37784, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chain of Shadows - OOC - Cast Enforced Submission'),
(21876, 0, 3, 0, 1, 0,100, 1, 0, 0, 0, 0, 11, 37784, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chain of Shadows - OOC - Cast Enforced Submission (No Repeat)'),
(21877, 0, 1, 0, 11, 0, 100, 1, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Respawn - Set Emote State 333'),
(21877, 0, 2, 0, 1, 0, 100, 0, 3000, 3000, 3000, 3000, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - OOC - Set Unit Flags'),
(21877, 0, 3, 4, 6, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 21876, 0, 200, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Death - Despawn Chain of Shadows'),
(21877, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 21867, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Death - Set Data'),
(21877, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Death - Despawn'),
(21877, 0, 6, 0, 1, 0, 100, 0, 3000, 3000, 3000, 3000, 19, 768, 0, 0, 0, 0, 0, 19, 21867, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - OOC - Set Unit Flags'),
(21877, 0, 7, 8, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 21876, 0, 200, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Evade Despawn'),
(21877, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 21797, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Despawn Ancient Shadowmoon Spirit'),
(21877, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 21867, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Despawn Ancient Shadowmoon Spirit'),
(21877, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Despawn Ancient Shadowmoon Spirit'),
(21877, 0, 11, 12, 6, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Just Died - Say Line 1'),
(21877, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 28, 37782, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Just Died - Remove Aura Disembodied Spirit'),
(21877, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 37748, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Just Died - Remove Aura Teron Gorefiend'),
(21877, 0, 14, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Data Set 2 2 - Evade'),
(2179701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script 2 - Evade'), 
(2179701, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 43, 0, 10720, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script 2 - Mount'), 
(2179701, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script 2 - Say Line 0'), -- 13:51:07.500
(2179701, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script 2 - Say Line 1'), -- 13:51:10.750
(2179701, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 53, 1, 21867, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script 2 - Start WP'), 
(2179700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Say Line 0'), -- 13:49:05.750
(2179700, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 36, 21867, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Change Entry'), -- 13:49:09.266
(2179700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Set Unit Flags'), -- 13:49:09.266
(2179700, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Add Aura Disembodied Spirit'), -- 13:49:09.266
(2179700, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 75, 37782, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Invoker Cast - Teron Gorefiend'), -- 13:49:10.235
(2179700, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 37769, 2, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Invoker Cast - Teron Gorefiend'), -- 13:49:10.235
(2179700, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 37728, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Cast - Haste'), -- 13:49:10.235
(2179700, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4524.726, 1009.763, 21.32487, 2.024582, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4515.913, 1020.078, 23.67377, 2.722714, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4515.165, 1033.106, 20.71271, 3.176499, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4525, 1045.415, 19.89447, 4.153883, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4537.54, 1049.356, 18.74087, 4.415683, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4551.174, 1044.113, 16.52099, 5.218534, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4523.753, 1062.352, 24.30409, 4.433136, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4509.667, 1047.063, 26.45817, 3.787364, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4504.674, 1020.563, 33.07281, 2.932153, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 16, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 12, 21877, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4535.794, 1029.284, 8.836361, 3.787364, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Karsius the Ancient Watcher\''), -- 13:49:12.782
(2179700, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21877, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Say Line 0 on \'Karsius the Ancient Watcher\''), -- 13:49:12.782
(2179700, 9, 18, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21872, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Say Line 0 on The Voice of Gorefiend'); -- 13:49:21.016

DELETE FROM `conditions`  WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(37748,37784);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 37748, 0, 0, 31, 0, 3, 21867, 0, 0, 0, 0, '', 'Teron Gorefiend (effects 1 & 2) target teron gorefiend'),
(13, 6, 37748, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Teron Gorefiend (effect 2 & 3) targets player'),
(13, 1, 37784, 0, 0, 31, 0, 3, 21867, 0, 0, 0, 0, '', 'Enforced Submission Targets Teron Gorefiend'),
(13, 1, 37784, 0, 1, 31, 0, 3, 21797, 0, 0, 0, 0, '', 'Enforced Submission Targets Ancient Shadowmoon Spirit');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=37748;
UPDATE `quest_template` SET `SourceSpellId`=0 WHERE  `Id`in(10645,10639);

DELETE FROM `creature_template_addon` WHERE `entry` IN (21876,21877,21797,21867);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(21876, 0, 0x0, 0x1, '37761'), -- 21876 - 37761
(21877, 0, 0x0, 0x1, '37497'), -- 21877
(21797, 0, 0x0, 0x1, '37509'), -- 21797 - 37509
(21867, 0, 0x0, 0x1, '37509'); -- 21867 - 37509 10720

UPDATE `creature_template` SET `unit_flags`=768 WHERE  `entry`=21876;
UPDATE `creature_template` SET `faction`=1821, `unit_flags`=33536 WHERE  `entry`=21877;
UPDATE `creature_template` SET `faction`=35, `unit_flags`=768 WHERE  `entry`=21867;

DELETE FROM  `waypoints` WHERE `entry`=21867;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(21867, 1, -4519.978, 1004.27, 12.49499, 'Teron Gorefiend'),
(21867, 2, -4520.013, 995.0764, 11.57806, 'Teron Gorefiend'),
(21867, 3, -4518.75, 968.75, 12.04559, 'Teron Gorefiend'),
(21867, 4, -4512.086, 938.8976, 2.529049, 'Teron Gorefiend');
