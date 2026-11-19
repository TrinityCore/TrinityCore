SET @HARPOON := 30066;
SET @HAYSTACK := 30096;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (55896,55934);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@HAYSTACK;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,4,55896,0,0,31,0,3,@HAYSTACK,0,0,0,'','Spell Explosion effect2 targets Dry Haystack'),
(13,2,55934,0,0,31,0,3,30103,0,0,0,'','Spell Valkyrion Fire effect1 targets Valkyrion Fire Bunny'),
(22,1,@HAYSTACK,0,0,1,1,55934,0,0,1,0,'','SAI Dry Haystack triggers only if Dry Haystack has no aura of spell Valkyrion Fire');

UPDATE `creature_template` SET `npcflag`=16777216, `ScriptName`='' WHERE `entry`=@HARPOON;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@HARPOON,@HAYSTACK);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@HARPOON,@HAYSTACK) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@HARPOON,0,0,0,11,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Valkyrion Harpoon Gun - On spawn - Root'),

(@HAYSTACK,0,0,1,8,0,100,0,55896,0,0,0,11,55934,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Dry Haystack - On spellhit Explosion - Spellcast Valkyrion Fire'),
(@HAYSTACK,0,1,2,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dry Haystack - Linked - Set event phase 1'),
(@HAYSTACK,0,2,0,61,0,100,0,0,0,0,0,33,@HAYSTACK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Dry Haystack - Linked - Quest credit'),
(@HAYSTACK,0,3,4,23,1,100,0,55934,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dry Haystack - On spellfade Valkyrion Fire (phase 1) - Set event phase 0'),
(@HAYSTACK,0,4,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dry Haystack - Linked - Despawn');
