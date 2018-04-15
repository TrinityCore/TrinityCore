SET @CONTROL_WATCHER := 58524;
SET @ETHREAL         := 58548;
SET @GOSSIP          := 10028;
SET @EYE             := 193058;
SET @WATCHER         := 31110;
SET @MIRROR_NPC      := 31005;
SET @FIGMENT_SPELL   := 57530; 
SET @PLAYER_MIRROR   := 58122;
SET @CONTROL_START   := 58120;
SET @MIRROR_SPELL    := 57528;
SET @WEAPON_COPY     := 41055;
SET @COPY_OFF_HAND   := 45205;

UPDATE `creature_template` SET `spell1` = 58541, `spell2` = 58544, `spell3` = 58543, `spell4` = 58562, `spell5` = 58563, `spell6` = 58658 WHERE `entry` = @WATCHER;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@MIRROR_NPC;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`= @EYE;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @WATCHER;
DELETE FROM `smart_scripts` WHERE `entryorguid`= @EYE;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@EYE,1,0,1,62,0,100,0,@GOSSIP,0,0,0,85,@CONTROL_WATCHER,2,0,0,0,0,7,0,0,0,0,0,0,0, 'On Gossip Option Select - Cast Control Eidolon Watcher - Action Invoker'),
(@EYE,1,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Eye of Dominion - On link - Close Gossip Option'),
(@EYE,1,2,3,61,0,100,0,0,0,0,0,85,@PLAYER_MIRROR,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Eye of Dominion - On link - Summon Player Mirror'),
(@EYE,1,3,0,61,0,100,0,0,0,0,0,15,13168,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Eye of Dominion - On link - Complete quest');
DELETE FROM `smart_scripts` WHERE `entryorguid`= @MIRROR_NPC;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MIRROR_NPC,0,0,1,54,0,100,1,0,0,0,0,85,@MIRROR_SPELL,2,0,0,0,0,1,0,0,0,0,0,0,0, 'On spawn - Cast Mirror Spell - Action Invoker'),
(@MIRROR_NPC,0,1,2,61,0,100,1,0,0,0,0,85,@WEAPON_COPY,2,0,0,0,0,1,0,0,0,0,0,0,0,'On Link - Copy Main Hand - Action Invoker'),
(@MIRROR_NPC,0,2,3,61,0,100,1,0,0,0,0,85,@COPY_OFF_HAND,2,0,0,0,0,1,0,0,0,0,0,0,0,'On Link - Copy Offhand - Action Invoker'),
(@MIRROR_NPC,0,3,0,61,0,100,1,0,0,0,0,11,@CONTROL_START,2,0,0,0,0,1,0,0,0,0,0,0,0,'On Spawn - Cast Start Control - Action Invoker');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@WATCHER;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@WATCHER,0,0,0,54,0,100,1,0,0,0,0,11,@ETHREAL,2,0,0,0,0,1,0,0,0,0,0,0,0, 'On spawn - Cast Ethreal Aura - On self');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = @EYE;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22,4,@EYE,1,0,9,0,13168,0,0,0,0,'','Execute SAI line only if player has quest active');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@MIRROR_SPELL;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,7,@MIRROR_SPELL,0,0,31,0,3,@MIRROR_NPC,0,0,0,'','Spell target Mirror npc');
