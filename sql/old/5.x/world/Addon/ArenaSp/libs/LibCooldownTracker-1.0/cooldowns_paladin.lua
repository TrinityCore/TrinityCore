-- ================ PALADIN ================
-- Paladin/baseline
-- Avengin Wrath
LCT_SpellData[31884] = {
	class = "PALADIN",
	offensive = true,
	defensive = true,
	duration = 20,
	cooldown = 180
}
-- Blinding Light
LCT_SpellData[115750] = {
	class = "PALADIN",
	cc = true,
	cooldown = 120
}
-- Cleanse
LCT_SpellData[4987] = {
	class = "PALADIN",
	cooldown_starts_on_dispel = true,
	dispel = true,
	cooldown = 8
}
-- Devotion Aura
LCT_SpellData[31821] = {
	class = "PALADIN",
	defensive = true,
	duration = 6,
	cooldown = 180
}
-- Divine Protection
LCT_SpellData[498] = {
	class = "PALADIN",
	defensive = true,
	duration = 10,
	cooldown = 60
}
-- Divine Shield
LCT_SpellData[642] = {
	class = "PALADIN",
	immune = true,
	duration = 8,
	cooldown = 300
}
-- Hammer of Justice
LCT_SpellData[853] = {
	class = "PALADIN",
	stun = true,
	cooldown = 60
}
-- Hammer of Wrath
LCT_SpellData[24275] = {
	class = "PALADIN",
	offensive = true,
	cooldown = 6
}
-- Hand of Freedom
LCT_SpellData[1044] = {
	class = "PALADIN",
	defensive = true,
	opt_charges = 2,
	opt_charges_linked = { 1022, 6940 },
	duration = 6,
	cooldown = 25
}
-- Hand of Protection
LCT_SpellData[1022] = {
	class = "PALADIN",
	defensive = true,
	opt_charges = 2,
	opt_charges_linked = { 1044, 6940 },
	duration = 10,
	cooldown = 300
}
-- Hand of Sacrifice
LCT_SpellData[6940] = {
	class = "PALADIN",
	defensive = true,
	opt_charges = 2,
	opt_charges_linked = { 1044, 1022 },
	duration = 12,
	cooldown = 120
}
-- Judgement
LCT_SpellData[20271] = {
	class = "PALADIN",
	offensive = true,
	cooldown = 6
}
-- Lay on Hands
--[[
LCT_SpellData[633] = {
	class = "PALADIN",
	heal = true -- todo: available on arenas?
	cooldown = 600
}
]]
-- Rebuke
LCT_SpellData[96231] = {
	class = "PALADIN",
	interrupt = true,
	cooldown = 15
}
-- Turn Evil
LCT_SpellData[10326] = {
	class = "PALADIN",
	offensive = true,
	cooldown = 15
}
-- Paladin/talents
-- Execution Sentence
LCT_SpellData[114157] = {
	class = "PALADIN",
	talent = true,
	offensive = true,
	heal = true, -- todo: check spellids for off/heal
	duration = 10,
	cooldown = 60
}
-- Fist of Justice
LCT_SpellData[105593] = {
	class = "PALADIN",
	talent = true,
	stun = true,
	replaces = 853,
	cooldown = 30
}
-- Hand of Purify
LCT_SpellData[114039] = {
	class = "PALADIN",
	talent = true,
	defensive = true,
	duration = 6,
	cooldown = 30
}
-- Holy Avenger
LCT_SpellData[105809] = {
	class = "PALADIN",
	talent = true,
	offensive = true,
	defensive = true,
	duration = 18,
	cooldown = 120
}
-- Holy Prism
LCT_SpellData[114165] = {
	class = "PALADIN",
	talent = true,
	offensive = true,
	heal = true,
	cooldown = 20
}
-- Light's Hammer
LCT_SpellData[114158] = {
	class = "PALADIN",
	talent = true,
	offensive = true,
	heal = true,
	duration = 16,
	cooldown = 60
}
-- Repentance
LCT_SpellData[20066] = {
	class = "PALADIN",
	talent = true,
	cc = true,
	cooldown = 15
}
-- Sacred Shield
LCT_SpellData[20925] = {
	class = "PALADIN",
	talent = true,
	defensive = true,
	duration = 30,
	cooldown = 6
}
-- Speed of Light
LCT_SpellData[85499] = {
	class = "PALADIN",
	talent = true,
	duration = 8,
	cooldown = 45
}

-- Paladin/Holy
-- Divine Favor
LCT_SpellData[31842] = {
	class = "PALADIN",
	specID = { 65 },
	defensive = true,
	duration = 20,
	cooldown = 180
}
-- Divine Plea
LCT_SpellData[54428] = {
	class = "PALADIN",
	specID = { 65 },
	duration = 9,
	cooldown = 120
}
-- Guardian of Ancient Kings
LCT_SpellData[86669] = {
	class = "PALADIN",
	specID = { 65 },
	heal = true,
	duration = 30,
	cooldown = 180
}
-- Holy Shock
LCT_SpellData[20473] = {
	class = "PALADIN",
	specID = { 65 },
	offensive = true,
	heal = true,
	cooldown = 6
}

-- Paladin/Protection
-- Ardent Defender
LCT_SpellData[31850] = {
	class = "PALADIN",
	specID = { 66 },
	defensive = true,
	duration = 10,
	cooldown = 180
}
-- Avenger's Shield
LCT_SpellData[31935] = {
	class = "PALADIN",
	specID = { 66 },
	silence = true,
	interrupt = true,
	cooldown = 15
}
-- Consecration
LCT_SpellData[26573] = {
	class = "PALADIN",
	specID = { 66 },
	offensive = true,
	duration = 9,
	cooldown = 9
}
-- Guardian of Ancient Kings
LCT_SpellData[86659] = {
	class = "PALADIN",
	specID = { 66 },
	duration = 12,
	defensive = true,
	cooldown = 180
}
-- Holy Wrath
LCT_SpellData[119072] = {
	class = "PALADIN",
	specID = { 66 },
	offensive = true,
	cooldown = 9
}
-- Symbiosis/Barkskin
LCT_SpellData[113075] = {
	class = "PALADIN",
	specID = { 66 },
	requires_aura = 110484,
	defensive = true,
	duration = 6,
	cooldown = 60
}

-- Paladin/Retribution
-- Exorcism
LCT_SpellData[879] = {
	class = "PALADIN",
	specID = { 70 },
	offensive = true,
	cooldown = 15
}
-- Guardian of Ancient Kings
LCT_SpellData[86698] = {
	class = "PALADIN",
	specID = { 70 },
	offensive = true,
	duration = 30,
	cooldown = 180
}
