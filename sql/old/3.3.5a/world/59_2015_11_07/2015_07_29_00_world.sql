--
UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=7774;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7774 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=777400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7774,0,0,1,19,0,100,0,2845,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Quest Accept (Wondering Shay) - Set NPC Flags'),
(7774,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Shay Leafrunner - On Quest Accept (Wondering Shay) - Store Target List'),
(7774,0,2,3,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Quest Accept (Wondering Shay) - Set Unit Flags'),
(7774,0,3,4,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Quest Accept (Wondering Shay) - Say Line 0'),
(7774,0,4,5,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Shay Leafrunner - On Quest Accept (Wondering Shay) - Follow Invoker'),
(7774,0,5,6,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Quest Accept (Wondering Shay) - Set Phase 2'),
(7774,0,6,0,61,0,100,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Quest Accept - Set Faction'),
(7774,0,7,0,7,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Evade - Set Phase 2'),
(7774,0,8,0,6,0,100,0,0,0,0,0,6,2845,0,0,0,0,0,12,1,0,0,0,0,0,0,'Shay Leafrunner - On Death - Fail Quest'),
(7774,0,9,0,1,2,100,0,40000,70000,60000,70000,80,777400,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - OOC (Phase 2) - Action list'),
(777400,9,0,0,0,0,100,0,0,0,0,0,46,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - Action list - move forword'),
(777400,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - Action list - Say Line 2'),
(777400,9,2,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - Action list - Say Line 3'),
(777400,9,3,0,0,0,100,0,5000,5000,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - Action list - Set home position'),
(777400,9,4,0,0,0,100,0,0,0,0,0,89,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - Action list - Set Random Movement'),
(7774,0,10,11,8,2,100,0,11402,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Spellhit (Shay''s Bell) - Turn Random Movement Off'),
(7774,0,11,12,61,2,100,0,0,0,0,0,29,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Shay Leafrunner - On Spellhit (Shay''s Bell) - Follow Invoker'),
(7774,0,12,0,61,2,100,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,'Shay Leafrunner - On Spellhit (Shay''s Bell) - Say Line 1'),
(7774,0,13,14,75,2,100,1,0,7765,10,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Rockbiter within 10 yards - Say Line 4'),
(7774,0,14,15,61,2,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Rockbiter within 10 yards - Root'),
(7774,0,15,16,61,2,100,0,0,0,0,0,15,2845,0,0,0,0,0,12,1,0,0,0,0,0,0,'Shay Leafrunner - On Rockbiter within 10 yards - Call areaexploredoreventhappens'),
(7774,0,16,0,61,2,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Rockbiter within 10 yards - Set Phase 1'),
(7774,0,17,18,52,0,100,0,4,7774,0,0,1,0,0,0,0,0,0,19,7765,0,0,0,0,0,0,'Shay Leafrunner - On Text Over Line 4  - Say Line 0 on Rockbiter'),
(7774,0,18,0,61,0,100,0,4,7774,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shay Leafrunner - On Text Over Line 4  - Despawn after 10 seconds');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=11402;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 11402, 0, 0, 31, 0, 3, 7774, 0, 0, 0, 0, '', 'Shays Bell targets Shay Leafrunner');

DELETE FROM `creature_text` WHERE `entry`IN(7774,7765);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(7774, 0, 0, 'Don''t forget to get my bell out of the chest here. And remember, if do happen to wander off, just ring it and i''ll find you again.', 12, 0, 100, 0, 0, 0, 3921, 0, 'Shay Leafrunner'),
(7774, 1, 0, 'This is quite an adventure!', 12, 0, 100, 0, 0, 0, 3914, 0, 'Shay Leafrunner'),
(7774, 1, 1, 'Oh, I wandered off again. I''m sorry.', 12, 0, 100, 0, 0, 0, 3913, 0, 'Shay Leafrunner'),
(7774, 1, 2, 'The bell again, such a sweet sound.', 12, 0, 100, 0, 0, 0, 3916, 0, 'Shay Leafrunner'),
(7774, 1, 3, 'I can''t help it, really. This is just such a beautiful place.', 12, 0, 100, 0, 0, 0, 3915, 0, 'Shay Leafrunner'),
(7774, 2, 0, '%s begins to wander off.', 16, 0, 100, 0, 0, 0, 3918, 0, 'Shay Leafrunner'),
(7774, 3, 0, 'Are we taking the scenic route?', 12, 0, 100, 0, 0, 0, 3912, 0, 'Shay Leafrunner'),
(7774, 3, 1, 'Oh, what a beautiful flower over there.', 12, 0, 100, 0, 0, 0, 3907, 0, 'Shay Leafrunner'),
(7774, 3, 2, 'These trees are quite glorious, aren''t they? ', 12, 0, 100, 0, 0, 0, 3908, 0, 'Shay Leafrunner'),
(7774, 3, 3, 'Are you sure this is the right way? Maybe we should go this way instead...', 12, 0, 100, 0, 0, 0, 3909, 0, 'Shay Leafrunner'),
(7774, 4, 0, 'Oh, here you are, Rockbiter! I''m sorry, I know I''m not supposed to wander off.', 12, 0, 100, 0, 0, 0, 3917, 0, 'Shay Leafrunner'),
(7765, 0, 0, 'I''m glad yer back, Shay. Please, don''t ever run off like that again! What would i tell yer parents if I lost ya?"', 12, 0, 100, 0, 0, 0, 3922, 0, 'Shay Leafrunner');
