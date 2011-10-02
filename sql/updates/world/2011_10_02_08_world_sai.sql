-- Fix quest 12166: The Liquid Fire Of Elune
SET @SPELL := 46770;
SET @VISUAL := 47972;
SET @ITEM := 36956;
SET @ELK := 26616;
SET @GRIZZLY := 26643;
SET @ELKDUMMY = 27111;
SET @GRIZZLYDUMMY = 27112;
 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ELK, @GRIZZLY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ELK,@GRIZZLY) AND `source_type`=0;
DELETE FROM `creature_ai_scripts` WHERE `id` IN (2661601,2661602,2661603,2664301,2664302,2664303);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GRIZZLY,0,0,1,8,0,100,0x01,@SPELL,0,0,0,33,@GRIZZLYDUMMY,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rabid Grizzly - On spell hit - Give kill credit for quest 12166'),
(@GRIZZLY,0,1,0,61,0,100,1,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rabid Grizzly - Despawn after 5 seconds'),
(@ELK,0,0,1,8,0,100,0x01,@SPELL,0,0,0,33,@ELKDUMMY,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Blighted Elk - On spell hit - Give kill credit for quest 12166'),
(@ELK,0,1,0,61,0,100,1,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blighted Elk - Despawn after 5 secondes');
 
-- Fix the quest item to allow it to only target the two quest NPCs
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=@ITEM;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,@ITEM,0,24,2,@GRIZZLY,0,0,'','Item Elune Liquid Fire target Rabid Grizzly (dead)'),
(18,0,@ITEM,0,24,2,@ELK,0,0,'','Item Elune Liquid Fire target Blighted Elk (dead)');

DELETE FROM `spell_linked_spell` `WHERE `spell_trigger`=46770;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(46770, 47972, 1, 'Liquid Fire of Elune');
