-- SmartAI script for creature entry 15170 Rutgar Glyphshaper and 15171 Frankal Stonebridge
SET @RUTGAR  := 15170;
SET @FRANKAL := 15171;

UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (@RUTGAR,@FRANKAL);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@RUTGAR,@FRANKAL) AND `source_type`= 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@RUTGAR, 0, 0,1, 62,0,100,0,6545,0,0,0, 33,15222,0,0,0,0,0, 7,0,0,0,0,0,0,0,"Rutgar Glyphshaper - on Gossip Menu 6545 id 0 selected - Kill Credit 'Rutgar Invisible Trigger'"),
(@RUTGAR, 0, 1,0, 61,0,100,0,   0,0,0,0, 72,    0,0,0,0,0,0, 7,0,0,0,0,0,0,0,"Rutgar Glyphshaper - on Gossip Menu 6545 id 0 selected - Close Gossip"),
(@FRANKAL,0, 2,3, 62,0,100,0,6552,0,0,0, 33,15221,0,0,0,0,0, 7,0,0,0,0,0,0,0,"Frankal Stonebridge - on Gossip Menu 6552 id 0 selected - Kill Credit 'Frankal Invisible Trigger'"),
(@FRANKAL,0, 3,0, 61,0,100,0,   0,0,0,0, 72,    0,0,0,0,0,0, 7,0,0,0,0,0,0,0,"Frankal Stonebridge - on Gossip Menu 6552 id 0 selected - Close Gossip");

-- gossip menu options for NPC 15170 Rutgar Glyphshaper and NPC 15171 Frankal Stonebridge
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (6534,6551,6550,6549,6548,6547,6546,6545,6533,6558,6557,6556,6555,6554,6553,6552);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(6534,0,0,"Hello, Rutgar. The Commander has sent me here to gather some information about his missing wife.",                    10712,1,1,6551,0,0,0,'',0),
(6551,0,0,"That sounds dangerous.",                                                                                              10714,1,1,6550,0,0,0,'',0),
(6550,0,0,"What happened to her after that?",                                                                                    10716,1,1,6549,0,0,0,'',0),
(6549,0,0,"Natalia?",                                                                                                            10718,1,1,6548,0,0,0,'',0),
(6548,0,0,"What demands?",                                                                                                       10720,1,1,6547,0,0,0,'',0),
(6547,0,0,"Lost it? What do you mean?",                                                                                          10722,1,1,6546,0,0,0,'',0),
(6546,0,0,"Possessed by what?",                                                                                                  10724,1,1,6545,0,0,0,'',0),
(6545,0,0,"I'll be back once I straighten this mess out.",                                                                       10726,1,1,   0,0,0,0,'',0),
(6533,0,0,"Hello, Frankal. I've heard that you might have some information as to the whereabouts of Mistress Natalia Mar'alith.",10727,1,1,6558,0,0,0,'',0),
(6558,0,0,"That's what I like to hear.",                                                                                         10729,1,1,6557,0,0,0,'',0),
(6557,0,0,"That's odd.",                                                                                                         10731,1,1,6556,0,0,0,'',0),
(6556,0,0,"You couldn't handle a lone night elf priestess?",                                                                     10733,1,1,6555,0,0,0,'',0),
(6555,0,0,"I've been meaning to ask you about that monkey.",                                                                     10735,1,1,6554,0,0,0,'',0),
(6554,0,0,"Then what?",                                                                                                          10737,1,1,6553,0,0,0,'',0),
(6553,0,0,"What a story! So she went into Hive'Regal and that was the last you saw of her?",                                     10739,1,1,6552,0,0,0,'',0),
(6552,0,0,"Thanks for the information, Frankal.",                                                                                10741,1,1,   0,0,0,0,'',0);

-- conditions for Rutgar Glyphshaper's and Frankal Stonebridge's gossip menus
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` IN (6533,6534) AND `SourceEntry` IN (0,7735,7736);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,6533,7735,0,0,9,0,8304,0,0,0,0,0,'',"Show gossip_menu.entry 6533 text_id 7735 only if Quest 8304 is taken (active)"),
(14,6534,7736,0,0,9,0,8304,0,0,0,0,0,'',"Show gossip_menu.entry 6534 text_id 7736 only if Quest 8304 is taken (active)"),
(15,6533,   0,0,0,9,0,8304,0,0,0,0,0,'',"Show gossip_menu_option.menu_id 6533 id 0 only if Quest 8304 is taken (active)"),
(15,6534,   0,0,0,9,0,8304,0,0,0,0,0,'',"Show gossip_menu_option.menu_id 6534 id 0 only if Quest 8304 is taken (active)");

-- gossip menu options for gameobject_template.displayId 6425 Lesser Wind Stone, 6426 Wind Stone, 6427 Greater Wind Stone
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (6540,6542,6543) AND `id` IN (0,1,2,3,4);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(6540,0,0,"I am no cultist, you monster!  Come to me and face your destruction!", 10684,1,1,0,0,0,0,'',0),
(6540,1,0,"Crimson Templar!  I hold your crest of beckoning.  Heed my summons!",  10685,1,1,0,0,0,0,'',0),
(6540,2,0,"Azure Templar!  I hold your crest of beckoning.  Heed my summons!",    10692,1,1,0,0,0,0,'',0),
(6540,3,0,"Earthen Templar!  I hold your crest of beckoning.  Heed my summons!",  10691,1,1,0,0,0,0,'',0),
(6540,4,0,"Hoary Templar!  I hold your crest of beckoning.  Heed my summons!",    10690,1,1,0,0,0,0,'',0),
(6542,0,0,"You will listen to this, vile duke!  I am not your Twilight's Hammer lapdog!  I am here to challenge you!  Come!  Come, and meet your death...",10698,1,1,0,0,0,0,'',0),
(6542,1,0,"Duke of Cynders! I hold your signet!  Heed my call!",                  10699,1,1,0,0,0,0,'',0),
(6542,2,0,"Duke of Fathoms! I hold your signet!  Heed my call!",                  10702,1,1,0,0,0,0,'',0),
(6542,3,0,"Duke of Shards! I hold your signet!  Heed my call!",                   10701,1,1,0,0,0,0,'',0),
(6542,4,0,"Duke of Zephyrs! I hold your signet!  Heed my call!",                  10700,1,1,0,0,0,0,'',0),
(6543,0,0,"The day of judgement has come, fiend!  I challenge you to battle!",    10707,1,1,0,0,0,0,'',0),
(6543,1,0,"Skaldrenox!  I hold your scepter, and charge you to enter this world!",10708,1,1,0,0,0,0,'',0),
(6543,2,0,"Skwol!  I hold your scepter!  I command you to enter this world!",     10711,1,1,0,0,0,0,'',0),
(6543,3,0,"Kazum!  I hold your scepter!  I command you to enter this world!",     10710,1,1,0,0,0,0,'',0),
(6543,4,0,"Whirlaxis!  I hold your scepter!  I command you to enter this world!", 10709,1,1,0,0,0,0,'',0);
