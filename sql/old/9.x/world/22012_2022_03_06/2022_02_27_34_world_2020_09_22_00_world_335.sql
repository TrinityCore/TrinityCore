-- https://www.youtube.com/watch?v=zL_zY-Qi7HA https://www.youtube.com/watch?v=U0dzJ0DCDPg https://www.youtube.com/watch?v=AXOt3XBYEbU
-- Anzu's scale is wrong
UPDATE `creature_template` SET `scale` = 1 WHERE `entry` = 23035;

DELETE FROM `event_scripts` WHERE `id` = 14797;

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 23057;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 185554;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 185554 AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23057 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2305700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Gameobject can be used twice or more so event should just not repeat https://www.youtube.com/watch?v=AXOt3XBYEbU
(185554,1,0,0,70,0,100,1,2,0,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Raven's Claw - On Gameobject State Changed - Summon Group 0 (No Repeat)"),

(23057,0,0,0,54,0,100,0,0,0,0,0,0,80,2305700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Invis Raven God Target - On Just Summoned - Run Script"),

(2305700,9,0,0,0,0,100,0,0,0,0,0,0,86,39952,0,19,23046,0,0,1,0,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Cross Cast 'Otherworldly Portal' (Invis Raven God Portal)"),
(2305700,9,1,0,0,0,100,0,0,0,0,0,0,50,185590,120,0,0,0,0,8,0,0,0,0,-87.718,287.838,30.575,3.15,"Invis Raven God Target - On Script - Summon Gameobject 'Sethekk Halls Moonstone'"),
(2305700,9,2,0,0,0,100,0,0,0,0,0,0,50,185595,120,0,0,0,0,8,0,0,0,0,-87.574,287.855,31.075,3.15,"Invis Raven God Target - On Script - Summon Gameobject 'Test Rift'"),
-- Probably incorrect spell
(2305700,9,3,0,0,0,100,0,10000,10000,0,0,0,11,32566,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Cast 'Purple Banish State'"),
(2305700,9,4,0,0,0,100,0,0,0,0,0,0,86,39978,0,11,23058,100,0,1,0,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Cross Cast 'Raven God Summon Beams' (Invis Raven God Caster)"),
(2305700,9,5,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Set Run Off"),
(2305700,9,6,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-87.574,287.855,34.181,3.15,"Invis Raven God Target - On Link - Move To Position"),
-- Correct sound & duration
(2305700,9,7,0,0,0,100,0,15000,15000,0,0,0,11,35757,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Cast 'Ultris Destroyed'"),
(2305700,9,8,0,0,0,100,0,10000,10000,0,0,0,11,39990,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Cast 'Red Lightning Bolt'"),
(2305700,9,9,0,0,0,100,0,2000,2000,0,0,0,28,32566,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Remove Aura 'Purple Banish State'"),
(2305700,9,10,0,0,0,100,0,0,0,0,0,0,92,0,0,0,0,0,0,19,23046,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Interrupt Spell (Invis Raven God Portal)"),
(2305700,9,11,0,0,0,100,0,0,0,0,0,0,92,0,0,0,0,0,0,11,23058,100,0,0,0,0,0,0,"Invis Raven God Target - On Script - Interrupt Spell (Invis Raven God Caster)"),
(2305700,9,12,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,185590,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Despawn Closest Gameobject 'Sethekk Halls Moonstone'"),
(2305700,9,13,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,185595,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Despawn Closest Gameobject 'Test Rift'"),
(2305700,9,14,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,185554,0,0,0,0,0,0,0,"Invis Raven God Target - On Script - Despawn Closest Gameobject 'The Raven's Claw'"),
(2305700,9,15,0,0,0,100,0,0,0,0,0,0,12,23035,8,0,0,0,0,8,0,0,0,0,-87.5742,287.855,26.483,3.14,"Invis Raven God Target - On Script - Summon Creature 'Anzu'");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 185554 AND `summonerType` = 1;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(185554,1,0,23046,-87.574,287.855,27.441,3.15,8,0,"The Raven's Claw - Group 0 - Invis Raven God Portal"),
(185554,1,0,23057,-87.574,287.855,68.422,3.15,8,0,"The Raven's Claw - Group 0 - Invis Raven God Target"),
-- I have no idea where they are spawned, even with video it's hard to find correct positions
(185554,1,0,23058,-70.497276,299.914459,69.531113,1.344,8,0,"The Raven's Claw - Group 0 - Invis Raven God Caster"),
(185554,1,0,23058,-96.124321,296.725861,70.584343,1.846,8,0,"The Raven's Claw - Group 0 - Invis Raven God Caster"),
(185554,1,0,23058,-109.100250,288.954956,68.502106,3.25,8,0,"The Raven's Claw - Group 0 - Invis Raven God Caster"),
(185554,1,0,23058,-98.110512,272.078003,68.249001,4.438,8,0,"The Raven's Claw - Group 0 - Invis Raven God Caster"),
(185554,1,0,23058,-68.669334,266.709564,66.084366,4.623,8,0,"The Raven's Claw - Group 0 - Invis Raven God Caster"),
(185554,1,0,23058,-61.912510,285.375275,62.882904,6.284,8,0,"The Raven's Claw - Group 0 - Invis Raven God Caster");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 39978;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,39978,0,0,31,0,3,23057,0,0,0,0,"","Group 0: Spell 'Raven God Summon Beams' (Effect 0) targets creature 'Invis Raven God Target'");

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (23046,23057,23058);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(23046,1,1,1,0,0,0),
(23057,1,1,1,0,0,0),
(23058,1,1,1,0,0,0);
