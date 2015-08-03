SET @Crystal=31131; -- Containment Crystal
SET @Watcher=31110; -- Eidolon Watcher

-- Update creature_templates and template_addons
UPDATE `creature_template` SET `exp`=2,`minlevel`=80,`maxlevel`=80,`unit_flags`=`unit_flags`|32776 WHERE `entry`=@Watcher; 
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33555200,`AIname`='SmartAI' WHERE `entry`=@Crystal;
DELETE FROM `creature_template_addon` WHERE `entry` IN (@Watcher,@Crystal);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@Watcher,0,0,1,0, NULL),
(@Crystal,0,0,1,0, NULL);
-- Delete old condition 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=193058 AND `SourceId`=1;
-- Four quests need gains control of the Eidolon Watcher not only one
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10028 AND `sourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,10028,0,0,0,9,0,13168,0,0,0,0,0,'','Show Gossip option only if player has quest active'),
(15,10028,0,0,1,9,0,13171,0,0,0,0,0,'','Show Gossip option only if player has quest active'),
(15,10028,0,0,2,9,0,13169,0,0,0,0,0,'','Show Gossip option only if player has quest active'),
(15,10028,0,0,3,9,0,13170,0,0,0,0,0,'','Show Gossip option only if player has quest active');
-- Conditions for Banish Scourge Crystal spell
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `sourceEntry`=58658;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,58658,0,0,31,0,3,@Crystal,0,0,0,0,'','Banish Scourge Crystal Hits Only Containment Crystal');
-- Sai for Containment Crystal
DELETE FROM `smart_scripts` WHERE `entryorguid`=31131 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Crystal,0,0,1,8,0,100,0,58662,0,0,0,33,@Crystal,0,0,0,0,0,7,0,0,0,0,0,0,0,'Containment Crystal - On Spell Hit - Give Quest Credit'),
(@Crystal,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Containment Crystal - Link With Previous Event - Despawn');
