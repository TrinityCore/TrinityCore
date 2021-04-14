DELETE FROM `gossip_menu_option` WHERE menu_id IN(8510,8524);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8510, 0, 0, 'Yes Scryer, You may possess me', 20008, 1, 1, 0, 0, 0, 0, NULL, 0);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (22258,22259,22273,22267,22366);

-- UPDATE `spell_dbc` SET `Effect1`=28,`EffectMiscValueB1`=64 WHERE  `Id`IN(38674,38675,38676,38677,38678,38679,38709,38681);


DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22258,22259,22273,22267,22366,2225800);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22258, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, 2225800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - On Spawn - Run Script'),
(22258, 0, 1, 2 ,62,0, 100, 0, 8510,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Demoniac Scryer - On Gossip Select - Close Gossip'),
(22258, 0, 2, 0, 61,0, 100, 0,0,0,0,0,85,38708,1,0,0,0,0,7,0,0,0,0,0,0,0,'Demoniac Scryer - On Gossip Select - Cast Demoniac Visitation'),
(22258, 0, 3, 7, 11,0, 100, 0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Demoniac Scryer - On Spawn - Set NPC Flags'),
(22258, 0, 4, 5, 7,0, 100, 0,0,0,0,0,11,38672,0,0,0,0,0,1,0,0,0,0,0,0,0,'Demoniac Scryer - On Evade  - Cast Magic Sucker Device timer'),
(22258, 0, 5, 0, 61,0, 100, 0,0,0,0,0,11,38690,0,0,0,0,0,1,0,0,0,0,0,0,0,'Demoniac Scryer - On Evade  - Cast Magic Sucker Device Bunny Appearance'),
(22258, 0, 6 ,0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 38691, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - On Death - Cast Magic Sucker Device Despawner, Mob AE'), 
(22258, 0, 7 ,8, 61, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - On Spawn - Disable Auto Attack'), 
(22258, 0, 8 ,9, 61, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - On Death - Disable Combatmovement'), 
(22258, 0, 9 ,0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - On Death - Disable Combatmovement'), 
(22258, 0, 10 ,0, 64, 0, 100, 0, 0, 0, 0, 0, 98, 8510, 10643, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - On Death - Disable Combatmovement'), 
(22366, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Visitation - On Just Summoned - Say'),
(22259, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 38683, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hellfire Wardling - On Just Summoned - Cast Magic Sucker Device Despawner, Mob'),
(22259, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hellfire Wardling - On Just Summoned - Say'),
(22259, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 7741, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hellfire Wardling - On Just Summoned - Cast Summoned Demon'),
(22259, 0, 3, 4, 6, 0, 100, 0, 0, 0, 0, 0, 11, 38891, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hellfire Wardling - On Death - Cast Magic Sucker Device (Despawn Visual)'),
(22259, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hellfire Wardling - On Death - Despawn'),
(22259, 0, 5, 0, 8, 0, 100, 0, 38691, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hellfire Wardling - On Spellhit (Magic Sucker Device Despawner, Mob AE) - Despawn'),
(22273, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 38683, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fel Warden - On Just Summoned - Cast Magic Sucker Device Despawner, Mob'),
(22273, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fel Warden - On Just Summoned - Say'),
(22273, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 7741, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fel Warden - On Just Summoned - Cast Summoned Demon'),
(22273, 0, 3, 0, 8, 0, 100, 0, 38691, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fel Warden - On Spellhit (Magic Sucker Device Despawner, Mob AE) - Despawn'),
(22267, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 38719, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magic Sucker Device Buttress - On Just Summoned - Cast Magic Sucker Device Buttress Appearance'),
(22267, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 22258, 0, 0, 0, 0, 0, 0, 'Magic Sucker Device Buttress - On Just Summoned - Set Orientation'),
(22267, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 30259, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magic Sucker Device Buttress - On Just Summoned - Cast Statue (dnd)'),
(22267, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 38721, 0, 0, 0, 0, 0, 19, 22258, 0, 0, 0, 0, 0, 0, 'Magic Sucker Device Buttress - On Just Summoned - Cast Magic Sucker Device Channel(dnd)'),
(22267, 0, 4, 0, 8, 0, 100, 0, 38691, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magic Sucker Device Buttress - On Spellhit (Magic Sucker Device Despawner, Mob AE) - Despawn'),
(22267, 0, 5, 3, 1, 0, 100, 0, 0, 0, 3000, 3000, 11, 38719, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magic Sucker Device Buttress - IC - Cast Magic Sucker Device Buttress Appearance'),
(22267, 0, 6, 3, 0, 0, 100, 0, 0, 0, 3000, 3000, 11, 38919, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magic Sucker Device Buttress - OOC - Cast Magic Sucker Device Buttress Appearance'),

(2225800, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38672, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Magic Sucker Device timer'), -- 15:36:21
(2225800, 9, 1 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38690, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Magic Sucker Device Bunny Appearance'), -- 15:36:21
(2225800, 9, 2 ,0, 0, 0, 100, 0, 8000, 8000, 0, 0, 11, 38681, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Spawner, Device'), -- 15:36:29
(2225800, 9, 3 ,0, 0, 0, 100, 0, 7000, 7000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:36:36 *
(2225800, 9, 4 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:36:51 *
(2225800, 9, 5 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:37:06 *
(2225800, 9, 6 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38675, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Create Magic Sucker Device Buttress (N)'), -- 15:37:06 *
(2225800, 9, 7 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:37:21 *
(2225800, 9, 8 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:37:36 *
(2225800, 9, 9 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:37:51 *
(2225800, 9, 10 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38676, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Create Magic Sucker Device Buttress (S)'), -- 15:37:51 *
(2225800, 9, 11 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:38:06 *
(2225800, 9, 12 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:38:21 *
(2225800, 9, 13 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:38:36 *
(2225800, 9, 14 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38709, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Boss'), -- 15:38:36 *
(2225800, 9, 15 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:38:51 *
(2225800, 9, 16 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38677, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Create Magic Sucker Device Buttress (E)'), -- 15:38:51 *
(2225800, 9, 17 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:39:06 *
(2225800, 9, 18 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:39:21 *
(2225800, 9, 19 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38678, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Create Magic Sucker Device Buttress (W)'), -- 15:39:21 *
(2225800, 9, 20 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:39:36 *
(2225800, 9, 21 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38679, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Spawn Magic Sucker Device Mob'), -- 15:39:51 *
(2225800, 9, 22 ,0, 0, 0, 100, 0, 15000, 15000, 0, 0, 11, 38691, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Magic Sucker Device Despawner, Mob AE'), -- 15:40:06 *
(2225800, 9, 23 ,0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 38727, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Magic Sucker Device (Success Visual timer)'), -- 15:40:07 *
(2225800, 9, 24 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Set Unit Flags'),
(2225800, 9, 25 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 38672, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Remove Aura Magic Sucker Device timer'),
(2225800, 9, 26 ,0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 38727, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Magic Sucker Device (Success Visual timer)'), -- 15:40:07 *
(2225800, 9, 27 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 38672, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Remove Aura Magic Sucker Device timer'),
(2225800, 9, 28 ,0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 38727, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Cast Magic Sucker Device (Success Visual timer)'), -- 15:40:07 *
(2225800, 9, 29 ,0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 38672, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Remove Aura Magic Sucker Device timer'),
(2225800, 9, 30 ,0, 0, 0, 100, 0, 84000, 84000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demoniac Scryer - Script - Remove Aura Magic Sucker Device timer');
  
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=22258;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 11, 22258, 0, 0, 9, 0, 10838, 0, 0, 0, 0, 0, '', 'Demoniac Scryer - Only run SAI if player has the Demoniac Scryer Taken'),
(22, 11, 22258, 0, 0, 2, 0, 31607, 1, 0, 1, 0, 0, '', 'Demoniac Scryer - Only run SAI if player does not have Demoniac Scryer Reading'),
(22, 11, 22258, 0, 0, 1, 0, 38708, 0, 0, 1, 0, 0, '', 'Demoniac Scryer - Only run SAI if player does not have Aura Demonaic Visitation'),
(22, 11, 22258, 0, 0, 1, 1, 38672, 0, 0, 1, 0, 0, '', 'Demoniac Scryer - Only run SAI if Demoniac Scryer does not have Aura Magic Sucker Device timer');

DELETE FROM `creature_text` WHERE `entry` IN (22259,22273,22366);

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(22273, 0, 0, 'Die, interloper!  Your puny device cannot pierce the dark magics of Hellfire Citadel!', 12, 0, 100, 397, 0, 0, 'Fel Warden',20020),
(22259, 0, 0, 'Your end has come!', 12, 0, 100, 0, 0, 0, 'Hellfire Wardling',53515),
(22259, 0, 1, 'An intruder!  Begone!', 12, 0, 100, 0, 0, 0, 'Hellfire Wardling',20027),
(22259, 0, 2, 'An intruder!  Begone!', 12, 0, 100, 0, 0, 8152, 'Hellfire Wardling',20027),
(22259, 0, 3, 'You will burn!', 12, 0, 100, 0, 0, 0, 'Hellfire Wardling',53513),
(22259, 0, 4, 'Die!', 12, 0, 100, 0, 0, 0, 'Hellfire Wardling',53514),
(22259, 0, 5, 'Your end has come!', 12, 0, 100, 0, 0, 8152, 'Hellfire Wardling',53515),
(22259, 0, 6, 'Die!', 12, 0, 100, 0, 0, 8152, 'Hellfire Wardling',53514),
(22366, 0, 0, 'Thank you for allowing me to visit, $n.  You have a very colorful soul, but it''s a little brighter than I prefer... or I might have stayed longer!', 15, 0, 100, 0, 0, 0, 'Demoniac Visitation',20154);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`IN(-38708);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-38708, 38991, 0,'Upon Demoniac Visitation expiring cast Summon Demonaic Visitation');
