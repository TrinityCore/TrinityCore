-- ================ SHAMAN ================
-- Shaman/baseline
-- Ascendance
LCT_SpellData[114049] = {
	class = "SHAMAN",
	offensive = true,
	defensive = true,
	duration = 15,
	cooldown = 180
}
--[[
-- Bloodlust
LCT_SpellData[2825] = {
	class = "SHAMAN",
	duration = 40,
	offensive = true,
	cooldown = 300
}
-- Heroism
LCT_SpellData[32182] = 2825
]]
-- Capacitor Totem
LCT_SpellData[108269] = {
	class = "SHAMAN",
	stun = true,
	duration = 5,
	cooldown = 45
}
-- Cleanse Spirit
LCT_SpellData[51886] = {
	class = "SHAMAN",
	dispel = true,
	cooldown_starts_on_dispel = true,
	cooldown = 8
}
-- Earth Elemental Totem
LCT_SpellData[2062] = {
	class = "SHAMAN",
	duration = 60,
	cooldown = 300
}
-- Earth Shock
LCT_SpellData[8042] = {
	class = "SHAMAN",
	offensive = true,
	cooldown = 6
}
-- Earthbind Totem
LCT_SpellData[2484] = {
	class = "SHAMAN",
	cc = true,
	duration = 20,
	cooldown = 30
}
-- Fire Elemental Totem
LCT_SpellData[2894] = {
	class = "SHAMAN",
	duration = 60,
	offensive = true,
	cooldown = 300
}
-- Flame Shock
LCT_SpellData[8050] = {
	class = "SHAMAN",
	offensive = true,
	cooldown = 6
}
-- Frost Shock
LCT_SpellData[8056] = {
	class = "SHAMAN",
	cc = true,
	cooldown = 6
}
-- Grounding Totem
LCT_SpellData[8177] = {
	class = "SHAMAN",
	defensive = true,
	duration = 15,
	cooldown = 25
}
-- Healing Rain
LCT_SpellData[73920] = {
	class = "SHAMAN",
	heal = true,
	duration = 10,
	cooldown = 10
}
-- Healing Stream Totem
LCT_SpellData[5394] = {
	class = "SHAMAN",
	heal = true,
	duration = 15,
	cooldown = 30
}
-- Hex
LCT_SpellData[51514] = {
	class = "SHAMAN",
	cc = true,
	cooldown = 45
}
-- Primal Strike
LCT_SpellData[73899] = {
	class = "SHAMAN",
	offensive = true,
	cooldown = 8
}
-- Spiritwalker's Grace
LCT_SpellData[79206] = {
	class = "SHAMAN",
	duration = 15,
	cooldown = 120
}
-- Stormblast
LCT_SpellData[115356] = {
	class = "SHAMAN",
	offensive = true,
	cooldown = 8
}
-- Stormlash Totem
LCT_SpellData[120668] = {
	class = "SHAMAN",
	offensive = true,
	duration = 10,
	cooldown = 300
}
-- Tremor Totem
LCT_SpellData[8143] = {
	class = "SHAMAN",
	defensive = true,
	duration = 6,
	cooldown = 60
}
-- Unleash Elements
LCT_SpellData[73680] = {
	class = "SHAMAN",
	cooldown = 15
}
-- Unleash Life
LCT_SpellData[73685] = {
	class = "SHAMAN",
	heal = true,
	cooldown = 15
}
-- Wind Shear
LCT_SpellData[57994] = {
	class = "SHAMAN",
	interrupt = true,
	cooldown = 12
}


-- Shaman/talents
-- Ancestral Guidance
LCT_SpellData[108281] = {
	class = "SHAMAN",
	talent = true,
	heal = true,
	duration = 10,
	cooldown = 120
}
-- Ancestral Swiftness
LCT_SpellData[16188] = {
	class = "SHAMAN",
	talent = true,
	cooldown_starts_on_aura_fade = true,
	cooldown = 90
}
-- Astral Shift
LCT_SpellData[108271] = {
	class = "SHAMAN",
	talent = true,
	defensive = true,
	duration = 6,
	cooldown = 90
}
-- Call of the Elements
LCT_SpellData[108285] = {
	class = "SHAMAN",
	talent = true,
	-- rests=... = true, TODO: this
	cooldown = 180
}
-- Earthgrab Totem
LCT_SpellData[51485] = {
	class = "SHAMAN",
	talent = true,
	replaces = 2484,
	duration = 20,
	cooldown = 30
}
-- Elemental Blast
LCT_SpellData[117014] = {
	class = "SHAMAN",
	talent = true,
	offensive = true,
	cooldown = 12
}
-- Elemental Mastery
LCT_SpellData[16166] = {
	class = "SHAMAN",
	talent = true,
	offensive = true,
	duration = 20,
	cooldown = 90
}
-- Healing Tide Totem
LCT_SpellData[108280] = {
	class = "SHAMAN",
	talent = true,
	heal = true,
	duration = 10,
	cooldown = 180
}
-- Stone Bulwark Totem
LCT_SpellData[108270] = {
	class = "SHAMAN",
	talent = true,
	defensive = true,
	duration = 30,
	cooldown = 60
}
-- Totem Projection
LCT_SpellData[108287] = {
	class = "SHAMAN",
	talent = true,
	cooldown = 10
}
-- Windwalk Totem
LCT_SpellData[108273] = {
	class = "SHAMAN",
	talent = true,
	defensive = true,
	duration = 6,
	cooldown = 60
}


-- Shaman/Elemental
-- Earthquake
LCT_SpellData[61882] = {
	class = "SHAMAN",
	specID = { 262 },
	knockback = true,
	duration = 10,
	cooldown = 10
}
-- Lave Burst
LCT_SpellData[51505] = {
	class = "SHAMAN",
	specID = { 262 },
	offensive = true,
	cooldown = 8
}
-- Thunderstorm
LCT_SpellData[51490] = {
	class = "SHAMAN",
	specID = { 262 },
	knockback = true,
	cc = true,
	cooldown = 22.5
}
-- Symbiosis/Solar Beam
LCT_SpellData[113286] = {
	class = "SHAMAN",
	specID = { 262, 263 },
	requires_aura = 110488,
	silence = true,
	interrupt = true,
	duration = 4,
	cooldown = 60
}

-- Shaman/Enhancement
-- Feral Spirit
LCT_SpellData[51533] = {
	class = "SHAMAN",
	specID = { 263 },
	offensive = true,
	heal = true,
	duration = 30,
	cooldown = 120
}
-- Lava Lash
LCT_SpellData[60103] = {
	class = "SHAMAN",
	specID = { 263 },
	offensive = true,
	cooldown = 10
}
-- Shamanistic Rage
LCT_SpellData[30823] = {
	class = "SHAMAN",
	specID = { 262, 263 },
	defensive = true,
	duration = 15,
	cooldown = 60
}
-- Spirit Walk
LCT_SpellData[58875] = {
	class = "SHAMAN",
	specID = { 263 },
	defensive = true,
	duration = 15,
	cooldown = 60
}
-- Stormstrike
LCT_SpellData[17364] = {
	class = "SHAMAN",
	specID = { 263 },
	offensive = true,
	cooldown = 8
}

-- Shaman/Restoration 264
-- Mana Tide Totem
LCT_SpellData[16190] = {
	class = "SHAMAN",
	specID = { 264 },
	duration = 16,
	cooldown = 180
}
-- Purify Spirit
LCT_SpellData[77130] = {
	class = "SHAMAN",
	specID = { 264 },
	dispel = true,
	replaces = 51886,
	cooldown_starts_on_dispel = true,
	cooldown = 8
}
-- Riptide
LCT_SpellData[61295] = {
	class = "SHAMAN",
	specID = { 264 },
	heal = true,
	cooldown = 6
}
-- Spirit Link Totem
LCT_SpellData[98008] = {
	class = "SHAMAN",
	specID = { 264 },
	defensive = true,
	duration = 6,
	cooldown = 180
}
