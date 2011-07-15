-- TODO: this list of vehicles isn't complete, need to find more vehicles with missing immunities
UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask` |
0x00000002| -- MECHANIC_DISORIENTED (Blind)
0x00000004| -- MECHANIC_DISARM (Disarm)
0x00000008| -- MECHANIC_DISTRACT (Distract)
0x00000010| -- MECHANIC_FEAR (Fear, Psychic Scream)
0x00000020| -- MECHANIC_GRIP (Death Grip)
0x00000040| -- MECHANIC_ROOT (Entangling Roots)
0x00000100| -- MECHANIC_SILENCE (Silence)
0x00000200| -- MECHANIC_SLEEP (Wyvern Sting)
0x00000400| -- MECHANIC_SNARE (Crippling Poison, Piercing Howl)
0x00000800| -- MECHANIC_STUN (Hammer of Justice)
0x00001000| -- MECHANIC_FREEZE (Freezing Trap)
0x00002000| -- MECHANIC_KNOUCKOUT (Gouge, Blast Wave)
-- 0x00004000| -- MECHANIC_BLEED (Rend, Deep Wounds) - requires confirmation
0x00010000| -- MECHANIC_POLYMORPH (Polymorph)
0x00040000| -- MECHANIC_SHIELD (Power word: Shield)
-- 0x00200000| -- MECHANIC_INFECTED (Frost Fever, Blood Plague) - requires confirmation
0x00800000| -- MECHANIC_HORROR (warlock's Death Coil)
0x10000000| -- MECHANIC_IMMUNE_SHIELD (Hand of Protection)
0x02000000| -- MECHANIC_INTERRUPT (Kick, Counterspell)
0x04000000 -- MECHANIC_DAZE (Dazed)
where entry IN (
-- Some random quest vehicles
25334, -- Horde Siege Tank
26523, -- Forsaken Blight Spreader
-- Strand of the Ancients vehicles
28781, -- Battleground Demolisher
27894, -- Antipersonnel Cannon
-- Wintergrasp vehicles
27881, -- Wintergrasp Catapult (both)
28094, -- Wintergrasp Demolisher (both)
28312, -- Wintergrasp Siege Engine (alliance)
28319, -- Wintergrasp Siege Turret (alliance)
28366, -- Wintergrasp Tower Cannon (both)
32627, -- Wintergrasp Siege Engine (horde)
32629, -- Wintergrasp Siege Turret (alliance)
-- Ulduar Vehicles
33060, -- Salvaged Siege Engine
33062, -- Salvaged Chopper
33067, -- Salvaged Siege Turret
33109, -- Salvaged Demolisher
-- Isle of Conquest vehicles
34793, -- Catapult (both)
34775, -- Demolisher (both)
34776, -- Siege Engine (alliance)
34777, -- Siege Turret (alliance)
34778, -- Flame Turret (alliance)
34802, -- Glaive Thrower (alliance)
34944, -- Keep Cannon (both)
35069, -- Siege Engine (horde)
35273, -- Glaive Thrower (horde)
36355, -- Siege Turret (horde)
36356); -- Flame Turret (horde)
