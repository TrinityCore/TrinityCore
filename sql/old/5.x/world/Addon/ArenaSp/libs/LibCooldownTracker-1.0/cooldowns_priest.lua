-- ================ PRIEST ================
-- Priest/baseline
-- Fear Ward
LCT_SpellData[6346] = {
	class = "PRIEST",
	defensive = true,
	cooldown = 180
}
-- Prayer of Mending
LCT_SpellData[33076] = {
	class = "PRIEST",
	heal = true,
	cooldown = 10
}
-- Hymn of Hope
LCT_SpellData[64901] = {
	class = "PRIEST",
	duration = 8,
	cooldown = 360,
}
-- Psychic Scream
LCT_SpellData[8122] = {
	class = "PRIEST",
	cc = true,
	cooldown = 27,
}
-- Shadowfiend
LCT_SpellData[34433] = {
	class = "PRIEST",
	offensive = true,
	duration = 12,
	cooldown = 180,
}
-- Leap of Faith
LCT_SpellData[73325] = {
	class = "PRIEST",
	defensive = true,
	cooldown = 90,
}
-- Mass Dispel
LCT_SpellData[32375] = {
	class = "PRIEST",
	mass_dispel = true,
	cooldown = 15
}
-- Priest/talents
-- Void Tendrils
LCT_SpellData[108920] = {
	class = "PRIEST",
	talent = true,
	cc = true,
	cooldown = 30
}
-- Psyfiend
LCT_SpellData[108921] = {
	class = "PRIEST",
	talent = true,
	cc = true,
	duration = 10,
	cooldown = 45
}
-- Phantasm
LCT_SpellData[114239] = {
	class = "PRIEST",
	talent = true,
	defensive = true,
	duration = 5,
	cooldown = 30
}
-- Angelic Feather
LCT_SpellData[121536] = {
	class = "PRIEST",
	talent = true,
	charges = 3,
	cooldown = 10
}
-- Mindbender
LCT_SpellData[123040] = {
	class = "PRIEST",
	talent = true,
	replaces = 34433,
	offensive = true,
	duration = 15,
	cooldown = 60
}
-- Desperate Prayer
LCT_SpellData[19236] = {
	class = "PRIEST",
	talent = true,
	defensive = true,
	cooldown = 120
}
-- Spectral Guise
LCT_SpellData[112833] = {
	class = "PRIEST",
	talent = true,
	defensive = true,
	duration = 6,
	cooldown = 30
}
-- Angelic Bulwark
LCT_SpellData[108945] = {
	class = "PRIEST",
	talent = true,
	defensive = true,
	cooldown = 90
}
-- Power Infusion
LCT_SpellData[10060] = {
	class = "PRIEST",
	talent = true,
	offensive = true,
	duration = 20,
	cooldown = 120
}
-- Cascade
LCT_SpellData[121135] = {
	class = "PRIEST",
	talent = true,
	offensive = true,
	heal = true,
	cooldown = 25
}
-- Divine Star
LCT_SpellData[110744] = {
	class = "PRIEST",
	talent = true,
	offensive = true,
	heal = true,
	cooldown = 15
}
-- Halo
LCT_SpellData[120517] = {
	class = "PRIEST",
	talent = true,
	offensive = true,
	heal = true,
	cooldown = 40
}

-- Priest/Discipline
-- Holy Fire
LCT_SpellData[14914] = {
	class = "PRIEST",
	specID = { 256, 257 },
	offensive = true,
	cooldown = 10
}
-- Archangel
LCT_SpellData[81700] = {
	class = "PRIEST",
	specID = { 256 },
	heal = true,
	duration = 18,
	cooldown = 30
}
-- Penance
LCT_SpellData[47540] = {
	class = "PRIEST",
	specID = { 256 },
	heal = true,
	duration = 2,
	cooldown = 9,
}
-- Inner Focus
LCT_SpellData[89485] = {
	class = "PRIEST",
	specID = { 256 },
	defensive = true,
	cooldown_starts_on_aura_fade = true,
	sets_cooldown = { spellid = 96267, cooldown = 45 },
	cooldown = 45,
}
-- Glyph of Inner Focus
LCT_SpellData[96267] = {
	class = "PRIEST",
	specID = { 256 },
	glyph = true,
	defensive = true,
	replaces = 89485,
	active_until_cooldown_start = true,
	duration = 5,
}
-- Pain Suppression
LCT_SpellData[33206] = {
	class = "PRIEST",
	specID = { 256 },
	defensive = true,
	duration = 8,
	cooldown = 180,
}
-- Power Word: Barrier
LCT_SpellData[62618] = {
	class = "PRIEST",
	specID = { 256 },
	defensive = true,
	duration = 10,
	cooldown = 180,
}
-- Spirit Shell
LCT_SpellData[109964] = {
	class = "PRIEST",
	specID = { 256 },
	defensive = true,
	duration = 10,
	cooldown = 60,
}
-- Purify
LCT_SpellData[527] = {
	class = "PRIEST",
	specID = { 256, 257 },
	dispel = true,
	cooldown_starts_on_dispel = true,
	cooldown = 8,
}
-- Void Shift
LCT_SpellData[108968] = {
	class = "PRIEST",
	specID = { 256, 257 },
	defensive = true,
	cooldown = 300,
}

-- Priest/Holy
-- Guardian Spirit
LCT_SpellData[47788] = {
	class = "PRIEST",
	specID = { 257 },
	defensive = true,
	duration = 10,
	cooldown = 180,
}
-- Lightwell
LCT_SpellData[724] = {
	class = "PRIEST",
	specID = { 257 },
	heal = true,
	cooldown = 180,
}
-- Divine Hymn
LCT_SpellData[64843] = {
	class = "PRIEST",
	specID = { 257 },
	heal = true,
	duration = 8,
	cooldown = 180
}
-- Holy Word: Chastise
LCT_SpellData[88625] = {
	class = "PRIEST",
	specID = { 257 },
	cc = true,
	cooldown = 30
}
-- Holy Word: Serenity
-- 88684 0 10
-- Circle of Healing
LCT_SpellData[34861] = {
	class = "PRIEST",
	specID = { 257 },
	heal = true,
	cooldown = 10
}

-- Priest/Shadow
-- Dispersion
LCT_SpellData[47585] = {
	class = "PRIEST",
	specID = { 258 },
	defensive = true,
	duration = 6,
	cooldown = 105, -- 120
}
-- Psychic Horror
LCT_SpellData[64044] = {
	class = "PRIEST",
	specID = { 258 },
	cc = true,
	cooldown = 45
}
-- Silence
LCT_SpellData[15487] = {
	class = "PRIEST",
	specID = { 258 },
	silence = true,
	cooldown = 45
}
-- Symbiosis/Tranquility
LCT_SpellData[113277] = {
	class = "PRIEST",
	specID = { 258 },
	requires_aura = 110485,
	heal = true,
	duration = 8,
	cooldown = 480
}
