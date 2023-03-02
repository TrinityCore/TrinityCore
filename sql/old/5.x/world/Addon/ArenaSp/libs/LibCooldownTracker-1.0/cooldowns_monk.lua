-- ================ MONK ================
-- Monk/baseline

-- Roll
LCT_SpellData[109132] = {
	class = "MONK",
	charges = 2,
	cooldown = 20,
}
-- Roll (Celerity)
LCT_SpellData[121827] = {
	class = "MONK",
	talent = true,
	replaces = 109132,
	charges = 3,
	cooldown = 15,
}
-- Chii Torpedo
LCT_SpellData[115008] = 109132
-- Chii Torpedo (Celerity)
LCT_SpellData[121828] = 121827
-- Detox
LCT_SpellData[115450] = {
	class = "MONK",
	dispel = true,
	cooldown_starts_on_dispel = true,
	cooldown = 8,
}
-- Expel Harm
LCT_SpellData[115072] = {
	class = "MONK",
	heal = true,
	offensive = true,
	cooldown = 15,
}
-- Fortifying Brew
LCT_SpellData[115203] = {
	class = "MONK",
	defensive = true,
	duration = 20,
	cooldown = 180,
}
-- Grapple Weapon
LCT_SpellData[117368] = {
	class = "MONK",
	disarm = true,
	cc = true,
	cooldown = 60,
}
-- Paralysis
LCT_SpellData[115078] = {
	class = "MONK",
	cc = true,
	cooldown = 15,
}
-- Spear Hand Strike
LCT_SpellData[116705] = {
	class = "MONK",
	interrupt = true,
	silence = true,
	cooldown = 15,
}
-- Touch of Death
LCT_SpellData[115080] = {
	class = "MONK",
	offensive = true,
	cooldown = 90,
}
-- Transcendence
LCT_SpellData[101643] = {
	class = "MONK",
	cooldown = 45,
}
-- Transcendence: Transfer
LCT_SpellData[119996] = {
	class = "MONK",
	cooldown = 25,
}
-- Zen Meditation
LCT_SpellData[115176] = {
	class = "MONK",
	defensive = true,
	duration = 8,
	cooldown = 180,
}
-- Nimble Brew
LCT_SpellData[137562] = {
	class = "MONK",
	defensive = true,
	duration = 6,
	cooldown = 120,
}

-- Monk/talents
-- Charging Ox Wave
LCT_SpellData[119392] = {
	class = "MONK",
	talent = true,
	stun = true,
	cooldown = 30,
}
-- Chi Brew
LCT_SpellData[115399] = {
	class = "MONK",
	talent = true,
	charges = 2,
	cooldown = 45
}
-- Chi Wave
LCT_SpellData[115098] = {
	class = "MONK",
	talent = true,
	cooldown = 15
}
-- Dampen Harm
LCT_SpellData[122278] = {
	class = "MONK",
	talent = true,
	defensive = true,
	duration = 45,
	cooldown = 90,
}
-- Diffuse Magic
LCT_SpellData[122783] = {
	class = "MONK",
	talent = true,
	defensive = true,
	duration = 6,
	cooldown = 90
}
-- Invoke Xuen, the White
LCT_SpellData[123904] = {
	class = "MONK",
	talent = true,
	duration = 45,
	cooldown = 180
}
-- Leg Sweep
LCT_SpellData[119381] = {
	class = "MONK",
	talent = true,
	stun = true,
	cooldown = 45
}
-- Ring of Peace
LCT_SpellData[116844] = {
	class = "MONK",
	talent = true,
	defensive = true,
	duration = 8,
	cooldown = 45
}
-- Rushing Jade Wind
LCT_SpellData[116847] = {
	class = "MONK",
	talent = true,
	offensive = true,
	cooldown = 6,
}
-- Tiger's Lust
LCT_SpellData[116841] = {
	class = "MONK",
	talent = true,
	defensive = true,
	duration = 6,
	cooldown = 30,
}

-- Monk/Brewmaster
-- Avert Harm
LCT_SpellData[115213] = {
	class = "MONK",
	specID = { 268 },
	defensive = true,
	duration = 6,
	cooldown = 180
}
-- Clash
LCT_SpellData[122057] = {
	class = "MONK",
	specID = { 268 },
	cooldown = 35
}
-- Elusive Brew
LCT_SpellData[115308] = {
	class = "MONK",
	specID = { 268 },
	defensive = true,
	duration = 3,
	cooldown = 6,
}
-- Guard
LCT_SpellData[115295] = {
	class = "MONK",
	specID = { 268 },
	defensive = true,
	duration = 30,
	cooldown = 30
}
-- Keg Smash
LCT_SpellData[121253] = {
	class = "MONK",
	specID = { 268 },
	offensive = true,
	cooldown = 8
}
-- Summon Black Ox
LCT_SpellData[115315] = {
	class = "MONK",
	specID = { 268 },
	cooldown = 30
}
-- Symbiosis/Survival Instincts
LCT_SpellData[113306] = {
	class = "MONK",
	specID = { 268 },
	requires_aura = 110483,
	defensive = true,
	duration = 6,
	cooldown = 180
}

-- Monk/Windwalker
-- Energizing Brew
LCT_SpellData[115288] = {
	class = "MONK",
	specID = { 269 },
	offensive = true,
	duration = 6,
	cooldown = 60,
}
-- Fists of Fury
LCT_SpellData[113656] = {
	class = "MONK",
	specID = { 269 },
	offensive = true,
	duration = 4,
	cooldown = 25,
}
-- Flying Serpent Kick
LCT_SpellData[101545] = {
	class = "MONK",
	specID = { 269 },
	cooldown = 25,

}
-- Rising Sun Kick
LCT_SpellData[107428] = {
	class = "MONK",
	specID = { 269 },
	offensive = true,
	cooldown = 8,

}
-- Touch of Karma
LCT_SpellData[122470] = {
	class = "MONK",
	specID = { 269 },
	offensive = true,
	defensive = true,
	duration = 10,
	cooldown = 90
}
-- Symbiosis/Bear Hug
LCT_SpellData[127361] = {
	class = "MONK",
	specID = { 269 },
	requires_aura = 110483,
	cc = true,
	offensive = true,
	duration = 3,
	cooldown = 60
}

-- Monk/Mistweaver
-- Life Cocoon
LCT_SpellData[116849] = {
	class = "MONK",
	specID = { 270 },
	heal = true,
	duration = 12,
	cooldown = 120,
}
-- Renewing Misg
LCT_SpellData[115151] = {
	class = "MONK",
	specID = { 270 },
	heal = true,
	cooldown = 8
}
-- Revival
LCT_SpellData[115310] = {
	class = "MONK",
	specID = { 270 },
	mass_dispel = true,
	cooldown = 180
}
-- Summon Jade Serpent
LCT_SpellData[115313] = {
	class = "MONK",
	specID = { 270 },
	heal = true,
	cooldown = 30
}
-- Thunder Focus Tea
LCT_SpellData[116680] = {
	class = "MONK",
	specID = { 270 },
	heal = true,
	duration = 30,
	cooldown = 45
}
