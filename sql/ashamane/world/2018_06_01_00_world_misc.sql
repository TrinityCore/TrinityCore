-- Re Apply Fix of Cantrips Nightborne Racial --

UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 35, npcflag = 67108864 WHERE entry = 129356;

-- Fix Horde Paladin Class Hall portal Spawn and Default Name --

UPDATE gameobject SET id = 251305 WHERE guid = 20375595;

UPDATE gameobject_template SET NAME = "Portal to Sanctum of Light" WHERE entry = 251304;
