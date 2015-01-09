SET @AETHER_RAY          := 22181;
SET @WRANGLED_RAY        := 23343;
SET @WRANGLE_SPELL       := 40856;
SET @WRANGLED_FORCE_CAST := 40917;
SET @WRANGLED_AURA       := 40926;
SET @QUEST_GIVER         := 23335;

DELETE FROM `creature_text` WHERE `entry`=@AETHER_RAY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@AETHER_RAY,1,0,'The Aether Ray appears ready to be wrangled.',16,0,100,0,0,0,'Aether Ray');

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@AETHER_RAY; 4.x removed
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@AETHER_RAY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@AETHER_RAY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@AETHER_RAY, 0, 0, 0, 0, 0, 100, 0, 5000, 6000, 8000, 9000, 11, 35333, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Aether Ray - IC - Cast Tail Swipe'),
(@AETHER_RAY, 0, 1, 0, 2, 0, 100, 1, 0, 40, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aether Ray - On 40 % HP - Say emote'),
(@AETHER_RAY, 0, 2, 3, 8, 0, 100, 0, @WRANGLE_SPELL, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aether Ray - On spellcast - Despawn'),
(@AETHER_RAY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, @WRANGLED_FORCE_CAST, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Aether Ray - Link with 2 - Summon Wrangled Aether Ray');

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@WRANGLED_RAY; 4.x removed
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@WRANGLED_RAY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@WRANGLED_RAY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@WRANGLED_RAY, 0, 0, 1, 54, 0, 100, 1, 0, 0, 0, 0, 85, @WRANGLED_AURA, 3, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spawn - Cast Wrangled Aura - Action Invoker'),
(@WRANGLED_RAY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, @QUEST_GIVER, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wrangled Ray - Link with 0 - Follow Player'),
(@WRANGLED_RAY, 0, 2, 0, 65, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrangled Ray - On follow complete - Despawn');

DELETE FROM `conditions` WHERE `SourceEntry`=@WRANGLE_SPELL;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, @WRANGLE_SPELL, 0, 0, 31, 1, 3, 22181, 0, 0, 0, 0, '', 'Spell only hits Aether Rey'),
(17, 0, @WRANGLE_SPELL, 0, 0, 38, 1, 40, 4, 0, 0, 0, 0, '', 'Spell only hits if at or below 40%');
