-- On Ruby Wings (12498)

SET @QUEST                              := 12498;
SET @NPC_WYRMREST_VANQUISHER            := 27996; -- Wyrmrest Vanquisher
SET @NPC_THIASSI_THE_LIGHNTNING_BRINGER := 28018; -- Thiassi the Lightning Bringer
SET @NPC_GRAND_NECROLORD_ANTIOK         := 28006; -- Grand Necrolord Antiok
SET @NPC_WASTES_SCAVENGER               := 28005; -- Wastes Scavenger
SET @SPELL_DEVOUR_GHOUL                 := 50430; -- Devour Ghoul
SET @SPELL_ENGULFING_FIREBALL           := 55987; -- Engulfing Fireball
SET @SPELL_FLAME_FURY                   := 50348; -- Flame Fury
SET @SPELL_MOUNT                        := 50343; -- Controlling Wyrmrest Vanquisher
SET @ITEM_SCYTHE_OF_ANTIOK              := 38305; -- Item Scythe of Antiok

UPDATE `creature_template` SET npcflag=16777216, `spell1`=@SPELL_FLAME_FURY, `spell2`=@SPELL_ENGULFING_FIREBALL, `spell3`=@SPELL_DEVOUR_GHOUL, `InhabitType`=4 WHERE `entry`=@NPC_WYRMREST_VANQUISHER;

DELETE FROM `npc_spellclick_spells` WHERE npc_entry IN (@NPC_WYRMREST_VANQUISHER);
INSERT INTO `npc_spellclick_spells` VALUES (@NPC_WYRMREST_VANQUISHER, @SPELL_MOUNT, 1, 0);

DELETE FROM `creature_template_addon` WHERE `entry` in (@NPC_WYRMREST_VANQUISHER, @NPC_GRAND_NECROLORD_ANTIOK);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC_WYRMREST_VANQUISHER,0,0,50331648,0,0,'50345'),
(@NPC_GRAND_NECROLORD_ANTIOK,0,0,0,0,0,'50494');

UPDATE vehicle_template_accessory set minion=0,`summontype`=1 where entry=@NPC_THIASSI_THE_LIGHNTNING_BRINGER; 

Delete from creature_loot_template where entry =@NPC_GRAND_NECROLORD_ANTIOK and item=@ITEM_SCYTHE_OF_ANTIOK;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_FLAME_FURY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_FLAME_FURY,0,1,31,0,3,@NPC_WASTES_SCAVENGER,0,0,0,0,'','Flame Fury can only Hit Wastes Scavenger');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=55988;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 55988, 0, 2, 31, 0, 3, 26493, 0, 0, 0, 0, '', 'Engulfing Fireball targets Wastes Task Manager'),
(13, 1, 55988, 0, 1, 31, 0, 3, 26492, 0, 0, 0, 0, '', 'Engulfing Fireball targets Wastes Digger'),
(13, 1, 55988, 0, 0, 31, 0, 3, 28005, 0, 0, 0, 0, '', 'Engulfing Fireball targets Wastes Scavenger'),
(13, 2, 55988, 0, 0, 31, 0, 3, 27270, 0, 0, 0, 0, '', 'Engulfing Fireball targets Rotting Storm Giant'),
(13, 2, 55988, 0, 1, 31, 0, 3, 28018, 0, 0, 0, 0, '', 'Engulfing Fireball targets Thiassi');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (50430,50443);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,50430,0,0,31,0,3,28005,0,0,0,0,'','Devour Ghoul targets Wastes Scavenger'),
(13,3,50443,0,0,31,0,3,27996,0,0,0,0,'','Nourishment targets Wyrmrest Vanquisher');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`in (16,17) AND `SourceEntry` IN (27996,50426);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(16, 0, 27996, 0, 0, 23, 0, 4161, 0, 0, 0, 0, 0, '', 'Wyrmrest Vanquisher allowed in Wyrmrest Temple'),
(16, 0, 27996, 0, 4, 23, 0, 4184, 0, 0, 0, 0, 0, '', 'Wyrmrest Vanquisher allowed in Path of the Titans'),
(16, 0, 27996, 0, 3, 23, 0, 4174, 0, 0, 0, 0, 0, '', 'Wyrmrest Vanquisher allowed in The Wicked Coil'),
(16, 0, 27996, 0, 2, 23, 0, 4173, 0, 0, 0, 0, 0, '', 'Wyrmrest Vanquisher allowed in Galakronds Rest'),
(16, 0, 27996, 0, 1, 23, 0, 4254, 0, 0, 0, 0, 0, '', 'Wyrmrest Vanquisher allowed in The Dragon Wastes'),
(17, 0, 50426, 0, 3, 23, 0, 4174, 0, 0, 0, 0, 0, '', 'Wyrmrest Vanquisher can be summoned  in The Wicked Coil'),
(17, 0, 50426, 0, 2, 23, 0, 4173, 0, 0, 0, 0, 0, '', 'Wyrmrest Vanquisher can be summoned  in Galakronds Rest'),
(17, 0, 50426, 0, 1, 23, 0, 4254, 0, 0, 0, 0, 0, '', 'Wyrmrest Vanquisher can be summoned in The Dragon Wastes'),
(17, 0, 50426, 0, 0, 23, 0, 4161, 0, 0, 0, 0, 0, '', 'Wyrmrest Vanquisher can be summoned in Wyrmrest Temple');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=5 and `SourceEntry`=@NPC_WYRMREST_VANQUISHER;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,5,@NPC_WYRMREST_VANQUISHER,0,9,12498,0,0,0,'','event require quest taken to prevent despawn when the spell devour ghoul is casted'),
(22,5,@NPC_WYRMREST_VANQUISHER,1,28,12498,0,0,0,'','event require quest complete to prevent despawn when the spell devour ghoul is casted');

UPDATE creature_template SET AIName='SmartAI' WHERE entry IN (@NPC_GRAND_NECROLORD_ANTIOK, @NPC_THIASSI_THE_LIGHNTNING_BRINGER, @NPC_WYRMREST_VANQUISHER);
DELETE FROM smart_scripts WHERE entryorguid = @NPC_GRAND_NECROLORD_ANTIOK and source_type=0;
DELETE FROM smart_scripts WHERE entryorguid = @NPC_THIASSI_THE_LIGHNTNING_BRINGER and source_type=0;
DELETE FROM smart_scripts WHERE entryorguid = @NPC_WYRMREST_VANQUISHER and source_type=0;
DELETE FROM smart_scripts WHERE entryorguid = @NPC_WYRMREST_VANQUISHER*100 and source_type=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28005 and source_type=0 and id=14; -- (there is already a script for this npc id=0 to id=13) 
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28005*100 and source_type=9;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES

(@NPC_GRAND_NECROLORD_ANTIOK, 0, 0, 0, 0, 0, 100, 0, 7000, 7000, 18000, 18000, 11, 32863, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Nekrolord Antiok - IC - Cast Demon Seed'),
(@NPC_GRAND_NECROLORD_ANTIOK, 0, 1, 0, 0, 0, 100, 0, 1100, 1100, 20000, 20000, 11, 50455, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Nekrolord Antiok - IC - Cast Shadow Bolt'),
(@NPC_GRAND_NECROLORD_ANTIOK, 0, 2, 0, 1, 0, 100, 0, 10000, 10000, 40000, 40000, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nekrolord Antiok - OOC - Random Yell'),
(@NPC_GRAND_NECROLORD_ANTIOK, 0, 3, 0, 2, 0, 100, 1, 0, 25, 0, 0, 11, 50497, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Nekrolord Antiok - HP under 25% - Cast Scream of Chaos'),
(@NPC_GRAND_NECROLORD_ANTIOK, 0, 4, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 50472, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nekrolord Antiok - On Death - Cast Drop Scythe of Antiok'),
(@NPC_GRAND_NECROLORD_ANTIOK, 0, 5, 7, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nekrolord Antiok - On Aggro - Yell'),
(@NPC_GRAND_NECROLORD_ANTIOK, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 55984, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Nekrolord Antiok - On Aggro - Cast Shadow Bolt'),
(@NPC_GRAND_NECROLORD_ANTIOK, 0, 7, 8, 4, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 19, @NPC_WYRMREST_VANQUISHER, 20, 0, 0, 0, 0, 0, 'Nekrolord Antiok - On Aggro - kill WYRMREST'),
(@NPC_GRAND_NECROLORD_ANTIOK, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 50494, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nekrolord Antiok - On Aggro - remove aura'),

(@NPC_THIASSI_THE_LIGHNTNING_BRINGER, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 12000, 14000, 11, 50456, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thiassi the Lightning Bringer - IC - Cast Thiassi''s Stormbolt'),
(@NPC_THIASSI_THE_LIGHNTNING_BRINGER, 0, 1, 0, 0, 0, 100, 0, 9000, 9000, 15000, 19000, 11, 15593, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thiassi the Lightning Bringer - IC - Cast War Stomp'),
(@NPC_THIASSI_THE_LIGHNTNING_BRINGER, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 19, 2146959359, 0, 0, 0, 0, 0, 19, @NPC_GRAND_NECROLORD_ANTIOK, 10, 0, 0, 0, 0, 0, 'Thiassi the Lightning Bringer - On Death - remove unitflag from target'),

(@NPC_WYRMREST_VANQUISHER, 0, 0, 0, 1, 0, 100, 0, 9000, 9000, 30000, 30000, 1, 0, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'WYRMREST VANQUISHER - OOC - Random talk'),
(@NPC_WYRMREST_VANQUISHER, 0, 1, 0, 2, 0, 100, 1, 0, 33, 0, 0, 1, 1, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'WYRMREST VANQUISHER - HP under 33% - talk'),
(@NPC_WYRMREST_VANQUISHER, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'WYRMREST VANQUISHER - Just summoned - react passif'),
(@NPC_WYRMREST_VANQUISHER, 0, 4, 0, 28, 0, 100, 0, 0, 0, 0, 0, 80, @NPC_WYRMREST_VANQUISHER*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'WYRMREST VANQUISHER - PASSENGER_REMOVED - Actionlist'),
(@NPC_WYRMREST_VANQUISHER*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'WYRMREST VANQUISHER - ActionList - talk'),
(@NPC_WYRMREST_VANQUISHER*100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'WYRMREST VANQUISHER - ActionList - despawn'),


(28005, 0, 14, 0, 8, 0, 100, 0, 50430, 0, 0, 0, 80, 28005*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wastes Scavenger - On spellhit Devour Ghoul - Run script'),
(28005*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 50437, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wastes Scavenger script - Spellcast Devour Ghoul'),
(28005*100, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 50443, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wastes Scavenger script - Spellcast Nourishment'),
(28005*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wastes Scavenger script - Despawn');

DELETE FROM creature_text WHERE entry in (@NPC_GRAND_NECROLORD_ANTIOK, @NPC_WYRMREST_VANQUISHER);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@NPC_GRAND_NECROLORD_ANTIOK,0,0,'You think you''ve won, mortal? Face the unbridled power of Antiok!',14,0,100,0,0,0,'Antiok Yell1',27415),
(@NPC_GRAND_NECROLORD_ANTIOK,0,1,'Behold! The Scythe of Antiok!',14,0,100,0,0,0,'Antiok Yell2', 27416),
(@NPC_GRAND_NECROLORD_ANTIOK,1,0,'Soon, the bones of Galakrond will rise from their eternal slumber and wreak havoc upon this world!',14,0,100,0,0,0,'Antiok Yell3', 27406),
(@NPC_GRAND_NECROLORD_ANTIOK,1,1,'The Lich King demands more frost wyrms be sent to Angrathar! Meet his demands or face my wrath!',14,0,100,0,0,0,'Antiok Yell4', 27408),
(@NPC_GRAND_NECROLORD_ANTIOK,1,2,'Faster, dogs! We mustn''t relent in our assault against the interlopers!',14,0,100,0,0,0,'Antiok Yell5', 27405),
(@NPC_GRAND_NECROLORD_ANTIOK,1,3,'Attackers are upon us! Let none through to this ancient grave!',14,0,100,0,0,0,'Antiok Yell6', 27409),
(@NPC_GRAND_NECROLORD_ANTIOK,1,4,'Hear me, minions! Hear your lord, Antiok! Double your efforts or pay the consequences of failure!',14,0,100,0,0,0,'Antiok Yell7', 27407),
(@NPC_WYRMREST_VANQUISHER,0,1,'Across this vast expanse rest the bones of my ancestors. Their spirits have ascended to the Chamber of the Aspects.',12,0,100,0,0,0,'WYRMREST VANQUISHER', 27394),
(@NPC_WYRMREST_VANQUISHER,0,2,'Galakrond was the progenitor of dragonkind. It was from Galakrond that the Titans shaped the five Aspects.',12,0,100,0,0,0,'WYRMREST VANQUISHER', 27396),
(@NPC_WYRMREST_VANQUISHER,0,3,'It truly is a shame that the blue dragonflight has chosen such a heartless, cold path. It pains me greatly to do battle with Malygos''s children.',12,0,100,0,0,0,'WYRMREST VANQUISHER', 27400),
(@NPC_WYRMREST_VANQUISHER,0,4,'The queen and her council have been speaking lately of a disaster at Ulduar. Something has happened in Storm Peaks!',12,0,100,0,0,0,'WYRMREST VANQUISHER', 27399),
(@NPC_WYRMREST_VANQUISHER,0,5,'Today is a good day, friend. Long has it been since I have left Wyrmrest Temple, free to fly across the great Dragonblight.',12,0,100,0,0,0,'WYRMREST VANQUISHER', 27398),
(@NPC_WYRMREST_VANQUISHER,0,6,'What the Scourge has done here will reverberate throughout our world. The aberrations must be stopped!',12,0,100,0,0,0,'WYRMREST VANQUISHER', 27395),
(@NPC_WYRMREST_VANQUISHER,1,0,'You must remember that I have yet to mature into an elder wyrm. I must eat to renew my strength!',12,0,100,0,0,0,'WYRMREST VANQUISHER', 27397),
(@NPC_WYRMREST_VANQUISHER,2,0,'I have been called back to Wyrmrest, ally. Farewell!',12,0,100,0,0,0,'WYRMREST VANQUISHER', 27404);

UPDATE `creature` SET `equipment_id`=0 WHERE  `guid` IN(74522,74523,74524);
