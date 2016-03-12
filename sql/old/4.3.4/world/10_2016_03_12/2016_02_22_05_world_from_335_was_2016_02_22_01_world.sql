UPDATE `spelleffect_dbc` SET `Effect`=28, `EffectMiscValueB`=64 WHERE  `EffectSpellId` IN(38953,38955,38956,38957,38958,38978);
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`=''  WHERE `entry` =22355;
DELETE FROM `smart_scripts` WHERE `entryorguid` =22355 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` BETWEEN 2235500 AND 2235505;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(22355, 0, 0, 1, 11, 0, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - On Respawn - Disable Combat Movement (No Repeat)'),
(22355, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 18, 2097152, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - On Respawn - Set Flag Disarmed (No Repeat)'),
(22355, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - On Respawn - Set Invincibility HP'),
(22355, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - On Agro - Store Target List (No Repeat)'),
(22355, 0, 4, 5, 2, 0, 100, 1, 0, 0, 0, 0, 11, 38949, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - On 1% HP - Cast Terokkar Free Webbed Creature (No Repeat)'),
(22355, 0, 5, 6,61, 0, 100, 1, 0, 0, 0, 0, 11, 38950, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - On 1% HP - Cast Terokkar Free Webbed Creature ON QUEST (No Repeat)'),
(22355, 0, 6, 0,61, 0, 100, 1, 0, 0, 0, 0, 87, 2233500, 2233501, 2233502, 2233503, 2233504, 2233505, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - On 1% HP - Run Random Script (No Repeat)'),
(2235500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38953, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 1 - Cast Terokkar Free Webbed Creature '),
(2235500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 1 - Die'),
(2235501, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38955, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 2 - Cast Terokkar Free Webbed Creature '),
(2235501, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 2 - Die'),
(2235502, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38956, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 3 - Cast Terokkar Free Webbed Creature '),
(2235502, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 3 - Die'),
(2235503, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38957, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 4 - Cast Terokkar Free Webbed Creature '),
(2235503, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 4 - Die'),
(2235504, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38958, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 5 - Cast Terokkar Free Webbed Creature '),
(2235504, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 5 - Die'),
(2235505, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 22459, 2, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 6 - Kill Credit'),
(2235505, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38978, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 6 - Cast Terokkar Free Webbed Creature '),
(2235505, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherweb Victim - Script 6 - Die');
