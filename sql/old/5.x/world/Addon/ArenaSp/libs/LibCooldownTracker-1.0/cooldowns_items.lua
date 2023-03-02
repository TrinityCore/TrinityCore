-- Items
-- PvP Trinket
LCT_SpellData[42292] = {
	item = true,
	pvp_trinket = true,
	icon_alliance = [[Interface\Icons\INV_Jewelry_TrinketPVP_01]],
	icon_horde = [[Interface\Icons\INV_Jewelry_TrinketPVP_02]],
	sets_cooldown = { spellid = 7744, cooldown = 30 }, -- WotF
	cooldown = 120,
}
-- Healthstone
LCT_SpellData[6262] = {
	item = true,
	talent = true, -- hack to prevent it being displayed before being detected
	heal = true,
	cooldown = 120
}