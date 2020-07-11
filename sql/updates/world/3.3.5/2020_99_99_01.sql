--
-- Note: All of these should be targetable by spells 46904 and 46903, but conditions are only set for Stormwind (damn Horde fanatics)
UPDATE gameobject_template_addon SET artkit0 = 121, artkit1 = 122 WHERE entry IN (
	188352, -- Flame of Shattrath
	188129, -- Flame of Silvermoon
	188128, -- Flame of the Exodar
	181567, -- Flame of the Wetlands
	181566, -- Flame of Hillsbrad
	181565, -- Flame of Westfall
	181564, -- Flame of Silverpine
	181563, -- Flame of Darkshore
	181562, -- Flame of Stonetalon
	181561, -- Flame of Ashenvale
	181560, -- Flame of the Barrens
	181349, -- Flame of the Scholomance
	181348, -- Flame of Stratholme
	181347, -- Flame of Blackrock Spire
	181346, -- Flame of Dire Maul
	181345, -- Flame of the Hinterlands
	181344, -- Flame of the Blasted Lands
	181343, -- Flame of Un'Goro
	181342, -- Flame of Azshara
	181341, -- Flame of Searing Gorge
	181340, -- Flame of Winterspring
	181339, -- Flame of Silithus
	181338, -- Flame of the Plaguelands
	181337, -- Flame of Thunder Bluff
	181336, -- Flame of Orgrimmar
	181335, -- Flame of the Undercity
	181334, -- Flame of Darnassus
	181333, -- Flame of Ironforge
	181332  -- Flame of Stormwind
);

DELETE FROM `spell_script_names` WHERE `ScriptName`= "spell_banging_the_gong";
