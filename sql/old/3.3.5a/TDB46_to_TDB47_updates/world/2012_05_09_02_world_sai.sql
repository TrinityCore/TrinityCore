-- Fixup for Quest Quest:The Path to the Citadel "Alliance and Horde"

-- Alliance slave add missing equipments
UPDATE `creature_template` SET `equipment_id`=254 WHERE `entry`=36767;

-- Horde Slave SAI
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry` IN (36770,36771,36772,36773);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (36770,36771,36772,36773);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (3677000);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(36770,0,0,0,11,0,100,6,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - On Reset - Emotestate'),
(36771,0,0,0,11,0,100,6,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - On Reset - Emotestate'),
(36772,0,0,0,11,0,100,6,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - On Reset - Emotestate'),
(36773,0,0,0,11,0,100,6,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - On Reset - Emotestate'),
(36770,0,1,0,8,0,100,7,71281,0,0,0,80,3677000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - On Spellhit - Run Script'),
(36771,0,1,0,8,0,100,7,71281,0,0,0,80,3677000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - On Spellhit - Run Script'),
(36772,0,1,0,8,0,100,7,71281,0,0,0,80,3677000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - On Spellhit - Run Script'),
(36773,0,1,0,8,0,100,7,71281,0,0,0,80,3677000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - On Spellhit - Run Script'),
-- Script
(3677000,9,0,0,0,0,100,0,500,500,500,500,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Horde Slave - Script - Turnto envoker'),
(3677000,9,1,0,0,0,100,0,500,500,500,500,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - Script - say text'),
(3677000,9,2,0,0,0,100,0,100,100,100,100,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - Script - set unitflag'),
(3677000,9,3,0,0,0,100,0,100,100,100,100,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - Script - set faction'),
(3677000,9,4,0,0,0,100,0,100,100,100,100,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - Script - set Emotestate'),
(3677000,9,5,0,0,0,100,0,100,100,100,100,33,36770,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Horde Slave - Script - give quest credit'),
(3677000,9,6,0,0,0,100,0,100,100,100,100,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - Script - set run on'),
(3677000,9,7,0,0,0,100,0,500,500,500,500,69,1,0,0,0,0,0,19,23837,70,0,0,0,0,0, 'Horde Slave - Script - move to closest trigger'),
(3677000,9,8,0,0,0,100,0,8000,8000,8000,8000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Horde Slave - Script - despawn');

-- Alliance Slave SAI
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry` IN (36764,36765,36766,36767);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (36764,36765,36766,36767);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (3676400);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(36764,0,0,0,11,0,100,6,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - On Reset - Emotestate'),
(36765,0,0,0,11,0,100,6,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - On Reset - Emotestate'),
(36766,0,0,0,11,0,100,6,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - On Reset - Emotestate'),
(36767,0,0,0,11,0,100,6,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - On Reset - Emotestate'),
(36764,0,1,0,8,0,100,7,71281,0,0,0,80,3676400,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - On Spellhit - Run Script'),
(36765,0,1,0,8,0,100,7,71281,0,0,0,80,3676400,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - On Spellhit - Run Script'),
(36766,0,1,0,8,0,100,7,71281,0,0,0,80,3676400,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - On Spellhit - Run Script'),
(36767,0,1,0,8,0,100,7,71281,0,0,0,80,3676400,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - On Spellhit - Run Script'),
-- Script
(3676400,9,0,0,0,0,100,0,500,500,500,500,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Alliance Slave - Script - Turnto envoker'),
(3676400,9,1,0,0,0,100,0,500,500,500,500,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - Script - say text'),
(3676400,9,2,0,0,0,100,0,100,100,100,100,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - Script - set unitflag'),
(3676400,9,3,0,0,0,100,0,100,100,100,100,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - Script - set faction'),
(3676400,9,4,0,0,0,100,0,100,100,100,100,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - Script - set Emotestate'),
(3676400,9,5,0,0,0,100,0,100,100,100,100,33,36764,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Alliance Slave - Script - give quest credit'),
(3676400,9,6,0,0,0,100,0,100,100,100,100,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - Script - set run on'),
(3676400,9,7,0,0,0,100,0,500,500,500,500,69,1,0,0,0,0,0,19,23837,70,0,0,0,0,0, 'Alliance Slave - Script - move to closest trigger'),
(3676400,9,8,0,0,0,100,0,8000,8000,8000,8000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alliance Slave - Script - despawn');

-- Ball and chain SAI
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (201969);
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid` IN (201969);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(201969,1,0,0,64,0,100,6,0,0,0,0,85,71281,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Ball and chain - On Gossip Hello - Envoker cast on self');

-- Spell Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=71281;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,71281,0,31,3,36770,0,0,'','Spell 71281 targets entry 36770'),
(13,1,71281,1,31,3,36771,0,0,'','Spell 71281 targets entry 36771'),
(13,1,71281,2,31,3,36772,0,0,'','Spell 71281 targets entry 36772'),
(13,1,71281,3,31,3,36773,0,0,'','Spell 71281 targets entry 36773'),
(13,1,71281,4,31,3,36764,0,0,'','Spell 71281 targets entry 36764'),
(13,1,71281,5,31,3,36765,0,0,'','Spell 71281 targets entry 36765'),
(13,1,71281,6,31,3,36766,0,0,'','Spell 71281 targets entry 36766'),
(13,1,71281,7,31,3,36767,0,0,'','Spell 71281 targets entry 36767');

-- Creature text from sniff
DELETE FROM `creature_text` WHERE `entry` IN (36770,36771,36772,36773,36764,36765,36766,36767);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- Alliance Slaves
(36764,0,0, 'You''re a beautiful sight... you have no idea.',12,0,100,0,0,0, 'Alliance Slave'),
(36764,0,1, '%s lets his mining pick drag on the ground as she approaches, clearly exhausted.',16,0,100,0,0,0, 'Alliance Slave'),
(36764,0,2, 'Have my babies.',12,0,100,0,0,0, 'Alliance Slave'),
(36764,0,3, 'If by life or death I can repay you, I will.',12,0,100,0,0,0, 'Alliance Slave'),
(36764,0,4, 'I''m going to return to the front of the quarry. Kill a few extra for me.',12,0,100,0,0,0, 'Alliance Slave'),
(36765,0,0, 'You''re a beautiful sight... you have no idea.',12,0,100,0,0,0, 'Alliance Slave'),
(36765,0,1, '%s lets his mining pick drag on the ground as she approaches, clearly exhausted.',16,0,100,0,0,0, 'Alliance Slave'),
(36765,0,2, 'Have my babies.',12,0,100,0,0,0, 'Alliance Slave'),
(36765,0,3, 'If by life or death I can repay you, I will.',12,0,100,0,0,0, 'Alliance Slave'),
(36765,0,4, 'I''m going to return to the front of the quarry. Kill a few extra for me.',12,0,100,0,0,0, 'Alliance Slave'),
(36766,0,0, 'You''re a beautiful sight... you have no idea.',12,0,100,0,0,0, 'Alliance Slave'),
(36766,0,1, '%s lets his mining pick drag on the ground as she approaches, clearly exhausted.',16,0,100,0,0,0, 'Alliance Slave'),
(36766,0,2, 'Have my babies.',12,0,100,0,0,0, 'Alliance Slave'),
(36766,0,3, 'If by life or death I can repay you, I will.',12,0,100,0,0,0, 'Alliance Slave'),
(36766,0,4, 'I''m going to return to the front of the quarry. Kill a few extra for me.',12,0,100,0,0,0, 'Alliance Slave'),
(36767,0,0, 'You''re a beautiful sight... you have no idea.',12,0,100,0,0,0, 'Alliance Slave'),
(36767,0,1, '%s lets his mining pick drag on the ground as she approaches, clearly exhausted.',16,0,100,0,0,0, 'Alliance Slave'),
(36767,0,2, 'Have my babies.',12,0,100,0,0,0, 'Alliance Slave'),
(36767,0,3, 'If by life or death I can repay you, I will.',12,0,100,0,0,0, 'Alliance Slave'),
(36767,0,4, 'I''m going to return to the front of the quarry. Kill a few extra for me.',12,0,100,0,0,0, 'Alliance Slave'),
-- Horde Slaves
(36770,0,0, 'You''re a beautiful sight... you have no idea.',12,0,100,0,0,0, 'Horde Slave'),
(36770,0,1, '%s lets his mining pick drag on the ground as she approaches, clearly exhausted.',16,0,100,0,0,0, 'Horde Slave'),
(36770,0,2, 'Have my babies.',12,0,100,0,0,0, 'Horde Slave'),
(36770,0,3, 'If by life or death I can repay you, I will.',12,0,100,0,0,0, 'Horde Slave'),
(36770,0,4, 'I''m going to return to the front of the quarry. Kill a few extra for me.',12,0,100,0,0,0, 'Horde Slave'),
(36771,0,0, 'You''re a beautiful sight... you have no idea.',12,0,100,0,0,0, 'Horde Slave'),
(36771,0,1, '%s lets his mining pick drag on the ground as she approaches, clearly exhausted.',16,0,100,0,0,0, 'Horde Slave'),
(36771,0,2, 'Have my babies.',12,0,100,0,0,0, 'Horde Slave'),
(36771,0,3, 'If by life or death I can repay you, I will.',12,0,100,0,0,0, 'Horde Slave'),
(36771,0,4, 'I''m going to return to the front of the quarry. Kill a few extra for me.',12,0,100,0,0,0, 'Horde Slave'),
(36772,0,0, 'You''re a beautiful sight... you have no idea.',12,0,100,0,0,0, 'Horde Slave'),
(36772,0,1, '%s lets his mining pick drag on the ground as she approaches, clearly exhausted.',16,0,100,0,0,0, 'Horde Slave'),
(36772,0,2, 'Have my babies.',12,0,100,0,0,0, 'Horde Slave'),
(36772,0,3, 'If by life or death I can repay you, I will.',12,0,100,0,0,0, 'Horde Slave'),
(36772,0,4, 'I''m going to return to the front of the quarry. Kill a few extra for me.',12,0,100,0,0,0, 'Horde Slave'),
(36773,0,0, 'You''re a beautiful sight... you have no idea.',12,0,100,0,0,0, 'Horde Slave'),
(36773,0,1, '%s lets his mining pick drag on the ground as she approaches, clearly exhausted.',16,0,100,0,0,0, 'Horde Slave'),
(36773,0,2, 'Have my babies.',12,0,100,0,0,0, 'Horde Slave'),
(36773,0,3, 'If by life or death I can repay you, I will.',12,0,100,0,0,0, 'Horde Slave'),
(36773,0,4, 'I''m going to return to the front of the quarry. Kill a few extra for me.',12,0,100,0,0,0, 'Horde Slave');
