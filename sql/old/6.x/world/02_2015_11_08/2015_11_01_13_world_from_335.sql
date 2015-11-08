UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=24108;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24108 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24108,0,0,0,8,0,100,0,42436,0,0,0,11,47173,0,0,0,0,0,7,0,0,0,0,0,0,0,'S.T.O.U.T. - On Spellhit Drink! - Cast Credit');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16348;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16348 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16345 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16345, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 28904, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Shadowpine Catlord - On Reset - Cast to summon Ghostclaw Lynx'),
(16348, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 8000, 12000, 11, 16828, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Ghostclaw Lynx - IC - Cast Claw'),
(16348, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 10000, 150000, 11, 59881, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Ghostclaw Lynx - IC - Cast Rake');
DELETE FROM `creature` WHERE `id`=3939;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=3939;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3939 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3265 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3265, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 6479, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Razormane Hunter- On Reset - Cast to summon Razormane Wolf'),
(3939, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 6000, 9000, 11, 17255, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Razormane Wolf - IC - Cast Bite'),
(3939, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 22000, 25000, 11, 24604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Razormane Wolf - IC - Furious Howl');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (2, 3) AND `SourceEntry`=27743;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(22,2,27743,0,31,3,27743,0,0,'','event will not trigger if the spell is casted by 27743', 1),
(22,3,27743,0,31,3,27743,0,0,'','event will not trigger if the spell is casted by 27743', 1);
DELETE FROM `spell_area` WHERE `spell` IN (40624, 40627, 40628);
INSERT INTO `spell_area` (`spell`, `area`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(40624,3767,0,2,1,0,0), -- Apexis Vibrations
(40624,3768,0,2,1,0,0),
(40624,3769,0,2,1,0,0),
(40624,3770,0,2,1,0,0),
(40624,3771,0,2,1,0,0),
(40624,3772,0,2,1,0,0),
(40624,3773,0,2,1,0,0),
(40624,3774,0,2,1,0,0),
(40624,3775,0,2,1,0,0),
(40624,3776,0,2,1,0,0),
(40624,3777,0,2,1,0,0),
(40624,3778,0,2,1,0,0),
(40624,3779,0,2,1,0,0),
(40624,3780,0,2,1,0,0),
(40624,3781,0,2,1,0,0),
(40624,3782,0,2,1,0,0),
(40624,3783,0,2,1,0,0),
(40624,3784,0,2,1,0,0),
(40624,3785,0,2,1,0,0),
(40624,3786,0,2,1,0,0),
(40624,3787,0,2,1,0,0),
(40624,3824,0,2,1,0,0),
(40624,3825,0,2,1,0,0),
(40624,3826,0,2,1,0,0),
(40624,3827,0,2,1,0,0),
(40624,3828,0,2,1,0,0),
(40624,3829,0,2,1,0,0),
(40624,3830,0,2,1,0,0),
(40624,3831,0,2,1,0,0),
(40624,3832,0,2,1,0,0),
(40624,3833,0,2,1,0,0),
(40624,3834,0,2,1,0,0),
(40624,3844,0,2,1,0,0),
(40624,3855,0,2,1,0,0),
(40624,3862,0,2,1,0,0),
(40624,3863,0,2,1,0,0),
(40624,3864,0,2,1,0,0),
(40624,3865,0,2,1,0,0),
(40624,3866,0,2,1,0,0),
(40624,3867,0,2,1,0,0),
(40624,3903,0,2,1,0,0),
(40624,3904,0,2,1,0,0),
(40624,3918,0,2,1,0,0),
(40624,3919,0,2,1,0,0),
(40624,3922,0,2,1,0,0),
(40624,3924,0,2,1,0,0),
(40624,3925,0,2,1,0,0),
(40624,3931,0,2,1,0,0),
(40624,3942,0,2,1,0,0),
(40624,3951,0,2,1,0,0),
(40624,3952,0,2,1,0,0),
(40624,3953,0,2,1,0,0),
(40624,3954,0,2,1,0,0),
(40624,3960,0,2,1,0,0),
(40624,3962,0,2,1,0,0),
(40624,3963,0,2,1,0,0),
(40624,3964,0,2,1,0,0),
(40624,3969,0,2,1,0,0),
(40624,3970,0,2,1,0,0),
(40624,3971,0,2,1,0,0),
(40624,3972,0,2,1,0,0),
(40624,4008,0,2,1,0,0),
(40627,3767,0,2,1,0,0), -- Apexis Emanations
(40627,3768,0,2,1,0,0),
(40627,3769,0,2,1,0,0),
(40627,3770,0,2,1,0,0),
(40627,3771,0,2,1,0,0),
(40627,3772,0,2,1,0,0),
(40627,3773,0,2,1,0,0),
(40627,3774,0,2,1,0,0),
(40627,3775,0,2,1,0,0),
(40627,3776,0,2,1,0,0),
(40627,3777,0,2,1,0,0),
(40627,3778,0,2,1,0,0),
(40627,3779,0,2,1,0,0),
(40627,3780,0,2,1,0,0),
(40627,3781,0,2,1,0,0),
(40627,3782,0,2,1,0,0),
(40627,3783,0,2,1,0,0),
(40627,3784,0,2,1,0,0),
(40627,3785,0,2,1,0,0),
(40627,3786,0,2,1,0,0),
(40627,3787,0,2,1,0,0),
(40627,3824,0,2,1,0,0),
(40627,3825,0,2,1,0,0),
(40627,3826,0,2,1,0,0),
(40627,3827,0,2,1,0,0),
(40627,3828,0,2,1,0,0),
(40627,3829,0,2,1,0,0),
(40627,3830,0,2,1,0,0),
(40627,3831,0,2,1,0,0),
(40627,3832,0,2,1,0,0),
(40627,3833,0,2,1,0,0),
(40627,3834,0,2,1,0,0),
(40627,3844,0,2,1,0,0),
(40627,3855,0,2,1,0,0),
(40627,3862,0,2,1,0,0),
(40627,3863,0,2,1,0,0),
(40627,3864,0,2,1,0,0),
(40627,3865,0,2,1,0,0),
(40627,3866,0,2,1,0,0),
(40627,3867,0,2,1,0,0),
(40627,3903,0,2,1,0,0),
(40627,3904,0,2,1,0,0),
(40627,3918,0,2,1,0,0),
(40627,3919,0,2,1,0,0),
(40627,3922,0,2,1,0,0),
(40627,3924,0,2,1,0,0),
(40627,3925,0,2,1,0,0),
(40627,3931,0,2,1,0,0),
(40627,3942,0,2,1,0,0),
(40627,3951,0,2,1,0,0),
(40627,3952,0,2,1,0,0),
(40627,3953,0,2,1,0,0),
(40627,3954,0,2,1,0,0),
(40627,3960,0,2,1,0,0),
(40627,3962,0,2,1,0,0),
(40627,3963,0,2,1,0,0),
(40627,3964,0,2,1,0,0),
(40627,3969,0,2,1,0,0),
(40627,3970,0,2,1,0,0),
(40627,3971,0,2,1,0,0),
(40627,3972,0,2,1,0,0),
(40627,4008,0,2,1,0,0),
(40628,3767,0,2,1,0,0), -- Apexis Enlightment
(40628,3768,0,2,1,0,0),
(40628,3769,0,2,1,0,0),
(40628,3770,0,2,1,0,0),
(40628,3771,0,2,1,0,0),
(40628,3772,0,2,1,0,0),
(40628,3773,0,2,1,0,0),
(40628,3774,0,2,1,0,0),
(40628,3775,0,2,1,0,0),
(40628,3776,0,2,1,0,0),
(40628,3777,0,2,1,0,0),
(40628,3778,0,2,1,0,0),
(40628,3779,0,2,1,0,0),
(40628,3780,0,2,1,0,0),
(40628,3781,0,2,1,0,0),
(40628,3782,0,2,1,0,0),
(40628,3783,0,2,1,0,0),
(40628,3784,0,2,1,0,0),
(40628,3785,0,2,1,0,0),
(40628,3786,0,2,1,0,0),
(40628,3787,0,2,1,0,0),
(40628,3824,0,2,1,0,0),
(40628,3825,0,2,1,0,0),
(40628,3826,0,2,1,0,0),
(40628,3827,0,2,1,0,0),
(40628,3828,0,2,1,0,0),
(40628,3829,0,2,1,0,0),
(40628,3830,0,2,1,0,0),
(40628,3831,0,2,1,0,0),
(40628,3832,0,2,1,0,0),
(40628,3833,0,2,1,0,0),
(40628,3834,0,2,1,0,0),
(40628,3844,0,2,1,0,0),
(40628,3855,0,2,1,0,0),
(40628,3862,0,2,1,0,0),
(40628,3863,0,2,1,0,0),
(40628,3864,0,2,1,0,0),
(40628,3865,0,2,1,0,0),
(40628,3866,0,2,1,0,0),
(40628,3867,0,2,1,0,0),
(40628,3903,0,2,1,0,0),
(40628,3904,0,2,1,0,0),
(40628,3918,0,2,1,0,0),
(40628,3919,0,2,1,0,0),
(40628,3922,0,2,1,0,0),
(40628,3924,0,2,1,0,0),
(40628,3925,0,2,1,0,0),
(40628,3931,0,2,1,0,0),
(40628,3942,0,2,1,0,0),
(40628,3951,0,2,1,0,0),
(40628,3952,0,2,1,0,0),
(40628,3953,0,2,1,0,0),
(40628,3954,0,2,1,0,0),
(40628,3960,0,2,1,0,0),
(40628,3962,0,2,1,0,0),
(40628,3963,0,2,1,0,0),
(40628,3964,0,2,1,0,0),
(40628,3969,0,2,1,0,0),
(40628,3970,0,2,1,0,0),
(40628,3971,0,2,1,0,0),
(40628,3972,0,2,1,0,0),
(40628,4008,0,2,1,0,0);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-40623,-40625,-40626) AND `spell_effect` IN (-40624,-40627,-40628);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-40623, -40624, 0, 'Remove Swiftness if Apexis Vibrations is removed'),
(-40625, -40627, 0, 'Remove Swiftness if Apexis Emanations is removed'),
(-40626, -40628, 0, 'Remove Swiftness if Apexis Enlightment is removed');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (40624, 40627, 40628);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ScriptName`, `Comment`) VALUES
(17,0,40624,0,0,1,0,40623, '', 'Swiftness - Only cast if Apexis Vibrations is active'),
(17,0,40627,0,0,1,0,40625, '', 'Swiftness - Only cast if Apexis Emanations is active'),
(17,0,40628,0,0,1,0,40626, '', 'Swiftness - Only cast if Apexis Enlightment is active');
UPDATE `creature` SET `Map`=622, `position_x`=-3.57706, `position_y`=0.507499, `position_z`=34.0151, `spawndist`=0, `MovementType`=0 WHERE `guid`=134846;
UPDATE `creature` SET `Map`=623, `position_x`=6.08656, `position_y`=-0.107499, `position_z`=20.5756, `spawndist`=0, `MovementType`=0 WHERE `guid`=134847;
DELETE FROM `creature_loot_template` WHERE `entry` IN (36597, 39167) AND `Item`= 51315; -- Delete Sealed Chest from 10 difficulties loot list
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=51315;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`Scriptname`,`Comment`) VALUES
-- Lich King 25N
(1,39166,51315,0,0,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,0,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,0,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39166,51315,0,0,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
--
(1,39166,51315,0,1,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,1,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,1,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39166,51315,0,1,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
--
(1,39166,51315,0,2,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,2,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,2,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39166,51315,0,2,8,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" rewarded'),
--
(1,39166,51315,0,3,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,3,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,3,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39166,51315,0,3,8,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" rewarded'),

--
(1,39166,51315,0,4,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,4,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,4,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39166,51315,0,4,28,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" Completed'),

(1,39166,51315,0,5,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,5,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,5,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39166,51315,0,5,28,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" Completed'),
-- Lich King 25H
(1,39168,51315,0,0,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,0,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,0,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39168,51315,0,0,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
--
(1,39168,51315,0,1,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,1,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,1,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39168,51315,0,1,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
--
(1,39168,51315,0,2,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,2,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,2,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39168,51315,0,2,8,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" rewarded'),
--
(1,39168,51315,0,3,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,3,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,3,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39168,51315,0,3,8,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" rewarded'),
--
(1,39168,51315,0,4,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,4,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,4,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39168,51315,0,4,28,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" Completed'),
--
(1,39168,51315,0,5,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,5,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,5,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39168,51315,0,5,28,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" Completed');
UPDATE `creature_text` SET `text`= "This is the last time I get caught! I promise! Bye!", `BroadcastTextId`=15308, `Language`=0 WHERE `entry`=20812;
SET @GUID         :=5625; -- 1 GOB guid set by TC
SET @cover        := 164819;
SET @Portrait     :=164825;
SET @Assemblage   :=8905;
SET @ReliCoffer   :=174564;
SET @ReliCoffer2  :=174563;
SET @ReliCoffer3  :=174562;
SET @ReliCoffer4  :=174561;
SET @ReliCoffer5  :=174560;
SET @ReliCoffer6  :=174559;
SET @ReliCoffer7  :=174554;
SET @ReliCoffer8  :=174555;
SET @ReliCoffer9  :=174556;
SET @ReliCoffer10 :=174557;
SET @ReliCoffer11 :=174566;
SET @ReliCoffer12 :=174558;
SET @DOOM         :=9476;
SET @Secret       :=174553; 
SET @Dark         :=174565;

DELETE FROM `gameobject` WHERE `guid` IN (@GUID);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseId`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID,165554,230,1,169, 802.907, -356.401, -48.9423,0,0,0,-0.382683, 0.92388, 7200, 100, 1);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Assemblage, @DOOM);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (@cover, @Dark, @Portrait, @ReliCoffer, @ReliCoffer2, @ReliCoffer3, @ReliCoffer4, @ReliCoffer5, @ReliCoffer6, @ReliCoffer7, @ReliCoffer8, @ReliCoffer9, @ReliCoffer10, @ReliCoffer11, @ReliCoffer12, @Secret);

DELETE FROM `smart_scripts` WHERE `entryorguid`=@Assemblage AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-46610 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Assemblage*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Assemblage*100+1 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DOOM AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@cover, @Dark, @Secret, @ReliCoffer, @ReliCoffer2, @ReliCoffer3, @ReliCoffer4, @ReliCoffer5, @ReliCoffer6, @ReliCoffer7, @ReliCoffer8, @ReliCoffer9, @ReliCoffer10, @ReliCoffer11, @ReliCoffer12) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@cover, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, @Portrait, 5, 0, 0, 0, 0, 0, 'Cover - On gossip hello - Remove flags'),
(@ReliCoffer, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Set data'), 
(@ReliCoffer, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer2, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer2, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer3, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer3, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer4, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer4, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer5, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer5, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer6, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer6, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer7, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer7, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer8, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer8, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer9, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer9, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer10, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer10, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer11, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer11, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer12, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer12, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@Assemblage, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On data set - Increment Counter 1'), -- the counter nbr 1 is incremented here
(@Assemblage, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On Respawn - Set passif'),
(@Assemblage, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On Respawn - Add unit_flag'),
(@Assemblage, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On Respawn - SET PHASE EVENT 0'),
(@Assemblage, 0, 4, 0, 77, 0, 100, 1, 1, 12, 0, 0, 80, @Assemblage*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On counter1=12 - Actionlist'),  -- event triggred when the counter 1= 12
(@Assemblage*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - Remmove unit flag'),
(@Assemblage*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - react agressif'),
(@Assemblage*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - SET PHASE EVENT 0'),
(@Assemblage, 0, 5, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 15621, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - IC - Cast'),
(@Secret, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 161495, 10, 0, 0, 0, 0, 0, 'Secret - On State 2  - Remove flags'),
(@Dark, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160845, 10, 0, 0, 0, 0, 0, '@Dark - On State 2  - Remove flags'),
(-46610, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On data set - Increment Counter1'), -- the counter nbr 1 is incremented here
(-46610, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On Respawn - Set passif'),
(-46610, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On Respawn - Add unit_flag'),
(-46610, 0, 4, 0, 77, 0, 100, 1, 1, 12, 0, 0, 80, @Assemblage*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On counter1=12 - Actionlist'), -- event triggred when the counter 1= 12
(@Assemblage*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - Remmove unit flag'),
(@Assemblage*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - react agressif'),
(@Assemblage*100+1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @DOOM, 7, 0, 0, 0, 0, 8, 0, 0, 0, 813.737915, -347.550354, -50.578030, 0.670515, 'Assemblage - Actionlist - Summon'),
(@Assemblage*100+1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - SET PHASE EVENT 0'),
(-46610, 0, 5, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 15621, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - IC - Cast'),
(@DOOM, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 11971, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'DOOM - IC - Cast'),
(@DOOM, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 14000, 14000, 11, 15504, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'DOOM - IC - Cast'),
(@DOOM, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 20, 174553, 70, 0, 0, 0, 0, 0, 'DOOM - On death - Activate gob'),
(@DOOM, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'DOOM - On aggro - Talk');

DELETE FROM `creature_text` WHERE `entry`IN (@DOOM);   
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(@DOOM,0,0,"What are you doing?  Intruders!!",14,0,100,0,0,0,'Watchman Doomgrip', 4962);
SET @GUID          := 16397; -- 1 creature guid Set by TC
DELETE FROM `creature` WHERE `id`=16123;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`curhealth`) VALUES
(@GUID, 16123, 0, 1, 169, -14457.221680, 448.084534, 20.406971, 6.115618, 600, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (16123, 16033, 16016);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`, `emote`, `auras`) VALUES
(16123,0,0,0,"27614 17327 44816"),
(16033,0,0,0,"27614 17327"),
(16016,0,0,0,"27614 17327");
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=38606;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,38606,0,0,31,1,3,21326,0,0,0,0,'','Exorcism Feather can be used only on Raven''s Wood Leafbeard');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (21326, 22226);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21326, 22226) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21326, 0, 0, 0, 0, 0, 100, 0, 10000, 12000, 35000, 40000, 11, 37696, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - IC - cast Force of Nature'),
(21326, 0, 1, 2, 38, 0, 100, 0, 0, 1, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - On Data set  - Set faction'),
(21326, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - On Data set  - Show emote'),
(21326, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - On Data set  - Set faction'),
(21326, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - On Data set  - Evade'),
(21326, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - On Data set  - Despawn'),
(22226, 0, 0, 0, 0, 0, 100, 0, 5000, 7000, 8000, 10000, 11, 36093, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Koi-Koi Spirit - IC - Ghost Strike'),
(22226, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 21326, 40, 0, 0, 0, 0,0,'Koi-Koi Spirit - On death  - Set data');

DELETE FROM `creature_text` WHERE `entry`= 21326;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(21326,0,0,'The %s appears very grateful to be free of the koi-koi spirit''s influence.',16,0,100,0,0,0,'Raven''s Wood Leafbeard ', 19943);
DELETE FROM  `conditions` where `SourceTypeOrReferenceId`=17 AND `SourceEntry`=72590;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 72590, 0, 0,27, 1, 70, 3, 0, 0, 0, 0, '', 'Minimum Level for Runescroll of Fortitude on players (70)');
--
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry` IN (28086, 28085);
UPDATE `smart_scripts` SET `target_type`=21, `target_param1`=8 WHERE `entryorguid` IN (32639, 32638, 32641, 32642) AND `id`=2; -- fix text target for Traveler's Tundra Mammoth's npcs
-- Add SAI support for Lance a Lot achievement ID: 2836
-- Champions SAI mechanic
SET @Sen_Valiant := 33285;
SET @Script := 3328500;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Sen_Valiant;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Sen_Valiant;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Script;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Sen_Valiant,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Valiant - On Reset - Remove auras from Defend'),
(@Sen_Valiant,0,1,2,62,0,100,0,10469,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sen Valiant - On gossip select - Close gossip'),
(@Sen_Valiant,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sen Valiant - Linked with previous event - store target'),
(@Sen_Valiant,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Valiant - Linked with previous event - Call timed actionlist'),
(@Sen_Valiant,0,4,0,52,0,100,0,0,@Sen_Valiant,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sen Valiant - On text over - Cast Charge'),
(@Sen_Valiant,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'Sen Valiant - IC - Cast Thrust'),
(@Sen_Valiant,0,6,0,9,0,100,0,5,5,4000,7000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Sen Valiant - On more than 5 yard range - Cast Shield-Breaker'),
(@Sen_Valiant,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Valiant - IC - Move forward 12 yards'),
(@Sen_Valiant,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Sen Valiant - On 10-12 yard range - Cast Charge'),
(@Sen_Valiant,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Sen Valiant - Linked with previous event - Cast Shield-Breaker'),
(@Sen_Valiant,0,10,11,2,0,100,1,1,3,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Valiant - On HP% between 1% and 3% - Change faction to 35'),
(@Sen_Valiant,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Valiant - Linked with previous event - Say text'),
(@Sen_Valiant,0,12,13,61,0,100,0,0,0,0,0,85,62724,0,0,0,0,0,12,1,0,0,0,0,0,0,'Sen Valiant - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@Sen_Valiant,0,13,14,61,0,100,0,0,0,0,0,85,64812,0,0,0,0,0,12,1,0,0,0,0,0,0,'Sen Valiant - Linked with previous event - Cast credit'),
(@Sen_Valiant,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Valiant - Linked with previous event - Evade'),
(@Sen_Valiant,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Valiant - On player killed - Say text'),
(@Sen_Valiant,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Valiant - Linked with previous event - Set unseen'),
(@Sen_Valiant,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Valiant - Linked with previous event - Despawn in 1 ms'),
-- Timed actionlist 1
(@Script,9,1,0,0,0,100,0,0,0,0,0,42,0,1,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Set INVINCIBILITY'),
(@Script,9,2,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Set run ON'),
(@Script,9,3,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Cast Defend on self/Layer 1/'),
(@Script,9,4,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Cast Defend on self/Layer 2/'),
(@Script,9,5,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Cast Defend on self/Layer 3/'),
(@Script,9,6,0,0,0,100,0,0,0,0,0,46,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Move forward 15 yards'),
(@Script,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Set run Off'),
(@Script,9,8,0,0,0,100,0,0,0,0,0,11,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Cast aura TriggerS for Defend /10 sec one/'),
(@Script,9,9,0,0,0,100,0,3500,3500,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Change faction to 14'),
(@Script,9,10,0,0,0,100,0,0,0,0,0,1,0,1500,0,0,0,0,2,0,0,0,0,0,0,0,'All champions - Script 1 - Say text');
-- Argent Valiants texts
DELETE FROM `creature_text` WHERE `entry`= @Sen_Valiant;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@Sen_Valiant,0,0,'Ready yourself!',12,1,100,0,0,0,'Argent Valiant', 33757),
(@Sen_Valiant,0,1,'Prepare yourself!',12,1,100,0,0,0,'Argent Valiant', 33755),
(@Sen_Valiant,0,2,'On your guard!',12,1,100,0,0,0,'Argent Valiant', 33756),
(@Sen_Valiant,0,3,'Let it begin!',12,1,100,0,0,0,'Argent Valiant', 33758),
(@Sen_Valiant,1,0,'Victory is mine!',12,1,100,0,0,0,'Argent Valiant', 33777),
(@Sen_Valiant,1,1,'It seems you still need more practice. Perhaps another time.',12,1,100,0,0,0,'Argent Valiant', 33764),
(@Sen_Valiant,1,2,'I have won. Better luck another time, friend.',12,1,100,0,0,0,'Argent Valiant', 33779),
(@Sen_Valiant,1,3,'I am afraid you will need more practice to defeat me.',12,1,100,0,0,0,'Argent Valiant', 33778),
(@Sen_Valiant,2,0,'I yield to you.',12,1,100,0,0,0,'Argent Valiant', 33774),
(@Sen_Valiant,2,1,'That was a well fought battle. I yield to you.',12,1,100,0,0,0,'Argent Valiant', 33776),
(@Sen_Valiant,2,2,'It would seem I underestimated your skills. Well done.',12,1,100,0,0,0,'Argent Valiant', 33775),
(@Sen_Valiant,2,3,'I have been defeated. Good fight!',12,1,100,0,0,0,'Argent Valiant', 33760);
-- Add condition for gossip option to show only, if player has quest: The Grand Melee is on tournament mount and have the spear equiped 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (10469, 10468, 10470, 10472, 10473, 10466, 10464, 10471, 10465, 10467);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTarget`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`,`NegativeCondition`) VALUES
(15,10469,0,0,1,9,13772,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10469,0,0,1,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1), 
(15,10469,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,2,9,13777,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10469,0,0,2,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10469,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,3,9,13782,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10469,0,0,3,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10469,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,4,9,13787,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10469,0,0,4,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10469,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,5,9,13767,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10469,0,0,5,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10469,0,0,5,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,5,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,6,9,13761,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10469,0,0,6,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10469,0,0,6,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,6,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,7,9,13745,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10469,0,0,7,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10469,0,0,7,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,7,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,8,9,13750,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10469,0,0,8,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10469,0,0,8,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,8,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,9,9,13756,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10469,0,0,9,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10469,0,0,9,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,9,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,10,9,13665,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10469,0,0,10,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10469,0,0,10,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10469,0,0,10,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,1,9,13772,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10468,0,0,1,1,64811,0,0,0,'','Show gossip menu only if don''t have the auran',1),
(15,10468,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,2,9,13777,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10468,0,0,2,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10468,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,3,9,13782,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10468,0,0,3,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10468,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,4,9,13787,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10468,0,0,4,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10468,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,5,9,13767,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10468,0,0,5,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10468,0,0,5,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,5,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,6,9,13761,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10468,0,0,6,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10468,0,0,6,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,6,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,7,9,13745,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10468,0,0,7,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10468,0,0,7,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,7,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,8,9,13750,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10468,0,0,8,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10468,0,0,8,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,8,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,9,9,13756,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10468,0,0,9,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10468,0,0,9,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,9,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,10,9,13665,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10468,0,0,10,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10468,0,0,10,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10468,0,0,10,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,1,9,13772,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10470,0,0,1,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10470,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,2,9,13777,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10470,0,0,2,1,64813,0,0,0,'','Show gossip menu only if don''t have the auran',1),
(15,10470,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,3,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10470,0,0,3,9,13782,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10470,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,4,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10470,0,0,4,9,13787,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10470,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,5,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10470,0,0,5,9,13767,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10470,0,0,5,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,5,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,6,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10470,0,0,6,9,13761,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10470,0,0,6,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,6,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,7,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10470,0,0,7,9,13745,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10470,0,0,7,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,7,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,8,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10470,0,0,8,9,13750,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10470,0,0,8,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,8,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,9,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10470,0,0,9,9,13756,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10470,0,0,9,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,9,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,10,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10470,0,0,10,9,13665,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10470,0,0,10,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10470,0,0,10,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,1,9,13772,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10472,0,0,1,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10472,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,2,9,13777,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10472,0,0,2,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10472,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,3,9,13782,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10472,0,0,3,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10472,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,4,9,13787,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10472,0,0,4,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10472,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,5,9,13767,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10472,0,0,5,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10472,0,0,5,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,5,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,6,9,13761,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10472,0,0,6,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10472,0,0,6,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,6,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,7,9,13745,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10472,0,0,7,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10472,0,0,7,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,7,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,8,9,13750,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10472,0,0,8,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10472,0,0,8,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,8,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,9,9,13756,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10472,0,0,9,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10472,0,0,9,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,9,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,10,9,13665,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10472,0,0,10,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10472,0,0,10,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10472,0,0,10,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,1,9,13772,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10473,0,0,1,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10473,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,2,9,13777,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10473,0,0,2,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10473,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,3,9,13782,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10473,0,0,3,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10473,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,4,9,13787,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10473,0,0,4,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10473,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,5,9,13767,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10473,0,0,5,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10473,0,0,5,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,5,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,6,9,13761,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10473,0,0,6,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10473,0,0,6,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,6,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,7,9,13745,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10473,0,0,7,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10473,0,0,7,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,7,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,8,9,13750,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10473,0,0,8,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10473,0,0,8,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,8,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,9,9,13756,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10473,0,0,9,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10473,0,0,9,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,9,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,10,9,13665,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10473,0,0,10,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10473,0,0,10,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10473,0,0,10,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,1,9,13772,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10466,0,0,1,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10466,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,2,9,13777,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10466,0,0,2,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10466,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,3,9,13782,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10466,0,0,3,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10466,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,4,9,13787,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10466,0,0,4,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10466,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,5,9,13767,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10466,0,0,5,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10466,0,0,5,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,5,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,6,9,13761,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10466,0,0,6,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10466,0,0,6,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,6,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,7,9,13745,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10466,0,0,7,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10466,0,0,7,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,7,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,8,9,13750,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10466,0,0,8,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10466,0,0,8,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,8,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,9,9,13756,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10466,0,0,9,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10466,0,0,9,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,9,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,10,9,13665,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10466,0,0,10,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10466,0,0,10,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10466,0,0,10,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,1,9,13772,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10464,0,0,1,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10464,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,2,9,13777,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10464,0,0,2,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10464,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,3,9,13782,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10464,0,0,3,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10464,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,4,9,13787,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10464,0,0,4,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10464,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,5,9,13767,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10464,0,0,5,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10464,0,0,5,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,5,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,6,9,13761,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10464,0,0,6,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10464,0,0,6,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,6,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,7,9,13745,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10464,0,0,7,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10464,0,0,7,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,7,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,8,9,13750,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10464,0,0,8,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10464,0,0,8,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,8,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,9,9,13756,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10464,0,0,9,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10464,0,0,9,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,9,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,10,9,13665,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10464,0,0,10,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10464,0,0,10,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10464,0,0,10,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,1,9,13772,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10471,0,0,1,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10471,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,2,9,13777,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10471,0,0,2,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10471,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,3,9,13782,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10471,0,0,3,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10471,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,4,9,13787,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10471,0,0,4,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10471,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,5,9,13767,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10471,0,0,5,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10471,0,0,5,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,5,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,6,9,13761,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10471,0,0,6,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10471,0,0,6,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,6,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,7,9,13745,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10471,0,0,7,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10471,0,0,7,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,7,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,8,9,13750,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10471,0,0,8,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10471,0,0,8,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,8,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,9,9,13756,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10471,0,0,9,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10471,0,0,9,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,9,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,10,9,13665,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10471,0,0,10,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10471,0,0,10,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10471,0,0,10,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,1,9,13772,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10465,0,0,1,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10465,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,2,9,13777,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10465,0,0,2,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10465,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,3,9,13782,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10465,0,0,3,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10465,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,4,9,13787,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10465,0,0,4,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10465,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,5,9,13767,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10465,0,0,5,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10465,0,0,5,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,5,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,6,9,13761,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10465,0,0,6,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10465,0,0,6,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,6,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,7,9,13745,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10465,0,0,7,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10465,0,0,7,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,7,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,8,9,13750,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10465,0,0,8,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10465,0,0,8,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,8,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,9,9,13756,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10465,0,0,9,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10465,0,0,9,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,9,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,10,9,13665,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10465,0,0,10,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10465,0,0,10,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10465,0,0,10,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,1,9,13772,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10467,0,0,1,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10467,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,2,9,13777,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10467,0,0,2,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10467,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,3,9,13782,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10467,0,0,3,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10467,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,4,9,13787,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10467,0,0,4,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10467,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,5,9,13767,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10467,0,0,5,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10467,0,0,5,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,5,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,6,9,13761,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10467,0,0,6,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10467,0,0,6,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,6,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,7,9,13745,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10467,0,0,7,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10467,0,0,7,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,7,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,8,9,13750,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10467,0,0,8,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10467,0,0,8,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,8,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,9,9,13756,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10467,0,0,9,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10467,0,0,9,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,9,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,10,9,13665,0,0,0,'','Show gossip menu only if quest The Grand Mele is taken',0),
(15,10467,0,0,10,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10467,0,0,10,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10467,0,0,10,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0);

SET @Orgri_Valiant := 33306;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Orgri_Valiant;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Orgri_Valiant;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Orgri_Valiant,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Valiant - On Reset - Remove auras from Defend'),
(@Orgri_Valiant,0,1,2,62,0,100,0,10468,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Orgri Valiant - On gossip select - Close gossip'),
(@Orgri_Valiant,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Orgri Valiant - Linked with previous event - store target'),
(@Orgri_Valiant,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Valiant - Linked with previous event - Call timed actionlist'),
(@Orgri_Valiant,0,4,0,52,0,100,0,0,@Orgri_Valiant,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'Orgri Valiant - On text over - Cast Charge'),
(@Orgri_Valiant,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'Orgri Valiant - IC - Cast Thrust'),
(@Orgri_Valiant,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Orgri Valiant - On more than 5 yard range - Cast Shield-Breaker'),
(@Orgri_Valiant,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Valiant - IC - Move forward 12 yards'),
(@Orgri_Valiant,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Orgri Valiant - On 10-12 yard range - Cast Charge'),
(@Orgri_Valiant,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Orgri Valiant - Linked with previous event - Cast Shield-Breaker'),
(@Orgri_Valiant,0,10,11,2,0,100,1,1,3,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Valiant - On HP% between 1% and 3% - Change faction to 35'),
(@Orgri_Valiant,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Valiant - Linked with previous event - Say text'),
(@Orgri_Valiant,0,12,13,61,0,100,0,0,0,0,0,85,62724,0,0,0,0,0,12,1,0,0,0,0,0,0,'Orgri Valiant - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@Orgri_Valiant,0,13,14,61,0,100,0,0,0,0,0,85,64811,0,0,0,0,0,12,1,0,0,0,0,0,0,'Orgri Valiant - Linked with previous event - Cast credit'),
(@Orgri_Valiant,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri_Valiant - Linked with previous event - Evade'),
(@Orgri_Valiant,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Valiant - On player killed - Say text'),
(@Orgri_Valiant,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Valiant - Linked with previous event - Set unseen'),
(@Orgri_Valiant,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Valiant - Linked with previous event - Despawn in 1 ms');
-- Argent Valiants texts
DELETE FROM `creature_text` WHERE `entry`= @Orgri_Valiant;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@Orgri_Valiant,0,0,'Ready yourself!',12,1,100,0,0,0,'Argent Valiant', 33757),
(@Orgri_Valiant,0,1,'Prepare yourself!',12,1,100,0,0,0,'Argent Valiant', 33755),
(@Orgri_Valiant,0,2,'On your guard!',12,1,100,0,0,0,'Argent Valiant', 33756),
(@Orgri_Valiant,0,3,'Let it begin!',12,1,100,0,0,0,'Argent Valiant', 33758),
(@Orgri_Valiant,1,0,'Victory is mine!',12,1,100,0,0,0,'Argent Valiant', 33777),
(@Orgri_Valiant,1,1,'It seems you still need more practice. Perhaps another time.',12,1,100,0,0,0,'Argent Valiant', 33764),
(@Orgri_Valiant,1,2,'I have won. Better luck another time, friend.',12,1,100,0,0,0,'Argent Valiant', 33779),
(@Orgri_Valiant,1,3,'I am afraid you will need more practice to defeat me.',12,1,100,0,0,0,'Argent Valiant', 33778),
(@Orgri_Valiant,2,0,'I yield to you.',12,1,100,0,0,0,'Argent Valiant', 33774),
(@Orgri_Valiant,2,1,'That was a well fought battle. I yield to you.',12,1,100,0,0,0,'Argent Valiant', 33776),
(@Orgri_Valiant,2,2,'It would seem I underestimated your skills. Well done.',12,1,100,0,0,0,'Argent Valiant', 33775),
(@Orgri_Valiant,2,3,'I have been defeated. Good fight!',12,1,100,0,0,0,'Argent Valiant', 33760);
SET @TB_Valiant := 33383;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@TB_Valiant;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TB_Valiant;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TB_Valiant,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Valiant - On Reset - Remove auras from Defend'),
(@TB_Valiant,0,1,2,62,0,100,0,10472,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'TB Valiant - On gossip select - Close gossip'),
(@TB_Valiant,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'TB_Valiant - Linked with previous event - store target'),
(@TB_Valiant,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'TB Valiant - Linked with previous event - Call timed actionlist'),
(@TB_Valiant,0,4,0,52,0,100,0,0,@TB_Valiant,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'TB Valiant - On text over - Cast Charge'),
(@TB_Valiant,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'TB Valiant - IC - Cast Thrust'),
(@TB_Valiant,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'TB Valiant - On more than 5 yard range - Cast Shield-Breaker'),
(@TB_Valiant,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Valiant - IC - Move forward 12 yards'),
(@TB_Valiant,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'TB Valiant - On 10-12 yard range - Cast Charge'),
(@TB_Valiant,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'TB Valiant - Linked with previous event - Cast Shield-Breaker'),
(@TB_Valiant,0,10,11,2,0,100,1,1,3,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Valiant - On HP% between 1% and 3% - Change faction to 35'),
(@TB_Valiant,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Valiant - Linked with previous event - Say text'),
(@TB_Valiant,0,12,13,61,0,100,0,0,0,0,0,85,62724,0,0,0,0,0,12,1,0,0,0,0,0,0,'TB Valiant - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@TB_Valiant,0,13,14,61,0,100,0,0,0,0,0,85,64815,0,0,0,0,0,12,1,0,0,0,0,0,0,'TB Valiant - Linked with previous event - Cast credit'),
(@TB_Valiant,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB_Valiant - Linked with previous event - Evade'),
(@TB_Valiant,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Valiant - On player killed - Say text'),
(@TB_Valiant,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Valiant - Linked with previous event - Set unseen'),
(@TB_Valiant,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Valiant - Linked with previous event - Despawn in 1 ms');
-- Argent Valiants texts
DELETE FROM `creature_text` WHERE `entry`= @TB_Valiant;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@TB_Valiant,0,0,'Ready yourself!',12,1,100,0,0,0,'Argent Valiant', 33757),
(@TB_Valiant,0,1,'Prepare yourself!',12,1,100,0,0,0,'Argent Valiant', 33755),
(@TB_Valiant,0,2,'On your guard!',12,1,100,0,0,0,'Argent Valiant', 33756),
(@TB_Valiant,0,3,'Let it begin!',12,1,100,0,0,0,'Argent Valiant', 33758),
(@TB_Valiant,1,0,'Victory is mine!',12,1,100,0,0,0,'Argent Valiant', 33777),
(@TB_Valiant,1,1,'It seems you still need more practice. Perhaps another time.',12,1,100,0,0,0,'Argent Valiant', 33764),
(@TB_Valiant,1,2,'I have won. Better luck another time, friend.',12,1,100,0,0,0,'Argent Valiant', 33779),
(@TB_Valiant,1,3,'I am afraid you will need more practice to defeat me.',12,1,100,0,0,0,'Argent Valiant', 33778),
(@TB_Valiant,2,0,'I yield to you.',12,1,100,0,0,0,'Argent Valiant', 33774),
(@TB_Valiant,2,1,'That was a well fought battle. I yield to you.',12,1,100,0,0,0,'Argent Valiant', 33776),
(@TB_Valiant,2,2,'It would seem I underestimated your skills. Well done.',12,1,100,0,0,0,'Argent Valiant', 33775),
(@TB_Valiant,2,3,'I have been defeated. Good fight!',12,1,100,0,0,0,'Argent Valiant', 33760);
SET @SM_Valiant := 33382;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@SM_Valiant;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SM_Valiant;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SM_Valiant,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Valiant - On Reset - Remove auras from Defend'),
(@SM_Valiant,0,1,2,62,0,100,0,10470,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'SM Valiant - On gossip select - Close gossip'),
(@SM_Valiant,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'SM_Valiant - Linked with previous event - store target'),
(@SM_Valiant,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'SM Valiant - Linked with previous event - Call timed actionlist'),
(@SM_Valiant,0,4,0,52,0,100,0,0,@SM_Valiant,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'SM Valiant - On text over - Cast Charge'),
(@SM_Valiant,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'SM Valiant - IC - Cast Thrust'),
(@SM_Valiant,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'SM Valiant - On more than 5 yard range - Cast Shield-Breaker'),
(@SM_Valiant,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Valiant - IC - Move forward 12 yards'),
(@SM_Valiant,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'SM Valiant - On 10-12 yard range - Cast Charge'),
(@SM_Valiant,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'SM Valiant - Linked with previous event - Cast Shield-Breaker'),
(@SM_Valiant,0,10,11,2,0,100,1,1,3,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Valiant - On HP% between 1% and 3% - Change faction to 35'),
(@SM_Valiant,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Valiant - Linked with previous event - Say text'),
(@SM_Valiant,0,12,13,61,0,100,0,0,0,0,0,85,62724,0,0,0,0,0,12,1,0,0,0,0,0,0,'SM Valiant - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@SM_Valiant,0,13,14,61,0,100,0,0,0,0,0,85,64813,0,0,0,0,0,12,1,0,0,0,0,0,0,'SM Valiant - Linked with previous event - Cast credit'),
(@SM_Valiant,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM_Valiant - Linked with previous event - Evade'),
(@SM_Valiant,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Valiant - On player killed - Say text'),
(@SM_Valiant,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Valiant - Linked with previous event - Set unseen'),
(@SM_Valiant,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Valiant - Linked with previous event - Despawn in 1 ms');
-- Argent Valiants texts
DELETE FROM `creature_text` WHERE `entry`= @SM_Valiant;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@SM_Valiant,0,0,'Ready yourself!',12,1,100,0,0,0,'Argent Valiant', 33757),
(@SM_Valiant,0,1,'Prepare yourself!',12,1,100,0,0,0,'Argent Valiant', 33755),
(@SM_Valiant,0,2,'On your guard!',12,1,100,0,0,0,'Argent Valiant', 33756),
(@SM_Valiant,0,3,'Let it begin!',12,1,100,0,0,0,'Argent Valiant', 33758),
(@SM_Valiant,1,0,'Victory is mine!',12,1,100,0,0,0,'Argent Valiant', 33777),
(@SM_Valiant,1,1,'It seems you still need more practice. Perhaps another time.',12,1,100,0,0,0,'Argent Valiant', 33764),
(@SM_Valiant,1,2,'I have won. Better luck another time, friend.',12,1,100,0,0,0,'Argent Valiant', 33779),
(@SM_Valiant,1,3,'I am afraid you will need more practice to defeat me.',12,1,100,0,0,0,'Argent Valiant', 33778),
(@SM_Valiant,2,0,'I yield to you.',12,1,100,0,0,0,'Argent Valiant', 33774),
(@SM_Valiant,2,1,'That was a well fought battle. I yield to you.',12,1,100,0,0,0,'Argent Valiant', 33776),
(@SM_Valiant,2,2,'It would seem I underestimated your skills. Well done.',12,1,100,0,0,0,'Argent Valiant', 33775),
(@SM_Valiant,2,3,'I have been defeated. Good fight!',12,1,100,0,0,0,'Argent Valiant', 33760);
SET @GR_Valiant := 33558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@GR_Valiant;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GR_Valiant;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GR_Valiant,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Valiant - On Reset - Remove auras from Defend'),
(@GR_Valiant,0,1,2,62,0,100,0,10466,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'GR Valiant - On gossip select - Close gossip'),
(@GR_Valiant,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'GR_Valiant - Linked with previous event - store target'),
(@GR_Valiant,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'GR Valiant - Linked with previous event - Call timed actionlist'),
(@GR_Valiant,0,4,0,52,0,100,0,0,@GR_Valiant,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'GR Valiant - On text over - Cast Charge'),
(@GR_Valiant,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'GR Valiant - IC - Cast Thrust'),
(@GR_Valiant,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'GR Valiant - On more than 5 yard range - Cast Shield-Breaker'),
(@GR_Valiant,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Valiant - IC - Move forward 12 yards'),
(@GR_Valiant,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'GR Valiant - On 10-12 yard range - Cast Charge'),
(@GR_Valiant,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'GR Valiant - Linked with previous event - Cast Shield-Breaker'),
(@GR_Valiant,0,10,11,2,0,100,1,1,3,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Valiant - On HP% between 1% and 3% - Change faction to 35'),
(@GR_Valiant,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Valiant - Linked with previous event - Say text'),
(@GR_Valiant,0,12,13,61,0,100,0,0,0,0,0,85,62724,0,0,0,0,0,12,1,0,0,0,0,0,0,'GR Valiant - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@GR_Valiant,0,13,14,61,0,100,0,0,0,0,0,85,64809,0,0,0,0,0,12,1,0,0,0,0,0,0,'GR Valiant - Linked with previous event - Cast credit'),
(@GR_Valiant,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR_Valiant - Linked with previous event - Evade'),
(@GR_Valiant,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Valiant - On player killed - Say text'),
(@GR_Valiant,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Valiant - Linked with previous event - Set unseen'),
(@GR_Valiant,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Valiant - Linked with previous event - Despawn in 1 ms');
-- Argent Valiants texts
DELETE FROM `creature_text` WHERE `entry`= @GR_Valiant;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@GR_Valiant,0,0,'Ready yourself!',12,7,100,0,0,0,'Argent Valiant', 33757),
(@GR_Valiant,0,1,'Prepare yourself!',12,7,100,0,0,0,'Argent Valiant', 33755),
(@GR_Valiant,0,2,'On your guard!',12,7,100,0,0,0,'Argent Valiant', 33756),
(@GR_Valiant,0,3,'Let it begin!',12,7,100,0,0,0,'Argent Valiant', 33758),
(@GR_Valiant,1,0,'Victory is mine!',12,7,100,0,0,0,'Argent Valiant', 33777),
(@GR_Valiant,1,1,'It seems you still need more practice. Perhaps another time.',12,7,100,0,0,0,'Argent Valiant', 33764),
(@GR_Valiant,1,2,'I have won. Better luck another time, friend.',12,7,100,0,0,0,'Argent Valiant', 33779),
(@GR_Valiant,1,3,'I am afraid you will need more practice to defeat me.',12,7,100,0,0,0,'Argent Valiant', 33778),
(@GR_Valiant,2,0,'I yield to you.',12,7,100,0,0,0,'Argent Valiant', 33774),
(@GR_Valiant,2,1,'That was a well fought battle. I yield to you.',12,7,100,0,0,0,'Argent Valiant', 33776),
(@GR_Valiant,2,2,'It would seem I underestimated your skills. Well done.',12,7,100,0,0,0,'Argent Valiant', 33775),
(@GR_Valiant,2,3,'I have been defeated. Good fight!',12,7,100,0,0,0,'Argent Valiant', 33760);
SET @IF_Valiant := 33564;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@IF_Valiant;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@IF_Valiant;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@IF_Valiant,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Valiant - On Reset - Remove auras from Defend'),
(@IF_Valiant,0,1,2,62,0,100,0,10467,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'IF Valiant - On gossip select - Close gossip'),
(@IF_Valiant,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'IF_Valiant - Linked with previous event - store target'),
(@IF_Valiant,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'IF Valiant - Linked with previous event - Call timed actionlist'),
(@IF_Valiant,0,4,0,52,0,100,0,0,@IF_Valiant,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'IF Valiant - On text over - Cast Charge'),
(@IF_Valiant,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'IF Valiant - IC - Cast Thrust'),
(@IF_Valiant,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'IF Valiant - On more than 5 yard range - Cast Shield-Breaker'),
(@IF_Valiant,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Valiant - IC - Move forward 12 yards'),
(@IF_Valiant,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'IF Valiant - On 10-12 yard range - Cast Charge'),
(@IF_Valiant,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'IF Valiant - Linked with previous event - Cast Shield-Breaker'),
(@IF_Valiant,0,10,11,2,0,100,1,1,3,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Valiant - On HP% between 1% and 3% - Change faction to 35'),
(@IF_Valiant,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Valiant - Linked with previous event - Say text'),
(@IF_Valiant,0,12,13,61,0,100,0,0,0,0,0,85,62724,0,0,0,0,0,12,1,0,0,0,0,0,0,'IF Valiant - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@IF_Valiant,0,13,14,61,0,100,0,0,0,0,0,85,64810,0,0,0,0,0,12,1,0,0,0,0,0,0,'IF Valiant - Linked with previous event - Cast credit'),
(@IF_Valiant,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF_Valiant - Linked with previous event - Evade'),
(@IF_Valiant,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Valiant - On player killed - Say text'),
(@IF_Valiant,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Valiant - Linked with previous event - Set unseen'),
(@IF_Valiant,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Valiant - Linked with previous event - Despawn in 1 ms');
-- Argent Valiants texts
DELETE FROM `creature_text` WHERE `entry`= @IF_Valiant;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@IF_Valiant,0,0,'Ready yourself!',12,7,100,0,0,0,'Argent Valiant', 33757),
(@IF_Valiant,0,1,'Prepare yourself!',12,7,100,0,0,0,'Argent Valiant', 33755),
(@IF_Valiant,0,2,'On your guard!',12,7,100,0,0,0,'Argent Valiant', 33756),
(@IF_Valiant,0,3,'Let it begin!',12,7,100,0,0,0,'Argent Valiant', 33758),
(@IF_Valiant,1,0,'Victory is mine!',12,7,100,0,0,0,'Argent Valiant', 33777),
(@IF_Valiant,1,1,'It seems you still need more practice. Perhaps another time.',12,7,100,0,0,0,'Argent Valiant', 33764),
(@IF_Valiant,1,2,'I have won. Better luck another time, friend.',12,7,100,0,0,0,'Argent Valiant', 33779),
(@IF_Valiant,1,3,'I am afraid you will need more practice to defeat me.',12,7,100,0,0,0,'Argent Valiant', 33778),
(@IF_Valiant,2,0,'I yield to you.',12,7,100,0,0,0,'Argent Valiant', 33774),
(@IF_Valiant,2,1,'That was a well fought battle. I yield to you.',12,7,100,0,0,0,'Argent Valiant', 33776),
(@IF_Valiant,2,2,'It would seem I underestimated your skills. Well done.',12,7,100,0,0,0,'Argent Valiant', 33775),
(@IF_Valiant,2,3,'I have been defeated. Good fight!',12,7,100,0,0,0,'Argent Valiant', 33760);
SET @SW_Valiant := 33561;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@SW_Valiant;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SW_Valiant;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SW_Valiant,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Valiant - On Reset - Remove auras from Defend'),
(@SW_Valiant,0,1,2,62,0,100,0,10471,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'SW Valiant - On gossip select - Close gossip'),
(@SW_Valiant,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'SW_Valiant - Linked with previous event - store target'),
(@SW_Valiant,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'SW Valiant - Linked with previous event - Call timed actionlist'),
(@SW_Valiant,0,4,0,52,0,100,0,0,@SW_Valiant,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'SW Valiant - On text over - Cast Charge'),
(@SW_Valiant,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'SW Valiant - IC - Cast Thrust'),
(@SW_Valiant,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'SW Valiant - On more than 5 yard range - Cast Shield-Breaker'),
(@SW_Valiant,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Valiant - IC - Move forward 12 yards'),
(@SW_Valiant,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'SW Valiant - On 10-12 yard range - Cast Charge'),
(@SW_Valiant,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'SW Valiant - Linked with previous event - Cast Shield-Breaker'),
(@SW_Valiant,0,10,11,2,0,100,1,1,3,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Valiant - On HP% between 1% and 3% - Change faction to 35'),
(@SW_Valiant,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Valiant - Linked with previous event - Say text'),
(@SW_Valiant,0,12,13,61,0,100,0,0,0,0,0,85,62724,0,0,0,0,0,12,1,0,0,0,0,0,0,'SW Valiant - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@SW_Valiant,0,13,14,61,0,100,0,0,0,0,0,85,64814,0,0,0,0,0,12,1,0,0,0,0,0,0,'SW Valiant - Linked with previous event - Cast credit'),
(@SW_Valiant,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW_Valiant - Linked with previous event - Evade'),
(@SW_Valiant,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Valiant - On player killed - Say text'),
(@SW_Valiant,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Valiant - Linked with previous event - Set unseen'),
(@SW_Valiant,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Valiant - Linked with previous event - Despawn in 1 ms');
-- Argent Valiants texts
DELETE FROM `creature_text` WHERE `entry`= @SW_Valiant;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@SW_Valiant,0,0,'Ready yourself!',12,7,100,0,0,0,'Argent Valiant', 33757),
(@SW_Valiant,0,1,'Prepare yourself!',12,7,100,0,0,0,'Argent Valiant', 33755),
(@SW_Valiant,0,2,'On your guard!',12,7,100,0,0,0,'Argent Valiant', 33756),
(@SW_Valiant,0,3,'Let it begin!',12,7,100,0,0,0,'Argent Valiant', 33758),
(@SW_Valiant,1,0,'Victory is mine!',12,7,100,0,0,0,'Argent Valiant', 33777),
(@SW_Valiant,1,1,'It seems you still need more practice. Perhaps another time.',12,7,100,0,0,0,'Argent Valiant', 33764),
(@SW_Valiant,1,2,'I have won. Better luck another time, friend.',12,7,100,0,0,0,'Argent Valiant', 33779),
(@SW_Valiant,1,3,'I am afraid you will need more practice to defeat me.',12,7,100,0,0,0,'Argent Valiant', 33778),
(@SW_Valiant,2,0,'I yield to you.',12,7,100,0,0,0,'Argent Valiant', 33774),
(@SW_Valiant,2,1,'That was a well fought battle. I yield to you.',12,7,100,0,0,0,'Argent Valiant', 33776),
(@SW_Valiant,2,2,'It would seem I underestimated your skills. Well done.',12,7,100,0,0,0,'Argent Valiant', 33775),
(@SW_Valiant,2,3,'I have been defeated. Good fight!',12,7,100,0,0,0,'Argent Valiant', 33760);
SET @Darn_Valiant := 33559;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Darn_Valiant;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Darn_Valiant;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Darn_Valiant,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Valiant - On Reset - Remove auras from Defend'),
(@Darn_Valiant,0,1,2,62,0,100,0,10464,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Darn Valiant - On gossip select - Close gossip'),
(@Darn_Valiant,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Darn_Valiant - Linked with previous event - store target'),
(@Darn_Valiant,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Valiant - Linked with previous event - Call timed actionlist'),
(@Darn_Valiant,0,4,0,52,0,100,0,0,@Darn_Valiant,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'Darn Valiant - On text over - Cast Charge'),
(@Darn_Valiant,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'Darn Valiant - IC - Cast Thrust'),
(@Darn_Valiant,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Darn Valiant - On more than 5 yard range - Cast Shield-Breaker'),
(@Darn_Valiant,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Valiant - IC - Move forward 12 yards'),
(@Darn_Valiant,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Darn Valiant - On 10-12 yard range - Cast Charge'),
(@Darn_Valiant,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Darn Valiant - Linked with previous event - Cast Shield-Breaker'),
(@Darn_Valiant,0,10,11,2,0,100,1,1,3,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Valiant - On HP% between 1% and 3% - Change faction to 35'),
(@Darn_Valiant,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Valiant - Linked with previous event - Say text'),
(@Darn_Valiant,0,12,13,61,0,100,0,0,0,0,0,85,62724,0,0,0,0,0,12,1,0,0,0,0,0,0,'Darn Valiant - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@Darn_Valiant,0,13,14,61,0,100,0,0,0,0,0,85,64805,0,0,0,0,0,12,1,0,0,0,0,0,0,'Darn Valiant - Linked with previous event - Cast credit'),
(@Darn_Valiant,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn_Valiant - Linked with previous event - Evade'),
(@Darn_Valiant,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Valiant - On player killed - Say text'),
(@Darn_Valiant,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Valiant - Linked with previous event - Set unseen'),
(@Darn_Valiant,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Valiant - Linked with previous event - Despawn in 1 ms');
-- Argent Valiants texts
DELETE FROM `creature_text` WHERE `entry`= @Darn_Valiant;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@Darn_Valiant,0,0,'Ready yourself!',12,7,100,0,0,0,'Argent Valiant', 33757),
(@Darn_Valiant,0,1,'Prepare yourself!',12,7,100,0,0,0,'Argent Valiant', 33755),
(@Darn_Valiant,0,2,'On your guard!',12,7,100,0,0,0,'Argent Valiant', 33756),
(@Darn_Valiant,0,3,'Let it begin!',12,7,100,0,0,0,'Argent Valiant', 33758),
(@Darn_Valiant,1,0,'Victory is mine!',12,7,100,0,0,0,'Argent Valiant', 33777),
(@Darn_Valiant,1,1,'It seems you still need more practice. Perhaps another time.',12,7,100,0,0,0,'Argent Valiant', 33764),
(@Darn_Valiant,1,2,'I have won. Better luck another time, friend.',12,7,100,0,0,0,'Argent Valiant', 33779),
(@Darn_Valiant,1,3,'I am afraid you will need more practice to defeat me.',12,7,100,0,0,0,'Argent Valiant', 33778),
(@Darn_Valiant,2,0,'I yield to you.',12,7,100,0,0,0,'Argent Valiant', 33774),
(@Darn_Valiant,2,1,'That was a well fought battle. I yield to you.',12,7,100,0,0,0,'Argent Valiant', 33776),
(@Darn_Valiant,2,2,'It would seem I underestimated your skills. Well done.',12,7,100,0,0,0,'Argent Valiant', 33775),
(@Darn_Valiant,2,3,'I have been defeated. Good fight!',12,7,100,0,0,0,'Argent Valiant', 33760);
SET @Exo_Valiant := 33562;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Exo_Valiant;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Exo_Valiant;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Exo_Valiant,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Valiant - On Reset - Remove auras from Defend'),
(@Exo_Valiant,0,1,2,62,0,100,0,10465,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Exo Valiant - On gossip select - Close gossip'),
(@Exo_Valiant,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Exo_Valiant - Linked with previous event - store target'),
(@Exo_Valiant,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Valiant - Linked with previous event - Call timed actionlist'),
(@Exo_Valiant,0,4,0,52,0,100,0,0,@Exo_Valiant,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'Exo Valiant - On text over - Cast Charge'),
(@Exo_Valiant,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'Exo Valiant - IC - Cast Thrust'),
(@Exo_Valiant,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Exo Valiant - On more than 5 yard range - Cast Shield-Breaker'),
(@Exo_Valiant,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Valiant - IC - Move forward 12 yards'),
(@Exo_Valiant,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Exo Valiant - On 10-12 yard range - Cast Charge'),
(@Exo_Valiant,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Exo Valiant - Linked with previous event - Cast Shield-Breaker'),
(@Exo_Valiant,0,10,11,2,0,100,1,1,3,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Valiant - On HP% between 1% and 3% - Change faction to 35'),
(@Exo_Valiant,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Valiant - Linked with previous event - Say text'),
(@Exo_Valiant,0,12,13,61,0,100,0,0,0,0,0,85,62724,0,0,0,0,0,12,1,0,0,0,0,0,0,'Exo Valiant - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@Exo_Valiant,0,13,14,61,0,100,0,0,0,0,0,85,64808,0,0,0,0,0,12,1,0,0,0,0,0,0,'Exo Valiant - Linked with previous event - Cast credit'),
(@Exo_Valiant,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo_Valiant - Linked with previous event - Evade'),
(@Exo_Valiant,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Valiant - On player killed - Say text'),
(@Exo_Valiant,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Valiant - Linked with previous event - Set unseen'),
(@Exo_Valiant,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Valiant - Linked with previous event - Despawn in 1 ms');
-- Argent Valiants texts
DELETE FROM `creature_text` WHERE `entry`= @Exo_Valiant;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@Exo_Valiant,0,0,'Ready yourself!',12,7,100,0,0,0,'Argent Valiant', 33757),
(@Exo_Valiant,0,1,'Prepare yourself!',12,7,100,0,0,0,'Argent Valiant', 33755),
(@Exo_Valiant,0,2,'On your guard!',12,7,100,0,0,0,'Argent Valiant', 33756),
(@Exo_Valiant,0,3,'Let it begin!',12,7,100,0,0,0,'Argent Valiant', 33758),
(@Exo_Valiant,1,0,'Victory is mine!',12,7,100,0,0,0,'Argent Valiant', 33777),
(@Exo_Valiant,1,1,'It seems you still need more practice. Perhaps another time.',12,7,100,0,0,0,'Argent Valiant', 33764),
(@Exo_Valiant,1,2,'I have won. Better luck another time, friend.',12,7,100,0,0,0,'Argent Valiant', 33779),
(@Exo_Valiant,1,3,'I am afraid you will need more practice to defeat me.',12,7,100,0,0,0,'Argent Valiant', 33778),
(@Exo_Valiant,2,0,'I yield to you.',12,7,100,0,0,0,'Argent Valiant', 33774),
(@Exo_Valiant,2,1,'That was a well fought battle. I yield to you.',12,7,100,0,0,0,'Argent Valiant', 33776),
(@Exo_Valiant,2,2,'It would seem I underestimated your skills. Well done.',12,7,100,0,0,0,'Argent Valiant', 33775),
(@Exo_Valiant,2,3,'I have been defeated. Good fight!',12,7,100,0,0,0,'Argent Valiant', 33760);
SET @UC_Valiant := 33384;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@UC_Valiant;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@UC_Valiant;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@UC_Valiant,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Valiant - On Reset - Remove auras from Defend'),
(@UC_Valiant,0,1,2,62,0,100,0,10473,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'UC Valiant - On gossip select - Close gossip'),
(@UC_Valiant,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'UC_Valiant - Linked with previous event - store target'),
(@UC_Valiant,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'UC Valiant - Linked with previous event - Call timed actionlist'),
(@UC_Valiant,0,4,0,52,0,100,0,0,@UC_Valiant,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'UC Valiant - On text over - Cast Charge'),
(@UC_Valiant,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'UC Valiant - IC - Cast Thrust'),
(@UC_Valiant,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'UC Valiant - On more than 5 yard range - Cast Shield-Breaker'),
(@UC_Valiant,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Valiant - IC - Move forward 12 yards'),
(@UC_Valiant,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'UC Valiant - On 10-12 yard range - Cast Charge'),
(@UC_Valiant,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'UC Valiant - Linked with previous event - Cast Shield-Breaker'),
(@UC_Valiant,0,10,11,2,0,100,1,1,3,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Valiant - On HP% between 1% and 3% - Change faction to 35'),
(@UC_Valiant,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Valiant - Linked with previous event - Say text'),
(@UC_Valiant,0,12,13,61,0,100,0,0,0,0,0,85,62724,0,0,0,0,0,12,1,0,0,0,0,0,0,'UC Valiant - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@UC_Valiant,0,13,14,61,0,100,0,0,0,0,0,85,64816,0,0,0,0,0,12,1,0,0,0,0,0,0,'UC Valiant - Linked with previous event - Cast credit'),
(@UC_Valiant,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC_Valiant - Linked with previous event - Evade'),
(@UC_Valiant,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Valiant - On player killed - Say text'),
(@UC_Valiant,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Valiant - Linked with previous event - Set unseen'),
(@UC_Valiant,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Valiant - Linked with previous event - Despawn in 1 ms');
-- Argent Valiants texts
DELETE FROM `creature_text` WHERE `entry`= @UC_Valiant;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@UC_Valiant,0,0,'Ready yourself!',12,1,100,0,0,0,'Argent Valiant', 33757),
(@UC_Valiant,0,1,'Prepare yourself!',12,1,100,0,0,0,'Argent Valiant', 33755),
(@UC_Valiant,0,2,'On your guard!',12,1,100,0,0,0,'Argent Valiant', 33756),
(@UC_Valiant,0,3,'Let it begin!',12,1,100,0,0,0,'Argent Valiant', 33758),
(@UC_Valiant,1,0,'Victory is mine!',12,1,100,0,0,0,'Argent Valiant', 33777),
(@UC_Valiant,1,1,'It seems you still need more practice. Perhaps another time.',12,1,100,0,0,0,'Argent Valiant', 33764),
(@UC_Valiant,1,2,'I have won. Better luck another time, friend.',12,1,100,0,0,0,'Argent Valiant', 33779),
(@UC_Valiant,1,3,'I am afraid you will need more practice to defeat me.',12,1,100,0,0,0,'Argent Valiant', 33778),
(@UC_Valiant,2,0,'I yield to you.',12,1,100,0,0,0,'Argent Valiant', 33774),
(@UC_Valiant,2,1,'That was a well fought battle. I yield to you.',12,1,100,0,0,0,'Argent Valiant', 33776),
(@UC_Valiant,2,2,'It would seem I underestimated your skills. Well done.',12,1,100,0,0,0,'Argent Valiant', 33775),
(@UC_Valiant,2,3,'I have been defeated. Good fight!',12,1,100,0,0,0,'Argent Valiant', 33760);

DELETE FROM `gossip_menu` WHERE `entry` IN (10469, 10468, 10470, 10472, 10473, 10466, 10464, 10471, 10465, 10467);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10469, 14384),
(10469, 14492),
(10468, 14384),
(10468, 14492),
(10470, 14384),
(10470, 14492),
(10472, 14384),
(10472, 14492),
(10473, 14384),
(10473, 14492),
(10466, 14384),
(10466, 14492),
(10464, 14384),
(10464, 14492),
(10471, 14384),
(10471, 14492),
(10465, 14384),
(10465, 14492),
(10467, 14384),
(10467, 14492);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (10469, 10468, 10470, 10472, 10473, 10466, 10464, 10471, 10465, 10467);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14,10469,14384,0,1,64812,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10469,14492,0,1,64812,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10468,14384,0,1,64811,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10468,14492,0,1,64811,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10470,14384,0,1,64813,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10470,14492,0,1,64813,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10472,14384,0,1,64815,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10472,14492,0,1,64815,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10473,14384,0,1,64816,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10473,14492,0,1,64816,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10466,14384,0,1,64809,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10466,14492,0,1,64809,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10464,14384,0,1,64805,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10464,14492,0,1,64805,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10471,14384,0,1,64814,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10471,14492,0,1,64814,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10465,14384,0,1,64808,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10465,14492,0,1,64808,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10467,14384,0,1,64810,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10467,14492,0,1,64810,0,0,0,'','Show gossip menu text if the player have the aura', 0);
--
UPDATE `creature_text` SET `groupid`=0, `id`=1, `comment`='engineer helice SAY_WP_1' WHERE `entry`=28787 AND `BroadcastTextId`=28856;
UPDATE `creature_text` SET `groupid`=6, `id`=1, `COMMENT`='engineer helice SAY_WP_7' WHERE `entry`=28787 AND `BroadcastTextId`=28865;
UPDATE `creature_text` SET `groupid`=1, `id`=1, `COMMENT`='engineer helice SAY_WP_2' WHERE `entry`=28787 AND `BroadcastTextId`=28857;
UPDATE `creature_text` SET `groupid`=2, `id`=1, `COMMENT`='engineer helice SAY_WP_3' WHERE `entry`=28787 AND `BroadcastTextId`=28859;
UPDATE `creature_text` SET `groupid`=5, `id`=1, `COMMENT`='engineer helice SAY_WP_6' WHERE `entry`=28787 AND `BroadcastTextId`=28864;
UPDATE `creature_text` SET `groupid`=4, `id`=1, `COMMENT`='engineer helice SAY_WP_5' WHERE `entry`=28787 AND `BroadcastTextId`=28862;
--
UPDATE `smart_scripts` SET `event_type`=25, `event_flags`=0 WHERE `entryorguid` IN (21784,21815, 21801) AND `source_type`=0 AND `id`=0;

DELETE FROM `creature_formations` WHERE `leaderGUID`=76082;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(76082,76082,0,0,2),
(76082,76083,7,360,2),
(76082,76084,14,360,2),
(76082,76085,21,360,2);

UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid` IN (76083, 76084, 76085);
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (76082);
DELETE FROM `creature_addon` WHERE `guid` IN (76082);
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`, `emote`, `auras`) VALUES
(76082,760820,16777216,4097,0,"");
DELETE FROM `creature` WHERE `id`=21998; -- wrong spawn, must be summoned by quest item only

DELETE FROM `waypoint_data` WHERE (`id`=760820);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(760820, 1, -3116.419922, 821.828979, -21.856766, 0, 0, 1, 0, 100, 0),
(760820, 2, -3127.299561, 795.134766, -22.401117, 0, 0, 1, 0, 100, 0),
(760820, 3, -3150.103027, 782.489380, -21.864737, 0, 0, 1, 0, 100, 0),
(760820, 4, -3219.880615, 780.314880, -19.754417, 0, 0, 1, 0, 100, 0),
(760820, 5, -3251.568604, 783.067688, -19.069899, 0, 0, 1, 0, 100, 0),
(760820, 6, -3295.924072, 767.111877, -21.192102, 0, 0, 1, 0, 100, 0),
(760820, 7, -3403.222656, 752.732056, -35.531361, 0, 0, 1, 0, 100, 0),
(760820, 8, -3617.548828, 732.945862, -8.339263, 0, 0, 1, 0, 100, 0),
(760820, 9, -3631.188965, 727.337463, -5.722647, 0, 0, 1, 0, 100, 0),
(760820, 10, -3733.907471, 751.174744, 7.209823, 0, 0, 1, 0, 100, 0),
(760820, 11, -3782.882813, 746.945984, 9.761057, 0, 0, 1, 0, 100, 0),
(760820, 12, -3859.570068, 752.093506, 10.382468, 0, 0, 1, 0, 100, 0),
(760820, 13, -3879.040283, 773.671936, 9.449715, 0, 0, 1, 0, 100, 0),
(760820, 14, -3888.581787, 854.766663, 15.828053, 0, 0, 1, 0, 100, 0),
(760820, 15, -3880.752930, 897.569763, 19.081347, 0, 0, 1, 0, 100, 0),
(760820, 16, -3886.515137, 944.770691, 21.956785, 0, 0, 1, 0, 100, 0),
(760820, 17, -3880.704834, 985.264221, 23.311592, 0, 0, 1, 0, 100, 0),
(760820, 18, -3883.812012, 1007.772705, 23.589699, 0, 0, 1, 0, 100, 0),
(760820, 19, -3975.737061, 1099.026733, 30.213566, 0, 0, 1, 0, 100, 0),
(760820, 20, -4000.627197, 1143.911499, 41.125046, 0, 0, 1, 0, 100, 0),
(760820, 21, -4036.700928, 1163.023804, 51.072033, 0, 0, 1, 0, 100, 0),
(760820, 22, -4052.043457, 1183.807129, 57.569439, 0, 0, 1, 0, 100, 0),
(760820, 23, -4053.111816, 1202.003784, 62.920666, 0, 0, 1, 0, 100, 0),
(760820, 24, -4037.213623, 1261.900757, 78.336632, 0, 0, 1, 0, 100, 0),
(760820, 25, -4038.152588, 1296.390991, 83.919540, 0, 0, 1, 0, 100, 0),
(760820, 26, -4053.791504, 1370.539185, 84.908981, 0, 0, 1, 0, 100, 0),
(760820, 27, -4054.700439, 1618.686279, 93.997330, 0, 0, 1, 0, 100, 0),
(760820, 28, -4045.018799, 1643.987061, 94.251122, 0, 0, 1, 0, 100, 0),
(760820, 29, -3983.812988, 1705.642944, 97.803833, 0, 0, 1, 0, 100, 0),
(760820, 30, -3938.369141, 1738.914917, 98.837524, 0, 0, 1, 0, 100, 0),
(760820, 31, -3900.309814, 1758.672363, 97.922089, 0, 0, 1, 0, 100, 0),
(760820, 32, -3867.449707, 1786.059937, 94.361740, 0, 0, 1, 0, 100, 0),
(760820, 33, -3850.530273, 1826.876221, 90.358040, 0, 0, 1, 0, 100, 0),
(760820, 34, -3847.338867, 1880.751831, 86.640762, 0, 0, 1, 0, 100, 0),
(760820, 35, -3814.812988, 1960.993286, 85.844566, 0, 0, 1, 0, 100, 0),
(760820, 36, -3756.163574, 2030.727905, 84.516495, 0, 0, 1, 0, 100, 0),
(760820, 37, -3752.126221, 2094.629395, 78.208092, 0, 0, 1, 0, 100, 0),
(760820, 38, -3755.360352, 2146.251221, 75.892380, 0, 0, 1, 0, 100, 0),
(760820, 39, -3743.547119, 2204.366699, 76.086136, 0, 0, 1, 0, 100, 0),
(760820, 40, -3744.448975, 2262.760742, 76.763046, 0, 0, 1, 0, 100, 0),
(760820, 41, -3714.628662, 2328.074219, 76.275826, 0, 0, 1, 0, 100, 0),
(760820, 42, -3688.062256, 2347.847168, 76.348412, 0, 0, 1, 0, 100, 0),
(760820, 43, -3674.596680, 2318.612061, 75.835876, 0, 0, 1, 0, 100, 0),
(760820, 44, -3624.145264, 2310.810791, 74.901398, 0, 0, 1, 0, 100, 0),
(760820, 45, -3596.897217, 2321.221191, 73.494583, 0, 0, 1, 0, 100, 0),
(760820, 46, -3570.569824, 2315.111572, 71.091606, 0, 0, 1, 0, 100, 0),
(760820, 47, -3505.514648, 2275.580811, 66.201355, 0, 0, 1, 0, 100, 0),
(760820, 48, -3444.574219, 2289.437500, 63.707752, 0, 0, 1, 0, 100, 0),
(760820, 49, -3402.431396, 2291.413818, 62.819668, 0, 0, 1, 0, 100, 0),
(760820, 50, -3344.245605, 2280.061523, 61.217396, 0, 0, 1, 0, 100, 0),
(760820, 51, -3266.743164, 2283.391113, 60.007225, 0, 0, 1, 0, 100, 0),
(760820, 52, -3233.561279, 2292.924561, 59.882648, 0, 0, 1, 0, 100, 0),
(760820, 53, -3221.570313, 2250.202393, 61.123081, 0, 0, 1, 0, 100, 0),
(760820, 54, -3189.590088, 2199.339844, 64.705276, 0, 0, 1, 0, 100, 0),
(760820, 55, -3175.489502, 2098.237549, 75.678909, 0, 0, 1, 0, 100, 0),
(760820, 56, -3160.424316, 2081.004150, 80.764908, 0, 0, 1, 0, 100, 0),
(760820, 57, -3141.073242, 2027.865112, 92.255219, 0, 0, 1, 0, 100, 0),
(760820, 58, -3100.545654, 1987.315796, 100.928787, 0, 0, 1, 0, 100, 0),
(760820, 59, -3079.955811, 1952.478638, 109.271744, 0, 0, 1, 0, 100, 0),
(760820, 60, -3043.312744, 1921.660156, 112.361816, 0, 0, 1, 0, 100, 0),
(760820, 61, -2973.852539, 1910.639648, 104.475471, 0, 0, 1, 0, 100, 0),
(760820, 62, -2956.038086, 1893.901855, 99.170197, 0, 0, 1, 0, 100, 0),
(760820, 63, -2950.733643, 1858.555664, 88.703011, 0, 0, 1, 0, 100, 0),
(760820, 64, -2923.169678, 1824.131348, 70.827278, 0, 0, 1, 0, 100, 0),
(760820, 65, -2889.111816, 1758.524658, 47.417206, 0, 0, 1, 0, 100, 0),
(760820, 66, -2879.456299, 1722.608887, 39.589905, 0, 0, 1, 0, 100, 0),
(760820, 67, -2865.740723, 1710.794922, 36.381069, 0, 0, 1, 0, 100, 0),
(760820, 68, -2848.158691, 1707.713623, 32.244236, 0, 0, 1, 0, 100, 0),
(760820, 69, -2824.067383, 1685.606934, 23.045313, 0, 0, 1, 0, 100, 0),
(760820, 70, -2819.241943, 1641.792847, 13.334887, 0, 0, 1, 0, 100, 0),
(760820, 71, -2871.091064, 1569.277466, 15.303233, 0, 0, 1, 0, 100, 0),
(760820, 72, -2893.539063, 1492.087402, 14.836093, 0, 0, 1, 0, 100, 0),
(760820, 73, -2981.375000, 1436.377686, 11.891064, 0, 0, 1, 0, 100, 0),
(760820, 74, -2987.835693, 1401.822510, 11.926711, 0, 0, 1, 0, 100, 0),
(760820, 75, -2988.486572, 1347.793457, 9.330483, 0, 0, 1, 0, 100, 0),
(760820, 76, -3078.444580, 1254.076050, 10.399191, 0, 0, 1, 0, 100, 0),
(760820, 77, -3090.341797, 1206.203125, 18.388882, 0, 0, 1, 0, 100, 0),
(760820, 78, -3114.885986, 1174.320313, 25.699680, 0, 0, 1, 0, 100, 0),
(760820, 79, -3112.093506, 1126.753174, 24.259985, 0, 0, 1, 0, 100, 0),
(760820, 80, -3120.531982, 1096.862549, 19.402412, 0, 0, 1, 0, 100, 0),
(760820, 81, -3113.394287, 1034.310425, 4.188662, 0, 0, 1, 0, 100, 0),
(760820, 82, -3117.856445, 982.948914, -7.988031, 0, 0, 1, 0, 100, 0),
(760820, 83, -3091.906494, 930.465881, -17.414244, 0, 0, 1, 0, 100, 0),
(760820, 84, -3116.419922, 821.828979, -21.856766, 0, 0, 1, 0, 100, 0);
--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (29489, 29490);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29489, 29490) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2949000, 2949001) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29489, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Captain Welsington- On Death - Say text 1'),
(29489, 0, 1, 0, 9, 0, 100, 0, 8, 25000, 8000, 12000, 11, 20615, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Captain Welsington - On 8-25 yard range - cast Intercept'),
(29489, 0, 2, 0, 0, 0, 100, 0, 3000, 7000, 5000, 10000, 11, 16856, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Captain Welsington- IC - cast Mortal Strike'),
(29490, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Captain Hartford - On Death - Say text 1'),
(29490, 0, 1, 0, 9, 0, 100, 0, 0, 25000, 3000, 4000, 87, 2949000, 2949001, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Captain Hartford - On 1-25 yard range - Random action list'),
(2949000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 20823, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Captain Hartford - action list - cast Fireball'),
(2949001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 20822, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Captain Hartford - action list - cast Frostbolt'),
(29490, 0, 2, 0, 0, 0, 100, 0, 5000, 10000, 10000, 15000, 11, 11831, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Captain Hartford - IC - cast Frost Nova');

DELETE FROM `creature_text` WHERE `entry` IN (29489, 29490);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(29489,0,0,'Archbishop Landgren must know! Aaaaaagggghhhh.....!',12,0,100,0,0,0,'Captain Welsington', 30161),
(29490,0,0,'I don''t know where the grand admiral is. Go to hell!',12,0,100,0,0,0,'Captain Hartford', 30146);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (29489, 29490);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,29489,0,0,9,0,12840,0,0,0,0,0,'','Captain Welsington- On Death - Say text 1 require quest 12840 taken'),
(22,1,29490,0,0,9,0,12840,0,0,0,0,0,'','Captain Hartford - On Death - Say text 1 require quest 12840 taken');
--
DELETE FROM `creature_text` WHERE `entry` = 7779;   
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(7779,1,0,"Good day to you both. I would speak to Lord Lescovar.",12,0,100,0,0,0,'Priestess Tyriona', 3781),
(7779,2,0,"Thank you. The Light be with you both.",12,0,100,0,0,0,'Priestess Tyriona', 3782),
(7779,3,0,"Milord, your guest has arrived. He awaits your presence.",12,0,100,0,0,0,'Priestess Tyriona', 3762),
(7779,4,0,"I shall use the time wisely, milord. Thank you.",12,0,100,0,0,0,'Priestess Tyriona', 3791);
-- Add SAI support for Lance a Lot achievement ID: 2836 and Amongts the Champions  quest
-- Champions SAI mechanic
SET @Sen_Champion := 33745;
SET @Script := 3374500;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Sen_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Sen_Champion;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Script;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Sen_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Champion - On Reset - Remove auras from Defend'),
(@Sen_Champion,0,1,2,62,0,100,0,10458,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sen Champion - On gossip select - Close gossip'),
(@Sen_Champion,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sen Champion - Linked with previous event - store target'),
(@Sen_Champion,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Champion - Linked with previous event - Call timed actionlist'),
(@Sen_Champion,0,4,0,52,0,100,0,0,@Sen_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sen Champion - On text over - Cast Charge'),
(@Sen_Champion,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'Sen Champion - IC - Cast Thrust'),
(@Sen_Champion,0,6,0,9,0,100,0,5,5,4000,7000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Sen Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@Sen_Champion,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Champion - IC - Move forward 12 yards'),
(@Sen_Champion,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Sen Champion - On 10-12 yard range - Cast Charge'),
(@Sen_Champion,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Sen Champion - Linked with previous event - Cast Shield-Breaker'),
(@Sen_Champion,0,10,11,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Champion - On HP% between 1% and 6% - Change faction to 35'),
(@Sen_Champion,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Champion - Linked with previous event - Say text'),
(@Sen_Champion,0,12,13,61,0,100,0,0,0,0,0,85,63596,0,0,0,0,0,12,1,0,0,0,0,0,0,'Sen Champion - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@Sen_Champion,0,13,14,61,0,100,0,0,0,0,0,85,64812,0,0,0,0,0,12,1,0,0,0,0,0,0,'Sen Champion - Linked with previous event - Cast credit'),
(@Sen_Champion,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Champion - Linked with previous event - Evade'),
(@Sen_Champion,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Champion - On player killed - Say text'),
(@Sen_Champion,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Champion - Linked with previous event - Set unseen'),
(@Sen_Champion,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sen Champion - Linked with previous event - Despawn in 1 ms'),
-- Timed actionlist 1
(@Script,9,1,0,0,0,100,0,0,0,0,0,42,0,1,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Set INVINCIBILITY'),
(@Script,9,2,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Set run ON'),
(@Script,9,3,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Cast Defend on self/Layer 1/'),
(@Script,9,4,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Cast Defend on self/Layer 2/'),
(@Script,9,5,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Cast Defend on self/Layer 3/'),
(@Script,9,6,0,0,0,100,0,0,0,0,0,46,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Move forward 15 yards'),
(@Script,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Set run Off'),
(@Script,9,8,0,0,0,100,0,0,0,0,0,11,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Cast aura TriggerS for Defend /10 sec one/'),
(@Script,9,9,0,0,0,100,0,3500,3500,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'All champions - Script 1 - Change faction to 14'),
(@Script,9,10,0,0,0,100,0,0,0,0,0,1,0,1500,0,0,0,0,2,0,0,0,0,0,0,0,'All champions - Script 1 - Say text');
-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @Sen_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@Sen_Champion,0,0,'Ready yourself!',12,1,100,0,0,0,'Argent Champion', 33757),
(@Sen_Champion,0,1,'Prepare yourself!',12,1,100,0,0,0,'Argent Champion', 33755),
(@Sen_Champion,0,2,'On your guard!',12,1,100,0,0,0,'Argent Champion', 33756),
(@Sen_Champion,0,3,'Let it begin!',12,1,100,0,0,0,'Argent Champion', 33758),
(@Sen_Champion,1,0,'Victory is mine!',12,1,100,0,0,0,'Argent Champion', 33777),
(@Sen_Champion,1,1,'It seems you still need more practice. Perhaps another time.',12,1,100,0,0,0,'Argent Champion', 33764),
(@Sen_Champion,1,2,'I have won. Better luck another time, friend.',12,1,100,0,0,0,'Argent Champion', 33779),
(@Sen_Champion,1,3,'I am afraid you will need more practice to defeat me.',12,1,100,0,0,0,'Argent Champion', 33778),
(@Sen_Champion,2,0,'I yield to you.',12,1,100,0,0,0,'Argent Champion', 33774),
(@Sen_Champion,2,1,'That was a well fought battle. I yield to you.',12,1,100,0,0,0,'Argent Champion', 33776),
(@Sen_Champion,2,2,'It would seem I underestimated your skills. Well done.',12,1,100,0,0,0,'Argent Champion', 33775),
(@Sen_Champion,2,3,'I have been defeated. Good fight!',12,1,100,0,0,0,'Argent Champion', 33760);

SET @Orgri_Champion := 33744;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Orgri_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Orgri_Champion;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Orgri_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Champion - On Reset - Remove auras from Defend'),
(@Orgri_Champion,0,1,2,62,0,100,0,10457,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Orgri Champion - On gossip select - Close gossip'),
(@Orgri_Champion,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Orgri Champion - Linked with previous event - store target'),
(@Orgri_Champion,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Champion - Linked with previous event - Call timed actionlist'),
(@Orgri_Champion,0,4,0,52,0,100,0,0,@Orgri_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'Orgri Champion - On text over - Cast Charge'),
(@Orgri_Champion,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'Orgri Champion - IC - Cast Thrust'),
(@Orgri_Champion,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Orgri Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@Orgri_Champion,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Champion - IC - Move forward 12 yards'),
(@Orgri_Champion,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Orgri Champion - On 10-12 yard range - Cast Charge'),
(@Orgri_Champion,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Orgri Champion - Linked with previous event - Cast Shield-Breaker'),
(@Orgri_Champion,0,10,11,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Champion - On HP% between 1% and 6% - Change faction to 35'),
(@Orgri_Champion,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Champion - Linked with previous event - Say text'),
(@Orgri_Champion,0,12,13,61,0,100,0,0,0,0,0,85,63596,0,0,0,0,0,12,1,0,0,0,0,0,0,'Orgri Champion - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@Orgri_Champion,0,13,14,61,0,100,0,0,0,0,0,85,64811,0,0,0,0,0,12,1,0,0,0,0,0,0,'Orgri Champion - Linked with previous event - Cast credit'),
(@Orgri_Champion,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Champion - Linked with previous event - Evade'),
(@Orgri_Champion,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Champion - On player killed - Say text'),
(@Orgri_Champion,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Champion - Linked with previous event - Set unseen'),
(@Orgri_Champion,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orgri Champion - Linked with previous event - Despawn in 1 ms');
-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @Orgri_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@Orgri_Champion,0,0,'Ready yourself!',12,1,100,0,0,0,'Argent Champion', 33757),
(@Orgri_Champion,0,1,'Prepare yourself!',12,1,100,0,0,0,'Argent Champion', 33755),
(@Orgri_Champion,0,2,'On your guard!',12,1,100,0,0,0,'Argent Champion', 33756),
(@Orgri_Champion,0,3,'Let it begin!',12,1,100,0,0,0,'Argent Champion', 33758),
(@Orgri_Champion,1,0,'Victory is mine!',12,1,100,0,0,0,'Argent Champion', 33777),
(@Orgri_Champion,1,1,'It seems you still need more practice. Perhaps another time.',12,1,100,0,0,0,'Argent Champion', 33764),
(@Orgri_Champion,1,2,'I have won. Better luck another time, friend.',12,1,100,0,0,0,'Argent Champion', 33779),
(@Orgri_Champion,1,3,'I am afraid you will need more practice to defeat me.',12,1,100,0,0,0,'Argent Champion', 33778),
(@Orgri_Champion,2,0,'I yield to you.',12,1,100,0,0,0,'Argent Champion', 33774),
(@Orgri_Champion,2,1,'That was a well fought battle. I yield to you.',12,1,100,0,0,0,'Argent Champion', 33776),
(@Orgri_Champion,2,2,'It would seem I underestimated your skills. Well done.',12,1,100,0,0,0,'Argent Champion', 33775),
(@Orgri_Champion,2,3,'I have been defeated. Good fight!',12,1,100,0,0,0,'Argent Champion', 33760);
SET @TB_Champion := 33748;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@TB_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TB_Champion;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TB_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Champion - On Reset - Remove auras from Defend'),
(@TB_Champion,0,1,2,62,0,100,0,10461,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'TB Champion - On gossip select - Close gossip'),
(@TB_Champion,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'TB Champion - Linked with previous event - store target'),
(@TB_Champion,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'TB Champion - Linked with previous event - Call timed actionlist'),
(@TB_Champion,0,4,0,52,0,100,0,0,@TB_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'TB Champion - On text over - Cast Charge'),
(@TB_Champion,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'TB Champion - IC - Cast Thrust'),
(@TB_Champion,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'TB Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@TB_Champion,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Champion - IC - Move forward 12 yards'),
(@TB_Champion,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'TB Champion - On 10-12 yard range - Cast Charge'),
(@TB_Champion,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'TB Champion - Linked with previous event - Cast Shield-Breaker'),
(@TB_Champion,0,10,11,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Champion - On HP% between 1% and 6% - Change faction to 35'),
(@TB_Champion,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Champion - Linked with previous event - Say text'),
(@TB_Champion,0,12,13,61,0,100,0,0,0,0,0,85,63596,0,0,0,0,0,12,1,0,0,0,0,0,0,'TB Champion - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@TB_Champion,0,13,14,61,0,100,0,0,0,0,0,85,64815,0,0,0,0,0,12,1,0,0,0,0,0,0,'TB Champion - Linked with previous event - Cast credit'),
(@TB_Champion,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB_Valiant - Linked with previous event - Evade'),
(@TB_Champion,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Champion - On player killed - Say text'),
(@TB_Champion,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Champion - Linked with previous event - Set unseen'),
(@TB_Champion,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'TB Champion - Linked with previous event - Despawn in 1 ms');
-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @TB_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@TB_Champion,0,0,'Ready yourself!',12,1,100,0,0,0,'Argent Champion', 33757),
(@TB_Champion,0,1,'Prepare yourself!',12,1,100,0,0,0,'Argent Champion', 33755),
(@TB_Champion,0,2,'On your guard!',12,1,100,0,0,0,'Argent Champion', 33756),
(@TB_Champion,0,3,'Let it begin!',12,1,100,0,0,0,'Argent Champion', 33758),
(@TB_Champion,1,0,'Victory is mine!',12,1,100,0,0,0,'Argent Champion', 33777),
(@TB_Champion,1,1,'It seems you still need more practice. Perhaps another time.',12,1,100,0,0,0,'Argent Champion', 33764),
(@TB_Champion,1,2,'I have won. Better luck another time, friend.',12,1,100,0,0,0,'Argent Champion', 33779),
(@TB_Champion,1,3,'I am afraid you will need more practice to defeat me.',12,1,100,0,0,0,'Argent Champion', 33778),
(@TB_Champion,2,0,'I yield to you.',12,1,100,0,0,0,'Argent Champion', 33774),
(@TB_Champion,2,1,'That was a well fought battle. I yield to you.',12,1,100,0,0,0,'Argent Champion', 33776),
(@TB_Champion,2,2,'It would seem I underestimated your skills. Well done.',12,1,100,0,0,0,'Argent Champion', 33775),
(@TB_Champion,2,3,'I have been defeated. Good fight!',12,1,100,0,0,0,'Argent Champion', 33760);
SET @SM_Champion := 33746;
UPDATE `creature_template` SET `AIName`='SmartAI'  WHERE `entry`=@SM_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SM_Champion;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SM_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Champion - On Reset - Remove auras from Defend'),
(@SM_Champion,0,1,2,62,0,100,0,10459,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'SM Champion - On gossip select - Close gossip'),
(@SM_Champion,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'SM Champion - Linked with previous event - store target'),
(@SM_Champion,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'SM Champion - Linked with previous event - Call timed actionlist'),
(@SM_Champion,0,4,0,52,0,100,0,0,@SM_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'SM Champion - On text over - Cast Charge'),
(@SM_Champion,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'SM Champion - IC - Cast Thrust'),
(@SM_Champion,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'SM Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@SM_Champion,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Champion - IC - Move forward 12 yards'),
(@SM_Champion,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'SM Champion - On 10-12 yard range - Cast Charge'),
(@SM_Champion,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'SM Champion - Linked with previous event - Cast Shield-Breaker'),
(@SM_Champion,0,10,11,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Champion - On HP% between 1% and 6% - Change faction to 35'),
(@SM_Champion,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Champion - Linked with previous event - Say text'),
(@SM_Champion,0,12,13,61,0,100,0,0,0,0,0,85,63596,0,0,0,0,0,12,1,0,0,0,0,0,0,'SM Champion - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@SM_Champion,0,13,14,61,0,100,0,0,0,0,0,85,64813,0,0,0,0,0,12,1,0,0,0,0,0,0,'SM Champion - Linked with previous event - Cast credit'),
(@SM_Champion,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Champion - Linked with previous event - Evade'),
(@SM_Champion,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Champion - On player killed - Say text'),
(@SM_Champion,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Champion - Linked with previous event - Set unseen'),
(@SM_Champion,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'SM Champion - Linked with previous event - Despawn in 1 ms');
-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @SM_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@SM_Champion,0,0,'Ready yourself!',12,1,100,0,0,0,'Argent Champion', 33757),
(@SM_Champion,0,1,'Prepare yourself!',12,1,100,0,0,0,'Argent Champion', 33755),
(@SM_Champion,0,2,'On your guard!',12,1,100,0,0,0,'Argent Champion', 33756),
(@SM_Champion,0,3,'Let it begin!',12,1,100,0,0,0,'Argent Champion', 33758),
(@SM_Champion,1,0,'Victory is mine!',12,1,100,0,0,0,'Argent Champion', 33777),
(@SM_Champion,1,1,'It seems you still need more practice. Perhaps another time.',12,1,100,0,0,0,'Argent Champion', 33764),
(@SM_Champion,1,2,'I have won. Better luck another time, friend.',12,1,100,0,0,0,'Argent Champion', 33779),
(@SM_Champion,1,3,'I am afraid you will need more practice to defeat me.',12,1,100,0,0,0,'Argent Champion', 33778),
(@SM_Champion,2,0,'I yield to you.',12,1,100,0,0,0,'Argent Champion', 33774),
(@SM_Champion,2,1,'That was a well fought battle. I yield to you.',12,1,100,0,0,0,'Argent Champion', 33776),
(@SM_Champion,2,2,'It would seem I underestimated your skills. Well done.',12,1,100,0,0,0,'Argent Champion', 33775),
(@SM_Champion,2,3,'I have been defeated. Good fight!',12,1,100,0,0,0,'Argent Champion', 33760);
SET @GR_Champion := 33740;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@GR_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GR_Champion;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GR_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Champion - On Reset - Remove auras from Defend'),
(@GR_Champion,0,1,2,62,0,100,0,10455,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'GR Champion - On gossip select - Close gossip'),
(@GR_Champion,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'GR Champion - Linked with previous event - store target'),
(@GR_Champion,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'GR Champion - Linked with previous event - Call timed actionlist'),
(@GR_Champion,0,4,0,52,0,100,0,0,@GR_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'GR Champion - On text over - Cast Charge'),
(@GR_Champion,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'GR Champion - IC - Cast Thrust'),
(@GR_Champion,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'GR Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@GR_Champion,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Champion - IC - Move forward 12 yards'),
(@GR_Champion,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'GR Champion - On 10-12 yard range - Cast Charge'),
(@GR_Champion,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'GR Champion - Linked with previous event - Cast Shield-Breaker'),
(@GR_Champion,0,10,11,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Champion - On HP% between 1% and 6% - Change faction to 35'),
(@GR_Champion,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Champion - Linked with previous event - Say text'),
(@GR_Champion,0,12,13,61,0,100,0,0,0,0,0,85,63596,0,0,0,0,0,12,1,0,0,0,0,0,0,'GR Champion - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@GR_Champion,0,13,14,61,0,100,0,0,0,0,0,85,64809,0,0,0,0,0,12,1,0,0,0,0,0,0,'GR Champion - Linked with previous event - Cast credit'),
(@GR_Champion,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Champion - Linked with previous event - Evade'),
(@GR_Champion,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Champion - On player killed - Say text'),
(@GR_Champion,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Champion - Linked with previous event - Set unseen'),
(@GR_Champion,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'GR Champion - Linked with previous event - Despawn in 1 ms');
-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @GR_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@GR_Champion,0,0,'Ready yourself!',12,7,100,0,0,0,'Argent Champion', 33757),
(@GR_Champion,0,1,'Prepare yourself!',12,7,100,0,0,0,'Argent Champion', 33755),
(@GR_Champion,0,2,'On your guard!',12,7,100,0,0,0,'Argent Champion', 33756),
(@GR_Champion,0,3,'Let it begin!',12,7,100,0,0,0,'Argent Champion', 33758),
(@GR_Champion,1,0,'Victory is mine!',12,7,100,0,0,0,'Argent Champion', 33777),
(@GR_Champion,1,1,'It seems you still need more practice. Perhaps another time.',12,7,100,0,0,0,'Argent Champion', 33764),
(@GR_Champion,1,2,'I have won. Better luck another time, friend.',12,7,100,0,0,0,'Argent Champion', 33779),
(@GR_Champion,1,3,'I am afraid you will need more practice to defeat me.',12,7,100,0,0,0,'Argent Champion', 33778),
(@GR_Champion,2,0,'I yield to you.',12,7,100,0,0,0,'Argent Champion', 33774),
(@GR_Champion,2,1,'That was a well fought battle. I yield to you.',12,7,100,0,0,0,'Argent Champion', 33776),
(@GR_Champion,2,2,'It would seem I underestimated your skills. Well done.',12,7,100,0,0,0,'Argent Champion', 33775),
(@GR_Champion,2,3,'I have been defeated. Good fight!',12,7,100,0,0,0,'Argent Champion', 33760);
SET @IF_Champion := 33743;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@IF_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@IF_Champion;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@IF_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Champion - On Reset - Remove auras from Defend'),
(@IF_Champion,0,1,2,62,0,100,0,10456,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'IF Champion - On gossip select - Close gossip'),
(@IF_Champion,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'IF Champion - Linked with previous event - store target'),
(@IF_Champion,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'IF Champion - Linked with previous event - Call timed actionlist'),
(@IF_Champion,0,4,0,52,0,100,0,0,@IF_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'IF Champion - On text over - Cast Charge'),
(@IF_Champion,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'IF Champion - IC - Cast Thrust'),
(@IF_Champion,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'IF Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@IF_Champion,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Champion - IC - Move forward 12 yards'),
(@IF_Champion,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'IF Champion - On 10-12 yard range - Cast Charge'),
(@IF_Champion,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'IF Champion - Linked with previous event - Cast Shield-Breaker'),
(@IF_Champion,0,10,11,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Champion - On HP% between 1% and 6% - Change faction to 35'),
(@IF_Champion,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Champion - Linked with previous event - Say text'),
(@IF_Champion,0,12,13,61,0,100,0,0,0,0,0,85,63596,0,0,0,0,0,12,1,0,0,0,0,0,0,'IF Champion - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@IF_Champion,0,13,14,61,0,100,0,0,0,0,0,85,64810,0,0,0,0,0,12,1,0,0,0,0,0,0,'IF Champion - Linked with previous event - Cast credit'),
(@IF_Champion,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Champion - Linked with previous event - Evade'),
(@IF_Champion,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Champion - On player killed - Say text'),
(@IF_Champion,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Champion - Linked with previous event - Set unseen'),
(@IF_Champion,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'IF Champion - Linked with previous event - Despawn in 1 ms');
-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @IF_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@IF_Champion,0,0,'Ready yourself!',12,7,100,0,0,0,'Argent Champion', 33757),
(@IF_Champion,0,1,'Prepare yourself!',12,7,100,0,0,0,'Argent Champion', 33755),
(@IF_Champion,0,2,'On your guard!',12,7,100,0,0,0,'Argent Champion', 33756),
(@IF_Champion,0,3,'Let it begin!',12,7,100,0,0,0,'Argent Champion', 33758),
(@IF_Champion,1,0,'Victory is mine!',12,7,100,0,0,0,'Argent Champion', 33777),
(@IF_Champion,1,1,'It seems you still need more practice. Perhaps another time.',12,7,100,0,0,0,'Argent Champion', 33764),
(@IF_Champion,1,2,'I have won. Better luck another time, friend.',12,7,100,0,0,0,'Argent Champion', 33779),
(@IF_Champion,1,3,'I am afraid you will need more practice to defeat me.',12,7,100,0,0,0,'Argent Champion', 33778),
(@IF_Champion,2,0,'I yield to you.',12,7,100,0,0,0,'Argent Champion', 33774),
(@IF_Champion,2,1,'That was a well fought battle. I yield to you.',12,7,100,0,0,0,'Argent Champion', 33776),
(@IF_Champion,2,2,'It would seem I underestimated your skills. Well done.',12,7,100,0,0,0,'Argent Champion', 33775),
(@IF_Champion,2,3,'I have been defeated. Good fight!',12,7,100,0,0,0,'Argent Champion', 33760);
SET @SW_Champion := 33747;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@SW_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SW_Champion;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SW_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Champion - On Reset - Remove auras from Defend'),
(@SW_Champion,0,1,2,62,0,100,0,10460,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'SW Champion - On gossip select - Close gossip'),
(@SW_Champion,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'SW Champion - Linked with previous event - store target'),
(@SW_Champion,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'SW Champion - Linked with previous event - Call timed actionlist'),
(@SW_Champion,0,4,0,52,0,100,0,0,@SW_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'SW Champion - On text over - Cast Charge'),
(@SW_Champion,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'SW Champion - IC - Cast Thrust'),
(@SW_Champion,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'SW Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@SW_Champion,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Champion - IC - Move forward 12 yards'),
(@SW_Champion,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'SW Champion - On 10-12 yard range - Cast Charge'),
(@SW_Champion,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'SW Champion - Linked with previous event - Cast Shield-Breaker'),
(@SW_Champion,0,10,11,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Champion - On HP% between 1% and 6% - Change faction to 35'),
(@SW_Champion,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Champion - Linked with previous event - Say text'),
(@SW_Champion,0,12,13,61,0,100,0,0,0,0,0,85,63596,0,0,0,0,0,12,1,0,0,0,0,0,0,'SW Champion - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@SW_Champion,0,13,14,61,0,100,0,0,0,0,0,85,64814,0,0,0,0,0,12,1,0,0,0,0,0,0,'SW Champion - Linked with previous event - Cast credit'),
(@SW_Champion,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Champion - Linked with previous event - Evade'),
(@SW_Champion,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Champion - On player killed - Say text'),
(@SW_Champion,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Champion - Linked with previous event - Set unseen'),
(@SW_Champion,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'SW Champion - Linked with previous event - Despawn in 1 ms');
-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @SW_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@SW_Champion,0,0,'Ready yourself!',12,7,100,0,0,0,'Argent Champion', 33757),
(@SW_Champion,0,1,'Prepare yourself!',12,7,100,0,0,0,'Argent Champion', 33755),
(@SW_Champion,0,2,'On your guard!',12,7,100,0,0,0,'Argent Champion', 33756),
(@SW_Champion,0,3,'Let it begin!',12,7,100,0,0,0,'Argent Champion', 33758),
(@SW_Champion,1,0,'Victory is mine!',12,7,100,0,0,0,'Argent Champion', 33777),
(@SW_Champion,1,1,'It seems you still need more practice. Perhaps another time.',12,7,100,0,0,0,'Argent Champion', 33764),
(@SW_Champion,1,2,'I have won. Better luck another time, friend.',12,7,100,0,0,0,'Argent Champion', 33779),
(@SW_Champion,1,3,'I am afraid you will need more practice to defeat me.',12,7,100,0,0,0,'Argent Champion', 33778),
(@SW_Champion,2,0,'I yield to you.',12,7,100,0,0,0,'Argent Champion', 33774),
(@SW_Champion,2,1,'That was a well fought battle. I yield to you.',12,7,100,0,0,0,'Argent Champion', 33776),
(@SW_Champion,2,2,'It would seem I underestimated your skills. Well done.',12,7,100,0,0,0,'Argent Champion', 33775),
(@SW_Champion,2,3,'I have been defeated. Good fight!',12,7,100,0,0,0,'Argent Champion', 33760);
SET @Darn_Champion := 33738;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Darn_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Darn_Champion;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Darn_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Champion - On Reset - Remove auras from Defend'),
(@Darn_Champion,0,1,2,62,0,100,0,10453,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Darn Champion - On gossip select - Close gossip'),
(@Darn_Champion,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Darn Champion - Linked with previous event - store target'),
(@Darn_Champion,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Champion - Linked with previous event - Call timed actionlist'),
(@Darn_Champion,0,4,0,52,0,100,0,0,@Darn_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'Darn Champion - On text over - Cast Charge'),
(@Darn_Champion,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'Darn Champion - IC - Cast Thrust'),
(@Darn_Champion,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Darn Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@Darn_Champion,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Champion - IC - Move forward 12 yards'),
(@Darn_Champion,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Darn Champion - On 10-12 yard range - Cast Charge'),
(@Darn_Champion,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Darn Champion - Linked with previous event - Cast Shield-Breaker'),
(@Darn_Champion,0,10,11,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Champion - On HP% between 1% and 6% - Change faction to 35'),
(@Darn_Champion,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Champion - Linked with previous event - Say text'),
(@Darn_Champion,0,12,13,61,0,100,0,0,0,0,0,85,63596,0,0,0,0,0,12,1,0,0,0,0,0,0,'Darn Champion - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@Darn_Champion,0,13,14,61,0,100,0,0,0,0,0,85,64805,0,0,0,0,0,12,1,0,0,0,0,0,0,'Darn Champion - Linked with previous event - Cast credit'),
(@Darn_Champion,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Champion - Linked with previous event - Evade'),
(@Darn_Champion,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Champion - On player killed - Say text'),
(@Darn_Champion,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Champion - Linked with previous event - Set unseen'),
(@Darn_Champion,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darn Champion - Linked with previous event - Despawn in 1 ms');
-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @Darn_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@Darn_Champion,0,0,'Ready yourself!',12,7,100,0,0,0,'Argent Champion', 33757),
(@Darn_Champion,0,1,'Prepare yourself!',12,7,100,0,0,0,'Argent Champion', 33755),
(@Darn_Champion,0,2,'On your guard!',12,7,100,0,0,0,'Argent Champion', 33756),
(@Darn_Champion,0,3,'Let it begin!',12,7,100,0,0,0,'Argent Champion', 33758),
(@Darn_Champion,1,0,'Victory is mine!',12,7,100,0,0,0,'Argent Champion', 33777),
(@Darn_Champion,1,1,'It seems you still need more practice. Perhaps another time.',12,7,100,0,0,0,'Argent Champion', 33764),
(@Darn_Champion,1,2,'I have won. Better luck another time, friend.',12,7,100,0,0,0,'Argent Champion', 33779),
(@Darn_Champion,1,3,'I am afraid you will need more practice to defeat me.',12,7,100,0,0,0,'Argent Champion', 33778),
(@Darn_Champion,2,0,'I yield to you.',12,7,100,0,0,0,'Argent Champion', 33774),
(@Darn_Champion,2,1,'That was a well fought battle. I yield to you.',12,7,100,0,0,0,'Argent Champion', 33776),
(@Darn_Champion,2,2,'It would seem I underestimated your skills. Well done.',12,7,100,0,0,0,'Argent Champion', 33775),
(@Darn_Champion,2,3,'I have been defeated. Good fight!',12,7,100,0,0,0,'Argent Champion', 33760);
SET @Exo_Champion := 33739;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Exo_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Exo_Champion;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Exo_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Champion - On Reset - Remove auras from Defend'),
(@Exo_Champion,0,1,2,62,0,100,0,10454,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Exo Champion - On gossip select - Close gossip'),
(@Exo_Champion,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Exo Champion - Linked with previous event - store target'),
(@Exo_Champion,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Champion - Linked with previous event - Call timed actionlist'),
(@Exo_Champion,0,4,0,52,0,100,0,0,@Exo_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'Exo Champion - On text over - Cast Charge'),
(@Exo_Champion,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'Exo Champion - IC - Cast Thrust'),
(@Exo_Champion,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Exo Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@Exo_Champion,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Champion - IC - Move forward 12 yards'),
(@Exo_Champion,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Exo Champion - On 10-12 yard range - Cast Charge'),
(@Exo_Champion,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Exo Champion - Linked with previous event - Cast Shield-Breaker'),
(@Exo_Champion,0,10,11,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Champion - On HP% between 1% and 6% - Change faction to 35'),
(@Exo_Champion,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Champion - Linked with previous event - Say text'),
(@Exo_Champion,0,12,13,61,0,100,0,0,0,0,0,85,63596,0,0,0,0,0,12,1,0,0,0,0,0,0,'Exo Champion - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@Exo_Champion,0,13,14,61,0,100,0,0,0,0,0,85,64808,0,0,0,0,0,12,1,0,0,0,0,0,0,'Exo Champion - Linked with previous event - Cast credit'),
(@Exo_Champion,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Champion - Linked with previous event - Evade'),
(@Exo_Champion,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Champion - On player killed - Say text'),
(@Exo_Champion,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Champion - Linked with previous event - Set unseen'),
(@Exo_Champion,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Exo Champion - Linked with previous event - Despawn in 1 ms');
-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @Exo_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@Exo_Champion,0,0,'Ready yourself!',12,7,100,0,0,0,'Argent Champion', 33757),
(@Exo_Champion,0,1,'Prepare yourself!',12,7,100,0,0,0,'Argent Champion', 33755),
(@Exo_Champion,0,2,'On your guard!',12,7,100,0,0,0,'Argent Champion', 33756),
(@Exo_Champion,0,3,'Let it begin!',12,7,100,0,0,0,'Argent Champion', 33758),
(@Exo_Champion,1,0,'Victory is mine!',12,7,100,0,0,0,'Argent Champion', 33777),
(@Exo_Champion,1,1,'It seems you still need more practice. Perhaps another time.',12,7,100,0,0,0,'Argent Champion', 33764),
(@Exo_Champion,1,2,'I have won. Better luck another time, friend.',12,7,100,0,0,0,'Argent Champion', 33779),
(@Exo_Champion,1,3,'I am afraid you will need more practice to defeat me.',12,7,100,0,0,0,'Argent Champion', 33778),
(@Exo_Champion,2,0,'I yield to you.',12,7,100,0,0,0,'Argent Champion', 33774),
(@Exo_Champion,2,1,'That was a well fought battle. I yield to you.',12,7,100,0,0,0,'Argent Champion', 33776),
(@Exo_Champion,2,2,'It would seem I underestimated your skills. Well done.',12,7,100,0,0,0,'Argent Champion', 33775),
(@Exo_Champion,2,3,'I have been defeated. Good fight!',12,7,100,0,0,0,'Argent Champion', 33760);
SET @UC_Champion := 33749;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@UC_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@UC_Champion;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@UC_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Champion - On Reset - Remove auras from Defend'),
(@UC_Champion,0,1,2,62,0,100,0,10462,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'UC Champion - On gossip select - Close gossip'),
(@UC_Champion,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'UC Champion - Linked with previous event - store target'),
(@UC_Champion,0,3,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'UC Champion - Linked with previous event - Call timed actionlist'),
(@UC_Champion,0,4,0,52,0,100,0,0,@UC_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'UC Champion - On text over - Cast Charge'),
(@UC_Champion,0,5,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'UC Champion - IC - Cast Thrust'),
(@UC_Champion,0,6,0,9,0,100,0,5,5,9000,10000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'UC Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@UC_Champion,0,7,0,0,0,100,0,9000,11000,9000,10000,46,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Champion - IC - Move forward 12 yards'),
(@UC_Champion,0,8,9,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'UC Champion - On 10-12 yard range - Cast Charge'),
(@UC_Champion,0,9,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'UC Champion - Linked with previous event - Cast Shield-Breaker'),
(@UC_Champion,0,10,11,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Champion - On HP% between 1% and 6% - Change faction to 35'),
(@UC_Champion,0,11,12,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Champion - Linked with previous event - Say text'),
(@UC_Champion,0,12,13,61,0,100,0,0,0,0,0,85,63596,0,0,0,0,0,12,1,0,0,0,0,0,0,'UC Champion - Linked with previous event - Cast Mounted Melee Victory /item/'),
(@UC_Champion,0,13,14,61,0,100,0,0,0,0,0,85,64816,0,0,0,0,0,12,1,0,0,0,0,0,0,'UC Champion - Linked with previous event - Cast credit'),
(@UC_Champion,0,14,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Champion - Linked with previous event - Evade'),
(@UC_Champion,0,15,16,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Champion - On player killed - Say text'),
(@UC_Champion,0,16,17,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Champion - Linked with previous event - Set unseen'),
(@UC_Champion,0,17,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'UC Champion - Linked with previous event - Despawn in 1 ms');
-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @UC_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@UC_Champion,0,0,'Ready yourself!',12,1,100,0,0,0,'Argent Champion', 33757),
(@UC_Champion,0,1,'Prepare yourself!',12,1,100,0,0,0,'Argent Champion', 33755),
(@UC_Champion,0,2,'On your guard!',12,1,100,0,0,0,'Argent Champion', 33756),
(@UC_Champion,0,3,'Let it begin!',12,1,100,0,0,0,'Argent Champion', 33758),
(@UC_Champion,1,0,'Victory is mine!',12,1,100,0,0,0,'Argent Champion', 33777),
(@UC_Champion,1,1,'It seems you still need more practice. Perhaps another time.',12,1,100,0,0,0,'Argent Champion', 33764),
(@UC_Champion,1,2,'I have won. Better luck another time, friend.',12,1,100,0,0,0,'Argent Champion', 33779),
(@UC_Champion,1,3,'I am afraid you will need more practice to defeat me.',12,1,100,0,0,0,'Argent Champion', 33778),
(@UC_Champion,2,0,'I yield to you.',12,1,100,0,0,0,'Argent Champion', 33774),
(@UC_Champion,2,1,'That was a well fought battle. I yield to you.',12,1,100,0,0,0,'Argent Champion', 33776),
(@UC_Champion,2,2,'It would seem I underestimated your skills. Well done.',12,1,100,0,0,0,'Argent Champion', 33775),
(@UC_Champion,2,3,'I have been defeated. Good fight!',12,1,100,0,0,0,'Argent Champion', 33760);


DELETE FROM `gossip_menu` WHERE `entry` IN (10453, 10454, 10455, 10456, 10457, 10458, 10459, 10460, 10461, 10462);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10453, 14421),
(10453, 14489),
(10454, 14421),
(10454, 14489),
(10455, 14421),
(10455, 14489),
(10456, 14421),
(10456, 14489),
(10457, 14421),
(10457, 14489),
(10458, 14421),
(10458, 14489),
(10459, 14421),
(10459, 14489),
(10460, 14421),
(10460, 14489),
(10461, 14421),
(10461, 14489),
(10462, 14421),
(10462, 14489);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (10453, 10454, 10455, 10456, 10457, 10458, 10459, 10460, 10461, 10462);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14,10453,14421,0,1,64805,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10453,14489,0,1,64805,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10454,14421,0,1,64808,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10454,14489,0,1,64808,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10455,14421,0,1,64809,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10455,14489,0,1,64809,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10456,14421,0,1,64810,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10456,14489,0,1,64810,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10457,14421,0,1,64811,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10457,14489,0,1,64811,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10458,14421,0,1,64812,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10458,14489,0,1,64812,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10459,14421,0,1,64813,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10459,14489,0,1,64813,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10460,14421,0,1,64814,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10460,14489,0,1,64814,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10461,14421,0,1,64815,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10461,14489,0,1,64815,0,0,0,'','Show gossip menu text if the player have the aura', 0),
(14,10462,14421,0,1,64816,0,0,0,'','Show gossip menu text if the player haven''t the aura', 1),
(14,10462,14489,0,1,64816,0,0,0,'','Show gossip menu text if the player have the aura', 0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (10453, 10454, 10455, 10456, 10457, 10458, 10459, 10460, 10461, 10462);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTarget`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`,`NegativeCondition`) VALUES
(15,10453,0,0,1,9,13790,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10453,0,0,1,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1), 
(15,10453,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10453,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10453,0,0,2,9,13793,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10453,0,0,2,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10453,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10453,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10453,0,0,3,9,13811,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10453,0,0,3,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10453,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10453,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10453,0,0,4,9,13814,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10453,0,0,4,1,64805,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10453,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10453,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10454,0,0,1,9,13790,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10454,0,0,1,1,64808,0,0,0,'','Show gossip menu only if don''t have the auran',1),
(15,10454,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10454,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10454,0,0,2,9,13793,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10454,0,0,2,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10454,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10454,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10454,0,0,3,9,13811,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10454,0,0,3,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10454,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10454,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10454,0,0,4,9,13814,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10454,0,0,4,1,64808,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10454,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10454,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10455,0,0,1,9,13790,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10455,0,0,1,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10455,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10455,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10455,0,0,2,9,13793,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10455,0,0,2,1,64809,0,0,0,'','Show gossip menu only if don''t have the auran',1),
(15,10455,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10455,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10455,0,0,3,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10455,0,0,3,9,13811,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10455,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10455,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10455,0,0,4,1,64809,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10455,0,0,4,9,13814,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10455,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10455,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10456,0,0,1,9,13790,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10456,0,0,1,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10456,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10456,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10456,0,0,2,9,13793,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10456,0,0,2,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10456,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10456,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10456,0,0,3,9,13811,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10456,0,0,3,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10456,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10456,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10456,0,0,4,9,13814,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10456,0,0,4,1,64810,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10456,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10456,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10457,0,0,1,9,13790,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10457,0,0,1,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10457,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10457,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10457,0,0,2,9,13793,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10457,0,0,2,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10457,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10457,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10457,0,0,3,9,13811,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10457,0,0,3,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10457,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10457,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10457,0,0,4,9,13814,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10457,0,0,4,1,64811,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10457,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10457,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10458,0,0,1,9,13790,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10458,0,0,1,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10458,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10458,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10458,0,0,2,9,13793,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10458,0,0,2,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10458,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10458,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10458,0,0,3,9,13811,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10458,0,0,3,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10458,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10458,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10458,0,0,4,9,13814,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10458,0,0,4,1,64812,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10458,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10458,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10459,0,0,1,9,13790,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10459,0,0,1,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10459,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10459,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10459,0,0,2,9,13793,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10459,0,0,2,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10459,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10459,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10459,0,0,3,9,13811,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10459,0,0,3,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10459,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10459,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10459,0,0,4,9,13814,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10459,0,0,4,1,64813,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10459,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10459,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10460,0,0,1,9,13790,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10460,0,0,1,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10460,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10460,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10460,0,0,2,9,13793,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10460,0,0,2,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10460,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10460,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10460,0,0,3,9,13811,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10460,0,0,3,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10460,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10460,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10460,0,0,4,9,13814,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10460,0,0,4,1,64814,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10460,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10460,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10461,0,0,1,9,13790,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10461,0,0,1,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10461,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10461,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10461,0,0,2,9,13793,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10461,0,0,2,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10461,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10461,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10461,0,0,3,9,13811,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10461,0,0,3,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10461,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10461,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10461,0,0,4,9,13814,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10461,0,0,4,1,64815,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10461,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10461,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10462,0,0,1,9,13790,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10462,0,0,1,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10462,0,0,1,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10462,0,0,1,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10462,0,0,2,9,13793,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10462,0,0,2,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10462,0,0,2,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10462,0,0,2,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10462,0,0,3,9,13811,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10462,0,0,3,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10462,0,0,3,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10462,0,0,3,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10462,0,0,4,9,13814,0,0,0,'','Show gossip menu only if quest Among the Champions is taken',0),
(15,10462,0,0,4,1,64816,0,0,0,'','Show gossip menu only if don''t have the aura',1),
(15,10462,0,0,4,1,63034,0,0,0,'','Show gossip menu only if the player have the aura',0),
(15,10462,0,0,4,1,62853,0,0,0,'','Show gossip menu only if the player have the aura',0);
--
UPDATE `conditions` SET `ConditionTypeOrReference`=9, `SourceEntry`=1 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8539;
-- 
-- Okla
DELETE FROM `creature_text` WHERE `entry` IN (14873, 5907);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextId`) VALUES 
(14873, 0, 0, "Can I go collect more rocks for my necklace, Papa?", 12, 1, 100, 1, 0, 0, 'Okla',10274),
(14873, 1, 0, "Dabu! I will be careful Papa!", 12, 1, 100, 1, 0, 0, 'Okla', 10276),
(14873, 2, 0, "Ooohh... This rock is nice and colorful. Let's see if I can find more like it...", 12, 1, 100, 1, 0, 0, 'Okla', 10277),
(14873, 3, 0, "Hmm... That rock is nice, but too small.", 12, 1, 100, 1, 0, 0, 'Okla', 10278),
(14873, 4, 0, "This is a shiney rock. I'll put it in my bucket. Ok, I just need a few more...", 12, 1, 100, 1, 0, 0, 'Okla', 10279),
(14873, 5, 0, "I bet my friend Gruk would like this rock for the spear he is making! It's very sharp... I hope he likes it.", 12, 1, 100, 1, 0, 0, 'Okla', 10280),
(14873, 6, 0, "There... That should be enough rocks to make a necklace. I should probably get home now anyway.", 12, 1, 100, 1, 0, 0, 'Okla', 10281),
(5907, 0, 0, "Yes you may, Okla. But do not stray too far from home.", 12, 1, 100, 1, 0, 0, 'Kranal Fiss', 10275);

-- Okla SAI
SET @ENTRY := 14873;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,14873,1,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,2,14873,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,13,14873,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 13 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,18,14873,0,0,80,@ENTRY*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 18 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,24,14873,0,0,80,@ENTRY*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 24 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,29,14873,0,0,80,@ENTRY*100+04,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 29 Reached - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,35,14873,0,0,80,@ENTRY*100+05,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 35 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1487300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,21000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,8000,8000,0,0,1,0,0,0,0,0,0,19,5907,50,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 1487301;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 2");

-- Actionlist SAI
SET @ENTRY := 1487302;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 3");

-- Actionlist SAI
SET @ENTRY := 1487303;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 4");

-- Actionlist SAI
SET @ENTRY := 1487304;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 5");

-- Actionlist SAI
SET @ENTRY := 1487305;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 6");

DELETE FROM `waypoints` WHERE `entry`=14873;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(14873, 1, 270.076, -3036.6, 97.6192),
(14873, 2, 262.171, -3043.45, 96.5053),
(14873, 3, 251.328, -3055.55, 96.1454),
(14873, 4, 246.888, -3070.92, 95.2793),
(14873, 5, 242.449, -3081.3, 91.82),
(14873, 6, 232.826, -3106.67, 93.3165),
(14873, 7, 226.41, -3120.76, 93.3475),
(14873, 8, 213.921, -3151.01, 91.2851),
(14873, 9, 221.681, -3147.9, 91.374),
(14873, 10, 214.549, -3134.64, 91.9876),
(14873, 11, 210.931, -3139.95, 91.6514),
(14873, 12, 214.059, -3139.64, 91.7),
(14873, 13, 213.426, -3131.78, 92.1297),
(14873, 14, 220.194, -3140.72, 91.7517),
(14873, 15, 225.395, -3139.1, 92.0847),
(14873, 16, 220.857, -3140.83, 91.7662),
(14873, 17, 218.769, -3132.79, 92.4983),
(14873, 18, 226.814, -3137.56, 92.169),
(14873, 19, 225.496, -3132.89, 92.7818),
(14873, 20, 213.603, -3148.39, 91.4489),
(14873, 21, 219.055, -3151.2, 91.2139),
(14873, 22, 220.469, -3141.93, 91.6344),
(14873, 23, 214.852, -3148.32, 91.4558),
(14873, 24, 218.373, -3144.99, 91.5714),
(14873, 25, 224.091, -3149.02, 91.2304),
(14873, 26, 224.591, -3145.02, 91.4801),
(14873, 27, 219.022, -3147.38, 91.4735),
(14873, 28, 220.167, -3139.75, 91.8958),
(14873, 29, 225.033, -3133.14, 92.8028),
(14873, 30, 222.021, -3128.32, 93.0422),
(14873, 31, 228.338, -3126.35, 92.9595),
(14873, 32, 229.495, -3129.22, 92.6818),
(14873, 33, 232.12, -3128.11, 92.5988),
(14873, 34, 227.003, -3137.58, 92.1461),
(14873, 35, 220.002, -3132.38, 92.659),
(14873, 36, 225.874, -3102.36, 93.6962),
(14873, 37, 233.086, -3085.54, 91.6788),
(14873, 38, 235.152, -3069.81, 91.8706),
(14873, 39, 239.821, -3061.03, 95.4022),
(14873, 40, 256.123, -3047.91, 96.2473),
(14873, 41, 267.05, -3039.04, 96.9212),
(14873, 42, 271.093, -3035.98, 97.6501),
(14873, 43, 278.975, -3029.68, 97.3919),
(14873, 44, 280.125, -3029.01, 97.3502);

UPDATE `creature_addon` SET `path_id`=59070 WHERE `guid`=13174;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=13174;
DELETE FROM `waypoint_data` WHERE `id` IN (59070);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`action`,`action_chance`,`wpguid`) VALUES
(59070,0,265.967000,-3050.670000,96.921500,0,0,0,100,0),
(59070,1,263.671661,-3047.959961,96.665161,0,0,0,100,0),
(59070,2,260.557739,-3038.177002,96.740677,0,0,0,100,0),
(59070,3,262.354950,-3036.125732,96.990982,0,0,0,100,0),
(59070,4,261.470215,-3036.779541,96.961708,0,60000,0,100,0),
(59070,5,259.890106,-3038.696045,96.572845,0,0,0,100,0),
(59070,6,265.967468,-3050.672363,96.921516,0,0,0,100,0),
(59070,7,265.967000,-3050.670000,96.921500,0,30000,0,100,0);
UPDATE `creature` SET `position_x`=280.125, `position_y`=-3029.01, `position_z`=97.3502, `orientation`= 3.764 WHERE `guid`=14873;
-- 
DELETE FROM `waypoint_data` WHERE `id`=1207950;
DELETE FROM `creature_addon` WHERE  `guid`=120795;
UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=120795;
DELETE FROM `waypoint_scripts` WHERE  `guid`=120795;

-- Refurbished Steam Tank SAI
SET @ENTRY := 29144;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,29144,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,29144,0,0,54,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,2,29144,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,3,29144,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 3 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,40,0,100,0,6,29144,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 6 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,40,0,100,0,10,29144,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 10 Reached - Pause Waypoint"),
(@ENTRY,0,6,7,40,0,100,0,11,29144,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 11 Reached - Pause Waypoint"),
(@ENTRY,0,7,0,61,0,100,0,11,29144,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Waypoint 11 Reached - Kill Self"),
(@ENTRY,0,8,0,6,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refurbished Steam Tank - On Just Died - Despawn In 3000 ms");

DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@ENTRY, 1, -8463.9, 1109.41, 19.1352, 'Refurbished Steam Tank'),
(@ENTRY, 2, -8463.52, 1112.6, 19.0517, 'Refurbished Steam Tank'),
(@ENTRY, 3, -8463.23, 1108.18, 19.053, 'Refurbished Steam Tank'),
(@ENTRY, 4, -8473.35, 1096.63, 18.7345, 'Refurbished Steam Tank'),
(@ENTRY, 5, -8496.34, 1095.88, 17.9444, 'Refurbished Steam Tank'),
(@ENTRY, 6, -8499.86, 1132.84, 17.9763, 'Refurbished Steam Tank'),
(@ENTRY, 7, -8486, 1138.24, 17.9608, 'Refurbished Steam Tank'),
(@ENTRY, 8, -8462.43, 1136.04, 18.6577, 'Refurbished Steam Tank'),
(@ENTRY, 9, -8440.65, 1137.48, 18.8719, 'Refurbished Steam Tank'),
(@ENTRY, 10, -8412.35, 1137.49, 18.0685, 'Refurbished Steam Tank'),
(@ENTRY, 11, -8412.35, 1137.49, 18.0685, 'Refurbished Steam Tank');
-- DB/Quest: Assault by Air (H)
DELETE FROM `creature` WHERE `id`=32225;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(16398, 32225, 571, 1, 169, 0, 0, 7303.23, 1520.81, 323.2961, 1.53589, 300, 0, 0, 63000, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `spell1`=59880 WHERE `entry`=32227;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=32225;
UPDATE `creature_template` SET `speed_run`=3 WHERE  `entry`=32225;
UPDATE `vehicle_template_accessory` SET `minion`=1 WHERE  `entry`=32225 AND `seat_id`=0;

DELETE FROM `waypoints` WHERE `entry`=32225;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(32225, 1, 7224.952, 1493.076, 355.6927, 'Skybreaker Troop Transport'),
(32225, 2, 7158.104, 1468.994, 408.7451, 'Skybreaker Troop Transport'),
(32225, 3, 7091.476, 1447.724, 454.6882, 'Skybreaker Troop Transport'),
(32225, 4, 6959.782, 1423.015, 558.3835, 'Skybreaker Troop Transport'),
(32225, 5, 6779.104, 1463.505, 646.3554, 'Skybreaker Troop Transport'),
(32225, 6, 6655.649, 1608.774, 709.994, 'Skybreaker Troop Transport'),
(32225, 7, 6624.22, 1736.658, 728.0214, 'Skybreaker Troop Transport'),
(32225, 8, 6669.947, 1866.185, 709.688, 'Skybreaker Troop Transport'),
(32225, 9, 6718.041, 1885.129, 690.6326, 'Skybreaker Troop Transport'),
(32225, 10, 6795.828, 1838.745, 659.0216, 'Skybreaker Troop Transport'),
(32225, 11, 6829.202, 1723.054, 616.9384, 'Skybreaker Troop Transport'),
(32225, 12, 6938.554, 1702.879, 585.9383, 'Skybreaker Troop Transport'),
(32225, 13, 7024.898, 1752.804, 565.5496, 'Skybreaker Troop Transport'),
(32225, 14, 7113.707, 1734.315, 556.3559, 'Skybreaker Troop Transport'),
(32225, 15, 7265.8, 1765.196, 556.3559, 'Skybreaker Troop Transport'),
(32225, 16, 7302.899, 1853.759, 575.8558, 'Skybreaker Troop Transport'),
(32225, 17, 7312.44, 1944.328, 581.4116, 'Skybreaker Troop Transport'),
(32225, 18, 7307.329, 2014.243, 581.4116, 'Skybreaker Troop Transport'),
(32225, 19, 7253.363, 2115.422, 583.3, 'Skybreaker Troop Transport'),
(32225, 20, 7193.522, 2155.816, 607.7997, 'Skybreaker Troop Transport'),
(32225, 21, 7128.84, 2168.484, 642.6707, 'Skybreaker Troop Transport'),
(32225, 22, 7069.121, 2157.589, 689.7963, 'Skybreaker Troop Transport'),
(32225, 23, 7024.457, 2135.705, 708.6849, 'Skybreaker Troop Transport'),
(32225, 24, 6934.063, 2183.969, 750.9397, 'Skybreaker Troop Transport'),
(32225, 25, 6941.725, 2249.074, 754.6065, 'Skybreaker Troop Transport'),
(32225, 26, 7072.678, 2295.607, 714.44, 'Skybreaker Troop Transport'),
(32225, 27, 7260.946, 2257.761, 639.7736, 'Skybreaker Troop Transport'),
(32225, 28, 7419.038, 2123.693, 587.7736, 'Skybreaker Troop Transport'),
(32225, 29, 7471.735, 1962.737, 559.6346, 'Skybreaker Troop Transport'),
(32225, 30, 7436.465, 1818.688, 508.0233, 'Skybreaker Troop Transport'),
(32225, 31, 7366.372, 1694.51, 469.3012, 'Skybreaker Troop Transport'),
(32225, 32, 7329.872, 1609.157, 432.2737, 'Skybreaker Troop Transport'),
(32225, 33, 7296.424, 1556.42, 417.7181, 'Skybreaker Troop Transport'),
(32225, 34, 7272.382, 1525.835, 411.4405, 'Skybreaker Troop Transport');

-- Skybreaker Suppression Turret SAI
SET @ENTRY := 32227;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,27,0,100,0,0,0,0,0,45,1,0,0,0,0,0,19,32225,10,0,0,0,0,0,"Skybreaker Suppression Turret - On Passenger Boarded - Set Data 1 0");

-- Skybreaker Troop Transport SAI
SET @ENTRY := 32225;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Data Set 1 0 - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,9,32225,0,0,11,64631,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Waypoint 11 Reached - Cast 'Eject Passenger 3'"),
(@ENTRY,0,2,0,40,0,100,0,13,32225,0,0,11,64614,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Waypoint 16 Reached - Cast 'Eject Passenger 4'"),
(@ENTRY,0,3,0,40,0,100,0,17,32225,0,0,11,64633,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Waypoint 19 Reached - Cast 'Eject Passenger 5'"),
(@ENTRY,0,4,0,40,0,100,0,22,32225,0,0,11,64634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Waypoint 22 Reached - Cast 'Eject Passenger 6'"),
(@ENTRY,0,5,0,40,0,100,0,34,32225,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Waypoint 32 Reached - Despawn Instant");

-- Actionlist SAI
SET @ENTRY := 3222500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,53,1,32225,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Script - Start Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Script - Set Reactstate Passive"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,18,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Script - Set Flag Pacified"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Troop Transport - On Script - Set Health Regeneration Off");

-- Skybreaker Infiltrator SAI
SET @ENTRY := 32222;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,1,46598,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Infiltrator - On Has Aura 'Ride Vehicle Hardcoded' - Run Script (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 3222200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,60208,0,0,0,0,0,21,20,0,0,0,0,0,0,"Skybreaker Infiltrator - On Script - Cast 'Ally Air Dropoff Kill Credit'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Infiltrator - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,100,100,0,0,11,45472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Infiltrator - On Script - Cast 'Parachute'"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Infiltrator - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`=32222;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(32222, 0, 0, 'I''ll kill one just for you.', 12, 0, 100, 0, 0, 0, 'Skybreaker Infiltrator',32532),
(32222, 0, 1, 'Dropping. Good luck, boys!', 12, 0, 100, 0, 0, 0, 'Skybreaker Infiltrator',32526),
(32222, 0, 2, 'Thanks for the cover!', 12, 0, 100, 0, 0, 0, 'Skybreaker Infiltrator',32527),
(32222, 0, 3, 'Destination reached - engaging in scouting mission.', 12, 0, 100, 0, 0, 0, 'Skybreaker Infiltrator',32528),
(32222, 0, 4, 'Infiltration commencing.', 12, 0, 100, 0, 0, 0, 'Skybreaker Infiltrator',32529);

-- Ymirheim Spear Gun SAI
SET @ENTRY := 31280;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,1,100,0,5000,5000,3000,4000,11,59894,0,0,0,0,0,19,32225,100,0,0,0,0,0,"Ymirheim Spear Gun - Out of Combat - Cast 'Launch Spear' (Phase 1)"),
(@ENTRY,0,1,0,1,1,100,0,5000,5000,3000,4000,11,59894,0,0,0,0,0,19,32225,100,0,0,0,0,0,"Ymirheim Spear Gun - Out of Combat - Cast 'Launch Spear' (Phase 1)"),
(@ENTRY,0,2,3,8,0,100,0,59880,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Spellhit 'Suppression Charge' - Set Event Phase 2"),
(@ENTRY,0,3,0,61,0,100,0,59880,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Spellhit 'Suppression Charge' - Run Script"),
(@ENTRY,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Reset - Set Event Phase 1");

-- Actionlist SAI
SET @ENTRY := 3128000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,15000,15000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Event Phase 1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=32227 AND `SourceEntry`=46598;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 32227, 46598, 0, 0, 9, 0, 13309, 0, 0, 0, 0, 0, '', 'Required quest ''Assault by Ait'' active for spellclick');


-- DB/Quest: Assault by Air (A)
UPDATE `creature_template` SET `spell1`=59880 WHERE `entry`=31884;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid`=125330;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=31881;
UPDATE `creature_template` SET `speed_run`=3 WHERE  `entry`=31881;
UPDATE `vehicle_template_accessory` SET `minion`=1 WHERE  `entry`=31881 AND `seat_id`=0;

DELETE FROM `waypoints` WHERE `entry`=31881;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(31881, 1, 7513.354, 1781.131, 381.561, 'Kor\'kron Troop Transport'),
(31881, 2, 7508.576, 1843.856, 445.5052, 'Kor\'kron Troop Transport'),
(31881, 3, 7496.634, 1890.942, 496.6479, 'Kor\'kron Troop Transport'),
(31881, 4, 7451.161, 1990.051, 581.2389, 'Kor\'kron Troop Transport'),
(31881, 5, 7372.757, 2143.088, 590.3499, 'Kor\'kron Troop Transport'),
(31881, 6, 7293.971, 2233.48, 602.4611, 'Kor\'kron Troop Transport'),
(31881, 7, 7117.833, 2278.535, 605.0721, 'Kor\'kron Troop Transport'),
(31881, 8, 7017.111, 2263.003, 647.082, 'Kor\'kron Troop Transport'),
(31881, 9, 6996.222, 2205.772, 679.2115, 'Kor\'kron Troop Transport'),
(31881, 10, 7061.963, 2173.603, 675.7964, 'Kor\'kron Troop Transport'),
(31881, 11, 7121.235, 2156.643, 656.629, 'Kor\'kron Troop Transport'),
(31881, 12, 7217.851, 2134.94, 612.4905, 'Kor\'kron Troop Transport'),
(31881, 13, 7288.108, 2086.021, 596.8795, 'Kor\'kron Troop Transport'),
(31881, 14, 7327.417, 1958.794, 585.9348, 'Kor\'kron Troop Transport'),
(31881, 15, 7298.545, 1875.991, 585.4906, 'Kor\'kron Troop Transport'),
(31881, 16, 7249.319, 1800.969, 588.4902, 'Kor\'kron Troop Transport'),
(31881, 17, 7157.543, 1745.975, 588.4902, 'Kor\'kron Troop Transport'),
(31881, 18, 7067.531, 1718.656, 588.4902, 'Kor\'kron Troop Transport'),
(31881, 19, 6988.929, 1710.539, 589.5177, 'Kor\'kron Troop Transport'),
(31881, 20, 6858.088, 1715.7, 617.0735, 'Kor\'kron Troop Transport'),
(31881, 21, 6789.24, 1811.618, 658.2943, 'Kor\'kron Troop Transport'),
(31881, 22, 6741.477, 1881.004, 687.6509, 'Kor\'kron Troop Transport'),
(31881, 23, 6687.517, 1859.595, 701.3486, 'Kor\'kron Troop Transport'),
(31881, 24, 6683.648, 1766.575, 692.5154, 'Kor\'kron Troop Transport'),
(31881, 25, 6738.948, 1709.63, 686.7657, 'Kor\'kron Troop Transport'),
(31881, 26, 6906.804, 1642.973, 664.1547, 'Kor\'kron Troop Transport'),
(31881, 27, 7009.317, 1640.16, 631.8771, 'Kor\'kron Troop Transport'),
(31881, 28, 7174.014, 1608.189, 554.7385, 'Kor\'kron Troop Transport'),
(31881, 29, 7328.232, 1587.251,  465.3495, 'Kor\'kron Troop Transport'),
(31881, 30, 7449.845, 1582.211, 415.2385, 'Kor\'kron Troop Transport'),
(31881, 31, 7493.209, 1659.839, 383.9886, 'Kor\'kron Troop Transport'),
(31881, 32, 7508.813, 1745.664, 371.2109, 'Kor\'kron Troop Transport');

-- Kor'kron Suppression Turret SAI
SET @ENTRY := 31884;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,27,0,100,0,0,0,0,0,45,1,0,0,0,0,0,19,31881,10,0,0,0,0,0,"Kor'kron Suppression Turret - On Passenger Boarded - Set Data 1 0");

-- Kor'kron Troop Transport SAI
SET @ENTRY := 31881;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,0,0,0,80,3188100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Data Set 1 0 - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,11,31881,0,0,11,64631,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Waypoint 2 Reached - Cast 'Dop Passenger3'"),
(@ENTRY,0,2,0,40,0,100,0,16,31881,0,0,11,64614,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Waypoint 2 Reached - Cast 'Dop Passenger4'"),
(@ENTRY,0,3,0,40,0,100,0,19,31881,0,0,11,64633,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Waypoint 2 Reached - Cast 'Dop Passenger5'"),
(@ENTRY,0,4,0,40,0,100,0,22,31881,0,0,11,64634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Waypoint 2 Reached - Cast 'Dop Passenger6'"),
(@ENTRY,0,5,0,40,0,100,0,32,31881,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Waypoint 32 Reached - Despawn");

-- Actionlist SAI
SET @ENTRY := 3188100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,53,1,31881,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Script - Start Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Script - Set Reactstate Passive"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,18,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Script - Set Flag Pacified"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Troop Transport - On Script - Set Health Regeneration Off");

-- Kor'kron Infiltrator SAI
SET @ENTRY := 31882;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,1,46598,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Infiltrator - On Has Aura 'Ride Vehicle Hardcoded' - Run Script (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 3188200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,59977,0,0,0,0,0,21,20,0,0,0,0,0,0,"Kor'kron Infiltrator - On Script - Cast 'Horde Air Dropoff Kill Credit'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Infiltrator - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,100,100,0,0,11,45472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Infiltrator - On Script - Cast 'Parachute'"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Infiltrator - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`=31882;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(31882, 0, 0, 'I''ll kill one just for you.', 12, 0, 100, 0, 0, 0, 'Kor''kron Infiltrator',32532),
(31882, 0, 1, 'Dropping. Good luck, boys!', 12, 0, 100, 0, 0, 0, 'Kor''kron Infiltrator',32526),
(31882, 0, 2, 'Thanks for the cover!', 12, 0, 100, 0, 0, 0, 'Kor''kron Infiltrator',32527),
(31882, 0, 3, 'Destination reached - engaging in scouting mission.', 12, 0, 100, 0, 0, 0, 'Kor''kron Infiltrator',32528),
(31882, 0, 4, 'Infiltration commencing.', 12, 0, 100, 0, 0, 0, 'Kor''kron Infiltrator',32529);

-- Ymirheim Spear Gun SAI
SET @ENTRY := 31280;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,1,100,0,5000,5000,3000,4000,11,59894,0,0,0,0,0,19,31881,100,0,0,0,0,0,"Ymirheim Spear Gun - Out of Combat - Cast 'Launch Spear' (Phase 1)"),
(@ENTRY,0,1,2,8,0,100,0,59880,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Spellhit 'Suppression Charge' - Set Event Phase 2"),
(@ENTRY,0,2,0,61,0,100,0,59880,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Spellhit 'Suppression Charge' - Run Script"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirheim Spear Gun - On Reset - Set Event Phase 1");

-- Actionlist SAI
SET @ENTRY := 3128000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,15000,15000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Event Phase 1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=31884 AND `SourceEntry`=46598;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 31884, 46598, 0, 0, 9, 0, 13310, 0, 0, 0, 0, 0, '', 'Required quest ''Assault by Ait'' active for spellclick');
-- 
-- Melizza Brimbuzzle SAI
SET @ENTRY := 12277;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,6132,0,0,0,53,0,@ENTRY*100+00,0,0,0,1,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Quest 'Get Me Out of Here!' Taken - Start Waypoint"),
(@ENTRY,0,1,12,61,0,100,0,6132,0,0,0,81,0,0,0,0,0,0,10,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Quest 'Get Me Out of Here!' Taken - Set Npc Flag "),
(@ENTRY,0,2,0,40,0,100,0,3,@ENTRY*100+00,0,0,1,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Melizza Brimbuzzle - On Waypoint 3 Reached - Say Line 0"),
(@ENTRY,0,3,4,40,0,100,0,58,@ENTRY*100+00,0,0,15,6132,0,0,0,0,0,17,0,30,0,0,0,0,0,"Melizza Brimbuzzle - On Waypoint 58 Reached - Quest Credit 'Get Me Out of Here!'"),
(@ENTRY,0,4,5,61,0,100,0,58,@ENTRY*100+00,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Waypoint 58 Reached - Say Line 1"),
(@ENTRY,0,5,6,61,0,100,0,58,@ENTRY*100+00,0,0,53,1,@ENTRY*100+01,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Waypoint 58 Reached - Start Waypoint"),
(@ENTRY,0,6,0,61,0,100,0,58,@ENTRY*100+00,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Waypoint 58 Reached - Set Active On"),
(@ENTRY,0,7,8,40,0,100,0,69,@ENTRY*100+01,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Waypoint 69 Reached - Pause Waypoint"),
(@ENTRY,0,8,0,61,0,100,0,69,@ENTRY*100+01,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Waypoint 69 Reached - Run Script"),
(@ENTRY,0,9,0,40,0,100,0,93,@ENTRY*100+01,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Waypoint 93 Reached - Despawn In 3000 ms"),
(@ENTRY,0,10,13,11,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Respawn - Set Npc Flag Questgiver"),
(@ENTRY,0,11,0,40,0,100,1,57,@ENTRY*100+00,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Waypoint 57 Reached - Run Script (No Repeat)"),
(@ENTRY,0,12,0,61,0,100,0,6132,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Quest 'Get Me Out of Here!' Taken - Set Faction 250"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,2,474,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Respawn - Set Faction 474");

-- Actionlist SAI
SET @ENTRY := 1227700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 2"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 3"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 4");

-- Actionlist SAI
SET @ENTRY := 1227701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,4655,7,0,0,0,0,8,0,0,0,-1382.56,2417.06,88.9714,2.46091,"Melizza Brimbuzzle - On Script - Summon Creature 'Maraudine Wrangler'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,12,4655,7,0,0,0,0,8,0,0,0,-1406.39,2423.48,88.5732,0.20944,"Melizza Brimbuzzle - On Script - Summon Creature 'Maraudine Wrangler'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,12,4655,7,0,0,0,0,8,0,0,0,-1394.38,2417.12,88.7675,0.959931,"Melizza Brimbuzzle - On Script - Summon Creature 'Maraudine Wrangler'");

DELETE FROM `creature_text` WHERE `entry`=12277;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(12277, 0, 0, 'Thanks $n.  Now let''s get out of here!', 12, 0, 100, 0, 0, 0, 7540, 'Melizza Brimbuzzle'),
(12277, 1, 0, 'We made it!  Thanks again!  I''m going to run ahead!', 12, 0, 100, 0, 0, 0, 7544, 'Melizza Brimbuzzle'),
(12277, 2, 0, 'Hey Hornizz!  I''m back!  And there are some people behind me who helped me out of a jam.', 12, 0, 100, 0, 0, 0, 7550, 'Melizza Brimbuzzle'),
(12277, 3, 0, 'We''re going to have to scratch the Maraudines off our list.  Too hard to work with...', 12, 0, 100, 0, 0, 0, 7551, 'Melizza Brimbuzzle'),
(12277, 4, 0, 'Well, I''m off to the Gelkis.  They''re not as dumb as the Maraudines, but they''re more reasonable.', 12, 0, 100, 0, 0, 0, 7552, 'Melizza Brimbuzzle');

SET @PATH := 1227700;
SET @PATH_TWO := 1227701;
DELETE FROM `waypoints` WHERE `entry` IN (@PATH, @PATH_TWO);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@PATH,1,-1155.146,2709.409,111.2361,'Melizza Brimbuzzle'),
(@PATH,2,-1155.146,2709.409,111.2361,'Melizza Brimbuzzle'),
(@PATH,3,-1162.785,2712.464,111.5828,'Melizza Brimbuzzle'),
(@PATH,4,-1162.752,2712.397,111.6417,'Melizza Brimbuzzle'),
(@PATH,5,-1169.502,2711.397,112.3917,'Melizza Brimbuzzle'),
(@PATH,6,-1177.48,2710.258,112.1255,'Melizza Brimbuzzle'),
(@PATH,7,-1199.98,2702.508,111.6255,'Melizza Brimbuzzle'),
(@PATH,8,-1206.389,2700.128,111.496,'Melizza Brimbuzzle'),
(@PATH,9,-1248.919,2680.271,111.8919,'Melizza Brimbuzzle'),
(@PATH,10,-1272.489,2666.548,111.8956,'Melizza Brimbuzzle'),
(@PATH,11,-1288.82,2646.104,111.7111,'Melizza Brimbuzzle'),
(@PATH,12,-1290.413,2644.388,111.6542,'Melizza Brimbuzzle'),
(@PATH,13,-1290.413,2644.388,111.6542,'Melizza Brimbuzzle'),
(@PATH,14,-1290.413,2644.388,111.6542,'Melizza Brimbuzzle'),
(@PATH,15,-1309.874,2622.18,111.7776,'Melizza Brimbuzzle'),
(@PATH,16,-1309.908,2622.186,111.9743,'Melizza Brimbuzzle'),
(@PATH,17,-1323.898,2605.008,111.8986,'Melizza Brimbuzzle'),
(@PATH,18,-1336.769,2591.199,111.8607,'Melizza Brimbuzzle'),
(@PATH,19,-1349.322,2578.486,111.7647,'Melizza Brimbuzzle'),
(@PATH,20,-1359.602,2564.017,111.4906,'Melizza Brimbuzzle'),
(@PATH,21,-1361.852,2559.517,110.7406,'Melizza Brimbuzzle'),
(@PATH,22,-1362.352,2557.767,109.9906,'Melizza Brimbuzzle'),
(@PATH,23,-1363.102,2556.267,109.4906,'Melizza Brimbuzzle'),
(@PATH,24,-1364.602,2553.517,108.9906,'Melizza Brimbuzzle'),
(@PATH,25,-1365.352,2551.767,108.2406,'Melizza Brimbuzzle'),
(@PATH,26,-1366.102,2550.017,107.7406,'Melizza Brimbuzzle'),
(@PATH,27,-1366.477,2549.685,107.5719,'Melizza Brimbuzzle'),
(@PATH,28,-1366.727,2549.185,107.0719,'Melizza Brimbuzzle'),
(@PATH,29,-1367.227,2547.185,106.8219,'Melizza Brimbuzzle'),
(@PATH,30,-1367.727,2545.185,106.0719,'Melizza Brimbuzzle'),
(@PATH,31,-1368.477,2543.435,105.3219,'Melizza Brimbuzzle'),
(@PATH,32,-1368.977,2541.435,104.5719,'Melizza Brimbuzzle'),
(@PATH,33,-1369.477,2539.435,103.8219,'Melizza Brimbuzzle'),
(@PATH,34,-1370.227,2536.685,103.3219,'Melizza Brimbuzzle'),
(@PATH,35,-1370.977,2534.685,102.5719,'Melizza Brimbuzzle'),
(@PATH,36,-1371.227,2532.935,102.0719,'Melizza Brimbuzzle'),
(@PATH,37,-1371.727,2531.185,101.3219,'Melizza Brimbuzzle'),
(@PATH,38,-1372.227,2529.185,100.8219,'Melizza Brimbuzzle'),
(@PATH,39,-1372.977,2527.185,100.0719,'Melizza Brimbuzzle'),
(@PATH,40,-1373.727,2524.435,99.32188,'Melizza Brimbuzzle'),
(@PATH,41,-1374.227,2522.435,98.57188,'Melizza Brimbuzzle'),
(@PATH,42,-1374.727,2520.685,97.82188,'Melizza Brimbuzzle'),
(@PATH,43,-1375.477,2518.685,97.32188,'Melizza Brimbuzzle'),
(@PATH,44,-1375.639,2518.402,97.00177,'Melizza Brimbuzzle'),
(@PATH,45,-1375.889,2517.152,96.75177,'Melizza Brimbuzzle'),
(@PATH,46,-1376.389,2515.152,96.00177,'Melizza Brimbuzzle'),
(@PATH,47,-1376.889,2513.402,95.25177,'Melizza Brimbuzzle'),
(@PATH,48,-1378.139,2509.402,93.75177,'Melizza Brimbuzzle'),
(@PATH,49,-1378.389,2507.652,93.00177,'Melizza Brimbuzzle'),
(@PATH,50,-1379.139,2504.902,92.50177,'Melizza Brimbuzzle'),
(@PATH,51,-1379.889,2501.902,91.75177,'Melizza Brimbuzzle'),
(@PATH,52,-1380.389,2500.152,91.25177,'Melizza Brimbuzzle'),
(@PATH,53,-1381.389,2496.152,90.50177,'Melizza Brimbuzzle'),
(@PATH,54,-1381.559,2495.931,90.14986,'Melizza Brimbuzzle'),
(@PATH,55,-1381.809,2495.431,90.14986,'Melizza Brimbuzzle'),
(@PATH,56,-1382.309,2491.431,89.64986,'Melizza Brimbuzzle'),
(@PATH,57,-1385.493,2471.513,89.11208,'Melizza Brimbuzzle'),
(@PATH,58,-1386.618,2405.71,89.767,'Melizza Brimbuzzle'),
(@PATH_TWO,1,-1385.368,2401.21,90.267,'Melizza Brimbuzzle'),
(@PATH_TWO,2,-1383.618,2395.46,90.767,'Melizza Brimbuzzle'),
(@PATH_TWO,3,-1382.118,2390.71,91.517,'Melizza Brimbuzzle'),
(@PATH_TWO,4,-1377.252,2375.137,91.91622,'Melizza Brimbuzzle'),
(@PATH_TWO,5,-1373.759,2355.208,92.06256,'Melizza Brimbuzzle'),
(@PATH_TWO,6,-1366.36,2323.406,91.9967,'Melizza Brimbuzzle'),
(@PATH_TWO,7,-1362.618,2277.267,91.79288,'Melizza Brimbuzzle'),
(@PATH_TWO,8,-1358.118,2257.017,91.54288,'Melizza Brimbuzzle'),
(@PATH_TWO,9,-1354.14,2239.229,91.62033,'Melizza Brimbuzzle'),
(@PATH_TWO,10,-1352.89,2229.729,92.12033,'Melizza Brimbuzzle'),
(@PATH_TWO,11,-1350.869,2214.848,91.63843,'Melizza Brimbuzzle'),
(@PATH_TWO,12,-1351.869,2210.848,90.88843,'Melizza Brimbuzzle'),
(@PATH_TWO,13,-1352.119,2209.848,90.13843,'Melizza Brimbuzzle'),
(@PATH_TWO,14,-1352.619,2208.098,89.13843,'Melizza Brimbuzzle'),
(@PATH_TWO,15,-1352.869,2207.098,87.88843,'Melizza Brimbuzzle'),
(@PATH_TWO,16,-1353.119,2206.098,86.38843,'Melizza Brimbuzzle'),
(@PATH_TWO,17,-1353.369,2205.348,85.38843,'Melizza Brimbuzzle'),
(@PATH_TWO,18,-1353.619,2204.348,84.38843,'Melizza Brimbuzzle'),
(@PATH_TWO,19,-1354.119,2202.348,83.63843,'Melizza Brimbuzzle'),
(@PATH_TWO,20,-1354.369,2201.348,82.88843,'Melizza Brimbuzzle'),
(@PATH_TWO,21,-1354.619,2200.598,82.13843,'Melizza Brimbuzzle'),
(@PATH_TWO,22,-1354.869,2199.598,81.38843,'Melizza Brimbuzzle'),
(@PATH_TWO,23,-1355.119,2198.598,80.63843,'Melizza Brimbuzzle'),
(@PATH_TWO,24,-1355.119,2197.598,79.88843,'Melizza Brimbuzzle'),
(@PATH_TWO,25,-1355.619,2195.598,78.88843,'Melizza Brimbuzzle'),
(@PATH_TWO,26,-1356.119,2193.848,77.88843,'Melizza Brimbuzzle'),
(@PATH_TWO,27,-1356.619,2191.848,77.13843,'Melizza Brimbuzzle'),
(@PATH_TWO,28,-1357.619,2188.848,76.38843,'Melizza Brimbuzzle'),
(@PATH_TWO,29,-1355.239,2198.246,80.43513,'Melizza Brimbuzzle'),
(@PATH_TWO,30,-1355.489,2197.246,79.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,31,-1355.989,2195.496,78.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,32,-1356.489,2193.496,77.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,33,-1356.989,2191.496,76.93513,'Melizza Brimbuzzle'),
(@PATH_TWO,34,-1357.739,2188.746,76.18513,'Melizza Brimbuzzle'),
(@PATH_TWO,35,-1357.989,2187.496,75.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,36,-1358.739,2185.746,75.18513,'Melizza Brimbuzzle'),
(@PATH_TWO,37,-1359.239,2183.746,74.43513,'Melizza Brimbuzzle'),
(@PATH_TWO,38,-1359.989,2181.996,73.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,39,-1360.489,2179.996,72.93513,'Melizza Brimbuzzle'),
(@PATH_TWO,40,-1361.489,2177.246,72.18513,'Melizza Brimbuzzle'),
(@PATH_TWO,41,-1362.239,2175.246,71.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,42,-1362.739,2173.496,70.93513,'Melizza Brimbuzzle'),
(@PATH_TWO,43,-1363.239,2171.746,70.43513,'Melizza Brimbuzzle'),
(@PATH_TWO,44,-1363.739,2169.746,69.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,45,-1364.739,2166.996,68.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,46,-1365.489,2164.996,67.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,47,-1365.989,2163.246,66.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,48,-1366.739,2161.246,65.93513,'Melizza Brimbuzzle'),
(@PATH_TWO,49,-1367.489,2159.496,64.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,50,-1367.989,2157.496,63.93513,'Melizza Brimbuzzle'),
(@PATH_TWO,51,-1368.989,2154.746,63.18513,'Melizza Brimbuzzle'),
(@PATH_TWO,52,-1369.739,2152.746,62.43513,'Melizza Brimbuzzle'),
(@PATH_TWO,53,-1370.239,2150.996,61.68513,'Melizza Brimbuzzle'),
(@PATH_TWO,54,-1370.989,2148.996,60.93513,'Melizza Brimbuzzle'),
(@PATH_TWO,55,-1369.163,2154.362,62.88633,'Melizza Brimbuzzle'),
(@PATH_TWO,56,-1369.913,2152.612,62.63633,'Melizza Brimbuzzle'),
(@PATH_TWO,57,-1370.413,2150.612,61.63633,'Melizza Brimbuzzle'),
(@PATH_TWO,58,-1371.163,2148.862,61.13633,'Melizza Brimbuzzle'),
(@PATH_TWO,59,-1371.663,2147.612,60.63633,'Melizza Brimbuzzle'),
(@PATH_TWO,60,-1374.663,2142.362,60.13633,'Melizza Brimbuzzle'),
(@PATH_TWO,61,-1381.413,2131.612,60.88633,'Melizza Brimbuzzle'),
(@PATH_TWO,62,-1387.413,2121.362,61.38633,'Melizza Brimbuzzle'),
(@PATH_TWO,63,-1391.413,2114.362,62.13633,'Melizza Brimbuzzle'),
(@PATH_TWO,64,-1395.163,2108.362,62.63633,'Melizza Brimbuzzle'),
(@PATH_TWO,65,-1391.807,2114.246,61.76419,'Melizza Brimbuzzle'),
(@PATH_TWO,66,-1395.307,2108.246,62.26419,'Melizza Brimbuzzle'),
(@PATH_TWO,67,-1396.307,2106.496,62.51419,'Melizza Brimbuzzle'),
(@PATH_TWO,68,-1404.391,2088.967,62.0089,'Melizza Brimbuzzle'),
(@PATH_TWO,69,-1405.748,2087.39,62.09642,'Melizza Brimbuzzle'),
(@PATH_TWO,70,-1407.248,2086.89,62.09642,'Melizza Brimbuzzle'),
(@PATH_TWO,71,-1408.248,2086.89,62.34642,'Melizza Brimbuzzle'),
(@PATH_TWO,72,-1410.498,2086.39,62.34642,'Melizza Brimbuzzle'),
(@PATH_TWO,73,-1412.498,2086.39,62.59642,'Melizza Brimbuzzle'),
(@PATH_TWO,74,-1413.998,2085.39,62.59642,'Melizza Brimbuzzle'),
(@PATH_TWO,75,-1415.498,2083.39,62.59642,'Melizza Brimbuzzle'),
(@PATH_TWO,76,-1416.498,2082.39,62.59642,'Melizza Brimbuzzle'),
(@PATH_TWO,77,-1417.498,2079.39,62.59642,'Melizza Brimbuzzle'),
(@PATH_TWO,78,-1417.998,2077.39,62.59642,'Melizza Brimbuzzle'),
(@PATH_TWO,79,-1419.998,2075.14,62.59642,'Melizza Brimbuzzle'),
(@PATH_TWO,80,-1424.748,2073.14,62.34642,'Melizza Brimbuzzle'),
(@PATH_TWO,81,-1418.114,2077.1,62.59175,'Melizza Brimbuzzle'),
(@PATH_TWO,82,-1420.364,2075.35,62.59175,'Melizza Brimbuzzle'),
(@PATH_TWO,83,-1425.114,2073.1,62.34175,'Melizza Brimbuzzle'),
(@PATH_TWO,84,-1425.114,2075.1,62.34175,'Melizza Brimbuzzle'),
(@PATH_TWO,85,-1436.864,2074.35,62.84175,'Melizza Brimbuzzle'),
(@PATH_TWO,86,-1451.277,2073.542,62.70998,'Melizza Brimbuzzle'),
(@PATH_TWO,87,-1464.777,2075.542,62.95998,'Melizza Brimbuzzle'),
(@PATH_TWO,88,-1465.031,2075.661,62.89689,'Melizza Brimbuzzle'),
(@PATH_TWO,89,-1473.031,2077.161,63.14689,'Melizza Brimbuzzle'),
(@PATH_TWO,90,-1480.031,2086.411,62.39689,'Melizza Brimbuzzle'),
(@PATH_TWO,91,-1485.531,2093.411,61.89689,'Melizza Brimbuzzle'),
(@PATH_TWO,92,-1485.639,2093.875,61.82396,'Melizza Brimbuzzle'),
(@PATH_TWO,93,-1487.889,2096.375,61.82396,'Melizza Brimbuzzle');
SET @Oguid=5638;  -- 2 free Gob guid set by TC
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (3746, 3766);
INSERT INTO `areatrigger_scripts` VALUES (3746,'SmartTrigger'), (3766,'SmartTrigger');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3746, 3766) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3746, 2, 0, 0, 46, 0, 100, 0, 3746, 0, 0, 0, 70, 7200, 0, 0, 0, 0, 0, 14, @Oguid+1, 180024, 0, 0, 0, 0, 0, 'Area Trigger 3746 - On Trigger - Respawn Mysterious Deadmines Chest'),
(3766, 2, 0, 0, 46, 0, 100, 0, 3766, 0, 0, 0, 70, 7200, 0, 0, 0, 0, 0, 14, @Oguid, 180055, 0, 0, 0, 0, 0, 'Area Trigger 3746 - On Trigger - Respawn Mysterious Wailing Caverns');
DELETE FROM `gameobject` WHERE `id` IN (180055, 180024);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseId`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@Oguid,180055,43,1,169,-97.6,173.8,-79,2.08,0,0,0.862404,0.50622,-1,100,1),
(@Oguid+1,180024,36,1,169,-32.1232,-374.64,59.06,3.0820,0,0,0.879275,-0.476315,-1,100,1); 
DELETE FROM `gameobject_questender` WHERE `id`=180055 AND `quest`=7944;
INSERT INTO `gameobject_questender` (`id`,`quest`) VALUES (180055,7944);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (3766,3746) AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,3746,2,0,28,0,7938,0,0,0,0,'','SAI areatrigger 3746 triggers only if player has the quest 7938'),
(22,1,3766,2,0,28,0,7944,0,0,0,0,'','SAI areatrigger 3766 triggers only if player has the quest 7944');
-- 
-- Pit-Fighting Spectator SAI
SET @ENTRY := 26869;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,6000,10000,20000,10,4,21,6,11,0,0,1,0,0,0,0,0,0,0,"Pit-Fighting Spectator - Out of Combat - Play Random Emote (4, 21, 6, 11)");
-- Conquest Hold Legionnaire
SET @NPC := 116284;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3222.422,`position_y`=-2261.431,`position_z`=112.903 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3222.422,-2261.431,112.903,0,0,0,0,100,0),
(@PATH,2,3223.03,-2264.1,112.1124,0,0,0,0,100,0),
(@PATH,3,3223.781,-2267.022,111.1831,0,0,0,0,100,0),
(@PATH,4,3224.569,-2267.831,111.0135,0,0,0,0,100,0),
(@PATH,5,3226.668,-2270.648,110.3546,0,0,0,0,100,0),
(@PATH,6,3229.054,-2274.084,109.3319,0,0,0,0,100,0),
(@PATH,7,3230.216,-2275.468,109.1555,0,0,0,0,100,0),
(@PATH,8,3232.466,-2278.367,108.6153,0,0,0,0,100,0),
(@PATH,9,3234.924,-2280.143,108.2696,0,0,0,0,100,0),
(@PATH,10,3237.392,-2281.926,108.2696,0,0,0,0,100,0),
(@PATH,11,3239.848,-2283.7,108.2879,0,0,0,0,100,0),
(@PATH,12,3240.568,-2283.284,108.2696,0,0,0,0,100,0),
(@PATH,13,3243.724,-2282.795,108.3946,0,0,0,0,100,0),
(@PATH,14,3246.881,-2282.306,108.3946,0,0,0,0,100,0),
(@PATH,15,3250.019,-2281.82,108.5137,0,0,0,0,100,0),
(@PATH,16,3253.206,-2281.326,108.5008,0,0,0,0,100,0),
(@PATH,17,3255.859,-2280.714,108.5196,0,0,0,0,100,0),
(@PATH,18,3258.817,-2279.989,108.4834,0,0,0,0,100,0),
(@PATH,19,3261.763,-2279.267,108.3458,0,0,0,0,100,0),
(@PATH,20,3264.564,-2278.554,108.5305,0,0,0,0,100,0),
(@PATH,21,3267.448,-2277.735,108.8179,0,0,0,0,100,0),
(@PATH,22,3269.372,-2277.215,109.3157,0,0,0,0,100,0),
(@PATH,23,3273.088,-2276.127,109.8022,0,0,0,0,100,0),
(@PATH,24,3277.416,-2276.224,109.3619,0,0,0,0,100,0),
(@PATH,25,3280.093,-2277.505,108.8861,0,0,0,0,100,0),
(@PATH,26,3282.834,-2278.816,108.7433,0,0,0,0,100,0),
(@PATH,27,3285.509,-2280.093,109.0773,0,0,0,0,100,0),
(@PATH,28,3287.798,-2280.42,109.6238,0,0,0,0,100,0),
(@PATH,29,3289.805,-2280.55,110.2963,0,0,0,0,100,0),
(@PATH,30,3291.436,-2282.21,110.212,0,0,0,0,100,0),
(@PATH,31,3293.136,-2279.585,110.3022,0,0,0,0,100,0),
(@PATH,32,3294.828,-2276.973,110.6279,0,0,0,0,100,0),
(@PATH,33,3296.068,-2275.338,110.8585,0,0,0,0,100,0),
(@PATH,34,3296.431,-2272.337,111.0591,0,0,0,0,100,0),
(@PATH,35,3296.789,-2269.371,111.363,0,0,0,0,100,0),
(@PATH,36,3297.156,-2266.315,111.6388,0,0,0,0,100,0),
(@PATH,37,3297.624,-2263.012,111.854,0,0,0,0,100,0),
(@PATH,38,3298.611,-2260.142,111.9759,0,0,0,0,100,0),
(@PATH,39,3299.594,-2257.286,112.3186,0,0,0,0,100,0),
(@PATH,40,3300.581,-2254.429,112.6177,0,0,0,0,100,0),
(@PATH,41,3300.73,-2253.996,112.6697,0,0,0,0,100,0),
(@PATH,42,3300.506,-2254.651,112.5911,0,0,0,0,100,0),
(@PATH,43,3303.751,-2259.06,112.062,0,0,0,0,100,0),
(@PATH,44,3303.142,-2262.008,111.7082,0,0,0,0,100,0),
(@PATH,45,3302.529,-2264.978,111.4768,0,0,0,0,100,0),
(@PATH,46,3301.917,-2267.939,111.3507,0,0,0,0,100,0),
(@PATH,47,3301.307,-2270.89,110.9967,0,0,0,0,100,0),
(@PATH,48,3300.701,-2273.825,110.6447,0,0,0,0,100,0),
(@PATH,49,3300.092,-2276.787,110.3161,0,0,0,0,100,0),
(@PATH,50,3297.877,-2280.104,110.3195,0,0,0,0,100,0),
(@PATH,51,3295.698,-2282.238,110.1211,0,0,0,0,100,0),
(@PATH,52,3291.665,-2283.44,110.1146,0,0,0,0,100,0),
(@PATH,53,3288.628,-2283.25,109.6978,0,0,0,0,100,0),
(@PATH,54,3286.963,-2283.097,109.5514,0,0,0,0,100,0),
(@PATH,55,3284.762,-2282.979,108.7865,0,0,0,0,100,0),
(@PATH,56,3281.819,-2282.813,107.6871,0,0,0,0,100,0),
(@PATH,57,3279.023,-2282.41,106.843,0,0,0,0,100,0),
(@PATH,58,3273.752,-2281.361,107.249,0,0,0,0,100,0),
(@PATH,59,3272.823,-2281.124,107.9806,0,0,0,0,100,0),
(@PATH,60,3269.315,-2280.155,108.8164,0,0,0,0,100,0),
(@PATH,61,3266.359,-2279.441,108.5643,0,0,0,0,100,0),
(@PATH,62,3261.786,-2278.462,108.5415,0,0,0,0,100,0),
(@PATH,63,3260.874,-2277.872,108.6126,0,0,0,0,100,0),
(@PATH,64,3258.454,-2279.771,108.5095,0,0,0,0,100,0),
(@PATH,65,3256.032,-2281.672,108.5072,0,0,0,0,100,0),
(@PATH,66,3253.73,-2283.478,108.3147,0,0,0,0,100,0),
(@PATH,67,3249.822,-2284.479,108.1946,0,0,0,0,100,0),
(@PATH,68,3246.836,-2284.902,108.1438,0,0,0,0,100,0),
(@PATH,69,3243.795,-2285.332,108.0923,0,0,0,0,100,0),
(@PATH,70,3240.329,-2284.271,108.2195,0,0,0,0,100,0),
(@PATH,71,3237.559,-2282.833,108.1446,0,0,0,0,100,0),
(@PATH,72,3234.771,-2281.385,108.2696,0,0,0,0,100,0),
(@PATH,73,3231.993,-2279.943,108.3994,0,0,0,0,100,0),
(@PATH,74,3229.22,-2278.504,108.7801,0,0,0,0,100,0),
(@PATH,75,3226.602,-2277.155,108.8858,0,0,0,0,100,0),
(@PATH,76,3224.147,-2273.925,109.3004,0,0,0,0,100,0),
(@PATH,77,3223.178,-2271.634,109.9661,0,0,0,0,100,0),
(@PATH,78,3222.1,-2269.727,110.5905,0,0,0,0,100,0),
(@PATH,79,3220.919,-2266.938,111.1347,0,0,0,0,100,0),
(@PATH,80,3219.873,-2264.861,111.7715,0,0,0,0,100,0),
(@PATH,81,3219.09,-2262.018,113.0721,0,0,0,0,100,0),
(@PATH,82,3218.371,-2259.129,113.9729,0,0,0,0,100,0),
(@PATH,83,3217.72,-2256.449,114.2141,0,0,0,0,100,0),
(@PATH,84,3217.931,-2257.32,114.1792,0,0,0,0,100,0),
(@PATH,85,3221.369,-2258.965,113.6241,0,0,0,0,100,0),
(@PATH,86,3222.448,-2261.465,112.8751,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=116284;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(116284, 116284, 0, 0, 2, 0, 0),
(116284, 116285, 3, 90, 0, 0, 0);
UPDATE `gameobject_template` SET `flags`=34 WHERE  `entry`=177192;
UPDATE `gameobject_template` SET `faction`=114 WHERE  `entry` IN(179504,179505);
-- Grizzlyhills Pathing/Events -1
SET @NPC := 105919;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2659.377,`position_y`=-2080.199,`position_z`=4.346071 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2659.377,-2080.199,4.346071,0,0,0,0,100,0),
(@PATH,2,2666.377,-2073.199,4.346071,0,0,0,0,100,0),
(@PATH,3,2670.377,-2068.949,4.346071,0,0,0,0,100,0),
(@PATH,4,2672.989,-2066.296,4.340314,0,0,0,0,100,0),
(@PATH,5,2675.489,-2062.546,4.340314,0,0,0,0,100,0),
(@PATH,6,2677.239,-2060.296,4.340314,0,0,0,0,100,0),
(@PATH,7,2678.989,-2057.796,4.340314,0,0,0,0,100,0),
(@PATH,8,2677.343,-2060.426,4.340314,0,0,0,0,100,0),
(@PATH,9,2675.593,-2062.676,4.340314,0,0,0,0,100,0),
(@PATH,10,2672.564,-2066.647,4.346634,0,0,0,0,100,0),
(@PATH,11,2670.314,-2068.897,4.346634,0,0,0,0,100,0),
(@PATH,12,2666.814,-2072.397,4.346634,0,0,0,0,100,0),
(@PATH,13,2659.411,-2080.233,4.331409,0,0,0,0,100,0),
(@PATH,14,2654.911,-2084.233,4.331409,0,0,0,0,100,0),
(@PATH,15,2653.411,-2085.733,4.331409,0,0,0,0,100,0),
(@PATH,16,2648.899,-2089.858,4.311839,0,0,0,0,100,0),
(@PATH,17,2646.649,-2091.858,4.311839,0,0,0,0,100,0),
(@PATH,18,2643.899,-2094.108,4.311839,0,0,0,0,100,0),
(@PATH,19,2640.707,-2096.753,4.415871,0,0,0,0,100,0),
(@PATH,20,2638.457,-2098.503,4.415871,0,0,0,0,100,0),
(@PATH,21,2634.457,-2101.253,5.165871,0,0,0,0,100,0),
(@PATH,22,2634.269,-2101.723,5.301712,0,0,0,0,100,0),
(@PATH,23,2632.769,-2102.723,5.551712,0,0,0,0,100,0),
(@PATH,24,2629.269,-2105.473,6.301712,0,0,0,0,100,0),
(@PATH,25,2629.244,-2105.614,6.409963,0,0,0,0,100,0),
(@PATH,26,2633.158,-2102.466,5.38058,0,0,0,0,100,0),
(@PATH,27,2634.658,-2101.466,5.13058,0,0,0,0,100,0),
(@PATH,28,2638.408,-2098.466,4.38058,0,0,0,0,100,0);

-- Pathing for  Entry: 27501 'TDB FORMAT' 
SET @NPC := 105928;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2650.357,`position_y`=-2025.178,`position_z`=4.323929 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2650.357,-2025.178,4.323929,0,0,0,0,100,0),
(@PATH,2,2653.107,-2027.178,4.323929,0,0,0,0,100,0),
(@PATH,3,2661.607,-2033.178,4.323929,0,0,0,0,100,0),
(@PATH,4,2664.357,-2035.323,4.346634,0,0,0,0,100,0),
(@PATH,5,2666.857,-2037.323,4.346634,0,0,0,0,100,0),
(@PATH,6,2666.913,-2037.288,4.346634,0,0,0,0,100,0),
(@PATH,7,2664.103,-2035.223,4.346634,0,0,0,0,100,0),
(@PATH,8,2661.603,-2033.223,4.346634,0,0,0,0,100,0),
(@PATH,9,2652.902,-2026.893,4.187136,0,0,0,0,100,0),
(@PATH,10,2650.152,-2024.893,4.187136,0,0,0,0,100,0),
(@PATH,11,2646.152,-2022.143,4.187136,0,0,0,0,100,0),
(@PATH,12,2644.652,-2021.143,3.937136,0,0,0,0,100,0),
(@PATH,13,2641.632,-2018.958,4.027632,0,0,0,0,100,0),
(@PATH,14,2641.649,-2019.105,3.777639,0,0,0,0,100,0),
(@PATH,15,2641.879,-2019.022,3.937136,0,0,0,0,100,0),
(@PATH,16,2644.629,-2021.022,3.937136,0,0,0,0,100,0),
(@PATH,17,2645.879,-2022.022,4.187136,0,0,0,0,100,0),
(@PATH,18,2650.129,-2025.022,4.187136,0,0,0,0,100,0);

-- Pathing for  Entry: 27501 'TDB FORMAT' 
SET @NPC := 105904;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2606.301,`position_y`=-2092.257,`position_z`=7.300018 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2606.301,-2092.257,7.300018,0,0,0,0,100,0),
(@PATH,2,2614.706,-2104.54,7.32203,0,0,0,0,100,0),
(@PATH,3,2614.56,-2104.616,7.087479,0,0,0,0,100,0),
(@PATH,4,2614.464,-2104.489,7.307891,0,0,0,0,100,0),
(@PATH,5,2606.464,-2092.739,7.307891,0,0,0,0,100,0),
(@PATH,6,2606.129,-2092.514,7.232858,0,0,0,0,100,0),
(@PATH,7,2605.879,-2092.014,7.232858,0,0,0,0,100,0),
(@PATH,8,2603.379,-2088.014,6.982858,0,0,0,0,100,0),
(@PATH,9,2599.288,-2081.792,7.103763,0,0,0,0,100,0),
(@PATH,10,2596.038,-2076.792,7.103763,0,0,0,0,100,0),
(@PATH,11,2593.906,-2073.879,6.877389,0,0,0,0,100,0),
(@PATH,12,2592.156,-2070.879,6.877389,0,0,0,0,100,0),
(@PATH,13,2591.965,-2070.718,6.863516,0,0,0,0,100,0),
(@PATH,14,2594.261,-2073.978,6.842519,0,0,0,0,100,0),
(@PATH,15,2595.761,-2076.728,7.092519,0,0,0,0,100,0),
(@PATH,16,2599.636,-2081.92,7.189054,0,0,0,0,100,0),
(@PATH,17,2603.386,-2087.92,7.189054,0,0,0,0,100,0);

-- Westfall Brigade Marine SAI
SET @ENTRY := 27501;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,10000,10000,10000,49,0,0,0,0,0,0,19,27500,10,0,0,0,0,0,"Westfall Brigade Marine - Out of Combat - Start Attacking");

-- Conquest Hold Berserker SAI
SET @ENTRY := 27500;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,1,0,100,0,10000,10000,10000,10000,49,0,0,0,0,0,0,19,27501,10,0,0,0,0,0,"Conquest Hold Berserker - Out of Combat - Start Attacking");

UPDATE `creature_template` SET `AIName`="" WHERE `entry`=27131;
-- Grizzly Bear SAI
SET @ENTRY := 27131;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 2713100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - On Script - Enable Combat Movement"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - On Script - Play Emote 7"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - On Script - Play Emote 7"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - On Script - Disable Combat Movement"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,89,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - On Script - Start Random Movement");

-- allow movement
UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid` IN (27259, 26679) AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Dragonflayer Flamebinder SAI
SET @ENTRY := 27259;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=14;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,14,0,1,0,100,0,5000,8000,5000,8000,11,48213,0,0,0,0,0,19,26785,25,0,0,0,0,0,"Dragonflayer Flamebinder - Out of Combat - Cast 'Dragonflayer Crone Fire'");


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=48213;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 48213, 0, 0, 31, 0, 3, 26785, 0, 0, 0, 0, '', 'Flame - only targets Bunny');

DELETE FROM `creature_addon` WHERE `guid` IN (103389, 103390, 107363, 110490, 107373, 110493, 11049, 110494, 110492, 116277, 116275, 116274, 116276, 116278, 110489);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(116277,0,0,8,1,0, ''),
(116275,0,0,8,1,0, ''),
(116274,0,0,8,1,0, ''),
(116276,0,0,8,1,0, ''),
(116278,0,0,8,1,0, ''),
(110489,0,0,0,1,214, ''),
(110492,0,0,0,1,214, ''),
(110494,0,0,0,1,214, ''),
(110490,0,0,0,1,214, ''),
(110493,0,0,0,1,214, ''),
(107363,0,0,1,1,0, ''),
(103389,0,0,0,1,1, ''),
(103390,0,0,0,1,1, ''),
(107373,0,0,1,1,0, '');

-- Graymist Hunter SAI
SET @ENTRY := 26592;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,1,0,100,0,15000,20000,15000,20000,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0,"Graymist Hunter - Out of Combat - Play Emote 53");

-- Pathing for  Entry: 26679 'TDB FORMAT' 
SET @NPC := 100911;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4346.669,`position_y`=-2484.654,`position_z`=240.982 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4346.669,-2484.654,240.982,0,0,0,0,100,0),
(@PATH,2,4347.169,-2484.904,240.982,0,0,0,0,100,0),
(@PATH,3,4348.169,-2488.654,241.982,0,0,0,0,100,0),
(@PATH,4,4349.169,-2492.404,242.232,0,0,0,0,100,0),
(@PATH,5,4350.169,-2495.154,242.982,0,0,0,0,100,0),
(@PATH,6,4351.169,-2498.904,243.732,0,0,0,0,100,0),
(@PATH,7,4352.729,-2503.633,244.4913,0,0,0,0,100,0),
(@PATH,8,4352.479,-2508.633,244.7413,0,0,0,0,100,0),
(@PATH,9,4352.229,-2516.383,245.4913,0,0,0,0,100,0),
(@PATH,10,4352.513,-2516.505,245.5218,0,0,0,0,100,0),
(@PATH,11,4352.513,-2519.755,245.5218,0,0,0,0,100,0),
(@PATH,12,4353.422,-2530.827,245.4402,0,0,0,0,100,0),
(@PATH,13,4353.167,-2531.085,245.3185,0,0,0,0,100,0),
(@PATH,14,4353.443,-2530.941,245.3693,0,0,0,0,100,0),
(@PATH,15,4352.554,-2519.469,245.4435,0,0,0,0,100,0),
(@PATH,16,4352.554,-2508.719,244.9435,0,0,0,0,100,0),
(@PATH,17,4352.496,-2503.444,244.2976,0,0,0,0,100,0),
(@PATH,18,4351.496,-2499.694,243.5476,0,0,0,0,100,0),
(@PATH,19,4350.246,-2495.944,243.0476,0,0,0,0,100,0),
(@PATH,20,4349.746,-2493.194,242.5476,0,0,0,0,100,0),
(@PATH,21,4348.746,-2490.194,242.0476,0,0,0,0,100,0),
(@PATH,22,4347.996,-2487.444,241.2976,0,0,0,0,100,0),
(@PATH,23,4346.94,-2484.907,240.7707,0,0,0,0,100,0),
(@PATH,24,4343.19,-2483.907,240.2707,0,0,0,0,100,0),
(@PATH,25,4339.44,-2482.907,239.7707,0,0,0,0,100,0),
(@PATH,26,4339.217,-2482.614,239.4836,0,0,0,0,100,0),
(@PATH,27,4337.717,-2482.114,239.2336,0,0,0,0,100,0),
(@PATH,28,4325.967,-2481.114,238.9836,0,0,0,0,100,0),
(@PATH,29,4320.836,-2480.163,238.4939,0,0,0,0,100,0),
(@PATH,30,4327.4,-2469.229,238.7592,0,0,0,0,100,0),
(@PATH,31,4339.832,-2457.689,239.1528,0,0,0,0,100,0),
(@PATH,32,4339.467,-2457.954,239.0422,0,0,0,0,100,0),
(@PATH,33,4339.559,-2457.928,239.3148,0,0,0,0,100,0),
(@PATH,34,4327.204,-2469.653,238.7065,0,0,0,0,100,0),
(@PATH,35,4320.694,-2480.362,238.713,0,0,0,0,100,0),
(@PATH,36,4330.444,-2481.362,239.213,0,0,0,0,100,0),
(@PATH,37,4337.947,-2482.492,239.5395,0,0,0,0,100,0),
(@PATH,38,4342.447,-2483.492,240.0395,0,0,0,0,100,0),
(@PATH,39,4346.447,-2484.492,240.5395,0,0,0,0,100,0);

SET @NPC := 100914;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4316.283,`position_y`=-2489.055,`position_z`=238.5876 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4316.283,-2489.055,238.5876,0,0,0,0,100,0),
(@PATH,2,4316.529,-2488.824,238.7166,0,0,0,0,100,0),
(@PATH,3,4320.335,-2479.741,238.3421,0,0,0,0,100,0),
(@PATH,4,4316.585,-2474.241,237.8421,0,0,0,0,100,0),
(@PATH,5,4313.78,-2470.097,237.5021,0,0,0,0,100,0),
(@PATH,6,4309.78,-2469.847,237.0021,0,0,0,0,100,0),
(@PATH,7,4306.03,-2469.347,236.5021,0,0,0,0,100,0),
(@PATH,8,4305.914,-2469.415,236.0416,0,0,0,0,100,0),
(@PATH,9,4303.414,-2469.165,235.5416,0,0,0,0,100,0),
(@PATH,10,4300.414,-2469.415,235.0416,0,0,0,0,100,0),
(@PATH,11,4297.414,-2469.915,234.2916,0,0,0,0,100,0),
(@PATH,12,4294.664,-2470.165,234.0416,0,0,0,0,100,0),
(@PATH,13,4290.664,-2470.415,233.2916,0,0,0,0,100,0),
(@PATH,14,4285.664,-2471.165,232.5416,0,0,0,0,100,0),
(@PATH,15,4285.473,-2471.28,232.3787,0,0,0,0,100,0),
(@PATH,16,4285.223,-2471.28,232.1287,0,0,0,0,100,0),
(@PATH,17,4277.473,-2472.28,231.8787,0,0,0,0,100,0),
(@PATH,18,4273.628,-2472.75,231.6418,0,0,0,0,100,0),
(@PATH,19,4267.374,-2468.811,231.65,0,0,0,0,100,0),
(@PATH,20,4263.313,-2458.705,231.5937,0,0,0,0,100,0),
(@PATH,21,4260.986,-2447.287,231.4928,0,0,0,0,100,0),
(@PATH,22,4258.986,-2445.537,231.4928,0,0,0,0,100,0),
(@PATH,23,4257.986,-2444.537,231.4928,0,0,0,0,100,0),
(@PATH,24,4257.986,-2443.787,231.4928,0,0,0,0,100,0),
(@PATH,25,4257.486,-2441.787,231.4928,0,0,0,0,100,0),
(@PATH,26,4257.564,-2441.543,231.4707,0,0,0,0,100,0),
(@PATH,27,4258.564,-2443.043,231.4707,0,0,0,0,100,0),
(@PATH,28,4258.814,-2444.543,231.4707,0,0,0,0,100,0),
(@PATH,29,4258.814,-2445.543,231.4707,0,0,0,0,100,0),
(@PATH,30,4259.061,-2445.944,231.3457,0,0,0,0,100,0),
(@PATH,31,4261.061,-2447.694,231.3457,0,0,0,0,100,0),
(@PATH,32,4263.474,-2458.961,231.6339,0,0,0,0,100,0),
(@PATH,33,4267.657,-2468.89,231.6431,0,0,0,0,100,0),
(@PATH,34,4273.792,-2472.652,231.7187,0,0,0,0,100,0),
(@PATH,35,4284.542,-2471.152,232.2187,0,0,0,0,100,0),
(@PATH,36,4284.735,-2471.201,232.4085,0,0,0,0,100,0),
(@PATH,37,4285.485,-2471.201,232.4085,0,0,0,0,100,0),
(@PATH,38,4289.235,-2470.701,233.1585,0,0,0,0,100,0),
(@PATH,39,4292.985,-2470.451,233.6585,0,0,0,0,100,0),
(@PATH,40,4296.985,-2469.951,234.4085,0,0,0,0,100,0),
(@PATH,41,4299.985,-2469.451,234.9085,0,0,0,0,100,0),
(@PATH,42,4303.572,-2469.107,235.8506,0,0,0,0,100,0),
(@PATH,43,4306.572,-2469.357,236.3506,0,0,0,0,100,0),
(@PATH,44,4311.322,-2469.857,237.1006,0,0,0,0,100,0),
(@PATH,45,4314.023,-2470.285,237.6709,0,0,0,0,100,0),
(@PATH,46,4318.273,-2476.535,238.1709,0,0,0,0,100,0),
(@PATH,47,4320.4,-2480.026,238.3305,0,0,0,0,100,0),
(@PATH,48,4316.393,-2488.953,238.7333,0,0,0,0,100,0),
(@PATH,49,4316.283,-2489.055,238.5876,0,0,0,0,100,0);

SET @NPC := 100910;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4338.308,`position_y`=-2566.474,`position_z`=245.7152 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4338.308,-2566.474,245.7152,0,0,0,0,100,0),
(@PATH,2,4339.808,-2567.724,245.7152,0,0,0,0,100,0),
(@PATH,3,4341.308,-2568.724,245.7152,0,0,0,0,100,0),
(@PATH,4,4342.308,-2569.724,245.7152,0,0,0,0,100,0),
(@PATH,5,4342.308,-2570.724,245.7152,0,0,0,0,100,0),
(@PATH,6,4345.808,-2573.724,245.7152,0,0,0,0,100,0),
(@PATH,7,4346.808,-2574.724,245.7152,0,0,0,0,100,0),
(@PATH,8,4345.922,-2575.817,245.7339,0,0,0,0,100,0),
(@PATH,9,4344.672,-2574.817,245.7339,0,0,0,0,100,0),
(@PATH,10,4342.422,-2570.817,245.7339,0,0,0,0,100,0),
(@PATH,11,4342.422,-2569.817,245.7339,0,0,0,0,100,0),
(@PATH,12,4341.422,-2568.817,245.7339,0,0,0,0,100,0),
(@PATH,13,4340.922,-2566.567,245.7339,0,0,0,0,100,0),
(@PATH,14,4340.74,-2566.308,245.6353,0,0,0,0,100,0),
(@PATH,15,4337.99,-2566.308,245.6353,0,0,0,0,100,0),
(@PATH,16,4326.376,-2555.018,245.3248,0,0,0,0,100,0),
(@PATH,17,4317.626,-2555.518,244.8248,0,0,0,0,100,0),
(@PATH,18,4313.838,-2555.828,244.4903,0,0,0,0,100,0),
(@PATH,19,4310.838,-2556.578,243.9903,0,0,0,0,100,0),
(@PATH,20,4308.088,-2557.078,243.4903,0,0,0,0,100,0),
(@PATH,21,4305.229,-2558.031,242.7213,0,0,0,0,100,0),
(@PATH,22,4304.324,-2561.028,243.1423,0,0,0,0,100,0),
(@PATH,23,4306.574,-2564.278,243.6423,0,0,0,0,100,0),
(@PATH,24,4309.324,-2568.528,244.1423,0,0,0,0,100,0),
(@PATH,25,4311.824,-2572.278,244.6423,0,0,0,0,100,0),
(@PATH,26,4314.824,-2576.528,245.3923,0,0,0,0,100,0),
(@PATH,27,4319.487,-2583.055,246.6341,0,0,0,0,100,0),
(@PATH,28,4322.487,-2587.055,247.1341,0,0,0,0,100,0),
(@PATH,29,4324.737,-2590.055,247.6341,0,0,0,0,100,0),
(@PATH,30,4327.237,-2593.055,248.1341,0,0,0,0,100,0),
(@PATH,31,4328.737,-2595.055,248.6341,0,0,0,0,100,0),
(@PATH,32,4304.205,-2560.936,242.7079,0,0,0,0,100,0),
(@PATH,33,4305.315,-2557.807,243.0027,0,0,0,0,100,0),
(@PATH,34,4308.065,-2557.307,243.5027,0,0,0,0,100,0),
(@PATH,35,4310.815,-2556.557,244.0027,0,0,0,0,100,0),
(@PATH,36,4314.014,-2555.685,244.613,0,0,0,0,100,0),
(@PATH,37,4320.764,-2555.435,245.113,0,0,0,0,100,0),
(@PATH,38,4326.62,-2555.132,245.2907,0,0,0,0,100,0),
(@PATH,39,4338.271,-2566.441,245.7103,0,0,0,0,100,0);

SET @NPC := 100930;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4243.639,`position_y`=-2493.448,`position_z`=231.605 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4243.639,-2493.448,231.605,0,0,0,0,100,0),
(@PATH,2,4245.705,-2503.654,231.4428,0,0,0,0,100,0),
(@PATH,3,4239.67,-2514.717,231.6307,0,0,0,0,100,0),
(@PATH,4,4239.557,-2514.651,231.5394,0,0,0,0,100,0),
(@PATH,5,4239.811,-2514.36,231.6327,0,0,0,0,100,0),
(@PATH,6,4245.605,-2503.552,231.3878,0,0,0,0,100,0),
(@PATH,7,4243.532,-2493.164,231.6278,0,0,0,0,100,0),
(@PATH,8,4237.666,-2485.062,231.6341,0,0,0,0,100,0);

SET @NPC := 98081;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3677.196,`position_y`=-3262.262,`position_z`=271.4974 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3677.196,-3262.262,271.4974,0,0,0,0,100,0),
(@PATH,2,3675.946,-3263.512,270.4974,0,0,0,0,100,0),
(@PATH,3,3673.446,-3266.012,267.7474,0,0,0,0,100,0),
(@PATH,4,3672.196,-3267.262,266.4974,0,0,0,0,100,0),
(@PATH,5,3670.696,-3268.762,264.4974,0,0,0,0,100,0),
(@PATH,6,3669.344,-3269.899,262.9258,0,0,0,0,100,0),
(@PATH,7,3665.594,-3268.399,259.1758,0,0,0,0,100,0),
(@PATH,8,3664.594,-3267.899,258.1758,0,0,0,0,100,0),
(@PATH,9,3657.594,-3265.399,252.4258,0,0,0,0,100,0),
(@PATH,10,3656.094,-3264.742,251.3945,0,0,0,0,100,0),
(@PATH,11,3648.844,-3264.492,245.1445,0,0,0,0,100,0),
(@PATH,12,3647.094,-3264.242,243.6445,0,0,0,0,100,0),
(@PATH,13,3642.363,-3263.935,240.8384,0,0,0,0,100,0),
(@PATH,14,3642.113,-3265.185,239.8384,0,0,0,0,100,0),
(@PATH,15,3640.613,-3270.685,237.3384,0,0,0,0,100,0),
(@PATH,16,3638.873,-3276.277,236.2841,0,0,0,0,100,0),
(@PATH,17,3637.873,-3283.027,235.7841,0,0,0,0,100,0),
(@PATH,18,3637.623,-3284.527,235.5341,0,0,0,0,100,0),
(@PATH,19,3637.542,-3284.433,235.5938,0,0,0,0,100,0),
(@PATH,20,3637.792,-3282.933,235.5938,0,0,0,0,100,0),
(@PATH,21,3639.209,-3276.042,236.5234,0,0,0,0,100,0),
(@PATH,22,3640.459,-3271.292,237.2734,0,0,0,0,100,0),
(@PATH,23,3641.709,-3265.792,239.5234,0,0,0,0,100,0),
(@PATH,24,3642.543,-3264.088,240.9962,0,0,0,0,100,0),
(@PATH,25,3646.543,-3264.338,243.2462,0,0,0,0,100,0),
(@PATH,26,3649.043,-3264.588,245.2462,0,0,0,0,100,0),
(@PATH,27,3656.203,-3264.957,251.5793,0,0,0,0,100,0),
(@PATH,28,3657.703,-3265.457,252.5793,0,0,0,0,100,0),
(@PATH,29,3664.453,-3267.957,258.0793,0,0,0,0,100,0),
(@PATH,30,3665.453,-3268.457,259.0793,0,0,0,0,100,0),
(@PATH,31,3669.533,-3269.755,263.1148,0,0,0,0,100,0),
(@PATH,32,3670.783,-3268.755,264.6148,0,0,0,0,100,0),
(@PATH,33,3672.283,-3267.255,266.1148,0,0,0,0,100,0),
(@PATH,34,3673.033,-3266.005,267.8648,0,0,0,0,100,0),
(@PATH,35,3675.783,-3263.505,270.3648,0,0,0,0,100,0),
(@PATH,36,3676.181,-3263.232,270.6315,0,0,0,0,100,0),
(@PATH,37,3677.431,-3261.982,271.8815,0,0,0,0,100,0),
(@PATH,38,3679.931,-3259.982,274.1315,0,0,0,0,100,0),
(@PATH,39,3683.181,-3256.982,276.8815,0,0,0,0,100,0),
(@PATH,40,3683.275,-3257.129,276.9308,0,0,0,0,100,0),
(@PATH,41,3680.025,-3259.629,274.4308,0,0,0,0,100,0),
(@PATH,42,3677.151,-3262.089,271.6892,0,0,0,0,100,0);

SET @NPC := 98083;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3608.663,`position_y`=-3311.686,`position_z`=224.8323 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3608.663,-3311.686,224.8323,0,0,0,0,100,0),
(@PATH,2,3610.913,-3313.436,224.5823,0,0,0,0,100,0),
(@PATH,3,3612.413,-3314.436,224.5823,0,0,0,0,100,0),
(@PATH,4,3621.448,-3320.278,226.055,0,0,0,0,100,0),
(@PATH,5,3624.948,-3320.278,226.555,0,0,0,0,100,0),
(@PATH,6,3630.948,-3320.278,227.055,0,0,0,0,100,0),
(@PATH,7,3632.198,-3320.278,227.555,0,0,0,0,100,0),
(@PATH,8,3631.236,-3320.25,227.2929,0,0,0,0,100,0),
(@PATH,9,3632.486,-3320.25,227.7929,0,0,0,0,100,0),
(@PATH,10,3633.486,-3320.25,228.2929,0,0,0,0,100,0),
(@PATH,11,3637.236,-3317,229.5429,0,0,0,0,100,0),
(@PATH,12,3637.84,-3316.242,229.9589,0,0,0,0,100,0),
(@PATH,13,3633.259,-3320.148,227.9277,0,0,0,0,100,0),
(@PATH,14,3632.259,-3320.148,227.4277,0,0,0,0,100,0),
(@PATH,15,3631.009,-3320.148,227.1777,0,0,0,0,100,0),
(@PATH,16,3624.759,-3320.398,226.4277,0,0,0,0,100,0),
(@PATH,17,3621.314,-3320.251,225.9905,0,0,0,0,100,0),
(@PATH,18,3613.064,-3315.001,224.7405,0,0,0,0,100,0),
(@PATH,19,3611.064,-3313.501,224.7405,0,0,0,0,100,0),
(@PATH,20,3608.404,-3311.755,224.6184,0,0,0,0,100,0),
(@PATH,21,3605.154,-3300.005,224.3684,0,0,0,0,100,0);

-- drakkari event
DELETE FROM `creature` where `id` IN (26582, 26583) and `guid` NOT IN (116602);

-- Horrified Drakkari Shaman SAI
SET @GUID := -116602;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26583;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,2000,1000,2000,88,11660200,11660201,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - Out of Combat - Run Random Script"),
(@GUID,0,1,2,63,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Reset - Set Active On"),
(@GUID,0,2,3,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Reset - Set Visibility On"),
(@GUID,0,3,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Reset - Set Reactstate Aggressive");

-- Actionlist SAI
SET @ENTRY := 11660200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,26583,3,120000,0,0,0,8,0,0,0,4690.051270,-2045.848755,194.348404,3.160445,"On Script - Summon Creature 'Horrified Drakkari Shaman'");

-- Actionlist SAI
SET @ENTRY := 11660201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,26582,3,120000,0,0,0,8,0,0,0,4690.051270,-2045.848755,194.348404,3.160445,"On Script - Summon Creature 'Horrified Drakkari Warrior'");

-- Horrified Drakkari Shaman SAI
SET @ENTRY := 26582;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,63,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Warrior - On Just Created - Set Active On"),
(@ENTRY,0,1,2,61,0,100,0,1,0,0,0,88,2658200,2658201,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Warrior - On Data Set 1 0 - Run Random Script"),
(@ENTRY,0,2,0,61,0,100,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Warrior - On Just Created - Say Line 0"),
(@ENTRY,0,3,0,40,0,100,0,20,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Warrior - On Waypoint 20 Reached - Despawn Instant");

-- Horrified Drakkari Shaman SAI
SET @ENTRY := 26583;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,63,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Just Created - Set Active On"),
(@ENTRY,0,1,2,61,0,100,0,1,0,0,0,88,2658200,2658201,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Just Created - Run Random Script"),
(@ENTRY,0,2,0,61,0,100,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Just Created - Say Line 0"),
(@ENTRY,0,3,0,40,0,100,0,20,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Waypoint 20 Reached - Despawn Instant");

-- Actionlist SAI
SET @ENTRY := 2658200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,53,1,2658200,0,0,3000,0,0,0,0,0,0,0,0,0,"On Script - Start Waypoint");

-- Actionlist SAI
SET @ENTRY := 2658201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,53,1,2658201,0,0,3000,0,0,0,0,0,0,0,0,0,"On Script - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry`=2658200;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(2658200, 1, 4680.19, -2044.68, 189.441),
(2658200, 2, 4662.73, -2045.93, 184.189),
(2658200, 3, 4651.83, -2051.77, 184.368),
(2658200, 4, 4643.71, -2060.59, 184.18),
(2658200, 5, 4635.04, -2061.83, 184.1),
(2658200, 6, 4617.55, -2061.84, 184.182),
(2658200, 7, 4596.55, -2061.57, 184.186),
(2658200, 8, 4579.06, -2061.36, 184.186),
(2658200, 9, 4562.37, -2062.32, 184.167),
(2658200, 10, 4551.87, -2062.12, 178.315),
(2658200, 11, 4534.37, -2062.09, 168.354),
(2658200, 12, 4523.88, -2061.96, 162.377),
(2658200, 13, 4509.88, -2062.05, 160.823),
(2658200, 14, 4498.51, -2063.27, 160.823),
(2658200, 15, 4490.23, -2069.98, 160.823),
(2658200, 16, 4492.74, -2078.85, 160.823),
(2658200, 17, 4496.31, -2094.72, 160.8),
(2658200, 18, 4506.59, -2103.06, 160.831),
(2658200, 19, 4518.52, -2110.39, 160.833),
(2658200, 20, 4533.43, -2119.56, 160.845),
(2658200, 21, 4545.35, -2130.19, 160.842);

DELETE FROM `waypoints` WHERE `entry`=2658201;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(2658201, 1, 4692.36, -2045.14, 195.516),
(2658201, 2, 4674.86, -2044.91, 186.46),
(2658201, 3, 4671.36, -2044.89, 185.043),
(2658201, 4, 4659.89, -2044.58, 184.318),
(2658201, 5, 4648.06, -2033.35, 184.184),
(2658201, 6, 4641.49, -2028.73, 183.862),
(2658201, 7, 4630.25, -2028.22, 184.182),
(2658201, 8, 4612.76, -2028.2, 184.185),
(2658201, 9, 4591.76, -2027.91, 184.189),
(2658201, 10, 4574.26, -2027.67, 184.185),
(2658201, 11, 4563.76, -2027.47, 184.166),
(2658201, 12, 4556.77, -2027.4, 180.928),
(2658201, 13, 4539.27, -2027.25, 170.966),
(2658201, 14, 4525.27, -2027.07, 162.997),
(2658201, 15, 4511.28, -2026.61, 160.823),
(2658201, 16, 4494.03, -2024.8, 160.824),
(2658201, 17, 4488.19, -2012.02, 161.055),
(2658201, 18, 4492.56, -1993.64, 160.824),
(2658201, 19, 4503.51, -1980.34, 160.824),
(2658201, 20, 4517.17, -1973.46, 160.824);

DELETE FROM `creature_text` WHERE `entry` IN (26583, 26582);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(26583, 0, 0, 'Drak\'Tharon be lost, mon!', 12, 0, 100, 0, 0, 0, 25857, 0, 'Horrified Drakkari'),
(26583, 0, 1, 'Da Scourge be everywhere, mon!', 12, 0, 100, 0, 0, 0, 25853, 0, 'Horrified Drakkari'),
(26583, 0, 2, 'Every troll for himself, mon!', 12, 0, 100, 0, 0, 0, 25855, 0, 'Horrified Drakkari'),
(26583, 0, 3, 'Ruuun!', 12, 0, 100, 0, 0, 0, 25859, 0, 'Horrified Drakkari'),
-- 
(26582, 0, 0, 'Drak\'Tharon be lost, mon!', 12, 0, 100, 0, 0, 0, 25857, 0, 'Horrified Drakkari'),
(26582, 0, 1, 'Da Scourge be everywhere, mon!', 12, 0, 100, 0, 0, 0, 25853, 0, 'Horrified Drakkari'),
(26582, 0, 2, 'Every troll for himself, mon!', 12, 0, 100, 0, 0, 0, 25855, 0, 'Horrified Drakkari'),
(26582, 0, 3, 'Ruuun!', 12, 0, 100, 0, 0, 0, 25859, 0, 'Horrified Drakkari');
-- DB/Creature: Grizzlyhills Pathing -2
UPDATE `smart_scripts` SET `action_param6`=2 WHERE  `entryorguid` IN (2658200, 2658201) AND `source_type`=9 AND `id`=0 AND `link`=0;

SET @NPC := 99310;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4194.24,`position_y`=-1806.269,`position_z`=200.4735 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4194.24,-1806.269,200.4735,0,0,0,0,100,0),
(@PATH,2,4197.74,-1808.269,201.2235,0,0,0,0,100,0),
(@PATH,3,4199.49,-1809.269,201.7235,0,0,0,0,100,0),
(@PATH,4,4202.99,-1811.269,202.2235,0,0,0,0,100,0),
(@PATH,5,4209.49,-1815.269,202.9735,0,0,0,0,100,0),
(@PATH,6,4226.4,-1825.46,203.2541,0,0,0,0,100,0),
(@PATH,7,4227.65,-1833.96,202.7541,0,0,0,0,100,0),
(@PATH,8,4228.602,-1839.474,202.2388,0,0,0,0,100,0),
(@PATH,9,4242.543,-1857.213,202.6918,0,0,0,0,100,0),
(@PATH,10,4242.543,-1863.963,203.1918,0,0,0,0,100,0),
(@PATH,11,4242.595,-1859.661,202.7076,0,0,0,0,100,0),
(@PATH,12,4242.467,-1856.869,202.4443,0,0,0,0,100,0),
(@PATH,13,4238.217,-1851.369,201.9443,0,0,0,0,100,0),
(@PATH,14,4228.504,-1839.239,202.5002,0,0,0,0,100,0),
(@PATH,15,4227.504,-1832.739,203.0002,0,0,0,0,100,0),
(@PATH,16,4226.358,-1825.27,203.1885,0,0,0,0,100,0),
(@PATH,17,4208.108,-1814.52,202.6885,0,0,0,0,100,0),
(@PATH,18,4200.608,-1810.02,201.9385,0,0,0,0,100,0),
(@PATH,19,4198.108,-1808.52,201.1885,0,0,0,0,100,0),
(@PATH,20,4194.608,-1806.52,200.6885,0,0,0,0,100,0),
(@PATH,21,4190.358,-1803.77,199.9385,0,0,0,0,100,0);

SET @NPC := 99309;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4163.295,`position_y`=-1958.695,`position_z`=208.3958 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4163.295,-1958.695,208.3958,0,0,0,0,100,0),
(@PATH,2,4167.545,-1960.945,208.8958,0,0,0,0,100,0),
(@PATH,3,4189.578,-1972.83,209.2269,0,0,0,0,100,0),
(@PATH,4,4193.578,-1973.83,208.7269,0,0,0,0,100,0),
(@PATH,5,4189.997,-1972.962,209.24,0,0,0,0,100,0),
(@PATH,6,4164.317,-1959.296,208.4842,0,0,0,0,100,0),
(@PATH,7,4163.099,-1958.743,208.3662,0,0,0,0,100,0),
(@PATH,8,4157.599,-1963.243,209.1162,0,0,0,0,100,0),
(@PATH,9,4154.599,-1965.743,209.8662,0,0,0,0,100,0),
(@PATH,10,4151.599,-1968.243,210.3662,0,0,0,0,100,0),
(@PATH,11,4148.349,-1970.743,210.8662,0,0,0,0,100,0),
(@PATH,12,4143.349,-1974.993,211.3662,0,0,0,0,100,0),
(@PATH,13,4136.349,-1980.993,212.1162,0,0,0,0,100,0),
(@PATH,14,4134.099,-1982.743,212.6162,0,0,0,0,100,0),
(@PATH,15,4133.807,-1983.081,212.7842,0,0,0,0,100,0),
(@PATH,16,4137.057,-1980.331,212.0342,0,0,0,0,100,0),
(@PATH,17,4143.807,-1974.581,211.2842,0,0,0,0,100,0),
(@PATH,18,4149.057,-1970.331,210.5342,0,0,0,0,100,0),
(@PATH,19,4152.807,-1967.081,210.0342,0,0,0,0,100,0),
(@PATH,20,4155.057,-1965.331,209.5342,0,0,0,0,100,0),
(@PATH,21,4159.057,-1962.081,209.0342,0,0,0,0,100,0);

SET @NPC := 99308;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4257.948,`position_y`=-1914.651,`position_z`=201.9758 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4257.948,-1914.651,201.9758,0,0,0,0,100,0),
(@PATH,2,4257.902,-1914.741,202.4635,0,0,0,0,100,0),
(@PATH,3,4257.152,-1923.741,202.9635,0,0,0,0,100,0),
(@PATH,4,4256.652,-1929.491,203.4635,0,0,0,0,100,0),
(@PATH,5,4256.402,-1934.241,203.9635,0,0,0,0,100,0),
(@PATH,6,4255.238,-1946.397,204.331,0,0,0,0,100,0),
(@PATH,7,4252.988,-1961.897,204.831,0,0,0,0,100,0),
(@PATH,8,4252.238,-1966.897,205.331,0,0,0,0,100,0),
(@PATH,9,4252.688,-1964.002,204.8374,0,0,0,0,100,0),
(@PATH,10,4254.188,-1953.252,204.5874,0,0,0,0,100,0),
(@PATH,11,4255.508,-1946.051,204.2277,0,0,0,0,100,0),
(@PATH,12,4256.758,-1930.551,203.4777,0,0,0,0,100,0),
(@PATH,13,4257.008,-1925.551,202.9777,0,0,0,0,100,0),
(@PATH,14,4257.508,-1919.551,202.4777,0,0,0,0,100,0),
(@PATH,15,4257.833,-1914.49,202.1853,0,0,0,0,100,0);

SET @NPC := 104074;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4245.058,`position_y`=-2021.197,`position_z`=237.4276 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4245.058,-2021.197,237.4276,0,0,0,0,100,0),
(@PATH,2,4245.791,-2017.078,233.2036,0,0,0,0,100,0),
(@PATH,3,4246.791,-2007.328,223.2036,0,0,0,0,100,0),
(@PATH,4,4247.152,-2007.004,222.8537,0,0,0,0,100,0),
(@PATH,5,4247.402,-2005.004,220.8537,0,0,0,0,100,0),
(@PATH,6,4248.152,-1999.504,215.8537,0,0,0,0,100,0),
(@PATH,7,4249.402,-1990.004,207.3537,0,0,0,0,100,0),
(@PATH,8,4249.673,-1989.776,207.2351,0,0,0,0,100,0),
(@PATH,9,4249.673,-1988.776,207.2351,0,0,0,0,100,0),
(@PATH,10,4250.423,-1976.026,206.7351,0,0,0,0,100,0),
(@PATH,11,4250.069,-1981.066,206.8915,0,0,0,0,100,0),
(@PATH,12,4248.495,-1989.926,206.7487,0,0,0,0,100,0),
(@PATH,13,4247.745,-1999.926,215.9987,0,0,0,0,100,0),
(@PATH,14,4247.169,-2005.335,221.2139,0,0,0,0,100,0),
(@PATH,15,4246.919,-2007.335,223.2139,0,0,0,0,100,0),
(@PATH,16,4245.507,-2017.251,233.4465,0,0,0,0,100,0);

DELETE FROM `creature_addon` WHERE `guid`=110106;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(110106,0,0,0,1,69, '');

SET @NPC := 10299;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3333.925,`position_y`=-1773.206,`position_z`=88.87373 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3333.925,-1773.206,88.87373,0,0,0,0,100,0),
(@PATH,2,3334.675,-1774.456,88.37373,0,0,0,0,100,0),
(@PATH,3,3335.175,-1775.456,88.37373,0,0,0,0,100,0),
(@PATH,4,3337.425,-1775.956,88.62373,0,0,0,0,100,0),
(@PATH,5,3338.675,-1779.706,89.12373,0,0,0,0,100,0),
(@PATH,6,3339.705,-1778.929,89.08168,0,0,0,0,100,0),
(@PATH,7,3339.705,-1775.929,88.58168,0,0,0,0,100,0),
(@PATH,8,3339.705,-1774.679,88.33168,0,0,0,0,100,0),
(@PATH,9,3339.705,-1771.679,87.83168,0,0,0,0,100,0),
(@PATH,10,3339.705,-1770.929,87.58168,0,0,0,0,100,0),
(@PATH,11,3339.705,-1766.679,87.33168,0,0,0,0,100,0),
(@PATH,12,3341.205,-1761.679,88.08168,0,0,0,0,100,0),
(@PATH,13,3340.286,-1761.39,87.88223,0,0,0,0,100,0),
(@PATH,14,3357.286,-1763.39,89.13223,0,0,0,0,100,0),
(@PATH,15,3358.286,-1763.39,89.38223,0,0,0,0,100,0),
(@PATH,16,3358.156,-1762.816,89.31908,0,0,0,0,100,0),
(@PATH,17,3357.656,-1762.816,89.06908,0,0,0,0,100,0),
(@PATH,18,3357.156,-1762.816,89.31908,0,0,0,0,100,0),
(@PATH,19,3340.241,-1761.592,87.80875,0,0,0,0,100,0),
(@PATH,20,3339.741,-1764.592,87.55875,0,0,0,0,100,0),
(@PATH,21,3339.741,-1766.592,87.30875,0,0,0,0,100,0),
(@PATH,22,3339.741,-1770.842,87.55875,0,0,0,0,100,0),
(@PATH,23,3339.741,-1774.592,88.30875,0,0,0,0,100,0),
(@PATH,24,3339.741,-1778.842,89.05875,0,0,0,0,100,0),
(@PATH,25,3335.925,-1777.206,88.87373,0,0,0,0,100,0),
(@PATH,26,3334.675,-1775.206,88.37373,0,0,0,0,100,0);

SET @NPC := 103003;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3392.038,`position_y`=-1786.48,`position_z`=99.89154 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3392.038,-1786.48,99.89154,0,0,0,0,100,0),
(@PATH,2,3393.788,-1785.98,99.64154,0,0,0,0,100,0),
(@PATH,3,3395.788,-1784.48,99.64154,0,0,0,0,100,0),
(@PATH,4,3398.038,-1784.48,99.64154,0,0,0,0,100,0),
(@PATH,5,3400.038,-1783.73,99.39154,0,0,0,0,100,0),
(@PATH,6,3408.288,-1780.23,99.14154,0,0,0,0,100,0),
(@PATH,7,3410.538,-1780.23,99.14154,0,0,0,0,100,0),
(@PATH,8,3412.538,-1780.23,99.39154,0,0,0,0,100,0),
(@PATH,9,3414.538,-1780.23,99.39154,0,0,0,0,100,0),
(@PATH,10,3416.788,-1780.23,99.64154,0,0,0,0,100,0),
(@PATH,11,3418.788,-1780.23,99.64154,0,0,0,0,100,0),
(@PATH,12,3418.788,-1782.48,100.8915,0,0,0,0,100,0),
(@PATH,13,3418.288,-1782.98,101.1415,0,0,0,0,100,0),
(@PATH,14,3418.538,-1786.48,102.1415,0,0,0,0,100,0),
(@PATH,15,3418.788,-1788.48,102.1415,0,0,0,0,100,0),
(@PATH,16,3418.788,-1790.23,102.6415,0,0,0,0,100,0),
(@PATH,17,3417.788,-1790.73,103.1415,0,0,0,0,100,0),
(@PATH,18,3412.288,-1793.98,103.1415,0,0,0,0,100,0),
(@PATH,19,3409.038,-1795.23,103.1415,0,0,0,0,100,0),
(@PATH,20,3402.038,-1798.23,103.1415,0,0,0,0,100,0),
(@PATH,21,3405.601,-1802.971,103.1744,0,0,0,0,100,0),
(@PATH,22,3412.601,-1804.221,103.1744,0,0,0,0,100,0),
(@PATH,23,3414.101,-1804.471,102.1744,0,0,0,0,100,0),
(@PATH,24,3414.601,-1803.471,102.1744,0,0,0,0,100,0),
(@PATH,25,3415.601,-1801.721,101.9244,0,0,0,0,100,0),
(@PATH,26,3415.601,-1799.721,101.9244,0,0,0,0,100,0),
(@PATH,27,3416.601,-1798.721,101.6744,0,0,0,0,100,0),
(@PATH,28,3420.351,-1795.471,101.4244,0,0,0,0,100,0),
(@PATH,29,3422.351,-1791.721,101.1744,0,0,0,0,100,0),
(@PATH,30,3423.851,-1789.471,101.1744,0,0,0,0,100,0),
(@PATH,31,3423.851,-1787.471,100.6744,0,0,0,0,100,0),
(@PATH,32,3423.851,-1785.471,100.4244,0,0,0,0,100,0),
(@PATH,33,3423.851,-1783.221,99.92442,0,0,0,0,100,0),
(@PATH,34,3422.851,-1781.721,99.42442,0,0,0,0,100,0),
(@PATH,35,3421.851,-1781.721,99.42442,0,0,0,0,100,0),
(@PATH,36,3420.851,-1781.721,99.67442,0,0,0,0,100,0),
(@PATH,37,3418.851,-1780.221,99.67442,0,0,0,0,100,0),
(@PATH,38,3416.601,-1780.221,99.67442,0,0,0,0,100,0),
(@PATH,39,3414.601,-1780.221,99.42442,0,0,0,0,100,0),
(@PATH,40,3412.601,-1780.221,99.42442,0,0,0,0,100,0),
(@PATH,41,3410.351,-1780.221,99.17442,0,0,0,0,100,0),
(@PATH,42,3408.351,-1780.221,99.17442,0,0,0,0,100,0),
(@PATH,43,3404.601,-1783.221,99.92442,0,0,0,0,100,0),
(@PATH,44,3403.101,-1783.971,99.67442,0,0,0,0,100,0),
(@PATH,45,3402.101,-1783.971,99.42442,0,0,0,0,100,0),
(@PATH,46,3401.101,-1783.971,99.42442,0,0,0,0,100,0),
(@PATH,47,3400.101,-1783.971,99.42442,0,0,0,0,100,0),
(@PATH,48,3397.851,-1784.471,99.67442,0,0,0,0,100,0),
(@PATH,49,3395.851,-1784.471,99.67442,0,0,0,0,100,0),
(@PATH,50,3393.851,-1784.471,99.42442,0,0,0,0,100,0);

SET @NPC := 103000;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3389.137,`position_y`=-1830.333,`position_z`=103.4552 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3389.137,-1830.333,103.4552,0,0,0,0,100,0),
(@PATH,2,3389.637,-1832.583,102.9552,0,0,0,0,100,0),
(@PATH,3,3383.887,-1839.083,102.9552,0,0,0,0,100,0),
(@PATH,4,3382.887,-1840.083,102.4552,0,0,0,0,100,0),
(@PATH,5,3382.387,-1840.583,102.7052,0,0,0,0,100,0),
(@PATH,6,3382.387,-1841.583,102.7052,0,0,0,0,100,0),
(@PATH,7,3378.887,-1844.833,103.4552,0,0,0,0,100,0),
(@PATH,8,3376.137,-1847.833,103.9552,0,0,0,0,100,0),
(@PATH,9,3375.137,-1848.833,104.2052,0,0,0,0,100,0),
(@PATH,10,3374.137,-1849.833,104.2052,0,0,0,0,100,0),
(@PATH,11,3372.387,-1852.083,104.7052,0,0,0,0,100,0),
(@PATH,12,3372.262,-1852.324,105.0966,0,0,0,0,100,0),
(@PATH,13,3371.512,-1853.574,105.3466,0,0,0,0,100,0),
(@PATH,14,3393.262,-1859.574,105.8466,0,0,0,0,100,0),
(@PATH,15,3397.262,-1860.824,106.5966,0,0,0,0,100,0),
(@PATH,16,3399.262,-1861.324,106.8466,0,0,0,0,100,0),
(@PATH,17,3403.012,-1862.324,107.5966,0,0,0,0,100,0),
(@PATH,18,3406.762,-1863.574,108.5966,0,0,0,0,100,0),
(@PATH,19,3382.792,-1856.847,105.1871,0,0,0,0,100,0),
(@PATH,20,3392.687,-1859.487,105.7214,0,0,0,0,100,0),
(@PATH,21,3396.437,-1860.737,106.4714,0,0,0,0,100,0),
(@PATH,22,3399.187,-1861.237,107.2214,0,0,0,0,100,0),
(@PATH,23,3402.937,-1862.237,107.7214,0,0,0,0,100,0),
(@PATH,24,3406.937,-1863.487,108.7214,0,0,0,0,100,0),
(@PATH,25,3408.163,-1863.834,108.8378,0,0,0,0,100,0),
(@PATH,26,3406.163,-1863.334,108.0878,0,0,0,0,100,0),
(@PATH,27,3402.413,-1862.084,107.3378,0,0,0,0,100,0),
(@PATH,28,3398.663,-1861.084,106.8378,0,0,0,0,100,0),
(@PATH,29,3394.663,-1860.084,105.8378,0,0,0,0,100,0),
(@PATH,30,3388.163,-1858.334,105.0878,0,0,0,0,100,0),
(@PATH,31,3376.036,-1851.585,104.1596,0,0,0,0,100,0),
(@PATH,32,3377.786,-1847.835,103.6596,0,0,0,0,100,0),
(@PATH,33,3379.536,-1844.335,103.1596,0,0,0,0,100,0),
(@PATH,34,3381.036,-1841.085,102.6596,0,0,0,0,100,0),
(@PATH,35,3382.036,-1839.835,102.6596,0,0,0,0,100,0),
(@PATH,36,3383.036,-1839.085,102.9096,0,0,0,0,100,0),
(@PATH,37,3389.537,-1832.41,102.813,0,0,0,0,100,0),
(@PATH,38,3389.037,-1829.91,102.813,0,0,0,0,100,0),
(@PATH,39,3388.787,-1827.91,104.813,0,0,0,0,100,0),
(@PATH,40,3386.787,-1816.66,111.313,0,0,0,0,100,0),
(@PATH,41,3386.537,-1815.41,112.063,0,0,0,0,100,0),
(@PATH,42,3386.537,-1813.41,113.313,0,0,0,0,100,0),
(@PATH,43,3386.537,-1812.41,113.813,0,0,0,0,100,0),
(@PATH,44,3386.367,-1811.625,114.3062,0,0,0,0,100,0),
(@PATH,45,3386.617,-1813.375,113.3062,0,0,0,0,100,0),
(@PATH,46,3386.867,-1814.375,112.5562,0,0,0,0,100,0),
(@PATH,47,3387.117,-1816.875,111.3062,0,0,0,0,100,0),
(@PATH,48,3388.867,-1827.875,104.8062,0,0,0,0,100,0);

UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=26447 AND `source_type`=0 AND `id`=0 AND `link`=0;

SET @NPC := 102007;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4364.09,`position_y`=-3079.468,`position_z`=339.3658 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4364.09,-3079.468,339.3658,0,0,0,0,100,0),
(@PATH,2,4367.34,-3080.468,339.6158,0,0,0,0,100,0),
(@PATH,3,4367.589,-3080.702,339.5166,0,0,0,0,100,0),
(@PATH,4,4363.933,-3079.255,339.4127,0,0,0,0,100,0),
(@PATH,5,4359.433,-3077.505,336.4127,0,0,0,0,100,0),
(@PATH,6,4355.786,-3075.964,334.2474,0,0,0,0,100,0),
(@PATH,7,4355.695,-3075.981,334.1053,0,0,0,0,100,0),
(@PATH,8,4356.195,-3076.231,334.3553,0,0,0,0,100,0),
(@PATH,9,4359.195,-3077.231,336.3553,0,0,0,0,100,0),
(@PATH,10,4364.154,-3079.562,339.3983,0,0,0,0,100,0),
(@PATH,11,4367.404,-3080.312,339.6483,0,0,0,0,100,0),
(@PATH,12,4367.589,-3080.702,339.5166,0,0,0,0,100,0),
(@PATH,13,4363.904,-3079.155,339.4361,0,0,0,0,100,0),
(@PATH,14,4359.404,-3077.405,336.4361,0,0,0,0,100,0);

DELETE FROM `creature_addon` WHERE `guid` IN (111265,111249,111251,111254,111253,111287,111250,111252,111256, 111257, 111255, 111258);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(111255,0,0,3,1,0, ''),
(111258,0,0,3,1,0, ''),
(111257,0,0,3,1,0, ''),
(111256,0,0,3,1,0, ''),
(111265,0,0,3,1,0, ''),
(111252,0,0,3,1,0, ''),
(111250,0,0,3,1,0, ''),
(111287,0,0,3,1,0, ''),
(111253,0,0,3,1,0, ''),
(111254,0,0,3,1,0, ''),
(111251,0,0,3,1,0, ''),
(111249,0,0,3,1,0, '');

SET @NPC := 111286;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4542.684,`position_y`=-3543.378,`position_z`=229.5949 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4542.684,-3543.378,229.5949,0,0,0,0,100,0),
(@PATH,2,4538.324,-3550.24,230.4706,0,0,0,0,100,0),
(@PATH,3,4538.574,-3554.24,230.9706,0,0,0,0,100,0),
(@PATH,4,4538.824,-3559.99,231.4706,0,0,0,0,100,0),
(@PATH,5,4538.906,-3559.937,231.3715,0,0,0,0,100,0),
(@PATH,6,4538.906,-3560.937,231.8715,0,0,0,0,100,0),
(@PATH,7,4558.198,-3552.972,231.0125,0,0,0,0,100,0),
(@PATH,8,4556.198,-3549.472,230.5125,0,0,0,0,100,0),
(@PATH,9,4553.948,-3546.472,229.7625,0,0,0,0,100,0),
(@PATH,10,4551.948,-3543.222,229.5125,0,0,0,0,100,0),
(@PATH,11,4542.659,-3543.267,229.5627,0,0,0,0,100,0);

SET @NPC := 111288;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4520.46,`position_y`=-3406.525,`position_z`=227.3326 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4520.46,-3406.525,227.3326,0,0,0,0,100,0),
(@PATH,2,4521.017,-3406.375,227.0677,0,0,0,0,100,0),
(@PATH,3,4520.318,-3406.741,227.3123,0,0,0,0,100,0),
(@PATH,4,4517.467,-3403.935,227.3069,0,0,0,0,100,0),
(@PATH,5,4526.76,-3393.349,227.3997,0,0,0,0,100,0),
(@PATH,6,4531.26,-3395.099,227.8997,0,0,0,0,100,0),
(@PATH,7,4531.282,-3395.075,227.8239,0,0,0,0,100,0),
(@PATH,8,4533.532,-3395.825,228.3239,0,0,0,0,100,0),
(@PATH,9,4532.032,-3397.075,228.0739,0,0,0,0,100,0),
(@PATH,10,4527.532,-3400.825,227.3239,0,0,0,0,100,0),
(@PATH,11,4520.34,-3406.549,227.3216,0,0,0,0,100,0),
(@PATH,12,4517.471,-3403.86,227.3069,0,0,0,0,100,0),
(@PATH,13,4526.883,-3393.393,227.3997,0,0,0,0,100,0),
(@PATH,14,4531.383,-3394.893,227.8997,0,0,0,0,100,0),
(@PATH,15,4531.462,-3395.123,227.7483,0,0,0,0,100,0),
(@PATH,16,4533.462,-3395.873,228.4983,0,0,0,0,100,0),
(@PATH,17,4531.962,-3397.123,227.9983,0,0,0,0,100,0),
(@PATH,18,4527.462,-3400.623,227.2483,0,0,0,0,100,0),
(@PATH,19,4520.34,-3406.627,227.3305,0,0,0,0,100,0),
(@PATH,20,4517.294,-3403.789,227.3069,0,0,0,0,100,0),
(@PATH,21,4526.909,-3393.429,227.3997,0,0,0,0,100,0),
(@PATH,22,4531.409,-3394.929,227.8997,0,0,0,0,100,0);

SET @NPC := 111289;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4484.351,`position_y`=-3478.285,`position_z`=227.3069 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4484.351,-3478.285,227.3069,0,0,0,0,100,0),
(@PATH,2,4480.057,-3487.22,227.2323,0,0,0,0,100,0),
(@PATH,3,4472.557,-3489.22,227.7323,0,0,0,0,100,0),
(@PATH,4,4472.306,-3489.237,227.8791,0,0,0,0,100,0),
(@PATH,5,4470.556,-3489.737,227.6291,0,0,0,0,100,0),
(@PATH,6,4462.207,-3481.591,227.8329,0,0,0,0,100,0),
(@PATH,7,4464.199,-3484.106,227.8086,0,0,0,0,100,0),
(@PATH,8,4476.075,-3486.219,227.4328,0,0,0,0,100,0),
(@PATH,9,4480.054,-3487.25,227.2926,0,0,0,0,100,0),
(@PATH,10,4472.554,-3489.25,227.7926,0,0,0,0,100,0),
(@PATH,11,4470.448,-3489.726,227.6761,0,0,0,0,100,0),
(@PATH,12,4461.976,-3481.571,227.8154,0,0,0,0,100,0),
(@PATH,13,4466.938,-3472.407,227.8242,0,0,0,0,100,0),
(@PATH,14,4479.269,-3468.501,227.1355,0,0,0,0,100,0),
(@PATH,15,4484.383,-3478.306,227.3069,0,0,0,0,100,0),
(@PATH,16,4479.968,-3487.13,227.2323,0,0,0,0,100,0),
(@PATH,17,4472.468,-3489.13,227.7323,0,0,0,0,100,0);

SET @NPC := 103184;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4462.269,`position_y`=-3450.493,`position_z`=229.296 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4462.269,-3450.493,229.296,0,0,0,0,100,0),
(@PATH,2,4459.769,-3447.243,230.296,0,0,0,0,100,0),
(@PATH,3,4458.269,-3445.243,231.046,0,0,0,0,100,0),
(@PATH,4,4457.019,-3443.493,231.796,0,0,0,0,100,0),
(@PATH,5,4455.269,-3441.243,232.546,0,0,0,0,100,0),
(@PATH,6,4453.519,-3438.743,233.046,0,0,0,0,100,0),
(@PATH,7,4452.269,-3437.243,233.796,0,0,0,0,100,0),
(@PATH,8,4452.268,-3436.947,233.8038,0,0,0,0,100,0),
(@PATH,9,4451.268,-3435.697,234.0538,0,0,0,0,100,0),
(@PATH,10,4456.768,-3431.197,233.5538,0,0,0,0,100,0),
(@PATH,11,4463.518,-3425.947,232.8038,0,0,0,0,100,0),
(@PATH,12,4466.768,-3423.447,232.3038,0,0,0,0,100,0),
(@PATH,13,4471.518,-3419.947,232.0538,0,0,0,0,100,0),
(@PATH,14,4467.077,-3423.216,232.6244,0,0,0,0,100,0),
(@PATH,15,4463.827,-3425.716,232.8744,0,0,0,0,100,0),
(@PATH,16,4458.577,-3429.716,233.6244,0,0,0,0,100,0),
(@PATH,17,4452.327,-3434.716,234.1244,0,0,0,0,100,0),
(@PATH,18,4452.155,-3435.054,234.091,0,0,0,0,100,0),
(@PATH,19,4451.155,-3435.804,234.091,0,0,0,0,100,0),
(@PATH,20,4452.905,-3438.304,233.341,0,0,0,0,100,0),
(@PATH,21,4454.905,-3440.554,232.841,0,0,0,0,100,0),
(@PATH,22,4455.905,-3442.304,232.091,0,0,0,0,100,0),
(@PATH,23,4457.155,-3443.804,231.591,0,0,0,0,100,0),
(@PATH,24,4458.905,-3446.054,230.841,0,0,0,0,100,0),
(@PATH,25,4460.655,-3448.304,229.841,0,0,0,0,100,0),
(@PATH,26,4462.905,-3451.554,229.091,0,0,0,0,100,0);

SET @NPC := 103186;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4494.403,`position_y`=-3398.471,`position_z`=228.9183 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4494.403,-3398.471,228.9183,0,0,0,0,100,0),
(@PATH,2,4497.653,-3396.221,229.6683,0,0,0,0,100,0),
(@PATH,3,4500.653,-3394.221,230.1683,0,0,0,0,100,0),
(@PATH,4,4509.161,-3388.243,230.0648,0,0,0,0,100,0),
(@PATH,5,4526.161,-3376.743,230.3148,0,0,0,0,100,0),
(@PATH,6,4529.797,-3374.429,230.5572,0,0,0,0,100,0),
(@PATH,7,4532.547,-3377.179,230.0572,0,0,0,0,100,0),
(@PATH,8,4531.893,-3376.673,230.1904,0,0,0,0,100,0),
(@PATH,9,4529.376,-3374.406,230.6659,0,0,0,0,100,0),
(@PATH,10,4525.376,-3377.156,230.1659,0,0,0,0,100,0),
(@PATH,11,4516.626,-3383.156,229.6659,0,0,0,0,100,0),
(@PATH,12,4508.783,-3388.445,229.8696,0,0,0,0,100,0),
(@PATH,13,4503.033,-3392.445,230.1196,0,0,0,0,100,0),
(@PATH,14,4497.533,-3396.195,229.6196,0,0,0,0,100,0),
(@PATH,15,4494.283,-3398.445,228.8696,0,0,0,0,100,0);

SET @NPC := 102291;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3636.139,`position_y`=-4596.764,`position_z`=191.9429 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3636.139,-4596.764,191.9429,0,0,0,0,100,0),
(@PATH,2,3635.861,-4596.798,191.7083,0,0,0,0,100,0),
(@PATH,3,3635.853,-4596.449,191.8018,0,0,0,0,100,0),
(@PATH,4,3625.146,-4589.744,191.7298,0,0,0,0,100,0),
(@PATH,5,3624.396,-4588.744,191.7298,0,0,0,0,100,0),
(@PATH,6,3623.646,-4587.744,191.9798,0,0,0,0,100,0),
(@PATH,7,3623.146,-4586.994,192.7298,0,0,0,0,100,0),
(@PATH,8,3622.646,-4586.244,193.2298,0,0,0,0,100,0),
(@PATH,9,3619.531,-4582.521,193.1351,0,0,0,0,100,0),
(@PATH,10,3608.531,-4574.021,193.6351,0,0,0,0,100,0),
(@PATH,11,3607.281,-4573.271,192.6351,0,0,0,0,100,0),
(@PATH,12,3606.781,-4572.771,192.6351,0,0,0,0,100,0),
(@PATH,13,3606.531,-4572.521,192.3851,0,0,0,0,100,0),
(@PATH,14,3606.273,-4572.244,192.437,0,0,0,0,100,0),
(@PATH,15,3604.773,-4570.994,192.687,0,0,0,0,100,0),
(@PATH,16,3603.523,-4569.494,193.187,0,0,0,0,100,0),
(@PATH,17,3602.023,-4566.994,194.187,0,0,0,0,100,0),
(@PATH,18,3600.023,-4563.744,194.687,0,0,0,0,100,0),
(@PATH,19,3597.773,-4560.494,195.437,0,0,0,0,100,0),
(@PATH,20,3596.023,-4557.994,196.187,0,0,0,0,100,0),
(@PATH,21,3593.575,-4554.499,197.0962,0,0,0,0,100,0),
(@PATH,22,3591.325,-4550.999,197.8462,0,0,0,0,100,0),
(@PATH,23,3589.575,-4547.999,198.3462,0,0,0,0,100,0),
(@PATH,24,3587.575,-4544.499,199.0962,0,0,0,0,100,0),
(@PATH,25,3587.266,-4544.312,199.2521,0,0,0,0,100,0),
(@PATH,26,3586.766,-4543.312,199.2521,0,0,0,0,100,0),
(@PATH,27,3583.266,-4534.312,199.7521,0,0,0,0,100,0),
(@PATH,28,3581.901,-4530.598,199.9242,0,0,0,0,100,0),
(@PATH,29,3577.257,-4510.44,199.8448,0,0,0,0,100,0),
(@PATH,30,3576.757,-4505.69,199.3448,0,0,0,0,100,0),
(@PATH,31,3576.196,-4499.946,199.2152,0,0,0,0,100,0),
(@PATH,32,3580.946,-4493.946,199.7152,0,0,0,0,100,0),
(@PATH,33,3581.288,-4493.67,199.6084,0,0,0,0,100,0),
(@PATH,34,3581.538,-4493.42,199.6084,0,0,0,0,100,0),
(@PATH,35,3586.788,-4484.17,199.1084,0,0,0,0,100,0),
(@PATH,36,3588.606,-4481.567,199.091,0,0,0,0,100,0),
(@PATH,37,3594.356,-4476.567,198.341,0,0,0,0,100,0),
(@PATH,38,3596.606,-4474.567,197.841,0,0,0,0,100,0),
(@PATH,39,3596,-4475.001,198.0385,0,0,0,0,100,0),
(@PATH,40,3593,-4477.751,198.5385,0,0,0,0,100,0),
(@PATH,41,3588.387,-4481.783,199.0264,0,0,0,0,100,0),
(@PATH,42,3582.387,-4491.783,199.5264,0,0,0,0,100,0),
(@PATH,43,3582.222,-4492.081,199.736,0,0,0,0,100,0),
(@PATH,44,3581.222,-4493.581,199.486,0,0,0,0,100,0),
(@PATH,45,3576.117,-4500.31,199.3681,0,0,0,0,100,0),
(@PATH,46,3577.448,-4510.77,199.8773,0,0,0,0,100,0),
(@PATH,47,3582.276,-4530.902,199.8257,0,0,0,0,100,0),
(@PATH,48,3585.526,-4540.152,199.3257,0,0,0,0,100,0),
(@PATH,49,3587.005,-4543.549,199.229,0,0,0,0,100,0),
(@PATH,50,3589.755,-4548.549,198.229,0,0,0,0,100,0),
(@PATH,51,3592.005,-4551.799,197.729,0,0,0,0,100,0),
(@PATH,52,3593.605,-4554.598,197.1403,0,0,0,0,100,0),
(@PATH,53,3595.355,-4557.098,196.3903,0,0,0,0,100,0),
(@PATH,54,3596.855,-4559.598,195.6403,0,0,0,0,100,0),
(@PATH,55,3598.355,-4562.098,195.1403,0,0,0,0,100,0),
(@PATH,56,3600.355,-4565.348,194.6403,0,0,0,0,100,0),
(@PATH,57,3602.105,-4567.848,193.8903,0,0,0,0,100,0),
(@PATH,58,3603.605,-4570.348,193.1403,0,0,0,0,100,0),
(@PATH,59,3604.866,-4572.453,192.3813,0,0,0,0,100,0),
(@PATH,60,3606.116,-4573.453,192.3813,0,0,0,0,100,0),
(@PATH,61,3606.366,-4573.703,192.8813,0,0,0,0,100,0),
(@PATH,62,3607.866,-4574.703,193.6313,0,0,0,0,100,0),
(@PATH,63,3619.845,-4582.56,193.2473,0,0,0,0,100,0),
(@PATH,64,3622.345,-4585.81,192.9973,0,0,0,0,100,0),
(@PATH,65,3623.095,-4586.81,192.7473,0,0,0,0,100,0),
(@PATH,66,3623.845,-4587.56,191.9973,0,0,0,0,100,0),
(@PATH,67,3624.595,-4588.81,191.7473,0,0,0,0,100,0),
(@PATH,68,3624.654,-4589.03,191.5894,0,0,0,0,100,0),
(@PATH,69,3625.404,-4589.78,191.5894,0,0,0,0,100,0),
(@PATH,70,3636.153,-4596.696,191.9285,0,0,0,0,100,0);
UPDATE `creature_text` SET `emote`=25 WHERE  `entry`=21797 AND `groupid`=0 AND `id`=0;
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128 WHERE  `entry`=21876;
UPDATE `creature_template` SET  `flags_extra`=128 WHERE  `entry`=21872;

UPDATE `creature_template` SET `spell1`=37729, `spell2`=37727, `spell3`=39658, `spell4`=37728 WHERE  `entry`=21867;

DELETE FROM `creature_text` WHERE `entry`in(21877,21872,21867);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(21877, 0, 0, 'Your pathetic attempt to escape will be short lived, Gorefiend. Let the $g boy:girl, go and submit! Even with your armor and weapons, you cannot defeat the ancients!', 12, 0, 100, 1, 0, 0, 19504, 0, 'Karsius the Ancient Watcher to Player'),
(21877, 1, 0, 'What ... have you done...', 14, 0, 100, 0, 0, 0, 19506, 0, 'Karsius the Ancient Watcher to Player'),
(21867, 0, 0, 'We will meet again... Someday.', 12, 0, 100, 273, 0, 0, 19508, 0, 'Teron Gorefiend'),
(21867, 1, 0, 'Death incarnate has been released upon the world once more! Teron Gorefiend has returned...', 14, 0, 100, 22, 0, 0, 19509, 0, 'Teron Gorefiend'),
(21872, 0, 0, 'Waste no time, fool! Use our power to kill those that stand in our way! Destroy Karsius before you are subdued!', 15, 0, 100, 1, 0, 0, 19503, 0, 'The Voice of Gorefiend');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(21797,21876,21877,21867);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN(21797,21876,21877,21867);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN(2179700,2179701);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21797, 0, 0, 1, 19, 0, 100, 0, 10645, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Quest \'Teron Gorefiend, I am...\' Taken - Store Targetlist'),
(21797, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2179700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Quest \'Teron Gorefiend, I am...\' Taken - Run Script'),
(21797, 0, 2, 3, 19, 0, 100, 0, 10639, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Quest \'Teron Gorefiend, I am...\' Taken - Store Targetlist'),
(21797, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2179700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Quest \'Teron Gorefiend, I am...\' Taken - Run Script'),
(21797, 0, 4, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 2179701, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Data Set - Run Script 2'),
(21797, 0, 5, 0, 40, 0, 100, 0, 3, 21867, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Reached WP7 - Despawn'),
(21797, 0, 6, 7, 6, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 21877, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Death - Set Data 2 2 on Karsius the Ancient Watcher'),
(21797, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 28, 37782, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - Just Died - Remove Aura Disembodied Spirit'),
(21797, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 37748, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - Just Died - Remove Aura Teron Gorefiend'),

(21876, 0, 0, 1, 11, 0, 100, 1, 0, 0, 0, 0, 11, 37761, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chain of Shadows - On Respawn - Cast \'Ancient Draenei Warden\''),
(21876, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chain of Shadows - On Respawn - Set Emote State 333'),
(21876, 0, 2, 0, 1, 0, 33, 0, 8000, 21000, 8000, 21000, 11, 37784, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chain of Shadows - OOC - Cast Enforced Submission'),
(21876, 0, 3, 0, 1, 0,100, 1, 0, 0, 0, 0, 11, 37784, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chain of Shadows - OOC - Cast Enforced Submission (No Repeat)'),
(21877, 0, 1, 0, 11, 0, 100, 1, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Respawn - Set Emote State 333'),
(21877, 0, 2, 0, 1, 0, 100, 0, 3000, 3000, 3000, 3000, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - OOC - Set Unit Flags'),
(21877, 0, 3, 4, 6, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 21876, 0, 200, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Death - Despawn Chain of Shadows'),
(21877, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 21867, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Death - Set Data'),
(21877, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Death - Despawn'),
(21877, 0, 6, 0, 1, 0, 100, 0, 3000, 3000, 3000, 3000, 19, 768, 0, 0, 0, 0, 0, 19, 21867, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - OOC - Set Unit Flags'),
(21877, 0, 7, 8, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 21876, 0, 200, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Evade Despawn'),
(21877, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 21797, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Despawn Ancient Shadowmoon Spirit'),
(21877, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 21867, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Despawn Ancient Shadowmoon Spirit'),
(21877, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Despawn Ancient Shadowmoon Spirit'),
(21877, 0, 11, 12, 6, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Just Died - Say Line 1'),
(21877, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 28, 37782, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Just Died - Remove Aura Disembodied Spirit'),
(21877, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 37748, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - Just Died - Remove Aura Teron Gorefiend'),
(21877, 0, 14, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karsius the Ancient Watcher - On Data Set 2 2 - Evade'),
(2179701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script 2 - Evade'), 
(2179701, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 43, 0, 10720, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script 2 - Mount'), 
(2179701, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script 2 - Say Line 0'), -- 13:51:07.500
(2179701, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script 2 - Say Line 1'), -- 13:51:10.750
(2179701, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 53, 1, 21867, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script 2 - Start WP'), 
(2179700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Say Line 0'), -- 13:49:05.750
(2179700, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 36, 21867, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Change Entry'), -- 13:49:09.266
(2179700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Set Unit Flags'), -- 13:49:09.266
(2179700, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Add Aura Disembodied Spirit'), -- 13:49:09.266
(2179700, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 75, 37782, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Invoker Cast - Teron Gorefiend'), -- 13:49:10.235
(2179700, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 37769, 2, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Invoker Cast - Teron Gorefiend'), -- 13:49:10.235
(2179700, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 37728, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Cast - Haste'), -- 13:49:10.235
(2179700, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4524.726, 1009.763, 21.32487, 2.024582, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4515.913, 1020.078, 23.67377, 2.722714, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4515.165, 1033.106, 20.71271, 3.176499, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4525, 1045.415, 19.89447, 4.153883, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4537.54, 1049.356, 18.74087, 4.415683, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4551.174, 1044.113, 16.52099, 5.218534, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4523.753, 1062.352, 24.30409, 4.433136, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4509.667, 1047.063, 26.45817, 3.787364, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21876, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4504.674, 1020.563, 33.07281, 2.932153, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Chain of Shadows\''), -- 13:49:12.782
(2179700, 9, 16, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 12, 21877, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4535.794, 1029.284, 8.836361, 3.787364, 'Ancient Shadowmoon Spirit - On Script - Summon Creature \'Karsius the Ancient Watcher\''), -- 13:49:12.782
(2179700, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21877, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Say Line 0 on \'Karsius the Ancient Watcher\''), -- 13:49:12.782
(2179700, 9, 18, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21872, 0, 0, 0, 0, 0, 0, 'Ancient Shadowmoon Spirit - On Script - Say Line 0 on The Voice of Gorefiend'); -- 13:49:21.016

DELETE FROM `conditions`  WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(37748,37784);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 37748, 0, 0, 31, 0, 3, 21867, 0, 0, 0, 0, '', 'Teron Gorefiend (effects 1 & 2) target teron gorefiend'),
(13, 6, 37748, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Teron Gorefiend (effect 2 & 3) targets player'),
(13, 1, 37784, 0, 0, 31, 0, 3, 21867, 0, 0, 0, 0, '', 'Enforced Submission Targets Teron Gorefiend'),
(13, 1, 37784, 0, 1, 31, 0, 3, 21797, 0, 0, 0, 0, '', 'Enforced Submission Targets Ancient Shadowmoon Spirit');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=37748;
UPDATE `quest_template_addon` SET `SourceSpellID`=0 WHERE  `ID` IN(10645,10639);

DELETE FROM `creature_template_addon` WHERE `entry` IN (21876,21877,21797,21867);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(21876, 0, 0x0, 0x1, '37761'), -- 21876 - 37761
(21877, 0, 0x0, 0x1, '37497'), -- 21877
(21797, 0, 0x0, 0x1, '37509'), -- 21797 - 37509
(21867, 0, 0x0, 0x1, '37509'); -- 21867 - 37509 10720

UPDATE `creature_template` SET `unit_flags`=768 WHERE  `entry`=21876;
UPDATE `creature_template` SET `faction`=1821, `unit_flags`=33536 WHERE  `entry`=21877;
UPDATE `creature_template` SET `faction`=35, `unit_flags`=768 WHERE  `entry`=21867;

DELETE FROM  `waypoints` WHERE `entry`=21867;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(21867, 1, -4519.978, 1004.27, 12.49499, 'Teron Gorefiend'),
(21867, 2, -4520.013, 995.0764, 11.57806, 'Teron Gorefiend'),
(21867, 3, -4518.75, 968.75, 12.04559, 'Teron Gorefiend'),
(21867, 4, -4512.086, 938.8976, 2.529049, 'Teron Gorefiend');
--
DELETE FROM `skill_fishing_base_level` WHERE `entry`=4722;
INSERT INTO `skill_fishing_base_level` (`entry`, `skill`) VALUES (4722,430);
--
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`="" WHERE `entry` IN (19991);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19991) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19991, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - On Death - Say text 1'),
(19991, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 4000, 5000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - IC - cast Cleave'),
(19991, 0, 2, 0, 0, 0, 100, 0, 5000, 10000, 8000, 12000, 11, 37577, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - IC - debilitating-strike'),
(19991, 0, 3, 0, 0, 0, 100, 1, 15000, 20000, 10000, 15000, 11, 34932, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - IC - Bloodmaul Buzz'),
(19991, 0, 4, 5, 2, 0, 100, 1, 0, 20, 1, 1, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - Heath pct - cast Enrage'),
(19991, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - Heath pct - say text 3');
--
-- Argent Champion SAI mechanic
SET @Arg_Champion := 33707;
SET @Script := 3370700;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN (@Arg_Champion, 33518);
UPDATE `creature_template_addon` SET  `auras`='63501 62852 64723' WHERE `entry`= @Arg_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Arg_Champion, 33518) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Script;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Arg_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - On Reset - Remove auras from Defend'),
(@Arg_Champion,0,1,0,63,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Just created - Call timed actionlist'),
(@Arg_Champion,0,2,0,52,0,100,0,0,@Arg_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'Arg Champion - On text over - Cast Charge'),
(@Arg_Champion,0,3,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'Arg Champion - IC - Cast Thrust'),
(@Arg_Champion,0,4,0,9,0,100,0,5,5,4000,7000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Arg Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@Arg_Champion,0,5,0,0,0,100,0,9000,11000,9000,10000,46,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - IC - Move forward 20 yards'),
(@Arg_Champion,0,6,7,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Arg Champion - On 10-12 yard range - Cast Charge'),
(@Arg_Champion,0,7,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Arg Champion - Linked with previous event - Cast Shield-Breaker'),
(@Arg_Champion,0,8,9,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - On HP% between 1% and 6% - Change faction to 35'),
(@Arg_Champion,0,9,10,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,33518,100,0,0,0,0,0,'Arg Champion - On HP% between 1% and 6% - set data'),
(@Arg_Champion,0,10,11,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,21,50,0,0,0,0,0,0,'Arg Champion - Linked with previous event - Say text'),
(@Arg_Champion,0,11,0,61,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Linked with previous event - Despawn in 3 sec'),
(@Arg_Champion,0,12,13,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,21,50,0,0,0,0,0,0,'Arg Champion - On player killed - Say text'),
(@Arg_Champion,0,13,0,61,0,100,0,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Linked with previous event - Despawn in 1 ms'),
-- Timed actionlist 1
(@Script,9,0,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Set run ON'),
(@Script,9,1,0,0,0,100,0,0,0,0,0,42,0,1,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Set INVINCIBILITY'),
(@Script,9,2,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Cast Defend on self/Layer 1/'),
(@Script,9,3,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Cast Defend on self/Layer 2/'),
(@Script,9,4,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Cast Defend on self/Layer 3/'),
(@Script,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,8562.076172, 1115.047119, 556.787231, 2.587977,'Arg Champion - Script 1 - Move to pos'), 
(@Script,9,6,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Set run Off'),
(@Script,9,7,0,0,0,100,0,0,0,0,0,11,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Cast aura TriggerS for Defend /10 sec one/'),
(@Script,9,8,0,0,0,100,0,3500,3500,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Change faction to 14'),
(@Script,9,9,0,0,0,100,0,0,0,0,0,1,0,1500,0,0,0,0,21,50,0,0,0,0,0,0,'Arg Champion - Script 1 - Say text'),
(33518, 0, 0, 1, 62, 0, 100, 0, 10343, 0, 0, 0, 11, 63171, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Squire Danny  -On gossip select, summons Argent Champion" ),
(33518, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Squire Danny - On gossip select - Close gossip" ),
(33518, 0, 2, 0, 61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Squire Danny  - Linked with previous event - store target'),
(33518, 0, 3, 0, 38,0,100,0,0,1,0,0,85,63516,0,0,0,0,0,12,1,0,0,0,0,0,0,'Squire Danny  - On data set - cast quest credit');

-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @Arg_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@Arg_Champion,0,1,'Ready yourself!',12,0,100,1,1000,0,'Argent Champion',33753),
(@Arg_Champion,0,2,'Prepare yourself!',12,0,100,1,1000,0,'Argent Champion',33750),
(@Arg_Champion,0,3,'On your guard!',12,0,100,1,1000,0,'Argent Champion',33752),
(@Arg_Champion,0,4,'On your guard!',12,0,100,1,1000,0,'Argent Champion',33756),
(@Arg_Champion,0,5,'Let it begin!',12,0,100,1,1000,0,'Argent Champion',33758),
(@Arg_Champion,0,6,'Argent Champion is looking winded!',12,0,100,1,1000,0,'Argent Champion',0),
(@Arg_Champion,1,7,'Victory is mine!',12,0,100,1,1000,0,'Argent Champion',33771),
(@Arg_Champion,1,8,'It seems you still need more practice. Perhaps another time.',12,0,100,1,1000,0,'Argent Champion',33763),
(@Arg_Champion,1,9,'I have won. Better luck another time, friend.',12,0,100,1,1000,0,'Argent Champion',33773),
(@Arg_Champion,1,10,'I am afraid you will need more practice to defeat me.',12,0,100,1,1000,0,'Argent Champion',33772),
(@Arg_Champion,2,11,'I yield to you.',12,0,100,1,1000,0,'Argent Champion',33767),
(@Arg_Champion,2,12,'That was a well fought battle. I yield to you.',12,0,100,1,1000,0,'Argent Champion',33776),
(@Arg_Champion,2,13,'It would seem I underestimated your skills. Well done..',12,0,100,1,1000,0,'Argent Champion',33768),
(@Arg_Champion,2,14,'I have been defeated. Good fight!',12,0,100,1,1000,0,'Argent Champion',33868);

DELETE FROM `spell_target_position` WHERE `id`=63137;
INSERT INTO `spell_target_position` (`id`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`) VALUES 
(63137, 0, 571, 8542.52, 1083.690, 556.406);
--
DELETE FROM `spell_group` WHERE `id`=1121;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1121,3671),
(1121,3672),
(1121,3673);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=1121;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1121,1);
--
UPDATE `gossip_menu_option` SET `action_menu_id`=943 WHERE `menu_id`=942 AND `id`=0;
UPDATE `gossip_menu_option` SET `action_menu_id`=944 WHERE `menu_id`=942 AND `id`=1;
DELETE FROM `gossip_menu` WHERE `entry` IN (944,943);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (943,1521),(944,1646);
--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (12222);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (12222) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(12222, 0, 0, 0, 0, 0, 100, 0, 4000, 6000, 7000, 10000, 11, 26419, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0,0,'Creeping Sludge - IC - Cast Acid Spray'),
(12222, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 75, 22638, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Creeping Sludge - On reset - Add Poison Shock');
--
UPDATE `smart_scripts` SET `event_type`=61, `event_param1`=0, `event_param2`=0, `event_param3`=0, `event_param4`=0, `action_param1`=10000 WHERE `entryorguid`=28156 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `link`=3 WHERE `entryorguid`=28156 AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid`=28156 AND `source_type`=0 AND `id`=0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=51276;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,51276,0,0,31,0,3,28156,0,0,0,0,'','Incinerate Corpse can be used only on Defeated Argent Footman.');
--
UPDATE `npc_text` SET `BroadcastTextId0`= 33761 WHERE `id`=14391;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=4007;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4007,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4007,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4007,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4007 AND `text_id` IN (4999, 5000);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4007, 4999), (4007, 5000);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=4007;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4007, 4999, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 4007, 5000, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1),
(15, 4007, 0, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4007, 1, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4007, 2, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4534;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4534,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4534,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4534,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4534 AND `text_id` IN (563, 562);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4534, 563), (4534, 562);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=4534;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4534, 562, 0, 15, 128, 0, 0, 0, '', 'Show gossip text if player is a Mage', 0),
(14, 4534, 563, 0, 15, 128, 0, 0, 0, '', 'Show gossip text if player is not a Mage', 1),
(15, 4534, 0, 0, 15, 128, 0, 0, 0, '', 'Show gossip option if player is a Mage', 0),
(15, 4534, 1, 0, 15, 128, 0, 0, 0, '', 'Show gossip option if player is a Mage', 0),
(15, 4534, 2, 0, 15, 128, 0, 0, 0, '', 'Show gossip option if player is a Mage', 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4092;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4092,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4092,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4092,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4092 AND `text_id` IN (4867, 4993);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4092, 4867), (4092, 4993);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4621;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4621,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4621,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4621,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4621 AND `text_id` IN (4994, 4993);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4621, 4994), (4621, 4993);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=4621;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4621, 4994, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 4621, 4993, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1),
(15, 4621, 0, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4621, 1, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4621, 2, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4694;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4694,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4694,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4694,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4694 AND `text_id` IN (6160, 4993);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4694, 6160), (4694, 4993);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=4694;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4694, 6160, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 4694, 4993, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1),
(15, 4694, 0, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4694, 1, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4694, 2, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4826;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4826,0,3,"I would like training.",5,16,0,0,0,0,'', 2603);
DELETE FROM `gossip_menu` WHERE `Entry`=4826 AND `text_id` IN (5884, 5883);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4826, 5884), (4826, 5883);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=4826;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4826, 5884, 0, 15, 128, 0, 0, 0, '', 'Show gossip text if player is a Mage', 0),
(14, 4826, 5883, 0, 15, 128, 0, 0, 0, '', 'Show gossip text if player is not a Mage', 1),
(15, 4826, 0, 0, 15, 128, 0, 0, 0, '', 'Show gossip option if player is a Mage', 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4674;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4674,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4674,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4674,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4674 AND `text_id` IN (4999, 5000);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4674, 4999), (4674, 5000);

UPDATE `creature_template` SET `gossip_menu_id`= 4007 WHERE `entry`=1231;
UPDATE `creature_template` SET `gossip_menu_id`= 4534 WHERE `entry`=3047;
UPDATE `creature_template` SET `gossip_menu_id`= 4092 WHERE `entry`=3963;
UPDATE `creature_template` SET `gossip_menu_id`= 4621 WHERE `entry`=4138;
UPDATE `creature_template` SET `gossip_menu_id`= 4694 WHERE `entry`=5501;
UPDATE `creature_template` SET `gossip_menu_id`= 4826 WHERE `entry`=5958;
UPDATE `creature_template` SET `gossip_menu_id`= 4092 WHERE `entry`=8308;
UPDATE `creature_template` SET `gossip_menu_id`= 4674 WHERE `entry`=10930;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` IN (4092, 4674);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4092, 4867, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 4092, 4993, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1),
(15, 4092, 0, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4092, 1, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4092, 2, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(14, 4674, 4999, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 4674, 5000, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1),
(15, 4674, 0, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4674, 1, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4674, 2, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0);
--
DELETE FROM `gossip_menu_option` WHERE `menu_id`=21221;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(21221,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(21221,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(21221,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762 );
DELETE FROM `gossip_menu` WHERE `Entry`=21221 AND `text_id`=4793;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (21221, 4793);
UPDATE `npc_text` SET `BroadcastTextId0`=3275 WHERE `id`=1124;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=21221;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14, 21221, 1124, 0, 15, 8, 0, 0, 0, '', 'Show gossip text if player is a Rogue'),
(14, 21221, 4793, 0, 15, 1527, 0, 0, 0, '', 'Show gossip text if player is not a Rogue'),
(15, 21221, 0, 0, 15, 8, 0, 0, 0, '', 'Show gossip option if player is a rogue'),
(15, 21221, 1, 0, 15, 8, 0, 0, 0, '', 'Show gossip option if player is a rogue'),
(15, 21221, 2, 0, 15, 8, 0, 0, 0, '', 'Show gossip option if player is a rogue');
--
DELETE FROM `pool_template` WHERE `entry` IN (11635, 11636, 11637, 11638);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(11635, 1, 'Defenders at Bloodmyst Isle 1'),
(11636, 1, 'Defenders at Bloodmyst Isle 2'),
(11637, 1, 'Defenders at Bloodmyst Isle 3'),
(11638, 1, 'Defenders at Bloodmyst Isle 4');

DELETE FROM `pool_creature` WHERE `pool_entry` IN (11635, 11636, 11637, 11638);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(63725, 11635, 0, 'Defenders at Bloodmyst Isle 1'),
(84397, 11635, 0, 'Defenders at Bloodmyst Isle 1'),
(63726, 11636, 0, 'Defenders at Bloodmyst Isle 2'),
(84395, 11636, 0, 'Defenders at Bloodmyst Isle 2'),
(63724, 11637, 0, 'Defenders at Bloodmyst Isle 3'),
(84396, 11637, 0, 'Defenders at Bloodmyst Isle 3'),
(63727, 11638, 0, 'Defenders at Bloodmyst Isle 4'),
(84428, 11638, 0, 'Defenders at Bloodmyst Isle 4');
--
SET @ENTRY := 18636;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,6,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Reset'),
(@ENTRY,0,1,0,9,0,100,6,0,8,0,0,11,30986,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cheap Shot on Close'),
(@ENTRY,0,2,0,67,0,100,6,9000,12000,0,0,11,30992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab'),
(@ENTRY,0,3,0,0,0,100,6,2000,4500,12000,20000,11,30981,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crippling Poison'),
(@ENTRY,0,4,0,0,0,100,6,8000,11000,22000,25000,11,36974,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wound Poison');

SET @ENTRY := 17695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,6,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Reset'),
(@ENTRY,0,1,0,9,0,100,6,0,8,0,0,11,30986,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cheap Shot on Close'),
(@ENTRY,0,2,0,67,0,100,6,9000,12000,0,0,11,30992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab'),
(@ENTRY,0,3,0,0,0,100,6,2000,4500,12000,20000,11,30981,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crippling Poison'),
(@ENTRY,0,4,0,0,0,100,6,8000,11000,22000,25000,11,36974,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wound Poison');

-- Void Traveler
SET @ENTRY := 19226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,20000,11,33783,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Empowering Shadows'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,12000,20000,11,39364,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Empowering Shadows'),
(@ENTRY,0,2,0,0,0,100,6,5000,9000,18000,25000,11,33846,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova');
--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (37748) AND `SourceGroup`=6;
