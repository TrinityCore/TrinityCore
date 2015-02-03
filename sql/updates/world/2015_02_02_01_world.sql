--
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=35427;
UPDATE `smart_scripts` SET `link`=19 WHERE `entryorguid`=26670 AND `id`=18;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=193424;
DELETE FROM `smart_scripts` WHERE `entryorguid`=193424 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(193424, 1, 0, 1, 62, 0, 100, 0, 10111, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of Dominion - On Gossip Option 0 Selected - Close Gossip'),
(193424, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 58106, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of Dominion - On Gossip Option 0 Selected - Invoker Cast Forcecast: Control Lithe Stalker'),
(193424, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 58037, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of Dominion - On Gossip Option 0 Selected - Invoker Cast Control Lithe Stalker');

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` =30895;
DELETE FROM `smart_scripts` WHERE `entryorguid` =30895 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30895, 0, 0, 0, 27, 0, 100, 1, 0, 0, 0, 0, 11, 58117, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Passenger Boarded - Cast Force Reaction: Scourge'),
(30895, 0, 1, 0, 28, 0, 100, 1, 0, 0, 0, 0, 28, 58117, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Passenger Removed - Remove Aura Force Reaction: Scourge');

UPDATE `creature_template` SET `spell1`=57882, `spell2`=58203, `spell3`=58282, `spell4`=58283 WHERE  `entry`=30895;
UPDATE `smart_scripts` SET `event_type`=25 WHERE  `entryorguid`=29717 AND `source_type`=0 AND `id`=0 AND `link`=0;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(31119,30952,30951,31131,30951);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(31110,31119,30952,3095200,31131,3113100,30951);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31110, 0, 0, 0, 54, 0, 100, 1, 0, 0, 0, 0, 11, 58548, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Just Summoned - Cast Ethereal'),
(31110, 0, 1, 0, 27, 0, 100, 1, 0, 0, 0, 0, 11, 58548, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Passenger Boarded - Cast Ethereal'),
(31110, 0, 2, 0, 28, 0, 100, 1, 0, 0, 0, 0, 28, 58548, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Passenger Removed - Remove Ethereal'),
(31110, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 58548, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Reset - Cast Ethereal'),
(31119, 0, 0, 1, 54, 0, 100, 1, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Just Summoned - Store Targetlist'),
(31119, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 30952, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Just Summoned - Set Data on Hungering Plaguehound'),
(31119, 0, 2, 3, 38, 0, 100, 1, 1, 1, 0, 0, 11, 58564, 2, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Data Set - Give Kill Credit'),
(31119, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Data Set - Despawn'),
(30952, 0, 0, 0, 75, 0, 100, 0, 0, 31119, 20, 15000, 80, 3095200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - On Bloody Meat within 20 yards - Run Script'),
(30951, 0, 0, 0, 8, 0, 100, 0, 45254, 0, 0, 0, 33, 30951, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Restless Lookout - On Spellhit - Killcredit'),
(31131, 0, 0, 0, 8, 0, 100, 0, 58662, 0, 300000, 300000, 80, 3113100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Crystal - On Spellhit - Run Script'),
(3113100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 31131, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Containment Crystal - Script - Kill Credit'),
(3113100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Crystal - Script - Set Bytes 1'),
(3113100, 9, 2, 0, 0, 0, 100, 0, 300000, 300000, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Crystal - Script - Remove Bytes 1'),
(3095200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Disable Random Move'),
(3095200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 31119, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Move to Bloodymeat'),
(3095200, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 31119, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Move to Bloodymeat'),
(3095200, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Evade'),
(3095200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Enable Random Move');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`IN(-58563);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-58563, 45254, 0,'Assasinate Restless Lookout triggers Suicide');
DELETE FROM `event_scripts`  WHERE `id`=8175;

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE  `entry` =179499;

DELETE FROM `smart_scripts` WHERE `entryorguid` =179499 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(179499,1,0,0,70,0,100,1,2,0,0,0,12,14351,1,900000,0,1,0,8,0,0,0,588.44,606.87,-4.75,5.62,'Ogre Tannin Basket - On State Changed - Spawn Gordok Bushwacker');

SET @Villager=27359;
SET @GEIST=27370;

UPDATE `creature_template` SET `ainame`='SmartAI',`scriptname`='' WHERE `entry` IN (@Villager,@GEIST);
UPDATE `creature_template` SET `exp`=1,`unit_flags`=`unit_flags`|33536 WHERE `entry`=@Villager;

DELETE FROM `creature_template_addon` WHERE `entry` IN (@Villager,@GEIST);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@Villager,0,0,1,0, NULL), 
(@GEIST,0,0,1,0, NULL);

DELETE FROM `creature_text` WHERE `entry`=@Villager;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(@Villager,0,0,'Good of you to come, champion! The beast almost had me!',12,7,0,0,0,0,'Trapped Wintergarde Villager',26470),
(@Villager,0,1,'Finally! A hero has come!',12,7,0,0,0,0,'Trapped Wintergarde Villager',26469),
(@Villager,0,2,'Thank you, kind soul.',12,7,0,0,0,0,'Trapped Wintergarde Villager',26467),
(@Villager,0,3,'I''ll never forget you, friend.',12,7,0,0,0,0,'Trapped Wintergarde Villager',26468);

DELETE FROM `smart_scripts` WHERE `entryorguid`=@GEIST AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GEIST,0,0,0,4,0,100,0,0,0,0,0,64,1,0,0,0,0,0,2,0,0,0,0,0,0,0,'Vengeful Geist - On Aggro - Store Target List '),
(@GEIST,0,1,2,6,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@Villager,10,0,0,0,0,0,'Vengeful Geist - On Death - Send stored targets'),
(@GEIST,0,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@Villager,10,0,0,0,0,0,'Vengeful Geist - Link With Previous Event - Set Data 0 1 ');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@Villager AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Villager*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Villager,0,0,0,38,1,100,1,0,1,0,0,80,2735900,0,0,0,0,0,1,0,0,0,0,0,0,0,'Trapped Wintergarde Villager - On Data Set 0 1 - Call Timed Actionlist'),
(@Villager,0,1,0,34,0,100,0,0,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Trapped Wintergarde Villager - On Movementinform - Despawn'),
(@Villager,0,2,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Trapped Wintergarde Villager - On Reset - Set Phase 1'),
(@Villager*100,9,0,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Trapped Wintergarde Villager - Script - Set Passive'),
(@Villager*100,9,1,0,0,0,100,0,10,10,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Trapped Wintergarde Villager - Script - Set Unit Flags (Unattackable)'),
(@Villager*100,9,2,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Trapped Wintergarde Villager - Script - Set Event Phase 2'),
(@Villager*100,9,3,0,0,0,100,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Trapped Wintergarde Villager - Script - Play Emote Cheers'),
(@Villager*100,9,4,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Trapped Wintergarde Villager - Script - Talk'),
(@Villager*100,9,5,0,0,0,100,0,0,0,0,0,33,27359,0,0,0,0,0,12,1,0,0,0,0,0,0,'Trapped Wintergarde Villager - Script Give Quest Credit'),
(@Villager*100,9,6,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Trapped Wintergarde Villager - Script - Set Run'),
(@Villager*100,9,7,0,0,0,100,0,2000,2000,0,0,69,1,0,0,0,0,0,8,0,0,0,3719.13,-839.1,164.9,0,'Trapped Wintergarde Villager - Script  - Move To Pos'),
(@Villager*100,9,8,0,0,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Trapped Wintergarde Villager - Script  - Despawn');
SET @OGUID=5544;
SET @CGUID=75010;

DELETE FROM `gameobject` WHERE  `guid`=21202;

DELETE FROM `gameobject` WHERE `guid` = @OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID, 188463, 571, 1, 1,  4045.556, 2193.373, 152.0166, 4.729844, 0, 0, 0, 1, 120, 255, 1); -- 188463 (Area: 65)

UPDATE `creature_template` SET `unit_flags`=32768 WHERE  `entry`=26608;

DELETE FROM `creature_addon` WHERE  `guid`=85321;

DELETE FROM `creature_template_addon` WHERE `entry`IN(26772,26608,26656,26654);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(26772, 0, 0x10000, 0x1, ''), -- 26772 - 29266
(26608, 0, 0x10000, 0x1, '47020'), -- 26608 - 47020
(26656, 0, 0x10000, 0x1, ''), -- 26656
(26654, 0, 0x10000, 0x1, ''); -- 26654 - 47273

UPDATE `creature` SET `spawntimesecs`=120 WHERE  `guid`=85321;

DELETE FROM `creature` WHERE `id` IN(26772,26608,26656);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phasemask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 26772, 571, 1, 1,  4026.681, 2196.83, 151.8157, 0.5235988, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+1, 26772, 571, 1, 1,  4057.075, 2189.563, 151.9275, 2.216568, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+2, 26772, 571, 1, 1,  4066.369, 2203.186, 151.8947, 2.827433, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+3, 26772, 571, 1, 1,  4028.012, 2220.003, 151.6349, 5.689773, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+4, 26772, 571, 1, 1,  4087.59, 2197.294, 150.3048, 5.899213, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+5, 26772, 571, 1, 1,  4062.908, 2222.086, 152.0691, 3.438299, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+6, 26772, 571, 1, 1,  4069.837, 2216.063, 151.6581, 3.420845, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+7, 26772, 571, 1, 1,  4059.205, 2234.109, 151.6747, 4.031711, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+8, 26772, 571, 1, 1,  4085.448, 2212.562, 150.3048, 2.600541, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+9, 26772, 571, 1, 1,  4102.396, 2215.324, 150.5771, 2.9147, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+10, 26772, 571, 1, 1,  4094.654, 2231.302, 150.3048, 4.39823, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+11, 26772, 571, 1, 1,  4085.341, 2238.712, 150.3048, 6.265732, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+12, 26608, 571, 1, 1,  4112.918, 2231.335, 221.9723, 3.281219, 120, 0, 0), -- 26608 (Area: 65)
(@CGUID+13, 26656, 571, 1, 1,  4041.442, 2205.44, 151.8544, 1.58825, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+14, 26656, 571, 1, 1,  4046.042, 2203.535, 151.8609, 1.780236, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+15, 26656, 571, 1, 1,  4039.123, 2210.314, 151.9584, 5.654867, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+16, 26656, 571, 1, 1,  4050.549, 2205.821, 151.8495, 1.745329, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+17, 26656, 571, 1, 1,  4045.468, 2217.318, 151.895, 3.961897, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+18, 26656, 571, 1, 1,  4052.386, 2210.654, 151.7681, 2.303835, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+19, 26656, 571, 1, 1,  4040.73, 2215.186, 151.9743, 1.692969, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+20, 26656, 571, 1, 1,  4050.493, 2215.687, 151.6617, 0, 120, 0, 0); -- 26656 (Area: 65)

DELETE FROM `creature_text` WHERE `entry`IN(26654,26608);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(26654, 0, 0, 'Release me, fiends!', 12, 0, 100, 15, 0, 0, 'Roanauk Icemist',25828),
(26654, 0, 1, 'Pray to whatever gods you believe in that I am never freed!', 12, 0, 100, 15, 0, 0, 'Roanauk Icemist',25829),
(26654, 1, 0, 'I... am... FREE!', 14, 0, 100, 22, 0, 0, 'Roanauk Icemist',25954),
(26654, 2, 0, 'What have they done to my people...', 12, 0, 100, 6, 0, 0, 'Roanauk Icemist',25955),
(26654, 3, 0, 'You will face the full fury of the ancestors for what you have done, monster!', 14, 0, 100, 22, 0, 0, 'Roanauk Icemist',25956),
(26654, 4, 0, 'Rebirth comes, my brothers... Rise... Rise and fight once more.', 12, 0, 100, 0, 0, 0, 'Roanauk Icemist',25957),
(26654, 5, 0, 'FOR ICEMIST! FOR THE TAUNKA!', 14, 0, 100, 0, 0, 0, 'Roanauk Icemist',25958),
(26654, 6, 0, 'Come down and face me, insect!', 14, 0, 100, 15, 0, 0, 'Roanauk Icemist',25962),
(26654, 7, 0, 'Then I will force you down! Wind grant me flight!', 14, 0, 100, 15, 0, 0, 'Roanauk Icemist',25963),
(26608, 0, 0, 'Give in, Taunka! Your will cannot hold out against the Scourge!', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25952),
(26608, 0, 1, 'Leave no survivors!', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25951),
(26608, 0, 2, 'Tear this pitiful village apart!', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25950),
(26608, 1, 0, 'Your freedom will be short lived, Icemist!', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25959),
(26608, 2, 0, 'Insolent mortal! You will be consumed!', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25964),
(26608, 3, 0, 'ARRGGH!! It cannot be! How...', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25965),
(26608, 4, 0, 'Anub''et''kan is defeated! Take a fragment of his husk as proof of your victory!', 41, 0, 100, 0, 0, 0, 'Under-King Anub''et''kan',25999);

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE  `entry` =188463;

DELETE FROM `smart_scripts` WHERE `entryorguid` =188463 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(188463,1,0,1,70,0,100,0,2,0,0,0,45,1,1,0,0,0,0,19,26654,0,0,0,0,0,0,'Anub ar Mechanism - On State Changed - Set Data on Roanauk Icemist'),
(188463,1,1,0,61,0,100,0,2,0,0,0,70,600,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anub ar Mechanism - On State Changed - Despawn GO');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(26654,26772,26608,26656);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26654,26772,26608,26656) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2665400,2665401,2665402,2660800) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(26654, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 2665400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Data Set 1 1 - Run Script'),

(26654, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 26656, 0, 200, 0, 0, 0, 0, 'Roanauk Icemist - On Spawn - Set Data 1 1 on Anub''ar Prison'),
(26654, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Spawn - Set Phase 1'),
(26654, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 47273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Spawn - Cast Icemist''s Prison'),
(26654, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Spawn - Set Passive'),
(26654, 0, 5, 0, 1, 1, 100, 0, 5000, 30000, 120000, 150000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - OOC (Phase 1) - Say Line 0'),
(26654, 0, 6, 0, 34, 0, 100, 0, 0, 1, 0, 0, 80, 2665401, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Reached WP1 - Run Script'),
(26654, 0, 7, 0, 1, 0, 100, 0, 0, 0, 15000, 35000, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - OOC - Play emote OneShotRoar'),
(26654, 0, 8, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 2665402, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Data Set - Despawn'),
(26654, 0, 9, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 47379, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Agro - Cast Icemist''s Blessing'),
(26654, 0, 10, 0, 11, 0, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Respawn - Reset Scripts'),

(26656, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 47272, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anub''ar Prison - On Data Set 1 1 - Cast Anub''ar Prison'),
(26656, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 28, 47272, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anub''ar Prison - On Data Set 2 2 - Remove Anub''ar Prison'),
(26772, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On Spawn - Set Unit Flags'),
(26772, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On Spawn - Cast Permament Feign Death'),
(26772, 0, 2, 3, 8, 0, 100, 0, 47378, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On Spell Hit (Glory of the Ancestors) - Set Unit Flags'),
(26772, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 28, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On On Spell Hit (Glory of the Ancestors) - Cast Permament Feign Death'),
(26772, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 19, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On On Spell Hit (Glory of the Ancestors) - Set Unit Flags 2'),
(26772, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 96, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On On Spell Hit (Glory of the Ancestors) - Set Dynamic Flags'),
(26772, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 91, 257, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On On Spell Hit (Glory of the Ancestors) - Set Agressive'),
(26772, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On On Spell Hit (Glory of the Ancestors) - Set Agressive'),
(26772, 0, 8, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On Data Set - Despawn'),
(26608, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 97, 15, 10,  0, 0, 0, 0,  1, 0, 0, 0,4088.679932, 2219.449951, 150.304993, 0, 'Under-King Anub''et''kan - On Data Set - Jump to Position'),
(26608, 0, 2, 0, 1, 0, 100, 0, 0, 0, 25000, 45000, 1, 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - OOC - Say Line 0'),
(26608, 0, 2, 3, 6, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death  - Say Line 3'),
(26608, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0,  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death  - Say Line 4'),
(26608, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 11, 47400, 2, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death  - Cast Summon Husk'),
(26608, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1,  0, 0, 0, 0, 9, 26772, 0, 200, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death  - Set Data on Icemist'),
(26608, 0, 6, 10, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0,  0, 19, 26654, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death  - Set Data on Roanauk Icemist'),
(26608, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Data Set - Set Agressive'),
(26608, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Data Set - Set Unit Flags'),
(26608, 0, 9, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Spawn - Set Unit Flags'),
(26608, 0, 1, 7, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2660800, 2, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Data Set - Run Script'),
(26608, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death - Despawn'),
(2660800, 9, 0, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 101, 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - Script - Set Home Position'),
(2665400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 1'),
(2665400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 47273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Remove Aura Icemist''s Prison'),
(2665400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 26656, 0, 200, 0, 0, 0, 0, 'Roanauk Icemist - Script - Set Data 2 2 on Anub''ar Prison'),
(2665400, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Set Phase 2'),
(2665400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 26654, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Start WP'),
(2665401, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 2'),
(2665401, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 2'),
(2665401, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 3'),
(2665401, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 26608, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 1 on Under-King Anub''et''kan'),
(2665401, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 47378, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Cast Glory of the Ancestors'),
(2665401, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 4'),
(2665401, 9, 6, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 11, 47379, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Cast Icemist''s Blessing'),
(2665401, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 5'),
(2665401, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 6'),
(2665401, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 26608, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 2 on Under-King Anub''et''kan'),
(2665401, 9, 10, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 7'),
(2665401, 9, 11, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 26608, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 7'),
(2665401, 9, 12, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Set Unit Flags'),
(2665401, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Set Home Position'),
(2665401, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Set Agressive'),
(2665401, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 26608, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Attack'),


(2665402, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 3 - Set Invisible'),
(2665402, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 3 - Die');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(47378,47379);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 47378, 0, 0, 31, 0, 3, 26772, 0, 0, 0, 0, '', 'Glory of the Ancestors targets Icemist Warrior'),

(13, 1, 47379, 0, 0, 31, 0, 3, 26772, 0, 0, 0, 0, '', 'Icemists Blessing targets Icemist Warrior'),
(13, 1, 47379, 0, 1, 31, 0, 3, 26654, 0, 0, 0, 0, '', 'Icemists Blessing targets Roanauk Icemist'),
(13, 1, 47379, 0, 2, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Icemists Blessing targets Player');

DELETE FROM `waypoints` WHERE `entry`=26654;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(26654, 1, 4067.684, 2214.182, 151.9559, 'Roanauk Icemist');
DELETE FROM `creature_text` WHERE `entry`IN(26810,26379,26437);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(26810, 0, 0, 'Gather, brothers and sisters.', 12, 1, 100, 1, 0, 0, 'Roanauk Icemist',26136),
(26810, 1, 0, '%s reads from the scroll as the other Taunka gather around him.', 16, 1, 100, 0, 0, 0, 'Roanauk Icemist',26130),
(26810, 2, 0, 'Lok''tar ogar! Victory or death - it is these words that bind me to the Horde! For they are the most sacred and fundamental of truths to any warrior of the Horde.', 12, 1, 100, 1, 0, 0, 'Roanauk Icemist',26137),
(26810, 3, 0, 'I give my flesh and blood freely to the Warchief. I am the instrument of my Warchief''s desire. I am a weapon of my Warchief''s command!', 12, 1, 100, 1, 0, 0, 'Roanauk Icemist',26138),
(26810, 4, 0, 'From this moment until the end of days I live and die - For the Horde!', 12, 1, 100, 1, 0, 0, 'Roanauk Icemist',26139),
(26810, 5, 0, 'For my Taunka brothers and sisters! FOR THE HORDE!', 14, 1, 100, 388, 0, 0, 'Roanauk Icemist',26140),
(26379, 0, 0, 'We will walk together, $n.', 12, 1, 100, 1, 0, 0, 'Overlord Agmar',26131),
(26379, 1, 0, 'Welcome to the Horde, High Chief. Lok''tar ogar!', 12, 1, 100, 2, 0, 0, 'Overlord Agmar',26141),
(26379, 2, 0, 'FOR THE HORDE!', 14, 1, 100, 15, 0, 0, 'Overlord Agmar',26142),
(26437, 0, 0, 'Amidst the tragedy and chaos, this place stands defiantly against the Scourge! It is good to be Horde.', 12, 1, 100, 113, 0, 0, 'Taunka Soldier',25727);

UPDATE`creature` SET `position_x`=3842.386, `position_y`=1486.616, `position_z`=92.06059, `orientation`=1.570796 WHERE  `guid`=97430;

DELETE FROM `creature_addon` WHERE  `guid`=97430;

DELETE FROM `creature_template_addon` WHERE `entry`IN(26379);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(26379, 0, 0x6, 0x101, '47786'); -- 26379 - 47786


UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(26379,26437,26810);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26379,26437,26810,-102329,-102341,-102330,-102328,-102326,-102333,-102327,-102326) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2681000) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(26379, 0, 0, 1, 19, 0, 100, 0, 12140, 0, 0, 0, 81, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Set Npc Flags'),
(26379, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 91, 257, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Set Bytes 1'),
(26379, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Say Line 1'),
(26379, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 26379, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Quest Accept (All Hail Roanauk!) - Start WP'),
(26379, 0, 4, 0, 40, 0, 100, 0, 10, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On reached WP10 - Set Orientation'),
(26379, 0, 5, 0, 38, 0, 100, 0, 1, 1, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Data Set - Evade'),
(26379, 0, 6, 0, 21, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Agmar - On Reached Home - Set Unit Flags'),
(26810, 0, 0, 1, 62, 0, 100, 0, 9462, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Gossip Option select - Store Targetlist'),
(26810, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Gossip Option select - Close Gossip'),
(26810, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Gossip Option select - Set NPC Flags'),
(26810, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 26437, 0, 200, 0, 0, 0, 0, 'Roanauk Icemist - On Gossip Option select - Set Data Taunka Soldier'),
(26810, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2681000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Gossip Option select - Run Script'),
(-102329, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65539, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102329, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643700, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102329, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102329, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102341, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65539, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102341, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643701, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102341, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102341, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102330, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102330, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643702, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102330, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102330, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102328, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102328, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643703, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102328, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102328, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102326, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65537, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102326, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643704, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102326, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102326, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102333, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65537, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102333, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643705, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102333, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102333, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(-102327, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 91, 65536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Set Bytes 1'),
(-102327, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2643706, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Start WP'),
(-102327, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On Data Set - Evade'),
(-102327, 0, 3, 0, 34, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26810, 0, 0, 0, 0, 0, 0, 'Taunka Soldier - On reached WP1 - Set Orientation'),
(2681000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 1'),
(2681000, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 2'),
(2681000, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 2, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 3'),
(2681000, 9, 3, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 3, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 4'),
(2681000, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 4, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 5'),
(2681000, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0,  0, 0, 0, 19, 26379, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 1 on Overlord Agmar'),
(2681000, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 5, 15, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Play emote OneShotRoar'),
(2681000, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 33, 26810, 0, 0,  0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Give Kill Credit'),
(2681000, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 388, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Play emote OneShotStomp'),
(2681000, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 6'),
(2681000, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0,  0, 0, 0, 19, 26379, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 2 on Overlord Agmar'),
(2681000, 9, 11, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0,  0, 0, 0, 19, 26437, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 0 on Taunka Soldier'),
(2681000, 9, 12, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 2, 2, 0,  0, 0, 0, 9, 26437, 0, 200, 0, 0, 0, 0, 'Roanauk Icemist - Script - Set Data Taunka Soldier'),
(2681000, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0,  0, 0, 0, 19, 26379, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Set Data Overlord Agmar'),
(2681000, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Set NPC Flags');

DELETE FROM `waypoints` WHERE `entry`=26379;
DELETE FROM `waypoints` WHERE `entry` BETWEEN 2643700 AND 2643707;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(26379, 1, 3842.118, 1492.083, 91.71697, 'Overlord Agmar'),
(26379, 2, 3842.422, 1498.366, 91.98796, 'Overlord Agmar'),
(26379, 3, 3842.672, 1511.366, 91.98796, 'Overlord Agmar'),
(26379, 4, 3842.172, 1520.616, 91.73796, 'Overlord Agmar'),
(26379, 5, 3842.672, 1535.866, 90.23796, 'Overlord Agmar'),
(26379, 6, 3850.172, 1547.616, 90.23796, 'Overlord Agmar'),
(26379, 7, 3859.422, 1559.866, 90.23796, 'Overlord Agmar'),
(26379, 8, 3865.922, 1568.366, 90.23796, 'Overlord Agmar'),
(26379, 9, 3868.922, 1577.616, 90.23796, 'Overlord Agmar'),
(26379, 10, 3870.227, 1589.648, 89.75896, 'Overlord Agmar'),
(2643700, 1, 3872.902, 1594.418, 90.0797, 'Taunka Soldier'), -- 102329 
(2643701, 1, 3880.851, 1591.76, 90.98628, 'Taunka Soldier'), -- 102341 
(2643702, 1, 3874.775, 1589.399, 90.39027, 'Taunka Soldier'), -- 102330 
(2643703, 1, 3877.774, 1588.824, 90.92334, 'Taunka Soldier'), -- 102328 
(2643704, 1, 3876.746, 1597.52, 90.69058, 'Taunka Soldier'), -- 102326 
(2643705, 1, 3879.273, 1595.718, 90.78122, 'Taunka Soldier'), -- 102333 
(2643706, 1, 3873.469, 1597.843, 90.18542, 'Taunka Soldier'); -- 102327 

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(9461,9462);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9461, 0, 0, 'Greetings High Chief. Would you do me the honor of accepting my invitation to join the Horde as an official member and leader of the Taunka?', 26127, 1, 1, 9462, 0, 0, 0, '', 0),
(9462, 0, 0, 'It is you who honor me, High Chief. Please read from this scroll. It is the oath of allegiance.', 26129, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9461;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9461, 0, 0, 0, 9, 0, 12140, 0, 0, 0, 0, 0, '', 'Show gossip option only if player is on quest All Hail Roanak'),
(15, 9461, 0, 0, 0, 29, 0, 26379, 30, 0, 0, 0, 0, '', 'Show gossip option only if Overlord Agmar is within 30 yards');
DELETE FROM `creature_text` WHERE `entry`=29677;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(29677,0,0,'The %s sniffs the ground to pickup the trail.',16,0,100,0,0,0,30366,'Frosthound to Player'),
(29677,1,0,'You''ve been seen! Use the net and ice slick to keep the dwarves away!',42,0,100,0,0,0,30365,'Frosthound to Player'),
(29677,2,0,'The frosthound has located the thief''s hiding place. Confront him!',42,0,100,377,0,0,30368,'Frosthound to Player'),
(29677,3,0,'The %s has tracked the scent to its source.',16,0,100,377,0,0,30367,'Frosthound to Player');

UPDATE `creature_template` SET `spell1`=54997, `spell2`=54996,`ainame`='SmartAI' WHERE `entry`=29677;

DELETE FROM `smart_scripts` WHERE `entryorguid`=29677 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2967700 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29677,0,0,1,54,0,100,0,0,0,0,0,11,54993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - On Just Summoned - Cast Frosthound Periodic'),
(29677,0,1,0,61,0,100,0,0,0,0,0,80,2967700,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - On Just Summoned - Run Script'),
(29677,0,2,0,7,0,100,0,0,0,0,0,11,54993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - On Evade - Cast Frosthound Periodic'),
(29677,0,3,4,40,0,100,0,33,29677,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - On Reached WP33 - Say Line 2'),
(29677,0,4,5,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,'Frosthound - On Reached WP33 - Say Line 3'),
(29677,0,5,6,61,0,100,0,0,0,0,0,11,55036,0,0,0,0,0,23,0,0,0,0,0,0,0,'Frosthound - On Reached WP33 - Cast Frosthound Boss Emote 2'),
(29677,0,6,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - On Reached WP33 - Despawn'),

(2967700,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - Script - Say Line 0'),
(2967700,9,1,0,0,0,100,0,0,0,0,0,11,55026,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - Script - Cast Frosthound Boss Emote'),
(2967700,9,2,0,0,0,100,0,0,0,0,0,53,1,29677,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - Script - Start WP'),
(2967700,9,3,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frosthound - Script - Say Line 1');

DELETE FROM `waypoints` WHERE `entry`=29677;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(29677,1,7173.071,-777.0275,899.1846,'Frosthound'),
(29677,2,7182.944,-781.4821,904.6174,'Frosthound'),
(29677,3,7193.046,-787.1729,910.843,'Frosthound'),
(29677,4,7205.287,-793.2994,917.2863,'Frosthound'),
(29677,5,7218.268,-802.1098,921.6022,'Frosthound'),
(29677,6,7230.444,-816.3606,924.8938,'Frosthound'),
(29677,7,7232.167,-834.2318,926.6146,'Frosthound'),
(29677,8,7247.474,-848.1854,925.8355,'Frosthound'),
(29677,9,7263.333,-875.3375,925.127,'Frosthound'),
(29677,10,7275.556,-895.3395,926.4728,'Frosthound'),
(29677,11,7283.682,-922.1505,922.8227,'Frosthound'),
(29677,12,7284.952,-947.7603,918.976,'Frosthound'),
(29677,13,7294.833,-985.7026,915.6023,'Frosthound'),
(29677,14,7291.617,-973.3366,916.3897,'Frosthound'),
(29677,15,7321.158,-1040.365,912.3143,'Frosthound'),
(29677,16,7341.228,-1082.531,906.1441,'Frosthound'),
(29677,17,7355.963,-1127.951,907.6265,'Frosthound'),
(29677,18,7359.741,-1156.937,910.1899,'Frosthound'),
(29677,19,7352.817,-1172.477,912.4103,'Frosthound'),
(29677,20,7340.049,-1188.073,914.7924,'Frosthound'),
(29677,21,7330.804,-1201.472,915.7355,'Frosthound'),
(29677,22,7323.127,-1228.335,909.517,'Frosthound'),
(29677,23,7316.839,-1268.214,902.8563,'Frosthound'),
(29677,24,7316.317,-1300.765,904.0386,'Frosthound'),
(29677,25,7315.278,-1332.342,904.7114,'Frosthound'),
(29677,26,7313.02,-1366.275,907.1307,'Frosthound'),
(29677,27,7312.081,-1399.743,910.574,'Frosthound'),
(29677,28,7312.83,-1434.1,912.8854,'Frosthound'),
(29677,29,7311.606,-1466.343,916.7098,'Frosthound'),
(29677,30,7309.714,-1498.702,921.2195,'Frosthound'),
(29677,31,7306.879,-1531.19,928.3399,'Frosthound'),
(29677,32,7305.797,-1558.925,939.4229,'Frosthound'),
(29677,33,7305.19,-1566.019,941.0005,'Frosthound');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` =1 AND `SourceGroup` =29695 AND `SourceEntry` =40971;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(1,29695,40971,0,0,28,0,12855,0,0,0,0,0,'','Brann\'s Communicator'),
(1,29695,40971,0,0,2,0,40971,1,1,1,0,0,'','Brann\'s Communicator'),
(1,29695,40971,0,1,9,0,12855,0,0,0,0,0,'','Brann\'s Communicator'),
(1,29695,40971,0,1,2,0,40971,1,1,1,0,0,'','Brann\'s Communicator'),
(1,29695,40971,0,2,8,0,12855,0,0,0,0,0,'','Brann\'s Communicator'),
(1,29695,40971,0,2,2,0,40971,1,1,1,0,0,'','Brann\'s Communicator');

UPDATE `creature_loot_template` SET `QuestRequired`=0 WHERE  `Entry`=29695 AND `Item`=40971;
DELETE FROM `creature_template_addon` WHERE `entry`=25383;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(25383, 0, 0x0, 0x1, '45617'); -- 25383 - 45617

DELETE FROM `smart_scripts`  WHERE  `entryorguid`IN(25471,25472,25473) AND `source_type`=0;
UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(25471,25472,25473);

DELETE FROM `areatrigger_scripts` WHERE `entry` IN(4857,4858,4860);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4857,'SmartTrigger'),
(4858,'SmartTrigger'),
(4860,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(4857,4858,4860) AND `source_type`=2;
INSERT  INTO `smart_scripts`  (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)  VALUES
(4857,2,0,1,46,0,100,0,4857,0,0,0,85,45627,2,0,0,0,0,7,0,0,0,0,0,0,0,'Area Trigger 4857 - On Trigger - invoker cast Temple A Credit'),
(4858,2,0,1,46,0,100,0,4858,0,0,0,85,45628,2,0,0,0,0,7,0,0,0,0,0,0,0,'Area Trigger 4858 - On Trigger - invoker cast Temple B Credit'),
(4860,2,0,1,46,0,100,0,4860,0,0,0,85,45629,2,0,0,0,0,7,0,0,0,0,0,0,0,'Area Trigger 4860 - On Trigger - invoker cast Temple C Credit');
SET @CGUID=75031;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(27315,27336);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN(27315,27336);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27315,0,0,1,8,0,100,0,48363,0,0,0,28,49774,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - Remove Aura'),
(27315,0,1,2,61,0,100,0,0,0,0,0,11,43671,0,0,0,0,0,7,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - mount to invoker'),
(27315,0,2,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - set phasemask to 2'),
(27315,0,3,0,1,2,100,1,5000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - OOC (Phase 2) - Say text 0'),
(27315,0,4,5,23,2,100,1,43671,0,1000,1000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - On Aura Missing - say text'),
(27315,0,5,0,61,2,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - On Aura Missing -  despawn after 2 secs'),
(27336,0,0,1,8,0,100,0,48363,0,0,0,28,49774,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - Remove Aura'),
(27336,0,1,2,61,0,100,0,0,0,0,0,11,43671,0,0,0,0,0,7,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - mount to invoker'),
(27336,0,2,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - on spellhit - set phasemask to 2'),
(27336,0,3,0,1,2,100,1,5000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - OOC (Phase 2) - Say text 0'),
(27336,0,4,5,23,2,100,1,43671,0,1000,1000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - On Aura Missing - say text'),
(27336,0,5,0,61,2,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Helpless Wintergarde Villager - On Aura Missing -  despawn after 2 secs');

/* aura for mount */
DELETE FROM `creature_template_addon` WHERE `entry`=27258;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(27258, 0, 0, 33554432, 0, 0, '34873');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN(13,17) AND `SourceEntry` IN(48397,48363);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 48397, 0, 0, 29, 0, 27315, 5, 1, 0, 0, 0, '', 'Required NPC to cast Spell'),
(17, 0, 48397, 0, 1, 29, 0, 27336, 5, 1, 0, 0, 0, '', 'Required NPC to cast Spell'),
(17, 0, 48397, 0, 0, 30, 0, 300199, 15, 0, 0, 0, 0, '', 'Spell focus for Drop Off Helpless Wintergarde Villager'),
(13, 2, 48397, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Drop Off Villager Effect #2 Targets Player'),
(13, 1, 48363, 0, 0, 31, 0, 3, 27315, 0, 0, 0, 0, '', 'Grab  targets Helpless Wintergarde Villager'),
(17, 0, 48363, 0, 0, 29, 0, 27315, 5, 1, 0, 0, 0, '', 'Required NPC to cast Spell'),
(13, 1, 48363, 0, 1, 31, 0, 3, 27336, 0, 0, 0, 0, '', 'Grab  targets Helpless Wintergarde Villager'),
(17, 0, 48363, 0, 1, 29, 0, 27336, 5, 1, 0, 0, 0, '', 'Required NPC to cast Spell');

UPDATE `creature_template` SET `faction`=35 WHERE  `entry`=27258;
UPDATE `creature_template` SET `exp`=2, `speed_walk`=1, `speed_run`=1.142857,`faction`=35 WHERE  `entry`=27258;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=48397;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(48397, -43671, 0, 'remove npc');

UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=68, `unit_flags`=33536 WHERE  `entry`=27336;
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=70, `unit_flags`=33536 WHERE  `entry`=27315;

DELETE FROM `creature_text` WHERE `entry` IN(27315,27336);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES 
(27315, 0, 0, 'Are you sure you know how to fly this thing? Feels a little wobbly.', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26359),
(27315, 0, 1, 'I don\'t mean to sound ungrateful, but could you fly a little closer to the ground? I hate heights!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26360),
(27315, 0, 2, 'I picked a bad day to stop drinking!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26345),
(27315, 0, 3, 'I\'m gettin\' a little woozy... Oooooof...', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26364),
(27315, 0, 4, 'You saved my life! Thanks!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26358),
(27315, 0, 5, 'You are my guardian angel! Like a white knight you flew in from the heavens and lifted me from the pit of damnation!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26362),
(27315, 1, 0, 'How can I ever repay you for this, friend?', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26363),
(27315, 1, 1, 'HURRAY!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26382),
(27315, 1, 2, 'Kindness is not lost with this one, Urik. Thank you, hero!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26383),
(27315, 1, 3, 'My shop\'s doors will always be open to you, friend.', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26385),
(27315, 1, 4, 'Safe at last! Thank you, stranger!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26381),
(27315, 1, 5, 'Thanks for your help, hero!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26357),
(27315, 1, 6, 'We made it! We actually made it!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26384),
(27336, 0, 0, 'Are you sure you know how to fly this thing? Feels a little wobbly.', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26359),
(27336, 0, 1, 'I don\'t mean to sound ungrateful, but could you fly a little closer to the ground? I hate heights!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26360),
(27336, 0, 2, 'I picked a bad day to stop drinking!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26345),
(27336, 0, 3, 'I\'m gettin\' a little woozy... Oooooof...', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26364),
(27336, 0, 4, 'You saved my life! Thanks!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26358),
(27336, 0, 5, 'You are my guardian angel! Like a white knight you flew in from the heavens and lifted me from the pit of damnation!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26362),
(27336, 1, 0, 'How can I ever repay you for this, friend?', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26363),
(27336, 1, 1, 'HURRAY!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26382),
(27336, 1, 2, 'Kindness is not lost with this one, Urik. Thank you, hero!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26383),
(27336, 1, 3, 'My shop\'s doors will always be open to you, friend.', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26385),
(27336, 1, 4, 'Safe at last! Thank you, stranger!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26381),
(27336, 1, 5, 'Thanks for your help, hero!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26357),
(27336, 1, 6, 'We made it! We actually made it!', 12, 0, 100, 0, 0, 0, 'Helpless Wintergarde Villager',26384);

DELETE FROM `creature` WHERE `id` IN(27336,27315);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 27336, 571, 1, 1, 3846.755, -929.0404, 112.8907, 4.708376, 120, 5, 1), -- 27336 (Area: 4177) (possible waypoints or random movement)
(@CGUID+1, 27336, 571, 1, 1, 3889.424, -935.4798, 115.6459, 1.28458, 120, 5, 1), -- 27336 (Area: 4177) (possible waypoints or random movement)
(@CGUID+2, 27336, 571, 1, 1, 3878.463, -985.8888, 116.4584, 5.028894, 120, 5, 1), -- 27336 (Area: 4177) (possible waypoints or random movement)
(@CGUID+3, 27336, 571, 1, 1, 3823.805, -1083.309, 119.5392, 1.963927, 120, 5, 1), -- 27336 (Area: 4177) (possible waypoints or random movement)
(@CGUID+4, 27336, 571, 1, 1, 3817.068, -1048.894, 119.9088, 1.822633, 120, 5, 1), -- 27336 (Area: 4177) (possible waypoints or random movement)
(@CGUID+5, 27336, 571, 1, 1, 3771.587, -1131.885, 121.5405, 5.288348, 120, 5, 1), -- 27336 (Area: 4188) (possible waypoints or random movement)
(@CGUID+6, 27336, 571, 1, 1, 3583.055, -1331.913, 109.3448, 6.212783, 120, 5, 1), -- 27336 (Area: 4188) (possible waypoints or random movement)
(@CGUID+7, 27315, 571, 1, 1, 3822.955, -1128.766, 120.1993, 5.973483, 120, 5, 1), -- 27315 (Area: 4188) (possible waypoints or random movement)
(@CGUID+8, 27315, 571, 1, 1, 3664.299, -1270.015, 112.583, 5.268541, 120, 5, 1), -- 27315 (Area: 4188) (possible waypoints or random movement)
(@CGUID+9, 27315, 571, 1, 1, 3625.333, -1260.047, 112.6119, 6.237288, 120, 5, 1), -- 27315 (Area: 4188) (possible waypoints or random movement)
(@CGUID+10, 27315, 571, 1, 1, 3721.795, -1345.791, 133.6774, 0.2871537, 120, 5, 1), -- 27315 (Area: 4188) (possible waypoints or random movement)
(@CGUID+11, 27315, 571, 1, 1, 3718.502, -1323.397, 125.0354, 1.818619, 120, 5, 1), -- 27315 (Area: 4234) (possible waypoints or random movement)
(@CGUID+12, 27315, 571, 1, 1, 3768.525, -1289.776, 133.6532, 4.827796, 120, 5, 1), -- 27315 (Area: 4234) (possible waypoints or random movement)
(@CGUID+13, 27336, 571, 1, 1, 3707.695, -1138.643, 120.2261, 4.974188, 120, 0, 0); -- 27336 (Area: 4188)

DELETE FROM `creature_template_addon` WHERE `entry` IN(27336,27315);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(27336, 0, 0x0, 0x1, '48361 49774'), -- 27336 - 48361, 49774
(27315, 0, 0x10000, 0x1, '48361 49774'); -- 27315 - 48361, 49774

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=27258;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(16, 0, 27258, 0, 0, 23, 0, 4188, 0, 0, 0, 0, 0, '', 'Dismount player when not in intended zone'),
(16, 0, 27258, 0, 1, 23, 0, 4177, 0, 0, 0, 0, 0, '', 'Dismount player when not in intended zone'),
(16, 0, 27258, 0, 2, 23, 0, 4178, 0, 0, 0, 0, 0, '', 'Dismount player when not in intended zone');
UPDATE `conditions` SET `ConditionValue1`=188679 WHERE `ConditionValue1`=300199;
DELETE FROM `creature_queststarter` WHERE `quest`=14351;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES 
(2215, 14351);
-- UPDATE `quest_template` SET `NextQuestIDChain`=14351 WHERE  `Id`=541;
-- UPDATE `quest_template` SET `PrevQuestID`=541 WHERE  `Id`=14351;
UPDATE `spell_area` SET `quest_start_status`=74 WHERE  `spell`=57745 AND `area`=4591 AND `quest_start`=13068 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=24035;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI',  `ScriptName`='' WHERE   `entry`IN(186491,186492,186493,186494,186498,186499,186500,186501,186502,186503,186504,186505,186508,186509,186512,186513,186514,186515,186516,186883,186895,186907,186908,186910,186911,186923,186924,186495,186496,186497,186507,186510,186511,186517,186518,186798,186909,186929,186930,186490);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN  (24035,186491,186492,18649100,186493,186494,186498,186499,186500,186501,186502,186503,186504,186505,186508,186509,186512,186513,186514,186515,186516,186883,186895,186907,186908,186910,186911,186923,186924,186495,186496,186497,186507,186510,186511,186517,186518,186798,186909,186929,186930,186490,18649000);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`,  `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`,  `event_param1`, `event_param2`, `event_param3`, `event_param4`,  `action_type`, `action_param1`, `action_param2`, `action_param3`,  `action_param4`, `action_param5`, `action_param6`, `target_type`,  `target_param1`, `target_param2`, `target_param3`, `target_x`,  `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186491, 1,  0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186492, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186493, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186494, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186495, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186496, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186497, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186498, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186499, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186500, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186501, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186502, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186503, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186504, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186505, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186507, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186508, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186509, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186510, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186511, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186512, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186513, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186514, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186515, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186516, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186517, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186518, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186798, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186883, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186895, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186907, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186908, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186909, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186910, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186911, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186923, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186924, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186929, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186930, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Gjalerbron Cage - On State Changed - Run Script'),
(186490, 1, 0  ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649000,2,0,0,0,0,1,0,0,0,0, 0, 0, 0,  'Large Gjalerbron Cage - On State Changed - Run Script'),
(24035, 0, 0 ,1,38, 0, 100, 0, 1, 1, 0,0,1,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Prisoner - On Data Set - Say'),
(24035, 0, 1 ,0,61, 0, 100, 0, 1, 1, 0,0,41,2000,0,0,0,0,0,1,0,0,0,0,  0, 0, 0, 'Gjalerbron Prisoner - Linked with Previous Event - Despawn  after 2 seconds'),
(18649100, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,9,24035,0,5,0, 0, 0, 0, 'Gjalerbron Cage - Script - Set Data'),
(18649100, 9, 1 ,0, 0, 0, 100, 0, 0, 0, 0,0,33,24035,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - Script - Kill Credit'),
(18649100, 9, 2 ,0, 0, 0, 100, 0, 300000, 300000,  0,0,32,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - Script - Reset  Go'),
(18649000, 9, 0 ,0, 0, 0, 100, 0, 0, 0,  0,0,45,1,1,0,0,0,0,9,24035,0,5,0, 0, 0, 0, 'Large Gjalerbron Cage -  Script - Set Data'),
(18649000, 9, 1 ,0, 0, 0, 100, 0, 0, 0,  0,0,33,24035,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage -  Script - Kill Credit'),
(18649000, 9, 2 ,0, 0, 0, 100, 0, 0, 0,  0,0,33,24035,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage -  Script - Kill Credit'),
(18649000, 9, 3 ,0, 0, 0, 100, 0, 0, 0,  0,0,33,24035,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage-  Script - Kill Credit'),
(18649000, 9, 4 ,0, 0, 0, 100, 0, 0, 0,  0,0,33,24035,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage -  Script - Kill Credit'),
(18649000, 9, 5 ,0, 0, 0, 100, 0, 0, 0,  0,0,33,24035,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage -  Script - Kill Credit'),
(18649000, 9, 6 ,0, 0, 0, 100, 0, 300000,  300000, 0,0,32,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage -  Script - Reset Go');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24035;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`,  `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`,  `ConditionTarget`, `ConditionValue1`, `ConditionValue2`,  `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`,  `Comment`) VALUES
(22, 1, 24035, 0, 0, 36, 1, 0, 0, 0, 0, 0, '','Only execute SAI if Gjalerbron Prisoner alive');
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE  `Id`=12933;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry`=12933;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 12933, 0, 0, 8, 0, 12932, 0, 0, 0, 0, 0, '', 'The Amphitheater of Anguish: Magnataur! after The Amphitheater of Anguish: Yggdras!'),
(20, 0, 12933, 0, 0, 8, 0, 12932, 0, 0, 0, 0, 0, '', 'The Amphitheater of Anguish: Magnataur! after The Amphitheater of Anguish: Yggdras!'),
(19, 0, 12933, 0, 1, 8, 0, 12954, 0, 0, 0, 0, 0, '', 'The Amphitheater of Anguish: Magnataur! after The Amphitheater of Anguish: Yggdras!'),
(20, 0, 12933, 0, 1, 8, 0, 12954, 0, 0, 0, 0, 0, '', 'The Amphitheater of Anguish: Magnataur! after The Amphitheater of Anguish: Yggdras!');
--
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (4857,4858,4860) AND `source_type`=2;
--
UPDATE `game_tele` SET `name`='FarstriderRetreat' WHERE `id`=367;
--
UPDATE `command` SET `help`='Syntax: .titles current #title\r\nSet title #title (id or shift-link) as current selected title for selected player. If title is not in known title list for player then it will be added to list.' WHERE `name`='titles current';
UPDATE `smart_scripts` SET `event_type`=0 WHERE  `entryorguid`=3636 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`IN(-53017);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-53017, 48330, 0,'On Indisposed Expiring - Cast Create Amberseeds');
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=28747 AND `source_type`=0 AND `id`=6 AND `link`=0;UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=28748 AND `source_type`=0 AND `id`=5 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28747 AND `source_type`=0 AND `id`=7;DELETE FROM `smart_scripts` WHERE `entryorguid`=28748 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28747, 0, 7, 0, 4, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Quetz\'lun Worshipper - On Agro - Store Targetlist'),
(28748, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Serpent-Touched Berserker - On Agro - Store Targetlist');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 26560 AND `spell_effect`=18280;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES (26560, 18280, 0, 'Summon Lord-Commander Arete');
UPDATE `smart_scripts` SET `event_param1`=12 WHERE  `entryorguid`=31279 AND `source_type`=0 AND `id`=18 AND `link`=0;
UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid` IN(24874,24875,24876,24877) AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=45323;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES(0, 45323, 64, '', '', 'Ignore LOS for Returning Vrykul Artifact');
UPDATE `creature_template` SET `unit_flags`=768 WHERE  `entry`=24889;
UPDATE `spell_area` SET `quest_start_status`=74 WHERE  `spell`=57745 AND `area`=4591 AND `quest_start`=13068 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=24018 AND `SourceEntry` IN(34090,34091);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(1, 24018, 34090, 0, 0, 8, 0, 11236, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player is rewarded for Necro Overlord Mezhen'),
(1, 24018, 34091, 0, 0, 8, 0, 11264, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player is rewarded for Necro Overlord Mezhen'),
(1, 24018, 34090, 0, 1, 9, 0, 11236, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player has taken Necro Overlord Mezhen'),
(1, 24018, 34091, 0, 1, 9, 0, 11264, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player has taken Necro Overlord Mezhen'),
(1, 24018, 34090, 0, 2,28, 0, 11236, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player has completed Necro Overlord Mezhen'),
(1, 24018, 34091, 0, 2,28, 0, 11264, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player has completed Necro Overlord Mezhen');
UPDATE `smart_scripts` SET `action_param4`=1 WHERE  `entryorguid`=21352 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_param4`=1 WHERE  `entryorguid`=21498 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_param4`=1 WHERE  `entryorguid`=21498 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `gameobject_loot_template` SET `maxcount`=4 WHERE  `entry`=1502 AND `item`=2770;
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=32239;
SET @VARIDUS := 25618;
SET @GETRY := 25729;
SET @NECROLORD := 25730;
SET @SAURFANG := 25751;

UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=@SAURFANG;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GETRY,@NECROLORD,@SAURFANG) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@VARIDUS*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NECROLORD,0,0,0,11,0,100,0,0,0,0,0,53,0,@NECROLORD,0,0,0,0,1,0,0,0,0,0,0,0, 'En''kilah Necrolord - On spawn - Start WP movement'),
(@NECROLORD,0,1,2,40,0,100,0,2,@NECROLORD,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'En''kilah Necrolord - On reached WP1 - Set home position'),
(@NECROLORD,0,2,0,61,0,100,0,0,0,0,0,45,0,4,0,0,0,0,19,@VARIDUS,10,0,0,0,0,0, 'En''kilah Necrolord - On reached WP1 - Set data 0 4 Varidus the Flenser'),
(@NECROLORD,0,3,4,38,0,100,0,5,1,0,0,66,0,0,0,0,0,0,19,@VARIDUS,10,0,0,0,0,0, 'En''kilah Necrolord - On data 0 1 set - Turn to'),
(@NECROLORD,0,4,5,61,0,100,0,0,0,0,0,12,@SAURFANG,1,300000,0,0,0,1,0,0,0,0,0,0,0, 'En''kilah Necrolord - On data 0 1 set - Change entry to High Overlord Saurfang'),
(@NECROLORD,0,5,6,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@SAURFANG,0,0,0,0,0,0, 'En''kilah Necrolord - On data 0 1 set - Change entry to High Overlord Saurfang'),
(@NECROLORD,0,6,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'En''kilah Necrolord - On data 0 1 set - Change entry to High Overlord Saurfang'),
(@SAURFANG,0,0,0,38,0,100,0,5,2,0,0,1,0,2500,0,0,0,0,12,1,0,0,0,0,0,0, 'High Overlord Saurfang - On data 0 2 set - Say line'),
(@SAURFANG,0,1,0,52,0,100,0,0,@SAURFANG,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'High Overlord Saurfang - On text 0 over - Turn to'),
(@SAURFANG,0,2,0,38,0,100,0,5,3,0,0,1,1,4000,0,0,0,0,12,1,0,0,0,0,0,0, 'High Overlord Saurfang - On data 0 3 set - Say line'),
(@SAURFANG,0,3,0,52,0,100,0,1,@SAURFANG,0,0,66,0,0,0,0,0,0,19,@VARIDUS,10,0,0,0,0,0, 'High Overlord Saurfang - On text 1 over - Turn to'),
(@SAURFANG,0,4,0,38,0,100,0,5,4,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 0 4 set - Say line'),
(@SAURFANG,0,5,0,52,0,100,0,2,@SAURFANG,0,0,1,3,12000,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On text 2 over - Say line'),
(@SAURFANG,0,6,0,52,0,100,0,3,@SAURFANG,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On text 3 over - Say line'),
(@SAURFANG,0,7,8,38,0,100,0,1,1,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 1 1 set - Remove unit_flags IMMUNE_TO_NPC'),
(@SAURFANG,0,8,9,61,0,100,0,0,0,0,0,11,45950,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 1 1 set - Spellcast Saurfang''s Rage'),
(@SAURFANG,0,9,0,61,0,100,0,0,0,0,0,1,5,1000,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 1 1 set - Say line'),
(@SAURFANG,0,10,0,52,0,100,0,5,@SAURFANG,0,0,1,6,1000,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On text 5 over - Say line'),
(@SAURFANG,0,11,0,61,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On text 7 over - Despawn after 3 seconds'),
(@SAURFANG,0,12,0,9,0,100,0,0,5,20000,25000,11,41097,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On target within 5y - Spellcast Whirlwind'),
(@SAURFANG,0,13,0,0,0,100,0,3000,7000,3000,8000,11,16044,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On update IC - Spellcast Cleave'),
(@SAURFANG,0,14,0,0,0,100,0,2000,7000,5000,7000,11,24573,0,0,0,0,0,2,0,0,0,0,0,0,0, 'High Overlord Saurfang - On update IC - Spellcast Mortal Strike'),
(@SAURFANG,0,15,0,9,0,100,0,8,25,5000,5000,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0, 'High Overlord Saurfang - On target within 8-25y - Spellcast Shield Charge'),
(@SAURFANG,0,16,0,38,0,100,0,5,5,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'High Overlord Saurfang - On data 0 5 set - Turn to'),
(@SAURFANG,0,17,0,38,0,100,0,1,2,0,0,1,7,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 1 2 set - Say line'),
(@SAURFANG,0,18,11,52,0,100,0,7,@SAURFANG,0,0,45,1,4,0,0,0,0,19,@GETRY,20,0,0,0,0,0, 'High Overlord Saurfang - On text 7 over - Set data 1 4 Shadowstalker Getry'),
(@SAURFANG,0,19,0,38,0,100,0,2,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 2 2 set - Despawn'),
(@VARIDUS*100,9,0,0,0,0,100,0,0,0,0,0,45,5,5,0,0,0,0,19,@NECROLORD,10,0,0,0,0,0, 'Varidus the Flenser script - Set data 0 5 En''kilah Necrolord'),
(@VARIDUS*100,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,2,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,3,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,4,0,0,0,100,0,4000,4000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,5,0,0,0,100,0,6000,6000,0,0,66,0,0,0,0,0,0,19,@NECROLORD,10,0,0,0,0,0, 'Varidus the Flenser script - Turn to'),
(@VARIDUS*100,9,6,0,0,0,100,0,1000,1000,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,7,0,0,0,100,0,6000,6000,0,0,45,5,1,0,0,0,0,19,@NECROLORD,10,0,0,0,0,0, 'Varidus the Flenser script - Set data 0 1 En''kilah Necrolord'),
(@VARIDUS*100,9,8,0,0,0,100,0,1000,1000,0,0,45,5,2,0,0,0,0,19,@SAURFANG,10,0,0,0,0,0, 'Varidus the Flenser script - Set data 0 2 High Overlord Saurfang'),
(@VARIDUS*100,9,9,0,0,0,100,0,1500,1500,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,10,0,0,0,100,0,2000,2000,0,0,45,5,3,0,0,0,0,19,@SAURFANG,10,0,0,0,0,0, 'Varidus the Flenser script - Set data 0 3 High Overlord Saurfang'),
(@VARIDUS*100,9,11,0,0,0,100,0,5000,5000,0,0,45,5,4,0,0,0,0,19,@SAURFANG,10,0,0,0,0,0, 'Varidus the Flenser script - Set data 0 4 High Overlord Saurfang'),
(@VARIDUS*100,9,12,0,0,0,100,0,13000,13000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,13,0,0,0,100,0,10000,10000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,14,0,0,0,100,0,2000,2000,0,0,1,10,2000,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On text 9 over - Say line'),
(@VARIDUS*100,9,15,0,0,0,100,0,0,0,0,0,11,45949,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Spellcast Release Aberration'),
(@VARIDUS*100,9,16,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,@GETRY,20,0,0,0,0,0, 'Varidus the Flenser script - Set data 1 1 Shadowstalker Getry'),
(@VARIDUS*100,9,17,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,@SAURFANG,20,0,0,0,0,0, 'Varidus the Flenser script - Set data 1 1 Saurfang');
SET @QUEST := 11705;
SET @VARIDUS := 25618;
SET @GETRY := 25729;
SET @NECROLORD := 25730;
SET @SAURFANG := 25751;

DELETE FROM `smart_scripts` WHERE `entryorguid` =@GETRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GETRY,0,0,1,19,0,100,0,@QUEST,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Store targetlist'),
(@GETRY,0,1,2,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Remove npcflag questgiver'),
(@GETRY,0,2,3,61,0,100,0,0,0,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Say line'),
(@GETRY,0,3,4,61,0,100,0,0,0,0,0,11,45924,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Spellcast On Getry''s Quest'),
(@GETRY,0,4,5,61,0,100,0,0,0,0,0,11,45924,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Spellcast On Getry''s Quest'),
(@GETRY,0,5,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@VARIDUS,50,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Set data 0 1 Varidus the Flenser'),
(@GETRY,0,6,7,52,0,100,0,0,@GETRY,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On text 0 over - Say line'),
(@GETRY,0,7,0,61,0,100,0,0,0,0,0,53,0,@GETRY,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On text 0 over - Start WP'),
(@GETRY,0,8,0,11,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On spawn - Set npcflag questgiver'),
(@GETRY,0,9,0,40,0,100,0,8,@GETRY,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP8 reached - Spellcast Stealth'),
(@GETRY,0,10,11,40,0,100,0,9,@GETRY,0,0,45,0,2,0,0,0,0,19,@VARIDUS,30,0,0,0,0,0, 'Shadowstalker Getry - On WP 9 reached - Set data 0 2 Varidus the Flenser'),
(@GETRY,0,11,0,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@VARIDUS,30,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Send targetlist to Varidus the Flenser'),
(@GETRY,0,12,13,40,0,100,0,10,@GETRY,0,0,66,0,0,0,0,0,0,19,@VARIDUS,20,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Turn to'),
(@GETRY,0,13,14,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Set home position'),
(@GETRY,0,14,15,61,0,100,0,0,0,0,0,28,34189,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Remove aura Stealth'),
(@GETRY,0,15,16,61,0,100,0,0,0,0,0,11,45922,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Spellcast Shadow Prison'),
(@GETRY,0,16,17,61,0,100,0,0,0,0,0,86,45922,0,12,1,0,0,12,1,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Crosscast Shadow Prison'),
(@GETRY,0,17,0,61,0,100,0,0,0,0,0,45,0,3,0,0,0,0,19,@VARIDUS,20,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Set Data 0 3 Varidus the Flenser'),
(@GETRY,0,18,19,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On data 1 1 set - Remove unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC'),
(@GETRY,0,19,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,@VARIDUS,20,0,0,0,0,0, 'Shadowstalker Getry - On data 1 1 set - Start attack'),
(@GETRY,0,20,21,38,0,100,0,1,3,0,0,15,@QUEST,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Shadowstalker Getry - On data 1 3 set - Quest credit'),
(@GETRY,0,21,0,61,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On data 1 3 set - Say line'),
(@GETRY,0,22,0,52,0,100,0,2,@GETRY,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On text 2 over - Say line'),
(@GETRY,0,23,0,52,0,100,0,3,@GETRY,0,0,45,1,2,0,0,0,0,19,@SAURFANG,20,0,0,0,0,0, 'Shadowstalker Getry - On text 3 over - Set data 1 2 High Overlord Saurfang'),
(@GETRY,0,24,0,38,0,100,0,1,4,0,0,53,0,@GETRY*100,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On data 1 4 set - Start WP movement'),
(@GETRY,0,26,27,40,0,100,0,10,@GETRY*100,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached (Return) - Set npcflag questgiver'),
(@GETRY,0,27,28,61,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached (Return) - Set unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC'),
(@GETRY,0,28,0,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached (Return) - Set homeposition'),
(@GETRY,0,29,30,8,0,100,0,45950,0,0,0,28,45922,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On spellhit Saurfangs Rage - Remove aura Shadow Prison'),
(@GETRY,0,30,0,61,0,100,0,0,0,0,0,28,45922,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Shadowstalker Getry - On spellhit Saurfangs Rage - Remove aura Shadow Prison'),
(@GETRY,0,31,32,6,0,100,0,0,0,0,0,6,@QUEST,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Shadowstalker Getry - On Death - Fail Quest'),
(@GETRY,0,32,33,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,@VARIDUS,0,0,0,0,0,0, 'Shadowstalker Getry - On Death - Set Data 2 2 Varidus'),
(@GETRY,0,33,34,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,@NECROLORD,0,0,0,0,0,0, 'Shadowstalker Getry - On Death - Set Data 2 2 Varidus'),
(@GETRY,0,34,0,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,@SAURFANG,0,0,0,0,0,0, 'Shadowstalker Getry - On Death - Set Data 2 2 Varidus');
--
UPDATE `creature_template` SET `unit_class`=4,`speed_walk`=8,`speed_run`=2.85714 WHERE `entry` IN (30161,31752); -- Wyrmrest Skytalon
--
UPDATE  creature_template  SET  Unit_class  = 4 WHERE  entry  = 30645;
UPDATE `creature_template` SET `faction`=35,`unit_flags`=0 WHERE `entry` IN 
(33562,33559,33558,33564,33561,33382,33383,33384,33306,33285,33739,33738,33747,33743,33740,33746,33748,33744,33745,33749);

-- Darnassus Champion
UPDATE `creature_template` SET `gossip_menu_id`=10453 WHERE `entry`=33738;
-- Exodar Champion
UPDATE `creature_template` SET `gossip_menu_id`=10454 WHERE `entry`=33739;
-- Gnomeregan Champion
UPDATE `creature_template` SET `gossip_menu_id`=10455 WHERE `entry`=33740;
-- Ironforge Champion
UPDATE `creature_template` SET `gossip_menu_id`=10456 WHERE `entry`=33743;
-- Orgrimmar Champion
UPDATE `creature_template` SET `gossip_menu_id`=10457 WHERE `entry`=33744;
-- Sen'jin Champion
UPDATE `creature_template` SET `gossip_menu_id`=10458 WHERE `entry`=33745;
-- Silvermoon Champion
UPDATE `creature_template` SET `gossip_menu_id`=10459 WHERE `entry`=33746;
-- Stormwind Champion
UPDATE `creature_template` SET `gossip_menu_id`=10460 WHERE `entry`=33747;
-- Thunder Bluff Champion
UPDATE `creature_template` SET `gossip_menu_id`=10461 WHERE `entry`=33748;
-- Undercity Champion
UPDATE `creature_template` SET `gossip_menu_id`=10462 WHERE `entry`=33749;
-- Darnassus Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10464 WHERE `entry`=33559;
-- Exodar Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10465 WHERE `entry`=33562;
-- Gnomeregan Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10466 WHERE `entry`=33558;
-- Ironforge Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10467 WHERE `entry`=33564;
-- Orgrimmar Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10468 WHERE `entry`=33306;
-- Sen'jin Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10469 WHERE `entry`=33285;
-- Silvermoon Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10470 WHERE `entry`=33382;
-- Stormwind Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10471 WHERE `entry`=33561;
-- Thunder Bluff Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10472 WHERE `entry`=33383;
-- Undercity Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10473 WHERE `entry`=33384;

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10453,10454,10455,10456,10457,10458,10459,10460,10461,10462,10464,10465,10466,10467,10468,10469,10470,10471,10472,10473);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES 
(10469, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10468, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10470, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10472, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10473, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10466, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10464, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10471, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10465, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10467, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10453, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10454, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10455, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10456, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10457, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10458, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10459, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10460, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10461, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10462, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0);
-- Champions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (10453,10454,10455,10456,10457,10458,10459,10460,10461,10462);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(15, 10453, 0, 0, 0, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Darnassus Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10453, 0, 0, 0, 9, 0, 13793, 0, 0, 0, 0, 0, '', 'Darnassus Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10453, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Darnassus Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10453, 0, 0, 1, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Darnassus Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10453, 0, 0, 1, 9, 0, 13790, 0, 0, 0, 0, 0, '', 'Darnassus Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10453, 0, 0, 1, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Darnassus Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10453, 0, 0, 2, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Darnassus Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10453, 0, 0, 2, 9, 0, 13814, 0, 0, 0, 0, 0, '', 'Darnassus Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10453, 0, 0, 2, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Darnassus Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10453, 0, 0, 3, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Darnassus Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10453, 0, 0, 3, 9, 0, 13811, 0, 0, 0, 0, 0, '', 'Darnassus Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10453, 0, 0, 3, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Darnassus Champion - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10454, 0, 0, 0, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Exodar Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10454, 0, 0, 0, 9, 0, 13793, 0, 0, 0, 0, 0, '', 'Exodar Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10454, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Exodar Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10454, 0, 0, 1, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Exodar Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10454, 0, 0, 1, 9, 0, 13790, 0, 0, 0, 0, 0, '', 'Exodar Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10454, 0, 0, 1, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Exodar Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10454, 0, 0, 2, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Exodar Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10454, 0, 0, 2, 9, 0, 13814, 0, 0, 0, 0, 0, '', 'Exodar Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10454, 0, 0, 2, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Exodar Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10454, 0, 0, 3, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Exodar Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10454, 0, 0, 3, 9, 0, 13811, 0, 0, 0, 0, 0, '', 'Exodar Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10454, 0, 0, 3, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Exodar Champion - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10455, 0, 0, 0, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10455, 0, 0, 0, 9, 0, 13793, 0, 0, 0, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10455, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10455, 0, 0, 1, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10455, 0, 0, 1, 9, 0, 13790, 0, 0, 0, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10455, 0, 0, 1, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10455, 0, 0, 2, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10455, 0, 0, 2, 9, 0, 13814, 0, 0, 0, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10455, 0, 0, 2, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10455, 0, 0, 3, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10455, 0, 0, 3, 9, 0, 13811, 0, 0, 0, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10455, 0, 0, 3, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Gnomeregan Champion - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10456, 0, 0, 0, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Ironforge Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10456, 0, 0, 0, 9, 0, 13793, 0, 0, 0, 0, 0, '', 'Ironforge Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10456, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Ironforge Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10456, 0, 0, 1, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Ironforge Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10456, 0, 0, 1, 9, 0, 13790, 0, 0, 0, 0, 0, '', 'Ironforge Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10456, 0, 0, 1, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Ironforge Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10456, 0, 0, 2, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Ironforge Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10456, 0, 0, 2, 9, 0, 13814, 0, 0, 0, 0, 0, '', 'Ironforge Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10456, 0, 0, 2, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Ironforge Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10456, 0, 0, 3, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Ironforge Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10456, 0, 0, 3, 9, 0, 13811, 0, 0, 0, 0, 0, '', 'Ironforge Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10456, 0, 0, 3, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Ironforge Champion - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10457, 0, 0, 0, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10457, 0, 0, 0, 9, 0, 13793, 0, 0, 0, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10457, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10457, 0, 0, 1, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10457, 0, 0, 1, 9, 0, 13790, 0, 0, 0, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10457, 0, 0, 1, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10457, 0, 0, 2, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10457, 0, 0, 2, 9, 0, 13814, 0, 0, 0, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10457, 0, 0, 2, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10457, 0, 0, 3, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10457, 0, 0, 3, 9, 0, 13811, 0, 0, 0, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10457, 0, 0, 3, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Orgrimmar Champion - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10458, 0, 0, 0, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10458, 0, 0, 0, 9, 0, 13793, 0, 0, 0, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10458, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10458, 0, 0, 1, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10458, 0, 0, 1, 9, 0, 13790, 0, 0, 0, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10458, 0, 0, 1, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10458, 0, 0, 2, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10458, 0, 0, 2, 9, 0, 13814, 0, 0, 0, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10458, 0, 0, 2, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10458, 0, 0, 3, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10458, 0, 0, 3, 9, 0, 13811, 0, 0, 0, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10458, 0, 0, 3, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Sen''jin Champion - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10459, 0, 0, 0, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10459, 0, 0, 0, 9, 0, 13793, 0, 0, 0, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10459, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10459, 0, 0, 1, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10459, 0, 0, 1, 9, 0, 13790, 0, 0, 0, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10459, 0, 0, 1, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10459, 0, 0, 2, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10459, 0, 0, 2, 9, 0, 13814, 0, 0, 0, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10459, 0, 0, 2, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10459, 0, 0, 3, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10459, 0, 0, 3, 9, 0, 13811, 0, 0, 0, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10459, 0, 0, 3, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Silvermoon Champion - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10460, 0, 0, 0, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Stormwind Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10460, 0, 0, 0, 9, 0, 13793, 0, 0, 0, 0, 0, '', 'Stormwind Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10460, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Stormwind Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10460, 0, 0, 1, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Stormwind Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10460, 0, 0, 1, 9, 0, 13790, 0, 0, 0, 0, 0, '', 'Stormwind Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10460, 0, 0, 1, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Stormwind Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10460, 0, 0, 2, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Stormwind Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10460, 0, 0, 2, 9, 0, 13814, 0, 0, 0, 0, 0, '', 'Stormwind Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10460, 0, 0, 2, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Stormwind Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10460, 0, 0, 3, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Stormwind Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10460, 0, 0, 3, 9, 0, 13811, 0, 0, 0, 0, 0, '', 'Stormwind Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10460, 0, 0, 3, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Stormwind Champion - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10461, 0, 0, 0, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10461, 0, 0, 0, 9, 0, 13793, 0, 0, 0, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10461, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10461, 0, 0, 1, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10461, 0, 0, 1, 9, 0, 13790, 0, 0, 0, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10461, 0, 0, 1, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10461, 0, 0, 2, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10461, 0, 0, 2, 9, 0, 13814, 0, 0, 0, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10461, 0, 0, 2, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10461, 0, 0, 3, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10461, 0, 0, 3, 9, 0, 13811, 0, 0, 0, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10461, 0, 0, 3, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Thunder Bluff Champion - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10462, 0, 0, 0, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Undercity Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10462, 0, 0, 0, 9, 0, 13793, 0, 0, 0, 0, 0, '', 'Undercity Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10462, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Undercity Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10462, 0, 0, 1, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Undercity Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10462, 0, 0, 1, 9, 0, 13790, 0, 0, 0, 0, 0, '', 'Undercity Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10462, 0, 0, 1, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Undercity Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10462, 0, 0, 2, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Undercity Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10462, 0, 0, 2, 9, 0, 13814, 0, 0, 0, 0, 0, '', 'Undercity Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10462, 0, 0, 2, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Undercity Champion - Show gossip option only if player has aura Player On Tournament Mount'),
(15, 10462, 0, 0, 3, 2, 0, 45500, 4, 1, 1, 0, 0, '', 'Undercity Champion - Show gossip option only if player does not have 4 Mark of the Champion'),
(15, 10462, 0, 0, 3, 9, 0, 13811, 0, 0, 0, 0, 0, '', 'Undercity Champion - Show gossip option only if player has taken quest Among the Champions'),
(15, 10462, 0, 0, 3, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Undercity Champion - Show gossip option only if player has aura Player On Tournament Mount');

-- Valiants
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (10464,10465,10466,10467,10468,10469,10470,10471,10472,10473);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(15, 10464, 0, 0, 0, 2, 0, 45127, 3, 1, 1, 0, 0, '', 'Darnassus Valiant - Show gossip option only if player does not have 4 Mark of the Valiant'),
(15, 10464, 0, 0, 0, 9, 0, 13761, 0, 0, 0, 0, 0, '', 'Darnassus Valiant - Show gossip option only if player has taken quest The Grand Melee'),
(15, 10464, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Darnassus Valiant - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10465, 0, 0, 0, 2, 0, 45127, 3, 1, 1, 0, 0, '', 'Exodar Valiant - Show gossip option only if player does not have 4 Mark of the Valiant'),
(15, 10465, 0, 0, 0, 9, 0, 13756, 0, 0, 0, 0, 0, '', 'Exodar Valiant - Show gossip option only if player has taken quest The Grand Melee'),
(15, 10465, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Exodar Valiant - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10466, 0, 0, 0, 2, 0, 45127, 3, 1, 1, 0, 0, '', 'Gnomeregan Valiant - Show gossip option only if player does not have 4 Mark of the Valiant'),
(15, 10466, 0, 0, 0, 9, 0, 13750, 0, 0, 0, 0, 0, '', 'Gnomeregan Valiant - Show gossip option only if player has taken quest The Grand Melee'),
(15, 10466, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Gnomeregan Valiant - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10467, 0, 0, 0, 2, 0, 45127, 3, 1, 1, 0, 0, '', 'Ironforge Valiant - Show gossip option only if player does not have 4 Mark of the Valiant'),
(15, 10467, 0, 0, 0, 9, 0, 13745, 0, 0, 0, 0, 0, '', 'Ironforge Valiant - Show gossip option only if player has taken quest The Grand Melee'),
(15, 10467, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Ironforge Valiant - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10468, 0, 0, 0, 2, 0, 45127, 3, 1, 1, 0, 0, '', 'Orgrimmar Valiant - Show gossip option only if player does not have 4 Mark of the Valiant'),
(15, 10468, 0, 0, 0, 9, 0, 13767, 0, 0, 0, 0, 0, '', 'Orgrimmar Valiant - Show gossip option only if player has taken quest The Grand Melee'),
(15, 10468, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Orgrimmar Valiant - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10469, 0, 0, 0, 2, 0, 45127, 3, 1, 1, 0, 0, '', 'Sen''jin Valiant - Show gossip option only if player does not have 4 Mark of the Valiant'),
(15, 10469, 0, 0, 0, 9, 0, 13772, 0, 0, 0, 0, 0, '', 'Sen''jin Valiant - Show gossip option only if player has taken quest The Grand Melee'),
(15, 10469, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Sen''jin Valiant - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10470, 0, 0, 0, 2, 0, 45127, 3, 1, 1, 0, 0, '', 'Silvermoon Valiant - Show gossip option only if player does not have 4 Mark of the Valiant'),
(15, 10470, 0, 0, 0, 9, 0, 13787, 0, 0, 0, 0, 0, '', 'Silvermoon Valiant - Show gossip option only if player has taken quest The Grand Melee'),
(15, 10470, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Silvermoon Valiant - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10471, 0, 0, 0, 2, 0, 45127, 3, 1, 1, 0, 0, '', 'Stormwind Valiant - Show gossip option only if player does not have 4 Mark of the Valiant'),
(15, 10471, 0, 0, 0, 9, 0, 13665, 0, 0, 0, 0, 0, '', 'Stormwind Valiant - Show gossip option only if player has taken quest The Grand Melee'),
(15, 10471, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Stormwind Valiant - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10472, 0, 0, 0, 2, 0, 45127, 3, 1, 1, 0, 0, '', 'Thunder Bluff Valiant - Show gossip option only if player does not have 4 Mark of the Valiant'),
(15, 10472, 0, 0, 0, 9, 0, 13777, 0, 0, 0, 0, 0, '', 'Thunder Bluff Valiant - Show gossip option only if player has taken quest The Grand Melee'),
(15, 10472, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Thunder Bluff Valiant - Show gossip option only if player has aura Player On Tournament Mount'),
--
(15, 10473, 0, 0, 0, 2, 0, 45127, 3, 1, 1, 0, 0, '', 'Undercity Valiant - Show gossip option only if player does not have 4 Mark of the Valiant'),
(15, 10473, 0, 0, 0, 9, 0, 13782, 0, 0, 0, 0, 0, '', 'Undercity Valiant - Show gossip option only if player has taken quest The Grand Melee'),
(15, 10473, 0, 0, 0, 1, 0, 63034, 0, 0, 0, 0, 0, '', 'Undercity Valiant - Show gossip option only if player has aura Player On Tournament Mount');
-- Achievement: Now Were Cookin
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (11118,11119,11120,11121,11122,11123,11124,11125,11126,11127);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`) VALUES
-- Alliance
(11118, 16, 404, 0), -- Now Were Cookin / Cranberry Chutney
(11119, 16, 404, 0), -- Now Were Cookin / Candied Sweet Potato
(11120, 16, 404, 0), -- Now Were Cookin / Pumpkin Pie
(11121, 16, 404, 0), -- Now Were Cookin / Slow-Roasted Turkey
(11122, 16, 404, 0), -- Now Were Cookin / Spice Bread Stuffing
-- Horde
(11123, 16, 404, 0), -- Now Were Cookin / Candied Sweet Potato
(11124, 16, 404, 0), -- Now Were Cookin / Cranberry Chutney
(11125, 16, 404, 0), -- Now Were Cookin / Pumpkin Pie
(11126, 16, 404, 0), -- Now Were Cookin / Slow-Roasted Turkey
(11127, 16, 404, 0); -- Now Were Cookin / Spice Bread Stuffing
--
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=20899;
SET @CGUID := 74539;

UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`IN(25335,25336,25338,25359);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25335,25336,25338,25359) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2533500,2533501,2533600) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25335,0,0,1,19,0,100,0,11592,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Quest Accept (We Strike!) - Store Targetlist'),
(25335,0,1,0,61,0,100,0,0,0,0,0,80,2533500,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Quest Accept (We Strike!) - Run Script'),
(25335,0,2,3,6,0,100,0,0,0,0,0,6,11592,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - On Death - Fail Quest (We Strike)'),
(25335,0,3,4,61,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,25336,0,0,0,0,0,0, 'Longrunner Proudhoof - On Death - Set Data to Grunt Ragefist'),
(25335,0,4,0,61,0,100,0,0,0,0,0,45,3,3,0,0,0,0,9,25338,0,200,0,0,0,0, 'Longrunner Proudhoof - On Death - Set Data to Warsong Caravan Guard'),
(25335,0,5,0,40,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP - Set Home Position'),
(25335,0,6,7,61,0,100,0,0,0,0,0,45,4,4,0,0,0,0,19,25336,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP - Set Data to Grunt Ragefist'),
(25335,0,7,0,61,0,100,0,0,0,0,0,45,4,4,0,0,0,0,9,25338,0,200,0,0,0,0, 'Longrunner Proudhoof - On Reached WP - Set Data to Warsong Caravan Guard'),
(25335,0,8,9,40,0,100,1,9,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP9 - Pause WP for 5 Seconds'),
(25335,0,9,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP9 - Say Line 2'),
(25335,0,10,0,61,0,100,0,9,0,0,0,107,1,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP9 - Summon Group 1'),
(25335,0,11,0,40,0,100,1,10,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP10 - Say Line 3'),
(25335,0,12,13,40,0,100,1,13,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP13 - Say Line 4'),
(25335,0,13,14,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0, 0, 0,0, 'Longrunner Proudhoof - On Reached WP13 - Set Home Position'),
(25335,0,14,0,61,0,100,0,0,0,0,0,12,25359,1,100000,0,0,0,8,0,0,0,3879.794, 5719.112, 66.50308,1.048136, 'Longrunner Proudhoof - On Reached WP13 - Summon '),
(25335,0,15,0,38,0,100,0,5,5,0,0,80,2533501,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Data Set 5 5 - Run Script 2'),
(25335,0,16,0,11,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Respawn - Reset Scripts '),
(25336,0,0,0,38,0,100,0,1,1,0,0,80,2533600,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - On Data Set 1 1 - Run Script'),
(25336,0,1,2,38,0,100,0,2,2,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - On Data Set 2 2 - Set Run on'),
(25336,0,2,0,61,0,100,0,0,0,0,0,29,2,3,0,0,0,0,19,25335,0,0,0,0,0,0, 'Grunt Ragefist - On Data Set 2 2 - Follow Longrunner Proudhoof'),
(25336,0,3,0,38,0,100,0,3,3,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - On Data Set 3 3 - Despawn'),
(25336,0,4,0,38,0,100,0,4,4,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - On Data Set 4 4 - Set Home Position'),
(25336,0,5,0,1,0,100,0,0,0,2000,2000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - OOC - Set Home Position'),
(25338,0,0,1,38,0,100,0,1,1,0,0,2,232,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 1 1 - Set Faction'),
(25338,0,1,2,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 1 1 - Set Hostile'),
(25338,0,2,0,61,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 1 1 - Switch HP Regen off'),
(25338,0,3,4,38,0,100,0,2,2,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 2 2 - Set Run on'),
(25338,0,4,0,61,0,100,0,0,0,0,0,29,1,2,0,0,0,0,19,25335,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 2 2 - Follow Longrunner Proudhoof'),
(25338,0,5,0,38,0,100,0,3,3,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 3 3 - Despawn'),
(25338,0,6,0,38,0,100,0,4,4,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 4 4 - Set Home Position'),
(25338,0,7,0,1,0,100,0,0,0,2000,2000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - OOC - Set Home Position'),

(25359,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,25335,0,0,0,0,0,0, 'Force-Commander Steeljaw - On Just Summoned - Attack Longrunner Proudhoof'),
(25359,0,1,2,6,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Force-Commander Steeljaw - On Death Say Line 0'),
(25359,0,2,0,6,0,100,0,0,0,0,0,45,5,5,0,0,0,0,19,25335,0,0,0,0,0,0, 'Force-Commander Steeljaw - On Death - Set Data to Longrunner Proudhoof'),
(25359,0,3,0,9,0,100,0,0,5,8000,13000,11,15284,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Force-Commander Steeljaw - On Range - Cast Cleave'),
(25359,0,4,0,0,0,100,0,6000,9000,11000,18000,11,38256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Force-Commander Steeljaw - IC - Cast Piercing Howl'),
(25359,0,5,0,2,0,100,1,0,50,0,0,11,50204,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Force-Commander Steeljaw - On 20% HP - Cast Steeljaw'),
(25359,0,6,0,0,0,100,0,9000,15000,18000,24000,11,41056,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Force-Commander Steeljaw - IC - Cast Whirlwind'),

(2533500,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Set NPC Flags'),
(2533500,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,25336,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Set Data to Grunt Ragefist'),
(2533500,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,25338,0,200,0,0,0,0, 'Longrunner Proudhoof - Script - Set Data to Warsong Caravan Guard'),
(2533500,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Say Line 0'),
(2533500,9,4,0,0,0,100,0,0,0,0,0,2,232,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Set Faction'),
(2533500,9,5,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Set Hostile'),
(2533500,9,6,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Switch HP Regen off'),
(2533500,9,7,0,0,0,100,0,11000,11000,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Say Line 0'),
(2533500,9,8,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,19,25336,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Set Data to Grunt Ragefist'),
(2533500,9,9,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,25338,0,200,0,0,0,0, 'Longrunner Proudhoof - Script - Set Data to Warsong Caravan Guard'),
(2533500,9,10,0,0,0,100,0,0,0,0,0,53,1,25335,0,0,0,2,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Start WP'),

(2533501,9,0,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - Script 2 - Say Line 5'),
(2533501,9,1,0,0,0,100,0,0,0,0,0,15,11592,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - Script 2 - Complete Quest (We Strike)'),
(2533501,9,2,0,0,0,100,0,6000,6000,0,0,45,3,3,0,0,0,0,19,25336,0,0,0,0,0,0, 'Longrunner Proudhoof - Script 2 - Set Data to Grunt Ragefist'),
(2533501,9,3,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,9,25338,0,200,0,0,0,0, 'Longrunner Proudhoof - Script 2 - Set Data to Warsong Caravan Guard'),
(2533501,9,4,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - Script 2 - Despawn'),

(2533600,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - Script - Set NPC Flags'),
(2533600,9,1,0,0,0,100,0,0,0,0,0,2,232,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - Script - Set Faction'),
(2533600,9,2,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - Script - Set Hostile'),
(2533600,9,3,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - Script - Switch HP Regen off');


DELETE FROM `waypoints` WHERE `entry`=25335;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25335, 1, 4121.404, 5791.311, 62.72873, 'Longrunner Proudhoof'),
(25335, 2, 4101.437, 5799.435, 67.94357, 'Longrunner Proudhoof'),
(25335, 3, 4083.929, 5805.443, 71.37161, 'Longrunner Proudhoof'),
(25335, 4, 4068.87, 5807.64, 73.81717, 'Longrunner Proudhoof'),
(25335, 5, 4052.772, 5802.647, 75.09177, 'Longrunner Proudhoof'),
(25335, 6, 4038.374, 5795.233, 75.40152, 'Longrunner Proudhoof'),
(25335, 7, 4025.04, 5789.227, 75.19473, 'Longrunner Proudhoof'),
(25335, 8, 4006.379, 5787.299, 73.14676, 'Longrunner Proudhoof'),
(25335, 9, 3984.424, 5778.06, 73.17698, 'Longrunner Proudhoof'), -- Event
(25335, 10, 3952.678, 5758.444, 70.48514, 'Longrunner Proudhoof'), -- text
(25335, 11, 3919.015, 5753.338, 69.2403, 'Longrunner Proudhoof'),
(25335, 12, 3894.645, 5745.702, 70.36196, 'Longrunner Proudhoof'),
(25335, 13, 3883.361, 5725.309, 67.55053, 'Longrunner Proudhoof');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=25335;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(25335, 0, 1, 25351, 3981.684, 5766.304, 71.69027, 1.508547, 3, 100000),
(25335, 0, 1, 25351, 3972.008, 5783.715, 74.18502, 5.856251, 3, 100000),
(25335, 0, 1, 25351, 3996.715, 5773.316, 70.84, 2.772876, 3, 100000),
(25335, 0, 1, 25350, 3988.267, 5791.996, 74.18443, 4.443494, 3, 100000),
(25335, 0, 1, 25351, 3969.23, 5768.75, 72.69688, 0.5497994, 3, 100000);


DELETE FROM `creature_text` WHERE `entry`IN(25335,25359);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(25335, 0, 0, '$n is going to join us on our assault. Let us bring peace to my ancestors!', 12, 1, 100, 396, 0, 0, 'Longrunner Proudhoof',24561),
(25335, 1, 0, 'WE STRIKE!', 14, 1, 100, 15, 0, 0, 'Longrunner Proudhoof',24562),
(25335, 2, 0, 'An ambush. Return them to their rest!', 12, 1, 100, 5, 0, 0, 'Longrunner Proudhoof',24563),
(25335, 3, 0, 'Regain your strength. The place where Steeljaw was felled is just ahead.', 12, 1, 100, 396, 0, 0, 'Longrunner Proudhoof',24564),
(25335, 4, 0, 'There''s the dog''s banner and there''s his corpse. What''s that? He''s upon us!', 12, 1, 100, 25, 0, 0, 'Longrunner Proudhoof',24565),
(25335, 5, 0, 'You fought well. Now go north to your orc outpost and inform Overlord Bor''gorok of our success!', 12, 1, 100, 113, 0, 0, 'Longrunner Proudhoof',24566),
(25359, 0, 0, 'I''m freed! Thank you.', 12, 1, 100, 0, 0, 0, 'Force-Commander Steeljaw',24575);

-- Warsong Caravan Guards
DELETE FROM `creature` WHERE `id`=25338;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 25338, 571, 1, 1, 4141.54, 5783.948, 60.69736, 2.86234, 120, 0, 0), -- 25338 (Area: 3537)
(@CGUID+1, 25338, 571, 1, 1, 4139.149, 5782.773, 60.48185, 2.86234, 120, 0, 0), -- 25338 (Area: 3537)
(@CGUID+2, 25338, 571, 1, 1, 4141.218, 5786.635, 61.20373, 2.9147, 120, 0, 0); -- 25338 (Area: 3537)
-- Achievement: Pilgrims Peril
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (11134,11135,11136,11137,11138,11139,11140,11141);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`) VALUES
-- Alliance
(11134, 5, 66303, 0), -- Orgrimmar
(11134, 6, 14, 0), -- Orgrimmar
(11134, 16, 404, 0), -- Orgrimmar
(11135, 5, 66303, 0), -- Silvermoon City
(11135, 6, 3470, 0), -- Silvermoon City
(11135, 16, 404, 0), -- Silvermoon City
(11136, 5, 66303, 0), -- Thunder Bluff
(11136, 6, 1638, 0), -- Thunder Bluff
(11136, 16, 404, 0), -- Thunder Bluff
(11137, 5, 66303, 0), -- Undercity
(11137, 6, 1497, 0), -- Undercity
(11137, 16, 404, 0), -- Undercity
-- Horde
(11138, 5, 66303, 0), -- Exodar
(11138, 6, 3557, 0), -- Exodar
(11138, 16, 404, 0), -- Exodar
(11139, 5, 66303, 0), -- Darnassus
(11139, 6, 1657, 0), -- Darnassus
(11139, 16, 404, 0), -- Darnassus
(11140, 5, 66303, 0), -- Ironforge
(11140, 6, 809, 0), -- Ironforge
(11140, 16, 404, 0), -- Ironforge
(11141, 5, 66303, 0), -- Stormwind
(11141, 6, 12, 0), -- Stormwind
(11141, 16, 404, 0); -- Stormwind
DELETE FROM `creature_text` WHERE `entry`=21767;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(21767, 0, 0, 'What $r dare harm those of my flock?', 14, 0, 100, 0, 0, 0, 'Harbinger of the Raven',19398);

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=21767;

DELETE FROM `smart_scripts` WHERE `entryorguid`=21767  AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21767,0,0,0,54,0,100,0,0,0,0,0,1,0,7000,0,0,0,0,1,0,0,0,0,0,0,0,'Harbinger of the Raven - On Just Summoned - Say Line 0'),
(21767,0,1,2,52,0,100,0,0,21767,0,0,11,37446,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbinger of the Raven - On Text Over Line 0 - Cast Ruuan ok Oracle Transformation'),
(21767,0,2,3,61,0,100,0,0,0,0,0,2,954,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbinger of the Raven - On Text Over Line 0 - Set Faction'),
(21767,0,3,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbinger of the Raven - On Text Over Line 0 - Set Hostile');
UPDATE `creature_template` SET `unit_flags`=0 WHERE  `entry`=19527;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=19527;

DELETE FROM `smart_scripts` WHERE `entryorguid`=19527  AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19527,0,0,0,4,0,100,0,0,0,0,0,11,34524,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Just Summoned - Cast Elemental Response'),
(19527,0,1,0,2,0,100,1,0,10,0,0,11,34842,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Less than 10% HP - Cast De-Materialize'),
(19527,0,2,0,8,0,100,0,34842,0,0,0,41,0,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit De-Materialize  - Despawn'),
(19527,0,3,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Agro - Set Phase 1'),
(19527,0,4,17,8,1,100,0,0,2,0,0,11,34336,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Holy) (Phase 1) - Cast Damage Reduction: Holy'),
(19527,0,5,18,8,1,100,0,0,4,0,0,11,34333,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Fire) (Phase 1) - Cast Damage Reduction: Fire'),
(19527,0,6,19,8,1,100,0,0,8,0,0,11,34335,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Nature)(Phase 1) - Cast Damage Reduction: Nature'),
(19527,0,7,20,8,1,100,0,0,16,0,0,11,34334,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Frost) (Phase 1) - Cast Damage Reduction: Frost'),
(19527,0,8,21,8,1,100,0,0,32,0,0,11,34338,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Shadow) (Phase 1)  - Cast Damage Reduction: Shadow'),
(19527,0,9,22,8,1,100,0,0,64,0,0,11,34331,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Arcane) (Phase 1)  - Cast Damage Reduction: Arcane'),
(19527,0,10,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - Link - Set Phase 2'),
(19527,0,11,0,0,2,100,0,0,0,2000,3000,11,34348,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Fireball'),
(19527,0,12,0,0,2,100,0,0,0,5000,6000,11,34446,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Arcane Missiles'),
(19527,0,13,0,0,2,100,0,0,0,2000,3000,11,34347,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Frost Bolt'),
(19527,0,14,0,0,2,100,0,0,0,2000,3000,11,34346,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Holy Bolt'),
(19527,0,15,0,0,2,100,0,0,0,2000,3000,11,34345,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Lightning Bolt'),
(19527,0,16,0,0,2,100,0,0,0,2000,3000,11,34344,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Shadow Bolt'),
(19527,0,17,10,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Holy) (Phase 1) - Say'),
(19527,0,18,10,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Fire) (Phase 1) - Say'),
(19527,0,19,10,61,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Nature)(Phase 1) - Say'),
(19527,0,20,10,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Frost) (Phase 1) - Say'),
(19527,0,21,10,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Shadow) (Phase 1)  - Say'),
(19527,0,22,10,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Arcane) (Phase 1)  - Say');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=19527;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 12, 19527, 0, 0, 1, 1, 34333, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Fire to cast Fireball'),
(22, 13, 19527, 0, 0, 1, 1, 34331, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Arcane to cast Arcane Missiles'),
(22, 14, 19527, 0, 0, 1, 1, 34334, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Frost to cast Frost Bolt'),
(22, 15, 19527, 0, 0, 1, 1, 34336, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Holy to cast Holy Bolt'),
(22, 16, 19527, 0, 0, 1, 1, 34335, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Nature to cast Lightning Bolt'),
(22, 17, 19527, 0, 0, 1, 1, 34338, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Shadow to cast Shadowbolt');

DELETE FROM `creature_text` WHERE `entry`=19527;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(19527, 0, 0, '%s absorbs the fire energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17105),
(19527, 1, 0, '%s absorbs the arcane energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17109),
(19527, 2, 0, '%s absorbs the frost energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17106),
(19527, 3, 0, '%s absorbs the holy energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17110),
(19527, 4, 0, '%s absorbs the nature energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17107),
(19527, 5, 0, '%s absorbs the shadow energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17108);
-- Nerub'Ar Victim by DDuarte closes #13621
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|4, `flags_extra`=`flags_extra`|64 WHERE `entry`=25284;
-- Search for Incendicite by Exodius closes #13309
UPDATE `gameobject_loot_template` SET `QuestRequired`=0 WHERE `Entry`=1409 AND `Item`=3340;
-- Feeding Arngrim closes #12826
UPDATE `creature_template` SET `unit_flags`=0 WHERE  `entry`=30423;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 30422;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30422;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30422, 0, 0, 1, 8,  0, 100, 0, 56727, 0, 0, 0, 12, 30423, 1, 240000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roaming Jormungar - On Spellhit - Spawn Disembodied Jormungar'),
(30422, 0, 1, 0,61,  0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roaming Jormungar - Linked with Previous Event - Despawn');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 30423;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30423;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30423, 0, 0, 0, 2,  0, 100, 1, 0, 30, 0, 0, 11, 56732, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disembodied Jormungar - On 30% HP - Summon Arngrim'),
(30423, 0, 1, 2,38,  0, 100, 0, 1, 1, 0, 0, 11, 56731, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Disembodied Jormungar - On Spellhit - Cast Kill Credit'),
(30423, 0, 2, 0,61,  0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Disembodied Jormungar - Linked with Previous Event - Despawn');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 30425;

DELETE FROM `smart_scripts` WHERE `entryorguid` =30425;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30425, 0, 0, 0,11,  0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 30423, 200, 0, 0, 0, 0, 0, 'Arngrim - On Spawn - Move to closest disembodied jormungar'),
(30425, 0, 1, 2, 1,  0, 100, 0, 10000, 10000, 30000, 30000, 45, 1, 1, 0, 0, 0, 0, 19, 30423, 20, 0, 0, 0, 0, 0, 'Arngrim - OOC - Cast Ping Jormungar'),
(30425, 0, 2, 0,61,  0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arngrim - OOC - Linked with Previous Event - Despawn After 5 seconds');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN(13,17) AND `SourceEntry`=56727;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,56727,0,0,31,1,3,30422,0,0,0, '', 'Arngrims Tooth only hits Roaming Jormungar'),
(13,0,56727,0,0,31,1,3,30422,0,0,0, '', 'Arngrims Tooth only hits Roaming Jormungar');

-- Some CPP to SAI conversions closes #12645
-- and yes of keys and cages again realised now the previous commit was not most recent version
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=24035;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE`entry`IN(186491,186492,186493,186494,186498,186499,186500,186501,186502,186503,186504,186505,186508,186509,186512,186513,186514,186515,186516,186883,186895,186907,186908,186910,186911,186923,186924,186495,186496,186497,186507,186510,186511,186517,186518,186798,186909,186929,186930,186490);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24035,2403500,186491,186492,18649100,186493,186494,186498,186499,186500,186501,186502,186503,186504,186505,186508,186509,186512,186513,186514,186515,186516,186883,186895,186907,186908,186910,186911,186923,186924,186495,186496,186497,186507,186510,186511,186517,186518,186798,186909,186929,186930,186490,18649000,24035);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186491, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186492, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186493, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186494, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186495, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186496, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186497, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186498, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186499, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186500, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186501, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186502, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186503, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186504, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186505, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186507, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186508, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186509, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186510, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186511, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186512, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186513, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186514, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186515, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186516, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186517, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186518, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186798, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186883, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186895, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186907, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186908, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186909, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186910, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186911, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186923, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186924, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186929, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186930, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649100,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - On State Changed - Run Script'),
(186490, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18649000,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage - On State Changed - Run Script'),
(18649100, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,9,24035,0,10,0, 0, 0, 0, 'Gjalerbron Cage - Script - Set Data'),
(18649000, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,9,24035,0,20,0, 0, 0, 0, 'Large Gjalerbron Cage - Set Data'),
(18649100, 9, 1 ,0, 0, 0, 100, 0, 0, 0, 0,0,64,1,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - Script - Store Targetlist'),
(18649000, 9, 1 ,0, 0, 0, 100, 0, 0, 0, 0,0,64,1,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage - Store Targetlist'),
(18649100, 9, 2 ,0, 0, 0, 100, 0, 0, 0, 0,0,100,1,0,0,0,0,0,9,24035,0,10,0, 0, 0, 0, 'Gjalerbron Cage - Script - Send Targetlist'),
(18649000, 9, 2 ,0, 0, 0, 100, 0, 0, 0, 0,0,100,1,0,0,0,0,0,9,24035,0,20,0, 0, 0, 0, 'Large Gjalerbron Cage - Send Targetlist'),
(18649100, 9, 3 ,0, 0, 0, 100, 0, 300000, 300000, 0,0,32,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Gjalerbron Cage - Script - Reset Go'),
(18649000, 9, 3 ,0, 0, 0, 100, 0, 300000, 300000, 0,0,32,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Large Gjalerbron Cage - Script - Reset Go'),
(24035, 0, 0, 1, 38, 0, 100, 1, 1, 1, 0, 0, 80, 2403500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Prisoner - On Data Set - Kill Credit'),
(2403500, 9, 0, 0, 0, 0, 100, 1, 3000, 3000, 0, 0, 33, 24035, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Gjalerbron Prisoner - On Data Set - Kill Credit'),
(2403500, 9, 1, 0, 0, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Prisoner - Linked with Previous Event - Say'),
(2403500, 9, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 46, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Prisoner - Linked with Previous Event - Move Forward'),
(2403500, 9, 3, 0, 0, 0, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gjalerbron Prisoner - Linked with Previous Event - Despawn');
-- Whats Haunting With Hill?
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE  `entry`=23555;

DELETE FROM `smart_scripts` WHERE `entryorguid` =23555;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23555, 0, 0, 0, 2,  0, 100, 0, 0, 50, 6000, 11000, 11, 37933, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Risen Husk - On Less than 50% HP - Cast Consume Flesh'),
(23555, 0, 1, 2, 6,  0, 100, 0, 0, 0, 0, 0, 11, 42511, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Husk - On Death - Cast Summon Restless Apparotation'),
(23555, 0, 2, 0,61,  0, 100, 0, 0, 0, 0, 0, 11, 42512, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Risen Husk - Linked with Previous Event - Cast Witch Hill Information Credit');

-- Risen Spirit 23554

UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE  `entry`=23554;

DELETE FROM `smart_scripts` WHERE `entryorguid` =23554;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23554, 0, 0, 0, 0,  0, 100, 0, 0, 0, 6000, 11000, 11, 43127, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Risen Spirit - IC - Intangible Presence'),
(23554, 0, 1, 2, 6,  0, 100, 0, 0, 0, 0, 0, 11, 42511, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Risen Spirit - On Death - Cast Summon Restless Apparotation'),
(23554, 0, 2, 0,61,  0, 100, 0, 0, 0, 0, 0, 11, 42512, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Risen Spirit - Linked with Previous Event - Cast Witch Hill Information Credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND  `SourceEntry`IN(23554,23555) AND `SourceId`=0;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,23554,0,0,9,0,11180,0,0,0,0,'','AI Only executes if player is on Whats haunting witch Hill'),
(22,2,23555,0,0,9,0,11180,0,0,0,0,'','AI Only executes if player is on Whats haunting witch Hill');
UPDATE `smart_scripts` SET `target_type`=23 WHERE  `entryorguid`=24981 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `target_type`=23 WHERE  `entryorguid`=24981 AND `source_type`=0 AND `id`=0 AND `link`=1;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=24972;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24972 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24972,0,0,0,8,0,100,0,44997,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Erratic Sentry - On Spellhit (Converting Sentry) - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=44997;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 44997, 0, 0, 31, 1, 3, 24972, 0, 0, 0, 0, '', 'Converting Sentry Effect #1 targets Erratic Sentry');
-- quest linking for Judgment at the eye of eternity/ Heroic Judgment at the eye of eternity
-- requires The Key to the Focusing Iris for 10m or Heroic: The Key to the Focusing Iris for 25m
UPDATE `quest_template_addon` SET `PrevQuestID`=13372 WHERE  `Id`=13384;
UPDATE `quest_template_addon` SET `PrevQuestID`=13375 WHERE  `Id`=13385;
UPDATE `quest_template_addon` SET `NextQuestID`=13384 WHERE  `Id`=13372;
UPDATE `quest_template_addon` SET `NextQuestID`=13385 WHERE  `Id`=13375;
-- Prevent Image of Loken and Warlord Jin\'arrak from aggroing on player when summoned for scripted quest event
DELETE FROM `smart_scripts` WHERE `entryorguid`=27199 AND `source_type`=0 AND `id`=5;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27212 AND `source_type`=0 AND `id`=6;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(27199, 0, 5, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warlord Jin\'arrak - On Spawn - Set Passive'),
(27212, 0, 6, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Loken - On Spawn - Set Passive');
UPDATE `vehicle_template_accessory` SET `minion`=0 WHERE  `entry` IN(32640,32633);

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(32641,32642,32638,32639);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(32641,32642,32638,32639) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(32641, 0, 0, 0, 23, 0, 100, 1, 61424, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drix Blackwrench - Mojodishu - On Has Aura - Set Phase 1'),
(32641, 0, 1, 2, 23, 1, 100, 1, 61424, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drix Blackwrench - On Has No Aura (Phase 1) - Set NPC Flags'),
(32641, 0, 2, 3, 61, 1, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drix Blackwrench - Link - Say'),
(32641, 0, 3, 0, 61, 1, 100, 1, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drix Blackwrench - Link - Despawn After 2 seconds'),

(32642, 0, 0, 0, 23, 0, 100, 1, 61424, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mojodishu - On Has Aura - Set Phase 1'),
(32642, 0, 1, 2, 23, 1, 100, 1, 61424, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mojodishu - On Has No Aura (Phase 1) - Set NPC Flags'),
(32642, 0, 2, 3, 61, 1, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mojodishu - Link - Say'),
(32642, 0, 3, 0, 61, 1, 100, 1, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mojodishu - Link - Despawn After 2 seconds'),

(32638, 0, 0, 0, 23, 0, 100, 1, 61424, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hakmud of Argus <Traveling Trader> - Mojodishu - On Has Aura - Set Phase 1'),
(32638, 0, 1, 2, 23, 1, 100, 1, 61424, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hakmud of Argus <Traveling Trader> - On Has No Aura (Phase 1) - Set NPC Flags'),
(32638, 0, 2, 3, 61, 1, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hakmud of Argus <Traveling Trader> - Link - Say'),
(32638, 0, 3, 0, 61, 1, 100, 1, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hakmud of Argus <Traveling Trader> - Link - Despawn After 2 seconds'),

(32639, 0, 0, 0, 23, 0, 100, 1, 61424, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnimo <Adventurous Tinker> - On Has Aura - Set Phase 1'),
(32639, 0, 1, 2, 23, 1, 100, 1, 61424, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnimo <Adventurous Tinker> - On Has No Aura (Phase 1) - Set NPC Flags'),
(32639, 0, 2, 3, 61, 1, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnimo <Adventurous Tinker> - Link - Say'),
(32639, 0, 3, 0, 61, 1, 100, 1, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnimo <Adventurous Tinker> - Link - Despawn After 2 seconds');

DELETE FROM `creature_text` WHERE `entry` in(32641,32642,32638,32639);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(32641, 0, 0, 'Our friendship is OVER!', 12, 0, 100, 6, 0, 0, 'Drix Blackwrench',33025),
(32641, 0, 1, 'Hey, yea, I''ve always wanted to be stranded somewhere.', 12, 0, 100, 0, 0, 0, 'Drix Blackwrench',33024),
(32641, 0, 2, 'Oh, I see how it is... You''re gonna do me like that, eh?', 12, 0, 100, 0, 0, 0, 'Drix Blackwrench',33023),
(32641, 0, 3, 'You''re just gonna leave me here? How am I supposed to get home?', 12, 0, 100, 0, 0, 0, 'Drix Blackwrench',33026),
(32642, 0, 0, 'Really, mon? Just like dat you be leavin'' Mojodishu behind?', 12, 0, 100, 1, 0, 0, 'Mojodishu',33027),
(32642, 0, 1, 'Dis bad mojo what you doin''. Don''t say Mojodishu didn''t warn ya!', 12, 0, 100, 0, 0, 0, 'Mojodishu',33028),
(32642, 0, 2, 'Be dat way den!', 12, 0, 100, 0, 0, 0, 'Mojodishu',33029),
(32638, 0, 0, 'Hakmud cannot work under these conditions! Goodbye!', 12, 0, 100, 0, 0, 0, 'Hakmud of Argus <Traveling Trader>',33017),
(32638, 0, 1, 'I thought we were friend, buddy! You leave Hakmud stranded?', 12, 0, 100, 0, 0, 0, 'Hakmud of Argus <Traveling Trader>',33018),
(32638, 0, 2, 'Thanks, buddy! Thanks for nothing!', 12, 0, 100, 0, 0, 0, 'Hakmud of Argus <Traveling Trader>',33014),
(32638, 0, 3, 'What is Hakmud supposed to do now, buddy?', 12, 0, 100, 0, 0, 0, 'Hakmud of Argus <Traveling Trader>',33016),
(32638, 0, 4, 'Why do you treat Hakmud like this, buddy?', 12, 0, 100, 0, 0, 0, 'Hakmud of Argus <Traveling Trader>',33015),
(32639, 0, 0, 'Goodbye! You were Gnimo''s best friend ever!', 12, 0, 100, 0, 0, 0, 'Gnimo <Adventurous Tinker>',33020),
(32639, 0, 1, 'Nobody loves Gnimo...', 12, 0, 100, 0, 0, 0, 'Gnimo <Adventurous Tinker>',33019),
(32639, 0, 2, 'Time for Gnimo to shut down.', 12, 0, 100, 0, 0, 0, 'Gnimo <Adventurous Tinker>',33021);
UPDATE `creature` SET `spawntimesecs`=120 WHERE  `guid` IN(74951,74950,74949,74948);
DELETE FROM `creature_text` WHERE `entry`=19228 AND `groupid` IN(49,50);
DELETE FROM `creature_text` WHERE `entry`=19228 AND `groupid` =0 and `id`=6;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(19228, 49, 0, 'Is it just me, or is the Horde about the ugliest enemy we could find?', 12, 7, 100, 6, 0, 0, 16678, 'Perry Gatner'),
(19228, 50, 0, 'Just so you guys don''t feel left out, all I said was how attractive the blood elves are.  It loses something in the translation.', 12, 1, 100, 6, 0, 0, 16679, 'Perry Gatner'),
(19228, 0, 6, 'Are you ready to laugh!', 12, 0, 100, 5, 0, 0, 16329, 'Perry Gatner');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1927116 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1927116, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 47, 0, 0, 0, 0, 0, 19, 19228, 0, 0, 0, 0, 0, 0, 'Albert Quarksprocket - - Script 16 - Say Line 49 (Perry Gatner'),
(1927116, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 48, 0, 0, 0, 0, 0, 19, 19228, 0, 0, 0, 0, 0, 0, 'Albert Quarksprocket - - Script 16 - Say Line 50 (Perry Gatner');

UPDATE `smart_scripts` SET `action_param4`=1927116 WHERE  `entryorguid`=19271 AND `source_type`=0 AND `id`=15;
DELETE FROM `game_event` WHERE  `eventEntry`=66;
UPDATE `game_event` SET `occurence`=240, `description`='Perry Gatner' WHERE  `eventEntry`=65;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18688  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1868800  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18688, 0, 0, 1, 8, 0, 100, 0, 34063, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Orc Ancestor - On Spellhit "Soul Mirror" - Say Line 1'),
(18688, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 36, 19480, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Orc Ancestor - On Spellhit "Soul Mirror" - Change Entry to Darkened Spirit'),
(18688, 0, 2, 0, 0, 0, 100, 0, 20000, 40000, 60000, 180000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ancient Orc Ancestor - In Combat - Say Line 0 (Phase 1) (No Repeat)');

UPDATE `vehicle_template_accessory` SET `minion`=0 WHERE `entry` IN(32640,32633);
UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=4880;

DELETE FROM `smart_scripts` WHERE `entryorguid`=4880  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(488000,488001)  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4880,0,0,2,19,0,100,0,1270,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Quest Accept (Stinkys Escape - H) - Store Targetlist'),
(4880,0,1,2,19,0,100,0,1222,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Quest Accept (Stinkys Escape - A) - Store Targetlist'),
(4880,0,2,0,61,0,100,0,0,0,0,0,80,488000,2,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Link - Run Script'),
(4880,0,3,4,40,0,100,0,8,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP8 - Pause WP (3 Seconds)'),
(4880,0,4,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP8 - Say Line 1'),
(4880,0,5,6,40,0,100,0,12,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP12 - Pause WP (3 Seconds)'),
(4880,0,6,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP12 - Say Line 2'),
(4880,0,7,0,40,0,100,0,26,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP26 - Say Line 3'),
(4880,0,8,9,40,0,100,0,27,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached 27 - Pause WP (6 Seconds)'),
(4880,0,9,0,61,0,100,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached 27 - Say Line 4'),
(4880,0,10,11,40,0,100,0,28,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP28 - Pause WP (6 Seconds)'),
(4880,0,11,0,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached 28 - Say Line 5'),
(4880,0,12,13,40,0,100,0,29,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP29 - Pause WP (6 Seconds)'),
(4880,0,13,14,61,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached 29 - Set Bytes 1'),
(4880,0,14,27,61,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached 29 - Say Line 6'),
(4880,0,15,16,40,0,100,0,30,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP30 - Set Bytes 1'),
(4880,0,16,0,61,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP30 - Say Line 7'),
(4880,0,17,18,40,0,100,0,38,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP38 - Pause WP (6 Seconds)'),
(4880,0,18,19,61,0,100,0,0,0,0,0,1,8,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP38 - Say Line 8'),
(4880,0,19,20,61,0,100,0,0,0,0,0,15,1270,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP38 - Complete Quest'),
(4880,0,20,21,61,0,100,0,0,0,0,0,15,1222,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP38 - Complete Quest'),
(4880,0,21,0,40,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP38 - Set Run On'),
(4880,0,22,23,40,0,100,0,40,0,0,0,1,9,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP40 - Say Line 9'),
(4880,0,23,0,61,0,100,0,40,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP40 - Despawn'),
(4880,0,24,26,6,0,100,0,0,0,0,0,6,1270,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Death - Fail Quest'),
(4880,0,25,0,61,0,100,0,0,0,0,0,6,1222,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - On Death - Fail Quest'),
(4880,0,26,0,0,0,100,0,1000,1000,30000,30000,1,10,0,0,0,0,0,12,1,0,0,0,0,0,0,'"Stinky" Ignatz - IC  - Say Line 10'),
(4880,0,27,0,61,0,100,0,0,0,0,0,70,300,0,0,0,0,0,14,11757,20939,0,0,0,0,0,'"Stinky" Ignatz - On Reached WP29 - Despawn Bogbean Plant'),
(4880,0,28,0,24,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - On Evade - Set Bytes 1'),
(488000,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Set NPC Flags'),
(488000,9,1,0,0,0,100,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Set Faction'),
(488000,9,2,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Set Bytes 1'),
(488000,9,3,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Set aggresive'),
(488000,9,4,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Say Line 0'),
(488000,9,5,0,0,0,100,0,0,0,0,0,53,0,4880,0,0,0,0,1,0,0,0,0,0,0,0,'"Stinky" Ignatz - Script - Start WP');

DELETE FROM `waypoints` WHERE `entry`=4880;
DELETE FROM `script_waypoint` WHERE `entry`=4880;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(4880, 1, -2646.43, -3436.07, 35.3732, '"Stinky" Ignatz'),
(4880, 2, -2650.83, -3440.15, 35.1381, '"Stinky" Ignatz'),
(4880, 3, -2662.31, -3447.67, 35.1089, '"Stinky" Ignatz'),
(4880, 4, -2680.48, -3454.6, 34.6538, '"Stinky" Ignatz'),
(4880, 5, -2701.02, -3457.44, 34.2691, '"Stinky" Ignatz'),
(4880, 6, -2724.06, -3458.64, 33.6735, '"Stinky" Ignatz'),
(4880, 7, -2745.01, -3459.28, 32.5346, '"Stinky" Ignatz'),
(4880, 8, -2759.42, -3464.78, 32.7143, '"Stinky" Ignatz'), -- 3000
(4880, 9, -2763.63, -3471.51, 33.5388, '"Stinky" Ignatz'),
(4880, 10, -2771.79, -3480.89, 33.2553, '"Stinky" Ignatz'),
(4880, 11, -2780.66, -3488.76, 31.875, '"Stinky" Ignatz'),
(4880, 12, -2796.14, -3489.01, 30.8585, '"Stinky" Ignatz'), -- 3000
(4880, 13, -2792.12, -3495.97, 30.7324, '"Stinky" Ignatz'),
(4880, 14, -2789.06, -3502.37, 30.6704, '"Stinky" Ignatz'),
(4880, 15, -2787.72, -3515.01, 31.1176, '"Stinky" Ignatz'),
(4880, 16, -2790.84, -3523.31, 30.5733, '"Stinky" Ignatz'),
(4880, 17, -2796.59, -3520.62, 29.9187, '"Stinky" Ignatz'),
(4880, 18, -2798.56, -3518.91, 30.3887, '"Stinky" Ignatz'),
(4880, 19, -2801.47, -3516.75, 30.1915, '"Stinky" Ignatz'),
(4880, 20, -2804.36, -3513.9, 29.5508, '"Stinky" Ignatz'),
(4880, 21, -2807.98, -3518, 29.9488, '"Stinky" Ignatz'),
(4880, 22, -2815.68, -3521.74, 29.7723, '"Stinky" Ignatz'),
(4880, 23, -2823.39, -3526.23, 31.7194, '"Stinky" Ignatz'),
(4880, 24, -2836.11, -3544.7, 32.4939, '"Stinky" Ignatz'),
(4880, 25, -2830.39, -3568.86, 30.4104, '"Stinky" Ignatz'),
(4880, 26, -2824.84, -3569.52, 31.2811, '"Stinky" Ignatz'),
(4880, 27, -2818.66, -3567.8, 30.9204, '"Stinky" Ignatz'), -- 6000
(4880, 28, -2817.66, -3568.94, 30.4312, '"Stinky" Ignatz'), -- 6000
(4880, 29, -2820.39, -3592.22, 30.7163, '"Stinky" Ignatz'), -- 6000
(4880, 30, -2820.77, -3592.5, 30.8861, '"Stinky" Ignatz'),
(4880, 31, -2829.91, -3588.73, 30.6831, '"Stinky" Ignatz'),
(4880, 32, -2842.32, -3577.5, 36.8489, '"Stinky" Ignatz'),
(4880, 33, -2851.18, -3567.58, 38.5159, '"Stinky" Ignatz'),
(4880, 34, -2865.55, -3551.58, 41.439, '"Stinky" Ignatz'),
(4880, 35, -2871.23, -3548.15, 40.7614, '"Stinky" Ignatz'),
(4880, 36, -2877.84, -3544.15, 38.6702, '"Stinky" Ignatz'),
(4880, 37, -2890.39, -3542.39, 34.3144, '"Stinky" Ignatz'),
(4880, 38, -2898.73, -3543.64, 34.32, '"Stinky" Ignatz'), -- 6000
(4880, 39, -2910.06, -3568.96, 34.25, '"Stinky" Ignatz'),
(4880, 40, -2932.51, -3584.62, 37.2385, '"Stinky" Ignatz');

DELETE FROM `creature_text` WHERE `entry`=4880;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(4880, 0, 0, 'Ok, let''s get started.', 12, 0, 100, 0, 0, 0, 1610, 0, '"Stinky" Ignatz'),
(4880, 1, 0, 'Now let''s look for the herb.', 12, 0, 100, 0, 0, 0, 1611, 0, '"Stinky" Ignatz'),
(4880, 2, 0, 'Nope, not here...', 12, 0, 100, 0, 0, 0, 1612, 0, '"Stinky" Ignatz'),
(4880, 3, 0, 'There must be one around here somewhere...', 12, 0, 100, 0, 0, 0, 1613, 0, '"Stinky" Ignatz'),
(4880, 4, 0, 'Ah, there''s one!', 12, 0, 100, 0, 0, 0, 1614, 0, '"Stinky" Ignatz'),
(4880, 5, 0, 'Come, $n!  Let''s go over there and collect it!', 12, 0, 100, 0, 0, 0, 1615, 0, '"Stinky" Ignatz'),
(4880, 6, 0, '%s picks the herb from the ground.', 16, 0, 100, 0, 0, 0, 1616, 0, '"Stinky" Ignatz'),
(4880, 7, 0, 'Ok, now let''s get out of here!', 12, 0, 100, 0, 0, 0, 1617, 0, '"Stinky" Ignatz'),
(4880, 8, 0, 'I can make it from here.  Thanks, $n!  And talk to my employer about a reward!', 12, 0, 100, 0, 0, 0, 1618, 0, '"Stinky" Ignatz'),
(4880, 9, 0, '%s disappears back into the swamp.', 16, 0, 100, 0, 0, 0, 1619, 0, '"Stinky" Ignatz'),
(4880, 10, 0, 'Help! I''m under attack!', 12, 0, 100, 0, 0, 0, 1629, 0, '"Stinky" Ignatz'),
(4880, 10, 1, 'Help!  The beast is on me!', 12, 0, 100, 0, 0, 0, 1630, 0, '"Stinky" Ignatz');

UPDATE `vehicle_template_accessory` SET `minion`=1 WHERE `entry` IN(32640,32633);
SET @CGUID := 74952;

DELETE FROM `creature` WHERE `id` IN(31314,30698,31306,31428);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 31314, 571, 1, 175, 6865.108, 3570.752, 736.0794, 3.01942, 120, 0, 0), -- 31314 (Area: 4531)
(@CGUID+1, 31314, 571, 1, 175, 6869.777, 3584.097, 735.8923, 2.879793, 120, 0, 0), -- 31314 (Area: 4531)
(@CGUID+2, 31314, 571, 1, 175, 6866.223, 3574.63, 735.9076, 3.036873, 120, 0, 0), -- 31314 (Area: 4531)
(@CGUID+3, 31314, 571, 1, 175, 6868.476, 3579.733, 736.1484, 2.949606, 120, 0, 0), -- 31314 (Area: 4531)
(@CGUID+4, 30698, 571, 1, 175, 6853.651, 3582.979, 738.027, 6.038839, 120, 0, 0), -- 30698 (Area: 4531)
(@CGUID+5, 31306, 571, 1, 175, 6865.82, 3577.979, 736.0449, 2.932153, 120, 0, 0), -- 31306 (Area: 4531)
(@CGUID+6, 31428, 571, 1, 175, 6857.328, 3571.491, 735.8922, 1.151917, 120, 5, 1); -- 31428 (Area: 4531) (possible waypoints or random movement)

DELETE FROM `gossip_menu` WHERE `entry`=10060;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(10060, 13978);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10060;

INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(10060, 0, 0, 'Let\'s kill this... thing... and get this over with.', 32118, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN(30698,31314,31306,31428,31301);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(30698, 0, 0x0, 0x1, ''), -- 30698
(31314, 0, 0x0, 0x1, ''), -- 31314
(31306, 0, 0x0, 0x1, '58949'), -- 31306 - 58949
(31428, 28919, 0x0, 0x1, ''), -- 31428
(31301, 0, 0x0, 0x1, '34427'); -- 31301 - 34427

UPDATE `creature_template` SET `unit_flags`=768 WHERE  `entry`=31301;


UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(30698,31314,31306,31428,31301);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(30698,31314,31306,31428,31301)  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(3130100)  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30698,0,0,1,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Morbidus - On Data Set 1 1 - Set Unit Flags'),
(30698,0,1,2,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Morbidus - On Data Set 1 1 - Set Hostile'),
(30698,0,2,3,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,31306,0,0,0,0,0,0,'Morbidus - On Data Set 1 1 - Set Data 1 1 on Margrave Dhakar'),
(30698,0,3,4,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,31428,0,0,0,0,0,0,'Morbidus - On Data Set 1 1 - Set Data 1 1 on Crusader Olakin Sainrith'),
(30698,0,4,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,31314,0,200,0,0,0,0,'Morbidus - On Data Set 1 1 - Set Data 1 1 on Ebon Blade Veteran'),
(30698,0,5,6,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Morbidus - On Reset - Set Passive'),
(30698,0,6,0,61,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Morbidus - On Reset - Set Unit Flags'),
(30698,0,7,0,6,0,100,0,0,0,0,0,33,30698,0,0,0,0,0,24,0,0,0,0,0,0,0,'Morbidus - On Death - Kill Credit'),
(31306,0,0,1,62,0,100,0,10060,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Margrave Dhakar - On Gossip Select - Store Targetlist'),
(31306,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Margrave Dhakar - On Gossip Select - Close Gossip'),
(31306,0,2,3,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Margrave Dhakar - On Gossip Select - Set NPC Flags'),
(31306,0,3,4,61,0,100,0,0,0,0,0,12,31301,1,600000,0,0,0,8,0,0,0,6858.596, 3580.5, 736.7512, 5.67232,'Margrave Dhakar - On Gossip Select - Summon The Lich King'),
(31306,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Margrave Dhakar - On Gossip Select - Say Line 0'),
(31306,0,5,6,38,0,100,0,1,1,0,0,8,2,0,0,0,0,0,1,0,0,0,0, 0, 0, 0,'Margrave Dhakar - On Data Set 1 1 - Set Hostile'),
(31306,0,6,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,30698,0,0,0,0,0,0,'Margrave Dhakar - On Data Set 1 1 - Attack Morbidus'),
(31306,0,7,8,7,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Margrave Dhakar - On Evade - Set Passive'),
(31306,0,8,0,61,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Margrave Dhakar - On Evade - Set NPC Flags'),
(31301,0,0,0,11,0,100,0,0,0,0,0,80,3130100,2,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - On Just Summoned - Run Script'),
(31314,0,0,1,38,0,100,0,1,1,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ebon Blade Veteran - On Data Set 1 1 - Set Hostile'),
(31314,0,1,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,30698,0,0,0,0,0,0,'Ebon Blade Veteran - On Data Set 1 1 - Attack Morbidus'),
(31314,0,2,0,7,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ebon Blade Veteran - On Evade - Set Passive'),
(31428,0,0,1,38,0,100,0,1,1,0,0,2,1770,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Data Set 1 1 - Set Faction'),
(31428,0,1,2,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Data Set 1 1 - Set Hostile'),
(31428,0,2,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,30698,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Data Set 1 1 - Attack Morbidus'),
(31428,0,3,4,7,0,100,0,1,1,0,0,2,2070,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Evade - Set Faction'),
(31428,0,4,0,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Olakin Sainrith - On Evade - Set Passive'),
(3130100,9,0,0,0,0,100,0,100,100,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Cast Ethereal Teleport'),
(3130100,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Say Line 0'),
(3130100,9,2,0,0,0,100,0,1000,1000,0,0,11,53274,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Cast Icebound Visage'),
(3130100,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Say Line 1'),
(3130100,9,4,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Say Line 2'),
(3130100,9,5,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Say Line 3'),
(3130100,9,6,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Say Line 4'),
(3130100,9,7,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,31428,0,0,0,0,0,0,'The Lich King - Script - Say Line 0 (Crusader Olakin Sainrith)'),
(3130100,9,8,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,19,30698,0,0,0,0,0,0,'The Lich King - Script - Set Data 1 1 on Morbidus'),
(3130100,9,9,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Script - Despawn');

UPDATE `smart_scripts` SET `event_type`=7 WHERE  `entryorguid`=4880 AND `source_type`=0 AND `id`=28 AND `link`=0;

DELETE FROM `conditions`  WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10060;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 10060, 0, 0, 0, 29, 0, 30698, 200, 0, 0, 0, 0, '', 'Margrave Dhakar only show gossip if Morbidus near'),
(15, 10060, 0, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0, '', 'Margrave Dhakar only show gossip if Morbidus is alive'),
(15, 10060, 0, 0, 0, 9, 0, 13235, 0, 0, 0, 0, 0, '', 'Margrave Dhakar only show gossip if player has The Flesh Giant Champion taken');
UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` =23720;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE  `entry`=186287;

DELETE FROM `smart_scripts` WHERE `entryorguid`=186287  AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23720  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18628700  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(186287, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Blackhoof Cage - On State Changed - Store Targetlist'),
(186287, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 18628700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blackhoof Cage - On State Changed - Run Script'),
(23720, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theramore Prisoner - On Data Set - Say'),
(23720, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 33, 23720, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Theramore Prisoner - Linked with Previous Event - Give Kill Credit'),
(23720, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theramore Prisoner - Linked with Previous Event - Despawn after 5 seconds'),
(23720, 0, 3, 0, 52, 0, 100, 0, 0, 23720, 0, 0, 46, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theramore Prisoner - Linked with Previous Event - Move Foward'),
(18628700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 9, 23720, 0, 5, 0, 0, 0, 0, 'Blackhoof Cage - Script - Send Targetlist to Theramore Prisoner'),
(18628700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 23720, 0, 5, 0, 0, 0, 0, 'Blackhoof Cage - Script - Set Data'),
(18628700, 9, 2, 0, 0, 0, 100, 0, 430000, 430000, 0, 0, 32, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blackhoof Cage - Script - Reset Go');
DELETE FROM `spell_area` WHERE `spell`=58932;
DELETE FROM `spell_area` WHERE `spell`=60778;

INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`,`racemask`, `autocast`, `gender`, `quest_start_status`, `quest_end_status`) VALUES(58932, 4171, 12499, 0,1101, 1,2,64,11),
(58932, 4171, 12499, 0,0, 1,2,64,11),
(58932, 4172, 12499, 0,0, 1,2,64,11),
(58932, 4171, 12500, 0,0, 1,2,64,11),
(58932, 4172, 12500, 0,0, 1,2,64,11),
(60778, 4171, 12499, 0,0, 1,2,64,11),
(60778, 4172, 12499, 0,0, 1,2,64,11),
(60778, 4171, 12500, 0,0, 1,2,64,11),
(60778, 4172, 12500, 0,0, 1,2,64,11);

DELETE FROM `creature_text` WHERE `entry` IN(31333,31334);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(31333, 0, 0, 'No, my beloved.', 12, 0, 100, 1, 0, 0, 32040, 'Alexstrasza the Life-Binder to Player'),
(31333, 1, 0, 'They must not discover the fate of the young paladin. Not yet.', 12, 11, 100, 5, 0, 0, 32041, 'Alexstrasza the Life-Binder to Player'),
(31333, 2, 0, 'Come to me, $n.', 15, 0, 100, 0, 0, 0, 32048, 'Alexstrasza the Life-Binder to Player'),
(31334, 0, 0, 'My Queen, do they know?', 12, 0, 100, 6, 0, 0, 32038, 'Korialstrasz to Player'),
(31334, 1, 0, '%s nods.', 16, 0, 100, 0, 0, 0, 32046, 'Korialstrasz to Player'),
(31334, 2, 0, 'They will not.', 12, 0, 100, 1, 0, 0, 32047, 'Korialstrasz to Player');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10179;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=31333;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 10179, 0, 0, 0, 8, 0, 12499, 0, 0, 0, 0, 0, '', 'Alexstrasza the Life-Binder - Show Gossip if player is rewarded for Return To Angrathar'),
(15, 10179, 0, 0, 1, 8, 0, 12500, 0, 0, 0, 0, 0, '', 'Alexstrasza the Life-Binder - Show Gossip if player is rewarded for Return To Angrathar'),
(22, 3, 31333, 0, 0, 8, 0, 12499, 0, 0, 0, 0, 0, '', 'Alexstrasza the Life-Binder - Run AI only if player is rewarded for Return To Angrathar'),
(22, 3, 31333, 0, 1, 8, 0, 12500, 0, 0, 0, 0, 0, '', 'Alexstrasza the Life-Binder - Run AI only if player is rewarded for Return To Angrathar');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='', `npcflag`=3 WHERE `entry`=31333;

DELETE FROM `smart_scripts` WHERE `entryorguid`=31333  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3133300  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31333,0,0,1,62,0,100,0,10179,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - On Gossip Option select - Close Gossip'),
(31333,0,1,0,61,0,100,0,0,0,0,0,68,14,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - On Gossip Option select - Play Movie'),
(31333,0,2,3,10,0,100,0,1,40,120000,120000,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - OOC Los - Store Targetlist'),
(31333,0,3,0,61,0,100,0,0,0,0,0,80,3133300,2,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - OOC Los - Run Script'),
(3133300,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,31334,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 0 (Korialstrasz)'),
(3133300,9,1,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 0 (Alexstrasza the Life-Binder)'),
(3133300,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 1 (Alexstrasza the Life-Binder)'),
(3133300,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,19,31334,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 1 (Korialstrasz)'),
(3133300,9,4,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,19,31334,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 2 (Korialstrasz)'),
(3133300,9,5,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,'Alexstrasza the Life-Binder - Script - Say Line 2 (Alexstrasza the Life-Binder)');

DELETE FROM `creature_template_addon` WHERE `entry` IN (31328, 31330, 26850, 31293, 31333, 28348, 31334, 31292, 31295, 31291, 31308, 31294, 31298, 31285, 31309, 31296, 31358, 31297, 31299, 31313, 31310, 26877);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(31328, 0, 0x0, 0x1, ''), -- 31328
(31330, 0, 0x0, 0x1, ''), -- 31330
(26850, 0, 0x0, 0x101, ''), -- 26850
(31293, 0, 0x10007, 0x1, '29266'), -- 31293 - 29266
(31333, 0, 0x3000001, 0x1, '60778'), -- 31333 - 60778
(28348, 0, 0x10000, 0x1, ''), -- 28348
(31334, 0, 0x3000001, 0x1, ''), -- 31334
(31292, 0, 0x10007, 0x1, '29266'), -- 31292 - 29266
(31295, 0, 0x10007, 0x1, '29266'), -- 31295 - 29266
(31291, 0, 0x10000, 0x1, ''), -- 31291
(31308, 0, 0x10007, 0x1, '29266'), -- 31308 - 29266
(31294, 0, 0x10007, 0x1, '29266'), -- 31294 - 29266
(31298, 0, 0x10007, 0x1, '29266'), -- 31298 - 29266
(31285, 0, 0x10007, 0x1, '29266'), -- 31285 - 29266
(31309, 0, 0x10007, 0x1, '29266'), -- 31309 - 29266
(31296, 0, 0x10007, 0x1, '29266'), -- 31296 - 29266
(31358, 0, 0x0, 0x1, ''), -- 31358
(31297, 0, 0x10007, 0x1, '29266'), -- 31297 - 29266
(31299, 0, 0x10007, 0x1, '29266'), -- 31299 - 29266
(31313, 0, 0x0, 0x1, ''), -- 31313
(31310, 0, 0x0, 0x1, ''), -- 31310
(26877, 0, 0x0, 0x101, ''); -- 26877

SET @CGUID := 75045;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18 AND `id` IN(31328,31330,31310,31313);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 31328, 571, 1, 2,4897.725, 1335.234, 231.006, 5.068347, 120, 0, 0), -- 31328 (Area: 4171)
(@CGUID+1, 31330, 571, 1, 2,4939.318, 1323.521, 235.045, 4.453136, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+2, 31313, 571, 1, 2,4664.651, 1447.415, 170.8568, 3.301515, 120, 0, 0), -- 31313 (Area: 4171)
(@CGUID+3, 31310, 571, 1, 2,4702.17, 1552.966, 249.4346, 2.188437, 120, 5, 1), -- 31310 (Area: 4171) (possible waypoints or random movement)
(@CGUID+4, 31313, 571, 1, 2,4702.964, 1557.946, 247.5312, 1.604996, 120, 0, 0), -- 31313 (Area: 4171)
(@CGUID+5, 31310, 571, 1, 2,4648.25, 1422.38, 170.9548, 1.993341, 120, 0, 0), -- 31310 (Area: 4171)
(@CGUID+6, 31330, 571, 1, 2,4806.307, 1318.516, 168.6461, 1.844061, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+7, 31328, 571, 1, 2,4793.399, 1329.59, 170.9456, 2.494735, 120, 0, 0), -- 31328 (Area: 4171)
(@CGUID+8, 31330, 571, 1, 2,4800.977, 1323.843, 170.5469, 2.492624, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+9, 31330, 571, 1, 2,4928.894, 1297.723, 230.3787, 4.188883, 120, 5, 1), -- 31330 (Area: 4171) (possible waypoints or random movement)
(@CGUID+10, 31330, 571, 1, 2,4901.572, 1317.947, 229.5681, 5.172978, 120, 5, 1), -- 31330 (Area: 4171) (possible waypoints or random movement)
(@CGUID+11, 31330, 571, 1, 2,4897.755, 1335.152, 231.0011, 5.068347, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+12, 31310, 571, 1, 2,4701.083, 1410.821, 172.1171, 4.542583, 120, 0, 0), -- 31310 (Area: 4171)
(@CGUID+13, 31310, 571, 1, 2,4714.932, 1432.092, 174.4268, 5.404375, 120, 0, 0), -- 31310 (Area: 4171)
(@CGUID+14, 31330, 571, 1, 2,4767.026, 1300.882, 159.1799, 3.967742, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+15, 31330, 571, 1, 2,4783.351, 1313.886, 165.2287, 3.801694, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+16, 31310, 571, 1, 2,4726.307, 1305.983, 152.4278, 4.304676, 120, 0, 0), -- 31310 (Area: 4171)
(@CGUID+17, 31313, 571, 1, 2,4709.668, 1412.268, 174.0422, 5.927182, 120, 0, 0), -- 31313 (Area: 4171)
(@CGUID+18, 31310, 571, 1, 2,4709.66, 1415.296, 174.3237, 5.371386, 120, 0, 0); -- 31310 (Area: 4171)

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(31310,31313,31328,31330);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(31310,31313,31328,31330)  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(3131000,3131001,3131002,3131003,3131004,3131005,3131006,3131007,3131008)  AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31313,0,0,1,11,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Set Run On'),
(31313,0,1,2,61,0,100,0,0,0,0,0,89,30,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Set Random Movement'),
(31313,0,2,0,61,0,100,0,0,0,0,0,11,52385,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Cast Cosmetic - Periodic Cower'),
(31313,0,3,0,1,0,100,0,0,3000,1000,3000,87,3131005,3131006,3131007,3131008,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - OOC - Run Random Script'),
(31330,0,0,1,11,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Set Run On'),
(31330,0,1,2,61,0,100,0,0,0,0,0,89,30,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Set Random Movement'),
(31330,0,2,0,61,0,100,0,0,0,0,0,11,52385,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Cast Cosmetic - Periodic Cower'),
(31330,0,3,0,1,0,100,0,0,3000,1000,3000,87,3131005,3131006,3131007,3131008,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - OOC - Run Random Script'),
(31310,0,0,1,11,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Set Run On'),
(31310,0,1,2,61,0,100,0,0,0,0,0,89,30,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Set Random Movement'),
(31310,0,2,0,61,0,100,0,0,0,0,0,11,52385,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Cast Cosmetic - Periodic Cower'),
(31310,0,3,0,1,0,100,0,0,3000,1000,3000,87,3131000,3131001,3131002,3131003,3131004,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - OOC - Run Random Script'),
(31328,0,0,1,11,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Set Run On'),
(31328,0,1,2,61,0,100,0,0,0,0,0,89,30,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Set Random Movement'),
(31328,0,2,0,61,0,100,0,0,0,0,0,11,52385,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Cast Cosmetic - Periodic Cower'),
(31328,0,3,0,1,0,100,0,0,3000,1000,3000,87,3131000,3131001,3131002,3131003,3131004,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - OOC - Run Random Script'),

(3131000,9,0,0,0,0,100,0,0,0,0,0,4,14994,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 1 - Play Sound 14994'),
(3131001,9,0,0,0,0,100,0,0,0,0,0,4,14991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 2 - Play Sound 14991'),
(3131002,9,0,0,0,0,100,0,0,0,0,0,4,14993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 3 - Play Sound 14993'),
(3131003,9,0,0,0,0,100,0,0,0,0,0,4,14992,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 4 - Play Sound 14992'),
(3131004,9,0,0,0,0,100,0,0,0,0,0,4,15005,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 5 - Play Sound 15005'),
(3131005,9,0,0,0,0,100,0,0,0,0,0,4,14990,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 6 - Play Sound 14990'),
(3131006,9,0,0,0,0,100,0,0,0,0,0,4,14988,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 7 - Play Sound 14988'),
(3131007,9,0,0,0,0,100,0,0,0,0,0,4,14989,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 8 - Play Sound 14989'),
(3131008,9,0,0,0,0,100,0,0,0,0,0,4,14987,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 9 - Play Sound 14987');
-- Apprentice Ralen SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=15941 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15941,0,0,1,8,0,100,0,27907,0,15000,15000,33,15941,0,0,0,0,0,7,0,0,0,0,0,0,0,"Apprentice Ralen - On Spellhit 'Disciplinary Rod' - Quest Credit 'Swift Discipline'"),
(15941,0,1,0,61,0,100,0,27907,0,15000,15000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Apprentice Ralen - On Spellhit 'Disciplinary Rod' - Say Line 0");

-- Apprentice Meledor SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=15945 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15945,0,0,1,8,0,100,0,27907,0,15000,15000,33,15945,0,0,0,0,0,7,0,0,0,0,0,0,0,"Apprentice Meledor - On Spellhit 'Disciplinary Rod' - Quest Credit 'Swift Discipline'"),
(15945,0,1,0,61,0,100,0,27907,0,15000,15000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Apprentice Meledor - On Spellhit 'Disciplinary Rod' - Say Line 0");
UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(33877,33761,33861,33862);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(33877,33761,33861,33862)  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(19455501,19455503)  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(19455501, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 104, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Go Flags '),
(19455501, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 3 on Archivum System '),
(19455501, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33876, 3, 67000, 0, 0, 0, 8, 0, 0, 0, 1438.32, 118.523, 425.434, 0, 'Archivum Console - Script 2 - Spawn Freya Image '),
(19455501, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 4 on Archivum System '),
(19455501, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33861, 3, 58000, 0, 0, 0, 8, 0, 0, 0, 1435.8, 118.855, 425.881, 0, 'Archivum Console - Script 2 - Spawn Elder Brightleaf Image'),
(19455501, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33862, 3, 58000, 0, 0, 0, 8, 0, 0, 0, 1435.71, 120.41, 425.823, 0, 'Archivum Console - Script 2 - Spawn Elder Stonebark Image'),
(19455501, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33761, 3, 58000, 0, 0, 0, 8, 0, 0, 0, 1435.77, 117.288, 425.838, 0, 'Archivum Console - Script 2 - Spawn Elder Ironbark Image'),
(19455501, 9, 7, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 5 on Archivum System '),
(19455501, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33761, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Brightleaf Image'),
(19455501, 9, 9, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 6 on Archivum System '),
(19455501, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33862, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Stonebark Image'),
(19455501, 9, 11, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 7 on Archivum System'),
(19455501, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33861, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Ironbranch Image'),
(19455501, 9, 13, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 8 on Archivum System'),
(19455501, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 33761, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Brightleaf Image'),
(19455501, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 33862, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Stonebark Image'),
(19455501, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 33861, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Ironbranch Image'),
(19455501, 9, 17, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 9, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 9 on Archivum System'),
(19455501, 9, 18, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 104, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Go Flags '),
(19455503, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 104, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Set Go Flags '),
(19455503, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 15, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Say Text Line 15 on Archivum System '),
(19455503, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33878, 3, 40000, 0, 0, 0, 8, 0, 0, 0, 1436.22, 118.364, 425.789, 0, 'Archivum Console - Script 4 - Spawn Thorim Image'),
(19455503, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 16, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Say Text Line 16 on Archivum System '),
(19455503, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33877, 3, 31000, 0, 0, 0, 8, 0, 0, 0, 1436.14, 120.3, 425.839, 4.95674, 'Archivum Console - Script 4 - Spawn Sif Image'),
(19455503, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33877, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Set Data on Sif Image'),
(19455503, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 17, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Say Text Line 17 on Archivum System '),
(19455503, 9, 7, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 18, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Say Text Line 18 on Archivum System '),
(19455503, 9, 8, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 104, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Set Go Flags '),
(33761,0,0,0,38,0,100,0,1,1,0,0,11,64201,0,0,0,0,0,1,0,0,0,0,0,0,0,'Elder Brightleaf Image - On Data Set - Cast Sunbeam'),
(33862,0,0,0,38,0,100,0,1,1,0,0,11,64228,0,0,0,0,0,1,0,0,0,0,0,0,0,'Elder Stonebark Image - On Data Set - Cast Ground Tremor'),
(33861,0,0,0,38,0,100,0,1,1,0,0,11,64229,0,0,0,0,0,1,0,0,0,0,0,0,0,'Elder Ironbranch Image - On Data Set - Cast Iron Roots'),
(33761,0,1,0,38,0,100,0,2,2,0,0,11,64269,0,0,0,0,0,19,33876,0,0,0,0,0,0,'Elder Brightleaf Image - On Data Set - Cast Hologram Freya Channel'),
(33862,0,1,0,38,0,100,0,2,2,0,0,11,64269,0,0,0,0,0,19,33876,0,0,0,0,0,0,'Elder Stonebark Image - On Data Set - Cast Hologram Freya Channel'),
(33861,0,1,0,38,0,100,0,2,2,0,0,11,64269,0,0,0,0,0,19,33876,0,0,0,0,0,0,'Elder Ironbranch Image - On Data Set - Cast Hologram Freya Channel'),
(33877,0,0,0,38,0,100,0,1,1,0,0,11,64324,0,0,0,0,0,19,33878,0,0,0,0,0,0,'Sif Image - On Data Set - Cast Hologram Sif Channel');

UPDATE `gossip_menu_option` SET `BoxBroadcastTextID`=0 WHERE  `menu_id`=10368;
SET @CGUID := 75064;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3 AND `id`=24921;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 24921, 603, 3, 1, 1437.423, 117.3453, 425.8442, 0, 7200, 0, 0), -- 24921 (Area: 0) (Auras: )
(@CGUID+1, 24921, 603, 3, 1, 1437.352, 115.7263, 425.8618, 0, 7200, 0, 0), -- 24921 (Area: 0) (Auras: )
(@CGUID+2, 24921, 603, 3, 1, 1437.107, 118.4796, 425.813, 0, 7200, 0, 0), -- 24921 (Area: 0) (Auras: )
(@CGUID+3, 24921, 603, 3, 1, 1436.955, 118.8366, 425.8709, 0, 7200, 0, 0); -- 24921 (Area: 0) (Auras: )

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(64201,64229);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 64201, 0, 0, 31, 0, 3, 24921, 0, 0, 0, 0, '', 'Sunbeam Targets Cosmetic Trigger - LAB'),
(13, 1, 64229, 0, 0, 31, 0, 3, 24921, 0, 0, 0, 0, '', 'Iron Roots Targets Cosmetic Trigger - LAB');
UPDATE `gameobject` SET `state`=1 WHERE `id`=195310 AND `guid` IN(61663,61683);
UPDATE `gameobject` SET `position_x`=4020.56, `position_y`=5895.08, `position_z`=267.871 WHERE  `guid`=13355;

Set @Zootfizzle:= 28374;
Set @Dorian:= 28376;
Set @Hemet:= 28451;
Set @Stampy:= 28468;
DELETE FROM `vehicle_template_accessory` where `entry` in (@Stampy) AND `accessory_entry` in (@Hemet);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)VALUES
(@Stampy,@Hemet,1,1,'Stampy',8,0);
UPDATE creature_template SET npcflag= 16777216,  spell1=51756, spell2=51751, spell3=51752  WHERE entry=@Stampy; 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` in (@Zootfizzle, @Dorian, @Hemet, @Stampy);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` in (@Stampy);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@Stampy, 46598, 1, 0);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dorian AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dorian*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dorian*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Hemet AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Hemet*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Dorian, 0, 0, 0, 19, 0, 100, 0, 12614, 0, 0, 0, 11, 51757, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dorian - On quest Accept - cast'),
(@Hemet, 0, 0, 0, 0, 0, 100, 0, 0, 0, 6000, 6000, 11, 51742, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dorian - IC - cast'),
(@Hemet, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 15000, 15000, 11, 51740, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dorian - IC - cast'),
(@Dorian, 0, 1, 0, 20, 0, 100, 0, 12614, 0, 0, 0, 80, @Dorian*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dorian - On quest rewarded - ActionList'),
(@Dorian*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Hemet, 20, 0, 0, 0, 0, 0, 'Dorian - ActionList - Despawn'),
(@Dorian*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Hemet, 5, 0, 0, 0, 0, 8, 0, 0, 0, 6448.532715, 5082.552734, -63.941204, 0.673032, 'Dorian - ActionList - Summon'),
(@Dorian*100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 75, 59872, 0, 0, 0, 0, 0, 19, @Hemet, 20, 0, 0, 0, 0, 0, 'Dorian - ActionList - AddAura to trigger to triiger the event'),
(@Hemet, 0, 2, 0, 23, 0, 100, 0, 59872, 1, 0, 0, 80, @Hemet*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - HasAura - Actionlist'),
(@Hemet*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 59872, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Remove aura'),
(@Hemet*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 7, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 8, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Dorian, 20, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Despawn'),
-- Securing the Bait
(@Dorian, 0, 2, 0, 20, 0, 100, 0, 12605, 0, 0, 0, 80, @Dorian*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dorian - On quest rewarded - ActionList'),
(@Dorian*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'Dorian - ActionList - talk'),
(@Dorian*100+1, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Zootfizzle, 20, 0, 0, 0, 0, 0, 'Dorian - ActionList - talk'),
(@Dorian*100+1, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dorian - ActionList - talk'),
(@Dorian*100+1, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Zootfizzle, 20, 0, 0, 0, 0, 0, 'Dorian - ActionList - talk');
Delete from `creature_text` where `entry` in (@Hemet, @Dorian, @Zootfizzle);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Hemet, 0, 0, 'What a fight you missed, Dorian! It was one for the ages!', 12, 0, 100, 0, 0, 0, 'Hemet', 28026),
(@Hemet, 1, 0, 'There we were, riding into battle at full speed on the back of Stampy...', 12, 0, 100, 0, 0, 0, 'Hemet', 28027),
(@Hemet, 2, 0, 'Everything was shaking all over the place. I could hardly steady my gun.', 12, 0, 100, 0, 0, 0, 'Hemet', 28028),
(@Hemet, 3, 0, 'And then we saw her, the fearsome beast!', 12, 0, 100, 0, 0, 0, 'Hemet', 28029),
(@Hemet, 4, 0, 'It took all of $n''s skill to maintain control of Stampy.', 12, 0, 100, 0, 0, 0, 'Hemet', 28030),
(@Hemet, 5, 0, 'The battle was a haze of blood, lead, and sweat. The broodmother''s attacks came faster and faster!', 12, 0, 100, 0, 0, 0, 'Hemet', 28032),
(@Hemet, 6, 0, 'But, in the end, $n and I prevailed through our wits and teamwork. And now we have this glorious trophy as a memento of our victory.', 12, 0, 100, 0, 0, 0, 'Hemet', 28033),
(@Hemet, 7, 0, 'Do I detect a bit of jealousy, Dorian?', 12, 0, 100, 0, 0, 0, 'Hemet', 28036),
(@Dorian, 0, 0, 'Well, I don''t know. I was here tending the fire and discussing the drawbacks of cogs with Zootfizzle. That''s pretty epic, too, in its own way.', 12, 0, 100, 0, 0, 0, 'Dorian', 28037),
(@Dorian, 1, 0, 'It''s your lucky day, Zootfizzle. $n has brought back more hatchlings for you.', 12, 0, 100, 0, 0, 0, 'Dorian', 28892),
(@Dorian, 2, 0, 'Well, you can always go back to the camp and help Weslex with all his cogs...', 12, 0, 100, 0, 0, 0, 'Dorian', 28894),
(@Zootfizzle, 0, 0, 'I''m not here to be the keeper of your hatchlings, Dorian. I''m doing research of my own, as well.', 12, 0, 100, 0, 0, 0, 'Zootfizzle', 28893),
(@Zootfizzle, 1, 0, 'No, not the cogs! Anything but the cogs!', 12, 0, 100, 0, 0, 0, 'Zootfizzle', 28895);
SET @ENTRY := 21315; -- Guid 74638
SET @Drake := 22106;
UPDATE `creature_template` SET inhabittype=4,`speed_walk`=2.4,`speed_run`=1.71429,`ScriptName`='',`AIName`='SmartAI', unit_flags=32768, MovementType=2 WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Drake;
UPDATE `creature` SET `position_x`=-3761.743,`position_y`=1081.672,`position_z`=125.3161 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@drake;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,'Ruul the Darkener - On Spawn - StarWP'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ruul the Darkener - On Spawn - Set fly on'),
(@ENTRY,0,2,0,40,0,100,0,47,@ENTRY,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,'Ruul the Darkener - Reach wp - Re Start WP'),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Ruul the Darkener - On aggro -  ActionList'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ruul the Darkener - ActionList -  talk1'),
(@ENTRY*100,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ruul the Darkener - ActionList -  talk2'),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,85,38343,1,0,0,0,0,1,0,0,0,0,0,0,0,'Ruul the Darkener - On death -  Summon Ruul''s Nether Drake With Invoker_cast'),
(@Drake, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 5000, 5000, 11, 38344, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Drake - IC - CAST'),
(@Drake, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 10000, 10000, 11, 36513, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drake - IC - CAST'),
(@Drake, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 25, 0, 0, 0, 0, 0, 0, 'Drake - Just Summoned - StartAttack'),
(@ENTRY, 0, 5, 0, 0, 0, 100, 0, 3000, 3000, 6000, 6000, 11, 36073, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'ENTRY - IC - CAST'),
(@ENTRY, 0, 6, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 39153, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'ENTRY - IC - CAST'),
(@ENTRY, 0, 7, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'ENTRY - IC - CAST');
-- Waypoints for Ruul the Darkener from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-3805.743,1074.672,125.3161, 'Ruul the Darkener WP'),
(@ENTRY,2,-3806.74,1074.585,125.3161, 'Ruul the Darkener WP'),
(@ENTRY,3,-3844.399,1071.154,116.4082, 'Ruul the Darkener WP'),
(@ENTRY,4,-3871.77,1061.122,104.3527, 'Ruul the Darkener WP'),
(@ENTRY,5,-3897.401,1040.65,84.43602, 'Ruul the Darkener WP'),
(@ENTRY,6,-3923.55,1019.801,59.43599, 'Ruul the Darkener WP'),
(@ENTRY,7,-3946.312,1007.962,41.49157, 'Ruul the Darkener WP'),
(@ENTRY,8,-3981.2,987.1596,17.43604, 'Ruul the Darkener WP'),
(@ENTRY,9,-4003.07,957.1582,13.24213, 'Ruul the Darkener WP'),
(@ENTRY,10,-4012.831,932.0213,12.51513, 'Ruul the Darkener WP'),
(@ENTRY,11,-4023.356,901.5677,8.140135, 'Ruul the Darkener WP'),
(@ENTRY,12,-4033.129,864.9609,4.726814, 'Ruul the Darkener WP'),
(@ENTRY,13,-4039.05,829.5438,1.101814, 'Ruul the Darkener WP'),
(@ENTRY,14,-4046.8,785.2863,2.422696, 'Ruul the Darkener WP'),
(@ENTRY,15,-4053.405,754.4661,1.867994, 'Ruul the Darkener WP'),
(@ENTRY,16,-4077.986,718.4368,1.501426, 'Ruul the Darkener WP'),
(@ENTRY,17,-4104.671,681.145,2.619006, 'Ruul the Darkener WP'),
(@ENTRY,18,-4124.385,652.7042,3.424712, 'Ruul the Darkener WP'),
(@ENTRY,19,-4139.037,629.68,4.261003, 'Ruul the Darkener WP'),
(@ENTRY,20,-4144.591,607.7719,5.011003, 'Ruul the Darkener WP'),
(@ENTRY,21,-4148.39,587.783,8.4231, 'Ruul the Darkener WP'),
(@ENTRY,22,-4155.772,562.8152,11.38299, 'Ruul the Darkener WP'),
(@ENTRY,23,-4165.006,542.4948,15.88299, 'Ruul the Darkener WP'),
(@ENTRY,24,-4174.202,524.9961,22.73551, 'Ruul the Darkener WP'), -- fi Aller 
(@ENTRY,25,-4165.006,542.4948,15.88299, 'Ruul the Darkener WP'),-- début du retour
(@ENTRY,26,-4155.772,562.8152,11.38299, 'Ruul the Darkener WP'),
(@ENTRY,27,-4148.39,587.783,8.4231, 'Ruul the Darkener WP'),
(@ENTRY,28,-4144.591,607.7719,5.011003, 'Ruul the Darkener WP'),
(@ENTRY,29,-4139.037,629.68,4.261003, 'Ruul the Darkener WP'),
(@ENTRY,30,-4124.385,652.7042,3.424712, 'Ruul the Darkener WP'),
(@ENTRY,31,-4104.671,681.145,2.619006, 'Ruul the Darkener WP'),
(@ENTRY,32,-4077.986,718.4368,1.501426, 'Ruul the Darkener WP'),
(@ENTRY,33,-4053.405,754.4661,1.867994, 'Ruul the Darkener WP'),
(@ENTRY,34,-4046.8,785.2863,2.422696, 'Ruul the Darkener WP'),
(@ENTRY,35,-4039.05,829.5438,1.101814, 'Ruul the Darkener WP'),
(@ENTRY,36,-4033.129,864.9609,4.726814, 'Ruul the Darkener WP'),
(@ENTRY,37,-4023.356,901.5677,8.140135, 'Ruul the Darkener WP'),
(@ENTRY,38,-4012.831,932.0213,12.51513, 'Ruul the Darkener WP'),
(@ENTRY,39,-4003.07,957.1582,13.24213, 'Ruul the Darkener WP'),
(@ENTRY,40,-3981.2,987.1596,17.43604, 'Ruul the Darkener WP'),
(@ENTRY,41,-3946.312,1007.962,41.49157, 'Ruul the Darkener WP'),
(@ENTRY,42,-3923.55,1019.801,59.43599, 'Ruul the Darkener WP'),
(@ENTRY,43,-3897.401,1040.65,84.43602, 'Ruul the Darkener WP'),
(@ENTRY,44,-3871.77,1061.122,104.3527, 'Ruul the Darkener WP'),
(@ENTRY,45,-3844.399,1071.154,116.4082, 'Ruul the Darkener WP'),
(@ENTRY,46,-3806.74,1074.585,125.3161, 'Ruul the Darkener WP'),
(@ENTRY,47,-3805.743,1074.672,125.3161, 'Ruul the Darkener WP');
Delete from `creature_text` where `entry` in (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@ENTRY, 0, 0, 'The skies will darken and all will go quiet. Only then will you know the sweet serenity of death...', 12, 0, 100, 0, 0, 0, 'Ruul the Darkener', 19291),
(@ENTRY, 1, 0, 'Your world is at an end.', 12, 0, 100, 0, 0, 0, 'Ruul the Darkener', 19290);
SET @Pentarus := 28160; -- Archmage Pentarus
SET @SPELL := 50860;  -- Summon Machine 28192
Set @Machine:= 28192;
Set @Spell2 := 51036; -- Summon Summon Venture Co. Air Patrol 28229
Set @AirPatrol:= 28229;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@Pentarus;
UPDATE `creature_template` SET `npcflag`= 16777216, `InhabitType`=4, `AIName`='SmartAI', `VehicleId`=220 WHERE `entry`=@Machine;
UPDATE `creature_template` SET `InhabitType`=4, `AIName`='SmartAI'  WHERE `entry`=@AirPatrol;
UPDATE creature_template SET InhabitType=4, `AIName`='SmartAI' WHERE entry=27987;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Pentarus;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Pentarus*100;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Machine;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Machine*100;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Machine;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Machine*100+1;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Machine*100+2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@AirPatrol;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@AirPatrol*100;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=27987*100;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27987 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Pentarus,0,0,0,62,0,100,0,10024,0,0,0,80,@Pentarus*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Archmage Pentarus - On gossip option select  - run script'),
(@Pentarus*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Archmage Pentarus - Actionlist - Close gossip'),
(@Pentarus*100,9,1,0,0,0,100,0,0,0,0,0,85,@SPELL,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Archmage Pentarus - Script - Cast Flight to Sholazar on player'),
(@Pentarus*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Archmage Pentarus - Script - say 0'), 
(@Pentarus*100,9,3,0,0,0,100,0,0,0,0,0,50,190488,19,0,0,0,0,8,0,0,0,5832.702637, 436.761108, 669.141174, 1.612513, 'Archmage Pentarus - Script - spawn portal'),
(@Machine, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Machine*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On summon - Action List'),
(@Machine*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - Set Fly ON'),
(@Machine*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 46598, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - CrossCast'),
(@Machine*100, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5832.702637, 436.761108, 669.141174, 0.612513, 'Machine - Action List - InvokerCast'),
(@Machine*100, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 11, 50987, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - cast teleportation'),
(@Machine*100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 53, 1, @Machine, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - Start wp'),
(@Machine, 0, 1, 0, 40, 0, 100, 0, 1, 0, 0, 0, 80, @Machine*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - on wp end - ActionList'),
(@Machine*100+1, 9, 0, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 11, @Spell2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - cast spell to invok AirPatrol'),
(@AirPatrol, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @AirPatrol*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - On spawn - Action List'),
(@AirPatrol*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Set Fly ON'),
(@AirPatrol*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Set react passif'),
(@AirPatrol*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 29, 5, 45, 0, 0, 0, 0, 19, @Machine, 60, 0, 0, 0, 0, 0, '@AirPatrol - Action List - follow target'),
(@AirPatrol*100, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Talk'),
(@AirPatrol*100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Talk'),
(@AirPatrol*100, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 8, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 9, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 10, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 11, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50892, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 12, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50892, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 13, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50892, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 14, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50892, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 15, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50892, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@Machine, 0, 2, 0, 40, 0, 100, 0, 2, 0, 0, 0, 80, 27987*100, 2, 0, 0, 0, 0, 10, 103289, 27987, 0, 0, 0, 0, 0, '@Machine - On WP2 - Actionlist'),
(27987*100, 9, 0, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, '27987 - Action List - talk'),
(@Machine, 0, 3, 0, 40, 0, 100, 0, 3, 0, 0, 0, 80, @Machine*100+2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@Machine - On spellHit - Actionlist'),
(@Machine*100+2, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 75, 61360, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, '@Machine - Actionlist - Add parachute'),
(@Machine*100+2, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@Machine - Actionlist - Eject passenger'),
(27987, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ' 27987 - On spawn - set fly on');
DELETE FROM `waypoints` WHERE `entry` IN(@Machine);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@Machine, 1, 5478.141113, 4971.844238, -22.431667, 'Archimage Pentarus Flying Machine'),
(@Machine, 2, 5593.686035, 5187.787109, -72.69004, 'Archimage Pentarus Flying Machine'),
(@Machine, 3, 5647.750488, 5229.604004, -72.69004, 'Archimage Pentarus Flying Machine');
DELETE FROM `creature_text` WHERE `entry`in (@AirPatrol, 27987, @Machine, 28160);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(28160,0,0, 'I''ll send you on my flying machine. Keep your eyes peeled for clues about what might''ve happened to Hemet!',12,0,100,25,0,0, 'Archmage Pentarus',27620),
(@AirPatrol,0,0, 'More intruders? You''ll soon learn, no one messes with the Venture Company!',14,0,100,0,0,0, 'Venture Co. Air Patrol',27611),
(27987,0,0, 'Over here, to the southeast. I see they got you too...',14,0,100,0,0,0, 'Monte Muzzleshot',27610),
(@Machine,0,0, 'WARNING: Missile lock detected. Engaging evasive maneuvers.',12,0,100,0,0,0, 'Archimage Pentarus Flying Machine',27621);
DELETE FROM `spell_target_position` WHERE `ID` in (50987, 50859); 
INSERT INTO `spell_target_position` (`ID`,`MapID`,`PositionX`,`PositionY`,`PositionZ`) VALUES
(50987, 571, 5071.35, 4642.54, 72.164),-- Teleport to Sholazar
(50859,571, 5832.892, 482.8708, 658.2753);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@Machine;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@Machine,46598,1,0);  -- Archmage Pentarus' Flying Machine - Ride Vehicle Hardcoded
DELETE FROM `creature_addon` WHERE `guid`=103289; -- Monte Muzzleshot
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`)VALUES
(103289,0,0,1,0, '50544'); -- Monte Muzzleshot, aura: Cosmetic - Parachute Stuck
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10024;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10024,0,0,28,12521,0,0,0,'','Show gossip option if player has quest Where in the World is Hemet Nesingwary?');
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10024 AND `id`=1;
Delete from `conditions` where `SourceTypeOrReferenceId`=13 AND `SourceEntry`in (50878, 50892);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 50892, 0, 31, 3, @Machine, 0, 0, '', 'Only petrus flying machine is the target for the rockets'),
(13, 1, 50878, 0, 31, 3, @Machine, 0, 0, '', 'Only petrus flying machine is the target for the rockets');

UPDATE `creature_template` SET `DamageModifier`=5 WHERE  `entry`=28468;

DELETE FROM `creature_text` WHERE `entry` IN(33662,33701,33626,33686,33696);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(33662, 0, 0, 'Any luck?', 12, 0, 100, 0, 0, 0, 34184, 'Kirin Tor Battle-Mage to Player'),
(33662, 1, 0, 'Keep at it. If our suspicions are right and this is a transporter, it could prove extremely useful in our assault.', 12, 0, 100, 0, 0, 0, 34186, 'Kirin Tor Battle-Mage to Player'),
(33701, 0, 0, 'I heard a story or two of a Lore Keeper in Uldaman that fit your description. Do you serve a similar purpose?', 12, 0, 100, 0, 0, 0, 33702, 'High Explorer Dellorah to Player'),
(33701, 1, 0, 'Frontal defense systems? Is there something I should let Brann know before he has anyone attempt to enter the complex?', 12, 0, 100, 0, 0, 0, 33704, 'High Explorer Dellorah to Player'),
(33701, 2, 0, 'Can you detail the nature of these defense systems?', 12, 0, 100, 0, 0, 0, 33706, 'High Explorer Dellorah to Player'),
(33701, 3, 0, 'Got it. At least we don''t have to deal with those orbital emplacements.', 12, 0, 100, 0, 0, 0, 33708, 'High Explorer Dellorah to Player'),
(33701, 4, 0, 'Rhydian, make sure you let Brann and Archmage Pentarus know about those defenses immediately.', 12, 0, 100, 0, 0, 0, 33709, 'High Explorer Dellorah to Player'),
(33701, 5, 0, 'And you mentioned an imprisoned entity? What is the nature of this entity and what is its status?', 12, 0, 100, 0, 0, 0, 33710, 'High Explorer Dellorah to Player'),
(33701, 6, 0, 'Yogg-Saron is here? It sounds like we really will have our hands full then.', 12, 0, 100, 0, 0, 0, 33713, 'High Explorer Dellorah to Player'),
(33626, 0, 0, 'Not a bit. For the life of me, I can''t figure out how this thing works.', 12, 0, 100, 0, 0, 0, 34183, 'Hired Engineer to Player'),
(33626, 1, 0, 'I know, I know... I haven''t given up yet. Don''t get your hopes up though, this technology is way beyond me.', 12, 0, 100, 0, 0, 0, 34187, 'Hired Engineer to Player'),
(33686, 0, 0, 'I was constructed to serve as a repository for essential information regarding this complex. My primary functions include communicating the status of the frontal defense systems and assessing the status of the entity that this complex was built to imprison.', 12, 0, 100, 0, 0, 0, 33703, 'Lore Keeper of Norgannon to Player'),
(33686, 1, 0, 'Compromise of complex detected, security override enabled - query permitted.', 12, 0, 100, 0, 0, 0, 33707, 'Lore Keeper of Norgannon to Player'),
(33686, 2, 0, 'Primary defensive emplacements consist of iron constructs and Storm Beacons, which will generate additional constructs as necessary. Secondary systems consist of orbital defense emplacements.', 12, 0, 100, 0, 0, 0, 33712, 'Lore Keeper of Norgannon to Player'),
(33686, 3, 0, 'Entity designate: Yogg-Saron. Security has been compromised. Prison operational status unknown. Unable to contact Watchers for notification purposes.', 12, 0, 100, 0, 0, 0, 33711, 'Lore Keeper of Norgannon to Player'),
(33696, 0, 0, '%s nods.', 16, 0, 100, 0, 0, 0, 33715, 'Archmage Rhydian to Player'),
(33696, 1, 0, '%s whispers something to Brann.', 16, 0, 100, 0, 0, 0, 33716, 'Archmage Rhydian to Player');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(33662,33701,33696);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(33696,33701,-136527) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(3369600,3370100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-136527,0,0,0,10,0,100,0,1,40,90000,120000,80,3369600,2,0,0,0,0,1,0,0,0,0,0,0,0,'Kirin Tor Battle-Mage - OOC Los - Run Script'),
(33701,0,0,0,10,0,100,1,1,40,30000,60000,80,3370100,2,0,0,0,0,1,0,0,0,0,0,0,0,'High Explorer Dellorah - OOC Los - Run Script (No repeat)'),
(33696,0,0,0,38,0,100,0,1,1,0,0,1,0,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Archmage Rhydian - On Data Set - Say Line 0'),
(33696,0,1,0,52,0,100,0,0,33696,0,0,53,1,33696,0,0,0,0,1,0,0,0,0,0,0,0,'Archmage Rhydian - On Text Over (Line 0) - Start WP'),
(33696,0,2,3,40,0,100,0,8,33696,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archmage Rhydian - On Reached WP8 - Pause WP'),
(33696,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archmage Rhydian - On Reached WP8 - Say Line 1'),
(33696,0,4,0,40,0,100,0,10,33696,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.916666,'Archmage Rhydian - On Reached WP10 - Set Orientation'),
(3369600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kirin Tor Battle-Mage - Script - Say Line 0'),
(3369600, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 33626, 0, 0, 0, 0, 0, 0, 'Kirin Tor Battle-Mage - Script - Say Line 0 (Hired Engineer)'),
(3369600, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kirin Tor Battle-Mage - Script - Say Line 1'),
(3369600, 9, 3, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 33626, 0, 0, 0, 0, 0, 0, 'Kirin Tor Battle-Mage - Script - Say Line 1 (Hired Engineer)'),
(3370100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 0'),
(3370100, 9, 1, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 33686, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 0 (Lore Keeper of Norgannon)'),
(3370100, 9, 2, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 1'),
(3370100, 9, 3, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 2'),
(3370100, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 33686, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 1 (Lore Keeper of Norgannon)'),
(3370100, 9, 5, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 33686, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 2 (Lore Keeper of Norgannon)'),
(3370100, 9, 6, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 3'),
(3370100, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 4'),
(3370100, 9, 8, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 5'),
(3370100, 9, 9, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33696, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Set Data to Archmage Rhydian'),
(3370100, 9, 10, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 33686 , 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 3 (Lore Keeper of Norgannon)'),
(3370100, 9, 11, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 6');

DELETE FROM `waypoints` WHERE `entry`=33696;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(33696, 1, -769.512 ,-120.8109 ,429.5509, 'Archmage Rhydian'),
(33696, 2, -769.1432 ,-104.0848 ,429.8661, 'Archmage Rhydian'),
(33696, 3, -763.0945 ,-86.176 ,429.9557, 'Archmage Rhydian'),
(33696, 4, -755.0403 ,-68.30566 ,429.9557, 'Archmage Rhydian'),
(33696, 5, -746.3733 ,-54.03885 ,429.9657, 'Archmage Rhydian'),
(33696, 6, -738.9852 ,-49.87864 ,429.9657, 'Archmage Rhydian'),
(33696, 7, -729.1484 ,-49.88547 ,429.9657, 'Archmage Rhydian'),
(33696, 8, -718.4777 ,-52.54433 ,429.8407, 'Archmage Rhydian'),
(33696, 9, -768.5124 ,-112.0747 ,429.8398, 'Archmage Rhydian'),
(33696, 10, -773.566 ,-144.6838 ,429.9191, 'Archmage Rhydian');
--
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=21004;
DELETE FROM `gossip_menu` WHERE `entry` in(10355,10366,10477);

INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(10355, 14369),
(10366, 14375),
(10477, 14496);

DELETE FROM `gossip_menu_option` WHERE `menu_id` in(10355,10366,10477);

INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(10355, 0, 0, 'We''re ready. Begin the assault!', 33652, 1, 1, 0, 0, 0, 0, NULL, 0),
(10366, 0, 0, 'Activate secondary defensive systems.', 34420, 1, 1, 10477, 0, 0, 0, NULL, 0),
(10477, 0, 0, 'Confirmed.', 34421, 1, 1, 0, 0, 0, 0, NULL, 0);

UPDATE `creature_template` SET `gossip_menu_id`=10355 WHERE  `entry`=33579;
UPDATE `creature_template` SET `gossip_menu_id`=10366 WHERE  `entry`=33686;
SET @OGUID := 6166;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 181575, 533, 3, 1, 3465.175, -3940.402, 308.79, 2.443457, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- 181575 (Area: 3456)
(@OGUID+1, 181578, 533, 3, 1, 2493.018, -2921.778, 241.1933, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- 181578 (Area: -1)
(@OGUID+2, 181576, 533, 3, 1, 3539.016, -2936.821, 302.4756, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1); -- 181576 (Area: 3456)

-- These gameobjects have wrong flags at tdb 335, it's fine at 6.x. As seen on sniffs, they should have flags 16. Previous value was 6553616.
UPDATE `gameobject_template` SET `flags` = 16 WHERE `entry` IN (181575, 181576);
--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE entry IN (32451);

UPDATE `creature` SET `modelid`=0, movementType=2 WHERE guid IN (114330, 114331);

DELETE FROM creature_addon WHERE guid = 114331;
INSERT INTO creature_addon (guid, path_id, mount, bytes1, bytes2, emote,auras) VALUES (114331, 1143310, 0, 0, 1, 0, '');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (32451);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32451, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 120000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dalaran Citizen - Ooc - talk');

DELETE FROM waypoint_data WHERE id=1143310;
INSERT INTO waypoint_data (id, POINT, position_x, position_y, position_z, orientation, delay, move_type, ACTION, action_chance, wpguid) VALUES
(1143310, 1, 5961.356445, 661.699219, 641.721252, 0, 0, 0, 0, 100, 0),
(1143310, 2, 5954.011230, 657.709167, 641.991577, 0, 0, 0, 0, 100, 0),
(1143310, 3, 5947.983887, 658.844055, 642.101562, 0, 0, 0, 0, 100, 0),
(1143310, 4, 5950.894043, 662.109314, 641.363831, 0, 0, 0, 0, 100, 0),
(1143310, 5, 5959.004395, 674.209778, 640.880432, 0, 0, 0, 0, 100, 0),
(1143310, 6, 5961.065430, 680.407043, 640.494263, 0, 0, 0, 0, 100, 0),
(1143310, 7, 5962.776367, 679.769470, 640.680603, 0, 0, 0, 0, 100, 0),
(1143310, 8, 5963.701172, 675.173035, 640.749817, 0, 0, 0, 0, 100, 0),
(1143310, 9, 5963.879883, 666.781982, 641.512024, 0, 20000, 0, 0, 100, 0);

DELETE FROM creature_text WHERE entry IN (32451);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(32451, 0, 0, 'She said to meet her right here... maybe I''m in the wrong place?', 12, 0, 100, 1, 0, 0, 'Dalaran Citizen', 33069), 
(32451, 0, 1, 'Luckily, the Lich King''s grasp has not reached Dalaran yet.', 12, 0, 100, 1, 0, 0, 'Dalaran Citizen', 33068), 
(32451, 0, 2, 'Sometimes it''s nice to get away from the sanctum and get some fresh air.', 12, 0, 100, 1, 0, 0, 'Dalaran Citizen', 33067);

UPDATE `creature` SET movementType=2 WHERE guid IN (28686);

DELETE FROM creature_addon WHERE guid IN (28686);
INSERT INTO creature_addon (guid, path_id, mount, bytes1, bytes2, emote,auras) 
VALUES (28686, 286860, 0, 0, 0, 0, '');

DELETE FROM waypoint_data WHERE id IN (286860);
INSERT INTO waypoint_data (id, POINT, position_x, position_y, position_z, orientation, delay, move_type, ACTION, action_chance, wpguid)VALUES
(286860, 1, 5960.950195, 598.314026, 650.627014, 0, 0, 0, 0, 100, 0),
(286860, 2, 5957.295898, 617.082153, 650.627258, 0, 0, 0, 0, 100, 0), 
(286860, 3, 5894.468262, 657.878052, 644.688843, 0, 0, 0, 0, 100, 0), 
(286860, 4, 5823.077637, 714.962402, 641.066895, 0, 0, 0, 0, 100, 0), 
(286860, 5, 5799.794922, 719.503174, 640.661865, 0, 0, 0, 0, 100, 0), 
(286860, 6, 5770.590820, 703.946777, 641.473755, 0, 0, 0, 0, 100, 0), 
(286860, 7, 5728.678223, 659.602661, 645.874878, 0, 0, 0, 0, 100, 0), 
(286860, 8, 5716.125977, 657.985718, 646.207947, 0, 0, 0, 0, 100, 0), 
(286860, 9, 5701.286621, 654.542480, 646.277710, 0, 0, 0, 0, 100, 0),
(286860, 10, 5697.024902, 648.178040, 646.409180, 0, 0, 0, 0, 100, 0),
(286860, 11, 5728.723633, 617.990295, 647.119080, 0, 0, 0, 0, 100, 0),
(286860, 12, 5764.286621, 595.154358, 649.794617, 0, 0, 0, 0, 100, 0),
(286860, 13, 5771.400391, 598.777588, 650.299805, 0, 0, 0, 0, 100, 0),
(286860, 14, 5798.370605, 631.354919, 647.415161, 0, 20000, 0, 0, 100, 0),
(286860, 15, 5809.011719, 632.435669, 647.466370, 0, 0, 0, 0, 100, 0),
(286860, 16, 5813.840332, 639.437012, 647.445251, 0, 0, 0, 0, 100, 0),
(286860, 17, 5812.633301, 647.708679, 647.411682, 0, 0, 0, 0, 100, 0),
(286860, 18, 5837.737305, 679.004089, 643.481323, 0, 0, 0, 0, 100, 0),
(286860, 19, 5863.233887, 672.251282, 644.026489, 0, 0, 0, 0, 100, 0),
(286860, 20, 5872.090332, 660.963562, 644.639648, 0, 0, 0, 0, 100, 0),
(286860, 21, 5871.882812, 655.302795, 645.210327, 0, 0, 0, 0, 100, 0),
(286860, 22, 5866.628906, 656.807068, 645.358337, 0, 0, 0, 0, 100, 0),
(286860, 23, 5858.618164, 665.766174, 647.507935, 0, 0, 0, 0, 100, 0),
(286860, 24, 5854.410645, 663.378418, 647.491699, 0, 0, 0, 0, 100, 0),
(286860, 25, 5853.316406, 646.056763, 647.511597, 0, 0, 0, 0, 100, 0),
(286860, 26, 5855.305664, 646.037170, 647.511597, 0, 20000, 0, 0, 100, 0),
(286860, 27, 5853.801270, 644.892761, 647.511597, 0, 0, 0, 0, 100, 0),
(286860, 28, 5854.399902, 639.586365, 647.511597, 0, 0, 0, 0, 100, 0),
(286860, 29, 5861.342773, 632.158997, 647.913147, 0, 0, 0, 0, 100, 0),
(286860, 30, 5873.931152, 637.613953, 646.993347, 0, 0, 0, 0, 100, 0),
(286860, 31, 5888.598145, 639.828796, 646.219421, 0, 0, 0, 0, 100, 0),
(286860, 32, 5911.427246, 634.141296, 645.621460, 0, 0, 0, 0, 100, 0),
(286860, 33, 5944.164062, 622.176941, 650.655151, 0, 0, 0, 0, 100, 0),
(286860, 34, 5958.649414, 608.832092, 650.627136, 0, 0, 0, 0, 100, 0),
(286860, 35, 5960.950195, 598.314026, 650.627014, 0, 20000, 0, 0, 100, 0);
--
DELETE FROM `spell_proc_event` WHERE `entry` IN (71174,71198);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(71174, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0),
(71198, 4, 11, 0, 0, 0, 0, 0, 0, 0, 0);
-- Adding missing spawn Bleeding Hollow Dark Shaman Entry: 16873
SET @GUID := 29978;
DELETE FROM `creature` WHERE `guid` = @GUID AND `id` = 16873;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`, `curmana`, `MovementType`) VALUES
(@GUID, 16873, 530, -945.313, 1948.252, 58.1359, 67.06455, 300, 3984, 2434, 2);

-- Bleeding Hollow Dark Shaman SAI
SET @ENTRY := 16873;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Out of Combat - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Out of Combat - Cast 'Lightning Shield' (No Repeat)"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Aggro - Cast 'Shadow Bolt' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Aggro - Increment Phase By 1 (No Repeat)"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Within 0-40 Range - Cast 'Shadow Bolt' (No Repeat)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-30% Health - Cast 'Bloodlust' (Phase 1) (No Repeat)"),
(@ENTRY,0,12,0,0,0,100,0,4000,8000,30000,45000,11,32062,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - In Combat - Cast 'Fire Nova Totem' (Phase 1) (No Repeat)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,16,0,5,0,100,1,0,0,0,0,11,34013,1,0,0,0,0,7,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Killed Unit - Cast 'Raise Soul' (No Repeat)");

-- Pathing for Bleeding Hollow Dark Shaman Entry: 16873 'TDB FORMAT' 
SET @NPC := 58257;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1058.69,`position_y`=2123.373,`position_z`=51.63616 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1058.69,2123.373,51.63616,0,0,0,0,100,0),
(@PATH,2,-1057.219,2099.756,59.51154,0,0,0,0,100,0),
(@PATH,3,-1044.785,2080.962,64.48811,0,0,0,0,100,0),
(@PATH,4,-1027.752,2060.003,67.17399,0,0,0,0,100,0),
(@PATH,5,-1035.883,2045.864,67.88428,0,0,0,0,100,0),
(@PATH,6,-1024.891,2036.104,67.17399,0,0,0,0,100,0),
(@PATH,7,-1011.885,2038.549,67.04899,0,0,0,0,100,0),
(@PATH,8,-993.7006,2017.729,67.06455,0,0,0,0,100,0),
(@PATH,9,-1008.182,1997.039,67.06455,0,0,0,0,100,0),
(@PATH,10,-992.9711,2018.175,67.06455,0,0,0,0,100,0),
(@PATH,11,-971.9114,2014.351,67.06455,0,0,0,0,100,0),
(@PATH,12,-992.9711,2018.175,67.06455,0,0,0,0,100,0),
(@PATH,13,-1008.182,1997.039,67.06455,0,0,0,0,100,0),
(@PATH,14,-1008.182,1997.039,67.06455,0,0,0,0,100,0),
(@PATH,15,-993.7006,2017.729,67.06455,0,0,0,0,100,0),
(@PATH,16,-1011.885,2038.549,67.04899,0,0,0,0,100,0),
(@PATH,17,-1011.885,2038.549,67.04899,0,0,0,0,100,0),
(@PATH,18,-1024.891,2036.104,67.17399,0,0,0,0,100,0),
(@PATH,19,-1035.883,2045.864,67.88428,0,0,0,0,100,0),
(@PATH,20,-1027.752,2060.003,67.17399,0,0,0,0,100,0),
(@PATH,21,-1027.752,2060.003,67.17399,0,0,0,0,100,0),
(@PATH,22,-1044.785,2080.966,64.57795,0,0,0,0,100,0),
(@PATH,23,-1057.219,2099.756,59.51154,0,0,0,0,100,0);
-- 0xF13041E90060F72D .go -1058.69 2123.373 51.63616

-- Pathing for Bleeding Hollow Dark Shaman Entry: 16873 'TDB FORMAT' 
SET @NPC := 58256;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1144.076,`position_y`=1954.738,`position_z`=80.57024 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1144.076,1954.738,80.57024,0,0,0,0,100,0),
(@PATH,2,-1133.44,1972.225,73.66801,0,0,0,0,100,0),
(@PATH,3,-1122.611,1999.216,68.83028,0,0,0,0,100,0),
(@PATH,4,-1099.563,2031.872,67.05327,0,0,0,0,100,0),
(@PATH,5,-1084.684,2065.122,66.82748,0,0,0,0,100,0),
(@PATH,6,-1070.713,2090.635,62.18363,0,0,0,0,100,0),
(@PATH,7,-1100.243,2084.849,66.59998,0,0,0,0,100,0),
(@PATH,8,-1129.753,2078.135,67.00842,0,0,0,0,100,0),
(@PATH,9,-1100.243,2084.849,66.59998,0,0,0,0,100,0),
(@PATH,10,-1070.713,2090.635,62.18363,0,0,0,0,100,0),
(@PATH,11,-1084.646,2065.203,66.72787,0,0,0,0,100,0),
(@PATH,12,-1099.563,2031.872,67.05327,0,0,0,0,100,0),
(@PATH,13,-1122.611,1999.216,68.83028,0,0,0,0,100,0),
(@PATH,14,-1133.43,1972.312,73.66801,0,0,0,0,100,0);
-- 0xF13041E900612D35 .go -1144.076 1954.738 80.57024

-- Pathing for Bleeding Hollow Dark Shaman Entry: 16873 'TDB FORMAT' 
SET @NPC := 58258;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1060.848,`position_y`=2105.119,`position_z`=58.13591 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1060.848,2105.119,58.13591,0,0,0,0,100,0),
(@PATH,2,-1037.167,2107.136,59.97014,0,0,0,0,100,0),
(@PATH,3,-1018.748,2084.713,68.99667,0,0,0,0,100,0),
(@PATH,4,-990.0961,2053.444,67.06454,0,0,0,0,100,0),
(@PATH,5,-961.8248,2037.499,67.04703,0,0,0,0,100,0),
(@PATH,6,-938.3379,2024.596,65.73439,0,0,0,0,100,0),
(@PATH,7,-921.1564,2015.199,62.66013,0,0,0,0,100,0),
(@PATH,8,-909.5775,1992.915,67.29996,0,0,0,0,100,0),
(@PATH,9,-889.6608,1985.54,67.38715,0,0,0,0,100,0),
(@PATH,10,-879.1632,1955.284,67.81312,0,0,0,0,100,0),
(@PATH,11,-877.1085,1921.789,70.60205,0,0,0,0,100,0),
(@PATH,12,-901.7319,1883,76.4217,0,0,0,0,100,0),
(@PATH,13,-877.1085,1921.789,70.60205,0,0,0,0,100,0),
(@PATH,14,-879.1632,1955.284,67.81312,0,0,0,0,100,0),
(@PATH,15,-889.6608,1985.54,67.38715,0,0,0,0,100,0),
(@PATH,16,-909.5775,1992.915,67.29996,0,0,0,0,100,0),
(@PATH,17,-921.1564,2015.199,62.66013,0,0,0,0,100,0),
(@PATH,18,-938.3379,2024.596,65.73439,0,0,0,0,100,0),
(@PATH,19,-961.8248,2037.499,67.04703,0,0,0,0,100,0),
(@PATH,20,-990.0961,2053.444,67.06454,0,0,0,0,100,0),
(@PATH,21,-1018.748,2084.713,68.99667,0,0,0,0,100,0),
(@PATH,22,-1037.167,2107.136,59.97014,0,0,0,0,100,0),
(@PATH,23,-1060.848,2105.119,58.13591,0,0,0,0,100,0);
-- 0xF13041E90061464D .go -1060.848 2105.119 58.13591

-- Pathing for Bleeding Hollow Dark Shaman Entry: 16873 'TDB FORMAT' 
SET @NPC := 6747;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-945.313,`position_y`=1948.252,`position_z`=67.06455 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-945.313,1948.252,67.06455,0,0,0,0,100,0),
(@PATH,2,-946.7964,1966.628,67.06455,0,0,0,0,100,0),
(@PATH,3,-932.1639,1983.549,66.96194,0,0,0,0,100,0),
(@PATH,4,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,5,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,6,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,7,-941.426,2015.632,66.31691,0,0,0,0,100,0),
(@PATH,8,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,9,-968.4443,2047.705,67.06454,0,0,0,0,100,0),
(@PATH,10,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,11,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,12,-941.426,2015.632,66.31691,0,0,0,0,100,0),
(@PATH,13,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,14,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,15,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,16,-932.1639,1983.549,66.96194,0,0,0,0,100,0),
(@PATH,17,-946.7964,1966.628,67.06455,0,0,0,0,100,0);
-- 0xF13041E90061F326 .go -945.313 1948.252 67.06455
-- Updating SAI
-- Dreadcaller SAI
SET @ENTRY := 19434;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Out of Combat - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,32666,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - On Aggro - Cast 'Shadow Bolt' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - On Aggro - Increment Phase By 1 (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,32666,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - Within 0-40 Range - Cast 'Shadow Bolt' (No Repeat)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,10,0,0,0,100,0,4000,9000,18100,24000,11,11443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - In Combat - Cast 'Cripple' (Phase 1) (No Repeat)");

-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69502;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=177.5729,`position_y`=2268.238,`position_z`=48.5948 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,177.5729,2268.238,48.5948,0,0,0,0,100,0),
(@PATH,2,206.0571,2228.519,54.04856,0,0,0,0,100,0);
-- 0xF1304BEA00397367 .go 177.5729 2268.238 48.5948

-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69501;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=190.7178,`position_y`=2286.323,`position_z`=49.66181 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,190.7178,2286.323,49.66181,0,0,0,0,100,0),
(@PATH,2,210.6431,2285.845,53.60326,0,0,0,0,100,0),
(@PATH,3,222.5459,2286.666,56.13475,0,0,0,0,100,0),
(@PATH,4,231.5569,2296.63,60.31371,0,0,0,0,100,0),
(@PATH,5,220.7462,2308.746,60.02021,0,0,0,0,100,0),
(@PATH,6,208.7211,2311.991,57.36103,0,0,0,0,100,0),
(@PATH,7,195.7977,2312.93,53.85427,0,0,0,0,100,0),
(@PATH,8,181.254,2297.919,50.28107,0,0,0,0,100,0);
-- 0xF1304BEA00396ED6 .go 190.7178 2286.323 49.66181

-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69500;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=233.3709,`position_y`=2074.927,`position_z`=39.10539 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,233.3709,2074.927,39.10539,0,0,0,0,100,0),
(@PATH,2,228.1582,2076.218,39.70464,0,0,0,0,100,0),
(@PATH,3,226.8357,2086.181,39.48833,0,0,0,0,100,0),
(@PATH,4,227.4231,2100.461,39.53439,0,0,0,0,100,0),
(@PATH,5,231.5971,2104.666,38.92635,0,0,0,0,100,0),
(@PATH,6,237.6874,2098.439,39.00676,0,0,0,0,100,0),
(@PATH,7,241.6207,2088.015,38.11906,0,0,0,0,100,0),
(@PATH,8,238.947,2078.802,38.06547,0,0,0,0,100,0);
-- 0xF1304BEA00353517 .go 233.3709 2074.927 39.10539


-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69503;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-523.7537,`position_y`=2008.213,`position_z`=82.43176 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-523.7537,2008.213,82.43176,0,0,0,0,100,0),
(@PATH,2,-513.3772,2034.226,82.13103,0,0,0,0,100,0),
(@PATH,3,-501.1374,2063.957,81.46646,0,0,0,0,100,0),
(@PATH,4,-490.7202,2097.977,79.50304,0,0,0,0,100,0),
(@PATH,5,-495.6437,2124.143,75.1469,0,0,0,0,100,0),
(@PATH,6,-500.0753,2152.032,70.07507,0,0,0,0,100,0),
(@PATH,7,-497.6553,2131.211,73.99121,0,0,0,0,100,0),
(@PATH,8,-488.903,2108.3,78.71799,0,0,0,0,100,0),
(@PATH,9,-496.6252,2076.111,81.08714,0,0,0,0,100,0),
(@PATH,10,-505.7927,2051.876,81.88617,0,0,0,0,100,0),
(@PATH,11,-519.2833,2018.794,82.35017,0,0,0,0,100,0),
(@PATH,12,-523.7976,2008.294,82.49103,0,0,0,0,100,0);
-- 0x1C09E4424012FA8000002000004E9B0D .go -523.7537 2008.213 82.43176

-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69499;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-558.5822,`position_y`=2003.227,`position_z`=98.30606 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-558.5822,2003.227,98.30606,0,0,0,0,100,0),
(@PATH,2,-557.4218,2005.291,99.07405,0,0,0,0,100,0),
(@PATH,3,-559.7542,2056.054,96.38632,0,0,0,0,100,0),
(@PATH,4,-540.9093,2062.701,104.2178,0,0,0,0,100,0),
(@PATH,5,-538.0739,2083.637,102.7935,0,0,0,0,100,0),
(@PATH,6,-531.9629,2100.469,104.145,0,0,0,0,100,0),
(@PATH,7,-540.8042,2121.509,97.44407,0,0,0,0,100,0),
(@PATH,8,-542.6715,2139.263,94.42299,0,0,0,0,100,0),
(@PATH,9,-542.0955,2125.005,96.38588,0,0,0,0,100,0),
(@PATH,10,-531.0101,2105.611,103.8495,0,0,0,0,100,0),
(@PATH,11,-533.4691,2097.096,103.5421,0,0,0,0,100,0),
(@PATH,12,-539.8324,2066.038,103.8721,0,0,0,0,100,0),
(@PATH,13,-559.5454,2057.871,96.58672,0,0,0,0,100,0),
(@PATH,14,-557.4636,2005.37,98.92694,0,0,0,0,100,0);
-- 0x1C09E4424012FA8000002D00001EC994 .go -558.5822 2003.227 98.30606

-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69504;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-506.4011,`position_y`=1982.52,`position_z`=85.11931 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-506.4011,1982.52,85.11931,0,0,0,0,100,0),
(@PATH,2,-491.8763,2002.533,90.20009,0,0,0,0,100,0),
(@PATH,3,-475.5587,2034.282,93.52704,0,0,0,0,100,0),
(@PATH,4,-459.14,2057.011,93.19531,0,0,0,0,100,0),
(@PATH,5,-488.9269,2006.812,90.64146,0,0,0,0,100,0),
(@PATH,6,-506.4684,1982.384,85.10349,0,0,0,0,100,0),
(@PATH,7,-459.1624,2056.984,93.22046,0,0,0,0,100,0),
(@PATH,8,-453.0856,2078.318,92.4622,0,0,0,0,100,0),
(@PATH,9,-458.4782,2105.915,91.30417,0,0,0,0,100,0),
(@PATH,10,-453.1829,2091.579,91.92897,0,0,0,0,100,0),
(@PATH,11,-454.6579,2067.877,92.86068,0,0,0,0,100,0),
(@PATH,12,-471.7339,2040.147,93.86339,0,0,0,0,100,0),
(@PATH,13,-488.8954,2006.772,90.6447,0,0,0,0,100,0),
(@PATH,14,-506.3882,1982.291,85.0636,0,0,0,0,100,0);
-- 0x1C09E4424012FA8000002D00001EC026 .go -506.4011 1982.52 85.11931
-- Pathing for Bleeding Hollow Tormentor Entry: 19424 'TDB FORMAT' 
SET @NPC := 69477;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-975.6777,`position_y`=1903.692,`position_z`=84.41418 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,9562,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-975.6777,1903.692,84.41418,0,0,0,0,100,0),
(@PATH,2,-973.8419,1939.495,70.39467,0,0,0,0,100,0),
(@PATH,3,-955.7029,1969.015,68.00587,0,0,0,0,100,0),
(@PATH,4,-933.9344,1986.529,66.71876,0,0,0,0,100,0),
(@PATH,5,-920.0254,2004.145,64.96164,0,0,0,0,100,0),
(@PATH,6,-912.637,2028.022,56.54257,0,0,0,0,100,0),
(@PATH,7,-891.1589,2064.74,34.64294,0,0,0,0,100,0),
(@PATH,8,-869.7386,2091.601,23.5704,0,0,0,0,100,0),
(@PATH,9,-858.7391,2124.865,17.03608,0,0,0,0,100,0),
(@PATH,10,-823.7175,2119.571,16.5663,0,0,0,0,100,0),
(@PATH,11,-792.2368,2090.261,22.4062,0,0,0,0,100,0),
(@PATH,12,-783.2084,2054.525,29.63973,0,0,0,0,100,0),
(@PATH,13,-779.9326,2023.77,34.75321,0,0,0,0,100,0),
(@PATH,14,-800.3509,1985.585,39.80645,0,0,0,0,100,0),
(@PATH,15,-814.7488,1949.572,47.55807,0,0,0,0,100,0),
(@PATH,16,-822.0464,1919.74,54.06172,0,0,0,0,100,0),
(@PATH,17,-847.4603,1891.778,64.08673,0,0,0,0,100,0),
(@PATH,18,-885.2077,1883.808,72.72009,0,0,0,0,100,0),
(@PATH,19,-915.132,1902.349,70.37255,0,0,0,0,100,0),
(@PATH,20,-940.0393,1898.689,74.6819,0,0,0,0,100,0),
(@PATH,21,-958.8931,1878.34,92.07265,0,0,0,0,100,0),
(@PATH,22,-967.469,1873.979,94.75582,0,0,0,0,100,0),
(@PATH,23,-976.3881,1877.903,94.82088,0,0,0,0,100,0);
-- 0xF1304BE000608B4F .go -975.6777 1903.692 84.41418

-- Pathing for Bleeding Hollow Tormentor Entry: 19424 'TDB FORMAT' 
SET @NPC := 69471;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1157.17,`position_y`=1943.396,`position_z`=81.40363 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1157.17,1943.396,81.40363,0,0,0,0,100,0),
(@PATH,2,-1151.672,1940.954,81.40428,0,0,0,0,100,0),
(@PATH,3,-1143.042,1932.632,81.42173,0,0,0,0,100,0),
(@PATH,4,-1139.161,1923.026,81.20094,0,0,0,0,100,0),
(@PATH,5,-1138.57,1918.28,81.37885,0,0,0,0,100,0),
(@PATH,6,-1135.403,1912.328,81.4029,0,0,0,0,100,0),
(@PATH,7,-1138.515,1901.65,81.35353,0,0,0,0,100,0),
(@PATH,8,-1145.631,1891.622,81.32314,0,0,0,0,100,0),
(@PATH,9,-1139.867,1899.911,81.37244,0,0,0,0,100,0),
(@PATH,10,-1155.281,1909.135,81.45526,0,0,0,0,100,0),
(@PATH,11,-1139.867,1899.911,81.37244,0,0,0,0,100,0),
(@PATH,12,-1145.631,1891.622,81.32314,0,0,0,0,100,0),
(@PATH,13,-1138.515,1901.65,81.35353,0,0,0,0,100,0),
(@PATH,14,-1135.493,1912.019,81.39507,0,0,0,0,100,0),
(@PATH,15,-1138.57,1918.28,81.37885,0,0,0,0,100,0),
(@PATH,16,-1139.161,1923.026,81.20094,0,0,0,0,100,0),
(@PATH,17,-1142.842,1932.44,81.40112,0,0,0,0,100,0),
(@PATH,18,-1151.672,1940.954,81.40428,0,0,0,0,100,0);
-- 0xF1304BE00060877C .go -1157.17 1943.396 81.40363

-- Pathing for Bleeding Hollow Tormentor Entry: 19424 'TDB FORMAT' 
SET @NPC := 69476;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1033.498,`position_y`=2016.301,`position_z`=67.98228 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,9562,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1033.498,2016.301,67.98228,0,0,0,0,100,0),
(@PATH,2,-1000.079,2017.703,67.06455,0,0,0,0,100,0),
(@PATH,3,-954.4206,2015.588,67.03322,0,0,0,0,100,0),
(@PATH,4,-915.6917,2025.381,58.45187,0,0,0,0,100,0),
(@PATH,5,-886.038,2057.447,35.91393,0,0,0,0,100,0),
(@PATH,6,-886.0889,2092.425,24.59444,0,0,0,0,100,0),
(@PATH,7,-915.6437,2115.709,20.89748,0,0,0,0,100,0),
(@PATH,8,-914.2065,2149.265,14.4707,0,0,0,0,100,0),
(@PATH,9,-922.1042,2170.104,12.60829,0,0,0,0,100,0),
(@PATH,10,-945.8377,2185.868,12.26309,0,0,0,0,100,0),
(@PATH,11,-961.3444,2217.514,9.387299,0,0,0,0,100,0),
(@PATH,12,-957.1495,2247.785,6.748508,0,0,0,0,100,0),
(@PATH,13,-984.4343,2282.687,6.486638,0,0,0,0,100,0),
(@PATH,14,-1016.313,2306.371,8.956036,0,0,0,0,100,0),
(@PATH,15,-1048.225,2313.089,14.2006,0,0,0,0,100,0),
(@PATH,16,-1081.711,2312.186,20.69922,0,0,0,0,100,0),
(@PATH,17,-1087.714,2285.604,24.63902,0,0,0,0,100,0),
(@PATH,18,-1067.954,2244.344,24.47042,0,0,0,0,100,0),
(@PATH,19,-1052.511,2214.931,19.66574,0,0,0,0,100,0),
(@PATH,20,-1051.316,2178.967,24.62208,0,0,0,0,100,0),
(@PATH,21,-1055.739,2145.756,39.92072,0,0,0,0,100,0),
(@PATH,22,-1057.033,2106.794,57.37517,0,0,0,0,100,0),
(@PATH,23,-1046.553,2082.452,64.01545,0,0,0,0,100,0),
(@PATH,24,-1029.464,2056.926,67.17399,0,0,0,0,100,0),
(@PATH,25,-1056.46,2029.947,67.56455,0,0,0,0,100,0),
(@PATH,26,-1084.9,1998.348,67.47117,0,0,0,0,100,0),
(@PATH,27,-1065.154,1984.061,69.4269,0,0,0,0,100,0),
(@PATH,28,-1084.9,1998.348,67.47117,0,0,0,0,100,0),
(@PATH,29,-1056.46,2029.947,67.56455,0,0,0,0,100,0),
(@PATH,30,-1029.464,2056.926,67.17399,0,0,0,0,100,0),
(@PATH,31,-1046.553,2082.452,64.01545,0,0,0,0,100,0),
(@PATH,32,-1057.033,2106.794,57.37517,0,0,0,0,100,0),
(@PATH,33,-1055.739,2145.756,39.92072,0,0,0,0,100,0),
(@PATH,34,-1051.316,2178.967,24.62208,0,0,0,0,100,0),
(@PATH,35,-1052.511,2214.931,19.66574,0,0,0,0,100,0),
(@PATH,36,-1067.954,2244.344,24.47042,0,0,0,0,100,0),
(@PATH,37,-1087.714,2285.604,24.63902,0,0,0,0,100,0),
(@PATH,38,-1081.711,2312.186,20.69922,0,0,0,0,100,0),
(@PATH,39,-1048.225,2313.089,14.2006,0,0,0,0,100,0),
(@PATH,40,-1016.313,2306.371,8.956036,0,0,0,0,100,0),
(@PATH,41,-984.4343,2282.687,6.486638,0,0,0,0,100,0),
(@PATH,42,-957.1495,2247.785,6.748508,0,0,0,0,100,0),
(@PATH,43,-961.3444,2217.514,9.387299,0,0,0,0,100,0),
(@PATH,44,-945.8377,2185.868,12.26309,0,0,0,0,100,0),
(@PATH,45,-922.1042,2170.104,12.60829,0,0,0,0,100,0),
(@PATH,46,-914.2065,2149.265,14.4707,0,0,0,0,100,0),
(@PATH,47,-915.6437,2115.709,20.89748,0,0,0,0,100,0),
(@PATH,48,-886.0889,2092.425,24.59444,0,0,0,0,100,0),
(@PATH,49,-886.038,2057.447,35.91393,0,0,0,0,100,0),
(@PATH,50,-915.6917,2025.381,58.45187,0,0,0,0,100,0),
(@PATH,51,-954.4206,2015.588,67.03322,0,0,0,0,100,0),
(@PATH,52,-1000.079,2017.703,67.06455,0,0,0,0,100,0),
(@PATH,53,-1033.498,2016.301,67.98228,0,0,0,0,100,0);
-- 0xF1304BE00060AF73 .go -1033.498 2016.301 67.98228

-- Pathing for Bleeding Hollow Tormentor Entry: 19424 'TDB FORMAT' 
SET @NPC := 69479;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-887.3162,`position_y`=2100.392,`position_z`=22.98137 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,9562,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-887.3162,2100.392,22.98137,0,0,0,0,100,0),
(@PATH,2,-902.8832,2104.852,22.5635,0,0,0,0,100,0),
(@PATH,3,-915.3331,2120.114,20.053,0,0,0,0,100,0),
(@PATH,4,-914.8217,2141.304,15.65685,0,0,0,0,100,0),
(@PATH,5,-920.6898,2180.254,11.73329,0,0,0,0,100,0),
(@PATH,6,-928.6917,2208.044,9.395775,0,0,0,0,100,0),
(@PATH,7,-935.8201,2223.378,8.009735,0,0,0,0,100,0),
(@PATH,8,-957.2545,2229.223,7.933442,0,0,0,0,100,0),
(@PATH,9,-962.3887,2210.646,10.17673,0,0,0,0,100,0),
(@PATH,10,-949.9908,2203.8,9.920502,0,0,0,0,100,0),
(@PATH,11,-929.2674,2205.433,9.8395,0,0,0,0,100,0),
(@PATH,12,-897.6884,2189.902,10.51884,0,0,0,0,100,0),
(@PATH,13,-862.864,2165.974,11.53246,0,0,0,0,100,0),
(@PATH,14,-840.7776,2152.851,13.35741,0,0,0,0,100,0),
(@PATH,15,-837.7058,2133.558,15.67247,0,0,0,0,100,0),
(@PATH,16,-852.1836,2118.362,17.45734,0,0,0,0,100,0),
(@PATH,17,-871.5316,2098.868,21.64986,0,0,0,0,100,0);
-- 0xF1304BE0006135E2 .go -887.3162 2100.392 22.98137

-- Pathing for Bleeding Hollow Tormentor Entry: 19424 'TDB FORMAT' 
SET @NPC := 69481;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1072.546,`position_y`=2254.384,`position_z`=25.03121 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,9562,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1072.546,2254.384,25.03121,0,0,0,0,100,0),
(@PATH,2,-1050.309,2248.466,22.70865,0,0,0,0,100,0),
(@PATH,3,-1016.866,2228.801,13.34218,0,0,0,0,100,0),
(@PATH,4,-975.5443,2209.247,10.59319,0,0,0,0,100,0),
(@PATH,5,-950.7357,2192.689,11.50015,0,0,0,0,100,0),
(@PATH,6,-915.4313,2157.962,13.552,0,0,0,0,100,0),
(@PATH,7,-912.6307,2132.925,17.52908,0,0,0,0,100,0),
(@PATH,8,-912.6307,2132.925,17.52908,0,0,0,0,100,0),
(@PATH,9,-915.4313,2157.962,13.552,0,0,0,0,100,0),
(@PATH,10,-950.7357,2192.689,11.50015,0,0,0,0,100,0),
(@PATH,11,-975.5443,2209.247,10.59319,0,0,0,0,100,0),
(@PATH,12,-1016.866,2228.801,13.34218,0,0,0,0,100,0),
(@PATH,13,-1050.309,2248.466,22.70865,0,0,0,0,100,0),
(@PATH,14,-1072.546,2254.384,25.03121,0,0,0,0,100,0);
-- 0xF1304BE00061378F .go -1072.546 2254.384 25.03121

-- Pathing for Bleeding Hollow Tormentor Entry: 19424 'TDB FORMAT' 
SET @NPC := 69480;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1000.677,`position_y`=2218.161,`position_z`=11.39956 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,9562,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1000.677,2218.161,11.39956,0,0,0,0,100,0),
(@PATH,2,-1034.118,2233.885,16.91886,0,0,0,0,100,0),
(@PATH,3,-1000.677,2218.161,11.39956,0,0,0,0,100,0),
(@PATH,4,-960.3612,2199.009,11.10769,0,0,0,0,100,0),
(@PATH,5,-929.8221,2168.747,12.79615,0,0,0,0,100,0),
(@PATH,6,-917.9709,2134.846,17.4569,0,0,0,0,100,0),
(@PATH,7,-899.0653,2097.202,24.10116,0,0,0,0,100,0),
(@PATH,8,-867.7588,2092.518,23.16903,0,0,0,0,100,0),
(@PATH,9,-834.6699,2065.056,28.35329,0,0,0,0,100,0),
(@PATH,10,-834.6699,2065.056,28.35329,0,0,0,0,100,0),
(@PATH,11,-867.7588,2092.518,23.16903,0,0,0,0,100,0),
(@PATH,12,-899.0653,2097.202,24.10116,0,0,0,0,100,0),
(@PATH,13,-917.9709,2134.846,17.4569,0,0,0,0,100,0),
(@PATH,14,-929.8221,2168.747,12.79615,0,0,0,0,100,0),
(@PATH,15,-960.3612,2199.009,11.10769,0,0,0,0,100,0),
(@PATH,16,-1000.677,2218.161,11.39956,0,0,0,0,100,0),
(@PATH,17,-1034.118,2233.885,16.91886,0,0,0,0,100,0),
(@PATH,18,-1000.677,2218.161,11.39956,0,0,0,0,100,0);
-- 0xF1304BE000613CEA .go -1000.677 2218.161 11.39956

-- Pathing for Bleeding Hollow Tormentor Entry: 19424 'TDB FORMAT' 
SET @NPC := 69474;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1141.451,`position_y`=2039.274,`position_z`=67.06458 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1141.451,2039.274,67.06458,0,0,0,0,100,0),
(@PATH,2,-1098.165,2044.068,66.97787,0,0,0,0,100,0),
(@PATH,3,-1053.092,2025.227,67.56455,0,0,0,0,100,0),
(@PATH,4,-1011.46,2004.103,67.06455,0,0,0,0,100,0),
(@PATH,5,-983.9862,1982.55,68.81455,0,0,0,0,100,0),
(@PATH,6,-984.9029,1950.981,70.32558,0,0,0,0,100,0),
(@PATH,7,-974.4434,1917.587,77.03918,0,0,0,0,100,0),
(@PATH,8,-951.4631,1888.722,82.49074,0,0,0,0,100,0),
(@PATH,9,-918.9573,1886.185,78.15961,0,0,0,0,100,0),
(@PATH,10,-918.9573,1886.185,78.15961,0,0,0,0,100,0),
(@PATH,11,-951.4631,1888.722,82.49074,0,0,0,0,100,0),
(@PATH,12,-974.4434,1917.587,77.03918,0,0,0,0,100,0),
(@PATH,13,-984.9029,1950.981,70.32558,0,0,0,0,100,0),
(@PATH,14,-983.9862,1982.55,68.81455,0,0,0,0,100,0),
(@PATH,15,-1011.46,2004.103,67.06455,0,0,0,0,100,0),
(@PATH,16,-1053.092,2025.227,67.56455,0,0,0,0,100,0),
(@PATH,17,-1098.165,2044.068,66.97787,0,0,0,0,100,0),
(@PATH,18,-1141.451,2039.274,67.06458,0,0,0,0,100,0);
-- 0xF1304BE00061420D .go -1141.451 2039.274 67.06458

-- Pathing for Bleeding Hollow Tormentor Entry: 19424 'TDB FORMAT' 
SET @NPC := 69478;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-824.4816,`position_y`=1990.778,`position_z`=38.91302 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,9562,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-824.4816,1990.778,38.91302,0,0,0,0,100,0),
(@PATH,2,-800.973,2019.102,38.81275,0,0,0,0,100,0),
(@PATH,3,-801.4883,2043.102,41.42069,0,0,0,0,100,0),
(@PATH,4,-820.149,2057.47,35.70707,0,0,0,0,100,0),
(@PATH,5,-830.2311,2072.128,25.74135,0,0,0,0,100,0),
(@PATH,6,-842.6055,2101.628,19.20734,0,0,0,0,100,0),
(@PATH,7,-854.4006,2133.824,15.76549,0,0,0,0,100,0),
(@PATH,8,-854.3831,2150.491,13.76549,0,0,0,0,100,0),
(@PATH,9,-871.9949,2163.9,11.56941,0,0,0,0,100,0),
(@PATH,10,-900.2237,2167.077,11.69764,0,0,0,0,100,0),
(@PATH,11,-900.2237,2167.077,11.69764,0,0,0,0,100,0),
(@PATH,12,-871.9949,2163.9,11.56941,0,0,0,0,100,0),
(@PATH,13,-854.3831,2150.491,13.76549,0,0,0,0,100,0),
(@PATH,14,-854.4006,2133.824,15.76549,0,0,0,0,100,0),
(@PATH,15,-842.6055,2101.628,19.20734,0,0,0,0,100,0),
(@PATH,16,-830.2311,2072.128,25.74135,0,0,0,0,100,0),
(@PATH,17,-820.149,2057.47,35.70707,0,0,0,0,100,0),
(@PATH,18,-801.4883,2043.102,41.42069,0,0,0,0,100,0),
(@PATH,19,-800.973,2019.102,38.81275,0,0,0,0,100,0),
(@PATH,20,-824.4816,1990.778,38.91302,0,0,0,0,100,0);
-- 0xF1304BE0006192D2 .go -824.4816 1990.778 38.91302

-- Pathing for Worg Master Kruush Entry: 19442 'TDB FORMAT' 
SET @NPC := 69634;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1057.877,`position_y`=1996.641,`position_z`=67.34181 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1057.877,1996.641,67.34181,0,0,0,0,100,0),
(@PATH,2,-1050.188,2009.977,67.06455,0,0,0,0,100,0);
-- 0xF1304BF20060E90B .go -1057.877 1996.641 67.34181
--
UPDATE `smart_scripts` SET `action_param2` = 0 WHERE `entryorguid`=37007 AND `id`=1;
DELETE FROM `creature_formations` WHERE `leaderGUID`=38429;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(38429, 38429, 0, 0, 2),
(38429, 38430, 3, 270, 2);

-- Pathing for Mattie Alred Entry: 5668 'TDB FORMAT'
SET @NPC := 38429;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1717.818,`position_y`=303.1138,`position_z`=-61.47988 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1717.818,303.1138,-61.47988,0,0,0,0,100,0),
(@PATH,2,1724.056,285.5189,-62.18394,0,0,0,0,100,0),
(@PATH,3,1725.809,279.2398,-62.18219,0,0,0,0,100,0),
(@PATH,4,1728.313,268.6199,-62.17767,0,0,0,0,100,0),
(@PATH,5,1730.295,250.8002,-62.17767,0,0,0,0,100,0),
(@PATH,6,1716.658,240.3017,-62.17767,0,0,0,0,100,0),
(@PATH,7,1692.596,241.7838,-62.17767,0,0,0,0,100,0),
(@PATH,8,1672.504,242.9413,-62.17767,0,0,0,0,100,0),
(@PATH,9,1665.619,249.5088,-62.1778,0,0,0,0,100,0),
(@PATH,10,1663.849,264.2947,-62.17823,0,0,0,0,100,0),
(@PATH,11,1659.715,273.889,-62.17942,0,0,0,0,100,0),
(@PATH,12,1652.447,286.605,-62.18125,0,0,0,0,100,0),
(@PATH,13,1637.696,299.425,-62.17578,0,0,0,0,100,0),
(@PATH,14,1621.363,308.3512,-62.17768,0,0,0,0,100,0),
(@PATH,15,1605.388,311.2079,-62.17768,0,0,0,0,100,0),
(@PATH,16,1598.25,318.9116,-62.17767,0,0,0,0,100,0),
(@PATH,17,1598.482,334.9213,-62.17767,0,0,0,0,100,0),
(@PATH,18,1599.09,358.2072,-62.17767,0,0,0,0,100,0),
(@PATH,19,1598.418,367.1544,-62.22174,0,0,0,0,100,0),
(@PATH,20,1610.374,374.7628,-62.17767,0,0,0,0,100,0),
(@PATH,21,1627.031,371.8268,-62.17767,0,0,0,0,100,0),
(@PATH,22,1637.79,368.5305,-62.16847,0,0,0,0,100,0),
(@PATH,23,1655.578,358.9601,-60.74146,0,0,0,0,100,0),
(@PATH,24,1657.84,352.9977,-60.72892,0,0,0,0,100,0),
(@PATH,25,1654.79,342.4309,-62.17167,0,0,0,0,100,0),
(@PATH,26,1668.162,325.3488,-62.15568,0,0,0,0,100,0),
(@PATH,27,1680.751,314.6597,-62.15656,0,0,0,0,100,0),
(@PATH,28,1694.482,302.0437,-62.16363,0,0,0,0,100,0);
-- 0xF13016240000906A .go 1717.818 303.1138 -61.47988
--
SET @GUID  := 75088;
DELETE FROM `creature` WHERE id IN (33630,33639,33642,33645);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@GUID+0, 33630, 530, 0, 0, 1, 1, 0, 1, -2091.979, 5634.983, 50.31123, 2.844887, 300, 0, 0, 2266, 6015, 0, 0, 0, 0, 0),
(@GUID+1, 33639, 530, 0, 0, 1, 1, 0, 1, -2093.764, 5632.878, 50.31123, 2.513274, 300, 0, 0, 3237, 0, 0, 0, 0, 0, 0),
(@GUID+2, 33642, 530, 0, 0, 1, 1, 0, 1, -2254.972, 5560.913, 67.10059, 5.951573, 300, 0, 0, 2835, 7196, 0, 0, 0, 0, 0),
(@GUID+3, 33645, 571, 0, 0, 1, 1, 0, 1, 8579.87, 749.8559, 547.376, 6.08289, 300, 0, 0, 10635, 0, 0, 0, 0, 0, 0);
--
SET @CGUID := 75092;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 29854, 571, 1, 1, 6712.09, -533.401, 1211.94, 1.69635, 0, 0, 0),
(@CGUID+1, 29854, 571, 1, 1, 6695.85, -487.759, 1195.42, 1.80238, 0, 0, 0),
(@CGUID+2, 29854, 571, 1, 1, 6675.19, -420.657, 1184.11, 3.36925, 0, 15, 1),
(@CGUID+3, 29854, 571, 1, 1, 6647.07, -477.868, 1167.51, 2.68202, 0, 0, 0),
(@CGUID+4, 29854, 571, 1, 1, 6706.95, -521.231, 1211.49, 5.17959, 0, 0, 0),
(@CGUID+5, 29854, 571, 1, 1, 6697.77, -462.455, 1178.17, 5.77257, 0, 0, 0),
(@CGUID+6, 29854, 571, 1, 1, 6671.19, -467.731, 1178.39, 6.27915, 0, 0, 0);

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (29854, 30013);

DELETE FROM `creature` WHERE `guid` IN (99014, 99015, 99017, 99172, 121713, 121358); -- vehicle accessory and wrong spawn

DELETE FROM `vehicle_template_accessory` WHERE `entry`= 30013;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(30013,29730,0,1,'Stormcrest Eagle',5,0);

UPDATE `creature` SET movementType=2 WHERE `guid` IN (101713, 101714, 101715, 101801);

DELETE FROM `creature_addon` WHERE `guid` IN (101713, 101714, 101715, 101801);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`,`auras`) VALUES
(101713, 1017130, 0, 0, 1, 0, ''),
(101714, 1017140, 0, 0, 1, 0, ''),
(101715, 1017150, 0, 0, 1, 0, ''),
(101801, 1018010, 0, 0, 1, 0, '');

DELETE FROM `waypoint_data` WHERE `id` IN (1017130, 1017140, 1017150, 1018010);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(1017130, 1, 6580.963, -341.5958, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 2, 6595.587, -274.2542, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 3, 6603.651, -214.6846, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 4, 6598.268, -139.6636, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 5, 6583.247, -70.26400, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 6, 6517.861, -27.37788, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 7, 6334.042, -80.26796, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 8, 6302.791, -214.7384, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 9, 6306.531, -372.1047, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 10, 6347.108, -523.2972, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 11, 6469.087, -575.7284, 1025.59, 0, 0, 1, 0, 100, 0),
(1017130, 12, 6543.881, -476.6713, 1025.59, 0, 0, 1, 0, 100, 0),
(1017140, 1, 6558.544, -152.0257, 1054.933, 0, 0, 1, 0, 100, 0),
(1017140, 2, 6609.241, -127.7897, 1055.322, 0, 0, 1, 0, 100, 0),
(1017140, 3, 6701.458, -107.1807, 1059.877, 0, 0, 1, 0, 100, 0),
(1017140, 4, 6774.843, -197.2011, 1078.129, 0, 0, 1, 0, 100, 0),
(1017140, 5, 6777.308, -292.3615, 1095.376, 0, 0, 1, 0, 100, 0),
(1017140, 6, 6703.971, -329.4862, 1100.933, 0, 0, 1, 0, 100, 0),
(1017140, 7, 6606.578, -326.3456, 1091.265, 0, 0, 1, 0, 100, 0),
(1017140, 8, 6552.779, -289.719, 1077.712, 0, 0, 1, 0, 100, 0),
(1017140, 9, 6536.85, -189.0296, 1059.237, 0, 0, 1, 0, 100, 0),
(1017150, 1, 6630.098, -152.5961, 999.0965, 0, 0, 1, 0, 100, 0),
(1017150, 2, 6663.148, -136.3936, 999.0965, 0, 0, 1, 0, 100, 0),
(1017150, 3, 6705.553, -94.23096, 999.0965, 0, 0, 1, 0, 100, 0),
(1017150, 4, 6728.896, 43.04465, 999.0965, 0, 0, 1, 0, 100, 0),
(1017150, 5, 6628.838, 175.6433, 999.0965, 0, 0, 1, 0, 100, 0),
(1017150, 6, 6520.246, 148.9764, 999.0965, 0, 0, 1, 0, 100, 0),
(1017150, 7, 6386.172, -22.66618, 999.0965, 0, 0, 1, 0, 100, 0),
(1017150, 8, 6253.463, -195.8139, 999.0965, 0, 0, 1, 0, 100, 0),
(1017150, 9, 6330.91, -276.6109, 999.0965, 0, 0, 1, 0, 100, 0),
(1017150, 10, 6537.496, -198.9901, 999.0965, 0, 0, 1, 0, 100, 0),
(1018010, 1, 6725.225586, -25.534340, 999.721313, 0, 0, 1, 0, 100, 0),
(1018010, 2, 6638.638184, -52.154530, 991.158203, 0, 0, 1, 0, 100, 0),
(1018010, 3, 6567.925293, -153.043152, 1001.600220, 0, 0, 1, 0, 100, 0),
(1018010, 4, 6591.385742, -224.502579, 1003.976013, 0, 0, 1, 0, 100, 0),
(1018010, 5, 6695.518555, -252.929214, 1022.529175, 0, 0, 1, 0, 100, 0),
(1018010, 6, 6802.429199, -243.025558, 1022.408691, 0, 0, 1, 0, 100, 0),
(1018010, 7, 6798.217285, -161.789276, 1046.530518, 0, 0, 1, 0, 100, 0);
-- The Brewmaiden SAI
SET @ENTRY := 36021;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,101,0,0,0,11,48249,1,0,0,0,0,7,0,0,0,0,0,0,0,"The Brewmaiden - Received Emote 101 - Cast 'Brewfest Brew Toss'"),
(@ENTRY,0,1,2,54,0,100,0,0,0,0,0,75,68269,0,0,0,0,0,23,0,0,0,0,0,0,0,"The Brewmaiden - On Just Summoned - Add Aura 'The Brewmaiden's Blessing'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"The Brewmaiden - On Just Summoned - Run Script");
-- Actionlist SAI
SET @ENTRY := 3602100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,34000,34000,0,0,28,68269,0,0,0,0,0,23,0,0,0,0,0,0,0,"On Script - Remove Aura 'The Brewmaiden's Blessing'");
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE  `Id` IN(10995,10996,10997);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=10983 WHERE  `Id` IN(10983,10989);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN(10995,10996,10997);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 10995, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Grulloc Has Two Skulls after Mog dorg the Wizened'),
(20, 0, 10995, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Grulloc Has Two Skulls after Mog dorg the Wizened'),
(19, 0, 10995, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Grulloc Has Two Skulls after Mog dorg the Wizened'),
(20, 0, 10995, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Grulloc Has Two Skulls after Mog dorg the Wizened'),
(19, 0, 10996, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Maggocs Treasure Chest after Mog dorg the Wizened'),
(20, 0, 10996, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Maggocs Treasure Chest after Mog dorg the Wizened'),
(19, 0, 10996, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Maggocs Treasure Chest after Mog dorg the Wizened'),
(20, 0, 10996, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Maggocs Treasure Chest after Mog dorg the Wizened'),
(19, 0, 10997, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Even Gronn Have Standards after Mog dorg the Wizened'),
(20, 0, 10997, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Even Gronn Have Standards after Mog dorg the Wizened'),
(19, 0, 10997, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Even Gronn Have Standards after Mog dorg the Wizened'),
(20, 0, 10997, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Even Gronn Have Standards after Mog dorg the Wizened');
-- Wrong npc spawned, should be a Stormwind Infantry npc
UPDATE `creature` SET `id`=16864 WHERE `guid`=57934;

-- Pathing for Stormwind Infantry Entry: 16864 'TDB FORMAT' 
SET @NPC := 57934;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-702.9703,`position_y`=1826.119,`position_z`=75.24933 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-702.9703,1826.119,75.24933,0,0,0,0,100,0),
(@PATH,2,-707.4134,1826.754,75.24933,0,0,0,0,100,0);
-- 0x1C09E4424010780000002B00009A4063 .go -702.9703 1826.119 75.24933

DELETE FROM `creature_formations` WHERE `leaderGUID`=57965;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(57965, 57965, 0, 0, 2),
(57965, 57966, 5, 0, 2),
(57965, 57967, 10, 0, 2),
(57965, 57968, 15, 0, 2);

-- SAI Set Run On is bugged, if fixed this will work.
-- Honor Hold Cavalryman SAI
SET @ENTRY := 16843;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Honor Hold Cavalryman - On Respawn - Set Run On");

-- Pathing for Honor Hold Cavalryman Entry: 16843 'TDB FORMAT' 
SET @NPC := 57965;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-693.6425,`position_y`=2675.357,`position_z`=93.08069 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,2410,0,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-693.6425,2675.357,93.08069,0,0,0,0,100,0),
(@PATH,2,-678.617,2653.904,90.11584,0,0,0,0,100,0),
(@PATH,3,-670.0779,2623.337,87.22372,0,0,0,0,100,0),
(@PATH,4,-647.809,2588.676,83.14737,0,0,0,0,100,0),
(@PATH,5,-620.405,2546.836,73.68471,0,0,0,0,100,0),
(@PATH,6,-604.7114,2503.37,64.40894,0,0,0,0,100,0),
(@PATH,7,-603.8063,2468.986,57.10122,0,0,0,0,100,0),
(@PATH,8,-604.4416,2435.113,50.43313,0,0,0,0,100,0),
(@PATH,9,-599.5267,2409.476,44.74646,0,0,0,0,100,0),
(@PATH,10,-584.7905,2406.665,43.70581,0,0,0,0,100,0),
(@PATH,11,-582.3721,2430.458,47.94434,0,0,0,0,100,0),
(@PATH,12,-582.2322,2463.321,53.99577,0,0,0,0,100,0),
(@PATH,13,-583.6086,2498.498,61.39573,0,0,0,0,100,0),
(@PATH,14,-558.1572,2532.4,67.07269,0,0,0,0,100,0),
(@PATH,15,-524.5069,2553.839,65.79486,0,0,0,0,100,0),
(@PATH,16,-505.5841,2594.287,68.31036,0,0,0,0,100,0),
(@PATH,17,-504.4444,2604.637,70.43836,0,0,0,0,100,0),
(@PATH,18,-510.0499,2664.531,70.29152,0,0,0,0,100,0),
(@PATH,19,-511.0184,2694.743,68.82625,0,0,0,0,100,0),
(@PATH,20,-517.2742,2716.729,67.8214,0,0,0,0,100,0),
(@PATH,21,-534.5939,2747.733,69.1256,0,0,0,0,100,0),
(@PATH,22,-565.1152,2807.142,63.14902,0,0,0,0,100,0),
(@PATH,23,-596.1111,2836.904,59.59448,0,0,0,0,100,0),
(@PATH,24,-630.4422,2866.988,51.1272,0,0,0,0,100,0),
(@PATH,25,-678.3279,2883.457,47.06744,0,0,0,0,100,0),
(@PATH,26,-723.3876,2887.968,33.10106,0,0,0,0,100,0),
(@PATH,27,-762.0458,2886.646,24.27474,0,0,0,0,100,0),
(@PATH,28,-792.7939,2863.772,21.49371,0,0,0,0,100,0),
(@PATH,29,-819.7803,2843.219,19.12334,0,0,0,0,100,0),
(@PATH,30,-873.9691,2815.151,15.98937,0,0,0,0,100,0),
(@PATH,31,-893.9761,2802.479,14.45792,0,0,0,0,100,0),
(@PATH,32,-897.1367,2771.076,20.99353,0,0,0,0,100,0),
(@PATH,33,-867.2095,2775.483,38.31301,0,0,0,0,100,0),
(@PATH,34,-860.2045,2761.954,45.71127,0,0,0,0,100,0),
(@PATH,35,-868.9539,2736.927,57.97308,0,0,0,0,100,0),
(@PATH,36,-871.5066,2701.324,78.20714,0,0,0,0,100,0),
(@PATH,37,-856.217,2675.711,92.33214,0,0,0,0,100,0),
(@PATH,38,-833.6348,2676.617,98.47594,0,0,0,0,100,0),
(@PATH,39,-808.0863,2687.279,104.1725,0,0,0,0,100,0),
(@PATH,40,-790.8087,2689.64,104.0867,0,0,0,0,100,0),
(@PATH,41,-724.9875,2676.18,96.8718,0,0,0,0,100,0);
-- 0x1C09E442401072C000002000004EA00B .go -693.6425 2675.357 93.08069

DELETE FROM `creature_formations` WHERE `leaderGUID`=57937;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(57937, 57937, 0, 0, 2),
(57937, 57923, 3, 90, 2);

-- Pathing for Honor Hold Defender Entry: 16842 'TDB FORMAT' 
SET @NPC := 57937;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-872.1663,`position_y`=2769.454,`position_z`=37.44319 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-872.1663,2769.454,37.44319,0,0,0,0,100,0),
(@PATH,2,-869.7395,2768.148,39.13062,0,0,0,0,100,0),
(@PATH,3,-865.2796,2739.821,56.70609,0,0,0,0,100,0),
(@PATH,4,-867.5071,2718.566,68.9836,0,0,0,0,100,0),
(@PATH,5,-867.6776,2699.037,79.59444,0,0,0,0,100,0),
(@PATH,6,-857.8785,2686.67,88.437,0,0,0,0,100,0),
(@PATH,7,-842.5071,2678.96,95.25343,0,0,0,0,100,0),
(@PATH,8,-822.5238,2681.506,102.4034,0,0,0,0,100,0),
(@PATH,9,-817.7297,2683.09,103.48,0,0,0,0,100,0),
(@PATH,10,-817.5452,2683.404,103.4257,0,0,0,0,100,0),
(@PATH,11,-838.7125,2678.288,96.64885,0,0,0,0,100,0),
(@PATH,12,-856.334,2685.094,89.30038,0,0,0,0,100,0),
(@PATH,13,-866.9412,2697.539,80.50797,0,0,0,0,100,0),
(@PATH,14,-867.8522,2713.977,71.4567,0,0,0,0,100,0),
(@PATH,15,-865.3911,2736.797,58.61076,0,0,0,0,100,0),
(@PATH,16,-866.6399,2765.021,41.61932,0,0,0,0,100,0);
-- 0x1C09E4424010728000002D00001E733B .go -872.1663 2769.454 37.44319

-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58441;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-794.1317,`position_y`=2601.671,`position_z`=133.2523 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-794.1317,2601.671,133.2523,0,0,0,0,100,0),
(@PATH,2,-778.0168,2611.436,133.2532,0,0,0,0,100,0);
-- 0x1C09E4424010800000001F00004BCB3D .go -794.1317 2601.671 133.2523

-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58440;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-800.5278,`position_y`=2648.273,`position_z`=133.2537 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-800.5278,2648.273,133.2537,0,0,0,0,100,0),
(@PATH,2,-816.2895,2638.862,133.2529,0,0,0,0,100,0);
-- 0x1C09E4424010800000001F00004BCB47 .go -800.5278 2648.273 133.2537

-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58448;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-697.1456,`position_y`=2567.732,`position_z`=101.4374 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-697.1456,2567.732,101.4374,0,0,0,0,100,0),
(@PATH,2,-683.9911,2574.386,100.8064,0,0,0,0,100,0),
(@PATH,3,-683.9779,2574.394,100.8655,0,0,0,0,100,0),
(@PATH,4,-697.2676,2567.764,101.4445,0,0,0,0,100,0),
(@PATH,5,-682.3236,2567.782,100.8602,0,0,0,0,100,0);
-- 0x1C09E4424010800000001F00014B15DB .go -697.1456 2567.732 101.4374


-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58442;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-750.128,`position_y`=2567.929,`position_z`=104.1502 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-750.128,2567.929,104.1502,0,0,0,0,100,0),
(@PATH,2,-746.1736,2566.977,104.3655,0,0,0,0,100,0),
(@PATH,3,-732.6676,2565.869,104.5501,0,0,0,0,100,0),
(@PATH,4,-754.0043,2574.421,104.1675,0,0,0,0,100,0),
(@PATH,5,-754.0061,2574.378,104.2026,0,0,0,0,100,0),
(@PATH,6,-732.6328,2565.721,104.5407,0,0,0,0,100,0),
(@PATH,7,-746.1768,2566.991,104.2605,0,0,0,0,100,0);
-- 0x1C09E4424010800000001F00024B15DA .go -750.128 2567.929 104.1502

-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58452;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-674.274,`position_y`=2787.06,`position_z`=109.5986 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-674.274,2787.06,109.5986,0,0,0,0,100,0),
(@PATH,2,-661.9408,2782.68,107.5661,0,0,0,0,100,0),
(@PATH,3,-645.2046,2773.514,104.8345,0,0,0,0,100,0),
(@PATH,4,-664.4965,2777.165,107.6214,0,0,0,0,100,0),
(@PATH,5,-664.445,2776.807,107.7074,0,0,0,0,100,0),
(@PATH,6,-645.4469,2773.186,104.7909,0,0,0,0,100,0);
-- 0x1C09E4424010800000001F0003CB15DA .go -674.274 2787.06 109.5986

-- Pathing for Honor Hold Archer Entry: 16896 'TDB FORMAT' 
SET @NPC := 58453;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-607.841,`position_y`=2612.785,`position_z`=99.32381 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-607.841,2612.785,99.32381,0,0,0,0,100,0),
(@PATH,2,-604.588,2617.701,99.53741,0,0,0,0,100,0),
(@PATH,3,-605.6599,2620.353,99.11266,0,0,0,0,100,0),
(@PATH,4,-605.5408,2620.273,98.99216,0,0,0,0,100,0),
(@PATH,5,-604.4185,2617.526,99.5359,0,0,0,0,100,0);
-- 0x1C09E4424010800000002000004E9D75 .go -607.841 2612.785 99.32381
DELETE FROM `spell_script_names` WHERE `spell_id`=49576;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49576, 'spell_dk_death_grip_initial');
-- Pathing for Bleeding Hollow Dark Shaman Entry: 16873 'TDB FORMAT'
SET @NPC := 29978;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-945.313,`position_y`=1948.252,`position_z`=67.06455 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-945.313,1948.252,67.06455,0,0,0,0,100,0),
(@PATH,2,-946.7964,1966.628,67.06455,0,0,0,0,100,0),
(@PATH,3,-932.1639,1983.549,66.96194,0,0,0,0,100,0),
(@PATH,4,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,5,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,6,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,7,-941.426,2015.632,66.31691,0,0,0,0,100,0),
(@PATH,8,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,9,-968.4443,2047.705,67.06454,0,0,0,0,100,0),
(@PATH,10,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,11,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,12,-941.426,2015.632,66.31691,0,0,0,0,100,0),
(@PATH,13,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,14,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,15,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,16,-932.1639,1983.549,66.96194,0,0,0,0,100,0),
(@PATH,17,-946.7964,1966.628,67.06455,0,0,0,0,100,0);
-- 0xF13041E90061F326 .go -945.313 1948.252 67.06455
-- Too many or incorrect npc spawns
DELETE FROM `creature` WHERE `guid` IN (105129,97882,97881,97886,97888,97880,97898,111144,111168, 99232);

-- Pathing for Rustler Burnhoof Entry: 27750 'TDB FORMAT' 
SET @NPC := 105130;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4903.906,`position_y`=1220.93,`position_z`=223.7604 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4903.906,1220.93,223.7604,0,1000,0,0,100,0),
(@PATH,2,4907.209,1219.953,222.8496,0,0,0,0,100,0),
(@PATH,3,4905.934,1220.017,223.2021,0,0,0,0,100,0),
(@PATH,4,4902.668,1221.12,224.2068,0,1000,0,0,100,0),
(@PATH,5,4903.906,1220.93,223.7604,0,0,0,0,100,0),
(@PATH,6,4907.628,1220.036,222.8975,0,0,0,0,100,0),
(@PATH,7,4905.934,1220.017,223.2021,0,0,0,0,100,0),
(@PATH,8,4902.884,1221.202,224.2569,0,0,0,0,100,0);
-- 0x1C10F047601B198000000900001F1A2A .go 4903.906 1220.93 223.7604

-- Update SAI for waypoints
-- Darkspear Spear Thrower SAI
SET @ENTRY := 27560;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Out of Combat - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Out of Combat - Stop Attacking (No Repeat)"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Spear Thrower - On Aggro - Cast 'Shoot' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - On Aggro - Increment Phase By 1 (No Repeat)"),
(@ENTRY,0,4,5,9,1,100,0,5,35,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 5-35 Range - Cast 'Shoot' (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 5-35 Range - Set Sheath Ranged (Phase 1)"),
(@ENTRY,0,6,7,9,1,100,0,30,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 30-80 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 30-80 Range - Start Attacking (Phase 1)"),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 0-5 Range - Set Sheath Melee (Phase 1)"),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 0-5 Range - Start Attacking (Phase 1)"),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 5-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 5-15 Range - Stop Attacking (Phase 1)"),
(@ENTRY,0,13,0,9,0,100,0,0,20,9000,14000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 0-20 Range - Cast 'Net' (Phase 1)"),
(@ENTRY,0,14,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Spear Thrower - On Evade - Set Sheath Melee (Phase 1)");

-- Pathing for Darkspear Spear Thrower Entry: 27560 'TDB FORMAT' 
SET @NPC := 111723;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5064.595,`position_y`=1152.95,`position_z`=256.9933 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5064.595,1152.95,256.9933,0,0,0,0,100,0),
(@PATH,2,5070.195,1148.834,258.9739,0,0,0,0,100,0),
(@PATH,3,5073.693,1146.814,259.7574,0,0,0,0,100,0),
(@PATH,4,5064.595,1152.95,256.9933,0,0,0,0,100,0),
(@PATH,5,5070.188,1148.872,259.0485,0,0,0,0,100,0),
(@PATH,6,5073.804,1146.81,259.5706,0,0,0,0,100,0),
(@PATH,7,5078.612,1145.942,259.8978,0,0,0,0,100,0),
(@PATH,8,5067.567,1150.284,258.2607,0,0,0,0,100,0),
(@PATH,9,5063.21,1155.218,255.487,0,0,0,0,100,0);
-- 0x1C10F047601AEA0000000B00019A427C .go 5064.595 1152.95 256.9933

-- Pathing for Darkspear Spear Thrower Entry: 27560 'TDB FORMAT' 
SET @NPC := 111724;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4911.591,`position_y`=1159.036,`position_z`=236.6868 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4911.591,1159.036,236.6868,0,0,0,0,100,0),
(@PATH,2,4911.276,1158.72,236.4579,0,0,0,0,100,0),
(@PATH,3,4911.188,1158.772,236.7394,0,0,0,0,100,0),
(@PATH,4,4899.376,1152.87,236.8453,0,0,0,0,100,0),
(@PATH,5,4894.586,1145.359,234.9626,0,0,0,0,100,0),
(@PATH,6,4897.318,1151.077,236.903,0,0,0,0,100,0),
(@PATH,7,4901.86,1152.988,236.7417,0,0,0,0,100,0),
(@PATH,8,4906.159,1153.659,236.4303,0,0,0,0,100,0);
-- 0x1C10F047601AEA0000000B00009A427C .go 4911.591 1159.036 236.6868

-- Pathing for Darkspear Spear Thrower Entry: 27560 'TDB FORMAT' 
SET @NPC := 111725;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4920.973,`position_y`=1199.484,`position_z`=220.5279 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4920.973,1199.484,220.5279,0,10000,0,0,100,0),
(@PATH,2,4906.262,1193.945,216.8263,0,0,0,0,100,0),
(@PATH,3,4896.307,1191.923,213.5118,0,0,0,0,100,0),
(@PATH,4,4877.854,1191.151,207.1242,0,0,0,0,100,0),
(@PATH,5,4869.318,1191.457,203.3286,0,0,0,0,100,0),
(@PATH,6,4861.047,1185.213,197.0835,0,0,0,0,100,0),
(@PATH,7,4855.936,1177.188,191.9594,0,0,0,0,100,0),
(@PATH,8,4851.635,1166.61,185.649,0,0,0,0,100,0),
(@PATH,9,4851.767,1158.619,182.5839,0,0,0,0,100,0),
(@PATH,10,4851.611,1145.529,178.0937,0,0,0,0,100,0),
(@PATH,11,4848.171,1135.259,173.5705,0,0,0,0,100,0),
(@PATH,12,4841.896,1128.136,169.8648,0,0,0,0,100,0),
(@PATH,13,4829.645,1127.843,162.5515,0,0,0,0,100,0),
(@PATH,14,4817.105,1120.131,150.2594,0,0,0,0,100,0),
(@PATH,15,4837.624,1131.328,167.8283,0,0,0,0,100,0),
(@PATH,16,4843.094,1133.076,170.812,0,0,0,0,100,0),
(@PATH,17,4849.752,1146.139,177.2836,0,0,0,0,100,0),
(@PATH,18,4851.623,1160.048,182.5452,0,0,0,0,100,0),
(@PATH,19,4853.529,1172.237,188.9928,0,0,0,0,100,0),
(@PATH,20,4860.48,1186.084,197.2776,0,0,0,0,100,0),
(@PATH,21,4865.775,1191.164,201.062,0,0,0,0,100,0),
(@PATH,22,4882.853,1189.864,208.7863,0,0,0,0,100,0),
(@PATH,23,4898.756,1190.01,214.2629,0,0,0,0,100,0),
(@PATH,24,4903.106,1189.946,216.3225,0,0,0,0,100,0),
(@PATH,25,4916.818,1193.317,219.5798,0,0,0,0,100,0),
(@PATH,26,4927.818,1197.552,223.1037,0,0,0,0,100,0),
(@PATH,27,4934.524,1200.075,224.6629,0,0,0,0,100,0);
-- 0x1C10F047601AEA0000000900001F18A3 .go 4920.973 1199.484 220.5279

DELETE FROM `creature_formations` WHERE `leaderGUID`=111218;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(111218, 111218, 0, 0, 2),
(111218, 111212, 3, 270, 2);

-- Make the second guard sit on a wolf 
DELETE FROM `creature_addon` WHERE `guid`=111212;
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes2`) VALUES (111212, 14574, 1);

-- Pathing for Kor'kron Vanguard Entry: 27553 'TDB FORMAT' 
SET @NPC := 111218;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4924.406,`position_y`=1275.88,`position_z`=226.2913 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,14574,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4924.406,1275.88,226.2913,0,0,0,0,100,0),
(@PATH,2,4937.631,1293.169,231.839,0,0,0,0,100,0),
(@PATH,3,4942.635,1298.434,233.2347,0,0,0,0,100,0),
(@PATH,4,4945.541,1308.453,235.1535,0,0,0,0,100,0),
(@PATH,5,4945.916,1311.464,235.4867,0,0,0,0,100,0),
(@PATH,6,4933.331,1328.104,234.9145,0,0,0,0,100,0),
(@PATH,7,4920.956,1329.519,232.9218,0,0,0,0,100,0),
(@PATH,8,4910.192,1318.32,229.7501,0,0,0,0,100,0),
(@PATH,9,4907.542,1298.864,227.4101,0,0,0,0,100,0),
(@PATH,10,4920.273,1273.854,225.6455,0,0,0,0,100,0),
(@PATH,11,4921.565,1272.237,225.4687,0,0,0,0,100,0),
(@PATH,12,4934.279,1260.357,225.9705,0,0,0,0,100,0),
(@PATH,13,4942.9,1231.032,225.8454,0,0,0,0,100,0),
(@PATH,14,4937.212,1219.435,224.397,0,0,0,0,100,0),
(@PATH,15,4911.338,1207.108,217.914,0,0,0,0,100,0),
(@PATH,16,4891.614,1199.313,212.0708,0,0,0,0,100,0),
(@PATH,17,4863.26,1198.326,202.0412,0,0,0,0,100,0),
(@PATH,18,4850.935,1180.464,192.229,0,0,0,0,100,0),
(@PATH,19,4847.402,1162.623,182.7594,0,0,0,0,100,0),
(@PATH,20,4841.849,1139.334,171.3826,0,0,0,0,100,0),
(@PATH,21,4820.599,1131.604,157.3213,0,0,0,0,100,0),
(@PATH,22,4801.356,1123.592,143.7112,0,0,0,0,100,0),
(@PATH,23,4793.032,1123.066,139.6156,0,0,0,0,100,0),
(@PATH,24,4768.374,1127.539,137.6369,0,0,0,0,100,0),
(@PATH,25,4754.815,1120.818,134.7707,0,0,0,0,100,0),
(@PATH,26,4756.951,1111.815,133.9409,0,0,0,0,100,0),
(@PATH,27,4783.79,1110.19,135.937,0,0,0,0,100,0),
(@PATH,28,4794.232,1119.631,139.188,0,0,0,0,100,0),
(@PATH,29,4821.204,1132.168,157.943,0,0,0,0,100,0),
(@PATH,30,4839.43,1138.844,170.0454,0,0,0,0,100,0),
(@PATH,31,4845.836,1150.71,177.3853,0,0,0,0,100,0),
(@PATH,32,4845.682,1166.896,184.5937,0,0,0,0,100,0),
(@PATH,33,4851.188,1179.674,191.6429,0,0,0,0,100,0),
(@PATH,34,4856.156,1191.45,197.6969,0,0,0,0,100,0),
(@PATH,35,4866.021,1197.9,202.6528,0,0,0,0,100,0),
(@PATH,36,4877.186,1197.585,207.2055,0,0,0,0,100,0),
(@PATH,37,4886.485,1195.461,210.3322,0,0,0,0,100,0),
(@PATH,38,4899.135,1196.966,214.2494,0,0,0,0,100,0),
(@PATH,39,4918.985,1205.409,219.7656,0,0,0,0,100,0),
(@PATH,40,4937.731,1213.068,223.7986,0,0,0,0,100,0),
(@PATH,41,4945.257,1216.732,225.4393,0,0,0,0,100,0),
(@PATH,42,4964.039,1213.632,227.3908,0,0,0,0,100,0),
(@PATH,43,4977.262,1211.667,228.8397,0,0,0,0,100,0),
(@PATH,44,4995.401,1220.229,230.2568,0,0,0,0,100,0),
(@PATH,45,5005.794,1216.344,229.7073,0,0,0,0,100,0),
(@PATH,46,4999.293,1203.755,229.2162,0,0,0,0,100,0),
(@PATH,47,4998.588,1202.614,228.9512,0,0,0,0,100,0),
(@PATH,48,4990.875,1206.203,228.9671,0,0,0,0,100,0),
(@PATH,49,4981.535,1210.325,228.6667,0,0,0,0,100,0),
(@PATH,50,4954.279,1220.26,226.6951,0,0,0,0,100,0),
(@PATH,51,4947.755,1223.85,226.0268,0,0,0,0,100,0),
(@PATH,52,4940.268,1236.863,226.4474,0,0,0,0,100,0),
(@PATH,53,4938.791,1241.772,226.2903,0,0,0,0,100,0),
(@PATH,54,4938.446,1241.541,226.0408,0,0,0,0,100,0),
(@PATH,55,4942.353,1231.415,225.6545,0,0,0,0,100,0),
(@PATH,56,4951.323,1221.968,226.2391,0,0,0,0,100,0),
(@PATH,57,4968.059,1214.005,228.1602,0,0,0,0,100,0),
(@PATH,58,4968.759,1213.868,228.1815,0,0,0,0,100,0),
(@PATH,59,4981.347,1210.41,228.6719,0,0,0,0,100,0),
(@PATH,60,4990.792,1206.41,229.0509,0,0,0,0,100,0),
(@PATH,61,5001.532,1208.859,229.2795,0,0,0,0,100,0),
(@PATH,62,5006.636,1217.603,229.9853,0,0,0,0,100,0),
(@PATH,63,4988.494,1214.931,229.4006,0,0,0,0,100,0),
(@PATH,64,4970.586,1211.76,228.4952,0,0,0,0,100,0),
(@PATH,65,4955.156,1216.567,226.4764,0,0,0,0,100,0),
(@PATH,66,4920.63,1206.658,220.0801,0,0,0,0,100,0),
(@PATH,67,4908.19,1199.289,216.899,0,0,0,0,100,0),
(@PATH,68,4888.762,1195.545,210.6963,0,0,0,0,100,0),
(@PATH,69,4878.838,1197.535,207.8827,0,0,0,0,100,0),
(@PATH,70,4868.977,1198.564,204.075,0,0,0,0,100,0),
(@PATH,71,4857.268,1192.864,198.429,0,0,0,0,100,0),
(@PATH,72,4852.329,1182.311,193.1272,0,0,0,0,100,0),
(@PATH,73,4846.871,1170.936,186.4543,0,0,0,0,100,0),
(@PATH,74,4846.116,1153.266,178.4778,0,0,0,0,100,0),
(@PATH,75,4840.938,1140.415,171.2645,0,0,0,0,100,0),
(@PATH,76,4822.356,1132.747,159.001,0,0,0,0,100,0),
(@PATH,77,4795.46,1120.689,140.3265,0,0,0,0,100,0),
(@PATH,78,4786.737,1111.815,136.5621,0,0,0,0,100,0),
(@PATH,79,4761.876,1105.746,133.8939,0,0,0,0,100,0),
(@PATH,80,4754.403,1118.203,134.364,0,0,0,0,100,0),
(@PATH,81,4764.019,1125.688,136.6772,0,0,0,0,100,0),
(@PATH,82,4782.308,1124.246,137.7441,0,0,0,0,100,0),
(@PATH,83,4797.498,1123.224,141.726,0,0,0,0,100,0),
(@PATH,84,4818.895,1130.859,156.3943,0,0,0,0,100,0),
(@PATH,85,4839.273,1137.457,169.8718,0,0,0,0,100,0),
(@PATH,86,4846.415,1158.605,180.5813,0,0,0,0,100,0),
(@PATH,87,4849.638,1177.232,190.3028,0,0,0,0,100,0),
(@PATH,88,4860.67,1196.271,200.4404,0,0,0,0,100,0),
(@PATH,89,4886.715,1198.448,210.6501,0,0,0,0,100,0),
(@PATH,90,4906.66,1204.837,216.6283,0,0,0,0,100,0),
(@PATH,91,4934.462,1217.512,223.728,0,0,0,0,100,0),
(@PATH,92,4940.261,1224.569,225.2942,0,0,0,0,100,0),
(@PATH,93,4940.506,1242.196,226.2575,0,0,0,0,100,0),
(@PATH,94,4933.305,1263.189,225.7185,0,0,0,0,100,0),
(@PATH,95,4931.952,1265.79,225.6381,0,0,0,0,100,0),
(@PATH,96,4907.601,1289.275,226.642,0,0,0,0,100,0),
(@PATH,97,4907.739,1309.926,228.4361,0,0,0,0,100,0),
(@PATH,98,4916.103,1327.044,231.7567,0,0,0,0,100,0),
(@PATH,99,4928.627,1329.424,234.3804,0,0,0,0,100,0),
(@PATH,100,4940.942,1320.479,235.4543,0,0,0,0,100,0),
(@PATH,101,4944.531,1301.983,234.3128,0,0,0,0,100,0),
(@PATH,102,4940.48,1296.446,232.8031,0,0,0,0,100,0),
(@PATH,103,4924.831,1276.205,226.2591,0,0,0,0,100,0);
-- 0x1C10F047601AE84000000A00001FFDD8 .go 4924.406 1275.88 226.2913

-- Pathing for Kor'kron Battle Wyvern Entry: 31269 'TDB FORMAT' 
SET @NPC := 99228;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5001.591,`position_y`=1222.632,`position_z`=256.7944 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5001.591,1222.632,256.7944,0,0,0,0,100,0),
(@PATH,2,5030.151,1242.143,268.1555,0,0,0,0,100,0),
(@PATH,3,5016.198,1276.81,265.4842,0,0,0,0,100,0),
(@PATH,4,4991.751,1280.123,265.4842,0,0,0,0,100,0),
(@PATH,5,4956.835,1268.773,265.4842,0,0,0,0,100,0),
(@PATH,6,4938.806,1223.236,259.9842,0,0,0,0,100,0),
(@PATH,7,4926.227,1191.379,255.3177,0,0,0,0,100,0),
(@PATH,8,4900.753,1152.352,243.8777,0,0,0,0,100,0),
(@PATH,9,4881.784,1164.878,242.3777,0,0,0,0,100,0),
(@PATH,10,4851.181,1199.767,234.0444,0,0,0,0,100,0),
(@PATH,11,4846.833,1226.647,234.0444,0,0,0,0,100,0),
(@PATH,12,4855.959,1279.159,239.3777,0,0,0,0,100,0),
(@PATH,13,4911.077,1262.704,243.6555,0,0,0,0,100,0),
(@PATH,14,4964.954,1234.062,250.3221,0,0,0,0,100,0);
-- 0x2010F047601E894000000B00029A427C .go 5001.591 1222.632 256.7944

-- Pathing for Kor'kron Battle Wyvern Entry: 31269 'TDB FORMAT' 
SET @NPC := 99227;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4875.777,`position_y`=1347.747,`position_z`=240.9708 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4875.777,1347.747,240.9708,0,0,0,0,100,0),
(@PATH,2,4900.708,1348.037,250.7207,0,0,0,0,100,0),
(@PATH,3,4926.32,1316.925,257.1653,0,0,0,0,100,0),
(@PATH,4,4938.213,1286.196,257.1653,0,0,0,0,100,0),
(@PATH,5,4947.025,1253.411,257.1653,0,0,0,0,100,0),
(@PATH,6,4945.441,1212.37,257.1653,0,0,0,0,100,0),
(@PATH,7,4948.411,1192.561,257.1653,0,0,0,0,100,0),
(@PATH,8,4972.647,1168.416,257.1653,0,0,0,0,100,0),
(@PATH,9,4995.961,1172.082,257.1653,0,0,0,0,100,0),
(@PATH,10,5004.243,1187.687,257.1653,0,0,0,0,100,0),
(@PATH,11,4989.543,1213.347,257.1653,0,0,0,0,100,0),
(@PATH,12,4965.152,1218.435,257.1653,0,0,0,0,100,0),
(@PATH,13,4923.045,1229.254,257.1653,0,0,0,0,100,0),
(@PATH,14,4887.481,1234.967,253.9984,0,0,0,0,100,0),
(@PATH,15,4851.523,1249.735,247.804,0,0,0,0,100,0),
(@PATH,16,4823.958,1288.316,234.6374,0,0,0,0,100,0),
(@PATH,17,4814.918,1327.853,230.693,0,0,0,0,100,0),
(@PATH,18,4853.216,1355.696,237.3319,0,0,0,0,100,0);
-- 0x2010F047601E894000000B00021A427C .go 4875.777 1347.747 240.9708

-- Pathing for Kor'kron Battle Wyvern Entry: 31269 'TDB FORMAT' 
SET @NPC := 99230;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5079.162,`position_y`=1142.135,`position_z`=267.7354 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5079.162,1142.135,267.7354,0,0,0,0,100,0),
(@PATH,2,5078.512,1126.875,267.7354,0,0,0,0,100,0),
(@PATH,3,5055.61,1116.456,267.7354,0,0,0,0,100,0),
(@PATH,4,5039.365,1121.131,267.7354,0,0,0,0,100,0),
(@PATH,5,4967.615,1187.905,260.0954,0,0,0,0,100,0),
(@PATH,6,4945.081,1216.898,260.0954,0,0,0,0,100,0),
(@PATH,7,4956.427,1234.148,260.0954,0,0,0,0,100,0),
(@PATH,8,4960.777,1262.983,260.0954,0,0,0,0,100,0),
(@PATH,9,4914.742,1284.397,254.9566,0,0,0,0,100,0),
(@PATH,10,4891.905,1273.239,254.5677,0,0,0,0,100,0),
(@PATH,11,4867.362,1252.014,255.6233,0,0,0,0,100,0),
(@PATH,12,4872.584,1220.825,255.6233,0,0,0,0,100,0),
(@PATH,13,4921.48,1192.52,255.6233,0,0,0,0,100,0),
(@PATH,14,4940.803,1188.571,255.6233,0,0,0,0,100,0),
(@PATH,15,4982.143,1184.493,255.6233,0,0,0,0,100,0),
(@PATH,16,5063.028,1170.208,265.2344,0,0,0,0,100,0),
(@PATH,17,5072.713,1157.194,267.7354,0,0,0,0,100,0);
-- 0x2010F047601E894000000B00009A427C .go 5079.162 1142.135 267.7354

-- Some specific Kor'kron Battle Wyvern's shouldn't move.
UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN (99246,99225,99226,99233);

-- Make those peon's work
SET @NPC := 27558;
DELETE FROM `creature_template_addon` WHERE `entry`=@NPC;
INSERT INTO `creature_template_addon` (`entry`, `emote`) VALUES (@NPC, 234);

-- Pathing for Warsong Peon Entry: 27558 'TDB FORMAT' 
SET @NPC := 111465;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5033.687,`position_y`=1241.426,`position_z`=231.0835 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,234, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5033.687,1241.426,231.0835,0,10000,0,0,100,0),
(@PATH,2,5035.556,1229.439,230.2363,0,0,0,0,100,0),
(@PATH,3,5040.211,1214.877,229.068,0,0,0,0,100,0),
(@PATH,4,5040.954,1202.383,228.5539,0,0,0,0,100,0),
(@PATH,5,5040.104,1193.25,228.4282,0,0,0,0,100,0),
(@PATH,6,5031.986,1186.173,228.1725,0,10000,0,0,100,0),
(@PATH,7,5040.118,1194.927,228.1124,0,0,0,0,100,0),
(@PATH,8,5040.393,1195.888,228.1124,0,0,0,0,100,0),
(@PATH,9,5042.309,1202.575,228.527,0,0,0,0,100,0),
(@PATH,10,5040.336,1213.374,228.7625,0,0,0,0,100,0),
(@PATH,11,5040.336,1213.374,228.7625,0,0,0,0,100,0),
(@PATH,12,5038.792,1223.162,229.6375,0,0,0,0,100,0),
(@PATH,13,5033.343,1233.986,230.8479,0,0,0,0,100,0);
-- 0x1C10F047601AE98000000B00029A427C .go 5033.687 1241.426 231.0835
--
UPDATE `creature` SET `spawndist`=0 WHERE `guid` IN (99225, 99226, 99233, 99246);
DELETE FROM `creature_addon` WHERE `guid`=99232;
UPDATE `creature` SET `orientation`=0 WHERE `guid`=29978;
-- Lunar 0
-- Lita  1
-- Noblegarden 2
-- Childrens week 3
-- Midsummer 4
-- Brewfest 5
-- Hallows End 6
-- Pilgrims 7
-- Winterveil 8

-- Undead  Hallows End Winterveil
-- Bloodelf Luna winterveil midsummer
-- Orc Luna brewfest hallows end 
-- Troll Luna 
-- Tauren 
-- Goblin Hallows end   Winterveil
-- Human Luna Hallows end
-- Gnome Hallows end
-- Dwarf 
-- Lunar
-- Night elf
-- Dreanei Brewfest

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`IN(20102,18927,19177,19169,19175,19171,19172,19176,19178);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(20102,18927,19177,19169,19175,19171,19172,19176,19178)  AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20102,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Commoner - OOC - Say'),
(18927,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Human Commoner - OOC - Say'),
(19177,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Troll Commoner - OOC - Say'),
(19169,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood Elf Commoner - OOC - Say'),
(19175,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orc Commoner - OOC - Say'),
(19169,0,4,0,1,0,100,0,3000,15000,45000,90000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood Elf Commoner - OOC - Say'),
(19175,0,5,0,1,0,100,0,3000,15000,45000,90000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orc Commoner - OOC - Say'),
(19171,0,5,0,1,0,100,0,3000,15000,45000,90000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood Elf Commoner - OOC - Say'),
(20102,0,6,0,1,0,100,0,3000,15000,45000,90000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Commoner - OOC - Say'),
(19172,0,6,0,1,0,100,0,3000,15000,45000,90000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnome Commoner - OOC - Say'),
(18927,0,6,0,1,0,100,0,3000,15000,45000,90000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Human Commoner - OOC - Say'),
(19175,0,6,0,1,0,100,0,3000,15000,45000,90000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orc Commoner - OOC - Say'),
(19178,0,6,0,1,0,100,0,3000,15000,45000,90000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forsaken Commoner - OOC - Say'),
(19178,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forsaken Commoner - OOC - Say'),
(20102,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Commoner - OOC - Say'),
(19169,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood Elf Commoner - OOC - Say');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` in(20102,18927,19177,19169,19175,19171,19172,19176,19178);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 20102, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 18927, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19175, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19169, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19177, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 5, 19169, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer must be active'),
(22, 6, 19175, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - BrewFest must be active'),
(22, 6, 19171, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - BrewFest must be active'),
(22, 7, 20102, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallows End must be active'),
(22, 7, 19172, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallows End must be active'),
(22, 7, 18927, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallows End must be active'),
(22, 7, 19175, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallows End must be active'),
(22, 7, 19178, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallows End must be active'),
(22, 9, 20102, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19169, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19178, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active');

DELETE FROM `creature_text` WHERE `entry` IN(20102,18927,19177,19169,19175,19171,19172,19176,19178);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(20102, 0, 0, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 0, 100, 0, 0, 0, 16465, 'Goblin Commoner to Goblin Commoner'),
(20102, 0, 1, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 0, 100, 0, 0, 0, 16468, 'Goblin Commoner to Goblin Commoner'),
(18927, 0, 0, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 7, 100, 274, 0, 0, 24350, 'Human Commoner to Human Commoner'),
(19177, 0, 0, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 1, 100, 0, 0, 0, 24332, 'Troll Commoner to Troll Commoner'),
(19169, 0, 0, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 1, 100, 0, 0, 0, 24332, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 0, 1, 'The festival of the moon was ever more important to the kaldorei. The great festival of the druids is surely in full swing.', 12, 1, 100, 274, 0, 0, 16171, 'Blood Elf Commoner to Blood Elf Commoner'),
(19175, 0, 0, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 1, 100, 0, 0, 0, 24333, 'Orc Commoner to Orc Commoner'),
(19175, 0, 1, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 1, 100, 0, 0, 0, 24334, 'Orc Commoner to Orc Commoner'),
(19175, 0, 2, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 1, 100, 0, 0, 0, 24335, 'Orc Commoner to Orc Commoner'),
-- Brew Fest
(19171, 5, 0, 'To Brewfest!', 12, 7, 100, 5, 0, 0, 23630, 'Draenei Commoner to Draenei Commoner'),
(19175, 5, 0, 'Where''s me gold? Where''s me beer? Where''s me feet?', 12, 1, 100, 5, 0, 0, 23352, 'Orc Commoner to Orc Commoner'),
-- Hallows end
(20102, 6, 0, 'There MUST be a way to make more money off of this holiday.', 12, 0, 100, 0, 0, 0, 23299, 'Goblin Commoner to Goblin Commoner'),
(20102, 6, 1, 'For the Alliance! Wait... the Horde! Wait... which was I again?', 12, 0, 100, 4, 0, 149, 23364, 'Goblin Commoner to Goblin Commoner'),
(20102, 6, 2, 'The innkeepers are mad to be giving away treats for free.', 12, 0, 100, 0, 0, 0, 23300, 'Goblin Commoner to Goblin Commoner'),
(20102, 6, 3, 'Happy Hallow''s End!', 12, 0, 100, 0, 0, 0, 23284, 'Goblin Commoner to Goblin Commoner'),
(19172, 6, 0, 'We should go trick or treating later.', 12, 7, 100, 0, 0, 0, 24348, 'Gnome Commoner to Gnome Commoner'),
(19172, 6, 1, 'Happy Hallow''s End!', 12, 7, 100, 0, 0, 0, 24346, 'Gnome Commoner to Gnome Commoner'),
(19172, 6, 2, 'We should go trick or treating later.', 12, 7, 100, 1, 0, 0, 24348, 'Gnome Commoner to Gnome Commoner'),
(19172, 6, 3, 'Me got the mad voodoo, mon!', 12, 7, 100, 1, 0, 0, 23361, 'Gnome Commoner to Gnome Commoner'),
(18927, 6, 0, 'I think I''ve eaten too much candy...', 12, 7, 100, 15, 0, 0, 24347, 'Human Commoner to Human Commoner'),
(18927, 6, 1, 'Brains... braaaiiins!', 12, 7, 100, 15, 0, 0, 23358, 'Human Commoner to Human Commoner'),
(18927, 6, 2, 'We should go trick or treating later.', 12, 7, 100, 0, 0, 0, 24348, 'Human Commoner to Human Commoner'),
(18927, 6, 3, 'I think I''ve eaten too much candy...', 12, 7, 100, 0, 0, 0, 24347, 'Human Commoner to Human Commoner'),
(18927, 6, 4, 'Are there any more inns we can visit for treats?', 12, 7, 100, 0, 0, 0, 23293, 'Human Commoner to Human Commoner'),
(18927, 6, 5, 'Next year, I''m dressing up as either a corsair or an assassin.', 12, 7, 100, 0, 0, 0, 24338, 'Human Commoner to Human Commoner'),
(18927, 6, 6, 'What do you think of the mask?', 12, 7, 100, 0, 0, 0, 24339, 'Human Commoner to Human Commoner'),
(18927, 6, 7, 'You know... why DO we celebrate this holiday?', 12, 7, 100, 0, 0, 0, 23287, 'Human Commoner to Human Commoner'),
(19175, 6, 0, 'Happy Hallow''s End!', 12, 1, 100, 0, 0, 0, 24329, 'Orc Commoner to Orc Commoner'),
(19175, 6, 1, 'Next year, I''m dressing up as either a corsair or an assassin.', 12, 1, 100, 0, 0, 0, 24336, 'Orc Commoner to Orc Commoner'),
(19175, 6, 2, 'The Forsaken are right to celebrate their freedom.', 12, 1, 100, 0, 0, 0, 23295, 'Orc Commoner to Orc Commoner'),
(19175, 6, 3, 'We should attend the next burning of the Wickerman.', 12, 1, 100, 0, 0, 0, 23292, 'Orc Commoner to Orc Commoner'),
(19175, 6, 4, 'What do you think of the mask?', 12, 1, 100, 0, 0, 0, 24337, 'Orc Commoner to Orc Commoner'),
(19175, 6, 5, 'We should go trick or treating later.', 12, 1, 100, 1, 0, 0, 24331, 'Orc Commoner to Orc Commoner'),
(19178, 6, 0, 'We should go trick or treating later.', 12, 1, 100, 0, 0, 0, 24331, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 6, 1, 'Happy Hallow''s End!', 12, 1, 100, 0, 0, 0, 24329, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 6, 2, 'I think I''ve eaten too much candy...', 12, 1, 100, 15, 0, 0, 24330, 'Forsaken Commoner to Forsaken Commoner'),
-- Winterveil
(19178, 8, 0, 'Winter Veil just isn''t the same now, but going through the motions still makes me feel something.', 12, 1, 100, 0, 0, 0, 16167, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 1, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 6, 0, 0, 16464, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 2, 'Where are all those wonderful winter hats coming from?', 12, 1, 100, 0, 0, 0, 24325, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 3, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 0, 0, 0, 24323, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 4, 'Winter Veil just isn''t the same now, but going through the motions still makes me feel something.', 12, 1, 100, 396, 0, 0, 16167, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 5, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 273, 0, 0, 24323, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 6, 'Where are all those wonderful winter hats coming from?', 12, 1, 100, 273, 0, 0, 24325, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 7, 'Winter Veil just isn''t the same now, but going through the motions still makes me feel something.', 12, 1, 100, 6, 0, 0, 16167, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 8, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 1, 100, 273, 0, 0, 24324, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 9, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 396, 0, 0, 16464, 'Forsaken Commoner to Forsaken Commoner'),
(20102, 8, 0, 'Where are all those wonderful winter hats coming from?', 12, 0, 100, 0, 0, 0, 16503, 'Goblin Commoner to Goblin Commoner'),
(20102, 8, 1, 'Ah, the Winter Wondervolt. What will we think of next?', 12, 0, 100, 0, 0, 0, 16501, 'Goblin Commoner to Goblin Commoner'),
(20102, 8, 2, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 0, 100, 0, 0, 0, 0, 'Goblin Commoner to Goblin Commoner'),
(20102, 8, 3, 'Ah, the Winter Wondervolt. What will we think of next?', 12, 0, 100, 274, 0, 0, 16501, 'Goblin Commoner to Goblin Commoner'),
(19169, 8, 0, 'Winter Veil has always been a human thing. To see the goblins and orcs take it up is rather strange.', 12, 1, 100, 0, 0, 0, 16173, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 8, 1, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 0, 0, 0, 16464, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 8, 2, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 6, 0, 0, 16464, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 8, 3, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 0, 0, 0, 24323, 'Blood Elf Commoner to Blood Elf Commoner'),
-- Midsummer
(19169, 4, 0, 'The Horde fires will never be extinguished!', 12, 1, 100, 4, 0, 0, 24534, 'Blood Elf Commoner to Blood Elf Commoner');
UPDATE `creature` SET `phaseMask`=2 WHERE  `id` In(31310,31313,31328,31330);
DELETE FROM `creature_text` WHERE `entry` IN(18927,19171,19175,19177,19173,19172,19176,19148) AND `groupid`=8;
DELETE FROM `creature_text` WHERE `entry` =15746;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(18927, 8, 0, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 7, 100, 6, 0, 0, 24341, 'Human Commoner to Human Commoner'),
(18927, 8, 1, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 7, 100, 0, 0, 0, 24341, 'Human Commoner to Human Commoner'),
(18927, 8, 2, 'I should take the tram to Ironforge and visit Greatfather Winter.', 12, 7, 100, 6, 0, 0, 16032, 'Human Commoner to Human Commoner'),
(18927, 8, 3, 'Greatfather Winter will leave presents for everyone under the tree in Ironforge. I can''t wait to get mine!', 12, 7, 100, 0, 0, 0, 16422, 'Human Commoner to Human Commoner'),
(18927, 8, 4, 'Greatfather Winter will leave presents for everyone under the tree in Ironforge. I can''t wait to get mine!', 12, 7, 100, 396, 0, 0, 16422, 'Human Commoner to Human Commoner'),
(18927, 8, 5, 'I should take the tram to Ironforge and visit Greatfather Winter.', 12, 7, 100, 0, 0, 0, 16032, 'Human Commoner to Human Commoner'),
(18927, 8, 6, 'Where are all those wonderful winter hats coming from?', 12, 7, 100, 0, 0, 0, 24342, 'Human Commoner to Human Commoner'),
(18927, 8, 7, 'I should take the tram to Ironforge and visit Greatfather Winter.', 12, 7, 100, 396, 0, 0, 16032, 'Human Commoner to Human Commoner'),
(19171, 8, 0, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 7, 100, 0, 0, 0, 24341, 'Draenei Commoner to Draenei Commoner'),
(19171, 8, 1, 'Where are all those wonderful winter hats coming from?', 12, 7, 100, 0, 0, 0, 24342, 'Draenei Commoner to Draenei Commoner'),
(19171, 8, 2, 'Greatfather Winter will leave presents for everyone under the tree in Ironforge. I can''t wait to get mine!', 12, 7, 100, 0, 0, 0, 16422, 'Draenei Commoner to Draenei Commoner'),
(19171, 8, 3, 'It is my understanding that the people of the Alliance celebrate this Winter Veil in Ironforge.', 12, 7, 100, 0, 0, 0, 16161, 'Draenei Commoner to Draenei Commoner'),
(19175, 8, 0, 'Though we do not truly understand the traditions of Winter Veil, we have taken to them.', 12, 1, 100, 0, 0, 0, 16164, 'Orc Commoner to Orc Commoner'),
(19175, 8, 1, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 0, 0, 0, 24323, 'Orc Commoner to Orc Commoner'),
(19175, 8, 2, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 6, 0, 0, 24323, 'Orc Commoner to Orc Commoner'),
(19177, 8, 0, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 0, 0, 0, 24323, 'Troll Commoner to Troll Commoner'),
(19177, 8, 1, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 0, 0, 0, 16464, 'Troll Commoner to Troll Commoner'),
(19177, 8, 2, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 1, 100, 0, 0, 0, 24324, 'Troll Commoner to Troll Commoner'),
(15746, 8, 0, 'Presents for everyone! Father Winter''s put gifts under the tree for all.', 14, 0, 100, 0, 0, 0, 11430, 'Great-father Winter''s Helper'),
(19173, 8, 0, 'It feels like everyone wants to kiss me under the mistletoe.', 12, 7, 100, 0, 0, 0, 16158, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 8, 1, 'It feels like everyone wants to kiss me under the mistletoe.', 12, 7, 100, 396, 0, 0, 16158, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 8, 2, 'Where are all those wonderful winter hats coming from?', 12, 7, 100, 0, 0, 0, 24342, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 8, 3, 'Greatfather Winter will leave presents for everyone under the tree in Ironforge. I can''t wait to get mine!', 12, 7, 100, 6, 0, 0, 16422, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 8, 4, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 7, 100, 0, 0, 0, 0, 'Night Elf Commoner to Night Elf Commoner'),
(19172, 8, 0, 'Greatfather Winter will leave presents for everyone under the tree in Ironforge. I can''t wait to get mine!', 12, 7, 100, 0, 0, 0, 16422, 'Gnome Commoner to Gnome Commoner'),
(19172, 8, 1, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 7, 100, 0, 0, 0, 24340, 'Gnome Commoner to Gnome Commoner'),
(19172, 8, 2, 'How embarrassing! Someone mistook me for one of Greatfather Winter''s helpers.', 12, 7, 100, 0, 0, 0, 016204, 'Gnome Commoner to Gnome Commoner'),
(19172, 8, 3, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 7, 100, 273, 0, 0, 24340, 'Gnome Commoner to Gnome Commoner'),
(19172, 8, 4, 'Where are all those wonderful winter hats coming from?', 12, 7, 100, 0, 0, 0, 24342, 'Gnome Commoner to Gnome Commoner'),
(19176, 8, 0, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 0, 0, 0, 24323, 'Tauren Commoner to Tauren Commoner'),
(19176, 8, 1, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 0, 0, 0, 16464, 'Tauren Commoner to Tauren Commoner'),
(19176, 8, 2, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 1, 100, 0, 0, 0, 24324, 'Tauren Commoner to Tauren Commoner'),
(19176, 8, 3, 'Greatfather Winter is only a wyvern''s ride away to Orgrimmar.', 12, 1, 100, 0, 0, 0, 16170, 'Tauren Commoner to Tauren Commoner'),
(19148, 8, 0, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 7, 100, 0, 0, 0, 24341, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 8, 1, 'Where are all those wonderful winter hats coming from?', 12, 7, 100, 274, 0, 0, 24342, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 8, 2, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 7, 100, 0, 0, 0, 24340, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 8, 3, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 7, 100, 0, 0, 0, 24341, 'Dwarf Commoner to Dwarf Commoner');


UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`IN(19148,15746,19173);
DELETE FROM `smart_scripts` WHERE `entryorguid`=15746  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(18927,19171,19175,19177,19173,19172,19176,19148)  AND `source_type`=0 AND  `id`=8;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(18927,19171,19175,19177,19173,19172,19176,19148,19148,19173)  AND `source_type`=0 AND  `id`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES

(18927,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Human Commoner - OOC - Say'),
(19171,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dreani Commoner - OOC - Say'),
(19175,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orc Commoner - OOC - Say'),
(19177,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Troll Commoner - OOC - Say'),
(19173,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Night Elf Commoner - OOC - Say'),
(19172,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnome Commoner - OOC - Say'),
(19176,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tauren Commoner - OOC - Say'),
(19148,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dwarf Commoner - OOC - Say'),
(15746,0,0,0,1,0,100,0,3000,15000,600000,600000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Great-father Winter''s Helper - OOC - Say'),

(18927,0,9,0,64,0,100,0,0,0,0,0,98,7862, 9626,0,0,0,0,7,0,0,0,0,0,0,0,'Human Commoner - On Gossip Hello - Send Gossip Menu'),
(19148,0,9,0,64,0,100,0,0,0,0,0,98,7907, 9686,0,0,0,0,7,0,0,0,0,0,0,0,'Dwarf Commoner - On Gossip Hello - Send Gossip Menu'),
(19169,0,9,0,64,0,100,0,0,0,0,0,98,7911, 9698,0,0,0,0,7,0,0,0,0,0,0,0,'Blood Elf Commoner - On Gossip Hello - Send Gossip Menu'),
(19171,0,9,0,64,0,100,0,0,0,0,0,98,7910, 9694,0,0,0,0,7,0,0,0,0,0,0,0,'Draeni Commoner - On Gossip Hello - Send Gossip Menu'),
(19172,0,9,0,64,0,100,0,0,0,0,0,98,7929, 9717,0,0,0,0,7,0,0,0,0,0,0,0,'Gnome Commoner - On Gossip Hello - Send Gossip Menu'),
(19173,0,9,0,64,0,100,0,0,0,0,0,98,7909, 9690,0,0,0,0,7,0,0,0,0,0,0,0,'Night Elf Commoner - On Gossip Hello - Send Gossip Menu'),
(19175,0,9,0,64,0,100,0,0,0,0,0,98,7912, 9702,0,0,0,0,7,0,0,0,0,0,0,0,'Orc Commoner - On Gossip Hello - Send Gossip Menu'),
(19176,0,9,0,64,0,100,0,0,0,0,0,98,7913, 9706,0,0,0,0,7,0,0,0,0,0,0,0,'Tauren Commoner - On Gossip Hello - Send Gossip Menu'),
(19177,0,9,0,64,0,100,0,0,0,0,0,98,7933, 9718,0,0,0,0,7,0,0,0,0,0,0,0,'Troll Commoner - On Gossip Hello - Send Gossip Menu'),
(19178,0,9,0,64,0,100,0,0,0,0,0,98,7914, 9710,0,0,0,0,7,0,0,0,0,0,0,0,'Forsaken Commoner - On Gossip Hello - Send Gossip Menu');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` in(18927,19171,19175,19177,19173,19172,19176,19148) AND `SourceGroup`=9;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` in(18927,19171,19175,19177,19173,19172,19176,19148,19148,19173) AND `SourceGroup`=10;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =15746;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 9, 18927, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19171, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19175, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19177, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19173, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19172, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19176, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19148, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 1, 15746, 0, 0, 12, 1, 52, 0, 0, 0, 0, 0, '', 'Great-father Winter''s Helper - Winter Veil: Gifts must be active'),
(22, 10, 18927, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19148, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19169, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19171, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19172, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19173, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19175, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19176, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19177, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19178, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active');

DELETE FROM `gossip_menu` WHERE `entry` IN(7929,7913,7912,7909,7862,7907,7911,7914,7933,7910);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(7929, 9717), -- 19172
(7913, 9706), -- 19176
(7912, 9702), -- 19175
(7909, 9690), -- 19173
(7862, 9626), -- 18927
(7907, 9686), -- 19148
(7911, 9698), -- 19169
(7914, 9710), -- 19178
(7933, 9718), -- 19177
(7910, 9694); -- 19171

-- Fix Karazhan opera event game objects 
-- Interaction fix => Disable player interaction with Door and Curtain
UPDATE `gameobject_template` SET `flags` = 16 WHERE `entry` IN (184278,184279,183932);
UPDATE `creature_template` SET `faction`=35 WHERE  `entry`IN(24009,24010);
UPDATE `creature_template` SET `faction`=1434 WHERE  `entry`=9516;
--
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry` IN (34796,34799,35438,35439,35440,35514,35515,35516);
--
-- ALTER TABLE `quest_template` CHANGE `RewardHonorMultiplier` `RewardHonorMultiplier` FLOAT NOT NULL DEFAULT '0';
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry` IN (35144,35511,35512,35513);
-- Replace the previously spawned chests with sniffed ones
DELETE FROM `gameobject` WHERE `id` IN (185168, 185169) AND `guid` IN (20499, 20496);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(20496, 185168, 543, 3, 1, -1429.81, 1772.916, 82.0765, 5.044002, 0, 0, 0, 1, 7200, 255, 1, 19243), -- 185168 (Area: 3562)
(20499, 185169, 543, 3, 1, -1429.81, 1772.916, 82.0765, 5.044002, 0, 0, 0, 1, 7200, 255, 1, 19243); -- 185169 (Area: 3562)
-- Lights Vengence

SET @QUEST := 24546;-- The Sacred and the Corrupt
SET @TRIGG := 5650;
SET @LIGHTSVENGENCE:= 49869;
SET @BUNNY		:= 37832;-- Lich King Stun Bunny
SET @BUNNY2		:= 37878;-- AoD Impact Bunny

SET @LICHKING 		:= 37857;-- The Lich King

SET @CGUID		:= 76000;

UPDATE `creature_template` SET `flags_extra`=130 WHERE  `entry`=37826;
UPDATE `creature_template` SET `unit_flags`=768, `unit_flags2`=2099200, `dynamicflags`=1613035584 WHERE  `entry`=37857;
UPDATE `creature_template` SET `unit_flags`=33554688, `unit_flags2`=2099200, `dynamicflags`=1613037824 WHERE  `entry`=37894;
UPDATE `creature_template` SET `unit_flags`=33554688, `unit_flags2`=2099200, `dynamicflags`=1613036800 WHERE  `entry`=37878;


DELETE FROM `areatrigger_scripts` WHERE `entry` = @TRIGG;
INSERT INTO `areatrigger_scripts`(`entry`, `ScriptName`) VALUES
(@TRIGG,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` =@TRIGG AND `source_type`=2;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TRIGG,2,0,1,46,0,100,0,@TRIGG,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"On Trigger - Store Target List"),
(@TRIGG,2,1,2,61,0,100,0,@TRIGG,0,0,0,100,1,0,0,0,0,0,10,@CGUID,@BUNNY,0,0,0,0,0,"On Trigger - Send Target List to Lich King Stun Bunny"),
(@TRIGG,2,2,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,@CGUID,@BUNNY,0,0,0,0,0,"On Trigger - Set Data on Lich King Stun Bunny");

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE`entry`IN(@BUNNY,@LICHKING,37827,37832,@BUNNY2,37881,37894,37893,38001,37976,37826,37952);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@BUNNY,@LICHKING,37827,37832,@BUNNY2,37881,37894,37893,38001,37976,37826,37952) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@LICHKING*100,37893*100,37952*100,3795201) AND `source_type`=9;

INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BUNNY,0,0,1,38,0,100,0,1,1,300000,300000,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lich King Stun Bunny - On Data Set - Set Data"),
(@BUNNY,0,1,2,61,0,100,0,0,0,0,0,11,70583,0,0,0,0,0,12,1,0,0,0, 0, 0, 0,"Lich King Stun Bunny - On Data Set - Cast Lich King Stun"),
(@BUNNY,0,2,0,61,0,100,0,0,0,0,0,12,@LICHKING,1,300000,0,0,0,8,0,0,0,4835.083, -586.7692, 162.0051, 2.804995,"Lich King Stun Bunny - On Data Set - Summon The Lich Kin"),
(@BUNNY,0,3,4,38,0,100,0,2,2,0,0,11,70571,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lich King Stunn Bunny - On Data Set - Cast Holy Zone Visual"),
(@BUNNY,0,4,0,61,0,100,0,0,0,0,0,11,70603,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lich King Stunn Bunny - On Data Set - Cast Summon Light's Vengeance"),
(@BUNNY,0,5,0,38,0,100,0,3,3,0,0,28,70571,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lich King Stunn Bunny - On Data Set - Remove Aura Holy Zone Visual"),
(@BUNNY2,0,0,0,8,0,100,0,70614,0,10000,15000,11,70617,0,0,0,0,0,1,0,0,0,0,0,0,0,"AOD Impact Bunny - On Spell Hit(AoD Special)- Cast Summon Ghoul"),
(@BUNNY2,0,1,0,8,0,100,0,70743,0,10000,15000,11,70617,0,0,0,0,0,1,0,0,0,0,0,0,0,"AOD Impact Bunny - On Spell Hit(AoD Special - Vegard)- Cast Summon Ghoul"),
(@LICHKING,0,0,0,54,0,100,0,0,0,0,0,53,0,@LICHKING,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - On Just Summoned - Start WP"),
(@LICHKING,0,1,0,40,0,100,0,11,@LICHKING,0,0,80,@LICHKING*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - On Reached WP11 - Run Script"),
(37826,0,0,1,11,0,100,0,0,0,0,0,12,37827,8,0,0,0,0,8,0,0,0,4812.009, -586.2327, 162.57,0,"Light's Vengeance - On Spawn - Spawn Light's Vengeance Vehicle Bunny"),
(37826,0,1,2,61,0,100,0,0,0,0,0,12,37952,8,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance - On Spawn - Spawn Light's Vengeance Vehicle Bunny 2"),
(37952,0,0,0,38,0,100,1,1,1,0,0,80,3795200,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - On Data Set - Run Script"),
(37952,0,1,2,40,0,100,0,8,37952,0,0,80,3795201,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - On Reached WP8 - Run Script 2"),
(37826,0,2,0,61,0,100,0,0,0,0,0,11,46598,0,0,0,0,0,19,37952,0,0,0,0,0,0,"Light's Vengeance - On Spawn - Cast Ride Vehicle Hardcoded"),
(37827,0,0,1,38,0,100,0,1,1,0,0,11,50630,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny - On Data Set - Cast Eject All Passengers"),
(37827,0,1,2,61,0,100,0,0,0,0,0,11,70595,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny - On Data Set - Cast Light's Vengeance Throw"),
(37827,0,2,0,61,0,100,0,0,0,0,0,70,300,0,0,0,0,0,20,201937,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny - On Data Set - Despawn Light's Vengence"),
(37881,0,0,1,54,0,100,0,0,0,0,0,11,7398,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Just Summoned - Cast Rebirth"),
(37881,0,1,0,61,0,100,0,0,0,0,0,11,70782,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Just Summoned - Cast Ghoul's Touch"),
(37881,0,2,0,8,0,100,0,70790,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Spellhit(Zap Ghouls) - Die"),
(37894,0,0,0,8,0,100,0,70643,0,0,0,11,70644,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard Bunny - On Spellhit(Zap Vegard Bunny) - Cast Summon Vegard"),
(37893,0,0,0,54,0,100,0,0,0,0,0,80,3789300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Just Summoned - Run Script"),
(37893,0,1,2,8,0,100,0,70792,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Spell Hit(Kill Vegard) - Die"),
(37893,0,2,0,61,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Spell Hit(Kill Vegard) - Despawn"),
(38001,0,0,0,38,0,100,0,4,4,0,0,11,70862,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Bunny 2 - On Data Set - Cast Summon Vegard Skeleton"),
(38001,0,1,2,38,0,100,0,1,1,0,0,11,70967,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Bunny 2 - On Data Set- Cast Summon Light's Vengeance III"),
(38001,0,2,0,61,0,100,0,0,0,0,0,11,70970,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Bunny 2 - On Data Set- Cast Hammer Shield"),
(38001,0,3,0,38,0,100,0,2,2,0,0,28,70970,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Bunny 2 - On Data Set- Remove Aura Hammer Shield"),
(38001,0,4,0,38,0,100,0,3,3,0,0,11,70894,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Bunny 2 - On Data Set- Cast Summon Light's Vengeance II"),
(37976,0,0,1,54,0,100,0,0,0,0,0,11,7398,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Just Summoned - Cast Rebirth"),
(37976,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Just Summoned - Say Line 0"),
(37976,0,2,3,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Death - Say Line 1"),
(37976,0,3,4,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,38001,0,0,0,0,0,0,"Vegard the Unforgiven - On Death - Say Line Set Data 2 2 on Light's Vengeance Bunny 2"),
(37976,0,4,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,201937,0,0,0,0,0,0,"Vegard the Unforgiven - On Death - Say Line Set Data 1 1 on Light's Vengeance"),
(37976,0,5,0,9,0,100,0,0,10,20000,35000,11,70866,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Range - Cast Shadow Blast"),
(37976,0,6,0,2,0,100,0,0,30,15000,25000,11,70886,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Less than 30% HP - Cast Vegard's Thirst"),
(37976,0,7,0,0,0,100,0,3000,7000,25000,35000,11,71003,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vegard the Unforgiven - IC - Cast Vegard's Vegard's Touch"),
(37976,0,8,9,7,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Evade - Say Line 2"),
(37976,0,9,0,61,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Evade - Despawn"),
(@LICHKING*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 0"), -- 16:59:11.266
(@LICHKING*100,9,1,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 1"), -- 16:59:18.641
(@LICHKING*100,9,2,0,0,0,100,0,4000,4000,0,0,11,70590,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 1"), -- 16:59:22.156
(@LICHKING*100,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,37827,0,0,0,0,0,0,"The Lich King - Script - Set Data on Light's Vengeance Vehicle Bunny"), -- 16:59:22.156
(@LICHKING*100,9,4,0,0,0,100,0,3000,3000,0,0,45,2,2,0,0,0,0,19,@BUNNY,0,0,0,0,0,0,"The Lich King - Script - Set Data on Light's Vengeance Vehicle Bunny"), -- 16:59:25.375
(@LICHKING*100,9,5,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 2"), -- 16:59:28.344
(@LICHKING*100,9,6,0,0,0,100,0,8000,8000,0,0,11,70612,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Cast Summon Ghouls"), -- 16:59:36.687
(@LICHKING*100,9,7,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 3"), -- 16:59:40.484
(@LICHKING*100,9,8,0,0,0,100,0,7000,7000,0,0,11,70643,0,0,0,0,0,19,37894,0,0,0,0,0,0,"The Lich King - Script - Cast Zap Vegard Bunny"), -- 16:59:47.672
(@LICHKING*100,9,9,0,0,0,100,0,7000,7000,0,0,5,397,0,0,0,0,0,21,100,0,0,0,0,0,0,"The Lich King - Script - Play Emote OneShotPointNoSheathe(397)"), -- 16:59:54.906
(@LICHKING*100,9,10,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 4"), -- 16:59:55.031
(@LICHKING*100,9,11,0,0,0,100,0,2000,2000,0,0,11,70653,0,0,0,0,0,21,50,0,0,0,0,0,0,"The Lich King - Script - Cast Lich King Zap Player"), -- 17:00:00.812
(@LICHKING*100,9,12,0,0,0,100,0,3000,3000,0,0,11,70673,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Cast Lich King Despawn"), -- 17:00:00.812
(@LICHKING*100,9,13,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Despawn"), -- 17:00:00.812
(37893*100,9,0,0,0,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - Script - Set Unit Flags"), 
(37893*100,9,1,0,0,0,100,0,0,0,0,0,11,70692,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - Script - Cast Shield of the Lich King"), 
(37893*100,9,2,0,0,0,100,0,3000,3000,0,0,11,70737,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - Script - Cast Vegard Summon Ghouls"), 
(37893*100,9,3,0,0,0,100,0,13000,13000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - Script - Say Line 0"), -- 17:00:15.609
(37893*100,9,4,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - Script - Say Line 1"), -- 17:00:15.609
(37952*100,9,0,0,0,0,100,0,0,0,0,0,11,70785,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script - Cast Holy Bomb Visual"), 
(37952*100,9,1,0,0,0,100,0,0,0,0,0,11,70789,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script - Cast Zap Ghouls Aura"), 
(37952*100,9,2,0,0,0,100,0,0,0,0,0,53,0,37952,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script - Start WP"),
(3795201,9,0,0,0,0,100,0,0,0,0,0,11,70792,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Cast Kill Vegard"),
(3795201,9,1,0,0,0,100,0,0,0,0,0,11,70786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Cast Holy Bomb Explosion"),
(3795201,9,2,0,0,0,100,0,0,0,0,0,12,38001,1,300000,0,0,0,8,0,0,0,4812.009, -586.2327, 162.57, 2.75762,'Lights Vengeance Vehicle Bunny 2 - Script 2 - Summon Lights Vengeance Bunny 2'),
(3795201,9,3,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,38001,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Set Data 3 3 on Light's Vengeance Bunny 2"),
(3795201,9,4,0,0,0,100,0,0,0,0,0,41,120000,0,0,0,0,0,19,37826,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Despawn Light's Vengeance"),
(3795201,9,5,0,0,0,100,0,0,0,0,0,41,120000,0,0,0,0,0,19,37827,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Despawn Light's Vengeance Vehicle Bunny"),
(3795201,9,6,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Despawn");


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND`SourceEntry`=@TRIGG;

INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@TRIGG,2,0,9,0,@QUEST,0,0,0,0,'','Trigger only activates if player is on and has not completed The Sacred and the Corrupt'),
(22,1,@TRIGG,2,0,2,0,@LIGHTSVENGENCE,1,0,1,0,'','Trigger does not activate if player already has lights vengence');
	
DELETE FROM `creature` WHERE `id`IN(@BUNNY,@BUNNY2,37826,37894);

INSERT INTO `creature`(`guid`, `id`, `map`, `spawnMask`, `phaseMask`,`position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, @BUNNY, 571, 1, 1, 4798.7, -639.529, 160.5693, 4.34587, 120, 0, 0), 
(@CGUID+1, @BUNNY2, 571, 1, 1, 4848.793, -601.8837, 157.445, 4.258604, 120, 0, 0), 
(@CGUID+2, @BUNNY2, 571, 1, 1, 4845.159, -576.0278, 159.9401, 5.532694, 120, 0, 0), 
(@CGUID+3, @BUNNY2, 571, 1, 1, 4826.658, -555.1059, 161.3158, 4.625123, 120, 0, 0), 
(@CGUID+4, @BUNNY2, 571, 1, 1, 4829.419, -629.3629, 157.6456, 3.612832, 120, 0, 0), 
(@CGUID+5, @BUNNY2, 571, 1, 1, 4779.228, -587.1545, 162.1223, 4.537856, 120, 0, 0), 
(@CGUID+6, @BUNNY2, 571, 1, 1, 4782.333, -572.7118, 161.8683, 5.585053, 120, 0, 0), 
(@CGUID+7, @BUNNY2, 571, 1, 1, 4796.73, -622.5868, 159.9098, 2.356194, 120, 0, 0), 
(@CGUID+8, @BUNNY2, 571, 1, 1, 4815.688, -625.3021, 158.6156, 4.066617, 120, 0, 0), 
(@CGUID+9, @BUNNY2, 571, 1, 1, 4792.949, -603.3854, 160.3281, 2.740167, 120, 0, 0), 
(@CGUID+10, @BUNNY2, 571, 1, 1, 4795.549, -631.2952, 160.2526, 1.361357, 120, 0, 0), 
(@CGUID+11, @BUNNY2, 571, 1, 1, 4804.116, -640.8143, 160.1202, 2.373648, 120, 0, 0), 
(@CGUID+12, @BUNNY2, 571, 1, 1, 4843.747, -587.0625, 159.7272, 0.9250245, 120, 0, 0), 
(@CGUID+13, @BUNNY2, 571, 1, 1, 4789.024, -611.7726, 160.3697, 0, 120, 0, 0), 
(@CGUID+14, @BUNNY2, 571, 1, 1, 4806.465, -618.2396, 159.5483, 5.445427, 120, 0, 0), 
(@CGUID+15, @BUNNY2, 571, 1, 1, 4845.673, -593.6736, 159.1436, 3.874631, 120, 0, 0), 
(@CGUID+16, @BUNNY2, 571, 1, 1, 4788.442, -639.3229, 162.3155, 1.37881, 120, 0, 0), 
(@CGUID+17, @BUNNY2, 571, 1, 1, 4803.761, -610.7188, 159.545, 4.24115, 120, 0, 0), 
(@CGUID+18, @BUNNY2, 571, 1, 1, 4793.397, -570.8108, 160.8941, 3.682645, 120, 0, 0), 
(@CGUID+19, @BUNNY2, 571, 1, 1, 4809.697, -642.8246, 159.2958, 2.007129, 120, 0, 0), 
(@CGUID+20, @BUNNY2, 571, 1, 1, 4790.142, -624.1771, 159.6133, 0.9773844, 120, 0, 0), 
(@CGUID+21, @BUNNY2, 571, 1, 1, 4810.049, -609.3768, 159.4645, 0, 120, 0, 0), 
(@CGUID+22, @BUNNY2, 571, 1, 1, 4800.022, -618.3073, 159.7944, 3.508112, 120, 0, 0), 
(@CGUID+23, @BUNNY2, 571, 1, 1, 4854.851, -593.2795, 157.3008, 4.625123, 120, 0, 0), 
(@CGUID+24, @BUNNY2, 571, 1, 1, 4759.741, -587.8351, 164.6121, 0, 120, 0, 0), 
(@CGUID+25, @BUNNY2, 571, 1, 1, 4822.641, -641.3472, 157.8503, 3.944444, 120, 0, 0), 
(@CGUID+26, @BUNNY2, 571, 1, 1, 4825.955, -637.9774, 157.6442, 5.340707, 120, 0, 0), 
(@CGUID+27, @BUNNY2, 571, 1, 1, 4809.641, -555.4688, 162.6923, 0.715585, 120, 0, 0), 
(@CGUID+28, @BUNNY2, 571, 1, 1, 4837.163, -576.5104, 160.5024, 5.078908, 120, 0, 0), 
(@CGUID+29, @BUNNY2, 571, 1, 1, 4809.902, -635.441, 159.2038, 1.151917, 120, 0, 0), 
(@CGUID+30, @BUNNY2, 571, 1, 1, 4842.37, -621.6962, 157.5227, 2.879793, 120, 0, 0), 
(@CGUID+31, @BUNNY2, 571, 1, 1, 4817.919, -551.9774, 162.0828, 3.036873, 120, 0, 0), 
(@CGUID+32, @BUNNY2, 571, 1, 1, 4851.638, -585.6007, 158.117, 2.059489, 120, 0, 0), 
(@CGUID+33, @BUNNY2, 571, 1, 1, 4809.817, -614.8125, 159.2753, 2.199115, 120, 0, 0), 
(@CGUID+34, @BUNNY2, 571, 1, 1, 4778.958, -567.7934, 162.0411, 3.647738, 120, 0, 0), 
(@CGUID+35, @BUNNY2, 571, 1, 1, 4763.713, -569.2257, 163.7682, 3.839724, 120, 0, 0), 
(@CGUID+36, @BUNNY2, 571, 1, 1, 4833.483, -635.0799, 157.4865, 4.834562, 120, 0, 0), 
(@CGUID+37, @BUNNY2, 571, 1, 1, 4790.34, -607.0833, 160.2565, 3.525565, 120, 0, 0), 
(@CGUID+38, @BUNNY2, 571, 1, 1, 4814.297, -619.2708, 158.7552, 0.715585, 120, 0, 0), 
(@CGUID+39, @BUNNY2, 571, 1, 1, 4798.659, -602.0208, 159.8221, 2.565634, 120, 0, 0), 
(@CGUID+40, @BUNNY2, 571, 1, 1, 4792.533, -591.684, 160.2542, 4.206244, 120, 0, 0), 
(@CGUID+41, @BUNNY2, 571, 1, 1, 4789.622, -579.4358, 161.0213, 4.520403, 120, 0, 0), 
(@CGUID+42, @BUNNY2, 571, 1, 1, 4797.168, -577.1268, 160.2595, 2.478368, 120, 0, 0), 
(@CGUID+43, @BUNNY2, 571, 1, 1, 4800.604, -547.7327, 164.9199, 0.715585, 120, 0, 0), 
(@CGUID+44, @BUNNY2, 571, 1, 1, 4784.508, -609.382, 161.722, 0, 120, 0, 0), 
(@CGUID+45, @BUNNY2, 571, 1, 1, 4776.268, -596.5695, 162.6325, 2.059489, 120, 0, 0), 
(@CGUID+46, @BUNNY2, 571, 1, 1, 4804.434, -635.9236, 159.8547, 0, 120, 0, 0), 
(@CGUID+47, @BUNNY2, 571, 1, 1, 4772.837, -575.5347, 162.7558, 1.64061, 120, 0, 0), 
(@CGUID+48, @BUNNY2, 571, 1, 1, 4797.148, -583.2952, 159.8615, 3.595378, 120, 0, 0), 
(@CGUID+49, @BUNNY2, 571, 1, 1, 4806.011, -623.4809, 159.5464, 2.740167, 120, 0, 0), 
(@CGUID+50, @BUNNY2, 571, 1, 1, 4848.793, -601.8837, 157.445, 4.258604, 120, 0, 0),
(@CGUID+51, 37826, 571, 1, 1, 4798.7, -639.529, 160.5693, 4.34587, 120, 0, 0),
(@CGUID+52, 37894, 571, 1, 1, 4812.028, -586.2222, 162.5564, 2.6529, 120, 0, 0);

DELETE FROM `waypoints` WHERE `entry`IN(@LICHKING,37952);
INSERT INTO `waypoints`(`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@LICHKING, 1, 4836.363, -586.9203, 161.9295, 'The Lichking'),
(@LICHKING, 2, 4835.365, -586.868, 161.9295, 'The Lichking'),
(@LICHKING, 3, 4834.092, -586.4228, 162.2705, 'The Lichking'),
(@LICHKING, 4, 4828.495, -584.4644, 163.6633, 'The Lichking'),
(@LICHKING, 5, 4826.363, -583.7183, 164.6168, 'The Lichking'),
(@LICHKING, 6, 4825.221, -583.3187, 164.9072, 'The Lichking'),
(@LICHKING, 7, 4823.253, -582.6302, 164.3474, 'The Lichking'),
(@LICHKING, 8, 4821.647, -582.0682, 163.8447, 'The Lichking'),
(@LICHKING, 9, 4818.997, -581.1409, 163.5256, 'The Lichking'),
(@LICHKING, 10, 4814.02, -579.3994, 162.4412, 'The Lichking'),
(@LICHKING, 11, 4814.02, -579.3994, 162.4412, 'The Lichking'),
(37952, 1, 4798.7, -639.529, 160.5693, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 2, 4801.055, -634.4948, 166.6768, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 3, 4797, -618.7934, 171.4821, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 4, 4794.907, -597.2153, 175.0993, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 5, 4796.127, -576.5347, 175.0993, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 6, 4808.424, -570.3871, 175.0993, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 7, 4818.083, -578.1805, 175.0993, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 8, 4812.49, -586.9028, 175.0993, 'Lights Vengeance Vehicle Bunny 2');

DELETE FROM `creature_text` WHERE `entry` IN(37976,37893,@LICHKING);
INSERT INTO `creature_text`(`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(37976, 0, 0, 'Fear not, master. I shall rend the flesh of your enemy!', 12, 0, 100, 0, 0, 17077, 37657, 'Vegard the Unforgiven'),
(37976, 1, 0, 'Master... I have... failed.', 12, 0, 100, 0, 0, 17076, 37656, 'Vegard the Unforgiven'),
(37976, 2, 0, 'It is done, master.', 12, 0, 100, 0, 0, 17075, 37655, 'Vegard the Unforgiven'),
(37893, 0, 0, 'I hear and obey, master...', 12, 0, 100, 0, 0, 17073, 0, 'Vegard the Unforgiven'),
(37893, 1, 0, 'The enemy shall suffer greatly, master!', 12, 0, 100, 0, 0, 17074, 37651, 'Vegard the Unforgiven'),
(@LICHKING, 0, 0, 'So predictable...', 12, 0, 100, 396, 0, 17252, 37506, 'The Lich King'),
(@LICHKING, 1, 0, 'Did you truly expect to fulfill Mograine''s task unopposed?', 12, 0, 100, 6, 0, 17253, 37507, 'The Lich King'),
(@LICHKING, 2, 0, 'You both shall suffer as his father does...', 12, 0, 100, 396, 0, 17254, 37508, 'The Lich King'),
(@LICHKING, 3, 0, '...in eternal unrest!', 12, 0, 100, 0, 0, 17255, 37509, 'The Lich King'),
(@LICHKING, 4, 0, 'Die well, fool.', 12, 0, 100, 397, 0, 17256, 37510, 'The Lich King');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(70590,70595,70614,70643,70612,70790,70792,70743);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 70590, 0, 0, 31, 0, 3, 37826, 0, 0, 0, 0, '', 'Lich King Repel Hammer targets Lights Vengence'),
(13, 1, 70590, 0, 1, 31, 0, 3, 37827, 0, 0, 0, 0, '', 'Lich King Repel Hammer targets Lights Vengeance Vehicle Bunny'),
(13, 1, 70595, 0, 1, 31, 0, 3, @BUNNY, 0, 0, 0, 0, '', 'Lich King Repel Hammer targets Lich King Stun Bunny'),
(13, 1, 70792, 0, 0, 31, 0, 3, 37893, 0, 0, 0, 0, '', 'Kill Vegard targets Vegard the Unforgiven'),
(13, 1, 70614, 0, 0, 31, 0, 3, @BUNNY2, 0, 0, 0, 0, '', 'AoD Special targets AoD Impact Bunny'),
(13, 1, 70790, 0, 0, 31, 0, 3, 37881, 0, 0, 0, 0, '', 'Zap Ghouls targets Wretched Ghoul'),
(13, 1, 70643, 0, 0, 31, 0, 3, 37894, 0, 0, 0, 0, '', 'Zap Vegard Bunny targets Vegard Bunny'),
(13, 1, 70743, 0, 0, 31, 0, 3, @BUNNY2, 0, 0, 0, 0, '', 'AoD Special - Vegard targets AoD Impact Bunny');

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE`entry` IN(201844,201922,201937);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(201844,201922,201937) AND `source_type`=1;

INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(201922,1,0,1,70,0,100,1,2,0,0,0,45,4,4,0,0,0,0,19,38001,0,0,0,0,0,0,"Lights Vengeance - On State Changed - Set Data 4 4 on Lights Vengeance Bunny 2"),
(201922,1,1,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,38001,0,0,0,0,0,0,"Lights Vengeance - On State Changed Set Data 1 1 on Light's Vengence Bunny 2"),
(201844,1,0,1,70,0,100,1,2,0,0,0,45,1,1,0,0,0,0,19,37952,0,0,0,0,0,0,"Lights Vengeance - On State Changed - Set Data on Lights Vengeance Vehicle Bunny 2"),
(201844,1,1,0,61,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,@BUNNY,0,0,0,0,0,0,"Lights Vengeance - On State Changed Set Data 3 3 on Lich King Stun Bunny"),
(201937,1,1,0,11,0,100,0,0,0,0,0,104,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lights Vengeance - On Spawn - Set Non Selectable"),
(201937,1,2,0,38,0,100,0,1,1,0,0,104,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lights Vengeance - On Data Set - Set Selectable");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=70653;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(70653, 70966, 1, 'Lich King Zap Player - Knockback 50 No Log');
UPDATE `creature_template` SET `flags_extra`=0 WHERE  `entry`=37826;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(37832,37878);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 37832, 0, 0, 29, 1, 37857, 100, 0, 1, 0, 0, '', 'Lich King Stun Bunny only Trigger if there is no spawn of the Lich King within 100 Yards'),
(22, 1, 37832, 0, 0, 29, 1, 37893, 100, 0, 1, 0, 0, '', 'Lich King Stun Bunny only Trigger if there is no spawn of Vegard within 100 Yards'),
(22, 1, 37832, 0, 0, 29, 1, 37976, 100, 0, 1, 0, 0, '', 'Lich King Stun Bunny only Trigger if there is no spawn of Vegard within 100 Yards'),
(22, 1, 37832, 0, 0, 30, 1, 201922, 100, 0, 1, 0, 0, '', 'Lich King Stun Bunny only Trigger if there is no spawn of Lights Vengence within 100 Yards'),
(22, 1, 37832, 0, 0, 30, 1, 201844, 100, 0, 1, 0, 0, '', 'Lich King Stun Bunny only Trigger if there is no spawn of Lights Vengence within 100 Yards'),
(22, 1, 37878, 0, 0, 29, 1, 37881, 2, 0, 1, 0, 0, '', 'AOD Impact Bunny only Trigger if there is no spawn of Wrethed Ghoul within 2 yards'),
(22, 2, 37878, 0, 0, 29, 1, 37881, 2, 0, 1, 0, 0, '', 'AOD Impact Bunny only Trigger if there is no spawn of Wrethed Ghoul within 2 yards');
DELETE FROM `creature_questender` WHERE  `id`=37120 AND `quest`=24545;
DELETE FROM `gameobject` WHERE  `guid`=100025;

DELETE FROM `smart_scripts` WHERE `entryorguid`=37120 AND `source_type`=0 AND `id`>1;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(3712000,3780100) AND `source_type`=9;
UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`IN(37702,37801,37814,38191);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(37702,37801,37814,38191) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(37120, 0, 2, 3, 38, 0, 100, 0, 1, 1, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Data Set - Set NPC Flags'), -- 23:45:40.047
(37120, 0, 3, 7, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3712000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Data Set - Run Script'),
(37120, 0, 4, 5, 40, 0, 100, 0, 1, 37120, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.969026, 'Highlord Darion Mograine - On Reached WP1 - Set Orientation'),
(37120, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 35000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Reached WP1 - Pause WP'),
(37120, 0, 6, 0, 40, 0, 100, 0, 2, 37120, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.448623, 'Highlord Darion Mograine - On Reached WP2 - Set Orientation'),
(38191, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 37801, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Data Set - Set NPC Flags'), -- 23:45:40.047
(37702, 0, 0, 0, 8, 0, 100, 0, 70471, 0, 0, 0, 11, 70508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runeforge Bunny - On Spellhit (Mograine Forge Beam) - Cast Summon Shadows Edge Bunny'), 
(37702, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 70367, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runeforge Bunny - On Data Set 1 1 - Cast Forge Flame Blue'), 
(37814, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 46598, 0, 0, 0, 0, 0, 19, 37801, 0, 0, 0, 0, 0, 0, 'Shadows Edge Axe Bunny - On Spawn - Cast Ride Vehicle Hardcoded'), 
(37801, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, 3780100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - On Spawn - Run Script'), 
(3780100, 9, 0, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:45:56.391
(3780100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:45:57.610
(3780100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:45:58.813
(3780100, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:46:00.016
(3780100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:46:01.235
(3780100, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:46:02.453
(3780100, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70504, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Shadows Edge Aura'), -- 23:46:03.656
(3780100, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 38191, 1, 24000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Summon Shadows Edge'), 
(3780100, 9, 8, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 53, 0, 37801, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Start WP'), -- 23:46:06.110
(3780100, 9, 9, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 11, 70529, 0, 0, 0, 0, 0, 19, 38191, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Shadows Edge Axe'), -- 23:46:19.438
(3780100, 9, 10, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Despawn'), 
(3712000, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 0'), -- 23:45:42.594
(3712000, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 53, 0, 37120, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Start WP'), -- 23:45:42.594
(3712000, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 11, 70471, 0, 0, 0, 0, 0, 19, 37702, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Mograine Forge Beam'), -- 23:45:49.906
(3712000, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 1'), -- 23:45:50.125
(3712000, 9, 4, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 2'), -- 23:46:07.125
(3712000, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 37702, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Set Data on Runeforge Bunny'), -- 23:46:08.000
(3712000, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 3'), -- 23:46:13.156
(3712000, 9, 7, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 11, 71310, 0, 0, 0, 0, 0, 19, 38191, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Pull Shadows Edge'), -- 23:46:25.094 
(3712000, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 19, 38191, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Set NPC Flags'), -- 23:46:25.094 
(3712000, 9, 9, 0, 0, 0, 100, 0, 150, 150, 0, 0, 11, 43671, 0, 0, 0, 0, 0, 19, 38191, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Ride Vehicle'), -- 23:46:25.110 
(3712000, 9, 10, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 71385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Mograine Axe Timer Aura'), -- 23:46:26.328 
(3712000, 9, 11, 0, 0, 0, 100, 0, 0, 1000, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Mograine Axe Timer Aura'); -- 23:46:26.328 


DELETE FROM `creature_text` WHERE `entry`in(37120);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(37120, 0, 0, 'So, it has begun....', 12, 0, 100, 396, 0, 16834, 37248, 'Highlord Darion Mograine to Player'),
(37120, 1, 0, 'Behold! The binding of sacred and corrupt; the forging of Shadow''s Edge, a weapon of untold potential!', 12, 0, 100, 0, 0, 16835, 37249, 'Highlord Darion Mograine to Player'),
(37120, 2, 0, 'Bend it to your will, and you shall wield unspeakable power!', 12, 0, 100, 396, 0, 16836, 37250, 'Highlord Darion Mograine to Player'),
(37120, 3, 0, 'Fail, and your soul shall forever be its slave.', 12, 0, 100, 396, 0, 16837, 37251, 'Highlord Darion Mograine to Player');

DELETE FROM `waypoints` WHERE `entry`IN(37120,37801);
INSERT INTO `waypoints`(`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(37120, 1, -67.52431, 2161.191, 30.65416, 'Highlord Darion Mograine'),
(37120, 2, -69.84028, 2155.585, 30.65416, 'Highlord Darion Mograine'),
(37801, 1, -62.15451, 2157.793, 31.59859, 'Shadows Edge Bunny'),
(37801, 2, -69.53472, 2159.691, 31.79306, 'Shadows Edge Bunny');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`IN(5650);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 5650, 2, 0, 9, 0, 24545, 0, 0, 0, 0, 0, '', 'Trigger only activates if player is on and has not completed The Sacred and the Corrupt'),
(22, 1, 5650, 2, 0, 2, 0, 49869, 1, 0, 1, 0, 0, '', 'Trigger does not activate if player already has lights vengence');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(70529,71310,70471);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 70529, 0, 0, 31, 0, 3, 38191, 0, 0, 0, 0, '', 'Summon Shadows Edge Axe targets Shadows Edge'),
(13, 3, 71310, 0, 0, 31, 0, 3, 38191, 0, 0, 0, 0, '', 'Pull Shadows Edge targets Shadows Edge'),
(13, 3, 70471, 0, 0, 31, 0, 3, 37702, 0, 0, 0, 0, '', ' Mograine Forge Beam targets Runeforge Bunny');

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE`entry` IN(201742);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(201742) AND `source_type`=1;

INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(201742,1,0,0,20,0,100,0,24545,0,0,0,45,1,1,0,0,0,0,19,37120,0,0,0,0,0,0,"RuneForge - On Quest Reward (the Sacred and the Corrupt) - Set Data 1 1 on Highlord Darion Mograine");
--
UPDATE `waypoint_data` SET `move_type`=1 WHERE  `id` IN (579650,1112180,992280,992270,992300);
-- Add missing spawns Rook and Corvax
SET @GUID := 69711;
DELETE FROM `creature` WHERE `guid` IN (@GUID+0, @GUID+1) AND `id` IN (22843, 22842);
INSERT INTO `creature` (`guid`, `id`, `map`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `curhealth`) VALUES
(@GUID + 0, 22843, 530, 21119, -237.2198, 5444.96, 31.853, 2.59318, 4059),
(@GUID + 1, 22842, 530, 21119, -254.8032, 5443.792, 30.77559, 0.6263401, 50);

-- Update InhabitType for flying
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=22843;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=22842;

-- Pathing for Rook Entry: 22843 'TDB FORMAT' 
SET @NPC := 69711;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-253.4223,`position_y`=5430.909,`position_z`=28.92926 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-253.4223,5430.909,28.92926,0,0,1,0,100,0),
(@PATH,2,-252.2368,5429.647,28.75794,0,0,1,0,100,0),
(@PATH,3,-246.0865,5428.435,29.54239,0,0,1,0,100,0),
(@PATH,4,-239.4053,5431.095,29.54241,0,0,1,0,100,0),
(@PATH,5,-235.5483,5436.207,30.90352,0,0,1,0,100,0),
(@PATH,6,-235.0203,5442.249,30.87573,0,0,1,0,100,0),
(@PATH,7,-238.777,5445.627,32.07018,0,0,1,0,100,0),
(@PATH,8,-246.5504,5445.43,30.82018,0,0,1,0,100,0),
(@PATH,9,-254.3803,5440.281,29.67928,0,0,1,0,100,0),
(@PATH,10,-255.2896,5432.612,28.92926,0,0,1,0,100,0);
-- 0x1C39204240164EC000002C00001A411E .go -253.4223 5430.909 28.92926

-- Pathing for Corvax Entry: 22842 'TDB FORMAT' 
SET @NPC := 69712;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-231.4784,`position_y`=5442.248,`position_z`=29.75438 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-231.4784,5442.248,29.75438,0,0,1,0,100,0),
(@PATH,2,-231.9071,5441.805,29.40595,0,0,1,0,100,0),
(@PATH,3,-233.5468,5436.123,30.58605,0,0,1,0,100,0),
(@PATH,4,-235.9648,5433.313,31.33606,0,0,1,0,100,0),
(@PATH,5,-245.6634,5430.377,32.44696,0,0,1,0,100,0),
(@PATH,6,-254.214,5432.43,32.50253,0,0,1,0,100,0),
(@PATH,7,-257.6299,5440.645,31.36549,0,0,1,0,100,0),
(@PATH,8,-250.052,5446.799,30.14325,0,0,1,0,100,0),
(@PATH,9,-244.9603,5449.014,29.67106,0,0,1,0,100,0),
(@PATH,10,-237.6145,5448.882,29.75438,0,0,1,0,100,0);
-- 0x1C39204240164E8000002C00001A411E .go -231.4784 5442.248 29.75438
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry` IN (16766,16610,5188,5189,5190,5191,5049);
UPDATE `creature_template` SET `gossip_menu_id`=9832 WHERE  `entry` IN (5188,5049,5191);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16766,16610,5188,5189,5190,5191,5049);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16766, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 10 Selected - Close Gossip'),
(16766, 0, 0, 10, 62, 0, 100, 0, 9832, 1, 0, 0, 11, 54974, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 1 Selected - Cast \'Create Blood Knight Tabard\''),
(16766, 0, 1, 10, 62, 0, 100, 0, 9832, 2, 0, 0, 11, 54976, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 2 Selected - Cast \'Create Tabard of the Hand\''),
(16766, 0, 2, 10, 62, 0, 100, 0, 9832, 3, 0, 0, 11, 55008, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 3 Selected - Cast \'Create Tabard of the Protector\''),
(16766, 0, 3, 10, 62, 0, 100, 0, 9832, 4, 0, 0, 11, 54977, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 4 Selected - Cast \'Create Green Trophy Tabard of the Illidari\''),
(16766, 0, 4, 10, 62, 0, 100, 0, 9832, 5, 0, 0, 11, 54982, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 5 Selected - Cast \'Create Purple Trophy Tabard of the Illidari\''),
(16766, 0, 5, 10, 62, 0, 100, 0, 9832, 6, 0, 0, 11, 62768, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 6 Selected - Cast \'Create Tabard of Summer Skies\''),
(16766, 0, 6, 10, 62, 0, 100, 0, 9832, 7, 0, 0, 11, 62769, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 7 Selected - Cast \'Create Tabard of Summer Flames\''),
(16766, 0, 7, 10, 62, 0, 100, 0, 9832, 8, 0, 0, 11, 58194, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 8 Selected - Cast \'Create Loremaster\'s Colors\''),
(16766, 0, 8, 10, 62, 0, 100, 0, 9832, 9, 0, 0, 11, 58224, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 9 Selected - Cast \'Create Tabard of the Explorer\''),
(16766, 0, 9, 10, 62, 0, 100, 0, 9832, 10, 0, 0, 11, 55006, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Issca - On Gossip Option 10 Selected - Cast \'Create Tabard of the Achiever\''),
(16610, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 10 Selected - Close Gossip'),
(16610, 0, 0, 10, 62, 0, 100, 0, 9832, 1, 0, 0, 11, 54974, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 1 Selected - Cast \'Create Blood Knight Tabard\''),
(16610, 0, 1, 10, 62, 0, 100, 0, 9832, 2, 0, 0, 11, 54976, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 2 Selected - Cast \'Create Tabard of the Hand\''),
(16610, 0, 2, 10, 62, 0, 100, 0, 9832, 3, 0, 0, 11, 55008, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 3 Selected - Cast \'Create Tabard of the Protector\''),
(16610, 0, 3, 10, 62, 0, 100, 0, 9832, 4, 0, 0, 11, 54977, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 4 Selected - Cast \'Create Green Trophy Tabard of the Illidari\''),
(16610, 0, 4, 10, 62, 0, 100, 0, 9832, 5, 0, 0, 11, 54982, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 5 Selected - Cast \'Create Purple Trophy Tabard of the Illidari\''),
(16610, 0, 5, 10, 62, 0, 100, 0, 9832, 6, 0, 0, 11, 62768, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 6 Selected - Cast \'Create Tabard of Summer Skies\''),
(16610, 0, 6, 10, 62, 0, 100, 0, 9832, 7, 0, 0, 11, 62769, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 7 Selected - Cast \'Create Tabard of Summer Flames\''),
(16610, 0, 7, 10, 62, 0, 100, 0, 9832, 8, 0, 0, 11, 58194, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 8 Selected - Cast \'Create Loremaster\'s Colors\''),
(16610, 0, 8, 10, 62, 0, 100, 0, 9832, 9, 0, 0, 11, 58224, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 9 Selected - Cast \'Create Tabard of the Explorer\''),
(16610, 0, 9, 10, 62, 0, 100, 0, 9832, 10, 0, 0, 11, 55006, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kredis - On Gossip Option 10 Selected - Cast \'Create Tabard of the Achiever\''),
(5190, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 10 Selected - Close Gossip'),
(5190, 0, 0, 10, 62, 0, 100, 0, 9832, 1, 0, 0, 11, 54974, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 1 Selected - Cast \'Create Blood Knight Tabard\''),
(5190, 0, 1, 10, 62, 0, 100, 0, 9832, 2, 0, 0, 11, 54976, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 2 Selected - Cast \'Create Tabard of the Hand\''),
(5190, 0, 2, 10, 62, 0, 100, 0, 9832, 3, 0, 0, 11, 55008, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 3 Selected - Cast \'Create Tabard of the Protector\''),
(5190, 0, 3, 10, 62, 0, 100, 0, 9832, 4, 0, 0, 11, 54977, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 4 Selected - Cast \'Create Green Trophy Tabard of the Illidari\''),
(5190, 0, 4, 10, 62, 0, 100, 0, 9832, 5, 0, 0, 11, 54982, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 5 Selected - Cast \'Create Purple Trophy Tabard of the Illidari\''),
(5190, 0, 5, 10, 62, 0, 100, 0, 9832, 6, 0, 0, 11, 62768, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 6 Selected - Cast \'Create Tabard of Summer Skies\''),
(5190, 0, 6, 10, 62, 0, 100, 0, 9832, 7, 0, 0, 11, 62769, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 7 Selected - Cast \'Create Tabard of Summer Flames\''),
(5190, 0, 7, 10, 62, 0, 100, 0, 9832, 8, 0, 0, 11, 58194, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 8 Selected - Cast \'Create Loremaster\'s Colors\''),
(5190, 0, 8, 10, 62, 0, 100, 0, 9832, 9, 0, 0, 11, 58224, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 9 Selected - Cast \'Create Tabard of the Explorer\''),
(5190, 0, 9, 10, 62, 0, 100, 0, 9832, 10, 0, 0, 11, 55006, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merill Pleasance - On Gossip Option 10 Selected - Cast \'Create Tabard of the Achiever\''),
(5189, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 10 Selected - Close Gossip'),
(5189, 0, 0, 10, 62, 0, 100, 0, 9832, 1, 0, 0, 11, 54974, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 1 Selected - Cast \'Create Blood Knight Tabard\''),
(5189, 0, 1, 10, 62, 0, 100, 0, 9832, 2, 0, 0, 11, 54976, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 2 Selected - Cast \'Create Tabard of the Hand\''),
(5189, 0, 2, 10, 62, 0, 100, 0, 9832, 3, 0, 0, 11, 55008, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 3 Selected - Cast \'Create Tabard of the Protector\''),
(5189, 0, 3, 10, 62, 0, 100, 0, 9832, 4, 0, 0, 11, 54977, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 4 Selected - Cast \'Create Green Trophy Tabard of the Illidari\''),
(5189, 0, 4, 10, 62, 0, 100, 0, 9832, 5, 0, 0, 11, 54982, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 5 Selected - Cast \'Create Purple Trophy Tabard of the Illidari\''),
(5189, 0, 5, 10, 62, 0, 100, 0, 9832, 6, 0, 0, 11, 62768, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 6 Selected - Cast \'Create Tabard of Summer Skies\''),
(5189, 0, 6, 10, 62, 0, 100, 0, 9832, 7, 0, 0, 11, 62769, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 7 Selected - Cast \'Create Tabard of Summer Flames\''),
(5189, 0, 7, 10, 62, 0, 100, 0, 9832, 8, 0, 0, 11, 58194, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 8 Selected - Cast \'Create Loremaster\'s Colors\''),
(5189, 0, 8, 10, 62, 0, 100, 0, 9832, 9, 0, 0, 11, 58224, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 9 Selected - Cast \'Create Tabard of the Explorer\''),
(5189, 0, 9, 10, 62, 0, 100, 0, 9832, 10, 0, 0, 11, 55006, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Thrumn - On Gossip Option 10 Selected - Cast \'Create Tabard of the Achiever\''),
(5188, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 10 Selected - Close Gossip'),
(5188, 0, 0, 10, 62, 0, 100, 0, 9832, 1, 0, 0, 11, 54974, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 1 Selected - Cast \'Create Blood Knight Tabard\''),
(5188, 0, 1, 10, 62, 0, 100, 0, 9832, 2, 0, 0, 11, 54976, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 2 Selected - Cast \'Create Tabard of the Hand\''),
(5188, 0, 2, 10, 62, 0, 100, 0, 9832, 3, 0, 0, 11, 55008, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 3 Selected - Cast \'Create Tabard of the Protector\''),
(5188, 0, 3, 10, 62, 0, 100, 0, 9832, 4, 0, 0, 11, 54977, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 4 Selected - Cast \'Create Green Trophy Tabard of the Illidari\''),
(5188, 0, 4, 10, 62, 0, 100, 0, 9832, 5, 0, 0, 11, 54982, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 5 Selected - Cast \'Create Purple Trophy Tabard of the Illidari\''),
(5188, 0, 5, 10, 62, 0, 100, 0, 9832, 6, 0, 0, 11, 62768, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 6 Selected - Cast \'Create Tabard of Summer Skies\''),
(5188, 0, 6, 10, 62, 0, 100, 0, 9832, 7, 0, 0, 11, 62769, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 7 Selected - Cast \'Create Tabard of Summer Flames\''),
(5188, 0, 7, 10, 62, 0, 100, 0, 9832, 8, 0, 0, 11, 58194, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 8 Selected - Cast \'Create Loremaster\'s Colors\''),
(5188, 0, 8, 10, 62, 0, 100, 0, 9832, 9, 0, 0, 11, 58224, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 9 Selected - Cast \'Create Tabard of the Explorer\''),
(5188, 0, 9, 10, 62, 0, 100, 0, 9832, 10, 0, 0, 11, 55006, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Garyl - On Gossip Option 10 Selected - Cast \'Create Tabard of the Achiever\''),
(5049, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 10 Selected - Close Gossip'),
(5049, 0, 0, 10, 62, 0, 100, 0, 9832, 1, 0, 0, 11, 54974, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 1 Selected - Cast \'Create Blood Knight Tabard\''),
(5049, 0, 1, 10, 62, 0, 100, 0, 9832, 2, 0, 0, 11, 54976, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 2 Selected - Cast \'Create Tabard of the Hand\''),
(5049, 0, 2, 10, 62, 0, 100, 0, 9832, 3, 0, 0, 11, 55008, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 3 Selected - Cast \'Create Tabard of the Protector\''),
(5049, 0, 3, 10, 62, 0, 100, 0, 9832, 4, 0, 0, 11, 54977, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 4 Selected - Cast \'Create Green Trophy Tabard of the Illidari\''),
(5049, 0, 4, 10, 62, 0, 100, 0, 9832, 5, 0, 0, 11, 54982, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 5 Selected - Cast \'Create Purple Trophy Tabard of the Illidari\''),
(5049, 0, 5, 10, 62, 0, 100, 0, 9832, 6, 0, 0, 11, 62768, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 6 Selected - Cast \'Create Tabard of Summer Skies\''),
(5049, 0, 6, 10, 62, 0, 100, 0, 9832, 7, 0, 0, 11, 62769, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 7 Selected - Cast \'Create Tabard of Summer Flames\''),
(5049, 0, 7, 10, 62, 0, 100, 0, 9832, 8, 0, 0, 11, 58194, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 8 Selected - Cast \'Create Loremaster\'s Colors\''),
(5049, 0, 8, 10, 62, 0, 100, 0, 9832, 9, 0, 0, 11, 58224, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 9 Selected - Cast \'Create Tabard of the Explorer\''),
(5049, 0, 9, 10, 62, 0, 100, 0, 9832, 10, 0, 0, 11, 55006, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lyesa Steelbrow - On Gossip Option 10 Selected - Cast \'Create Tabard of the Achiever\''),
(5191, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 10 Selected - Close Gossip'),
(5191, 0, 0, 10, 62, 0, 100, 0, 9832, 1, 0, 0, 11, 54974, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 1 Selected - Cast \'Create Blood Knight Tabard\''),
(5191, 0, 1, 10, 62, 0, 100, 0, 9832, 2, 0, 0, 11, 54976, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 2 Selected - Cast \'Create Tabard of the Hand\''),
(5191, 0, 2, 10, 62, 0, 100, 0, 9832, 3, 0, 0, 11, 55008, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 3 Selected - Cast \'Create Tabard of the Protector\''),
(5191, 0, 3, 10, 62, 0, 100, 0, 9832, 4, 0, 0, 11, 54977, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 4 Selected - Cast \'Create Green Trophy Tabard of the Illidari\''),
(5191, 0, 4, 10, 62, 0, 100, 0, 9832, 5, 0, 0, 11, 54982, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 5 Selected - Cast \'Create Purple Trophy Tabard of the Illidari\''),
(5191, 0, 5, 10, 62, 0, 100, 0, 9832, 6, 0, 0, 11, 62768, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 6 Selected - Cast \'Create Tabard of Summer Skies\''),
(5191, 0, 6, 10, 62, 0, 100, 0, 9832, 7, 0, 0, 11, 62769, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 7 Selected - Cast \'Create Tabard of Summer Flames\''),
(5191, 0, 7, 10, 62, 0, 100, 0, 9832, 8, 0, 0, 11, 58194, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 8 Selected - Cast \'Create Loremaster\'s Colors\''),
(5191, 0, 8, 10, 62, 0, 100, 0, 9832, 9, 0, 0, 11, 58224, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 9 Selected - Cast \'Create Tabard of the Explorer\''),
(5191, 0, 9, 10, 62, 0, 100, 0, 9832, 10, 0, 0, 11, 55006, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shalumon - On Gossip Option 10 Selected - Cast \'Create Tabard of the Achiever\'');
SET @CGUID		:= 143410;
DELETE FROM `creature` WHERE `id`IN(37827,37878);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 37878, 571, 1, 1, 4785.788, -587.8594, 161.2263, 5.009095, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+1, 37878, 571, 1, 1, 4779.228, -587.1545, 162.1223, 4.537856, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+2, 37878, 571, 1, 1, 4802.324, -553.8646, 163.156, 4.869469, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+3, 37878, 571, 1, 1, 4778.958, -567.7934, 162.0411, 3.647738, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+4, 37878, 571, 1, 1, 4782.333, -572.7118, 161.8683, 5.585053, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+5, 37878, 571, 1, 1, 4789.622, -579.4358, 161.0213, 4.520403, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+6, 37878, 571, 1, 1, 4798.444, -562.9028, 161.4739, 1.466077, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+7, 37878, 571, 1, 1, 4760.652, -561.3246, 165.0569, 3.944444, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+8, 37878, 571, 1, 1, 4787.11, -566.2014, 161.6813, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+9, 37878, 571, 1, 1, 4767.754, -560.6215, 163.8418, 1.064651, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+10, 37878, 571, 1, 1, 4772.837, -575.5347, 162.7558, 1.64061, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+11, 37878, 571, 1, 1, 4797.168, -577.1268, 160.2595, 2.478368, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+12, 37878, 571, 1, 1, 4763.54, -576.6424, 163.8399, 5.253441, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+13, 37878, 571, 1, 1, 4763.713, -569.2257, 163.7682, 3.839724, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+14, 37878, 571, 1, 1, 4800.604, -547.7327, 164.9199, 0.715585, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+15, 37878, 571, 1, 1, 4782.397, -593.6545, 161.6707, 1.605703, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+16, 37878, 571, 1, 1, 4771.824, -566.1719, 162.4859, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+17, 37878, 571, 1, 1, 4791.537, -557.3125, 162.7901, 4.066617, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+18, 37878, 571, 1, 1, 4756.674, -580.4653, 165.0974, 1.48353, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+19, 37878, 571, 1, 1, 4782.095, -580.7483, 161.8616, 1.27409, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+20, 37878, 571, 1, 1, 4772.525, -585.9844, 163.0426, 2.687807, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+21, 37878, 571, 1, 1, 4759.741, -587.8351, 164.6121, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+22, 37878, 571, 1, 1, 4776.268, -596.5695, 162.6325, 2.059489, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+23, 37878, 571, 1, 1, 4793.397, -570.8108, 160.8941, 3.682645, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+24, 37878, 571, 1, 1, 4767.424, -594.3489, 163.828, 1.58825, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+25, 37878, 571, 1, 1, 4797.148, -583.2952, 159.8615, 3.595378, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+26, 37878, 571, 1, 1, 4817.919, -551.9774, 162.0828, 3.036873, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+27, 37878, 571, 1, 1, 4792.533, -591.684, 160.2542, 4.206244, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+28, 37878, 571, 1, 1, 4790.34, -607.0833, 160.2565, 3.525565, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+29, 37878, 571, 1, 1, 4782.63, -605.3073, 161.6125, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+30, 37878, 571, 1, 1, 4817.919, -551.9774, 162.0828, 3.036873, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+31, 37878, 571, 1, 1, 4792.533, -591.684, 160.2542, 4.206244, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+32, 37878, 571, 1, 1, 4790.34, -607.0833, 160.2565, 3.525565, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+33, 37878, 571, 1, 1, 4782.63, -605.3073, 161.6125, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+34, 37878, 571, 1, 1, 4798.115, -607.4479, 159.7254, 0.715585, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+35, 37878, 571, 1, 1, 4791.471, -618.4844, 159.7092, 2.059489, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+36, 37878, 571, 1, 1, 4792.949, -603.3854, 160.3281, 2.740167, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+37, 37878, 571, 1, 1, 4798.659, -602.0208, 159.8221, 2.565634, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+38, 37878, 571, 1, 1, 4810.37, -549.7691, 163.2147, 3.385939, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+39, 37878, 571, 1, 1, 4796.788, -613.9011, 159.7589, 0.8901179, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+40, 37878, 571, 1, 1, 4802.318, -570.2361, 160.2752, 1.064651, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+41, 37878, 571, 1, 1, 4784.508, -609.382, 161.722, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+42, 37878, 571, 1, 1, 4789.024, -611.7726, 160.3697, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+43, 37878, 571, 1, 1, 4816.295, -556.5955, 161.8312, 3.822271, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+44, 37878, 571, 1, 1, 4806.933, -604.0538, 159.585, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+45, 37878, 571, 1, 1, 4809.641, -555.4688, 162.6923, 0.715585, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+46, 37878, 571, 1, 1, 4826.658, -555.1059, 161.3158, 4.625123, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+47, 37878, 571, 1, 1, 4790.142, -624.1771, 159.6133, 0.9773844, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+48, 37878, 571, 1, 1, 4810.255, -627.4636, 159.1524, 1.500983, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+49, 37878, 571, 1, 1, 4810.049, -609.3768, 159.4645, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+50, 37878, 571, 1, 1, 4806.465, -618.2396, 159.5483, 5.445427, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+51, 37878, 571, 1, 1, 4815.847, -606.0087, 160.2059, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+52, 37878, 571, 1, 1, 4793.201, -627.0521, 159.9451, 3.473205, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+53, 37878, 571, 1, 1, 4814.297, -619.2708, 158.7552, 0.715585, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+54, 37878, 571, 1, 1, 4837.163, -576.5104, 160.5024, 5.078908, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+55, 37878, 571, 1, 1, 4800.022, -618.3073, 159.7944, 3.508112, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+56, 37878, 571, 1, 1, 4796.73, -622.5868, 159.9098, 2.356194, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+57, 37878, 571, 1, 1, 4806.011, -623.4809, 159.5464, 2.740167, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+58, 37878, 571, 1, 1, 4803.761, -610.7188, 159.545, 4.24115, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+59, 37878, 571, 1, 1, 4791.314, -635.191, 160.8559, 4.817109, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+60, 37878, 571, 1, 1, 4795.549, -631.2952, 160.2526, 1.361357, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+61, 37878, 571, 1, 1, 4809.817, -614.8125, 159.2753, 2.199115, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+62, 37878, 571, 1, 1, 4828.341, -562.2778, 160.3308, 0.9599311, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+63, 37878, 571, 1, 1, 4793.918, -639.1545, 161.241, 4.468043, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+64, 37878, 571, 1, 1, 4788.442, -639.3229, 162.3155, 1.37881, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+65, 37878, 571, 1, 1, 4801.533, -631.1614, 160.0972, 3.525565, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+66, 37878, 571, 1, 1, 4804.434, -635.9236, 159.8547, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+67, 37878, 571, 1, 1, 4806.627, -631.4097, 159.5468, 4.939282, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+68, 37878, 571, 1, 1, 4835.668, -563.5555, 161.4551, 0.4886922, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+69, 37878, 571, 1, 1, 4788.494, -629.8542, 161.1564, 5.340707, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+70, 37878, 571, 1, 1, 4798.058, -635.0156, 160.5321, 3.141593, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+71, 37878, 571, 1, 1, 4814.169, -631.3663, 158.7541, 5.235988, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+72, 37878, 571, 1, 1, 4809.902, -635.441, 159.2038, 1.151917, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+73, 37878, 571, 1, 1, 4845.159, -576.0278, 159.9401, 5.532694, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+74, 37878, 571, 1, 1, 4845.673, -593.6736, 159.1436, 3.874631, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+75, 37878, 571, 1, 1, 4809.697, -642.8246, 159.2958, 2.007129, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+76, 37878, 571, 1, 1, 4804.116, -640.8143, 160.1202, 2.373648, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+77, 37878, 571, 1, 1, 4825.955, -637.9774, 157.6442, 5.340707, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+78, 37878, 571, 1, 1, 4854.851, -593.2795, 157.3008, 4.625123, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+79, 37878, 571, 1, 1, 4822.641, -641.3472, 157.8503, 3.944444, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+80, 37878, 571, 1, 1, 4843.747, -587.0625, 159.7272, 0.9250245, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+81, 37878, 571, 1, 1, 4822.299, -616.1996, 157.9486, 2.286381, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+82, 37878, 571, 1, 1, 4851.638, -585.6007, 158.117, 2.059489, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+83, 37878, 571, 1, 1, 4842.857, -580.882, 159.7307, 2.96706, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+84, 37878, 571, 1, 1, 4826.226, -624.4792, 157.9513, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+85, 37878, 571, 1, 1, 4845.403, -613.0851, 157.4199, 1.815142, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+86, 37878, 571, 1, 1, 4840.92, -570.6979, 161.174, 3.769911, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+87, 37878, 571, 1, 1, 4837.809, -627.6736, 157.6199, 1.954769, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+88, 37878, 571, 1, 1, 4813.187, -639.132, 158.8725, 0, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+89, 37878, 571, 1, 1, 4833.483, -635.0799, 157.4865, 4.834562, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+90, 37878, 571, 1, 1, 4842.37, -621.6962, 157.5227, 2.879793, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+91, 37878, 571, 1, 1, 4829.419, -629.3629, 157.6456, 3.612832, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+92, 37878, 571, 1, 1, 4815.688, -625.3021, 158.6156, 4.066617, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+93, 37878, 571, 1, 1, 4848.793, -601.8837, 157.445, 4.258604, 120, 0, 0), -- 37878 (Area: 4192)
(@CGUID+94, 37827, 571, 1, 1, 4812.731, -582.6302, 162.4707, 4.118977, 120, 0, 0); -- 37827 (Area: 4192) 

UPDATE `smart_scripts` SET `action_param1`=1000 WHERE  `entryorguid`=3795201 AND `source_type`=9 AND `id`=6;
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=3000 WHERE  `entryorguid`=3785700 AND `source_type`=9 AND `id`=11 AND `link`=0;

UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=0, `action_param1`=1000 WHERE  `entryorguid`=3785700 AND `source_type`=9 AND `id`=13 AND `link`=0;
UPDATE `smart_scripts` SET `event_param1`=1000, `event_param2`=1000 WHERE  `entryorguid`=3785700 AND `source_type`=9 AND `id`=11 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid` =37826 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(37826,0,0,1,11,0,100,0,0,0,0,0,12,37952,8,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance - On Spawn - Spawn Light's Vengeance Vehicle Bunny 2"),
(37826,0,1,0,61,0,100,0,0,0,0,0,11,46598,0,0,0,0,0,19,37952,0,0,0,0,0,0,"Light's Vengeance - On Spawn - Cast Ride Vehicle Hardcoded");
--
UPDATE `gameobject` SET `spawnMask` = 1 WHERE `guid` = 20496 AND `id` = 185168;
UPDATE `gameobject` SET `spawnMask` = 2 WHERE `guid` = 20499 AND `id` = 185169; 
--
DELETE FROM `spell_script_names` WHERE `spell_id`=70903 AND `ScriptName`='spell_cultist_dark_martyrdrom';
DELETE FROM `spell_script_names` WHERE `spell_id`=71236 AND `ScriptName`='spell_cultist_dark_martyrdrom';
UPDATE `spell_script_names` SET `ScriptName`='spell_cultist_dark_martyrdom' WHERE `spell_id` IN (72495,72496,72497,72498,72499,72500);
DELETE FROM `npc_text` WHERE `ID`=9690;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `BroadcastTextID1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `BroadcastTextID2`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `BroadcastTextID3`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `BroadcastTextID4`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `BroadcastTextID5`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `BroadcastTextID6`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `BroadcastTextID7`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `VerifiedBuild`) VALUES 
(9690, 'The younger races make a big fuss over Winter Veil. Ironforge''s bank is the center of the festivities.', 'The younger races make a big fuss over Winter Veil. Ironforge''s bank is the center of the festivities.', 16179, 0, 01, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
UPDATE `smart_scripts` SET `link`=18 WHERE  `entryorguid`=24238 AND `source_type`=0 AND `id`=16 AND `link`=0;
UPDATE `smart_scripts` SET `link`=22 WHERE  `entryorguid`=24238 AND `source_type`=0 AND `id`=13 AND `link`=0;
UPDATE `smart_scripts` SET `link`=24 WHERE  `entryorguid`=24238 AND `source_type`=0 AND `id`=2 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=24238 AND `source_type`=0 AND `id`>16;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24474 AND `source_type`=0 AND `id`>1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24458 AND `source_type`=0 AND `id`>2;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24238, 0, 17, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - IC - Update Home Position'),
(24238, 0, 18, 27, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 24238, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - On Evade - Start WP'),
(24238, 0, 19, 20, 34, 0, 100, 0, 0, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.41052, 'Bjorn Halgurdsson - On Reached WP1 - Set Orientation'),
(24238, 0, 20, 21, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - Reached WP1 - Set Home Position'),
(24238, 0, 21, 0, 61, 0, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - Reached WP1 - Reset Script'),
(24238, 0, 22, 23, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - On Spawn - Set Passive'),
(24238, 0, 23, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - On Spawn - Set Non Attackable'),
(24238, 0, 24, 25, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson -  On Spellhit "Vrykul Insult" - Set Hostile'),
(24238, 0, 25, 26, 61, 0, 100, 0, 0, 0, 0, 0, 19, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson -  On Spellhit "Vrykul Insult" - Set Attackable'),
(24238, 0, 26, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson -  On Spellhit "Vrykul Insult" - Attack Invoker'),
(24238, 0, 27, 28, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - On Evade - Set Passive'),
(24238, 0, 28, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - On Evade - Set Non Attackable'),
(24474, 0, 2, 3, 4, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vengeance Landing Assassin - On Agro - Store Targetlist'),
(24474, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 24458, 0, 0, 0, 0, 0, 0, 'Vengeance Landing Assassin - On Agro - Send Targetlist to Lydia'),
(24474, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24458, 0, 0, 0, 0, 0, 0, 'Vengeance Landing Assassin - On Agro - Set Data 1 1 on Lydia'),
(24458, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Lydell - On Data Set - Attack Stored Target');

DELETE FROM `waypoints` WHERE `entry`=24238;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(24238, 1, 1518.61, -5249.85, 207.396,  'Bjorn Halgurdsson');
UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(18230,18237);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(18230,18237) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18230, 0, 0, 0, 1, 0, 100, 0, 0, 0, 500, 500, 29, 0, 0, 0, 0, 0, 0, 19, 18237, 0, 0, 0, 0, 0, 0, 'Trayanise - OOC - Follow Tiny Arcane Construct'),
(18230, 0, 1, 0, 1, 0, 100, 0, 0, 60000, 180000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Trayanise - OOC - Say Line 0'),
(18237, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 1, 18237, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tiny Arcane Construct - On Spawn - Start WP');

UPDATE `creature_template` SET `speed_run`=1.142857 WHERE  `entry`=18230;
UPDATE `creature_template` SET `speed_run`=2.142857 WHERE  `entry`=18237;

DELETE FROM `creature_addon` WHERE `guid` IN(65501,65505);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(65501, 0, 0, 0x0, 0x1, 0, NULL),
(65505, 0, 0, 0x0, 0x1, 0, NULL);

DELETE FROM `creature_template_addon` WHERE `entry` IN(18230,18237);

DELETE FROM `creature` WHERE `guid` IN(65501,65505);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(65501, 18230, 530, 1, 1,  9891.047, -7180.686, 31.02935, 2.363085, 120, 0, 0), -- 18230 (Area: 3487)
(65505, 18237, 530, 1, 1,  9886.445, -7179.344, 31.03508, 2.353462, 120, 0, 0); -- 18237 (Area: 3487)


DELETE FROM `waypoint_data` WHERE `id` IN(655010,655050);

DELETE FROM `waypoints` WHERE `entry` IN(18230,18237);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(18237, 1, 9854.372, -7131.53, 30.8774,  'Tiny Arcane Construct'),
(18237, 2, 9848.939, -7149.687, 30.88104,  'Tiny Arcane Construct'),
(18237, 3, 9853.528, -7164.35, 30.94116,  'Tiny Arcane Construct'),
(18237, 4, 9873.93, -7174.143, 31.04511,  'Tiny Arcane Construct'),
(18237, 5, 9890.317, -7171.364, 32.04652,  'Tiny Arcane Construct'),
(18237, 6, 9893.691, -7182.642, 31.02659,  'Tiny Arcane Construct'),
(18237, 7, 9906.294, -7211.048, 30.9103,  'Tiny Arcane Construct'),
(18237, 8, 9914.21, -7215.013, 30.81886,  'Tiny Arcane Construct'),
(18237, 9, 9930.763, -7214.394, 30.86104,  'Tiny Arcane Construct'),
(18237, 10, 9954.362, -7211.773, 30.87779,  'Tiny Arcane Construct'),
(18237, 11, 9953.68, -7204.061, 30.87768,  'Tiny Arcane Construct'),
(18237, 12, 9941.922, -7198.434, 30.87755,  'Tiny Arcane Construct'),
(18237, 13, 9915.126, -7188.168, 30.9569,  'Tiny Arcane Construct'),
(18237, 14, 9897.4, -7190.357, 31.03786,  'Tiny Arcane Construct'),
(18237, 15, 9885.156, -7178.048, 31.03413,  'Tiny Arcane Construct'),
(18237, 16, 9874.851, -7163.025, 30.99726,  'Tiny Arcane Construct'),
(18237, 17, 9867.523, -7139.578, 30.87733,  'Tiny Arcane Construct');

DELETE FROM `creature_text` WHERE `entry`=18230;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(18230, 0, 0, 'The magister''s going to kill me...', 12, 1, 100, 0, 0, 0, 15011, 'Trayanise'),
(18230, 0, 1, 'No, no, no! Come back here!', 12, 1, 100, 0, 0, 0, 15010, 'Trayanise'),
(18230, 0, 2, 'Argh. They told me those crystals would work properly!', 12, 1, 100, 0, 0, 0, 15013, 'Trayanise'),
(18230, 0, 3, 'When I catch you, I''m going to disenchant your components, so help me...', 12, 1, 100, 0, 0, 0, 15015, 'Trayanise'),
(18230, 0, 4, 'Get back here, you little...', 12, 1, 100, 0, 0, 0, 15012, 'Trayanise'),
(18230, 0, 5, 'You stay out of the regent lord''s way! I mean it!', 12, 1, 100, 0, 0, 0, 15014, 'Trayanise');
