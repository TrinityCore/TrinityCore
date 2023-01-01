-- 
UPDATE `creature_template` SET `AIName`= 'SmartAI', `ScriptName`="" WHERE `entry`IN (23778,23998);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23998,23778) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23778, 0, 0, 0, 1, 0, 100, 0, 0, 45000, 90000, 180000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Ranger Lyana - OOC - Say'),
(23778, 0, 1, 0, 62, 0, 100, 0, 8879, 0, 0, 0, 11, 42799, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dark Ranger Lyana - on gossip select - Credit quest'),
(23778, 0, 2, 0, 0, 0, 100, 0, 2000, 2000, 2000, 3000, 11, 61512, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dark Ranger Lyana - IC - Cast '),
(23998, 0, 0, 0, 62, 0, 100, 0, 8870, 0, 0, 0, 11, 42756, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Deathstalker Razael - on gossip select - Credit quest');

UPDATE `creature` SET `position_x`=1618.561035, `position_y`=-6155.402832, `position_z`=9.270269, `orientation`=3.982527 WHERE `id`=23778; 
DELETE FROM `creature_template_addon` WHERE `entry` IN (23778);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`) VALUES
(23778, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8879,8870);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8879,0,0,9,11221,0,0,0,0,'','Only show gossip option 0 if player has if player has quest 11221 active'),
(15,8870,0,0,9,11221,0,0,0,0,'','Only show gossip option 0 if player has if player has quest 11221 active');
