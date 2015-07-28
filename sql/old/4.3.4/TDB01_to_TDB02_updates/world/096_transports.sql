-- Add Krazzworks <-> Dragonmaw Port Transports
DELETE FROM `transports` WHERE `entry` IN (206328, 206329);
INSERT INTO `transports` (`guid`, `entry`, `name`, `period`, `ScriptName`) VALUES 
(21, 206328, 'Krazzworks to Dragonmaw Port', 205674, ''),
(22, 206329, 'Dragonmaw Port to Krazzworks', 205674, '');
-- Transport flags
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry` IN (206328, 206329);

-- Add Passengers
DELETE FROM `creature_transport` WHERE `transport_entry` IN (206328, 206329);
INSERT INTO `creature_transport` (`guid`, `transport_entry`, `npc_entry`, `TransOffsetX`, `TransOffsetY`, `TransOffsetZ`, `TransOffsetO`, `emote`) VALUES 
(1, 206328, 46763, 4.26206, -11.6361, -17.82397, 3.420845, 0), -- Captain Fizzlesneer
(2, 206328, 48535, -15.9296, -10.8046, -15.32037, 4.258604, 0), -- Krazzworks Sky Marshall
(3, 206328, 48535, 2.31688, -7.91102, -23.63947, 0, 0), -- Krazzworks Sky Marshall
(4, 206328, 48535, -4.130146, -2.779428, -17.79507, 0.01120401, 0), -- Krazzworks Sky Marshall
(1, 206329, 46764, 4.15988, -11.1731, -17.82867, 3.368485, 0), -- Captain Smoldersmitten
(2, 206329, 48535, -11.77357, -10.21906, -16.61713, 1.694214, 0), -- Krazzworks Sky Marshall
(3, 206329, 48535, 6.63632, -3.07199, -17.71427, 1.22173, 0), -- Krazzworks Sky Marshall
(4, 206329, 48535, 7.3889, -7.71648, -23.53657, 3.246312, 0); -- Krazzworks Sky Marshall

-- Add Equip Template
DELETE FROM `creature_equip_template` WHERE `entry` IN (46763, 46764, 48535);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(46763, 3364, 0, 0), -- Captain Fizzlesneer
(46764, 3364, 0, 0), -- Captain Smoldersmitten
(48535, 53583, 0, 45937); -- Krazzworks Sky Marshall

-- Add Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (46763, 46764, 48535);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(46763, 0, 0x0, 0x101, ''), -- Captain Fizzlesneer
(46764, 0, 0x0, 0x101, ''), -- Captain Smoldersmitten
(48535, 0, 0x0, 0x1, ''); -- Krazzworks Sky Marshall
