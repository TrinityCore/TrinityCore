-- GameObject update
UPDATE `gameobject_template` SET `ScriptName` = 'go_headless_horseman_pumpkin' WHERE `entry` = 186267;
-- Creature Updates
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|512|2097152 WHERE `entry` = 23682;
UPDATE `creature_template` SET `flags_extra` =`flags_extra`|512, `ScriptName` = 'npc_pulsing_pumpkin' WHERE `entry` = 23694;
UPDATE `creature_template` SET `ScriptName` = 'npc_flame_bunny' WHERE `entry` = 23686;
UPDATE `creature_template` SET `ScriptName` = 'npc_headless_horseman_head', `mechanic_immune_mask`=617299827 WHERE `entry` = 23775;
UPDATE `creature_template` SET `ScriptName` = 'npc_sir_thomas' WHERE `entry` = 23904;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 24034;
-- Model Updates
UPDATE `creature_model_info` SET `BoundingRadius` = 0.75, `CombatReach` = 2.25 WHERE `DisplayID` = 22351;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.5, `CombatReach` = 1 WHERE `DisplayID` = 24720;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.75, `CombatReach` = 1.125 WHERE `DisplayID` = 21822;
-- AllowableRaces for Sir Thomas' quests
UPDATE `quest_template` SET `AllowableRaces` = 1101 WHERE `ID` = 11242;
UPDATE `quest_template` SET `AllowableRaces` = 690 WHERE `ID` = 11403;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_headless_horseman_yell_timer',
'spell_headless_horseman_maniacal_laugh',
'spell_headless_horseman_head_reposition',
'spell_headless_horseman_send_head',
'spell_headless_horseman_head_periodic',
'spell_headless_horseman_command_head_request_body',
'spell_headless_horseman_return_head',
'spell_summon_pumpkin_burst_delay',
'spell_headless_horseman_head_is_dead',
'spell_headless_horseman_summoning_rhyme_aura',
'spell_headless_horseman_sprouting',
'spell_headless_horseman_wisp_teleport');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42432,'spell_headless_horseman_yell_timer'),
(43893,'spell_headless_horseman_maniacal_laugh'),
(42410,'spell_headless_horseman_head_reposition'),
(42399,'spell_headless_horseman_send_head'),
(42603,'spell_headless_horseman_head_periodic'),
(43101,'spell_headless_horseman_command_head_request_body'),
(42401,'spell_headless_horseman_return_head'),
(52236,'spell_summon_pumpkin_burst_delay'),
(42428,'spell_headless_horseman_head_is_dead'),
(42879,'spell_headless_horseman_summoning_rhyme_aura'),
(42281,'spell_headless_horseman_sprouting'),
(42821,'spell_headless_horseman_wisp_teleport'),
(42818,'spell_headless_horseman_wisp_teleport');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (42410, 43101, 43306);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,42410,0,0,31,0,3,23775,0,0,0,0,'','Effect_0 hits Head of the Horseman'), -- Headless Horseman Climax - Command, Head Repositions
(13,1,43306,0,0,31,0,3,23682,0,0,0,0,'','Effect_0 hits Headless Horseman'),    -- Headless Horseman Climax - Command, Head Requests Body
(13,1,43101,0,0,31,0,3,23682,0,0,0,0,'','Effect_0 hits Headless Horseman');    -- Headless Horseman Climax - Heal Body

DELETE FROM `creature_text` WHERE `CreatureID` IN (23682,23775);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23682,0,0,'It is over, your search is done. Let fate choose now, the righteous one.',12,0,100,0,0,11961,22261,0,'Headless Horseman SAY_ENTRANCE'),
(23682,1,0,'Here\'s my body, fit and pure!  Now, your blackened souls I\'ll cure!',14,0,100,0,0,12567,22271,0,'Headless Horseman SAY_REJOINED'),
(23682,2,0,'Harken, cur!  Tis you I spurn!  Now feel... the burn!',11,0,100,0,0,12573,22587,0,'Headless Horseman SAY_CONFLAGRATION'),
(23682,3,0,'Soldiers arise, stand and fight! Bring victory at last to this fallen knight!',12,0,100,0,0,11963,23861,0,'Headless Horseman SAY_SPROUTING_PUMPKINS'),
(23682,4,0,'This end have I reached before.  What new adventure lies in store?',12,0,100,0,0,11964,23455,0,'Headless Horseman SAY_DEATH'),
(23682,5,0,'Your body lies beaten, battered and broken! Let my curse be your own, fate has spoken!',14,0,100,0,0,11962,40546,0,'Headless Horseman SAY_KILL_PLAYER'),
(23775,0,0,'So eager you are, for my blood to spill. Yet to vanquish me, \'tis my head you must kill!',14,0,100,0,0,11969,22757,0,'Head of the Horseman SAY_LOST_HEAD'),
(23775,1,0,'Get over here, you idiot!',12,0,100,0,0,12569,22415,0,'Head of the Horseman SAY_REQUEST_BODY'),
(23775,2,0,'Horseman rise...',1,0,100,0,0,0,22695,0,'Head of the Horseman SAY_PLAYER_RISE'),
(23775,3,0,'Your time is nigh...',1,0,100,0,0,0,22696,0,'Head of the Horseman SAY_PLAYER_TIME'),
(23775,4,0,'You felt death once...',1,0,100,22,0,0,22720,0,'Head of the Horseman SAY_PLAYER_DEATH'),
(23775,5,0,'Now, know demise!',1,0,100,5,0,0,22721,0,'Head of the Horseman SAY_PLAYER_DEMISE');
