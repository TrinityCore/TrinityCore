-- ----------------------------------
-- -- Class Trainers for Cataclysm -- 
-- ----------------------------------
SET @Warrior := 200001;
SET @Paladin := 200002;
SET @Hunter := 200003;
SET @Rogue := 200004;
SET @Priest := 200005;
SET @DeathKnight := 200006;
SET @Shaman := 200007;
SET @Mage := 200008;
SET @Warlock := 200009;
SET @Druid := 200011;
DELETE FROM `npc_trainer` WHERE `entry` IN ( @Warrior,@Paladin,@Hunter,@Rogue,@Priest,@DeathKnight,@Shaman,@Mage,@Warlock,@Druid);
INSERT INTO `npc_trainer` (`entry`,`spell`,`spellcost`,`reqskill`,`reqskillvalue`,`reqlevel`) VALUES
-- Warrior 42 spells
(@Warrior,100,60,0,0,3), -- Charge
(@Warrior,34428,142,0,0,5), -- Victory Rush
(@Warrior,772,285,0,0,7), -- Rend
(@Warrior,6343,552,0,0,9), -- Thunder Clap
(@Warrior,71,680,0,0,10), -- Defensive Stance
(@Warrior,3127,680,0,0,10), -- Parry
(@Warrior,355,1076,0,0,12), -- Taunt
(@Warrior,78,1418,0,0,14), -- Heroic Strike
(@Warrior,5308,2060,0,0,16), -- Execute
(@Warrior,7386,2785,0,0,18), -- Sunder Armor
(@Warrior,6673,3600,0,0,20), -- Battle Shout
(@Warrior,57755,3600,0,0,20), -- Heroic Throw
(@Warrior,7384,4200,0,0,22), -- Overpwoer
(@Warrior,845,5100,0,0,24), -- Cleave
(@Warrior,1715,6000,0,0,26), -- Hamstring
(@Warrior,2565,7500,0,0,28), -- Shield Block
(@Warrior,2458,7500,0,0,30), -- Berserker Stance
(@Warrior,676,10500,0,0,34), -- Disarm
(@Warrior,1680,12000,0,0,36), -- Whirlwind
(@Warrior,6552,13500,0,0,38), -- Pummel
(@Warrior,6572,15000,0,0,40), -- Revenge
(@Warrior,750,0,0,0,40), -- Plate Mail
(@Warrior,5246,16500,0,0,42), -- Intimidating Shout
(@Warrior,1464,19500,0,0,44), -- Slam
(@Warrior,1161,19500,0,0,46), -- Challenging Shout
(@Warrior,871,21000,0,0,48), -- Shield Wall
(@Warrior,20252,22500,0,0,50), -- Intercept
(@Warrior,87509,22500,0,0,50), -- Plate Specialization
(@Warrior,1160,22500,0,0,52), -- Demoralizing Shout
(@Warrior,18499,24000,0,0,54), -- Berserker Rage
(@Warrior,1134,25500,0,0,56), -- Inner Rage
(@Warrior,12678,27000,0,0,58), -- Stance Mastery
(@Warrior,20230,81000,0,0,62), -- Retaliation
(@Warrior,1719,93000,0,0,64), -- Recklessness
(@Warrior,23920,105000,0,0,66), -- Spell Reflection
(@Warrior,469,117000,0,0,68), -- Commanding Shout
(@Warrior,3411,150000,0,0,72), -- Intervene
(@Warrior,64382,168000,0,0,74), -- Shattering Throw
(@Warrior,55694,186000,0,0,76), -- Enraged Regeneration
(@Warrior,87500,222000,0,0,80), -- Mastery
(@Warrior,86346,234000,0,0,81), -- Colossus Smash
(@Warrior,97462,258000,0,0,83), -- Rallying Cry
(@Warrior,6544,282000,0,0,85), -- Heroic Leap
-- -----------------------------------------------------------------------------
-- -- Paladin 43 spells -- 
-- -----------------------------------------------------------------------------
(@Paladin,20271,60,0,0,3), -- Judgement
(@Paladin,20154,60,0,0,3), -- Seal of Righteousness
(@Paladin,465,142,0,0,5), -- Devotion Aura
(@Paladin,635,284,0,0,7), -- Holy Light
(@Paladin,85673,552,0,0,9), -- Word of Glory
(@Paladin,82242,680,0,0,10), -- Parry
(@Paladin,7328,1076,0,0,12), -- Redemption
(@Paladin,25780,1076,0,0,12), -- Righteous Fury
(@Paladin,853,1418,0,0,14), -- Hammer of Justice
(@Paladin,62124,1418,0,0,14), -- Hand of Reckoning
(@Paladin,19750,2060,0,0,16), -- Flash of Light
(@Paladin,633,2060,0,0,16), -- Lay on Hands
(@Paladin,879,2785,0,0,18), -- Exorcism
(@Paladin,1022,2785,0,0,18), -- Hand of Protection
(@Paladin,20217,4200,0,0,22), -- Blessing of Kings
(@Paladin,26573,5100,0,0,24), -- Consecration
(@Paladin,7294,6000,0,0,26), -- Retribution Aura
(@Paladin,2812,7500,0,0,28), -- Holy Wrath
(@Paladin,498,7500,0,0,30), -- Devine Protection
(@Paladin,20165,9000,0,0,32), -- Seal of Insight
(@Paladin,4987,10500,0,0,34), -- Cleanse
(@Paladin,31789,12000,0,0,36), -- Righteous Defence
(@Paladin,750,0,0,0,40), -- Plate Mail
(@Paladin,19746,16500,0,0,42), -- Concentration Aura
(@Paladin,54428,19500,0,0,44), -- Devine Plea
(@Paladin,31801,19500,0,0,44), -- Seal of Truth
(@Paladin,24275,19500,0,0,46), -- Hammer of Wrath
(@Paladin,642,21000,0,0,48), -- Devine Shield
(@Paladin,87511,22500,0,0,50), -- Plate Specialization
(@Paladin,1044,22500,0,0,52), -- Hand of Freedom
(@Paladin,96231,24000,0,0,54), -- Rebuke
(@Paladin,19740,25500,0,0,56), -- Blessing of Might
(@Paladin,32223,81000,0,0,62), -- Crusader Aura
(@Paladin,82326,81000,0,0,62), -- Devine Light
(@Paladin,20164,93000,0,0,64), -- Seal of Justice
(@Paladin,1038,105000,0,0,66), -- Hand of Salvation
(@Paladin,31884,150000,0,0,72), -- Avenging Wrath
(@Paladin,19891,186000,0,0,76), -- Resistance Aura
(@Paladin,10326,204000,0,0,78), -- Turn Evil
(@Paladin,6940,222000,0,0,80), -- Hand of Sacrifice
(@Paladin,87494,222000,0,0,80), -- Mastery
(@Paladin,84963,234000,0,0,81), -- Inquisition
(@Paladin,82327,258000,0,0,83), -- Holy Radiance
(@Paladin,86150,282000,0,0,85), -- Guardian of Ancient Kings
-- -----------------------------------------------------------------------------
-- -- Hunter 56 Spells -- 
-- -----------------------------------------------------------------------------
(@Hunter,56641,60,0,0,3), -- Steady Shot
(@Hunter,1494,97,0,0,4), -- Track Beasts
(@Hunter,2973,190,0,0,6), -- Raptor Strike
(@Hunter,5116,390,0,0,8), -- Concussive Shot
(@Hunter,82243,390,0,0,8), -- Parry
(@Hunter,1462,680,0,0,10), -- Beast Lore
(@Hunter,79682,110,0,0,10), -- Control Pet
(@Hunter,2641,110,0,0,10), -- Dismiss Pet
(@Hunter,6991,110,0,0,10), -- Feed Pet
(@Hunter,34026,680,0,0,10), -- Kill Command
(@Hunter,1978,1076,0,0,10), -- Serpent Sting
(@Hunter,1515,680,0,0,10), -- Tame Beast
(@Hunter,13165,1076,0,0,12), -- Aspect of the Hawk
(@Hunter,19883,1076,0,0,12), -- Track Humaniods
(@Hunter,2974,1076,0,0,12), -- Wing Clip
(@Hunter,781,1418,0,0,14), -- Disengage
(@Hunter,1130,1418,0,0,14), -- Hunter's Mark
(@Hunter,19503,1728,0,0,15), -- Scatter Shot
(@Hunter,5118,5100,0,0,16), -- Aspect of the Cheetah
(@Hunter,6197,2060,0,0,16), -- Eagle Eye
(@Hunter,136,2060,0,0,16), -- Mend Pet
(@Hunter,83242,2784,0,0,18), -- Call Pet 2
(@Hunter,19884,2784,0,0,18), -- Track Undead
(@Hunter,674,0,0,0,20), -- Dual Wield
(@Hunter,13795,4200,0,0,22), -- Immolation Trap
(@Hunter,2643,5100,0,0,24), -- Multi-Shot
(@Hunter,19885,6000,0,0,26), -- Track Hidden
(@Hunter,1499,7500,0,0,28), -- Freezing Trap
(@Hunter,5384,9000,0,0,32), -- Feign Death
(@Hunter,19880,10500,0,0,34), -- Track Elementals
(@Hunter,53351,10500,0,0,35), -- Kill Shot
(@Hunter,19801,10500,0,0,35), -- Tranquilizing Shot
(@Hunter,1513,12000,0,0,36), -- Scare Beast
(@Hunter,19878,12000,0,0,36), -- Track Demons
(@Hunter,13813,13500,0,0,38), -- Explosive Trap
(@Hunter,1543,13500,0,0,38), -- Flare
(@Hunter,82654,15000,0,0,40), -- Window Venom
(@Hunter,8737,0,0,0,40), -- Mail
(@Hunter,83243,16500,0,0,42), -- Call Pet 3
(@Hunter,13809,19500,0,0,46), -- Ice Trap
(@Hunter,19882,19500,0,0,46), -- Track Giants
(@Hunter,77769,21000,0,0,48), -- Trap Launcher
(@Hunter,87506,22500,0,0,50), -- Mail Specialization
(@Hunter,20736,22500,0,0,52), -- Distracting Shot
(@Hunter,19879,22500,0,0,52), -- Track Dragonkin
(@Hunter,3045,24000,0,0,54), -- Rapid Fire
(@Hunter,13159,25500,0,0,56), -- Aspect of the Pack
(@Hunter,83244,81000,0,0,62), -- Call Pet 4
(@Hunter,20043,93000,0,0,64), -- Aspect of the Wild
(@Hunter,34600,105000,0,0,66), -- Snake Trap
(@Hunter,53271,168000,0,0,74), -- Master's Call
(@Hunter,34477,186000,0,0,76), -- Misdirection
(@Hunter,19263,204000,0,0,78), -- Deterrence
(@Hunter,87493,222000,0,0,80), -- Mastery
(@Hunter,77767,234000,0,0,81), -- Cobra Shot
(@Hunter,83245,246000,0,0,82), -- Call Pet 5
(@Hunter,82661,258000,0,0,83), -- Aspect of the Fox
(@Hunter,51753,282000,0,0,85), -- Camouflage
-- -----------------------------------------------------------------------------
-- -- Rogue 38 spells -- 
-- -----------------------------------------------------------------------------
(@Rogue,2098,60,0,0,3), -- Eviscerate
(@Rogue,1784,142,0,0,5), -- Stealth
(@Rogue,921,285,0,0,7), -- Pick Pocket
(@Rogue,8676,390,0,0,8), -- Ambush
(@Rogue,5277,552,0,0,9), -- Evasion
(@Rogue,6770,680,0,0,10), -- Sap
(@Rogue,82245,1076,0,0,12), -- Parry
(@Rogue,73651,1076,0,0,12), -- Recuperate
(@Rogue,1766,1418,0,0,14), -- Kick
(@Rogue,1776,2060,0,0,16), -- Gouge
(@Rogue,1804,3600,0,0,16), -- Pick Lock
(@Rogue,2983,2060,0,0,16), -- Sprint
(@Rogue,53,2784,0,0,18), -- Backstab
(@Rogue,5171,4200,0,0,22), -- Slice and Dice
(@Rogue,1856,5100,0,0,24), -- Vanish
(@Rogue,1833,6000,0,0,26), -- Cheap Shot
(@Rogue,1725,7500,0,0,28), -- Distract
(@Rogue,408,7500,0,0,30), -- Kidney Shot
(@Rogue,2836,9000,0,0,32), -- Detect Traps
(@Rogue,2094,10500,0,0,34), -- Blind
(@Rogue,8647,12000,0,0,36), -- Expose Armor
(@Rogue,51722,13500,0,0,38), -- Dismantle
(@Rogue,703,15000,0,0,40), -- Garrote
(@Rogue,1966,16500,0,0,42), -- Feint
(@Rogue,1842,19500,0,0,44), -- Disarm Trap
(@Rogue,1943,19500,0,0,46), -- Rupture
(@Rogue,1860,21000,0,0,48), -- Safe Fall
(@Rogue,87504,22500,0,0,50), -- Leather Specialization
(@Rogue,32645,24000,0,0,54), -- Envenom
(@Rogue,31224,27000,0,0,58), -- Cloak of Shadows
(@Rogue,26679,81000,0,0,62), -- Deadly Throw
(@Rogue,5938,132000,0,0,70), -- Shiv
(@Rogue,57934,177000,0,0,75), -- Tricks of the Trade
(@Rogue,51723,222000,0,0,80), -- Fan of Knives
(@Rogue,87496,222000,0,0,80), -- Mastery
(@Rogue,74001,234000,0,0,81), -- Combat Readiness
(@Rogue,73981,258000,0,0,83), -- Redirect
(@Rogue,76577,282000,0,0,85), -- Smoke Bomb
-- -----------------------------------------------------------------------------
-- -- Priest 39 spells-- 
-- -----------------------------------------------------------------------------
(@Priest,2061,60,0,0,3), -- Flash Heal
(@Priest,589,97,0,0,4), -- Shadow Word: Pain
(@Priest,17,142,0,0,5), -- Power Word: Shield
(@Priest,588,285,0,0,7), -- Inner Fire
(@Priest,139,390,0,0,8), -- Renew
(@Priest,8092,552,0,0,9), -- Mind Blast
(@Priest,8122,1076,0,0,12), -- Psychic Scream
(@Priest,21562,1418,0,0,14), -- Power Word: Fortitude
(@Priest,2006,1418,0,0,14), -- Resurrection
(@Priest,2050,2060,0,0,16), -- Heal
(@Priest,14914,2785,0,0,18), -- Holy Fire
(@Priest,528,4200,0,0,22), -- Cure Disease
(@Priest,586,5100,0,0,24), -- Fade
(@Priest,527,6000,0,0,26), -- Dispel Magic
(@Priest,2944,7500,0,0,28), -- Devouring Plague
(@Priest,9484,9000,0,0,32), -- Shackle Undead
(@Priest,32379,9000,0,0,32), -- Shadow Word: Death
(@Priest,1706,10500,0,0,34), -- Levitate
(@Priest,2096,12000,0,0,36), -- Mind Vision
(@Priest,2060,16500,0,0,38), -- Greater Heal
(@Priest,605,13500,0,0,38), -- Mind Control
(@Priest,596,19500,0,0,44), -- Prayer of Healing
(@Priest,32546,21000,0,0,48), -- Binding Heal
(@Priest,89745,22500,0,0,50), -- Mysticism
(@Priest,27683,22500,0,0,52), -- Shadow Protection
(@Priest,6346,24000,0,0,54), -- Fear Ward
(@Priest,453,25500,0,0,56), -- Mind Soothe
(@Priest,8129,27000,0,0,58), -- Mana Burn
(@Priest,15237,81000,0,0,62), -- Holy Nova
(@Priest,64901,93000,0,0,64), -- Hymn of Hope
(@Priest,34433,105000,0,0,66), -- Shadowfiend
(@Priest,33076,117000,0,0,68), -- Prayer of Mending
(@Priest,32375,150000,0,0,72), -- Mass Dispel
(@Priest,48045,168000,0,0,74), -- Mind Sear
(@Priest,64843,204000,0,0,78), -- Divine Hymn
(@Priest,87495,224000,0,0,80), -- Mastery
(@Priest,73510,234000,0,0,81), -- Mind Spike
(@Priest,73413,258000,0,0,83), -- Inner Will
(@Priest,73325,282000,0,0,85), -- Leap of Faith
-- -----------------------------------------------------------------------------
-- -- Death Knight 38 spells -- 
-- -----------------------------------------------------------------------------
(@DeathKnight,53341,25500,0,0,55), -- Rune of Cinderglacier
(@DeathKnight,53343,25500,0,0,55), -- Rune of Razorice
(@DeathKnight,49998,25500,0,0,56), -- Death Strike
(@DeathKnight,50842,25500,0,0,56), -- Pestilence
(@DeathKnight,46584,25500,0,0,56), -- Raise Dead
(@DeathKnight,48263,25500,0,0,57), -- Blood Presence
(@DeathKnight,47528,25500,0,0,57), -- Mind Freeze
(@DeathKnight,54447,25500,0,0,57), -- Rune of Spellbreaking
(@DeathKnight,53342,25500,0,0,57), -- Rune of Spellshattering
(@DeathKnight,48721,27000,0,0,58), -- Blood Boil
(@DeathKnight,45524,27000,0,0,58), -- Chains of Ice
(@DeathKnight,47476,27000,0,0,59), -- Strangulate
(@DeathKnight,43265,27000,0,0,60), -- Death and Decay
(@DeathKnight,53331,27000,0,0,60), -- Rune of Lichbane
(@DeathKnight,49020,60000,0,0,61), -- Obliterate
(@DeathKnight,3714,60000,0,0,61), -- Path of Frost
(@DeathKnight,48792,81000,0,0,62), -- Icebound Fortitude
(@DeathKnight,54446,87000,0,0,63), -- Rune of Swordbreaking
(@DeathKnight,53323,87000,0,0,63), -- Rune of Swordshattering
(@DeathKnight,45529,93000,0,0,64), -- Blood Tap
(@DeathKnight,85948,117000,0,0,64), -- Festering Strike
(@DeathKnight,56222,99000,0,0,65), -- Dark Command
(@DeathKnight,57330,99000,0,0,65), -- Horn of Winter
(@DeathKnight,48743,105000,0,0,66), -- Death Pact
(@DeathKnight,56815,111000,0,0,67), -- Rune Strike
(@DeathKnight,48707,117000,0,0,68), -- Anti-Magic Shell
(@DeathKnight,81229,117000,0,0,68), -- Runic Empowerment
(@DeathKnight,53344,132000,0,0,70), -- Rune of the Fallen Crusader
(@DeathKnight,48265,132000,0,0,70), -- Unholy Presence
(@DeathKnight,61999,141000,0,0,72), -- Raise Ally
(@DeathKnight,70164,150000,0,0,72), -- Rune of the Nerubian Carapace
(@DeathKnight,62158,150000,0,0,72), -- Rune of the Stoneskin Gargoyle
(@DeathKnight,47568,177000,0,0,75), -- Empower Rune Weapon
(@DeathKnight,42650,222000,0,0,80), -- Army of the Dead
(@DeathKnight,87492,222000,0,0,80), -- Mastery
(@DeathKnight,77575,234000,0,0,81), -- Outbreak
(@DeathKnight,73975,258000,0,0,83), -- Necrotic Strike
(@DeathKnight,77606,282000,0,0,85), -- Dark Simulacrum
-- -----------------------------------------------------------------------------
-- -- Shaman 56 spells + Heroism/Bloodlust -- 
-- -----------------------------------------------------------------------------
(@Shaman,73899,60,0,0,3), -- Primal Strike
(@Shaman,8075,97,0,0,4), -- Strenght of Earth Totem
(@Shaman,8042,142,0,0,5), -- Earth Shock
(@Shaman,331,285,0,0,7), -- Healing Wave
(@Shaman,324,390,0,0,8), -- Lightning Shield
(@Shaman,8024,680,0,0,10), -- Flametongue Weapon
(@Shaman,3599,680,0,0,10), -- Searing Totem
(@Shaman,2008,1076,0,0,12), -- Ancestral Spirit
(@Shaman,8227,1076,0,0,12), -- Flametongue Totem
(@Shaman,370,1076,0,0,12), -- Purge
(@Shaman,8050,1418,0,0,14), -- Flame Shock
(@Shaman,2645,1728,0,0,15), -- Ghost Wolf
(@Shaman,57994,2060,0,0,16), -- Wind Shear
(@Shaman,51886,2785,0,0,18), -- Cleanse Spirit
(@Shaman,2484,2785,0,0,18), -- Earthbind Totem
(@Shaman,5394,3600,0,0,20), -- Healing Stream Totem
(@Shaman,8004,3600,0,0,20), -- Healing Surge
(@Shaman,52127,3600,0,0,20), -- Water Shield
(@Shaman,8056,4200,0,0,22), -- Frost Shock
(@Shaman,546,5100,0,0,24), -- Water Walking
(@Shaman,8033,6000,0,0,26), -- Frostbrand Weapon
(@Shaman,421,7500,0,0,28), -- Chain Lightning
(@Shaman,1535,7500,0,0,28), -- Fire Nova
(@Shaman,556,7500,0,0,30), -- Astral Recall
(@Shaman,66842,7500,0,0,30), -- Call of the Elements
(@Shaman,20608,7500,0,0,30), -- Reincarnation
(@Shaman,36936,7500,0,0,30), -- Totemic Recall
(@Shaman,8512,7500,0,0,30), -- Windfury Totem
(@Shaman,8232,9000,0,0,32), -- Windfury Weapon
(@Shaman,51505,10500,0,0,34), -- Lava Burst
(@Shaman,6196,12000,0,0,36), -- Far Sight
(@Shaman,8190,12000,0,0,36), -- Magma Totem
(@Shaman,8177,13500,0,0,38), -- Grounding Totem
(@Shaman,66843,15000,0,0,40), -- Call of the Ancestors
(@Shaman,1064,15000,0,0,40), -- Chain Heal
(@Shaman,8737,0,0,0,40), -- Mail
(@Shaman,5675,16500,0,0,42), -- Mana Spring Totem
(@Shaman,3738,19500,0,0,44), -- Wrath of Air Totem
(@Shaman,131,19500,0,0,46), -- Water Breathing
(@Shaman,8071,21000,0,0,48), -- Stoneskin Totem
(@Shaman,66844,22500,0,0,50), -- Call of the Spirits
(@Shaman,87507,22500,0,0,50), -- Mail Specialization
(@Shaman,8143,22500,0,0,52), -- Tremor Totem
(@Shaman,51730,24000,0,0,54), -- Earthliving Weapon
(@Shaman,2062,25500,0,0,56), -- Earth Elemental Totem
(@Shaman,5730,27000,0,0,58), -- Stoneclaw Totem
(@Shaman,8184,81000,0,0,62), -- Elemental Resistance Totem
(@Shaman,76780,93000,0,0,64), -- Bind Elemental
(@Shaman,2894,105000,0,0,66), -- Fire Elemental Totem
(@Shaman,77472,117000,0,0,68), -- Greater Healing Wave
(@Shaman,87718,168000,0,0,74), -- Totem of Tranquil Mind
(@Shaman,8017,177000,0,0,75), -- Rockbiter Weapon
(@Shaman,51514,222000,0,0,80), -- Hex
(@Shaman,87497,222000,0,0,80), -- Mastery
(@Shaman,73680,234000,0,0,81), -- Unleash Elements
(@Shaman,73920,258000,0,0,83), -- Healing Rain
(@Shaman,79206,282000,0,0,85), -- Spiritwalker's Grace
-- -----------------------------------------------------------------------------
-- -- Mage 36 spells --
-- -----------------------------------------------------------------------------
(@Mage,5143,60,0,0,3), -- Arcane Missiles
(@Mage,2136,142,0,0,5), -- Fire Blast
(@Mage,116,284,0,0,7), -- Frostbolt
(@Mage,122,390,0,0,8), -- Frost Nova
(@Mage,2139,524,0,0,9), -- Counterspell
(@Mage,12051,1076,0,0,12), -- Evocation
(@Mage,118,1418,0,0,14), -- Polymorph
(@Mage,1953,2060,0,0,16), -- Blink
(@Mage,120,2784,0,0,18), -- Cone of Cold
(@Mage,30451,10500,0,0,20), -- Arcane Blast
(@Mage,1449,4400,0,0,22), -- Arcane Explosion
(@Mage,2948,6000,0,0,26), -- Scorch
(@Mage,30455,7500,0,0,28), -- Ice Lance
(@Mage,45438,7500,0,0,30), -- Ice Block
(@Mage,475,7500,0,0,30), -- Remove Curse
(@Mage,130,9000,0,0,32), -- Slow Fall
(@Mage,30482,12000,0,0,34), -- Molten Armor
(@Mage,543,3600,0,0,36), -- Mage Ward
(@Mage,42955,13500,0,0,38), -- Conjure Refreshment
(@Mage,2120,19500,0,0,44), -- Flamestrike
(@Mage,1463,19500,0,0,46), -- Mana Shield
(@Mage,759,21000,0,0,48), -- Conjure Mana Gem
(@Mage,55342,22500,0,0,50), -- Mirror Image
(@Mage,89744,22500,0,0,50), -- Wizardry
(@Mage,10,22500,0,0,52), -- Blizzard
(@Mage,7302,24000,0,0,54), -- Frost Armor
(@Mage,44614,25500,0,0,56), -- Frostfire Bolt
(@Mage,1459,27000,0,0,58), -- Arcane Brilliance
(@Mage,6117,117000,0,0,68), -- Mage Armor
(@Mage,30449,132000,0,0,70), -- Spellsteal
(@Mage,43987,186000,0,0,76), -- Ritual of Refreshment
(@Mage,66,204000,0,0,78), -- Invisibility
(@Mage,86467,222000,0,0,80), -- Mastery
(@Mage,82731,234000,0,0,81), -- Flame Orb
(@Mage,82676,258000,0,0,83), -- Ring of Frost
(@Mage,80353,282000,0,0,85), -- Time Warp
-- -----------------------------------------------------------------------------
-- -- Warlock 51 spells --
-- -----------------------------------------------------------------------------
(@Warlock,348,60,0,0,3), -- Immolate
(@Warlock,172,97,0,0,4), -- Corruption
(@Warlock,1454,142,0,0,5), -- Life Tap
(@Warlock,689,190,0,0,6), -- Drain Life
(@Warlock,687,480,0,0,8), -- Demon Armor
(@Warlock,697,390,0,0,8), -- Summon Voidwalker
(@Warlock,6201,552,0,0,9), -- Create Healthstone
(@Warlock,80388,680,0,0,10), -- Control Demon
(@Warlock,1120,680,0,0,10), -- Drain Soul
(@Warlock,74434,680,0,0,10), -- Soulburn
(@Warlock,980,1076,0,0,12), -- Bane of Agony
(@Warlock,755,1076,0,0,12), -- Health Funnel
(@Warlock,79268,1076,0,0,12), -- Soul Harvest
(@Warlock,5782,1418,0,0,14), -- Fear
(@Warlock,702,2060,0,0,16), -- Curse of Weakness
(@Warlock,5697,2060,0,0,16), -- Unending Breath
(@Warlock,5740,2784,0,0,18), -- Rain of Fire
(@Warlock,5676,2784,0,0,18), -- Searing Pain
(@Warlock,693,2784,0,0,18), -- Create Soulstone
(@Warlock,603,3600,0,0,20), -- Bane of Doom
(@Warlock,5784,0,0,0,20), -- Felsteed
(@Warlock,6353,3600,0,0,20), -- Soul Fire
(@Warlock,19028,3600,0,0,20), -- Soul Link
(@Warlock,712,3600,0,0,20), -- Summon Succubus
(@Warlock,126,4200,0,0,22), -- Eye of Killrogg
(@Warlock,1714,6000,0,0,26), -- Curse of Tongues
(@Warlock,1098,7500,0,0,30), -- Enslave Demon
(@Warlock,1949,7500,0,0,30), -- Hellfire
(@Warlock,691,7500,0,0,30), -- Summon Felhunter
(@Warlock,710,9000,0,0,32), -- Banish
(@Warlock,6229,10500,0,0,34), -- Shadow Ward
(@Warlock,23161,0,0,0,40), -- Dreadstead
(@Warlock,6789,16500,0,0,42), -- Death Coil
(@Warlock,698,16500,0,0,42), -- Ritual of Summoning
(@Warlock,5484,19500,0,0,44), -- Howl of Terror
(@Warlock,86091,22500,0,0,50), -- Nethermancy
(@Warlock,1122,22500,0,0,50), -- Summon Infernal
(@Warlock,1490,22500,0,0,52), -- Curse of the Elements
(@Warlock,18540,27000,0,0,58), -- Summon Doomguard
(@Warlock,28176,81000,0,0,62), -- Fel Armor
(@Warlock,29722,93000,0,0,64), -- Incinerate
(@Warlock,29858,105000,0,0,66), -- Soulshatter
(@Warlock,29893,117000,0,0,68), -- Ritual of Souls
(@Warlock,27243,150000,0,0,72), -- Seed of Corruption
(@Warlock,47897,186000,0,0,76), -- Shadowflame
(@Warlock,48018,102000,0,0,78), -- Demonic Circle: Summon
(@Warlock,48020,102000,0,0,78), -- Demonic Circle: Teleport
(@Warlock,87498,222000,0,0,80), -- Mastery
(@Warlock,77799,234000,0,0,81), -- Fel Flame
(@Warlock,80398,258000,0,0,83), -- Dark Intent
(@Warlock,77801,282000,0,0,85), -- Demon Soul
-- -----------------------------------------------------------------------------
-- -- Druid 67 spells -- 
-- -----------------------------------------------------------------------------
(@Druid,774,60,0,0,3), -- Rejuvenation
(@Druid,8921,97,0,0,4), -- Moonfire
(@Druid,467,142,0,0,5), -- Thorns
(@Druid,339,284,0,0,7), -- Entangling Roots
(@Druid,768,390,0,0,8), -- Cat Form
(@Druid,1082,390,0,0,8), -- Claw
(@Druid,22568,390,0,0,8), -- Ferocious Bite
(@Druid,50464,390,0,0,8), -- Nourish
(@Druid,1822,390,0,0,8), -- Rake
(@Druid,2912,390,0,0,8), -- Starfire
(@Druid,5215,680,0,0,10), -- Prowl
(@Druid,8936,1076,0,0,12), -- Regrowth
(@Druid,50769,1076,0,0,12), -- Revive
(@Druid,5487,1728,0,0,15), -- Bear Form
(@Druid,99,1728,0,0,15), -- Demoralizing Roar
(@Druid,6795,1728,0,0,15), -- Growl
(@Druid,6807,1728,0,0,15), -- Maul
(@Druid,18960,1728,0,0,15), -- Teleport: Moonglade
(@Druid,1066,2060,0,0,16), -- Aquatic Form
(@Druid,783,2060,0,0,16), -- Travel Form
(@Druid,779,2784,0,0,18), -- Swipe
(@Druid,5570,3600,0,0,20), -- Insect Swarm
(@Druid,16864,3600,0,0,20), -- Omen of Clarity
(@Druid,20484,3600,0,0,20), -- Rebirth
(@Druid,5229,4200,0,0,22), -- Enrage
(@Druid,6785,4200,0,0,22), -- Ravage
(@Druid,80964,2100,0,0,22), -- Skull Bash
(@Druid,80965,2100,0,0,22), -- Skull Bash
(@Druid,770,2550,0,0,24), -- Faerie Fire
(@Druid,16857,2550,0,0,24), -- Faerie Fire Feral
(@Druid,2782,5100,0,0,24), -- Remove Corruption
(@Druid,5217,5100,0,0,24), -- Tiger's Fury
(@Druid,8998,6000,0,0,25), -- Cower
(@Druid,1850,6000,0,0,26), -- Dash
(@Druid,20719,6000,0,0,26), -- Feline Grace
(@Druid,5209,7500,0,0,28), -- Challenging Roar
(@Druid,29166,7500,0,0,28), -- Innervate
(@Druid,2908,7500,0,0,28), -- Soothe
(@Druid,1126,7500,0,0,30), -- Mark of the Wild
(@Druid,5211,9000,0,0,32), -- Bash
(@Druid,5225,9000,0,0,32), -- Track Humaniods
(@Druid,9005,9000,0,0,36), -- Pounce
(@Druid,62078,9000,0,0,36), -- Swipe
(@Druid,62600,15000,0,0,40), -- Savage Defence
(@Druid,16914,19500,0,0,44), -- Hurricane
(@Druid,5221,19500,0,0,46), -- Shred
(@Druid,2637,21000,0,0,48), -- Hibernate
(@Druid,87505,22500,0,0,50), -- Leather Specialization
(@Druid,22842,22500,0,0,52), -- Frenzied Regeneration
(@Druid,16689,22500,0,0,52), -- Nature's Grasp
(@Druid,1079,24000,0,0,54), -- Rip
(@Druid,22812,27000,0,0,58), -- Barkskin
(@Druid,33943,27000,0,0,60), -- Flight Form
(@Druid,22570,81000,0,0,62), -- Maim
(@Druid,33763,93000,0,0,64), -- Lifebloom
(@Druid,33745,105000,0,0,66), -- Lacerate
(@Druid,740,117000,0,0,68), -- Tranquility
(@Druid,40120,141000,0,0,70), -- Swift Flight Form
(@Druid,33786,168000,0,0,74), -- Cyclone
(@Druid,52610,186000,0,0,76), -- Savage Roar
(@Druid,5185,200400,0,0,78), -- Healing Touch
(@Druid,87491,222000,0,0,80), -- Mastery
(@Druid,77758,234000,0,0,81), -- Trash
(@Druid,77761,129000,0,0,83), -- Stampeding Roar
(@Druid,77764,129000,0,0,83), -- Stampeding Roar
(@Druid,88747,141000,0,0,85), -- Wild Mushroom
(@Druid,88751,0,0,0,85); -- Wild Mushroom: Detonate

-- Assign Templates to trainer NPCs
-- --------------------------------------------------
-- -- Warrior Trainers (57 trainers, +12 starters) --
-- --------------------------------------------------
-- Starters (12)
DELETE FROM `npc_trainer` WHERE `entry` IN (198,328,331,375,376,377,459,460,461,837,895,906,911,912,913,914,915,916,917,918,925,926,927,928,985,986,987,988,1226,1228,1229,1231,1232,1234,1404,1411,1901,2119,2122,2123,2124,2126,2127,2128,2129,2130,2131,3033,3034,3036,3038,3039,3040,3041,3042,3043,3044,3045,3046,3047,3048,3049,3059,3060,3061,3062,3063,3064,3065,3153,3155,3156,3157,3169,3170,3171,3172,3173,3324,3325,3326,3327,3328,3344,3352,3353,3354,3403,3593,3594,3595,3596,3597,3598,3599,3600,3601,3602,3706,4087,4089,4090,4091,4092,4138,4146,4163,4205,4214,4215,4217,4218,4219,4563,4564,4565,4566,4567,4568,4582,4583,4584,4593,4594,4595,4606,4607,4608,4892,5113,5114,5115,5116,5117,5141,5142,5143,5144,5145,5146,5147,5148,5149,5165,5166,5167,5171,5172,5173,5479,5480,5484,5489,5491,5492,5495,5496,5497,5498,5501,5504,5515,5516,5517,5612,5880,6251,6707,7311,7312,7315,8140,8141,8142,8308,8664,10930,11397,11401,11406,12042,13283,13417,13476,15279,15280,15283,15284,15285,15513,16266,16269,16270,16275,16276,16279,16499,16500,16501,16502,16503,16646,16647,16648,16651,16652,16653,16655,16658,16659,16660,16661,16672,16673,16674,16679,16680,16681,16684,16685,16686,16721,16749,16756,16761,16771,17089,17110,17120,17121,17122,17204,17212,17219,17480,17481,17482,17483,17505,17509,17510,17511,17513,17514,17519,17520,17844,20406,20407,23103,23127,23128,23534,23566,27704,28471,28472,28474,28956,28958,29194,29195,29196,31084,32712,34600,34673,34689,34692,34693,34695,34696,34697,35281,35758,35778,35780,35786,35805,35806,35807,35839,35869,35870,35871,35872,35873,35874,36518,36519,36520,36521,36523,36524,36525,36628,36629,36630,36631,36632,36651,36652,37115,37121,37724,37737,38037,38122,38242,38243,38244,38245,38246,38247,38465,38466,38467,38513,38514,38515,38516,38517,38518,38793,38794,38795,38796,38797,38798,38799,38911,39100,39116,39206,39214,42323,42324,42331,42366,42618,43001,43004,43005,43006,43009,43010,43011,43012,43013,43015,43277,43278,43455,43464,43795,43796,43870,43881,43883,43892,44128,44129,44247,44249,44380,44393,44394,44395,44455,44459,44461,44464,44465,44468,44469,44723,44725,44726,44735,44740,44743,44978,45019,45023,45029,45095,45137,45138,45306,45337,45339,45347,45709,45713,45714,45717,45718,45720,46667,46983,47233,47246,47247,47248,47767,47788,48612,48613,48614,48615,48616,48618,49715,49716,49718,49720,49736,49741,49745,49749,49760,49769,49781,49782,49784,49786,49791,49793,49806,49808,49870,49894,49895,49896,49900,49901,49902,49909,49923,49927,49939,49940,49942,49945,49946,49949,49950,49952,49954,49955,49957,49958,49959,49961,49962,49963,49964,49966,49968,49997,49998,50001,50002,50004,50006,50007,50010,50011,50012,50013,50015,50016,50017,50018,50019,50020,50021,50022,50023,50024,50025,50027,50028,50029,50031,50032,50033,50034,50035,50127,50128,50130,50136,50137,50142,50144,50147,50148,50149,50150,50152,50153,50155,50156,50157,50158,50160,50163,50171,50174,50497,50498,50499,50500,50501,50502,50504,50505,50506,50507,50609,50690,50714,50715,50717,50720,50723,50729,50732,51637,51638,51639,51640,51998,52292,52317,52319,52335,53403,53404,53405,200100,200101);
INSERT INTO `npc_trainer` (`entry`,`spell`,`spellcost`,`reqskill`,`reqskillvalue`,`reqlevel`) VALUES
(3593,100,60,0,0,3), -- Charge - Alyissia
(3593,34428,142,0,0,5), -- Victory Rush - Alyissia
(2119,100,60,0,0,3), -- Charge - Dannal Stern
(2119,34428,142,0,0,5), -- Victory Rush - Dannal Stern
(43010,100,60,0,0,3), -- Charge - Delios Silverblade
(43010,34428,142,0,0,5), -- Victory Rush - Delios Silverblade
(42324,100,60,0,0,3), -- Charge - Drill Sergeant Steamcrank
(42324,34428,142,0,0,5), -- Victory Rush - Drill Sergeant Steamcrank
(3153,100,60,0,0,3), -- Charge - Frang
(3153,34428,142,0,0,5), -- Victory Rush - Frang
(3059,100,60,0,0,3), -- Charge - Harutt Thunderhorn
(3059,34428,142,0,0,5), -- Victory Rush - Harutt Thunderhorn
(16503,100,60,0,0,3), -- Charge - Kore
(16503,34428,142,0,0,5), -- Victory Rush - Kore
(911,100,60,0,0,3), -- Charge - Llane Beshere
(911,34428,142,0,0,5), -- Victory Rush - Llane Beshere
(38037,100,60,0,0,3), -- Charge - Nortet
(38037,34428,142,0,0,5), -- Victory Rush - Nortet
(35839,100,60,0,0,3), -- Charge - Sergeant Cleese
(35839,34428,142,0,0,5), -- Victory Rush - Sergeant Cleese
(912,100,60,0,0,3), -- Charge - Thran Khorman
(912,34428,142,0,0,5), -- Victory Rush - Thran Khorman
(34697,100,60,0,0,3), -- Charge - Warrior-Matic NX-01
(34697,34428,142,0,0,5), -- Victory Rush - Warrior-Matic NX-01
-- Trainers (57)
(16771,-200001,0,0,0,0), -- Ahonan
(43009,-200001,0,0,0,0), -- Alsudar the Bastion
(914,-200001,0,0,0,0), -- Ander Germaine
(4594,-200001,0,0,0,0), -- Angela Curthas
(4087,-200001,0,0,0,0), -- Arias'ta Bladesinger
(2131,-200001,0,0,0,0), -- Austil de Mon
(4595,-200001,0,0,0,0), -- Baltus Fowler
(17120,-200001,0,0,0,0), -- Behomat
(44129,-200001,0,0,0,0), -- Beldis
(45019,-200001,0,0,0,0), -- Berserker Zanga
(5114,-200001,0,0,0,0), -- Bilban Tosslespanner
(46667,-200001,0,0,0,0), -- Blademaster Ronakada
(50025,-200001,0,0,0,0), -- Bratu
(45709,-200001,0,0,0,0), -- Bruiser Janx
(8141,-200001,0,0,0,0), -- Captain Evencane
(4593,-200001,0,0,0,0), -- Christoph Walker
(7315,-200001,0,0,0,0), -- Darnath Bladesinger
(49720,-200001,0,0,0,0), -- Eugene Daller
(50033,-200001,0,0,0,0), -- Ging
(1229,-200001,0,0,0,0), -- Granis Swiftaxe
(49781,-200001,0,0,0,0), -- Grendin Swiftaxe
(3353,-200001,0,0,0,0), -- Grezz Ragefist
(5480,-200001,0,0,0,0), -- Ilsa Corbin
(49736,-200001,0,0,0,0), -- Kallen Stanner
(48616,-200001,0,0,0,0), -- Karla Fain
(1901,-200001,0,0,0,0), -- Kelstrum Stonebreaker
(5113,-200001,0,0,0,0), -- Kelv Sternhammer
(3043,-200001,0,0,0,0), -- Ker Ragetotem
(3063,-200001,0,0,0,0), -- Krang Stonehoof
(3598,-200001,0,0,0,0), -- Kyra Windblade
(49955,-200001,0,0,0,0), -- Leonic Truehair
(43012,-200001,0,0,0,0), -- Lothan Silverblade
(913,-200001,0,0,0,0), -- Lyria Du Lac
(985,-200001,0,0,0,0), -- Malosh
(44723,-200001,0,0,0,0), -- Nahu Ragehoof
(50155,-200001,0,0,0,0), -- Naseev
(17480,-200001,0,0,0,0), -- Ruada
(44128,-200001,0,0,0,0), -- Sarithra
(3042,-200001,0,0,0,0), -- Sark Ragetotem
(49923,-200001,0,0,0,0), -- Sentinel Moonwing
(50500,-200001,0,0,0,0), -- Sergeant Cleese
(44455,-200001,0,0,0,0), -- Sergeant Cleese
(38793,-200001,0,0,0,0), -- Sergeant Cleese
(36651,-200001,0,0,0,0), -- Sergeant Cleese
(4089,-200001,0,0,0,0), -- Sildanair
(3354,-200001,0,0,0,0), -- Sorek
(50018,-200001,0,0,0,0), -- Tarlhir
(3169,-200001,0,0,0,0), -- Tarshaw Jaggedscar
(3041,-200001,0,0,0,0), -- Torm Ragetotem
(49961,-200001,0,0,0,0), -- Viik
(50149,-200001,0,0,0,0), -- Vinsun
(49902,-200001,0,0,0,0), -- Warrior-Matic NX-01
(38518,-200001,0,0,0,0), -- Warrior-Matic NX-01
(36525,-200001,0,0,0,0), -- Warrior-Matic NX-01
(35807,-200001,0,0,0,0), -- Warrior-Matic NX-01
(5479,-200001,0,0,0,0), -- Wu Shen
(50006,-200001,0,0,0,0), -- Yeniss
-- --------------------------------------------------
-- -- Paladin Trainers (35 trainers, +5 starters) --
-- --------------------------------------------------
-- starters (5)
(16501,20271,60,0,0,3), -- Judgement,Aurelon
(16501,20154,60,0,0,3), -- Seal of Righteousness,Aurelon
(16501,465,142,0,0,5), -- Devotion Aura,Aurelon
(926,20271,60,0,0,3), -- Judgement,Bromos Grummner
(926,20154,60,0,0,3), -- Seal of Righteousness,Bromos Grummner
(926,465,142,0,0,5), -- Devotion Aura,Bromos Grummner
(925,20271,60,0,0,3), -- Judgement,Brother Sammuel
(925,20154,60,0,0,3), -- Seal of Righteousness,Brother Sammuel
(925,465,142,0,0,5), -- Devotion Aura,Brother Sammuel
(15280,20271,60,0,0,3), -- Judgement,Jesthenis Sunstriker
(15280,20154,60,0,0,3), -- Seal of Righteousness,Jesthenis Sunstriker
(15280,465,142,0,0,5), -- Devotion Aura,Jesthenis Sunstriker
(37737,20271,60,0,0,3), -- Judgement,Sunwalker Helaku
(37737,20154,60,0,0,3), -- Seal of Righteousness,Sunwalker Helaku
(37737,465,142,0,0,5), -- Devotion Aura,Sunwalker Helaku
-- trainers (35)
(43795,-200002,0,0,0,0), -- Aponi Brightmane
(5491,-200002,0,0,0,0), -- Arthur the Faithful
(1232,-200002,0,0,0,0), -- Azar Stronghammer
(16761,-200002,0,0,0,0), -- Baatun
(5148,-200002,0,0,0,0), -- Beldruk Doombrow
(50012,-200002,0,0,0,0), -- Blood Knight Argaron
(5149,-200002,0,0,0,0), -- Brandur Ironhammer
(8140,-200002,0,0,0,0), -- Brother Karman
(927,-200002,0,0,0,0), -- Brother Wilhelm
(16681,-200002,0,0,0,0), -- Champion Bachi
(20406,-200002,0,0,0,0), -- Champion Cyssa Dawnrose
(49957,-200002,0,0,0,0), -- Delemm
(49793,-200002,0,0,0,0), -- Faldoc Stonefaith
(49954,-200002,0,0,0,0), -- Haris Lightsbreath
(16680,-200002,0,0,0,0), -- Ithelis
(17509,-200002,0,0,0,0), -- Jol
(5492,-200002,0,0,0,0), -- Katherine the Pure
(17121,-200002,0,0,0,0), -- Kavaan
(928,-200002,0,0,0,0), -- Lord Grayson Shadowbreaker
(23128,-200002,0,0,0,0), -- Master Pyreanor
(50150,-200002,0,0,0,0), -- Nelur Lightsown
(16275,-200002,0,0,0,0), -- Noellene
(50023,-200002,0,0,0,0), -- Ordo
(16679,-200002,0,0,0,0), -- Osselan
(35281,-200002,0,0,0,0), -- Rukua
(50160,-200002,0,0,0,0), -- Rulen Lightsreap
(49741,-200002,0,0,0,0), -- Sister Darnhald
(44725,-200002,0,0,0,0), -- Sunwalker Atohmo
(43013,-200002,0,0,0,0), -- Sunwalker Iopi
(50035,-200002,0,0,0,0), -- Sunwalker Lonaki
(43001,-200002,0,0,0,0), -- Sunwalker Reha
(8664,-200002,0,0,0,0), -- Sunwalker Saern
(17483,-200002,0,0,0,0), -- Tullas
(5147,-200002,0,0,0,0), -- Valgar Highforge
(17844,-200002,0,0,0,0), -- Vindicator Aesom
/* TODO: MOUNTS */
-- Paladin Mounts Horde
(200100,69820,0,0,0,20), -- Summon Sunwalker Kodo (Tauren)
(200100,34769,0,0,0,20), -- Summon Warhorse (Blood Elf)
(200100,69826,0,0,0,40), -- Summon Great Sunwalker Kodo (Tauren) 
(200100,34767,0,0,0,40), -- Summon Charger (Blood Elf)
-- Paladin Mounts Alliance
(200101,13819,0,0,0,20), -- Summon Warhorse (Dwarf Human Undead)
(200101,23214,0,0,0,40), -- Summon Charger (Dwarf Human Undead) 
(200101,73629,0,0,0,20), -- Summon Exarch's Elekk (Draenei)
(200101,73630,0,0,0,40), -- Summon Great Exarch's Elekk (Draenei)
-- --------------------------------------------------
-- -- Hunter Trainers (66 trainers, +10 starters) --
-- --------------------------------------------------
-- Starters (10)
(43278,56641,60,0,0,3), -- Steady Shot - Ashley Blank
(43278,1494,97,0,0,4), -- Track Beasts - Ashley Blank
(3596,56641,60,0,0,3), -- Steady Shot - Ayanna Everstride
(3596,1494,97,0,0,4), -- Track Beasts - Ayanna Everstride
(34673,56641,60,0,0,3), -- Steady Shot - Bamm Megabomb
(34673,1494,97,0,0,4), -- Track Beasts - Bamm Megabomb
(35874,56641,60,0,0,3), -- Steady Shot - Huntsman Blake
(35874,1494,97,0,0,4), -- Track Beasts - Huntsman Blake
(16499,56641,60,0,0,3), -- Steady Shot - Keilnei
(16499,1494,97,0,0,4), -- Track Beasts - Keilnei
(3061,56641,60,0,0,3), -- Steady Shot - Lanka Farshot
(3061,1494,97,0,0,4), -- Track Beasts - Lanka Farshot
(38247,56641,60,0,0,3), -- Steady Shot - Ortezza
(38247,1494,97,0,0,4), -- Track Beasts - Ortezza
(15513,56641,60,0,0,3), -- Steady Shot - Ranger Sallina
(15513,1494,97,0,0,4), -- Track Beasts - Ranger Sallina
(895,56641,60,0,0,3), -- Steady Shot - Thorgas Grimson
(895,1494,97,0,0,4), -- Track Beasts - Thorgas Grimson
(38911,56641,60,0,0,3), -- Steady Shot - Xavier the Huntsman
(38911,1494,97,0,0,4), -- Track Beasts - Xavier the Huntsman
-- Trainers (66)
(17110,-200003,0,0,0,0), -- Acteon
(8308,-200003,0,0,0,0), -- Alenndaar Lapidaar
(34600,-200003,0,0,0,0), -- Alenndaar Lapidaar
(39116,-200003,0,0,0,0), -- Apolos
(36518,-200003,0,0,0,0), -- Bamm Megabomb
(49894,-200003,0,0,0,0), -- Bamm Megabomb
(35758,-200003,0,0,0,0), -- Bamm Megabomb
(38122,-200003,0,0,0,0), -- Bamm Megabomb
(49806,-200003,0,0,0,0), -- Belda Wildheart
(46983,-200003,0,0,0,0), -- Benjamin Foxworthy
(5115,-200003,0,0,0,0), -- Daera Brightspear
(45713,-200003,0,0,0,0), -- Dankin Farsnipe
(10930,-200003,0,0,0,0), -- Dargh Trueaim
(48618,-200003,0,0,0,0), -- Darna Woad
(3601,-200003,0,0,0,0), -- Dazalar
(39100,-200003,0,0,0,0), -- Dedlow Wormwood
(50007,-200003,0,0,0,0), -- Derithela
(43277,-200003,0,0,0,0), -- Don Omar
(4205,-200003,0,0,0,0), -- Dorion
(5515,-200003,0,0,0,0), -- Einris Brightspear
(1231,-200003,0,0,0,0), -- Grif Wildheart
(47788,-200003,0,0,0,0), -- Guldor
(16270,-200003,0,0,0,0), -- Hannovia
(3039,-200003,0,0,0,0), -- Holt Thunderhorn
(45023,-200003,0,0,0,0), -- Huntress Kuzari
(50497,-200003,0,0,0,0), -- Huntsman Blake
(38798,-200003,0,0,0,0), -- Huntsman Blake
(38467,-200003,0,0,0,0), -- Huntsman Blake
(44461,-200003,0,0,0,0), -- Huntsman Blake
(36629,-200003,0,0,0,0), -- Huntsman Blake
(50020,-200003,0,0,0,0), -- Irva
(50004,-200003,0,0,0,0), -- Jamai
(4138,-200003,0,0,0,0), -- Jeen'ra Nightrunner
(4892,-200003,0,0,0,0), -- Jensen Farran
(4146,-200003,0,0,0,0), -- Jocaste
(5501,-200003,0,0,0,0), -- Kaerbrus
(39214,-200003,0,0,0,0), -- Karranisha
(3038,-200003,0,0,0,0), -- Kary Thunderhorn
(17505,-200003,0,0,0,0), -- Killac
(47767,-200003,0,0,0,0), -- Korla
(1404,-200003,0,0,0,0), -- Kragg
(49927,-200003,0,0,0,0), -- Lanla Bowleaf
(43011,-200003,0,0,0,0), -- Lyndsay Hollister
(49958,-200003,0,0,0,0), -- Matt Bruxworthy
(50609,-200003,0,0,0,0), -- Nathanos Blightcaller
(44743,-200003,0,0,0,0), -- Nohi Plainswalker
(987,-200003,0,0,0,0), -- Ogromm
(5116,-200003,0,0,0,0), -- Olmin Burningbeard
(16673,-200003,0,0,0,0), -- Oninath
(3352,-200003,0,0,0,0), -- Ormak Grimshot
(49946,-200003,0,0,0,0), -- Ranger Belonis
(50144,-200003,0,0,0,0), -- Ranger Eoss
(50157,-200003,0,0,0,0), -- Ranger Selone
(5117,-200003,0,0,0,0), -- Regnus Thundergranite
(44249,-200003,0,0,0,0), -- Sarisse Jume
(49966,-200003,0,0,0,0), -- Shaniri
(16672,-200003,0,0,0,0), -- Tana
(50032,-200003,0,0,0,0), -- Tarmod
(5517,-200003,0,0,0,0), -- Thorfin Stoneshield
(3171,-200003,0,0,0,0), -- Thotar
(5516,-200003,0,0,0,0), -- Ulfir Ironbeard
(3040,-200003,0,0,0,0), -- Urek Thunderhorn
(17122,-200003,0,0,0,0), -- Vord
(44247,-200003,0,0,0,0), -- Wulf Hansreim
(3065,-200003,0,0,0,0), -- Yaw Sharpmane
(16674,-200003,0,0,0,0), -- Zandine
-- ------------------------------------------------
-- -- Rogue Trainers (49 trainers, +10 starters) --
-- ------------------------------------------------
-- Starters (10)
(2122,2098,60,0,0,3), -- Eviscerate - David Trias
(2122,1784,142,0,0,5), -- Stealth - David Trias
(3594,2098,60,0,0,3), -- Eviscerate - Frahun Shadewhisper
(3594,1784,142,0,0,5), -- Stealth - Frahun Shadewhisper
(915,2098,60,0,0,3), -- Eviscerate - Jorik Kerridan
(915,1784,142,0,0,5), -- Stealth - Jorik Kerridan
(42366,2098,60,0,0,3), -- Eviscerate - Kelsey Steelspark
(42366,1784,142,0,0,5), -- Stealth - Kelsey Steelspark
(38244,2098,60,0,0,3), -- Eviscerate - Legati
(38244,1784,142,0,0,5), -- Stealth - Legati
(35871,2098,60,0,0,3), -- Eviscerate - Loren the Fence
(35871,1784,142,0,0,5), -- Stealth - Loren the Fence
(15285,2098,60,0,0,3), -- Eviscerate - Pathstalker Kariel
(15285,1784,142,0,0,5), -- Stealth - Pathstalker Kariel
(3155,2098,60,0,0,3), -- Eviscerate - Rwag
(3155,1784,142,0,0,5), -- Stealth - Rwag
(916,2098,60,0,0,3), -- Eviscerate - Solm Hargrin
(916,1784,142,0,0,5), -- Stealth - Solm Hargrin
(34693,2098,60,0,0,3), -- Eviscerate - Slinky Sharpshiv
(34693,1784,142,0,0,5), -- Stealth - Slinky Sharpshiv
-- Trainers (49)
(49870,-200004,0,0,0,0), -- Angela Hipple
(4215,-200004,0,0,0,0), -- Anishar
(51998,-200004,0,0,0,0), -- Arthur Huwe
(23566,-200004,0,0,0,0), -- Calia Hastings
(4582,-200004,0,0,0,0), -- Carolyn Ward
(50027,-200004,0,0,0,0), -- Dargad
(16685,-200004,0,0,0,0), -- Elara
(4214,-200004,0,0,0,0), -- Erion Shadewhisper
(6707,-200004,0,0,0,0), -- Fahrad
(5167,-200004,0,0,0,0), -- Fenthwick
(49782,-200004,0,0,0,0), -- Galda Bronzeblade
(3327,-200004,0,0,0,0), -- Gest
(47233,-200004,0,0,0,0), -- Gordul
(4584,-200004,0,0,0,0), -- Gregory Charles
(1234,-200004,0,0,0,0), -- Hogral Bakkan
(5165,-200004,0,0,0,0), -- Hulfdan Blackbeard
(1411,-200004,0,0,0,0), -- Ian Strom
(3599,-200004,0,0,0,0), -- Jannok Breezesong
(3170,-200004,0,0,0,0), -- Kaplak
(49939,-200004,0,0,0,0), -- Kenral Nightwind
(917,-200004,0,0,0,0), -- Keryn Sylvius
(13283,-200004,0,0,0,0), -- Lord Tony Romano
(36630,-200004,0,0,0,0), -- Loren the Fence
(50498,-200004,0,0,0,0), -- Loren the Fence
(44464,-200004,0,0,0,0), -- Loren the Fence
(38796,-200004,0,0,0,0), -- Loren the Fence
(2130,-200004,0,0,0,0), -- Marion Call
(4583,-200004,0,0,0,0), -- Miles Dexter
(50015,-200004,0,0,0,0), -- Munalti
(16686,-200004,0,0,0,0), -- Nerisen
(45095,-200004,0,0,0,0), -- Night-Stalker Ku'nanji
(3328,-200004,0,0,0,0), -- Ormok
(5166,-200004,0,0,0,0), -- Ormyr Flinteye
(918,-200004,0,0,0,0), -- Osborne the Night Man
(50016,-200004,0,0,0,0), -- Pathstalker Arpalir
(49949,-200004,0,0,0,0), -- Pathstalker Lontral
(50158,-200004,0,0,0,0), -- Pathstalker Ralsir
(50147,-200004,0,0,0,0), -- Pathstalker Rislar
(49745,-200004,0,0,0,0), -- Sern Hallows
(48615,-200004,0,0,0,0), -- Shernon the Footpad
(36524,-200004,0,0,0,0), -- Slinky Sharpshiv
(35806,-200004,0,0,0,0), -- Slinky Sharpshiv
(38517,-200004,0,0,0,0), -- Slinky Sharpshiv
(49909,-200004,0,0,0,0), -- Stinky Sharpshiv
(4163,-200004,0,0,0,0), -- Syurna
(16279,-200004,0,0,0,0), -- Tannaria
(45717,-200004,0,0,0,0), -- Vish the Sneak
(50127,-200004,0,0,0,0), -- Windstalker Ifram
(16684,-200004,0,0,0,0), -- Zelanis
-- -------------------------------------------------
-- -- Priest Trainers (71 trainers, +5 starters) --
-- -------------------------------------------------
-- Starters (5)
(42323,2061,60,3,0,0), -- Flash Heal - Doc Cogspin
(42323,589,142,5,0,0), -- Shadow Word: Pain - Doc Cogspin
(42323,17,97,4,0,0), -- Power Word: Shield - Doc Cogspin
(3595,2061,60,3,0,0), -- Flash Heal - Shanda
(3595,589,142,5,0,0), -- Shadow Word: Pain - Shanda
(3595,17,97,4,0,0), -- Power Word: Shield - Shanda
(35870,2061,60,3,0,0), -- Flash Heal - Sister Almyra
(35870,589,142,5,0,0), -- Shadow Word: Pain - Sister Almyra
(35870,17,97,4,0,0), -- Power Word: Shield - Sister Almyra
(34692,2061,60,3,0,0), -- Flash Heal - Sister Goldskimmer
(34692,589,142,5,0,0), -- Shadow Word: Pain - Sister Goldskimmer
(34692,17,97,4,0,0), -- Power Word: Shield - Sister Goldskimmer
(38245,2061,60,3,0,0), -- Flash Heal - Tunari
(38245,589,142,5,0,0), -- Shadow Word: Pain - Tunari
(38245,17,97,4,0,0), -- Power Word: Shield - Tunari
-- Trainers (71)
(4606,-200005,0,0,0,0), -- Aelthalyste
(16658,-200005,0,0,0,0), -- Aldrae
(53403,-200005,0,0,0,0), -- Allen Bright
(49962,-200005,0,0,0,0), -- Andrenatol
(4090,-200005,0,0,0,0), -- Astarii Starseeker
(16660,-200005,0,0,0,0), -- Belestra
(50504,-200005,0,0,0,0), -- Belysra Starbreeze
(5142,-200005,0,0,0,0), -- Braenna Flintcrag
(837,-200005,0,0,0,0), -- Branstock Khalder
(5484,-200005,0,0,0,0), -- Brother Benjamin
(5489,-200005,0,0,0,0), -- Brother Joshua
(45347,-200005,0,0,0,0), -- Brother Silverhallow
(16756,-200005,0,0,0,0), -- Caedmos
(45306,-200005,0,0,0,0), -- Chief Surgeon Gashweld
(2129,-200005,0,0,0,0), -- Dark Cleric Beryl
(45339,-200005,0,0,0,0), -- Dark Cleric Cecille
(48614,-200005,0,0,0,0), -- Dark Cleric Claressa
(2123,-200005,0,0,0,0), -- Dark Cleric Duesten
(49715,-200005,0,0,0,0), -- Dark Cleric Pordon
(17511,-200005,0,0,0,0), -- Fallat
(3046,-200005,0,0,0,0), -- Father Cobb
(4607,-200005,0,0,0,0), -- Father Lankester
(4608,-200005,0,0,0,0), -- Father Lazarus
(17482,-200005,0,0,0,0), -- Guvan
(11406,-200005,0,0,0,0), -- High Priest Rohan
(376,-200005,0,0,0,0), -- High Priestess Laurena
(49940,-200005,0,0,0,0), -- Irlara Morninglight
(17510,-200005,0,0,0,0), -- Izmir
(4091,-200005,0,0,0,0), -- Jandria
(4092,-200005,0,0,0,0), -- Lariia
(3600,-200005,0,0,0,0), -- Laurna Morninglight
(16659,-200005,0,0,0,0), -- Lotheolan
(3045,-200005,0,0,0,0), -- Malakai Cross
(50163,-200005,0,0,0,0), -- Matron Alesso
(15284,-200005,0,0,0,0), -- Matron Arena
(50013,-200005,0,0,0,0), -- Matron Ismara
(49950,-200005,0,0,0,0), -- Matron Narsilla
(50148,-200005,0,0,0,0), -- Matron Ossela
(1226,-200005,0,0,0,0), -- Maxan Anvol
(3044,-200005,0,0,0,0), -- Miles Welsh
(11397,-200005,0,0,0,0), -- Nara Meideros
(50001,-200005,0,0,0,0), -- Parata
(16276,-200005,0,0,0,0), -- Ponaris
(11401,-200005,0,0,0,0), -- Priestess Alathea
(375,-200005,0,0,0,0), -- Priestess Anetta
(49784,-200005,0,0,0,0), -- Priestess Baerla
(49749,-200005,0,0,0,0), -- Priestess Cocoa Anderson
(377,-200005,0,0,0,0), -- Priestess Josetta
(50024,-200005,0,0,0,0), -- Salha
(43015,-200005,0,0,0,0), -- Seer Alsoomse
(43870,-200005,0,0,0,0), -- Seer Beryl
(43004,-200005,0,0,0,0), -- Seer Kaya
(44735,-200005,0,0,0,0), -- Seer Liwatha
(37724,-200005,0,0,0,0), -- Seer Ravenfeather
(45137,-200005,0,0,0,0), -- Shadow-Walker Zuru
(38795,-200005,0,0,0,0), -- Sister Almyra
(44468,-200005,0,0,0,0), -- Sister Almyra
(50501,-200005,0,0,0,0), -- Sister Almyra
(38466,-200005,0,0,0,0), -- Sister Almyra
(36632,-200005,0,0,0,0), -- Sister Almyra
(36523,-200005,0,0,0,0), -- Sister Goldskimmer
(49901,-200005,0,0,0,0), -- Sister Goldskimmer
(35805,-200005,0,0,0,0), -- Sister Goldskimmer
(38516,-200005,0,0,0,0), -- Sister Goldskimmer
(43796,-200005,0,0,0,0), -- Tahu Sagewind
(3706,-200005,0,0,0,0), -- Tai'jin
(5141,-200005,0,0,0,0), -- Theodrus Frostbeard
(5143,-200005,0,0,0,0), -- Toldren Deepiron
(45337,-200005,0,0,0,0), -- Tyelis
(16502,-200005,0,0,0,0), -- Zalduun
(50031,-200005,0,0,0,0), -- Zumolo
-- ---------------------------------------
-- -- DeathKnight Trainers (7 trainers) --
-- ---------------------------------------
(29194,-200006,0,0,0,0), -- Amal'thazad
(28474,-200006,0,0,0,0), -- Amal'thazad
(31084,-200006,0,0,0,0), -- Highlord Darion Mograine
(28471,-200006,0,0,0,0), -- Lady Alistra
(29195,-200006,0,0,0,0), -- Lady Alistra
(28472,-200006,0,0,0,0), -- Lord Thorval
(29196,-200006,0,0,0,0), -- Lord Thorval
-- ------------------------------------------------
-- -- Shaman Trainers (38 trainers + 6 starters) --
-- ------------------------------------------------
-- Starters (6)
(17089,73899,60,0,0,3), --  Primal Strike - Firmanvaar
(17089,8075,97,0,0,4), --  Strength of Earth Totem - Firmanvaar
(17089,8042,142,0,0,5), --  Earth Shock - Firmanvaar
(34695,73899,60,0,0,3), --  Primal Strike - Maxx Avalanche
(34695,8075,97,0,0,4), --  Strength of Earth Totem - Maxx Avalanche
(34695,8042,142,0,0,5), --  Earth Shock - Maxx Avalanche
(3062,73899,60,0,0,3), --  Primal Strike - Meela Dawnstrider
(3062,8075,97,0,0,4), --  Strength of Earth Totem - Meela Dawnstrider
(3062,8042,142,0,0,5), --  Earth Shock - Meela Dawnstrider
(38242,73899,60,0,0,3), --  Primal Strike - Nekali
(38242,8075,97,0,0,4), --  Strength of Earth Totem - Nekali
(38242,8042,142,0,0,5), --  Earth Shock - Nekali
(3157,73899,60,0,0,3), --  Primal Strike - Shikrik
(3157,8075,97,0,0,4), --  Strength of Earth Totem - Shikrik
(3157,8042,142,0,0,5), --  Earth Shock - Shikrik
(37115,73899,60,0,0,3), --  Primal Strike - Teo Hammerstorm
(37115,8075,97,0,0,4), --  Strength of Earth Totem - Teo Hammerstorm
(37115,8042,142,0,0,5), --  Earth Shock - Teo Hammerstorm
-- Trainers (38)
(49964,-200007,0,0,0,0), -- Adrihi
(44393,-200007,0,0,0,0), -- Bolner Hammerbeak
(50022,-200007,0,0,0,0), -- Brulla
(50011,-200007,0,0,0,0), -- Cona
(44394,-200007,0,0,0,0), -- Dalga Hammerbeak
(50019,-200007,0,0,0,0), -- Darahu
(52292,-200007,0,0,0,0), -- Droha
(45718,-200007,0,0,0,0), -- Environmental Engineer Linza
(23127,-200007,0,0,0,0), -- Farseer Javad
(50174,-200007,0,0,0,0), -- Farseer Lopaa
(17204,-200007,0,0,0,0), -- Farseer Nobundo
(20407,-200007,0,0,0,0), -- Farseer Umbrua
(51638,-200007,0,0,0,0), -- Garn Cloudsong
(16661,-200007,0,0,0,0), -- Gez'li
(49808,-200007,0,0,0,0), -- Grenhild Darktalon
(17520,-200007,0,0,0,0), -- Gurrag
(43464,-200007,0,0,0,0), -- Halbin Frosthammer
(986,-200007,0,0,0,0), -- Haromm
(17519,-200007,0,0,0,0), -- Hobahken
(51639,-200007,0,0,0,0), -- Kador Cloudsong
(3344,-200007,0,0,0,0), -- Kardris Dreamseeker
(51640,-200007,0,0,0,0), -- Lama Cloudsong
(50130,-200007,0,0,0,0), -- Luknar
(52317,-200007,0,0,0,0), -- Mahala Cloudsong
(49900,-200007,0,0,0,0), -- Maxx Avalanche
(38515,-200007,0,0,0,0), -- Maxx Avalanche
(36521,-200007,0,0,0,0), -- Maxx Avalanche
(35786,-200007,0,0,0,0), -- Maxx Avalanche
(50153,-200007,0,0,0,0), -- Murgha the Tempered
(53405,-200007,0,0,0,0), -- Raedra Windhammer
(13417,-200007,0,0,0,0), -- Sagorne Creststrider
(44740,-200007,0,0,0,0), -- Sahi Cloudsinger
(3403,-200007,0,0,0,0), -- Sian'tsu
(17219,-200007,0,0,0,0), -- Sulaa
(3173,-200007,0,0,0,0), -- Swart
(51637,-200007,0,0,0,0), -- Tarl Cloudsong
(17212,-200007,0,0,0,0), -- Tuluun
(45029,-200007,0,0,0,0), -- Witch Doctor Umbu
-- ------------------------------------------------
-- -- Mage Trainers (61 trainers + 11 starters) --
-- ------------------------------------------------
-- Starters (11)
(39206,5143,60,0,0,3), -- Arcane Missiles - Acrypha
(39206,2136,142,0,0,5), -- Fire Blast - Acrypha
(42331,5143,60,0,0,3), -- Arcane Missiles - Bipsi Frostflinger
(42331,2136,142,0,0,5), -- Fire Blast - Bipsi Frostflinger
(34689,5143,60,0,0,3), -- Arcane Missiles - Fizz Lighter
(34689,2136,142,0,0,5), -- Fire Blast - Fizz Lighter
(2124,5143,60,0,0,3), -- Arcane Missiles - Isabella
(2124,2136,142,0,0,5), -- Fire Blast - Isabella
(15279,5143,60,0,0,3), -- Arcane Missiles - Julia Sunstriker
(15279,2136,142,0,0,5), -- Fire Blast - Julia Sunstriker
(198,5143,60,0,0,3), -- Arcane Missiles - Khelden Bremen
(198,2136,142,0,0,5), -- Fire Blast - Khelden Bremen
(35872,5143,60,0,0,3), -- Arcane Missiles - Myriam Spellwaker
(35872,2136,142,0,0,5), -- Fire Blast - Myriam Spellwaker
(43006,5143,60,0,0,3), -- Arcane Missiles - Rhyanda
(43006,2136,142,0,0,5), -- Fire Blast - Rhyanda
(38246,5143,60,0,0,3), -- Arcane Missiles - Soratha
(38246,2136,142,0,0,5), -- Fire Blast - Soratha
(37121,5143,60,0,0,3), -- Arcane Missiles - Teegli Merrowith
(37121,2136,142,0,0,5), -- Fire Blast - Teegli Merrowith
(16500,5143,60,0,0,3), -- Arcane Missiles - Valaatu
(16500,2136,142,0,0,5), -- Fire Blast - Valaatu
-- Trainers (61)
(50010,-200008,0,0,0,0), -- Alaressa
(4568,-200008,0,0,0,0), -- Anastasia Hartwell
(3047,-200008,0,0,0,0), -- Archmage Shymm
(17514,-200008,0,0,0,0), -- Bati
(5144,-200008,0,0,0,0), -- Bink
(50002,-200008,0,0,0,0), -- Bomsanchu
(2128,-200008,0,0,0,0), -- Cain Firesong
(45714,-200008,0,0,0,0), -- Conjurer Mixli
(49952,-200008,0,0,0,0), -- Denara Eversun
(23103,-200008,0,0,0,0), -- Derek the Undying
(7312,-200008,0,0,0,0), -- Dink
(50714,-200008,0,0,0,0), -- Dyrhara
(16749,-200008,0,0,0,0), -- Edirah
(50029,-200008,0,0,0,0), -- Egnom
(5498,-200008,0,0,0,0), -- Elsharin
(38514,-200008,0,0,0,0), -- Fizz Lighter
(36520,-200008,0,0,0,0), -- Fizz Lighter
(35780,-200008,0,0,0,0), -- Fizz Lighter
(49896,-200008,0,0,0,0), -- Fizz Lighter
(50717,-200008,0,0,0,0), -- Flarna Flametongue
(16269,-200008,0,0,0,0), -- Garridel
(47248,-200008,0,0,0,0), -- Gija
(49786,-200008,0,0,0,0), -- Gindle the Green
(17513,-200008,0,0,0,0), -- Harnan
(27704,-200008,0,0,0,0), -- Horace Alder
(16653,-200008,0,0,0,0), -- Inethven
(43005,-200008,0,0,0,0), -- Irriende
(5497,-200008,0,0,0,0), -- Jennea Cannon
(28958,-200008,0,0,0,0), -- Jessa Weaver
(5145,-200008,0,0,0,0), -- Juli Stormkettle
(4566,-200008,0,0,0,0), -- Kaelystia Hatebringer
(50720,-200008,0,0,0,0), -- Lainda Gemgold
(48613,-200008,0,0,0,0), -- Larah Firesong
(49968,-200008,0,0,0,0), -- Lareth Beld
(49959,-200008,0,0,0,0), -- Lennah
(50715,-200008,0,0,0,0), -- Maelir
(331,-200008,0,0,0,0), -- Maginor Dumas
(1228,-200008,0,0,0,0), -- Magis Sparkmantle
(47247,-200008,0,0,0,0), -- Marud
(38465,-200008,0,0,0,0), -- Myriam Spellwaker
(50499,-200008,0,0,0,0), -- Myriam Spellwaker
(36631,-200008,0,0,0,0), -- Myriam Spellwaker
(44465,-200008,0,0,0,0), -- Myriam Spellwaker
(38794,-200008,0,0,0,0), -- Myriam Spellwaker
(5146,-200008,0,0,0,0), -- Nittlebur Sparkfizzle
(4567,-200008,0,0,0,0), -- Pierce Shackleton
(16652,-200008,0,0,0,0), -- Quithas
(50021,-200008,0,0,0,0), -- Raluhi
(17481,-200008,0,0,0,0), -- Semid
(50690,-200008,0,0,0,0), -- Tarelvir
(32712,-200008,0,0,0,0), -- The Amazing Zanzo
(49716,-200008,0,0,0,0), -- Thom Denger
(3049,-200008,0,0,0,0), -- Thurston Xane
(5880,-200008,0,0,0,0), -- Un'Thuwa
(47246,-200008,0,0,0,0), -- Ureda
(3048,-200008,0,0,0,0), -- Ursyn Ghull
(7311,-200008,0,0,0,0), -- Uthel'nay
(28956,-200008,0,0,0,0), -- Warcaster Fanoraithe
(16651,-200008,0,0,0,0), -- Zaedana
(328,-200008,0,0,0,0), -- Zaldimar Wefhellt
(49760,-200008,0,0,0,0), -- Zalna Wefhellt
-- -------------------------------------------------
-- -- Warlock Trainers (52 trainers + 9 starters) --
-- -------------------------------------------------
-- Starters (9)
(460,348,60,0,0,3), -- Immolation - Alamar Grimm
(460,172,97,0,0,4), -- Corruption - Alamar Grimm
(460,1454,142,0,0,5), -- Life Tap - Alamar Grimm
(459,348,60,0,0,3), -- Immolation - Drusilla La Salle
(459,172,97,0,0,4), -- Corruption - Drusilla La Salle
(459,1454,142,0,0,5), -- Life Tap - Drusilla La Salle
(34696,348,60,0,0,3), -- Immolation - Evol Fingers
(34696,172,97,0,0,4), -- Corruption - Evol Fingers
(34696,1454,142,0,0,5), -- Life Tap - Evol Fingers
(2126,348,60,0,0,3), -- Immolation - Maximillion
(2126,172,97,0,0,4), -- Corruption - Maximillion
(2126,1454,142,0,0,5), -- Life Tap - Maximillion
(3156,348,60,0,0,3), -- Immolation - Nartok
(3156,172,97,0,0,4), -- Corruption - Nartok
(3156,1454,142,0,0,5), -- Life Tap - Nartok
(43455,348,60,0,0,3), -- Immolation - Saripal Smolderbrew
(43455,172,97,0,0,4), -- Corruption - Saripal Smolderbrew
(43455,1454,142,0,0,5), -- Life Tap - Saripal Smolderbrew
(15283,348,60,0,0,3), -- Immolation - Summoner Teli'Larien
(15283,172,97,0,0,4), -- Corruption - Summoner Teli'Larien
(15283,1454,142,0,0,5), -- Life Tap - Summoner Teli'Larien
(35869,348,60,0,0,3), -- Immolation - Vitus Darkwalker
(35869,172,97,0,0,4), -- Corruption - Vitus Darkwalker
(35869,1454,142,0,0,5), -- Life Tap - Vitus Darkwalker
(42618,348,60,0,0,3), -- Immolation - Voldreka
(42618,172,97,0,0,4), -- Corruption - Voldreka
(42618,1454,142,0,0,5), -- Life Tap - Voldreka
-- Trainers (52)
(16646,-200009,0,0,0,0), -- Alamma
(5173,-200009,0,0,0,0), -- Alexander Calder
(23534,-200009,0,0,0,0), -- Babagaya Shadowcleft
(49718,-200009,0,0,0,0), -- Bee Bruxworthy
(5172,-200009,0,0,0,0), -- Briarthorn
(16266,-200009,0,0,0,0), -- Celoenus
(50028,-200009,0,0,0,0), -- Chintoka
(50729,-200009,0,0,0,0), -- Darba the Crone
(49769,-200009,0,0,0,0), -- Deborah Fain
(43881,-200009,0,0,0,0), -- Delano Morisett
(461,-200009,0,0,0,0), -- Demisette Cloyce
(3172,-200009,0,0,0,0), -- Dhugru Gorelust
(38513,-200009,0,0,0,0), -- Evol Fingers
(36519,-200009,0,0,0,0), -- Evol Fingers
(35778,-200009,0,0,0,0), -- Evol Fingers
(49895,-200009,0,0,0,0), -- Evol Fingers
(6251,-200009,0,0,0,0), -- Farsan
(50128,-200009,0,0,0,0), -- Fel-Caller Guloto
(5612,-200009,0,0,0,0), -- Gimrizz Shadowcog
(3324,-200009,0,0,0,0), -- Grol'dar
(49998,-200009,0,0,0,0), -- Gusini
(43883,-200009,0,0,0,0), -- Jensen Thomasson
(4563,-200009,0,0,0,0), -- Kaal Soulreaper
(988,-200009,0,0,0,0), -- Kartosh
(45720,-200009,0,0,0,0), -- Kazrali the Witch
(50723,-200009,0,0,0,0), -- Keric Smolderblade
(49963,-200009,0,0,0,0), -- Laera Dubois
(50732,-200009,0,0,0,0), -- Larn Caverndeep
(4564,-200009,0,0,0,0), -- Luther Pickman
(48612,-200009,0,0,0,0), -- Maressa Milner
(906,-200009,0,0,0,0), -- Maximillian Crowe
(3325,-200009,0,0,0,0), -- Mirket
(43892,-200009,0,0,0,0), -- Morairania Horton
(53404,-200009,0,0,0,0), -- Redia Vaunt
(4565,-200009,0,0,0,0), -- Richard Kerwin
(2127,-200009,0,0,0,0), -- Rupert Boch
(5496,-200009,0,0,0,0), -- Sandahl
(49791,-200009,0,0,0,0), -- Solbin Shadowcog
(50142,-200009,0,0,0,0), -- Summoner Calwen
(50017,-200009,0,0,0,0), -- Summoner Durael
(49945,-200009,0,0,0,0), -- Summoner Fanorad
(50156,-200009,0,0,0,0), -- Summoner Nolric
(16647,-200009,0,0,0,0), -- Talionia
(5171,-200009,0,0,0,0), -- Thistleheart
(45138,-200009,0,0,0,0), -- Unjari Feltongue
(5495,-200009,0,0,0,0), -- Ursula Deline
(50502,-200009,0,0,0,0), -- Vitus Darkwalker
(38797,-200009,0,0,0,0), -- Vitus Darkwalker
(36652,-200009,0,0,0,0), -- Vitus Darkwalker
(44469,-200009,0,0,0,0), -- Vitus Darkwalker
(16648,-200009,0,0,0,0), -- Zanien
(3326,-200009,0,0,0,0), -- Zevrost
-- -----------------------------------------------
-- -- Druid Trainers (33 trainers + 4 starters) --
-- -----------------------------------------------
-- Starters (4)
(35873,774,60,0,0,3), -- Rejuvenation - Celestine of the Harvest
(35873,8921,97,0,0,4), -- Moonfire - Celestine of the Harvest
(35873,467,142,0,0,5), -- Thorns - Celestine of the Harvest
(3060,774,60,0,0,3), -- Rejuvenation - Gart Mistrunner
(3060,8921,97,0,0,4), -- Moonfire - Gart Mistrunner
(3060,467,142,0,0,5), -- Thorns - Gart Mistrunner
(3597,774,60,0,0,3), -- Rejuvenation - Mardant Strongoak
(3597,8921,97,0,0,4), -- Moonfire - Mardant Strongoak
(3597,467,142,0,0,5), -- Thorns - Mardant Strongoak
(38243,774,60,0,0,3), -- Rejuvenation - Zen'tabra
(38243,8921,97,0,0,4), -- Moonfire - Zen'tabra
(38243,467,142,0,0,5), -- Thorns - Zen'tabra
-- Trainers (33)
(50136,-200011,0,0,0,0), -- Baelir
(44395,-200011,0,0,0,0), -- Celestine of the Harvest
(36628,-200011,0,0,0,0), -- Celestine of the Harvest
(38799,-200011,0,0,0,0), -- Celestine of the Harvest
(44459,-200011,0,0,0,0), -- Celestine of the Harvest
(52335,-200011,0,0,0,0), -- Dareth
(4218,-200011,0,0,0,0), -- Denatharion
(49997,-200011,0,0,0,0), -- Den'chulu
(49942,-200011,0,0,0,0), -- Dular
(4219,-200011,0,0,0,0), -- Fylerian Nightwing
(3064,-200011,0,0,0,0), -- Gennia Runetotem
(50152,-200011,0,0,0,0), -- Hahna Moonscrest
(16655,-200011,0,0,0,0), -- Harene Plainwalker
(44380,-200011,0,0,0,0), -- Jabul
(8142,-200011,0,0,0,0), -- Jannos Lighthoof
(3602,-200011,0,0,0,0), -- Kal
(3036,-200011,0,0,0,0), -- Kym Wildmane
(12042,-200011,0,0,0,0), -- Loganaar
(50505,-200011,0,0,0,0), -- Lyros Swiftwind
(52319,-200011,0,0,0,0), -- Mala Skywatcher
(4217,-200011,0,0,0,0), -- Mathrengyl Bearwalker
(50137,-200011,0,0,0,0), -- Muha
(50171,-200011,0,0,0,0), -- Muran Fairden
(50034,-200011,0,0,0,0), -- Musu Gentlemoon
(44978,-200011,0,0,0,0), -- Sesebi
(16721,-200011,0,0,0,0), -- Shalannius
(44726,-200011,0,0,0,0), -- Shalla Whiteleaf
(3034,-200011,0,0,0,0), -- Sheal Runetotem
(5504,-200011,0,0,0,0), -- Sheldras Moontree
(50506,-200011,0,0,0,0), -- Talran of the Wild
(3033,-200011,0,0,0,0), -- Turak Runetotem
(50507,-200011,0,0,0,0), -- Vassandra Stormclaw
(13476,-200011,0,0,0,0); -- Zen'Balai

DELETE FROM `npc_trainer` WHERE `spell` IN (2825,32182);
DELETE FROM `npc_trainer` WHERE `entry` BETWEEN 200100 AND 200103;
DELETE FROM `npc_trainer` WHERE `spell` BETWEEN -200103 AND -200100 ; 
INSERT INTO `npc_trainer` (`entry`,`spell`,`spellcost`,`reqskill`,`reqskillvalue`,`reqlevel`) VALUES
-- Horde Bloodlust
(50022,2825,132000,0,0,70), -- Bloodlust - Brulla
(50011,2825,132000,0,0,70), -- Bloodlust - Cona
(50019,2825,132000,0,0,70), -- Bloodlust - Darahu
(45718,2825,132000,0,0,70), -- Bloodlust - Environmental Engineer Linza
(51638,2825,132000,0,0,70), -- Bloodlust - Garn Cloudsong
(16661,2825,132000,0,0,70), -- Bloodlust - Gez'li
(986,2825,132000,0,0,70), -- Bloodlust - Haromm
(51639,2825,132000,0,0,70), -- Bloodlust - Kador Cloudsong
(3344,2825,132000,0,0,70), -- Bloodlust - Kardis Dreamseeker
(51640,2825,132000,0,0,70), -- Bloodlust - Lama Cloudsong
(50130,2825,132000,0,0,70), -- Bloodlust - Luknar
(52317,2825,132000,0,0,70), -- Bloodlust - Mahala Cloudsong
(36521,2825,132000,0,0,70), -- Bloodlust - Maxx Avalanche
(49900,2825,132000,0,0,70), -- Bloodlust - Maxx Avalanche
(35786,2825,132000,0,0,70), -- Bloodlust - Maxx Avalanche
(38515,2825,132000,0,0,70), -- Bloodlust - Maxx Avalanche
(50153,2825,132000,0,0,70), -- Bloodlust - Murgha the Tempered
(13417,2825,132000,0,0,70), -- Bloodlust - Sagorne Creststrider
(44740,2825,132000,0,0,70), -- Bloodlust - Sahi Cloudsinger
(3403,2825,132000,0,0,70), -- Bloodlust - Sain'tsu
(3173,2825,132000,0,0,70), -- Bloodlust - Swart
(51637,2825,132000,0,0,70), -- Bloodlust - Tarl Cloudsong
(45029,2825,132000,0,0,70), -- Bloodlust - Witch Doctor Umbu
-- Alliance Heroism
(49964,32182,132000,0,0,70), -- Bloodlust - Adrihi
(44393,32182,132000,0,0,70), -- Bloodlust - Bolner Hammerbeak
(44394,32182,132000,0,0,70), -- Bloodlust - Dalga Hammerbeak
(50019,32182,132000,0,0,70), -- Bloodlust - Darahu
(52292,32182,132000,0,0,70), -- Bloodlust - Droha
(23127,32182,132000,0,0,70), -- Bloodlust - Farseer Javad
(50174,32182,132000,0,0,70), -- Bloodlust - Farseer Lopaa
(17204,32182,132000,0,0,70), -- Bloodlust - Farseer Nobundo
(20407,32182,132000,0,0,70), -- Bloodlust - Farseer Umbrua
(49808,32182,132000,0,0,70), -- Bloodlust - Grenhild Darktalon
(17520,32182,132000,0,0,70), -- Bloodlust - Gurrag
(43464,32182,132000,0,0,70), -- Bloodlust - Halbin Frosthammer
(17519,32182,132000,0,0,70), -- Bloodlust - Hobahken
(50130,32182,132000,0,0,70), -- Bloodlust - Luknar
(53405,32182,132000,0,0,70), -- Bloodlust - Raedra Windhammer
(17219,32182,132000,0,0,70), -- Bloodlust - Sulaa
(17212,32182,132000,0,0,70), -- Bloodlust - Tuluun
-- Paladin Mounts Tauren
(200100,69820,0,0,0,20), -- Summon Sunwalker Kodo (Tauren)
(200100,69826,0,0,0,40), -- Summon Great Sunwalker Kodo (Tauren) 
-- Paladin Mounts Blood Elf
(200101,34769,0,0,0,20), -- Summon Warhorse (Blood Elf)
(200101,34767,0,0,0,40), -- Summon Charger (Blood Elf)
-- Paladin Mounts Human/Dwarf
(200102,13819,0,0,0,20), -- Summon Warhorse (Dwarf Human Undead)
(200102,23214,0,0,0,40), -- Summon Charger (Dwarf Human Undead) 
-- Paladin Mounts Draenei
(200103,73629,0,0,0,20), -- Summon Exarch's Elekk (Draenei)
(200103,73630,0,0,0,40), -- Summon Great Exarch's Elekk (Draenei)
-- HORDE MOUNTS
-- Sunwalker Kodo & Greater Sunwalker Kodo (13)
(43795,-200100,0,0,0,0), -- Aponi Brightmane
(50012,-200100,0,0,0,0), -- Blood Knight Argaron
(16681,-200100,0,0,0,0), -- Champion Bachi
(20406,-200100,0,0,0,0), -- Champion Cyssa Dawnrose
(49954,-200100,0,0,0,0), -- Haris Lightsbreath
(23128,-200100,0,0,0,0), -- Master Pyreanor
(20150,-200100,0,0,0,0), -- Nelur Lightsown
(50023,-200100,0,0,0,0), -- Ordo
(44725,-200100,0,0,0,0), -- Sunwalker Atohmo
(43013,-200100,0,0,0,0), -- Sunwalker Iopi
(50035,-200100,0,0,0,0), -- Sunwalker Lonaki
(43001,-200100,0,0,0,0), -- Sunwalker Reha
(8664,-200100,0,0,0,0), -- Sunwalker Saern
-- Summon Warhorse & Summon Charger (16) 
(43795,-200101,0,0,0,0), -- Aponi Brightmane
(50012,-200101,0,0,0,0), -- Blood Knight Argaron
(16681,-200101,0,0,0,0), -- Champion Bachi
(20406,-200101,0,0,0,0), -- Champion Cyssa Dawnrose
(49954,-200101,0,0,0,0), -- Haris Lightsbreath
(16680,-200101,0,0,0,0), -- Ithelis
(23128,-200101,0,0,0,0), -- Master Pyreanor
(20150,-200101,0,0,0,0), -- Nelur Lightsown
(16275,-200101,0,0,0,0), -- Noellene
(50023,-200101,0,0,0,0), -- Ordo
(16679,-200101,0,0,0,0), -- Osselan
(44725,-200101,0,0,0,0), -- Sunwalker Atohmo
(43013,-200101,0,0,0,0), -- Sunwalker Iopi
(50035,-200101,0,0,0,0), -- Sunwalker Lonaki
(43001,-200101,0,0,0,0), -- Sunwalker Reha
(8664,-200101,0,0,0,0), -- Sunwalker Saern
-- ALLIANCE MOUNTS
-- Summon Warhorse & Summon Charger (21)
(5491,-200102,0,0,0,0), -- Arthur the Faithful
(1232,-200102,0,0,0,0), -- Azar Stronghammer
(16761,-200102,0,0,0,0), -- Baatun
(5148,-200102,0,0,0,0), -- Beldruk Doombrow
(50012,-200102,0,0,0,0), -- Blood Knight Argaron
(5149,-200102,0,0,0,0), -- Brandur Ironhammer
(8140,-200102,0,0,0,0), -- Brother Karman
(927,-200102,0,0,0,0), -- Brother Wilhelm
(49957,-200102,0,0,0,0), -- Delemm
(49793,-200102,0,0,0,0), -- Faldoc Stonefaith
(17509,-200102,0,0,0,0), -- Jol
(5492,-200102,0,0,0,0), -- Katherine the Pure
(17121,-200102,0,0,0,0), -- Kavaan
(928,-200102,0,0,0,0), -- Lord Grayson Shadowbreaker
(50023,-200102,0,0,0,0), -- Ordo
(35281,-200102,0,0,0,0), -- Rukua
(50160,-200102,0,0,0,0), -- Rulen Lightsreap
(49741,-200102,0,0,0,0), -- Sister Darnhald
(17483,-200102,0,0,0,0), -- Tullas
(5147,-200102,0,0,0,0), -- Valgar Highforge
(17844,-200102,0,0,0,0), -- Vindicator Aesom
-- Summon Exarch's Elekk && Summon Great Exarch's Elekk
(5491,-200103,0,0,0,0), -- Arthur the Faithful
(16761,-200103,0,0,0,0), -- Baatun
(5148,-200103,0,0,0,0), -- Beldruk Doombrow
(5149,-200103,0,0,0,0), -- Brandur Ironhammer
(8140,-200103,0,0,0,0), -- Brother Karman
(927,-200103,0,0,0,0), -- Brother Wilhelm
(49957,-200103,0,0,0,0), -- Delemm
(49793,-200103,0,0,0,0), -- Faldoc Stonefaith
(17509,-200103,0,0,0,0), -- Jol
(5492,-200103,0,0,0,0), -- Katherine the Pure
(17121,-200103,0,0,0,0), -- Kavaan
(928,-200103,0,0,0,0), -- Lord Grayson Shadowbreaker
(50023,-200103,0,0,0,0), -- Ordo
(35281,-200103,0,0,0,0), -- Rukua
(50160,-200103,0,0,0,0), -- Rulen Lightsreap
(49741,-200103,0,0,0,0), -- Sister Darnhald
(17483,-200103,0,0,0,0), -- Tullas
(5147,-200103,0,0,0,0), -- Valgar Highforge
(17844,-200103,0,0,0,0); -- Vindicator Aesom

SET @PortalA := 200200;
SET @PortalH := 200201;
SET @PortalD := 200202;
SET @RidingJ := 200300;
SET @RidingM := 200301;
SET @Fishing := 200302;
SET @FirstAid := 200303; 
SET @Archeology := 200304;
SET @Cooking := 200305; 
-- ------------------------------------------------------------------------------------------------------------------------------------------
-- Generic Templates
DELETE FROM `npc_trainer` WHERE `entry` IN (@PortalA,@PortalH,@PortalD,@RidingJ,@RidingM,@Fishing,@FirstAid,@Archeology,@Cooking);
-- Portal Trainers
DELETE FROM `npc_trainer` WHERE `entry` IN (4165,2485,16755,2489,27703,5957,5957,2492,2492,27705,27705,16654,16654,47253,47253,45139,45139,29156,29156,29156,20791,20791,20791,19340,19340,19340);
-- Riding Trainers
DELETE FROM `npc_trainer` WHERE `entry` IN (20914,7954,4753,3690,4752,16280,4732,48513,53407,4772,4773,7953,43769,43693,35100,31238,20511,35133,44919,20500,28746,31247,35093,35135);
-- Fishing Trainers
DELETE FROM `npc_trainer` WHERE `entry` IN (23896,3607,26957,4573,5493,4156,7946,26909,5690,17101,16780,16774,33623,32474,5161,3179,18911,3028,14740,12961,5941,1651,12032,3332,28742,1680,2834,25580,26993,44975,1700,56068,5938,1683,50570,18018);
-- First Aid Trainers
DELETE FROM `npc_trainer` WHERE `entry` IN (16662,50574,22477,17214,17424,23734,56796,18991,26992,18990,6094,4211,49879,36615,12939,19478,33621,3181,33589,16272,45540,4591,2329,19184,5150,29233,5759,16731,28706,2798,5943,26956,2326,5939);
-- Archeology Trainers
DELETE FROM `npc_trainer` WHERE `entry` IN (47382,47571,47575,47579,47570,39718,47346,53421,47576,47574,47569,44238,47578,47568,47577,47572,47573,51997);
-- Cooking Trainers
DELETE FROM `npc_trainer` WHERE `entry` IN (17246,4210,49789,46709,3026,29631,33587,26905,19369,1355,33619,4894,3087,5159,8306,4552,50567,18987,1699,19185,28705,19186,16253,54232,1382,16719,18993,26972,3067,16277,26989,2818,5482,16676,47405,26953,1430,3399,45550,6286);
-- ------------------------------------------------------------------------------------------------------------------------------------------
-- Insert new templates:
INSERT INTO `npc_trainer` (`entry`,`spell`,`spellcost`,`reqskill`,`reqskillvalue`,`reqlevel`) VALUES
-- Dalaran Portals (2 portals)
(@PortalD,53142,168000,0,0,74), -- Portal: Dalaran	
(@PortalD,53140,150000,0,0,71), -- Teleport: Dalaran
-- Alliance Portals (14 portals)
(@PortalA,11419,16500,0,0,42), -- Portal: Darnassus
(@PortalA,32266,16500,0,0,42), -- Portal: Exodar
(@PortalA,11416,16500,0,0,42), -- Portal: Ironforge
(@PortalA,33691,105000,0,0,66), -- Portal: Shattrath
(@PortalA,10059,16500,0,0,42), -- Portal: Stormwind
(@PortalA,49360,16500,0,0,42), -- Portal: Theramore
(@PortalA,88345,282000,0,0,96), -- Portal: Tol Barad
(@PortalA,3565,5100,0,0,24), -- Teleport: Darnassus
(@PortalA,32271,5100,0,0,24), -- Teleport: Exodar
(@PortalA,3562,5100,0,0,24), -- Teleport: Ironforge
(@PortalA,33960,81000,0,0,62), -- Teleport: Shattrath
(@PortalA,3561,5100,0,0,24), -- Teleport: Stormwind
(@PortalA,49359,5100,0,0,24), -- Teleport: Theramore
(@PortalA,88342,282000,0,0,85), -- Teleport: Tol Barad
-- Horde Portals (14 portals)
(@PortalH,11417,16500,0,0,42), -- Portal: Orgrimmar
(@PortalH,35717,105000,0,0,66), -- Portal: Shattrath
(@PortalH,32267,16500,0,0,42), -- Portal: Silvermoon
(@PortalH,49361,22500,0,0,52), -- Portal: Stonard
(@PortalH,11420,16500,0,0,42), -- Portal: Thunder Bluff
(@PortalH,88346,282000,0,0,85), -- Portal: Tol Barad
(@PortalH,11418,16500,0,0,42), -- Portal: Undercity
(@PortalH,3567,5100,0,0,24), -- Teleport: Orgrimmar
(@PortalH,35715,81000,0,0,62), -- Teleport: Shattrath
(@PortalH,32272,5100,0,0,24), -- Teleport: Silvermoon
(@PortalH,49358,22500,0,0,52), -- Teleport: Stonard
(@PortalH,3566,5100,0,0,24), -- Teleport: Thunder Bluff
(@PortalH,88344,282000,0,0,85), -- Teleport: Tol Barad
(@PortalH,3563,5100,0,0,24), -- Teleport: Undercity
-- Journeyman Riding (Skill 762)
(@RidingJ,33388,40000,0,0,20), -- Apprentice Riding
(@RidingJ,33391,500000,762,75,40), -- Journeyman Riding
-- Master Riding (Skill 762)
(@RidingM,-@RidingJ,0,0,0,0), -- Include Journeyman&Apprentice
(@RidingM,34090,2500000,762,150,60), -- Expert Riding
(@RidingM,34091,50000000,762,225,70), -- Artisan Riding
(@RidingM,54197,5000000,762,225,68), -- Cold Weather Flying
(@RidingM,90267,2500000,762,225,60), -- Flight Master's License
(@RidingM,90265,50000000,762,300,80), -- Master Riding
-- Fishing (Skill 356)
(@Fishing,7620,100,0,0,5), -- Fishing 75
(@Fishing,7731,500,365,50,5), -- Fishing (150)
(@Fishing,7732,10000,365,125,5), -- Fishing (225)
(@Fishing,18248,25000,365,200,5), -- Fishing (300)
(@Fishing,33095,100000,365,275,5), -- Fishing (375)
(@Fishing,51294,150000,365,350,5), -- Fishing (450)
(@Fishing,88868,500000,365,425,5), -- Fishing (525)
-- First Aid (skill 129)
(@FirstAid,3273,100,0,0,0), -- First Aid (75)
(@FirstAid,3274,500,129,50,0), -- First Aid (150)
(@FirstAid,7924,1000,129,125,0), -- First Aid (225)
(@FirstAid,10846,25000,129,225,35), -- First Aid (300)
(@FirstAid,27028,100000,129,275,50), -- First Aid (375)
(@FirstAid,45542,150000,129,350,65), -- First Aid (450)
(@FirstAid,74559,250000,129,425,75), -- First Aid (525)
(@FirstAid,3276,100,129,40,0), -- Heavy Linen Bandage
(@FirstAid,7934,250,129,80,0), -- Anti-Venom
(@FirstAid,3277,250,129,80,0), -- Wool Bandage
(@FirstAid,3278,1000,129,115,0), -- Heavy Wool Bandage
(@FirstAid,7928,5000,129,150,0), -- Silk Bandage
(@FirstAid,7929,5000,129,180,0), -- Heavy Silk Bandage
(@FirstAid,10840,10000,129,210,0), -- Mageweave Bandage
(@FirstAid,10841,10000,129,240,0), -- Heavy Mageweave Bandage
(@FirstAid,18629,20000,129,260,0), -- Runecloth Bandage
(@FirstAid,18630,20000,129,290,0), -- Heavy Runecloth Bandage
(@FirstAid,27032,20000,129,300,0), -- Netherweave Bandage
(@FirstAid,27033,40000,129,330,0), -- Heavy Netherweave Bandage
(@FirstAid,45545,40000,129,350,0), -- Frostweave Bandage
(@FirstAid,45546,60000,129,400,0), -- Heavy Frostweave Bandage
(@FirstAid,74556,60000,129,425,0), -- Embersilk Bandage
(@FirstAid,74557,80000,129,475,0), -- Heavy Embersilk Bandage
(@FirstAid,88893,80000,129,525,0), -- Dense Embersilk Bandage
(@FirstAid,74558,15000,129,525,0), -- Field Bandage: Dense Embersilk
-- Archeology (skill 794)
(@Archeology,78670,1000,0,0,20), -- Archeology (75)
(@Archeology,88961,1000,794,50,20), -- Archeology (150)
(@Archeology,89718,1000,794,125,20), -- Archeology (225)
(@Archeology,89719,25000,794,200,35), -- Archeology (300)
(@Archeology,89720,100000,794,275,50), -- Archeology (375)
(@Archeology,89721,150000,794,350,65), -- Archeology (450)
(@Archeology,89722,250000,794,425,75), -- Archeology (525)
-- Cooking (Skill 185)
(@Cooking,2550,100,0,0,0), -- Cooking (75)
(@Cooking,3102,500,185, 50,0), -- Cooking (150)
(@Cooking,3413,10000,185,125,0), -- Cooking (225)
(@Cooking,18260,25000,185,200,0), -- Cooking (300)
(@Cooking,33359,100000,185,275,0), -- Cooking (375)
(@Cooking,51296,350000,185,350,0), -- Cooking (450)
(@Cooking,88053,500000,185,425,0), -- Cooking (525)
(@Cooking,37836,10,185,1,0), -- Spice Bread
(@Cooking,6412,50,185,10,0), -- Kaldorei Spider Kabob
(@Cooking,2539,50,185,10,0), -- Spiced Wolf Meat
(@Cooking,93741,80,185,40,0), -- Venison Jerky
(@Cooking,6499,100,185,50,0), -- Boiled Clams
(@Cooking,2541,100,185,50,0), -- Coyote Steak
(@Cooking,6415,100,185,50,0), -- Fillet of Frenzy
(@Cooking,2544,200,185,75,0), -- Crab Cake
(@Cooking,2546,150,185,80,0), -- Dry Pork Ribs
(@Cooking,6500,300,185,125,0), -- Goblin Deviled Clams
(@Cooking,3399,450,185,150,0), -- Tasty Lion Steak
(@Cooking,4094,500,185,175,0), -- Barbecued Buzzard Wing
(@Cooking,3400,500,185,175,0), -- Soothing Turtle Bisque
(@Cooking,21175,4000,185,200,0), -- Spider Sausage
(@Cooking,18238,5000,185,225,0), -- Spotted Yellowtail
(@Cooking,18240,6000,185,240,0), -- Grilled Squid
(@Cooking,46684,6500,185,250,0), -- Charred Bear Kabobs
(@Cooking,46688,6500,185,250,0), -- Juicy Bear Burger
(@Cooking,18243,6500,185,250,0), -- Nightfin Soup
(@Cooking,18244,6500,185,250,0), -- Poached Sunscale Salmon
(@Cooking,42296,15000,185,320,0), -- Stewed Trout
(@Cooking,45561,10000,185,350,0), -- Grilled Bonescale
(@Cooking,45562,10000,185,350,0), -- Sauteed Goby
(@Cooking,45560,10000,185,350,0), -- Smoked Rockfin
(@Cooking,45569,20000,185,350,0), -- Baked Manta Ray
(@Cooking,58065,20000,185,350,0), -- Dalaran Clam Chowder
(@Cooking,45563,20000,185,350,0), -- Grilled Sculpin
(@Cooking,45549,20000,185,350,0), -- Mammoth Meal
(@Cooking,45566,20000,185,350,0), -- Pickled Fangtooth
(@Cooking,45565,20000,185,350,0), -- Poached Nettlefish
(@Cooking,45553,20000,185,350,0), -- Rhino Dogs
(@Cooking,45552,20000,185,350,0), -- Roasted Worg
(@Cooking,45550,20000,185,350,0), -- Shoveltusk Steak
(@Cooking,45564,20000,185,350,0), -- Smoked Salmon
(@Cooking,45551,20000,185,350,0), -- Worm Delight
(@Cooking,42302,20000,185,350,0), -- Fisherman's Feast
(@Cooking,42305,20000,185,350,0), -- Hot Buttered Trout
(@Cooking,45554,50000,185,375,0), -- Great Feast
(@Cooking,64358,50000,185,400,0), -- Black Jelly
(@Cooking,88015,30000,185,415,0), -- Darkbrew Lager
(@Cooking,88006,35000,185,425,0), -- Blackened Surprise
-- ------------------------------------
-- -- Assign portals to the trainers --
-- ------------------------------------
-- Alliance Trainers (5 trainers)
(4165,-@PortalA,0,0,0,0), -- Elissa Dumas (Darnassus)
(2485,-@PortalA,0,0,0,0), -- Larimaine Purdue (Stormwind City)
(16755,-@PortalA,0,0,0,0), -- Lunaraa (The Exodar)
(2489,-@PortalA,0,0,0,0), -- Milstaff Stormeye (Ironforge)
(27703,-@PortalA,0,0,0,0), -- Ysuria (Dustwallow Marsh)
-- Horde Trainers (6 trainers)
(5957,-@PortalH,0,0,0,0), -- Birgitte Cranston (Thunder Bluff)
(5957,-@PortalD,0,0,0,0), -- Birgitte Cranston (Thunder Bluff)
(2492,-@PortalH,0,0,0,0), -- Lexington Mortaim (Undercity)
(2492,-@PortalD,0,0,0,0), -- Lexington Mortaim (Undercity)
(27705,-@PortalH,0,0,0,0), -- Lorrin Foxfire (Swamp of Sorrows)
(27705,-@PortalD,0,0,0,0), -- Lorrin Foxfire (Swamp of Sorrows)
(16654,-@PortalH,0,0,0,0), -- Narinth (Silvermoon City)
(16654,-@PortalD,0,0,0,0), -- Narinth (Silvermoon City)
(47253,-@PortalH,0,0,0,0), -- Rundok (Orgrimmar)
(47253,-@PortalD,0,0,0,0), -- Rundok (Orgrimmar)
(45139,-@PortalH,0,0,0,0), -- Zirazi the Star-Gazer (Orgrimmar)
(45139,-@PortalD,0,0,0,0), -- Zirazi the Star-Gazer (Orgrimmar)
-- Neutral Trainers (3 trainers)
(29156,-@PortalA,0,0,0,0), -- Archmage Celindra (Dalaran)
(29156,-@PortalH,0,0,0,0), -- Archmage Celindra (Dalaran)
(29156,-@PortalD,0,0,0,0), -- Archmage Celindra (Dalaran)
(20791,-@PortalA,0,0,0,0), -- Iorioa (Shattrath City)
(20791,-@PortalH,0,0,0,0), -- Iorioa (Shattrath City)
(20791,-@PortalD,0,0,0,0), -- Iorioa (Shattrath City)
(19340,-@PortalA,0,0,0,0), -- Mi'irku Farstep (Shattrath City)
(19340,-@PortalH,0,0,0,0), -- Mi'irku Farstep (Shattrath City)
(19340,-@PortalD,0,0,0,0), -- Mi'irku Farstep (Shattrath City)
-- ------------------------------------
-- -- Assign Riding to the trainers --
-- ------------------------------------
-- Journeyman Riding (12 Trainers)
(20914,-@RidingJ,0,0,0,0), -- Aalun (The Exodar)
(7954,-@RidingJ,0,0,0,0), -- Binjy Featherwhistle (Dun Morogh)
(4753,-@RidingJ,0,0,0,0), -- Jartsam (Darnassus)
(3690,-@RidingJ,0,0,0,0), -- Kar Stormsinger (Mulgore)
(4752,-@RidingJ,0,0,0,0), -- Kildar (Orgrimmar)
(16280,-@RidingJ,0,0,0,0), -- Perascamin (Eversong Woods)
(4732,-@RidingJ,0,0,0,0), -- Randal Hunter (Elwynn Forest)
(48513,-@RidingJ,0,0,0,0), -- Revi Ramrod (Orgrimmar)
(53407,-@RidingJ,0,0,0,0), -- Sansha MacVince (Dustwallow Marsh)
(4772,-@RidingJ,0,0,0,0), -- Ultham Ironhorn (Dun Morogh)
(4773,-@RidingJ,0,0,0,0), -- Velma Warnam (Tirisfal Glades)
(7953,-@RidingJ,0,0,0,0), -- Xar'Ti (Durotar)
-- Master Riding (12 Trainers)
(43769,-@RidingM,0,0,0,0), -- Bralla Cloudwing (Stormwind City)
(43693,-@RidingM,0,0,0,0), -- Darlene Stokx (Stormwind City)
(35100,-@RidingM,0,0,0,0), -- Hargen Bronzewing (Hellfire Peninsula)
(31238,-@RidingM,0,0,0,0), -- Hira Snowdawn (Dalaran)
(20511,-@RidingM,0,0,0,0), -- Ilsa Blusterbrew (Shadowmoon Valley)
(35133,-@RidingM,0,0,0,0), -- Maigra Keenfeather (Borean Tundra)
(44919,-@RidingM,0,0,0,0), -- Maztha (Orgrimmar)
(20500,-@RidingM,0,0,0,0), -- Olrokk (Shadowmoon Valley)
(28746,-@RidingM,0,0,0,0), -- Pilot Vic (Sholazar Basin)
(31247,-@RidingM,0,0,0,0), -- Roxi Ramrocket (The Storm Peaks)
(35093,-@RidingM,0,0,0,0), -- Wind Rider Jahubo (Hellfire Peninsula)
(35135,-@RidingM,0,0,0,0), -- Wind Rider Sabamba (Borean Tundra)
-- ------------------------------------
-- -- Assign Fishing to the trainers --
-- ------------------------------------
(23896,-@Fishing,0,0,0,0), -- "Dirty" Michael Crowe (Dustwallow Marsh)
(3607,-@Fishing,0,0,0,0), -- Androl Oakhand (Teldrassil)
(26957,-@Fishing,0,0,0,0), -- Angelina Soren (Howling Fjord)
(4573,-@Fishing,0,0,0,0), -- Armand Cromwell (Undercity)
(5493,-@Fishing,0,0,0,0), -- Arnold Leland (Stormwind City)
(4156,-@Fishing,0,0,0,0), -- Astaia (Darnassus)
(7946,-@Fishing,0,0,0,0), -- Brannock (Feralas)
(26909,-@Fishing,0,0,0,0), -- Byron Welwick (Howling Fjord)
(5690,-@Fishing,0,0,0,0), -- Clyde Kellen (Tirisfal Glades)
(17101,-@Fishing,0,0,0,0), -- Diktynna (Azuremyst Isle)
(16780,-@Fishing,0,0,0,0), -- Drathen (Silvermoon City)
(16774,-@Fishing,0,0,0,0), -- Erett (The Exodar)
(33623,-@Fishing,0,0,0,0), -- Fishing (Shattrath City)
(32474,-@Fishing,0,0,0,0), -- Fishy Ser'ji (Borean Tundra)
(5161,-@Fishing,0,0,0,0), -- Grimnur Stonebrand (Ironforge))
(3179,-@Fishing,0,0,0,0), -- Harold Riggs (Wetlands)
(18911,-@Fishing,0,0,0,0), -- Juno Dufrain (Zangarmarsh)
(3028,-@Fishing,0,0,0,0), -- Kah Mistrunner (Thunder Bluff)
(14740,-@Fishing,0,0,0,0), -- Katoom the Angler (The Hinterlands)
(12961,-@Fishing,0,0,0,0), -- Kil'Hiwana (Ashenvale)
(5941,-@Fishing,0,0,0,0), -- Lau'Tiki (Durotar)
(1651,-@Fishing,0,0,0,0), -- Lee Brown (Elwynn Forest)
(12032,-@Fishing,0,0,0,0), -- Lui'Mala (Desolace)
(3332,-@Fishing,0,0,0,0), -- Lumak (Orgrimmar)
(28742,-@Fishing,0,0,0,0), -- Marcia Chase (Dalaran)
(1680,-@Fishing,0,0,0,0), -- Matthew Hooper (Redridge Mountains)
(2834,-@Fishing,0,0,0,0), -- Myizz Luckycatch (The Cape of Stranglethorn)
(25580,-@Fishing,0,0,0,0), -- Old Man Barlo (Terokkar Forest)
(26993,-@Fishing,0,0,0,0), -- Old Man Robert (Borean Tundra)
(44975,-@Fishing,0,0,0,0), -- Old Umbehto (Orgrimmar)
(1700,-@Fishing,0,0,0,0), -- Paxton Ganter (Dun Morogh)
(56068,-@Fishing,0,0,0,0), -- Steven Stagnaro (Darkmoon Island)
(5938,-@Fishing,0,0,0,0), -- Uthan Stillwater (Mulgore)
(1683,-@Fishing,0,0,0,0), -- Warg Deepwater(Loch Modan)
(50570,-@Fishing,0,0,0,0), -- Whilsey Bottomtooth(Gilneas, Gilneas City)
(18018,-@Fishing,0,0,0,0), -- Zurjaya (Zangarmarsh)
-- -------------------------------------
-- -- Assign FirstAid to the trainers --
-- -------------------------------------
(16662,-@FirstAid,0,0,0,0), -- Alestus (Silvermoon City)
(50574,-@FirstAid,0,0,0,0), -- Amelia Atherton(Gilneas, Gilneas City)
(22477,-@FirstAid,0,0,0,0), -- Anchorite Ensham(Terokkar Forest)
(17214,-@FirstAid,0,0,0,0), -- Anchorite Fateema(Azuremyst Isle)
(17424,-@FirstAid,0,0,0,0), -- Anchorite Paetheus(Bloodmyst Isle)
(23734,-@FirstAid,0,0,0,0), -- Anchorite Yazmina(Howling Fjord)
(56796,-@FirstAid,0,0,0,0), -- Angela Leifeld(Stormwind City)
(18991,-@FirstAid,0,0,0,0), -- Aresella(Hellfire Peninsula)
(26992,-@FirstAid,0,0,0,0), -- Brynna Wilson(Borean Tundra)
(18990,-@FirstAid,0,0,0,0), -- Burko(Hellfire Peninsula)
(6094,-@FirstAid,0,0,0,0), -- Byancie(Teldrassil)
(4211,-@FirstAid,0,0,0,0), -- Dannelor(Darnassus)
(49879,-@FirstAid,0,0,0,0), -- Doc Zapnozzle(Azshara)
(36615,-@FirstAid,0,0,0,0), -- Doc Zapnozzle(The Lost Isles)
(12939,-@FirstAid,0,0,0,0), -- Doctor Gustaf VanHowzen(Dustwallow Marsh)
(19478,-@FirstAid,0,0,0,0), -- Fera Palerunner(Blade's Edge Mountains)
(33621,-@FirstAid,0,0,0,0), -- First Aid (Shattrath City)
(3181,-@FirstAid,0,0,0,0), -- Fremal Doohickey(Wetlands)
(33589,-@FirstAid,0,0,0,0), -- Joseph Wilson(Icecrown)
(16272,-@FirstAid,0,0,0,0), -- Kanaria(??)
(45540,-@FirstAid,0,0,0,0), -- Krenk Choplimb(Orgrimmar)
(4591,-@FirstAid,0,0,0,0), -- Mary Edras(Undercity)
(2329,-@FirstAid,0,0,0,0), -- Michelle Belle(Elwynn Forest)
(19184,-@FirstAid,0,0,0,0), -- Mildred Fletcher(Shattrath City)
(5150,-@FirstAid,0,0,0,0), -- Nissa Firestone(Ironforge)
(29233,-@FirstAid,0,0,0,0), -- Nurse Applewood(Borean Tundra)
(5759,-@FirstAid,0,0,0,0), -- Nurse Neela(Tirisfal Glades)
(16731,-@FirstAid,0,0,0,0), -- Nus(The Exodar)
(28706,-@FirstAid,0,0,0,0), -- Olisarra the Kind(Dalaran)
(2798,-@FirstAid,0,0,0,0), -- Pand Stonebinder(Thunder Bluff)
(5943,-@FirstAid,0,0,0,0), -- Rawrk(Durotar)
(26956,-@FirstAid,0,0,0,0), -- Sally Tompkins(Howling Fjord)
(2326,-@FirstAid,0,0,0,0), -- Thamner Pol(Dun Morogh)
(5939,-@FirstAid,0,0,0,0), -- Vira Younghoof(Mulgore)
-- ---------------------------------------
-- -- Assign Archeology to the trainers --
-- ---------------------------------------
(47382,-@Archeology,0,0,0,0), -- Adam Hossack (Undercity)
(47571,-@Archeology,0,0,0,0), -- Belloc Brightblade (Orgrimmar)
(47575,-@Archeology,0,0,0,0), -- Boduro the Seeker (Shattrath City)
(47579,-@Archeology,0,0,0,0), -- Dariness the Learned (Dalaran)
(47570,-@Archeology,0,0,0,0), -- Diya (The Exodar)
(39718,-@Archeology,0,0,0,0), -- Doktor Professor Ironpants (Ironforge)
(47346,-@Archeology,0,0,0,0), -- Elynara (Silvermoon City)
(53421,-@Archeology,0,0,0,0), -- Faena Woolybush (Dustwallow Marsh)
(47576,-@Archeology,0,0,0,0), -- Falda Fardelve (Borean Tundra)
(47574,-@Archeology,0,0,0,0), -- Gerdra Fardelve (Hellfire Peninsula)
(47569,-@Archeology,0,0,0,0), -- Hammon the Jaded (Darnassus)
(44238,-@Archeology,0,0,0,0), -- Harrison Jones (Stormwind City)
(47578,-@Archeology,0,0,0,0), -- Hugen Goldwise (Howling Fjord)
(47568,-@Archeology,0,0,0,0), -- Ian Thomas Wall (Howling Fjord)
(47577,-@Archeology,0,0,0,0), -- Lindarel (Borean Tundra)
(47572,-@Archeology,0,0,0,0), -- Otoh Greyhide (Thunder Bluff)
(47573,-@Archeology,0,0,0,0), -- Sirabel (Hellfire Peninsula)
(51997,-@Archeology,0,0,0,0), -- Stephanie Krutsick (Darkshore)
-- ------------------------------------
-- -- Assign Cooking to the trainers --
-- ------------------------------------
(17246,-@Cooking,0,0,0,0), -- "Cookie" McWeaksauce (Azuremyst Isle)
(4210,-@Cooking,0,0,0,0), -- Alegorn (Darnassus)
(49789,-@Cooking,0,0,0,0), -- Allison (Hellfire Peninsula)
(46709,-@Cooking,0,0,0,0), -- Arugi (Orgrimmar)
(3026,-@Cooking,0,0,0,0), -- Aska Mistrunner (Thunder Bluff)
(29631,-@Cooking,0,0,0,0), -- Awilo Lon'gomba (Dalaran)
(33587,-@Cooking,0,0,0,0), -- Bethany Cromwell (Icecrown)
(26905,-@Cooking,0,0,0,0), -- Brom Brewbaster (Howling Fjord)
(19369,-@Cooking,0,0,0,0), -- Celie Steelwing (Shadowmoon Valley)
(1355,-@Cooking,0,0,0,0), -- Cook Ghilm(Dun Morogh)
(33619,-@Cooking,0,0,0,0), -- Cooking (Shattrath City)
(4894,-@Cooking,0,0,0,0), -- Craig Nollward (Dustwallow Marsh)
(3087,-@Cooking,0,0,0,0), -- Crystal Boughman (Redridge Mountains)
(5159,-@Cooking,0,0,0,0), -- Daryl Riknussun (Ironforge)
(8306,-@Cooking,0,0,0,0), -- Duhng (Northern Barrens)
(4552,-@Cooking,0,0,0,0), -- Eunice Burch (Undercity)
(50567,-@Cooking,0,0,0,0), -- Fielding Chesterhill (Gilneas, Gilneas City)
(18987,-@Cooking,0,0,0,0), -- Gaston (Hellfire Peninsula)
(1699,-@Cooking,0,0,0,0), -- Gremlock Pilsnor (Dun Morogh)
(19185,-@Cooking,0,0,0,0), -- Jack Trapper (Shattrath City)
(28705,-@Cooking,0,0,0,0), -- Katherine Lee (Dalaran)
(19186,-@Cooking,0,0,0,0), -- Kylene (Shattrath City)
(16253,-@Cooking,0,0,0,0), -- Master Chef Mouldier (Ghostlands)
(54232,-@Cooking,0,0,0,0), -- Mrs. Gant (The Cape of Stranglethorn)
(1382,-@Cooking,0,0,0,0), -- Mudduk (Northern Stranglethorn)
(16719,-@Cooking,0,0,0,0), -- Mumman (The Exodar)
(18993,-@Cooking,0,0,0,0), -- Naka (Zangarmarsh)
(26972,-@Cooking,0,0,0,0), -- Orn Tenderhoof (Borean Tundra)
(3067,-@Cooking,0,0,0,0), -- Pyall Silentstride (Mulgore)
(16277,-@Cooking,0,0,0,0), -- Quarelestra ()
(26989,-@Cooking,0,0,0,0), -- Rollick MacKreel (Borean Tundra)
(2818,-@Cooking,0,0,0,0), -- Slagg (Arathi Highlands)
(5482,-@Cooking,0,0,0,0), -- Stephen Ryback (Stormwind City)
(16676,-@Cooking,0,0,0,0), -- Sylann (Silvermoon City)
(47405,-@Cooking,0,0,0,0), -- The Chef (Tirisfal Glades)
(26953,-@Cooking,0,0,0,0), -- Thomas Kolichio (Howling Fjord)
(1430,-@Cooking,0,0,0,0), -- Tomas (Elwynn Forest)
(3399,-@Cooking,0,0,0,0), -- Zamja (Orgrimmar)
(45550,-@Cooking,0,0,0,0), -- Zarbo Porkpatty (Orgrimmar)
(6286,-@Cooking,0,0,0,0); -- Zarrin (Teldrassil)
