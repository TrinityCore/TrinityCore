-- Fix quest: Adding Injury to Insult (12481)

UPDATE `creature` SET `position_z`=207.3961 WHERE `guid`=112513;

UPDATE `creature_template` SET `speed_run`=2.571428, `InhabitType`=7, `HoverHeight`=7.5 WHERE `entry`=24238;

DELETE FROM `creature_template_addon` WHERE `entry`=24238;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`) VALUES
(24238,33554432,1);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (24458,24474);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24238,24458,24474) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24238,0,0,0,1,0,100,0,10000,15000,45000,60000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On update OOC - Say text 2'),
(24238,0,1,2,8,0,100,1,43315,0,0,0,84,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On spellhit Vrykul Insult - Invoker say text 0'),
(24238,0,2,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On spellhit Vrykul Insult - Say text 1'),
(24238,0,3,4,9,0,100,1,0,10,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On target within 10y - Unmount'),
(24238,0,4,5,61,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On target within 10y - Disable fly'),
(24238,0,5,0,61,0,100,0,0,0,0,0,91,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On target within 10y - Remove unit_field_bytes1 (hovering)'),
(24238,0,6,0,8,0,100,0,6660,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On spellhit Shoot - Attack'),
(24238,0,7,0,8,0,100,0,11971,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On spellhit Sunder Armor - Attack'),
(24238,0,8,0,8,0,100,0,18802,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On spellhit Frost Shot - Attack'),
(24238,0,9,0,8,0,100,0,43895,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On spellhit Lydell''s Poison - Attack'),
(24238,0,10,0,6,0,100,0,0,0,0,0,11,43371,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On death - Spellcast Bjorn Kill Credit'),
(24238,0,11,0,0,0,100,0,5000,10000,10000,15000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On update IC - Spellcast Mortal Strike'),
(24238,0,12,0,0,0,100,0,0,5000,10000,15000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On update IC - Spellcast Crush Armor'),
(24238,0,13,0,11,0,100,0,0,0,0,0,43,0,22657,0,0,0,0,1,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On spawn - Mount'),
(24238,0,14,15,7,0,100,0,0,0,0,0,43,0,22657,0,0,0,0,1,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On evade - Mount'),
(24238,0,15,16,61,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On evade - Enable fly'),
(24238,0,16,0,61,0,100,0,0,0,0,0,90,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bjorn Halgurdsson - On evade - Set unit_field_bytes1 (hovering)'),

(24458,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lydell - On aggro - Say line'),
(24458,0,1,0,9,0,100,0,0,5,8000,15000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Lydell - On target within 5y - Spellcast Sunder Armor'),
(24458,0,2,0,0,0,100,0,3000,5000,70000,75000,11,43895,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Lydell - On update IC - Spellcast Lydell''s Poison'),

(24474,0,0,0,9,0,100,0,5,30,8000,10000,11,18802,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Vengeance Landing Assassin - On target within 5-30y - Spellcast Frost Shot'),
(24474,0,1,0,9,0,100,0,5,30,1500,2000,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Vengeance Landing Assassin - On target within 5-30y - Spellcast Shoot');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=43315;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(43315,46348,2,'On aura Vrykul Insult apply Slow Creature');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=43315;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorType`,`ScriptName`,`Comment`) VALUES
(17,0,43315,0,31,1,3,24238,0,12,'','Spell Vrykul Insult is castable on Bjorn Halgurdsson only');

DELETE FROM `creature_text` WHERE `entry` IN (24238,24458);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24238,0,0,'[Crude Vrykul] Bjorns mottar haelgond sygar!',14,0,100,0,0,0,'Bjorn Halgurdsson'),
(24238,1,0,'No one speaks of my mother in that manner!',14,0,100,0,0,0,'Bjorn Halgurdsson'),
(24238,2,0,'Drive the invaders out!  For Queen Angerboda!',14,0,100,0,0,0,'Bjorn Halgurdsson'),
(24238,2,1,'Fight without fear and the Val''kyr will reward you!',14,0,100,0,0,0,'Bjorn Halgurdsson'),
(24238,2,2,'The Winterskorn tribe will prevail!',14,0,100,0,0,0,'Bjorn Halgurdsson'),

(24458,0,0,'I''ve been saving this just for you, big boy!',12,0,100,0,0,0,'Lydell');
