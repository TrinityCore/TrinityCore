SET @ETHEREAL_TELEPORT  := 34427; -- Arete Teleport Animation
SET @ARETE              := 29560; -- LC Arete
SET @SUMMON_AERTE       := 18280; -- LC Arete Summon Spell
SET @LANDGREN           := 29542; -- Landgren
SET @LANDGRENS_SOUL     := 29572; -- Landgren's Soul
SET @SOUL_TARGET_BUNNY  := 29577; -- Target Bunny for the Soul
SET @CORPSE_SFOCUS      := 22965;  -- Spell focus for the corpse
SET @SOUL_COAX          := 22966;  -- Soul Coax Spell
SET @SOUL_MOVE          := 12601; -- Sould Move position
SET @SUMMON_SOUL        := 12600; -- Summon Landgren's Soul
SET @SOUL_WRACK         := 54723; -- Soul Wrack Spell
SET @ARCANE_EXP         := 35426; -- Arcane Explosion Visual
SET @SUMMON_GATE        := 26560; -- Summon Arete Gateway spell
SET @ARETE_GATE         := 191579; -- Arete Gateway Object
SET @LANDGREN_CORPSE    := 191578; -- Landgrens Corpse Object

UPDATE `gameobject_template` SET `faction`=114, `AIName`='SmartGameObjectAI' WHERE `entry`=@ARETE_GATE;
DELETE FROM `gameobject_template` WHERE `entry`=@LANDGREN_CORPSE;
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`data0`,`data1`,`data6`) VALUES
(@LANDGREN_CORPSE,8,0,'Archbishop Landgren''s Corpse',1566,20,0);

UPDATE `creature_template` SET `npcflag`=2, `unit_flags`=33280 WHERE `entry`=@ARETE;
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14, `speed_walk`=0.4, `unit_flags`=256, `dynamicflags`=32 WHERE `entry`=@LANDGRENS_SOUL;
UPDATE `creature_template` SET `unit_flags`=33555200, `flags_extra`=`flags_extra`|128  WHERE `entry`=@SOUL_TARGET_BUNNY;

UPDATE `creature_model_info` SET `bounding_radius`=0.5745, `combat_reach`=2.25 WHERE `modelid`=26197;
UPDATE `creature_model_info` SET `bounding_radius`=0.3825, `combat_reach`=1.875 WHERE `modelid`=26346;

DELETE FROM `creature_template_addon` WHERE `entry`=@LANDGRENS_SOUL;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`emote`,`auras`) VALUES
(@LANDGRENS_SOUL,1,0,'36545 36550'); -- Float Aura for Landgren's Soul

DELETE FROM `creature_text` WHERE `entry` IN (@ARETE,@LANDGRENS_SOUL);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ARETE,0,0,'Well done. Let''s get this over with.',12,0,100,1,0,0,''),
(@ARETE,1,0,'Come, Landgren, cough up your soul so that I can ask you a very important question.',12,0,100,0,0,0,''),
(@ARETE,2,0,'YOU WILL TELL ME WHERE WESTWIND IS OR I WILL DESTROY YOUR SOUL!',14,0,100,25,0,0,''),
(@ARETE,3,0,'Then you leave me no choice. I won''t say that I won''t enjoy this.',12,0,100,1,0,0,''),
(@ARETE,4,0,'Very well. Tell me!',12,0,100,0,0,0,''),
(@ARETE,5,0,'A hidden hollow? How very interesting. You''ve served your purpose, Landgren, but I''m afraid there''ll be no resurrection for you this time!',12,0,100,6,0,0,''),
(@ARETE,6,0,'Now that the unpleasantness is finished with, let''s talk about you dealing with Grand Admiral Westwind.',12,0,100,11,0,0,''),

(@LANDGRENS_SOUL,0,0,'You''ll get nothing out of me, monster. I am beyond your ability to influence.',12,0,100,0,0,0,''),
(@LANDGRENS_SOUL,1,0,'No.',12,0,100,0,0,0,''),
(@LANDGRENS_SOUL,2,0,'STOP! It isn''t worth it. I''ll tell you where he is.',12,0,100,0,0,0,''),
(@LANDGRENS_SOUL,3,0,'On the south end of the island is a cave -- a hidden hollow. The grand admiral has holed himself up in there, preparing for the final battle against the Lich King.',12,0,100,0,0,0,''),
(@LANDGRENS_SOUL,4,0,'AAAEEEEIIIiiiiiiiiiiiiiiiiiiiiiiiiiiii........................................',14,0,100,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@SOUL_COAX,@SUMMON_GATE);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SOUL_COAX,0,0,31,0,3,@LANDGREN,0,0,0,'','Spell Soul Coax targets Archbishop Landgren'),
(13,2,@SUMMON_GATE,0,0,31,0,3,@LANDGREN,0,0,0,'','Spell Summon Arete''s Gate effect1 targets Archbishop Landgren');

UPDATE `creature_template` SET AIName='SmartAI' WHERE entry=@SOUL_TARGET_BUNNY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SOUL_TARGET_BUNNY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@SOUL_TARGET_BUNNY,0,0,0,54,0,100,0,0,0,0,0,69,0,0,0,0,0,0,19,@LANDGREN,20,0,0,0,59.057,0,'Spell Focus Bunny - Just summoned - Move to position');


UPDATE `creature_template` SET AIName='SmartAI' WHERE entry IN (@LANDGREN,@ARETE,@LANDGRENS_SOUL);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@LANDGREN,@ARETE,@LANDGRENS_SOUL) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ARETE_GATE AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ARETE_GATE*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ARETE*100,@LANDGRENS_SOUL*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@LANDGREN,0,0,0,4,0,100,0,0,0,0,0,42,0,1,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On Aggro - Set invincibility 1HP'),
(@LANDGREN,0,1,2,2,0,100,1,0,1,0,0,11,@CORPSE_SFOCUS,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On health below 0.1% - Spellcast Summon Archbishop Landgren''s Corpse Spell Focus'),
(@LANDGREN,0,2,3,61,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On health below 0.1% - Add unit field byte1 Death'),
(@LANDGREN,0,3,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On Link - Forbid Attack'),
(@LANDGREN,0,4,0,8,0,100,0,@SUMMON_GATE,0,0,0,45,0,1,0,0,0,0,20,@ARETE_GATE,20,0,0,0,0,0,'Archbishop Landgren - On spellhit Summon Arete''s Gate - Set data 0 1 Arete''s Gate'),
(@LANDGREN,0,5,0,8,0,100,0,@SOUL_COAX,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On spellhit Soul Coax - Set event phase 1'),
(@LANDGREN,0,6,7,23,1,100,1,@SOUL_COAX,0,0,0,11,@SOUL_MOVE,2,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On spellfade Soul Coax (phase 1) - Spellcast Summon Landgren''s Soul Moveto Target Bunny'),
(@LANDGREN,0,7,8,61,1,100,0,0,0,0,0,11,@SUMMON_SOUL,2,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On spellfade Soul Coax (phase 1) - Spellcast Summon Landgren''s Soul'),
(@LANDGREN,0,8,0,61,1,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On Link - Die'),
(@LANDGREN,0,9,10,11,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On Respawn - Remove unit field byte1 Death'),
(@LANDGREN,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archbishop Landgren - On Respawn - Allow Attack'),


(@ARETE,0,0,1,54,0,100,0,0,0,0,0,11,@ETHEREAL_TELEPORT,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete - Just summoned - Spellcast Ethereal Teleport'),
(@ARETE,0,1,2,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@LANDGREN,20,0,0,0,0,0,'Lord-Commander Arete - Just summoned - Turn to Archbishop Landgren'),
(@ARETE,0,2,3,61,0,100,0,0,0,0,0,41,300000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete - On Link - Despawn after timer'),
(@ARETE,0,3,0,61,0,100,0,0,0,0,0,80,@ARETE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete - Just summoned - Run script'),

(@LANDGRENS_SOUL,0,0,0,54,0,100,0,0,0,0,0,80,@LANDGRENS_SOUL*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul - Just summoned - Run script'),


(@ARETE_GATE,1,0,1,38,0,100,0,0,1,0,0,80,@ARETE_GATE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Arete''s Gateway - On Data Set - Start Action Script'),
(@ARETE_GATE,1,1,0,61,0,100,0,0,0,0,0,41,300000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arete''s Gateway - On Link - Despawn after timer'),
(@ARETE_GATE*100,9,0,0,0,0,100,0,4000,4000,0,0,11,@SUMMON_ARETE,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arete''s Gateway - On Script - Spellcast Summon Arete'),

(@ARETE*100,9,0,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@ARETE*100,9,1,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,19,@LANDGREN,20,0,0,0,0,0,'Lord-Commander Arete script - Turn to Archbishop Landgren'),
(@ARETE*100,9,2,0,0,0,100,0,1000,1000,0,0,11,@SOUL_COAX,0,0,0,0,0,19,@LANDGREN,20,0,0,0,0,0,'Lord-Commander Arete script - Spellcast Soul Coax'),
(@ARETE*100,9,3,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@ARETE*100,9,4,0,0,0,100,0,20000,20000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@ARETE*100,9,5,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@ARETE*100,9,6,0,0,0,100,0,4000,4000,0,0,11,27765,0,0,0,0,0,19,@LANDGRENS_SOUL,20,0,0,0,0,0,'Lord-Commander Arete script - Spellcast Soul Wrack'), 
(@ARETE*100,9,7,0,0,0,100,0,15000,15000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'), 
(@ARETE*100,9,8,0,0,0,100,0,0,0,0,0,92,0,27765,1,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Interrupt spellcast'),
(@ARETE*100,9,9,0,0,0,100,0,10000,10000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@ARETE*100,9,10,0,0,0,100,0,4000,4000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Play emote'), 
(@ARETE*100,9,11,0,0,0,100,0,4000,4000,0,0,11,@SOUL_WRACK,0,0,0,0,0,19,@LANDGRENS_SOUL,20,0,0,0,0,0,'Lord-Commander Arete script - Spellcast Soul Wrack'), -- 18
(@ARETE*100,9,12,0,0,0,100,0,8000,8000,0,0,92,0,@SOUL_WRACK,1,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Interrupt spellcast'),
(@ARETE*100,9,13,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Say line'),
(@ARETE*100,9,14,0,0,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord-Commander Arete script - Set npcflag questgiver'),

(@LANDGRENS_SOUL*100,9,0,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,19,@ARETE,20,0,0,0,0,0,'Landgren''s Soul script - Turn to Lord-Commander Arete'),
(@LANDGRENS_SOUL*100,9,1,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Say line'), 
(@LANDGRENS_SOUL*100,9,2,0,0,0,100,0,10000,10000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Say line'), 
(@LANDGRENS_SOUL*100,9,3,0,0,0,100,0,15000,15000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Say line'),
(@LANDGRENS_SOUL*100,9,4,0,0,0,100,0,10000,10000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Say line'),
(@LANDGRENS_SOUL*100,9,5,0,0,0,100,0,16000,16000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Say line'), 
(@LANDGRENS_SOUL*100,9,6,0,0,0,100,0,5000,5000,0,0,11,@ARCANE_EXP,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Spellcast Arcane Explosion Visual'), 
(@LANDGRENS_SOUL*100,9,7,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Landgren''s Soul script - Despawn');
