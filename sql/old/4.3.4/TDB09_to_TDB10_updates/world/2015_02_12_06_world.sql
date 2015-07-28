-- The Grasp Weakens 
SET @Malia:=   39117;
SET @Devlin:=  38980;
SET @Spell:=   73180;
SET @Shadow:=  38981;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Malia  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Malia*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Malia*100+1  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Shadow  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Devlin  AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Malia, @Devlin, @Shadow);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Malia, 0, 0, 0, 62, 0, 100, 0, 11156, 0, 0, 0, 80, @Malia*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - On Gossip Select - Actionlist'),
(@Malia*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Close gossip'),
(@Malia*100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk1'),  -- 0
(@Malia*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - On Script - Set React Passive'),
(@Malia*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @Malia, 0, 0, 999990, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Action list - StartWaypoint'),
(@Malia, 0, 1, 0, 40, 0, 100, 0, 4, 0, 0, 0, 80, @Malia*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - On waypointReached - Actionlist'),
(@Malia*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'), 
(@Malia*100+1, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'), 
(@Malia*100+1, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 12, @Devlin, 1, 111110, 0, 0, 0, 8, 0, 0, 0, 2246.889893, 228.612000, 44.834801, 2.019680, 'Malia - Actionlist - Spawn'), 
(@Malia*100+1, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'), 
(@Malia*100+1, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 8, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 10, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 11, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 12, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 13, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Despawn'),
(@Malia*100+1, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @Spell, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - cast to summon'),
(@Malia*100+1, 9, 15, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 16, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Despawn'),
(@Devlin, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 17, 437, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Devlin - On spawn - StateEmote'),
(@Shadow, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 18, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow - On spawn - UnitFlag 4'),
(@Shadow, 0, 1, 0, 0, 0, 100, 0, 0, 0, 6000, 6000, 11, 16568, 2, 0, 0, 0, 0, 21, 15, 0, 0, 0, 0, 0, 0, 'Shadow - IC - CastSpell');

UPDATE `creature_template` SET `faction`=14, `minlevel`=10, `maxlevel`=11, `inhabittype`=4 WHERE (`entry`=@Shadow);
UPDATE `creature_template` SET `inhabittype`=4 WHERE (`entry`=@Devlin);
UPDATE `creature_template` SET `gossip_menu_id`=11156, `npcflag`=1 WHERE (`entry`=@Malia);

DELETE FROM `waypoints` WHERE `entry`=@Malia;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Malia,1, 2240.255615, 233.003922, 34.551388, 'Malia'),
(@Malia,2, 2234.646240, 229.994614, 38.211372, 'Malia'),
(@Malia,3, 2236.925537, 226.070419, 38.245140, 'Malia'),
(@Malia,4, 2243.648193, 228.888794, 41.812122, 'Malia');

UPDATE `npc_text` SET `BroadcastTextID0`=39150 WHERE `ID`=15527;

DELETE FROM `gossip_menu` WHERE `entry`=11156 AND `text_id`=15527;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (11156,15527);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11156;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES (11156, 0, 0, 'I am ready', 39152, 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11156;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11156,0,0,9,25006,0,0,0,'','Show gossip menu if player accept The Grasp Weakens');

DELETE FROM `creature_text` WHERE `entry` IN (@Devlin, @Malia);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Malia, 0, 0, 'Very well. Follow me.', 12, 0, 100, 0, 0, 0, 'Malia', 39153),
(@Malia, 1, 0, 'Now it is time for us to begin.', 12, 0, 100, 1, 0, 0, 'Malia', 39154),
(@Malia, 2, 0, 'Devlin Agamand! Listen to my voice!', 14, 0, 100, 22, 0, 0, 'Malia', 39155),
(@Malia, 3, 0, 'Your mortal remains have been gathered, here in this place where you spent your childhood!', 14, 0, 100, 22, 0, 0, 'Malia', 39156),
(@Malia, 4, 0, 'Resist the Lich King''s will, Devlin! Come to us!', 14, 0, 100, 22, 0, 0, 'Malia', 39157),
(@Malia, 5, 0, 'I had better return to my post. You can find me downstairs if you need anything.', 12, 0, 100, 1, 0, 0, 'Malia', 39158),
(@Devlin, 0, 0, 'What''s going on here?', 12, 0, 100, 0, 0, 0, 'Devlin', 39160),
(@Devlin, 1, 0, 'Wait, am I... home?', 12, 0, 100, 0, 0, 0, 'Devlin', 39161),
(@Devlin, 2, 0, 'You people... what are you doing here? Why are you in my house?', 12, 0, 100, 0, 0, 0, 'Devlin', 39162),
(@Devlin, 3, 0, 'Mother... father... Thurman... where are you?', 12, 0, 100, 0, 0, 0, 'Devlin', 39163),
(@Devlin, 4, 0, 'No... I remember. My family is dead. And so am I.', 12, 0, 100, 0, 0, 0, 'Devlin', 39164),
(@Devlin, 5, 0, 'And my soul.... my soul belongs to the Scourge!', 12, 0, 100, 0, 0, 0, 'Devlin', 39165),
(@Devlin, 6, 0, 'DIE, YOU WRETCHES!', 14, 0, 100, 0, 0, 0, 'Devlin', 39166);
