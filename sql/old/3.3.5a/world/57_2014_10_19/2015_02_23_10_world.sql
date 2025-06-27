-- A Distraction For Akama
SET @Maiev          := 22989; -- Maev
SET @Akama          := 22990; -- Akama
SET @Vagath         := 23152; -- Vagath 
SET @IllidariShadow := 22988; -- IllidariShadow
SET @Ashtongue      := 21701; -- Ashtongue
SET @FanOfBlades    := 39954; -- Maev spell
SET @Stealth        := 34189; -- Maev spell
SET @ChainLightning := 39945; -- Akama spell 
SET @Xiri           := 18528; -- XI'RI
SET @IllidariRavag  := 22857; -- Illidari Ravager
SET @LightOfTheNaa1 := 39829; -- XI'RI spell
SET @LightOfTheNaa2 := 39831; -- XI'RI spell
SET @FyraDawnstar   := 22864; -- FyraDawnstar
SET @Caalen         := 22862; -- Anachorete Caalen
SET @Lightsworn     := 22861; -- Lightsworn Vindicator
SET @Magister       := 22863; -- Seasoned Magister
SET @ID             := 8650;  -- Gossip Menu

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (22989, 22990, 23152, 22988, 21701, 18528, 22857, 22864, 22863, 22862, 22861);
UPDATE `creature_template` SET `npcflag`=0 where `entry`=22990;
DELETE FROM creature_summon_groups WHERE summonerid=@Xiri;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(@Xiri,0,0,@Akama,-3557.775635,624.185852,6.244853,4.687259,3,300000),
(@Xiri,0,0,@Maiev,-3563.998047,623.326050,6.134195,4.687259,3,300000),  
(@Xiri,0,0,@Ashtongue,-3568.963867,627.467407,5.477327,4.742220,3,300000), 
(@Xiri,0,0,@Ashtongue,-3565.453125,627.804199,5.458982,4.801125,3,300000),
(@Xiri,0,0,@Ashtongue,-3561.734375,628.002930,5.536494,4.76578,3,300000),
(@Xiri,0,0,@Ashtongue,-3557.638428,628.221863,5.681130,4.76578,3,300000),
(@Xiri,0,0,@Ashtongue,-3554.038574,628.414246,5.853768,4.76578,3,300000), 
(@Xiri,0,0,@Ashtongue,-3557.367188,632.975952,5.016828,4.830713,3,300000), 
(@Xiri,0,0,@Ashtongue,-3561.433350,632.492554,4.889128,4.830713,3,300000), 
(@Xiri,0,0,@Ashtongue,-3565.568848,632.000916,4.862391,4.830713,3,300000),
(@Xiri,0,0,@Vagath,-3564.023438,406.373199,29.640791,1.577282,3,300000),
(@Xiri,0,0,@IllidariRavag,-3570.985840,408.893219,29.715797,1.529191,3,300000),
(@Xiri,0,0,@IllidariRavag,-3556.721924,409.166534,29.495508,1.599877,3,300000),
(@Xiri,0,0,@IllidariShadow,-3571.129395,418.261780,28.846333,1.556680,3,300000),
(@Xiri,0,0,@IllidariShadow,-3581.750977,417.807861,30.357321,1.560607,3,300000),
(@Xiri,0,0,@IllidariShadow,-3576.343506,424.403748,28.781679,1.482065,3,300000),
(@Xiri,0,0,@IllidariShadow,-3568.493652,427.238312,28.031080,1.609870,3,300000),
(@Xiri,0,0,@IllidariShadow,-3559.938232,428.418793,27.697611,1.641286,3,300000),
(@Xiri,0,0,@IllidariShadow,-3564.919678,432.020447,27.485765,1.633432,3,300000);

DELETE FROM `creature_text` WHERE `entry` IN (@Akama, @FyraDawnstar, @Caalen, @Vagath, @Maiev, @Xiri) ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(@FyraDawnstar, 0, 0, 'Onward, Scryers! Show Illidan''s lackeys the temper of our steel!', 14, 0, 100, 0, 0, 0, 'Fyra Downstar', 20696),
(@Caalen, 0, 0, 'Come closer, demon! Death awaits!', 12, 0, 100, 0, 0, 0, 'Caalen', 20670),
(@Caalen, 0, 1, 'Illidan''s lapdogs! Destroy them all!', 12, 0, 100, 0, 0, 0, 'Caalen', 20669),
(@Caalen, 0, 2, 'I''ve a message for your master, scum!', 12, 0, 100, 0, 0, 0, 'Caalen', 20672),
(@Caalen, 0, 3, 'Pathetic worm... your master''s days are over!', 12, 0, 100, 0, 0, 0, 'Caalen', 20671),
(@Caalen, 0, 4, 'For Xi''ri!  For the Sha''tar!', 12, 0, 100, 0, 0, 0, 'Caalen', 20667),
(@Caalen, 0, 5, 'Your end is at hand, Illidari!', 12, 0, 100, 0, 0, 0, 'Caalen', 20668),
(@Vagath, 0, 0, 'Pitiful wretches. You dared invade Illidan''s temple? Very well, I shall make it your death bed!', 14, 0, 100, 0, 0, 0, 'Vagath', 20719),
(@Akama, 0, 0, 'Now is the time, Maiev! Unleash your wrath!', 14, 0, 100, 0, 0, 0, 'Akama', 20742),
(@Maiev, 0, 0, 'I''ve waited for this moment for years. Illidan and his lapdogs will be destroyed!', 14, 0, 100, 0, 0, 0, 'Maiev', 20743),
(@Akama, 1, 0, 'Slay all who see us! Word must not get back to Illidan.', 14, 0, 100, 0, 0, 0, 'Akama', 20744),
(@Maiev, 1, 0, 'Meet your end, demon!', 12, 0, 100, 0, 0, 0, 'Maiev', 0),
(@Vagath, 1, 0, 'You''ve sealed you fate, Akama. The Master will learn from your betrayal!', 14, 0, 100, 0, 0, 0, 'Vagath', 20745),
(@Akama, 2, 0, 'Akama has no master, not anymore.', 12, 0, 100, 0, 0, 0, 'Akama', 20746),
(@Akama, 3, 0, 'Our plans are in danger already. It appears Maiev''s decided to do things her own way.', 12, 0, 100, 0, 0, 0, 'Akama', 20748),
(@Akama, 4, 0, '%s''s attention shifts to a crack along the temple''s southern wall.', 16, 0, 100, 0, 0, 0, 'Akama', 20749),
(@Akama, 5, 0, 'We must carry on with or without Maiev. Inside! Quickly!', 12, 0, 100, 0, 0, 0, 'Akama', 20750),
(@Xiri, 0, 0, '%s falls silent and a quiet tension falls over nearby Sha''tar forces as Xi''ri makes his decision.', 16, 0, 100, 0, 0, 0, 'Xiri', 20737),
(@Xiri, 1, 0, '%s begins channeling the powers of the light.', 16, 0, 100, 0, 0, 0, 'Xiri', 20693);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 8650 AND `id` = 0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `OptionBroadcastTextID`) VALUES 
(8650,0,0, 'I am ready to join you for the battle, Xi''ri.',1,1,0,0,0,0, '', 21003);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@ID,0,0,9,10985,0,0,0,'','Show gossip menu if player accept the quest A distraction for Akama');

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Akama AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Akama*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Maiev AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Maiev*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Xiri AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Xiri*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Xiri*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Xiri*100+2 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Ashtongue AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Vagath AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lightsworn AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Magister AND `source_type` = 0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Xiri, 0, 0, 0, 62, 0, 100, 0, 8650, 0, 0, 0, 80, @Xiri*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - On Gossip use - ActionList'),
(@Xiri*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Close gossip'),
(@Xiri*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Remove npcflag'),
(@Xiri*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Talk'),
(@Xiri*100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Talk'),
(@Xiri*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 39828, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Cast'),
(@Xiri*100, 9, 5, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 107, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Summon Group'),
(@Xiri*100, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Caalen, 60, 0, 0, 0, 0, 0, 'Caalen - On Gossip use - Talk'),
(@Xiri*100, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @FyraDawnstar, 60, 0, 0, 0, 0, 0, 'Caalen - On Gossip use - Talk'),
(@Xiri*100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 39831, 0, 0, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 'Xiri - ActionList - Cast'),
(@Xiri*100, 9, 9, 0, 0, 0, 100, 0, 40000, 40000, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - ActionList - Add npcflag'),
(@Akama, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Akama, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Gossip use - Start Waypoint'),
(@Ashtongue, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Ashtongue, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue - On Gossip use - Start Waypoint'),
(@Maiev, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Maiev, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue - On Gossip use - Start Waypoint'),
(@Xiri, 0, 1, 0, 62, 0, 100, 0, 8650, 0, 0, 0, 80, @Xiri*100+1, 2, 0, 0, 0, 0, 11, @Lightsworn, 80, 0, 0, 0, 0, 0, 'Xiri - On Gossip use - Start waypoint'),
(@Xiri*100+1, 9, 0, 0, 0, 0, 100, 0, 27000, 27000, 0, 0, 53, 1, @Lightsworn, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - On Gossip use - Start waypoint'),
(@Xiri, 0, 2, 0, 62, 0, 100, 0, 8650, 0, 0, 0, 80, @Xiri*100+2, 2, 0, 0, 0, 0, 11, @Magister, 80, 0, 0, 0, 0, 0, 'Xiri - On Gossip use - Start waypoint'),
(@Xiri*100+2, 9, 0, 0, 0, 0, 100, 0, 27000, 27000, 0, 0, 53, 1, @Magister, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Xiri - On Gossip use - Start waypoint'),
(@Maiev, 0, 1, 0, 40, 0, 100, 0, 1, 0, 0, 0, 80, @Maiev*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vagath - On waypoint1 - Start Script'),
(@Maiev*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Vagath, 80, 0, 0, 0, 0, 0, 'Vagath - On Script - Talk1'),
(@Maiev*100, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Akama, 20, 0, 0, 0, 0, 0, 'Akama - On Script - Talk1'),
(@Maiev*100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - Talk1'),
(@Maiev*100, 9, 3, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Akama, 20, 0, 0, 0, 0, 0, 'Akama - On Script - Talk2'),
(@Maiev*100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - Talk2'),
(@Maiev*100, 9, 5, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - Set React Passive'),
(@Maiev*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - Set Immune To NPC'),
(@Maiev*100, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - evade'),
(@Maiev*100, 9, 8, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 34189, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev - On Script - Stealth'),
(@Vagath, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 14000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vagath - On aggro - Talk2'),
(@Vagath, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 1, 2, 14000, 0, 0, 0, 0, 19, @Akama, 20, 0, 0, 0, 0, 0, 'Akama - On Vagath death - Talk3'),
(@Akama, 0, 1, 0, 40, 0, 100, 0, 2, 0, 0, 0, 80, @Akama*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On waypoint2 - Start Script'),
(@Akama*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 12000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Script - pause Waypoint'),
(@Akama*100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 3, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Script - Talk4'),
(@Akama*100, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Script - Talk5'),
(@Akama*100, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 5, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Script - Talk6'),
(@Ashtongue, 0, 1, 0, 40, 0, 100, 0, 2, 0, 0, 0, 54, 23000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On waypoint2 - event'),
(@Akama, 0, 2, 0, 40, 0, 100, 0, 6, 0, 0, 0, 11, 39932, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On waypoint3 - Cast Spell'),
(@Akama, 0, 3, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, @ChainLightning, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Akama - IC - Cast Spell'),
(@Maiev, 0, 2, 0, 0, 0, 100, 0, 1000, 1000, 3000, 3000, 11, @FanOfBlades, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Maiev - IC - Cast Spell'),
(@Magister, 0, 0, 0, 75, 0, 100, 0, 0, @IllidariRavag, 10, 5000, 49, 0, 0, 0, 0, 0, 0, 19, @IllidariRavag, 10, 0, 0, 0, 0, 0, 'Magister - On los ooc - Attack'),
(@Lightsworn, 0, 0, 0, 75, 0, 100, 0, 0, @IllidariRavag, 10, 5000, 49, 0, 0, 0, 0, 0, 0, 19, @IllidariRavag, 10, 0, 0, 0, 0, 0, 'Lightsworn - On los ooc - Attacka'), 
(@Magister, 0, 1, 0, 75, 0, 100, 0, 0, @IllidariShadow, 10, 5000, 49, 0, 0, 0, 0, 0, 0, 19, @IllidariShadow, 10, 0, 0, 0, 0, 0, 'Magister - On los ooc - Attack'),
(@Lightsworn, 0, 1, 0, 75, 0, 100, 0, 0, @IllidariShadow, 10, 5000, 49, 0, 0, 0, 0, 0, 0, 19, @IllidariShadow, 10, 0, 0, 0, 0, 0, 'Lightsworn - On los ooc - Attacka'),
(@Magister, 0, 2, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, 9053, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Akama - IC - Cast Spell'),
(@Lightsworn, 0, 2, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, 33632, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Akama - IC - Cast Spell'),
(@Lightsworn, 0, 3, 0, 0, 0, 100, 0, 5000, 5000, 10000, 10000, 11, 13005, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Akama - IC - Cast Spell'),
(@Lightsworn, 0, 4, 0, 0, 0, 100, 0, 3000, 8000, 5000, 8000, 11, 13952, 0, 0, 0, 0, 0, 26, 10, 0, 0, 0, 0, 0, 0, 'Akama - IC - Cast Spell');

DELETE FROM `waypoints` WHERE entry in (@Akama, @Maiev, @Ashtongue, @Lightsworn, @Magister);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Akama,1,-3562.123291, 486.208344, 22.091547,'Akama1'),
(@Akama,2,-3569.400879, 408.074738, 29.698217,'Akama2'),  
(@Akama,3,-3578.632568, 353.128601, 35.888973,'Ashtongue3'),
(@Akama,4,-3600.931885, 322.053955, 39.085770,'Ashtongue3'),
(@Akama,5,-3617.203125, 320.658691, 39.697262,'Ashtongue3'),
(@Akama,6,-3651.692627, 317.280975, 35.914421,'Akama3'),
(@Maiev,1,-3567.418457, 485.073334, 22.376778,'Maiev1'),
(@Maiev,2,-3567.913086, 400.602386, 30.253670,'Maiev2'), 
(@Maiev,3,-3567.458740, 371.282898, 32.955494,'Maiev3'),
(@Maiev,4,-3651.692627, 317.280975, 35.914421,'Maiev4'),
(@Lightsworn,1,-3562.123291, 486.208344, 22.091547,'Lightsworn1'),
(@Lightsworn,2,-3569.400879, 408.074738, 29.698217,'Lightsworn2'),
(@Magister,1,-3562.123291, 486.208344, 22.091547,'Magister1'),
(@Magister,2,-3569.400879, 408.074738, 29.698217,'Magister2'),
(@Ashtongue,1,-3562.123291, 486.208344, 22.091547,'Ashtongue1'),
(@Ashtongue,2,-3569.400879, 408.074738, 29.698217,'Ashtongue2'),
(@Ashtongue,3,-3578.632568, 353.128601, 35.888973,'Ashtongue3'),
(@Ashtongue,4,-3600.931885, 322.053955, 39.085770,'Ashtongue3'),
(@Ashtongue,5,-3617.203125, 320.658691, 39.697262,'Ashtongue3'),   
(@Ashtongue,6,-3651.692627, 317.280975, 35.914421,'Ashtongue3');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 39831;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 39831, 0, 31, 3, @Ashtongue, 0, 0, '', NULL),
(13, 3, 39831, 1, 31, 3, @Akama, 0, 0, '', NULL),
(13, 3, 39831, 2, 31, 3, @Maiev, 0, 0, '', NULL),
(13, 3, 39831, 3, 31, 3, @Lightsworn, 0, 0, '', NULL),
(13, 3, 39831, 4, 31, 3, @Magister, 0, 0, '', NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 39832;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 39832, 0, 31, 3, @Ashtongue, 0, 0, '', NULL),
(13, 3, 39832, 1, 31, 3, @Akama, 0, 0, '', NULL),
(13, 3, 39832, 2, 31, 3, @Maiev, 0, 0, '', NULL),
(13, 3, 39832, 3, 31, 3, @Lightsworn, 0, 0, '', NULL),
(13, 3, 39832, 4, 31, 3, @Magister, 0, 0, '', NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 39932;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 39932, 0, 8, 13429 , 0, 0, 0, '', 'Eye of the Witness Distraction for Akama');
