-- 
UPDATE `creature_template` SET `ScriptName` = 'npc_stormcrest_eagle' WHERE `entry` = 30108;

DELETE FROM `gossip_menu_option` WHERE  `menu_id`=9891 and `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9891, 0, 0, 'King Stormheart sent me to be tested as a frostborn would. I am ready for my test, Fjorlin', 32929, 1, 1, 0, 0, 0, 0, '',0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceID`=15 AND `SourceEntry`=0 AND `SourceGroup`=9891;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`elseGroup`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(15,9891,0,9,0,12874,0,0,0,'show gossip on quest 12874 taken');

-- Fjorlin Frostbrow SAI
SET @ENTRY := 29732;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9891,1,0,0,11,56411,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fjorlin Frostbrow - On Gossip Option 1 Selected - Cast 'Forcecast Summon Scripted Eagle'"),
(@ENTRY,0,1,0,61,0,100,0,9891,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fjorlin Frostbrow - On Gossip Option 1 Selected - Close Gossip"),
(@ENTRY,0,2,3,62,0,100,0,9891,0,0,0,85,55942,2,0,0,0,0,7,0,0,0,0,0,0,0,"Fjorlin Frostbrow - On Gossip Option 0 Selected - Invoker Cast 'Summon Battle Eagle'"),
(@ENTRY,0,3,0,61,0,100,0,9891,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fjorlin Frostbrow - On Gossip Option 0 Selected - Close Gossip");


DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=30108;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(30108,46598,1,1);

DELETE FROM `creature_text` WHERE `entry`=30401;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextId`) VALUES 
(30401, 0, 0, 'King Stormheart is putting you to the test, eh?  He must see something in you to begin with or I doubt he''d put you through such a sacred ritual.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30942),
(30401, 1, 0, 'I know you''re new to our kind, so I''ll catch you up a bit while we''re on our way over.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30943),
(30401, 2, 0, 'Years back, my father and several other frostborn were returning from a trek across Dragonblight. There was a heavy blizzard... far worse than we''ve ever seen since.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30944),
(30401, 3, 0, 'They crossed a trail of blood-soaked snow and followed it to find a dwarf wandering and speaking in a dialect they couldn''t make out... and not a dwarf of our kind mind you, but a mountain dwarf - something our kind had never seen before.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30945),
(30401, 4, 0, 'The dwarf seemed lost, having no memory of where he came from, or even of his own name. Not being the kind to leave a dwarven cousin to die in the snow, my father''s party took him in and continued back towards Frosthold.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30946),
(30401, 5, 0, 'Not long later, out of nowhere, the snow burst before them and a jormungar the size of Veranus herself came down upon their party... one of them was swallowed whole before they even had time to react.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30947),
(30401, 6, 0, 'My father thought they were all doomed... but behind him, a furious roar rumbled across the snow, and he turned to see the mountain dwarf growing in size, his skin taking on a stone-like texture, and his hands sizzling with lightning.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30948),
(30401, 7, 0, 'The dwarf barreled forward with a sound like rolling thunder and hurled a shining metal hammer, lightning coursing over its surface, directly into the jormungar''s throat.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30949),
(30401, 8, 0, 'The jormungar collapsed instantly, its head barely still attached to its convulsing body.  My father turned to the dwarf in awe and raised a fist in praise...', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30950),
(30401, 9, 0, 'The stranger having no name of his own, my father deemed \"Yorg,\" a name reserved for champions of legend. Years later, he now stands before us as Yorg Stormheart, King of the Frostborn.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30952),
(30401, 10, 0, 'King Stormheart has trained us well... turned us into even more fearsome warriors than we could have boasted during the time of our war with the Frost Giants.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30953),
(30401, 11, 0, 'And as one of the fiercest tests put upon a warrior of the frostborn, we are made to face a creature far larger than ourselves--giants, dragons, jormungar--as a testament to the fact that size will never be our weakness.', 12, 0, 100, 0, 0, 0, 'Velog Icebellow',30954),
(30401, 12, 0, 'This is the test put before you this day. Return to us only once The Iron Watcher is dead, and be revered as a warrior of the frostborn.', 14, 0, 100, 0, 0, 0, 'Velog Icebellow',30955),
(30401, 13, 0, 'He is slow from the rust of the ages... be quick on your feet and he will not best you. You have King Stormheart''s favor - do not disappoint.', 14, 0, 100, 0, 0, 0, 'Velog Icebellow',30956);

DELETE FROM `creature_template_addon` WHERE `entry`=30108;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30108,0,0,0,1,0,'52211'); -- Flight Aura

DELETE FROM `waypoint_data` WHERE `id`=30108;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(30108, 1, 6586.2, -294.997, 989.82, 0, 0, 0, 0, 100, 0),
(30108, 2, 6519.83, -384.722, 994.117, 0, 0, 0, 0, 100, 0),
(30108, 3, 6519.97, -524.613, 986.315, 0, 0, 0, 0, 100, 0),
(30108, 4, 6582.99, -676.868, 973.055, 0, 0, 0, 0, 100, 0),
(30108, 5, 6687.48, -733.39, 964.698, 0, 0, 0, 0, 100, 0),
(30108, 6, 6855.16, -744.853, 961.192, 0, 0, 0, 0, 100, 0),
(30108, 7, 6994.31, -760.115, 959.543, 0, 0, 0, 0, 100, 0),
(30108, 8, 7119.54, -785.058, 970.552, 0, 0, 0, 0, 100, 0),
(30108, 9, 7245.46, -832.456, 982.112, 0, 0, 0, 0, 100, 0),
(30108, 10, 7372.43, -884.75, 992.92, 0, 0, 0, 0, 100, 0),
(30108, 11, 7451.38, -912.608, 999.791, 0, 0, 0, 0, 100, 0),
(30108, 12, 7550.54, -946.482, 1008.39, 0, 0, 0, 0, 100, 0),
(30108, 13, 7627.06, -969.296, 1025.31, 0, 0, 0, 0, 100, 0),
(30108, 14, 7701.49, -991.429, 1041.78, 0, 0, 0, 0, 100, 0),
(30108, 15, 7767.2, -1011.33, 1056.82, 0, 0, 0, 0, 100, 0),
(30108, 16, 7837.09, -1032.49, 1072.82, 0, 0, 0, 0, 100, 0),
(30108, 17, 7898.99, -1053.29, 1090.37, 0, 0, 0, 0, 100, 0),
(30108, 18, 7944.64, -1070.18, 1112.88, 0, 0, 0, 0, 100, 0),
(30108, 19, 7995.38, -1111.07, 1138.38, 0, 0, 0, 0, 100, 0),
(30108, 20, 8075.38, -1184.51, 1180.87, 0, 0, 0, 0, 100, 0),
(30108, 21, 8133, -1259.6, 1214.29, 0, 0, 0, 0, 100, 0),
(30108, 22, 8221.79, -1381.51, 1271, 0, 0, 0, 0, 100, 0),
(30108, 23, 8300.22, -1485.87, 1321.57, 0, 0, 0, 0, 100, 0),
(30108, 24, 8367.07, -1592.58, 1382.36, 0, 0, 0, 0, 100, 0),
(30108, 25, 8414.48, -1701.68, 1449.03, 0, 0, 0, 0, 100, 0),
(30108, 26, 8456.78, -1783.6, 1462.78, 0, 0, 0, 0, 100, 0),
(30108, 27, 8482.2, -1838.47, 1470, 0, 0, 0, 0, 100, 0),
(30108, 28, 8526.7, -1956.21, 1473.59, 0, 0, 0, 0, 100, 0);
