UPDATE `creature_template` SET `AIName`='SmartAI',`npcflag`=16777216 WHERE `entry`=26809;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26809 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26809, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 31261, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ravaged Crystalline Ice Giant - On Spawn - Cast Permanent Feign Death (Root) on self'),
(26809, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 56, 36765, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ravaged Crystalline Ice Giant - On Spellclick - Add Sample of Rockflesh');
 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =26809;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =26048;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN(26809, 26048);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(26809, 47416, 0, 0),
(26048, 46407, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN(26809,26048);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 26809, 47416, 0, 0, 9, 0, 12075, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
(18, 26048, 46407, 0, 0, 9, 0, 11895, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick');

DELETE FROM `smart_scripts` WHERE  `entryorguid`=26048 AND `source_type`=0 AND `id`=6 AND `link`=0;
UPDATE `smart_scripts` SET `event_type`=73 WHERE  `entryorguid`=26048 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `action_param1`=16777216 WHERE  `entryorguid`=2604800 AND `source_type`=9 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`=16777216 WHERE  `entryorguid`=26048 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`=16777216 WHERE  `entryorguid`=26045 AND `source_type`=0 AND `id`=8 AND `link`=9;
