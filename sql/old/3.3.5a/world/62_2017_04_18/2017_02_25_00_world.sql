-- Quest: Thrusting Hodir's Spear - 13003
SET @ENTRY := 30275;
SET @PATH := @ENTRY * 10;

UPDATE `creature_template` SET `HoverHeight`=5.2, `unit_flags`=32768, `ScriptName`='npc_wild_wyrm' WHERE `entry`=@ENTRY;

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (56673,60863,60713,60810) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56673, 0, 0, 31, 0, 3, 30275, 0, 0, 0, 0, '', 'Spell Fight Wyrm (effect 0) will hit the potential target of the spell if target is unit Wild Wyrm.'),
(13, 1, 60863, 0, 0, 31, 0, 3, 30275, 0, 0, 0, 0, '', 'Spell Fight Wyrm (effect 0) will hit the potential target of the spell if target is unit Wild Wyrm.'),
(13, 1, 60713, 0, 0, 31, 0, 3, 30275, 0, 0, 0, 0, '', 'Spell Visual: Grab On (effect 0) will hit the potential target of the spell if target is unit Wild Wyrm.'),
(13, 1, 60810, 0, 0, 31, 0, 3, 30275, 0, 0, 0, 0, '', 'Spell Visual: Thrust Spear (effect 0) will hit the potential target of the spell if target is unit Wild Wyrm.');

-- Condition for source Spell condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=56671 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 56671, 0, 0, 31, 1, 3, 30275, 0, 0, 0, 0, '', 'Spell Spear of Hodir will hit the explicit target of the spell if target is unit Wild Wyrm.');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_eject_passenger_wild_wyrm','spell_grip','spell_grab_on','spell_thrust_spear','spell_mighty_spear_thrust','spell_low_health_trigger','spell_jaws_of_death_claw_swipe_pct_damage','spell_claw_swipe_check','spell_fatal_strike','spell_falling_dragon_feign_death','spell_player_mount_wyrm');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(60603, 'spell_eject_passenger_wild_wyrm'),
(56689, 'spell_grip'),
(60533, 'spell_grab_on'),
(56690, 'spell_thrust_spear'),
(60586, 'spell_mighty_spear_thrust'),
(60596, 'spell_low_health_trigger'),
(60864, 'spell_jaws_of_death_claw_swipe_pct_damage'),
(60776, 'spell_jaws_of_death_claw_swipe_pct_damage'),
(56705, 'spell_claw_swipe_check'),
(60587, 'spell_fatal_strike'),
(55795, 'spell_falling_dragon_feign_death'),
(56672, 'spell_player_mount_wyrm');

DELETE FROM `spell_custom_attr` WHERE `entry` IN (56690,60586,60776,60881,60864);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(56690, 0x8000),
(60586, 0x8000),
(60776, 0x8000),
(60881, 0x8000),
(60864, 0x8000);

DELETE FROM `creature_text` WHERE `entry` =@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@ENTRY, 0, 0, '%s swipes at you with his claws!', 42, 0, 100, 0, 0, 0, 'Wild Wyrm - SAY_SWIPE', 32763),
(@ENTRY, 1, 0, 'DODGED!', 42, 0, 100, 0, 0, 0, 'Wild Wyrm - SAY_DODGED', 32794),
(@ENTRY, 2, 0, '%s shrieks in pain and twists around, grabbing you with his mouth!', 42, 0, 100, 0, 0, 0, 'Wild Wyrm - SAY_PHASE_2', 32813),
(@ENTRY, 3, 0, 'Your Grip is Failing!', 42, 0, 100, 0, 0, 0, 'Wild Wyrm - SAY_GRIP_WARN', 32784),
(@ENTRY, 4, 0, 'FATAL STRIKE MISSED! KEEP PRYING!', 42, 0, 100, 0, 0, 0, 'Wild Wyrm - SAY_STRIKE_MISS', 32795);

-- Pathing for Wild Wyrm Entry: 30275 'TDB FORMAT' 
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7323.32,-2434.555,785.0732,0,0,0,0,100,0), -- 02:32:47
(@PATH,2,7323.309,-2434.542,785.0561,0,0,0,0,100,0), -- 02:32:47
(@PATH,3,7323.297,-2434.528,785.038,0,0,0,0,100,0), -- 02:32:47
(@PATH,4,7335.602,-2376.98,812.4385,0,0,0,0,100,0), -- 02:32:48
(@PATH,5,7325.237,-2359.835,825.4155,0,0,0,0,100,0), -- 02:32:51
(@PATH,6,7325.253,-2359.815,825.4035,0,0,0,0,100,0), -- 02:32:51
(@PATH,7,7238.397,-2307.871,926.4048,0,0,0,0,100,0), -- 02:32:52
(@PATH,8,7441.65,-1691.336,1315.965,0,0,0,0,100,0), -- 02:33:52
(@PATH,9,7441.65,-1691.336,1315.965,0,0,0,0,100,0), -- 02:33:56
(@PATH,10,7441.65,-1691.336,1315.965,4.5961,0,0,0,100,0); -- 02:33:59
