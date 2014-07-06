-- Fix quest 11879 "Kaw the Mammoth Destroyer"
-- Set to SAI and delete CAIS
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='25802';
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='25881';

-- Wooly Mammoth Bull SAI
UPDATE `creature_template` SET `npcflag`=16777216 WHERE  `entry`=25743;

UPDATE `creature_template` SET `spell1`=46317,`spell2`=46315,`spell3`=46316,`Health_mod`=2 WHERE `entry`=25743;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25743 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25743,0,2,0,27,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wooly Mammoth Bull - On Passenger board - Set react state passive'),
(25743,0,3,0,28,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wooly Mammoth Bull - On Passenger remove - Despawn');

-- Wooly Mammoth Bull Vehicle condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=25743;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(16,0,25743,0,0,9,0,11879,0,0,0,0,'','Vehicle Wooly Mammoth Bull requires quest 11879');

-- Apply rep aura on quest accept 
DELETE FROM `spell_area` WHERE `spell`=46234;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(46234, 3537, 11879, 0, 0, 0, 2, 1, 74, 11);

-- Kaw speach on event start
DELETE FROM `creature_text` WHERE `entry`='25802';
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(25802, 0, 0, 'You challenge Kaw, destroyer of mammoths? Then face me and feel my thunder!', 14, 0, 100, 0, 0, 0, 'Kaw the Mammoth Destroyer', 25071);

-- Kaw SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`='25802' and `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`='2580200' and `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25802,0,0,0,1,0,100,1,0,0,0,0,18,33024,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kaw - OOC - Make self unattackable'),
(25802,0,1,0,38,0,100,0,1,1,0,0,80,2580200,2,0,0,0,0,1,0,0,0,0,0,0,0,'Kaw - On Data Set 1 1 - Run Script'),
(25802,0,2,0,6,0,100,0,0,0,0,0,11,46310,2,0,0,0,0,1,0,0,0,0,0,0,0,'Kaw - On Death - Cast Drop War Halberd'),
(2580200,9,0,0,0,0,100,1,0,0,0,0,1,0,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Kaw - Timed - Yell'),
(2580200,9,1,0,0,0,100,1,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kaw - Timed - Enable Running'),
(2580200,9,2,0,0,0,100,1,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,3974.17,5476.31,35.602,5.564,'Kaw - Timed - Move to Moria'),
(2580200,9,3,0,0,0,100,1,2500,2500,0,0,11,46260,2,0,0,0,0,19,25881,100,0,0,0,0,0,'Kaw - Timed - Mount to Moria');

-- Moria SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`='25881';
DELETE FROM `smart_scripts` WHERE `entryorguid`='2588100';

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(25881,0,0,0,8,0,100,1,46317,0,0,0,80,2588100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Moria - On spell hit - Start Event'),
(25881,0,1,0,6,0,100,1,0,0,0,0,19,33024,0,0,0,0,0,19,25802,100,0,0,0,0,0,'Moria - On death - Make Kaw attackable'),
(25881,0,2,0,1,0,100,1,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Moria - OOC - Set passive'),
(25881,0,3,0,1,0,100,1,0,0,0,0,28,46260,0,0,0,0,0,1,0,0,0,0,0,0,0,'Moria - OOC - Dismount Kaw'),
(2588100,9,0,0,0,0,100,1,0,0,0,0,11,17683,2,0,0,0,0,1,0,0,0,0,0,0,0,'Moria - Timed - Heal self'),
(2588100,9,1,0,0,0,100,1,0,0,0,0,45,1,1,0,0,0,0,19,25802,100,0,0,0,0,0,'Moria - Timed - Set Data 1 1 on Kaw'),
(2588100,9,2,0,0,0,100,1,5500,5500,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Moria - Timed - Set aggresive'),
(2588100,9,3,0,0,0,100,1,0,0,0,0,11,17683,2,0,0,0,0,1,0,0,0,0,0,0,0,'Moria - Timed - Heal self');
