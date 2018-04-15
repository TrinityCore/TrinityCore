--
SET @ARTRUIS := 28659;
SET @JALOOT   := 28667;
SET @ZEPIK    := 28668;
SET @ARTRUISGUID := 202971;
SET @JALOOTGUID   := 202969;
SET @ZEPIKGUID    := 202970;

DELETE FROM `creature_questender` WHERE `id` IN (@ZEPIK,@JALOOT) AND `quest` IN (12582, 12689);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(@ZEPIK, 12582),  -- Zepik the Gorloc Hunter q12582 Frenzyheart Champion
(@JALOOT, 12689);  -- Jaloot q12689 Hand of the Oracles

UPDATE `creature_queststarter` SET `id`=@ZEPIK WHERE `quest`=12582;

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= @ARTRUIS;

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ARTRUIS;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ARTRUIS;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ARTRUIS, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Respawn- Respawn Jaloot'),
(@ARTRUIS, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Respawn Zephik'),
(@ARTRUIS, 0, 2, 0, 0, 0, 100, 0, 5000, 9000, 9000, 15000, 11, 15530, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - IC - Cast Frostbolt (Phase 1)'),
(@ARTRUIS, 0, 3, 0, 0, 0, 100, 0, 7000, 11000, 11000, 15000, 11, 54261, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - IC - Cast Ice Lance (Phase 1)'),
(@ARTRUIS, 0, 4, 0, 9, 0, 100, 0, 0, 10, 14000, 18000, 11, 11831, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,  'Artruis the Heartless - On Range - Cast Frost Nova (Phase 1)'),
(@ARTRUIS, 0, 5, 0, 0, 0, 100, 0, 9000, 13000, 25000, 35000, 11, 54792, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,  'Artruis the Heartless - Cast Icy Veins (Phase 1)'),
(@ARTRUIS, 0, 6, 7, 6, 0, 100, 0, 0, 0, 0, 0, 11, 52518, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - On death - Spawn Artruis Phylactery'),
(@ARTRUIS, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 4, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event- Send Data 1 4 to Jaloot'),
(@ARTRUIS, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 4, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Send Data 1 4 to Zephik'),
(@ARTRUIS, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 5, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Say Line 5'),
(@ARTRUIS, 0, 10, 11, 2, 0, 100, 1, 0, 30, 0, 0, 11, 52185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - At 20% Hp Cast Bindings of Submission'),
(@ARTRUIS, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Send Data 1 1 to Jaloot'),
(@ARTRUIS, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Send Data 1 1 to Zephik'),
(@ARTRUIS, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 1, 3, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Say Line 3'),
(@ARTRUIS, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 4, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Say Line 4'),
(@ARTRUIS, 0, 15, 16, 25, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Reset - Send Data 1 2 to Jaloot'),
(@ARTRUIS, 0, 16, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Send Data 1 2 to Zephik'),
(@ARTRUIS, 0, 17, 18, 38, 0, 100, 0, 1, 2, 0, 0, 45, 1, 3, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Receive Data 1 2- Send Data 1 3 to Jaloot'),
(@ARTRUIS, 0, 18, 19, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Remove Bindings of Submission'),
(@ARTRUIS, 0, 19,  0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Set Data 1 0'),
(@ARTRUIS, 0, 20, 21, 4, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Agro- Respawn Jaloot'),
(@ARTRUIS, 0, 21, 22, 61, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Respawn Zephik'),
(@ARTRUIS, 0, 22, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Say Line 0'),
(@ARTRUIS, 0, 23, 0, 2, 0, 100, 1, 0, 75, 0, 0, 1, 1, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - On 75% HP - Say Line 1'),
(@ARTRUIS, 0, 24, 0, 2, 0, 100, 1, 0, 50, 0, 0, 1, 2, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - On 50% HP - Say Line 2'),
(@ARTRUIS, 0, 25, 26, 38, 0, 100, 0, 1, 1, 0, 0, 45, 1, 5, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Receive Data 1 1- Send Data 1 5 to Zepik'),
(@ARTRUIS, 0, 26, 27, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Remove Bindings of Submission'),
(@ARTRUIS, 0, 28,  0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Set Data 1 0'),
(@ARTRUIS, 0, 29,  0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, 53163, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - IC - Cast Dessawn Retainer'),
(@ARTRUIS, 0, 30,  0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 53163, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Agro - Cast Dessawn Retainer');

DELETE FROM `creature_text` WHERE `entry` =@ARTRUIS;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ARTRUIS,0,0,'Ah, the hero. Your little friends said you would come. This certainly saves me the trouble of hunting you down myself.',14,0,100,2,0,0,'Artruis the Heartless'),
(@ARTRUIS,1,0,'I have weathered a hundred years of war and suffering. Do you truly think it wise to pit your mortals boddies against a being that cannot die? I''d venture you have more to lose',14,0,100,2,0,0,'Artruis the Heartless'),
(@ARTRUIS,2,0,'Even shattered into countless pieces, the crystals all around weaken me... perhaps I should not have underestimated the titans so...',14,0,100,2,0,0,'Artruis the Heartless'),
(@ARTRUIS,3,0,'These two brave, ignorant fools despise each other, yet somehow they both spoke of you as a hero. Perhaps you just lack the will to choose a side... let me extend you that opportunity.',14,0,100,2,0,0,'Artruis the Heartless'),
(@ARTRUIS,4,0,'Artruis is shielded. You must choose your side quickly to break his spell.',41,0,100,2,0,0,'Artruis the Heartless'),
(@ARTRUIS,5,0,'Arthas once mustered strength...of the very same sort... perhaps his is the path that you will follow.',14,0,100,2,0,0,'Artruis the Heartless');

UPDATE `creature_template` SET `AIName`= 'SmartAI',`npcflag`=0,`unit_flags`=32832 WHERE `entry`= @JALOOT;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@JALOOT;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@JALOOT, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Spawn - Remove quest giver flag'),
(@JALOOT, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Set Unit Flags'),
(@JALOOT, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Cast Tomb of the Heartless'),
(@JALOOT, 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Data Set 1 1 - Set Hostile'),
(@JALOOT, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Remove Tomb of the Heartless'),
(@JALOOT, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 40, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Attack'),
(@JALOOT, 0, 6, 7, 38, 0, 100, 0, 1, 2, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Data Set 1 2 - Set Friendly'),
(@JALOOT, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Set Unit Flags'),
(@JALOOT, 0, 8 ,0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Cast Tomb of the Heartless'),
(@JALOOT, 0, 9, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @ARTRUISGUID, @ARTRUIS, 0, 0, 0, 0, 0, 'Jaloot - On Death - Send Data 1 1 to Artruis'),
(@JALOOT, 0, 10,11, 38, 0, 100, 0, 1, 3, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Data Set 1 3 - Set Friendly'),
(@JALOOT, 0, 11,12, 61, 0, 100, 0, 0, 0, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Remove Unit Flags'),
(@JALOOT, 0, 12,13, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Say Line 0'),
(@JALOOT, 0, 13,14, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, @ARTRUISGUID, @ARTRUIS, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Attack Artruis'),
(@JALOOT, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Remove Bindings of Submission'),
(@JALOOT, 0, 15,16, 38, 0, 100, 0, 1, 4, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Data Set 1 4 - Set Friendly'),
(@JALOOT, 0, 16,17, 61, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Set Unit Flags'),
(@JALOOT, 0, 17,18, 61, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Add quest giver flag'),
(@JALOOT, 0, 18,19 , 61, 0, 100, 0, 0, 0, 0, 0, 41, 120000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Despawn After 2 mins'),
(@JALOOT, 0, 19,0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Evade'),
(@JALOOT, 0, 20, 0, 9, 0, 100, 0, 0, 5, 15000, 20000, 11, 52943, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Range - Cast Lightning Whirl'),
(@JALOOT, 0, 21, 0, 9, 0, 100, 0, 0, 5, 15000, 18000, 11, 52944, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Range - Cast Lightning Strike'),
(@JALOOT, 0, 22, 0, 9, 0, 100, 0, 0, 5, 20000, 25000, 11, 52964, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Range - Cast Spark Frenzy'),
(@JALOOT, 0, 23, 0, 2, 0, 100, 0, 0, 30, 9000, 12000, 11, 52969, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Less than 30% HP - Cast Energy Siphon');

DELETE FROM `creature_text` WHERE `entry` =@JALOOT;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@JALOOT, 0, 0, 'Now you not catch us with back turned.  Now we hurt you bad undead. BAD!', 12, 0, 100, 0, 0, 0, 'Jaloot');

UPDATE `creature_template` SET `AIName`= 'SmartAI',`npcflag`=0,`unit_flags`=32832 WHERE `entry`= @ZEPIK;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ZEPIK;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ZEPIK, 0, 0, 1, 11, 0, 100, 1, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Spawn - Remove quest giver flag'),
(@ZEPIK, 0, 1, 2, 61, 0, 100, 1, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Set Unit Flags'),
(@ZEPIK, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Cast Tomb of the Heartless'),
(@ZEPIK, 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Data Set 1 1 - Set Hostile'),
(@ZEPIK, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Remove Tomb of the Heartless'),
(@ZEPIK, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 40, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Attack'),
(@ZEPIK, 0, 6, 7, 38, 0, 100, 0, 1, 2, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Data Set 1 2 - Set Friendly'),
(@ZEPIK, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Set Unit Flags'),
(@ZEPIK, 0, 8 ,0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Cast Tomb of the Heartless'),
(@ZEPIK, 0, 9, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 10, @ARTRUISGUID, @ARTRUIS, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Death - Send Data 1 2 to Artruis'),
(@ZEPIK, 0, 10, 11, 38, 0, 100, 0, 1, 5, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Data Set 1 5 - Set Friendly'),
(@ZEPIK, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Remove Unit Flags'),
(@ZEPIK, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Say Line 0'),
(@ZEPIK, 0, 13,14, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, @ARTRUISGUID, @ARTRUIS, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Attack Artruis'),
(@ZEPIK, 0, 14,0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Remove Bindings of Submission'),
(@ZEPIK, 0, 15,16, 38, 0, 100, 0, 1, 4, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Data Set 1 4 - Set Friendly'),
(@ZEPIK, 0, 16,17, 61, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Set Unit Flags'),
(@ZEPIK, 0, 17,18, 61, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Add quest giver flag'),
(@ZEPIK, 0, 18,19 ,61, 0, 100, 0, 0, 0, 0, 0, 41, 120000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Despawn After 2 mins'),
(@ZEPIK, 0, 19,0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Evade'),
(@ZEPIK, 0, 20, 0, 9, 0, 100, 0, 0, 20, 15000, 18000, 11, 52761, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Range - Cast Barbed Net'),
(@ZEPIK, 0, 21, 0, 9, 0, 100, 0, 5, 30, 12000, 15000, 11, 52889, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Range - Cast Envenomed Shot'),
(@ZEPIK, 0, 22, 0, 9, 0, 100, 0, 0, 5, 15000, 18000, 11, 52873, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Range - Cast Open Wound'),
(@ZEPIK, 0, 23, 0, 9, 0, 100, 0, 5, 30, 3000, 7000, 11, 52758, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Range - Cast Piercing Arrow'),
(@ZEPIK, 0, 24, 0, 9, 0, 100, 0, 0, 5, 30000, 40000, 11, 52886, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Range - Cast Spike Trap'),
(@ZEPIK, 0, 25, 0, 2, 0, 100, 0, 0, 30, 30000, 30000, 11, 52895, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Less than 30% HP Cast Bandage - Cast Bandage');

DELETE FROM `creature_text` WHERE `entry` =@ZEPIK;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ZEPIK, 0, 0, 'You going die big bad undead thing! You not catch Zepik sleeping this time!', 12, 0, 100, 0, 0, 0, 'Zepik the Gorloc Hunter');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=52185;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,52185,0,0,31,0,3,@ZEPIK,0,0,0,'','bindings of submission can hit Zepik the Gorloc Hunter'),
(13,1,52185,0,1,31,0,3,@JALOOT,0,0,0,'','bindings of submission can hit Jaloot'),
(13,1,52185,0,2,31,0,3,@ARTRUIS,0,0,0,'','bindings of submission can hit Artruis the Heartless');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN(51186,51188,51189,51190,51191,51192);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 51186, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Goregek the Bristlepine Hunter cannot be used near artruis'),
(17, 0, 51188, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Dajik the Wasp Hunter cannot be used near artruis'),
(17, 0, 51189, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Zepik the Gorloc Hunter cannot be used near artruis'),
(17, 0, 51190, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Lafoo cannot be used near artruis'),
(17, 0, 51191, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Jaloot cannot be used near artruis'),
(17, 0, 51192, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Moodle cannot be used near artruis');

UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry` IN (28667,28668);
