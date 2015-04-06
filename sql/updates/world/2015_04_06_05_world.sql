SET @OGUID     := 5596; -- 1 free guid set by TC
SET @QUEST     := 12326;
SET @TANK      := 27587; -- Alliance Steam Tank
SET @ELITE     := 27588; -- 7th Legion Elite
SET @ENGI      := 27163; -- 7th Legion Siege Engineer
SET @SPELL_1   := 49315; -- Ice Cannon
SET @SPELL_2   := 49333; -- Ice Prison
SET @SPELL_3   := 49109; -- Drop Off Gnome
SET @SPELL_4   := 49081; -- Drop Off Soldier

DELETE FROM `gameobject` WHERE `guid` = @OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 189331, 571, 1, 1, 3707.753418, -1182.235840, 120.745689, 1.24532, 0, 0, 0, 1, 120, 0, 1);

UPDATE `creature_template` SET `npcflag`=16777216, `unit_flags`=32768, `spell1`=49315, `spell2`=49333, `spell3`=49109, `spell4`=49081 WHERE `entry`=@TANK;
UPDATE `creature_template` SET `faction` = 1975 WHERE `entry`=27335;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ENGI, 27607, @TANK);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@TANK;
INSERT INTO `npc_spellclick_spells`(`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@TANK,49078,1,0), -- player
(@TANK,46598,1,1); -- npc

DELETE FROM `vehicle_template_accessory` WHERE `entry`=@TANK;
INSERT INTO `vehicle_template_accessory`(`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(@TANK,@ENGI,1,1,"7th Legion Siege Engineer Rides Alliance Steam Tank",5,0),
(@TANK,@ELITE,2,1,"7th Legion Elite Rides Alliance Steam Tank",5,0),
(@TANK,@ELITE,3,1,"7th Legion Elite Rides Alliance Steam Tank",5,0);
DELETE FROM `creature` WHERE `id` IN (27163,27588);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=16 AND `SourceEntry`=@TANK) OR (`SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@SPELL_2,@SPELL_3))  OR (`SourceTypeOrReferenceId`=18 AND `SourceEntry` IN (46598,49078));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(16,0,@TANK,0,0,23,0,4246,0,0,0,0,'','Dismount player when not in intended zone'),
(16,0,@TANK,0,1,23,0,4190,0,0,0,0,'','Dismount player when not in intended zone'),
(16,0,@TANK,0,2,23,0,4188,0,0,0,0,'','Dismount player when not in intended zone'),
(13,1,@SPELL_2,0,0,31,0,3,27288,0,0,0,'','Ice Prison can target Death Knight Champion'),
(13,1,@SPELL_2,0,1,31,0,3,27410,0,0,0,'','Ice Prison can target Scourge SeigeSmith'),
(13,1,@SPELL_2,0,2,31,0,3,27286,0,0,0,'','Ice Prison can target Dreadbone Invader'),
(13,1,@SPELL_2,0,3,31,0,3,27283,0,0,0,'','Ice Prison can target Risen Winterguarde Mage'),
(13,2,@SPELL_3,0,0,31,0,3,@ENGI,0,0,0,'','Drop Off Gnome target 7th Legion Siege Engineer'),
(18,@TANK,46598,0,0,31,0,3,0,0,0,0,'','Only npc for spellclick'),
(18,@TANK,49078,0,0,9,0,@QUEST,0,0,0,0,'','Required quest active for spellclick');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=@TANK;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`, `ConditionTarget`, `ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,@TANK,0,1,1,49078,0,0,0,'','event require aura 49078');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@ENGI;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`, `ConditionTarget`, `ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@ENGI,0,1,29,27607,14,0,0,'','event require creature distance');

DELETE FROM `creature_template_addon` WHERE `entry` IN (@ENGI,@ELITE);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENGI,0,0,0,257,133,NULL),
(@ELITE,0,0,0,257,333,NULL);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27607  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27607*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @TANK  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @TANK*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENGI  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENGI*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENGI*100+1  AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENGI, 0, 0, 0, 8, 0, 100, 0, @SPELL_3, 0, 0, 0, 80, @ENGI*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - On spell hit - action list'),
(@ENGI*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Set visible off'),
(@ENGI*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @ENGI, 3, 18000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Summon'),
(@ENGI*100, 9, 2, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Set visible on'),
(@ENGI, 0, 1, 0, 23, 0, 100, 1, 46598, 0, 0, 0, 80, @ENGI*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - Has aura - action list'),
(@ENGI*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Talk'),
(@ENGI*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - React passif'),
(@ENGI*100+1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 29, 3, 0, 0, 0, 0, 0, 19, 27607, 15, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - follow'),
(@ENGI*100+1, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 49114, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Cast to summon a GO'),
(@ENGI*100+1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Talk'),
(@ENGI*100+1, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 75, 49215, 0, 0, 0, 0, 0, 19, 27607, 15, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Add aura'),
(@ENGI*100+1, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Talk'),
(@ENGI*100+1, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 29, 1, 0, 0, 0, 0, 0, 19, @TANK, 15, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - follow'),
(@TANK,0,0,0,38,0,100,0,0,1,0,0,11,49122,0,0,0,0,0,23,0,0,0,0,0,0,0,"Tank - On data set- cast spell credit"),
(@TANK,0,1,0,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tank - On reset- react passif"),
(@TANK,0,2,0,1,0,100,0,30000,30000,50000,50000,1,1,0,0,0,0,0,19,@ELITE,10,0,0,0,0,0,'Tank - OOC - Talk'),
(@TANK,0,4,0,25,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tank - On reset- Set Run on"),
(@TANK, 0, 3, 0, 8, 0, 100, 0, @SPELL_4, 0, 0, 0, 80, @TANK*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - On spell hit - action list'),
(@TANK*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 11, @ELITE, 10, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Set visible off'),
(@TANK*100, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 11, @ELITE, 10, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Summon'),
(@TANK*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '7th Legion Siege Engineer - action list - Set visible on'),
(27607, 0, 1, 0, 23, 0, 100, 1, 49215, 1, 0, 0, 80, 27607*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Plague Wagon - Has aura - action list'),
(27607*100, 9, 0, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, @TANK, 30, 0, 0, 0, 0, 0, 'Plague Wagon - action list - Set data'),
(27607*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Plague Wagon - action list - despawn');

DELETE FROM `creature_text` WHERE `entry` IN (@ELITE, @ENGI);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(@ELITE, 0, 0, 'Without you we''d be lost. Thanks for the ride!', 12, 7, 100, 0, 0, 0, 26844, 0, '7th Legion Elite'),
(@ELITE, 0, 1, 'For the Alliance and Lord Fordragon!', 12, 7, 100, 0, 0, 0, 26841, 0, '7th Legion Elite'),
(@ELITE, 0, 2, 'HOO-WAH! The cavalry has arrived!', 12, 7, 100, 0, 0, 0, 26842, 0, '7th Legion Elite'),
(@ELITE, 0, 3, 'Great driving, soldier! Not a scratch on us!', 12, 7, 100, 0, 0, 0, 26843, 0, '7th Legion Elite'),
(@ELITE, 1, 0, 'I think I see one of their plague wagons!', 12, 0, 100, 0, 0, 0, 26971, 0, '7th Legion Elite'),
(@ELITE, 1, 1, 'Did I ever tell you soldiers about the time I destroyed the Thandol Span? Yep, weren''t no dark irons destroyed that bridge! Was me!', 12, 7, 100, 0, 0, 0, 26972, 0, '7th Legion Elite'),
(@ELITE, 1, 2, 'It doesn''t make any sense. Why don''t they just fly Naxxramas over Wintergarde Keep and blow it up? I mean, that''s what I would do if I were Kel''Thuzad.', 12, 7, 100, 0, 0, 0, 26973, 0, '7th Legion Elite'),
(@ELITE, 1, 3, 'I wonder if we''ll ever solve the mystery of the strange ore. There''s gotta be some use for it!', 12, 0, 100, 0, 0, 0, 26974, 0, '7th Legion Elite'),
(@ELITE, 1, 4, 'Hey, do any of you know McGoyver over at Valgarde? He''s my uncle. You know what his title is? Pro. Yea, just "Pro." I want to be a pro too.', 12, 0, 100, 0, 0, 0, 26975, 0, '7th Legion Elite'),
(@ELITE, 1, 5, 'Something straight up stinks in here! It''s definitely not me. Gnomes smell like butter and sunshine. Not like those dwarves that smell like they were born from a trogg''s armpit! None of you are dwarves, are you?', 12, 0, 100, 0, 0, 0, 26976, 0, '7th Legion Elite'),
(@ELITE, 1, 6, 'I used to know a dwarf that claimed gnomes evolved from beneath the earth. That we all started out as sand gnomes. What a load of nonsense! Sand gnomes? PUH-LEASE!', 12, 0, 100, 0, 0, 0, 26977, 0, '7th Legion Elite'),
(@ELITE, 1, 7, 'I''ve never seen destruction like this...', 12, 0, 100, 0, 0, 0, 26978, 0, '7th Legion Elite'),
(@ELITE, 1, 8, 'Keep the chatter down, people. We need to stay alert!', 12, 0, 100, 0, 0, 0, 26979, 0, '7th Legion Elite'),
(@ELITE, 1, 9, 'The smell of death covers every inch of this place.', 12, 0, 100, 0, 0, 0, 26980, 0, '7th Legion Elite'),
(@ELITE, 1, 10, 'Driver, I hear you single handedly airlifted our villagers out of this hell-hole. Is that true?', 12, 0, 100, 0, 0, 0, 26981, 0, '7th Legion Elite'),
(@ELITE, 1, 11, 'So does anyone know anything about Thel''zan? Who is he? How did he come to leading the Scourge armies on the ground?', 12, 0, 100, 0, 0, 0, 26982, 0, '7th Legion Elite'),
(@ELITE, 1, 12, 'Look at this mess... The Scourge will pay for this!', 12, 0, 100, 0, 0, 0, 26983, 0, '7th Legion Elite'),
(@ELITE, 1, 13, 'Where are all the corpses? What have they done to our people?', 12, 0, 100, 0, 0, 0, 26984, 0, '7th Legion Elite'),
(@ELITE, 1, 14, 'I hope I''m alive to see Arthas get what''s coming to him.', 12, 0, 100, 0, 0, 0, 26985, 0, '7th Legion Elite'),
(@ELITE, 2, 0, 'Reporting for duty, sir!', 12, 7, 100, 0, 0, 0, 26954, 0, '7th Legion Elite'),
(@ENGI, 0, 1, 'Keep ''em off me for about 15 seconds and this thing is as good as dead.', 12, 7, 100, 0, 0, 0, 26854, 0, '7th Legion Siege Engineer'),
(@ENGI, 0, 2, 'Cover me!', 12, 7, 100, 0, 0, 0, 26852, 0, '7th Legion Siege Engineer'),
(@ENGI, 0, 3, 'When I''m done with this plague wagon it''ll look like a goblin built it! Keep me safe!', 12, 7, 100, 0, 0, 0, 26855, 0, '7th Legion Siege Engineer'),
(@ENGI, 0, 4, 'Keep the bad guys off me!', 12, 7, 100, 0, 0, 0, 26853, 0, '7th Legion Siege Engineer'),
(@ENGI, 1, 0, '%s deftly assembles a strange machine.', 16, 7, 100, 0, 0, 0, 26856, 0, '7th Legion Siege Engineer'),
(@ENGI, 2, 0, 'That oughta do it! Just a few more seconds now.', 12, 7, 100, 0, 0, 0, 26858, 0, '7th Legion Siege Engineer');
