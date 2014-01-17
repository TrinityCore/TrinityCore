-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (30021,31748,32795,32796,34045,33782,33318,33323,33322,33317,33319,33316,33321,33324,33320,33845,33844,33217);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(30021,46598,0,0,0,1,0,0,0), -- Enormos - Ride Vehicle Hardcoded
(30021,55785,0,0,0,3,0,0,0), -- Enormos - Mammoth Jack
(31748,56378,0,0,0,1,0,0,0), -- Hover Disk (1)- Summon Disk
(32795,56378,0,0,0,1,0,0,0), -- Antipersonnel Cannon (1) - Ride Vehicle
(32796,60683,0,0,0,1,0,0,0), -- Battleground Demolisher (1) - Ride Vehicle
(34045,65030,0,0,0,1,0,0,0), -- Salvaged Chopper (1) - Ride Vehicle
(33782,63151,0,0,0,1,0,0,0), -- Argent Warhorse
(33318,63151,0,0,0,1,0,0,0), -- Exodar Elekk
(33323,63151,0,0,0,1,0,0,0), -- Silvermoon Hawkstrider
(33322,63151,0,0,0,1,0,0,0), -- Thunder Bluff Kodo
(33317,63151,0,0,0,1,0,0,0), -- Gnomeregan Mechanostrider
(33319,63151,0,0,0,1,0,0,0), -- Darnassian Nightsaber
(33316,63151,0,0,0,1,0,0,0), -- Ironforge Ram
(33321,63151,0,0,0,1,0,0,0), -- Darkspear Raptor
(33324,63151,0,0,0,1,0,0,0), -- Forsaken Warhorse
(33320,63151,0,0,0,1,0,0,0), -- Orgrimmar Wolf
(33845,63151,0,0,0,1,0,0,0), -- Quel''dorei Steed
(33844,63151,0,0,0,1,0,0,0), -- Sunreaver Hawkstrider
(33217,63151,0,0,0,1,0,0,0); -- Stormwind Steed
-- Template update
UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16,`speed_walk`=0.666668,`speed_run`=2 WHERE `entry`=30021; -- Enormos
