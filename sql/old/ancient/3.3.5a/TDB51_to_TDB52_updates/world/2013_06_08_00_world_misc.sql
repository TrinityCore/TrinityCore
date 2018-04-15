-- Fix quest: Danger! Explosives! (11218)

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (23974,29881);
UPDATE `gameobject_template` SET `flags`=`flags`|4 WHERE `entry` IN (186403,186404,186466,186467,186468);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (186403,186470);

DELETE FROM `spell_area` WHERE `spell`=27769;
INSERT INTO `spell_area` (`spell`,`area`,`autocast`) VALUES
(27769,4071,1);

DELETE FROM `creature_text` WHERE `entry`=29881;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(29881,0,0,'They are coming for you.',15,0,100,0,0,14376,'An Unknown Voice'),
(29881,0,1,'Give into your fear.',15,0,100,0,0,14377,'An Unknown Voice'),
(29881,0,2,'Kill them all... before they kill you.',15,0,100,0,0,14378,'An Unknown Voice'),
(29881,0,3,'They have turned against you. Now... take your revenge.',15,0,100,0,0,14379,'An Unknown Voice'),
(29881,0,4,'Tell yourself again that these are not truly your friends.',15,0,100,0,0,14380,'An Unknown Voice'),
(29881,0,5,'There is no escape, Not in this life. Not in the next.',15,0,100,0,0,14381,'An Unknown Voice'),
(29881,0,6,'You are a pawn of forces unseen.',15,0,100,0,0,14382,'An Unknown Voice'),
(29881,0,7,'It WAS your fault.',15,0,100,0,0,14383,'An Unknown Voice');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23974,29881) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (186403,186470) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23974*100+0,23974*100+1,23974*100+2,23974*100+3,186403*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23974,0,0,0,8,0,100,0,42697,0,0,0,87,23974*100+0,23974*100+1,23974*100+2,23974*100+3,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore Bunny - On spellhit Spell Danger! Explosive!: Ore Trap - Run random script'),

(29881,0,0,0,8,0,100,0,29072,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'An Unknown Voice - On spellhit Whisper Gulch: Yogg-Saron Whisper Dummy - Say line'),

(186403,1,0,1,38,0,100,0,0,1,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore - On data 0 1 set - Set phasemask 2'),
(186403,1,1,0,61,0,100,0,0,0,0,0,80,186403*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore - On data 0 1 set - Run script'),

(186470,1,0,0,70,0,100,0,1,0,0,0,45,0,1,0,0,0,0,20,186403,5,0,0,0,0,0,'Whisper Gulch Ore Trap - On state changed - Set data 0 1 Whisper Gulch Ore'),

(23974*100+0,9,0,0,0,0,100,0,0,0,0,0,50,186404,120000,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore Bunny script 0 - Summon Whisper Gulch Gem'),
(23974*100+0,9,1,0,0,0,100,0,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore Bunny script 0 - Despawn'),
(23974*100+1,9,0,0,0,0,100,0,0,0,0,0,50,186466,120000,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore Bunny script 0 - Summon Whisper Gulch Gem'),
(23974*100+1,9,1,0,0,0,100,0,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore Bunny script 0 - Despawn'),
(23974*100+2,9,0,0,0,0,100,0,0,0,0,0,50,186467,120000,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore Bunny script 0 - Summon Whisper Gulch Gem'),
(23974*100+2,9,1,0,0,0,100,0,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore Bunny script 0 - Despawn'),
(23974*100+3,9,0,0,0,0,100,0,0,0,0,0,50,186468,120000,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore Bunny script 0 - Summon Whisper Gulch Ore Fragment'),
(23974*100+3,9,1,0,0,0,100,0,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore Bunny script 0 - Despawn'),

(186403*100,9,0,0,0,0,100,0,300000,300000,0,0,44,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Whisper Gulch Ore script - Set phasemask 1');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (29072,42697,42703);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,29072,0,0,31,0,3,29881,0,0,0,'','Spell Whisper Gulch: Yogg-Saron Whisper Dummy targets An Unknown Voice'),
(13,1,42697,0,0,31,0,3,23974,0,0,0,'','Spell Danger! Explosive!: Ore Trap targets Whisper Gulch Ore Bunny'),
(13,1,42703,0,0,31,0,5,186470,0,0,0,'','Spell Steelring''s Foolproof Dynamite effect0 targets Whisper Gulch Ore Trap');

DELETE FROM `spell_script_names` WHERE `spell_id`=27769;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(27769,'spell_gen_whisper_gulch_yogg_saron_whisper');
