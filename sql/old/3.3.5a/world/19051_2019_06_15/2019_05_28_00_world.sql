-- 
DELETE FROM `creature` WHERE `guid` IN (106803,106805,106806);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(106805, 21902, 530, 0, 0, 1, 1, 0, 1, -3159.26, 4934.68, -8.98392, 1.65806, 600, 0, 0, 4300, 2620, 0, 0, 0, 0, 0),
(106803, 21963, 530, 0, 0, 1, 1, 0, 0, -3159.3007, 4943.1191, -9.0023, 6.271395, 600, 0, 0, 4572, 2705, 0, 0, 0, 0, 0),
(106806, 21957, 530, 0, 0, 1, 1, 0, 0, -3154.967, 4938.921, -7.373, 2.373469, 600, 0, 0, 42, 0, 0, 0, 0, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=38014;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,38014,0,1,31,0,3,21963,0,0,0,'','Shadow Council Channel can hit Enslaved Doomguard');

DELETE FROM `smart_scripts` WHERE `entryorguid`=21902 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21902, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 38014, 0, 0, 0, 0, 0, 19, 21963, 20, 0, 0, 0, 0, 0, 'Cabal Spell-weaver - On reset - Cast Shadow Council Channel');

UPDATE `creature_template` SET `AIName`='SmartAI', `unit_flags`=0 WHERE `entry` IN (21963);
DELETE FROM `smart_scripts` WHERE `entryorguid`=21963 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21963, 0, 0, 0, 0, 0, 100, 0, 3000, 6000, 7000, 10000, 11, 11876, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enslaved Doomguard - IC - Cast War Stomp'),
(21963, 0, 1, 0, 0, 0, 100, 0, 3000, 6000, 5000, 9000, 11, 11443, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Enslaved Doomguard - IC - Cast Cripple'),
(21963, 0, 2, 0, 0, 0, 100, 0, 5000, 8000, 8000, 12000, 11, 31598, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Enslaved Doomguard - IC - Cast Rain of Fire'),
(21963, 0, 3, 0, 23, 0, 100, 0, 38014, 1, 2000, 2000, 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enslaved Doomguard - Has aura - Add unit flag'),
(21963, 0, 4, 0, 23, 0, 100, 0, 38014, 0, 2000, 2000, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enslaved Doomguard - Has aura - remove unit flag');
