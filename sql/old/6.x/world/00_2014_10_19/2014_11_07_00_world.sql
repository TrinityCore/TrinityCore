UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` IN(26158,26167,26162);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26158,26167,26162) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2616700,2616701,2616702,2616703) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26158, 0, 0, 0, 19, 0, 100, 0, 11930, 0, 0, 0, 85, 46657, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mother Tauranook - On Quest Accept (Across Transborea) - Invoker Cast Taunka''le Evacuee'),
(26167, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 46669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - On Spawn - Cast Evacuee Random Action'),
(26167, 0, 1, 0, 8, 0, 100, 0, 46663, 0, 0, 0, 87, 2616700, 2616701, 2616702, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - On Spellhit (Evacuee Random Action) - Run Random Script'),
(26167, 0, 2, 0, 8, 0, 100, 1, 46677, 0, 0, 0, 80, 2616703, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - On Spellhit (Evacuee Reaches Dragonblight) - Run Script'),
(26162, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 1000, 11, 46677, 0, 0, 0, 0, 0, 19, 26167, 0, 0, 0, 0, 0, 0, 'Transborea Generator 001 - OOC - Cast Evacuee Reaches Dragonblight'),
(2616700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 1 - Say Line'),
(2616701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 2 - Say Line'),
(2616701, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 46694, 0, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 2 - Cast Feed'),
(2616702, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 46670, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 3 - Cast Transborea Monster'),
(2616702, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 3 - Say Line'),
(2616703, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 46669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 4 - Remove Aura Evacuee Random Action'),
(2616703, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 4 - Say Line'),
(2616703, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 4 - Say Line'),
(2616703, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 4 - Say Line'),
(2616703, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 4 - Say Line'),
(2616703, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 4 - Say Line'),
(2616703, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 46676, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 4 - Cast Across Transborea Complete'),
(2616703, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Taunka''le Evacuee - Script 4 - Despawn');

DELETE FROM `creature_template_addon` WHERE `entry`=26167;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(26167, 0, 0, 0, 4097, 0, '46669');

DELETE FROM `creature_text` WHERE `entry`=26167;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(26167, 0, 0, '%s cries.', 16, 1, 100, 18, 0, 0, 'Taunka''le Evacuee',25304),
(26167, 1, 0, 'Stop!', 12, 1, 100, 5, 0, 0, 'Taunka''le Evacuee',25294),
(26167, 2, 0, 'Look out!', 12, 1, 100, 0, 0, 0, 'Taunka''le Evacuee',25299),
(26167, 3, 0, '%s points northeast.', 16, 1, 100, 25, 0, 0, 'Taunka''le Evacuee',25311),
(26167, 4, 0, 'The smoke in the distance... It is Wartook. He is trying to tell us something...', 12, 1, 100, 1, 0, 0, 'Taunka''le Evacuee',25312),
(26167, 5, 0, '%s expertly identifies the messages hidden within the smoke signals.', 16, 1, 100, 20, 0, 0, 'Taunka''le Evacuee',25315),
(26167, 6, 0, 'No... It cannot be true...', 12, 1, 100, 274, 0, 0, 'Taunka''le Evacuee',25313),
(26167, 7, 0, 'Icemist... Not Icemist... NO!!! Come quickly, hero! Follow me!', 12, 1, 100, 15, 0, 0, 'Taunka''le Evacuee',25314);
