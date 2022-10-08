-- ================ DRUID ================
-- Druid/baseline
-- Barkskin
LCT_SpellData[22812] = {
	class = "DRUID",
	defensive = true,
	duration = 12,
	cooldown = 60
}
-- Dash
LCT_SpellData[1850] = {
	class = "DRUID",
	duration = 15,
	cooldown = 180
}
-- Innervate
LCT_SpellData[29166] = {
	class = "DRUID",
	duration = 10,
	cooldown = 180
}
-- Might of the Ursoc
LCT_SpellData[106922] = {
	class = "DRUID",
	defensive = true,
	duration = 20,
	cooldown = 180
}
-- Nature's Grasp
LCT_SpellData[16689] = {
	class = "DRUID",
	cc = true,
	duration = 45,
	cooldown = 60
}
-- Stampeding Roar
LCT_SpellData[77761] = {
	class = "DRUID",
	duration = 8,
	cooldown = 120
}
LCT_SpellData[77764] = 77761
LCT_SpellData[106898] = 77761
-- Tranquility
LCT_SpellData[740] = {
	class = "DRUID",
	heal = true,
	duration = 8,
	cooldown = 480
}

-- Druid/talents
-- Cenarion Ward
LCT_SpellData[102351] = {
	class = "DRUID",
	talent = true,
	heal = true,
	duration = 30,
	cooldown = 30
}
-- Disorienting Roar
LCT_SpellData[99] = {
	class = "DRUID",
	talent = true,
	cc = true,
	cooldown = 30
}
-- Displacer Beast
LCT_SpellData[102280] = {
	class = "DRUID",
	talent = true,
	cooldown = 30
}
-- Wild Charge
LCT_SpellData[102401] = {
	class = "DRUID",
	talent = true,
	cooldown = 15
}
LCT_SpellData[16979] = 102401 -- Bear
LCT_SpellData[49376] = 102401 -- Cat
LCT_SpellData[102416] = 102401 -- Aquatic
LCT_SpellData[102417] = 102401 -- Travel
LCT_SpellData[102383] = 102401 -- Moonkin
-- Force of Nature
LCT_SpellData[106737] = {
	class = "DRUID",
	talent = true,
	offensive = true,
	charges = 3,
	cooldown = 20
}
LCT_SpellData[102706] = 106737 -- Guardian
LCT_SpellData[102703] = 106737 -- Feral
LCT_SpellData[102693] = 106737 -- Restoration
LCT_SpellData[33831] = 106737 -- Balance
-- Incarnation
LCT_SpellData[106731] = {
	class = "DRUID",
	talent = true,
	offensive = true,
	defensive = true,
	duration = 30,
	cooldown = 180
}
LCT_SpellData[102558] = 106731 -- Guardian
LCT_SpellData[102543] = 106731 -- Feral
LCT_SpellData[33891] = 106731 -- Restoration
LCT_SpellData[102560] = 106731 -- Balance
-- Heart of the Wild
LCT_SpellData[108288] = {
	class = "DRUID",
	talent = true,
	offensive = true,
	defensive = true,
	duration = 45,
	cooldown = 360
}
LCT_SpellData[108291] = 108288
LCT_SpellData[108292] = 108288
LCT_SpellData[108293] = 108288
LCT_SpellData[108294] = 108288
-- Mass Entanglement
LCT_SpellData[102359] = {
	class = "DRUID",
	talent = true,
	cc = true,
	cooldown = 30
}
-- Mighty Bash
LCT_SpellData[5211] = {
	class = "DRUID",
	talent = true,
	stun = true,
	cooldown = 50
}
-- Nature's Swiftness
LCT_SpellData[132158] = {
	class = "DRUID",
	talent = true,
	heal = true,
	cooldown_starts_on_aura_fade = true,
	cooldown = 60
}
-- Nature's Vigil
LCT_SpellData[124974] = {
	class = "DRUID",
	talent = true,
	offensive = true,
	defensive = true,
	duration = 30,
	cooldown = 90
}
-- Renewal
LCT_SpellData[108238] = {
	class = "DRUID",
	talent = true,
	heal = true,
	cooldown = 120
}
-- Typhoon
LCT_SpellData[132469] = {
	class = "DRUID",
	talent = true,
	knockback = true,
	cooldown = 30
}
-- Ursol's Vortex
LCT_SpellData[102793] = {
	class = "DRUID",
	talent = true,
	cc = true,
	cooldown = 60
}

-- Druid/Balance
-- Celestial Alignment
LCT_SpellData[112071] = {
	class = "DRUID",
	specID = { 102 },
	offensive = true,
	duration = 15,
	cooldown = 180
}
-- Remove Corruption
LCT_SpellData[2782] = {
	class = "DRUID",
	specID = { 102, 103, 104 },
	dispel = true,
	cooldown_starts_on_dispel = true,
	cooldown = 8
}
-- Solar Beam
LCT_SpellData[78675] = {
	class = "DRUID",
	specID = { 102 },
	interrupt = true,
	silence = true,
	duration = 10,
	cooldown = 60
}
-- Starfall
LCT_SpellData[48505] = {
	class = "DRUID",
	specID = { 102 },
	offensive = true,
	duration = 10,
	cooldown = 90
}
-- Starsurge
LCT_SpellData[78674] = {
	class = "DRUID",
	specID = { 102 },
	offensive = true,
	cooldown = 15
}
-- Wild Mushroom: Detonate
LCT_SpellData[88751] = {
	class = "DRUID",
	specID = { 102 },
	offensive = true,
	cooldown = 10
}

-- Symbiosis/Anti-Magic Shell
LCT_SpellData[110570] = {
	class = "DRUID",
	specID = { 102 },
	symbiosis = true,
	defensive = true,
	duration = 5,
	cooldown = 45
}
-- Symbiosis/Mirror Image
LCT_SpellData[110621] = {
	class = "DRUID",
	specID = { 102 },
	symbiosis = true,
	offensive = true,
	duration = 30,
	cooldown = 180
}
-- Symbiosis/Grapple Weapon
LCT_SpellData[126458] = {
	class = "DRUID",
	specID = { 102 },
	symbiosis = true,
	cc = true,
	duration = 8,
	cooldown = 60
}
-- Symbiosis/Hammer of Justice
LCT_SpellData[110698] = {
	class = "DRUID",
	specID = { 102 },
	symbiosis = true,
	stun = true,
	cooldown = 60
}
-- Symbiosis/Mass Dispel
LCT_SpellData[110707] = {
	class = "DRUID",
	specID = { 102 },
	symbiosis = true,
	mass_dispel = true,
	cooldown = 60
}
-- Symbiosis/Cloak of Shadows
LCT_SpellData[110788] = {
	class = "DRUID",
	specID = { 102 },
	symbiosis = true,
	defensive = true,
	duration = 5,
	cooldown = 120
}
-- Symbiosis/Unending Resolve
LCT_SpellData[122291] = {
	class = "DRUID",
	specID = { 102 },
	symbiosis = true,
	defensive = true,
	duration = 12,
	cooldown = 180
}
-- Symbiosis/Intervene
LCT_SpellData[122292] = {
	class = "DRUID",
	specID = { 102 },
	symbiosis = true,
	defensive = true,
	duration = 10,
	cooldown = 30
}

-- Druid/Feral
-- Berserk (Cat Form)
LCT_SpellData[106951] = {
	class = "DRUID",
	specID = { 103, 104 },
	offensive = true,
	sets_cooldown = { spellid = 50334, cooldown = 180 },
	duration = 15,
	cooldown = 180
}
-- Berserk (Bear Form)
LCT_SpellData[50334] = {
	class = "DRUID",
	specID = { 103, 104 },
	offensive = true,
	sets_cooldown = { spellid = 106951, cooldown = 180 },
	duration = 10,
	cooldown = 180
}
-- Skull Bash
LCT_SpellData[80964] = {
	class = "DRUID",
	specID = { 103, 104 },
	interrupt = true,
	cooldown = 15
}
LCT_SpellData[80965] = 80964
-- Tiger's Fury
LCT_SpellData[5217] = {
	class = "DRUID",
	specID = { 103 },
	offensive = true,
	duration = 6,
	cooldown = 30
}
-- Symbiosis/Play Dead
LCT_SpellData[110597] = {
	class = "DRUID",
	specID = { 103 },
	symbiosis = true,
	defensive = true,
	cooldown = 30
}
-- Symbiosis/Frost Nova
LCT_SpellData[110693] = {
	class = "DRUID",
	specID = { 103 },
	symbiosis = true,
	cc = true,
	cooldown = 25
}
-- Symbiosis/Clash
LCT_SpellData[126449] = {
	class = "DRUID",
	specID = { 103 },
	symbiosis = true,
	stun = true,
	cooldown = 35
}
-- Symbiosis/Divine Shield
LCT_SpellData[110700] = {
	class = "DRUID",
	specID = { 103 },
	symbiosis = true,
	immune = true,
	duration = 8,
	cooldown = 300
}
-- Symbiosis/Dispersion
LCT_SpellData[110715] = {
	class = "DRUID",
	specID = { 103 },
	symbiosis = true,
	defensive = true,
	duration = 6,
	cooldown = 180
}
-- Symbiosis/Redirect
LCT_SpellData[110730] = {
	class = "DRUID",
	specID = { 103 },
	symbiosis = true,
	offensive = true,
	cooldown = 60
}
-- Symbiosis/Feral Spirit
LCT_SpellData[110807] = {
	class = "DRUID",
	specID = { 103 },
	symbiosis = true,
	offensive = true,
	duration = 30,
	cooldown = 120
}
-- Symbiosis/Soul Swap
LCT_SpellData[110810] = {
	class = "DRUID",
	specID = { 103 },
	symbiosis = true,
	offensive = true,
	cooldown = 30
}
-- Symbiosis/Shattering Blow
LCT_SpellData[112997] = {
	class = "DRUID",
	specID = { 103 },
	symbiosis = true,
	mass_dispel = true,
	offensive = true,
	cooldown = 300
}


-- Druid/Guardian
-- Bear Hug
LCT_SpellData[102795] = {
	class = "DRUID",
	specID = { 104 },
	stun = true,
	duration = 3,
	cooldown = 60
}
-- Enrage
LCT_SpellData[5229] = {
	class = "DRUID",
	specID = { 104 },
	duration = 10,
	cooldown = 60
}
-- Savage Defense
LCT_SpellData[62606] = {
	class = "DRUID",
	specID = { 104 },
	charges = 3,
	defensive = true,
	duration = 6,
	cooldown = 9
}
-- Survival Instincts
LCT_SpellData[61336] = {
	class = "DRUID",
	specID = { 103, 104 },
	defensive = true,
	duration = 12,
	cooldown = 180
}
-- Symbiosis/Bone Shield
LCT_SpellData[122285] = {
	class = "DRUID",
	specID = { 104 },
	symbiosis = true,
	defensive = true,
	cooldown = 60
}
-- Symbiosis/Consecration
LCT_SpellData[110701] = {
	class = "DRUID",
	specID = { 104 },
	symbiosis = true,
	offensive = true,
	duration = 10,
	cooldown = 30
}
-- Symbiosis/Fear Ward
LCT_SpellData[110717] = {
	class = "DRUID",
	specID = { 104 },
	symbiosis = true,
	defensive = true,
	cooldown = 180
}
-- Symbiosis/Life Tap
LCT_SpellData[122290] = {
	class = "DRUID",
	specID = { 104 },
	symbiosis = true,
	offensive = true,
	cooldown = 15
}
-- Symbiosis/Spell Reflection
LCT_SpellData[113002] = {
	class = "DRUID",
	specID = { 104 },
	symbiosis = true,
	defensive = true,
	duration = 5,
	cooldown = 120
}

-- Druid/Restoration
-- Ironbark
LCT_SpellData[102342] = {
	class = "DRUID",
	specID = { 105 },
	defensive = true,
	duration = 12,
	cooldown = 30
}
-- Nature's Cure
LCT_SpellData[88423] = {
	class = "DRUID",
	specID = { 105 },
	dispel = true,
	cooldown_starts_on_dispel = true,
	cooldown = 8
}
-- Swiftmend
LCT_SpellData[18562] = {
	class = "DRUID",
	specID = { 105 },
	heal = true,
	cooldown = 13
}
-- Wild Growth
LCT_SpellData[48438] = {
	class = "DRUID",
	specID = { 105 },
	heal = true,
	cooldown = 8
}
-- Symbiosis/Icebound Fortitude
LCT_SpellData[110575] = {
	class = "DRUID",
	specID = { 105 },
	symbiosis = true,
	defensive = true,
	duration = 12,
	cooldown = 180
}
-- Symbiosis/Deterrence
LCT_SpellData[110617] = {
	class = "DRUID",
	specID = { 105 },
	symbiosis = true,
	defensive = true,
	duration = 5,
	cooldown = 120
}
-- Symbiosis/Ice Block
LCT_SpellData[110696] = {
	class = "DRUID",
	specID = { 105 },
	symbiosis = true,
	immune = true,
	duration = 10,
	cooldown = 300
}
-- Symbiosis/Fortifying Brew
LCT_SpellData[126456] = {
	class = "DRUID",
	specID = { 105 },
	symbiosis = true,
	defensive = true,
	duration = 20,
	cooldown = 180
}
-- Symbiosis/Cleanse
LCT_SpellData[122288] = {
	class = "DRUID",
	specID = { 105 },
	symbiosis = true,
	dispel = true,
	cooldown_starts_on_dispel = true,
	cooldown = 8
}
-- Symbiosis/Leap of Faith
LCT_SpellData[110718] = {
	class = "DRUID",
	specID = { 105 },
	symbiosis = true,
	defensive = true,
	cooldown = 90
}
-- Symbiosis/Evasion
LCT_SpellData[110791] = {
	class = "DRUID",
	specID = { 105 },
	symbiosis = true,
	defensive = true,
	duration = 15,
	cooldown = 180
}
-- Symbiosis/Spiritwalker's Grace
LCT_SpellData[110806] = {
	class = "DRUID",
	specID = { 105 },
	symbiosis = true,
	defensive = true,
	offensive = true,
	duration = 15,
	cooldown = 120
}
-- Symbiosis/Demonic Circle: Teleport
LCT_SpellData[112970] = {
	class = "DRUID",
	specID = { 105 },
	symbiosis = true,
	cooldown = 30
}
-- Symbiosis/Intimidating Roar
LCT_SpellData[113004] = {
	class = "DRUID",
	specID = { 105 },
	symbiosis = true,
	cc = true,
	cooldown = 90
}
