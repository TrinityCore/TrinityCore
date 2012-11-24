-- Make Dame Evniki Kapsalis show vendor gossip option only to players with Crusader title
UPDATE `creature_template` SET `AIName` = 'SmartAI',`ScriptName` = '' WHERE `entry` = 34885;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10598;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`COMMENT`) VALUES
(15,10598,0,0,17,2816,0,0,0,'',"Evniki Kapsalis should only sell to Crusaders"),
(15,10598,0,1,17,2817,0,0,0,'',"Evniki Kapsalis should only sell to Crusaders");

SET @SPELL_CHAIN          = 68341;
SET @NPC_FJOLA_LIGHTBANE  = 36065;
SET @NPC_EYDIS_DARKBANE   = 36066;
SET @NPC_PRIESTESS_ALORAH = 36101;
SET @NPC_PRIEST_GRIMMIN   = 36102;

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN(@NPC_PRIESTESS_ALORAH,@NPC_PRIEST_GRIMMIN);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN(@NPC_PRIESTESS_ALORAH,@NPC_PRIEST_GRIMMIN) AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_PRIESTESS_ALORAH,0,0,0,1,0,100,1,100,100,0,0,11,@SPELL_CHAIN,0,0,0,0,0,19,@NPC_EYDIS_DARKBANE,0,0,0,0,0,0,'Priestess Alorah - Cast chain on Eydis Darkbane'),
(@NPC_PRIEST_GRIMMIN,0,0,0,1,0,100,1,100,100,0,0,11,@SPELL_CHAIN,0,0,0,0,0,19,@NPC_FJOLA_LIGHTBANE,0,0,0,0,0,0,'Priestess Grimmin - Cast chain on Fjola Lightbane');
