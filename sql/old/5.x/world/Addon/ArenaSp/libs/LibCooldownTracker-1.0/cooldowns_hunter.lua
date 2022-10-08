-- ================ HUNTER ================
-- Hunter/baseline
-- Concussive Shot
LCT_SpellData[5116] = {
	class = "HUNTER",
	cc = true,
	cooldown = 5
}
-- Disengage
LCT_SpellData[781] = {
	class = "HUNTER",
	defensive = true,
	cooldown = 20
}
-- Scatter Shot
LCT_SpellData[19503] = {
	class = "HUNTER",
	cc = true,
	cooldown = 30
}
-- Freezing Trap
LCT_SpellData[1499] = {
	class = "HUNTER",
	cc = true,
	cooldown = 28
}
-- Kill Shot
LCT_SpellData[53351] = {
	class = "HUNTER",
	offensive = true,
	cooldown = 10
}
-- Explosive Trap
LCT_SpellData[13813] = {
	class = "HUNTER",
	offensive = true,
	sets_cooldown = { spellid = 3674, cooldown = 28 }, -- Black Arrow
	cooldown = 28
}
-- Flare
LCT_SpellData[1543] = {
	class = "HUNTER",
	none = true,
	cooldown = 20
}
-- Ice Trap
LCT_SpellData[13809] = {
	class = "HUNTER",
	cc = true,
	cooldown = 28
}
-- Rapid Fire
LCT_SpellData[3045] = {
	class = "HUNTER",
	offensive = true,
	duration = 15,
	cooldown = 180
}
-- Snake Trap
LCT_SpellData[34600] = {
	class = "HUNTER",
	offensive = true,
	cooldown = 28
}
-- Master's Call
LCT_SpellData[53271] = {
	class = "HUNTER",
	defensive = true,
	duration = 4,
	cooldown = 45
}
-- Deterrence
LCT_SpellData[19263] = {
	class = "HUNTER",
	defensive = true,
	duration = 5,
	charges = 2,
	cooldown = 180
}
-- Camouflage
LCT_SpellData[51753] = {
	class = "HUNTER",
	defensive = true,
	duration = 6,
	cooldown = 60
}
-- Stampede
LCT_SpellData[121818] = {
	class = "HUNTER",
	offensive = true,
	duration = 20,
	cooldown = 300
}

-- Hunter/talent
-- Binding Shot
LCT_SpellData[109248] = {
	class = "HUNTER",
	talent = true,
	cc = true,
	cooldown = 45
}
-- Wyvern Sting
LCT_SpellData[19386] = {
	class = "HUNTER",
	talent = true,
	cc = true,
	cooldown = 45
}
-- Exhilaration
LCT_SpellData[109304] = {
	class = "HUNTER",
	talent = true,
	heal = true,
	cooldown = 120
}
-- Dire Beast
LCT_SpellData[120679] = {
	class = "HUNTER",
	talent = true,
	offensive = true,
	duration = 15,
	cooldown = 30
}
-- Fervor
LCT_SpellData[82726] = {
	class = "HUNTER",
	talent = true,
	offensive = true,
	duration = 10,
	cooldown = 30
}
-- A Murder of Crows
LCT_SpellData[131894] = {
	class = "HUNTER",
	talent = true,
	offensive = true,
	duration = 30,
	cooldown = 120
}
-- Blink Strike
LCT_SpellData[130392] = {
	class = "HUNTER",
	talent = true,
	offensive = true,
	cooldown = 20
}
-- Lynx Rush
LCT_SpellData[120697] = {
	class = "HUNTER",
	talent = true,
	offensive = true,
	cooldown = 90
}
-- Barrage
LCT_SpellData[120360] = {
	class = "HUNTER",
	talent = true,
	offensive = true,
	duration = 3,
	cooldown = 30
}
-- Glaive Toss
LCT_SpellData[117050] = {
	class = "HUNTER",
	talent = true,
	offensive = true,
	cc = true,
	cooldown = 15
}
-- Powershot
LCT_SpellData[109259] = {
	class = "HUNTER",
	talent = true,
	offensive = true,
	knockback = true,
	cooldown = 45
}
-- Intimidation
LCT_SpellData[19577] = {
	class = "HUNTER",
	talent = true,
	stun = true,
	cooldown = 60
}

-- Hunter/253 - Beast Mastery
-- Kill Command
LCT_SpellData[34026] = {
	class = "HUNTER",
	specID = { 253 },
	offensive = true,
	cooldown = 6
}
-- Bestial Wrath
LCT_SpellData[19574] = {
	class = "HUNTER",
	specID = { 253 },
	offensive = true,
	duration = 10,
	cooldown = 60
}
-- Symbiosis/Dash
LCT_SpellData[113073] = {
	class = "HUNTER",
	specID = { 253, 254, 255 },
	requires_aura = 110479,
	duration = 15,
	cooldown = 180
}

-- Hunter/254 - Marksmanship
-- Chimera Shot
LCT_SpellData[53209] = {
	class = "HUNTER",
	specID = { 254 },
	offensive = true,
	cooldown = 9
}
-- Silencing Shot
LCT_SpellData[34490] = {
	class = "HUNTER",
	specID = { 254 },
	interrupt = true,
	cooldown = 24
}

-- Hunter/255 - Survival
-- Explosive Shot
LCT_SpellData[53301] = {
	class = "HUNTER",
	specID = { 255 },
	offensive = true,
	cooldown = 6
}
-- Black Arrow
LCT_SpellData[3674] = {
	class = "HUNTER",
	specID = { 255 },
	offensive = true,
	sets_cooldown = { spellid = 13813, cooldown = 28 }, -- Explosive Trap
	cooldown = 28
}

-- Pet/Basic
-- Cower
LCT_SpellData[1742] = {
	class = "HUNTER",
	pet = true,
	defensive = true,
	duration = 6,
	cooldown = 45
}

-- Pet/Ferocity
-- Rabid
LCT_SpellData[53401] = {
	class = "HUNTER",
	pet = true,
	offensive = true,
	duration = 20,
	cooldown = 90
}
-- Heart of the Phoenix
LCT_SpellData[55709] = {
	class = "HUNTER",
	pet = true,
	defensive = true,
	cooldown = 480
}
-- Dash
LCT_SpellData[61684] = {
	class = "HUNTER",
	pet = true,
	duration = 16,
	cooldown = 32
}

-- Pet/Tenacity
-- Last Stand
LCT_SpellData[53478] = {
	class = "HUNTER",
	pet = true,
	defensive = true,
	duration = 20,
	cooldown = 360
}
-- Charge
LCT_SpellData[61685] = {
	class = "HUNTER",
	pet = true,
	offensive = true,
	cooldown = 25
}
-- Thunderstomp
LCT_SpellData[63900] = {
	class = "HUNTER",
	pet = true,
	offensive = true,
	cooldown = 10
}

-- Pet/Cunning
-- Roar of Sacrifice
LCT_SpellData[53480] = {
	class = "HUNTER",
	pet = true,
	defensive = true,
	duration = 12,
	cooldown = 60
}
-- Bullheaded
LCT_SpellData[53490] = {
	class = "HUNTER",
	pet = true,
	defensive = true,
	duration = 12,
	cooldown = 180
}
-- Dash


-- Pet/Specific
-- Pin
LCT_SpellData[50245] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 40
}
-- Dust Cloud
LCT_SpellData[50285] = {
	class = "HUNTER",
	pet = true,
	offensive = true,
	cooldown = 25
}
-- Clench
LCT_SpellData[50541] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 60
}
-- Petrifying Gaze
LCT_SpellData[126423] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	duration = 3,
	cooldown = 120
}
-- Reflective Armor Plating
LCT_SpellData[137798] = {
	class = "HUNTER",
	pet = true,
	defensive = true,
	duration = 6,
	cooldown = 30
}
-- Lightning Breath
LCT_SpellData[24844] = {
	class = "HUNTER",
	pet = true,
	offensive = true,
	cooldown = 30
}
-- Shell Shield
LCT_SpellData[26064] = {
	class = "HUNTER",
	pet = true,
	defensive = true,
	duration = 12,
	cooldown = 60
}
-- Fire Breath
LCT_SpellData[34889] = {
	class = "HUNTER",
	pet = true,
	offensive = true,
	cooldown = 30
}
-- Time Warp
LCT_SpellData[35346] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 15
}
-- Web
LCT_SpellData[4167] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 40
}
-- Ankle Crack
LCT_SpellData[50433] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 10
}
-- Nether Shock
LCT_SpellData[50479] = {
	class = "HUNTER",
	pet = true,
	interrupt = true,
	cooldown = 40
}
-- Sonic Blast
LCT_SpellData[50519] = {
	class = "HUNTER",
	pet = true,
	stun = true,
	cooldown = 120
}
-- Lock Jaw
LCT_SpellData[90327] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 40
}
-- Harden Carapace
LCT_SpellData[90339] = {
	class = "HUNTER",
	pet = true,
	defensive = true,
	duration = 12,
	cooldown = 60
}
-- Trample
LCT_SpellData[126402] = {
	class = "HUNTER",
	pet = true,
	offensive = true,
	cooldown = 10
}
-- Pummel
LCT_SpellData[26090] = {
	class = "HUNTER",
	pet = true,
	interrupt = true,
	cooldown = 30
}
-- Serenity Dust
LCT_SpellData[50318] = {
	class = "HUNTER",
	pet = true,
	interrupt = true,
	cooldown = 60
}
-- Sting
LCT_SpellData[56626] = {
	class = "HUNTER",
	pet = true,
	stun = true,
	cooldown = 90
}
-- Bad Manner
LCT_SpellData[90337] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 120
}
-- Paralyzing Quill
LCT_SpellData[126355] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 120
}
-- Venom Web Spray
LCT_SpellData[54706] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 40
}
-- Snatch
LCT_SpellData[91644] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 60
}
-- Eternal Guardian
LCT_SpellData[126393] = {
	class = "HUNTER",
	pet = true,
	res = true,
	cooldown = 600
}
-- Frost Breath
LCT_SpellData[54644] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 10
}
-- Burrow Attack
LCT_SpellData[93433] = {
	class = "HUNTER",
	pet = true,
	offensive = true,
	duration = 8,
	cooldown = 14
}
-- Tailspin
LCT_SpellData[90314] = {
	class = "HUNTER",
	pet = true,
	offensive = true,
	cooldown = 10
}
--[[
-- Ancient Hysteria
LCT_SpellData[90355] = {
	class = "HUNTER",
	pet = true,
	offensive = true,
	duration = 40,
	cooldown = 360
}
]]
-- Lava Breath
LCT_SpellData[58604] = {
	class = "HUNTER",
	pet = true,
	cooldown = 8
}
-- Web Wrap
LCT_SpellData[96201] = {
	class = "HUNTER",
	pet = true,
	stun = true,
	cooldown = 90
}
-- Lullaby
LCT_SpellData[126246] = {
	class = "HUNTER",
	pet = true,
	cc = true,
	cooldown = 120
}
-- Spore Cloud
LCT_SpellData[50274] = {
	class = "HUNTER",
	pet = true,
	cooldown = 8
}
-- Horn Toss
LCT_SpellData[93434] = {
	class = "HUNTER",
	pet = true,
	knockback = true,
	cooldown = 90
}
-- Spirit Mend
LCT_SpellData[90361] = {
	class = "HUNTER",
	pet = true,
	heal = true,
	cooldown = 30
}
