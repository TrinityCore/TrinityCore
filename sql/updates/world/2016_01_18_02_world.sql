DELETE FROM `smart_scripts` WHERE `entryorguid`IN(27450,27355) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(2735500) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27450,0,0,1,8,0,100,0,48790,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Neltharions Flame Control Bunny - On Spellhit (Neltharions Flame) - Store Targetlist'),
(27450,0,1,2,61,0,100,0,48790,0,0,0,33,27450,0,0,0,0,0,7,0,0,0,0,0,0,0,'Neltharions Flame Control Bunny - On Spellhit (Neltharions Flame) - Give Kill Credit'),
(27450,0,2,3,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,27449,0,200,0,0,0,0, 'Neltharions Flame Control Bunny - Linked with Previous Event - Set Data 1 1 on Neltharions Flame Fire Bunny'),
(27450,0,3,4,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,27355,0,200,0,0,0,0, 'Neltharions Flame Control Bunny - Linked with Previous Event - Set Data 1 1 on Rothin the Decaying'),
(27450,0,4,0,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,27355,0,200,0,0,0,0, 'Neltharions Flame Control Bunny - Linked with Previous Event - Send Targetlist to Rothin the Decaying'),
(27355,0,0,0,25,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - On Reset - Set Phase 0'),
(27355,0,1,2,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - On Agro - Cast Shadowbolt'),
(27355,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - Linked with Previous Event - Set Phase 1'),
(27355,0,3,0,9,1,100,0,0,40,3400,4800,11,9613,64,0,0,0,0,7,0,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - On Range (Phase 1) - Cast Shadow Bolt'),
(27355,0,4,0,0,0,100,0,12000,17000,15000,20000,11,51337,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - IC - On Range (Phase 1) - Cast Shadow Flame'),
(27355,0,5,0,2,0,100,1,0,30,9500,11000,11,51512,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - On Less than 30% HP - Cast Aegis of Neltharion'),
(27355,0,6,0,6,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - On Death - Say'),
(27355,0,7,0,1,0,100,0,10000,10000,10000,10000,11,48685,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying - OOC - Cast Imbue Power'),
(27355,0,8,0,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying - On Reset - Set Passive'),
(27355,0,9,0,38,0,100,0,1,1,30000,30000,80,2735500,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Rothin the Decaying - On Data Set 1 1 - Run Script'),
(2735500,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - Script - Face Target'),
(2735500,9,1,0,0,0,100,0,0,0,0,0,28,48685,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - Script - Remove Aura Imbue Power'),
(2735500,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - Script - Say'),
(2735500,9,3,0,0,0,100,0,7000,7000,0,0,28,48695,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying - Script - Remove Aura Imbue Power Shield State'),
(2735500,9,4,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying - Script - Set Aggresive'),
(2735500,9,5,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rothin the Decaying <Cult of the Damned> - script - Say'),
(2735500,9,6,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Rothin the Decaying - Script - Attack Target');

DELETE FROM `creature_template_addon` WHERE `entry`=27355;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(27355, 0, 0, 0x0, 0x1, 0, '48695'); -- -- 27355 - 48695 - 48695

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=48685;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=27355;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 48685, 0, 0, 31, 0, 3, 27418, 0, 0, 0, 0, '', 'Imbue Power targets Rothins Spell Bunny'),
(13, 1, 48685, 0, 1, 31, 0, 3, 26475, 0, 0, 0, 0, '', 'Imbue Power targets Magmawyrm'),
(22, 10, 27355, 0, 0, 36, 1, 0, 0, 0, 0, 0, 0, '', 'Only execute SAI if Rothin the Decaying alive'),
(22, 2, 27355, 0, 0, 1, 1, 48695, 0, 0, 1, 0, 0, '', 'Only execute SAI if Rothin the Decaying does not have aura Imbue Power Shield State');
