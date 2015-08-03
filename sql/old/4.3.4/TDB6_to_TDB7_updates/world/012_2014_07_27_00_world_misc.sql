DELETE FROM `creature_text` WHERE `entry` IN(17246,17240, 17242, 17241,17214,17215,17117);
DELETE FROM `creature_text` WHERE `entry` =17375 and `id` IN(3,4);

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(17246, 0, 0, 'Yarr, Admiral. Let me think about it... Arrr... It be comin'' into focus.', 12, 7, 100, 1, 0, 0, '"Cookie" McWeaksauce', 13699),
(17246, 1, 0, 'It looks like it be succulent pork ribs basted with its own delectable juices and a side o'' Captain Sander''s Secret Sauce - fer dippin''.', 12, 7, 100, 1, 0, 0, '"Cookie" McWeaksauce', 13700),
(17246, 2, 0, 'And fer dessert we be havin'' cheesecake, flown in fresh from Stormwind on the wings o'' angels...', 12, 7, 100, 1, 0, 0, '"Cookie" McWeaksauce', 13701),
(17246, 3, 0, 'No. Not really...', 12, 7, 100, 274, 0, 0, '"Cookie" McWeaksauce', 13702),
(17246, 4, 0, 'It be chicken...', 12, 7, 100, 1, 0, 0, '"Cookie" McWeaksauce', 13704),
(17240, 0, 0, 'Hey, Cookie! What''s for dinner tonight? And don''t say chicken!', 12, 7, 100, 22, 0, 0, 'Admiral Odesyus', 13698),
(17240, 1, 0, 'Wow! Really?', 12, 7, 100, 5, 0, 0, 'Admiral Odesyus', 13702),
(17240, 2, 0, 'I hate you so much, Cookie.', 12, 7, 100, 1, 0, 0, 'Admiral Odesyus', 13705),
(17242, 0, 0, 'Of course! Anything for you, darling!', 12, 7, 100, 5, 0, 0, 'Archaeologist Adamant Ironheart', 13712),
(17242, 1, 0, 'Alright, let me take a look at that tablet.', 12, 7, 100, 1, 0, 0, 'Archaeologist Adamant Ironheart', 13713),
(17242, 2, 0, '%s slowly reads the tablet, mouthing the words in their native tongue.', 16, 7, 100, 0, 0, 0, 'Archaeologist Adamant Ironheart', 13714),
(17242, 3, 0, 'Naga warlord! Oh dear...', 12, 7, 100, 5, 0, 0, 'Archaeologist Adamant Ironheart', 13715),
(17242, 4, 0, 'Well, you aren''t going to like what I have to tell you, young missy. This tablet is a naga communication. Their leader, Warlord Sriss''tiz, has ordered his naga to take the rest of the island by force.', 12, 7, 100, 1, 0, 0, 'Archaeologist Adamant Ironheart', 13716),
(17242, 5, 0, 'And it looks like he''s got reinforcements comin'' from Nazjatar!', 12, 7, 100, 5, 0, 0, 'Archaeologist Adamant Ironheart', 13717),
(17242, 6, 0, 'We''ve got to do something about this!', 12, 0, 100, 5, 0, 0, 'Archaeologist Adamant Ironheart', 13718),
(17241, 0, 0, 'Adamant, could you please take a look at this tablet and try to decipher the runes?', 12, 7, 100, 1, 0, 0, 'Priestess Kyleen Il''dinare', 13711),
(17241, 1, 0, 'Thank you, Adamant. I think I know just the person for the job.', 12, 7, 100, 2, 0, 0, 'Priestess Kyleen Il''dinare', 13719),
(17214, 0, 0, 'Now to apply the ointment to her wounds.', 12, 7, 100, 1, 0, 0, 'Anchorite Fateema', 13596),
(17214, 1, 0, 'It appears that the ointment is ineffective. Such a pity...', 12, 7, 100, 1, 0, 0, 'Anchorite Fateema', 13597),
(17214, 2, 0, 'Man''ari... But how... We are not eredar! She must know! If there are others like her, we must find them and explain...', 12, 7, 100, 1, 0, 0, 'Anchorite Fateema', 13608),
(17215, 0, 0, 'There may still be a solution. Come here, $n. I will explain what I need.', 12, 7, 100, 1, 0, 0, 'Daedal0', 13598),
(17215, 1, 0, 'This should do it...', 12, 7, 100, 0, 0, 0, 'Daedal', 13599),
(17215, 2, 0, 'Wake up little creature. Wake up from your slumber... You are safe now.', 12, 7, 100, 0, 0, 0, 'Daedal', 13600),
(17117, 0, 0, '%s groans.', 16, 7, 100, 0, 0, 0, 'Injured Night Elf Priestess', 13601),
(17117, 1, 0, '%s sits up.', 16, 7, 100, 0, 0, 0, 'Injured Night Elf Priestess', 13602),
(17117, 2, 0, 'Whe... Where am I? What... What is this place?', 12, 7, 100, 6, 0, 0, 'Injured Night Elf Priestess', 13603),
(17117, 3, 0, 'BY THE LIGHT OF ELUNE! Eredar! Cursed demons, what have you done to me? I have not come alone, we will fight you as we have in the past! I...', 12, 7, 100, 5, 0, 0, 'Injured Night Elf Priestess', 13604),
(17117, 4, 0, '%s falls back into a coma.', 16, 0, 100, 0, 0, 0, 'Injured Night Elf Priestess', 13605),
(17375, 0, 3, '[Furbolg] The prophecy is true!', 12, 0, 100, 0, 0, 0, 'Stillpine Captive', 13980),
(17375, 0, 4, '%s growls at its captors.', 16, 0, 100, 0, 0, 0, 'Stillpine Captive', 13977);

-- Change cookie mcweaksauces spawn position to sniffed one, wp lead to where was previously spawned
UPDATE `creature` SET `position_x`=-4708.59, `position_y`=-12400.26, `position_z`=11.94285, `orientation`=0.9948376 WHERE  `guid`=61976;


UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(17246,17240, 17242, 17241, 17240,17214,17215,17117);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(17246,17240, 17242, 17241, 17240,17214,17215,17117) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(1724100,1724600,1724100, 1721500, 1721400) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17241,0,0,0,20,0,100,0,9514,0,0,0,80,1724100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - On Quest reward rune covered tablet - run script'),
(17242,0,0,0,38,0,100,0,1,1,0,0,53,0,1724200,0,0,0,0,1,0,0,0,0,0,0,0,'Archaeologist Adamant Ironheart - On Data Set 1 1- Start WP (Path 1)'),
(17242,0,1,0,38,0,100,0,2,2,0,0,53,0,1724201,0,0,0,0,1,0,0,0,0,0,0,0,'Archaeologist Adamant Ironheart - On Data Set 2 2- Start WP (Path 2)'),
(17242,0,2,0,40,0,100,0,1,1724201,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.26573,'Archaeologist Adamant Ironheart - On Reached WP1 (Path 2) - Set Orientation'),
(17246,0,0,0,1,0,100,0,0,30000,300000,450000,80,1724600,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Cookie" McWeaksauce - OOC - Run Script'),
(17246,0,1,0,40,0,100,0,3,17246,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Cookie" McWeaksauce - On Reached WP3 - Pause WP'),
(17240,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,19 ,17246,0,0,0,0,0,0,'Admiral Odesyus - On Data Set 1 1- Face "Cookie" McWeaksauce'),
(17240,0,1,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.38078,'Admiral Odesyus - On Data Set 2 2- Set Orientation'),
(17215,0,0,0,38,0,100,0,1,1,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daedal - On Data Set 1 1- Set NPC Flags'),
(17215,0,1,0,38,0,100,0,2,2,0,0,81,83,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daedal - On Data Set 2 2- Set NPC Flags'),
(17215,0,2,0,20,0,100,0,9473,2,0,0,80,1721500,2,0,0,0,0,1,0,0,0,0,0,0,0,'Daedal - On Quest Reward - An Alternative Alternative - Run Script'),
(17117,0,0,0,38,0,100,0,1,1,0,0,91,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Injured Night Elf Priestess - On Data Set 1 1- Set Bytes 1'),
(17117,0,1,0,38,0,100,0,2,2,0,0,90,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Injured Night Elf Priestess - On Data Set 2 2- Set Bytes 1'),
(17214,0,0,0,20,0,100,0,9463,2,0,0,80,1721400,2,0,0,0,0,1,0,0,0,0,0,0,0,'Anchorite Fateema - On Quest Reward - Medicinal Purposes - Run Script'),
(1721400,9,0,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,17215,0,0,0,0,0,0,'Anchorite Fateema - Script - Set Data 1 1 Daedal'),
(1721400,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anchorite Fateema - Script - Say Line 1'),
(1721400,9,2,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anchorite Fateema - Script - Say Line 2'),
(1721400,9,3,0,0,0,100,0,9000,9000,0,0,1,0,0,0,0,0,0,19,17215,0,0,0,0,0,0,'Anchorite Fateema - Script - Say Line 1 (Daedal)'),
(1721400,9,4,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,17215,0,0,0,0,0,0,'Anchorite Fateema - Script - Set Data 2 2 Daedal'),
(1721500,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daedal - Script - Say Line 2'),
(1721500,9,1,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daedal - Script - Say Line 3'),
(1721500,9,2,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,17117,0,0,0,0,0,0,'Daedal - Script - Say Line 1 (Injured Night Elf Priestess)'),
(1721500,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,17117,0,0,0,0,0,0,'Daedal - Script - Say Line 2 (Injured Night Elf Priestess)'),
(1721500,9,4,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,17117,0,0,0,0,0,0,'Daedal - Script - Set Data 1 1 (Injured Night Elf Priestess)'),
(1721500,9,5,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,19,17117,0,0,0,0,0,0,'Daedal - Script - Say Line 3 (Injured Night Elf Priestess)'),
(1721500,9,6,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,19,17117,0,0,0,0,0,0,'Daedal - Script - Say Line 4 (Injured Night Elf Priestess)'),
(1721500,9,7,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,19,17117,0,0,0,0,0,0,'Daedal - Script - Say Line 5 (Injured Night Elf Priestess)'),
(1721500,9,8,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,17117,0,0,0,0,0,0,'Daedal - Script - Set Data 2 2 (Injured Night Elf Priestess)'),
(1721500,9,9,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,19,17214,0,0,0,0,0,0,'Daedal - Script - Say Line 3 (Anchorite Fateema)'),
(1724600,9,0,0,0,0,100,0,0,0,0,0,53,0,17246,0,0,0,0,1,0,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Start WP'),
(1724600,9,1,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,19,17240,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Set Data 1 1 on Admiral Odesyus'),
(1724600,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,19,17240,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Say Line 1 on Admiral Odesyus'),
(1724600,9,3,0,0,0,100,0,9000,9000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Say Line 1'),
(1724600,9,4,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Say Line 2'),
(1724600,9,5,0,0,0,100,0,9000,9000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Say Line 3'),
(1724600,9,6,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,17240,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Say Line 2 on Admiral Odesyus'),
(1724600,9,7,0,0,0,100,0,9000,9000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Say Line 4'),
(1724600,9,8,0,0,0,100,0,4000,4000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Say Line 6'),
(1724600,9,9,0,0,0,100,0,1000,1000,0,0,11,30221,0,0,0,0,0,19,620,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Cast Shoot (Target Closest chicken)'),
(1724600,9,10,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,19,17240,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Say Line 3 on Admiral Odesyus'),
(1724600,9,11,0,0,0,100,0,5000,5000,0,0,45,2,2,0,0,0,0,19,17240,0,0,0,0,0,0,'Cookie" McWeaksauce - Script - Set Data 2 2 on Admiral Odesyus'),
(1724100,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Set NPC Flags'),
(1724100,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,17242,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Face Archaeologist Adamant Ironheart'),
(1724100,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Say Line 1'),
(1724100,9,3,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,19,17242,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Set Data 1 1 on Archaeologist Adamant Ironheart'),
(1724100,9,4,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,19,17242,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Say Line 1 (Archaeologist Adamant Ironheart)'),
(1724100,9,5,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,19,17242,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Say Line 2 (Archaeologist Adamant Ironheart)'),
(1724100,9,6,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,19,17242,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Say Line 3 (Archaeologist Adamant Ironheart)'),
(1724100,9,7,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,19,17242,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Say Line 4 (Archaeologist Adamant Ironheart)'),
(1724100,9,8,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,19,17242,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Say Line 5 (Archaeologist Adamant Ironheart)'),
(1724100,9,9,0,0,0,100,0,7000,7000,0,0,1,5,0,0,0,0,0,19,17242,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Say Line 6 (Archaeologist Adamant Ironheart)'),
(1724100,9,10,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Say Line 2'),
(1724100,9,11,0,0,0,100,0,2000,2000,0,0,45,2,2,0,0,0,0,19,17242,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Set Data 2 2 on Archaeologist Adamant Ironheart'),
(1724100,9,12,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.994838,'Priestess Kyleen Il''dinare - Script - Set Orientation'),
(1724100,9,13,0,0,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Priestess Kyleen Il''dinare - Script - Set NPC Flags');

DELETE FROM `waypoints` WHERE `entry` IN (1724200,1724201, 17246);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(1724200, 1, -4699.27, -12419.77, 11.7000, 'Archaeologist Adamant Ironheart'),
(1724201, 1, -4693.81, -12423.1, 11.8935, 'Archaeologist Adamant Ironheart'),
(17246, 1, -4712.833, -12394.57, 12.2762, '"Cookie" McWeaksauce'),
(17246, 2, -4715.833, -12400.07, 12.5262, '"Cookie" McWeaksauce'),
(17246, 3, -4712.333, -12404.32, 12.2762, '"Cookie" McWeaksauce'),
(17246, 4, -4715.833, -12400.07, 12.5262, '"Cookie" McWeaksauce'),
(17246, 5, -4708.59, -12400.26, 11.94285, '"Cookie" McWeaksauce');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=30221;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 30221, 0, 0, 31, 0, 3, 620, 0, 0, 0, 0, '', 'Shoot Targets Chicken');
