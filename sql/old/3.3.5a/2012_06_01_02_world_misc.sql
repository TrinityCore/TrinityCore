/* Quest:  Kick, What Kick? - 12589 by Nay */

-- Lucky Wilhelm: 0xF150006D960041CB
-- Drostan:       0xF130006EA80041CA
-- Apple:         0xF130006D950041C8

-- Remove old conditions, now done in cpp
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=51330;

-- Spells conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (51331,51332,51366);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 51331, 0, 0, 31, 0, 3, 28053, 0, 0, 0, '', 'Hit Apple - Apple - Q: Kick, What Kick?'),
(13, 1, 51332, 0, 0, 31, 0, 3, 28054, 0, 0, 0, '', 'Miss Apple - Wilhelm - Q: Kick, What Kick?'),
(13, 1, 51366, 0, 0, 31, 0, 3, 28093, 0, 0, 0, '', 'Miss Apple, Hit Bird - Sholazar Tickbird - Q: Kick, What Kick?');

-- Assign script to spell
DELETE FROM `spell_script_names` WHERE `spell_id`=51330;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(51330, 'spell_q12589_shoot_rjr');

-- Spellclick spell for Wilhelm
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=28054;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(28054,50556,1,0);

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (28053,28328,30737,28346);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28053,0,0,1,0, NULL), -- Apple
(28328,0,0,257,0, NULL), -- Drostan
(30737,0,0,256,0, NULL), -- Nesingwary Game Warden
(28346,0,0,1,0, NULL); -- Crunchy

-- Put Apple in Wilhelm's head
DELETE FROM `vehicle_template_accessory` WHERE `entry`=28054 AND `accessory_entry`=28053;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(28054, 28053, -1, 0, 'Lucky Wilhelm - Apple', 6, 10000);

-- Says and yells
DELETE FROM `creature_text` WHERE `entry`=28328 OR (`entry`=28054 AND `groupid` IN (0,1));
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(28328, 0, 0, 'The only thing hurt is your pride, lad. Buck up!', 12, 0, 100, 11, 0, 0, 'Drostan to Lucky Wilhelm'),
(28328, 0, 1, 'Stop whining. You''ve still got your luck.', 12, 0, 100, 11, 0, 0, 'Drostan to Lucky Wilhelm'),
(28328, 0, 2, 'Bah, it''s an improvement.', 12, 0, 100, 0, 0, 0, 'Drostan to Lucky Wilhelm'),
(28328, 0, 3, 'Calm down lad, it''s just a birdshot!', 12, 0, 100, 0, 0, 0, 'Drostan to Lucky Wilhelm'),
(28054, 0, 0, 'Not the ''stache! Now I''m asymmetrical!', 12, 0, 100, 5, 0, 0, 'Lucky Wilhelm'),
(28054, 0, 1, 'Ouch! That''s it, I quit the target business!', 12, 0, 100, 0, 0, 0, 'Lucky Wilhelm'),
(28054, 0, 2, 'My ear! You grazed my ear!', 12, 0, 100, 0, 0, 0, 'Lucky Wilhelm'),
(28054, 1, 0, 'Good shot!', 12, 0, 100, 4, 0, 0, 'Lucky Wilhelm');

/* * Hit: */
/* player casts Shoot RJR on Lucky */
/* apple gets hit by 51331 (Hit Apple) by player */
/* after that apple casts 51371 (Apple Falls to ground) on self */
/* Wilhelm says Good shot! */
/* reward killcredit 28053 */

/* * Miss: */
/* player casts Shoot RJR on Lucky */
/* lucky gets hit by 51332 (Miss Apple) by player */
/* lucky says random text */
/* drostan says random text */

/* * Miss, Hit Bird - guessed */
/* player casts Shoot RJR on Lucky */
/* bird gets hit by 51366 (Miss Apple, Hit Bird and dies) */
/* bird gets hit by 51369 (Tickbird Signal to Fall) */
/* lucky says random text */
/* drostan says random text */
