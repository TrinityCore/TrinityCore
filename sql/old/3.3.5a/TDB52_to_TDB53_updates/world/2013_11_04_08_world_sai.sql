--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=30098;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13,7,30098,0,0,31,0,3,17253,0,0,0, '', 'Defile Uthers Tomb Targets Defile Uthers Tomb Trigger'),
(13,7,30098,0,1,31,0,5,181653,0,0,0, '', 'Defile Uthers Tomb Targets Temp Uthers Statue');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(17253,1854) AND `source_type`=0;

UPDATE creature_template SET `InhabitType`=4 WHERE entry IN(17233);
UPDATE creature_template SET AIName='SmartAI' WHERE entry IN(17253,1854);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` =30098;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 30098, 0, 0, 29, 0, 17233, 40, 0, 1, 0, 0, '', 'Cant cast Defile Uthers Tomb within 40 yards of Ghost of Uther Lightbringer');


INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17253,0,0,0,8,0,100,0,30098,0,60000,60000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Defile Uthers Tomb Trigger - On Spellhit - Set Phase 2'),
(17253,0,1,2,1,2,100,0,5000,5000,5000,5000,1,4,10000,0,0,0,0,9,17233,0,200,0,0,0,0,'Defile Uthers Tomb Trigger - OOC (Phase 2) - Say Line 4 on Ghost of Uther the Lightbringer'),
(17253,0,2,0,61,2,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Defile Uthers Tomb Trigger - Linked with Previous Event (Phase 2) - Set Phase 1'),
(17253,0,3,0,52,0,100,0,4,17233,0,0,1,5,10000,0,0,0,0,9,17233,0,200,0,0,0,0,'Defile Uthers Tomb Trigger - On Text Over on Ghost of Uther (line 4) - Say Line 5 on Ghost of Uther the Lightbringer'),
(17253,0,4,0,52,0,100,0,5,17233,0,0,1,6,10000,0,0,0,0,9,17233,0,200,0,0,0,0,'Defile Uthers Tomb Trigger - On Text Over on Ghost of Uther (line 5) - Say Line 6 on Ghost of Uther the Lightbringer'),
(17253,0,5,0,52,0,100,0,6,17233,0,0,1,7,10000,0,0,0,0,9,17233,0,200,0,0,0,0,'Defile Uthers Tomb Trigger - On Text Over on Ghost of Uther (line 6) - Say Line 7 on Ghost of Uther the Lightbringer'),
(1854,0,0,0,4,0,100,0,0,0,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,'High Priest Thel danis - On Agro - Say Line 1'),
(1854,0,1,0,16,0,100,0,10951,50,6000,6000,11,10951,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Priest Thel danis - On Missing Inner Fire (Rank 4) - Cast Inner Fire (Rank 4)'),
(1854,0,2,0,2,0,100,0,0,50,15000,15000,11,30155,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Priest Thel danis - On Low HP - Cast Heal'),
(1854,0,3,0,0,0,100,0,0,0,2500,3000,11,15498,0,0,0,0,0,2,0,0,0,0,0,0,0,'High Priest Thel danis - IC - Cast Holy Smite'),
(1854,0,4,0,25,0,100,0,0,0,0,0,11,10591,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Priest Thel danis - On Spawn - Cast Inner Fire (Rank 4)');

-- Event script to spawn Ghost of Uther the Lightbringer in correct place, seems the trigger npc is in exact spot where spawns in video so using the co-ordinates of that

DELETE FROM `event_scripts` WHERE `id`=10561;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(10561, 0, 10, 17233, 90000, 0, 972.969971, -1824.719971, 82.540703, 0.2935);

-- Texts groupid 0,1,2,3 are for alliance quest so starting from 4 here

DELETE FROM `creature_text` WHERE `entry`=17233 AND `groupid` BETWEEN 4 AND 7;
DELETE FROM `creature_text` WHERE `entry`=1854 AND `groupid`=1;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(17233, 4, 0, 'Why do you do this? Did I somehow wrong you in life?', 12, 0, 100, 0, 0, 0, 'Ghost of Uther Lightbringer '),
(17233, 5, 0, 'Ah, I see it now in your mind. This is the work of one of my former students... Mehlar Dawnblade. It is sad to know that his heart has turned so dark.', 12, 0, 100, 0, 0, 0, 'Ghost of Uther Lightbringer'),
(17233, 6, 0, 'Return to him. Return to Mehlor and tell him that I forgive him and that I understand why he believes what he does.', 12, 0, 100, 0, 0, 0, 'Ghost of Uther Lightbringer '),
(17233, 7, 0, 'I can only hope that he will see the Light and instead turn his energies to restoring once-beautiful Quel''Thalas.', 12, 0, 100, 0, 0, 0, 'Ghost of Uther Lightbringer '),
(1854, 1, 0, 'By the Light you will leave this tomb!', 12, 0, 100, 0, 0, 0, 'High Priest Thel danis');
