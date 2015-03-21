SET @CGUID=75031;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(27315,27336);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN(27315,27336);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27315,0,0,1,8,0,100,0,48363,0,0,0,28,49774,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - Remove Aura'),
(27315,0,1,2,61,0,100,0,0,0,0,0,11,43671,0,0,0,0,0,7,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - mount to invoker'),
(27315,0,2,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - set phasemask to 2'),
(27315,0,3,0,1,2,100,1,5000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - OOC (Phase 2) - Say text 0'),
(27315,0,4,5,23,2,100,1,43671,0,1000,1000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - On Aura Missing - say text'),
(27315,0,5,0,61,2,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - On Aura Missing -  despawn after 2 secs'),
(27336,0,0,1,8,0,100,0,48363,0,0,0,28,49774,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - Remove Aura'),
(27336,0,1,2,61,0,100,0,0,0,0,0,11,43671,0,0,0,0,0,7,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - mount to invoker'),
(27336,0,2,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - set phasemask to 2'),
(27336,0,3,0,1,2,100,1,5000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - OOC (Phase 2) - Say text 0'),
(27336,0,4,5,23,2,100,1,43671,0,1000,1000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - On Aura Missing - say text'),
(27336,0,5,0,61,2,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - On Aura Missing -  despawn after 2 secs');

/* aura for mount */
DELETE FROM `creature_template_addon` WHERE `entry`=27258;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(27258, 0, 0, 33554432, 0, 0, '34873');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN(13,17) AND `SourceEntry` IN(48397,48363);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 48397, 0, 0, 29, 0, 27315, 5, 1, 0, 0, 0, '', 'Required NPC to cast Spell'),
(17, 0, 48397, 0, 1, 29, 0, 27336, 5, 1, 0, 0, 0, '', 'Required NPC to cast Spell'),
(17, 0, 48397, 0, 0, 30, 0, 300199, 15, 0, 0, 0, 0, '', 'Spell focus for Drop Off Helpless Wintergarde Villager'),
(13, 2, 48397, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Drop Off Villager Effect #2 Targets Player'),
(13, 1, 48363, 0, 0, 31, 0, 3, 27315, 0, 0, 0, 0, '', 'Grab  targets Helpless Wintergarde Villager'),
(17, 0, 48363, 0, 0, 29, 0, 27315, 5, 1, 0, 0, 0, '', 'Required NPC to cast Spell'),
(13, 1, 48363, 0, 1, 31, 0, 3, 27336, 0, 0, 0, 0, '', 'Grab  targets Helpless Wintergarde Villager'),
(17, 0, 48363, 0, 1, 29, 0, 27336, 5, 1, 0, 0, 0, '', 'Required NPC to cast Spell');

UPDATE `creature_template` SET `faction`=35 WHERE  `entry`=27258;
UPDATE `creature_template` SET `exp`=2, `speed_walk`=1, `speed_run`=1.142857,`faction`=35 WHERE  `entry`=27258;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=48397;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(48397, -43671, 0, 'remove npc');

UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=68, `unit_flags`=33536 WHERE  `entry`=27336;
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=70, `unit_flags`=33536 WHERE  `entry`=27315;

DELETE FROM `creature_text` WHERE `entry` IN(27315,27336);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES 
(27315, 0, 0, 'Are you sure you know how to fly this thing? Feels a little wobbly.', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26359),
(27315, 0, 1, 'I don\'t mean to sound ungrateful, but could you fly a little closer to the ground? I hate heights!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26360),
(27315, 0, 2, 'I picked a bad day to stop drinking!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26345),
(27315, 0, 3, 'I\'m gettin\' a little woozy... Oooooof...', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26364),
(27315, 0, 4, 'You saved my life! Thanks!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26358),
(27315, 0, 5, 'You are my guardian angel! Like a white knight you flew in from the heavens and lifted me from the pit of damnation!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26362),
(27315, 1, 0, 'How can I ever repay you for this, friend?', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26363),
(27315, 1, 1, 'HURRAY!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26382),
(27315, 1, 2, 'Kindness is not lost with this one, Urik. Thank you, hero!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26383),
(27315, 1, 3, 'My shop\'s doors will always be open to you, friend.', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26385),
(27315, 1, 4, 'Safe at last! Thank you, stranger!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26381),
(27315, 1, 5, 'Thanks for your help, hero!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26357),
(27315, 1, 6, 'We made it! We actually made it!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26384),
(27336, 0, 0, 'Are you sure you know how to fly this thing? Feels a little wobbly.', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26359),
(27336, 0, 1, 'I don\'t mean to sound ungrateful, but could you fly a little closer to the ground? I hate heights!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26360),
(27336, 0, 2, 'I picked a bad day to stop drinking!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26345),
(27336, 0, 3, 'I\'m gettin\' a little woozy... Oooooof...', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26364),
(27336, 0, 4, 'You saved my life! Thanks!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26358),
(27336, 0, 5, 'You are my guardian angel! Like a white knight you flew in from the heavens and lifted me from the pit of damnation!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26362),
(27336, 1, 0, 'How can I ever repay you for this, friend?', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26363),
(27336, 1, 1, 'HURRAY!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26382),
(27336, 1, 2, 'Kindness is not lost with this one, Urik. Thank you, hero!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26383),
(27336, 1, 3, 'My shop\'s doors will always be open to you, friend.', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26385),
(27336, 1, 4, 'Safe at last! Thank you, stranger!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26381),
(27336, 1, 5, 'Thanks for your help, hero!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26357),
(27336, 1, 6, 'We made it! We actually made it!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26384);

DELETE FROM `creature` WHERE `id` IN(27336,27315);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 27336, 571, 1, 1, 3846.755, -929.0404, 112.8907, 4.708376, 120, 5, 1), -- 27336 (Area: 4177) (possible waypoints or random movement)
(@CGUID+1, 27336, 571, 1, 1, 3889.424, -935.4798, 115.6459, 1.28458, 120, 5, 1), -- 27336 (Area: 4177) (possible waypoints or random movement)
(@CGUID+2, 27336, 571, 1, 1, 3878.463, -985.8888, 116.4584, 5.028894, 120, 5, 1), -- 27336 (Area: 4177) (possible waypoints or random movement)
(@CGUID+3, 27336, 571, 1, 1, 3823.805, -1083.309, 119.5392, 1.963927, 120, 5, 1), -- 27336 (Area: 4177) (possible waypoints or random movement)
(@CGUID+4, 27336, 571, 1, 1, 3817.068, -1048.894, 119.9088, 1.822633, 120, 5, 1), -- 27336 (Area: 4177) (possible waypoints or random movement)
(@CGUID+5, 27336, 571, 1, 1, 3771.587, -1131.885, 121.5405, 5.288348, 120, 5, 1), -- 27336 (Area: 4188) (possible waypoints or random movement)
(@CGUID+6, 27336, 571, 1, 1, 3583.055, -1331.913, 109.3448, 6.212783, 120, 5, 1), -- 27336 (Area: 4188) (possible waypoints or random movement)
(@CGUID+7, 27315, 571, 1, 1, 3822.955, -1128.766, 120.1993, 5.973483, 120, 5, 1), -- 27315 (Area: 4188) (possible waypoints or random movement)
(@CGUID+8, 27315, 571, 1, 1, 3664.299, -1270.015, 112.583, 5.268541, 120, 5, 1), -- 27315 (Area: 4188) (possible waypoints or random movement)
(@CGUID+9, 27315, 571, 1, 1, 3625.333, -1260.047, 112.6119, 6.237288, 120, 5, 1), -- 27315 (Area: 4188) (possible waypoints or random movement)
(@CGUID+10, 27315, 571, 1, 1, 3721.795, -1345.791, 133.6774, 0.2871537, 120, 5, 1), -- 27315 (Area: 4188) (possible waypoints or random movement)
(@CGUID+11, 27315, 571, 1, 1, 3718.502, -1323.397, 125.0354, 1.818619, 120, 5, 1), -- 27315 (Area: 4234) (possible waypoints or random movement)
(@CGUID+12, 27315, 571, 1, 1, 3768.525, -1289.776, 133.6532, 4.827796, 120, 5, 1), -- 27315 (Area: 4234) (possible waypoints or random movement)
(@CGUID+13, 27336, 571, 1, 1, 3707.695, -1138.643, 120.2261, 4.974188, 120, 0, 0); -- 27336 (Area: 4188)

DELETE FROM `creature_template_addon` WHERE `entry` IN(27336,27315);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(27336, 0, 0x0, 0x1, '48361 49774'), -- 27336 - 48361, 49774
(27315, 0, 0x10000, 0x1, '48361 49774'); -- 27315 - 48361, 49774

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=27258;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(16, 0, 27258, 0, 0, 23, 0, 4188, 0, 0, 0, 0, 0, '', 'Dismount player when not in intended zone'),
(16, 0, 27258, 0, 1, 23, 0, 4177, 0, 0, 0, 0, 0, '', 'Dismount player when not in intended zone'),
(16, 0, 27258, 0, 2, 23, 0, 4178, 0, 0, 0, 0, 0, '', 'Dismount player when not in intended zone');
