SET @NPC_LANDGREN := 29542;
SET @NPC_ARETE    := 29560;
SET @NPC_SOUL     := 29572;
SET @NPC_SOUL_TARGET := 29577;
SET @GO_FOCUS      := 191578;
SET @GO_GATE      := 191579;

UPDATE `gameobject_template` SET `faction`=114, `AIName`='SmartGameObjectAI' WHERE `entry`=@GO_GATE;
DELETE FROM `gameobject_template` WHERE `entry`=@GO_FOCUS;
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`data0`,`data1`,`data6`,`AIName`) VALUES
(@GO_FOCUS,8,0,'Archbishop Landgren''s Corpse',1566,20,0,'SmartGameObjectAI');

UPDATE `creature_template` SET `npcflag`=2, `unit_flags`=33280 WHERE `entry`=@NPC_ARETE;
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14, `speed_walk`=0.4, `unit_flags`=256, `dynamicflags`=0, `InhabitType`=4 WHERE `entry`=@NPC_SOUL;
UPDATE `creature_template` SET `unit_flags`=33555200, `InhabitType`=4 WHERE `entry`=@NPC_SOUL_TARGET;

UPDATE `creature_model_info` SET `bounding_radius`=0.5745, `combat_reach`=2.25 WHERE `modelid`=26197;
UPDATE `creature_model_info` SET `bounding_radius`=0.3825, `combat_reach`=1.875 WHERE `modelid`=26346;

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_SOUL;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`emote`,`auras`) VALUES
(@NPC_SOUL,1,0,'36545');

DELETE FROM `creature_equip_template` WHERE `entry`=@NPC_ARETE;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@NPC_ARETE,1,40276,0,0);

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_LANDGREN,@NPC_ARETE,@NPC_SOUL);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_LANDGREN,0,0,'I will not die so quickly this time!',14,0,100,0,0,0,''),

(@NPC_ARETE,0,0,'Well done. Let''s get this over with.',12,0,100,1,0,0,''),
(@NPC_ARETE,1,0,'Come, Landgren, cough up your soul so that I can ask you a very important question.',12,0,100,0,0,0,''),
(@NPC_ARETE,2,0,'YOU WILL TELL ME WHERE WESTWIND IS OR I WILL DESTROY YOUR SOUL!',14,0,100,25,0,0,''),
(@NPC_ARETE,3,0,'Then you leave me no choice. I won''t say that I won''t enjoy this.',12,0,100,1,0,0,''),
(@NPC_ARETE,4,0,'Very well. Tell me!',12,0,100,0,0,0,''),
(@NPC_ARETE,5,0,'A hidden hollow? How very interesting. You''ve served your purpose, Landgren, but I''m afraid there''ll be no resurrection for you this time!',12,0,100,6,0,0,''),
(@NPC_ARETE,6,0,'Now that the unpleasantness is finished with, let''s talk about you dealing with Grand Admiral Westwind.',12,0,100,11,0,0,''),

(@NPC_SOUL,0,0,'You''ll get nothing out of me, monster. I am beyond your ability to influence.',12,0,100,0,0,0,''),
(@NPC_SOUL,1,0,'No.',12,0,100,0,0,0,''),
(@NPC_SOUL,2,0,'STOP! It isn''t worth it. I''ll tell you where he is.',12,0,100,0,0,0,''),
(@NPC_SOUL,3,0,'On the south end of the island is a cave -- a hidden hollow. The grand admiral has holed himself up in there, preparing for the final battle against the Lich King.',12,0,100,0,0,0,''),
(@NPC_SOUL,4,0,'AAAEEEEIIIiiiiiiiiiiiiiiiiiiiiiiiiiiii........................................',14,0,100,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (22966,26560);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,22966,0,0,31,0,3,@NPC_LANDGREN,0,0,0,'','Spell Soul Coax targets Archbishop Landgren'),
(13,2,26560,0,0,31,0,3,@NPC_LANDGREN,0,0,0,'','Spell Summon Arete''s Gate effect1 targets Archbishop Landgren');

DELETE FROM `spell_script_names` WHERE `spell_id`=12601;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(12601,'spell_q12847_summon_soul_moveto_bunny');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_LANDGREN,@NPC_ARETE,@NPC_SOUL);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_LANDGREN,@NPC_ARETE,@NPC_SOUL) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GO_FOCUS,@GO_GATE) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_LANDGREN*100,@NPC_ARETE*100,@NPC_SOUL*100,@GO_GATE*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_LANDGREN,0,0,0,25,0,100,0,0,0,0,0,28,60449,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On reset - Remove aura Shadowform'),
(@NPC_LANDGREN,0,1,0,0,0,100,0,10000,12000,9000,10000,11,60453,0,0,0,0,0,2,0,0,0,0,0,0,0,'Archbishop Landgren - On update IC - Spellcast Mind Blast'),
(@NPC_LANDGREN,0,2,0,0,0,100,0,15000,16000,18000,20000,11,60446,0,0,0,0,0,2,0,0,0,0,0,0,0,'Archbishop Landgren - On update IC - Spellcast Shadow Word: Pain'),
(@NPC_LANDGREN,0,3,0,0,0,100,0,30000,35000,35000,40000,11,60440,0,0,0,0,0,2,0,0,0,0,0,0,0,'Archbishop Landgren - On update IC - Spellcast Mind Sear'),
(@NPC_LANDGREN,0,4,5,2,0,100,1,0,50,0,0,11,60449,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On health below 50% - Spellcast Shadowform'),
(@NPC_LANDGREN,0,5,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On health below 50% - Say line'),
(@NPC_LANDGREN,0,6,0,6,0,100,0,0,0,0,0,11,22965,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On death - Spellcast Summon Archbishop Landgren''s Corpse Spell Focus'),
(@NPC_LANDGREN,0,7,8,8,0,100,0,26560,0,0,0,45,0,1,0,0,0,0,20,@GO_GATE,50,0,0,0,0,0,'Archbishop Landgren - On spellhit Summon Arete''s Gate - Set data 0 1 Arete''s Gate'),
(@NPC_LANDGREN,0,8,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,20,@GO_FOCUS,5,0,0,0,0,0,'Archbishop Landgren - On spellhit Summon Arete''s Gate - Set data 0 1 Arete''s Gate'),
(@NPC_LANDGREN,0,9,10,38,0,100,0,0,1,0,0,11,12601,2,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On data 0 1 set - Spellcast Summon Landgren''s Soul Moveto Target Bunny'),
(@NPC_LANDGREN,0,10,0,61,0,100,0,0,0,0,0,11,12600,2,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On data 0 1 set - Spellcast Summon Landgren''s Soul'),

(@NPC_ARETE,0,0,1,1,0,100,1,0,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete - Just summoned - Spellcast Ethereal Teleport'),
(@NPC_ARETE,0,1,2,61,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete - Just summoned - Remove npcflag questgiver'),
(@NPC_ARETE,0,2,3,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@NPC_LANDGREN,20,0,0,0,0,0,'Lord-Commander Arete - Just summoned - Turn to Archbishop Landgren'),
(@NPC_ARETE,0,3,0,61,0,100,0,0,0,0,0,80,@NPC_ARETE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete - Just summoned - Run script'),

(@NPC_SOUL,0,0,0,54,0,100,0,0,0,0,0,80,@NPC_SOUL*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul - Just summoned - Run script'),

(@GO_FOCUS,1,0,0,38,0,100,0,0,1,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren''s Corpse Spell Focus - On data 0 1 set - Set phase 2'),

(@GO_GATE,1,0,0,38,0,100,0,0,1,0,0,80,@GO_GATE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Arete''s Gateway - On data 0 1 set - Run script'),

(@GO_GATE*100,9,0,0,0,0,100,0,4000,4000,0,0,11,18280,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arete''s Gateway script - Spellcast Summon Arete'),
(@GO_GATE*100,9,1,0,0,0,100,0,180000,180000,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arete''s Gateway script - Set phase 2'),

(@NPC_ARETE*100,9,0,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@NPC_ARETE*100,9,1,0,0,0,100,0,0,0,0,0,46,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Move forward'),
(@NPC_ARETE*100,9,2,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,19,@NPC_LANDGREN,20,0,0,0,0,0,'Lord-Commander Arete script - Turn to Archbishop Landgren'),
(@NPC_ARETE*100,9,3,0,0,0,100,0,1000,1000,0,0,11,22966,0,0,0,0,0,19,@NPC_LANDGREN,20,1,0,0,0,0,'Lord-Commander Arete script - Spellcast Soul Coax'),
(@NPC_ARETE*100,9,4,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@NPC_ARETE*100,9,5,0,0,0,100,0,8000,8000,0,0,45,0,1,0,0,0,0,19,@NPC_LANDGREN,20,1,0,0,0,0,'Lord-Commander Arete script - Set data 0 1 Archbishop Landgren'),
(@NPC_ARETE*100,9,6,0,0,0,100,0,12000,12000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@NPC_ARETE*100,9,7,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@NPC_ARETE*100,9,8,0,0,0,100,0,4000,4000,0,0,11,27765,0,0,0,0,0,19,@NPC_SOUL,20,0,0,0,0,0,'Lord-Commander Arete script - Spellcast Soul Wrack'),
(@NPC_ARETE*100,9,9,0,0,0,100,0,15000,15000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@NPC_ARETE*100,9,10,0,0,0,100,0,0,0,0,0,92,0,27765,1,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Interrupt spellcast'),
(@NPC_ARETE*100,9,11,0,0,0,100,0,10000,10000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@NPC_ARETE*100,9,12,0,0,0,100,0,4000,4000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Play emote'),
(@NPC_ARETE*100,9,13,0,0,0,100,0,4000,4000,0,0,11,54723,0,0,0,0,0,19,@NPC_SOUL,20,0,0,0,0,0,'Lord-Commander Arete script - Spellcast Soul Wrack'),
(@NPC_ARETE*100,9,14,0,0,0,100,0,8000,8000,0,0,92,0,54723,1,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Interrupt spellcast'),
(@NPC_ARETE*100,9,15,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@NPC_ARETE*100,9,16,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Set npcflag questgiver'),
(@NPC_ARETE*100,9,17,0,0,0,100,0,98000,98000,0,0,69,0,0,0,0,0,0,20,@GO_GATE,10,0,0,0,0,0,'Lord-Commander Arete script - Move to position'),
(@NPC_ARETE*100,9,18,0,0,0,100,0,2000,2000,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Spellcast Ethereal Teleport'),
(@NPC_ARETE*100,9,19,0,0,0,100,0,500,500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Despawn'),

(@NPC_SOUL*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@NPC_ARETE,20,0,0,0,0,0,'Landgren''s Soul script - Turn to Lord-Commander Arete'),
(@NPC_SOUL*100,9,1,0,0,0,100,0,500,500,0,0,11,36545,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Spellcast Floating Drowned'),
(@NPC_SOUL*100,9,2,0,0,0,100,0,6500,6500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Say line'),
(@NPC_SOUL*100,9,3,0,0,0,100,0,10000,10000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Say line'),
(@NPC_SOUL*100,9,4,0,0,0,100,0,15000,15000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Say line'),
(@NPC_SOUL*100,9,5,0,0,0,100,0,10000,10000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Say line'),
(@NPC_SOUL*100,9,6,0,0,0,100,0,16000,16000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Say line'),
(@NPC_SOUL*100,9,7,0,0,0,100,0,5000,5000,0,0,11,35426,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Spellcast Arcane Explosion Visual'),
(@NPC_SOUL*100,9,8,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Despawn');
