-- Spell condition for Cosmetic - Spear Throw
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43647;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,43647,0,0,31,0,3,24375,0,0,0,0, '', 'Cosmetic - Spear Throw - Harrison Jones');

/* 4.x removed
-- Text for Harrison Jones from sniff
DELETE FROM `creature_text` WHERE `entry` IN (24358,24375);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24358,0,0, 'Suit yourself. At least five of you must assist me if we''re to get inside. Follow me....',14,0,100,1,0,0, 'Harrison Jones - Gong Event Say 0'),
(24358,1,0, 'According to my calculations, if enough of us bang the gong at once the seal on these doors will break and we can enter.',14,0,100,1,0,0, 'Harrison Jones - Gong Event Say 1'),
(24375,0,0, 'I''ve researched this site extensively and I won''t allow any dim-witted treasure hunters to swoop in and steal what belongs in a museum. I''ll lead this charge...',14,0,100,0,0,0, 'Harrison Jones - Gong Event Say 2'),
(24375,1,0, 'In fact, it would be best if you just stay here. You''d only get in my way....',14,0,100,0,0,0, 'Harrison Jones - Gong Event Say 3');
*/

-- Add spell script for banging the gong
DELETE FROM `spell_script_names` WHERE `spell_id`=45226;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45226, 'spell_banging_the_gong');

-- Remove creature from db
DELETE FROM `creature` WHERE id=24358;
-- DELETE FROM `creature_addon` WHERE guid=86177; 4.x removed
UPDATE `creature_template` SET `equipment_id`=0 WHERE `entry`=24358;

/* 4.x removed
-- Pathing for Harrison Jones Entry: 24358
SET @NPC := 86044;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_data` WHERE `id`IN (861770,861771,861772);
DELETE FROM `waypoint_data` WHERE `id`IN (@PATH,@PATH+1,@PATH+2);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,131.8243,1642.853,42.0216,0,0,0,100,0),
(@PATH+1,1,121.897,1639.106,42.19081,0,0,0,100,0),
(@PATH+1,2,120.8522,1637.931,42.37172,0,0,0,100,0),
(@PATH+1,3,120.7898,1609.063,43.49005,0,0,0,100,0),
(@PATH+2,1,120.6967,1603.713,43.4503,0,0,0,100,0);
*/
